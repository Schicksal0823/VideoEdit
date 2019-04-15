#include "videoui.h"
#include <Qstring>
#include <QFileDialog>
#include <QMessageBox>
#include <string>
#include "VideoThread.h"
#include "xfilter.h"
#include <opencv2/imgcodecs.hpp>
#include "Audio.h"
#include <QFile>

using namespace cv;
using namespace std;
static bool pressSlider = false;
static bool isExport = false;
static bool isColor = true;
static bool isMark = false;
static bool isBlend = false;
static bool isMerge = false;

VideoUI::VideoUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	//ע��Ԫ����
	qRegisterMetaType<cv::Mat>("cv::Mat");
	//ͨ������ָ����ʽ�����źŲ�
	connect(VideoThread::Get(), &VideoThread::ViewImage1, ui.src1video, &VideoWidget::SetImage);
	connect(VideoThread::Get(), &VideoThread::ViewDes, ui.desvideo, &VideoWidget::SetImage);
	connect(VideoThread::Get(), &VideoThread::SaveEnd, this, &VideoUI::ExportEnd);
	connect(VideoThread::Get(), &VideoThread::ViewImage2, ui.src2video, &VideoWidget::SetImage);

	// 	connect(VideoThread::Get(), 
	// 		SIGNAL(ViewImage1(cv::Mat)), 
	// 		ui.src1video,
	// 		SLOT(SetImage(cv::Mat)));
	Pause();

	startTimer(34);

}


void VideoUI::timerEvent(QTimerEvent *event)
{
	if (pressSlider)return;
	double pos = VideoThread::Get()->GetPos();
	ui.playSlider->setValue(pos * 1000);
}

void VideoUI::Open()
{
	QString filename = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("���ļ�"));
	if (filename.isEmpty())return;
	string file = filename.toLocal8Bit().data();
	//MessageBox::information(this, "", filename);
	if (!VideoThread::Get()->Open(file))
	{
		QMessageBox::information(this, "error", filename + "Openg Failed!");
	};
	Play();
}

void VideoUI::SliderPress()
{
	pressSlider = true;
}

void VideoUI::SliderRelease()
{
	pressSlider = false;
}

void VideoUI::SetPos(int pos)
{
	VideoThread::Get()->Seek((double)pos / 1000);
}

void VideoUI::Set()
{
	//������
	XFilter::Get()->Clear();
	isColor = true;

	//��Ƶͼ��ü�
	bool isClip = false;
	double cx = ui.cxBox->value();
	double cy = ui.cyBox->value();
	double cw = ui.cwBox->value();
	double ch = ui.chBox->value();
	if (cx + cy + cw + ch > 0.00001)
	{
		bool isClip = true;
		XFilter::Get()->Add(XTask{ XTASK_CLIP,{cx,cy,cw,ch} });
		double w = VideoThread::Get()->width;
		double h = VideoThread::Get()->height;
		XFilter::Get()->Add(XTask{ XTASK_RESIZE,{ w,h } });

	}

	//ͼ�������
	bool isPy = false;
	int down = ui.pydownBox->value();
	int up = ui.pyupBox->value();

	if (down > 0)
	{
		isPy = true;
		XFilter::Get()->Add(XTask{ XTASK_PYDOWM,{(double)down} });
		int w = VideoThread::Get()->width;
		int h = VideoThread::Get()->height;
		for (int i = 0;i < down;i++)
		{
			w = w / 2;
			h = h / 2;
		}
		ui.widthBox->setValue(w);
		ui.heightBox->setValue(h);
	}
	if (up > 0)
	{
		isPy = true;
		XFilter::Get()->Add(XTask{ XTASK_PYUP,{ (double)up } });
		int w = VideoThread::Get()->width;
		int h = VideoThread::Get()->height;
		for (int i = 0;i < up;i++)
		{
			w = w * 2;
			h = h * 2;
		}
		ui.widthBox->setValue(w);
		ui.heightBox->setValue(h);
	}


	//������Ƶ�ߴ�
	double w = ui.widthBox->value();
	double h = ui.heightBox->value();
	if (!isMerge && !isClip && !isPy && ui.widthBox->value() > 0 && ui.heightBox->value() > 0)
	{
		XFilter::Get()->Add(XTask{ XTASK_RESIZE,{w,h} });
	}
	//�ԱȶȺ�����
	if (ui.brightBox->value() > 0 || ui.contrastBox->value() > 1)
	{
		//C++ 11 ʵ��Xtask
		XFilter::Get()->Add(XTask{ XTASK_GAIN,{(double)ui.brightBox->value(),ui.contrastBox->value()} });
	}
	//תΪ�Ҷ�ͼ
	if (ui.colorBox->currentIndex() == 1)
	{
		XFilter::Get()->Add(XTask{ XTASK_GRAY });
		isColor = false;
	}
	//ͼ����ת
	if (ui.rotateBox->currentIndex() == 1)
	{
		XFilter::Get()->Add(XTask{ XTASK_ROTATE90 });
	}
	else if (ui.rotateBox->currentIndex() == 2)
	{
		XFilter::Get()->Add(XTask{ XTASK_ROTATE180 });
	}
	else if (ui.rotateBox->currentIndex() == 3)
	{
		XFilter::Get()->Add(XTask{ XTASK_ROTATE270 });
	}
	//ͼ����
	if (ui.flipBox->currentIndex() == 1)
	{
		XFilter::Get()->Add(XTask{ XTASK_FLIPX });
	}
	else if (ui.flipBox->currentIndex() == 2)
	{
		XFilter::Get()->Add(XTask{ XTASK_FLIPY });
	}
	else if (ui.flipBox->currentIndex() == 3)
	{
		XFilter::Get()->Add(XTask{ XTASK_FLIPXY });
	}
	//���ˮӡ
	if (isMark)
	{
		double x = ui.mxBox->value();
		double y = ui.myBox->value();
		double a = ui.maBox->value();
		XFilter::Get()->Add(XTask{ XTASK_MARK,{ x,y,a } });
	}
	//��Ƶ�ں�
	if (isBlend)
	{
		double a = ui.baBox->value();
		XFilter::Get()->Add(XTask{ XTASK_BLEND,{ a } });
	}
	//��Ƶ�ϲ�
	if (isMerge)
	{
		double h1 = VideoThread::Get()->height;
		double h2 = VideoThread::Get()->height2;
		int w = VideoThread::Get()->width2 * (h2 / h1);
		XFilter::Get()->Add(XTask{ XTASK_MERGE });
		ui.widthBox->setValue(VideoThread::Get()->width + w);
		ui.heightBox->setValue(h1);
	}

}

void VideoUI::Export()
{
	if (isExport)
	{
		//ֹͣ����
		VideoThread::Get()->StopSave();
		isExport = false;
		ui.exportButton->setText(QString::fromLocal8Bit("����"));
		return;
	}
	//��ʼ����
	QString name = QFileDialog::getSaveFileName(this, "Save", "New1.avi");
	if (name.isEmpty())return;
	std::string filename = name.toLocal8Bit().data();
	//��Ƶ��С�ı����Ҫ��ȡwidth��height��������ԭ��С����ʧ��
	int w = ui.widthBox->value();
	int h = ui.heightBox->value();
	if (VideoThread::Get()->StartSave(filename, w, h, isColor))
	{
		isExport = true;
		ui.exportButton->setText(QString::fromLocal8Bit("ֹͣ"));
		return;
	}
}

void VideoUI::ExportEnd()
{
	isExport = false;
	ui.exportButton->setText(QString::fromLocal8Bit("����"));

	//������Ƶ
	string src = VideoThread::Get()->srcfile;
	string des = VideoThread::Get()->desfile;
	int tt = 0;
	ui.leftSlider->value();
	int ss = VideoThread::Get()->totalMs*((double)ui.leftSlider->value() / 1000);
	int end = VideoThread::Get()->totalMs*((double)ui.rightSlider->value() / 1000);
	tt = end - ss;
	Audio::Get()->ExportA(src, src + ".mp3", ss, tt);
	string tmp = des + ".avi";
	QFile::remove(tmp.c_str());
	QFile::rename(des.c_str(), tmp.c_str());
	Audio::Get()->Merge(tmp, src + ".mp3", des);
}

void VideoUI::Play()
{
	ui.pauseButton->show();
	ui.pauseButton->setGeometry(ui.playButton->geometry());
	ui.playButton->hide();
	VideoThread::Get()->Play();
	ui.playButton->setText(QString::fromLocal8Bit("����"));
}

void VideoUI::Pause()
{
	ui.playButton->show();
	ui.pauseButton->hide();
	VideoThread::Get()->Pause();
}

void VideoUI::Mark()
{
	isMark = false;
	isBlend = false;
	isMerge = false;
	QString filename = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("ѡ��ͼƬ"));
	if (filename.isEmpty())return;
	std::string file = filename.toLocal8Bit().data();
	cv::Mat mark = imread(file);
	if (mark.empty())return;
	VideoThread::Get()->SetMark(mark);
	isMark = true;
}

void VideoUI::Blend()
{
	isMark = false;
	isBlend = false;
	isMerge = false;
	QString filename = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("ѡ����Ƶ"));
	if (filename.isEmpty())return;
	std::string file = filename.toLocal8Bit().data();
	isBlend = VideoThread::Get()->Open2(file);
}

void VideoUI::Merge()
{
	isMark = false;
	isBlend = false;
	isMerge = false;
	QString filename = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("ѡ����Ƶ"));
	if (filename.isEmpty())return;
	std::string file = filename.toLocal8Bit().data();
	isMerge = VideoThread::Get()->Open2(file);
}

void VideoUI::Left(int pos)
{
	VideoThread::Get()->SetBegin((double)pos / 1000);
	SetPos(pos);
}

void VideoUI::Right(int pos)
{
	VideoThread::Get()->SetEnd((double)pos / 1000);
}
