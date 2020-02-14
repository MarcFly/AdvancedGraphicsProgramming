/********************************************************************************
** Form generated from reading UI file 'transform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFORM_H
#define UI_TRANSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Transform
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QGridLayout *gridLayout;
    QDoubleSpinBox *PosZ;
    QDoubleSpinBox *PosX;
    QDoubleSpinBox *ScaleZ;
    QDoubleSpinBox *ScaleX;
    QDoubleSpinBox *RotZ;
    QDoubleSpinBox *RotX;
    QDoubleSpinBox *ScaleY;
    QDoubleSpinBox *PosY;
    QDoubleSpinBox *RotY;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Transform)
    {
        if (Transform->objectName().isEmpty())
            Transform->setObjectName(QString::fromUtf8("Transform"));
        Transform->resize(292, 142);
        verticalLayout = new QVBoxLayout(Transform);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(Transform);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(Transform);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(Transform);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        PosZ = new QDoubleSpinBox(Transform);
        PosZ->setObjectName(QString::fromUtf8("PosZ"));

        gridLayout->addWidget(PosZ, 0, 2, 1, 1);

        PosX = new QDoubleSpinBox(Transform);
        PosX->setObjectName(QString::fromUtf8("PosX"));

        gridLayout->addWidget(PosX, 0, 0, 1, 1);

        ScaleZ = new QDoubleSpinBox(Transform);
        ScaleZ->setObjectName(QString::fromUtf8("ScaleZ"));

        gridLayout->addWidget(ScaleZ, 2, 2, 1, 1);

        ScaleX = new QDoubleSpinBox(Transform);
        ScaleX->setObjectName(QString::fromUtf8("ScaleX"));

        gridLayout->addWidget(ScaleX, 2, 0, 1, 1);

        RotZ = new QDoubleSpinBox(Transform);
        RotZ->setObjectName(QString::fromUtf8("RotZ"));

        gridLayout->addWidget(RotZ, 1, 2, 1, 1);

        RotX = new QDoubleSpinBox(Transform);
        RotX->setObjectName(QString::fromUtf8("RotX"));

        gridLayout->addWidget(RotX, 1, 0, 1, 1);

        ScaleY = new QDoubleSpinBox(Transform);
        ScaleY->setObjectName(QString::fromUtf8("ScaleY"));

        gridLayout->addWidget(ScaleY, 2, 1, 1, 1);

        PosY = new QDoubleSpinBox(Transform);
        PosY->setObjectName(QString::fromUtf8("PosY"));

        gridLayout->addWidget(PosY, 0, 1, 1, 1);

        RotY = new QDoubleSpinBox(Transform);
        RotY->setObjectName(QString::fromUtf8("RotY"));

        gridLayout->addWidget(RotY, 1, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        verticalSpacer = new QSpacerItem(20, 39, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(Transform);

        QMetaObject::connectSlotsByName(Transform);
    } // setupUi

    void retranslateUi(QWidget *Transform)
    {
        Transform->setWindowTitle(QApplication::translate("Transform", "Form", nullptr));
        label->setText(QApplication::translate("Transform", "Position", nullptr));
        label_2->setText(QApplication::translate("Transform", "Rotation", nullptr));
        label_3->setText(QApplication::translate("Transform", "Scale", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Transform: public Ui_Transform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFORM_H
