#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/Building/Building.h>
#include <kenshi/Building/DoorStuff.h>
#include <kenshi/Building/ProductionBuilding.h>
#include <kenshi/Building/CraftingBuilding.h>
#include <kenshi/Building/FarmBuilding.h>
#include <kenshi/Building/TurretBuilding.h>
#include <kenshi/Building/FurnaceBuilding.h>
#include <kenshi/Building/ResearchBuilding.h>
#include <kenshi/Building/UseableStuff.h>
#include <kenshi/Building/WallBuilding.h>
#include <kenshi/Building/StorageBuilding.h>
#include <kenshi/Building/LightBuilding.h>
#include <kenshi/Building/GeneratorBuilding.h>
#include <kenshi/Building/GatewayBuilding.h>
#include <kenshi/Building/TortureBuilding.h>
#include <kenshi/Building/RainCollectorBuilding.h>
#include <kenshi/Character.h>
#include <kenshi/Damages.h>
#include <kenshi/Gear.h>
#include <kenshi/Item.h>
#include <kenshi/util/UtilityT.h>
#include <kenshi/Faction.h>
#include <kenshi/Platoon.h>
#include <kenshi/GameData.h>

// ---------------------------------------------------------------------------
// Hooks for Building/Building.h
// ---------------------------------------------------------------------------

static bool (*Building_isPublic_orig)(const Building*) = NULL;
static bool Building_isPublic_hook(const Building* thisptr)
{
    bool current = Building_isPublic_orig(thisptr);
    return CallBuildingIsPublicCallbacks(thisptr, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_isPublic,
    "Building::isPublic",
    KenshiLib::GetRealAddress(&Building::isPublic),
    Building_isPublic_hook, Building_isPublic_orig)

static bool (*Building_isForSale_orig)(Building*) = NULL;
static bool Building_isForSale_hook(Building* thisptr)
{
    bool current = Building_isForSale_orig(thisptr);
    return CallBuildingIsForSaleCallbacks(thisptr, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_isForSale,
    "Building::isForSale",
    KenshiLib::GetRealAddress(&Building::isForSale),
    Building_isForSale_hook, Building_isForSale_orig)

static int (*Building_calculateSaleValue_orig)(Building*) = NULL;
static int Building_calculateSaleValue_hook(Building* thisptr)
{
    int current = Building_calculateSaleValue_orig(thisptr);
    return CallBuildingCalculateSaleValueCallbacks(thisptr, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_calculateSaleValue,
    "Building::calculateSaleValue",
    KenshiLib::GetRealAddress(&Building::calculateSaleValue),
    Building_calculateSaleValue_hook, Building_calculateSaleValue_orig)

static void (*Building_NV_onBuildingLoaded_orig)(Building*) = NULL;
static void Building_NV_onBuildingLoaded_hook(Building* thisptr)
{
    Building_NV_onBuildingLoaded_orig(thisptr);
    CallBuildingLoadedCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_NV_onBuildingLoaded,
    "Building::_NV_onBuildingLoaded",
    KenshiLib::GetRealAddress(&Building::_NV_onBuildingLoaded),
    Building_NV_onBuildingLoaded_hook, Building_NV_onBuildingLoaded_orig)

static void (*Building_NV_setBroken_orig)(Building*, bool) = NULL;
static void Building_NV_setBroken_hook(Building* thisptr, bool broken)
{
    Building_NV_setBroken_orig(thisptr, broken);
    CallBuildingBrokenChangedCallbacks(thisptr, broken);
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_NV_setBroken,
    "Building::_NV_setBroken",
    KenshiLib::GetRealAddress(&Building::_NV_setBroken),
    Building_NV_setBroken_hook, Building_NV_setBroken_orig)

static void (*Building_setResidentSquad_orig)(Building*, Platoon*) = NULL;
static void Building_setResidentSquad_hook(Building* thisptr, Platoon* who)
{
    Building_setResidentSquad_orig(thisptr, who);
    CallBuildingSetResidentSquadCallbacks(thisptr, who);
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_setResidentSquad,
    "Building::setResidentSquad",
    KenshiLib::GetRealAddress(&Building::setResidentSquad),
    Building_setResidentSquad_hook, Building_setResidentSquad_orig)

static void (*Building_addAnInternalBuilding_orig)(Building*, Building*) = NULL;
static void Building_addAnInternalBuilding_hook(Building* thisptr, Building* b)
{
    Building_addAnInternalBuilding_orig(thisptr, b);
    CallBuildingAddInternalBuildingCallbacks(thisptr, b);
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_addAnInternalBuilding,
    "Building::addAnInternalBuilding",
    KenshiLib::GetRealAddress(&Building::addAnInternalBuilding),
    Building_addAnInternalBuilding_hook, Building_addAnInternalBuilding_orig)

static GameSaveState (*Building_NV_serialise_orig)(Building*, GameDataContainer*, GameData*, PosRotPair*) = NULL;
static GameSaveState Building_NV_serialise_hook(Building* thisptr, GameDataContainer* container, GameData* refList, PosRotPair* offsetPosToSubtract)
{
    GameSaveState res = Building_NV_serialise_orig(thisptr, container, refList, offsetPosToSubtract);
    CallBuildingSerialiseCallbacks(thisptr, container, refList);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_NV_serialise,
    "Building::_NV_serialise",
    KenshiLib::GetRealAddress(&Building::_NV_serialise),
    Building_NV_serialise_hook, Building_NV_serialise_orig)

static void (*Building_NV_loadFromSerialise_orig)(Building*, GameSaveState*) = NULL;
static void Building_NV_loadFromSerialise_hook(Building* thisptr, GameSaveState* savestate)
{
    Building_NV_loadFromSerialise_orig(thisptr, savestate);
    CallBuildingLoadFromSerialiseCallbacks(thisptr, savestate);
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_NV_loadFromSerialise,
    "Building::_NV_loadFromSerialise",
    KenshiLib::GetRealAddress(&Building::_NV_loadFromSerialise),
    Building_NV_loadFromSerialise_hook, Building_NV_loadFromSerialise_orig)

static void (*Building_NV_buyMeCallback_orig)(Building*, int) = NULL;
static void Building_NV_buyMeCallback_hook(Building* thisptr, int result)
{
    Building_NV_buyMeCallback_orig(thisptr, result);
    CallBuildingBuyMeCallbackCallbacks(thisptr, result);
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_NV_buyMeCallback,
    "Building::_NV_buyMeCallback",
    KenshiLib::GetRealAddress(&Building::_NV_buyMeCallback),
    Building_NV_buyMeCallback_hook, Building_NV_buyMeCallback_orig)

static Building* (*Building_CONSTRUCTOR_orig)(Building*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*) = NULL;
static Building* Building_CONSTRUCTOR_hook(Building* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors)
{
    Building* res = Building_CONSTRUCTOR_orig(thisptr, data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors);
    Building* overrideRes = CallBuildingConstructedCallbacks(thisptr, data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_CONSTRUCTOR,
    "Building::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&Building::_CONSTRUCTOR),
    Building_CONSTRUCTOR_hook, Building_CONSTRUCTOR_orig)

// ---------------------------------------------------------------------------
// Hooks for Ownerships.h
// ---------------------------------------------------------------------------

static bool (*Ownerships_canIUseThisBuilding_orig)(Ownerships*, Building*, Character*) = NULL;
static bool Ownerships_canIUseThisBuilding_hook(Ownerships* thisptr, Building* b, Character* me)
{
    bool current = Ownerships_canIUseThisBuilding_orig(thisptr, b, me);
    return CallOwnershipsCanIUseThisBuildingCallbacks(thisptr, b, me, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_Ownerships_canIUseThisBuilding,
    "Ownerships::canIUseThisBuilding",
    KenshiLib::GetRealAddress(&Ownerships::canIUseThisBuilding),
    Ownerships_canIUseThisBuilding_hook, Ownerships_canIUseThisBuilding_orig)

// ---------------------------------------------------------------------------
// Hooks for Building/UseableStuff.h
// ---------------------------------------------------------------------------

static bool (*UseableStuff_NV_tryOperate_orig)(UseableStuff*, const hand&) = NULL;
static bool UseableStuff_NV_tryOperate_hook(UseableStuff* thisptr, const hand& h)
{
    bool success = UseableStuff_NV_tryOperate_orig(thisptr, h);
    CallUseableStuffTryOperateCallbacks(thisptr, h, success);
    return success;
}
DEFINE_HOOK_INSTALLER(InstallHook_UseableStuff_NV_tryOperate,
    "UseableStuff::_NV_tryOperate",
    KenshiLib::GetRealAddress(&UseableStuff::_NV_tryOperate),
    UseableStuff_NV_tryOperate_hook, UseableStuff_NV_tryOperate_orig)

static void (*UseableStuff_stopOperating_orig)(UseableStuff*, const hand&) = NULL;
static void UseableStuff_stopOperating_hook(UseableStuff* thisptr, const hand& h)
{
    UseableStuff_stopOperating_orig(thisptr, h);
    CallUseableStuffStopOperatingCallbacks(thisptr, h);
}
DEFINE_HOOK_INSTALLER(InstallHook_UseableStuff_stopOperating,
    "UseableStuff::stopOperating",
    KenshiLib::GetRealAddress(&UseableStuff::stopOperating),
    UseableStuff_stopOperating_hook, UseableStuff_stopOperating_orig)

static void (*UseableStuff_occupantHandleChangedEvent_orig)(UseableStuff*, const hand&) = NULL;
static void UseableStuff_occupantHandleChangedEvent_hook(UseableStuff* thisptr, const hand& h)
{
    UseableStuff_occupantHandleChangedEvent_orig(thisptr, h);
    CallUseableStuffOccupantChangedCallbacks(thisptr, h);
}
DEFINE_HOOK_INSTALLER(InstallHook_UseableStuff_occupantHandleChangedEvent,
    "UseableStuff::occupantHandleChangedEvent",
    KenshiLib::GetRealAddress(&UseableStuff::occupantHandleChangedEvent),
    UseableStuff_occupantHandleChangedEvent_hook, UseableStuff_occupantHandleChangedEvent_orig)

static void (*UseableStuff_NV_switchPowerOn_orig)(UseableStuff*, bool) = NULL;
static void UseableStuff_NV_switchPowerOn_hook(UseableStuff* thisptr, bool on)
{
    UseableStuff_NV_switchPowerOn_orig(thisptr, on);
    CallUseableStuffPowerSwitchedCallbacks(thisptr, on);
}
DEFINE_HOOK_INSTALLER(InstallHook_UseableStuff_NV_switchPowerOn,
    "UseableStuff::_NV_switchPowerOn",
    KenshiLib::GetRealAddress(&UseableStuff::_NV_switchPowerOn),
    UseableStuff_NV_switchPowerOn_hook, UseableStuff_NV_switchPowerOn_orig)

static void (*UseableStuff_NV_givePower_orig)(UseableStuff*, float) = NULL;
static void UseableStuff_NV_givePower_hook(UseableStuff* thisptr, float amount)
{
    UseableStuff_NV_givePower_orig(thisptr, amount);
    CallUseableStuffGivePowerCallbacks(thisptr, amount);
}
DEFINE_HOOK_INSTALLER(InstallHook_UseableStuff_NV_givePower,
    "UseableStuff::_NV_givePower",
    KenshiLib::GetRealAddress(&UseableStuff::_NV_givePower),
    UseableStuff_NV_givePower_hook, UseableStuff_NV_givePower_orig)

static int (*UseableStuff_NV_getCostToUse_orig)(UseableStuff*, Character*) = NULL;
static int UseableStuff_NV_getCostToUse_hook(UseableStuff* thisptr, Character* who)
{
    int current = UseableStuff_NV_getCostToUse_orig(thisptr, who);
    return CallUseableStuffGetCostToUseCallbacks(thisptr, who, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_UseableStuff_NV_getCostToUse,
    "UseableStuff::_NV_getCostToUse",
    KenshiLib::GetRealAddress(&UseableStuff::_NV_getCostToUse),
    UseableStuff_NV_getCostToUse_hook, UseableStuff_NV_getCostToUse_orig)

static bool (*UseableStuff_NV_couldIOperate_orig)(const UseableStuff*, const hand&) = NULL;
static bool UseableStuff_NV_couldIOperate_hook(const UseableStuff* thisptr, const hand& h)
{
    bool current = UseableStuff_NV_couldIOperate_orig(thisptr, h);
    return CallUseableStuffCouldIOperateCallbacks(thisptr, h, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_UseableStuff_NV_couldIOperate,
    "UseableStuff::_NV_couldIOperate",
    KenshiLib::GetRealAddress(&UseableStuff::_NV_couldIOperate),
    UseableStuff_NV_couldIOperate_hook, UseableStuff_NV_couldIOperate_orig)

static bool (*UseableStuff_NV_dontNeedWorkRightNow_orig)(const UseableStuff*) = NULL;
static bool UseableStuff_NV_dontNeedWorkRightNow_hook(const UseableStuff* thisptr)
{
    bool current = UseableStuff_NV_dontNeedWorkRightNow_orig(thisptr);
    return CallUseableStuffDontNeedWorkCallbacks(thisptr, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_UseableStuff_NV_dontNeedWorkRightNow,
    "UseableStuff::_NV_dontNeedWorkRightNow",
    KenshiLib::GetRealAddress(&UseableStuff::_NV_dontNeedWorkRightNow),
    UseableStuff_NV_dontNeedWorkRightNow_hook, UseableStuff_NV_dontNeedWorkRightNow_orig)

// ---------------------------------------------------------------------------
// Additional Hooks for Building/Building.h
// ---------------------------------------------------------------------------

static void (*Building_NV_notifyConstructionComplete_orig)(Building*) = NULL;
static void Building_NV_notifyConstructionComplete_hook(Building* thisptr)
{
    Building_NV_notifyConstructionComplete_orig(thisptr);
    CallBuildingNotifyConstructionCompleteCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_NV_notifyConstructionComplete,
    "Building::_NV_notifyConstructionComplete",
    KenshiLib::GetRealAddress(&Building::_NV_notifyConstructionComplete),
    Building_NV_notifyConstructionComplete_hook, Building_NV_notifyConstructionComplete_orig)

static void (*Building_NV_addConstructionProgress_orig)(Building*, float) = NULL;
static void Building_NV_addConstructionProgress_hook(Building* thisptr, float amount)
{
    Building_NV_addConstructionProgress_orig(thisptr, amount);
    CallBuildingAddConstructionProgressCallbacks(thisptr, amount);
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_NV_addConstructionProgress,
    "Building::_NV_addConstructionProgress",
    KenshiLib::GetRealAddress(&Building::_NV_addConstructionProgress),
    Building_NV_addConstructionProgress_hook, Building_NV_addConstructionProgress_orig)

static void (*Building_NV_setConstructionProgress_orig)(Building*, float) = NULL;
static void Building_NV_setConstructionProgress_hook(Building* thisptr, float amount)
{
    Building_NV_setConstructionProgress_orig(thisptr, amount);
    CallBuildingSetConstructionProgressCallbacks(thisptr, amount);
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_NV_setConstructionProgress,
    "Building::_NV_setConstructionProgress",
    KenshiLib::GetRealAddress(&Building::_NV_setConstructionProgress),
    Building_NV_setConstructionProgress_hook, Building_NV_setConstructionProgress_orig)

static bool (*Building_NV_addDismantleProgress_orig)(Building*, float) = NULL;
static bool Building_NV_addDismantleProgress_hook(Building* thisptr, float amount)
{
    bool current = Building_NV_addDismantleProgress_orig(thisptr, amount);
    return CallBuildingAddDismantleProgressCallbacks(thisptr, amount, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_NV_addDismantleProgress,
    "Building::_NV_addDismantleProgress",
    KenshiLib::GetRealAddress(&Building::_NV_addDismantleProgress),
    Building_NV_addDismantleProgress_hook, Building_NV_addDismantleProgress_orig)

static void (*Building_NV_notifyConstructionDismantling_orig)(Building*) = NULL;
static void Building_NV_notifyConstructionDismantling_hook(Building* thisptr)
{
    Building_NV_notifyConstructionDismantling_orig(thisptr);
    CallBuildingNotifyConstructionDismantlingCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_NV_notifyConstructionDismantling,
    "Building::_NV_notifyConstructionDismantling",
    KenshiLib::GetRealAddress(&Building::_NV_notifyConstructionDismantling),
    Building_NV_notifyConstructionDismantling_hook, Building_NV_notifyConstructionDismantling_orig)

static void (*Building_NV_upgrade_orig)(Building*, DataPanelLine*) = NULL;
static void Building_NV_upgrade_hook(Building* thisptr, DataPanelLine* line)
{
    Building_NV_upgrade_orig(thisptr, line);
    CallBuildingUpgradeCallbacks(thisptr, line);
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_NV_upgrade,
    "Building::_NV_upgrade",
    KenshiLib::GetRealAddress(&Building::_NV_upgrade),
    Building_NV_upgrade_hook, Building_NV_upgrade_orig)

static GameData* (*Building_NV_canUpgrade_orig)(Building*) = NULL;
static GameData* Building_NV_canUpgrade_hook(Building* thisptr)
{
    GameData* current = Building_NV_canUpgrade_orig(thisptr);
    return CallBuildingCanUpgradeCallbacks(thisptr, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_NV_canUpgrade,
    "Building::_NV_canUpgrade",
    KenshiLib::GetRealAddress(&Building::_NV_canUpgrade),
    Building_NV_canUpgrade_hook, Building_NV_canUpgrade_orig)

// ---------------------------------------------------------------------------
// Hooks for Building/WallBuilding.h
// ---------------------------------------------------------------------------

static HitMaterialType (*WallBuilding_NV_hitByMeleeAttack_orig)(WallBuilding*, CutDirection, Damages&, Character*, CombatTechniqueData*, int) = NULL;
static HitMaterialType WallBuilding_NV_hitByMeleeAttack_hook(WallBuilding* thisptr, CutDirection dir, Damages& damage, Character* who, CombatTechniqueData* attack, int comboID)
{
    HitMaterialType res = WallBuilding_NV_hitByMeleeAttack_orig(thisptr, dir, damage, who, attack, comboID);
    CallWallBuildingHitByMeleeAttackCallbacks(thisptr, static_cast<int>(dir), &damage, who, attack, comboID);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_WallBuilding_NV_hitByMeleeAttack,
    "WallBuilding::_NV_hitByMeleeAttack",
    KenshiLib::GetRealAddress(&WallBuilding::_NV_hitByMeleeAttack),
    WallBuilding_NV_hitByMeleeAttack_hook, WallBuilding_NV_hitByMeleeAttack_orig)

static void (*Building_destroyDoors_orig)(Building*) = NULL;
static void Building_destroyDoors_hook(Building* thisptr)
{
    Building_destroyDoors_orig(thisptr);
    CallBuildingDestroyDoorsCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_destroyDoors,
    "Building::destroyDoors",
    KenshiLib::GetRealAddress(&Building::destroyDoors),
    Building_destroyDoors_hook, Building_destroyDoors_orig)

static void (*Building_NV_setFaction_orig)(Building*, Faction*, ActivePlatoon*) = NULL;
static void Building_NV_setFaction_hook(Building* thisptr, Faction* p, ActivePlatoon* a)
{
    Building_NV_setFaction_orig(thisptr, p, a);
    CallBuildingSetFactionCallbacks(thisptr, p, a);
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_NV_setFaction,
    "Building::_NV_setFaction",
    KenshiLib::GetRealAddress(&Building::_NV_setFaction),
    Building_NV_setFaction_hook, Building_NV_setFaction_orig)

static void (*Building_setFloorVisibility_orig)(Building*, int, bool) = NULL;
static void Building_setFloorVisibility_hook(Building* thisptr, int floor, bool vis)
{
    Building_setFloorVisibility_orig(thisptr, floor, vis);
    CallBuildingSetFloorVisibilityCallbacks(thisptr, floor, vis);
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_setFloorVisibility,
    "Building::setFloorVisibility",
    KenshiLib::GetRealAddress(&Building::setFloorVisibility),
    Building_setFloorVisibility_hook, Building_setFloorVisibility_orig)

static void (*Building_NV_switchLights_orig)(Building*, bool) = NULL;
static void Building_NV_switchLights_hook(Building* thisptr, bool on)
{
    Building_NV_switchLights_orig(thisptr, on);
    CallBuildingSwitchLightsCallbacks(thisptr, on);
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_NV_switchLights,
    "Building::_NV_switchLights",
    KenshiLib::GetRealAddress(&Building::_NV_switchLights),
    Building_NV_switchLights_hook, Building_NV_switchLights_orig)

static void (*Building_NV_switchEffects_orig)(Building*, bool) = NULL;
static void Building_NV_switchEffects_hook(Building* thisptr, bool on)
{
    Building_NV_switchEffects_orig(thisptr, on);
    CallBuildingSwitchEffectsCallbacks(thisptr, on);
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_NV_switchEffects,
    "Building::_NV_switchEffects",
    KenshiLib::GetRealAddress(&Building::_NV_switchEffects),
    Building_NV_switchEffects_hook, Building_NV_switchEffects_orig)

static void (*Building_NV_notifyEffect_orig)(Building*, EffectType::Enum, WeatherAffecting, float) = NULL;
static void Building_NV_notifyEffect_hook(Building* thisptr, EffectType::Enum type, WeatherAffecting what, float strength)
{
    Building_NV_notifyEffect_orig(thisptr, type, what, strength);
    CallBuildingNotifyEffectCallbacks(thisptr, static_cast<int>(type), static_cast<int>(what), strength);
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_NV_notifyEffect,
    "Building::_NV_notifyEffect",
    KenshiLib::GetRealAddress(&Building::_NV_notifyEffect),
    Building_NV_notifyEffect_hook, Building_NV_notifyEffect_orig)

// ---------------------------------------------------------------------------
// Hooks for Building/DoorStuff.h
// ---------------------------------------------------------------------------

static bool (*DoorStuff_openDoor_orig)(DoorStuff*) = NULL;
static bool DoorStuff_openDoor_hook(DoorStuff* thisptr)
{
    bool current = DoorStuff_openDoor_orig(thisptr);
    return CallDoorStuffOpenDoorCallbacks(thisptr, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_DoorStuff_openDoor,
    "DoorStuff::openDoor",
    KenshiLib::GetRealAddress(&DoorStuff::openDoor),
    DoorStuff_openDoor_hook, DoorStuff_openDoor_orig)

static bool (*DoorStuff_closeDoor_orig)(DoorStuff*) = NULL;
static bool DoorStuff_closeDoor_hook(DoorStuff* thisptr)
{
    bool current = DoorStuff_closeDoor_orig(thisptr);
    return CallDoorStuffCloseDoorCallbacks(thisptr, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_DoorStuff_closeDoor,
    "DoorStuff::closeDoor",
    KenshiLib::GetRealAddress(&DoorStuff::closeDoor),
    DoorStuff_closeDoor_hook, DoorStuff_closeDoor_orig)

static void (*DoorStuff_lockDoor_orig)(DoorStuff*) = NULL;
static void DoorStuff_lockDoor_hook(DoorStuff* thisptr)
{
    DoorStuff_lockDoor_orig(thisptr);
    CallDoorStuffLockDoorCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DoorStuff_lockDoor,
    "DoorStuff::lockDoor",
    KenshiLib::GetRealAddress(&DoorStuff::lockDoor),
    DoorStuff_lockDoor_hook, DoorStuff_lockDoor_orig)

static void (*DoorStuff_unlockDoor_orig)(DoorStuff*) = NULL;
static void DoorStuff_unlockDoor_hook(DoorStuff* thisptr)
{
    DoorStuff_unlockDoor_orig(thisptr);
    CallDoorStuffUnlockDoorCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DoorStuff_unlockDoor,
    "DoorStuff::unlockDoor",
    KenshiLib::GetRealAddress(&DoorStuff::unlockDoor),
    DoorStuff_unlockDoor_hook, DoorStuff_unlockDoor_orig)

static void (*DoorStuff_setDoorState_orig)(DoorStuff*, DoorState) = NULL;
static void DoorStuff_setDoorState_hook(DoorStuff* thisptr, DoorState what)
{
    DoorStuff_setDoorState_orig(thisptr, what);
    CallDoorStuffSetDoorStateCallbacks(thisptr, static_cast<int>(what));
}
DEFINE_HOOK_INSTALLER(InstallHook_DoorStuff_setDoorState,
    "DoorStuff::setDoorState",
    KenshiLib::GetRealAddress(&DoorStuff::setDoorState),
    DoorStuff_setDoorState_hook, DoorStuff_setDoorState_orig)

static HitMaterialType (*DoorStuff_NV_hitByMeleeAttack_orig)(DoorStuff*, CutDirection, Damages&, Character*, CombatTechniqueData*, int) = NULL;
static HitMaterialType DoorStuff_NV_hitByMeleeAttack_hook(DoorStuff* thisptr, CutDirection dir, Damages& damage, Character* who, CombatTechniqueData* attack, int comboID)
{
    HitMaterialType res = DoorStuff_NV_hitByMeleeAttack_orig(thisptr, dir, damage, who, attack, comboID);
    CallDoorStuffHitByMeleeAttackCallbacks(thisptr, static_cast<int>(dir), &damage, who, attack, comboID);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DoorStuff_NV_hitByMeleeAttack,
    "DoorStuff::_NV_hitByMeleeAttack",
    KenshiLib::GetRealAddress(&DoorStuff::_NV_hitByMeleeAttack),
    DoorStuff_NV_hitByMeleeAttack_hook, DoorStuff_NV_hitByMeleeAttack_orig)

// ---------------------------------------------------------------------------
// Hooks for Building/ProductionBuilding.h
// ---------------------------------------------------------------------------

static void (*ProductionBuilding_NV_operate_orig)(ProductionBuilding*, Character*, float) = NULL;
static void ProductionBuilding_NV_operate_hook(ProductionBuilding* thisptr, Character* _a1, float amount)
{
    ProductionBuilding_NV_operate_orig(thisptr, _a1, amount);
    CallProductionBuildingOperateCallbacks(thisptr, _a1, amount);
}
DEFINE_HOOK_INSTALLER(InstallHook_ProductionBuilding_NV_operate,
    "ProductionBuilding::_NV_operate",
    KenshiLib::GetRealAddress(&ProductionBuilding::_NV_operate),
    ProductionBuilding_NV_operate_hook, ProductionBuilding_NV_operate_orig)

// ---------------------------------------------------------------------------
// Hooks for Building/CraftingBuilding.h
// ---------------------------------------------------------------------------

static void (*CraftingBuilding_NV_operate_orig)(CraftingBuilding*, Character*, float) = NULL;
static void CraftingBuilding_NV_operate_hook(CraftingBuilding* thisptr, Character* stats, float _amount)
{
    CraftingBuilding_NV_operate_orig(thisptr, stats, _amount);
    CallCraftingBuildingOperateCallbacks(thisptr, stats, _amount);
}
DEFINE_HOOK_INSTALLER(InstallHook_CraftingBuilding_NV_operate,
    "CraftingBuilding::_NV_operate",
    KenshiLib::GetRealAddress(&CraftingBuilding::_NV_operate),
    CraftingBuilding_NV_operate_hook, CraftingBuilding_NV_operate_orig)

static void (*CraftingBuilding_NV_newCraftingButton_orig)(CraftingBuilding*, MyGUI::Widget*) = NULL;
static void CraftingBuilding_NV_newCraftingButton_hook(CraftingBuilding* thisptr, MyGUI::Widget* _sender)
{
    CraftingBuilding_NV_newCraftingButton_orig(thisptr, _sender);
    CallCraftingBuildingNewCraftingButtonCallbacks(thisptr, _sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_CraftingBuilding_NV_newCraftingButton,
    "CraftingBuilding::_NV_newCraftingButton",
    KenshiLib::GetRealAddress(&CraftingBuilding::_NV_newCraftingButton),
    CraftingBuilding_NV_newCraftingButton_hook, CraftingBuilding_NV_newCraftingButton_orig)

static void (*CraftingBuilding_addFinishedCraftItem_orig)(CraftingBuilding*, Item*) = NULL;
static void CraftingBuilding_addFinishedCraftItem_hook(CraftingBuilding* thisptr, Item* what)
{
    CraftingBuilding_addFinishedCraftItem_orig(thisptr, what);
    CallCraftingBuildingAddFinishedCraftItemCallbacks(thisptr, what);
}
DEFINE_HOOK_INSTALLER(InstallHook_CraftingBuilding_addFinishedCraftItem,
    "CraftingBuilding::addFinishedCraftItem",
    KenshiLib::GetRealAddress(&CraftingBuilding::addFinishedCraftItem),
    CraftingBuilding_addFinishedCraftItem_hook, CraftingBuilding_addFinishedCraftItem_orig)

static void (*CraftingBuilding_notifyCraftFailiure_orig)(CraftingBuilding*) = NULL;
static void CraftingBuilding_notifyCraftFailiure_hook(CraftingBuilding* thisptr)
{
    CraftingBuilding_notifyCraftFailiure_orig(thisptr);
    CallCraftingBuildingNotifyCraftFailureCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_CraftingBuilding_notifyCraftFailiure,
    "CraftingBuilding::notifyCraftFailiure",
    KenshiLib::GetRealAddress(&CraftingBuilding::notifyCraftFailiure),
    CraftingBuilding_notifyCraftFailiure_hook, CraftingBuilding_notifyCraftFailiure_orig)

static void (*CraftingBuilding_destroyProductionItem_orig)(CraftingBuilding*) = NULL;
static void CraftingBuilding_destroyProductionItem_hook(CraftingBuilding* thisptr)
{
    CraftingBuilding_destroyProductionItem_orig(thisptr);
    CallCraftingBuildingDestroyProductionItemCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_CraftingBuilding_destroyProductionItem,
    "CraftingBuilding::destroyProductionItem",
    KenshiLib::GetRealAddress(&CraftingBuilding::destroyProductionItem),
    CraftingBuilding_destroyProductionItem_hook, CraftingBuilding_destroyProductionItem_orig)

static void (*CraftingBuilding_removeCraft_orig)(CraftingBuilding*, int) = NULL;
static void CraftingBuilding_removeCraft_hook(CraftingBuilding* thisptr, int index)
{
    CraftingBuilding_removeCraft_orig(thisptr, index);
    CallCraftingBuildingRemoveCraftCallbacks(thisptr, index);
}
DEFINE_HOOK_INSTALLER(InstallHook_CraftingBuilding_removeCraft,
    "CraftingBuilding::_removeCraft",
    KenshiLib::GetRealAddress(&CraftingBuilding::_removeCraft),
    CraftingBuilding_removeCraft_hook, CraftingBuilding_removeCraft_orig)

// ---------------------------------------------------------------------------
// Hooks for Building/FurnaceBuilding.h
// ---------------------------------------------------------------------------

static void (*FurnaceBuilding_NV_operate_orig)(FurnaceBuilding*, Character*, float) = NULL;
static void FurnaceBuilding_NV_operate_hook(FurnaceBuilding* thisptr, Character* stats, float amount)
{
    FurnaceBuilding_NV_operate_orig(thisptr, stats, amount);
    CallFurnaceBuildingOperateCallbacks(thisptr, stats, amount);
}
DEFINE_HOOK_INSTALLER(InstallHook_FurnaceBuilding_NV_operate,
    "FurnaceBuilding::_NV_operate",
    KenshiLib::GetRealAddress(&FurnaceBuilding::_NV_operate),
    FurnaceBuilding_NV_operate_hook, FurnaceBuilding_NV_operate_orig)

// ---------------------------------------------------------------------------
// Hooks for Building/ResearchBuilding.h
// ---------------------------------------------------------------------------

static void (*ResearchBuilding_NV_operate_orig)(ResearchBuilding*, Character*, float) = NULL;
static void ResearchBuilding_NV_operate_hook(ResearchBuilding* thisptr, Character* stats, float amount)
{
    ResearchBuilding_NV_operate_orig(thisptr, stats, amount);
    CallResearchBuildingOperateCallbacks(thisptr, stats, amount);
}
DEFINE_HOOK_INSTALLER(InstallHook_ResearchBuilding_NV_operate,
    "ResearchBuilding::_NV_operate",
    KenshiLib::GetRealAddress(&ResearchBuilding::_NV_operate),
    ResearchBuilding_NV_operate_hook, ResearchBuilding_NV_operate_orig)

// ---------------------------------------------------------------------------
// Hooks for Building/FarmBuilding.h
// ---------------------------------------------------------------------------

static void (*FarmBuilding_NV_operate_orig)(FarmBuilding*, Character*, float) = NULL;
static void FarmBuilding_NV_operate_hook(FarmBuilding* thisptr, Character* who, float amount)
{
    FarmBuilding_NV_operate_orig(thisptr, who, amount);
    CallFarmBuildingOperateCallbacks(thisptr, who, amount);
}
DEFINE_HOOK_INSTALLER(InstallHook_FarmBuilding_NV_operate,
    "FarmBuilding::_NV_operate",
    KenshiLib::GetRealAddress(&FarmBuilding::_NV_operate),
    FarmBuilding_NV_operate_hook, FarmBuilding_NV_operate_orig)

static bool (*FarmBuilding_destroyAPlant_orig)(FarmBuilding*) = NULL;
static bool FarmBuilding_destroyAPlant_hook(FarmBuilding* thisptr)
{
    bool current = FarmBuilding_destroyAPlant_orig(thisptr);
    return CallFarmBuildingDestroyAPlantCallbacks(thisptr, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_FarmBuilding_destroyAPlant,
    "FarmBuilding::destroyAPlant",
    KenshiLib::GetRealAddress(&FarmBuilding::destroyAPlant),
    FarmBuilding_destroyAPlant_hook, FarmBuilding_destroyAPlant_orig)

static void (*FarmBuilding_eat_orig)(FarmBuilding*, float) = NULL;
static void FarmBuilding_eat_hook(FarmBuilding* thisptr, float rate)
{
    FarmBuilding_eat_orig(thisptr, rate);
    CallFarmBuildingEatCallbacks(thisptr, rate);
}
DEFINE_HOOK_INSTALLER(InstallHook_FarmBuilding_eat,
    "FarmBuilding::eat",
    KenshiLib::GetRealAddress(&FarmBuilding::eat),
    FarmBuilding_eat_hook, FarmBuilding_eat_orig)

// ---------------------------------------------------------------------------
// Hooks for Building/TurretBuilding.h
// ---------------------------------------------------------------------------

static void (*TurretBuilding_NV_operate_orig)(TurretBuilding*, Character*, float) = NULL;
static void TurretBuilding_NV_operate_hook(TurretBuilding* thisptr, Character* who, float _a2)
{
    TurretBuilding_NV_operate_orig(thisptr, who, _a2);
    CallTurretBuildingOperateCallbacks(thisptr, who, _a2);
}
DEFINE_HOOK_INSTALLER(InstallHook_TurretBuilding_NV_operate,
    "TurretBuilding::_NV_operate",
    KenshiLib::GetRealAddress(&TurretBuilding::_NV_operate),
    TurretBuilding_NV_operate_hook, TurretBuilding_NV_operate_orig)

static void (*TurretBuilding_aimAt_orig)(TurretBuilding*, const Ogre::Vector3&) = NULL;
static void TurretBuilding_aimAt_hook(TurretBuilding* thisptr, const Ogre::Vector3& who)
{
    TurretBuilding_aimAt_orig(thisptr, who);
    CallTurretBuildingAimAtCallbacks(thisptr, who);
}
DEFINE_HOOK_INSTALLER(InstallHook_TurretBuilding_aimAt,
    "TurretBuilding::aimAt",
    KenshiLib::GetRealAddress(&TurretBuilding::aimAt),
    TurretBuilding_aimAt_hook, TurretBuilding_aimAt_orig)

// ---------------------------------------------------------------------------
// Additional Hooks for Building/UseableStuff.h
// ---------------------------------------------------------------------------

static HitMaterialType (*UseableStuff_NV_hitByMeleeAttack_orig)(UseableStuff*, CutDirection, Damages&, Character*, CombatTechniqueData*, int) = NULL;
static HitMaterialType UseableStuff_NV_hitByMeleeAttack_hook(UseableStuff* thisptr, CutDirection dir, Damages& damage, Character* who, CombatTechniqueData* attack, int comboID)
{
    HitMaterialType res = UseableStuff_NV_hitByMeleeAttack_orig(thisptr, dir, damage, who, attack, comboID);
    CallUseableStuffHitByMeleeAttackCallbacks(thisptr, static_cast<int>(dir), &damage, who, attack, comboID);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_UseableStuff_NV_hitByMeleeAttack,
    "UseableStuff::_NV_hitByMeleeAttack",
    KenshiLib::GetRealAddress(&UseableStuff::_NV_hitByMeleeAttack),
    UseableStuff_NV_hitByMeleeAttack_hook, UseableStuff_NV_hitByMeleeAttack_orig)

static float (*UseableStuff_takePowerFrom_orig)(UseableStuff*, float, float) = NULL;
static float UseableStuff_takePowerFrom_hook(UseableStuff* thisptr, float amount, float frameTime)
{
    float current = UseableStuff_takePowerFrom_orig(thisptr, amount, frameTime);
    return CallUseableStuffTakePowerFromCallbacks(thisptr, amount, frameTime, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_UseableStuff_takePowerFrom,
    "UseableStuff::takePowerFrom",
    KenshiLib::GetRealAddress(&UseableStuff::takePowerFrom),
    UseableStuff_takePowerFrom_hook, UseableStuff_takePowerFrom_orig)

static void (*UseableStuff_NV_togglePowerButton_orig)(UseableStuff*, DataPanelLine*) = NULL;
static void UseableStuff_NV_togglePowerButton_hook(UseableStuff* thisptr, DataPanelLine* _a1)
{
    UseableStuff_NV_togglePowerButton_orig(thisptr, _a1);
    CallUseableStuffTogglePowerButtonCallbacks(thisptr, _a1);
}
DEFINE_HOOK_INSTALLER(InstallHook_UseableStuff_NV_togglePowerButton,
    "UseableStuff::_NV_togglePowerButton",
    KenshiLib::GetRealAddress(&UseableStuff::_NV_togglePowerButton),
    UseableStuff_NV_togglePowerButton_hook, UseableStuff_NV_togglePowerButton_orig)

static void (*UseableStuff_NV_toggleBattButton_orig)(UseableStuff*, DataPanelLine*) = NULL;
static void UseableStuff_NV_toggleBattButton_hook(UseableStuff* thisptr, DataPanelLine* _a1)
{
    UseableStuff_NV_toggleBattButton_orig(thisptr, _a1);
    CallUseableStuffToggleBattButtonCallbacks(thisptr, _a1);
}
DEFINE_HOOK_INSTALLER(InstallHook_UseableStuff_NV_toggleBattButton,
    "UseableStuff::_NV_toggleBattButton",
    KenshiLib::GetRealAddress(&UseableStuff::_NV_toggleBattButton),
    UseableStuff_NV_toggleBattButton_hook, UseableStuff_NV_toggleBattButton_orig)

// ---------------------------------------------------------------------------
// Hooks for PreviewBuilding
// ---------------------------------------------------------------------------

static void (*PreviewBuilding_NV_placeFinalPreviewBuilding_orig)(PreviewBuilding*) = NULL;
static void PreviewBuilding_NV_placeFinalPreviewBuilding_hook(PreviewBuilding* thisptr)
{
    PreviewBuilding_NV_placeFinalPreviewBuilding_orig(thisptr);
    CallPreviewBuildingPlaceFinalPreviewBuildingCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_PreviewBuilding_NV_placeFinalPreviewBuilding,
    "PreviewBuilding::_NV_placeFinalPreviewBuilding",
    KenshiLib::GetRealAddress(&PreviewBuilding::_NV_placeFinalPreviewBuilding),
    PreviewBuilding_NV_placeFinalPreviewBuilding_hook, PreviewBuilding_NV_placeFinalPreviewBuilding_orig)

static bool (*PreviewBuilding_NV_placementVerification_orig)(PreviewBuilding*) = NULL;
static bool PreviewBuilding_NV_placementVerification_hook(PreviewBuilding* thisptr)
{
    bool current = PreviewBuilding_NV_placementVerification_orig(thisptr);
    return CallPreviewBuildingPlacementVerificationCallbacks(thisptr, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_PreviewBuilding_NV_placementVerification,
    "PreviewBuilding::_NV_placementVerification",
    KenshiLib::GetRealAddress(&PreviewBuilding::_NV_placementVerification),
    PreviewBuilding_NV_placementVerification_hook, PreviewBuilding_NV_placementVerification_orig)

static void (*PreviewBuilding_NV_placePreview_orig)(PreviewBuilding*, const Ogre::Vector3&, const Ogre::Quaternion&, int) = NULL;
static void PreviewBuilding_NV_placePreview_hook(PreviewBuilding* thisptr, const Ogre::Vector3& position, const Ogre::Quaternion& rotation, int floorNumber)
{
    PreviewBuilding_NV_placePreview_orig(thisptr, position, rotation, floorNumber);
    CallPreviewBuildingPlacePreviewCallbacks(thisptr, position, rotation, floorNumber);
}
DEFINE_HOOK_INSTALLER(InstallHook_PreviewBuilding_NV_placePreview,
    "PreviewBuilding::_NV_placePreview",
    KenshiLib::GetRealAddress(&PreviewBuilding::_NV_placePreview),
    PreviewBuilding_NV_placePreview_hook, PreviewBuilding_NV_placePreview_orig)

// ---------------------------------------------------------------------------
// Constructor Hooks
// ---------------------------------------------------------------------------

static DoorStuff* (*DoorStuff_CONSTRUCTOR_orig)(DoorStuff*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, Building*) = NULL;
static DoorStuff* DoorStuff_CONSTRUCTOR_hook(DoorStuff* thisptr, GameData* dat, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, Building* par)
{
    DoorStuff* res = DoorStuff_CONSTRUCTOR_orig(thisptr, dat, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, par);
    DoorStuff* overrideRes = CallDoorStuffConstructedCallbacks(thisptr, dat, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, par, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DoorStuff_CONSTRUCTOR,
    "DoorStuff::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&DoorStuff::_CONSTRUCTOR),
    DoorStuff_CONSTRUCTOR_hook, DoorStuff_CONSTRUCTOR_orig)

static ProductionBuilding* (*ProductionBuilding_CONSTRUCTOR_orig)(ProductionBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*) = NULL;
static ProductionBuilding* ProductionBuilding_CONSTRUCTOR_hook(ProductionBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors)
{
    ProductionBuilding* res = ProductionBuilding_CONSTRUCTOR_orig(thisptr, _data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors);
    ProductionBuilding* overrideRes = CallProductionBuildingConstructedCallbacks(thisptr, _data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ProductionBuilding_CONSTRUCTOR,
    "ProductionBuilding::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&ProductionBuilding::_CONSTRUCTOR),
    ProductionBuilding_CONSTRUCTOR_hook, ProductionBuilding_CONSTRUCTOR_orig)

static CraftingBuilding* (*CraftingBuilding_CONSTRUCTOR_orig)(CraftingBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*) = NULL;
static CraftingBuilding* CraftingBuilding_CONSTRUCTOR_hook(CraftingBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors)
{
    CraftingBuilding* res = CraftingBuilding_CONSTRUCTOR_orig(thisptr, _data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors);
    CraftingBuilding* overrideRes = CallCraftingBuildingConstructedCallbacks(thisptr, _data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_CraftingBuilding_CONSTRUCTOR,
    "CraftingBuilding::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&CraftingBuilding::_CONSTRUCTOR),
    CraftingBuilding_CONSTRUCTOR_hook, CraftingBuilding_CONSTRUCTOR_orig)

static FarmBuilding* (*FarmBuilding_CONSTRUCTOR_orig)(FarmBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*) = NULL;
static FarmBuilding* FarmBuilding_CONSTRUCTOR_hook(FarmBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors)
{
    FarmBuilding* res = FarmBuilding_CONSTRUCTOR_orig(thisptr, data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors);
    FarmBuilding* overrideRes = CallFarmBuildingConstructedCallbacks(thisptr, data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_FarmBuilding_CONSTRUCTOR,
    "FarmBuilding::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&FarmBuilding::_CONSTRUCTOR),
    FarmBuilding_CONSTRUCTOR_hook, FarmBuilding_CONSTRUCTOR_orig)

static TurretBuilding* (*TurretBuilding_CONSTRUCTOR_orig)(TurretBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*) = NULL;
static TurretBuilding* TurretBuilding_CONSTRUCTOR_hook(TurretBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors)
{
    TurretBuilding* res = TurretBuilding_CONSTRUCTOR_orig(thisptr, _data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors);
    TurretBuilding* overrideRes = CallTurretBuildingConstructedCallbacks(thisptr, _data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_TurretBuilding_CONSTRUCTOR,
    "TurretBuilding::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&TurretBuilding::_CONSTRUCTOR),
    TurretBuilding_CONSTRUCTOR_hook, TurretBuilding_CONSTRUCTOR_orig)

static FurnaceBuilding* (*FurnaceBuilding_CONSTRUCTOR_orig)(FurnaceBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*) = NULL;
static FurnaceBuilding* FurnaceBuilding_CONSTRUCTOR_hook(FurnaceBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors)
{
    FurnaceBuilding* res = FurnaceBuilding_CONSTRUCTOR_orig(thisptr, data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors);
    FurnaceBuilding* overrideRes = CallFurnaceBuildingConstructedCallbacks(thisptr, data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_FurnaceBuilding_CONSTRUCTOR,
    "FurnaceBuilding::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&FurnaceBuilding::_CONSTRUCTOR),
    FurnaceBuilding_CONSTRUCTOR_hook, FurnaceBuilding_CONSTRUCTOR_orig)

static ResearchBuilding* (*ResearchBuilding_CONSTRUCTOR_orig)(ResearchBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*) = NULL;
static ResearchBuilding* ResearchBuilding_CONSTRUCTOR_hook(ResearchBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors)
{
    ResearchBuilding* res = ResearchBuilding_CONSTRUCTOR_orig(thisptr, _data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors);
    ResearchBuilding* overrideRes = CallResearchBuildingConstructedCallbacks(thisptr, _data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ResearchBuilding_CONSTRUCTOR,
    "ResearchBuilding::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&ResearchBuilding::_CONSTRUCTOR),
    ResearchBuilding_CONSTRUCTOR_hook, ResearchBuilding_CONSTRUCTOR_orig)

static WallBuilding* (*WallBuilding_CONSTRUCTOR_orig)(WallBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, Layout*, const hand&, const hand&) = NULL;
static WallBuilding* WallBuilding_CONSTRUCTOR_hook(WallBuilding* thisptr, GameData* dat, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, Layout* furnitureOf, const hand& town, const hand& _handle)
{
    WallBuilding* res = WallBuilding_CONSTRUCTOR_orig(thisptr, dat, position, orientation, _participant, furnitureOf, town, _handle);
    WallBuilding* overrideRes = CallWallBuildingConstructedCallbacks(thisptr, dat, position, orientation, _participant, furnitureOf, town, _handle, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_WallBuilding_CONSTRUCTOR,
    "WallBuilding::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&WallBuilding::_CONSTRUCTOR),
    WallBuilding_CONSTRUCTOR_hook, WallBuilding_CONSTRUCTOR_orig)

static PreviewBuilding* (*PreviewBuilding_CONSTRUCTOR_orig)(PreviewBuilding*, GameData*, Building*) = NULL;
static PreviewBuilding* PreviewBuilding_CONSTRUCTOR_hook(PreviewBuilding* thisptr, GameData* data, Building* _furnitureParent)
{
    PreviewBuilding* res = PreviewBuilding_CONSTRUCTOR_orig(thisptr, data, _furnitureParent);
    PreviewBuilding* overrideRes = CallPreviewBuildingConstructedCallbacks(thisptr, data, _furnitureParent, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_PreviewBuilding_CONSTRUCTOR,
    "PreviewBuilding::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&PreviewBuilding::_CONSTRUCTOR),
    PreviewBuilding_CONSTRUCTOR_hook, PreviewBuilding_CONSTRUCTOR_orig)

static UseableStuff* (*UseableStuff_CONSTRUCTOR_orig)(UseableStuff*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*) = NULL;
static UseableStuff* UseableStuff_CONSTRUCTOR_hook(UseableStuff* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors)
{
    UseableStuff* res = UseableStuff_CONSTRUCTOR_orig(thisptr, _data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors);
    UseableStuff* overrideRes = CallUseableStuffConstructedCallbacks(thisptr, _data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_UseableStuff_CONSTRUCTOR,
    "UseableStuff::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&UseableStuff::_CONSTRUCTOR),
    UseableStuff_CONSTRUCTOR_hook, UseableStuff_CONSTRUCTOR_orig)

static StorageBuilding* (*StorageBuilding_CONSTRUCTOR_orig)(StorageBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*) = NULL;
static StorageBuilding* StorageBuilding_CONSTRUCTOR_hook(StorageBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors)
{
    StorageBuilding* res = StorageBuilding_CONSTRUCTOR_orig(thisptr, _data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors);
    StorageBuilding* overrideRes = CallStorageBuildingConstructedCallbacks(thisptr, _data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_StorageBuilding_CONSTRUCTOR,
    "StorageBuilding::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&StorageBuilding::_CONSTRUCTOR),
    StorageBuilding_CONSTRUCTOR_hook, StorageBuilding_CONSTRUCTOR_orig)

static LightBuilding* (*LightBuilding_CONSTRUCTOR_orig)(LightBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*) = NULL;
static LightBuilding* LightBuilding_CONSTRUCTOR_hook(LightBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors)
{
    LightBuilding* res = LightBuilding_CONSTRUCTOR_orig(thisptr, data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors);
    LightBuilding* overrideRes = CallLightBuildingConstructedCallbacks(thisptr, data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_LightBuilding_CONSTRUCTOR,
    "LightBuilding::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&LightBuilding::_CONSTRUCTOR),
    LightBuilding_CONSTRUCTOR_hook, LightBuilding_CONSTRUCTOR_orig)

static GeneratorBuilding* (*GeneratorBuilding_CONSTRUCTOR_orig)(GeneratorBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*) = NULL;
static GeneratorBuilding* GeneratorBuilding_CONSTRUCTOR_hook(GeneratorBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors)
{
    GeneratorBuilding* res = GeneratorBuilding_CONSTRUCTOR_orig(thisptr, data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors);
    GeneratorBuilding* overrideRes = CallGeneratorBuildingConstructedCallbacks(thisptr, data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_GeneratorBuilding_CONSTRUCTOR,
    "GeneratorBuilding::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&GeneratorBuilding::_CONSTRUCTOR),
    GeneratorBuilding_CONSTRUCTOR_hook, GeneratorBuilding_CONSTRUCTOR_orig)

static WindGeneratorBuilding* (*WindGeneratorBuilding_CONSTRUCTOR_orig)(WindGeneratorBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*) = NULL;
static WindGeneratorBuilding* WindGeneratorBuilding_CONSTRUCTOR_hook(WindGeneratorBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors)
{
    WindGeneratorBuilding* res = WindGeneratorBuilding_CONSTRUCTOR_orig(thisptr, data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors);
    WindGeneratorBuilding* overrideRes = CallWindGeneratorBuildingConstructedCallbacks(thisptr, data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_WindGeneratorBuilding_CONSTRUCTOR,
    "WindGeneratorBuilding::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&WindGeneratorBuilding::_CONSTRUCTOR),
    WindGeneratorBuilding_CONSTRUCTOR_hook, WindGeneratorBuilding_CONSTRUCTOR_orig)

static GatewayBuilding* (*GatewayBuilding_CONSTRUCTOR_orig)(GatewayBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&) = NULL;
static GatewayBuilding* GatewayBuilding_CONSTRUCTOR_hook(GatewayBuilding* thisptr, GameData* dat, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle)
{
    GatewayBuilding* res = GatewayBuilding_CONSTRUCTOR_orig(thisptr, dat, position, orientation, _participant, town, _handle);
    GatewayBuilding* overrideRes = CallGatewayBuildingConstructedCallbacks(thisptr, dat, position, orientation, _participant, town, _handle, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_GatewayBuilding_CONSTRUCTOR,
    "GatewayBuilding::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&GatewayBuilding::_CONSTRUCTOR),
    GatewayBuilding_CONSTRUCTOR_hook, GatewayBuilding_CONSTRUCTOR_orig)

static TortureBuilding* (*TortureBuilding_CONSTRUCTOR_orig)(TortureBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*) = NULL;
static TortureBuilding* TortureBuilding_CONSTRUCTOR_hook(TortureBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* participant, const hand& town, const hand& handle, Layout* isfurnitureOf, Building* indoors)
{
    TortureBuilding* res = TortureBuilding_CONSTRUCTOR_orig(thisptr, data, position, orientation, participant, town, handle, isfurnitureOf, indoors);
    TortureBuilding* overrideRes = CallTortureBuildingConstructedCallbacks(thisptr, data, position, orientation, participant, town, handle, isfurnitureOf, indoors, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_TortureBuilding_CONSTRUCTOR,
    "TortureBuilding::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&TortureBuilding::_CONSTRUCTOR),
    TortureBuilding_CONSTRUCTOR_hook, TortureBuilding_CONSTRUCTOR_orig)

static RainCollectorBuilding* (*RainCollectorBuilding_CONSTRUCTOR_orig)(RainCollectorBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*) = NULL;
static RainCollectorBuilding* RainCollectorBuilding_CONSTRUCTOR_hook(RainCollectorBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* participant, const hand& town, const hand& handle, Layout* isfurnitureOf, Building* indoors)
{
    RainCollectorBuilding* res = RainCollectorBuilding_CONSTRUCTOR_orig(thisptr, data, position, orientation, participant, town, handle, isfurnitureOf, indoors);
    RainCollectorBuilding* overrideRes = CallRainCollectorBuildingConstructedCallbacks(thisptr, data, position, orientation, participant, town, handle, isfurnitureOf, indoors, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_RainCollectorBuilding_CONSTRUCTOR,
    "RainCollectorBuilding::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&RainCollectorBuilding::_CONSTRUCTOR),
    RainCollectorBuilding_CONSTRUCTOR_hook, RainCollectorBuilding_CONSTRUCTOR_orig)


