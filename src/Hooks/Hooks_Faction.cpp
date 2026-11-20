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

static Platoon* (*Faction_createNewEmptyUnloadedPlatoon_orig)(Faction*, GameData*, const Ogre::Vector3&, GameDataContainer*, bool) = NULL;
static Platoon* Faction_createNewEmptyUnloadedPlatoon_hook(Faction* thisptr, GameData* squadTemplate, const Ogre::Vector3& pos, GameDataContainer* forcecharacterDatas, bool persistent)
{
    Platoon* platoon = Faction_createNewEmptyUnloadedPlatoon_orig(thisptr, squadTemplate, pos, forcecharacterDatas, persistent);
    CallFactionUnloadedPlatoonCreatedCallbacks(thisptr, squadTemplate, pos, forcecharacterDatas, persistent, platoon);
    return platoon;
}
DEFINE_HOOK_INSTALLER(InstallHook_Faction_createNewEmptyUnloadedPlatoon,
    "Faction::createNewEmptyUnloadedPlatoon",
    KenshiLib::GetRealAddress(&Faction::createNewEmptyUnloadedPlatoon),
    Faction_createNewEmptyUnloadedPlatoon_hook, Faction_createNewEmptyUnloadedPlatoon_orig)

static void (*Faction_restorePlatoon_orig)(Faction*, Platoon*) = NULL;
static void Faction_restorePlatoon_hook(Faction* thisptr, Platoon* platoon)
{
    Faction_restorePlatoon_orig(thisptr, platoon);
    CallFactionPlatoonRestoredCallbacks(thisptr, platoon);
}
DEFINE_HOOK_INSTALLER(InstallHook_Faction_restorePlatoon,
    "Faction::restorePlatoon",
    KenshiLib::GetRealAddress(&Faction::restorePlatoon),
    Faction_restorePlatoon_hook, Faction_restorePlatoon_orig)

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

static void (*Faction_removePlatoon_orig)(Faction*, Platoon*) = NULL;
static void Faction_removePlatoon_hook(Faction* thisptr, Platoon* platoon)
{
    Faction_removePlatoon_orig(thisptr, platoon);
    CallFactionPlatoonRemovedCallbacks(thisptr, platoon);
}
DEFINE_HOOK_INSTALLER(InstallHook_Faction_removePlatoon,
    "Faction::removePlatoon",
    KenshiLib::GetRealAddress(&Faction::removePlatoon),
    Faction_removePlatoon_hook, Faction_removePlatoon_orig)

static bool (*Faction_NV_addActiveObject_orig)(Faction*, RootObject*, ActivePlatoon*) = NULL;
static bool Faction_NV_addActiveObject_hook(Faction* thisptr, RootObject* object, ActivePlatoon* platoon)
{
    bool success = Faction_NV_addActiveObject_orig(thisptr, object, platoon);
    CallFactionActiveObjectAddedCallbacks(thisptr, object, platoon, success);
    return success;
}
DEFINE_HOOK_INSTALLER(InstallHook_Faction_NV_addActiveObject,
    "Faction::_NV_addActiveObject",
    KenshiLib::GetRealAddress(&Faction::_NV_addActiveObject),
    Faction_NV_addActiveObject_hook, Faction_NV_addActiveObject_orig)

static void (*Faction_NV_removeObject_orig)(Faction*, RootObject*) = NULL;
static void Faction_NV_removeObject_hook(Faction* thisptr, RootObject* object)
{
    Faction_NV_removeObject_orig(thisptr, object);
    CallFactionObjectRemovedCallbacks(thisptr, object);
}
DEFINE_HOOK_INSTALLER(InstallHook_Faction_NV_removeObject,
    "Faction::_NV_removeObject",
    KenshiLib::GetRealAddress(&Faction::_NV_removeObject),
    Faction_NV_removeObject_hook, Faction_NV_removeObject_orig)

static void (*Faction_NV_destroyObject_orig)(Faction*, RootObject*) = NULL;
static void Faction_NV_destroyObject_hook(Faction* thisptr, RootObject* object)
{
    Faction_NV_destroyObject_orig(thisptr, object);
    CallFactionObjectDestroyedCallbacks(thisptr, object);
}
DEFINE_HOOK_INSTALLER(InstallHook_Faction_NV_destroyObject,
    "Faction::_NV_destroyObject",
    KenshiLib::GetRealAddress(&Faction::_NV_destroyObject),
    Faction_NV_destroyObject_hook, Faction_NV_destroyObject_orig)

static void (*Faction_setName_orig)(Faction*, const std::string&) = NULL;
static void Faction_setName_hook(Faction* thisptr, const std::string& name)
{
    Faction_setName_orig(thisptr, name);
    CallFactionNameChangedCallbacks(thisptr, name);
}
DEFINE_HOOK_INSTALLER(InstallHook_Faction_setName,
    "Faction::setName",
    KenshiLib::GetRealAddress(&Faction::setName),
    Faction_setName_hook, Faction_setName_orig)

static void (*Faction_setup3_orig)(Faction*) = NULL;
static void Faction_setup3_hook(Faction* thisptr)
{
    Faction_setup3_orig(thisptr);
    CallFactionSetupCompletedCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_Faction_setup3,
    "Faction::setup3",
    KenshiLib::GetRealAddress(&Faction::setup3),
    Faction_setup3_hook, Faction_setup3_orig)

static void (*Faction_loadState_orig)(Faction*, GameDataContainer*, GameData*) = NULL;
static void Faction_loadState_hook(Faction* thisptr, GameDataContainer* saveSource, GameData* factionState)
{
    Faction_loadState_orig(thisptr, saveSource, factionState);
    CallFactionStateLoadedCallbacks(thisptr, saveSource, factionState);
}
DEFINE_HOOK_INSTALLER(InstallHook_Faction_loadState,
    "Faction::loadState",
    KenshiLib::GetRealAddress(&Faction::loadState),
    Faction_loadState_hook, Faction_loadState_orig)

static FactionManager* (*FactionManager_CONSTRUCTOR_orig)(FactionManager*) = NULL;
static FactionManager* FactionManager_CONSTRUCTOR_hook(FactionManager* thisptr)
{
    FactionManager* res = FactionManager_CONSTRUCTOR_orig(thisptr);
    FactionManager* overrideRes = CallFactionManagerConstructedCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionManager_CONSTRUCTOR,
    "FactionManager::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&FactionManager::_CONSTRUCTOR),
    FactionManager_CONSTRUCTOR_hook, FactionManager_CONSTRUCTOR_orig)

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
