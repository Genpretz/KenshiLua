#include "pch.h"
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
#include "Bindings/Kenshi/AI/TaskMatchBinding.h"
#include "Bindings/Kenshi/ActivePlatoonBinding.h"
#include "Bindings/Kenshi/Building/CraftingItemBinding.h"
#include "Bindings/Kenshi/CampaignInstanceBinding.h"
#include "Bindings/Kenshi/Character_RagdollMsgBinding.h"
#include "Bindings/Kenshi/CombatTechniqueDataBinding.h"
#include "Bindings/Kenshi/CreatelistItemBinding.h"
#include "Bindings/Kenshi/DialogChoiceListBinding.h"
#include "Bindings/Kenshi/DialogLineDataBinding.h"
#include "Bindings/Kenshi/DialogStateBinding.h"
#include "Bindings/Kenshi/FactionBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/Gui/FactionRelationsLineBinding.h"
#include "Bindings/Kenshi/Gui/InventorySectionGUIBinding.h"
#include "Bindings/Kenshi/Gui/SquadDataBinding.h"
#include "Bindings/Kenshi/ModInfoBinding.h"
#include "Bindings/Kenshi/PlatoonBinding.h"
#include "Bindings/Kenshi/RaceDataBinding.h"
#include "Bindings/Kenshi/RootObjectBinding.h"
#include "Bindings/Kenshi/SpotBinding.h"
#include "Bindings/Kenshi/TaskerBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/Util/StdDequeBinding.h"
#include "Bindings/Kenshi/Util/StdMapBinding.h"
#include "Bindings/Kenshi/Util/StdSetBinding.h"
#include "Lua/LuaBindings.h"

#include "Lua/ContainerBinding.h"
#include "Lua/Containers/StdContainersTypes.h"

namespace KenshiLua
{

KENSHILUA_DEFINE_CONTAINER(Containers::DialogLineDataBoolMapBinding, "boost_unordered_map<DialogLineData*, bool>",
    DialogLineDataBinding::getMetatableName(), nullptr, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::ConversationsMainMapBinding, "boost_unordered_map<std::string, DialogChoiceList>",
    nullptr, DialogChoiceListBinding::getMetatableName(), NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::EventDeliveredStatesMapBinding, "boost_unordered_map<std::string, hand>",
    nullptr, HandBinding::getMetatableName(), NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::CharacterRagdollMsgDequeBinding, "std::deque<Character::RagdollMsg>",
    Character_RagdollMsgBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::CraftingItemDequeBinding, "std::deque<CraftingItem>",
    CraftingItemBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::CreatelistItemDequeBinding, "std::deque<CreatelistItem*>",
    CreatelistItemBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::NestBatcherKillListDequeBinding, "std::deque<NestBatcher*>",
    nullptr, NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::KillListPhase2DequeBinding, "std::deque<RootObject*>",
    RootObjectBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::TaskerDequeBinding, "std::deque<Tasker*>",
    TaskerBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::FloatDequeBinding, "std::deque<float>",
    nullptr, NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::SquadsMapBinding, "std::map<ActivePlatoon*, SquadData*>",
    ActivePlatoonBinding::getMetatableName(), SquadDataBinding::getMetatableName(), NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::StdMap_CombatTechniqueDataPtr_floatBinding, "std::map<CombatTechniqueData*, float>",
    CombatTechniqueDataBinding::getMetatableName(), nullptr, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::EventRepeatTimersMapBinding, "std::map<EventTriggerEnum, float>",
    nullptr, nullptr, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::FactionLinesMapBinding, "std::map<Faction*, FactionRelationsLine*>",
    FactionBinding::getMetatableName(), FactionRelationsLineBinding::getMetatableName(), NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::StdMap_GameDataPtr_boolBinding, "std::map<GameData*, bool>",
    GameDataBinding::getMetatableName(), nullptr, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::BonusRacesMapBinding, "std::map<GameData*, float>",
    GameDataBinding::getMetatableName(), nullptr, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::GameDataHandMapBinding, "std::map<GameData*, hand>",
    GameDataBinding::getMetatableName(), nullptr, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::StdMap_PlatoonPtr_CampaignInstancePtrBinding, "std::map<Platoon*, CampaignInstance*>",
    PlatoonBinding::getMetatableName(), CampaignInstanceBinding::getMetatableName(), NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::TaskMatchBoolMapBinding, "std::map<TaskMatch, bool>",
    TaskMatchBinding::getMetatableName(), nullptr, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::WeatherProtectionsMapBinding, "std::map<WeatherAffecting, float>",
    nullptr, nullptr, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::StdMap_float_CombatTechniqueDataPtrBinding, "std::map<float, CombatTechniqueData*>",
    nullptr, CombatTechniqueDataBinding::getMetatableName(), NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::StdMap_float_GameDataPtrBinding, "std::map<float, GameData*>",
    nullptr, GameDataBinding::getMetatableName(), NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::StdMap_float_TaskerPtrBinding, "std::map<float, Tasker*>",
    nullptr, TaskerBinding::getMetatableName(), NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::StdMap_hand_SensoryData_SpottingPeopleMgr_SpotBinding, "std::map<hand, SensoryData::SpottingPeopleMgr::Spot>",
    HandBinding::getMetatableName(), SpotBinding::getMetatableName(), NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::RepetitionStatesMapBinding, "std::map<std::string, DialogState*>",
    nullptr, DialogStateBinding::getMetatableName(), NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::InventorySectionsMapBinding, "std::map<std::string, InventorySectionGUI*>",
    nullptr, InventorySectionGUIBinding::getMetatableName(), NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::AvailableModsMapBinding, "std::map<std::string, ModInfo>",
    nullptr, ModInfoBinding::getMetatableName(), NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::StdMap_std_string_Ogre_QuaternionBinding, "std::map<std::string, Quaternion>",
    NULL, NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::HandleShiftMapBinding, "std::map<unsigned __int64, unsigned int>",
    nullptr, nullptr, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::StdSet_FactionPtrBinding, "std::set<Faction*>",
    FactionBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::StdSet_GameDataPtrBinding, "std::set<GameData*>",
    GameDataBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::StdSet_RaceDataPtrBinding, "std::set<RaceData*>",
    RaceDataBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::StdSet_handBinding, "std::set<hand>",
    HandBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

static_assert(std::is_same<Containers::StdMap_GameDataPtr_boolBinding::ContainerType,
    decltype(((Inventory::HasRoomCache*)0)->itemStates)>::value, "Inventory::HasRoomCache::itemStates container type mismatch");
static_assert(std::is_same<Containers::GameDataHandMapBinding::ContainerType,
    decltype(((AI::AIResultsCacher*)0)->resourceSourceCache)>::value, "AI::AIResultsCacher::resourceSourceCache container type mismatch");
static_assert(std::is_same<Containers::KillListPhase2DequeBinding::ContainerType,
    decltype(((GameWorld*)0)->killListPhase2)>::value, "GameWorld::killListPhase2 container type mismatch");
static_assert(std::is_same<Containers::NestBatcherKillListDequeBinding::ContainerType,
    decltype(((GameWorld*)0)->nestBatcherKillList)>::value, "GameWorld::nestBatcherKillList container type mismatch");

void LuaBindings::collectStdContainers(ContainerBindingList& definitions)
{
    definitions.push_back(&containerBindingDefinition<Containers::DialogLineDataBoolMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::ConversationsMainMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::EventDeliveredStatesMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::CharacterRagdollMsgDequeBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::CraftingItemDequeBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::CreatelistItemDequeBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::NestBatcherKillListDequeBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::KillListPhase2DequeBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::TaskerDequeBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::FloatDequeBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::SquadsMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::StdMap_CombatTechniqueDataPtr_floatBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::EventRepeatTimersMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::FactionLinesMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::StdMap_GameDataPtr_boolBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::BonusRacesMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::GameDataHandMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::StdMap_PlatoonPtr_CampaignInstancePtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::TaskMatchBoolMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::WeatherProtectionsMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::StdMap_float_CombatTechniqueDataPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::StdMap_float_GameDataPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::StdMap_float_TaskerPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::StdMap_hand_SensoryData_SpottingPeopleMgr_SpotBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::RepetitionStatesMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::InventorySectionsMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::AvailableModsMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::StdMap_std_string_Ogre_QuaternionBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::HandleShiftMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::StdSet_FactionPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::StdSet_GameDataPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::StdSet_RaceDataPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::StdSet_handBinding::MetadataType>());
}

} // namespace KenshiLua
