#pragma once
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
#include "kenshi/NavMesh.h"
#include "kenshi/Renderer.h"
#include "kenshi/Town.h"
#include "kenshi/ZoneManager.h"
#include "kenshi/combat/CombatTechniqueData.h"
#include "kenshi/gui/DatapanelGUI.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"
#include "Bindings/Kenshi/Util/StringPairBinding.h"
#include "Bindings/Kenshi/Util/iVector2Binding.h"

namespace KenshiLua
{
namespace Containers
{
typedef LektorValueBinding<FarmBuilding::SubPlant> SubPlantLektorBinding;
typedef LektorValueBinding<NavMesh::BuildingInfo> NavMeshBuildingInfoLektorBinding;
typedef LektorPtrBinding<AIPackage*> LektorPtr_AIPackagePtrBinding;
typedef LektorPtrBinding<AnimationClassBase::AnimationLayer*> LektorPtr_AnimationClassBase_AnimationLayerPtrBinding;
typedef LektorPtrBinding<AnimationData*> LektorPtr_AnimationDataPtrBinding;
typedef LektorPtrBinding<Armour*> LektorPtr_ArmourPtrBinding;
typedef LektorPtrBinding<Building*> LektorPtr_BuildingPtrBinding;
typedef LektorPtrBinding<Building::ConstructionState::BuildMaterial*> LektorPtr_Building_ConstructionState_BuildMaterialPtrBinding;
typedef LektorValueBinding<StorageBuilding::ConsumptionItem> LektorValue_StorageBuilding_ConsumptionItemBinding;
typedef LektorPtrBinding<CampaignData*> LektorPtr_CampaignDataPtrBinding;
typedef LektorPtrBinding<CampaignInstance*> LektorPtr_CampaignInstancePtrBinding;
typedef LektorPtrBinding<Character*> LektorPtr_CharacterPtrBinding;
typedef LektorPtrBinding<CombatTechniqueData*> CombatTechniqueDataLektorBinding;
typedef LektorValueReadOnlyBinding<CombatTechniqueData::ImpactPoint> LektorValueReadOnly_CombatTechniqueData_ImpactPointBinding;
typedef LektorPtrBinding<DatapanelGUI*> LektorPtr_DatapanelGUIPtrBinding;
typedef LektorPtrBinding<DialogLineData::DialogAction*> LektorPtr_DialogLineData_DialogActionPtrBinding;
typedef LektorPtrBinding<DialogLineData::DialogCondition*> LektorPtr_DialogLineData_DialogConditionPtrBinding;
typedef LektorPtrBinding<DialogLineData*> LektorPtr_DialogLineDataPtrBinding;
typedef LektorPtrBinding<Faction*> LektorPtr_FactionPtrBinding;
typedef LektorValueBinding<Faction::BuildingSwaps> LektorValue_Faction_BuildingSwapsBinding;
typedef LektorPtrBinding<FactionUniqueSquadManager::UniqueSpawnData*> LektorPtr_FactionUniqueSquadManager_UniqueSpawnDataPtrBinding;
typedef LektorPtrBinding<FactionWarMgr::CampaignRequest*> LektorPtr_FactionWarMgr_CampaignRequestPtrBinding;
typedef LektorPtrBinding<FarmBuilding*> LektorPtr_FarmBuildingPtrBinding;
typedef LektorValueBinding<FarmBuilding::Plant> LektorValue_FarmBuilding_PlantBinding;
typedef LektorPtrBinding<FarmBuilding::PlantSource*> LektorPtr_FarmBuilding_PlantSourcePtrBinding;
typedef LektorPtrBinding<GUIWindow*> LektorPtr_GUIWindowPtrBinding;
typedef LektorPtrBinding<GameData*> LektorPtr_GameDataPtrBinding;
typedef LektorPtrBinding<GameData::ObjectInstance*> LektorPtr_GameData_ObjectInstancePtrBinding;
typedef LektorValueReadOnlyBinding<GameDataGroup> LektorValueReadOnly_GameDataGroupBinding;
typedef LektorValueReadOnlyBinding<GameDataValuePair> LektorValueReadOnly_GameDataValuePairBinding;
typedef LektorPtrBinding<MedicalSystem::HealthPartStatus*> LektorPtr_MedicalSystem_HealthPartStatusPtrBinding;
typedef LektorPtrBinding<InventorySection*> LektorPtr_InventorySectionPtrBinding;
typedef LektorPtrBinding<Item*> LektorPtr_ItemPtrBinding;
typedef LektorPtrBinding<ModInfo*> LektorPtr_ModInfoPtrBinding;
typedef LektorValueBinding<ModInfo> LektorValue_ModInfoBinding;
typedef LektorPtrBinding<MyGUI::Button*> LektorPtr_MyGUI_ButtonPtrBinding;
typedef LektorPtrBinding<OrdersReceiver::TaskRequestSimple*> TaskRequestSimpleLektorBinding;
typedef LektorPtrBinding<Platoon*> LektorPtr_PlatoonPtrBinding;
typedef LektorPtrBinding<RenderEntityT*> LektorPtr_RenderEntityTPtrBinding;
typedef LektorValueBinding<TownBase::ResidentData> LektorValue_TownBase_ResidentDataBinding;
typedef LektorPtrBinding<RootObject*> LektorPtr_RootObjectPtrBinding;
typedef LektorValueBinding<SaveInfo> LektorValue_SaveInfoBinding;
typedef LektorPtrBinding<ScreenLabelInterface*> LektorPtr_ScreenLabelInterfacePtrBinding;
typedef LektorPtrBinding<AnimationClassBase::SingleAnimation*> LektorPtr_AnimationClassBase_SingleAnimationPtrBinding;
typedef LektorPtrBinding<StorageBuilding::ConsumptionItem*> LektorPtr_StorageBuilding_ConsumptionItemPtrBinding;
typedef LektorValueBinding<StringPair> LektorValue_StringPairBinding;
typedef LektorValueBinding<TaskRequest> TaskRequestLektorBinding;
typedef LektorPtrBinding<Tasker*> TaskerLektorBinding;
typedef LektorPtrBinding<Town*> LektorPtr_TownPtrBinding;
typedef LektorPtrBinding<TownBase*> LektorPtr_TownBasePtrBinding;
typedef LektorPtrBinding<ZoneMap*> LektorPtr_ZoneMapPtrBinding;
typedef LektorValueBinding<float> LektorValue_floatBinding;
typedef LektorValueBinding<hand> LektorValue_handBinding;
typedef LektorValueBinding<iVector2> LektorValue_iVector2Binding;
typedef LektorIntBinding<int> LektorInt_intBinding;
typedef LektorStringBinding<std::string> LektorString_std_stringBinding;
}
} // namespace KenshiLua
