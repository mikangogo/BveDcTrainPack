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
	void loadSingleGaugeSettings(const AtsIni &, std::tstring); // æêøÍAtsIniÖÌQÆ

	int gaugeCount;

	int keyIndex[9];

	std::vector<CStateFromSubjectKey> state;// üÍóÔÊIð
	std::vector<CNeedleVibration> vibration; // wjU®
	std::vector<CUnequalIntervalScale> unequal; // sÔuÚ·
	std::vector<CEllipseGauge> ellipse; // È~ví

	std::vector<bool> useEllipse;
	std::vector<int> needleIndex;
};
