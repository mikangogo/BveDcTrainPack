#pragma once
#include <string>
#include "Unicode.h"

class CStateFromSubjectKey
{
public:
	CStateFromSubjectKey(void);
	~CStateFromSubjectKey(void);
	void SetSubjectKey(std::tstring); // SubjectKey�̓o�^
	double GetStateValue(const ATS_VEHICLESTATE &, const int *, const int *); // ��ԗʂ̎擾
	double GetStateValue(void); // ��ԗʂ̎擾

private:
	int type;
	int index;
};

