struct vector
{
	float x, y, z;
};

bool IsPlayerMoving()
{
	vector PlayerVelocity = mem.Read<vector>(value.LocalPlayer + offset.m_vecVelocity);
	int Velocity = PlayerVelocity.x + PlayerVelocity.y + PlayerVelocity.z;

	if (Velocity)
		return true;
	else
		return false;
}

bool IsMouseActive()
{
	BYTE MouseActivity = mem.Read<BYTE>(GameModule.dwBase + offset.dwMouseEnable);

	if (MouseActivity == 'Y')
		return true;
	else
		return false;
}

void BunnyHop()
{
	if(GetAsyncKeyState(VK_SPACE))
	if(IsPlayerMoving())
	if(IsMouseActive())
	{
		value.Flag = mem.Read<BYTE>(value.LocalPlayer + offset.m_fFlags);
		mem.Write<DWORD>(GameModule.dwBase + offset.dwForceJump, (value.Flag & (1 << 0)) ? 5 : 4);
	}
}
