#pragma once
#include "Lua/Containers/CommonTypes.h"
#include "kenshi/Tasker.h"
#include "kenshi/AI/AI.h"
#include "kenshi/AI/AITaskSystem.h"
#include "kenshi/CharStats.h"
#include "kenshi/CharacterAnimal.h"
#include "kenshi/Dialogue.h"
#include "kenshi/GameWorld.h"
#include "kenshi/HandleManager.h"
#include "kenshi/Item.h"
#include "kenshi/SensoryData.h"
#include "kenshi/gui/FactionsScreen.h"
#include "kenshi/gui/SquadManagementScreen.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/Util/StdDequeBinding.h"
#include "Bindings/Kenshi/Util/StdMapBinding.h"
#include "Bindings/Kenshi/Util/StdSetBinding.h"

namespace KenshiLua
{
namespace Containers
{
typedef StdMapBinding<DialogLineData*, bool> DialogLineDataBoolMapBinding;
typedef StdMapBinding<EventTriggerEnum, DialogChoiceList*> ConversationsMainMapBinding;
typedef StdMapBinding<EventTriggerEnum, hand> EventDeliveredStatesMapBinding;
typedef StdDequeValueBinding<Character::RagdollMsg> CharacterRagdollMsgDequeBinding;
typedef StdDequeValueReadOnlyBinding<CraftingItem> CraftingItemDequeBinding;
typedef StdDequePtrBinding<RootObjectFactory::CreatelistItem*> CreatelistItemDequeBinding;
typedef StdDequePtrBinding<Tasker*> TaskerDequeBinding;
typedef StdDequePrimitiveBinding<float> FloatDequeBinding;
typedef StdMapBinding<ActivePlatoon*, SquadManagementScreen::SquadData*> SquadsMapBinding;
typedef StdMapBinding<CombatTechniqueData*, float> StdMap_CombatTechniqueDataPtr_floatBinding;
typedef StdMapBinding<EventTriggerEnum, float> EventRepeatTimersMapBinding;
typedef StdMapBinding<Faction*, FactionsScreen::FactionRelationsLine*> FactionLinesMapBinding;
typedef StdMapBinding<GameData*, float> BonusRacesMapBinding;
typedef StdMapBinding<Platoon*, CampaignInstance*> StdMap_PlatoonPtr_CampaignInstancePtrBinding;
typedef StdMapBinding<TaskMatch, bool> TaskMatchBoolMapBinding;
typedef StdMapBinding<WeatherAffecting, float> WeatherProtectionsMapBinding;
typedef StdMapBinding<float, CombatTechniqueData*> StdMap_float_CombatTechniqueDataPtrBinding;
typedef StdMapBinding<float, GameData*> StdMap_float_GameDataPtrBinding;
typedef StdMapBinding<float, Tasker*> StdMap_float_TaskerPtrBinding;
typedef StdMapBinding<hand, SensoryData::SpottingPeopleMgr::Spot> StdMap_hand_SensoryData_SpottingPeopleMgr_SpotBinding;
typedef StdMapBinding<EventTriggerEnum, Dialogue::RepetitionCounter::DialogState> RepetitionStatesMapBinding;
typedef StdMapBinding<std::string, InventorySectionGUI*> InventorySectionsMapBinding;
typedef StdMapBinding<std::string, ModInfo> AvailableModsMapBinding;
typedef StdMapBinding<std::string, Ogre::Quaternion> StdMap_std_string_Ogre_QuaternionBinding;
typedef StdMapBinding<unsigned __int64, unsigned int> HandleShiftMapBinding;
typedef StdSetBinding<Faction*> StdSet_FactionPtrBinding;
typedef StdSetBinding<GameData*> StdSet_GameDataPtrBinding;
typedef StdSetBinding<RaceData*> StdSet_RaceDataPtrBinding;
typedef StdSetBinding<hand> StdSet_handBinding;
}
} // namespace KenshiLua
