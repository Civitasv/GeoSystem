#include "GeoPoint.h"


CGeoPoint::CGeoPoint(void)
{
	this->r = 1.0f;
	this->g = 0.0f;
	this->b = 0.0f;
}


CGeoPoint::~CGeoPoint(void)
{
}

void CGeoPoint::setPoint(QPointF pt)
{
	this->pt = pt;
}

QPointF CGeoPoint::getPoint(){
	return this->pt;
}

void CGeoPoint::paint(QPainter *paint){
	paint->drawPoint(this->pt);
}

float* CGeoPoint::getVert(float *vert,int *count){
	// 重新分配内存
	vert = (float*)realloc(vert,sizeof(float)* (*count+6));
	vert[*count] = pt.x();
	vert[*count+1] = pt.y();
	vert[*count+2] = 0.0f;
	vert[*count+3] = r;
	vert[*count+4] = g;
	vert[*count+5] = b;
	// 设置个数
	*count = *count+1*6;
	return vert;
}

QRectF CGeoPoint::getScope(){
	return QRectF(pt.x(), pt.y(), pt.x(), pt.y());
}