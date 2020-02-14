/********************************************************************************
** Form generated from reading UI file 'dmain.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DMAIN_H
#define UI_DMAIN_H

#include <QtCore/QLocale>
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

class Ui_dmain
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuBaseWindow;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *Hierarchy;
    QWidget *dockWidgetContents;
    QDockWidget *Inspector;
    QWidget *dockWidgetContents_5;
    QDockWidget *Project;
    QWidget *dockWidgetContents_6;
    QDockWidget *Rendering;
    QWidget *dockWidgetContents_7;

    void setupUi(QMainWindow *dmain)
    {
        if (dmain->objectName().isEmpty())
            dmain->setObjectName(QString::fromUtf8("dmain"));
        dmain->resize(400, 409);
        centralWidget = new QWidget(dmain);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        dmain->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(dmain);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuBaseWindow = new QMenu(menuBar);
        menuBaseWindow->setObjectName(QString::fromUtf8("menuBaseWindow"));
        dmain->setMenuBar(menuBar);
        mainToolBar = new QToolBar(dmain);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        dmain->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(dmain);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        dmain->setStatusBar(statusBar);
        Hierarchy = new QDockWidget(dmain);
        Hierarchy->setObjectName(QString::fromUtf8("Hierarchy"));
        Hierarchy->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        Hierarchy->setWidget(dockWidgetContents);
        dmain->addDockWidget(static_cast<Qt::DockWidgetArea>(1), Hierarchy);
        Inspector = new QDockWidget(dmain);
        Inspector->setObjectName(QString::fromUtf8("Inspector"));
        Inspector->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QString::fromUtf8("dockWidgetContents_5"));
        Inspector->setWidget(dockWidgetContents_5);
        dmain->addDockWidget(static_cast<Qt::DockWidgetArea>(2), Inspector);
        Project = new QDockWidget(dmain);
        Project->setObjectName(QString::fromUtf8("Project"));
        Project->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        dockWidgetContents_6 = new QWidget();
        dockWidgetContents_6->setObjectName(QString::fromUtf8("dockWidgetContents_6"));
        Project->setWidget(dockWidgetContents_6);
        dmain->addDockWidget(static_cast<Qt::DockWidgetArea>(8), Project);
        Rendering = new QDockWidget(dmain);
        Rendering->setObjectName(QString::fromUtf8("Rendering"));
        Rendering->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        dockWidgetContents_7 = new QWidget();
        dockWidgetContents_7->setObjectName(QString::fromUtf8("dockWidgetContents_7"));
        Rendering->setWidget(dockWidgetContents_7);
        dmain->addDockWidget(static_cast<Qt::DockWidgetArea>(2), Rendering);

        menuBar->addAction(menuBaseWindow->menuAction());

        retranslateUi(dmain);

        QMetaObject::connectSlotsByName(dmain);
    } // setupUi

    void retranslateUi(QMainWindow *dmain)
    {
        dmain->setWindowTitle(QApplication::translate("dmain", "dmain", nullptr));
        menuBaseWindow->setTitle(QApplication::translate("dmain", "BaseWindow", nullptr));
        Hierarchy->setWindowTitle(QApplication::translate("dmain", "Hierarchy", nullptr));
        Inspector->setWindowTitle(QApplication::translate("dmain", "Inspector", nullptr));
#ifndef QT_NO_TOOLTIP
        Project->setToolTip(QApplication::translate("dmain", "Project", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        Project->setWhatsThis(QApplication::translate("dmain", "Project", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        Project->setAccessibleName(QApplication::translate("dmain", "Project", nullptr));
#endif // QT_NO_ACCESSIBILITY
        Project->setWindowTitle(QApplication::translate("dmain", "Project", nullptr));
        Rendering->setWindowTitle(QApplication::translate("dmain", "Rendering", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dmain: public Ui_dmain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DMAIN_H
