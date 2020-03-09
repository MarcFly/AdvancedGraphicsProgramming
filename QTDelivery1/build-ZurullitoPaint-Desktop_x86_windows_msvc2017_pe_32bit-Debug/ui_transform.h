/********************************************************************************
** Form generated from reading UI file 'Transform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFORM_H
#define UI_TRANSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Transform
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *layoutPosScale;
    QVBoxLayout *layoutPos;
    QLabel *labelPos;
    QDoubleSpinBox *PX;
    QDoubleSpinBox *PY;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *layoutScale;
    QFrame *line_2;
    QLabel *labelScale;
    QDoubleSpinBox *SX;
    QDoubleSpinBox *SY;
    QSpacerItem *verticalSpacer;
    QFrame *line;
    QVBoxLayout *LayoutRot;
    QLabel *labelRot;
    QDial *Rdial;
    QSpinBox *Rinput;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *Transform)
    {
        if (Transform->objectName().isEmpty())
            Transform->setObjectName(QString::fromUtf8("Transform"));
        Transform->resize(357, 316);
        horizontalLayout = new QHBoxLayout(Transform);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        layoutPosScale = new QVBoxLayout();
        layoutPosScale->setObjectName(QString::fromUtf8("layoutPosScale"));
        layoutPos = new QVBoxLayout();
        layoutPos->setObjectName(QString::fromUtf8("layoutPos"));
        labelPos = new QLabel(Transform);
        labelPos->setObjectName(QString::fromUtf8("labelPos"));
        labelPos->setAlignment(Qt::AlignCenter);

        layoutPos->addWidget(labelPos);

        PX = new QDoubleSpinBox(Transform);
        PX->setObjectName(QString::fromUtf8("PX"));

        layoutPos->addWidget(PX);

        PY = new QDoubleSpinBox(Transform);
        PY->setObjectName(QString::fromUtf8("PY"));

        layoutPos->addWidget(PY);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        layoutPos->addItem(verticalSpacer_2);

        layoutScale = new QVBoxLayout();
        layoutScale->setObjectName(QString::fromUtf8("layoutScale"));
        line_2 = new QFrame(Transform);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        layoutScale->addWidget(line_2);

        labelScale = new QLabel(Transform);
        labelScale->setObjectName(QString::fromUtf8("labelScale"));
        labelScale->setTextFormat(Qt::AutoText);
        labelScale->setScaledContents(false);
        labelScale->setAlignment(Qt::AlignCenter);
        labelScale->setWordWrap(false);

        layoutScale->addWidget(labelScale);

        SX = new QDoubleSpinBox(Transform);
        SX->setObjectName(QString::fromUtf8("SX"));

        layoutScale->addWidget(SX);

        SY = new QDoubleSpinBox(Transform);
        SY->setObjectName(QString::fromUtf8("SY"));

        layoutScale->addWidget(SY);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        layoutScale->addItem(verticalSpacer);


        layoutPos->addLayout(layoutScale);


        layoutPosScale->addLayout(layoutPos);


        horizontalLayout->addLayout(layoutPosScale);

        line = new QFrame(Transform);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        LayoutRot = new QVBoxLayout();
        LayoutRot->setObjectName(QString::fromUtf8("LayoutRot"));
        labelRot = new QLabel(Transform);
        labelRot->setObjectName(QString::fromUtf8("labelRot"));
        labelRot->setLayoutDirection(Qt::LeftToRight);
        labelRot->setTextFormat(Qt::AutoText);
        labelRot->setAlignment(Qt::AlignCenter);

        LayoutRot->addWidget(labelRot);

        Rdial = new QDial(Transform);
        Rdial->setObjectName(QString::fromUtf8("Rdial"));
        Rdial->setNotchTarget(18.699999999999999);

        LayoutRot->addWidget(Rdial);

        Rinput = new QSpinBox(Transform);
        Rinput->setObjectName(QString::fromUtf8("Rinput"));

        LayoutRot->addWidget(Rinput);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        LayoutRot->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(LayoutRot);


        retranslateUi(Transform);

        QMetaObject::connectSlotsByName(Transform);
    } // setupUi

    void retranslateUi(QWidget *Transform)
    {
        Transform->setWindowTitle(QCoreApplication::translate("Transform", "Form", nullptr));
        labelPos->setText(QCoreApplication::translate("Transform", "Position", nullptr));
        labelScale->setText(QCoreApplication::translate("Transform", "Scale", nullptr));
        labelRot->setText(QCoreApplication::translate("Transform", "Rotation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Transform: public Ui_Transform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFORM_H
