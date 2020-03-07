/********************************************************************************
** Form generated from reading UI file 'hierarchy.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIERARCHY_H
#define UI_HIERARCHY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hierarchy
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeHierarchy;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonAdd;
    QPushButton *buttonRemove;

    void setupUi(QWidget *Hierarchy)
    {
        if (Hierarchy->objectName().isEmpty())
            Hierarchy->setObjectName(QString::fromUtf8("Hierarchy"));
        Hierarchy->resize(400, 300);
        verticalLayout = new QVBoxLayout(Hierarchy);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        treeHierarchy = new QTreeWidget(Hierarchy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Picture.png"), QSize(), QIcon::Normal, QIcon::Off);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        font.setStrikeOut(false);
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setFont(1, font1);
        __qtreewidgetitem->setTextAlignment(0, Qt::AlignLeading|Qt::AlignVCenter);
        __qtreewidgetitem->setFont(0, font);
        __qtreewidgetitem->setBackground(0, QColor(103, 103, 102));
        __qtreewidgetitem->setForeground(0, brush);
        __qtreewidgetitem->setIcon(0, icon);
        treeHierarchy->setHeaderItem(__qtreewidgetitem);
        treeHierarchy->setObjectName(QString::fromUtf8("treeHierarchy"));
        treeHierarchy->setAutoFillBackground(true);

        verticalLayout->addWidget(treeHierarchy);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonAdd = new QPushButton(Hierarchy);
        buttonAdd->setObjectName(QString::fromUtf8("buttonAdd"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/Orb plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonAdd->setIcon(icon1);

        horizontalLayout->addWidget(buttonAdd);

        buttonRemove = new QPushButton(Hierarchy);
        buttonRemove->setObjectName(QString::fromUtf8("buttonRemove"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/Orb minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonRemove->setIcon(icon2);

        horizontalLayout->addWidget(buttonRemove);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Hierarchy);

        QMetaObject::connectSlotsByName(Hierarchy);
    } // setupUi

    void retranslateUi(QWidget *Hierarchy)
    {
        Hierarchy->setWindowTitle(QCoreApplication::translate("Hierarchy", "Form", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeHierarchy->headerItem();
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("Hierarchy", "ID", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("Hierarchy", "SCENE", nullptr));
        buttonAdd->setText(QCoreApplication::translate("Hierarchy", "Add", nullptr));
        buttonRemove->setText(QCoreApplication::translate("Hierarchy", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hierarchy: public Ui_Hierarchy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIERARCHY_H
