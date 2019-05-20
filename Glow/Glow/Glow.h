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
	DGlow = mem.Read<GlowStruct>(value.GlowObject + (GlowIndex * 0x38));

	DGlow.red = 1.0f;
	DGlow.green = 1.0f;
	DGlow.blue = 1.0f;
	DGlow.alpha = 1.0f;
	DGlow.occluded = true;
	DGlow.unoccluded = false;

	mem.Write<GlowStruct>(value.GlowObject + (GlowIndex * 0x38), DGlow);
}

void SetTGlow(int GlowIndex)
{
	GlowStruct TGlow;
	TGlow = mem.Read<GlowStruct>(value.GlowObject + (GlowIndex * 0x38));

	TGlow.red = 1.0f;
	TGlow.green = 0.15f;
	TGlow.alpha = 1.0f;
	TGlow.occluded = true;
	TGlow.unoccluded = false;

	mem.Write<GlowStruct>(value.GlowObject + (GlowIndex * 0x38), TGlow);
}

void SetCTGlow(int GlowIndex)
{
	GlowStruct CTGlow;
	CTGlow = mem.Read<GlowStruct>(value.GlowObject + (GlowIndex * 0x38));

	CTGlow.blue = 0.8f;
	CTGlow.alpha = 1.0f;
	CTGlow.occluded = true;
	CTGlow.unoccluded = false;

	mem.Write<GlowStruct>(value.GlowObject + (GlowIndex * 0x38), CTGlow);
}

void Glow()
{
	value.GlowObject = mem.Read<DWORD>(GameModule.dwBase + offset.dwGlowObjectManager);
	value.LocalTeam = mem.Read<int>(value.LocalPlayer + offset.m_iTeamNum);

	for (int i = 0; i < 32; i++)
	{
		value.Entity = mem.Read<int>(GameModule.dwBase + offset.dwEntityList + i * 0x10);
		if (!value.Entity)
			continue;
		value.Dormant = mem.Read<bool>(value.Entity + offset.m_bDormant);
		int GlowIndex = mem.Read<int>(value.Entity + offset.m_iGlowIndex);
		value.EntityTeam = mem.Read<int>(value.Entity + offset.m_iTeamNum);
		value.EntityHP = mem.Read<int>(value.Entity + offset.m_iHealth);
		bool Defusing = mem.Read<bool>(value.Entity + offset.m_bIsDefusing);

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