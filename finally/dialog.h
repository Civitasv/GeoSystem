#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "XColorMaster.h"
#include "ui_dialog.h"

namespace Ui {
	class Dialog;
}

class Dialog : public QDialog
{
	Q_OBJECT

public:
	explicit Dialog(QWidget *parent = 0);
	~Dialog();
	enum CheckedColor
	{
		H,S,V,R,G,B
	}checkedColor;
	XColorMaster *sc;
private:
	Ui::Form7 ui;

	private slots:
		void continueClick();
		void cancelClick();
signals:
		void sendColorAndWidthData(QColor color,float width);//÷ÿ–¬‰÷»æ–≈∫≈
};

#endif // DIALOG_H
