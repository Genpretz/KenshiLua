#pragma once
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
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/Util/OgreUnorderedBinding.h"

namespace KenshiLua
{
namespace Containers
{
typedef OgreUnorderedMapBinding<Building*, TownBuildingsManager::BuildingInfo> OgreUnorderedMap_BuildingPtr_TownBuildingsManager_BuildingInfoBinding;
typedef OgreUnorderedMapBinding<Character*, float> OgreUnorderedMap_CharacterPtr_floatBinding;
typedef OgreUnorderedMapBinding<CropType, float> OgreUnorderedMap_CropType_floatBinding;
typedef OgreUnorderedMapBinding<Faction*, Bounty> BountiesMapBinding;
typedef OgreUnorderedMapBinding<Faction*, FactionRelations::RelationData> OgreUnorderedMap_FactionPtr_FactionRelations_RelationDataBinding;
typedef OgreUnorderedMapBinding<Faction*, bool> OgreUnorderedMap_FactionPtr_boolBinding;
typedef OgreUnorderedMapBinding<Faction*, float> OgreUnorderedMap_FactionPtr_floatBinding;
typedef OgreUnorderedMapBinding<GameData*, MedicalSystem::HealthPartStatus> HealthStatusMapBinding;
typedef OgreUnorderedMapBinding<GameData*, RaceLimiter::Limiter> OgreUnorderedMap_GameDataPtr_RaceLimiter_LimiterBinding;
typedef OgreUnorderedMapBinding<GameData*, WorldStateEnum> OgreUnorderedMap_GameDataPtr_WorldStateEnumBinding;
typedef OgreUnorderedMapBinding<GameData*, float> OgreUnorderedMap_GameDataPtr_floatBinding;
typedef OgreUnorderedMapBinding<GameData*, int> FactionRelationEffectsMapBinding;
typedef OgreUnorderedMapBinding<RootObject*, float> OgreUnorderedMap_RootObjectPtr_floatBinding;
typedef OgreUnorderedMapBinding<StatsEnumerated, float> OgreUnorderedMap_StatsEnumerated_floatBinding;
typedef OgreUnorderedMapBinding<TaskType, hand> TaskTypeHandMapBinding;
typedef OgreUnorderedMapBinding<TutorialItem*, TutorialGUI::TutorialGUILine*> ActiveTutorialsMapBinding;
typedef OgreUnorderedMapBinding<WorldEventStateQuery*, bool> OgreUnorderedMap_WorldEventStateQueryPtr_boolBinding;
typedef OgreUnorderedMapBinding<ZoneMap*, bool> OgreUnorderedMap_ZoneMapPtr_boolBinding;
typedef OgreUnorderedMapBinding<ZoneMap*, unsigned char> OgreUnorderedMap_ZoneMapPtr_unsigned_charBinding;
typedef OgreUnorderedMapBinding<hand, Blackboard::TaskInfo> HandTaskInfoMapBinding;
typedef OgreUnorderedMapBinding<hand, Character*> OgreUnorderedMap_hand_CharacterPtrBinding;
typedef OgreUnorderedMapBinding<hand, InventoryGUI*> ForgottenInventoryWindowsOpenMapBinding;
typedef OgreUnorderedMapBinding<hand, InventorySection*> OgreUnorderedMap_hand_InventorySectionPtrBinding;
typedef OgreUnorderedMapBinding<hand, MapScreen::MapMarkerCharacter*> MapMarkersCharactersMapBinding;
typedef OgreUnorderedMapBinding<hand, MapScreen::MapMarkerTown*> MapMarkersTownsMapBinding;
typedef OgreUnorderedMapBinding<hand, PortraitData*> MainBarPortraitsMapBinding;
typedef OgreUnorderedMapBinding<hand, TaskRequest> HandTaskRequestMapBinding;
typedef OgreUnorderedMapBinding<hand, Ogre::Vector3> HandVector3MapBinding;
typedef OgreUnorderedMapBinding<hand, float> OgreUnorderedMap_hand_floatBinding;
typedef OgreUnorderedMapBinding<hand, hand> HandHandMapBinding;
typedef OgreUnorderedMapBinding<int, GameData*> OgreUnorderedMap_int_GameDataPtrBinding;
typedef OgreUnorderedMapBinding<itemType, GameData*> StatesMapBinding;
typedef OgreUnorderedMapBinding<swordStateEnum, CombatState*> SwordStateMapBinding;
typedef OgreUnorderedSetBinding<Character*> OgreUnorderedSet_CharacterPtrBinding;
typedef OgreUnorderedSetBinding<GameData*> OgreUnorderedSet_GameDataPtrBinding;
typedef OgreUnorderedSetBinding<RootObject*> OgreUnorderedSet_RootObjectPtrBinding;
typedef OgreUnorderedSetBinding<TownBase*> OgreUnorderedSet_TownBasePtrBinding;
typedef OgreUnorderedSetBinding<TownBuildingsManager*> OgreUnorderedSet_TownBuildingsManagerPtrBinding;
typedef OgreUnorderedSetBinding<WeatherAffecting> OgreUnorderedSet_WeatherAffectingBinding;
typedef OgreUnorderedSetBinding<ZoneMap*> OgreUnorderedSet_ZoneMapPtrBinding;
typedef OgreUnorderedSetBinding<hand> ForgottenInventoryWindowsPermanentSetBinding;
}
} // namespace KenshiLua
