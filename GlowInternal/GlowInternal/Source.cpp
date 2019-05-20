#include "Offsets.h"
#include "Glow.h"

bool IsWindowFocused()
{
	HWND tWnd = FindWindow(NULL, "Counter-Strike: Global Offensive");

	if (GetForegroundWindow() == tWnd)
		return true;
	else
		return false;
}

BOOL WINAPI main()
{
	while (true)
	{
		if (!IsWindowFocused())
			continue;

		value.LocalPlayer = *(DWORD*)(GameModule + offset.dwLocalPlayer);
		if (!value.LocalPlayer)
			continue;

		Glow();
	}
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(hModule);
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)main, NULL, NULL, NULL);
	}
	return TRUE;
}