#pragma once
#include <string>
#include "Unicode.h"

static class CUtil
{
public:
	CUtil(void);
	~CUtil(void);
	static int GetAtsKeyCodeFromString(std::tstring); // 文字列からATSキーを表す数値への変換
	/*
	static std::tstring GetPluginDirectory(HANDLE);
	static std::tstring GetIniPath(HANDLE);
	static std::tstring GetCsvPath(HANDLE);
private:
	static std::tstring getDllPath(HANDLE);
	*/
};

