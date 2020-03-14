#include "hierarchy.h"
#include "ui_hierarchy.h"

#include <QDateTime> // For random id generation

Hierarchy::Hierarchy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hierarchy),
    itemcount(0),
    fromAR(false),
    fromNF(false)
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
    if(prev != nullptr && !fromAR & !fromNF)
    {
        QTimer ss_t;
        uint id = prev->data(1, Qt::DisplayRole).toUInt();
        //uint tid = (prev->parent() == nullptr) ? NULL : prev->parent()->data(1, Qt::DisplayRole).toUInt();

        ss_t.singleShot(500, nullptr, [id, prev, this]
        {
            if(prev != nullptr)
            {
                uint p_id = (prev->parent() == nullptr) ? NULL : prev->parent()->data(1, Qt::DisplayRole).toUInt();
                uint pos = this->currItemPos(prev);
                updateParenting(id, p_id, pos);
            }

        });
    }

    fromAR = fromNF = false;


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
    fromAR = true;

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

void Hierarchy::newFile()
{
    fromNF  = true;
    ui->treeHierarchy->clearSelection();
    ui->treeHierarchy->setCurrentItem(nullptr);

    while(ui->treeHierarchy->topLevelItemCount() > 0)
    {
        RecursiveRemove(ui->treeHierarchy->topLevelItem(0));
    }
}

void Hierarchy::AddToHierarchy(uint id, uint p_id)
{
    QString text = QString::number(p_id);
    QList<QTreeWidgetItem*> items = ui->treeHierarchy->findItems( text, Qt::MatchExactly|Qt::MatchRecursive);
    QTreeWidgetItem* newE = new QTreeWidgetItem();
    newE->setData(0, Qt::DisplayRole, QString("temp_name_").append(QString::number(itemcount)));
    newE->setData(1, Qt::DisplayRole, id);

    if(items.size() > 0)
        items[0]->addChild(newE);
    else
    {
        ui->treeHierarchy->addTopLevelItem(newE);
    }

}
