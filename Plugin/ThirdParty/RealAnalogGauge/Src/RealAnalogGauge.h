#pragma once
#include <string>
#include <vector>
#include "Unicode.h"

class CRealAnalogGauge
{
public:
	CRealAnalogGauge(void);
	virtual ~CRealAnalogGauge(void);
	void OnLoad(const char*);
	void OnLoad(HANDLE);
	void OnInitialize(void);
	void OnElapse(const ATS_VEHICLESTATE &, int *, int *);
	void OnKeyDown(int);

private:
	void loadSingleGaugeSettings(const AtsIni &, std::tstring); // ��������AtsIni�ւ̎Q��

	int gaugeCount;

	int keyIndex[9];

	std::vector<CStateFromSubjectKey> state;// ���͏�ԗʑI��
	std::vector<CNeedleVibration> vibration; // �w�j�U��
	std::vector<CUnequalIntervalScale> unequal; // �s���Ԋu�ڐ�
	std::vector<CEllipseGauge> ellipse; // �ȉ~�v��

	std::vector<bool> useEllipse;
	std::vector<int> needleIndex;
};
