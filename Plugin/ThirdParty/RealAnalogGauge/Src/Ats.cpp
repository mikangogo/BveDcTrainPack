#include "stdafx.h"
#include "atsplugin.h"
#include "AtsIni.h"
#include "StateFromSubjectKey.h"
#include "NeedleVibration.h"
#include "UnequalIntervalScale.h"
#include "DampingObject.h"
#include "EllipseGauge.h"
#include "RealAnalogGauge.h"
#include "Ats.h"

BOOL APIENTRY DllMain(HINSTANCE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
	)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
		GetModuleFileNameA(hModule, g_module_path, MAX_PATH);
		break;
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}

	g_handle = hModule;

	return TRUE;
}
ATS_API void WINAPI Load()
{
	g_rag.OnLoad(g_module_path);
}

ATS_API void WINAPI Dispose()
{
}

ATS_API int WINAPI GetPluginVersion()
{
	return ATS_VERSION;
}

ATS_API void WINAPI SetVehicleSpec(ATS_VEHICLESPEC spec)
{
}

ATS_API void WINAPI Initialize(int brake)
{
	g_rag.OnInitialize();
}

ATS_API ATS_HANDLES WINAPI Elapse(ATS_VEHICLESTATE state, int *panel, int *sound)
{
	// ハンドル出力
	g_output.Reverser = g_reverser;
	g_output.Power = g_powerNotch;
	g_output.Brake = g_brakeNotch;
	g_output.ConstantSpeed = ATS_CONSTANTSPEED_CONTINUE;

	// パネル出力
	g_rag.OnElapse(state, panel, sound);

	// サウンド出力

	return g_output;
}

ATS_API void WINAPI SetPower(int power)
{
	g_powerNotch = power;
}

ATS_API void WINAPI SetBrake(int brake)
{
	g_brakeNotch = brake;
}

ATS_API void WINAPI SetReverser(int reverser)
{
	g_reverser = reverser;
}

ATS_API void WINAPI KeyDown(int keyCode)
{
	g_rag.OnKeyDown(keyCode);
}

ATS_API void WINAPI KeyUp(int keyCode)
{
}

ATS_API void WINAPI HornBlow(int keyCode)
{
}

ATS_API void WINAPI DoorOpen()
{
}

ATS_API void WINAPI DoorClose()
{
}

ATS_API void WINAPI SetSignal(int signal)
{
}

ATS_API void WINAPI SetBeaconData(ATS_BEACONDATA data)
{
}