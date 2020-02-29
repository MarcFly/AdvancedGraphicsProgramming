#ifndef INSPECTOR_H
#define INSPECTOR_H

#include <QWidget>

namespace Ui {
    class Transform;
//    class Outline;
//    class Fill;
//    class Shape;
}

//===================================================
// Component Declarations //=========================
//===================================================

void SetupTransform(Ui::Transform* uiT);
void UpdateTransform(/**/);

//===================================================
//===================================================

class Inspector : public QWidget
{
    Q_OBJECT
public:
    explicit Inspector(QWidget *parent = nullptr);
    ~Inspector();

private:
    Ui::Transform *uiTransform;
//    Ui::Outline *uiOutline;
//    Ui::Fill *uiFill;
//    Ui::Shape *uiShape;

public slots:
    //void onEntitySelected(/**/);

signals:
    void UpdatedEntity(/* entity id */);

};

#endif // INSPECTOR_H
