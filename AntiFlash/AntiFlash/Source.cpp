#include "Memory.h"
#include "Offsets.h"
#include <iostream>

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
	int FlashDuration = mem.Read<int>(value.LocalPlayer + offset.m_flFlashDuration);
	if (FlashDuration > 0)
		mem.Write<int>(value.LocalPlayer + offset.m_flFlashDuration, 0);
}

int main()
{
	while (!mem.Attach("csgo.exe", PROCESS_ALL_ACCESS)) {}
	GameModule = mem.GetModule("client_panorama.dll");

	while (true)
	{
		if (!IsWindowFocused())
			continue;
		
		value.LocalPlayer = mem.Read<DWORD>(GameModule.dwBase + offset.dwLocalPlayer);
		if (!value.LocalPlayer)
			continue;

		AntiFlash();

		Sleep(1);
	}
}
