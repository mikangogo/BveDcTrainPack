#pragma once

#include <vector>
#include <string>
#include <map>
#include "Unicode.h"

#define NORMAL 0
#define VERIFY 1
#define ADJUST 2
#define ROTATE 3

class CUnequalIntervalScale
{
public:
	CUnequalIntervalScale(void);
	~CUnequalIntervalScale(void);
	void CsvParse(std::tstring); // CSV�t�@�C���̓ǂݍ���
	void SetAdjustStep(double); // �m�F�p�̐��l�����ʂ̐ݒ�
	void SetAngleStep(double); // �p�x�����ʂ̐ݒ�
	void SetRotateStep(double); // �p�x�����ʂ̐ݒ�
	void SetDeveloperMode(int); // �J���҃��[�h�̐ݒ�

	void SwitchAdjustMode(void); // ���[�h�ؑ�
	void ResetAdjustValue(void); // �����l�̃��Z�b�g

	void AdjustIncrementLarge(void); // �����l�����i��j
	void AdjustIncrementMedium(void); // �����l�����i���j
	void AdjustIncrementSmall(void); // �����l�����i���j
	void AdjustDecrementLarge(void); // �����l�����i��j
	void AdjustDecrementMedium(void); // �����l�����i���j
	void AdjustDecrementSmall(void); // �����l�����i���j
	void SetAngleToClipboard(void); // �p�x�l���N���b�v�{�[�h�֏o��
	double ConvertValue(double); // ���l���p�x�̕ϊ�
	bool GetDeveloperModeSetting(); // �J���҃��[�h�ݒ�l�擾

private:
	double linearInterpolate(double); // ���`���
	BOOL clipboardOutput(TCHAR *); // �N���b�v�{�[�h�o��

	std::map<double, double> params; // ���͒l�Əo�͊p�x�̑g
	double adjustValue; // �m�F�p���l
	double adjustStep; // �m�F�p���l������
	double angle; // ���݂̊p�x�i�����p�j
	double angleStep; // �p�x������
	double rotateAngle; // ���݂̊p�x�i��]���[�h�j
	double rotateStep; // ��]���x[deg/frame]
	int adjustMode; // ���݂̐��l�o�̓��[�h
	bool developerMode; // �J���҃��[�h���ۂ�
};
