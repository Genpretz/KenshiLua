#include "pch.h"
#include "kenshi/Tasker.h"
#include "kenshi/AI/AITaskSystem.h"
#include "kenshi/Animation/AnimationClass.h"
#include "kenshi/Building/Building.h"
#include "kenshi/Building/ProductionBuilding.h"
#include "kenshi/Building/StorageBuilding.h"
#include "kenshi/Enums.h"
#include "kenshi/Faction.h"
#include "kenshi/FactionUniqueSquadManager.h"
#include "kenshi/FactionWarMgr.h"
#include "kenshi/GameSaveState.h"
#include "kenshi/MedicalSystem.h"
#include "kenshi/Renderer.h"
#include "kenshi/Town.h"
#include "kenshi/ZoneManager.h"
#include "kenshi/combat/CombatTechniqueData.h"
#include "kenshi/faction.h"
#include "kenshi/gui/DatapanelGUI.h"
#include "Bindings/Kenshi/AI/AIPackageBinding.h"
#include "Bindings/Kenshi/AI/OrdersReceiver_TaskRequestSimpleBinding.h"
#include "Bindings/Kenshi/AI/TaskRequestBinding.h"
#include "Bindings/Kenshi/Animation/AnimationClassBase_AnimationLayerBinding.h"
#include "Bindings/Kenshi/Animation/AnimationClassBase_SingleAnimationBinding.h"
#include "Bindings/Kenshi/Animation/AnimationDataBinding.h"
#include "Bindings/Kenshi/ArmourBinding.h"
#include "Bindings/Kenshi/Building/BuildMaterialBinding.h"
#include "Bindings/Kenshi/Building/BuildingBinding.h"
#include "Bindings/Kenshi/Building/ConsumptionItemBinding.h"
#include "Bindings/Kenshi/Building/FarmBuildingBinding.h"
#include "Bindings/Kenshi/Building/FarmBuilding_PlantBinding.h"
#include "Bindings/Kenshi/Building/FarmBuilding_PlantSourceBinding.h"
#include "Bindings/Kenshi/Building/GameDataGroupBinding.h"
#include "Bindings/Kenshi/CampaignDataBinding.h"
#include "Bindings/Kenshi/CampaignInstanceBinding.h"
#include "Bindings/Kenshi/CampaignRequestBinding.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/CombatTechniqueDataBinding.h"
#include "Bindings/Kenshi/DialogActionBinding.h"
#include "Bindings/Kenshi/DialogConditionBinding.h"
#include "Bindings/Kenshi/DialogLineDataBinding.h"
#include "Bindings/Kenshi/FactionBinding.h"
#include "Bindings/Kenshi/Faction_BuildingSwapsBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/GameDataValuePairBinding.h"
#include "Bindings/Kenshi/Gui/DatapanelGUIBinding.h"
#include "Bindings/Kenshi/Gui/GUIWindowBinding.h"
#include "Bindings/Kenshi/Gui/ScreenLabelInterfaceBinding.h"
#include "Bindings/Kenshi/ImpactPointBinding.h"
#include "Bindings/Kenshi/InventorySectionBinding.h"
#include "Bindings/Kenshi/ItemBinding.h"
#include "Bindings/Kenshi/MedicalSystem_HealthPartStatusBinding.h"
#include "Bindings/Kenshi/ModInfoBinding.h"
#include "Bindings/Kenshi/NavMesh_BuildingInfoBinding.h"
#include "Bindings/Kenshi/Building/FarmBuilding_SubPlantBinding.h"
#include "Bindings/Kenshi/ObjectInstanceBinding.h"
#include "Bindings/Kenshi/PlatoonBinding.h"
#include "Bindings/Kenshi/RootObjectBinding.h"
#include "Bindings/Kenshi/SaveInfoBinding.h"
#include "Bindings/Kenshi/TaskerBinding.h"
#include "Bindings/Kenshi/TownBaseBinding.h"
#include "Bindings/Kenshi/TownBinding.h"
#include "Bindings/Kenshi/TownBase_ResidentDataBinding.h"
#include "Bindings/Kenshi/UniqueSpawnDataBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"
#include "Bindings/Kenshi/Util/StringPairBinding.h"
#include "Bindings/Kenshi/Util/iVector2Binding.h"
#include "Bindings/Kenshi/ZoneMapBinding.h"
#include "Bindings/MyGUI/ButtonBinding.h"
#include "Lua/LuaBindings.h"

#include "Lua/ContainerBinding.h"
#include "Lua/Containers/LektorTypes.h"

namespace KenshiLua
{

static const char* const LektorPtr_AIPackagePtrBindingFactories[] = {
    "KenshiLua.AIPackage",
    "KenshiLua.AIPackage*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_AIPackagePtrBinding, "lektor<AIPackage*>",
    AIPackageBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_AIPackagePtrBinding::createNew, LektorPtr_AIPackagePtrBindingFactories)))

static const char* const LektorPtr_AnimationClassBase_AnimationLayerPtrBindingFactories[] = {
    "KenshiLua.AnimationClassBase.AnimationLayer",
    "KenshiLua.AnimationClassBase.AnimationLayer*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_AnimationClassBase_AnimationLayerPtrBinding, "lektor<AnimationClassBase::AnimationLayer*>",
    AnimationClassBase_AnimationLayerBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_AnimationClassBase_AnimationLayerPtrBinding::createNew, LektorPtr_AnimationClassBase_AnimationLayerPtrBindingFactories)))

static const char* const LektorPtr_AnimationDataPtrBindingFactories[] = {
    "KenshiLua.AnimationData",
    "KenshiLua.AnimationData*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_AnimationDataPtrBinding, "lektor<AnimationData*>",
    AnimationDataBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_AnimationDataPtrBinding::createNew, LektorPtr_AnimationDataPtrBindingFactories)))

static const char* const LektorPtr_ArmourPtrBindingFactories[] = {
    "KenshiLua.Armour",
    "KenshiLua.Armour*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_ArmourPtrBinding, "lektor<Armour*>",
    ArmourBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_ArmourPtrBinding::createNew, LektorPtr_ArmourPtrBindingFactories)))

static const char* const LektorPtr_BuildingPtrBindingFactories[] = {
    "KenshiLua.Building",
    "KenshiLua.Building*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_BuildingPtrBinding, "lektor<Building*>",
    BuildingBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_BuildingPtrBinding::createNew, LektorPtr_BuildingPtrBindingFactories)))

static const char* const LektorPtr_Building_ConstructionState_BuildMaterialPtrBindingFactories[] = {
    "KenshiLua.BuildMaterial",
    "KenshiLua.BuildMaterial*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_Building_ConstructionState_BuildMaterialPtrBinding, "lektor<Building::ConstructionState::BuildMaterial*>",
    BuildMaterialBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_Building_ConstructionState_BuildMaterialPtrBinding::createNew, LektorPtr_Building_ConstructionState_BuildMaterialPtrBindingFactories)))

static const char* const LektorValue_StorageBuilding_ConsumptionItemBindingFactories[] = {
    "lektor<Building::ConsumptionItem>",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorValue_StorageBuilding_ConsumptionItemBinding, "lektor<Building::ConsumptionItem>",
    ConsumptionItemBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorValue_StorageBuilding_ConsumptionItemBinding::createNew, LektorValue_StorageBuilding_ConsumptionItemBindingFactories)))

static const char* const LektorPtr_CampaignDataPtrBindingFactories[] = {
    "KenshiLua.CampaignData",
    "KenshiLua.CampaignData*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_CampaignDataPtrBinding, "lektor<CampaignData*>",
    CampaignDataBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_CampaignDataPtrBinding::createNew, LektorPtr_CampaignDataPtrBindingFactories)))

static const char* const LektorPtr_CampaignInstancePtrBindingFactories[] = {
    "KenshiLua.CampaignInstance",
    "KenshiLua.CampaignInstance*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_CampaignInstancePtrBinding, "lektor<CampaignInstance*>",
    CampaignInstanceBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_CampaignInstancePtrBinding::createNew, LektorPtr_CampaignInstancePtrBindingFactories)))

static const char* const LektorPtr_CharacterPtrBindingFactories[] = {
    "KenshiLua.Character",
    "KenshiLua.Character*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_CharacterPtrBinding, "lektor<Character*>",
    CharacterBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_CharacterPtrBinding::createNew, LektorPtr_CharacterPtrBindingFactories)))

static const char* const CombatTechniqueDataLektorBindingFactories[] = {
    "KenshiLua.CombatTechniqueData",
    "KenshiLua.CombatTechniqueData*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::CombatTechniqueDataLektorBinding, "lektor<CombatTechniqueData*>",
    CombatTechniqueDataBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::CombatTechniqueDataLektorBinding::createNew, CombatTechniqueDataLektorBindingFactories)))

static const char* const LektorValueReadOnly_CombatTechniqueData_ImpactPointBindingFactories[] = {
    "KenshiLua.ImpactPoint",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorValueReadOnly_CombatTechniqueData_ImpactPointBinding, "lektor<CombatTechniqueData::ImpactPoint>",
    ImpactPointBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorValueReadOnly_CombatTechniqueData_ImpactPointBinding::createNew, LektorValueReadOnly_CombatTechniqueData_ImpactPointBindingFactories)))

static const char* const LektorPtr_DatapanelGUIPtrBindingFactories[] = {
    "KenshiLua.DatapanelGUI",
    "KenshiLua.DatapanelGUI*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_DatapanelGUIPtrBinding, "lektor<DatapanelGUI*>",
    DatapanelGUIBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_DatapanelGUIPtrBinding::createNew, LektorPtr_DatapanelGUIPtrBindingFactories)))

static const char* const LektorPtr_DialogLineData_DialogActionPtrBindingFactories[] = {
    "KenshiLua.DialogAction",
    "KenshiLua.DialogAction*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_DialogLineData_DialogActionPtrBinding, "lektor<DialogAction*>",
    DialogActionBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_DialogLineData_DialogActionPtrBinding::createNew, LektorPtr_DialogLineData_DialogActionPtrBindingFactories)))

static const char* const LektorPtr_DialogLineData_DialogConditionPtrBindingFactories[] = {
    "KenshiLua.DialogCondition",
    "KenshiLua.DialogCondition*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_DialogLineData_DialogConditionPtrBinding, "lektor<DialogCondition*>",
    DialogConditionBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_DialogLineData_DialogConditionPtrBinding::createNew, LektorPtr_DialogLineData_DialogConditionPtrBindingFactories)))

static const char* const LektorPtr_DialogLineDataPtrBindingFactories[] = {
    "KenshiLua.DialogLineData",
    "KenshiLua.DialogLineData*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_DialogLineDataPtrBinding, "lektor<DialogLineData*>",
    DialogLineDataBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_DialogLineDataPtrBinding::createNew, LektorPtr_DialogLineDataPtrBindingFactories)))

static const char* const LektorPtr_FactionPtrBindingFactories[] = {
    "KenshiLua.Faction",
    "KenshiLua.Faction*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_FactionPtrBinding, "lektor<Faction*>",
    FactionBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_FactionPtrBinding::createNew, LektorPtr_FactionPtrBindingFactories)))

static const char* const LektorValue_Faction_BuildingSwapsBindingFactories[] = {
    "KenshiLua.BuildingSwaps",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorValue_Faction_BuildingSwapsBinding, "lektor<Faction::BuildingSwaps>",
    BuildingSwapsBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorValue_Faction_BuildingSwapsBinding::createNew, LektorValue_Faction_BuildingSwapsBindingFactories)))

static const char* const LektorPtr_FactionUniqueSquadManager_UniqueSpawnDataPtrBindingFactories[] = {
    "KenshiLua.UniqueSpawnData",
    "KenshiLua.UniqueSpawnData*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_FactionUniqueSquadManager_UniqueSpawnDataPtrBinding, "lektor<FactionUniqueSquadManager::UniqueSpawnData*>",
    UniqueSpawnDataBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_FactionUniqueSquadManager_UniqueSpawnDataPtrBinding::createNew, LektorPtr_FactionUniqueSquadManager_UniqueSpawnDataPtrBindingFactories)))

static const char* const LektorPtr_FactionWarMgr_CampaignRequestPtrBindingFactories[] = {
    "KenshiLua.CampaignRequest",
    "KenshiLua.CampaignRequest*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_FactionWarMgr_CampaignRequestPtrBinding, "lektor<FactionWarMgr::CampaignRequest*>",
    CampaignRequestBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_FactionWarMgr_CampaignRequestPtrBinding::createNew, LektorPtr_FactionWarMgr_CampaignRequestPtrBindingFactories)))

static const char* const LektorPtr_FarmBuildingPtrBindingFactories[] = {
    "KenshiLua.FarmBuilding",
    "KenshiLua.FarmBuilding*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_FarmBuildingPtrBinding, "lektor<FarmBuilding*>",
    FarmBuildingBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_FarmBuildingPtrBinding::createNew, LektorPtr_FarmBuildingPtrBindingFactories)))

static const char* const LektorValue_FarmBuilding_PlantBindingFactories[] = {
    "KenshiLua.FarmBuilding_Plant",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorValue_FarmBuilding_PlantBinding, "lektor<FarmBuilding::Plant>",
    FarmBuilding_PlantBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorValue_FarmBuilding_PlantBinding::createNew, LektorValue_FarmBuilding_PlantBindingFactories)))

static const char* const LektorPtr_FarmBuilding_PlantSourcePtrBindingFactories[] = {
    "KenshiLua.FarmBuilding_PlantSource",
    "KenshiLua.FarmBuilding_PlantSource*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_FarmBuilding_PlantSourcePtrBinding, "lektor<FarmBuilding::PlantSource*>",
    FarmBuilding_PlantSourceBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_FarmBuilding_PlantSourcePtrBinding::createNew, LektorPtr_FarmBuilding_PlantSourcePtrBindingFactories)))

static const char* const LektorPtr_GUIWindowPtrBindingFactories[] = {
    "KenshiLua.GUIWindow",
    "KenshiLua.GUIWindow*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_GUIWindowPtrBinding, "lektor<GUIWindow*>",
    GUIWindowBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_GUIWindowPtrBinding::createNew, LektorPtr_GUIWindowPtrBindingFactories)))

static const char* const LektorPtr_GameDataPtrBindingFactories[] = {
    "KenshiLua.GameData",
    "KenshiLua.GameData*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_GameDataPtrBinding, "lektor<GameData*>",
    GameDataBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_GameDataPtrBinding::createNew, LektorPtr_GameDataPtrBindingFactories)))

static const char* const LektorPtr_GameData_ObjectInstancePtrBindingFactories[] = {
    "KenshiLua.ObjectInstance",
    "KenshiLua.ObjectInstance*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_GameData_ObjectInstancePtrBinding, "lektor<GameData::ObjectInstance*>",
    ObjectInstanceBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_GameData_ObjectInstancePtrBinding::createNew, LektorPtr_GameData_ObjectInstancePtrBindingFactories)))

static const char* const LektorValueReadOnly_GameDataGroupBindingFactories[] = {
    "KenshiLua.GameDataGroup",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorValueReadOnly_GameDataGroupBinding, "lektor<GameDataGroup>",
    GameDataGroupBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorValueReadOnly_GameDataGroupBinding::createNew, LektorValueReadOnly_GameDataGroupBindingFactories)))

static const char* const LektorValueReadOnly_GameDataValuePairBindingFactories[] = {
    "KenshiLua.GameDataValuePair",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorValueReadOnly_GameDataValuePairBinding, "lektor<GameDataValuePair>",
    GameDataValuePairBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorValueReadOnly_GameDataValuePairBinding::createNew, LektorValueReadOnly_GameDataValuePairBindingFactories)))

static const char* const LektorPtr_MedicalSystem_HealthPartStatusPtrBindingFactories[] = {
    "KenshiLua.MedicalSystem_HealthPartStatus",
    "KenshiLua.MedicalSystem_HealthPartStatus*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_MedicalSystem_HealthPartStatusPtrBinding, "lektor<HealthPartStatus*>",
    HealthPartStatusBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_MedicalSystem_HealthPartStatusPtrBinding::createNew, LektorPtr_MedicalSystem_HealthPartStatusPtrBindingFactories)))

static const char* const LektorPtr_InventorySectionPtrBindingFactories[] = {
    "KenshiLua.InventorySection",
    "KenshiLua.InventorySection*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_InventorySectionPtrBinding, "lektor<InventorySection*>",
    InventorySectionBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_InventorySectionPtrBinding::createNew, LektorPtr_InventorySectionPtrBindingFactories)))

static const char* const LektorPtr_ItemPtrBindingFactories[] = {
    "KenshiLua.Item",
    "KenshiLua.Item*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_ItemPtrBinding, "lektor<Item*>",
    ItemBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_ItemPtrBinding::createNew, LektorPtr_ItemPtrBindingFactories)))

static const char* const LektorPtr_ModInfoPtrBindingFactories[] = {
    "KenshiLua.ModInfo",
    "KenshiLua.ModInfo*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_ModInfoPtrBinding, "lektor<ModInfo*>",
    ModInfoBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_ModInfoPtrBinding::createNew, LektorPtr_ModInfoPtrBindingFactories)))

static const char* const LektorValue_ModInfoBindingFactories[] = {
    "lektor<ModInfo>",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorValue_ModInfoBinding, "lektor<ModInfo>",
    ModInfoBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorValue_ModInfoBinding::createNew, LektorValue_ModInfoBindingFactories)))

static const char* const LektorPtr_MyGUI_ButtonPtrBindingFactories[] = {
    "KenshiLua.MyGUI.Button",
    "KenshiLua.MyGUI.Button*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_MyGUI_ButtonPtrBinding, "lektor<MyGUI::Button*>",
    ButtonBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_MyGUI_ButtonPtrBinding::createNew, LektorPtr_MyGUI_ButtonPtrBindingFactories)))

static const char* const TaskRequestSimpleLektorBindingFactories[] = {
    "KenshiLua.OrdersReceiver_TaskRequestSimple",
    "KenshiLua.OrdersReceiver_TaskRequestSimple*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::TaskRequestSimpleLektorBinding, "lektor<OrdersReceiver::TaskRequestSimple*>",
    OrdersReceiver_TaskRequestSimpleBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::TaskRequestSimpleLektorBinding::createNew, TaskRequestSimpleLektorBindingFactories)))

static const char* const LektorPtr_PlatoonPtrBindingFactories[] = {
    "KenshiLua.Platoon",
    "KenshiLua.Platoon*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_PlatoonPtrBinding, "lektor<Platoon*>",
    PlatoonBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_PlatoonPtrBinding::createNew, LektorPtr_PlatoonPtrBindingFactories)))

static const char* const LektorPtr_RenderEntityTPtrBindingFactories[] = {
    "lektor<RenderEntityT*>",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_RenderEntityTPtrBinding, "lektor<RenderEntityT*>",
    nullptr, NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_RenderEntityTPtrBinding::createNew, LektorPtr_RenderEntityTPtrBindingFactories)))

static const char* const LektorValue_TownBase_ResidentDataBindingFactories[] = {
    "KenshiLua.TownBase_ResidentData",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorValue_TownBase_ResidentDataBinding, "lektor<ResidentData>",
    TownBase_ResidentDataBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorValue_TownBase_ResidentDataBinding::createNew, LektorValue_TownBase_ResidentDataBindingFactories)))

static const char* const LektorPtr_RootObjectPtrBindingFactories[] = {
    "KenshiLua.RootObject",
    "KenshiLua.RootObject*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_RootObjectPtrBinding, "lektor<RootObject*>",
    RootObjectBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_RootObjectPtrBinding::createNew, LektorPtr_RootObjectPtrBindingFactories)))

static const char* const LektorValue_SaveInfoBindingFactories[] = {
    "KenshiLua.SaveInfo",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorValue_SaveInfoBinding, "lektor<SaveInfo>",
    SaveInfoBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorValue_SaveInfoBinding::createNew, LektorValue_SaveInfoBindingFactories)))

static const char* const LektorPtr_ScreenLabelInterfacePtrBindingFactories[] = {
    "KenshiLua.ScreenLabelInterface",
    "KenshiLua.ScreenLabelInterface*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_ScreenLabelInterfacePtrBinding, "lektor<ScreenLabelInterface*>",
    ScreenLabelInterfaceBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_ScreenLabelInterfacePtrBinding::createNew, LektorPtr_ScreenLabelInterfacePtrBindingFactories)))

static const char* const LektorPtr_AnimationClassBase_SingleAnimationPtrBindingFactories[] = {
    "KenshiLua.AnimationClassBase.SingleAnimation",
    "KenshiLua.AnimationClassBase.SingleAnimation*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_AnimationClassBase_SingleAnimationPtrBinding, "lektor<SingleAnimation*>",
    AnimationClassBase_SingleAnimationBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_AnimationClassBase_SingleAnimationPtrBinding::createNew, LektorPtr_AnimationClassBase_SingleAnimationPtrBindingFactories)))

static const char* const LektorPtr_StorageBuilding_ConsumptionItemPtrBindingFactories[] = {
    "KenshiLua.ConsumptionItem",
    "KenshiLua.ConsumptionItem*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_StorageBuilding_ConsumptionItemPtrBinding, "lektor<StorageBuilding::ConsumptionItem*>",
    ConsumptionItemBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_StorageBuilding_ConsumptionItemPtrBinding::createNew, LektorPtr_StorageBuilding_ConsumptionItemPtrBindingFactories)))

static const char* const LektorValue_StringPairBindingFactories[] = {
    "KenshiLua.StringPair",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorValue_StringPairBinding, "lektor<StringPair>",
    StringPairBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorValue_StringPairBinding::createNew, LektorValue_StringPairBindingFactories)))

static const char* const TaskRequestLektorBindingFactories[] = {
    "KenshiLua.TaskRequest",
};
KENSHILUA_DEFINE_CONTAINER(Containers::TaskRequestLektorBinding, "lektor<TaskRequest>",
    TaskRequestBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::TaskRequestLektorBinding::createNew, TaskRequestLektorBindingFactories)))

static const char* const TaskerLektorBindingFactories[] = {
    "KenshiLua.Tasker",
    "KenshiLua.Tasker*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::TaskerLektorBinding, "lektor<Tasker*>",
    TaskerBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::TaskerLektorBinding::createNew, TaskerLektorBindingFactories)))

static const char* const LektorPtr_TownBasePtrBindingFactories[] = {
    "KenshiLua.TownBase",
    "KenshiLua.TownBase*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_TownBasePtrBinding, "lektor<TownBase*>",
    TownBaseBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_TownBasePtrBinding::createNew, LektorPtr_TownBasePtrBindingFactories)))

static const char* const LektorPtr_ZoneMapPtrBindingFactories[] = {
    "KenshiLua.ZoneMap",
    "KenshiLua.ZoneMap*",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_ZoneMapPtrBinding, "lektor<ZoneMap*>",
    ZoneMapBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_ZoneMapPtrBinding::createNew, LektorPtr_ZoneMapPtrBindingFactories)))

static const char* const LektorValue_floatBindingFactories[] = {
    "lektor<float>",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorValue_floatBinding, "lektor<float>",
    nullptr, NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorValue_floatBinding::createNew, LektorValue_floatBindingFactories)))

static const char* const LektorValue_handBindingFactories[] = {
    "KenshiLua.hand",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorValue_handBinding, "lektor<hand>",
    HandBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorValue_handBinding::createNew, LektorValue_handBindingFactories)))

static const char* const LektorValue_iVector2BindingFactories[] = {
    "KenshiLua.iVector2",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorValue_iVector2Binding, "lektor<iVector2>",
    iVector2Binding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorValue_iVector2Binding::createNew, LektorValue_iVector2BindingFactories)))

static const char* const LektorInt_intBindingFactories[] = {
    "int",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorInt_intBinding, "lektor<int>",
    NULL, NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorInt_intBinding::createNew, LektorInt_intBindingFactories)))

static const char* const LektorString_std_stringBindingFactories[] = {
    "lektor<string>",
    "std::string",
    "string",
};
KENSHILUA_DEFINE_CONTAINER(Containers::LektorString_std_stringBinding, "lektor<std::string>",
    NULL, NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorString_std_stringBinding::createNew, LektorString_std_stringBindingFactories)))

static const char* const TownPointerFactories[] = { "KenshiLua.Town", "KenshiLua.Town*" };
KENSHILUA_DEFINE_CONTAINER(Containers::LektorPtr_TownPtrBinding, "lektor<Town*>",
    TownBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::LektorPtr_TownPtrBinding::createNew, TownPointerFactories)))

static_assert(std::is_same<Containers::LektorPtr_TownPtrBinding::ContainerType,
    decltype(((TownList*)0)->deletedTowns)>::value, "TownList::deletedTowns container type mismatch");

static const char* const SubPlantFactories[] = { "KenshiLua.FarmBuilding_SubPlant" };
KENSHILUA_DEFINE_CONTAINER(Containers::SubPlantLektorBinding, "lektor<FarmBuilding::SubPlant>",
    FarmBuilding_SubPlantBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::SubPlantLektorBinding::createNew, SubPlantFactories)))

static const char* const NavMeshBuildingInfoFactories[] = { "KenshiLua.NavMesh_BuildingInfo" };
KENSHILUA_DEFINE_CONTAINER(Containers::NavMeshBuildingInfoLektorBinding, "lektor<NavMesh::BuildingInfo>",
    NavMesh_BuildingInfoBinding::getMetatableName(), NULL, NULL,
    (ContainerFactoryDefinition("lektor", Containers::NavMeshBuildingInfoLektorBinding::createNew, NavMeshBuildingInfoFactories)))

static_assert(std::is_same<Containers::SubPlantLektorBinding::ContainerType,
    decltype(((FarmBuilding::Plant*)0)->parts)>::value, "FarmBuilding::Plant::parts container type mismatch");
static_assert(std::is_same<Containers::NavMeshBuildingInfoLektorBinding::ContainerType,
    decltype(((NavMesh::NavMeshMessage*)0)->interiors)>::value, "NavMesh::NavMeshMessage::interiors container type mismatch");

void LuaBindings::collectLektor(ContainerBindingList& definitions)
{
    definitions.push_back(&containerBindingDefinition<Containers::SubPlantLektorBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::NavMeshBuildingInfoLektorBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_TownPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_AIPackagePtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_AnimationClassBase_AnimationLayerPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_AnimationDataPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_ArmourPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_BuildingPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_Building_ConstructionState_BuildMaterialPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorValue_StorageBuilding_ConsumptionItemBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_CampaignDataPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_CampaignInstancePtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_CharacterPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::CombatTechniqueDataLektorBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorValueReadOnly_CombatTechniqueData_ImpactPointBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_DatapanelGUIPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_DialogLineData_DialogActionPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_DialogLineData_DialogConditionPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_DialogLineDataPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_FactionPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorValue_Faction_BuildingSwapsBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_FactionUniqueSquadManager_UniqueSpawnDataPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_FactionWarMgr_CampaignRequestPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_FarmBuildingPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorValue_FarmBuilding_PlantBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_FarmBuilding_PlantSourcePtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_GUIWindowPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_GameDataPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_GameData_ObjectInstancePtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorValueReadOnly_GameDataGroupBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorValueReadOnly_GameDataValuePairBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_MedicalSystem_HealthPartStatusPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_InventorySectionPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_ItemPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_ModInfoPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorValue_ModInfoBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_MyGUI_ButtonPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::TaskRequestSimpleLektorBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_PlatoonPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_RenderEntityTPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorValue_TownBase_ResidentDataBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_RootObjectPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorValue_SaveInfoBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_ScreenLabelInterfacePtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_AnimationClassBase_SingleAnimationPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_StorageBuilding_ConsumptionItemPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorValue_StringPairBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::TaskRequestLektorBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::TaskerLektorBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_TownBasePtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorPtr_ZoneMapPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorValue_floatBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorValue_handBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorValue_iVector2Binding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorInt_intBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LektorString_std_stringBinding::MetadataType>());
}

} // namespace KenshiLua
