#include "canvas.h"
#include <QPainter>

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    setAutoFillBackground(true);
}

QSize Canvas::sizeHint() const
{
    return QSize(256,256); // this returns expected size
}

QSize Canvas::minimumSizeHint() const
{
    return QSize(64,64); // this returns expected size
}

void Canvas::paintEvent(QPaintEvent* ev)
{
    // do something
    QColor blue = QColor::fromRgb(127,190,220);
    QColor white = QColor::fromRgb(255,255,255);
    QColor black = QColor::fromRgb(0,0,0);
    QPainter painter(this);

    QBrush brush;
    QPen pen;

    // Configure Brush / Pen

    brush.setColor(blue);
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    pen.setStyle(Qt::PenStyle::NoPen);
    painter.setBrush(brush);
    painter.setPen(pen);

    // Base Background, painter depending on the latest configuration
    painter.drawRect(rect());

    // Reconfigure Brush to paint Circle
    brush.setColor(white);
    pen.setWidth(4);
    pen.setColor(black);
    pen.setStyle(Qt::PenStyle::DashLine);
    painter.setBrush(brush);
    painter.setPen(pen);

    // Draw the circle figure
    int r = 64;
    int w = r*2;
    int h = r*2;
    int x = rect().width() / 2 - r;
    int y = rect().height() / 2 - r;
    QRect circleRect(x,y,w,h);
    painter.drawEllipse(circleRect);


}
