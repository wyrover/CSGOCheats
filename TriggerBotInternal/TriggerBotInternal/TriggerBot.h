#define WEAPON_AWP 9
#define WEAPON_SCOUT 40

void Shoot(int delay)
{
	Sleep(delay);
	*(int*)(GameModule + offset.dwForceAttack) = 5;
	Sleep(delay);
	*(int*)(GameModule + offset.dwForceAttack) = 4;
}

bool CheckScoped()
{
	return *(bool*)(value.LocalPlayer + offset.m_bIsScoped);
}

void GetMyWeaponID()
{
	value.Weapon = *(int*)(value.LocalPlayer + offset.m_hActiveWeapon);
	value.EntityWeapon = *(int*)(GameModule + offset.dwEntityList + ((value.Weapon & 0xFFF) - 1) * 0x10);
	if(value.EntityWeapon)
		value.MyWeaponID = *(int*)(value.EntityWeapon + offset.m_iItemDefinitionIndex);
}

bool CheckTBot()
{
	int Crosshair =*(int*)(value.LocalPlayer + offset.m_iCrosshairId);
	if (Crosshair != 0 && Crosshair < 64)
	{
		value.Entity = *(DWORD*)(GameModule + offset.dwEntityList + ((Crosshair - 1) * 0x10));
		value.EntityTeam = *(int*)(value.Entity + offset.m_iTeamNum);
		value.EntityHP = *(int*)(value.Entity + offset.m_iHealth);
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