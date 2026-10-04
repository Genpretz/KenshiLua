#include "pch.h"
#include "Hooks_Common.h"

#include <kenshi/WorldEventStateQuery.h>

static WorldEventStateQuery* (*WorldEventStateQuery_CONSTRUCTOR_orig)(WorldEventStateQuery*) = NULL;
static WorldEventStateQuery* WorldEventStateQuery_CONSTRUCTOR_hook(WorldEventStateQuery* thisptr)
{
    WorldEventStateQuery* res = WorldEventStateQuery_CONSTRUCTOR_orig(thisptr);
    WorldEventStateQuery* overrideRes = CallWorldEventStateQueryConstructedCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_WorldEventStateQuery_CONSTRUCTOR,
    "WorldEventStateQuery::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&WorldEventStateQuery::_CONSTRUCTOR),
    WorldEventStateQuery_CONSTRUCTOR_hook, WorldEventStateQuery_CONSTRUCTOR_orig)
