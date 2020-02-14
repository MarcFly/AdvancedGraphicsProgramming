#ifndef DMAIN_H
#define DMAIN_H

#include <QMainWindow>

namespace Ui {
class dmain;
}

class dmain : public QMainWindow
{
    Q_OBJECT

public:
    explicit dmain(QWidget *parent = nullptr);
    ~dmain();

private:
    Ui::dmain *ui;
};

#endif // DMAIN_H
