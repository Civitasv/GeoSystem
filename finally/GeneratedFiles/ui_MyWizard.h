/********************************************************************************
** Form generated from reading UI file 'MyWizard.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIZARD_H
#define UI_MYWIZARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form4
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Form4)
    {
        if (Form4->objectName().isEmpty())
            Form4->setObjectName(QStringLiteral("Form4"));
        Form4->resize(411, 497);
        QIcon icon;
        icon.addFile(QStringLiteral("address.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Form4->setWindowIcon(icon);
        verticalLayout_3 = new QVBoxLayout(Form4);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit = new QLineEdit(Form4);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(Form4);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(Form4);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        verticalLayout->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(Form4);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        verticalLayout->addWidget(lineEdit_4);

        lineEdit_5 = new QLineEdit(Form4);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        verticalLayout->addWidget(lineEdit_5);

        lineEdit_6 = new QLineEdit(Form4);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        verticalLayout->addWidget(lineEdit_6);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(Form4);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(Form4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 2);

        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout_3->setStretch(0, 4);
        verticalLayout_3->setStretch(1, 1);

        retranslateUi(Form4);
        QObject::connect(pushButton, SIGNAL(clicked()), Form4, SLOT(continueClick()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), Form4, SLOT(cancelClick()));

        QMetaObject::connectSlotsByName(Form4);
    } // setupUi

    void retranslateUi(QWidget *Form4)
    {
        Form4->setWindowTitle(QApplication::translate("Form4", "\346\225\260\346\215\256\345\272\223\350\277\236\346\216\245\345\217\202\346\225\260\350\256\276\347\275\256", 0));
        pushButton->setText(QApplication::translate("Form4", "continue", 0));
        pushButton_2->setText(QApplication::translate("Form4", "cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Form4: public Ui_Form4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIZARD_H
