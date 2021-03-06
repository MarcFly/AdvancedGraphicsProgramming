/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QAction *actionSave;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *Hierarchy;
    QWidget *dockHierarchy;
    QDockWidget *Inspector;
    QWidget *dockInspector;
    QDockWidget *Project;
    QWidget *dockProject;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(487, 353);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad->setIcon(icon);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/Disquette.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 487, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        Hierarchy = new QDockWidget(MainWindow);
        Hierarchy->setObjectName(QString::fromUtf8("Hierarchy"));
        dockHierarchy = new QWidget();
        dockHierarchy->setObjectName(QString::fromUtf8("dockHierarchy"));
        Hierarchy->setWidget(dockHierarchy);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, Hierarchy);
        Inspector = new QDockWidget(MainWindow);
        Inspector->setObjectName(QString::fromUtf8("Inspector"));
        dockInspector = new QWidget();
        dockInspector->setObjectName(QString::fromUtf8("dockInspector"));
        Inspector->setWidget(dockInspector);
        MainWindow->addDockWidget(Qt::RightDockWidgetArea, Inspector);
        Project = new QDockWidget(MainWindow);
        Project->setObjectName(QString::fromUtf8("Project"));
        dockProject = new QWidget();
        dockProject->setObjectName(QString::fromUtf8("dockProject"));
        Project->setWidget(dockProject);
        MainWindow->addDockWidget(Qt::BottomDockWidgetArea, Project);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionSave);
        mainToolBar->addAction(actionLoad);
        mainToolBar->addAction(actionSave);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        Hierarchy->setWindowTitle(QCoreApplication::translate("MainWindow", "Hierarchy", nullptr));
        Inspector->setWindowTitle(QCoreApplication::translate("MainWindow", "Inspector", nullptr));
        Project->setWindowTitle(QCoreApplication::translate("MainWindow", "Project", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
