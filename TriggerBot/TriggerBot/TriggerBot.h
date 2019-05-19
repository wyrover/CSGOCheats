#define WEAPON_AWP 9
#define WEAPON_SCOUT 40

void Shoot(int delay)
{
	Sleep(delay);
	mem.Write<int>(GameModule.dwBase + offset.dwForceAttack, 5);
	Sleep(delay);
	mem.Write<int>(GameModule.dwBase + offset.dwForceAttack, 4);
}

bool CheckScoped()
{
	return mem.Read<bool>(value.LocalPlayer + offset.m_bIsScoped);
}

void GetMyWeaponID()
{
	value.Weapon = mem.Read<int>(value.LocalPlayer + offset.m_hActiveWeapon);
	value.EntityWeapon = mem.Read<int>(GameModule.dwBase + offset.dwEntityList + ((value.Weapon & 0xFFF) - 1) * 0x10);
	if (value.EntityWeapon)
		value.MyWeaponID = mem.Read<int>(value.EntityWeapon + offset.m_iItemDefinitionIndex);
}

bool CheckTBot()
{
	int Crosshair = mem.Read<int>(value.LocalPlayer + offset.m_iCrosshairId);
	if (Crosshair != 0 && Crosshair < 64)
	{
		value.Entity = mem.Read<DWORD>(GameModule.dwBase + offset.dwEntityList + ((Crosshair - 1) * 0x10));
		value.EntityTeam = mem.Read<int>(value.Entity + offset.m_iTeamNum);
		value.EntityHP = mem.Read<int>(value.Entity + offset.m_iHealth);
		if (value.EntityTeam != value.MyTeam && value.EntityHP > 0)
		{
			GetMyWeaponID();
			if (value.MyWeaponID == WEAPON_SCOUT || value.MyWeaponID == WEAPON_AWP)
				return CheckScoped();
			else
				return false;
		}
		else return false;
	}
	else return false;
}

void HandleTBot(int delay)
{
	if (CheckTBot())
		Shoot(delay);
}