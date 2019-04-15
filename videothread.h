#pragma once

#include <QThread>
#include <QMutex>
#include "opencv2/core.hpp"

class VideoThread : public QThread
{
	Q_OBJECT

public:
	//����ģʽ
	static VideoThread *Get() 
	{
		static VideoThread vt;
		return &vt;
	}
	//�߳���ں���
	void run();

	//��һ����ƵԴ�ļ�
	bool Open(const std::string file);
	//���ص�ǰ���ŵ�λ��
	double GetPos();
	//frame int֡λ��
	bool Seek(int frame);
	double Seek(double pos);
	//��ʼ������Ƶ
	bool StartSave(const std::string filename, int width = 0, int height = 0, bool isColor = true);
	//ֹͣ������Ƶ��д����Ƶ֡����
	void StopSave();
	//����/��ͣ
	void Play();
	void Pause();
	//���ˮӡ
	void SetMark(cv::Mat m);
	//�򿪶�����ƵԴ�ļ�
	bool Open2(const std::string file);

	void SetBegin(double pos);
	void SetEnd(double pos);

	//VideoThread();
	~VideoThread();
signals:
	//��ʾԭ��Ƶͼ��1
	void ViewImage1(cv::Mat mat);
	//��ʾ���ɺ�ͼ��
	void ViewDes(cv::Mat mat);
	//��β�Զ�����
	void SaveEnd();
	//��ʾԭ��Ƶͼ��2
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
	//����ģʽ���Խ����캯�����뱣�����Է�ʽ�������ɶ�������Ψһ��
	VideoThread();
	QMutex mutex;
	cv::Mat mark;
	bool isWrite = false;
	bool isPlay = false;
};
