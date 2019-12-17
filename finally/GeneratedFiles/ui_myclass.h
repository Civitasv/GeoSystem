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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QAction *actionIndex_grid;
    QAction *actionHideIndexGrid;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menuAdd_data;
    QMenu *menuHelp;
    QMenu *menu_2;
    QMenu *menuDatabase;
    QToolBar *mainToolBar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyClassClass)
    {
        if (MyClassClass->objectName().isEmpty())
            MyClassClass->setObjectName(QStringLiteral("MyClassClass"));
        MyClassClass->resize(816, 587);
        QIcon icon;
        icon.addFile(QStringLiteral("address.svg"), QSize(), QIcon::Normal, QIcon::Off);
        MyClassClass->setWindowIcon(icon);
        MyClassClass->setStyleSheet(QStringLiteral(""));
        MyClassClass->setIconSize(QSize(30, 30));
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
        actionIndex_grid = new QAction(MyClassClass);
        actionIndex_grid->setObjectName(QStringLiteral("actionIndex_grid"));
        actionHideIndexGrid = new QAction(MyClassClass);
        actionHideIndexGrid->setObjectName(QStringLiteral("actionHideIndexGrid"));
        centralWidget = new QWidget(MyClassClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, -1);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setLayoutDirection(Qt::LeftToRight);
        lineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../search.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../close.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        verticalLayout_2->addLayout(verticalLayout);

        verticalLayout_2->setStretch(1, 13);
        MyClassClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyClassClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 816, 26));
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
        toolBar = new QToolBar(MyClassClass);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MyClassClass->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MyClassClass);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        MyClassClass->addToolBar(Qt::TopToolBarArea, toolBar_2);
        statusBar = new QStatusBar(MyClassClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyClassClass->setStatusBar(statusBar);

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
        QObject::connect(pushButton, SIGNAL(clicked()), MyClassClass, SLOT(search()));

        QMetaObject::connectSlotsByName(MyClassClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyClassClass)
    {
        MyClassClass->setWindowTitle(QApplication::translate("MyClassClass", "\344\270\273\347\225\214\351\235\242", 0));
        actionGeojson->setText(QApplication::translate("MyClassClass", "geojson", 0));
        actionShp->setText(QApplication::translate("MyClassClass", "shp", 0));
        actionAbout_us->setText(QApplication::translate("MyClassClass", "about us", 0));
        actionContent->setText(QApplication::translate("MyClassClass", "content", 0));
        actionSave_shapefile->setText(QApplication::translate("MyClassClass", "save shapefile", 0));
        actionGet_databaseData->setText(QApplication::translate("MyClassClass", "get databaseData", 0));
        actionIndex_grid->setText(QApplication::translate("MyClassClass", "showIndexGrid", 0));
        actionHideIndexGrid->setText(QApplication::translate("MyClassClass", "hideIndexGrid", 0));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
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
