/********************************************************************************
** Form generated from reading UI file 'myclass.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCLASS_H
#define UI_MYCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyClassClass
{
public:
    QAction *actionGeojson;
    QAction *actionShp;
    QAction *actionAbout_us;
    QAction *actionContent;
    QAction *actionSave_shapefile;
    QAction *actionGet_databaseData;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menuAdd_data;
    QMenu *menuHelp;
    QMenu *menu_2;
    QMenu *menuDatabase;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *MyClassClass)
    {
        if (MyClassClass->objectName().isEmpty())
            MyClassClass->setObjectName(QStringLiteral("MyClassClass"));
        MyClassClass->resize(889, 644);
        actionGeojson = new QAction(MyClassClass);
        actionGeojson->setObjectName(QStringLiteral("actionGeojson"));
        actionShp = new QAction(MyClassClass);
        actionShp->setObjectName(QStringLiteral("actionShp"));
        actionAbout_us = new QAction(MyClassClass);
        actionAbout_us->setObjectName(QStringLiteral("actionAbout_us"));
        actionContent = new QAction(MyClassClass);
        actionContent->setObjectName(QStringLiteral("actionContent"));
        actionSave_shapefile = new QAction(MyClassClass);
        actionSave_shapefile->setObjectName(QStringLiteral("actionSave_shapefile"));
        actionGet_databaseData = new QAction(MyClassClass);
        actionGet_databaseData->setObjectName(QStringLiteral("actionGet_databaseData"));
        centralWidget = new QWidget(MyClassClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));

        horizontalLayout->addLayout(verticalLayout_2);

        MyClassClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyClassClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 889, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menuAdd_data = new QMenu(menu);
        menuAdd_data->setObjectName(QStringLiteral("menuAdd_data"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menuDatabase = new QMenu(menuBar);
        menuDatabase->setObjectName(QStringLiteral("menuDatabase"));
        MyClassClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyClassClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MyClassClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MyClassClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyClassClass->setStatusBar(statusBar);
        toolBar = new QToolBar(MyClassClass);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MyClassClass->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MyClassClass);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        MyClassClass->addToolBar(Qt::TopToolBarArea, toolBar_2);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuDatabase->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menu->addSeparator();
        menu->addAction(menuAdd_data->menuAction());
        menuAdd_data->addAction(actionGeojson);
        menuAdd_data->addAction(actionShp);
        menuHelp->addAction(actionAbout_us);
        menu_2->addAction(actionContent);
        menuDatabase->addAction(actionSave_shapefile);
        menuDatabase->addAction(actionGet_databaseData);

        retranslateUi(MyClassClass);

        QMetaObject::connectSlotsByName(MyClassClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyClassClass)
    {
        MyClassClass->setWindowTitle(QApplication::translate("MyClassClass", "MyClass", 0));
        actionGeojson->setText(QApplication::translate("MyClassClass", "geojson", 0));
        actionShp->setText(QApplication::translate("MyClassClass", "shp", 0));
        actionAbout_us->setText(QApplication::translate("MyClassClass", "about us", 0));
        actionContent->setText(QApplication::translate("MyClassClass", "content", 0));
        actionSave_shapefile->setText(QApplication::translate("MyClassClass", "save shapefile", 0));
        actionGet_databaseData->setText(QApplication::translate("MyClassClass", "get databaseData", 0));
        menu->setTitle(QApplication::translate("MyClassClass", "file", 0));
        menuAdd_data->setTitle(QApplication::translate("MyClassClass", "add data", 0));
        menuHelp->setTitle(QApplication::translate("MyClassClass", "help", 0));
        menu_2->setTitle(QApplication::translate("MyClassClass", "frame", 0));
        menuDatabase->setTitle(QApplication::translate("MyClassClass", "database", 0));
        toolBar->setWindowTitle(QApplication::translate("MyClassClass", "toolBar", 0));
        toolBar_2->setWindowTitle(QApplication::translate("MyClassClass", "toolBar_2", 0));
    } // retranslateUi

};

namespace Ui {
    class MyClassClass: public Ui_MyClassClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCLASS_H
