#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "inspector.h" // Include Inspector to main window
#include "hierarchy.h" // "" Hierrachy to main window
#include "canvas.h"
#include <QVBoxLayout>
#include "ecs.h"
#include "Globals.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , ecs(new ECS(nullptr))
{
    ui->setupUi(this);



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

    // Create a Canvas in the Central Widget
    Canvas* wcanvas = new Canvas(ui->centralwidget);
    ui->centralwidget->setLayout(new QVBoxLayout());
    ui->centralwidget->layout()->addWidget(wcanvas);

    // Connect ecs and canvas draw signals and slots
    connect(ecs, SIGNAL(askDraw(DrawStruct)), wcanvas, SLOT(drawEntity(DrawStruct)));
    connect(ecs, SIGNAL(callEnd()), wcanvas, SLOT(executeEnd()));
    connect(ecs, SIGNAL(callRePaint()), wcanvas, SLOT(RePaint()));

    connect(wcanvas, SIGNAL(CallDraw()), ecs, SLOT(executeDraw()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

