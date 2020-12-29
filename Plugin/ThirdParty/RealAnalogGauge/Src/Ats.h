int g_prevTime; // 直前フレームの時間[msec]
int g_brakeNotch; // ブレーキノッチ
int g_powerNotch; // 力行ノッチ
int g_reverser; // レバーサ

ATS_HANDLES g_output; // 出力

HINSTANCE g_handle;
CRealAnalogGauge g_rag;
char g_module_path[MAX_PATH];