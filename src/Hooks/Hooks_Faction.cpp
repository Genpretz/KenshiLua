#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/FactionLeader.h>
#include <kenshi/FactionUniqueSquadManager.h>

// ---------------------------------------------------------------------------
// Hooks for Faction.h
// ---------------------------------------------------------------------------

static GameData* (*Faction_chooseARace_orig)(Faction*, GameData*, GameData*) = NULL;
static GameData* Faction_chooseARace_hook(Faction* thisptr, GameData* character, GameData* squadTemplate)
{
    GameData* current = Faction_chooseARace_orig(thisptr, character, squadTemplate);
    return CallFactionChooseARaceCallbacks(thisptr, character, squadTemplate, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_Faction_chooseARace,
    "Faction::chooseARace",
    KenshiLib::GetRealAddress(&Faction::chooseARace),
    Faction_chooseARace_hook, Faction_chooseARace_orig)

static GameData* (*Faction_getBuildingReplacement_orig)(Faction*, GameData*) = NULL;
static GameData* Faction_getBuildingReplacement_hook(Faction* thisptr, GameData* building)
{
    GameData* current = Faction_getBuildingReplacement_orig(thisptr, building);
    return CallFactionGetBuildingReplacementCallbacks(thisptr, building, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_Faction_getBuildingReplacement,
    "Faction::getBuildingReplacement",
    KenshiLib::GetRealAddress(&Faction::getBuildingReplacement),
    Faction_getBuildingReplacement_hook, Faction_getBuildingReplacement_orig)

static Platoon* (*Faction_createNewEmptyActivePlatoon_orig)(Faction*, GameData*, bool, const Ogre::Vector3&) = NULL;
static Platoon* Faction_createNewEmptyActivePlatoon_hook(Faction* thisptr, GameData* squadTemplate, bool permanent, const Ogre::Vector3& p)
{
    Platoon* platoon = Faction_createNewEmptyActivePlatoon_orig(thisptr, squadTemplate, permanent, p);
    CallFactionActivePlatoonCreatedCallbacks(thisptr, platoon);
    return platoon;
}
DEFINE_HOOK_INSTALLER(InstallHook_Faction_createNewEmptyActivePlatoon,
    "Faction::createNewEmptyActivePlatoon",
    KenshiLib::GetRealAddress(&Faction::createNewEmptyActivePlatoon),
    Faction_createNewEmptyActivePlatoon_hook, Faction_createNewEmptyActivePlatoon_orig)

static void (*Faction_destroyPlatoon_orig)(Faction*, Platoon*) = NULL;
static void Faction_destroyPlatoon_hook(Faction* thisptr, Platoon* platoon)
{
    Faction_destroyPlatoon_orig(thisptr, platoon);
    CallFactionPlatoonDestroyedCallbacks(thisptr, platoon);
}
DEFINE_HOOK_INSTALLER(InstallHook_Faction_destroyPlatoon,
    "Faction::destroyPlatoon",
    KenshiLib::GetRealAddress(&Faction::destroyPlatoon),
    Faction_destroyPlatoon_hook, Faction_destroyPlatoon_orig)

static Faction* (*Faction_CONSTRUCTOR_orig)(Faction*, const std::string&) = NULL;
static Faction* Faction_CONSTRUCTOR_hook(Faction* thisptr, const std::string& _name)
{
    Faction* res = Faction_CONSTRUCTOR_orig(thisptr, _name);
    Faction* overrideRes = CallFactionConstructedCallbacks(thisptr, _name, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Faction_CONSTRUCTOR,
    "Faction::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&Faction::_CONSTRUCTOR),
    Faction_CONSTRUCTOR_hook, Faction_CONSTRUCTOR_orig)

static FactionLeader* (*FactionLeader_CONSTRUCTOR_orig)(FactionLeader*, Faction*) = NULL;
static FactionLeader* FactionLeader_CONSTRUCTOR_hook(FactionLeader* thisptr, Faction* f)
{
    FactionLeader* res = FactionLeader_CONSTRUCTOR_orig(thisptr, f);
    FactionLeader* overrideRes = CallFactionLeaderConstructedCallbacks(thisptr, f, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionLeader_CONSTRUCTOR,
    "FactionLeader::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&FactionLeader::_CONSTRUCTOR),
    FactionLeader_CONSTRUCTOR_hook, FactionLeader_CONSTRUCTOR_orig)

static FactionUniqueSquadManager* (*FactionUniqueSquadManager_CONSTRUCTOR_orig)(FactionUniqueSquadManager*) = NULL;
static FactionUniqueSquadManager* FactionUniqueSquadManager_CONSTRUCTOR_hook(FactionUniqueSquadManager* thisptr)
{
    FactionUniqueSquadManager* res = FactionUniqueSquadManager_CONSTRUCTOR_orig(thisptr);
    FactionUniqueSquadManager* overrideRes = CallFactionUniqueSquadManagerConstructedCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionUniqueSquadManager_CONSTRUCTOR,
    "FactionUniqueSquadManager::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&FactionUniqueSquadManager::_CONSTRUCTOR),
    FactionUniqueSquadManager_CONSTRUCTOR_hook, FactionUniqueSquadManager_CONSTRUCTOR_orig)

static ProsperityManager* (*ProsperityManager_CONSTRUCTOR_orig)(ProsperityManager*) = NULL;
static ProsperityManager* ProsperityManager_CONSTRUCTOR_hook(ProsperityManager* thisptr)
{
    ProsperityManager* res = ProsperityManager_CONSTRUCTOR_orig(thisptr);
    ProsperityManager* overrideRes = CallProsperityManagerConstructedCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ProsperityManager_CONSTRUCTOR,
    "ProsperityManager::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&ProsperityManager::_CONSTRUCTOR),
    ProsperityManager_CONSTRUCTOR_hook, ProsperityManager_CONSTRUCTOR_orig)

