#include "GeoObject.h"


CGeoObject::CGeoObject(void)
{
}


CGeoObject::~CGeoObject(void)
{
}

void CGeoObject::setRect(QRectF rect){
	this->qRect = rect;
}
QRectF CGeoObject::getRect(){
	return this->qRect;
}

void CGeoObject::setType(QString type){
	this->type = type;
}
QString CGeoObject::getType(){
	return this->type;
}

QString CGeoObject::getProps(){
	return this->properties;
}
void CGeoObject::setProps(QString props){
	this->properties = props;
}

void CGeoObject::paint(QPainter *paint){
	
}

float* CGeoObject::getVert(float *vert,int *count){
	return 0;
}


QRectF CGeoObject::getScope(){
	return QRectF();
}