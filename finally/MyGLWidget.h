#pragma once
#include "ui_MyGLWidget.h"
#include <qopenglwidget.h>
#include <qopenglfunctions.h>
#include <qopenglbuffer.h>
#include <qopenglshaderprogram.h>
#include <qopenglfunctions_3_3_core.h>
#include <QPainter>
#include "GeoJsonTool.h"
#include "GeoMap.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "GeoMap.h"
#include <qdebug.h>
#include "GdalTool.h"
#include <QWheelEvent>
#include "Connect_Sql.h"
class MyGLWidget:public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
	Q_OBJECT
public:
	MyGLWidget(QWidget *parent = 0);
	virtual ~MyGLWidget(void);
	void readDataFromShape(const char* filename);
	void readDataFromGeoJSON(const char* filename);
	void readDataFromPostgresql();
	int mode; // 绘制模式0:geojson 1:shp 2:隐藏/显示 3:删除
	const char* filename; // 绘制数据
	CGeoMap *map;
	int layerID; // 要展示的layerID
	CGeoLayer *viewLayer; // 展示的layer
	QRectF rect;
private:
	Ui::Form ui;
	GLuint* VBO, *VAO;
	GLuint ID;
	int *len;
	//float *vertices;
	//int *count;
	int size;
	QPoint offset;
	float scaleParam;
	QPoint begin;
	QString dbname, host, user, password, table; // postgresql配置
	void createShader(const char* vertexPath, const char* fragmentPath);
	void checkCompileErrors(unsigned int shader, std::string type);
	void loadData();
	void wheelEvent(QWheelEvent *event);
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);

protected:
	// 绘制opengl
	void initializeGL() override;
	void paintGL() override;
	void resizeGL(int w,int h) override;
public slots:
	void updateMyGLSlot(int mode,const char* filename,int layerID);
	void updateMyGLPostgresqlSlot(int mode,int layerID,QString dbname,QString host,QString user,QString password,QString table); // 读取数据库，重新渲染
	void updateData(int mode,CGeoMap *map);
	void updateLayerID(int mode,int LayerID);
};