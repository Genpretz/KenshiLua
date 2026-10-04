#include "pch.h"
#include "Hooks_Common.h"

#include <kenshi/ZoneManager.h>

static ZoneMap* (*ZoneMap_CONSTRUCTOR_orig)(ZoneMap*) = NULL;
static ZoneMap* ZoneMap_CONSTRUCTOR_hook(ZoneMap* thisptr)
{
    ZoneMap* res = ZoneMap_CONSTRUCTOR_orig(thisptr);
    ZoneMap* overrideRes = CallZoneMapConstructedCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ZoneMap_CONSTRUCTOR,
    "ZoneMap::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&ZoneMap::_CONSTRUCTOR),
    ZoneMap_CONSTRUCTOR_hook, ZoneMap_CONSTRUCTOR_orig)

static ZoneManager* (*ZoneManager_CONSTRUCTOR_orig)(ZoneManager*) = NULL;
static ZoneManager* ZoneManager_CONSTRUCTOR_hook(ZoneManager* thisptr)
{
    ZoneManager* res = ZoneManager_CONSTRUCTOR_orig(thisptr);
    ZoneManager* overrideRes = CallZoneManagerConstructedCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ZoneManager_CONSTRUCTOR,
    "ZoneManager::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&ZoneManager::_CONSTRUCTOR),
    ZoneManager_CONSTRUCTOR_hook, ZoneManager_CONSTRUCTOR_orig)
