#include "pch.h"
#include "Hooks_Common.h"

#include <kenshi/GameData.h>

static GameData* (*GameData_CONSTRUCTOR_orig)(GameData*) = NULL;
static GameData* GameData_CONSTRUCTOR_hook(GameData* thisptr)
{
    GameData* res = GameData_CONSTRUCTOR_orig(thisptr);
    GameData* overrideRes = CallGameDataConstructedCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_GameData_CONSTRUCTOR,
    "GameData::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&GameData::_CONSTRUCTOR),
    GameData_CONSTRUCTOR_hook, GameData_CONSTRUCTOR_orig)
