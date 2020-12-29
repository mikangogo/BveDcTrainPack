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
	// CSV�t�@�C���̓ǂݍ���
	tifstream ifs(path.c_str());

	tstring str; // �s
	tstring element; // �v�f

	// CSV�t�@�C���̍s�ǂݍ���
	while (ifs && getline(ifs, str))
	{
		int colCnt = 0; // ��J�E���^�[
		bool addFlag = true; // ���X�g�ǉ��t���O
		double x = 0;
		double y = 0;

		// �s������𕶎���X�g���[����
		tistringstream row(str);

		// CSV�t�@�C���̊e���ړǂݍ���
		while (getline(row, element, _T(',')))
		{
			// ������𐔒l�ɕϊ�
			tstringstream ss;
			double value;

			ss << element;
			ss >> value;

			// �p�����[�^�̓o�^
			switch (colCnt)
			{
			case 0:
				// 1��ځi���͒l�j
				x = value;
				break;
			case 1:
				// 2��ځi�o�͊p�x�j
				y = value;
				break;
			}

			// ���l�̓ǂݍ��݂Ɏ��s�����ꍇ�A���X�g�̒ǉ������Ȃ�
			if (ss.fail())
			{
				addFlag = false;
				break;
			}

			colCnt++;
		}

		// ����ɓǂݍ��߂��ꍇ�̂݃p�����[�^��ǉ�
		if (colCnt >= 2 && addFlag)
		{
			params[x] = y; // map�͒ǉ����Ɏ����\�[�g
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
	// �p�����[�^����������͗v�f��2�����̏ꍇ
	if (params.empty() || (int)params.size() < 2)
	{
		// ���`�⊮���s�\�Ȃ��߃[����Ԃ�
		return 0;
	}

	// �C�e���[�^
	map<double, double>::iterator prev;
	map<double, double>::iterator next;

	if (x < params.begin()->first) // ���͒l���p�����[�^�̍ŏ�X�����̏ꍇ
	{
		prev = params.begin(); // �f�[�^�擪
		next = prev++;
	}
	else if (x >= (--params.end())->first) // ���͒l���p�����[�^�̍ő�X�ȏ�̏ꍇ
	{
		next = --params.end(); // �f�[�^����
		prev = next--;
	}
	else // X�͈͓̔��̏ꍇ
	{
		next = params.upper_bound(x); // x���傫���l�����ŏ��̗v�f
		prev = next--;
	}

	// ���`���
	return prev->second + (x - prev->first) * (next->second - prev->second) / (next->first - prev->first);
}

// *********************************************************
// http://win32cpp.seesaa.net/article/120567918.html
// �N���b�v�{�[�h�փe�L�X�g���R�s�[
// �߂�l : ���� true, ���s false
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