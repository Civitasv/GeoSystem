#pragma once
#include <qstring.h>
#include <qrect.h>
#include <qlist.h>
#include "geopoint.h"
#include "geopolyline.h"
#include "geopolygon.h"
#include "geoobject.h"
#define FLT_MAX         3.402823466e+38F

class CGeoLayer
{
private:
	// ͼ����
	QString layerName;
	// �ɼ���
	bool isVisible;
	// ͼ�㷶Χ
	QRectF qRect;
public:
	CGeoLayer(void);
	virtual ~CGeoLayer(void);
	// ����Ŀ������
	QList<CGeoObject*> geoObjects;
	void setRect(QRectF qRect);
	QRectF getRect();

	void setLayerName(QString layerName);
	QString getLayerName();

	void setVisible(bool isVisible);
	bool getVisible();

	void addObjects(CGeoObject* obj);
	void deleteObjectAt(int index);
	void deleteObjectAll();

	void paint(QPainter *paint);

	float* getVert(float *vert,int *count);

	QRectF getScope();
	bool paintLoc;

};

