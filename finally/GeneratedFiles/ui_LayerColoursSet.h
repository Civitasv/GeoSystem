/********************************************************************************
** Form generated from reading UI file 'LayerColoursSet.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAYERCOLOURSSET_H
#define UI_LAYERCOLOURSSET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form11
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Form11)
    {
        if (Form11->objectName().isEmpty())
            Form11->setObjectName(QStringLiteral("Form11"));
        Form11->resize(522, 406);
        verticalLayout = new QVBoxLayout(Form11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(-1, -1, 200, -1);
        label = new QLabel(Form11);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(Form11);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 300, -1);
        label_2 = new QLabel(Form11);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBox = new QComboBox(Form11);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 5);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, 200, -1);
        pushButton = new QPushButton(Form11);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(Form11);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 3);
        verticalLayout->setStretch(2, 1);

        retranslateUi(Form11);
        QObject::connect(pushButton, SIGNAL(clicked()), Form11, SLOT(continueClick()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), Form11, SLOT(cancelClick()));

        QMetaObject::connectSlotsByName(Form11);
    } // setupUi

    void retranslateUi(QWidget *Form11)
    {
        Form11->setWindowTitle(QApplication::translate("Form11", "Form", 0));
        label->setText(QApplication::translate("Form11", "\345\233\276\345\261\202\345\220\215\357\274\232", 0));
        label_2->setText(QApplication::translate("Form11", "\345\210\206\345\261\202\350\256\276\350\211\262\345\261\236\346\200\247\357\274\232", 0));
        pushButton->setText(QApplication::translate("Form11", "continue", 0));
        pushButton_2->setText(QApplication::translate("Form11", "cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Form11: public Ui_Form11 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAYERCOLOURSSET_H
