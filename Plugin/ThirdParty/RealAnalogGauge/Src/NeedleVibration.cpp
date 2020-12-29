#include "stdafx.h"
#include "atsplugin.h"
#include "NeedleVibration.h"
#define _USE_MATH_DEFINES
#include <math.h>

CNeedleVibration::CNeedleVibration()
{
}

CNeedleVibration::~CNeedleVibration()
{
}

void CNeedleVibration::SetPeriod(double value)
{
	coefficient = value == 0 ? 0 : fabs((2 * M_PI) / ((10.0 * 1000 / 3600) * value));
}

void CNeedleVibration::SetAmplitude(double value)
{
	amplitude = fabs(value);
}

void CNeedleVibration::SetThreshold(double value)
{
	threshold = fabs(value);
}

void CNeedleVibration::SetParameters(double p, double a, double t)
{
	coefficient = p == 0 ? 0 : fabs((2 * M_PI) / ((10.0 * 1000 / 3600) * p));
	amplitude = fabs(a);
	threshold = fabs(t);
}

double CNeedleVibration::NeedleVibrationMain(double value, double location)
{
	// �U���p�����[�^��0�Ȃ���͒l�����̂܂ܕԂ�
	if (amplitude == 0 || coefficient == 0)
	{
		return value;
	}

	// ���x�̐�Βl�����
	double speed = fabs(value);

	// ���x���������l�ȏ�Ȃ�j��U�������Ȃ�
	if (threshold != 0 && threshold < speed)
	{
		return speed;
	}
	else
	{
		// �w�j�U����̑��x�o��
		return speed + sin(location * coefficient)
			* (amplitude > speed ? speed : amplitude); // ���x��0�ߖT�̏ꍇ�A�U������߂�
	}
}