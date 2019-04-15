#pragma once

#include <QThread>
#include <QMutex>
#include "opencv2/core.hpp"

class VideoThread : public QThread
{
	Q_OBJECT

public:
	//单例模式
	static VideoThread *Get() 
	{
		static VideoThread vt;
		return &vt;
	}
	//线程入口函数
	void run();

	//打开一号视频源文件
	bool Open(const std::string file);
	//返回当前播放的位置
	double GetPos();
	//frame int帧位置
	bool Seek(int frame);
	double Seek(double pos);
	//开始保存视频
	bool StartSave(const std::string filename, int width = 0, int height = 0, bool isColor = true);
	//停止保存视频，写入视频帧索引
	void StopSave();
	//播放/暂停
	void Play();
	void Pause();
	//添加水印
	void SetMark(cv::Mat m);
	//打开二号视频源文件
	bool Open2(const std::string file);

	void SetBegin(double pos);
	void SetEnd(double pos);

	//VideoThread();
	~VideoThread();
signals:
	//显示原视频图像1
	void ViewImage1(cv::Mat mat);
	//显示生成后图像
	void ViewDes(cv::Mat mat);
	//结尾自动保存
	void SaveEnd();
	//显示原视频图像2
	void ViewImage2(cv::Mat mat);

public:
	int fps = 0;
	int width = 0;
	int height = 0;
	int width2 = 0;
	int height2 = 0;
	std::string srcfile;
	std::string desfile;

	int begin = 0;
	int end = 0;
	int totalMs = 0;


private:
	//单例模式可以将构造函数放入保护，以方式调用生成对象，做好唯一性
	VideoThread();
	QMutex mutex;
	cv::Mat mark;
	bool isWrite = false;
	bool isPlay = false;
};
