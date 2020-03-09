#include "inspector.h"
#include "ui_transform.h"

#include <iostream>

#include <QVBoxLayout>
#include <QSpacerItem>

Inspector::Inspector(QWidget *parent) :
    QWidget(parent), uiTransform(new Ui::Transform)
{
    QVBoxLayout* layout = new QVBoxLayout();

    // Create and add the widgets to the layout
    QWidget* wtransform = new QWidget();
    uiTransform->setupUi(wtransform);
    layout->addWidget(wtransform);
    SetupTransform(uiTransform);

    // Set widget layout to the one we have created
    setLayout(layout);
}

Inspector::~Inspector()
{
    // Inverse order delete

    delete uiTransform;
}

void Inspector::updateEntity(const DrawStruct& drawData)
{
    UpdateTransform(uiTransform, drawData.t);
}

//===================================================
// Transform Setup //================================
//===================================================

void SetupTransform(Ui::Transform *uiT)
{
    uiT->Rdial->setWrapping(true);
    uiT->Rdial->setTracking(true);
    uiT->Rdial->setRange(0,360);
    uiT->Rinput->setMaximum(360);
    Inspector::connect(uiT->Rdial, SIGNAL(valueChanged(int)), uiT->Rinput, SLOT(setValue(int)));
    Inspector::connect(uiT->Rinput, SIGNAL(valueChanged(int)), uiT->Rdial, SLOT(setValue(int)));
}

void UpdateTransform(Ui::Transform* uiT,const Transform& t)
{
    uiT->Rdial->setValue(t.r);
    uiT->Rinput->setValue(t.r);
}

//===================================================
//===================================================
