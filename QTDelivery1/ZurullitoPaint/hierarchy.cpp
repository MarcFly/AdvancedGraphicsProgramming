#include "hierarchy.h"
#include "ui_hierarchy.h"

#include <QDateTime> // For random id generation

Hierarchy::Hierarchy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hierarchy),
    itemcount(0)
{
    ui->setupUi(this);

    // Setup the tree
    ui->treeHierarchy->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->treeHierarchy->setDragEnabled(true);
    ui->treeHierarchy->setAcceptDrops(true);
    ui->treeHierarchy->setDropIndicatorShown(true);
    ui->treeHierarchy->setDragDropMode(QAbstractItemView::InternalMove);

    connect(ui->treeHierarchy, SIGNAL(currentItemChanged(QTreeWidgetItem*, QTreeWidgetItem*)), this, SLOT(currItemChanged(QTreeWidgetItem*, QTreeWidgetItem*)));

    // Connect the signals and slots from the buttons to functions to add thigngs
    connect(ui->buttonAdd, SIGNAL(clicked()), this, SLOT(onAdd()));
    connect(ui->buttonRemove, SIGNAL(clicked()), this, SLOT(onRemove()));
}

Hierarchy::~Hierarchy()
{
    for(int i = 0; i < ui->treeHierarchy->topLevelItemCount(); i++)
        RecursiveRemove( ui->treeHierarchy->topLevelItem(i));

    delete ui;
}
void Hierarchy::currItemChanged(QTreeWidgetItem* cur, QTreeWidgetItem* prev)
{
    if(cur != nullptr)
        entitySelected(cur->data(1, Qt::DisplayRole).toUInt());

    // Issue, tree parenting is not updated when this is called
    if(prev != nullptr)
    {
        if(prev->parent() != nullptr)
            updateParenting(prev->data(1, Qt::DisplayRole).toUInt(), prev->parent()->data(1, Qt::DisplayRole).toUInt(), currItemPos(prev));
        else
            updateParenting(prev->data(1, Qt::DisplayRole).toUInt(), NULL, currItemPos(prev));
    }
}

uint Hierarchy::currItemPos(QTreeWidgetItem* curr)
{
    uint ret = 0;

    if(curr->parent() == nullptr)
    {
        while(ui->treeHierarchy->topLevelItem(ret) != curr && ret < ui->treeHierarchy->topLevelItemCount())
            ret++;
    }
    else
    {
        while(curr->parent()->child(ret) != curr && ret < curr->parent()->childCount())
            ret++;
    }

    return ret;
}

void Hierarchy::changedName(const char* name)
{
    ui->treeHierarchy->currentItem()->setData(0, Qt::DisplayRole, QString(name));
}

void Hierarchy::onAdd()
{
    itemcount++;

    // Initialize random seed
    qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);
    uint id = qrand();

    QTreeWidgetItem* new_item = new QTreeWidgetItem();
    new_item->setData( 0, Qt::DisplayRole, QString("new_item_").append(std::to_string(itemcount).c_str()));
    new_item->setData( 1, Qt::DisplayRole, id);

    QTreeWidgetItem* curr = ui->treeHierarchy->currentItem();

    if(!curr)
    {

       ui->treeHierarchy->addTopLevelItem(new_item);
       AddEntity(id, NULL);

    }
    else
    {
        curr->addChild(new_item);
        AddEntity(id, curr->data(1, Qt::DisplayRole).toUInt());
    }

    ui->buttonAdd->setDisabled(true);
    ui->buttonRemove->setDisabled(true);
    ar_block.singleShot(1000, [this]{
        this->ui->buttonAdd->setDisabled(false);
        this->ui->buttonRemove->setDisabled(false);
    });
}


void Hierarchy::onRemove()
{
    QTreeWidgetItem* curr = ui->treeHierarchy->currentItem();
    if(curr) RecursiveRemove(curr);

    ui->buttonAdd->setDisabled(true);
    ui->buttonRemove->setDisabled(true);
    ar_block.singleShot(1000, [this]{
        this->ui->buttonAdd->setDisabled(false);
        this->ui->buttonRemove->setDisabled(false);
    });

}

void Hierarchy::RecursiveRemove(QTreeWidgetItem* curr)
{
    while(curr->childCount() > 0)
        RecursiveRemove(curr->child(0));

    RemoveEntity(curr->data(1, Qt::DisplayRole).toUInt());
    QTreeWidgetItem* p = curr->parent();
    if(p)
        p->removeChild(curr);
    else
    {
        ui->treeHierarchy->removeItemWidget(curr, 0);
        ui->treeHierarchy->removeItemWidget(curr, 1);
    }
    delete curr;
    curr = nullptr;
    itemcount--;
}
