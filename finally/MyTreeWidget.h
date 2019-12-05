#pragma once
#include <qtreewidget.h>
#include "ui_MyTreeWidget.h"
#include "GeoLayer.h"
#include "GeoMap.h"
#include <QContextMenuEvent>
#include <qmenu.h>
class MyTreeWidget:public QTreeWidget
{
	Q_OBJECT
public:
	MyTreeWidget(QWidget *parent = 0);
	virtual ~MyTreeWidget(void);
	QMenu* popMenu;
	QTreeWidgetItem* curItem;
private:
	Ui::Form2 ui;
	CGeoMap *map;
	void createActions();
	void createMenu();
	//void contextMenuEvent ( QContextMenuEvent * event );
	private slots:
		void updateMyTreeWidgetSlot(CGeoMap *map);
		void itemClick();
		void viewIt();
		void deleteIt();
		void sltShowPopMenu(const QPoint&);
signals:
		void updateTreeGLSignal(int mode,CGeoMap *map);
		void updateLayerIDSignal(int mode,int layerID);
};

