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
	//����ƵԴ�ļ�
	void Open();
	//���������������
	void SliderPress();
	void SliderRelease();
	//�϶�������
	void SetPos(int pos);
	//���ù�����
	void Set();
	//������Ƶ
	void Export();
	//��������
	void ExportEnd();
	//����/��ͣ
	void Play();
	void Pause();
	//���ˮӡ
	void Mark();
	//�ں�
	void Blend();
	//�ϲ�
	void Merge();
	//���Ҳ໬����
	void Left(int pos);
	void Right(int pos);
private:
	Ui::VideoUIClass ui;
};
