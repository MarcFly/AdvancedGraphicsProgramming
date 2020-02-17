#include "inspector.h"
#include "ui_transform.h"
#include "ui_color.h"
#include <QVBoxLayout> // A Layout that can hold widgets
#include <QSpacerItem> // The Spring that presses things together
Inspector::Inspector(QWidget *parent) :
    QWidget(parent), uiTransform(new Ui::Transform), uiColor(new Ui::Color)
{
    QVBoxLayout* layout = new QVBoxLayout();
    // Create the widgets needed
    QWidget* wtransform = new QWidget();
    uiTransform->setupUi(wtransform);

    QWidget* wcolor = new QWidget();
    uiColor->setupUi(wcolor);

    // Add the widgets to the layout
    layout->addWidget(wtransform);
    layout->addWidget(wcolor);
    layout->addItem(new QSpacerItem(1,1,QSizePolicy::Expanding, QSizePolicy::Expanding));
    setLayout(layout);
}

Inspector::~Inspector()
{
    delete uiColor;

    delete uiTransform;
}

void Inspector::onEntitySelected(int row)
{
    // change detected
    int tt = row;
}



