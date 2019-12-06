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
#include "MyWizard.h"
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
	QString dbname, host, user, password, table,port; // postgresql配置

	MyGLWidget* gl; // 储存opengl
	MyWizard *mywizard;
	private slots:
		void readGeoJson();
		void readShape();
		void saveShapefile();
		void getDatabaseData();

protected:
	//void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
signals:
	void updateMyGLSignal(int mode,const char* filename,int layerID);//重新渲染信号
	void updateMyGLPostgresqlSignal(int mode,int layerID,QString port,QString dbname,QString host,QString user,QString password,QString table); // 读取数据库，重新渲染
	void updateMyTreeWidgetSignal(CGeoMap *map);
	void updateData(int mode,CGeoMap *map);
	void updateLayerIDSignal(int mode,int layerID);
	void sendColorAndWidthData2(int layerID,QColor color,float width);//重新渲染信号
	private slots:
		void updateTreeGLSlot(int mode,CGeoMap *map);
		void updateLayerIDSlot(int mode,int layerID);
		void getPostgresqlSlot(QString dbname,QString host,QString user,QString password,QString table,QString port);
		void getColorAndWidthData(int layerID,QColor color,float width);//重新渲染信号

};

#endif // MYCLASS_H
