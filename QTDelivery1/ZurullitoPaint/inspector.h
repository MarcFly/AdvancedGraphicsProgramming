#ifndef INSPECTOR_H
#define INSPECTOR_H

#include <QWidget>
#include "Globals.h"

class QTextEdit;

namespace Ui {
    class Transform;
}

class Inspector : public QWidget
{
    Q_OBJECT
public:
    explicit Inspector(QWidget *parent = nullptr);
    ~Inspector();

    void SetupTransform();
    void UpdateTransform(const Transform& t);

private:
    QTextEdit* uiName;
    Ui::Transform *uiTransform;
//    Ui::Outline *uiOutline;
//    Ui::Fill *uiFill;
//    Ui::Shape *uiShape;

    uint curr_id;
    bool updating;

public slots:
    void updateEntity(const uint id, const char* name, const DrawStruct& drawData);
    void sendUpdate();
signals:
    void UpdatedEntity(const uint id, const char* name, DrawStruct& drawData);
};

#endif // INSPECTOR_H
