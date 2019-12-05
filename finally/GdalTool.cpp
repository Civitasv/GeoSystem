#include "GdalTool.h"
using namespace std;

GdalTool::GdalTool(void)
{
}


GdalTool::~GdalTool(void)
{
}

/**
*	��shp����ΪGeoJson��ʽ
*/
void GdalTool::getGeoJson(const char* filename){
	// ע��
	GDALAllRegister();
	// �½����ݼ�����
	GDALDataset *poDS;
	// �������·��
	CPLSetConfigOption("GDAL_FILENAME_IS_UTF8","NO");
	// ���������������
	CPLSetConfigOption("SHAPE_ENCODING","");  
	// ��ȡshp�ļ�
	poDS = (GDALDataset*) GDALOpenEx(filename, GDAL_OF_VECTOR, NULL, NULL, NULL );
	if( poDS == NULL )
	{
		printf( "Open failed.\n" );
		exit( 1 );
	}
	// �½�����
	OGRSFDriverH driver = OGRGetDriverByName("GeoJSON");
	// ����ļ�
	OGR_Dr_CopyDataSource(driver,poDS,"test.geojson",NULL);
	// �ر��ļ�
	GDALClose( poDS );
}

/**
*	�������Ա��ļ�
*/
void GdalTool::getDBF(const char* filename){
	// ע��
	GDALAllRegister();
	// �½����ݼ�����
	GDALDataset *poDS;
	// �������·��
	CPLSetConfigOption("GDAL_FILENAME_IS_UTF8","NO");
	// ���������������
	CPLSetConfigOption("SHAPE_ENCODING","");  
	// ��ȡshp�ļ�
	poDS = (GDALDataset*) GDALOpenEx(filename, GDAL_OF_VECTOR, NULL, NULL, NULL );
	if( poDS == NULL )
	{
		printf( "Open failed.\n" );
		exit( 1 );
	}
	// �½�txt�ļ�
	ofstream dataFile;
	fstream file("dataFile.txt", ios::out);
	dataFile.open("dataFile.txt", ofstream::app);
	if(dataFile!=NULL)
		dataFile.clear();
	dataFile << "{" << endl;

	// �õ�ͼ����
	int layerCount = poDS->GetLayerCount();
	for(int k=0;k<layerCount;k++){
		// ͼ�������
		OGRLayer *poLayer;
		poLayer = poDS->GetLayer(k); //��ȡ��
		// Ҫ�����������
		OGRFeatureDefn *poFeaDefn;
		poFeaDefn = poLayer->GetLayerDefn();
		// Ҫ�������
		OGRFeature *poFeature;
		poLayer->ResetReading();
		int i=0;
		while( (poFeature = poLayer->GetNextFeature()) != NULL )
		{
			i=i++;
			cout<<i<<"  ";
			dataFile << i<<":{"<<endl;
			int n=poFeaDefn->GetFieldCount(); //����ֶε���Ŀ��������ǰ�����ֶΣ�FID,Shape);
			for(int iField = 0; iField <n; iField++ )
			{
				// �õ�����
				dataFile<<poFeaDefn->GetFieldDefn(iField)->GetNameRef()<<":";
				//���ÿ���ֶε�ֵ
				cout<<poFeature->GetFieldAsString(iField)<<"    ";
				// ��TXT�ĵ���д������
				dataFile << poFeature->GetFieldAsString(iField)<< ","<<endl;
			}
			dataFile << "}"<<endl;
			cout<<endl;
			OGRFeature::DestroyFeature( poFeature );
		}
	}
	dataFile << "}" << endl;
	GDALClose( poDS );
	// �ر��ĵ�
	dataFile.close();
}

CGeoLayer* GdalTool::readShape(const char* filename){
	// ע��
	GDALAllRegister();
	// ��ȡ
	GDALDataset* dataset = (GDALDataset*)GDALOpenEx(filename, GDAL_OF_VECTOR, NULL, NULL, NULL);
	if( dataset == NULL )
	{
		printf( "Open failed.\n" );
		exit( 1 );
	}
	// ͼ�������
	OGRLayer *poLayer;
	CGeoLayer *geolayer = new CGeoLayer();
	poLayer = dataset->GetLayer(0); //��ȡ��
	// Ҫ�����������
	OGRFeatureDefn *poFeaDefn;
	poFeaDefn = poLayer->GetLayerDefn();
	geolayer->setLayerName(poLayer->GetName());
	OGREnvelope *envelope = new OGREnvelope;
	poLayer->GetExtent(envelope);
	geolayer->setRect(QRectF(QPointF(envelope->MinX,envelope->MaxY),QPointF(envelope->MaxX,envelope->MinY)));
	// Ҫ�������
	OGRFeature *poFeature;
	int n=poFeaDefn->GetFieldCount(); //����ֶε���Ŀ��������ǰ�����ֶΣ�FID,Shape);
	// ȷ���Ǵӿ�ʼ����
	poLayer->ResetReading();
	int i=0;
	while( (poFeature = poLayer->GetNextFeature()) != NULL )
	{
		CGeoObject *object;
		OGRGeometry *geo = poFeature->GetGeometryRef();
		if( geo != NULL
			&& wkbFlatten(geo->getGeometryType()) == wkbPoint )
		{
			OGRPoint *poPoint = (OGRPoint *) geo;
			object = new CGeoPoint();
			((CGeoPoint *)object)->setType(QString("Point"));
			QPointF pt;
			pt.setX(poPoint->getX());
			pt.setY(poPoint->getY());
			((CGeoPoint *)object)->setPoint(pt);
		}
		else if(geo != NULL
			&& wkbFlatten(geo->getGeometryType()) == wkbPolygon )
		{
			OGRPolygon *polygon = (OGRPolygon*) geo;
			object = new CGeoPolygon();
			((CGeoPolygon *)object)->setType(QString("Polygon"));
			OGRLinearRing *ring = polygon->getExteriorRing();
			int pointNum = ring->getNumPoints(); // �����
			OGRRawPoint *points = new OGRRawPoint[pointNum];
			ring->getPoints(points);
			for(int i=0;i<pointNum;i++){
				QPointF pt;
				pt.setX(points[i].x);
				pt.setY(points[i].y);
				((CGeoPolygon *)object)->addPoint(pt);
			}
		}
		else if(geo != NULL
			&& wkbFlatten(geo->getGeometryType()) == wkbLineString )
		{
			OGRLineString *polyline = (OGRLineString*) geo;
			object = new CGeoPolyline();
			((CGeoPolyline *)object)->setType(QString("Polyline"));
			int pointNum = polyline->getNumPoints(); // �����
			for(int i=0;i<pointNum;i++){
				QPointF pt;
				pt.setX(polyline->getX(i));
				pt.setY(polyline->getY(i));
				((CGeoPolyline *)object)->addPoint(pt);
			}
		}

		QString str;
		// ��������
		for(int iField = 0; iField <n; iField++ )
		{
			// �õ�����
			str+=poFeaDefn->GetFieldDefn(iField)->GetNameRef();
			str+=":";
			//���ÿ���ֶε�ֵ
			str+=poFeature->GetFieldAsString(iField);
			str+=";";
		}
		object->setProps(str);
		// ���÷�Χ
		OGREnvelope *envelope2 = new OGREnvelope;
		geo->getEnvelope(envelope2);
		object->setRect(QRectF(QPointF(envelope2->MinX,envelope2->MaxY),QPointF(envelope2->MaxX,envelope2->MinY)));
		geolayer->addObjects(object);
		OGRFeature::DestroyFeature( poFeature );

	}
	GDALClose( dataset );
	return geolayer;
}