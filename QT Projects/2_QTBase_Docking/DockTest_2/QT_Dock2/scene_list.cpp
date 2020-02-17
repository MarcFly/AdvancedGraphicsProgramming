#include "scene_list.h"
#include "ui_scene_list.h"

scene_list::scene_list(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::scene_list)
{
    ui->setupUi(this);

    connect(ui->add, SIGNAL(clicked()), this, SLOT(onAdd()));
    connect(ui->remove, SIGNAL(clicked()), this, SLOT(onRemove()));
    connect(ui->list, SIGNAL(currentRowChanged(int)), this, SLOT(onEntitySelected(int)));
}

scene_list::~scene_list()
{
    delete ui;
}

// Functions Add and Remove

void scene_list::onAdd()
{
    ui->list->addItem("Entity");
}

void scene_list::onRemove()
{
    ui->list->takeItem(ui->list->currentRow());
}

void scene_list::onEntitySelected(int row)
{
    emit(EntitySelect(row));
}
