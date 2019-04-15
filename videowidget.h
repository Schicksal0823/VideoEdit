#pragma once

#include <QOpenGLWidget>
#include "opencv2\core.hpp"

class VideoWidget : public QOpenGLWidget
{
	Q_OBJECT

public:
	VideoWidget(QWidget *parent = 0);

	void paintEvent(QPaintEvent *e);

	virtual ~VideoWidget();

public slots:
	void SetImage(cv::Mat mat);
private:
	QImage img;
};
