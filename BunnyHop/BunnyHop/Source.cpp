#include "Memory.h"
#include "Offsets.h"
#include <iostream>
#include "BHop.h"

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

	value.LocalPlayer = mem.Read<DWORD>(GameModule.dwBase + offset.dwLocalPlayer);

	if (!value.LocalPlayer)
		while (!value.LocalPlayer)
			value.LocalPlayer = mem.Read<DWORD>(GameModule.dwBase + offset.dwLocalPlayer);

	while (true)
	{
		if (!IsWindowFocused())
			continue;

		BunnyHop();

		Sleep(1);
	}
}
