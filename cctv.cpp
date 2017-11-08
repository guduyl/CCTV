
#include "cctv.h"





#define TELEVISIONWIDGETWIDTH			300
#define TELEVISIONWIDGETHEIGET			(TELEVISIONWIDGETWIDTH * 0.618)





CCTV::CCTV(QWidget *parent) :
	QMainWindow(parent),
	m_pscaCentral(new QScrollArea),
	m_pwgScroll(new QWidget),
	m_pbnAddTv(new QPushButton("+", m_pwgScroll)),
	m_plstTvWidgets(new QList<TelevisionWidget *>),
	m_ploV0(new QVBoxLayout(m_pwgScroll)),
	m_nLayoutCols(0),
	m_plstHlayouts(new QList<QHBoxLayout *>)
{
	qDebug() << "CCTV::CCTV";

	QDesktopWidget desktop;
	this->resize(desktop.width() * 0.8, desktop.height() * 0.8);
	this->move((desktop.width() - this->width()) / 2, (desktop.height() - 80 - this->height()) / 2);
	this->setCentralWidget(m_pscaCentral);
	this->setMinimumWidth(TELEVISIONWIDGETWIDTH + 100);

	m_pscaCentral->setBackgroundRole(QPalette::Dark);
	m_pscaCentral->setWidget(m_pwgScroll);

	m_pbnAddTv->setFixedSize(TELEVISIONWIDGETWIDTH, TELEVISIONWIDGETHEIGET);
	m_pbnAddTv->setFont(QFont("微软雅黑", 40));
	this->connect(this->m_pbnAddTv, SIGNAL(released()), this, SLOT(onreleased_bnAddTv()));
}



CCTV::~CCTV()
{
	qDebug() << "CCTV::~CCTV";

	foreach (QHBoxLayout *h0, *m_plstHlayouts)
		delete h0;
	delete m_plstHlayouts;
	delete m_ploV0;
	foreach (TelevisionWidget *tv, *m_plstTvWidgets)
		delete tv;
	delete m_plstTvWidgets;
	delete m_pbnAddTv;
	delete m_pwgScroll;
	delete m_pscaCentral;
}





/**
 * @brief CCTV::onreleased_bnAddTv
 *		按下添加按钮事件
 */
void CCTV::onreleased_bnAddTv()
{
	TelevisionWidget *tv = new TelevisionWidget(TELEVISIONWIDGETWIDTH, TELEVISIONWIDGETHEIGET, this);
	m_plstTvWidgets->append(tv);
	QHBoxLayout *hx = m_plstHlayouts->last();
	hx->removeWidget(this->m_pbnAddTv);
	hx->addWidget(tv);
	if (m_plstTvWidgets->size() % m_nLayoutCols == 0)
	{
		hx = new QHBoxLayout;
		m_plstHlayouts->append(hx);
		m_ploV0->addLayout(hx);
		this->MySetScrollSize();
	}
	hx->addWidget(this->m_pbnAddTv);
}





/**
 * @brief CCTV::resizeEvent
 *		重置大小事件
 * @param e
 */
void CCTV::resizeEvent(QResizeEvent *e)
{
//	qDebug() << "CCTV::resizeEvent";

	m_pscaCentral->resize(this->size());
	int col = this->width() / TELEVISIONWIDGETWIDTH;
	if (m_nLayoutCols != col)
	{
		this->MyUpdateHlayoutList(col);
	}
	this->MySetScrollSize();
}





void CCTV::MyUpdateHlayoutList(int col)
{
//	qDebug() << "CCTV::MyUpdateHlayoutList";

	if (col != 0 && m_plstTvWidgets->size() != 0)
	{
		int k = 0;
		foreach (QHBoxLayout *h0, *m_plstHlayouts)
		{
			for (int i = 0; i < m_nLayoutCols; ++i)
			{
				h0->removeWidget(this->m_plstTvWidgets->value(k++));
			}
			if (k == m_plstTvWidgets->size())
			{
				h0->removeWidget(this->m_pbnAddTv);
			}
			m_ploV0->removeItem(h0);
			delete h0;
		}
		m_plstHlayouts->clear();

		m_nLayoutCols = col;
		QHBoxLayout *h0 = new QHBoxLayout;
		m_plstHlayouts->append(h0);
		m_ploV0->addLayout(h0);
		k = 0;
		foreach (TelevisionWidget *tv, *m_plstTvWidgets)
		{
			h0->addWidget(tv);
			++k;
			if (k == m_nLayoutCols)
			{
				k = 0;
				h0 = new QHBoxLayout;
				m_plstHlayouts->append(h0);
				m_ploV0->addLayout(h0);
			}
		}
	}
	else if (col != 0 && m_plstHlayouts->size() == 0)
	{
		m_nLayoutCols = col;
		QHBoxLayout *h0 = new QHBoxLayout;
		m_plstHlayouts->append(h0);
		m_ploV0->addLayout(h0);
	}
	else
	{
		m_nLayoutCols = col;
	}

	m_plstHlayouts->last()->addWidget(this->m_pbnAddTv);
}



void CCTV::MySetScrollSize()
{
	int width = m_pscaCentral->width() - 2;
	int height = m_plstHlayouts->size() * (TELEVISIONWIDGETHEIGET + 40);
	if (height > this->height())
		width -= 18;
	m_pwgScroll->resize(width, height);
}










