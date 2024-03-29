#pragma once
#include <string>
#include "Unicode.h"

class CStateFromSubjectKey
{
public:
	CStateFromSubjectKey(void);
	~CStateFromSubjectKey(void);
	void SetSubjectKey(std::tstring); // SubjectKeyの登録
	double GetStateValue(const ATS_VEHICLESTATE &, const int *, const int *); // 状態量の取得
	double GetStateValue(void); // 状態量の取得

private:
	int type;
	int index;
};

