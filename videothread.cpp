#include "videothread.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "xfilter.h"


using namespace cv;
using namespace std;

//一号视频源/二号视频源
static VideoCapture cap1;
static VideoCapture cap2;
//保存视频
static VideoWriter vw;
//退出
static bool isExit = false;

VideoThread::VideoThread()
{
	start();
}

void VideoThread::run()
{
	Mat mat1;
	for (;;)
	{
		//判断视频是否打开
		mutex.lock();
		if (isExit)
		{
			mutex.unlock();
			break;
		}
		if (!cap1.isOpened())
		{
			mutex.unlock();
			msleep(5);
			continue;
		}

		if (!isPlay)
		{
			mutex.unlock();
			msleep(5);
			continue;
		}

		int cur = cap1.get(CAP_PROP_POS_FRAMES);
		//读取一帧视频，解码并颜色转换
		if ((end > 0 && cur >= end) || !cap1.read(mat1) || mat1.empty())
		{
			mutex.unlock();
			//导出到结尾位置，停止导出
			if (isWrite)
			{
				StopSave();
				SaveEnd();
			}
			msleep(5);
			continue;
		}

		Mat mat2 = mark;
		if (cap2.isOpened())
		{
			cap2.read(mat2);
		}
		//显示图像1
		if (!isWrite)
		{
			ViewImage1(mat1);
			if (!mat2.empty())
			{
				ViewImage2(mat2);
			}
		}
		//通过过滤器处理视频
		Mat des = XFilter::Get()->Filter(mat1, mat2);
		//显示生成后的图像
		if (!isWrite)ViewDes(des);

		//msleep(30);
		int s = 0;
		s = 1000 / fps;
		if (isWrite)
		{
			s = 1;
			vw.write(des);
		}

		msleep(s);
		cout << "fps:" << s << endl;
		mutex.unlock();

	}
}

bool VideoThread::Open(const std::string file)
{
	Seek(0);
	cout << "open:" << file << endl;
	mutex.lock();
	bool re = cap1.open(file);
	mutex.unlock();
	cout << re << endl;
	if (!re)return re;
	fps = cap1.get(CAP_PROP_FPS);
	width = cap1.get(CAP_PROP_FRAME_WIDTH);
	height = cap1.get(CAP_PROP_FRAME_HEIGHT);
	if (fps <= 0)fps = 30;
	srcfile = file;
	double count = cap1.get(CAP_PROP_FRAME_COUNT);
	totalMs = (count / (double)fps) * 1000;
	return true;
}

double VideoThread::GetPos()
{
	double pos = 0;
	mutex.lock();
	if (!cap1.isOpened())
	{
		mutex.unlock();
		return pos;
	}
	double count = cap1.get(CAP_PROP_FRAME_COUNT);
	double cur = cap1.get(CAP_PROP_POS_FRAMES);
	if (count > 0.001)pos = cur / count;
	mutex.unlock();
	return pos;
}

bool VideoThread::Seek(int frame)
{
	mutex.lock();
	if (!cap1.isOpened())
	{
		mutex.unlock();
		return false;
	}
	int re = cap1.set(CAP_PROP_POS_FRAMES, frame);
	if (cap2.isOpened()) 
	{
		cap2.set(CAP_PROP_POS_FRAMES, frame);
	}
	mutex.unlock();
	return re;
}

double VideoThread::Seek(double pos)
{
	double count = cap1.get(CAP_PROP_FRAME_COUNT);
	int frame = pos * count;
	return Seek(frame);
}

bool VideoThread::StartSave(const std::string filename, int width /*= 0*/, int height /*= 0*/,bool isColor /*= true*/)
{
	cout << "开始导出" << endl;
	Seek(begin);
	mutex.lock();
	if (!cap1.isOpened()) 
	{
		mutex.unlock();
		cout << "VideoCapture Failed!" << endl;
		return false;
	}
	if (width <= 0)width = cap1.get(CAP_PROP_FRAME_WIDTH);
	if (height <= 0)height = cap1.get(CAP_PROP_FRAME_HEIGHT);
	vw.open(filename, VideoWriter::fourcc('X', '2', '6', '4'), this->fps, Size(width, height), isColor);
	if (!vw.isOpened())
	{
		mutex.unlock();
		cout << "Start Save Failed!" << endl;
		return false;
	}
	this->isWrite = true;
	desfile = filename;
	mutex.unlock();
	return true;
}

void VideoThread::StopSave()
{
	cout << "停止导出" << endl;
	mutex.lock();
	vw.release();
	isWrite = false;
	mutex.unlock();
	return;
}

void VideoThread::Play()
{
	mutex.lock();
	isPlay = true;
	mutex.unlock();
}

void VideoThread::Pause()
{
	mutex.lock();
	isPlay = false;
	mutex.unlock();
}

void VideoThread::SetMark(Mat m)
{
	mutex.lock();
	this->mark = m;
	mutex.unlock();
}

bool VideoThread::Open2(const std::string file)
{
	Seek(0);
	cout << "open2:" << file << endl;
	mutex.lock();
	bool re = cap2.open(file);
	mutex.unlock();
	cout << re << endl;
	if (!re)return re;
// 	fps = cap2.get(CAP_PROP_FPS);
	width2 = cap2.get(CAP_PROP_FRAME_WIDTH);
	height2 = cap2.get(CAP_PROP_FRAME_HEIGHT);
// 	if (fps <= 0)fps = 30;
	return true;

}

void VideoThread::SetBegin(double pos)
{
	mutex.lock();
	double count = cap1.get(CAP_PROP_FRAME_COUNT);
	int frame = pos * count;
	begin = frame;
	mutex.unlock();
}

void VideoThread::SetEnd(double pos)
{
	mutex.lock();
	double count = cap1.get(CAP_PROP_FRAME_COUNT);
	int frame = pos * count;
	end = frame;
	mutex.unlock();

}

VideoThread::~VideoThread()
{
	mutex.lock();
	isExit = true;
	mutex.unlock();
	wait();
}



