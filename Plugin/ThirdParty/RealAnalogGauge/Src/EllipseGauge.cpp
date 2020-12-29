#include "StdAfx.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "DampingObject.h"
#include "EllipseGauge.h"

using namespace std;

#define TO_RAD	M_PI / 180
#define TO_DEG	180 / M_PI

CEllipseGauge::CEllipseGauge(void)
{
}

CEllipseGauge::~CEllipseGauge(void)
{
}

void CEllipseGauge::SetPanelIndex(int index)
{
	panelIndex.push_back(index);
}

void CEllipseGauge::SetPanelIndex(vector<int> index)
{
	panelIndex = index;
}

void CEllipseGauge::SetEllipseParameters(int d, double f, double ra, double sa)
{
	// �ݒ�l�o�^
	if (f < 0) { flattening = 0; }
	else if (f > 1) { flattening = 1; }
	else { flattening = f; }

	if (d < 2) { division = 2; }
	else if (d > panelIndex.size()) { division = panelIndex.size(); }
	else { division = d; }

	rotateAngle = ra;
	standbyAngle = sa;

	double r = 1 - flattening; // (b / a)
	double a = 1; // ����
	double b = 1 * r; // �Z��

	vector<double> angle;

	// ���S����j��܂ł̋��������Ԋu�ɕω�����ꍇ�ɂ�����p�x�i�}��ϐ��j�̔z��
	for (int i = 0; i < division; i++)
	{
		double l = b + (a - b) * (division - 1 - i) / (division - 1);
		angle.push_back(TO_DEG * acos(sqrt((pow(l, 2) - pow(r, 2)) / (1 - pow(r, 2)))));
	}

	/*
	// ���Ԋu�Ȋp�x�̔z��
	for (int i = 0; i < division; i++)
	{
		angle.push_back(i * 90 / (double)(division - 1));
	}
	*/

	// �p�x�ƃp�l���C���f�b�N�X�̑Ή��֌W��o�^
	for (int i = 0; i < (int)angle.size() - 1; i++)
	{
		indexAngleMap[(angle[i] + angle[i + 1]) / 2] = panelIndex[i];
	}

	// �\���傫���p�x�ɍŌ�̃p�l���C���f�b�N�X��ݒ�
	indexAngleMap[180] = panelIndex[(int)angle.size() - 1];
}

void CEllipseGauge::SetDampingParameters(double naturalFrequency, double dampingRatio)
{
	damping.SetParameters(naturalFrequency, dampingRatio);
}

void CEllipseGauge::InitNeedle(void)
{
	forceStandbyNeedle = true;
}

void CEllipseGauge::EllipseGaugeMain(double angle, int time, int *panel)
{
	// [deg] -> [rad]
	angle = angle * TO_RAD;

	// �w�j�̌����U���Č�
	damping.UpdateDamping((time - prevTime) / 1000.0, &angle);

	// �p�x�i�}��ϐ��j���w�j�I��p�̃L�[�ɕϊ�
	double needleSelectKey = fmod(abs(angle * TO_DEG - rotateAngle), 180);
	if (needleSelectKey > 90) { needleSelectKey = 180 - needleSelectKey; }

	// �~�̎w���p[rad]���ȉ~�̎w���p[deg]
	angle = TO_DEG * (2 * M_PI
		+ atan2(sin(angle - rotateAngle * TO_RAD)
		* (1 - flattening), cos(angle - rotateAngle * TO_RAD)))
		+ rotateAngle;

	// ���O�t���[���̎w�j�w�����L�����Z��
	if (prevIndex >= 0 && prevIndex <= 255)
	{
		panel[prevIndex] = standbyAngle * 1000;
	}

	// �w���p�x����p�l���C���f�b�N�X�̎擾
	int index = -1;

	if (indexAngleMap.lower_bound(needleSelectKey) != indexAngleMap.end())
	{
		index = indexAngleMap.lower_bound(needleSelectKey)->second;
	}
	else
	{
		index = (--indexAngleMap.end())->second;
	}

	// ���������Ɏw�j���Z�b�g
	if (forceStandbyNeedle)
	{
		map<double, int>::iterator itr;

		for (itr = indexAngleMap.begin(); itr != indexAngleMap.end(); itr++)
		{
			if (itr->second >= 0 && itr->second <= 255)
			{
				panel[itr->second] = standbyAngle * 1000;
			}
		}

		forceStandbyNeedle = false;
	}

	// �w�j�w���o��
	if (index >= 0 && index <= 255)
	{
		panel[index] = angle * 1000;
	}
	
	// ���t���[���̏�Ԃ��L�^
	prevTime = time;
	prevIndex = index;
}
