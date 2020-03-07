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
    int px,py;
    float sx,sy;
    int r;
};

#include <QPainter>

struct DrawStruct
{
    QBrush fill;
    QPen outline;
    DrawShapes shape;
    Transform t;
};

#endif // GLOBALS_H
