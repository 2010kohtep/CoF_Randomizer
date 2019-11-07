#pragma once

BOOL GetPrivateProfileBoolean(LPCSTR lpAppName, LPCSTR lpKeyName, BOOL lpDefault, LPCSTR lpFileName);

bool IsMonster(const char *name);
bool IsItem(const char *name);
bool IsWeapon(const char *name);
bool IsSyringe(const char *name);