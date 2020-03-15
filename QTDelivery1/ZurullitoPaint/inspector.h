#ifndef INSPECTOR_H
#define INSPECTOR_H

#include <QWidget>
#include "Globals.h"

class QTextEdit;

namespace Ui {
    class Transform;
    class Shape;
}

class FillOutline;

class Inspector : public QWidget
{
    Q_OBJECT
public:
    explicit Inspector(QWidget *parent = nullptr);
    ~Inspector();

    void SetupTransform();
    void UpdateTransform(const Transform& t);

    void SetupShape();
    void UpdateShape(const DrawShapes& s);

    void SetupFillOutline(bool is_fp);
    void UpdateFill(const QBrush& b);
    void UpdateOutline(const QPen& p);

private:
    QTextEdit* uiName;
    Ui::Transform *uiTransform;
    FillOutline *uiOutline;
    FillOutline *uiFill;
    Ui::Shape *uiShape;

    uint curr_id;
    bool updating;
    QStringList strings;

public slots:
    void updateEntity(const uint id, const char* name, const DrawStruct& drawData);
    void sendUpdate();
    void NoSelection();
    void MouseMove(int dx, int dy);
signals:
    void UpdatedEntity(const uint id, const char* name, DrawStruct& drawData);
};

#endif // INSPECTOR_H
