#ifndef FILLOUTLINE_H
#define FILLOUTLINE_H

#include <QWidget>
#include <QPen>

class QColorDialog;

class canvasShow: public QWidget
{
    Q_OBJECT
public:
    explicit canvasShow(bool is_fp, QWidget *parent = nullptr);
    ~canvasShow();

    void paintEvent(QPaintEvent* ev) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

public:
    bool fp;
    QBrush* b;
    QPen* p;
    bool click;
    QColorDialog* cd;

public slots:
    void SetColor(const QColor& rgb);
signals:
    void sendUpdate();
};

class QLabel;
class QComboBox;
class QSpinBox;


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
    QSpinBox* width;
    canvasShow* expo;

signals:
    void sendUpdate();
    void SRepaint();

public slots:
    void change_fp(int val);
    void change_pw(int val);

};

#endif // FILLOUTLINE_H
