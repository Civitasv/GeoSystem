/********************************************************************************
** Form generated from reading UI file 'MyTreeWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTREEWIDGET_H
#define UI_MYTREEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form2
{
public:
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *Form2)
    {
        if (Form2->objectName().isEmpty())
            Form2->setObjectName(QStringLiteral("Form2"));
        Form2->resize(198, 650);
        QIcon icon;
        icon.addFile(QStringLiteral("address.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Form2->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Form2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        retranslateUi(Form2);

        QMetaObject::connectSlotsByName(Form2);
    } // setupUi

    void retranslateUi(QWidget *Form2)
    {
        Form2->setWindowTitle(QApplication::translate("Form2", "\347\233\256\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class Form2: public Ui_Form2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTREEWIDGET_H
