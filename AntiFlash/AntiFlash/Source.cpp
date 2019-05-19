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
		mem.Write(value.LocalPlayer + offset.m_flFlashDuration, 0);
}

int main()
{
	while (!mem.Attach("csgo.exe", PROCESS_ALL_ACCESS)) {}
	bClient = mem.GetModule("client_panorama.dll");

	value.LocalPlayer = mem.Read<DWORD>(bClient.dwBase + offset.dwLocalPlayer);

	if (!value.LocalPlayer)
		while (!value.LocalPlayer)
			value.LocalPlayer = mem.Read<DWORD>(bClient.dwBase + offset.dwLocalPlayer);

	while (true)
	{
		if (!IsWindowFocused())
			continue;

		AntiFlash();

		Sleep(1);
	}
}