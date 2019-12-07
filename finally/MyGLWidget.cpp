#include "MyGLWidget.h"


MyGLWidget::MyGLWidget(QWidget *parent)
	: QOpenGLWidget(parent)
{
	ui.setupUi(this);
	VBO = (GLuint *) malloc(16);
	VAO = (GLuint *) malloc(16);
	len = (int *) malloc(16);
	map = new CGeoMap();
	size = 0;
	QCursor cursor;
	cursor.setShape(Qt::ArrowCursor);
	setCursor(cursor);
	scaleParam = 0;
	//设置无边框
	this->setWindowFlags(Qt::FramelessWindowHint);
}

MyGLWidget::~MyGLWidget(void)
{
	glDeleteVertexArrays(size, VAO);
	glDeleteBuffers(size, VBO);
}

void MyGLWidget::createShader(const char* vertexPath, const char* fragmentPath){
	// 1. retrieve the vertex/fragment source code from filePath
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	// ensure ifstream objects can throw exceptions:
	vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		// open files
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		std::stringstream vShaderStream, fShaderStream;
		// read file's buffer contents into streams
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		// close file handlers
		vShaderFile.close();
		fShaderFile.close();
		// convert stream into string
		vertexCode   = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
	const char* vShaderCode = vertexCode.c_str();
	const char * fShaderCode = fragmentCode.c_str();
	// 2. compile shaders
	unsigned int vertex, fragment;
	// vertex shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	checkCompileErrors(vertex, "VERTEX");
	// fragment Shader
	fragment =glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	checkCompileErrors(fragment, "FRAGMENT");
	// shader Program
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	checkCompileErrors(ID, "PROGRAM");
	// delete the shaders as they're linked into our program now and no longer necessary
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}
void MyGLWidget::initializeGL(){
	initializeOpenGLFunctions();
	// 设置初始屏幕颜色和透明度
	glClearColor(25,35,45,1);
	createShader("G:\\qt_project\\shader.vs", "G:\\qt_project\\shader.fs");
	if(mode==0){ //==0表示绘制geojson
		readDataFromGeoJSON(filename);
	}
	else if(mode==1){//==1表示绘制shapefile
		readDataFromShape(filename);
	}
	else if(mode==6){// ==5表示读取数据库数据
		readDataFromPostgresql();
	}
	loadData();
}

void MyGLWidget::resizeGL(int w,int h){
	glViewport(0,0,w,h);
}

void MyGLWidget::paintGL(){
	glClearColor(25.0/255,35.0/255,45.0/255,1);
	//glClearColor(255,255,255,1);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(ID);
	if(mode!=0 && mode!=1&&mode!=3&&mode!=4&&mode!=5&&mode!=6)
		return;
	if(size==0){
		return;
	}
	QMatrix4x4 model;
	QMatrix4x4 view;
	QMatrix4x4 ortho;
	float screen_width = width();
	float screen_height = height();
	ortho.scale(1+scaleParam); 

	// 正投影矩阵
	float ratio = -rect.width()/rect.height();
	float ratio2 = screen_width/screen_height;
	if(ratio2>ratio){
		ortho.scale(ratio/ratio2,1); 
	}
	else{
		ortho.scale(1,ratio2/ratio); 
	}
	ortho.ortho(rect);
	ortho.translate(offset.x(),-offset.y());

	//ortho.ortho(70.0f,140.0f,3.0f,60.0f,0.0f,15.0f);
	view.lookAt(QVector3D(0,0,0),QVector3D(0,0,0),QVector3D(0,1,0));
	//model.scale(QVector3D(0.5f,0.5f,1.0f));
	// 先写缩放，再写投影，实际上是先投影再缩放

	//model.rotate(-55.0f,QVector3D(1.0f, 0.0f, 0.0f));

	GLuint modeLoc = glGetUniformLocation(ID,"model");
	GLuint viewLoc = glGetUniformLocation(ID,"view");
	GLuint projLoc = glGetUniformLocation(ID,"ortho");
	GLuint colorLoc = glGetUniformLocation(ID,"mycolor");
	// 传入着色器
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view.data());
	glUniformMatrix4fv(modeLoc, 1, GL_FALSE, model.data());
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, ortho.data());

	int count = 0;

	for(int i=0;i<map->geoLayers.size();i++){
		if(map->geoLayers[i]->type==2){
			for(int j=0;j<map->geoLayers[i]->geoObjects.size();j++){
				CGeoObject *obj = map->geoLayers[i]->geoObjects[j];
				// 启动反走样
				/*
				glEnable(GL_BLEND);
				glEnable(GL_POLYGON_SMOOTH);
				glHint(GL_POLYGON_SMOOTH_HINT, GL_FASTEST);  // Antialias the lines
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
				*/
				glUniform4f(colorLoc, obj->fillR, obj->fillG, obj->fillB, obj->alpha);
				glBindVertexArray(VAO[count]);
				glDrawArrays(GL_TRIANGLES, 0, len[count]);
				count++;
			}
		}
		else if(map->geoLayers[i]->type==0 ){
			CGeoObject *obj = map->geoLayers[i]->geoObjects[0];
			// 启动反走样
			/*
			glEnable(GL_BLEND);
			glEnable(GL_POINT_SMOOTH);
			glHint(GL_POINT_SMOOTH_HINT, GL_FASTEST);  // Antialias the lines
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
			*/
			glUniform4f(colorLoc, obj->fillR, obj->fillG, obj->fillB, obj->alpha);
			glBindVertexArray(VAO[count]);
			glDrawArrays(GL_POINTS, 0, len[count]);
			count++;
		}
		else if(map->geoLayers[i]->type==1 ){
			for(int j=0;j<map->geoLayers[i]->geoObjects.size();j++){
				CGeoObject *obj = map->geoLayers[i]->geoObjects[j];
				//启用反走样
				/*glEnable(GL_BLEND);
				glEnable(GL_LINE_SMOOTH);
				glHint(GL_LINE_SMOOTH_HINT, GL_FASTEST);  // Antialias the lines
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
				*/
				glUniform4f(colorLoc, obj->strokeR, obj->strokeG, obj->strokeB, obj->alpha);
				// 线宽
				glLineWidth(obj->strokeWidth); 
				glBindVertexArray(VAO[count]);
				glDrawArrays(GL_LINE_STRIP, 0, len[count]);
				count++;
			}
		}

	}
}

void MyGLWidget:: checkCompileErrors(unsigned int shader, std::string type)
{
	int success;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
}

void MyGLWidget::readDataFromGeoJSON(const char* filename){
	// 获取layer
	GeoJsonTool geo;
	CGeoLayer *layer = geo.readGeoJSON(filename);
	map->addLayer(layer);
	viewLayer = map->geoLayers[layerID];
}

void MyGLWidget::readDataFromShape(const char* filename){
	// 获取layer
	GdalTool gdal;
	CGeoLayer *layer = gdal.readShape(filename);
	// 使用第二种方式设置map的范围
	map->addLayer(layer);
	viewLayer = map->geoLayers[layerID];
}

void MyGLWidget::readDataFromPostgresql(){
	Connect_Sql connectSql;
	CGeoLayer* layer = connectSql.ConnectToDBGetShpByGdal(dbname,port,host,user,password,table);
	map->addLayer(layer);
	viewLayer = map->geoLayers[layerID];
}


void MyGLWidget::loadData(){
	if(mode==0 || mode==1||mode==3||mode==4||mode==5||mode==6){
		if(viewLayer->getRect().width()!=0){
			rect = viewLayer->getRect();
		}else{
			rect = viewLayer->getScope();
		}
	}
	size = 0;
	for(int i=0;i<map->geoLayers.size();i++){
		if(map->geoLayers[i]->getVisible() && (map->geoLayers[i]->type==2 || map->geoLayers[i]->type==1)){ // 可见且为POLYGON
			// 对每一个POLYGON LAYER的每一个object生成一个VBO和VAO对象
			size += map->geoLayers[i]->geoObjects.size();
		}
		else if(map->geoLayers[i]->getVisible() && map->geoLayers[i]->type==0){ // 可见且为POINT
			// 对每一个POINT LAYER仅生成一个VBO和VAO对象
			size += 1;
		}
		/*else if(map->geoLayers[i]->getVisible() && map->geoLayers[i]->type==1){ // 可见且为POLYLINE
		// 对每一个POLYINE LAYER仅生成一个VBO和VAO对象
		size += 1;
		}
		*/
	}
	qDebug()<<size;
	// 重新分配内存
	VAO = new GLuint[size];
	VBO = new GLuint[size];
	len =  new int[size];
	glGenVertexArrays(size, VAO);
	glGenBuffers(size, VBO);
	int num = 0;
	for(int j=0;j<map->geoLayers.size();j++){
		CGeoLayer *temp = map->geoLayers[j];
		if(temp->getVisible() && (temp->type==2 || temp->type==1)){
			for(int i=0;i<temp->geoObjects.size();i++){
				// 对于每一个VAO和VBO,count是Geobject的顶点数组的数目
				float *vertices =  (float *) malloc(16);
				int *count = (int *) malloc(4);
				*count = 0; // 初始值为零
				vertices = temp->geoObjects[i]->getVert(vertices,count);
				len[num] = *count/3;
				// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
				glBindVertexArray(VAO[num]);
				glBindBuffer(GL_ARRAY_BUFFER, VBO[num]);
				glBufferData(GL_ARRAY_BUFFER, *count*sizeof(float), vertices, GL_STATIC_DRAW);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
				glEnableVertexAttribArray(0);
				// color attribute
				//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
				//glEnableVertexAttribArray(1);
				// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
				glBindBuffer(GL_ARRAY_BUFFER, 0); 

				// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
				// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
				glBindVertexArray(0);
				delete[] vertices;
				delete count;
				num++;
			}
		}

		else if(temp->getVisible() && temp->type==0){
			// 对于每一个VAO和VBO,count是Geobject的顶点数组的数目
			float *vertices =  new float();
			int *count = new int();
			*count = 0; // 初始值为零
			vertices = temp->getVert(vertices,count);
			len[num] = *count/3;
			// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
			glBindVertexArray(VAO[num]);
			glBindBuffer(GL_ARRAY_BUFFER, VBO[num]);
			glBufferData(GL_ARRAY_BUFFER, *count*sizeof(float), vertices, GL_STATIC_DRAW);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);
			// color attribute
			//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
			//glEnableVertexAttribArray(1);
			// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
			glBindBuffer(GL_ARRAY_BUFFER, 0); 

			// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
			// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
			glBindVertexArray(0);
			delete[] vertices;
			delete count;
			num++;
		}
	}
}
void MyGLWidget::updateMyGLSlot(int mode,const char* filename,int layerID){
	this->mode = mode;
	this->filename = filename;
	this->layerID = layerID;
	makeCurrent();
	initializeGL();
	update();

}

void MyGLWidget::getColorAndWidthData2(int layerID,QColor color,float width){//重新渲染信号
	CGeoLayer *layer = map->geoLayers[layerID];
	for(int i=0;i<layer->geoObjects.size();i++){
		CGeoObject *obj =layer->geoObjects[i];
		if(obj->getType().compare("point")==0 || obj->getType().compare("Polygon")==0){
			obj->fillR = color.redF();
			obj->fillG = color.greenF();
			obj->fillB = color.blueF();
			obj->alpha = color.alphaF();
		}
		else if(obj->getType().compare("Polyline")==0){
			obj->strokeR = color.redF();
			obj->strokeG = color.greenF();
			obj->strokeB = color.blueF();
			obj->alpha = color.alphaF();
			obj->strokeWidth = width;
		}
	}
	update();
}

void MyGLWidget::updateMyGLPostgresqlSlot(int mode,int layerID,QString port,QString dbname,QString host,QString user,QString password,QString table){ // 读取数据库，重新渲染
	this->mode = mode;
	this->dbname = dbname;
	this->host = host;
	this->user = user;
	this->password = password;
	this->table = table;
	this->layerID = layerID;
	this->port = port;
	makeCurrent();
	initializeGL();
	update();

}

void MyGLWidget::updateData(int mode,CGeoMap* map){
	this->mode = mode;
	this->map = map;
	//loadData();
	makeCurrent();
	initializeGL();
	update();

}

void MyGLWidget::updateLayerID(int mode,int layerID){
	this->mode = mode;
	this->layerID = layerID;
	viewLayer = map->geoLayers[layerID];
	offset.setX(0);
	offset.setY(0);
	scaleParam = 0;
	makeCurrent();
	initializeGL();
	update();
}



void MyGLWidget::wheelEvent(QWheelEvent *event){

	QRect tmp=this->geometry();
	if(event->delta()>0){//如果滚轮往上滚
		// 放大
		scaleParam += (event->delta()/(15*8))*0.1;
	}else{
		// 缩放
		scaleParam -= -event->delta()/(15*8)*0.1;
	}
	if(scaleParam<=-1){
		scaleParam = -0.9;
	}
	update();
	event->accept();
}

void MyGLWidget::mousePressEvent(QMouseEvent* event){
	if(event->button() == Qt::LeftButton){
		QCursor cursor;
		cursor.setShape(Qt::ClosedHandCursor);
		QApplication::setOverrideCursor(cursor);
		//globalPos()是鼠标指针相对于屏幕左上角的坐标， pos()是窗体左上角相对于屏幕左上角的坐标 （获取未移动前的窗体位置）
		begin = event->globalPos() - pos();
	}
	else if(event->button() == Qt::RightButton){

	}
}
void MyGLWidget::mouseReleaseEvent(QMouseEvent* event){
	QApplication::restoreOverrideCursor();
}
void MyGLWidget::mouseMoveEvent(QMouseEvent* event){
	if(event->buttons() & Qt::LeftButton){//与运算
		QPointF temp;
		temp = event->globalPos() -begin;//
		offset.setX(offset.x()+screenToWorld(temp).x());
		offset.setY(offset.y()-screenToWorld(temp).y());

		//move(offset);//移动到具体坐标点
		//paintGL();
		update();
		qDebug()<<"globalPos"<<event->globalPos()<<endl;
		qDebug()<<"pos"<<pos()<<endl;
	}
}

QPointF MyGLWidget::screenToWorld(QPointF screenPoint){
	QPointF p;
	double w = this->width() * 1.0;
	double h = this->height() * 1.0;
	double x = screenPoint.x() * 1.0;
	double y = screenPoint.y() * 1.0;

	p.setX(x / w * rect.width()/10);
	p.setY(y/h * rect.height()/10);

	return p;

}