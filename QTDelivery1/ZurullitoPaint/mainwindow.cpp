#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "inspector.h" // Include Inspector to main window

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    // Linking Inspector Widget to Inspector Dock
    Inspector* insp = new Inspector();
    insp->show();
    ui->dockInspector->setWidget(insp);
}

MainWindow::~MainWindow()
{
    delete ui;
}

