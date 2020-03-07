#include "ecs.h"

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
        entities.push_back(new Entity);
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

        for(uint i = 0; i < del_ent->children.size(); ++i)
            RemoveEntity(del_ent->children[i]->id);

        delete del_ent;
    }
}

void ECS::executeDraw()
{
    // Ask draws for the object in the proper order

    // Tell the painter that it can end the painting session
    callEnd();
}

