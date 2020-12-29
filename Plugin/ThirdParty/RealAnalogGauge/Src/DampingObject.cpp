// Ported from ObjectManager.cs in OpenBVE.

#include "stdafx.h"
#include "math.h"
#include "DampingObject.h"

CDampingObject::CDampingObject()
{
}

CDampingObject::~CDampingObject()
{
}

void CDampingObject::SetParameters(double NaturalFrequency, double DampingRatio)
{
	if (NaturalFrequency < 0.0)
	{
		this->NaturalFrequency = 0;
	}
	else if (DampingRatio < 0.0)
	{
		this->DampingRatio = 0;
	}
	else
	{
		this->NaturalFrequency = NaturalFrequency;
		this->NaturalTime = NaturalFrequency != 0.0 ? 1.0 / NaturalFrequency : 0.0;
		this->DampingRatio = DampingRatio;
		if (DampingRatio < 1.0)
		{
			this->NaturalDampingFrequency = NaturalFrequency * sqrt(1.0 - DampingRatio * DampingRatio);
		}
		else if (DampingRatio == 1.0)
		{
			this->NaturalDampingFrequency = NaturalFrequency;
		}
		else
		{
			this->NaturalDampingFrequency = NaturalFrequency * sqrt(DampingRatio * DampingRatio - 1.0);
		}
		this->OriginalAngle = 0.0;
		this->OriginalDerivative = 0.0;
		this->TargetAngle = 0.0;
		this->CurrentAngle = 0.0;
		this->CurrentValue = 1.0;
		this->CurrentTimeDelta = 0.0;
	}
}

void CDampingObject::UpdateDamping(double TimeElapsed, double* Angle)
{
	if (this->NaturalFrequency == 0)
	{
		return;
	}
	if (TimeElapsed < 0.0)
	{
		TimeElapsed = 0.0;
	}
	else if (TimeElapsed > 1.0)
	{
		TimeElapsed = 1.0;
	}
	if (this->CurrentTimeDelta > this->NaturalTime)
	{
		// update
		double newDerivative;
		if (this->NaturalFrequency == 0.0)
		{
			newDerivative = 0.0;
		}
		else if (this->DampingRatio == 0.0)
		{
			newDerivative = this->OriginalDerivative * cos(this->NaturalFrequency * this->CurrentTimeDelta) - this->NaturalFrequency * sin(this->NaturalFrequency * this->CurrentTimeDelta);
		}
		else if (this->DampingRatio < 1.0)
		{
			newDerivative = exp(-this->DampingRatio * this->NaturalFrequency * this->CurrentTimeDelta) * (this->NaturalDampingFrequency * this->OriginalDerivative * cos(this->NaturalDampingFrequency * this->CurrentTimeDelta) - (this->NaturalDampingFrequency * this->NaturalDampingFrequency + this->DampingRatio * this->NaturalFrequency * (this->DampingRatio * this->NaturalFrequency + this->OriginalDerivative)) * sin(this->NaturalDampingFrequency * this->CurrentTimeDelta)) / this->NaturalDampingFrequency;
		}
		else if (this->DampingRatio == 1.0)
		{
			newDerivative = exp(-this->NaturalFrequency * this->CurrentTimeDelta) * (this->OriginalDerivative - this->NaturalFrequency * (this->NaturalFrequency + this->OriginalDerivative) * this->CurrentTimeDelta);
		}
		else
		{
			newDerivative = exp(-this->DampingRatio * this->NaturalFrequency * this->CurrentTimeDelta) * (this->NaturalDampingFrequency * this->OriginalDerivative * cosh(this->NaturalDampingFrequency * this->CurrentTimeDelta) + (this->NaturalDampingFrequency * this->NaturalDampingFrequency - this->DampingRatio * this->NaturalFrequency * (this->DampingRatio * this->NaturalFrequency + this->OriginalDerivative)) * sinh(this->NaturalDampingFrequency * this->CurrentTimeDelta)) / this->NaturalDampingFrequency;
		}
		double a = this->TargetAngle - this->OriginalAngle;
		this->OriginalAngle = this->CurrentAngle;
		this->TargetAngle = *Angle;
		double b = this->TargetAngle - this->OriginalAngle;
		double r = b == 0.0 ? 1.0 : a / b;
		this->OriginalDerivative = newDerivative * r;
		if (this->NaturalTime > 0.0)
		{
			this->CurrentTimeDelta = fmod(this->CurrentTimeDelta, this->NaturalTime);
		}
	}
	// perform
	double newValue;
	if (this->NaturalFrequency == 0.0)
	{
		newValue = 1.0;
	}
	else if (this->DampingRatio == 0.0)
	{
		newValue = cos(this->NaturalFrequency * this->CurrentTimeDelta) + this->OriginalDerivative * sin(this->NaturalFrequency * this->CurrentTimeDelta) / this->NaturalFrequency;
	}
	else if (this->DampingRatio < 1.0)
	{
		double n = (this->OriginalDerivative + this->NaturalFrequency * this->DampingRatio) / this->NaturalDampingFrequency;
		newValue = exp(-this->DampingRatio * this->NaturalFrequency * this->CurrentTimeDelta) * (cos(this->NaturalDampingFrequency * this->CurrentTimeDelta) + n * sin(this->NaturalDampingFrequency * this->CurrentTimeDelta));
	}
	else if (this->DampingRatio == 1.0)
	{
		newValue = exp(-this->NaturalFrequency * this->CurrentTimeDelta) * (1.0 + (this->OriginalDerivative + this->NaturalFrequency) * this->CurrentTimeDelta);
	}
	else
	{
		double n = (this->OriginalDerivative + this->NaturalFrequency * this->DampingRatio) / this->NaturalDampingFrequency;
		newValue = exp(-this->DampingRatio * this->NaturalFrequency * this->CurrentTimeDelta) * (cosh(this->NaturalDampingFrequency * this->CurrentTimeDelta) + n * sinh(this->NaturalDampingFrequency * this->CurrentTimeDelta));
	}
	this->CurrentValue = newValue;
	this->CurrentAngle = this->TargetAngle * (1.0 - newValue) + this->OriginalAngle * newValue;
	this->CurrentTimeDelta += TimeElapsed;
	*Angle = this->CurrentAngle;
}
