#include "ecs.h"
#include <QtMath>
#include <QFile>

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
        newE->p_id = NULL;
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
            newE->p_id = p_id;
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
    for(int i = entities.size() -1; i >= 0; --i)
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
        if(e->drawData.t.r > 360) e->drawData.t.r -= 360;
        if(e->drawData.t.r < 0) e->drawData.t.r += 360;

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
        bool stm1 = ent_ind != GetRealPos(p_id, pos);
        bool stm2 = entities[ent_ind]-> parent == nullptr && p_id != NULL;
        bool stm3 = entities[ent_ind]->parent != nullptr && entities[ent_ind]->p_id != p_id;
        if(stm1 || stm2 || stm3)
            changeParent(entities[ent_ind], p_id, pos);
    }
}

void ECS::changeParent(Entity *e, uint p_id, uint pos)
{
    uint p_ind = FindEntity(p_id);
    Entity* new_p = nullptr;
    e->p_id = p_id;

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

    // Remove from hierarchy

    for(uint i = 0; i < entities.size(); ++i)
        if(entities[i] != e) swap_v.push_back(entities[i]);
    entities.swap(swap_v);
    swap_v.clear();

    e->parent = new_p;

    if(new_p != nullptr)
    {
        // Add in order to parent's children
        for(uint i = 0; i < pos; ++i)
            swap_v.push_back(new_p->children[i]);

        swap_v.push_back(e);

        for(uint i = pos; i < new_p->children.size(); ++i)
            swap_v.push_back(new_p->children[i]);

        new_p->children.swap(swap_v);
        swap_v.clear();

        // Add back to entity vector
        for(uint i = 0; i < p_ind; ++i)
            swap_v.push_back(entities[i]);
        swap_v.push_back(e);
        for(uint i = p_ind; i < entities.size(); ++i)
            swap_v.push_back(entities[i]);

        entities.swap(swap_v);

        swap_v.clear();
    }
    else
    {
        // For entities that stopped having a parent, we need other solution
        // Have to find pos of NULL parent entities to determine new position

        int epos = -1;
        int rpos = 0;
        int last_child_pos = 0;
        for(uint i = 0; epos < pos && i < entities.size();++i)
            if(entities[i]->p_id == NULL)
            {
                if(last_child_pos != rpos) last_child_pos = rpos;
                ++epos;
                rpos = i;
            }

        // Add back to entity vector
        for(uint i = 0; i < last_child_pos; ++i)
            swap_v.push_back(entities[i]);
        swap_v.push_back(e);
        for(uint i = last_child_pos; i < entities.size(); ++i)
            swap_v.push_back(entities[i]);

        entities.swap(swap_v);

        swap_v.clear();
    }

    callRePaint();

}


void ECS::transformChildren(Entity *e, double px_delta, double py_delta, double r_delta, double px_par, double py_par)
{


    double vx = e->drawData.t.px - px_par;
    double vy = e->drawData.t.py - py_par;

    double dx = cos(r_delta)*vx - sin(r_delta)*vy;
    double dy = sin(r_delta)*vx + cos(r_delta)*vy;

    e->drawData.t.px = dx + px_par + px_delta;
    e->drawData.t.py = dy + py_par + py_delta;
    e->drawData.t.r += qRadiansToDegrees(r_delta);

    if(e->drawData.t.r > 360) e->drawData.t.r -= 360;
    if(e->drawData.t.r < 0) e->drawData.t.r += 360;

    for(uint i = 0; i < e->children.size(); ++i)
        transformChildren(e->children[i], px_delta, py_delta, r_delta, px_par, py_par);
}

void ECS::onSaveFile(QString filename)
{
    // Constant size of the entity
    int const_e_size = sizeof(uint) * 2 + sizeof(Transform) + sizeof(int) * 3 + sizeof(int)*6 + sizeof(int);
    // 2 x uint for id and p_id
    // 1 x Transform of the object
    // 3 ints (Brush Style, Shape, Pen Style)
    // 2 x 3 int of a color
    // 1 x int for the width of pen

    // Constant definitions for variables
    const_e_size += sizeof(int);
    // Size of children array, size of name

    if(QFile::exists(filename))
    {
        QFile::remove(filename);
    }

    QFile write(filename);
    write.open(QIODevice::WriteOnly);

    QDataStream bytes(&write);

    int esize = entities.size();
    bytes << esize;

    for(uint i = 0; i < entities.size(); ++i)
    {
        Entity* e = entities[i];
        int n_size = e->name.length();

        // Order: ID, PID, Transform, Brush(Style then Color), Pen(Width, Style, Color)
        // name , children ids

        bytes << e->id;
        bytes << e->p_id;

        bytes << e->drawData.t.px;
        bytes << e->drawData.t.py;
        bytes << e->drawData.t.sx;
        bytes << e->drawData.t.sy;
        bytes << e->drawData.t.r;

        int style = (int)e->drawData.fill.style();
        int r,g,b;
        r = e->drawData.fill.color().red();
        g = e->drawData.fill.color().green();
        b = e->drawData.fill.color().blue();

        bytes << style;
        bytes << r;
        bytes << g;
        bytes << b;

        style = (int)e->drawData.outline.style();
        r = e->drawData.outline.color().red();
        g = e->drawData.outline.color().green();
        b = e->drawData.outline.color().blue();
        int width = e->drawData.outline.width();

        bytes << width;
        bytes << style;
        bytes << r;
        bytes << g;
        bytes << b;

        bytes << n_size;
        bytes.writeRawData(e->name.c_str(), n_size+1);
    }

    write.close();
}

void ECS::onOpenFile(QString filename)
{

    if(QFile::exists(filename))
    {

        QFile read(filename);
        read.open(QIODevice::ReadOnly);
        QDataStream bytes(&read);

        uint e_size;
        bytes >> e_size;

        for(uint i = 0; i < e_size; ++i)
        {
            Entity* e = new Entity();

            // Order: ID, PID, Transform, Brush(Style then Color), Pen(Width, Style, Color)
            // name size, name

            bytes >> e->id;
            bytes >> e->p_id;

            bytes >> e->drawData.t.px;
            bytes >> e->drawData.t.py;
            bytes >> e->drawData.t.sx;
            bytes >> e->drawData.t.sy;
            bytes >> e->drawData.t.r;

            int style;
            int r,g,b;

            bytes >> style;
            bytes >> r;
            bytes >> g;
            bytes >> b;

            e->drawData.fill.setStyle((Qt::BrushStyle)style);
            e->drawData.fill.setColor(QColor(r,g,b));

            int width;
            bytes >> width;
            bytes >> style;
            bytes >> r;
            bytes >> g;
            bytes >> b;

            e->drawData.outline.setWidth(width);
            e->drawData.outline.setStyle((Qt::PenStyle)style);
            e->drawData.outline.setColor(QColor(r,g,b));

            int n_size;
            bytes >> n_size;
            n_size +=1;

            char* str = new char[n_size];
            const uint nsize = n_size;
            bytes.readRawData(str, nsize);
            e->name = std::string(str, n_size);
            delete[] str;


            entities.push_back(e);
        }

        read.close();
    }

    for(uint i = 0; i < entities.size(); ++i)
    {
        uint p_ind = FindEntity(entities[i]->p_id);
        if(p_ind != UINT_MAX)
        {
            entities[i]->parent = entities[p_ind];
            entities[p_ind]->children.push_back(entities[i]);
        }
        else entities[i]->parent = nullptr;
    }

    for(uint i = 0; i < entities.size(); ++i)
    {
        if(entities[i]->p_id == NULL)
        {
            SendToHierarchy(entities[i]->id, NULL);
            ChildSendToHierarchy(entities[i]);
        }
    }

}

void ECS::ChildSendToHierarchy(Entity* e)
{

    for(uint i = 0; i < e->children.size(); ++i)
    {
        SendToHierarchy(e->children[i]->id, e->id);
        ChildSendToHierarchy(e->children[i]);
    }
}

void ECS::MousePick(int x, int y)
{
    for(uint i = 0; i < entities.size(); ++i)
    {
        int vx, vy;
        vx = x - entities[i]->drawData.t.px;
        vy = y - entities[i]->drawData.t.py;

        double dx = cos(entities[i]->drawData.t.r)*vx - sin(entities[i]->drawData.t.r)*vy;
        double dy = sin(entities[i]->drawData.t.r)*vx + cos(entities[i]->drawData.t.r)*vy;

        double realx = dx + entities[i]->drawData.t.px;
        double realy = dy + entities[i]->drawData.t.py;

        double x1,x2,y1,y2;
        x1 = entities[i]->drawData.t.px - (entities[i]->drawData.t.sx / 2);
        x2 = entities[i]->drawData.t.px + (entities[i]->drawData.t.sx / 2);
        y1 = entities[i]->drawData.t.py - (entities[i]->drawData.t.sy / 2);
        y2 = entities[i]->drawData.t.py + (entities[i]->drawData.t.sy / 2);

        if(realx >= x1 && realx <= x2 && realy >= y1 && realy <= y2)
        {
            MousePickSelect(entities[i]->id);
            break;
        }

    }
}
