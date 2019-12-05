#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtWidgets/QMainWindow>
#include "ui_myclass.h"
#include <QPainter>
#include "GeoJsonTool.h"
#include "GeoMap.h"
#include "MyGLWidget.h"
#include <qtreewidget.h>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include "MyTreeWidget.h"
#include "Connect_Sql.h"
class MyClass : public QMainWindow
{
	Q_OBJECT

public:
	MyClass(QWidget *parent = 0);
	~MyClass();

private:
	Ui::MyClassClass ui;
	void createActions();
public:
	//MyTreeWidget *treeWidget;
	MyGLWidget* gl; // 储存opengl
	private slots:
		void readGeoJson();
		void readShape();
		void saveShapefile();
		void getDatabaseData();

protected:
	//void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
signals:
	void updateMyGLSignal(int mode,const char* filename,int layerID);//重新渲染信号
	void updateMyGLPostgresqlSignal(int mode,int layerID,QString dbname,QString host,QString user,QString password,QString table); // 读取数据库，重新渲染
	void updateMyTreeWidgetSignal(CGeoMap *map);
	void updateData(int mode,CGeoMap *map);
	void updateLayerIDSignal(int mode,int layerID);
	private slots:
		void updateTreeGLSlot(int mode,CGeoMap *map);
		void updateLayerIDSlot(int mode,int layerID);

};

#endif // MYCLASS_H
