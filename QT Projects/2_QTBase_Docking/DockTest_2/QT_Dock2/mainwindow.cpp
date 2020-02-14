#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "transform.h" Si se hace el codigo del widget
#include "ui_transform.h" // para meter el
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
    uiInspector = new Ui::Transform; // Initialize the ui element
    QWidget* TWidget = new QWidget(); // Initialize the Widget
    uiInspector->setupUi(TWidget); // Setup the Inspector UI with the widget
    ui->Inspector->setWidget(TWidget); // attach the widget to the dock

    // now uiInspector will hold every data about the setup widgets inside


    // Connect Signals to Slots
    connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT(onLoadFile()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(onSaveFile()));
}

MainWindow::~MainWindow()
{
    delete ui; // Delete Main Window

    delete uiInspector; // Delete the Inspector Dock/Widget
}

void MainWindow::onLoadFile()
{
    bool test = false;
    return;
}

void MainWindow::onSaveFile()
{
    bool test = false;
    return;
}
