#include "mainwindow.h"
#include "ui_mainwindow.h"
// #include "transform.h" Si se hace el codigo del widget
// #include "ui_transform.h" // para meter el elemento de ui directamente
#include "inspector.h"
#include "scene_list.h"

#include <iostream>

#include <QMessageBox> // include the MessageBox for user interaction
#include <QFileDialog> // "" File Dialogs

#include "canvas.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Si utilizamos el h y cpp creado directamente ---------------------------------------
    //Transform *t = new Transform(); // creates a new widget of tiype Transform

    //t->show();

    //ui->Inspector->setWidget(t); // Esto pone como main widget el que le pongas

    // Si utilizamos solo el .ui --------------------------------------------------------
    // new empty widget -> setupUI del widget -> poner el widget en el dock
//    uiTransform = new Ui::Transform; // Initialize the ui element
//    QWidget* TWidget = new QWidget(); // Initialize the Widget
//    uiTransform->setupUi(TWidget); // Setup the Inspector UI with the widget
//    ui->
//    ui->setWidget(TWidget); // attach the widget to the dock

    // --------------------------------------------------------------------------------------
    // Connect Signals to Slots
    connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT(onLoadFile()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(onSaveFile()));

    // Scene_list connection to Hierarchy Dock
    scene_list* slist = new scene_list();
    slist->show();
    ui->Hierarchy->setWidget(slist);

    // Inspector Widget connect to Inspector Dock
    Inspector* insp = new Inspector(); // Create base insp widget
    insp->show(); // show it
    ui->Inspector->setWidget(insp); // Setup Inspector dock with Inspector widget

    // When connecting a signal from a class that is not included in another one
    // a middle part has to go and connect one that knows both
    // in this case, in main window that has both widgets/docks, connect widget 1 signal with widget 2 slot
    connect(ui->Hierarchy->widget(), SIGNAL(EntitySelect(int)), ui->Inspector->widget(), SLOT(onEntitySelected(int)));
    // As the widget is linked to the dock widget, you have to go into ->DockWidget->Widget() to get the programatic widget

    // --------------------------------------------------------------------------------------

    Canvas* wcanvas = new Canvas(ui->centralWidget); // Create a base canvas
    ui->centralWidget->setLayout(new QVBoxLayout()); // Give the centralWidget a Layout
    ui->centralWidget->layout()->addWidget(wcanvas); // add the canvas widget to the central Widget


}

MainWindow::~MainWindow()
{
    delete ui; // Delete Main Window
}

void MainWindow::onLoadFile()
{

    // Test Code for app exit
//    QMessageBox::StandardButton button = QMessageBox::question(
//                this, // parent
//                "Exit Application", // Box Title
//                "Do you want to exit without Saving?"); // Actual Message
//    if (button == QMessageBox::Yes)
//    {
//        std::cout << "Exit without saving changes" << std::endl;
//    }
//    else
//    {
//     std::cout << "Cancel exit" << std::endl;
//    }

    // Open File Dialog
    QString path = QFileDialog::getOpenFileName(
                this, // parent
                "Open File" // , // Title
                // start directory, default is working directory
                // file filters by types,
                // selected filters,
                // options ?
                );
    if (!path.isEmpty())
    {
        std::cout << path.toStdString() << std::endl;
        QMessageBox::information(this, "Has intentau cargar ehto", path);
    }
}

void MainWindow::onSaveFile()
{
    bool test = false;
    return;
}
