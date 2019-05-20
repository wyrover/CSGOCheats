#include "Offsets.h"
#include "TriggerBot.h"

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
	bool canTBot = false;

	while (true)
	{
		if (!IsWindowFocused())
			continue;
		
		value.LocalPlayer = *(DWORD*)(GameModule + offset.dwLocalPlayer);
		if (!value.LocalPlayer)
			continue;

		if (GetAsyncKeyState(VK_F2) & 1)
		{
			value.MyTeam = *(int*)(value.LocalPlayer + offset.m_iTeamNum);
			canTBot = !canTBot;
		}
		if (canTBot)
			HandleTBot(20);
	}
}

BOOL WINAPI DllMain( HMODULE hModule,DWORD  dwReason,LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(hModule);
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)main, NULL, NULL, NULL);
	}
	return TRUE;
}

