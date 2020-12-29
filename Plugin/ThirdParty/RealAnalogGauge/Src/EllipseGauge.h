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

	int division; // ������
	double flattening; // �Ε���
	double rotateAngle; // ��]�p�x[deg]
	double standbyAngle; // �ҋ@�ʒu�p�x[deg]
	double r; // 1 - f or b / a

	bool forceStandbyNeedle;
};
