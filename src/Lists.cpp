#include "precompiled.h"

char *gConfigName = "./cryoffear/addons/CoF_Randomizer.ini";

void CSimpleMonsterList::LoadConfig()
{
	m_bEnabled = GetPrivateProfileBoolean("Monsters", "Enable", false, gConfigName);
	m_bAllowBookSimon = GetPrivateProfileBoolean("Monsters", "AllowBookSimon", false, gConfigName);
	m_bAllowBookSimonHammer = GetPrivateProfileBoolean("Monsters", "AllowBookSimonHammer", false, gConfigName);
	m_bAllowDoctor = GetPrivateProfileBoolean("Monsters", "AllowDoctor", false, gConfigName);
	m_bAllowBossChainsaw = GetPrivateProfileBoolean("Monsters", "AllowBossChainsaw", false, gConfigName);
	m_bAllowSawCrazy = GetPrivateProfileBoolean("Monsters", "AllowSawCrazy", false, gConfigName);
	m_bAllowDefault = GetPrivateProfileBoolean("Monsters", "AllowDefault", true, gConfigName);
}

void CSimpleMonsterList::Init()
{
	LoadConfig();

	if (m_bAllowBookSimon)
		AddString("monster_booksimon");

	if (m_bAllowBookSimonHammer)
		AddString("monster_booksimonsledgehammer");

	if (m_bAllowDoctor)
		AddString("monster_doctorboss");

	if (m_bAllowBossChainsaw)
		AddString("monster_bosschainsaw");

	if (m_bAllowSawCrazy)
		AddString("monster_sawcrazy");

	if (m_bAllowDefault)
	{
		for (auto &&name : m_DefaultMonsterNames)
			AddString(name);
	}
}

void CSimpleWeaponList::LoadConfig()
{
	m_bEnabled = GetPrivateProfileBoolean("Weapons", "Enable", false, gConfigName);
	m_bAllowBrowningPistol = GetPrivateProfileBoolean("Weapons", "AllowBrowningPistol", false, gConfigName);
	m_bAllowBookLaser = GetPrivateProfileBoolean("Weapons", "AllowBookLaser", false, gConfigName);
	m_bAllowPrivilegedWeapons = GetPrivateProfileBoolean("Weapons", "AllowPrivilegedWeapons", false, gConfigName);
	m_bAllowRestrictedWeapons = GetPrivateProfileBoolean("Weapons", "AllowRestrictedWeapons", false, gConfigName);
	m_bReplaceSyringes = GetPrivateProfileBoolean("Weapons", "ReplaceSyringes", true, gConfigName);
}

void CSimpleWeaponList::Init()
{
	LoadConfig();

	if (m_bAllowBrowningPistol)
		AddString("weapon_browning_wheelchair");

	if (m_bAllowBookLaser)
		AddString("weapon_booklaser");

	if (m_bAllowPrivilegedWeapons)
	{
		for (auto &&name : m_PrivilegedWeaponNames)
			AddString(name);
	}

	if (m_bAllowRestrictedWeapons)
	{
		for (auto &&name : m_RestrictedWeaponNames)
			AddString(name);
	}

	for (auto &&name : m_DefaultWeaponNames)
		AddString(name);
}

void CSimpleItemList::LoadConfig()
{
	m_bEnabled = GetPrivateProfileBoolean("Items", "Enable", false, gConfigName);
}

void CSimpleItemList::Init()
{
	LoadConfig();
}