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
	// 設定値登録
	if (f < 0) { flattening = 0; }
	else if (f > 1) { flattening = 1; }
	else { flattening = f; }

	if (d < 2) { division = 2; }
	else if (d > panelIndex.size()) { division = panelIndex.size(); }
	else { division = d; }

	rotateAngle = ra;
	standbyAngle = sa;

	double r = 1 - flattening; // (b / a)
	double a = 1; // 長辺
	double b = 1 * r; // 短辺

	vector<double> angle;

	// 中心から針先までの距離が等間隔に変化する場合における角度（媒介変数）の配列
	for (int i = 0; i < division; i++)
	{
		double l = b + (a - b) * (division - 1 - i) / (division - 1);
		angle.push_back(TO_DEG * acos(sqrt((pow(l, 2) - pow(r, 2)) / (1 - pow(r, 2)))));
	}

	/*
	// 等間隔な角度の配列
	for (int i = 0; i < division; i++)
	{
		angle.push_back(i * 90 / (double)(division - 1));
	}
	*/

	// 角度とパネルインデックスの対応関係を登録
	for (int i = 0; i < (int)angle.size() - 1; i++)
	{
		indexAngleMap[(angle[i] + angle[i + 1]) / 2] = panelIndex[i];
	}

	// 十分大きい角度に最後のパネルインデックスを設定
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

	// 指針の減衰振動再現
	damping.UpdateDamping((time - prevTime) / 1000.0, &angle);

	// 角度（媒介変数）を指針選択用のキーに変換
	double needleSelectKey = fmod(abs(angle * TO_DEG - rotateAngle), 180);
	if (needleSelectKey > 90) { needleSelectKey = 180 - needleSelectKey; }

	// 円の指示角[rad]→楕円の指示角[deg]
	angle = TO_DEG * (2 * M_PI
		+ atan2(sin(angle - rotateAngle * TO_RAD)
		* (1 - flattening), cos(angle - rotateAngle * TO_RAD)))
		+ rotateAngle;

	// 直前フレームの指針指示をキャンセル
	if (prevIndex >= 0 && prevIndex <= 255)
	{
		panel[prevIndex] = standbyAngle * 1000;
	}

	// 指示角度からパネルインデックスの取得
	int index = -1;

	if (indexAngleMap.lower_bound(needleSelectKey) != indexAngleMap.end())
	{
		index = indexAngleMap.lower_bound(needleSelectKey)->second;
	}
	else
	{
		index = (--indexAngleMap.end())->second;
	}

	// 初期化時に指針リセット
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

	// 指針指示出力
	if (index >= 0 && index <= 255)
	{
		panel[index] = angle * 1000;
	}
	
	// 現フレームの状態を記録
	prevTime = time;
	prevIndex = index;
}
