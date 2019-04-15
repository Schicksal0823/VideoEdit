#pragma once
#include <opencv2/core.hpp>

class ImagePro
{
public:
	ImagePro();

	//设置原图，会清理处理结果
	void Set(cv::Mat mat1, cv::Mat mat2);
	//获取处理后的结果
	cv::Mat Get();
	//设置亮度和对比度
	//亮度  0~100
	//对比度  1.0~3.0
	void Gain(double bright, double contrast);
	//旋转
	void Rotate90();
	void Rotate180();
	void Rotate270();
	//镜像
	void FlipX();
	void FlipY();
	void FlipXY();
	//图像尺寸
	void Resize(int width, int heigth);
	//图像金字塔
	void PyDown(int count);
	void PyUp(int count);
	//视频裁剪
	void Clip(int x, int y, int w, int h);
	//转为灰度图
	void Gray();
	//设置水印
	void Mark(int x, int y, double a);
	//融合
	void Blend(double a);
	//合并
	void Merge();


	~ImagePro();
private:
	//原图
	cv::Mat src1, src2;
	//目标图
	cv::Mat des;
};

