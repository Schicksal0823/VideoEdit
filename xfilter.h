#pragma once
#include <opencv2/core.hpp>
#include <vector>

enum XTaskType {
	XTASK_NONE,
	XTASK_GAIN,
	XTASK_ROTATE90,
	XTASK_ROTATE180,
	XTASK_ROTATE270,
	XTASK_FLIPX,
	XTASK_FLIPY,
	XTASK_FLIPXY,
	XTASK_RESIZE,
	XTASK_PYDOWM,
	XTASK_PYUP,
	XTASK_CLIP,
	XTASK_GRAY,
	XTASK_MARK,
	XTASK_BLEND,
	XTASK_MERGE,

};
struct XTask {
	XTaskType type;
	std::vector<double> para;
};

class XFilter
{
	//Q_OBJECT

public:
	static XFilter *Get();
	virtual cv::Mat Filter(cv::Mat mat1, cv::Mat mat2) = 0;
	virtual void Add(XTask task) = 0;
	virtual void Clear() = 0;

	virtual ~XFilter();
protected:
	XFilter();
};
