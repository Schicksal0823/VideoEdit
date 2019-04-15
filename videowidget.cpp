#include "videowidget.h"
#include <QPainter>
#include <opencv2/imgproc.hpp>

using namespace cv;

VideoWidget::VideoWidget(QWidget *parent)
	: QOpenGLWidget(parent)
{
}


//
void VideoWidget::paintEvent(QPaintEvent *e)
{
	QPainter p;
	p.begin(this);
	p.drawImage(QPoint(0, 0), img);
	p.end();
}



VideoWidget::~VideoWidget()
{
}

void VideoWidget::SetImage(cv::Mat mat)
{
	QImage::Format fmt = QImage::Format_RGB888;
	int pixSize = 3;
	//�Ҷ�ͼ
	if (mat.type() == CV_8UC1)
	{
		fmt = QImage::Format_Grayscale8;
		pixSize = 1;
	}
	if (img.isNull() || img.format() != fmt)
	{
		uchar *buf = new uchar[width()*height() * pixSize];
		img = QImage(buf, width(), height(), fmt);
	}
	Mat des;
	//����ͼ���С
	cv::resize(mat, des, Size(img.size().width(), img.size().height()));
	//����ͼ����ɫ��ʽ
	if (pixSize > 1)
	{
		cv::cvtColor(des, des, COLOR_BGR2RGB);
	}
	//�����ڴ�ռ�
	memcpy(img.bits(), des.data, des.cols*des.rows*des.elemSize());
	update();
}

