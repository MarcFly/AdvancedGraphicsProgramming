#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "inspector.h" // Include Inspector to main window
#include "hierarchy.h" // "" Hierrachy to main window
#include "canvas.h"
#include <QVBoxLayout>
#include "ecs.h"
#include "Globals.h"

#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , ecs(new ECS(nullptr))
{
    ui->setupUi(this);

    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(onSaveFile()));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(onOpenFile()));
    connect(this, SIGNAL(askSaveFile(QString)), ecs, SLOT(onSaveFile(QString)));
    connect(this, SIGNAL(askOpenFile(QString)), ecs, SLOT(onOpenFile(QString)));
    connect(ui->actionEXIT, SIGNAL(triggered()), this, SLOT(onExit()));

    // Linking Inspector Widget to Inspector Dock
    Inspector* insp = new Inspector();
    insp->show();
    ui->dockInspector->setWidget(insp);

    // Connect ecs and Inspector signals and slots
    connect(ecs, SIGNAL(selectedEntity(const uint, const char*,const DrawStruct&)), insp, SLOT(updateEntity(const uint, const char*, const DrawStruct&)));
    connect(insp, SIGNAL(UpdatedEntity(const uint, const char*, DrawStruct&)), ecs, SLOT(updatedEntity(const uint, const char*, DrawStruct&)));

    // Linking Hierarchy Widget to Widget Dock
    Hierarchy* hier = new Hierarchy();
    hier->show();
    ui->dockHierarchy->setWidget(hier);

    // Connect ecs and hierarchy signals and slots
    connect(hier, SIGNAL(AddEntity(uint,uint)), ecs, SLOT(AddEntity(uint,uint)));
    connect(hier, SIGNAL(RemoveEntity(uint)), ecs, SLOT(RemoveEntity(uint)));
    connect(hier, SIGNAL(entitySelected(uint)), ecs, SLOT(entitySelected(uint)));
    connect(hier, SIGNAL(updateParenting(uint,uint,uint)), ecs, SLOT(updateParenting(uint,uint,uint)));

    connect(ecs, SIGNAL(changedName(const char*)), hier, SLOT(changedName(const char*)));
    connect(ecs, SIGNAL(SendToHierarchy(uint, uint)),hier, SLOT(AddToHierarchy(uint, uint)));
    connect(ecs, SIGNAL(MousePickSelect(uint)), hier, SLOT(MousePickSelect(uint)));

    // Connect Inspector and Hierarhcy signals and slots
    connect(hier, SIGNAL(SelectionCleared()), insp, SLOT(NoSelection()));

    // Connect MainWindow and Hierarchy
    connect(ui->actionNew, SIGNAL(triggered()), hier, SLOT(newFile()));

    // Create a Canvas in the Central Widget
    Canvas* wcanvas = new Canvas(ui->centralwidget);
    ui->centralwidget->setLayout(new QVBoxLayout());
    ui->centralwidget->layout()->addWidget(wcanvas);

    // Connect Main Window and Canvas
    connect(ui->actionRender, SIGNAL(triggered()), wcanvas, SLOT(Render()));

    // Connect ecs and canvas draw signals and slots
    connect(ecs, SIGNAL(askDraw(DrawStruct)), wcanvas, SLOT(drawEntity(DrawStruct)));
    connect(ecs, SIGNAL(callEnd()), wcanvas, SLOT(executeEnd()));
    connect(ecs, SIGNAL(callRePaint()), wcanvas, SLOT(RePaint()));

    connect(ecs, SIGNAL(MousePickSelect(uint)), wcanvas, SLOT(PickedEntity(uint)));
    connect(wcanvas, SIGNAL(Clicked(int, int)), ecs, SLOT(MousePick(int, int)));
    connect(wcanvas, SIGNAL(CallDraw()), ecs, SLOT(executeDraw()));

    // Connect canvas and inspector
    connect(wcanvas, SIGNAL(Mouse(int, int)), insp, SLOT(MouseMove(int, int)));

    hier->newFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onOpenFile()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                "Open a scene file",
                "./",
                "AWOOGA file (*.awooga)");

    ui->actionNew->triggered();

    if(!filename.isEmpty())
        askOpenFile(filename);
}

void MainWindow::onSaveFile()
{
    QString filename = QFileDialog::getSaveFileName(
                this,
                "Save a scene file",
                "./",
                "AWOOGA file (*.awooga");

    if(!filename.isEmpty())
        askSaveFile(filename);
}

void MainWindow::onExit()
{
    QMessageBox msgBox;
    msgBox.setText("Before closing, do you want to save your scene?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    bool tclose = true;

    switch(ret)
    {
    case QMessageBox::Save:
        onSaveFile();
        tclose = true;
        break;
    case QMessageBox::Cancel:
        tclose = false;
        break;
    case QMessageBox::Discard:
        tclose = true;
        break;
    }

    if(tclose)
    {
        close();
    }
}
