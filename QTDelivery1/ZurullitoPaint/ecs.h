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

private:
    std::vector<Entity*> entities;

public slots:
    void entitySelected(uint id);
    void AddEntity(uint id, uint p_id);
    void RemoveEntity(uint id);
    void executeDraw();
    void updatedEntity(const uint id, const char* name, DrawStruct& drawData);

signals:
    void askDraw(DrawStruct drawData);
    void callEnd();
    void callRePaint();
    void selectedEntity(const uint id, const char* name, const DrawStruct& drawData);
    void changedName(const char* name);
};

#endif // ECS_H
