#include "pch.h"
#include "kenshi/Tasker.h"
#include "kenshi/Building/FarmBuilding.h"
#include "kenshi/AI/Blackboard.h"
#include "kenshi/BountyManager.h"
#include "kenshi/Dialogue.h"
#include "kenshi/FactionRelations.h"
#include "kenshi/GameSaveState.h"
#include "kenshi/GameWorld.h"
#include "kenshi/HandleManager.h"
#include "kenshi/Item.h"
#include "kenshi/MedicalSystem.h"
#include "kenshi/RaceData.h"
#include "kenshi/ShopTraderInventory.h"
#include "kenshi/Town.h"
#include "kenshi/combat/CombatClass.h"
#include "kenshi/gamedatamanager.h"
#include "kenshi/gui/ForgottenGUI.h"
#include "kenshi/gui/MainBarGUI.h"
#include "kenshi/gui/MapScreen.h"
#include "kenshi/gui/TutorialGUI.h"
#include "Bindings/Kenshi/AI/Blackboard_TaskInfoBinding.h"
#include "Bindings/Kenshi/AI/TaskRequestBinding.h"
#include "Bindings/Kenshi/BountyBinding.h"
#include "Bindings/Kenshi/Building/BuildingBinding.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/FactionBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/Gui/InventoryGUIBinding.h"
#include "Bindings/Kenshi/Gui/MapMarkerCharacterBinding.h"
#include "Bindings/Kenshi/Gui/MapMarkerTownBinding.h"
#include "Bindings/Kenshi/Gui/PortraitDataBinding.h"
#include "Bindings/Kenshi/Gui/TutorialGUILineBinding.h"
#include "Bindings/Kenshi/Gui/TutorialItemBinding.h"
#include "Bindings/Kenshi/InventorySectionBinding.h"
#include "Bindings/Kenshi/MedicalSystem_HealthPartStatusBinding.h"
#include "Bindings/Kenshi/RaceLimiter_LimiterBinding.h"
#include "Bindings/Kenshi/RelationDataBinding.h"
#include "Bindings/Kenshi/RootObjectBinding.h"
#include "Bindings/Kenshi/TownBaseBinding.h"
#include "Bindings/Kenshi/TownBuildingsManagerBinding.h"
#include "Bindings/Kenshi/TownBuildingsManager_BuildingInfoBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/Util/OgreUnorderedBinding.h"
#include "Bindings/Kenshi/WorldEventStateQueryBinding.h"
#include "Bindings/Kenshi/ZoneMapBinding.h"
#include "Lua/LuaBindings.h"

#include "Lua/ContainerBinding.h"
#include "Lua/Containers/OgreUnorderedTypes.h"

namespace KenshiLua
{

static const char* const OgreUnorderedMap_BuildingPtr_TownBuildingsManager_BuildingInfoBindingFactories[] = {
    "KenshiLua.Building,KenshiLua.TownBuildingsManager_BuildingInfo",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedMap_BuildingPtr_TownBuildingsManager_BuildingInfoBinding, "ogre_unordered_map<Building*, TownBuildingsManager::BuildingInfo>",
    BuildingBinding::getMetatableName(), TownBuildingsManager_BuildingInfoBinding::getMetatableName(), NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::OgreUnorderedMap_BuildingPtr_TownBuildingsManager_BuildingInfoBinding::createNew, OgreUnorderedMap_BuildingPtr_TownBuildingsManager_BuildingInfoBindingFactories)))

static const char* const OgreUnorderedMap_CharacterPtr_floatBindingFactories[] = {
    "ogre_unordered_map<Character*, float>",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedMap_CharacterPtr_floatBinding, "ogre_unordered_map<Character*, float>",
    CharacterBinding::getMetatableName(), nullptr, NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::OgreUnorderedMap_CharacterPtr_floatBinding::createNew, OgreUnorderedMap_CharacterPtr_floatBindingFactories)))

static const char* const OgreUnorderedMap_CropType_floatBindingFactories[] = {
    "ogre_unordered_map<CropType, float>",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedMap_CropType_floatBinding, "ogre_unordered_map<CropType, float>",
    nullptr, nullptr, NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::OgreUnorderedMap_CropType_floatBinding::createNew, OgreUnorderedMap_CropType_floatBindingFactories)))

static const char* const BountiesMapBindingFactories[] = {
    "KenshiLua.Faction,KenshiLua.Bounty",
};
KENSHILUA_DEFINE_CONTAINER(Containers::BountiesMapBinding, "ogre_unordered_map<Faction*, Bounty>",
    FactionBinding::getMetatableName(), BountyBinding::getMetatableName(), NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::BountiesMapBinding::createNew, BountiesMapBindingFactories)))

static const char* const OgreUnorderedMap_FactionPtr_FactionRelations_RelationDataBindingFactories[] = {
    "KenshiLua.Faction,KenshiLua.RelationData",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedMap_FactionPtr_FactionRelations_RelationDataBinding, "ogre_unordered_map<Faction*, FactionRelationData>",
    FactionBinding::getMetatableName(), RelationDataBinding::getMetatableName(), NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::OgreUnorderedMap_FactionPtr_FactionRelations_RelationDataBinding::createNew, OgreUnorderedMap_FactionPtr_FactionRelations_RelationDataBindingFactories)))

static const char* const OgreUnorderedMap_FactionPtr_boolBindingFactories[] = {
    "ogre_unordered_map<Faction*, bool>",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedMap_FactionPtr_boolBinding, "ogre_unordered_map<Faction*, bool>",
    FactionBinding::getMetatableName(), nullptr, NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::OgreUnorderedMap_FactionPtr_boolBinding::createNew, OgreUnorderedMap_FactionPtr_boolBindingFactories)))

static const char* const OgreUnorderedMap_FactionPtr_floatBindingFactories[] = {
    "ogre_unordered_map<Faction*, float>",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedMap_FactionPtr_floatBinding, "ogre_unordered_map<Faction*, float>",
    FactionBinding::getMetatableName(), nullptr, NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::OgreUnorderedMap_FactionPtr_floatBinding::createNew, OgreUnorderedMap_FactionPtr_floatBindingFactories)))

static const char* const HealthStatusMapBindingFactories[] = {
    "KenshiLua.GameData,KenshiLua.MedicalSystem_HealthPartStatus",
};
KENSHILUA_DEFINE_CONTAINER(Containers::HealthStatusMapBinding, "ogre_unordered_map<GameData*, HealthPartStatus>",
    GameDataBinding::getMetatableName(), HealthPartStatusBinding::getMetatableName(), NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::HealthStatusMapBinding::createNew, HealthStatusMapBindingFactories)))

static const char* const OgreUnorderedMap_GameDataPtr_RaceLimiter_LimiterBindingFactories[] = {
    "KenshiLua.GameData,KenshiLua.Limiter",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedMap_GameDataPtr_RaceLimiter_LimiterBinding, "ogre_unordered_map<GameData*, RaceLimiter::Limiter>",
    GameDataBinding::getMetatableName(), LimiterBinding::getMetatableName(), NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::OgreUnorderedMap_GameDataPtr_RaceLimiter_LimiterBinding::createNew, OgreUnorderedMap_GameDataPtr_RaceLimiter_LimiterBindingFactories)))

static const char* const OgreUnorderedMap_GameDataPtr_WorldStateEnumBindingFactories[] = {
    "ogre_unordered_map<GameData*, WorldStateEnum>",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedMap_GameDataPtr_WorldStateEnumBinding, "ogre_unordered_map<GameData*, WorldStateEnum>",
    GameDataBinding::getMetatableName(), nullptr, NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::OgreUnorderedMap_GameDataPtr_WorldStateEnumBinding::createNew, OgreUnorderedMap_GameDataPtr_WorldStateEnumBindingFactories)))

static const char* const OgreUnorderedMap_GameDataPtr_floatBindingFactories[] = {
    "ogre_unordered_map<GameData*, float>",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedMap_GameDataPtr_floatBinding, "ogre_unordered_map<GameData*, float>",
    GameDataBinding::getMetatableName(), nullptr, NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::OgreUnorderedMap_GameDataPtr_floatBinding::createNew, OgreUnorderedMap_GameDataPtr_floatBindingFactories)))

static const char* const FactionRelationEffectsMapBindingFactories[] = {
    "ogre_unordered_map<GameData*, int>",
};
KENSHILUA_DEFINE_CONTAINER(Containers::FactionRelationEffectsMapBinding, "ogre_unordered_map<GameData*, int>",
    GameDataBinding::getMetatableName(), nullptr, NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::FactionRelationEffectsMapBinding::createNew, FactionRelationEffectsMapBindingFactories)))

static const char* const OgreUnorderedMap_RootObjectPtr_floatBindingFactories[] = {
    "ogre_unordered_map<RootObject*, float>",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedMap_RootObjectPtr_floatBinding, "ogre_unordered_map<RootObject*, float>",
    RootObjectBinding::getMetatableName(), nullptr, NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::OgreUnorderedMap_RootObjectPtr_floatBinding::createNew, OgreUnorderedMap_RootObjectPtr_floatBindingFactories)))

static const char* const OgreUnorderedMap_StatsEnumerated_floatBindingFactories[] = {
    "ogre_unordered_map<StatsEnumerated, float>",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedMap_StatsEnumerated_floatBinding, "ogre_unordered_map<StatsEnumerated, float>",
    nullptr, nullptr, NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::OgreUnorderedMap_StatsEnumerated_floatBinding::createNew, OgreUnorderedMap_StatsEnumerated_floatBindingFactories)))

static const char* const TaskTypeHandMapBindingFactories[] = {
    "ogre_unordered_map<TaskType, hand>",
};
KENSHILUA_DEFINE_CONTAINER(Containers::TaskTypeHandMapBinding, "ogre_unordered_map<TaskType, hand>",
    NULL, NULL, NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::TaskTypeHandMapBinding::createNew, TaskTypeHandMapBindingFactories)))

static const char* const ActiveTutorialsMapBindingFactories[] = {
    "KenshiLua.TutorialItem,KenshiLua.TutorialGUILine",
};
KENSHILUA_DEFINE_CONTAINER(Containers::ActiveTutorialsMapBinding, "ogre_unordered_map<TutorialItem*, TutorialGUILine*>",
    TutorialItemBinding::getMetatableName(), TutorialGUILineBinding::getMetatableName(), NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::ActiveTutorialsMapBinding::createNew, ActiveTutorialsMapBindingFactories)))

static const char* const OgreUnorderedMap_WorldEventStateQueryPtr_boolBindingFactories[] = {
    "ogre_unordered_map<WorldEventStateQuery*, bool>",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedMap_WorldEventStateQueryPtr_boolBinding, "ogre_unordered_map<WorldEventStateQuery*, bool>",
    WorldEventStateQueryBinding::getMetatableName(), nullptr, NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::OgreUnorderedMap_WorldEventStateQueryPtr_boolBinding::createNew, OgreUnorderedMap_WorldEventStateQueryPtr_boolBindingFactories)))

static const char* const OgreUnorderedMap_ZoneMapPtr_boolBindingFactories[] = {
    "ogre_unordered_map<ZoneMap*, bool>",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedMap_ZoneMapPtr_boolBinding, "ogre_unordered_map<ZoneMap*, bool>",
    ZoneMapBinding::getMetatableName(), nullptr, NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::OgreUnorderedMap_ZoneMapPtr_boolBinding::createNew, OgreUnorderedMap_ZoneMapPtr_boolBindingFactories)))

static const char* const OgreUnorderedMap_ZoneMapPtr_unsigned_charBindingFactories[] = {
    "ogre_unordered_map<ZoneMap*, unsigned char>",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedMap_ZoneMapPtr_unsigned_charBinding, "ogre_unordered_map<ZoneMap*, unsigned char>",
    ZoneMapBinding::getMetatableName(), nullptr, NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::OgreUnorderedMap_ZoneMapPtr_unsigned_charBinding::createNew, OgreUnorderedMap_ZoneMapPtr_unsigned_charBindingFactories)))

static const char* const HandTaskInfoMapBindingFactories[] = {
    "KenshiLua.hand,KenshiLua.Blackboard_TaskInfo",
};
KENSHILUA_DEFINE_CONTAINER(Containers::HandTaskInfoMapBinding, "ogre_unordered_map<hand, Blackboard::TaskInfo>",
    HandBinding::getMetatableName(), Blackboard_TaskInfoBinding::getMetatableName(), NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::HandTaskInfoMapBinding::createNew, HandTaskInfoMapBindingFactories)))

static const char* const OgreUnorderedMap_hand_CharacterPtrBindingFactories[] = {
    "KenshiLua.hand,KenshiLua.Character",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedMap_hand_CharacterPtrBinding, "ogre_unordered_map<hand, Character*>",
    HandBinding::getMetatableName(), CharacterBinding::getMetatableName(), NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::OgreUnorderedMap_hand_CharacterPtrBinding::createNew, OgreUnorderedMap_hand_CharacterPtrBindingFactories)))

static const char* const ForgottenInventoryWindowsOpenMapBindingFactories[] = {
    "KenshiLua.hand,KenshiLua.InventoryGUI",
};
KENSHILUA_DEFINE_CONTAINER(Containers::ForgottenInventoryWindowsOpenMapBinding, "ogre_unordered_map<hand, InventoryGUI*>",
    HandBinding::getMetatableName(), InventoryGUIBinding::getMetatableName(), NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::ForgottenInventoryWindowsOpenMapBinding::createNew, ForgottenInventoryWindowsOpenMapBindingFactories)))

static const char* const OgreUnorderedMap_hand_InventorySectionPtrBindingFactories[] = {
    "KenshiLua.hand,KenshiLua.InventorySection",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedMap_hand_InventorySectionPtrBinding, "ogre_unordered_map<hand, InventorySection*>",
    HandBinding::getMetatableName(), InventorySectionBinding::getMetatableName(), NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::OgreUnorderedMap_hand_InventorySectionPtrBinding::createNew, OgreUnorderedMap_hand_InventorySectionPtrBindingFactories)))

static const char* const MapMarkersCharactersMapBindingFactories[] = {
    "KenshiLua.hand,KenshiLua.MapMarkerCharacter",
};
KENSHILUA_DEFINE_CONTAINER(Containers::MapMarkersCharactersMapBinding, "ogre_unordered_map<hand, MapMarkerCharacter*>",
    HandBinding::getMetatableName(), MapMarkerCharacterBinding::getMetatableName(), NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::MapMarkersCharactersMapBinding::createNew, MapMarkersCharactersMapBindingFactories)))

static const char* const MapMarkersTownsMapBindingFactories[] = {
    "KenshiLua.hand,KenshiLua.MapMarkerTown",
};
KENSHILUA_DEFINE_CONTAINER(Containers::MapMarkersTownsMapBinding, "ogre_unordered_map<hand, MapMarkerTown*>",
    HandBinding::getMetatableName(), MapMarkerTownBinding::getMetatableName(), NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::MapMarkersTownsMapBinding::createNew, MapMarkersTownsMapBindingFactories)))

static const char* const MainBarPortraitsMapBindingFactories[] = {
    "KenshiLua.hand,KenshiLua.PortraitData",
};
KENSHILUA_DEFINE_CONTAINER(Containers::MainBarPortraitsMapBinding, "ogre_unordered_map<hand, PortraitData*>",
    HandBinding::getMetatableName(), PortraitDataBinding::getMetatableName(), NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::MainBarPortraitsMapBinding::createNew, MainBarPortraitsMapBindingFactories)))

static const char* const HandTaskRequestMapBindingFactories[] = {
    "KenshiLua.hand,KenshiLua.TaskRequest",
};
KENSHILUA_DEFINE_CONTAINER(Containers::HandTaskRequestMapBinding, "ogre_unordered_map<hand, TaskRequest>",
    HandBinding::getMetatableName(), TaskRequestBinding::getMetatableName(), NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::HandTaskRequestMapBinding::createNew, HandTaskRequestMapBindingFactories)))

static const char* const HandVector3MapBindingFactories[] = {
    "ogre_unordered_map<hand, Vector3>",
};
KENSHILUA_DEFINE_CONTAINER(Containers::HandVector3MapBinding, "ogre_unordered_map<hand, Vector3>",
    HandBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::HandVector3MapBinding::createNew, HandVector3MapBindingFactories)))

static const char* const OgreUnorderedMap_hand_floatBindingFactories[] = {
    "ogre_unordered_map<hand, float>",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedMap_hand_floatBinding, "ogre_unordered_map<hand, float>",
    HandBinding::getMetatableName(), nullptr, NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::OgreUnorderedMap_hand_floatBinding::createNew, OgreUnorderedMap_hand_floatBindingFactories)))

static const char* const HandHandMapBindingFactories[] = {
    "KenshiLua.hand,KenshiLua.hand",
};
KENSHILUA_DEFINE_CONTAINER(Containers::HandHandMapBinding, "ogre_unordered_map<hand, hand>",
    HandBinding::getMetatableName(), HandBinding::getMetatableName(), NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::HandHandMapBinding::createNew, HandHandMapBindingFactories)))

static const char* const OgreUnorderedMap_int_GameDataPtrBindingFactories[] = {
    "ogre_unordered_map<int, GameData*>",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedMap_int_GameDataPtrBinding, "ogre_unordered_map<int, GameData*>",
    nullptr, GameDataBinding::getMetatableName(), NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::OgreUnorderedMap_int_GameDataPtrBinding::createNew, OgreUnorderedMap_int_GameDataPtrBindingFactories)))

static const char* const StatesMapBindingFactories[] = {
    "ogre_unordered_map<itemType, GameData*>",
};
KENSHILUA_DEFINE_CONTAINER(Containers::StatesMapBinding, "ogre_unordered_map<itemType, GameData*>",
    nullptr, GameDataBinding::getMetatableName(), NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::StatesMapBinding::createNew, StatesMapBindingFactories)))

static const char* const SwordStateMapBindingFactories[] = {
    "ogre_unordered_map<swordStateEnum, CombatState*>",
};
KENSHILUA_DEFINE_CONTAINER(Containers::SwordStateMapBinding, "ogre_unordered_map<swordStateEnum, CombatState*>",
    nullptr, nullptr, NULL,
    (ContainerFactoryDefinition("ogre_unordered_map", Containers::SwordStateMapBinding::createNew, SwordStateMapBindingFactories)))

static const char* const OgreUnorderedSet_CharacterPtrBindingFactories[] = {
    "KenshiLua.Character",
    "KenshiLua.Character*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedSet_CharacterPtrBinding, "ogre_unordered_set<Character*>",
    CharacterBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("ogre_unordered_set", Containers::OgreUnorderedSet_CharacterPtrBinding::createNew, OgreUnorderedSet_CharacterPtrBindingFactories)))

static const char* const OgreUnorderedSet_GameDataPtrBindingFactories[] = {
    "KenshiLua.GameData",
    "KenshiLua.GameData*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedSet_GameDataPtrBinding, "ogre_unordered_set<GameData*>",
    GameDataBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("ogre_unordered_set", Containers::OgreUnorderedSet_GameDataPtrBinding::createNew, OgreUnorderedSet_GameDataPtrBindingFactories)))

static const char* const OgreUnorderedSet_RootObjectPtrBindingFactories[] = {
    "KenshiLua.RootObject",
    "KenshiLua.RootObject*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedSet_RootObjectPtrBinding, "ogre_unordered_set<RootObject*>",
    RootObjectBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("ogre_unordered_set", Containers::OgreUnorderedSet_RootObjectPtrBinding::createNew, OgreUnorderedSet_RootObjectPtrBindingFactories)))

static const char* const OgreUnorderedSet_TownBasePtrBindingFactories[] = {
    "KenshiLua.TownBase",
    "KenshiLua.TownBase*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedSet_TownBasePtrBinding, "ogre_unordered_set<TownBase*>",
    TownBaseBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("ogre_unordered_set", Containers::OgreUnorderedSet_TownBasePtrBinding::createNew, OgreUnorderedSet_TownBasePtrBindingFactories)))

static const char* const OgreUnorderedSet_TownBuildingsManagerPtrBindingFactories[] = {
    "KenshiLua.TownBuildingsManager",
    "KenshiLua.TownBuildingsManager*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedSet_TownBuildingsManagerPtrBinding, "ogre_unordered_set<TownBuildingsManager*>",
    TownBuildingsManagerBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("ogre_unordered_set", Containers::OgreUnorderedSet_TownBuildingsManagerPtrBinding::createNew, OgreUnorderedSet_TownBuildingsManagerPtrBindingFactories)))

static const char* const OgreUnorderedSet_WeatherAffectingBindingFactories[] = {
    "ogre_unordered_set<WeatherAffecting>",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedSet_WeatherAffectingBinding, "ogre_unordered_set<WeatherAffecting>",
    nullptr, NULL, NULL,
    (ContainerFactoryDefinition("ogre_unordered_set", Containers::OgreUnorderedSet_WeatherAffectingBinding::createNew, OgreUnorderedSet_WeatherAffectingBindingFactories)))

static const char* const OgreUnorderedSet_ZoneMapPtrBindingFactories[] = {
    "KenshiLua.ZoneMap",
    "KenshiLua.ZoneMap*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::OgreUnorderedSet_ZoneMapPtrBinding, "ogre_unordered_set<ZoneMap*>",
    ZoneMapBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("ogre_unordered_set", Containers::OgreUnorderedSet_ZoneMapPtrBinding::createNew, OgreUnorderedSet_ZoneMapPtrBindingFactories)))

static const char* const ForgottenInventoryWindowsPermanentSetBindingFactories[] = {
    "KenshiLua.hand",
    "KenshiLua.hand*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::ForgottenInventoryWindowsPermanentSetBinding, "ogre_unordered_set<hand>",
    HandBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("ogre_unordered_set", Containers::ForgottenInventoryWindowsPermanentSetBinding::createNew, ForgottenInventoryWindowsPermanentSetBindingFactories)))

void LuaBindings::collectOgreUnordered(ContainerBindingList& definitions)
{
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedMap_BuildingPtr_TownBuildingsManager_BuildingInfoBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedMap_CharacterPtr_floatBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedMap_CropType_floatBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::BountiesMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedMap_FactionPtr_FactionRelations_RelationDataBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedMap_FactionPtr_boolBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedMap_FactionPtr_floatBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::HealthStatusMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedMap_GameDataPtr_RaceLimiter_LimiterBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedMap_GameDataPtr_WorldStateEnumBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedMap_GameDataPtr_floatBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::FactionRelationEffectsMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedMap_RootObjectPtr_floatBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedMap_StatsEnumerated_floatBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::TaskTypeHandMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::ActiveTutorialsMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedMap_WorldEventStateQueryPtr_boolBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedMap_ZoneMapPtr_boolBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedMap_ZoneMapPtr_unsigned_charBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::HandTaskInfoMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedMap_hand_CharacterPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::ForgottenInventoryWindowsOpenMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedMap_hand_InventorySectionPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::MapMarkersCharactersMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::MapMarkersTownsMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::MainBarPortraitsMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::HandTaskRequestMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::HandVector3MapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedMap_hand_floatBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::HandHandMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedMap_int_GameDataPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::StatesMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::SwordStateMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedSet_CharacterPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedSet_GameDataPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedSet_RootObjectPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedSet_TownBasePtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedSet_TownBuildingsManagerPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedSet_WeatherAffectingBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreUnorderedSet_ZoneMapPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::ForgottenInventoryWindowsPermanentSetBinding::MetadataType>());
}

} // namespace KenshiLua
