#include "myclass.h"

MyClass::MyClass(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	createActions();

	QString message = tr("A context menu is available by right-clicking");
	statusBar()->showMessage(message);
	gl = new MyGLWidget();

	QObject::connect(this,SIGNAL(updateMyGLSignal(int,const char*,int)),gl,SLOT(updateMyGLSlot(int,const char*,int)));
	QObject::connect(this,SIGNAL(updateMyGLPostgresqlSignal(int,int,QString,QString,QString,QString ,QString )),gl,SLOT(updateMyGLPostgresqlSlot(int,int,QString,QString,QString,QString ,QString)));
	QObject::connect(this,SIGNAL(updateData(int,CGeoMap*)),gl,SLOT(updateData(int,CGeoMap*)));
	QObject::connect(this,SIGNAL(updateLayerIDSignal(int,int)),gl,SLOT(updateLayerID(int,int)));

	ui.verticalLayout_2->addWidget(gl);

}

MyClass::~MyClass()
{
	if(gl!=NULL)
		delete gl;
}


void MyClass::readGeoJson(){
	QString message = tr("readGeoJson");
	statusBar()->showMessage(message);
	QString filename;
	filename = QFileDialog::getOpenFileName(this,tr("file"),"",tr("*.geojson"));
	if(!filename.isNull()){
		const char *fileName;
		// 二进制读取
		QByteArray ba = filename.toLocal8Bit();
		fileName=ba.data();
		FILE *file = fopen(fileName,"rb");
		if (file == NULL)//判断文件存在
		{
			exit(1);
		}
		/*
		MyGLWidget *gl = new MyGLWidget();
		gl->id = gls.size(); // 设置id
		// 储存所有的图像
		gls.append(gl);
		*/
		//MyGLWidget* glTemp = new MyGLWidget();
		//glTemp->map = gl->map;
		int layerID = gl->map->geoLayers.size();
		int mode = 0;
		emit updateMyGLSignal(mode,fileName,layerID);
		//gl->show();
		// 删除所有的
		//QLayoutItem *child;
		//while(child=ui.verticalLayout_2->takeAt(0)) {
		//delete child;
		//}
		// 画出全部
		//gl=glTemp;
		// 菜单栏

		emit updateMyTreeWidgetSignal(gl->map);
		//this->show();
	}
	else{
		qDebug()<<"取消";
	}

}

void MyClass::readShape(){
	QString message = tr("readShape");
	statusBar()->showMessage(message);
	QString filename;
	filename = QFileDialog::getOpenFileName(this,tr("file"),"",tr("*.shp"));
	if(!filename.isNull()){
		const char *fileName;
		// 二进制读取
		QByteArray ba = filename.toLocal8Bit();
		fileName=ba.data();
		FILE *file = fopen(fileName,"rb");
		if (file == NULL)//判断文件存在
		{
			exit(1);
		}
		/*
		MyGLWidget* glTemp = new MyGLWidget();
		glTemp->map = gl->map;
		int layerID = gl->map->geoLayers.size();
		QObject::connect(this,SIGNAL(updateMyGLSignal(int,const char*,int)),glTemp,SLOT(updateMyGLSlot(int,const char*,int)),Qt::UniqueConnection);
		int mode = 1;
		emit updateMyGLSignal(mode,fileName,layerID);
		// 删除所有的
		QLayoutItem *child;
		while(child=ui.verticalLayout_2->takeAt(0)) {
		delete child;
		}
		// 画出全部
		ui.verticalLayout_2->addWidget(glTemp);
		gl = glTemp;
		*/
		int layerID = gl->map->geoLayers.size();
		int mode = 1;
		emit updateMyGLSignal(mode,fileName,layerID);
		// 菜单栏
		// QObject::connect(this,SIGNAL(updateMyTreeWidgetSignal(CGeoMap *,MyGLWidget *)),treeWidget,SLOT(updateMyTreeWidgetSlot(CGeoMap *,MyGLWidget*)),Qt::UniqueConnection);
		emit updateMyTreeWidgetSignal(gl->map);
		//this->show();
	}
	else{
		qDebug()<<"取消";
	}
}


void MyClass::saveShapefile(){
	QString message = tr("saveShapefile");
	statusBar()->showMessage(message);
	QString filename;
	filename = QFileDialog::getOpenFileName(this,tr("file"),"",tr("*.shp"));
	if(!filename.isNull()){
		const char *fileName;
		// 二进制读取
		QByteArray ba = filename.toLocal8Bit();
		fileName=ba.data();
		FILE *file = fopen(fileName,"rb");
		if (file == NULL)//判断文件存在
		{
			exit(1);
		}
		Connect_Sql connectSql;
		connectSql.ConnectToDBSaveShpByGdal(fileName);
	}
	else{
		qDebug()<<"取消";
	}
}

void MyClass::getDatabaseData(){
	// 向导
	int layerID = gl->map->geoLayers.size();
	int mode = 6;
	QString dbname="test";
	QString host="127.0.0.1";
	QString user="postgres";
	QString password="husen";
	QString table="bou2_4p";
	emit updateMyGLPostgresqlSignal(mode,layerID,dbname,host,user,password,table); // 读取数据库，重新渲染
	emit updateMyTreeWidgetSignal(gl->map);
	gl->update();

}


void MyClass::createActions(){
	connect(ui.actionGeojson, &QAction::triggered, this, &MyClass::readGeoJson);
	connect(ui.actionShp, &QAction::triggered, this, &MyClass::readShape);
	connect(ui.actionSave_shapefile,&QAction::triggered,this,&MyClass::saveShapefile);
	connect(ui.actionGet_databaseData,&QAction::triggered,this,&MyClass::getDatabaseData);


}

void MyClass::updateTreeGLSlot(int mode,CGeoMap *map){
	/*
	MyGLWidget* glTemp = new MyGLWidget();
	glTemp->map = gl->map;
	//int layerID = gl->map->geoLayers.size();
	glTemp->layerID = gl->layerID;
	glTemp->viewLayer = gl->viewLayer;
	glTemp->rect = gl->rect;
	QObject::connect(this,SIGNAL(updateData(int,CGeoMap*)),glTemp,SLOT(updateData(int,CGeoMap*)),Qt::UniqueConnection);
	emit updateData(mode,map);
	// 删除所有的
	QLayoutItem *child;
	while(child=ui.verticalLayout_2->takeAt(0)) {
	delete child;
	}
	// 画出全部
	ui.verticalLayout_2->addWidget(glTemp);
	gl=glTemp;
	*/
	//int layerID = gl->map->geoLayers.size();
	//int mode = 0;
	emit updateData(mode,map);
	//this->show();
	gl->update();
}
/*
void MyClass::paintEvent(QPaintEvent * /* event )
{
CGeoMap *map = new CGeoMap();
GeoJsonTool geo;
CGeoLayer *layer = geo.readGeoJSON("F:\\college\\大三上\\kmj\\second_exp\\second_exp\\test.geojson");
map->addLayer(layer);
QPainter painter(this);
// 尽可能的消除锯齿
painter.setRenderHint(QPainter::Antialiasing, true);
// 坐标变换
int W=width(); //取窗体的宽
int H=height();//去窗体的高
// 视口 物理
QRect view_rect(QPoint(0,0),QPoint(W,H));
// 窗口 逻辑
QRect logic_rect = map->getScope().toRect();
// 使视口比例与窗口比例一致
double ratio = -logic_rect.width()/logic_rect.height();
view_rect.setWidth(view_rect.height()*ratio);
view_rect.moveLeft((W-view_rect.width())/2);
painter.setViewport(view_rect);
painter.setWindow(logic_rect);
map->paint(&painter);

}
*/

void MyClass::updateLayerIDSlot(int mode,int layerID){
	emit updateLayerIDSignal(mode,layerID);
	gl->update();
}