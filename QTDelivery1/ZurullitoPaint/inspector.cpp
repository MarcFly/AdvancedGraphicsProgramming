#include "inspector.h"
#include "ui_transform.h"

#include <iostream>

#include <QVBoxLayout>
#include <QSpacerItem>
#include <QTextEdit>

Inspector::Inspector(QWidget *parent) :
    QWidget(parent), uiTransform(new Ui::Transform),
    curr_id(UINT_MAX), updating(false)
{
    QVBoxLayout* layout = new QVBoxLayout();

    // Create and add the widgets to the layout
    QFrame* line = new QFrame(this);
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    // Name - basic text edit

    uiName = new QTextEdit(QString("tempname"), this);
    uiName->setFixedHeight(30);
    layout->addWidget(uiName);

    connect(uiName, SIGNAL(textChanged()), this, SLOT(sendUpdate()));

    layout->addWidget(line);

    // Transform
    QWidget* wtransform = new QWidget();
    uiTransform->setupUi(wtransform);
    layout->addWidget(wtransform);
    SetupTransform();

    line = new QFrame(this);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
    layout->addWidget(line);

    //  Shape


    line = new QFrame(this);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
    layout->addWidget(line);

    //  Brush / Fill

    line = new QFrame(this);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
    layout->addWidget(line);

    //  Pen / Outline



    // Vertical Spacer to push things up just in case
    layout->addItem(new QSpacerItem(1,1,QSizePolicy::Expanding, QSizePolicy::Expanding));

    // Set widget layout to the one we have created
    setLayout(layout);
}

Inspector::~Inspector()
{
    // Inverse order delete
    delete uiName;
    delete uiTransform;
}

void Inspector::updateEntity(const uint id, const char* name,const DrawStruct& drawData)
{
    updating = true;

    curr_id = id;
    uiName->setText(QString(name));
    UpdateTransform(drawData.t);
    // Brush, Pen, Shape
    switch(drawData.shape)
    {
    case DrawShapes::BG:
    case DrawShapes::Circle:
    case DrawShapes::Box:
        uiTransform->labelScale->setText("Scale");
        break;
    case DrawShapes::Line:
        uiTransform->labelScale->setText("Position 2");
        break;
    }

    updating = false;
}

void Inspector::sendUpdate()
{
    if(!updating)
    {
        DrawStruct dD;
        dD.t.px = uiTransform->PX->value();
        dD.t.py = uiTransform->PY->value();
        dD.t.sx = uiTransform->SX->value();
        dD.t.sy = uiTransform->SY->value();
        dD.t.r = uiTransform->Rdial->value();

        std::string str = uiName->toPlainText().toStdString();
        UpdatedEntity(curr_id, str.c_str(), dD);
    }
}

//===================================================
// Transform Setup //================================
//===================================================

void Inspector::SetupTransform()
{

    uiTransform->Rdial->setWrapping(true);
    uiTransform->Rdial->setTracking(true);
    uiTransform->Rdial->setRange(0,360);
    uiTransform->Rinput->setMaximum(360);
    Inspector::connect(uiTransform->Rdial, SIGNAL(valueChanged(int)), uiTransform->Rinput, SLOT(setValue(int)));
    Inspector::connect(uiTransform->Rinput, SIGNAL(valueChanged(int)), uiTransform->Rdial, SLOT(setValue(int)));

    uiTransform->PX->setRange(LONG_MIN, LONG_MAX);
    uiTransform->PY->setRange(LONG_MIN, LONG_MAX);
    uiTransform->SX->setRange(LONG_MIN, LONG_MAX);
    uiTransform->SY->setRange(LONG_MIN, LONG_MAX);

    Inspector::connect(uiTransform->Rdial, SIGNAL(valueChanged(int)), this, SLOT(sendUpdate()));
    Inspector::connect(uiTransform->Rinput, SIGNAL(valueChanged(int)), this, SLOT(sendUpdate()));
    Inspector::connect(uiTransform->PX, SIGNAL(valueChanged(double)), this, SLOT(sendUpdate()));
    Inspector::connect(uiTransform->PY, SIGNAL(valueChanged(double)), this, SLOT(sendUpdate()));
    Inspector::connect(uiTransform->SX, SIGNAL(valueChanged(double)), this, SLOT(sendUpdate()));
    Inspector::connect(uiTransform->SY, SIGNAL(valueChanged(double)), this, SLOT(sendUpdate()));
}

void Inspector::UpdateTransform(const Transform& t)
{
    uiTransform->Rdial->setValue(t.r);
    uiTransform->Rinput->setValue(t.r);

    uiTransform->PX->setValue(t.px);
    uiTransform->PY->setValue(t.py);
    uiTransform->SX->setValue(t.sx);
    uiTransform->SY->setValue(t.sy);

}

//===================================================
//===================================================
