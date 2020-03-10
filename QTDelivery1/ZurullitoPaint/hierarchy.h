#ifndef HIERARCHY_H
#define HIERARCHY_H

#include <QWidget>
#include <QTimer>

class QTreeWidgetItem;

namespace Ui {
class Hierarchy;
}

class Hierarchy : public QWidget
{
    Q_OBJECT

public:
    explicit Hierarchy(QWidget *parent = nullptr);
    ~Hierarchy();

private:
    void RecursiveRemove(QTreeWidgetItem* curr);
    void BlockButtons();
    uint currItemPos(QTreeWidgetItem* curr);
private:
    Ui::Hierarchy *ui;
    uint itemcount;
    QTimer ar_block;
    bool fromAR;
public slots:
    void onAdd();
    void onRemove();
    void currItemChanged(QTreeWidgetItem* cur, QTreeWidgetItem* prev);
    void changedName(const char* name);
signals:
    void AddEntity(uint id, uint parent_id);
    void RemoveEntity(uint id);
    void entitySelected(uint id);
    void updateParenting(uint id, uint p_id, uint pos);
};

#endif // HIERARCHY_H
