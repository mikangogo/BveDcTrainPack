#pragma once
#include <string>
#include "Unicode.h"

static class CUtil
{
public:
	CUtil(void);
	~CUtil(void);
	static int GetAtsKeyCodeFromString(std::tstring); // �����񂩂�ATS�L�[��\�����l�ւ̕ϊ�
	/*
	static std::tstring GetPluginDirectory(HANDLE);
	static std::tstring GetIniPath(HANDLE);
	static std::tstring GetCsvPath(HANDLE);
private:
	static std::tstring getDllPath(HANDLE);
	*/
};

