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
    QLabel *label;
    QSpinBox *R;
    QLabel *label_2;
    QSpinBox *G;
    QLabel *label_3;
    QSpinBox *B;
    QLabel *label_4;
    QSpinBox *A;

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
        label = new QLabel(Color);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        R = new QSpinBox(Color);
        R->setObjectName(QString::fromUtf8("R"));

        horizontalLayout->addWidget(R);

        label_2 = new QLabel(Color);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        G = new QSpinBox(Color);
        G->setObjectName(QString::fromUtf8("G"));

        horizontalLayout->addWidget(G);

        label_3 = new QLabel(Color);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        B = new QSpinBox(Color);
        B->setObjectName(QString::fromUtf8("B"));

        horizontalLayout->addWidget(B);

        label_4 = new QLabel(Color);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        A = new QSpinBox(Color);
        A->setObjectName(QString::fromUtf8("A"));

        horizontalLayout->addWidget(A);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Color);

        QMetaObject::connectSlotsByName(Color);
    } // setupUi

    void retranslateUi(QWidget *Color)
    {
        Color->setWindowTitle(QApplication::translate("Color", "Form", nullptr));
        label->setText(QApplication::translate("Color", "R", nullptr));
        label_2->setText(QApplication::translate("Color", "G", nullptr));
        label_3->setText(QApplication::translate("Color", "B", nullptr));
        label_4->setText(QApplication::translate("Color", "A", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Color: public Ui_Color {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLOR_H
