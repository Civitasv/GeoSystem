#include "GeoPolyline.h"


CGeoPolyline::CGeoPolyline(void)
{
}


CGeoPolyline::~CGeoPolyline(void)
{
}

void CGeoPolyline::addPoint(QPointF pt)
{
	pts.append(pt);
}

void CGeoPolyline::paint(QPainter *paint){
	QPen pen;
	pen.setWidthF(0.3f);
	pen.setColor(QColor("#e16b15"));
	paint->setPen(pen);
	paint->drawPolyline(this->pts);
}


float* CGeoPolyline::getVert(float *vert,int *count){
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
}

QRectF CGeoPolyline::getScope(){
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