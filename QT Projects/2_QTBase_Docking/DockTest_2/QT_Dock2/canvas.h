#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent* ev) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
signals:

public slots:
};

#endif // CANVAS_H
