#include "canvas.h"
#include <QMouseEvent>
#include <QFileDialog>

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    setAutoFillBackground(true);
    painter = new QPainter(this);
    allowBegin = true;
    tracking_pos = false;
    //painter->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);
    render = nullptr;
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
        Clicked(x, y);
        oldx = x;
        oldy = y;
    }

}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    if(tracking_pos)
    {
        Mouse(event->x() -oldx, event->y() - oldy);
        oldx = event->x();
        oldy = event->y();
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

        trender = false;
        CallDraw();
    }
}

void Canvas::drawEntity(const DrawStruct& drawData)
{
    QPainter* p = painter;
    if(trender) p = render;

    p->setPen(drawData.outline);
    p->setBrush(drawData.fill);

    const Transform& t = drawData.t;

    p->translate(t.px, t.py);
    p->rotate(t.r);
    p->translate(- t.sx / 2,- t.sy/2);

    switch(drawData.shape)
    {
    case DrawShapes::BG:
        break;
    case DrawShapes::Circle:
        p->drawEllipse(0, 0, t.sx, t.sy);
        break;
    case DrawShapes::Box:
        p->drawRect(0, 0, t.sx, t.sy);
        break;
    case DrawShapes::Line:
        p->drawLine(0, 0, t.sx, t.sy);
        break;
    }

    p->translate(t.sx / 2, t.sy/2);
    p->rotate(-t.r);
    p->translate(-t.px,-t.py);
}

void Canvas::executeEnd()
{
    if(allowBegin == false)
        painter->end();
    allowBegin = true;
}

void Canvas::Render()
{
    QString filename = QFileDialog::getSaveFileName(
                this,
                "Save Image File",
                "./",
                "PNG (*.png);;JPG (*.jpg)");

    QImage img(this->size(), QImage::Format_ARGB32);
    render = new QPainter(&img);
    render->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);
    trender = true;
    CallDraw();
    trender = false;
    render->end();
    delete render;
    render = nullptr;

    img.save(filename);
}

void Canvas::PickedEntity(uint id)
{
    if(id == UINT_MAX) tracking_pos = false;
}
