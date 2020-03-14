#include "filloutline.h"

#include <QPainter>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>

//===================================================================
canvasShow::canvasShow(bool is_fp, QWidget* parent) : QWidget(parent), fp(is_fp)
{
    setAutoFillBackground(true);
    b = new QBrush();
    p = new QPen();

    b->setStyle(Qt::BrushStyle::NoBrush);
    p->setStyle(Qt::PenStyle::NoPen);
}

canvasShow::~canvasShow()
{
    delete b;
    delete p;
}

QSize canvasShow::minimumSizeHint() const
{
    return QSize(16,16);
}

QSize canvasShow::sizeHint() const
{
    return QSize(64,64);
}

void canvasShow::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    QSize s = this->size();

    // Draw White background
    QPen wp;
    QBrush wb;
    wb.setColor(QColor::fromRgb(255,255,255));
    wb.setStyle(Qt::BrushStyle::SolidPattern);

    wp.setColor(QColor::fromRgb(0,0,0));
    wp.setStyle(Qt::PenStyle::NoPen);

    painter.setPen(wp);
    painter.setBrush(wb);
    painter.drawRect(0,0, s.width(), s.height());

    // Draw intended result
    painter.setPen(*p);
    painter.setBrush(*b);

    if(fp)
        painter.drawRect(0,0, s.width(), s.height());
    else
        painter.drawLine(0,0, s.width(), s.height());
}

//===================================================================

FillOutline::FillOutline(bool is_fp, QWidget *parent) : QWidget(parent)
{
    QHBoxLayout* layout = new QHBoxLayout();

    title = new QLabel((is_fp) ? "Fill" : "Outline" ,this);

    layout->addWidget(title);

    QStringList strings;
    if(is_fp)
    {
        strings.push_back("NoFill");
        strings.push_back("Solid");
        strings.push_back("Dense1");
        strings.push_back("Dense2");
        strings.push_back("Dense3");
        strings.push_back("Dense4");
        strings.push_back("Dense5");
        strings.push_back("Dense6");
        strings.push_back("Dense7");
        strings.push_back("Horizontal");
        strings.push_back("Vertical");
        strings.push_back("Cross");
        strings.push_back("Up Diagonal");
        strings.push_back("Down Diagonal");
        strings.push_back("Cross Diagonal");
    }
    else
    {
        strings.push_back("No Outline");
        strings.push_back("Solid");
        strings.push_back("Dash");
        strings.push_back("Dot");
        strings.push_back("Dash Dot");
        strings.push_back("Dash Dot Dot");
    }

    types = new QComboBox(this);
    types->addItems(strings);
    layout->addWidget(types);

    width = new QSpinBox(this);
    width->hide();
    if(!is_fp)
    {
        width->show();
        width->setRange(1,999999);
        //width->setValue(1);
        layout->addWidget(width);
    }

    expo = new canvasShow(is_fp, this);
    layout->addWidget(expo);

    setLayout(layout);

    // Connect intern components
    connect(types, SIGNAL(currentIndexChanged(int)), this, SLOT(change_fp(int)));

    connect(width, SIGNAL(valueChanged(int)), this, SLOT(change_pw(int)));
}

FillOutline::~FillOutline()
{
    delete expo;
    delete types;
    delete title;
    delete width;
}

void FillOutline::change_fp(int val)
{
    if(expo->fp )
        expo->b->setStyle((Qt::BrushStyle)val);
    else
        expo->p->setStyle((Qt::PenStyle)val);

    expo->repaint();
    sendUpdate();
}

void FillOutline::change_pw(int val)
{
    if(!expo->fp)
    {
        expo->p->setWidth(val);
        expo->repaint();
        sendUpdate();
    }
}

void FillOutline::Update(const QBrush &b, const QPen &p)
{
    if(expo->fp)
    {
        delete expo->b;
        expo->b = new QBrush(b);
        types->setCurrentIndex((int)b.style());
    }
    else
    {
        delete expo->p;
        expo->p = new QPen(p);
        types->setCurrentIndex((int)p.style());
    }



}


