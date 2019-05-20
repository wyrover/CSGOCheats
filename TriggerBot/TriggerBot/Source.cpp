#include "Memory.h"
#include "Offsets.h"
#include <iostream>
#include "TriggerBot.h"

bool IsWindowFocused()
{
	HWND tWnd = FindWindow(NULL, "Counter-Strike: Global Offensive");

	if (GetForegroundWindow() == tWnd)
		return true;
	else
		return false;
}

int main()
{
	bool canTBot = false;

	while (!mem.Attach("csgo.exe", PROCESS_ALL_ACCESS)) {}
	GameModule = mem.GetModule("client_panorama.dll");

	while (true)
	{
		if (!IsWindowFocused())
			continue;
		
		value.LocalPlayer = mem.Read<DWORD>(GameModule.dwBase + offset.dwLocalPlayer);
		if (!value.LocalPlayer)
			continue;
		
		if (GetAsyncKeyState(VK_F2) & 1)
		{
			value.MyTeam = mem.Read<int>(value.LocalPlayer + offset.m_iTeamNum);
			canTBot = !canTBot;
		}
		if (canTBot)
			HandleTBot(20);

		Sleep(1);
	}
}
