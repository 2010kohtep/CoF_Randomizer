#include "precompiled.h"

cl_enginefunc_t *pEngine;
DLL_FUNCTIONS *pgEntityInterface;

char gszExeDir[MAX_PATH];

plugin_info_t gPluginInfo =
{
	"CoF Randomizer",
	"Randomize monster and weapon spawn.",
	"https://github.com/2010kohtep/",

	1,
	0,

	0,
};

void hkKeyValue(edict_t *pentKeyvalue, KeyValueData *pkvd)
{
	if (gMonsterList.getEnabled() && IsMonster(pkvd->szValue))
	{
		const char *s = gMonsterList.PickRandomString();

		if (!s)
		{
			pentKeyvalue->free = true;
			return;
		}

		pEngine->Con_DPrintf(__FUNCTION__ ": Replacing monster %s with %s\n", pkvd->szValue, s);

		strcpy(pkvd->szValue, s);
	}
	else if (gItemList.Enabled() && IsItem(pkvd->szValue))
	{
		// Not implemented
	}
	else if (gWeaponList.getEnabled() && IsWeapon(pkvd->szValue))
	{
		if (!gWeaponList.getReplaceSyringes() && IsSyringe(pkvd->szValue))
		{
			pgEntityInterface->pfnKeyValue(pentKeyvalue, pkvd);
			return;
		}

		const char *s = gWeaponList.PickRandomString();

		if (!s)
		{
			pentKeyvalue->free = true;
			return;
		}

		pEngine->Con_DPrintf(__FUNCTION__ ": Replacing weapon %s with %s\n", pkvd->szValue, s);

		strcpy(pkvd->szValue, s);
	}

	pgEntityInterface->pfnKeyValue(pentKeyvalue, pkvd);
}

bool PatchSuckoutClassName()
{
	auto h = GetModuleHandleA("hw.dll");
	if (!h)
		return false;

	auto pfn = Transpose(h, 0xA84EF);
	Fill(pfn, 0x90, 6);
	WriteCall(pfn, hkKeyValue);

	return true;
}

EXPORT bool Init(int nVerMajor, int nVerMinor)
{
	srand(time(NULL));

	if (!PatchSuckoutClassName())
		return false;

	gMonsterList.Init();
	gWeaponList.Init();
	gItemList.Init();

	return true;
}

EXPORT void GetPluginInfo(plugin_info_t **info)
{
	*info = &gPluginInfo;
}

EXPORT void GetGameVars(cof_data_t *cofdata)
{
	pEngine = cofdata->pcl_enginefuncs;
	pgEntityInterface = cofdata->p_entityInterface;
}

BOOL WINAPI DllMain(_In_ HINSTANCE hinstDLL, _In_ DWORD fdwReason, _In_ LPVOID lpvReserved)
{
	return TRUE;
}