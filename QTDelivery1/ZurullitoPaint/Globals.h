#ifndef GLOBALS_H
#define GLOBALS_H

enum DrawShapes
{
    BG = 0,
    Circle,
    Box,
    Line
};

struct Transform
{
    double px = 0,py = 0;
    double sx = 100,sy = 100;
    double r = 45;
};

#include <QPainter>

struct DrawStruct
{
    QBrush fill = QBrush(Qt::SolidPattern);
    QPen outline = QPen(QColor(0,0,0));
    DrawShapes shape = DrawShapes::Box;
    Transform t;
};

struct Entity
{
    Entity* parent = nullptr;
    std::vector<Entity*> children;

    std::vector<uint> children_id; // load save purpose only

    uint id = UINT_MAX;
    uint p_id = NULL;

    std::string name = "";

    DrawStruct drawData;
};

#endif // GLOBALS_H
