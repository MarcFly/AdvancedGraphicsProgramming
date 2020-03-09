#ifndef INSPECTOR_H
#define INSPECTOR_H

#include <QWidget>
#include "Globals.h"
namespace Ui {
    class Transform;
}

//===================================================
// Component Declarations //=========================
//===================================================

void SetupTransform(Ui::Transform* uiT);
void UpdateTransform(Ui::Transform* uiT, const Transform& t);

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
    void updateEntity(const DrawStruct& drawData);

signals:
    void UpdatedEntity(/* entity id */);

};

#endif // INSPECTOR_H
