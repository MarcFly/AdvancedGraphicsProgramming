/********************************************************************************
** Form generated from reading UI file 'FillOutline.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILLOUTLINE_H
#define UI_FILLOUTLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FillOutline
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *typeLabel;
    QComboBox *itemsCombo;

    void setupUi(QWidget *FillOutline)
    {
        if (FillOutline->objectName().isEmpty())
            FillOutline->setObjectName(QString::fromUtf8("FillOutline"));
        FillOutline->resize(400, 300);
        horizontalLayout = new QHBoxLayout(FillOutline);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        typeLabel = new QLabel(FillOutline);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));

        horizontalLayout->addWidget(typeLabel);

        itemsCombo = new QComboBox(FillOutline);
        itemsCombo->setObjectName(QString::fromUtf8("itemsCombo"));

        horizontalLayout->addWidget(itemsCombo);


        retranslateUi(FillOutline);

        QMetaObject::connectSlotsByName(FillOutline);
    } // setupUi

    void retranslateUi(QWidget *FillOutline)
    {
        FillOutline->setWindowTitle(QCoreApplication::translate("FillOutline", "Form", nullptr));
        typeLabel->setText(QCoreApplication::translate("FillOutline", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FillOutline: public Ui_FillOutline {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILLOUTLINE_H
