#include "pch.h"
#include "Lua/LuaBindings.h"
#include "Bindings/Kenshi/AABB2DBinding.h"
#include "Bindings/Kenshi/AI/AIBinding.h"
#include "Bindings/Kenshi/AI/AIEventClassBinding.h"
#include "Bindings/Kenshi/AI/AIPackageBinding.h"
#include "Bindings/Kenshi/AI/AIPatrolToTownBinding.h"
#include "Bindings/Kenshi/AI/AITaskSytemBinding.h"
#include "Bindings/Kenshi/AI/AITaskSytem_ActionsListMgrBinding.h"
#include "Bindings/Kenshi/AI/AITaskSytem_FailedTaskBinding.h"
#include "Bindings/Kenshi/AI/AI_AIResultsCacherBinding.h"
#include "Bindings/Kenshi/AI/ActionDequeBinding.h"
#include "Bindings/Kenshi/AI/BlackboardBinding.h"
#include "Bindings/Kenshi/AI/Blackboard_TaskInfoBinding.h"
#include "Bindings/Kenshi/AI/Contract_DefendPlayerBaseBinding.h"
#include "Bindings/Kenshi/AI/Contract_HiredAllyBinding.h"
#include "Bindings/Kenshi/AI/Contract_TimedBinding.h"
#include "Bindings/Kenshi/AI/Contract_UntilExSlaveBinding.h"
#include "Bindings/Kenshi/AI/Contract_UntilOutOfDangerBinding.h"
#include "Bindings/Kenshi/AI/OrdersReceiverBinding.h"
#include "Bindings/Kenshi/AI/OrdersReceiver_TaskRequestSimpleBinding.h"
#include "Bindings/Kenshi/AI/StateFunctionListBinding.h"
#include "Bindings/Kenshi/AI/TargetInfoBinding.h"
#include "Bindings/Kenshi/AI/TargetWithScoreBinding.h"
#include "Bindings/Kenshi/AI/TaskMatchBinding.h"
#include "Bindings/Kenshi/AI/TaskRequestBinding.h"
#include "Bindings/Kenshi/AIOptionsBinding.h"
#include "Bindings/Kenshi/AbstractMovementBaseBinding.h"
#include "Bindings/Kenshi/ActivePlatoonBinding.h"
#include "Bindings/Kenshi/AkSoundPositionBinding.h"
#include "Bindings/Kenshi/AkVectorBinding.h"
#include "Bindings/Kenshi/AnimalInventoryLayoutBinding.h"
#include "Bindings/Kenshi/Animation/AnimationChoicesBinding.h"
#include "Bindings/Kenshi/Animation/AnimationClassBase_AnimationLayerBinding.h"
#include "Bindings/Kenshi/Animation/AnimationClassBase_SingleAnimationBinding.h"
#include "Bindings/Kenshi/Animation/AnimationEventsBinding.h"
#include "Bindings/Kenshi/Animation/AnimationRequirementBinding.h"
#include "Bindings/Kenshi/Animation/AnimsListsManagerBinding.h"
#include "Bindings/Kenshi/Animation/AnimsListsManager_AnimListBinding.h"
#include "Bindings/Kenshi/Animation/AnimationClassAnimalBinding.h" 
#include "Bindings/Kenshi/Animation/AnimationClassBaseBinding.h"
#include "Bindings/Kenshi/Animation/AnimationClassBinding.h"
#include "Bindings/Kenshi/Animation/AnimationClassHumanBinding.h"
#include "Bindings/Kenshi/Animation/AnimationDataBinding.h"
#include "Bindings/Kenshi/Animation/AnimationEventBinding.h"
#include "Bindings/Kenshi/Animation/AnimationGroundEventBinding.h"
#include "Bindings/Kenshi/Animation/AnimationReloadEventBinding.h"
#include "Bindings/Kenshi/Animation/AnimationSFXEventBinding.h"
#include "Bindings/Kenshi/Animation/RagdollAnimationBinding.h"
#include "Bindings/Kenshi/Animation/RagdollAnimation_RagdollAnimationTrackBinding.h"
#include "Bindings/Kenshi/Appearance/AppearanceAnimalBinding.h"
#include "Bindings/Kenshi/Appearance/AppearanceBaseBinding.h"
#include "Bindings/Kenshi/Appearance/AppearanceHumanBinding.h"
#include "Bindings/Kenshi/Appearance/AppearanceManagerBinding.h"
#include "Bindings/Kenshi/Appearance/AppearanceManager_AppearanceDataBinding.h"
#include "Bindings/Kenshi/Appearance/AppearanceManager_DataCategoryBinding.h"
#include "Bindings/Kenshi/Appearance/AppearanceManager_DataRangeBinding.h"
#include "Bindings/Kenshi/Appearance/AppearanceManager_DataRangePoseBinding.h"
#include "Bindings/Kenshi/Appearance/AppearanceManager_DataRangeVectorBinding.h"
#include "Bindings/Kenshi/Appearance/AppearanceManager_GenderBinding.h"
#include "Bindings/Kenshi/ArmourBinding.h"
#include "Bindings/Kenshi/AttachedArrowManagerBinding.h"
#include "Bindings/Kenshi/Combat/AttackSlotManagerBinding.h"
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
#include "Bindings/Kenshi/Building/CraftingItemBinding.h"
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
#include "Bindings/Kenshi/CampaignDataBinding.h"
#include "Bindings/Kenshi/CampaignInstanceBinding.h"
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
#include "Bindings/Kenshi/Combat/CombatClassBinding.h"
#include "Bindings/Kenshi/Combat/CombatClass_AttackSlotManager_SlotDataBinding.h"
#include "Bindings/Kenshi/Combat/CombatClass_EffectDataBinding.h"
#include "Bindings/Kenshi/CombatMovementControllerBinding.h"
#include "Bindings/Kenshi/Combat/CombatTechniqueDataBinding.h"
#include "Bindings/Kenshi/Combat/CombatStateBinding.h"
#include "Bindings/Kenshi/Combat/AttackStateBinding.h"
#include "Bindings/Kenshi/Combat/CircleStateAIBinding.h"
#include "Bindings/Kenshi/Combat/WaitingStateAIBinding.h"
#include "Bindings/Kenshi/ContainerItemBinding.h"
#include "Bindings/Kenshi/CreatelistItemBinding.h"
#include "Bindings/Kenshi/CrossbowBinding.h"
#include "Bindings/Kenshi/DamagesBinding.h"
#include "Bindings/Kenshi/DataObjectContainerBinding.h"
#include "Bindings/Kenshi/DelayedSpawnMsgBinding.h"
#include "Bindings/Kenshi/Dialogue/DialogActionBinding.h"
#include "Bindings/Kenshi/Dialogue/DialogChoiceListBinding.h"
#include "Bindings/Kenshi/Dialogue/DialogConditionBinding.h"
#include "Bindings/Kenshi/Dialogue/DialogDataManagerBinding.h"
#include "Bindings/Kenshi/Dialogue/DialogLineDataBinding.h"
#include "Bindings/Kenshi/Dialogue/DialogStateBinding.h"
#include "Bindings/Kenshi/Dialogue/DialogueBinding.h"
#include "Bindings/Kenshi/Dialogue/DialogueSpeechBubbleBinding.h"
#include "Bindings/Kenshi/EdgeCacheBinding.h"
#include "Bindings/Kenshi/EdgeCache_EdgeBinding.h"
#include "Bindings/Kenshi/EdgePathNodeBinding.h"
#include "Bindings/Kenshi/EntDataBinding.h"
#include "Bindings/Kenshi/EnumBinding.h"
#include "Bindings/OIS/OISEnumBinding.h"
#include "Bindings/Kenshi/FactionBinding.h"
#include "Bindings/Kenshi/FactionLeaderBinding.h"
#include "Bindings/Kenshi/FactionManagerBinding.h"
#include "Bindings/Kenshi/FactionRelationsBinding.h"
#include "Bindings/Kenshi/FactionUniqueSquadManagerBinding.h"
#include "Bindings/Kenshi/FactionWarMgrBinding.h"
#include "Bindings/Kenshi/Faction_CharacteristicsDataBinding.h"
#include "Bindings/Kenshi/Gui/FactionsScreen_FactionRelationsLine_LessSortBinding.h"
#include "Bindings/Kenshi/FactoryCallbackInterfaceBinding.h"
#include "Bindings/Kenshi/FlagConditionBinding.h"
#include "Bindings/Kenshi/FlockingToolsBinding.h"
#include "Bindings/Kenshi/FoliageSystemBinding.h"
#include "Bindings/Kenshi/FormationMoverBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/GameDataContainerBinding.h"
#include "Bindings/Kenshi/GameDataCopyStandaloneBinding.h"
#include "Bindings/Kenshi/Gui/GameDataEditorWindow_DataItemBinding.h"
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
#include "Bindings/Kenshi/GunClassBinding.h"
#include "Bindings/Kenshi/GunClassPersonalBinding.h"
#include "Bindings/Kenshi/GunClassTurretBinding.h"
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
#include "Bindings/Kenshi/Havok/HavokCharacterBinding.h"
#include "Bindings/Kenshi/MedicalSystem_HealthPartStatusBinding.h"
#include "Bindings/Kenshi/Combat/ImpactPointBinding.h"
#include "Bindings/Kenshi/InputHandlerBinding.h"
#include "Bindings/Kenshi/InputHandler_CommandBinding.h"
#include "Bindings/Kenshi/InstanceIDBinding.h"
#include "Bindings/Kenshi/InventoryBinding.h"
#include "Bindings/Kenshi/Gui/InventoryGUI_FenceCallbackDataBinding.h"
#include "Bindings/Kenshi/InventoryItemBaseBinding.h"
#include "Bindings/Kenshi/InventorySectionBinding.h"
#include "Bindings/Kenshi/ItemBinding.h"
#include "Bindings/Kenshi/ItemDataBinding.h"
#include "Bindings/Kenshi/KingOfRenderThreadBinding.h"
#include "Bindings/Kenshi/LightEntBinding.h"
#include "Bindings/Kenshi/LimbsInventoryLayoutBinding.h"
#include "Bindings/Kenshi/RaceLimiter_LimiterBinding.h"
#include "Bindings/Kenshi/ListenerBinding.h"
#include "Bindings/Kenshi/LockedArmourBinding.h"
#include "Bindings/Kenshi/LoggerBinding.h"
#include "Bindings/Kenshi/MainthreadStateReaderTBinding.h"
#include "Bindings/Kenshi/Gui/ManagementScreen_TechItemViewDataBinding.h"
#include "Bindings/Kenshi/Gui/MapScreen_MapRoadBinding.h"
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
#include "Bindings/Kenshi/Combat/RangedCombatClassBinding.h"
#include "Bindings/Kenshi/RelationDataBinding.h"
#include "Bindings/Kenshi/RenderToTextureotronBinding.h"
#include "Bindings/Kenshi/RendererBinding.h"
#include "Bindings/Kenshi/RendererTBinding.h"
#include "Bindings/Kenshi/RepetitionCounterBinding.h"
#include "Bindings/Kenshi/ResearchBinding.h"
#include "Bindings/Kenshi/ResearchItemBinding.h"
#include "Bindings/Kenshi/Research_BuildingUpgradesBinding.h"
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
#include "Bindings/Kenshi/SerialisableBinding.h"
#include "Bindings/Kenshi/HandleListBaseBinding.h"
#include "Bindings/Kenshi/HandleContainerListBinding.h"
#include "Bindings/Kenshi/PlatoonHandleContainerListBinding.h"
#include "Bindings/Kenshi/ZoneMapHandleContainerListBinding.h"
#include "Bindings/Kenshi/TownHandleContainerListBinding.h"
#include "Bindings/Kenshi/HandleListBinding.h"
#include "Bindings/Kenshi/ItemHandleListBinding.h"
#include "Bindings/Kenshi/HandleManagerBinding.h"
#include "Bindings/Kenshi/LocaleInfoBinding.h"
#include "Bindings/Kenshi/LocaleManagerBinding.h"
#include "Bindings/Kenshi/SharedKingBinding.h"
#include "Bindings/Kenshi/ShopTraderBinding.h"
#include "Bindings/Kenshi/ShopTraderInventoryBinding.h"
#include "Bindings/Kenshi/ShopTraderInventorySectionBinding.h"
#include "Bindings/Kenshi/SimpleTimeStamperBinding.h"
#include "Bindings/Kenshi/SpecificItemLoadFirstBinding.h"
#include "Bindings/Kenshi/SpeedGroupBinding.h"
#include "Bindings/Kenshi/SpotBinding.h"
#include "Bindings/Kenshi/SpottingPeopleMgrBinding.h"
#include "Bindings/Kenshi/StateBroadcastDataBinding.h"
#include "Bindings/Kenshi/StateTBinding.h"
#include "Bindings/Kenshi/StaticEntBinding.h"
#include "Bindings/Kenshi/SwordBinding.h"
#include "Bindings/Kenshi/GameWorld_SysMessageBinding.h"
#include "Bindings/Kenshi/TaskDataBinding.h"
#include "Bindings/Kenshi/TaskStateDataBinding.h"
#include "Bindings/Kenshi/TaskerBinding.h"
#include "Bindings/Kenshi/Terrain/TerrainBinding.h"
#include "Bindings/Kenshi/Terrain/Terrain_BloodQueueBinding.h"
#include "Bindings/Kenshi/Terrain/Terrain_BoxBinding.h"
#include "Bindings/Kenshi/Terrain/Terrain_HitBinding.h"
#include "Bindings/Kenshi/Terrain/Terrain_InfoBinding.h"
#include "Bindings/Kenshi/TextureArrayLoadDataBinding.h"
#include "Bindings/Kenshi/TextureLoadDataBinding.h"
#include "Bindings/Kenshi/ThreadClassBinding.h"
#include "Bindings/Kenshi/ThreadWannabeBinding.h"
#include "Bindings/Kenshi/TownBaseBinding.h"
#include "Bindings/Kenshi/TownBase_ResidentDataBinding.h"
#include "Bindings/Kenshi/TownBinding.h"
#include "Bindings/Kenshi/TownListBinding.h"
#include "Bindings/Kenshi/FormationBinding.h"
#include "Bindings/Kenshi/GameDataScoredListBinding.h"
#include "Bindings/Kenshi/BlueprintItemBinding.h"
#include "Bindings/Kenshi/MapItemBinding.h"
#include "Bindings/Kenshi/MoneyItemBinding.h"
#include "Bindings/Kenshi/NestItemBinding.h"
#include "Bindings/Kenshi/SeveredLimbItemBinding.h"

#include "Bindings/Kenshi/TownBuildingsManagerBinding.h"
#include "Bindings/Kenshi/TownBuildingsManager_BuildingInfoBinding.h"
#include "Bindings/Kenshi/TownPositionCacherBinding.h"
#include "Bindings/Kenshi/Town_NestSpotBinding.h"
#include "Bindings/Kenshi/TradeCultureBinding.h"
#include "Bindings/Kenshi/TraitBoolBinding.h"
#include "Bindings/Kenshi/TreeDataBinding.h"
#include "Bindings/Kenshi/TriggerCallbackBinding.h"
#include "Bindings/Kenshi/UniqueSpawnDataBinding.h"
#include "Bindings/Kenshi/Util/BadSizeBinding.h"
#include "Bindings/Kenshi/Util/BoundsViolationBinding.h"
#include "Bindings/Kenshi/Util/CPerfTimerBinding.h"
#include "Bindings/Kenshi/Util/CPerfTimerTBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
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
#include "Bindings/Kenshi/Weather/WeatherRegionBinding.h"
#include "Bindings/Kenshi/Weather/SeasonBinding.h"
#include "Bindings/Kenshi/Weather/WeatherBinding.h"
#include "Bindings/Kenshi/Weather/WeatherInstanceBinding.h"
#include "Bindings/Kenshi/Weather/WeatherSystemBinding.h"
#include "Bindings/Kenshi/Weather/WeatherSystem_FogValuesBinding.h"
#include "Bindings/Kenshi/Weather/WeatherSystem_ZoneFogBinding.h"
#include "Bindings/Kenshi/WhoSeesMeBinding.h"
#include "Bindings/Kenshi/WorldEventStateQueryBinding.h"
#include "Bindings/Kenshi/WorldEventStateQueryListBinding.h"
#include "Bindings/Kenshi/ZoneManagerBinding.h"
#include "Bindings/Kenshi/ZoneManagerInterfaceTBinding.h"
#include "Bindings/Kenshi/ZoneManager_BiomeGroundEffectsBinding.h"
#include "Bindings/Kenshi/ZoneMapBinding.h"
#include "Bindings/Kenshi/ZoneMapContentBinding.h"
#include "Bindings/Kenshi/ZoneMapContent_HandleDummyBinding.h"
#include "Bindings/Kenshi/ZoneMapContent_ZoneMapContentOrderLoaderBinding.h"
#include "Bindings/Kenshi/ZoneSmellBinding.h"
#include "Bindings/Kenshi/ZoneSmell_SmellBinding.h"
#include "Bindings/Kenshi/ZoneSmell_SmellMsgBinding.h"
#include "Bindings/Kenshi/ZoneSpacialGridBinding.h"
#include "Bindings/Kenshi/ZoneSpacialGrid_ZoneCellBinding.h"
#include "Bindings/Kenshi/Havok/hkBoolBinding.h"
#include "Bindings/Kenshi/Havok/hkContainerHeapAllocatorBinding.h"
#include "Bindings/Kenshi/Havok/hkContainerHeapAllocator_AllocatorBinding.h"
#include "Bindings/Kenshi/Havok/hkMemoryAllocatorBinding.h"
#include "Bindings/Kenshi/Havok/hkMemoryAllocator_ExtendedInterfaceBinding.h"
#include "Bindings/Kenshi/Havok/hkMemoryAllocator_MemoryStatisticsBinding.h"
#include "Bindings/Kenshi/Havok/hkResultBinding.h"
#include "Bindings/Kenshi/Havok/hkVector4fBinding.h"
#include "Bindings/Kenshi/Havok/hkVector4fComparisonBinding.h"
#include "Bindings/Kenshi/physHitBinding.h"

namespace KenshiLua
{

static void registerInheritance(lua_State* L)
{
// --- ACTIVE INHERITANCE WIRING ---
    setMetatableParent(L, AIPatrolToTownBinding::getMetatableName(),                    AIEventClassBinding::getMetatableName());
    setMetatableParent(L, AITaskSytemBinding::getMetatableName(),                       OrdersReceiverBinding::getMetatableName());
    setMetatableParent(L, AITaskSytem_ActionsListMgrBinding::getMetatableName(),        ActionDequeBinding::getMetatableName());
    setMetatableParent(L, AbstractMovementBaseBinding::getMetatableName(),              NxUserControllerHitReportBinding::getMetatableName());
    setMetatableParent(L, ActivePlatoonBinding::getMetatableName(),                     RootObjectContainerBinding::getMetatableName());
    setMetatableParent(L, AnimalInventoryLayoutBinding::getMetatableName(),             InventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, AnimationClassAnimalBinding::getMetatableName(),              AnimationClassBinding::getMetatableName());
    setMetatableParent(L, AnimationClassBinding::getMetatableName(),                    AnimationClassBaseBinding::getMetatableName());
    setMetatableParent(L, AnimationClassHumanBinding::getMetatableName(),               AnimationClassBinding::getMetatableName());
    setMetatableParent(L, AnimationGroundEventBinding::getMetatableName(),              AnimationEventBinding::getMetatableName());
    setMetatableParent(L, AnimationReloadEventBinding::getMetatableName(),              AnimationEventBinding::getMetatableName());
    setMetatableParent(L, AnimationSFXEventBinding::getMetatableName(),                 AnimationEventBinding::getMetatableName());
    setMetatableParent(L, AppearanceAnimalBinding::getMetatableName(),                  AppearanceBaseBinding::getMetatableName());
    setMetatableParent(L, AppearanceHumanBinding::getMetatableName(),                   AppearanceBaseBinding::getMetatableName());
    setMetatableParent(L, AppearanceManager_DataRangePoseBinding::getMetatableName(),   AppearanceManager_DataRangeBinding::getMetatableName());
    setMetatableParent(L, AppearanceManager_DataRangeVectorBinding::getMetatableName(), AppearanceManager_DataRangeBinding::getMetatableName());
    setMetatableParent(L, AttackStateBinding::getMetatableName(),                       CombatStateBinding::getMetatableName());
    setMetatableParent(L, ArmourBinding::getMetatableName(),                            GearBinding::getMetatableName());
    setMetatableParent(L, BackpackInventoryLayoutBinding::getMetatableName(),           GenericFixedInventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, BoxBinding::getMetatableName(),                               BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, BuildInventoryLayoutBinding::getMetatableName(),              InventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, BuildModeWindowBinding::getMetatableName(),                   BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, BuildingBinding::getMetatableName(),                          RootObjectBinding::getMetatableName());
    setMetatableParent(L, BuildingContainerInventoryLayoutBinding::getMetatableName(),  GenericInventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, CPerfTimerTBinding::getMetatableName(),                       CPerfTimerBinding::getMetatableName());
    setMetatableParent(L, CharMovementBinding::getMetatableName(),                      AbstractMovementBaseBinding::getMetatableName());
    setMetatableParent(L, CircleStateAIBinding::getMetatableName(),                     CombatStateBinding::getMetatableName());
    setMetatableParent(L, CharacterAnimalBinding::getMetatableName(),                   CharacterBinding::getMetatableName());
    setMetatableParent(L, CharacterBinding::getMetatableName(),                         RootObjectBinding::getMetatableName());
    setMetatableParent(L, CharacterEditWindowBinding::getMetatableName(),               BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, CharacterHumanBinding::getMetatableName(),                    CharacterBinding::getMetatableName());
    setMetatableParent(L, CharacterInventoryLayoutBinding::getMetatableName(),          InventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, CharacterStatsWindowBinding::getMetatableName(),              GUIWindowBinding::getMetatableName());
    setMetatableParent(L, CharacterTradingWindowBinding::getMetatableName(),            GUIWindowBinding::getMetatableName());
    setMetatableParent(L, ContainerItemBinding::getMetatableName(),                     ItemBinding::getMetatableName());
    setMetatableParent(L, ContextMenuGUIBinding::getMetatableName(),                    BaseLayoutBinding::getMetatableName());
    setMetatableParent(L, Contract_DefendPlayerBaseBinding::getMetatableName(),         Contract_HiredAllyBinding::getMetatableName());
    setMetatableParent(L, Contract_HiredAllyBinding::getMetatableName(),                Contract_TimedBinding::getMetatableName());
    setMetatableParent(L, Contract_TimedBinding::getMetatableName(),                    AIPackageBinding::getMetatableName());
    setMetatableParent(L, Contract_UntilExSlaveBinding::getMetatableName(),             AIPackageBinding::getMetatableName());
    setMetatableParent(L, Contract_UntilOutOfDangerBinding::getMetatableName(),         Contract_TimedBinding::getMetatableName());
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
    setMetatableParent(L, GunClassPersonalBinding::getMetatableName(),                  GunClassBinding::getMetatableName());
    setMetatableParent(L, GunClassTurretBinding::getMetatableName(),                    GunClassBinding::getMetatableName());
    setMetatableParent(L, HandleListBaseBinding::getMetatableName(),             SerialisableBinding::getMetatableName());
    setMetatableParent(L, HandleContainerListBinding::getMetatableName(),        HandleListBaseBinding::getMetatableName());
    setMetatableParent(L, PlatoonHandleContainerListBinding::getMetatableName(), HandleContainerListBinding::getMetatableName());
    setMetatableParent(L, ZoneMapHandleContainerListBinding::getMetatableName(), HandleContainerListBinding::getMetatableName());
    setMetatableParent(L, TownHandleContainerListBinding::getMetatableName(),    HandleContainerListBinding::getMetatableName());
    setMetatableParent(L, HandleListBinding::getMetatableName(),                 HandleListBaseBinding::getMetatableName());
    setMetatableParent(L, ItemHandleListBinding::getMetatableName(),             HandleListBinding::getMetatableName());
    setMetatableParent(L, HandleManagerBinding::getMetatableName(),              SerialisableBinding::getMetatableName());
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
    setMetatableParent(L, RendererBinding::getMetatableName(),                          RendererTBinding::getMetatableName());
    setMetatableParent(L, RobotLimbItemBinding::getMetatableName(),                     GearBinding::getMetatableName());
    setMetatableParent(L, RootObjectBinding::getMetatableName(),                        RootObjectBaseBinding::getMetatableName());
        setMetatableParent(L, TownListBinding::getMetatableName(),                     RootObjectContainerBinding::getMetatableName());
    setMetatableParent(L, GameDataScoredListBinding::getMetatableName(),            "FitnessSelector<GameData*>");
    setMetatableParent(L, BlueprintItemBinding::getMetatableName(),                 ItemBinding::getMetatableName());
    setMetatableParent(L, MapItemBinding::getMetatableName(),                       ItemBinding::getMetatableName());
    setMetatableParent(L, MoneyItemBinding::getMetatableName(),                     ItemBinding::getMetatableName());
    setMetatableParent(L, NestItemBinding::getMetatableName(),                      ItemBinding::getMetatableName());
    setMetatableParent(L, SeveredLimbItemBinding::getMetatableName(),               ItemBinding::getMetatableName());
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
    setMetatableParent(L, WaitingStateAIBinding::getMetatableName(),                    CombatStateBinding::getMetatableName());
    setMetatableParent(L, WindGeneratorBuildingBinding::getMetatableName(),             GeneratorBuildingBinding::getMetatableName());
    setMetatableParent(L, ZoneManagerBinding::getMetatableName(),                       ZoneManagerInterfaceTBinding::getMetatableName());
    setMetatableParent(L, ZoneMapContentBinding::getMetatableName(),                     RootObjectContainerBinding::getMetatableName());
    setMetatableParent(L, ZoneMapContent_HandleDummyBinding::getMetatableName(),        RootObjectBaseBinding::getMetatableName());
    setMetatableParent(L, ZoneMapContent_ZoneMapContentOrderLoaderBinding::getMetatableName(), SpecificItemLoadFirstBinding::getMetatableName());

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

void LuaBindings::registerClasses(lua_State* L)
{
    AABB2DBinding::registerBinding(L);
    AIBinding::registerBinding(L);
    AIEventClassBinding::registerBinding(L);
    AIPackageBinding::registerBinding(L);
    AIPatrolToTownBinding::registerBinding(L);
    AITaskSytemBinding::registerBinding(L);
    AITaskSytem_ActionsListMgrBinding::registerBinding(L);
    AITaskSytem_FailedTaskBinding::registerBinding(L);
    AI_AIResultsCacherBinding::registerBinding(L);
    ActionDequeBinding::registerBinding(L);
    BlackboardBinding::registerBinding(L);
    Blackboard_TaskInfoBinding::registerBinding(L);
    Contract_DefendPlayerBaseBinding::registerBinding(L);
    Contract_HiredAllyBinding::registerBinding(L);
    Contract_TimedBinding::registerBinding(L);
    Contract_UntilExSlaveBinding::registerBinding(L);
    Contract_UntilOutOfDangerBinding::registerBinding(L);
    OrdersReceiverBinding::registerBinding(L);
    OrdersReceiver_TaskRequestSimpleBinding::registerBinding(L);
    StateFunctionListBinding::registerBinding(L);
    TargetInfoBinding::registerBinding(L);
    TargetWithScoreBinding::registerBinding(L);
    TaskMatchBinding::registerBinding(L);
    TaskRequestBinding::registerBinding(L);
    AIOptionsBinding::registerBinding(L);
    AbstractMovementBaseBinding::registerBinding(L);
    ActivePlatoonBinding::registerBinding(L);
    AkSoundPositionBinding::registerBinding(L);
    AkVectorBinding::registerBinding(L);
    AnimalInventoryLayoutBinding::registerBinding(L);
    AnimationChoicesBinding::registerBinding(L);
    AnimationClassBase_AnimationLayerBinding::registerBinding(L);
    AnimationClassBase_SingleAnimationBinding::registerBinding(L);
    AnimationEventsBinding::registerBinding(L);
    AnimationRequirementBinding::registerBinding(L);
    AnimsListsManagerBinding::registerBinding(L);
    AnimsListsManager_AnimListBinding::registerBinding(L);
    AnimationClassAnimalBinding::registerBinding(L);
    AnimationClassBaseBinding::registerBinding(L);
    AnimationClassBinding::registerBinding(L);
    AnimationClassHumanBinding::registerBinding(L);
    AnimationDataBinding::registerBinding(L);
    AnimationEventBinding::registerBinding(L);
    AnimationGroundEventBinding::registerBinding(L);
    AnimationReloadEventBinding::registerBinding(L);
    AnimationSFXEventBinding::registerBinding(L);
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
    AttackStateBinding::registerBinding(L);
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
    CampaignDataBinding::registerBinding(L);
    CampaignInstanceBinding::registerBinding(L);
    CampaignRequestBinding::registerBinding(L);
    CampaignTriggerDataBinding::registerBinding(L);
    CharBodyBinding::registerBinding(L);
    CharMovementBinding::registerBinding(L);
    CircleStateAIBinding::registerBinding(L);
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
    CombatStateBinding::registerBinding(L);
    CombatTechniqueDataBinding::registerBinding(L);
    ConstructionStateBinding::registerBinding(L);
    ConsumptionItemBinding::registerBinding(L);
    ContainerItemBinding::registerBinding(L);
    ContextMenuBinding::registerBinding(L);
    ContextMenuGUIBinding::registerBinding(L);
    CraftingBuildingBinding::registerBinding(L);
    CraftingItemBinding::registerBinding(L);
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
    GunClassBinding::registerBinding(L);
    GunClassPersonalBinding::registerBinding(L);
    GunClassTurretBinding::registerBinding(L);
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
    KingOfRenderThreadBinding::registerBinding(L);
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
    RagdollAnimationBinding::registerBinding(L);
    RagdollAnimation_RagdollAnimationTrackBinding::registerBinding(L);
    RainCollectorBuildingBinding::registerBinding(L);
    RangedCombatClassBinding::registerBinding(L);
    RelationDataBinding::registerBinding(L);
    RenderToTextureotronBinding::registerBinding(L);
    RendererTBinding::registerBinding(L);
    RendererBinding::registerBinding(L);
    RepetitionCounterBinding::registerBinding(L);
    ResearchBinding::registerBinding(L);
    ResearchItemBinding::registerBinding(L);
    Research_BuildingUpgradesBinding::registerBinding(L);
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
    SeasonBinding::registerBinding(L);
    SeenSomeoneBinding::registerBinding(L);
    SelectionBoxBinding::registerBinding(L);
    SenseItrBinding::registerBinding(L);
    SensoryDataBinding::registerBinding(L);
    SerialisableBinding::registerBinding(L);
    HandleListBaseBinding::registerBinding(L);
    HandleContainerListBinding::registerBinding(L);
    PlatoonHandleContainerListBinding::registerBinding(L);
    ZoneMapHandleContainerListBinding::registerBinding(L);
    TownHandleContainerListBinding::registerBinding(L);
    HandleListBinding::registerBinding(L);
    ItemHandleListBinding::registerBinding(L);
    HandleManagerBinding::registerBinding(L);
    LocaleInfoBinding::registerBinding(L);
    LocaleManagerBinding::registerBinding(L);
    SharedKingBinding::registerBinding(L);
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
    StateBroadcastDataBinding::registerBinding(L);
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
    TownListBinding::registerBinding(L);
    FormationBinding::registerBinding(L);
    GameDataScoredListBinding::registerBinding(L);
    BlueprintItemBinding::registerBinding(L);
    MapItemBinding::registerBinding(L);
    MoneyItemBinding::registerBinding(L);
    NestItemBinding::registerBinding(L);
    SeveredLimbItemBinding::registerBinding(L);

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
    WaitingStateAIBinding::registerBinding(L);
    WallBuildingBinding::registerBinding(L);
    WeaponBinding::registerBinding(L);
    WeatherBinding::registerBinding(L);
    WeatherInstanceBinding::registerBinding(L);
    WeatherRegionBinding::registerBinding(L);
    WeatherSystemBinding::registerBinding(L);
    WeatherSystem_FogValuesBinding::registerBinding(L);
    WeatherSystem_ZoneFogBinding::registerBinding(L);
    WhoSeesMeBinding::registerBinding(L);
    WindGeneratorBuildingBinding::registerBinding(L);
    WorldEventStateQueryBinding::registerBinding(L);
    WorldEventStateQueryListBinding::registerBinding(L);
    YesNoMaybeBinding::registerBinding(L);
    ZoneManagerBinding::registerBinding(L);
    ZoneManagerInterfaceTBinding::registerBinding(L);
    ZoneManager_BiomeGroundEffectsBinding::registerBinding(L);
    ZoneMapBinding::registerBinding(L);
    ZoneMapContentBinding::registerBinding(L);
    ZoneMapContent_HandleDummyBinding::registerBinding(L);
    ZoneMapContent_ZoneMapContentOrderLoaderBinding::registerBinding(L);
    ZoneSmellBinding::registerBinding(L);
    ZoneSmell_SmellBinding::registerBinding(L);
    ZoneSmell_SmellMsgBinding::registerBinding(L);
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
    registerOISEnumBindings(L);

    registerContainers(L);

    registerClasses(L);
    registerInheritance(L);
    registerGlobals(L);
}
} // namespace KenshiLua
