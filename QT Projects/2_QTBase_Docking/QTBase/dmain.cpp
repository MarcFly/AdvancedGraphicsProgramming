#include "dmain.h"
#include "ui_dmain.h"

dmain::dmain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dmain)
{
    ui->setupUi(this);

    // test docks
    /*QDockWidget* dW = new QDockWidget;
    dW->setWindowTitle("Lighting");
    this->addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, dW);
    //tabifyDockWidget(Ui_dmain->renderingDock, dW); ?? UiMainWindow?*/
}

dmain::~dmain()
{
    delete ui;
}
