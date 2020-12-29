#include "StdAfx.h"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream> 
#include <map>
#include <algorithm>

#include "UnequalIntervalScale.h"

using namespace std;

CUnequalIntervalScale::CUnequalIntervalScale(void)
{
	adjustMode = NORMAL;
	developerMode = false;

	adjustValue = 0;
	angle = 0;
	rotateAngle = 0;
}

CUnequalIntervalScale::~CUnequalIntervalScale(void)
{
}

void CUnequalIntervalScale::CsvParse(tstring path)
{
	// CSVファイルの読み込み
	tifstream ifs(path.c_str());

	tstring str; // 行
	tstring element; // 要素

	// CSVファイルの行読み込み
	while (ifs && getline(ifs, str))
	{
		int colCnt = 0; // 列カウンター
		bool addFlag = true; // リスト追加フラグ
		double x = 0;
		double y = 0;

		// 行文字列を文字列ストリームへ
		tistringstream row(str);

		// CSVファイルの各項目読み込み
		while (getline(row, element, _T(',')))
		{
			// 文字列を数値に変換
			tstringstream ss;
			double value;

			ss << element;
			ss >> value;

			// パラメータの登録
			switch (colCnt)
			{
			case 0:
				// 1列目（入力値）
				x = value;
				break;
			case 1:
				// 2列目（出力角度）
				y = value;
				break;
			}

			// 数値の読み込みに失敗した場合、リストの追加をしない
			if (ss.fail())
			{
				addFlag = false;
				break;
			}

			colCnt++;
		}

		// 正常に読み込めた場合のみパラメータを追加
		if (colCnt >= 2 && addFlag)
		{
			params[x] = y; // mapは追加時に自動ソート
		}
	}
}

void CUnequalIntervalScale::SetAdjustStep(double step)
{
	adjustStep = fabs(step);
}

void CUnequalIntervalScale::SetAngleStep(double step)
{
	angleStep = fabs(step);
}

void CUnequalIntervalScale::SetRotateStep(double step)
{
	rotateStep = step;
}

void CUnequalIntervalScale::SetDeveloperMode(int enabled)
{
	developerMode = enabled;
}

void CUnequalIntervalScale::SwitchAdjustMode(void)
{
	if (developerMode)
	{
		switch (adjustMode)
		{
		case NORMAL:
			adjustMode = ADJUST;
			break;
		case ADJUST:
			adjustMode = VERIFY;
			break;
		case VERIFY:
			adjustMode = ROTATE;
			break;
		case ROTATE:
			adjustMode = NORMAL;
			rotateAngle = 0;
			break;
		}
	}
}

void CUnequalIntervalScale::ResetAdjustValue(void)
{
	if (adjustMode == VERIFY)
	{
		adjustValue = 0;
	}
	else if (adjustMode == ADJUST)
	{
		angle = 0;
	}
}

void CUnequalIntervalScale::AdjustIncrementLarge(void)
{
	if (adjustMode == VERIFY)
	{
		adjustValue += adjustStep * 10;
	}
	else if (adjustMode == ADJUST)
	{
		angle += angleStep * 10;
	}
}

void CUnequalIntervalScale::AdjustIncrementMedium(void)
{
	if (adjustMode == VERIFY)
	{
		adjustValue += adjustStep;
	}
	else if (adjustMode == ADJUST)
	{
		angle += angleStep;
	}
}

void CUnequalIntervalScale::AdjustIncrementSmall(void)
{
	if (adjustMode == VERIFY)
	{
		adjustValue += adjustStep / 10;
	}
	else if (adjustMode == ADJUST)
	{
		angle += angleStep * 0.1;
	}
}

void CUnequalIntervalScale::AdjustDecrementLarge(void)
{
	if (adjustMode == VERIFY)
	{
		adjustValue -= adjustStep * 10;
	}
	else if (adjustMode == ADJUST)
	{
		angle -= angleStep * 10;
	}
}

void CUnequalIntervalScale::AdjustDecrementMedium(void)
{
	if (adjustMode == VERIFY)
	{
		adjustValue -= adjustStep;
	}
	else if (adjustMode == ADJUST)
	{
		angle -= angleStep;
	}
}

void CUnequalIntervalScale::AdjustDecrementSmall(void)
{
	if (adjustMode == VERIFY)
	{
		adjustValue -= adjustStep / 10;
	}
	else if (adjustMode == ADJUST)
	{
		angle -= angleStep * 0.1;
	}
}

void CUnequalIntervalScale::SetAngleToClipboard(void)
{
	if (adjustMode == ADJUST)
	{
		tstringstream ss;
		tstring str;
		ss << angle;
		ss >> str;
				
		clipboardOutput((TCHAR*)str.c_str());
	}
}
double CUnequalIntervalScale::ConvertValue(double x)
{
	switch (adjustMode)
	{
	case NORMAL:
		return linearInterpolate(x) + 180;
	case ADJUST:
		return angle + 180;
	case VERIFY:
		return linearInterpolate(adjustValue) + 180;
	case ROTATE:
		rotateAngle += rotateStep;
		return rotateAngle + 180;
	default:
		return 0;
	}
}

bool CUnequalIntervalScale::GetDeveloperModeSetting()
{
	return developerMode;
}

double CUnequalIntervalScale::linearInterpolate(double x)
{
	// パラメータが空もしくは要素数2未満の場合
	if (params.empty() || (int)params.size() < 2)
	{
		// 線形補完が不可能なためゼロを返す
		return 0;
	}

	// イテレータ
	map<double, double>::iterator prev;
	map<double, double>::iterator next;

	if (x < params.begin()->first) // 入力値がパラメータの最小X未満の場合
	{
		prev = params.begin(); // データ先頭
		next = prev++;
	}
	else if (x >= (--params.end())->first) // 入力値がパラメータの最大X以上の場合
	{
		next = --params.end(); // データ末尾
		prev = next--;
	}
	else // Xの範囲内の場合
	{
		next = params.upper_bound(x); // xより大きい値を持つ最初の要素
		prev = next--;
	}

	// 線形補間
	return prev->second + (x - prev->first) * (next->second - prev->second) / (next->first - prev->first);
}

// *********************************************************
// http://win32cpp.seesaa.net/article/120567918.html
// クリップボードへテキストをコピー
// 戻り値 : 成功 true, 失敗 false
// *********************************************************
BOOL CUnequalIntervalScale::clipboardOutput(TCHAR *szData)
{
	HGLOBAL hGlobal;
	LPTSTR pMem;

	hGlobal = GlobalAlloc(GHND, lstrlen(szData) + 128);
	if (hGlobal == NULL) {
		return FALSE;
	}
	pMem = (LPTSTR)GlobalLock(hGlobal);
	if (pMem == NULL) {
		GlobalFree(hGlobal);
		return FALSE;
	}
	lstrcpy(pMem, szData);
	GlobalUnlock(hGlobal);
	OpenClipboard(NULL);
	EmptyClipboard();
	SetClipboardData(CF_TEXT, hGlobal);
	CloseClipboard();

	return TRUE;
}