#pragma once

extern char *gConfigName;

class CSimpleMonsterList : public CSimpleList
{
private:
	const char *m_DefaultMonsterNames[23] =
	{
		"monster_child",
		"monster_crab",
		"monster_crazybitch",
		"monster_faceless",
		"monster_facelessv",
		"monster_faster",
		//"monster_krypande", // Crawler, crash?
		"monster_nerd",
		"monster_rcrazy",
		//"monster_roofboss", // Carcass, crash?
		"monster_ruben",
		"monster_sawrunner",
		//"monster_sewerboss", // Mace, Can't be killed
		"monster_sewmo",
		"monster_slower",
		"monster_slower3",
		"monster_slowerstuck",
		//"monster_spitter", // Looks weird outside train
		"monster_stranger",
		"monster_suicider",
		"monster_taller",
		"monster_twitcher",
		"monster_twitcher2",
		"monster_twitcher3",
		"monster_twitcher4",
		"monster_watro",
		"monster_zombie",
	};

private:
	bool m_bEnabled;

	bool m_bAllowBookSimon;
	bool m_bAllowBookSimonHammer;
	bool m_bAllowDoctor;
	bool m_bAllowBossChainsaw;
	bool m_bAllowSawCrazy;
	bool m_bAllowDefault;

	void LoadConfig();

public:
	CSimpleMonsterList()
	{
		m_bEnabled = false;

		m_bAllowBookSimon = false;
		m_bAllowBookSimonHammer = false;
		m_bAllowDoctor = false;
		m_bAllowBossChainsaw = false;
		m_bAllowSawCrazy = false;
		m_bAllowDefault = false;
	}

	void Init();

	bool getEnabled()
	{
		return m_bEnabled;
	}
};

class CSimpleWeaponList : public CSimpleList
{
private:
	const char *m_DefaultWeaponNames[25] =
	{
		"weapon_P228",
		"weapon_axe",
		"weapon_beretta",
		"weapon_branch",
		"weapon_camera",
		"weapon_famas",
		"weapon_flare",
		"weapon_flashlight",
		"weapon_g43",
		"weapon_glock",
		"weapon_lantern",
		"weapon_m16",
		"weapon_mobile",
		"weapon_nightstick",
		"weapon_p345",
		"weapon_revolver",
		"weapon_rifle",
		"weapon_shotgun",
		"weapon_sledgehammer",
		"weapon_switchblade",
		"weapon_syringe",
		"weapon_vp70",
	};

	const char *m_PrivilegedWeaponNames[2] =
	{
		"weapon_tmp",
		"weapon_mp5",
	};

	const char *m_RestrictedWeaponNames[2] =
	{
		//"weapon_action",
		"weapon_mobile",
	};
private:
	bool m_bEnabled;

	bool m_bAllowBrowningPistol;
	bool m_bAllowBookLaser;
	bool m_bAllowPrivilegedWeapons;
	bool m_bAllowRestrictedWeapons;
	bool m_bReplaceSyringes;

	void LoadConfig();

public:
	CSimpleWeaponList()
	{
		m_bEnabled = false;

		m_bAllowBrowningPistol = false;
		m_bAllowBookLaser = false;
		m_bAllowPrivilegedWeapons = false;
		m_bAllowRestrictedWeapons = false;
	}

	void Init();

	bool getEnabled() { return m_bEnabled; }
	bool getReplaceSyringes() { return m_bReplaceSyringes; }
};

class CSimpleItemList : public CSimpleList
{
private:
	bool m_bEnabled;

	void LoadConfig();

public:
	CSimpleItemList()
	{
		m_bEnabled = false;
	}

	void Init();

	bool Enabled()
	{
		return m_bEnabled;
	}
};
