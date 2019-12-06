#pragma once
#include "ui_MyGLWidget.h"
#include <qopenglwidget.h>
#include <qopenglfunctions.h>
#include <qopenglbuffer.h>
#include <qopenglshaderprogram.h>
#include <qopenglfunctions_4_5_core.h>
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
#include <QGraphicsDropShadowEffect>
class MyGLWidget:public QOpenGLWidget, protected QOpenGLFunctions_4_5_Core
{
	Q_OBJECT
public:
	MyGLWidget(QWidget *parent = 0);
	virtual ~MyGLWidget(void);
	void readDataFromShape(const char* filename);
	void readDataFromGeoJSON(const char* filename);
	void readDataFromPostgresql();
	int mode; // ����ģʽ0:geojson 1:shp 2:����/��ʾ 3:ɾ��
	const char* filename; // ��������
	CGeoMap *map;
	int layerID; // Ҫչʾ��layerID
	CGeoLayer *viewLayer; // չʾ��layer
	QRectF rect;
private:
	Ui::Form ui;
	GLuint* VBO, *VAO;
	GLuint ID;
	int *len;
	//float *vertices;
	//int *count;
	int size;
	QPointF offset;
	float scaleParam;
	QPointF begin;
	QString dbname, host, user, password, table,port; // postgresql����
	void createShader(const char* vertexPath, const char* fragmentPath);
	void checkCompileErrors(unsigned int shader, std::string type);
	void loadData();
	void wheelEvent(QWheelEvent *event);
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	QPointF screenToWorld(QPointF screenPoint);
protected:
	// ����opengl
	void initializeGL() override;
	void paintGL() override;
	void resizeGL(int w,int h) override;
public slots:
	void updateMyGLSlot(int mode,const char* filename,int layerID);
	void updateMyGLPostgresqlSlot(int mode,int layerID,QString port,QString dbname,QString host,QString user,QString password,QString table); // ��ȡ���ݿ⣬������Ⱦ
	void updateData(int mode,CGeoMap *map);
	void updateLayerID(int mode,int LayerID);
	void getColorAndWidthData2(int layerID,QColor color,float width);//������Ⱦ�ź�
};