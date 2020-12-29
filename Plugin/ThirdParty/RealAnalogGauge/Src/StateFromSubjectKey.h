#pragma once
#include <string>
#include "Unicode.h"

class CStateFromSubjectKey
{
public:
	CStateFromSubjectKey(void);
	~CStateFromSubjectKey(void);
	void SetSubjectKey(std::tstring); // SubjectKey‚Ì“o˜^
	double GetStateValue(const ATS_VEHICLESTATE &, const int *, const int *); // ó‘Ô—Ê‚Ìæ“¾
	double GetStateValue(void); // ó‘Ô—Ê‚Ìæ“¾

private:
	int type;
	int index;
};

