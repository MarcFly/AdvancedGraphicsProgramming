/********************************************************************************
** Form generated from reading UI file 'Shape.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHAPE_H
#define UI_SHAPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Shape
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *shapeLabel;
    QComboBox *shapeSelect;

    void setupUi(QWidget *Shape)
    {
        if (Shape->objectName().isEmpty())
            Shape->setObjectName(QString::fromUtf8("Shape"));
        Shape->resize(400, 43);
        horizontalLayout_2 = new QHBoxLayout(Shape);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        shapeLabel = new QLabel(Shape);
        shapeLabel->setObjectName(QString::fromUtf8("shapeLabel"));

        horizontalLayout->addWidget(shapeLabel);

        shapeSelect = new QComboBox(Shape);
        shapeSelect->setObjectName(QString::fromUtf8("shapeSelect"));
        shapeSelect->setMaxVisibleItems(5);

        horizontalLayout->addWidget(shapeSelect);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(Shape);

        QMetaObject::connectSlotsByName(Shape);
    } // setupUi

    void retranslateUi(QWidget *Shape)
    {
        Shape->setWindowTitle(QCoreApplication::translate("Shape", "Form", nullptr));
        shapeLabel->setText(QCoreApplication::translate("Shape", "Shape", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Shape: public Ui_Shape {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHAPE_H
