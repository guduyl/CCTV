
#ifndef CCTV_H
#define CCTV_H



#include "headers.h"
#include "televisionwidget.h"



class CCTV : public QMainWindow
{
	Q_OBJECT

public:
	CCTV(QWidget *parent = 0);
	~CCTV();

public slots:
	void onreleased_bnAddTv();

protected:
	void resizeEvent(QResizeEvent *e);

	void MyUpdateHlayoutList(int col = 0);
	void MySetScrollSize();

private:
	QScrollArea *m_pscaCentral;
	QWidget *m_pwgScroll;
	QPushButton *m_pbnAddTv;
	QList<TelevisionWidget *> *m_plstTvWidgets;
	QVBoxLayout *m_ploV0;
	int m_nLayoutCols;
	QList<QHBoxLayout *> *m_plstHlayouts;

};





















#endif // CCTV_H













