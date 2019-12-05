#include "GeoPolygon.h"


CGeoPolygon::CGeoPolygon(void)
{
	this->r = 1.0f;
	this->g = 0.0f;
	this->b = 0.0f;
}


CGeoPolygon::~CGeoPolygon(void)
{
}

void CGeoPolygon::addPoint(QPointF pt)
{
	pts.append(pt);
}

void CGeoPolygon::paint(QPainter *paint){
	// 设置线形状
	QPen pen;
	pen.setWidthF(0.3f);
	pen.setColor(QColor("#e16b15"));
	paint->setPen(pen);
	// 设置填充
	paint->setBrush(QBrush(QColor("#ed9758"), Qt::SolidPattern));
	paint->drawPolygon(this->pts,Qt::WindingFill);
}

float* CGeoPolygon::getVert(float *vert,int* count){
	// 重新分配内存
	vert = (float*)realloc(vert,sizeof(float)* (*count + 6*pts.size()));

	for(int i=0;i<pts.size();i++){
		vert[*count+i*6] = pts[i].x();
		vert[*count+i*6+1] = pts[i].y();
		vert[*count+i*6+2] = 0.0f;
		vert[*count+i*6+3] = r;
		vert[*count+i*6+4] = g;
		vert[*count+i*6+5] = b;
	}

	*count = *count + 6*pts.size();
	return vert;
	/*
	vert = (float*)realloc(vert,sizeof(float)* (*count + 18));
	vert[*count] = 0.02f;
	vert[*count+1] =  0.9f;
	vert[*count+2] = 0.0f;
	vert[*count+3] = r;
	vert[*count+4] = g;
	vert[*count+5] = b;

	vert[*count+6] = 0.024f;
	vert[*count+7] =  0.92f;
	vert[*count+8] = 0.0f;
	vert[*count+9] = r;
	vert[*count+10] = g;
	vert[*count+11] = b;

	vert[*count+12] = 0.025f;
	vert[*count+13] =  0.9f;
	vert[*count+14] = 0.0f;
	vert[*count+15] = r;
	vert[*count+16] = g;
	vert[*count+17] = b;
	*count = *count + 18;
	return vert;
	*/
}

QRectF CGeoPolygon::getScope(){
	QRectF rect;
	QPointF topleft;
	QPointF bottomright;
	float maxx=0,minx=FLT_MAX,maxy=0,miny=FLT_MAX;
	for(int i=0;i<pts.size();i++){
		if(pts[i].x()>maxx){
			maxx = pts[i].x();
		}
		if(pts[i].y()>maxy){
			maxy = pts[i].y();
		}
		if(pts[i].x()<minx){
			minx = pts[i].x();
		}
		if(pts[i].y()<miny){
			miny = pts[i].y();
		}
	}
	topleft.setX(minx);
	topleft.setY(maxy);
	bottomright.setX(maxx);
	bottomright.setY(miny);
	rect.setBottomRight(bottomright);
	rect.setTopLeft(topleft);
	this->setRect(rect);
	return rect;
}