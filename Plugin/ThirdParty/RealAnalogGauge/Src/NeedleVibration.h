#pragma once
class CNeedleVibration
{
public:
	CNeedleVibration();
	virtual ~CNeedleVibration();
	void SetPeriod(double); // �����̐ݒ�
	void SetAmplitude(double); // �U�����x�̐ݒ�
	void SetThreshold(double); // �������l�̐ݒ�
	void SetParameters(double, double, double); // ��L3���ڂ��܂Ƃ߂Đݒ�
	double NeedleVibrationMain(double, double); // �w�j�̐U������

private:
	double coefficient; // ����->�p�x�ւ̕ϊ��W��
	double amplitude; // �j�̐U�����x
	double threshold; // �U�����~�߂邵�����l���x
};

