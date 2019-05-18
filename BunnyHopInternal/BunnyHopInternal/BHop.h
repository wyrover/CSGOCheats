struct vector
{
	float x, y, z;
};

bool IsPlayerMoving()
{
	vector PlayerVelocity = *(vector*)(value.LocalPlayer + offset.m_vecVelocity);
	int Velocity = PlayerVelocity.x + PlayerVelocity.y + PlayerVelocity.z;
	if (Velocity)
		return true;
	else
		return false;
}

bool IsMouseActive()
{
	BYTE MouseActivity = *(BYTE*)(GameModule + offset.dwMouseEnable);

	if (MouseActivity == 'Y')
		return true;
	else
		return false;
}

void BunnyHop()
{
	if (GetAsyncKeyState(VK_SPACE))
	if (IsPlayerMoving())
	if (IsMouseActive())
	{
		value.Flag = *(BYTE*)(value.LocalPlayer + offset.m_fFlags);
		*(DWORD*)(GameModule + offset.dwForceJump) = (value.Flag & (1 << 0) ? 5 : 4);
	}
}