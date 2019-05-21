#include "Memory.h"
#include "Offsets.h"

bool IsWindowFocused()
{
	HWND twnd = FindWindow(NULL, "Counter-Strike: Global Offensive");

	if (GetForegroundWindow() == twnd)
		return true;
	else
		return false;
}

void Radar()
{
	for (int i = 0; i < 32; i++)
	{
		value.Entity = mem.Read<DWORD>(GameModule.dwBase + offset.dwEntityList + i * 0x10);
		if (!value.Entity)
			continue;

		bool Dormant = mem.Read<bool>(value.Entity + offset.m_bDormant);
		if (Dormant)
			continue;

		mem.Write<bool>(value.Entity + offset.m_bSpotted, true);
	}
}

int main()
{
	while(!mem.Attach("csgo.exe", PROCESS_ALL_ACCESS)) {}
	GameModule = mem.GetModule("client_panorama.dll");

	while (true)
	{
		if (!IsWindowFocused())
			continue;

		value.LocalPlayer = mem.Read<DWORD>(GameModule.dwBase + offset.dwLocalPlayer);
		if (!value.LocalPlayer)
			continue;

		Radar();

		Sleep(1);
	}
}