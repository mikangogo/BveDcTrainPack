#pragma once
class CNeedleVibration
{
public:
	CNeedleVibration();
	virtual ~CNeedleVibration();
	void SetPeriod(double); // 周期の設定
	void SetAmplitude(double); // 振動強度の設定
	void SetThreshold(double); // しきい値の設定
	void SetParameters(double, double, double); // 上記3項目をまとめて設定
	double NeedleVibrationMain(double, double); // 指針の振動処理

private:
	double coefficient; // 距離->角度への変換係数
	double amplitude; // 針の振動強度
	double threshold; // 振動を止めるしきい値速度
};

