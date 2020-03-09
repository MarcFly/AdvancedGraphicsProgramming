#ifndef ECS_H
#define ECS_H

#include <QObject>
#include "Globals.h"

struct Entity
{
    Entity* parent;
    std::vector<Entity*> children;
    uint id;

    DrawStruct drawData;
};

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

signals:
    void askDraw(DrawStruct drawData);
    void callEnd();
    void callRePaint();
    void selectedEntity(const DrawStruct& drawData);
};

#endif // ECS_H
