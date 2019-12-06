#include "dialog.h"
#include "XColorMaster.h"
#include "XGradientSlider.h"
#include "XColorPreview.h"
#include "XColorDialog.h"
#include <QLayout>

Dialog::Dialog(QWidget *parent) :
	QDialog(parent)
{
	ui.setupUi(this);
	//    XColorSquare* colorSquare = new XColorSquare(this);
	//    colorSquare->setColor(Qt::red);
	//    colorSquare->setCheckedColor('H');
	//    XColorPreview *color = new XColorPreview(this);
	//    color->setColor(Qt::red);

	//    XColorDialog *dialog = new XColorDialog(this);

	sc = new XColorMaster(this);
	ui.horizontalLayout_5->addWidget(sc);

	//    XGradientSlider *slider = new XGradientSlider(this);
	//    slider->setFirstColor(Qt::red);
	//    slider->setLastColor(Qt::green);
	//    QVBoxLayout *hLayout = new QVBoxLayout;
	//    hLayout->addWidget(sc);
	//    hLayout->addWidget(slider);
	//    hLayout->addWidget(dialog);
	//    this->setLayout(hLayout);
	//    hLayout->addWidget(color);
	//    hLayout->addWidget(sc);
	//    setLayout(hLayout);
}

Dialog::~Dialog()
{
	
}

void Dialog::continueClick(){
	bool ok;
	float width = ui.lineEdit->displayText().toFloat(&ok);
	emit sendColorAndWidthData(sc->color,width);
	this->close();
}

void Dialog::cancelClick(){
	this->close();
}