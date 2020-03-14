#ifndef FILLOUTLINE_H
#define FILLOUTLINE_H

#include <QWidget>
#include <QPen>

class canvasShow: public QWidget
{
    Q_OBJECT
public:
    explicit canvasShow(bool is_fp, QWidget *parent = nullptr);
    ~canvasShow();

    void paintEvent(QPaintEvent* ev) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void Repaint() {repaint();}

public:
    bool fp;
    QBrush* b;
    QPen* p;


signals:
    void Clicked();

};

class QLabel;
class QComboBox;

class FillOutline : public QWidget
{
    Q_OBJECT
public:
    explicit FillOutline(bool is_fp, QWidget *parent = nullptr);
    ~FillOutline();


    void Update(const QBrush& b, const QPen& p);

    QBrush GetFill()
    {
        return *expo->b;
    }

    QPen GetOutline()
    {
        return *expo->p;
    }
private:
    QLabel* title;
    QComboBox* types;
    canvasShow* expo;

signals:
    void sendUpdate();

public slots:
    void change_fp(int val);

};

#endif // FILLOUTLINE_H
