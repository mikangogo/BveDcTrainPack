#pragma once
class CDampingObject
{
public:
	CDampingObject();
	virtual ~CDampingObject();
	void CDampingObject::SetParameters(double, double); // NaturalFrequency, DampingRatio
	void CDampingObject::UpdateDamping(double, double*); // ElapsedTime[sec], Angle[rad]

private:
	double NaturalFrequency;
	double NaturalTime;
	double DampingRatio;
	double NaturalDampingFrequency;
	double OriginalAngle;
	double OriginalDerivative;
	double TargetAngle;
	double CurrentAngle;
	double CurrentValue;
	double CurrentTimeDelta;
};

