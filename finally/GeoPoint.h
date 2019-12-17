#pragma once
#include "geoobject.h"

class CGeoPoint :
	public CGeoObject
{
private:
	QPointF pt;
public:
	CGeoPoint(void);
	virtual ~CGeoPoint(void);
	void setPoint(QPointF pt);
	QPointF getPoint();
	void paint(QPainter *paint);
	float* getVert(float *vert,int *count);
	QRectF getScope();
	QPolygonF pts;// Õ‚Ω”
};