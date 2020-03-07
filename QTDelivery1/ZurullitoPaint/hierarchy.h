#ifndef HIERARCHY_H
#define HIERARCHY_H

#include <QWidget>

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

private:
    Ui::Hierarchy *ui;
    uint itemcount;

public slots:
    void onAdd();
    void onRemove();

signals:
    void AddEntity(uint id, uint parent_id);
    void RemoveEntity(uint id);
};

#endif // HIERARCHY_H
