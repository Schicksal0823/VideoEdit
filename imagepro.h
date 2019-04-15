#pragma once
#include <opencv2/core.hpp>

class ImagePro
{
public:
	ImagePro();

	//����ԭͼ������������
	void Set(cv::Mat mat1, cv::Mat mat2);
	//��ȡ�����Ľ��
	cv::Mat Get();
	//�������ȺͶԱȶ�
	//����  0~100
	//�Աȶ�  1.0~3.0
	void Gain(double bright, double contrast);
	//��ת
	void Rotate90();
	void Rotate180();
	void Rotate270();
	//����
	void FlipX();
	void FlipY();
	void FlipXY();
	//ͼ��ߴ�
	void Resize(int width, int heigth);
	//ͼ�������
	void PyDown(int count);
	void PyUp(int count);
	//��Ƶ�ü�
	void Clip(int x, int y, int w, int h);
	//תΪ�Ҷ�ͼ
	void Gray();
	//����ˮӡ
	void Mark(int x, int y, double a);
	//�ں�
	void Blend(double a);
	//�ϲ�
	void Merge();


	~ImagePro();
private:
	//ԭͼ
	cv::Mat src1, src2;
	//Ŀ��ͼ
	cv::Mat des;
};

