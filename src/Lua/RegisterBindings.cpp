#include "pch.h"
class CraftingItem {};
#include "Lua/LuaBindings.h"
#include "Bindings/AABB2DBinding.h"
#include "Bindings/AIOptionsBinding.h"
#include "Bindings/AbstractMovementBaseBinding.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/AkSoundPositionBinding.h"
#include "Bindings/AkVectorBinding.h"
#include "Bindings/AnimalInventoryLayoutBinding.h"
#include "Bindings/AppearanceAnimalBinding.h"
#include "Bindings/AppearanceBaseBinding.h"
#include "Bindings/AppearanceHumanBinding.h"
#include "Bindings/ArmourBinding.h"
#include "Bindings/AttachedArrowManagerBinding.h"
#include "Bindings/AttackSlotManagerBinding.h"
#include "Bindings/BackThreadMessagesToMainTBinding.h"
#include "Bindings/BountyBinding.h"
#include "Bindings/BountyManagerBinding.h"
#include "Bindings/Building/BuildInventoryLayoutBinding.h"
#include "Bindings/Building/BuildMaterialBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/Building/BuildingContainerInventoryLayoutBinding.h"
#include "Bindings/Building/BuildingPlacementGroundTypeBinding.h"
#include "Bindings/Building/ConstructionStateBinding.h"
#include "Bindings/Building/ConsumptionItemBinding.h"
#include "Bindings/Building/CraftingBuildingBinding.h"
#include <kenshi/Building/CraftingBuilding.h>
#include "Bindings/Building/CraftingInventoryLayoutBinding.h"
#include "Bindings/Building/DoorStuffBinding.h"
#include "Bindings/Building/FarmBatchBinding.h"
#include "Bindings/Building/FarmBuildingBinding.h"
#include "Bindings/Building/FootprintBinding.h"
#include "Bindings/Building/FootprintNodeBinding.h"
#include "Bindings/Building/FurnaceBuildingBinding.h"
#include "Bindings/Building/FurnaceInventoryLayoutBinding.h"
#include "Bindings/Building/GameDataGroupBinding.h"
#include "Bindings/Building/GatewayBuildingBinding.h"
#include "Bindings/Building/GeneratorBuildingBinding.h"
#include "Bindings/Building/GenericInventoryLayoutBinding.h"
#include "Bindings/Building/LightBuildingBinding.h"
#include "Bindings/Building/PreviewBuildingBinding.h"
#include "Bindings/Building/ProductionBuildingBinding.h"
#include "Bindings/Building/ProductionInventoryLayoutBinding.h"
#include "Bindings/Building/RainCollectorBuildingBinding.h"
#include "Bindings/Building/ResearchBuildingBinding.h"
#include "Bindings/Building/ResearchBuildingInventoryLayoutBinding.h"
#include "Bindings/Building/StorageBuildingBinding.h"
#include "Bindings/Building/TortureBuildingBinding.h"
#include "Bindings/Building/TurretBuildingBinding.h"
#include "Bindings/Building/UseableStuffBinding.h"
#include "Bindings/Building/WallBuildingBinding.h"
#include "Bindings/Building/WindGeneratorBuildingBinding.h"
#include "Bindings/BuildingSwapsBinding.h"
#include "Bindings/CameraClassBinding.h"
#include "Bindings/CampaignRequestBinding.h"
#include "Bindings/CampaignTriggerDataBinding.h"
#include "Bindings/CharBodyBinding.h"
#include "Bindings/CharMovementBinding.h"
#include "Bindings/CharStatsBinding.h"
#include "Bindings/CharacterAnimalBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/CharacterHumanBinding.h"
#include "Bindings/CharacterInventoryLayoutBinding.h"
#include "Bindings/Character_CarryMsgBinding.h"
#include "Bindings/Character_RagdollMsgBinding.h"
#include "Bindings/CombatClassBinding.h"
#include "Bindings/CombatClass_AttackSlotManager_SlotDataBinding.h"
#include "Bindings/CombatClass_EffectDataBinding.h"
#include "Bindings/CombatMovementControllerBinding.h"
#include "Bindings/CombatTechniqueDataBinding.h"
#include "Bindings/ContainerItemBinding.h"
#include "Bindings/CreatelistItemBinding.h"
#include "Bindings/CrossbowBinding.h"
#include "Bindings/DamagesBinding.h"
#include "Bindings/DataObjectContainerBinding.h"
#include "Bindings/DelayedSpawnMsgBinding.h"
#include "Bindings/DialogActionBinding.h"
#include "Bindings/DialogChoiceListBinding.h"
#include "Bindings/DialogConditionBinding.h"
#include "Bindings/DialogDataManagerBinding.h"
#include "Bindings/DialogLineDataBinding.h"
#include "Bindings/DialogStateBinding.h"
#include "Bindings/DialogueBinding.h"
#include "Bindings/DialogueSpeechBubbleBinding.h"
#include "Bindings/EdgeCacheBinding.h"
#include "Bindings/EdgeCache_EdgeBinding.h"
#include "Bindings/EdgePathNodeBinding.h"
#include "Bindings/EntDataBinding.h"
#include "Bindings/EnumBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/FactionLeaderBinding.h"
#include "Bindings/FactionManagerBinding.h"
#include "Bindings/FactionRelationsBinding.h"
#include "Bindings/FactionUniqueSquadManagerBinding.h"
#include "Bindings/FactionWarMgrBinding.h"
#include "Bindings/Faction_CharacteristicsDataBinding.h"
#include "Bindings/FactionsScreen_FactionRelationsLine_LessSortBinding.h"
#include "Bindings/FactoryCallbackInterfaceBinding.h"
#include "Bindings/FarmBuilding_PlantBinding.h"
#include "Bindings/FarmBuilding_PlantSourceBinding.h"
#include "Bindings/FarmBuilding_SubPlantBinding.h"
#include "Bindings/FitnessSelectorBinding.h"
#include "Bindings/FlagConditionBinding.h"
#include "Bindings/FlockingToolsBinding.h"
#include "Bindings/FoliageSystemBinding.h"
#include "Bindings/FormationMoverBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/GameDataCopyStandaloneBinding.h"
#include "Bindings/GameDataEditorWindow_DataItemBinding.h"
#include "Bindings/GameDataHeaderBinding.h"
#include "Bindings/GameDataManagerBinding.h"
#include "Bindings/GameDataReferenceBinding.h"
#include "Bindings/GameDataValuePairBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/GameWorldBinding.h"
#include "Bindings/GameplayOptionsBinding.h"
#include "Bindings/GearBinding.h"
#include "Bindings/GlobalBinding.h"
#include "Bindings/GlobalConstantsBinding.h"
#include "Bindings/Gui/BackpackInventoryLayoutBinding.h"
#include "Bindings/Gui/BaseLayoutBinding.h"
#include "Bindings/Gui/BoxBinding.h"
#include "Bindings/Gui/BuildModeWindowBinding.h"
#include "Bindings/Gui/BuildingCategoryBinding.h"
#include "Bindings/Gui/BuildingGroupBinding.h"
#include "Bindings/Gui/CharacterEditWindowBinding.h"
#include "Bindings/Gui/CharacterStatsWindowBinding.h"
#include "Bindings/Gui/CharacterTradingWindowBinding.h"
#include "Bindings/Gui/ContextMenuBinding.h"
#include "Bindings/Gui/ContextMenuGUIBinding.h"
#include "Bindings/Gui/DataPanelLineBinding.h"
#include "Bindings/Gui/DataPanelLine_ButtonBinding.h"
#include "Bindings/Gui/DataPanelLine_CheckBoxBinding.h"
#include "Bindings/Gui/DataPanelLine_DropBoxBinding.h"
#include "Bindings/Gui/DataPanelLine_FactionBinding.h"
#include "Bindings/Gui/DataPanelLine_KeyConfigBinding.h"
#include "Bindings/Gui/DataPanelLine_ProgressBinding.h"
#include "Bindings/Gui/DataPanelLine_ResearchBinding.h"
#include "Bindings/Gui/DataPanelLine_SliderBinding.h"
#include "Bindings/Gui/DataPanelLine_SliderEditableBinding.h"
#include "Bindings/Gui/DataPanelLine_TextBinding.h"
#include "Bindings/Gui/DataPanelLine_TextEditableBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/Gui/DialogueWindowBinding.h"
#include "Bindings/Gui/FactionListWindowBinding.h"
#include "Bindings/Gui/FactionRelationsLineBinding.h"
#include "Bindings/Gui/FactionsScreenBinding.h"
#include "Bindings/Gui/FloatingProgressBarBinding.h"
#include "Bindings/Gui/FogEditorBinding.h"
#include "Bindings/Gui/ForgottenGUIBinding.h"
#include "Bindings/Gui/GUIWindowBinding.h"
#include "Bindings/Gui/GameDataEditorWindowBinding.h"
#include "Bindings/Gui/GamedataSelectionListBinding.h"
#include "Bindings/Gui/GenericFixedInventoryLayoutBinding.h"
#include "Bindings/Gui/ImportGameMenuBinding.h"
#include "Bindings/Gui/InteriorModeButtonWindowBinding.h"
#include "Bindings/Gui/InventoryGUIBinding.h"
#include "Bindings/Gui/InventoryIconBinding.h"
#include "Bindings/Gui/InventoryLayoutBinding.h"
#include "Bindings/Gui/InventorySectionGUIBinding.h"
#include "Bindings/Gui/InventoryTradeDataBinding.h"
#include "Bindings/Gui/InventoryTraderGUIBinding.h"
#include "Bindings/Gui/ItemListWindowBinding.h"
#include "Bindings/Gui/LevelEditorBinding.h"
#include "Bindings/Gui/ListScrollBarBinding.h"
#include "Bindings/Gui/LoadSaveWindowBinding.h"
#include "Bindings/Gui/LoadingWindowBinding.h"
#include "Bindings/Gui/MainBarGUIBinding.h"
#include "Bindings/Gui/MainTabPortraitPlatoonBinding.h"
#include "Bindings/Gui/ManagementScreenBinding.h"
#include "Bindings/Gui/MapMarkerCharacterBinding.h"
#include "Bindings/Gui/MapMarkerTownBinding.h"
#include "Bindings/Gui/MapScreenBinding.h"
#include "Bindings/Gui/MessageBoxManagerBinding.h"
#include "Bindings/Gui/MultiSliderBinding.h"
#include "Bindings/Gui/NewGameOptionsWindowBinding.h"
#include "Bindings/Gui/NewGameWindowBinding.h"
#include "Bindings/Gui/NpcListWindowBinding.h"
#include "Bindings/Gui/OpenSaveFileDialogBinding.h"
#include "Bindings/Gui/OptionsWindowBinding.h"
#include "Bindings/Gui/OrderCellViewBinding.h"
#include "Bindings/Gui/OrderDataBinding.h"
#include "Bindings/Gui/OrdersItemBoxBinding.h"
#include "Bindings/Gui/OrdersPanelBinding.h"
#include "Bindings/Gui/PortraitDataBinding.h"
#include "Bindings/Gui/PortraitImageBinding.h"
#include "Bindings/Gui/PortraitMainCellViewBinding.h"
#include "Bindings/Gui/PortraitManagerBinding.h"
#include "Bindings/Gui/PortraitSquadCellViewBinding.h"
#include "Bindings/Gui/PortraitSquadItemBoxBinding.h"
#include "Bindings/Gui/ProgressBarWidgetBinding.h"
#include "Bindings/Gui/ProspectingWindowBinding.h"
#include "Bindings/Gui/ReorderableListBinding.h"
#include "Bindings/Gui/ResourceLinePanelBinding.h"
#include "Bindings/Gui/ScreenLabelBinding.h"
#include "Bindings/Gui/ScreenLabelDebugBinding.h"
#include "Bindings/Gui/ScreenLabelInterfaceBinding.h"
#include "Bindings/Gui/SliderBinding.h"
#include "Bindings/Gui/SplashScreenBinding.h"
#include "Bindings/Gui/SquadCellViewBinding.h"
#include "Bindings/Gui/SquadDataBinding.h"
#include "Bindings/Gui/SquadItemBoxBinding.h"
#include "Bindings/Gui/SquadListWindowBinding.h"
#include "Bindings/Gui/SquadManagementScreenBinding.h"
#include "Bindings/Gui/StatBinding.h"
#include "Bindings/Gui/StatGroupBinding.h"
#include "Bindings/Gui/TitleScreenBinding.h"
#include "Bindings/Gui/ToolTipBinding.h"
#include "Bindings/Gui/ToolTipDynamicBinding.h"
#include "Bindings/Gui/ToolTipFixedBinding.h"
#include "Bindings/Gui/ToolTipInventoryBinding.h"
#include "Bindings/Gui/ToolTipLineBinding.h"
#include "Bindings/Gui/ToolTipStaticBinding.h"
#include "Bindings/Gui/TownListWindowBinding.h"
#include "Bindings/Gui/TradeResultBinding.h"
#include "Bindings/Gui/TraderInventoryLayoutBinding.h"
#include "Bindings/Gui/TransformWindowBinding.h"
#include "Bindings/Gui/TutorialGUIBinding.h"
#include "Bindings/Gui/TutorialGUILineBinding.h"
#include "Bindings/Gui/TutorialItemBinding.h"
#include "Bindings/Gui/TutorialSubItemBinding.h"
#include "Bindings/Gui/TutorialpediaGUIBinding.h"
#include "Bindings/Inventory_HasRoomCacheBinding.h"
#include "Bindings/HavokCharacterBinding.h"
#include "Bindings/HealthPartStatusBinding.h"
#include "Bindings/ImpactPointBinding.h"
#include "Bindings/InputHandlerBinding.h"
#include "Bindings/InputHandler_CommandBinding.h"
#include "Bindings/InstanceIDBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/InventoryGUI_FenceCallbackDataBinding.h"
#include "Bindings/InventoryItemBaseBinding.h"
#include "Bindings/InventorySectionBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/ItemDataBinding.h"
#include "Bindings/LightEntBinding.h"
#include "Bindings/LimbsInventoryLayoutBinding.h"
#include "Bindings/LimiterBinding.h"
#include "Bindings/ListenerBinding.h"
#include "Bindings/LockedArmourBinding.h"
#include "Bindings/LoggerBinding.h"
#include "Bindings/MainthreadStateReaderTBinding.h"
#include "Bindings/ManagementScreen_TechItemViewDataBinding.h"
#include "Bindings/MapScreen_MapRoadBinding.h"
#include "Bindings/MedianFilter2DVectorBinding.h"
#include "Bindings/MedianFilterBinding.h"
#include "Bindings/MedicalSystemBinding.h"
#include "Bindings/MeshDataLookupBinding.h"
#include "Bindings/MeshLoadDataBinding.h"
#include "Bindings/MessageChainBinding.h"
#include "Bindings/MessageQueueBinding.h"
#include "Bindings/MessageQueue_NodeBinding.h"
#include "Bindings/ModInfoBinding.h"
#include "Bindings/MotionFilterBinding.h"
#include "Bindings/MustEndWithSemiColonBinding.h"
#include "Bindings/MyGuiBinding.h"
#include "Bindings/NavInstanceBinding.h"
#include "Bindings/NavMeshBinding.h"
#include "Bindings/NavMeshGeneratorBinding.h"
#include "Bindings/NavMeshGenerator_TaskBinding.h"
#include "Bindings/NavMeshGenerator_TaskQueueBinding.h"
#include "Bindings/NavMeshSeedsBinding.h"
#include "Bindings/NavMesh_BuildingInfoBinding.h"
#include "Bindings/NavMesh_NavMeshMessageBinding.h"
#include "Bindings/Nx9RealBinding.h"
#include "Bindings/Nx9Real_SBinding.h"
#include "Bindings/NxBoxBinding.h"
#include "Bindings/NxMat33Binding.h"
#include "Bindings/NxUserControllerHitReportBinding.h"
#include "Bindings/NxUserTriggerReportBinding.h"
#include "Bindings/NxVec3Binding.h"
#include "Bindings/ObjectInstanceBinding.h"
#include "Bindings/OptionsHolderBinding.h"
#include "Bindings/OwnershipsBinding.h"
#include "Bindings/ParticlePoolBinding.h"
#include "Bindings/ParticlePool_ParticleDataBinding.h"
#include "Bindings/PhysicalEntityBinding.h"
#include "Bindings/PhysicsActualBinding.h"
#include "Bindings/PhysicsClassBinding.h"
#include "Bindings/PhysicsCollectionBinding.h"
#include "Bindings/PhysicsInterfaceBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/PlayerInterfaceBinding.h"
#include "Bindings/ProsperityManagerBinding.h"
#include "Bindings/RaceDataBinding.h"
#include "Bindings/RaceLimiterBinding.h"
#include "Bindings/RelationDataBinding.h"
#include "Bindings/RepetitionCounterBinding.h"
#include "Bindings/ResourceLoadRequestMeshBinding.h"
#include "Bindings/ResourceLoadRequestTextureBinding.h"
#include "Bindings/ResourceLoaderBinding.h"
#include "Bindings/RobotLimbItemBinding.h"
#include "Bindings/RobotLimbsBinding.h"
#include "Bindings/RootObjectBaseBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/RootObjectContainerBinding.h"
#include "Bindings/RootObjectFactoryBinding.h"
#include "Bindings/RotatingEntBinding.h"
#include "Bindings/SaveFileSystemBinding.h"
#include "Bindings/SaveFileSystem_FileMessageBinding.h"
#include "Bindings/SaveInfoBinding.h"
#include "Bindings/SaveManagerBinding.h"
#include "Bindings/SectionItemBinding.h"
#include "Bindings/SeenSomeoneBinding.h"
#include "Bindings/SelectionBoxBinding.h"
#include "Bindings/SenseItrBinding.h"
#include "Bindings/SensoryDataBinding.h"
#include "Bindings/ShopTraderBinding.h"
#include "Bindings/ShopTraderInventoryBinding.h"
#include "Bindings/ShopTraderInventorySectionBinding.h"
#include "Bindings/SimpleTimeStamperBinding.h"
#include "Bindings/SpecificItemLoadFirstBinding.h"
#include "Bindings/SpeedGroupBinding.h"
#include "Bindings/SpotBinding.h"
#include "Bindings/SpottingPeopleMgrBinding.h"
#include "Bindings/StateTBinding.h"
#include "Bindings/StaticEntBinding.h"
#include "Bindings/SwordBinding.h"
#include "Bindings/SysMessageBinding.h"
#include "Bindings/TaskDataBinding.h"
#include "Bindings/TaskStateDataBinding.h"
#include "Bindings/TaskerBinding.h"
#include "Bindings/TerrainBinding.h"
#include "Bindings/Terrain_BloodQueueBinding.h"
#include "Bindings/Terrain_BoxBinding.h"
#include "Bindings/Terrain_HitBinding.h"
#include "Bindings/Terrain_InfoBinding.h"
#include "Bindings/TextureArrayLoadDataBinding.h"
#include "Bindings/TextureLoadDataBinding.h"
#include "Bindings/ThreadClassBinding.h"
#include "Bindings/ThreadWannabeBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/TownBase_ResidentDataBinding.h"
#include "Bindings/TownBinding.h"
#include "Bindings/TownBuildingsManagerBinding.h"
#include "Bindings/TownBuildingsManager_BuildingInfoBinding.h"
#include "Bindings/TownPositionCacherBinding.h"
#include "Bindings/Town_NestSpotBinding.h"
#include "Bindings/TradeCultureBinding.h"
#include "Bindings/TraitBoolBinding.h"
#include "Bindings/TreeDataBinding.h"
#include "Bindings/TriggerCallbackBinding.h"
#include "Bindings/UniqueSpawnDataBinding.h"
#include "Bindings/Util/Array2dBinding.h"
#include "Bindings/Util/BadSizeBinding.h"
#include "Bindings/Util/BoostUnorderedBinding.h"
#include "Bindings/Util/BoundsViolationBinding.h"
#include "Bindings/Util/CPerfTimerBinding.h"
#include "Bindings/Util/CPerfTimerTBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"
#include "Bindings/Util/OgreVectorBinding.h"
#include "Bindings/Util/StdDequeBinding.h"
#include "Bindings/Util/StdMapBinding.h"
#include "Bindings/Util/StdSetBinding.h"
#include "Bindings/Util/StringPairBinding.h"
#include "Bindings/Util/TagsClassBinding.h"
#include "Bindings/Util/TimeOfDayBinding.h"
#include "Bindings/Util/TimerClassBinding.h"
#include "Bindings/Util/TripleIntBinding.h"
#include "Bindings/Util/UtilityTBinding.h"
#include "Bindings/Util/YesNoMaybeBinding.h"
#include "Bindings/Util/iVector2Binding.h"
#include "Bindings/Util/rendHitBinding.h"
#include "Bindings/VisibleObjectInfoBinding.h"
#include "Bindings/WeaponBinding.h"
#include "Bindings/WeatherRegionBinding.h"
#include "Bindings/WhoSeesMeBinding.h"
#include "Bindings/WorldEventStateQueryBinding.h"
#include "Bindings/WorldEventStateQueryListBinding.h"
#include "Bindings/ZoneManagerBinding.h"
#include "Bindings/ZoneManagerInterfaceTBinding.h"
#include "Bindings/ZoneManager_BiomeGroundEffectsBinding.h"
#include "Bindings/ZoneMapBinding.h"
#include "Bindings/ZoneSpacialGridBinding.h"
#include "Bindings/ZoneSpacialGrid_ZoneCellBinding.h"
#include "Bindings/hkArrayBaseBinding.h"
#include "Bindings/hkArrayBinding.h"
#include "Bindings/hkBoolBinding.h"
#include "Bindings/hkContainerHeapAllocatorBinding.h"
#include "Bindings/hkContainerHeapAllocator_AllocatorBinding.h"
#include "Bindings/hkMemoryAllocatorBinding.h"
#include "Bindings/hkMemoryAllocator_ExtendedInterfaceBinding.h"
#include "Bindings/hkMemoryAllocator_MemoryStatisticsBinding.h"
#include "Bindings/hkResultBinding.h"
#include "Bindings/hkVector4fBinding.h"
#include "Bindings/hkVector4fComparisonBinding.h"
#include "Bindings/physHitBinding.h"

namespace KenshiLua
{

static void registerInheritance(lua_State* L)
{
// --- ACTIVE INHERITANCE WIRING ---
    setMetatableParent(L, AbstractMovementBaseBinding::getMetatableName(),             NxUserControllerHitReportBinding::getMetatableName());
    setMetatableParent(L, ActivePlatoonBinding::getMetatableName(),                    RootObjectContainerBinding::getMetatableName());
    setMetatableParent(L, AnimalInventoryLayoutBinding::getMetatableName(),            InventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, AppearanceAnimalBinding::getMetatableName(),                 AppearanceBaseBinding::getMetatableName());
    setMetatableParent(L, AppearanceHumanBinding::getMetatableName(),                  AppearanceBaseBinding::getMetatableName());
    setMetatableParent(L, ArmourBinding::getMetatableName(),                           GearBinding::getMetatableName());
    setMetatableParent(L, BackpackInventoryLayoutBinding::getMetatableName(),          GenericFixedInventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, BoxBinding::getMetatableName(),                              wraps::BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, BuildInventoryLayoutBinding::getMetatableName(),             InventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, BuildModeWindowBinding::getMetatableName(),                  wraps::BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, BuildingBinding::getMetatableName(),                         RootObjectBinding::getMetatableName());
    setMetatableParent(L, BuildingContainerInventoryLayoutBinding::getMetatableName(), GenericInventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, CPerfTimerTBinding::getMetatableName(),                      CPerfTimerBinding::getMetatableName());
    setMetatableParent(L, CharMovementBinding::getMetatableName(),                     AbstractMovementBaseBinding::getMetatableName());
    setMetatableParent(L, CharacterAnimalBinding::getMetatableName(),                  CharacterBinding::getMetatableName());
    setMetatableParent(L, CharacterBinding::getMetatableName(),                        RootObjectBinding::getMetatableName());
    setMetatableParent(L, CharacterEditWindowBinding::getMetatableName(),              wraps::BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, CharacterHumanBinding::getMetatableName(),                   CharacterBinding::getMetatableName());
    setMetatableParent(L, CharacterInventoryLayoutBinding::getMetatableName(),         InventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, CharacterStatsWindowBinding::getMetatableName(),             GUIWindowBinding::getMetatableName());
    setMetatableParent(L, CharacterTradingWindowBinding::getMetatableName(),           GUIWindowBinding::getMetatableName());
    setMetatableParent(L, ContainerItemBinding::getMetatableName(),                    ItemBinding::getMetatableName());
    setMetatableParent(L, ContextMenuGUIBinding::getMetatableName(),                   wraps::BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, CraftingBuildingBinding::getMetatableName(),                 ProductionBuildingBinding::getMetatableName());
    setMetatableParent(L, CraftingInventoryLayoutBinding::getMetatableName(),          BuildInventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, CrossbowBinding::getMetatableName(),                         WeaponBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_ButtonBinding::getMetatableName(),             DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_CheckBoxBinding::getMetatableName(),           DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_DropBoxBinding::getMetatableName(),            DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_FactionBinding::getMetatableName(),            DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_KeyConfigBinding::getMetatableName(),          DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_ProgressBinding::getMetatableName(),           DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_ResearchBinding::getMetatableName(),           DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_SliderBinding::getMetatableName(),             DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_SliderEditableBinding::getMetatableName(),     DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_TextBinding::getMetatableName(),               DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_TextEditableBinding::getMetatableName(),       DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DatapanelGUIBinding::getMetatableName(),                     GUIWindowBinding::getMetatableName());
    setMetatableParent(L, DialogueWindowBinding::getMetatableName(),                   GUIWindowBinding::getMetatableName());
    setMetatableParent(L, DoorStuffBinding::getMetatableName(),                        BuildingBinding::getMetatableName());
    setMetatableParent(L, FactionListWindowBinding::getMetatableName(),                KenshiLua::GamedataSelectionListBinding::getMetatableName());
    setMetatableParent(L, FactionRelationsLineBinding::getMetatableName(),             wraps::BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, FarmBuildingBinding::getMetatableName(),                     ProductionBuildingBinding::getMetatableName());
    setMetatableParent(L, FloatingProgressBarBinding::getMetatableName(),              ScreenLabelInterfaceBinding::getMetatableName());
    setMetatableParent(L, FogEditorBinding::getMetatableName(),                        wraps::BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, FootprintNodeBinding::getMetatableName(),                    FootprintBinding::getMetatableName());
    setMetatableParent(L, FurnaceBuildingBinding::getMetatableName(),                  ProductionBuildingBinding::getMetatableName());
    setMetatableParent(L, FurnaceInventoryLayoutBinding::getMetatableName(),           BuildInventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, GatewayBuildingBinding::getMetatableName(),                  BuildingBinding::getMetatableName());
    setMetatableParent(L, GearBinding::getMetatableName(),                             ItemBinding::getMetatableName());
    setMetatableParent(L, GeneratorBuildingBinding::getMetatableName(),                ProductionBuildingBinding::getMetatableName());
    setMetatableParent(L, GenericFixedInventoryLayoutBinding::getMetatableName(),      InventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, GenericInventoryLayoutBinding::getMetatableName(),           InventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, ImportGameMenuBinding::getMetatableName(),                   LoadSaveWindowBinding::getMetatableName());
    setMetatableParent(L, InteriorModeButtonWindowBinding::getMetatableName(),         wraps::BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, InventoryGUIBinding::getMetatableName(),                     GUIWindowBinding::getMetatableName());
    setMetatableParent(L, InventoryIconBinding::getMetatableName(),                    wraps::BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, InventoryItemBaseBinding::getMetatableName(),                RootObjectBinding::getMetatableName());
    setMetatableParent(L, InventoryLayoutBinding::getMetatableName(),                  wraps::BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, InventoryTraderGUIBinding::getMetatableName(),               InventoryGUIBinding::getMetatableName());
    setMetatableParent(L, ItemBinding::getMetatableName(),                             InventoryItemBaseBinding::getMetatableName());
    setMetatableParent(L, ItemListWindowBinding::getMetatableName(),                   GamedataSelectionListBinding::getMetatableName());
    setMetatableParent(L, LightBuildingBinding::getMetatableName(),                    UseableStuffBinding::getMetatableName());
    setMetatableParent(L, LimbsInventoryLayoutBinding::getMetatableName(),             InventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, LoadSaveWindowBinding::getMetatableName(),                   wraps::BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, LoadingWindowBinding::getMetatableName(),                    wraps::BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, LockedArmourBinding::getMetatableName(),                     ArmourBinding::getMetatableName());
    setMetatableParent(L, MainBarGUIBinding::getMetatableName(),                       GUIWindowBinding::getMetatableName());
    setMetatableParent(L, ManagementScreenBinding::getMetatableName(),                 wraps::BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, MultiSliderBinding::getMetatableName(),                      MyGuiBinding::getMetatableName());
    setMetatableParent(L, NavMeshBinding::getMetatableName(),                          ThreadClassBinding::getMetatableName());
    setMetatableParent(L, NavMeshGeneratorBinding::getMetatableName(),                 ThreadClassBinding::getMetatableName());
    setMetatableParent(L, NewGameOptionsWindowBinding::getMetatableName(),             wraps::BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, NewGameWindowBinding::getMetatableName(),                    GUIWindowBinding::getMetatableName());
    setMetatableParent(L, NpcListWindowBinding::getMetatableName(),                    KenshiLua::GamedataSelectionListBinding::getMetatableName());
    setMetatableParent(L, OpenSaveFileDialogBinding::getMetatableName(),               wraps::BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, OptionsWindowBinding::getMetatableName(),                    GUIWindowBinding::getMetatableName());
    setMetatableParent(L, PhysicsActualBinding::getMetatableName(),                    PhysicsInterfaceBinding::getMetatableName());
    setMetatableParent(L, PhysicsInterfaceBinding::getMetatableName(),                 ThreadWannabeBinding::getMetatableName());
    setMetatableParent(L, PlatoonBinding::getMetatableName(),                          RootObjectBaseBinding::getMetatableName());
    setMetatableParent(L, PlayerInterfaceBinding::getMetatableName(),                  FactoryCallbackInterfaceBinding::getMetatableName());
    setMetatableParent(L, ProductionBuildingBinding::getMetatableName(),               StorageBuildingBinding::getMetatableName());
    setMetatableParent(L, ProductionInventoryLayoutBinding::getMetatableName(),        BuildInventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, ProgressBarWidgetBinding::getMetatableName(),                wraps::BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, ProspectingWindowBinding::getMetatableName(),                wraps::BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, RainCollectorBuildingBinding::getMetatableName(),            ProductionBuildingBinding::getMetatableName());
    setMetatableParent(L, ResearchBuildingBinding::getMetatableName(),                 UseableStuffBinding::getMetatableName());
    setMetatableParent(L, ResearchBuildingInventoryLayoutBinding::getMetatableName(),  GenericInventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, ResourceLinePanelBinding::getMetatableName(),                wraps::BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, RobotLimbItemBinding::getMetatableName(),                    ItemBinding::getMetatableName());
    setMetatableParent(L, RootObjectBinding::getMetatableName(),                       RootObjectBaseBinding::getMetatableName());
    setMetatableParent(L, RootObjectContainerBinding::getMetatableName(),              DataObjectContainerBinding::getMetatableName());
    setMetatableParent(L, RotatingEntBinding::getMetatableName(),                      StaticEntBinding::getMetatableName());
    setMetatableParent(L, SaveFileSystemBinding::getMetatableName(),                   ThreadClassBinding::getMetatableName());
    setMetatableParent(L, ScreenLabelBinding::getMetatableName(),                      ScreenLabelInterfaceBinding::getMetatableName());
    setMetatableParent(L, ScreenLabelDebugBinding::getMetatableName(),                 ScreenLabelBinding::getMetatableName());
    setMetatableParent(L, ShopTraderBinding::getMetatableName(),                       RootObjectBinding::getMetatableName());
    setMetatableParent(L, ShopTraderInventoryBinding::getMetatableName(),              InventoryBinding::getMetatableName());
    setMetatableParent(L, ShopTraderInventorySectionBinding::getMetatableName(),       InventorySectionBinding::getMetatableName());
    setMetatableParent(L, SliderBinding::getMetatableName(),                           MyGuiBinding::getMetatableName());
    setMetatableParent(L, SquadListWindowBinding::getMetatableName(),                  GamedataSelectionListBinding::getMetatableName());
    setMetatableParent(L, StaticEntBinding::getMetatableName(),                        PhysicalEntityBinding::getMetatableName());
    setMetatableParent(L, StorageBuildingBinding::getMetatableName(),                  UseableStuffBinding::getMetatableName());
    setMetatableParent(L, SwordBinding::getMetatableName(),                            WeaponBinding::getMetatableName());
    setMetatableParent(L, TextureArrayLoadDataBinding::getMetatableName(),             TextureLoadDataBinding::getMetatableName());
    setMetatableParent(L, ThreadWannabeBinding::getMetatableName(),                    ThreadClassBinding::getMetatableName());
    setMetatableParent(L, TitleScreenBinding::getMetatableName(),                      GUIWindowBinding::getMetatableName());
    setMetatableParent(L, ToolTipDynamicBinding::getMetatableName(),                   ToolTipBinding::getMetatableName());
    setMetatableParent(L, ToolTipFixedBinding::getMetatableName(),                     ToolTipBinding::getMetatableName());
    setMetatableParent(L, ToolTipInventoryBinding::getMetatableName(),                 ToolTipBinding::getMetatableName());
    setMetatableParent(L, ToolTipStaticBinding::getMetatableName(),                    ToolTipBinding::getMetatableName());
    setMetatableParent(L, TortureBuildingBinding::getMetatableName(),                  ProductionBuildingBinding::getMetatableName());
    setMetatableParent(L, TownBaseBinding::getMetatableName(),                         RootObjectBinding::getMetatableName());
    setMetatableParent(L, TownBinding::getMetatableName(),                             TownBaseBinding::getMetatableName());
    setMetatableParent(L, TownBuildingsManagerBinding::getMetatableName(),             FactoryCallbackInterfaceBinding::getMetatableName());
    setMetatableParent(L, TownListWindowBinding::getMetatableName(),                   NpcListWindowBinding::getMetatableName());
    setMetatableParent(L, TraderInventoryLayoutBinding::getMetatableName(),            InventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, TriggerCallbackBinding::getMetatableName(),                  NxUserTriggerReportBinding::getMetatableName());
    setMetatableParent(L, TurretBuildingBinding::getMetatableName(),                   UseableStuffBinding::getMetatableName());
    setMetatableParent(L, TutorialGUIBinding::getMetatableName(),                      GUIWindowBinding::getMetatableName());
    setMetatableParent(L, TutorialGUILineBinding::getMetatableName(),                  wraps::BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, TutorialpediaGUIBinding::getMetatableName(),                 GUIWindowBinding::getMetatableName());
    setMetatableParent(L, UseableStuffBinding::getMetatableName(),                     BuildingBinding::getMetatableName());
    setMetatableParent(L, WallBuildingBinding::getMetatableName(),                     BuildingBinding::getMetatableName());
    setMetatableParent(L, WeaponBinding::getMetatableName(),                           GearBinding::getMetatableName());
    setMetatableParent(L, WindGeneratorBuildingBinding::getMetatableName(),            GeneratorBuildingBinding::getMetatableName());
    setMetatableParent(L, ZoneManagerBinding::getMetatableName(),                      ZoneManagerInterfaceTBinding::getMetatableName());

// --- FUTURE / COMMENTED-OUT INHERITANCE ---
    // setMetatableParent(L, AppearanceBaseBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, AttackSlotManagerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, CharBodyBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, CharStatsBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, CombatClassBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, ConstructionStateBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, DamagesBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, DataPanelLineBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, EntDataBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, FoliageSystemBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, ForgottenGUIBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, GUIWindowBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, GameDataEditorWindowBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, InputHandlerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, InventoryBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, LevelEditorBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, ListScrollBarBinding::getMetatableName(), ScrollBarBinding::getMetatableName());
    // setMetatableParent(L, MainTabPortraitPlatoonBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, MeshDataLookupBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, MessageBoxManagerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, OrderDataBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, OrdersPanelBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, ParticlePoolBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, PhysicalEntityBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, PhysicsCollectionBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, PortraitDataBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, PortraitImageBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, PortraitManagerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, PreviewBuildingBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, ResourceLoaderBinding::getMetatableName(), Ogre::ResourceBackgroundQueue::ListenerBinding::getMetatableName());
    // setMetatableParent(L, RootObjectFactoryBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, SaveManagerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, ScreenLabelInterfaceBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, SelectionBoxBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, TaskDataBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, TaskerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, TerrainBinding::getMetatableName(), Ogre::MovableObjectBinding::getMetatableName());
    // setMetatableParent(L, ToolTipBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, TransformWindowBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, TreeDataBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, TutorialItemBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, TutorialSubItemBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, WeatherRegionBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, ZoneMapBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
}

void LuaBindings::registerAll(lua_State* L)
{
    installKenshiLuaTable(L);

    // Register Enums
    registerEnumBindings(L);

    // Register templates centrally before classes are bound
    LektorPtrBinding<Character*>::registerBinding(L, "lektor<Character*>", CharacterBinding::getMetatableName());
    LektorPtrBinding<ModInfo*>::registerBinding(L, "lektor<ModInfo*>", ModInfoBinding::getMetatableName());
    LektorPtrBinding<GameData::ObjectInstance*>::registerBinding(L, "lektor<GameData::ObjectInstance*>", ObjectInstanceBinding::getMetatableName());
    LektorPtrBinding<GameData*>::registerBinding(L, "lektor<GameData*>", GameDataBinding::getMetatableName());
    LektorPtrBinding<DialogLineData::DialogCondition*>::registerBinding(L, "lektor<DialogCondition*>", DialogConditionBinding::getMetatableName());
    LektorPtrBinding<DialogLineData::DialogAction*>::registerBinding(L, "lektor<DialogAction*>", DialogActionBinding::getMetatableName());
    LektorPtrBinding<DialogLineData*>::registerBinding(L, "lektor<DialogLineData*>", DialogLineDataBinding::getMetatableName());
    LektorPtrBinding<CombatTechniqueData*>::registerBinding(L, "lektor<CombatTechniqueData*>", CombatTechniqueDataBinding::getMetatableName());
    LektorPtrBinding<Item*>::registerBinding(L, "lektor<Item*>", ItemBinding::getMetatableName());
    LektorPtrBinding<InventorySection*>::registerBinding(L, "lektor<InventorySection*>", InventorySectionBinding::getMetatableName());
    LektorPtrBinding<RootObject*>::registerBinding(L, "lektor<RootObject*>", RootObjectBinding::getMetatableName());
    LektorPtrBinding<FarmBuilding*>::registerBinding(L, "lektor<FarmBuilding*>", FarmBuildingBinding::getMetatableName());

    LektorValueBinding<ModInfo>::registerBinding(L, "lektor<ModInfo>", ModInfoBinding::getMetatableName());
    LektorValueBinding<hand>::registerBinding(L, "lektor<hand>", HandBinding::getMetatableName());

    LektorValueReadOnlyBinding<GameDataValuePair>::registerBinding(L, "lektor<GameDataValuePair>", GameDataValuePairBinding::getMetatableName());

    LektorStringBinding<std::string>::registerBinding(L, "lektor<string>");
    LektorIntBinding<int>::registerBinding(L, "lektor<int>");
    
    OgreUnorderedSetBinding<hand>::registerBinding(L, "ogre_unordered_set<hand>", HandBinding::getMetatableName());
    OgreUnorderedSetBinding<GameData*>::registerBinding(L, "ogre_unordered_set<GameData*>", GameDataBinding::getMetatableName());
    OgreUnorderedSetBinding<TownBase*>::registerBinding(L, "ogre_unordered_set<TownBase*>", TownBaseBinding::getMetatableName());
    OgreUnorderedSetBinding<Character*>::registerBinding(L, "ogre_unordered_set<Character*>", CharacterBinding::getMetatableName());
    OgreUnorderedSetBinding<RootObject*>::registerBinding(L, "ogre_unordered_set<RootObject*>", RootObjectBinding::getMetatableName());
    OgreUnorderedSetBinding<ZoneMap*>::registerBinding(L, "ogre_unordered_set<ZoneMap*>", ZoneMapBinding::getMetatableName());

    OgreUnorderedMapBinding<RootObject*, float>::registerBinding(L, "ogre_unordered_map<RootObject*, float>", RootObjectBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<hand, float>::registerBinding(L, "ogre_unordered_map<hand, float>", HandBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<hand, Character*>::registerBinding(L, "ogre_unordered_map<hand, Character*>", HandBinding::getMetatableName(), CharacterBinding::getMetatableName());
    OgreUnorderedMapBinding<GameData*, float>::registerBinding(L, "ogre_unordered_map<GameData*, float>", GameDataBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<ZoneMap*, unsigned char>::registerBinding(L, "ogre_unordered_map<ZoneMap*, unsigned char>", ZoneMapBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<ZoneMap*, bool>::registerBinding(L, "ogre_unordered_map<ZoneMap*, bool>", ZoneMapBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<Faction*, bool>::registerBinding(L, "ogre_unordered_map<Faction*, bool>", FactionBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<GameData*, WorldStateEnum>::registerBinding(L, "ogre_unordered_map<GameData*, WorldStateEnum>", GameDataBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<WorldEventStateQuery*, bool>::registerBinding(L, "ogre_unordered_map<WorldEventStateQuery*, bool>", WorldEventStateQueryBinding::getMetatableName(), nullptr);

    StdMapBinding<float, CombatTechniqueData*>::registerBinding(L, "std::map<float, CombatTechniqueData*>", nullptr, CombatTechniqueDataBinding::getMetatableName());
    StdMapBinding<CombatTechniqueData*, float>::registerBinding(L, "std::map<CombatTechniqueData*, float>", CombatTechniqueDataBinding::getMetatableName(), nullptr);
    StdMapBinding<float, GameData*>::registerBinding(L, "std::map<float, GameData*>", nullptr, GameDataBinding::getMetatableName());
    StdMapBinding<GameData*, float>::registerBinding(L, "std::map<GameData*, float>", GameDataBinding::getMetatableName(), nullptr);
    StdMapBinding<GameData*, bool, std::less<GameData*>, std::allocator<std::pair<GameData* const, bool>>>::registerBinding(L, "std::map<GameData*, bool>", GameDataBinding::getMetatableName(), nullptr);

    StdSetBinding<hand>::registerBinding(L, "std::set<hand>", HandBinding::getMetatableName());
    StdSetBinding<Faction*>::registerBinding(L, "std::set<Faction*>", FactionBinding::getMetatableName());
    StdSetBinding<GameData*>::registerBinding(L, "std::set<GameData*>", GameDataBinding::getMetatableName());
    
    FitnessSelectorBinding<CombatTechniqueData*>::registerBinding(L, "FitnessSelector<CombatTechniqueData*>", CombatTechniqueDataBinding::getMetatableName(), "std::map<float, CombatTechniqueData*>", "std::map<CombatTechniqueData*, float>");
    FitnessSelectorBinding<GameData*>::registerBinding(L, "FitnessSelector<GameData*>", GameDataBinding::getMetatableName(), "std::map<float, GameData*>", "std::map<GameData*, float>");

    StdDequePtrBinding<RootObject*, Ogre::STLAllocator<RootObject*, Ogre::GeneralAllocPolicy>>::registerBinding(L, "std::deque<RootObject*>", RootObjectBinding::getMetatableName());
    StdDequePtrBinding<NestBatcher*, Ogre::STLAllocator<NestBatcher*, Ogre::GeneralAllocPolicy>>::registerBinding(L, "std::deque<NestBatcher*>", nullptr);
    StdDequePtrBinding<RootObjectFactory::CreatelistItem*>::registerBinding(L, "std::deque<CreatelistItem*>", CreatelistItemBinding::getMetatableName());
    StdDequeValueBinding<CraftingItem>::registerBinding(L, "std::deque<CraftingItem>", nullptr);
    StdDequeValueBinding<Character::RagdollMsg>::registerBinding(L, "std::deque<Character::RagdollMsg>", Character_RagdollMsgBinding::getMetatableName());
    StdDequePrimitiveBinding<float>::registerBinding(L, "std::deque<float>", nullptr);

    // Register Classes
    AABB2DBinding::registerBinding(L);
    AIOptionsBinding::registerBinding(L);
    AbstractMovementBaseBinding::registerBinding(L);
    ActivePlatoonBinding::registerBinding(L);
    AkSoundPositionBinding::registerBinding(L);
    AkVectorBinding::registerBinding(L);
    AnimalInventoryLayoutBinding::registerBinding(L);
    AppearanceAnimalBinding::registerBinding(L);
    AppearanceBaseBinding::registerBinding(L);
    AppearanceHumanBinding::registerBinding(L);
    ArmourBinding::registerBinding(L);
    AttachedArrowManagerBinding::registerBinding(L);
    AttackSlotManagerBinding::registerBinding(L);
    BackThreadMessagesToMainTBinding::registerBinding(L);
    BackpackInventoryLayoutBinding::registerBinding(L);
    BountyBinding::registerBinding(L);
    BountyManagerBinding::registerBinding(L);
    BoxBinding::registerBinding(L);
    BuildInventoryLayoutBinding::registerBinding(L);
    BuildMaterialBinding::registerBinding(L);
    BuildModeWindowBinding::registerBinding(L);
    BuildingBinding::registerBinding(L);
    BuildingCategoryBinding::registerBinding(L);
    BuildingContainerInventoryLayoutBinding::registerBinding(L);
    BuildingGroupBinding::registerBinding(L);
    BuildingPlacementGroundTypeBinding::registerBinding(L);
    BuildingSwapsBinding::registerBinding(L);
    CPerfTimerBinding::registerBinding(L);
    CPerfTimerTBinding::registerBinding(L);
    CameraClassBinding::registerBinding(L);
    CampaignRequestBinding::registerBinding(L);
    CampaignTriggerDataBinding::registerBinding(L);
    CharBodyBinding::registerBinding(L);
    CharMovementBinding::registerBinding(L);
    CharStatsBinding::registerBinding(L);
    CharacterAnimalBinding::registerBinding(L);
    CharacterBinding::registerBinding(L);
    CharacterEditWindowBinding::registerBinding(L);
    CharacterHumanBinding::registerBinding(L);
    CharacterInventoryLayoutBinding::registerBinding(L);
    CharacterStatsWindowBinding::registerBinding(L);
    CharacterTradingWindowBinding::registerBinding(L);
    Character_CarryMsgBinding::registerBinding(L);
    Character_RagdollMsgBinding::registerBinding(L);
    CombatClassBinding::registerBinding(L);
    CombatClass_AttackSlotManager_SlotDataBinding::registerBinding(L);
    CombatClass_EffectDataBinding::registerBinding(L);
    CombatMovementControllerBinding::registerBinding(L);
    CombatTechniqueDataBinding::registerBinding(L);
    ConstructionStateBinding::registerBinding(L);
    ConsumptionItemBinding::registerBinding(L);
    ContainerItemBinding::registerBinding(L);
    ContextMenuBinding::registerBinding(L);
    ContextMenuGUIBinding::registerBinding(L);
    CraftingBuildingBinding::registerBinding(L);
    CraftingInventoryLayoutBinding::registerBinding(L);
    CreatelistItemBinding::registerBinding(L);
    CrossbowBinding::registerBinding(L);
    DamagesBinding::registerBinding(L);
    DataObjectContainerBinding::registerBinding(L);
    DataPanelLineBinding::registerBinding(L);
    DataPanelLine_ButtonBinding::registerBinding(L);
    DataPanelLine_CheckBoxBinding::registerBinding(L);
    DataPanelLine_DropBoxBinding::registerBinding(L);
    DataPanelLine_FactionBinding::registerBinding(L);
    DataPanelLine_KeyConfigBinding::registerBinding(L);
    DataPanelLine_ProgressBinding::registerBinding(L);
    DataPanelLine_ResearchBinding::registerBinding(L);
    DataPanelLine_SliderBinding::registerBinding(L);
    DataPanelLine_SliderEditableBinding::registerBinding(L);
    DataPanelLine_TextBinding::registerBinding(L);
    DataPanelLine_TextEditableBinding::registerBinding(L);
    DatapanelGUIBinding::registerBinding(L);
    DelayedSpawnMsgBinding::registerBinding(L);
    DialogActionBinding::registerBinding(L);
    DialogChoiceListBinding::registerBinding(L);
    DialogConditionBinding::registerBinding(L);
    DialogDataManagerBinding::registerBinding(L);
    DialogLineDataBinding::registerBinding(L);
    DialogStateBinding::registerBinding(L);
    DialogueBinding::registerBinding(L);
    DialogueSpeechBubbleBinding::registerBinding(L);
    DialogueWindowBinding::registerBinding(L);
    DoorStuffBinding::registerBinding(L);
    EdgeCacheBinding::registerBinding(L);
    EdgeCache_EdgeBinding::registerBinding(L);
    EdgePathNodeBinding::registerBinding(L);
    EntDataBinding::registerBinding(L);
    FactionBinding::registerBinding(L);
    FactionLeaderBinding::registerBinding(L);
    FactionListWindowBinding::registerBinding(L);
    FactionManagerBinding::registerBinding(L);
    FactionRelationsBinding::registerBinding(L);
    FactionRelationsLineBinding::registerBinding(L);
    FactionUniqueSquadManagerBinding::registerBinding(L);
    FactionWarMgrBinding::registerBinding(L);
    Faction_CharacteristicsDataBinding::registerBinding(L);
    FactionsScreenBinding::registerBinding(L);
    FactionsScreen_FactionRelationsLine_LessSortBinding::registerBinding(L);
    FactoryCallbackInterfaceBinding::registerBinding(L);
    FarmBatchBinding::registerBinding(L);
    FarmBuildingBinding::registerBinding(L);
    FarmBuilding_PlantBinding::registerBinding(L);
    FarmBuilding_PlantSourceBinding::registerBinding(L);
    FarmBuilding_SubPlantBinding::registerBinding(L);
    FlagConditionBinding::registerBinding(L);
    FloatingProgressBarBinding::registerBinding(L);
    FlockingToolsBinding::registerBinding(L);
    FogEditorBinding::registerBinding(L);
    FoliageSystemBinding::registerBinding(L);
    FootprintBinding::registerBinding(L);
    FootprintNodeBinding::registerBinding(L);
    ForgottenGUIBinding::registerBinding(L);
    FormationMoverBinding::registerBinding(L);
    FurnaceBuildingBinding::registerBinding(L);
    FurnaceInventoryLayoutBinding::registerBinding(L);
    GUIWindowBinding::registerBinding(L);
    GameDataBinding::registerBinding(L);
    GameDataContainerBinding::registerBinding(L);
    GameDataCopyStandaloneBinding::registerBinding(L);
    GameDataEditorWindowBinding::registerBinding(L);
    GameDataEditorWindow_DataItemBinding::registerBinding(L);
    GameDataGroupBinding::registerBinding(L);
    GameDataHeaderBinding::registerBinding(L);
    GameDataManagerBinding::registerBinding(L);
    GameDataReferenceBinding::registerBinding(L);
    GameDataValuePairBinding::registerBinding(L);
    GameSaveStateBinding::registerBinding(L);
    GameWorldBinding::registerBinding(L);
    GameplayOptionsBinding::registerBinding(L);
    GatewayBuildingBinding::registerBinding(L);
    GearBinding::registerBinding(L);
    GeneratorBuildingBinding::registerBinding(L);
    GenericFixedInventoryLayoutBinding::registerBinding(L);
    GenericInventoryLayoutBinding::registerBinding(L);
    GlobalConstantsBinding::registerBinding(L);
    HandBinding::registerBinding(L);
    Inventory_HasRoomCacheBinding::registerBinding(L);
    HavokCharacterBinding::registerBinding(L);
    HealthPartStatusBinding::registerBinding(L);
    ImpactPointBinding::registerBinding(L);
    ImportGameMenuBinding::registerBinding(L);
    InputHandlerBinding::registerBinding(L);
    InputHandler_CommandBinding::registerBinding(L);
    InstanceIDBinding::registerBinding(L);
    InteriorModeButtonWindowBinding::registerBinding(L);
    InventoryBinding::registerBinding(L);
    InventoryGUIBinding::registerBinding(L);
    InventoryGUI_FenceCallbackDataBinding::registerBinding(L);
    InventoryIconBinding::registerBinding(L);
    InventoryItemBaseBinding::registerBinding(L);
    InventoryLayoutBinding::registerBinding(L);
    InventorySectionBinding::registerBinding(L);
    InventorySectionGUIBinding::registerBinding(L);
    InventoryTradeDataBinding::registerBinding(L);
    InventoryTraderGUIBinding::registerBinding(L);
    ItemBinding::registerBinding(L);
    ItemDataBinding::registerBinding(L);
    ItemListWindowBinding::registerBinding(L);
    GamedataSelectionListBinding::registerBinding(L);
    LevelEditorBinding::registerBinding(L);
    LightBuildingBinding::registerBinding(L);
    LightEntBinding::registerBinding(L);
    LimbsInventoryLayoutBinding::registerBinding(L);
    LimiterBinding::registerBinding(L);
    ListScrollBarBinding::registerBinding(L);
    ListenerBinding::registerBinding(L);
    LoadSaveWindowBinding::registerBinding(L);
    LoadingWindowBinding::registerBinding(L);
    LockedArmourBinding::registerBinding(L);
    LoggerBinding::registerBinding(L);
    MainBarGUIBinding::registerBinding(L);
    MainTabPortraitPlatoonBinding::registerBinding(L);
    MainthreadStateReaderTBinding::registerBinding(L);
    ManagementScreenBinding::registerBinding(L);
    ManagementScreen_TechItemViewDataBinding::registerBinding(L);
    MapMarkerCharacterBinding::registerBinding(L);
    MapMarkerTownBinding::registerBinding(L);
    MapScreenBinding::registerBinding(L);
    MapScreen_MapRoadBinding::registerBinding(L);
    MedianFilter2DVectorBinding::registerBinding(L);
    MedianFilterBinding::registerBinding(L);
    MedicalSystemBinding::registerBinding(L);
    MeshDataLookupBinding::registerBinding(L);
    MeshLoadDataBinding::registerBinding(L);
    MessageBoxManagerBinding::registerBinding(L);
    MessageQueue_NodeBinding::registerBinding(L);
    ModInfoBinding::registerBinding(L);
    MotionFilterBinding::registerBinding(L);
    MultiSliderBinding::registerBinding(L);
    MyGuiBinding::registerBinding(L);
    NavInstanceBinding::registerBinding(L);
    NavMeshBinding::registerBinding(L);
    NavMeshGeneratorBinding::registerBinding(L);
    NavMeshGenerator_TaskBinding::registerBinding(L);
    NavMeshGenerator_TaskQueueBinding::registerBinding(L);
    NavMeshSeedsBinding::registerBinding(L);
    NavMesh_BuildingInfoBinding::registerBinding(L);
    NavMesh_NavMeshMessageBinding::registerBinding(L);
    NewGameOptionsWindowBinding::registerBinding(L);
    NewGameWindowBinding::registerBinding(L);
    NpcListWindowBinding::registerBinding(L);
    Nx9RealBinding::registerBinding(L);
    Nx9Real_SBinding::registerBinding(L);
    NxBoxBinding::registerBinding(L);
    NxMat33Binding::registerBinding(L);
    NxUserControllerHitReportBinding::registerBinding(L);
    NxUserTriggerReportBinding::registerBinding(L);
    NxVec3Binding::registerBinding(L);
    ObjectInstanceBinding::registerBinding(L);
    OpenSaveFileDialogBinding::registerBinding(L);
    OptionsHolderBinding::registerBinding(L);
    OptionsWindowBinding::registerBinding(L);
    OrderCellViewBinding::registerBinding(L);
    OrderDataBinding::registerBinding(L);
    OrdersItemBoxBinding::registerBinding(L);
    OrdersPanelBinding::registerBinding(L);
    OwnershipsBinding::registerBinding(L);
    ParticlePoolBinding::registerBinding(L);
    ParticlePool_ParticleDataBinding::registerBinding(L);
    PhysicalEntityBinding::registerBinding(L);
    PhysicsActualBinding::registerBinding(L);
    PhysicsClassBinding::registerBinding(L);
    PhysicsCollectionBinding::registerBinding(L);
    PhysicsInterfaceBinding::registerBinding(L);
    PlatoonBinding::registerBinding(L);
    PlayerInterfaceBinding::registerBinding(L);
    PortraitDataBinding::registerBinding(L);
    PortraitImageBinding::registerBinding(L);
    PortraitMainCellViewBinding::registerBinding(L);
    PortraitManagerBinding::registerBinding(L);
    PortraitSquadCellViewBinding::registerBinding(L);
    PortraitSquadItemBoxBinding::registerBinding(L);
    PreviewBuildingBinding::registerBinding(L);
    ProductionBuildingBinding::registerBinding(L);
    ProductionInventoryLayoutBinding::registerBinding(L);
    ProgressBarWidgetBinding::registerBinding(L);
    ProspectingWindowBinding::registerBinding(L);
    ProsperityManagerBinding::registerBinding(L);
    RaceDataBinding::registerBinding(L);
    RaceLimiterBinding::registerBinding(L);
    RainCollectorBuildingBinding::registerBinding(L);
    RelationDataBinding::registerBinding(L);
    RepetitionCounterBinding::registerBinding(L);
    ResearchBuildingBinding::registerBinding(L);
    ResearchBuildingInventoryLayoutBinding::registerBinding(L);
    ResourceLinePanelBinding::registerBinding(L);
    ResourceLoadRequestMeshBinding::registerBinding(L);
    ResourceLoadRequestTextureBinding::registerBinding(L);
    ResourceLoaderBinding::registerBinding(L);
    RobotLimbItemBinding::registerBinding(L);
    RobotLimbsBinding::registerBinding(L);
    RootObjectBaseBinding::registerBinding(L);
    RootObjectBinding::registerBinding(L);
    RootObjectContainerBinding::registerBinding(L);
    RootObjectFactoryBinding::registerBinding(L);
    RotatingEntBinding::registerBinding(L);
    SaveFileSystemBinding::registerBinding(L);
    SaveFileSystem_FileMessageBinding::registerBinding(L);
    SaveInfoBinding::registerBinding(L);
    SaveManagerBinding::registerBinding(L);
    ScreenLabelBinding::registerBinding(L);
    ScreenLabelDebugBinding::registerBinding(L);
    ScreenLabelInterfaceBinding::registerBinding(L);
    SectionItemBinding::registerBinding(L);
    SeenSomeoneBinding::registerBinding(L);
    SelectionBoxBinding::registerBinding(L);
    SenseItrBinding::registerBinding(L);
    SensoryDataBinding::registerBinding(L);
    ShopTraderBinding::registerBinding(L);
    ShopTraderInventoryBinding::registerBinding(L);
    ShopTraderInventorySectionBinding::registerBinding(L);
    SimpleTimeStamperBinding::registerBinding(L);
    SliderBinding::registerBinding(L);
    SpecificItemLoadFirstBinding::registerBinding(L);
    SpeedGroupBinding::registerBinding(L);
    SplashScreenBinding::registerBinding(L);
    SpotBinding::registerBinding(L);
    SpottingPeopleMgrBinding::registerBinding(L);
    SquadCellViewBinding::registerBinding(L);
    SquadDataBinding::registerBinding(L);
    SquadItemBoxBinding::registerBinding(L);
    SquadListWindowBinding::registerBinding(L);
    SquadManagementScreenBinding::registerBinding(L);
    StatBinding::registerBinding(L);
    StatGroupBinding::registerBinding(L);
    StateTBinding::registerBinding(L);
    StaticEntBinding::registerBinding(L);
    StorageBuildingBinding::registerBinding(L);
    StringPairBinding::registerBinding(L);
    SwordBinding::registerBinding(L);
    SysMessageBinding::registerBinding(L);
    TaskDataBinding::registerBinding(L);
    TaskStateDataBinding::registerBinding(L);
    TaskerBinding::registerBinding(L);
    TerrainBinding::registerBinding(L);
    Terrain_BloodQueueBinding::registerBinding(L);
    Terrain_BoxBinding::registerBinding(L);
    Terrain_HitBinding::registerBinding(L);
    Terrain_InfoBinding::registerBinding(L);
    TextureArrayLoadDataBinding::registerBinding(L);
    TextureLoadDataBinding::registerBinding(L);
    ThreadClassBinding::registerBinding(L);
    ThreadWannabeBinding::registerBinding(L);
    TimeOfDayBinding::registerBinding(L);
    TimerClassBinding::registerBinding(L);
    TitleScreenBinding::registerBinding(L);
    ToolTipBinding::registerBinding(L);
    ToolTipDynamicBinding::registerBinding(L);
    ToolTipFixedBinding::registerBinding(L);
    ToolTipInventoryBinding::registerBinding(L);
    ToolTipLineBinding::registerBinding(L);
    ToolTipStaticBinding::registerBinding(L);
    TortureBuildingBinding::registerBinding(L);
    TownBaseBinding::registerBinding(L);
    TownBase_ResidentDataBinding::registerBinding(L);
    TownBinding::registerBinding(L);
    TownBuildingsManagerBinding::registerBinding(L);
    TownBuildingsManager_BuildingInfoBinding::registerBinding(L);
    TownListWindowBinding::registerBinding(L);
    TownPositionCacherBinding::registerBinding(L);
    Town_NestSpotBinding::registerBinding(L);
    TradeCultureBinding::registerBinding(L);
    TradeResultBinding::registerBinding(L);
    TraderInventoryLayoutBinding::registerBinding(L);
    TraitBoolBinding::registerBinding(L);
    TransformWindowBinding::registerBinding(L);
    TreeDataBinding::registerBinding(L);
    TriggerCallbackBinding::registerBinding(L);
    TripleIntBinding::registerBinding(L);
    TurretBuildingBinding::registerBinding(L);
    TutorialGUIBinding::registerBinding(L);
    TutorialGUILineBinding::registerBinding(L);
    TutorialItemBinding::registerBinding(L);
    TutorialSubItemBinding::registerBinding(L);
    TutorialpediaGUIBinding::registerBinding(L);
    UniqueSpawnDataBinding::registerBinding(L);
    UseableStuffBinding::registerBinding(L);
    UtilityTBinding::registerBinding(L);
    VisibleObjectInfoBinding::registerBinding(L);
    WallBuildingBinding::registerBinding(L);
    WeaponBinding::registerBinding(L);
    WeatherRegionBinding::registerBinding(L);
    WhoSeesMeBinding::registerBinding(L);
    WindGeneratorBuildingBinding::registerBinding(L);
    WorldEventStateQueryBinding::registerBinding(L);
    WorldEventStateQueryListBinding::registerBinding(L);
    YesNoMaybeBinding::registerBinding(L);
    ZoneManagerBinding::registerBinding(L);
    ZoneManagerInterfaceTBinding::registerBinding(L);
    ZoneManager_BiomeGroundEffectsBinding::registerBinding(L);
    ZoneMapBinding::registerBinding(L);
    ZoneSpacialGridBinding::registerBinding(L);
    ZoneSpacialGrid_ZoneCellBinding::registerBinding(L);
    hkBoolBinding::registerBinding(L);
    hkContainerHeapAllocatorBinding::registerBinding(L);
    hkContainerHeapAllocator_AllocatorBinding::registerBinding(L);
    hkMemoryAllocatorBinding::registerBinding(L);
    hkMemoryAllocator_ExtendedInterfaceBinding::registerBinding(L);
    hkMemoryAllocator_MemoryStatisticsBinding::registerBinding(L);
    hkResultBinding::registerBinding(L);
    hkVector4fBinding::registerBinding(L);
    iVector2Binding::registerBinding(L);
    physHitBinding::registerBinding(L);
    rendHitBinding::registerBinding(L);
    wraps::BaseLayoutBinding::registerBinding(L);

    registerInheritance(L);
    registerGlobals(L);
}
} // namespace KenshiLua
