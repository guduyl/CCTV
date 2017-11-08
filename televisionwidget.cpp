
#include "televisionwidget.h"





TelevisionWidget::TelevisionWidget(float w, float h, QWidget *parent) :
	QWidget(parent)
{
	this->setFixedSize(w, h);

	QPushButton *p = new QPushButton(this);
	p->setFixedSize(w, h);
	p->setDisabled(true);
	p->setFont(QFont("微软雅黑", 18, 75));
	p->setText("这儿有一个视频的");
}

















