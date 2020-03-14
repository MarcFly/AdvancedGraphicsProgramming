#include "ecs.h"
#include <QtMath>

ECS::ECS(QObject* parent) : QObject(parent)
{

}

ECS::~ECS()
{
    for(uint i = 0; i < entities.size(); ++i)
        delete entities[i];
    entities.clear();
}

uint ECS::FindEntity(uint id)
{
    uint ret = UINT_MAX;
    for(uint i = 0; i < entities.size(); ++i)
    {
        ret = i;
        if(entities[i]->id == id) break;
        ret = UINT_MAX;
    }

    return ret;
}

void ECS::AddEntity(uint id, uint p_id)
{
    Entity* newE = new Entity();
    newE->id = id;
    if(p_id==0)
    {
        newE->parent = nullptr;
        entities.push_back(newE);
    }
    else
    {
        uint ent_ind = FindEntity(p_id);
        if(ent_ind == UINT_MAX)
        {
            //Call removal of the added child in the tree
        }
        else
        {
            newE->parent = entities[ent_ind];
            entities[ent_ind]->children.push_back(newE);

            std::vector<Entity*> swap_v;

            for(uint i = 0; i < ent_ind; ++i)
                swap_v.push_back(entities[i]);

            swap_v.push_back(newE);

            for(uint i = ent_ind; i < entities.size(); ++i)
                swap_v.push_back(entities[i]);

            entities.swap(swap_v);
            swap_v.clear();
        }

    }

    callRePaint();
}

void ECS::RemoveEntity(uint id)
{
    uint ent_ind = FindEntity(id);
    if(ent_ind != UINT_MAX)
    {
        Entity* del_ent = entities[ent_ind];
        std::vector<Entity*> swap_v;

        for(uint i = 0; i < ent_ind; ++i)
            swap_v.push_back(entities[i]);
        for(uint i = ent_ind+1; i < entities.size(); ++i)
            swap_v.push_back(entities[i]);

        entities.swap(swap_v);
        swap_v.clear();

        delete del_ent;
    }

    callRePaint();
}

void ECS::executeDraw()
{
    // Ask draws for the object in the proper order
    for(uint i = 0; i < entities.size(); ++i)
        askDraw(entities[i]->drawData);

    // Tell the painter that it can end the painting session
    callEnd();
}

void ECS::entitySelected(uint id)
{
    uint e = FindEntity(id);
    if(e != UINT_MAX)
       selectedEntity(id, entities[e]->name.c_str(), entities[e]->drawData);
}

void ECS::updatedEntity(const uint id, const char* name, DrawStruct& drawData)
{
    uint ent_ind = FindEntity(id);
    if(ent_ind != UINT_MAX)
    {
        Entity* e = entities[ent_ind];
        e->name = name;
        changedName(e->name.c_str());

        double px_delta, py_delta;
        px_delta = drawData.t.px - e->drawData.t.px;
        py_delta = drawData.t.py - e->drawData.t.py;
        int r_delta = (drawData.t.r - e->drawData.t.r);

        e->drawData.t.px += px_delta;
        e->drawData.t.py += py_delta;
        e->drawData.t.sx = drawData.t.sx;
        e->drawData.t.sy = drawData.t.sy;
        e->drawData.t.r += r_delta;
        double d_r_delta = qDegreesToRadians((double)r_delta);
        for(uint i = 0; i < e->children.size(); ++i)
            transformChildren(e->children[i], px_delta, py_delta, d_r_delta, e->drawData.t.px, e->drawData.t.py);

        e->drawData.fill = drawData.fill;
        e->drawData.shape = drawData.shape;
        e->drawData.outline = drawData.outline;

        callRePaint();
    }
}

void ECS::updateParenting(uint id, uint p_id, uint pos)
{
    uint ent_ind = FindEntity(id);
    if(ent_ind != UINT_MAX)
    {
        Entity* e = entities[ent_ind];
        if(e->parent == nullptr)
        {
            if(p_id != NULL)
                changeParent(e, p_id, pos);
        }
        else if(e->parent != nullptr && e->parent->id != p_id)
        {
            changeParent(e, p_id, pos);
        }
    }
}

void ECS::changeParent(Entity *e, uint p_id, uint pos)
{
    uint p_ind = FindEntity(p_id);
    Entity* new_p = nullptr;
    if(p_ind != UINT_MAX)
        new_p = entities[p_ind];
    Entity* old_p = e->parent;

    std::vector<Entity*> swap_v;

    // Remove from child list of old parent
    if(old_p != nullptr)
    {
        for(uint i = 0; i < old_p->children.size(); ++i)
        {
            if(old_p->children[i] != e)
                swap_v.push_back(entities[i]);
        }

        old_p->children.swap(swap_v);
        swap_v.clear();
    }

    e->parent = new_p;

    if(new_p != nullptr)
    {
        // naive reparenting, no proper order
        new_p->children.push_back(e);

        // Child reordering, not yet in the entities vector
        e = new_p->children[pos];
        new_p->children[pos] = new_p->children[new_p->children.size()-1];
        new_p->children[new_p->children.size()-1] = e;

        //  Reorder vector with new list

    }

}


void ECS::transformChildren(Entity *e, double px_delta, double py_delta, double r_delta, double px_par, double py_par)
{
    double vx = e->drawData.t.px - px_par;
    double vy = e->drawData.t.py - py_par;

    double dx = cos(r_delta)*vx - sin(r_delta)*vy;
    double dy = sin(r_delta)*vx + cos(r_delta)*vy;

    e->drawData.t.px = dx + px_par;
    e->drawData.t.py = dy + py_par;
    e->drawData.t.r += qRadiansToDegrees(r_delta);

    for(uint i = 0; i < e->children.size(); ++i)
        transformChildren(e->children[i], px_delta, py_delta, r_delta, px_par, py_par);
}
