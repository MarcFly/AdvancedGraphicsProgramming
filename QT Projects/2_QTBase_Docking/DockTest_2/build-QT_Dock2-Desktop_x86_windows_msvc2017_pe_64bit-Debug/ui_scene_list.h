/********************************************************************************
** Form generated from reading UI file 'scene_list.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCENE_LIST_H
#define UI_SCENE_LIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_scene_list
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *list;
    QHBoxLayout *horizontalLayout;
    QPushButton *add;
    QPushButton *remove;

    void setupUi(QWidget *scene_list)
    {
        if (scene_list->objectName().isEmpty())
            scene_list->setObjectName(QString::fromUtf8("scene_list"));
        scene_list->resize(415, 381);
        verticalLayout = new QVBoxLayout(scene_list);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        list = new QListWidget(scene_list);
        list->setObjectName(QString::fromUtf8("list"));

        verticalLayout->addWidget(list);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        add = new QPushButton(scene_list);
        add->setObjectName(QString::fromUtf8("add"));

        horizontalLayout->addWidget(add);

        remove = new QPushButton(scene_list);
        remove->setObjectName(QString::fromUtf8("remove"));

        horizontalLayout->addWidget(remove);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(scene_list);

        QMetaObject::connectSlotsByName(scene_list);
    } // setupUi

    void retranslateUi(QWidget *scene_list)
    {
        scene_list->setWindowTitle(QCoreApplication::translate("scene_list", "Form", nullptr));
        add->setText(QCoreApplication::translate("scene_list", "Add", nullptr));
        remove->setText(QCoreApplication::translate("scene_list", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class scene_list: public Ui_scene_list {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCENE_LIST_H
