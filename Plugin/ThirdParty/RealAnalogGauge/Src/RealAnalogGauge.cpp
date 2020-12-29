#include "StdAfx.h"
#include "Unicode.h"

#include "atsplugin.h"
#include "Util.h"
#include "AtsIni.h"
#include "StateFromSubjectKey.h"
#include "NeedleVibration.h"
#include "UnequalIntervalScale.h"
#include "DampingObject.h"
#include "EllipseGauge.h"
#include "RealAnalogGauge.h"

using namespace std;

#define COPY_VALUE_TO_CLIPBOARD		0
#define ADJUST_INCREMENT_SMALL		1
#define ADJUST_DECREMENT_SMALL		2
#define ADJUST_INCREMENT_MEDIUM		3
#define ADJUST_DECREMENT_MEDIUM		4
#define ADJUST_INCREMENT_LARGE		5
#define ADJUST_DECREMENT_LARGE		6
#define SWITCH_ADJUST_MODE			7
#define RESET_ADJUST_VALUE			8

CRealAnalogGauge::CRealAnalogGauge(void)
{
}

CRealAnalogGauge::~CRealAnalogGauge(void)
{
}

void CRealAnalogGauge::OnLoad(const char *modulePathChar)
{
	char drive[MAX_PATH], dir[MAX_PATH], fname[MAX_PATH];
	_splitpath_s(modulePathChar, drive, MAX_PATH, dir, MAX_PATH, fname, MAX_PATH, 0, 0);

	char iniPathChar[MAX_PATH];
	strcpy(iniPathChar, drive);
	strcat(iniPathChar, dir);
	strcat(iniPathChar, fname);
	strcat(iniPathChar, ".ini");
	tstring iniPath = iniPathChar;

	char csvPathChar[MAX_PATH];
	strcpy(csvPathChar, drive);
	strcat(csvPathChar, dir);
	strcat(csvPathChar, fname);
	strcat(csvPathChar, ".csv");
	tstring csvPath = csvPathChar;

	char dirPathChar[MAX_PATH];
	strcpy(dirPathChar, drive);
	strcat(dirPathChar, dir);
	tstring dirPath = dirPathChar;

	AtsIni parentIniData;

	// �e�ݒ�t�@�C���̓ǂݍ���
	if (parentIniData.load(iniPath))
	{
		// �q�ݒ�t�@�C���p�X���X�g�̍쐬
		vector<tstring> pathList;

		pathList.push_back(dirPath + parentIniData.FileName.Gauge0);
		pathList.push_back(dirPath + parentIniData.FileName.Gauge1);
		pathList.push_back(dirPath + parentIniData.FileName.Gauge2);
		pathList.push_back(dirPath + parentIniData.FileName.Gauge3);
		pathList.push_back(dirPath + parentIniData.FileName.Gauge4);
		pathList.push_back(dirPath + parentIniData.FileName.Gauge5);
		pathList.push_back(dirPath + parentIniData.FileName.Gauge6);
		pathList.push_back(dirPath + parentIniData.FileName.Gauge7);
		pathList.push_back(dirPath + parentIniData.FileName.Gauge8);
		pathList.push_back(dirPath + parentIniData.FileName.Gauge9);
		pathList.push_back(dirPath + parentIniData.FileName.Gauge10);
		pathList.push_back(dirPath + parentIniData.FileName.Gauge11);
		pathList.push_back(dirPath + parentIniData.FileName.Gauge12);
		pathList.push_back(dirPath + parentIniData.FileName.Gauge13);
		pathList.push_back(dirPath + parentIniData.FileName.Gauge14);
		pathList.push_back(dirPath + parentIniData.FileName.Gauge15);

		// �L�[�A�T�C���ݒ�
		keyIndex[COPY_VALUE_TO_CLIPBOARD] = CUtil::GetAtsKeyCodeFromString(parentIniData.KeyIndex.CopyValueToClipboard);
		keyIndex[ADJUST_INCREMENT_SMALL] = CUtil::GetAtsKeyCodeFromString(parentIniData.KeyIndex.AdjustIncrementSmall);
		keyIndex[ADJUST_DECREMENT_SMALL] = CUtil::GetAtsKeyCodeFromString(parentIniData.KeyIndex.AdjustDecrementSmall);
		keyIndex[ADJUST_INCREMENT_MEDIUM] = CUtil::GetAtsKeyCodeFromString(parentIniData.KeyIndex.AdjustIncrementMedium);
		keyIndex[ADJUST_DECREMENT_MEDIUM] = CUtil::GetAtsKeyCodeFromString(parentIniData.KeyIndex.AdjustDecrementMedium);
		keyIndex[ADJUST_INCREMENT_LARGE] = CUtil::GetAtsKeyCodeFromString(parentIniData.KeyIndex.AdjustIncrementLarge);
		keyIndex[ADJUST_DECREMENT_LARGE] = CUtil::GetAtsKeyCodeFromString(parentIniData.KeyIndex.AdjustDecrementLarge);
		keyIndex[SWITCH_ADJUST_MODE] = CUtil::GetAtsKeyCodeFromString(parentIniData.KeyIndex.SwitchAdjustMode);
		keyIndex[RESET_ADJUST_VALUE] = CUtil::GetAtsKeyCodeFromString(parentIniData.KeyIndex.ResetAdjustValue);

		// �e�ݒ�t�@�C���̌v��Č��ݒ�ǂݍ��݁i�݊��p�j
		loadSingleGaugeSettings(parentIniData, csvPath);

		// �t�@�C���p�X���X�g����Ɏq�ݒ�t�@�C����ǂݍ���
		for (int i = 0; i < pathList.size(); i++)
		{
			// ������
			AtsIni childIniData;

			if (childIniData.load(pathList[i] + _T(".ini")))
			{
				loadSingleGaugeSettings(childIniData, pathList[i] + _T(".csv"));
			}
		}

		// �J���҃��[�h�ݒ�
		for (int i = 1; i < (int)unequal.size(); i++)
		{
			unequal[i].SetAdjustStep(parentIniData.StepValue.Value);
			unequal[i].SetAngleStep(parentIniData.StepValue.Angle);
			unequal[i].SetRotateStep(parentIniData.StepValue.Rotate);
			unequal[i].SetDeveloperMode(parentIniData.DeveloperMode.Enabled);
		}
	}
}

void CRealAnalogGauge::OnLoad(HANDLE hModule)
{
}

void CRealAnalogGauge::loadSingleGaugeSettings(const AtsIni &iniData, tstring csvPath)
{
	CStateFromSubjectKey s;
	CNeedleVibration v;
	CUnequalIntervalScale u;
	CEllipseGauge e;

	// �����ʂ̑I��
	s.SetSubjectKey(iniData.SubjectKey.Subject);

	// �w�j�U�����̐ݒ�
	v.SetAmplitude(iniData.Vibration.Amplitude);
	v.SetPeriod(iniData.Vibration.Period);
	v.SetThreshold(iniData.Vibration.Threshold);

	// �s���Ԋu�ڐ����̐ݒ�
	u.CsvParse(csvPath);

	u.SetAdjustStep(iniData.StepValue.Value);
	u.SetAngleStep(iniData.StepValue.Angle);
	u.SetRotateStep(iniData.StepValue.Rotate);
	u.SetDeveloperMode(iniData.DeveloperMode.Enabled);

	// �ȉ~�`�v��̐ݒ�
	e.SetPanelIndex(iniData.PanelIndex.Ellipse0);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse1);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse2);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse3);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse4);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse5);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse6);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse7);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse8);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse9);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse10);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse11);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse12);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse13);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse14);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse15);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse15);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse16);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse17);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse18);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse19);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse20);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse21);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse22);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse23);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse24);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse25);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse26);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse27);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse28);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse29);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse30);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse31);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse31);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse32);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse33);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse34);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse35);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse36);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse37);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse38);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse39);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse40);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse41);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse42);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse43);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse44);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse45);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse46);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse47);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse48);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse49);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse50);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse51);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse52);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse53);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse54);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse55);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse56);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse57);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse58);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse59);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse60);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse61);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse62);
	e.SetPanelIndex(iniData.PanelIndex.Ellipse63);

	e.SetEllipseParameters(iniData.Ellipse.Division, iniData.Ellipse.Flattening,
		iniData.Ellipse.RotateAngle, iniData.Ellipse.StandbyAngle);

	// �����U���̐ݒ�
	e.SetDampingParameters(iniData.Damping.NaturalFreq, iniData.Damping.DampingRatio);
	
	// �ȉ~�ό`���g�p���邩�ۂ�
	iniData.Ellipse.Division < 2 ? useEllipse.push_back(false) : useEllipse.push_back(true);
	needleIndex.push_back(iniData.PanelIndex.Needle);

	state.push_back(s);
	vibration.push_back(v);
	unequal.push_back(u);
	ellipse.push_back(e);

	gaugeCount++;
}
void CRealAnalogGauge::OnInitialize(void)
{
	for (int i = 0; i < gaugeCount; i++)
	{
		ellipse[i].InitNeedle();
	}
}

void CRealAnalogGauge::OnElapse(const ATS_VEHICLESTATE &vehicleState, int *panel, int *sound)
{
	double value;

	for (int i = 0; i < gaugeCount; i++)
	{
		// ��ԗʂ̑I��
		value = state[i].GetStateValue(vehicleState, panel, sound);

		// �j�̐U��
		value = vibration[i].NeedleVibrationMain(value, vehicleState.Location);

		// �s���Ԋu�ڐ��̍Č�
		value = unequal[i].ConvertValue(value);

		// �ȉ~�`�ɕό`
		if (useEllipse[i])
		{
			// �ȉ~�`�ό`���g�p����ꍇ
			ellipse[i].EllipseGaugeMain(value, vehicleState.Time, panel);
		}
		else if (needleIndex[i] >= 0 && needleIndex[i] <= 255)
		{
			// �ȉ~�`�ό`���g�p���Ȃ��ꍇ
			panel[needleIndex[i]] = value * 1000;
		}
	}
}

void CRealAnalogGauge::OnKeyDown(int keyCode)
{
	for (int i = 0; i < gaugeCount; i++)
	{
		if (keyCode == keyIndex[COPY_VALUE_TO_CLIPBOARD]) { unequal[i].SetAngleToClipboard(); }
		if (keyCode == keyIndex[ADJUST_INCREMENT_SMALL]) { unequal[i].AdjustIncrementSmall(); }
		if (keyCode == keyIndex[ADJUST_DECREMENT_SMALL]) { unequal[i].AdjustDecrementSmall(); }
		if (keyCode == keyIndex[ADJUST_INCREMENT_MEDIUM]) { unequal[i].AdjustIncrementMedium(); }
		if (keyCode == keyIndex[ADJUST_DECREMENT_MEDIUM]) { unequal[i].AdjustDecrementMedium(); }
		if (keyCode == keyIndex[ADJUST_INCREMENT_LARGE]) { unequal[i].AdjustIncrementLarge(); }
		if (keyCode == keyIndex[ADJUST_DECREMENT_LARGE]) { unequal[i].AdjustDecrementLarge(); }
		if (keyCode == keyIndex[SWITCH_ADJUST_MODE]) { unequal[i].SwitchAdjustMode(); }
		if (keyCode == keyIndex[RESET_ADJUST_VALUE]) { unequal[i].ResetAdjustValue(); }
	}
}