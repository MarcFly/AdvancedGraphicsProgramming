#ifndef ECS_H
#define ECS_H

#include <QObject>
#include "Globals.h"

struct Entity
{
    Entity* parent;
    std::vector<Entity*> children;
    uint id;

    Transform t;
    DrawShapes shape;
    QBrush fill;
    QPen outline;
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
    void AddEntity(uint id, uint p_id);
    void RemoveEntity(uint id);
    void executeDraw();

signals:
    void askDraw(DrawStruct drawData);
    void callEnd();
};

#endif // ECS_H
