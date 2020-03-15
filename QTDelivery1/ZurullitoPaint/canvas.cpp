#include "canvas.h"
#include <QMouseEvent>

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    setAutoFillBackground(true);
    painter = new QPainter(this);
    allowBegin = true;
    tracking_pos = false;
}

Canvas::~Canvas()
{
    delete painter;
}

QSize Canvas::sizeHint() const
{
    return QSize(256,256); // this returns expected size
}

QSize Canvas::minimumSizeHint() const
{
    return QSize(64,64); // this returns minimum size
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    int wx = this->x();
    int wy = this->y();
    int ww = wx + this->size().width();
    int wh = wy + this->size().height();

    if(x >= wx && x <= ww && y >+ wy && y <= wh)
    {
        tracking_pos = true;
        Clicked(event->x(), event->y());
    }

}
void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
    if(tracking_pos) Release(event->x(), event->y());
    tracking_pos = false;
}

void Canvas::paintEvent(QPaintEvent* ev)
{
    if(allowBegin)
    {
        const QSize& s = this->size();
        painter->eraseRect(QRectF(0,0,s.width(),s.height()));

        allowBegin = false;
        painter->begin(this);

        painter->setBrush(QBrush(QColor(255,255,255),Qt::BrushStyle::SolidPattern));
        painter->setPen(QPen(Qt::PenStyle::NoPen));
        painter->drawRect(rect());

        CallDraw();
    }
}

void Canvas::drawEntity(const DrawStruct& drawData)
{
    painter->setPen(drawData.outline);
    painter->setBrush(drawData.fill);

    const Transform& t = drawData.t;

    painter->translate(t.px, t.py);
    painter->rotate(t.r);
    painter->translate(- t.sx / 2,- t.sy/2);

    switch(drawData.shape)
    {
    case DrawShapes::BG:
        break;
    case DrawShapes::Circle:
        painter->drawEllipse(0, 0, t.sx, t.sy);
        break;
    case DrawShapes::Box:
        painter->drawRect(0, 0, t.sx, t.sy);
        break;
    case DrawShapes::Line:
        painter->drawLine(0, 0, t.sx, t.sy);
        break;
    }

    painter->translate(t.sx / 2, t.sy/2);
    painter->rotate(-t.r);
    painter->translate(-t.px,-t.py);
}

void Canvas::executeEnd()
{
    painter->end();
    allowBegin = true;
}
