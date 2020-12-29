#pragma once

#include <vector>
#include <string>
#include <map>
#include "Unicode.h"

#define NORMAL 0
#define VERIFY 1
#define ADJUST 2
#define ROTATE 3

class CUnequalIntervalScale
{
public:
	CUnequalIntervalScale(void);
	~CUnequalIntervalScale(void);
	void CsvParse(std::tstring); // CSVファイルの読み込み
	void SetAdjustStep(double); // 確認用の数値増加量の設定
	void SetAngleStep(double); // 角度増加量の設定
	void SetRotateStep(double); // 角度増加量の設定
	void SetDeveloperMode(int); // 開発者モードの設定

	void SwitchAdjustMode(void); // モード切替
	void ResetAdjustValue(void); // 調整値のリセット

	void AdjustIncrementLarge(void); // 調整値増加（大）
	void AdjustIncrementMedium(void); // 調整値増加（中）
	void AdjustIncrementSmall(void); // 調整値増加（小）
	void AdjustDecrementLarge(void); // 調整値減少（大）
	void AdjustDecrementMedium(void); // 調整値減少（中）
	void AdjustDecrementSmall(void); // 調整値減少（小）
	void SetAngleToClipboard(void); // 角度値をクリップボードへ出力
	double ConvertValue(double); // 数値→角度の変換
	bool GetDeveloperModeSetting(); // 開発者モード設定値取得

private:
	double linearInterpolate(double); // 線形補間
	BOOL clipboardOutput(TCHAR *); // クリップボード出力

	std::map<double, double> params; // 入力値と出力角度の組
	double adjustValue; // 確認用数値
	double adjustStep; // 確認用数値増加量
	double angle; // 現在の角度（調整用）
	double angleStep; // 角度増加量
	double rotateAngle; // 現在の角度（回転モード）
	double rotateStep; // 回転速度[deg/frame]
	int adjustMode; // 現在の数値出力モード
	bool developerMode; // 開発者モードか否か
};
