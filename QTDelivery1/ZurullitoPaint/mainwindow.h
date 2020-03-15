#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class ECS;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ECS* ecs;
public slots:
    void onOpenFile();
    void onSaveFile();
    void onExit();

signals:
    void askOpenFile(QString filename);
    void askSaveFile(QString filename);
};
#endif // MAINWINDOW_H
