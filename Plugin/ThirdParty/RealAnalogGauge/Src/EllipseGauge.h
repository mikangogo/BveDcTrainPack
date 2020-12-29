#pragma once

#include <vector>
#include <map>

class CEllipseGauge
{
public:
	CEllipseGauge(void);
	virtual ~CEllipseGauge(void);
	void SetPanelIndex(int);
	void SetPanelIndex(std::vector<int>);
	void SetEllipseParameters(int, double, double, double);
	void SetDampingParameters(double, double);
	void InitNeedle(void);
	void EllipseGaugeMain(double, int, int *);

private:
	CDampingObject damping;

	std::vector<int> panelIndex;
	std::map<double, int> indexAngleMap;

	int prevIndex;
	int prevTime;

	int division; // •ªŠ„”
	double flattening; // •Î•½—¦
	double rotateAngle; // ‰ñ“]Šp“x[deg]
	double standbyAngle; // ‘Ò‹@ˆÊ’uŠp“x[deg]
	double r; // 1 - f or b / a

	bool forceStandbyNeedle;
};
