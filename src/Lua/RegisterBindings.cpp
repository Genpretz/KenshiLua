#include "pch.h"
#include "Lua/LuaBindings.h"
#include "Bindings/Kenshi/AABB2DBinding.h"
#include "Bindings/Kenshi/AIOptionsBinding.h"
#include "Bindings/Kenshi/AbstractMovementBaseBinding.h"
#include "Bindings/Kenshi/ActivePlatoonBinding.h"
#include "Bindings/Kenshi/AkSoundPositionBinding.h"
#include "Bindings/Kenshi/AkVectorBinding.h"
#include "Bindings/Kenshi/AnimalInventoryLayoutBinding.h"
#include "Bindings/Kenshi/AppearanceAnimalBinding.h"
#include "Bindings/Kenshi/AppearanceBaseBinding.h"
#include "Bindings/Kenshi/AppearanceHumanBinding.h"
#include "Bindings/Kenshi/AppearanceManagerBinding.h"
#include "Bindings/Kenshi/AppearanceManager_AppearanceDataBinding.h"
#include "Bindings/Kenshi/AppearanceManager_DataCategoryBinding.h"
#include "Bindings/Kenshi/AppearanceManager_DataRangeBinding.h"
#include "Bindings/Kenshi/AppearanceManager_DataRangePoseBinding.h"
#include "Bindings/Kenshi/AppearanceManager_DataRangeVectorBinding.h"
#include "Bindings/Kenshi/AppearanceManager_GenderBinding.h"
#include "Bindings/Kenshi/ArmourBinding.h"
#include "Bindings/Kenshi/AttachedArrowManagerBinding.h"
#include "Bindings/Kenshi/AttackSlotManagerBinding.h"
#include "Bindings/Kenshi/BackThreadMessagesToMainTBinding.h"
#include "Bindings/Kenshi/BinaryVersionBinding.h"
#include "Bindings/Kenshi/BountyBinding.h"
#include "Bindings/Kenshi/BountyManagerBinding.h"
#include "Bindings/Kenshi/Building/BuildInventoryLayoutBinding.h"
#include "Bindings/Kenshi/Building/BuildMaterialBinding.h"
#include "Bindings/Kenshi/Building/BuildingBinding.h"
#include "Bindings/Kenshi/Building/BuildingContainerInventoryLayoutBinding.h"
#include "Bindings/Kenshi/Building/BuildingPlacementGroundTypeBinding.h"
#include "Bindings/Kenshi/Building/ConstructionStateBinding.h"
#include "Bindings/Kenshi/Building/ConsumptionItemBinding.h"
#include "Bindings/Kenshi/Building/CraftingBuildingBinding.h"
#include "Bindings/Kenshi/Building/CraftingInventoryLayoutBinding.h"
#include "Bindings/Kenshi/Building/DoorStuffBinding.h"
#include "Bindings/Kenshi/Building/FarmBatchBinding.h"
#include "Bindings/Kenshi/Building/FarmBuildingBinding.h"
#include "Bindings/Kenshi/Building/FarmBuilding_PlantBinding.h"
#include "Bindings/Kenshi/Building/FarmBuilding_PlantSourceBinding.h"
#include "Bindings/Kenshi/Building/FarmBuilding_SubPlantBinding.h"
#include "Bindings/Kenshi/Building/FootprintBinding.h"
#include "Bindings/Kenshi/Building/FootprintNodeBinding.h"
#include "Bindings/Kenshi/Building/FurnaceBuildingBinding.h"
#include "Bindings/Kenshi/Building/FurnaceInventoryLayoutBinding.h"
#include "Bindings/Kenshi/Building/GameDataGroupBinding.h"
#include "Bindings/Kenshi/Building/GatewayBuildingBinding.h"
#include "Bindings/Kenshi/Building/GeneratorBuildingBinding.h"
#include "Bindings/Kenshi/Building/GenericInventoryLayoutBinding.h"
#include "Bindings/Kenshi/Building/LightBuildingBinding.h"
#include "Bindings/Kenshi/Building/PreviewBuildingBinding.h"
#include "Bindings/Kenshi/Building/ProductionBuildingBinding.h"
#include "Bindings/Kenshi/Building/ProductionInventoryLayoutBinding.h"
#include "Bindings/Kenshi/Building/RainCollectorBuildingBinding.h"
#include "Bindings/Kenshi/Building/ResearchBuildingBinding.h"
#include "Bindings/Kenshi/Building/ResearchBuildingInventoryLayoutBinding.h"
#include "Bindings/Kenshi/Building/StorageBuildingBinding.h"
#include "Bindings/Kenshi/Building/TortureBuildingBinding.h"
#include "Bindings/Kenshi/Building/TurretBuildingBinding.h"
#include "Bindings/Kenshi/Building/UseableStuffBinding.h"
#include "Bindings/Kenshi/Building/WallBuildingBinding.h"
#include "Bindings/Kenshi/Building/WindGeneratorBuildingBinding.h"
#include "Bindings/Kenshi/Faction_BuildingSwapsBinding.h"
#include "Bindings/Kenshi/CameraClassBinding.h"
#include "Bindings/Kenshi/CampaignRequestBinding.h"
#include "Bindings/Kenshi/CampaignTriggerDataBinding.h"
#include "Bindings/Kenshi/CharBodyBinding.h"
#include "Bindings/Kenshi/CharMovementBinding.h"
#include "Bindings/Kenshi/CharStatsBinding.h"
#include "Bindings/Kenshi/CharacterAnimalBinding.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/CharacterHumanBinding.h"
#include "Bindings/Kenshi/CharacterInventoryLayoutBinding.h"
#include "Bindings/Kenshi/Character_CarryMsgBinding.h"
#include "Bindings/Kenshi/Character_RagdollMsgBinding.h"
#include "Bindings/Kenshi/CombatClassBinding.h"
#include "Bindings/Kenshi/CombatClass_AttackSlotManager_SlotDataBinding.h"
#include "Bindings/Kenshi/CombatClass_EffectDataBinding.h"
#include "Bindings/Kenshi/CombatMovementControllerBinding.h"
#include "Bindings/Kenshi/CombatTechniqueDataBinding.h"
#include "Bindings/Kenshi/ContainerItemBinding.h"
#include "Bindings/Kenshi/CreatelistItemBinding.h"
#include "Bindings/Kenshi/CrossbowBinding.h"
#include "Bindings/Kenshi/DamagesBinding.h"
#include "Bindings/Kenshi/DataObjectContainerBinding.h"
#include "Bindings/Kenshi/DelayedSpawnMsgBinding.h"
#include "Bindings/Kenshi/DialogActionBinding.h"
#include "Bindings/Kenshi/DialogChoiceListBinding.h"
#include "Bindings/Kenshi/DialogConditionBinding.h"
#include "Bindings/Kenshi/DialogDataManagerBinding.h"
#include "Bindings/Kenshi/DialogLineDataBinding.h"
#include "Bindings/Kenshi/DialogStateBinding.h"
#include "Bindings/Kenshi/DialogueBinding.h"
#include "Bindings/Kenshi/DialogueSpeechBubbleBinding.h"
#include "Bindings/Kenshi/EdgeCacheBinding.h"
#include "Bindings/Kenshi/EdgeCache_EdgeBinding.h"
#include "Bindings/Kenshi/EdgePathNodeBinding.h"
#include "Bindings/Kenshi/EntDataBinding.h"
#include "Bindings/Kenshi/EnumBinding.h"
#include "Bindings/Kenshi/FactionBinding.h"
#include "Bindings/Kenshi/FactionLeaderBinding.h"
#include "Bindings/Kenshi/FactionManagerBinding.h"
#include "Bindings/Kenshi/FactionRelationsBinding.h"
#include "Bindings/Kenshi/FactionUniqueSquadManagerBinding.h"
#include "Bindings/Kenshi/FactionWarMgrBinding.h"
#include "Bindings/Kenshi/Faction_CharacteristicsDataBinding.h"
#include "Bindings/Kenshi/FactionsScreen_FactionRelationsLine_LessSortBinding.h"
#include "Bindings/Kenshi/FactoryCallbackInterfaceBinding.h"
#include "Bindings/Kenshi/FitnessSelectorBinding.h"
#include "Bindings/Kenshi/FlagConditionBinding.h"
#include "Bindings/Kenshi/FlockingToolsBinding.h"
#include "Bindings/Kenshi/FoliageSystemBinding.h"
#include "Bindings/Kenshi/FormationMoverBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/GameDataContainerBinding.h"
#include "Bindings/Kenshi/GameDataCopyStandaloneBinding.h"
#include "Bindings/Kenshi/GameDataEditorWindow_DataItemBinding.h"
#include "Bindings/Kenshi/GameDataHeaderBinding.h"
#include "Bindings/Kenshi/GameDataManagerBinding.h"
#include "Bindings/Kenshi/GameDataReferenceBinding.h"
#include "Bindings/Kenshi/GameDataValuePairBinding.h"
#include "Bindings/Kenshi/GameSaveStateBinding.h"
#include "Bindings/Kenshi/GameWorldBinding.h"
#include "Bindings/Kenshi/GameplayOptionsBinding.h"
#include "Bindings/Kenshi/GearBinding.h"
#include "Bindings/Kenshi/GlobalBinding.h"
#include "Bindings/Kenshi/GlobalConstantsBinding.h"
#include "Bindings/Kenshi/Gui/BackpackInventoryLayoutBinding.h"
#include "Bindings/Kenshi/Gui/BaseLayoutBinding.h"
#include "Bindings/Kenshi/Gui/BoxBinding.h"
#include "Bindings/Kenshi/Gui/BuildModeWindowBinding.h"
#include "Bindings/Kenshi/Gui/BuildingCategoryBinding.h"
#include "Bindings/Kenshi/Gui/BuildingGroupBinding.h"
#include "Bindings/Kenshi/Gui/CharacterEditWindowBinding.h"
#include "Bindings/Kenshi/Gui/CharacterStatsWindowBinding.h"
#include "Bindings/Kenshi/Gui/CharacterTradingWindowBinding.h"
#include "Bindings/Kenshi/Gui/ContextMenuBinding.h"
#include "Bindings/Kenshi/Gui/ContextMenuGUIBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLineBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLine_ButtonBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLine_CheckBoxBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLine_DropBoxBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLine_FactionBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLine_KeyConfigBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLine_ProgressBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLine_ResearchBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLine_SliderBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLine_SliderEditableBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLine_TextBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLine_TextEditableBinding.h"
#include "Bindings/Kenshi/Gui/DatapanelGUIBinding.h"
#include "Bindings/Kenshi/Gui/DialogueWindowBinding.h"
#include "Bindings/Kenshi/Gui/FactionListWindowBinding.h"
#include "Bindings/Kenshi/Gui/FactionRelationsLineBinding.h"
#include "Bindings/Kenshi/Gui/FactionsScreenBinding.h"
#include "Bindings/Kenshi/Gui/FloatingProgressBarBinding.h"
#include "Bindings/Kenshi/Gui/FogEditorBinding.h"
#include "Bindings/Kenshi/Gui/ForgottenGUIBinding.h"
#include "Bindings/Kenshi/Gui/GUIWindowBinding.h"
#include "Bindings/Kenshi/Gui/GameDataEditorWindowBinding.h"
#include "Bindings/Kenshi/Gui/GamedataSelectionListBinding.h"
#include "Bindings/Kenshi/Gui/GenericFixedInventoryLayoutBinding.h"
#include "Bindings/Kenshi/Gui/ImportGameMenuBinding.h"
#include "Bindings/Kenshi/Gui/InteriorModeButtonWindowBinding.h"
#include "Bindings/Kenshi/Gui/InventoryGUIBinding.h"
#include "Bindings/Kenshi/Gui/InventoryIconBinding.h"
#include "Bindings/Kenshi/Gui/InventoryLayoutBinding.h"
#include "Bindings/Kenshi/Gui/InventorySectionGUIBinding.h"
#include "Bindings/Kenshi/Gui/InventoryTradeDataBinding.h"
#include "Bindings/Kenshi/Gui/InventoryTraderGUIBinding.h"
#include "Bindings/Kenshi/Gui/ItemListWindowBinding.h"
#include "Bindings/Kenshi/Gui/LevelEditorBinding.h"
#include "Bindings/Kenshi/Gui/ListScrollBarBinding.h"
#include "Bindings/Kenshi/Gui/LoadSaveWindowBinding.h"
#include "Bindings/Kenshi/Gui/LoadingWindowBinding.h"
#include "Bindings/Kenshi/Gui/MainBarGUIBinding.h"
#include "Bindings/Kenshi/Gui/MainTabPortraitPlatoonBinding.h"
#include "Bindings/Kenshi/Gui/ManagementScreenBinding.h"
#include "Bindings/Kenshi/Gui/MapMarkerCharacterBinding.h"
#include "Bindings/Kenshi/Gui/MapMarkerTownBinding.h"
#include "Bindings/Kenshi/Gui/MapScreenBinding.h"
#include "Bindings/Kenshi/Gui/MessageBoxManagerBinding.h"
#include "Bindings/Kenshi/Gui/MultiSliderBinding.h"
#include "Bindings/Kenshi/Gui/NewGameOptionsWindowBinding.h"
#include "Bindings/Kenshi/Gui/NewGameWindowBinding.h"
#include "Bindings/Kenshi/Gui/NpcListWindowBinding.h"
#include "Bindings/Kenshi/Gui/OpenSaveFileDialogBinding.h"
#include "Bindings/Kenshi/Gui/OptionsWindowBinding.h"
#include "Bindings/Kenshi/Gui/OrderCellViewBinding.h"
#include "Bindings/Kenshi/Gui/OrderDataBinding.h"
#include "Bindings/Kenshi/Gui/OrdersItemBoxBinding.h"
#include "Bindings/Kenshi/Gui/OrdersPanelBinding.h"
#include "Bindings/Kenshi/Gui/PortraitDataBinding.h"
#include "Bindings/Kenshi/Gui/PortraitImageBinding.h"
#include "Bindings/Kenshi/Gui/PortraitMainCellViewBinding.h"
#include "Bindings/Kenshi/Gui/PortraitManagerBinding.h"
#include "Bindings/Kenshi/Gui/PortraitSquadCellViewBinding.h"
#include "Bindings/Kenshi/Gui/PortraitSquadItemBoxBinding.h"
#include "Bindings/Kenshi/Gui/ProgressBarWidgetBinding.h"
#include "Bindings/Kenshi/Gui/ProspectingWindowBinding.h"
#include "Bindings/Kenshi/Gui/ReorderableListBinding.h"
#include "Bindings/Kenshi/Gui/ResourceLinePanelBinding.h"
#include "Bindings/Kenshi/Gui/ScreenLabelBinding.h"
#include "Bindings/Kenshi/Gui/ScreenLabelDebugBinding.h"
#include "Bindings/Kenshi/Gui/ScreenLabelInterfaceBinding.h"
#include "Bindings/Kenshi/Gui/SliderBinding.h"
#include "Bindings/Kenshi/Gui/SplashScreenBinding.h"
#include "Bindings/Kenshi/Gui/SquadCellViewBinding.h"
#include "Bindings/Kenshi/Gui/SquadDataBinding.h"
#include "Bindings/Kenshi/Gui/SquadItemBoxBinding.h"
#include "Bindings/Kenshi/Gui/SquadListWindowBinding.h"
#include "Bindings/Kenshi/Gui/SquadManagementScreenBinding.h"
#include "Bindings/Kenshi/Gui/StatBinding.h"
#include "Bindings/Kenshi/Gui/StatGroupBinding.h"
#include "Bindings/Kenshi/Gui/TitleScreenBinding.h"
#include "Bindings/Kenshi/Gui/ToolTipBinding.h"
#include "Bindings/Kenshi/Gui/ToolTipDynamicBinding.h"
#include "Bindings/Kenshi/Gui/ToolTipFixedBinding.h"
#include "Bindings/Kenshi/Gui/ToolTipInventoryBinding.h"
#include "Bindings/Kenshi/Gui/ToolTipLineBinding.h"
#include "Bindings/Kenshi/Gui/ToolTipStaticBinding.h"
#include "Bindings/Kenshi/Gui/TownListWindowBinding.h"
#include "Bindings/Kenshi/Gui/TradeResultBinding.h"
#include "Bindings/Kenshi/Gui/TraderInventoryLayoutBinding.h"
#include "Bindings/Kenshi/Gui/TransformWindowBinding.h"
#include "Bindings/Kenshi/Gui/TutorialGUIBinding.h"
#include "Bindings/Kenshi/Gui/TutorialGUILineBinding.h"
#include "Bindings/Kenshi/Gui/TutorialItemBinding.h"
#include "Bindings/Kenshi/Gui/TutorialSubItemBinding.h"
#include "Bindings/Kenshi/Gui/TutorialpediaGUIBinding.h"
#include "Bindings/Kenshi/Inventory_HasRoomCacheBinding.h"
#include "Bindings/Kenshi/HavokCharacterBinding.h"
#include "Bindings/Kenshi/MedicalSystem_HealthPartStatusBinding.h"
#include "Bindings/Kenshi/ImpactPointBinding.h"
#include "Bindings/Kenshi/InputHandlerBinding.h"
#include "Bindings/Kenshi/InputHandler_CommandBinding.h"
#include "Bindings/Kenshi/InstanceIDBinding.h"
#include "Bindings/Kenshi/InventoryBinding.h"
#include "Bindings/Kenshi/InventoryGUI_FenceCallbackDataBinding.h"
#include "Bindings/Kenshi/InventoryItemBaseBinding.h"
#include "Bindings/Kenshi/InventorySectionBinding.h"
#include "Bindings/Kenshi/ItemBinding.h"
#include "Bindings/Kenshi/ItemDataBinding.h"
#include "Bindings/Kenshi/LightEntBinding.h"
#include "Bindings/Kenshi/LimbsInventoryLayoutBinding.h"
#include "Bindings/Kenshi/RaceLimiter_LimiterBinding.h"
#include "Bindings/Kenshi/ListenerBinding.h"
#include "Bindings/Kenshi/LockedArmourBinding.h"
#include "Bindings/Kenshi/LoggerBinding.h"
#include "Bindings/Kenshi/MainthreadStateReaderTBinding.h"
#include "Bindings/Kenshi/ManagementScreen_TechItemViewDataBinding.h"
#include "Bindings/Kenshi/MapScreen_MapRoadBinding.h"
#include "Bindings/Kenshi/MedianFilter2DVectorBinding.h"
#include "Bindings/Kenshi/MedianFilterBinding.h"
#include "Bindings/Kenshi/MedicalSystemBinding.h"
#include "Bindings/Kenshi/MeshDataLookupBinding.h"
#include "Bindings/Kenshi/MeshLoadDataBinding.h"
#include "Bindings/Kenshi/MessageChainBinding.h"
#include "Bindings/Kenshi/MessageForBBinding.h"
#include "Bindings/Kenshi/MessageQueue_NodeBinding.h"
#include "Bindings/Kenshi/ModInfoBinding.h"
#include "Bindings/Kenshi/MotionFilterBinding.h"
#include "Bindings/Kenshi/MustEndWithSemiColonBinding.h"
#include "Bindings/MyGUI/MyGUIBinding.h"
#include "Bindings/Kenshi/NavInstanceBinding.h"
#include "Bindings/Kenshi/NavMeshBinding.h"
#include "Bindings/Kenshi/NavMeshGeneratorBinding.h"
#include "Bindings/Kenshi/NavMeshGenerator_TaskBinding.h"
#include "Bindings/Kenshi/NavMeshGenerator_TaskQueueBinding.h"
#include "Bindings/Kenshi/NavMeshSeedsBinding.h"
#include "Bindings/Kenshi/NavMesh_BuildingInfoBinding.h"
#include "Bindings/Kenshi/NavMesh_NavMeshMessageBinding.h"
#include "Bindings/Kenshi/Nx9RealBinding.h"
#include "Bindings/Kenshi/Nx9Real_SBinding.h"
#include "Bindings/Kenshi/NxBoxBinding.h"
#include "Bindings/Kenshi/NxMat33Binding.h"
#include "Bindings/Kenshi/NxUserControllerHitReportBinding.h"
#include "Bindings/Kenshi/NxUserTriggerReportBinding.h"
#include "Bindings/Kenshi/NxVec3Binding.h"
#include "Bindings/Kenshi/ObjectInstanceBinding.h"
#include "Bindings/Kenshi/OptionsHolderBinding.h"
#include "Bindings/Kenshi/OwnershipsBinding.h"
#include "Bindings/Kenshi/ParticlePoolBinding.h"
#include "Bindings/Kenshi/ParticlePool_ParticleDataBinding.h"
#include "Bindings/Kenshi/PhysicalEntityBinding.h"
#include "Bindings/Kenshi/PhysicsActualBinding.h"
#include "Bindings/Kenshi/PhysicsClassBinding.h"
#include "Bindings/Kenshi/PhysicsCollectionBinding.h"
#include "Bindings/Kenshi/PhysicsInterfaceBinding.h"
#include "Bindings/Kenshi/PlatoonBinding.h"
#include "Bindings/Kenshi/PlayerInterfaceBinding.h"
#include "Bindings/Kenshi/ProsperityManagerBinding.h"
#include "Bindings/Kenshi/RaceDataBinding.h"
#include "Bindings/Kenshi/RaceLimiterBinding.h"
#include "Bindings/Kenshi/RelationDataBinding.h"
#include "Bindings/Kenshi/RepetitionCounterBinding.h"
#include "Bindings/Kenshi/ResourceLoadRequestMeshBinding.h"
#include "Bindings/Kenshi/ResourceLoadRequestTextureBinding.h"
#include "Bindings/Kenshi/ResourceLoaderBinding.h"
#include "Bindings/Kenshi/RobotLimbItemBinding.h"
#include "Bindings/Kenshi/RobotLimbsBinding.h"
#include "Bindings/Kenshi/RootObjectBaseBinding.h"
#include "Bindings/Kenshi/RootObjectBinding.h"
#include "Bindings/Kenshi/RootObjectContainerBinding.h"
#include "Bindings/Kenshi/RootObjectFactoryBinding.h"
#include "Bindings/Kenshi/RotatingEntBinding.h"
#include "Bindings/Kenshi/SaveFileSystemBinding.h"
#include "Bindings/Kenshi/SaveFileSystem_FileMessageBinding.h"
#include "Bindings/Kenshi/SaveInfoBinding.h"
#include "Bindings/Kenshi/SaveManagerBinding.h"
#include "Bindings/Kenshi/InventorySection_SectionItemBinding.h"
#include "Bindings/Kenshi/SeenSomeoneBinding.h"
#include "Bindings/Kenshi/SelectionBoxBinding.h"
#include "Bindings/Kenshi/SenseItrBinding.h"
#include "Bindings/Kenshi/SensoryDataBinding.h"
#include "Bindings/Kenshi/ShopTraderBinding.h"
#include "Bindings/Kenshi/ShopTraderInventoryBinding.h"
#include "Bindings/Kenshi/ShopTraderInventorySectionBinding.h"
#include "Bindings/Kenshi/SimpleTimeStamperBinding.h"
#include "Bindings/Kenshi/SpecificItemLoadFirstBinding.h"
#include "Bindings/Kenshi/SpeedGroupBinding.h"
#include "Bindings/Kenshi/SpotBinding.h"
#include "Bindings/Kenshi/SpottingPeopleMgrBinding.h"
#include "Bindings/Kenshi/StateTBinding.h"
#include "Bindings/Kenshi/StaticEntBinding.h"
#include "Bindings/Kenshi/SwordBinding.h"
#include "Bindings/Kenshi/GameWorld_SysMessageBinding.h"
#include "Bindings/Kenshi/TaskDataBinding.h"
#include "Bindings/Kenshi/TaskStateDataBinding.h"
#include "Bindings/Kenshi/TaskerBinding.h"
#include "Bindings/Kenshi/TerrainBinding.h"
#include "Bindings/Kenshi/Terrain_BloodQueueBinding.h"
#include "Bindings/Kenshi/Terrain_BoxBinding.h"
#include "Bindings/Kenshi/Terrain_HitBinding.h"
#include "Bindings/Kenshi/Terrain_InfoBinding.h"
#include "Bindings/Kenshi/TextureArrayLoadDataBinding.h"
#include "Bindings/Kenshi/TextureLoadDataBinding.h"
#include "Bindings/Kenshi/ThreadClassBinding.h"
#include "Bindings/Kenshi/ThreadWannabeBinding.h"
#include "Bindings/Kenshi/TownBaseBinding.h"
#include "Bindings/Kenshi/TownBase_ResidentDataBinding.h"
#include "Bindings/Kenshi/TownBinding.h"
#include "Bindings/Kenshi/TownBuildingsManagerBinding.h"
#include "Bindings/Kenshi/TownBuildingsManager_BuildingInfoBinding.h"
#include "Bindings/Kenshi/TownPositionCacherBinding.h"
#include "Bindings/Kenshi/Town_NestSpotBinding.h"
#include "Bindings/Kenshi/TradeCultureBinding.h"
#include "Bindings/Kenshi/TraitBoolBinding.h"
#include "Bindings/Kenshi/TreeDataBinding.h"
#include "Bindings/Kenshi/TriggerCallbackBinding.h"
#include "Bindings/Kenshi/UniqueSpawnDataBinding.h"
#include "Bindings/Kenshi/Util/Array2dBinding.h"
#include "Bindings/Kenshi/Util/BadSizeBinding.h"
#include "Bindings/Kenshi/Util/BoostUnorderedBinding.h"
#include "Bindings/Kenshi/Util/BoundsViolationBinding.h"
#include "Bindings/Kenshi/Util/CPerfTimerBinding.h"
#include "Bindings/Kenshi/Util/CPerfTimerTBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"
#include "Bindings/Kenshi/Util/OgreFastArrayBinding.h"
#include "Bindings/Kenshi/Util/OgreUnorderedBinding.h"
#include "Bindings/Kenshi/Util/OgreVectorBinding.h"
#include "Bindings/Kenshi/Util/StdDequeBinding.h"
#include "Bindings/Kenshi/Util/StdMapBinding.h"
#include "Bindings/Kenshi/Util/StdSetBinding.h"
#include "Bindings/Kenshi/Util/StringPairBinding.h"
#include "Bindings/Kenshi/Util/TagsClassBinding.h"
#include "Bindings/Kenshi/Util/TimeOfDayBinding.h"
#include "Bindings/Kenshi/Util/TimerClassBinding.h"
#include "Bindings/Kenshi/Util/TripleIntBinding.h"
#include "Bindings/Kenshi/Util/UtilityTBinding.h"
#include "Bindings/Kenshi/Util/YesNoMaybeBinding.h"
#include "Bindings/Kenshi/Util/iVector2Binding.h"
#include "Bindings/Kenshi/Util/rendHitBinding.h"
#include "Bindings/Kenshi/VisibleObjectInfoBinding.h"
#include "Bindings/Kenshi/WeaponBinding.h"
#include "Bindings/Kenshi/WeatherRegionBinding.h"
#include "Bindings/Kenshi/WhoSeesMeBinding.h"
#include "Bindings/Kenshi/WorldEventStateQueryBinding.h"
#include "Bindings/Kenshi/WorldEventStateQueryListBinding.h"
#include "Bindings/Kenshi/ZoneManagerBinding.h"
#include "Bindings/Kenshi/ZoneManagerInterfaceTBinding.h"
#include "Bindings/Kenshi/ZoneManager_BiomeGroundEffectsBinding.h"
#include "Bindings/Kenshi/ZoneMapBinding.h"
#include "Bindings/Kenshi/ZoneSpacialGridBinding.h"
#include "Bindings/Kenshi/ZoneSpacialGrid_ZoneCellBinding.h"
#include "Bindings/Kenshi/hkArrayBaseBinding.h"
#include "Bindings/Kenshi/hkArrayBinding.h"
#include "Bindings/Kenshi/hkBoolBinding.h"
#include "Bindings/Kenshi/hkContainerHeapAllocatorBinding.h"
#include "Bindings/Kenshi/hkContainerHeapAllocator_AllocatorBinding.h"
#include "Bindings/Kenshi/hkMemoryAllocatorBinding.h"
#include "Bindings/Kenshi/hkMemoryAllocator_ExtendedInterfaceBinding.h"
#include "Bindings/Kenshi/hkMemoryAllocator_MemoryStatisticsBinding.h"
#include "Bindings/Kenshi/hkResultBinding.h"
#include "Bindings/Kenshi/hkVector4fBinding.h"
#include "Bindings/Kenshi/hkVector4fComparisonBinding.h"
#include "Bindings/Kenshi/physHitBinding.h"

namespace KenshiLua
{

static void registerInheritance(lua_State* L)
{
// --- ACTIVE INHERITANCE WIRING ---
    setMetatableParent(L, AbstractMovementBaseBinding::getMetatableName(),              NxUserControllerHitReportBinding::getMetatableName());
    setMetatableParent(L, ActivePlatoonBinding::getMetatableName(),                     RootObjectContainerBinding::getMetatableName());
    setMetatableParent(L, AnimalInventoryLayoutBinding::getMetatableName(),             InventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, AppearanceAnimalBinding::getMetatableName(),                  AppearanceBaseBinding::getMetatableName());
    setMetatableParent(L, AppearanceHumanBinding::getMetatableName(),                   AppearanceBaseBinding::getMetatableName());
    setMetatableParent(L, AppearanceManager_DataRangePoseBinding::getMetatableName(),   AppearanceManager_DataRangeBinding::getMetatableName());
    setMetatableParent(L, AppearanceManager_DataRangeVectorBinding::getMetatableName(), AppearanceManager_DataRangeBinding::getMetatableName());
    setMetatableParent(L, ArmourBinding::getMetatableName(),                            GearBinding::getMetatableName());
    setMetatableParent(L, BackpackInventoryLayoutBinding::getMetatableName(),           GenericFixedInventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, BoxBinding::getMetatableName(),                               BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, BuildInventoryLayoutBinding::getMetatableName(),              InventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, BuildModeWindowBinding::getMetatableName(),                   BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, BuildingBinding::getMetatableName(),                          RootObjectBinding::getMetatableName());
    setMetatableParent(L, BuildingContainerInventoryLayoutBinding::getMetatableName(),  GenericInventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, CPerfTimerTBinding::getMetatableName(),                       CPerfTimerBinding::getMetatableName());
    setMetatableParent(L, CharMovementBinding::getMetatableName(),                      AbstractMovementBaseBinding::getMetatableName());
    setMetatableParent(L, CharacterAnimalBinding::getMetatableName(),                   CharacterBinding::getMetatableName());
    setMetatableParent(L, CharacterBinding::getMetatableName(),                         RootObjectBinding::getMetatableName());
    setMetatableParent(L, CharacterEditWindowBinding::getMetatableName(),               BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, CharacterHumanBinding::getMetatableName(),                    CharacterBinding::getMetatableName());
    setMetatableParent(L, CharacterInventoryLayoutBinding::getMetatableName(),          InventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, CharacterStatsWindowBinding::getMetatableName(),              GUIWindowBinding::getMetatableName());
    setMetatableParent(L, CharacterTradingWindowBinding::getMetatableName(),            GUIWindowBinding::getMetatableName());
    setMetatableParent(L, ContainerItemBinding::getMetatableName(),                     ItemBinding::getMetatableName());
    setMetatableParent(L, ContextMenuGUIBinding::getMetatableName(),                    BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, CraftingBuildingBinding::getMetatableName(),                  ProductionBuildingBinding::getMetatableName());
    setMetatableParent(L, CraftingInventoryLayoutBinding::getMetatableName(),           BuildInventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, CrossbowBinding::getMetatableName(),                          WeaponBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_ButtonBinding::getMetatableName(),              DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_CheckBoxBinding::getMetatableName(),            DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_DropBoxBinding::getMetatableName(),             DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_FactionBinding::getMetatableName(),             DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_KeyConfigBinding::getMetatableName(),           DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_ProgressBinding::getMetatableName(),            DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_ResearchBinding::getMetatableName(),            DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_SliderBinding::getMetatableName(),              DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_SliderEditableBinding::getMetatableName(),      DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_TextBinding::getMetatableName(),                DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_TextEditableBinding::getMetatableName(),        DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DatapanelGUIBinding::getMetatableName(),                      GUIWindowBinding::getMetatableName());
    setMetatableParent(L, DialogueSpeechBubbleBinding::getMetatableName(),              BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, DialogueWindowBinding::getMetatableName(),                    GUIWindowBinding::getMetatableName());
    setMetatableParent(L, DoorStuffBinding::getMetatableName(),                         BuildingBinding::getMetatableName());
    setMetatableParent(L, FactionListWindowBinding::getMetatableName(),                 GamedataSelectionListBinding::getMetatableName());
    setMetatableParent(L, FactionRelationsLineBinding::getMetatableName(),              BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, FarmBuildingBinding::getMetatableName(),                      ProductionBuildingBinding::getMetatableName());
    setMetatableParent(L, FloatingProgressBarBinding::getMetatableName(),               ScreenLabelInterfaceBinding::getMetatableName());
    setMetatableParent(L, FogEditorBinding::getMetatableName(),                         BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, FootprintNodeBinding::getMetatableName(),                     FootprintBinding::getMetatableName());
    setMetatableParent(L, FurnaceBuildingBinding::getMetatableName(),                   ProductionBuildingBinding::getMetatableName());
    setMetatableParent(L, FurnaceInventoryLayoutBinding::getMetatableName(),            BuildInventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, GameDataCopyStandaloneBinding::getMetatableName(),            GameDataBinding::getMetatableName());
    setMetatableParent(L, GameDataManagerBinding::getMetatableName(),                   GameDataContainerBinding::getMetatableName());
    setMetatableParent(L, GatewayBuildingBinding::getMetatableName(),                   BuildingBinding::getMetatableName());
    setMetatableParent(L, GearBinding::getMetatableName(),                              ItemBinding::getMetatableName());
    setMetatableParent(L, GeneratorBuildingBinding::getMetatableName(),                 ProductionBuildingBinding::getMetatableName());
    setMetatableParent(L, GenericFixedInventoryLayoutBinding::getMetatableName(),       InventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, GenericInventoryLayoutBinding::getMetatableName(),            InventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, hkContainerHeapAllocator_AllocatorBinding::getMetatableName(), hkMemoryAllocatorBinding::getMetatableName());
    setMetatableParent(L, ImportGameMenuBinding::getMetatableName(),                    LoadSaveWindowBinding::getMetatableName());
    setMetatableParent(L, InteriorModeButtonWindowBinding::getMetatableName(),          BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, InventoryGUIBinding::getMetatableName(),                      GUIWindowBinding::getMetatableName());
    setMetatableParent(L, InventoryIconBinding::getMetatableName(),                     BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, InventoryItemBaseBinding::getMetatableName(),                 RootObjectBinding::getMetatableName());
    setMetatableParent(L, InventoryLayoutBinding::getMetatableName(),                   BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, InventoryTraderGUIBinding::getMetatableName(),                InventoryGUIBinding::getMetatableName());
    setMetatableParent(L, ItemBinding::getMetatableName(),                              InventoryItemBaseBinding::getMetatableName());
    setMetatableParent(L, ItemListWindowBinding::getMetatableName(),                    GamedataSelectionListBinding::getMetatableName());
    setMetatableParent(L, LightBuildingBinding::getMetatableName(),                     UseableStuffBinding::getMetatableName());
    setMetatableParent(L, LimbsInventoryLayoutBinding::getMetatableName(),              InventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, LoadSaveWindowBinding::getMetatableName(),                    BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, LoadingWindowBinding::getMetatableName(),                     BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, LockedArmourBinding::getMetatableName(),                      ArmourBinding::getMetatableName());
    setMetatableParent(L, MainBarGUIBinding::getMetatableName(),                        GUIWindowBinding::getMetatableName());
    setMetatableParent(L, ManagementScreenBinding::getMetatableName(),                  BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, MultiSliderBinding::getMetatableName(),                       MyGUIBinding::getMetatableName());
    setMetatableParent(L, NavMeshBinding::getMetatableName(),                           ThreadClassBinding::getMetatableName());
    setMetatableParent(L, NavMeshGeneratorBinding::getMetatableName(),                  ThreadClassBinding::getMetatableName());
    setMetatableParent(L, NewGameOptionsWindowBinding::getMetatableName(),              BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, NewGameWindowBinding::getMetatableName(),                     GUIWindowBinding::getMetatableName());
    setMetatableParent(L, NpcListWindowBinding::getMetatableName(),                     GamedataSelectionListBinding::getMetatableName());
    setMetatableParent(L, OpenSaveFileDialogBinding::getMetatableName(),                BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, OptionsWindowBinding::getMetatableName(),                     GUIWindowBinding::getMetatableName());
    setMetatableParent(L, PhysicsActualBinding::getMetatableName(),                     PhysicsInterfaceBinding::getMetatableName());
    setMetatableParent(L, PhysicsInterfaceBinding::getMetatableName(),                  ThreadWannabeBinding::getMetatableName());
    setMetatableParent(L, PlatoonBinding::getMetatableName(),                           RootObjectBaseBinding::getMetatableName());
    setMetatableParent(L, PlayerInterfaceBinding::getMetatableName(),                   FactoryCallbackInterfaceBinding::getMetatableName());
    setMetatableParent(L, ProductionBuildingBinding::getMetatableName(),                StorageBuildingBinding::getMetatableName());
    setMetatableParent(L, ProductionInventoryLayoutBinding::getMetatableName(),         BuildInventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, ProgressBarWidgetBinding::getMetatableName(),                 BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, ProspectingWindowBinding::getMetatableName(),                 BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, RainCollectorBuildingBinding::getMetatableName(),             ProductionBuildingBinding::getMetatableName());
    setMetatableParent(L, ResearchBuildingBinding::getMetatableName(),                  UseableStuffBinding::getMetatableName());
    setMetatableParent(L, ResearchBuildingInventoryLayoutBinding::getMetatableName(),   GenericInventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, ResourceLinePanelBinding::getMetatableName(),                 BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, ResourceLoaderBinding::getMetatableName(),                    ThreadClassBinding::getMetatableName());
    setMetatableParent(L, RobotLimbItemBinding::getMetatableName(),                     ItemBinding::getMetatableName());
    setMetatableParent(L, RootObjectBinding::getMetatableName(),                        RootObjectBaseBinding::getMetatableName());
    setMetatableParent(L, RootObjectContainerBinding::getMetatableName(),               DataObjectContainerBinding::getMetatableName());
    setMetatableParent(L, RotatingEntBinding::getMetatableName(),                       StaticEntBinding::getMetatableName());
    setMetatableParent(L, SaveFileSystemBinding::getMetatableName(),                    ThreadClassBinding::getMetatableName());
    setMetatableParent(L, ScreenLabelBinding::getMetatableName(),                       ScreenLabelInterfaceBinding::getMetatableName());
    setMetatableParent(L, ScreenLabelDebugBinding::getMetatableName(),                  ScreenLabelBinding::getMetatableName());
    setMetatableParent(L, ShopTraderBinding::getMetatableName(),                        RootObjectBinding::getMetatableName());
    setMetatableParent(L, ShopTraderInventoryBinding::getMetatableName(),               InventoryBinding::getMetatableName());
    setMetatableParent(L, ShopTraderInventorySectionBinding::getMetatableName(),        InventorySectionBinding::getMetatableName());
    setMetatableParent(L, SliderBinding::getMetatableName(),                            MyGUIBinding::getMetatableName());
    setMetatableParent(L, SquadListWindowBinding::getMetatableName(),                   GamedataSelectionListBinding::getMetatableName());
    setMetatableParent(L, StaticEntBinding::getMetatableName(),                         PhysicalEntityBinding::getMetatableName());
    setMetatableParent(L, StorageBuildingBinding::getMetatableName(),                   UseableStuffBinding::getMetatableName());
    setMetatableParent(L, SwordBinding::getMetatableName(),                             WeaponBinding::getMetatableName());
    setMetatableParent(L, TextureArrayLoadDataBinding::getMetatableName(),              TextureLoadDataBinding::getMetatableName());
    setMetatableParent(L, ThreadWannabeBinding::getMetatableName(),                     ThreadClassBinding::getMetatableName());
    setMetatableParent(L, TitleScreenBinding::getMetatableName(),                       GUIWindowBinding::getMetatableName());
    setMetatableParent(L, ToolTipDynamicBinding::getMetatableName(),                    ToolTipBinding::getMetatableName());
    setMetatableParent(L, ToolTipFixedBinding::getMetatableName(),                      ToolTipBinding::getMetatableName());
    setMetatableParent(L, ToolTipInventoryBinding::getMetatableName(),                  ToolTipBinding::getMetatableName());
    setMetatableParent(L, ToolTipStaticBinding::getMetatableName(),                     ToolTipBinding::getMetatableName());
    setMetatableParent(L, TortureBuildingBinding::getMetatableName(),                   ProductionBuildingBinding::getMetatableName());
    setMetatableParent(L, TownBaseBinding::getMetatableName(),                          RootObjectBinding::getMetatableName());
    setMetatableParent(L, TownBinding::getMetatableName(),                              TownBaseBinding::getMetatableName());
    setMetatableParent(L, TownBuildingsManagerBinding::getMetatableName(),              FactoryCallbackInterfaceBinding::getMetatableName());
    setMetatableParent(L, TownListWindowBinding::getMetatableName(),                    NpcListWindowBinding::getMetatableName());
    setMetatableParent(L, TraderInventoryLayoutBinding::getMetatableName(),             InventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, TriggerCallbackBinding::getMetatableName(),                   NxUserTriggerReportBinding::getMetatableName());
    setMetatableParent(L, TurretBuildingBinding::getMetatableName(),                    UseableStuffBinding::getMetatableName());
    setMetatableParent(L, TutorialGUIBinding::getMetatableName(),                       GUIWindowBinding::getMetatableName());
    setMetatableParent(L, TutorialGUILineBinding::getMetatableName(),                   BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, TutorialpediaGUIBinding::getMetatableName(),                  GUIWindowBinding::getMetatableName());
    setMetatableParent(L, UseableStuffBinding::getMetatableName(),                      BuildingBinding::getMetatableName());
    setMetatableParent(L, WallBuildingBinding::getMetatableName(),                      BuildingBinding::getMetatableName());
    setMetatableParent(L, WeaponBinding::getMetatableName(),                            GearBinding::getMetatableName());
    setMetatableParent(L, WindGeneratorBuildingBinding::getMetatableName(),             GeneratorBuildingBinding::getMetatableName());
    setMetatableParent(L, ZoneManagerBinding::getMetatableName(),                       ZoneManagerInterfaceTBinding::getMetatableName());

// --- FUTURE / COMMENTED-OUT INHERITANCE ---
    // setMetatableParent(L, AbstractMovementBaseBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, AppearanceBaseBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, AppearanceManagerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, AttackSlotManagerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, BuildingBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, CharBodyBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, CharStatsBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, CharacterBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, CharacterEditWindowBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, CombatClassBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, CombatClass_AttackSlotManager_SlotDataBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, CombatClass_EffectDataBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, ConstructionStateBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, ContextMenuBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, ContextMenuGUIBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, DamagesBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, DataPanelLineBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, DialogueSpeechBubbleBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, EntDataBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, FactionBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, FactionManagerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, FactionWarMgrBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, FoliageSystemBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, ForgottenGUIBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, GUIWindowBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, GameDataBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, GameDataContainerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, GameDataEditorWindowBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, GameWorldBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, InputHandlerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, InteriorModeButtonWindowBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, InventoryBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, InventoryItemBaseBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, InventoryLayoutBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, LevelEditorBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, ListScrollBarBinding::getMetatableName(), ScrollBarBinding::getMetatableName());
    // setMetatableParent(L, MainTabPortraitPlatoonBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, MainthreadStateReaderTBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, MeshDataLookupBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, MessageBoxManagerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, ModInfoBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, OrderCellViewBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, OrderCellViewBinding::getMetatableName(), wraps::BaseCellViewBinding::getMetatableName());
    // setMetatableParent(L, OrderDataBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, OrdersItemBoxBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, OrdersItemBoxBinding::getMetatableName(), wraps::BaseItemBoxBinding::getMetatableName());
    // setMetatableParent(L, OrdersPanelBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, ParticlePoolBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, PhysicalEntityBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, PhysicsActualBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, PhysicsCollectionBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, PlatoonBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, PlayerInterfaceBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, PortraitDataBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, PortraitImageBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, PortraitMainCellViewBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, PortraitMainCellViewBinding::getMetatableName(), wraps::BaseCellViewBinding::getMetatableName());
    // setMetatableParent(L, PortraitManagerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, PortraitSquadCellViewBinding::getMetatableName(), wraps::BaseCellViewBinding::getMetatableName());
    // setMetatableParent(L, PortraitSquadItemBoxBinding::getMetatableName(), wraps::BaseItemBoxBinding::getMetatableName());
    // setMetatableParent(L, PreviewBuildingBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, ResourceLoaderBinding::getMetatableName(), Ogre::ResourceAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, ResourceLoaderBinding::getMetatableName(), Ogre::ResourceBackgroundQueue::ListenerBinding::getMetatableName());
    // setMetatableParent(L, RootObjectContainerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, RootObjectFactoryBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, SaveManagerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, ScreenLabelInterfaceBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, SelectionBoxBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, ShopTraderBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, SquadCellViewBinding::getMetatableName(), wraps::BaseCellViewBinding::getMetatableName());
    // setMetatableParent(L, SquadItemBoxBinding::getMetatableName(), wraps::BaseItemBoxBinding::getMetatableName());
    // setMetatableParent(L, TaskDataBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, TaskerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, TerrainBinding::getMetatableName(), Ogre::FrameListenerBinding::getMetatableName());
    // setMetatableParent(L, TerrainBinding::getMetatableName(), Ogre::MovableObjectBinding::getMetatableName());
    // setMetatableParent(L, ToolTipBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, TownBaseBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, TownBuildingsManagerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, TransformWindowBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, TreeDataBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, TutorialItemBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, TutorialSubItemBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, WeatherRegionBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, ZoneManagerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
    // setMetatableParent(L, ZoneMapBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());
}

void LuaBindings::registerLektor(lua_State* L)
{
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
    LektorPtrBinding<Building*>::registerBinding(L, "lektor<Building*>", BuildingBinding::getMetatableName());
    LektorPtrBinding<FarmBuilding*>::registerBinding(L, "lektor<FarmBuilding*>", FarmBuildingBinding::getMetatableName());
    LektorPtrBinding<FarmBuilding::PlantSource*>::registerBinding(L, "lektor<FarmBuilding::PlantSource*>", FarmBuilding_PlantSourceBinding::getMetatableName());
    LektorPtrBinding<TownBase*>::registerBinding(L, "lektor<TownBase*>", TownBaseBinding::getMetatableName());
    LektorPtrBinding<DatapanelGUI*>::registerBinding(L, "lektor<DatapanelGUI*>", DatapanelGUIBinding::getMetatableName());
    LektorPtrBinding<GUIWindow*>::registerBinding(L, "lektor<GUIWindow*>", GUIWindowBinding::getMetatableName());
    LektorPtrBinding<ScreenLabelInterface*>::registerBinding(L, "lektor<ScreenLabelInterface*>", ScreenLabelInterfaceBinding::getMetatableName());

    LektorValueBinding<ModInfo>::registerBinding(L, "lektor<ModInfo>", ModInfoBinding::getMetatableName());
    LektorValueBinding<hand>::registerBinding(L, "lektor<hand>", HandBinding::getMetatableName());
    LektorValueBinding<SaveInfo>::registerBinding(L, "lektor<SaveInfo>", SaveInfoBinding::getMetatableName());
    LektorValueBinding<StringPair>::registerBinding(L, "lektor<StringPair>", StringPairBinding::getMetatableName());
    LektorValueBinding<Faction::BuildingSwaps>::registerBinding(L, "lektor<Faction::BuildingSwaps>", BuildingSwapsBinding::getMetatableName());
    LektorValueBinding<FarmBuilding::Plant>::registerBinding(L, "lektor<FarmBuilding::Plant>", FarmBuilding_PlantBinding::getMetatableName());

    LektorValueReadOnlyBinding<GameDataValuePair>::registerBinding(L, "lektor<GameDataValuePair>", GameDataValuePairBinding::getMetatableName());
    LektorValueReadOnlyBinding<GameDataGroup>::registerBinding(L, "lektor<GameDataGroup>", GameDataGroupBinding::getMetatableName());

    LektorStringBinding<std::string>::registerBinding(L, "lektor<std::string>");
    LektorIntBinding<int>::registerBinding(L, "lektor<int>");
    
    registerLektorGlobal(L);
}

void LuaBindings::registerOgreUnordered(lua_State* L)
{
    OgreUnorderedSetBinding<hand>::registerBinding(L, "ogre_unordered_set<hand>", HandBinding::getMetatableName());
    OgreUnorderedSetBinding<GameData*>::registerBinding(L, "ogre_unordered_set<GameData*>", GameDataBinding::getMetatableName());
    OgreUnorderedSetBinding<TownBase*>::registerBinding(L, "ogre_unordered_set<TownBase*>", TownBaseBinding::getMetatableName());
    OgreUnorderedSetBinding<Character*>::registerBinding(L, "ogre_unordered_set<Character*>", CharacterBinding::getMetatableName());
    OgreUnorderedSetBinding<RootObject*>::registerBinding(L, "ogre_unordered_set<RootObject*>", RootObjectBinding::getMetatableName());
    OgreUnorderedSetBinding<ZoneMap*>::registerBinding(L, "ogre_unordered_set<ZoneMap*>", ZoneMapBinding::getMetatableName());

    OgreUnorderedMapBinding<RootObject*, float>::registerBinding(L, "ogre_unordered_map<RootObject*, float>", RootObjectBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<Character*, float>::registerBinding(L, "ogre_unordered_map<Character*, float>", CharacterBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<hand, float>::registerBinding(L, "ogre_unordered_map<hand, float>", HandBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<hand, Character*>::registerBinding(L, "ogre_unordered_map<hand, Character*>", HandBinding::getMetatableName(), CharacterBinding::getMetatableName());
    OgreUnorderedMapBinding<GameData*, float>::registerBinding(L, "ogre_unordered_map<GameData*, float>", GameDataBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<ZoneMap*, unsigned char>::registerBinding(L, "ogre_unordered_map<ZoneMap*, unsigned char>", ZoneMapBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<ZoneMap*, bool>::registerBinding(L, "ogre_unordered_map<ZoneMap*, bool>", ZoneMapBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<Faction*, bool>::registerBinding(L, "ogre_unordered_map<Faction*, bool>", FactionBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<GameData*, WorldStateEnum>::registerBinding(L, "ogre_unordered_map<GameData*, WorldStateEnum>", GameDataBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<WorldEventStateQuery*, bool>::registerBinding(L, "ogre_unordered_map<WorldEventStateQuery*, bool>", WorldEventStateQueryBinding::getMetatableName(), nullptr);
    
    registerOgreUnorderedGlobals(L);
}

void LuaBindings::registerStdSet(lua_State* L)
{
    StdSetBinding<hand>::registerBinding(L, "std::set<hand>", HandBinding::getMetatableName());
    StdSetBinding<Faction*>::registerBinding(L, "std::set<Faction*>", FactionBinding::getMetatableName());
    StdSetBinding<GameData*>::registerBinding(L, "std::set<GameData*>", GameDataBinding::getMetatableName());
}

void LuaBindings::registerStdMap(lua_State* L)
{
    StdMapBinding<float, CombatTechniqueData*>::registerBinding(L, "std::map<float, CombatTechniqueData*>", nullptr, CombatTechniqueDataBinding::getMetatableName());
    StdMapBinding<CombatTechniqueData*, float>::registerBinding(L, "std::map<CombatTechniqueData*, float>", CombatTechniqueDataBinding::getMetatableName(), nullptr);
    StdMapBinding<float, GameData*>::registerBinding(L, "std::map<float, GameData*>", nullptr, GameDataBinding::getMetatableName());
    StdMapBinding<GameData*, float>::registerBinding(L, "std::map<GameData*, float>", GameDataBinding::getMetatableName(), nullptr);
    StdMapBinding<GameData*, bool, std::less<GameData*>, std::allocator<std::pair<GameData* const, bool>>>::registerBinding(L, "std::map<GameData*, bool>", GameDataBinding::getMetatableName(), nullptr);
}

void LuaBindings::registerStdDeque(lua_State* L)
{
    StdDequePtrBinding<RootObject*, Ogre::STLAllocator<RootObject*, Ogre::GeneralAllocPolicy>>::registerBinding(L, "std::deque<RootObject*>", RootObjectBinding::getMetatableName());
    StdDequePtrBinding<NestBatcher*, Ogre::STLAllocator<NestBatcher*, Ogre::GeneralAllocPolicy>>::registerBinding(L, "std::deque<NestBatcher*>", nullptr);
    StdDequePtrBinding<RootObjectFactory::CreatelistItem*>::registerBinding(L, "std::deque<CreatelistItem*>", CreatelistItemBinding::getMetatableName());
    StdDequeValueBinding<CraftingItem>::registerBinding(L, "std::deque<CraftingItem>", nullptr);
    StdDequeValueBinding<Character::RagdollMsg>::registerBinding(L, "std::deque<Character::RagdollMsg>", Character_RagdollMsgBinding::getMetatableName());
    StdDequePrimitiveBinding<float>::registerBinding(L, "std::deque<float>", nullptr);
}

void LuaBindings::registerFitnessSelector(lua_State* L)
{
    FitnessSelectorBinding<CombatTechniqueData*>::registerBinding(L, "FitnessSelector<CombatTechniqueData*>", CombatTechniqueDataBinding::getMetatableName(), "std::map<float, CombatTechniqueData*>", "std::map<CombatTechniqueData*, float>");
    FitnessSelectorBinding<GameData*>::registerBinding(L, "FitnessSelector<GameData*>", GameDataBinding::getMetatableName(), "std::map<float, GameData*>", "std::map<GameData*, float>");
}

void LuaBindings::registerSTL(lua_State* L)
{
    registerStdSet(L);
    registerStdMap(L);
    registerStdDeque(L);
}

void LuaBindings::registerClasses(lua_State* L)
{
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
    AppearanceManagerBinding::registerBinding(L);
    AppearanceManager_AppearanceDataBinding::registerBinding(L);
    AppearanceManager_DataCategoryBinding::registerBinding(L);
    AppearanceManager_DataRangeBinding::registerBinding(L);
    AppearanceManager_DataRangePoseBinding::registerBinding(L);
    AppearanceManager_DataRangeVectorBinding::registerBinding(L);
    AppearanceManager_GenderBinding::registerBinding(L);
    ArmourBinding::registerBinding(L);
    AttachedArrowManagerBinding::registerBinding(L);
    AttackSlotManagerBinding::registerBinding(L);
    BackThreadMessagesToMainTBinding::registerBinding(L);
    BackpackInventoryLayoutBinding::registerBinding(L);
    BadSizeBinding::registerBinding(L);
    BinaryVersionBinding::registerBinding(L);
    BoundsViolationBinding::registerBinding(L);
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
    MedicalSystem_HealthPartStatusBinding::registerBinding(L);
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
    MessageForBBinding::registerBinding(L);
    MessageQueue_NodeBinding::registerBinding(L);
    ModInfoBinding::registerBinding(L);
    MotionFilterBinding::registerBinding(L);
    MultiSliderBinding::registerBinding(L);
    MustEndWithSemiColonBinding::registerBinding(L);
    MyGUIBinding::registerBinding(L);
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
    hkVector4fComparisonBinding::registerBinding(L);
    iVector2Binding::registerBinding(L);
    physHitBinding::registerBinding(L);
    rendHitBinding::registerBinding(L);
    BaseLayoutBinding::registerBinding(L);
}

void LuaBindings::registerAll(lua_State* L)
{
    installKenshiLuaTable(L);

    // Register Enums
    registerEnumBindings(L);

    // Register templates centrally before classes are bound
    registerLektor(L);
    registerOgreUnordered(L);
    registerSTL(L);
    registerFitnessSelector(L);

    registerClasses(L);
    registerInheritance(L);
    registerGlobals(L);
}
} // namespace KenshiLua