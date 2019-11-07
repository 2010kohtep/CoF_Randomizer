#include "precompiled.h"

BOOL GetPrivateProfileBoolean(LPCSTR lpAppName, LPCSTR lpKeyName, BOOL lpDefault, LPCSTR lpFileName)
{
	char value[256];

	GetPrivateProfileString(lpAppName, lpKeyName, NULL, value, sizeof(value), lpFileName);

	return !value[0] ? lpDefault : value[0] != '0';
}

bool IsMonster(const char *name)
{
	return name && (!strncmp(name, "monster_", 8) || !strncmp(name, "cof_monster_", 12));
}

bool IsItem(const char *name)
{
	return name && !strncmp(name, "item_", 5);
}

bool IsWeapon(const char *name)
{
	return name && !strncmp(name, "weapon_", 7);
}

bool IsSyringe(const char *name)
{
	return name && !strcmp(name, "weapon_syringe");
}