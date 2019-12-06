/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form7
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *Form7)
    {
        if (Form7->objectName().isEmpty())
            Form7->setObjectName(QStringLiteral("Form7"));
        Form7->resize(421, 124);
        QIcon icon;
        icon.addFile(QStringLiteral("address.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Form7->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Form7);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(30, -1, 30, -1);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));

        horizontalLayout_3->addLayout(horizontalLayout_5);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(30, -1, 20, -1);
        label_2 = new QLabel(Form7);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setFamily(QStringLiteral("Arial Narrow"));
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral(""));
        label_2->setTextFormat(Qt::AutoText);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(Form7);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(30, -1, 30, -1);
        pushButton_2 = new QPushButton(Form7);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setStyleSheet(QStringLiteral(""));

        horizontalLayout_4->addWidget(pushButton_2);

        pushButton = new QPushButton(Form7);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        horizontalLayout_4->setStretch(0, 2);
        horizontalLayout_4->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(Form7);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Form7, SLOT(continueClick()));
        QObject::connect(pushButton, SIGNAL(clicked()), Form7, SLOT(cancelClick()));

        QMetaObject::connectSlotsByName(Form7);
    } // setupUi

    void retranslateUi(QWidget *Form7)
    {
        Form7->setWindowTitle(QApplication::translate("Form7", "\345\261\236\346\200\247\350\256\276\347\275\256", 0));
        label_2->setText(QApplication::translate("Form7", "\347\272\277\345\256\275\357\274\232", 0));
        pushButton_2->setText(QApplication::translate("Form7", "set", 0));
        pushButton->setText(QApplication::translate("Form7", "cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Form7: public Ui_Form7 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
