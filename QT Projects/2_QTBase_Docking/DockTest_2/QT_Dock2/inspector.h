#ifndef INSPECTOR_H
#define INSPECTOR_H

#include <QWidget>

namespace Ui {
// We will not use the designer layout, we will use base inspector
// Here we add the widgets that are needed for the Inspector
class Transform;
class Color;
}

class Inspector : public QWidget
{
    Q_OBJECT

public:
    explicit Inspector(QWidget *parent = nullptr);
    ~Inspector();

private:
    Ui::Transform *uiTransform;
    Ui::Color *uiColor;

public slots:
    void onEntitySelected(/*entity* e*/ int row);
};

#endif // INSPECTOR_H
