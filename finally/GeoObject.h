#pragma once
#include <qstring.h>
#include <qrect.h>
#include <qpoint.h>
#include <qpainter.h>
#include <qtransform.h>
#define FLT_MAX         3.402823466e+38F

class CGeoObject
{
private:
	// 目标类型
	QString type;
	// 外接矩形 可能存在
	QRectF qRect;
	// 属性
	QString properties;
public:
	float r,g,b;
	CGeoObject(void);
	virtual ~CGeoObject(void);
	void setRect(QRectF rect);
	QRectF getRect();

	void setType(QString type);
	QString getType();

	QString getProps();
	void setProps(QString props);

	virtual void paint(QPainter *paint);

	virtual float* getVert(float *vert,int *count);

	virtual QRectF getScope();
};

