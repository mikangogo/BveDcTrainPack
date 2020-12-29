#include "StdAfx.h"
#include <algorithm>
#include "atsplugin.h"
#include "Unicode.h"
#include "Util.h"
using namespace std;

CUtil::CUtil(void)
{
}

CUtil::~CUtil(void)
{
}

int CUtil::GetAtsKeyCodeFromString(tstring keyCode)
{
	tstring lower = keyCode;

	// 小文字変換
	transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

	if (lower == _T("s"))
	{
		return ATS_KEY_S;
	}
	else if (lower == _T("a1"))
	{
		return ATS_KEY_A1;
	}
	else if (lower == _T("a2"))
	{
		return ATS_KEY_A2;
	}
	else if (lower == _T("b1"))
	{
		return ATS_KEY_B1;
	}
	else if (lower == _T("b2"))
	{
		return ATS_KEY_B2;
	}
	else if (lower == _T("c1"))
	{
		return ATS_KEY_C1;
	}
	else if (lower == _T("c2"))
	{
		return ATS_KEY_C2;
	}
	else if (lower == _T("d"))
	{
		return ATS_KEY_D;
	}
	else if (lower == _T("e"))
	{
		return ATS_KEY_E;
	}
	else if (lower == _T("f"))
	{
		return ATS_KEY_F;
	}
	else if (lower == _T("g"))
	{
		return ATS_KEY_G;
	}
	else if (lower == _T("h"))
	{
		return ATS_KEY_H;
	}
	else if (lower == _T("i"))
	{
		return ATS_KEY_I;
	}
	else if (lower == _T("j"))
	{
		return ATS_KEY_J;
	}
	else if (lower == _T("k"))
	{
		return ATS_KEY_K;
	}
	else if (lower == _T("l"))
	{
		return ATS_KEY_L;
	}
	else
	{
		return -1;
	}
}
/*
tstring CUtil::GetPluginDirectory(HANDLE hModule)
{
	// ディレクトリパス作成
	tstring dirPath = getDllPath(hModule);
	if (dirPath.find_last_of(_T("\\")) != tstring::npos){ dirPath.erase(dirPath.find_last_of(_T("\\"))); }
	dirPath += _T("\\");

	return dirPath;
}

tstring CUtil::GetIniPath(HANDLE hModule)
{
	// iniファイルのパス作成
	tstring iniPath = getDllPath(hModule);
	if (iniPath.rfind(_T(".dll")) != tstring::npos) { iniPath.erase(iniPath.rfind(_T(".dll"))); }
	iniPath += _T(".ini");

	return iniPath;
}

tstring CUtil::GetCsvPath(HANDLE hModule)
{
	// csvファイルのパス作成
	tstring csvPath = getDllPath(hModule);
	if (csvPath.rfind(_T(".dll")) != tstring::npos) { csvPath.erase(csvPath.rfind(_T(".dll"))); }
	csvPath += _T(".csv");

	return csvPath;
}

tstring CUtil::getDllPath(HANDLE hModule)
{
	TCHAR filePath[_MAX_PATH + 1] = _T(""); // ファイルパス格納文字列
	TCHAR *posIni; // 検索文字列へのポインタ

	// プラグインのファイルパスを取得
	::GetModuleFileName((HMODULE)hModule, filePath, _MAX_PATH);

	return filePath;
}
*/