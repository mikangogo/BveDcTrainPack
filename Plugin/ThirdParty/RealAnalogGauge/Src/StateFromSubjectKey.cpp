#include "stdafx.h"
#include <algorithm>
#include <sstream>

#include "atsplugin.h"
#include "StateFromSubjectKey.h"

using namespace std;

#define STATE 0
#define PANEL 1
#define SOUND 2

#define NONE	0
#define KMPH	1
#define BC		2
#define MR		3
#define SAP		4
#define BP		5
#define ER		6
#define AM		7
#define AMABS	8

CStateFromSubjectKey::CStateFromSubjectKey()
{
}

CStateFromSubjectKey::~CStateFromSubjectKey()
{
}

void CStateFromSubjectKey::SetSubjectKey(tstring subjectKey)
{
	// è¨ï∂éöïœä∑
	transform(subjectKey.begin(), subjectKey.end(), subjectKey.begin(), ::tolower);

	if (subjectKey.find(_T("panel"), 0) == 0)
	{
		subjectKey.erase(0, 5);
		tstringstream ss;
		double v;
		ss << subjectKey;
		ss >> v;

		if (!ss.fail() && v >= 0 && v <= 255 && fmod(v, 1) == 0 && subjectKey.find(_T("."), 0) == tstring::npos)
		{
			type = PANEL;
			index = (int)v;
		}
		else
		{
			type = STATE;
			index = NONE;
		}
	}
	else if (subjectKey.find(_T("sound"), 0) == 0)
	{
		subjectKey.erase(0, 5);
		tstringstream ss;
		double v;
		ss << subjectKey;
		ss >> v;

		if (!ss.fail() && v >= 0 && v <= 255 && fmod(v, 1) == 0 && subjectKey.find(_T("."), 0) == tstring::npos)
		{
			type = SOUND;
			index = (int)v;
		}
		else
		{
			type = STATE;
			index = NONE;
		}
	}
	else
	{
		type = STATE;
		index = NONE;

		if (subjectKey == _T("kmph")) { index = KMPH; }
		if (subjectKey == _T("bc")) { index = BC; }
		if (subjectKey == _T("mr")) { index = MR; }
		if (subjectKey == _T("sap")) { index = SAP; }
		if (subjectKey == _T("bp")) { index = BP; }
		if (subjectKey == _T("er")) { index = ER; }
		if (subjectKey == _T("am")) { index = AM; }
		if (subjectKey == _T("amabs")) { index = AMABS; }
	}
}

double CStateFromSubjectKey::GetStateValue(const ATS_VEHICLESTATE &state, const int *panel, const int *sound)
{
	switch (type)
	{
	case STATE:
		switch (index)
		{
		case KMPH:
			return fabs(state.Speed);
			break;
		case BC:
			return state.BcPressure * 1;
			break;
		case MR:
			return state.MrPressure * 1;
			break;
		case SAP:
			return state.SapPressure * 1;
			break;
		case BP:
			return state.BpPressure * 1;
			break;
		case ER:
			return state.ErPressure * 1;
			break;
		case AM:
			return state.Current;
			break;
		case AMABS:
			return fabs(state.Current);
			break;
		}
		return 0;
		break;
	case PANEL:
		if (index >= 0 && index <= 255) { return panel[index]; }
		break;
	case SOUND:
		if (index >= 0 && index <= 255) { return sound[index]; }
		break;
	}

	return 0;
}
