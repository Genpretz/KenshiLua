#include "pch.h"
#include "Hooks_Common.h"

#include <kenshi/FactionWarMgr.h>

static FactionWarMgr* (*FactionWarMgr_CONSTRUCTOR_orig)(FactionWarMgr*, Faction*) = NULL;
static FactionWarMgr* FactionWarMgr_CONSTRUCTOR_hook(FactionWarMgr* thisptr, Faction* faction)
{
    FactionWarMgr* res = FactionWarMgr_CONSTRUCTOR_orig(thisptr, faction);
    FactionWarMgr* overrideRes = CallFactionWarMgrConstructedCallbacks(thisptr, faction, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionWarMgr_CONSTRUCTOR,
    "FactionWarMgr::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&FactionWarMgr::_CONSTRUCTOR),
    FactionWarMgr_CONSTRUCTOR_hook, FactionWarMgr_CONSTRUCTOR_orig)
