#include "GeoJsonTool.h"


GeoJsonTool::GeoJsonTool(void)
{
}


GeoJsonTool::~GeoJsonTool(void)
{
}

CGeoLayer* GeoJsonTool::readGeoJSON(const char* filename){
	ifstream ifs(filename);
	IStreamWrapper isw(ifs);
	Document document;
	document.ParseStream(isw);
	CGeoLayer *geolayer = new CGeoLayer();
	// ����layer��
	geolayer->setLayerName(QString("test"));
	// ������е�features
	const Value& f = document["features"].GetArray();
	for(int i=0;i<f.Size();i++){
		// ���geometry������
		const char* type = f[i]["geometry"]["type"].GetString();
		CGeoObject *obj;
		// ����ǵ�
		if(strcmp(type, "Point") == 0){
			obj = new CGeoPoint();
			((CGeoPoint *)obj)->setType(QString("Point"));
			const Value& c = f[i]["geometry"]["coordinates"];
			QPointF pt;
			pt.setX(c[0][0][0].GetDouble());
			pt.setY(c[0][0][1].GetDouble());
			((CGeoPoint *)obj)->setPoint(pt);
		}
		else if(strcmp(type, "LineString")==0){
			obj = new CGeoPolyline();
			((CGeoPolyline *)obj)->setType(QString("Polyline"));
			const Value& c = f[i]["geometry"]["coordinates"];
			for (SizeType i = 0; i < c[0].Size(); i++){ // ʹ�� SizeType ������ size_t
				QPointF pt;
				pt.setX(c[0][i][0].GetDouble());
				pt.setY(c[0][i][1].GetDouble());
				((CGeoPolyline *)obj)->addPoint(pt);
			}
		}
		else if(strcmp(type, "Polygon")==0){
			obj = new CGeoPolygon();
			((CGeoPolygon *)obj)->setType(QString("Polygon"));
			const Value& c = f[i]["geometry"]["coordinates"];
			for (SizeType i = 0; i < c[0].Size(); i++){ // ʹ�� SizeType ������ size_t
				QPointF pt;
				pt.setX(c[0][i][0].GetDouble());
				pt.setY(c[0][i][1].GetDouble());
				((CGeoPolygon *)obj)->addPoint(pt);
			}
		}
		// �洢���Դ�
		const Value& p = f[i]["properties"];
		QString str;
		for (Value::ConstMemberIterator itr = p.MemberBegin(); itr != p.MemberEnd(); ++itr)
		{
			str += QString::fromLocal8Bit(itr->name.GetString());
			str += ":";
			if(itr->value.IsDouble()){
				str += "\"";
				double x =itr->value.GetDouble();
				str += QString::number(x);
				str += "\"";
			}
			else if(itr->value.IsString())
				str += QString::fromLocal8Bit(itr->value.GetString());
			else if(itr->value.IsInt()){
				str += "\"";
				int x = itr->value.GetInt();
				str += QString::number(x);
				str += "\"";
			}
			str += ";";
		}
		obj->setProps(str);
		geolayer->addObjects(obj);
	}
	return geolayer;
}