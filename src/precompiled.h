#pragma once

#define WIN32_MEAN_AND_LEAN
#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdio.h>
#include <time.h>

#include "shared/hlsdk/dlls/extdll.h"

#include "shared/hlsdk/cl_dll/wrect.h"
#include "shared/hlsdk/cl_dll/cl_dll.h"

#include "shared/hlsdk/common/const.h"
#include "shared/hlsdk/engine/APIProxy.h"
#include "shared/hlsdk/engine/eiface.h"

#include "shared/hlsdk/pm_shared/pm_defs.h"
#include "shared/hlsdk/extended/basetypes.h"
#include "shared/hlsdk/extended/server_static.h"

#include "public/opcode_len_calc.h"
#include "common/Memory.h"
#include "common/SimpleList.h"
#include "common/Common.h"

struct client_static_t
{
	cactive_t state;

	// TODO: Complete struct
};

#include "Lists.h"

#include "CoFSDK.h"

#include "Global.h"

#define EXPORT extern "C" __declspec(dllexport)