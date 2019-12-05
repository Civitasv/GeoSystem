#include "myclass.h"
#include <QtWidgets/QApplication>
#include "MyGLWidget.h"
#include "MyTreeWidget.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	MyClass *w = new MyClass();
	//MyGLWidget *glWidget=new MyGLWidget();
	//w.putOpenGLWidget(glWidget);
	MyTreeWidget *treeWidget = new MyTreeWidget();
	///MyGLWidget *gl = new MyGLWidget();
	treeWidget->resize(231, 644);
	//w->treeWidget = treeWidget;
	//w->gl = gl;
	//treeWidget->gl = gl;
	//w.putTreeWidget(treeWidget);
	w->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
	QObject::connect(treeWidget,SIGNAL(updateTreeGLSignal(int,CGeoMap *)),w,SLOT(updateTreeGLSlot(int ,CGeoMap *)),Qt::UniqueConnection);
	QObject::connect(w,SIGNAL(updateMyTreeWidgetSignal(CGeoMap *)),treeWidget,SLOT(updateMyTreeWidgetSlot(CGeoMap *)),Qt::UniqueConnection);
	QObject::connect(treeWidget,SIGNAL(updateLayerIDSignal(int,int)),w,SLOT(updateLayerIDSlot(int,int)),Qt::UniqueConnection);

	w->show();
	treeWidget->show();
	//MyGLWidget gl;
	//gl.show();
	return a.exec();
}
