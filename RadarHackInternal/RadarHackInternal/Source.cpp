#include "Offsets.h"

bool IsWindowFocused()
{
	HWND tWnd = FindWindow(NULL, "Counter-Strike: Global Offensive");

	if (GetForegroundWindow() == tWnd)
		return true;
	else
		return false;
}

void Radar()
{
	for (int i = 0; i < 32; i++)
	{
		value.Entity = *(DWORD*)(GameModule + offset.dwEntityList + i * 0x10);
		if (!value.Entity)
			continue;

		bool Dormant = *(bool*)(value.Entity + offset.m_bDormant);
		if (Dormant)
			continue;

		*(bool*)(value.Entity + offset.m_bSpotted) = true;
	}
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

		Radar();
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