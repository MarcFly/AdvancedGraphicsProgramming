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
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    QPainter* painter;
    bool allowBegin;
    bool tracking_pos;
    bool trender;
    QImage img;
    QPainter* render;
    int oldx, oldy;

signals:
    void Clicked(int x, int y);
    void Mouse(int x, int y);
    void Release(int x, int y);
    void CallDraw();

public slots:
    void executeEnd();
    void drawEntity(const DrawStruct& drawData);
    void RePaint() {repaint();}
    void Render();
    void PickedEntity(uint id);
};

#endif // CANVAS_H
