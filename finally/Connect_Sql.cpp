#include "Connect_Sql.h"
using namespace std;


Connect_Sql::Connect_Sql(void)
{
}


Connect_Sql::~Connect_Sql(void)
{
}

// 使用libpq连接
bool Connect_Sql::ConnectToDB()
{
	int lib_ver = PQlibVersion();
	printf("Version of libpq: %d\n", lib_ver);
	PGconn *conn = PQconnectdb("host=127.0.0.1 dbname=test user=postgres password=husen");//该行应根据个人情况进行修改
	if (PQstatus(conn) == CONNECTION_BAD) {
		fprintf(stderr, "Connection to database failed: %s\n",
			PQerrorMessage(conn));
		PQfinish(conn);
		return 0;
	}
	int ver = PQserverVersion(conn);
	printf("Server version: %d\n", ver);
	PQfinish(conn);
	return 0;
}

// 连接数据库存储shp数据，这样的话一个shp文件对应一张表
bool Connect_Sql::ConnectToDBSaveShpByGdal(const char* filename){
	GdalTool gdalTool;

	CGeoLayer *layer = gdalTool.readShape(filename);
	// 注册驱动
	OGRRegisterAll();
	// 数据库连接参数
	const char* filepath = "PG:dbname=test host=127.0.0.1 user=postgres password=husen";
	const char* driver = "PostgreSQL";
	std::string str = layer->getLayerName().toStdString();
	const char* table = str.c_str();
	OGRSFDriver *pDriver = NULL;
	OGRLayer* player = NULL;
	OGRDataSource* pDS = NULL;
	pDS = (OGRDataSource*) GDALOpenEx(filepath, GDAL_OF_VECTOR, NULL, NULL, NULL );
	/*
	pDriver = (OGRSFDriver*)OGRSFDriverRegistrar::GetRegistrar()->GetDriverByName(driver);
	if ( pDriver == NULL ) {
	return false;
	}
	pDS = pDriver->Open(filepath,0);
	*/
	if ( NULL == pDS ) {
		return false;
	}
	// 创建数据表
	//pDS->DeleteLayer(0);
	player = pDS->CreateLayer( table,NULL,wkbPolygon,NULL );
	if ( NULL == player )
	{
		return false;
	}
	//定义一个字段one_way
	OGRFieldDefn* pfielddefn_oneway = new OGRFieldDefn("type",OFTString);
	//在数据表中创建定义的字段
	player->CreateField(pfielddefn_oneway);
	OGRFieldDefn* pfielddefn_name = new OGRFieldDefn("properties",OFTString);
	player->CreateField(pfielddefn_name);
	//删除字段定义指针
	delete pfielddefn_oneway;
	delete pfielddefn_name;

	for(int i = 0;i<layer->geoObjects.size();i++){
		CGeoObject *obj = layer->geoObjects[i];
		std::string str2 = obj->getType().toStdString();
		if(strcmp(str2.c_str(),"Point")==0){
			OGRPoint *point = new OGRPoint();
			point->setX(((CGeoPoint*)obj)->getPoint().x());
			point->setY(((CGeoPoint*)obj)->getPoint().y());
			OGRGeometry* pgeo = (OGRGeometry*)point;
			pgeo->setCoordinateDimension(2);//设置坐标系维度
			OGRFeature* pfeature = OGRFeature::CreateFeature( player->GetLayerDefn() );
			pfeature->SetField("type","Point");
			std::string str3 = ((CGeoPoint*)obj)->getProps().toStdString();
			pfeature->SetField("properties",str3.c_str());
			if ( OGRERR_NONE != pfeature->SetGeometry( pgeo ) )
			{
				return false;
			}
			//将记录写入数据表
			if ( OGRERR_NONE != player->CreateFeature( pfeature ) )
			{
				return false;
			}
			//delete point;
			OGRFeature::DestroyFeature(pfeature);
		}
		else if(strcmp(str2.c_str(),"Polygon")==0){
			OGRPolygon *polygon = new OGRPolygon();
			OGRLinearRing *ring = new OGRLinearRing();
			int num = ((CGeoPolygon*)obj)->pts.size();
			for(int i=0;i<num;i++){
				ring->addPoint( ((CGeoPolygon*)obj)->pts[i].x(), ((CGeoPolygon*)obj)->pts[i].y());
			}
			polygon->addRing(ring);
			OGRGeometry* pgeo = (OGRGeometry*)polygon;
			pgeo->setCoordinateDimension(2);//设置坐标系维度
			OGRFeature* pfeature = OGRFeature::CreateFeature( player->GetLayerDefn() );
			pfeature->SetField("type","Polygon");
			std::string str3 = ((CGeoPolygon*)obj)->getProps().toStdString();
			pfeature->SetField("properties",str3.c_str());
			if ( OGRERR_NONE != pfeature->SetGeometry( pgeo ) )
			{
				return false;
			}
			//将记录写入数据表
			if ( OGRERR_NONE != player->CreateFeature( pfeature ) )
			{
				return false;
			}
			//delete polygon;
			OGRFeature::DestroyFeature(pfeature);

		}
		else if(strcmp(str2.c_str(),"Polyline")==0){
			OGRLineString *polyline = new OGRLineString();
			int num = ((CGeoPolyline*)obj)->pts.size();
			for(int i=0;i<num;i++){
				polyline->addPoint( ((CGeoPolyline*)obj)->pts[i].x(), ((CGeoPolyline*)obj)->pts[i].y());
			}
			OGRGeometry* pgeo = (OGRGeometry*)polyline;
			pgeo->setCoordinateDimension(2);//设置坐标系维度
			OGRFeature* pfeature = OGRFeature::CreateFeature( player->GetLayerDefn() );
			pfeature->SetField("type","Polyline");
			std::string str3 = ((CGeoPolyline*)obj)->getProps().toStdString();
			pfeature->SetField("properties",str3.c_str());
			if ( OGRERR_NONE != pfeature->SetGeometry( pgeo ) )
			{
				return false;
			}
			//将记录写入数据表
			if ( OGRERR_NONE != player->CreateFeature( pfeature ) )
			{
				return false;
			}
			//delete polyline;
			OGRFeature::DestroyFeature(pfeature);
		}
	}
	OGRDataSource::DestroyDataSource(pDS);
	return true;
}

// 使用gdal连接得到shp数据
CGeoLayer* Connect_Sql::ConnectToDBGetShpByGdal( QString dbname,QString port,QString host,QString user,QString password,QString table){
	// 数据库连接参数
	OGRRegisterAll();
	QString filepath = "PG:dbname="+dbname+" port="+port+" host="+host+" user="+user+" password="+password;
	OGRDataSource* pDS = NULL;
	std::string s = table.toStdString();
	const char* tab = s.c_str();
	OGRLayer* player = NULL;
	std::string s2 = filepath.toStdString();
	const char* filep = s2.c_str();
	pDS = (OGRDataSource*) GDALOpenEx(filep, GDAL_OF_VECTOR, NULL, NULL, NULL );
	if ( NULL == pDS ) {
		return false;
	}
	// 得到table表
	player = pDS->GetLayerByName(tab);
	if ( NULL == player )
	{
		return false;
	}

	// 图层类对象
	CGeoLayer *geolayer = new CGeoLayer();
	// 要素描述类对象
	OGRFeatureDefn *poFeaDefn;
	poFeaDefn = player->GetLayerDefn();
	geolayer->setLayerName(player->GetName());
	OGREnvelope *envelope = new OGREnvelope;
	player->GetExtent(envelope);
	geolayer->setRect(QRectF(QPointF(envelope->MinX,envelope->MaxY),QPointF(envelope->MaxX,envelope->MinY)));
	// 要素类对象
	OGRFeature *poFeature;
	int n=poFeaDefn->GetFieldCount(); //获得字段的数目，不包括前两个字段（FID,Shape);
	// 确保是从开始读的
	player->ResetReading();
	int i=0;
	while( (poFeature = player->GetNextFeature()) != NULL )
	{
		const char* type = poFeature->GetFieldAsString("type");
		const char* properties = poFeature->GetFieldAsString("properties");

		CGeoObject *object;
		OGRGeometry *geo = poFeature->GetGeometryRef();
		if( geo != NULL
			&& strcmp(type, "Point")==0)
		{
			OGRPoint *poPoint = (OGRPoint *) geo;
			object = new CGeoPoint();
			((CGeoPoint *)object)->setType(QString("Point"));
			QPointF pt;
			pt.setX(poPoint->getX());
			pt.setY(poPoint->getY());
			((CGeoPoint *)object)->setPoint(pt);
			geolayer->type = 0;

		}
		else if(geo != NULL
			&& strcmp(type, "Polygon")==0)
		{
			OGRPolygon *polygon = (OGRPolygon*) geo;
			object = new CGeoPolygon();
			((CGeoPolygon *)object)->setType(QString("Polygon"));
			OGRLinearRing *ring = polygon->getExteriorRing();
			int pointNum = ring->getNumPoints(); // 点个数
			OGRRawPoint *points = new OGRRawPoint[pointNum];
			ring->getPoints(points);
			for(int i=0;i<pointNum;i++){
				QPointF pt;
				pt.setX(points[i].x);
				pt.setY(points[i].y);
				((CGeoPolygon *)object)->addPoint(pt);
			}
			geolayer->type = 2;

		}
		else if(geo != NULL
			&& strcmp(type, "Polyline")==0 )
		{
			OGRLineString *polyline = (OGRLineString*) geo;
			object = new CGeoPolyline();
			((CGeoPolyline *)object)->setType(QString("Polyline"));
			int pointNum = polyline->getNumPoints(); // 点个数
			for(int i=0;i<pointNum;i++){
				QPointF pt;
				pt.setX(polyline->getX(i));
				pt.setY(polyline->getY(i));
				((CGeoPolyline *)object)->addPoint(pt);
			}
			geolayer->type = 1;

		}

		object->setProps(properties);
		// 设置范围
		OGREnvelope *envelope2 = new OGREnvelope;
		geo->getEnvelope(envelope2);
		object->setRect(QRectF(QPointF(envelope2->MinX,envelope2->MaxY),QPointF(envelope2->MaxX,envelope2->MinY)));
		if(object->getType().compare("Polygon")==0){ // 如果是多边形
			/*QPolygonF pts = ((CGeoPolygon *)object)->pts; // 得到多边形所有顶点
			// 三角剖分
			QPolygonF result;
			Triangulate::Process(pts,result);
			CGeoObject *obj = new CGeoPolygon();
			((CGeoPolygon *)obj)->pts = result;
			((CGeoPolygon *)obj)->setType("Polygon");
			geolayer->addObjects(obj);*/
			gpc_tristrip* tristrip = new gpc_tristrip();
			Triangle((CGeoPolygon*)object,tristrip);
			CGeoObject *obj = new CGeoPolygon();
			((CGeoPolygon *)obj)->setType("Polygon");
			for (int i=0; i<tristrip->num_strips; i++)
			{
				for (int j=0; j<tristrip->strip[i].num_vertices; j++)
				{
					((CGeoPolygon *)obj)->addPoint(QPointF(tristrip->strip[i].vertex[j].x,tristrip->strip[i].vertex[j].y));
					((CGeoPolygon *)obj)->addPoint(QPointF(tristrip->strip[i].vertex[j+1].x,tristrip->strip[i].vertex[j+1].y));
					((CGeoPolygon *)obj)->addPoint(QPointF(tristrip->strip[i].vertex[j+2].x,tristrip->strip[i].vertex[j+2].y));
				}
			}
			geolayer->addObjects(obj);
		}else{
			geolayer->addObjects(object);
		}
	}

	OGRDataSource::DestroyDataSource(pDS);
	MyXMLReader xmlReader;
	xmlReader.readSLDFile("G:\\finally\\polygon.xml",geolayer);
	return geolayer;

}