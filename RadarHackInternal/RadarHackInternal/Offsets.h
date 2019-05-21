#pragma once
#include <Windows.h>

// 2019-05-17 09:28:31.378496100 UTC

struct gameOffsets
{
	//netvars
	DWORD cs_gamerules_data = 0x0;
	DWORD m_ArmorValue = 0xB340;
	DWORD m_Collision = 0x31C;
	DWORD m_CollisionGroup = 0x474;
	DWORD m_Local = 0x2FBC;
	DWORD m_MoveType = 0x25C;
	DWORD m_OriginalOwnerXuidHigh = 0x31B4;
	DWORD m_OriginalOwnerXuidLow = 0x31B0;
	DWORD m_SurvivalGameRuleDecisionTypes = 0x1320;
	DWORD m_SurvivalRules = 0xCF8;
	DWORD m_aimPunchAngle = 0x302C;
	DWORD m_aimPunchAngleVel = 0x3038;
	DWORD m_angEyeAnglesX = 0xB344;
	DWORD m_angEyeAnglesY = 0xB348;
	DWORD m_bBombPlanted = 0x99D;
	DWORD m_bFreezePeriod = 0x20;
	DWORD m_bGunGameImmunity = 0x392C;
	DWORD m_bHasDefuser = 0xB350;
	DWORD m_bHasHelmet = 0xB334;
	DWORD m_bInReload = 0x3285;
	DWORD m_bIsDefusing = 0x3918;
	DWORD m_bIsQueuedMatchmaking = 0x74;
	DWORD m_bIsScoped = 0x3910;
	DWORD m_bIsValveDS = 0x75;
	DWORD m_bSpotted = 0x93D;
	DWORD m_bSpottedByMask = 0x980;
	DWORD m_bStartedArming = 0x33D0;
	DWORD m_clrRender = 0x70;
	DWORD m_dwBoneMatrix = 0x26A8;
	DWORD m_fAccuracyPenalty = 0x3310;
	DWORD m_fFlags = 0x104;
	DWORD m_flC4Blow = 0x2990;
	DWORD m_flDefuseCountDown = 0x29AC;
	DWORD m_flDefuseLength = 0x29A8;
	DWORD m_flFallbackWear = 0x31C0;
	DWORD m_flFlashDuration = 0xA3F4;
	DWORD m_flFlashMaxAlpha = 0xA3F0;
	DWORD m_flLastBoneSetupTime = 0x2924;
	DWORD m_flLowerBodyYawTarget = 0x3A78;
	DWORD m_flNextAttack = 0x2D70;
	DWORD m_flNextPrimaryAttack = 0x3218;
	DWORD m_flSimulationTime = 0x268;
	DWORD m_flTimerLength = 0x2994;
	DWORD m_hActiveWeapon = 0x2EF8;
	DWORD m_hMyWeapons = 0x2DF8;
	DWORD m_hObserverTarget = 0x3388;
	DWORD m_hOwner = 0x29CC;
	DWORD m_hOwnerEntity = 0x14C;
	DWORD m_iAccountID = 0x2FC8;
	DWORD m_iClip1 = 0x3244;
	DWORD m_iCompetitiveRanking = 0x1A84;
	DWORD m_iCompetitiveWins = 0x1B88;
	DWORD m_iCrosshairId = 0xB3AC;
	DWORD m_iEntityQuality = 0x2FAC;
	DWORD m_iFOV = 0x31E4;
	DWORD m_iFOVStart = 0x31E8;
	DWORD m_iGlowIndex = 0xA40C;
	DWORD m_iHealth = 0x100;
	DWORD m_iItemDefinitionIndex = 0x2FAA;
	DWORD m_iItemIDHigh = 0x2FC0;
	DWORD m_iMostRecentModelBoneCounter = 0x2690;
	DWORD m_iObserverMode = 0x3374;
	DWORD m_iShotsFired = 0xA380;
	DWORD m_iState = 0x3238;
	DWORD m_iTeamNum = 0xF4;
	DWORD m_lifeState = 0x25F;
	DWORD m_nFallbackPaintKit = 0x31B8;
	DWORD m_nFallbackSeed = 0x31BC;
	DWORD m_nFallbackStatTrak = 0x31C4;
	DWORD m_nForceBone = 0x268C;
	DWORD m_nTickBase = 0x342C;
	DWORD m_rgflCoordinateFrame = 0x444;
	DWORD m_szCustomName = 0x303C;
	DWORD m_szLastPlaceName = 0x35B0;
	DWORD m_thirdPersonViewAngles = 0x31D8;
	DWORD m_vecOrigin = 0x138;
	DWORD m_vecVelocity = 0x114;
	DWORD m_vecViewOffset = 0x108;
	DWORD m_viewPunchAngle = 0x3020;

	//signatures
	DWORD clientstate_choked_commands = 0x4D28;
	DWORD clientstate_delta_ticks = 0x174;
	DWORD clientstate_last_outgoing_command = 0x4D24;
	DWORD clientstate_net_channel = 0x9C;
	DWORD convar_name_hash_table = 0x2F0F8;
	DWORD dwClientState = 0x58BCFC;
	DWORD dwClientState_GetLocalPlayer = 0x180;
	DWORD dwClientState_IsHLTV = 0x4D40;
	DWORD dwClientState_Map = 0x28C;
	DWORD dwClientState_MapDirectory = 0x188;
	DWORD dwClientState_MaxPlayer = 0x388;
	DWORD dwClientState_PlayerInfo = 0x52B8;
	DWORD dwClientState_State = 0x108;
	DWORD dwClientState_ViewAngles = 0x4D88;
	DWORD dwEntityList = 0x4D03AE4;
	DWORD dwForceAttack = 0x31351DC;
	DWORD dwForceAttack2 = 0x31351E8;
	DWORD dwForceBackward = 0x3135194;
	DWORD dwForceForward = 0x3135200;
	DWORD dwForceJump = 0x51A7050;
	DWORD dwForceLeft = 0x3135188;
	DWORD dwForceRight = 0x31351AC;
	DWORD dwGameDir = 0x631F70;
	DWORD dwGameRulesProxy = 0x521939C;
	DWORD dwGetAllClasses = 0xD1698C;
	DWORD dwGlobalVars = 0x58BA00;
	DWORD dwGlowObjectManager = 0x5243EB0;
	DWORD dwInput = 0x514EB30;
	DWORD dwInterfaceLinkList = 0x8C7DE4;
	DWORD dwLocalPlayer = 0xCF1A3C;
	DWORD dwMouseEnable = 0xCF7588;
	DWORD dwMouseEnablePtr = 0xCF7558;
	DWORD dwPlayerResource = 0x313352C;
	DWORD dwRadarBase = 0x5138844;
	DWORD dwSensitivity = 0xCF7424;
	DWORD dwSensitivityPtr = 0xCF73F8;
	DWORD dwSetClanTag = 0x896A0;
	DWORD dwViewMatrix = 0x4CF5514;
	DWORD dwWeaponTable = 0x514F5F4;
	DWORD dwWeaponTableIndex = 0x323C;
	DWORD dwYawPtr = 0xCF71E8;
	DWORD dwZoomSensitivityRatioPtr = 0xCFC428;
	DWORD dwbSendPackets = 0xD277A;
	DWORD dwppDirect3DDevice9 = 0xA6030;
	DWORD force_update_spectator_glow = 0x393652;
	DWORD interface_engine_cvar = 0x3E9EC;
	DWORD is_c4_owner = 0x39F980;
	DWORD m_bDormant = 0xED;
	DWORD m_pStudioHdr = 0x294C;
	DWORD m_pitchClassPtr = 0x5138AF0;
	DWORD m_yawClassPtr = 0xCF71E8;
	DWORD model_ambient_min = 0x58ED1C;
	DWORD set_abs_angles = 0x1CA9B0;
	DWORD set_abs_origin = 0x1CA7F0;
}offset;

DWORD GameModule = (DWORD)GetModuleHandle("client_panorama.dll");

struct values
{
	DWORD LocalPlayer;
	DWORD Entity;
}value;