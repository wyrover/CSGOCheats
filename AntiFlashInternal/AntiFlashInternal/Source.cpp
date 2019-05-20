#include "Offsets.h"

bool IsWindowFocused()
{
	HWND tWnd = FindWindow(NULL, "Counter-Strike: Global Offensive");

	if (GetForegroundWindow() == tWnd)
		return true;
	else
		return false;
}

void AntiFlash()
{
	int FlashDuration = *(int*)(value.LocalPlayer + offset.m_flFlashDuration);
	if (FlashDuration > 0)
		*(int*)(value.LocalPlayer + offset.m_flFlashDuration) = 0;
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

		AntiFlash();
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

