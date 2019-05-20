#include "Memory.h"
#include "Offsets.h"
#include <iostream>
#include "Glow.h"

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
	while (!mem.Attach("csgo.exe", PROCESS_ALL_ACCESS)) {}
	GameModule = mem.GetModule("client_panorama.dll");

	while (true)
	{
		if (!IsWindowFocused())
			continue;

		value.LocalPlayer = mem.Read<DWORD>(GameModule.dwBase + offset.dwLocalPlayer);
		if (!value.LocalPlayer)
			continue;

		Glow();

		Sleep(1);
	}
}