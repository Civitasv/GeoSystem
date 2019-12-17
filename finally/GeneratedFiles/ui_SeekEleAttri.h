/********************************************************************************
** Form generated from reading UI file 'SeekEleAttri.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEEKELEATTRI_H
#define UI_SEEKELEATTRI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form9
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *Form9)
    {
        if (Form9->objectName().isEmpty())
            Form9->setObjectName(QStringLiteral("Form9"));
        Form9->resize(400, 309);
        verticalLayout = new QVBoxLayout(Form9);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableWidget = new QTableWidget(Form9);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        horizontalLayout->addWidget(tableWidget);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));

        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_2 = new QPushButton(Form9);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);

        pushButton = new QPushButton(Form9);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 8);
        verticalLayout->setStretch(1, 3);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);

        retranslateUi(Form9);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Form9, SLOT(continueClick()));
        QObject::connect(pushButton, SIGNAL(clicked()), Form9, SLOT(cancelClick()));

        QMetaObject::connectSlotsByName(Form9);
    } // setupUi

    void retranslateUi(QWidget *Form9)
    {
        Form9->setWindowTitle(QApplication::translate("Form9", "Form", 0));
        pushButton_2->setText(QApplication::translate("Form9", "set", 0));
        pushButton->setText(QApplication::translate("Form9", "cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Form9: public Ui_Form9 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEEKELEATTRI_H
