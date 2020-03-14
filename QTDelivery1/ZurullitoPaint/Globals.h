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
    int px = 0,py = 0;
    float sx = 100,sy = 100;
    int r = 45;
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
    uint id = UINT_MAX;

    std::string name = "";

    DrawStruct drawData;
};

#endif // GLOBALS_H