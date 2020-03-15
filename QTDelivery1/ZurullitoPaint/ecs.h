#ifndef ECS_H
#define ECS_H

#include <QObject>
#include "Globals.h"



class ECS : public QObject
{
    Q_OBJECT
public:
    explicit ECS(QObject *parent = nullptr );
    ~ECS();

    //void Update();
    uint FindEntity(uint id);

    void changeParent(Entity* e, uint p_id, uint pos);

    void transformChildren(Entity* e, double px_delta, double py_delta, double r_delta, double px_par, double py_par);

    void ChildSendToHierarchy(Entity* e);

    int GetRealPos(uint p_id, int pos)
    {
        int ret = 0;
        uint p_ind = FindEntity(p_id);
        if(p_ind != UINT_MAX)
        {
            int epos = -1;
            for(uint i = 0; epos <= pos && i < entities.size();++i)
                if(entities[i]->p_id == p_id)
                {
                    ++epos;
                    ret = i;
                }
        }
        else
        {
            int epos = -1;
            for(uint i = 0; epos < pos && i < entities.size();++i)
                if(entities[i]->p_id == NULL)
                {
                    ++epos;
                    ret = i;
                }
        }

        return ret;
    }
private:
    std::vector<Entity*> entities;

public slots:
    void entitySelected(uint id);
    void AddEntity(uint id, uint p_id);
    void RemoveEntity(uint id);
    void executeDraw();
    void updatedEntity(const uint id, const char* name, DrawStruct& drawData);
    void updateParenting(uint id, uint p_id, uint pos);

    void onSaveFile(QString filename);
    void onOpenFile(QString filename);

signals:
    void askDraw(DrawStruct drawData);
    void callEnd();
    void callRePaint();
    void selectedEntity(const uint id, const char* name, const DrawStruct& drawData);
    void changedName(const char* name);
    void SendToHierarchy(uint id, uint p_id);
};

#endif // ECS_H
