#pragma once

#include <QtWidgets/QWidget>
#include "ui_videoui.h"

class VideoUI : public QWidget
{
	Q_OBJECT

public:
	VideoUI(QWidget *parent = Q_NULLPTR);

	void timerEvent(QTimerEvent *event);

public slots:
	//打开视频源文件
	void Open();
	//滑动条按下与回起
	void SliderPress();
	void SliderRelease();
	//拖动滑动条
	void SetPos(int pos);
	//设置过滤器
	void Set();
	//导出视频
	void Export();
	//导出结束
	void ExportEnd();
	//播放/暂停
	void Play();
	void Pause();
	//添加水印
	void Mark();
	//融合
	void Blend();
	//合并
	void Merge();
	//左右侧滑动条
	void Left(int pos);
	void Right(int pos);
private:
	Ui::VideoUIClass ui;
};
