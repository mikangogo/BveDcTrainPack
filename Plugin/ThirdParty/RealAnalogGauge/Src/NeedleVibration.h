#pragma once
class CNeedleVibration
{
public:
	CNeedleVibration();
	virtual ~CNeedleVibration();
	void SetPeriod(double); // üŠú‚Ìİ’è
	void SetAmplitude(double); // U“®‹­“x‚Ìİ’è
	void SetThreshold(double); // ‚µ‚«‚¢’l‚Ìİ’è
	void SetParameters(double, double, double); // ã‹L3€–Ú‚ğ‚Ü‚Æ‚ß‚Äİ’è
	double NeedleVibrationMain(double, double); // wj‚ÌU“®ˆ—

private:
	double coefficient; // ‹——£->Šp“x‚Ö‚Ì•ÏŠ·ŒW”
	double amplitude; // j‚ÌU“®‹­“x
	double threshold; // U“®‚ğ~‚ß‚é‚µ‚«‚¢’l‘¬“x
};

