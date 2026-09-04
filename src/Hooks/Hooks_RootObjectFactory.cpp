#include "pch.h"
#include "Hooks_Common.h"

// ---------------------------------------------------------------------------
// Hooks for RootObjectFactory.h
// ---------------------------------------------------------------------------

static void (*RootObjectFactory_chooseMyClothing_orig)(lektor<GameData*>&, GameData*, const std::string&, RaceData*, bool) = NULL;
static void RootObjectFactory_chooseMyClothing_hook(lektor<GameData*>& gear, GameData* dataList, const std::string& listName, RaceData* race, bool noShoes)
{
    RootObjectFactory_chooseMyClothing_orig(gear, dataList, listName, race, noShoes);
    CallChooseMyClothingCallbacks(gear, dataList, listName, race, noShoes);
}
DEFINE_HOOK_INSTALLER(InstallHook_RootObjectFactory_chooseMyClothing,
    "RootObjectFactory::chooseMyClothing",
    KenshiLib::GetRealAddress(&RootObjectFactory::chooseMyClothing),
    RootObjectFactory_chooseMyClothing_hook, RootObjectFactory_chooseMyClothing_orig)
