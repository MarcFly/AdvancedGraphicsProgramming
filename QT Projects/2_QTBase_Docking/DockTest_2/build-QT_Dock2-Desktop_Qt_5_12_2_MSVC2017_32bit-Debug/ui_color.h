/********************************************************************************
** Form generated from reading UI file 'color.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLOR_H
#define UI_COLOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Color
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QLabel *labelR;
    QSpinBox *intR;
    QLabel *labelG;
    QSpinBox *intG;
    QLabel *labelB;
    QSpinBox *intB;
    QLabel *labelA;
    QSpinBox *intA;

    void setupUi(QWidget *Color)
    {
        if (Color->objectName().isEmpty())
            Color->setObjectName(QString::fromUtf8("Color"));
        Color->resize(273, 80);
        verticalLayout = new QVBoxLayout(Color);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        line = new QFrame(Color);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelR = new QLabel(Color);
        labelR->setObjectName(QString::fromUtf8("labelR"));

        horizontalLayout->addWidget(labelR);

        intR = new QSpinBox(Color);
        intR->setObjectName(QString::fromUtf8("intR"));

        horizontalLayout->addWidget(intR);

        labelG = new QLabel(Color);
        labelG->setObjectName(QString::fromUtf8("labelG"));

        horizontalLayout->addWidget(labelG);

        intG = new QSpinBox(Color);
        intG->setObjectName(QString::fromUtf8("intG"));

        horizontalLayout->addWidget(intG);

        labelB = new QLabel(Color);
        labelB->setObjectName(QString::fromUtf8("labelB"));

        horizontalLayout->addWidget(labelB);

        intB = new QSpinBox(Color);
        intB->setObjectName(QString::fromUtf8("intB"));

        horizontalLayout->addWidget(intB);

        labelA = new QLabel(Color);
        labelA->setObjectName(QString::fromUtf8("labelA"));

        horizontalLayout->addWidget(labelA);

        intA = new QSpinBox(Color);
        intA->setObjectName(QString::fromUtf8("intA"));

        horizontalLayout->addWidget(intA);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Color);

        QMetaObject::connectSlotsByName(Color);
    } // setupUi

    void retranslateUi(QWidget *Color)
    {
        Color->setWindowTitle(QApplication::translate("Color", "Form", nullptr));
        labelR->setText(QApplication::translate("Color", "R", nullptr));
        labelG->setText(QApplication::translate("Color", "G", nullptr));
        labelB->setText(QApplication::translate("Color", "B", nullptr));
        labelA->setText(QApplication::translate("Color", "A", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Color: public Ui_Color {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLOR_H
