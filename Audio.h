#pragma once
#include <string>

class Audio
{
public:
	static Audio *Get();

	//������Ƶ�ļ�
	virtual bool ExportA(std::string src, std::string out, int beginMs = 0, int outMs = 0) = 0;
	virtual bool Merge(std::string v, std::string a, std::string out) = 0;
	virtual ~Audio();
protected:
	Audio();
};

