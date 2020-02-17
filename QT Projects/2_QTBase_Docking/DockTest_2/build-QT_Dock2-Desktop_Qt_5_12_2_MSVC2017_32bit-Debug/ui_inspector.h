/********************************************************************************
** Form generated from reading UI file 'inspector.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSPECTOR_H
#define UI_INSPECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inspector
{
public:

    void setupUi(QWidget *inspector)
    {
        if (inspector->objectName().isEmpty())
            inspector->setObjectName(QString::fromUtf8("inspector"));
        inspector->resize(400, 300);

        retranslateUi(inspector);

        QMetaObject::connectSlotsByName(inspector);
    } // setupUi

    void retranslateUi(QWidget *inspector)
    {
        inspector->setWindowTitle(QApplication::translate("inspector", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inspector: public Ui_inspector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSPECTOR_H
