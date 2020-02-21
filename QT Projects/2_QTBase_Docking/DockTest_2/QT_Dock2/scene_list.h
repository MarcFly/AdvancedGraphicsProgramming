#ifndef SCENE_LIST_H
#define SCENE_LIST_H

#include <QWidget>

struct float4
{
    float x,y,z,w;
};

struct Entity
{

    std::vector<std::pair<int,float4>> fake_comps;
};

namespace Ui {
class scene_list;
}

struct Entity;

class scene_list : public QWidget
{
    Q_OBJECT

public:
    explicit scene_list(QWidget *parent = nullptr);
    ~scene_list();

private:
    Ui::scene_list *ui;
    std::vector<Entity*> entitties;

public slots:
    void onAdd();
    void onRemove();
    void onEntitySelected(int row);

signals: // no requeren definicion de proteccion (public, private o protected)
    void EntitySelect(/*Entity* e*/ Entity* e);
};

#endif // SCENE_LIST_H
