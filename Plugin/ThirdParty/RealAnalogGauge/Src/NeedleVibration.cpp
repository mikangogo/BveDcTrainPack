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
	// 振動パラメータが0なら入力値をそのまま返す
	if (amplitude == 0 || coefficient == 0)
	{
		return value;
	}

	// 速度の絶対値を取る
	double speed = fabs(value);

	// 速度がしきい値以上なら針を振動させない
	if (threshold != 0 && threshold < speed)
	{
		return speed;
	}
	else
	{
		// 指針振動後の速度出力
		return speed + sin(location * coefficient)
			* (amplitude > speed ? speed : amplitude); // 速度が0近傍の場合、振動を弱める
	}
}