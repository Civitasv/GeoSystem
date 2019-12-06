#include "MyTreeWidget.h"


MyTreeWidget::MyTreeWidget(QWidget *parent)
	:QTreeWidget(parent)
{
	ui.setupUi(this);
	//ui.treeWidget->setHeaderHidden(true);
	this->setHeaderLabel(QString::fromLocal8Bit("图层"));
	dialog = new Dialog();
	createActions();
	createMenu();
	setContextMenuPolicy(Qt::CustomContextMenu);  //设置枚举值
	connect(this, SIGNAL(customContextMenuRequested(const QPoint&)),this, SLOT(sltShowPopMenu(const QPoint&)));
	connect(dialog, SIGNAL(sendColorAndWidthData(QColor ,float )),this, SLOT(getColorAndWidth(QColor ,float )));
}


MyTreeWidget::~MyTreeWidget(void)
{
}

void MyTreeWidget::updateMyTreeWidgetSlot(CGeoMap *map){
	this->clear();
	this->map = map;
	for(int i=0;i<map->geoLayers.size();i++){
		QTreeWidgetItem *item = new QTreeWidgetItem(this,QStringList(map->geoLayers[i]->getLayerName()));
		item->setCheckState(0,Qt::Checked);
	}
}

void MyTreeWidget::itemClick(){
	QTreeWidgetItemIterator it(this);
	int count = 0;
	while (*it) {
		if((*it)->checkState(0)==Qt::Checked){
			map->geoLayers[count]->setVisible(true);
		}
		else{
			map->geoLayers[count]->setVisible(false);
		}
		++it;
		count++;
	}
	int mode = 3;
	emit updateTreeGLSignal(mode,this->map);
}

void MyTreeWidget::createActions(){
	//connect(ui.view_this, &QAction::triggered, this, &MyTreeWidget::viewIt);
	connect(this,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(itemClick()),Qt::UniqueConnection);

}

void MyTreeWidget::createMenu(){
	popMenu = new QMenu(this);
	QAction* act = popMenu->addAction("viewIt");
	connect(act, SIGNAL(triggered(bool)), this, SLOT(viewIt()));
	QAction* act2 = popMenu->addAction("deleteIt");
	connect(act2, SIGNAL(triggered(bool)), this, SLOT(deleteIt()));
	QAction* act3 = popMenu->addAction("properties");
	connect(act3, SIGNAL(triggered(bool)), this, SLOT(serProp()));
}

void MyTreeWidget::sltShowPopMenu(const QPoint& pos)//槽函数
{

	curItem = this->itemAt(pos);

	if (curItem == NULL)return;
	//curItem = ui.treeWidget->currentItem();  //获取当前被点击的节点
	//如果没有点击到节点
	popMenu->exec(QCursor::pos());
}

void MyTreeWidget::serProp(){
	
	dialog->show();
}

void MyTreeWidget::getColorAndWidth(QColor color,float width){
	QModelIndex index = this->currentIndex();
	int layerID = index.row();
	emit sendColorAndWidthData(layerID,color,width);
}

//右键选项的执行函数
void MyTreeWidget::viewIt()
{
	QModelIndex index = this->currentIndex();
	int layerID = index.row();
	int mode = 5;
	emit updateLayerIDSignal(mode,layerID);

}

//右键选项的执行函数
void MyTreeWidget::deleteIt()
{
	// 删除map的第几个
	QModelIndex index = this->currentIndex();
	int layerID = index.row();
	map->deleteLayerAt(layerID);
	// 通知myclass
	int mode = 4;
	emit updateTreeGLSignal(mode,this->map);
	// 刷新菜单
	updateMyTreeWidgetSlot(this->map);
}

