#include "pch.h"
#include "Hooks_Common.h"

// ---------------------------------------------------------------------------
// Hooks for Town.h
// ---------------------------------------------------------------------------

static void (*Town_NV_loadFromSerialise_orig)(Town*, GameSaveState*) = NULL;
static void Town_NV_loadFromSerialise_hook(Town* thisptr, GameSaveState* state)
{
    Town_NV_loadFromSerialise_orig(thisptr, state);
    CallTownLoadFromSerialiseCallbacks(thisptr, state);
}
DEFINE_HOOK_INSTALLER(InstallHook_Town_NV_loadFromSerialise,
    "Town::_NV_loadFromSerialise",
    KenshiLib::GetRealAddress(&Town::_NV_loadFromSerialise),
    Town_NV_loadFromSerialise_hook, Town_NV_loadFromSerialise_orig)

static Town* (*Town_CONSTRUCTOR_orig)(Town*, GameData*) = NULL;
static Town* Town_CONSTRUCTOR_hook(Town* thisptr, GameData* d)
{
    Town* res = Town_CONSTRUCTOR_orig(thisptr, d);
    Town* overrideRes = CallTownConstructedCallbacks(thisptr, d, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Town_CONSTRUCTOR,
    "Town::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&Town::_CONSTRUCTOR),
    Town_CONSTRUCTOR_hook, Town_CONSTRUCTOR_orig)

static TownBase* (*TownBase_CONSTRUCTOR_orig)(TownBase*, GameData*) = NULL;
static TownBase* TownBase_CONSTRUCTOR_hook(TownBase* thisptr, GameData* d)
{
    TownBase* res = TownBase_CONSTRUCTOR_orig(thisptr, d);
    TownBase* overrideRes = CallTownBaseConstructedCallbacks(thisptr, d, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_TownBase_CONSTRUCTOR,
    "TownBase::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&TownBase::_CONSTRUCTOR),
    TownBase_CONSTRUCTOR_hook, TownBase_CONSTRUCTOR_orig)

