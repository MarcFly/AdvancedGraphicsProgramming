#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include "Globals.h"

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);
    ~Canvas();

    void paintEvent(QPaintEvent* ev) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QPainter* painter;
    bool allowBegin;
    bool tracking_pos;
signals:
    void Clicked(int x, int y);
    void Mouse(int x, int y);
    void Release(int x, int y);
    void CallDraw();

public slots:
    void executeEnd();
    void drawEntity(const DrawStruct& drawData);
    void RePaint() {repaint();}
};

#endif // CANVAS_H
