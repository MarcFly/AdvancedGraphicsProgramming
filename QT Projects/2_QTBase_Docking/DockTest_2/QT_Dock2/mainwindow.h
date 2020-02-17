#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
class Inspector;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots: // Capturar eventos

    void onLoadFile(/*void triggered*/);
    void onSaveFile(/*void triggered*/);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
