struct GlowStruct
{
	BYTE base[4];
	float red;
	float green;
	float blue;
	float alpha;
	BYTE buffer1[16];
	bool occluded;
	bool unoccluded;
	bool fullBloom;
	BYTE buffer2[5];
	int glowStyle;
};

void SetDGlow(int GlowIndex)
{
	GlowStruct DGlow;
	DGlow = *(GlowStruct*)(value.GlowObject + (GlowIndex * 0x38));

	DGlow.red = 1.0f;
	DGlow.green = 1.0f;
	DGlow.blue = 1.0f;
	DGlow.alpha = 1.0f;
	DGlow.occluded = true;
	DGlow.unoccluded = false;

	*(GlowStruct*)(value.GlowObject + (GlowIndex * 0x38)) = DGlow;
}

void SetTGlow(int GlowIndex)
{
	GlowStruct TGlow;
	TGlow = *(GlowStruct*)(value.GlowObject + (GlowIndex * 0x38));

	TGlow.red = 1.0f;
	TGlow.green = 0.15f;
	TGlow.alpha = 1.0f;
	TGlow.occluded = true;
	TGlow.unoccluded = false;

	*(GlowStruct*)(value.GlowObject + (GlowIndex * 0x38)) = TGlow;
}

void SetCTGlow(int GlowIndex)
{
	GlowStruct CTGlow;
	CTGlow = *(GlowStruct*)(value.GlowObject + (GlowIndex * 0x38));

	CTGlow.blue = 0.8f;
	CTGlow.alpha = 1.0f;
	CTGlow.occluded = true;
	CTGlow.unoccluded = false;

	*(GlowStruct*)(value.GlowObject + (GlowIndex * 0x38)) = CTGlow;
}

void Glow()
{
	value.GlowObject = *(DWORD*)(GameModule + offset.dwGlowObjectManager);
	value.LocalTeam = *(int*)(value.LocalPlayer + offset.m_iTeamNum);

	for (int i = 0; i < 32; i++)
	{
		value.Entity = *(int*)(GameModule + offset.dwEntityList + i * 0x10);
		if (!value.Entity)
			continue;
		value.Dormant = *(bool*)(value.Entity + offset.m_bDormant);
		int GlowIndex = *(int*)(value.Entity + offset.m_iGlowIndex);
		value.EntityTeam = *(int*)(value.Entity + offset.m_iTeamNum);
		value.EntityHP = *(int*)(value.Entity + offset.m_iHealth);
		bool Defusing = *(bool*)(value.Entity + offset.m_bIsDefusing);

		if (!value.Entity || value.Dormant || !value.EntityTeam || !value.EntityHP)
			continue;

		if (value.LocalTeam != value.EntityTeam)
			switch (value.EntityTeam) // 1 GoTV; 2 T; 3 CT
			{
			case 2:
				SetTGlow(GlowIndex);
				break;
			case 3:
				SetCTGlow(GlowIndex);
				break;
			}
		if (Defusing)
			SetDGlow(GlowIndex);
	}
}