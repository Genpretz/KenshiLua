#include "pch.h"
#include "Lua/LuaBindings.h"
#include "Bindings/EnumBinding.h"
#include "Bindings/AABB2DBinding.h"
#include "Bindings/AIOptionsBinding.h"
#include "Bindings/AbstractMovementBaseBinding.h"
#include "Bindings/ActivePlatoonBinding.h"
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
#include "Bindings/BuildingSwapsBinding.h"
#include "Bindings/Building/BuildInventoryLayoutBinding.h"
#include "Bindings/Building/BuildMaterialBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/Building/BuildingContainerInventoryLayoutBinding.h"
#include "Bindings/Building/BuildingPlacementGroundTypeBinding.h"
#include "Bindings/Building/ConstructionStateBinding.h"
#include "Bindings/Building/ConsumptionItemBinding.h"
#include "Bindings/Building/CraftingBuildingBinding.h"
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
#include "Bindings/CombatClassBinding.h"
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
#include "Bindings/FactionBinding.h"
#include "Bindings/FactionLeaderBinding.h"
#include "Bindings/FactionManagerBinding.h"
#include "Bindings/FactionRelationsBinding.h"
#include "Bindings/FactionUniqueSquadManagerBinding.h"
#include "Bindings/FactionWarMgrBinding.h"
#include "Bindings/FactoryCallbackInterfaceBinding.h"
#include "Bindings/FlagConditionBinding.h"
#include "Bindings/FlockingToolsBinding.h"
#include "Bindings/FormationMoverBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/GameDataCopyStandaloneBinding.h"
#include "Bindings/GameDataHeaderBinding.h"
#include "Bindings/GameDataManagerBinding.h"
#include "Bindings/GameDataReferenceBinding.h"
#include "Bindings/GameDataValuePairBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/GameWorldBinding.h"
#include "Bindings/GameplayOptionsBinding.h"
#include "Bindings/GearBinding.h"
#include "Bindings/GlobalConstantsBinding.h"
#include "Bindings/GlobalBinding.h"
#include "Bindings/Gui/BackpackInventoryLayoutBinding.h"
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
#include "Bindings/HasRoomCacheBinding.h"
#include "Bindings/HealthPartStatusBinding.h"
#include "Bindings/ImpactPointBinding.h"
#include "Bindings/InputHandlerBinding.h"
#include "Bindings/InstanceIDBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/InventoryItemBaseBinding.h"
#include "Bindings/InventorySectionBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/ItemDataBinding.h"
#include "Bindings/LimbsInventoryLayoutBinding.h"
#include "Bindings/LimiterBinding.h"
#include "Bindings/LockedArmourBinding.h"
#include "Bindings/MainthreadStateReaderTBinding.h"
#include "Bindings/MedianFilter2DVectorBinding.h"
#include "Bindings/MedianFilterBinding.h"
#include "Bindings/MedicalSystemBinding.h"
#include "Bindings/MeshDataLookupBinding.h"
#include "Bindings/MeshLoadDataBinding.h"
#include "Bindings/ModInfoBinding.h"
#include "Bindings/MotionFilterBinding.h"
#include "Bindings/MyGuiBinding.h"
#include "Bindings/NxUserControllerHitReportBinding.h"
#include "Bindings/ObjectInstanceBinding.h"
#include "Bindings/OptionsHolderBinding.h"
#include "Bindings/OwnershipsBinding.h"
#include "Bindings/ParticlePoolBinding.h"
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
#include "Bindings/SaveFileSystemBinding.h"
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
#include "Bindings/SwordBinding.h"
#include "Bindings/SysMessageBinding.h"
#include "Bindings/TaskDataBinding.h"
#include "Bindings/TaskStateDataBinding.h"
#include "Bindings/TaskerBinding.h"
#include "Bindings/TextureArrayLoadDataBinding.h"
#include "Bindings/TextureLoadDataBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/TownBinding.h"
#include "Bindings/TownBuildingsManagerBinding.h"
#include "Bindings/TownPositionCacherBinding.h"
#include "Bindings/TradeCultureBinding.h"
#include "Bindings/UniqueSpawnDataBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/StringPairBinding.h"
#include "Bindings/Util/TimeOfDayBinding.h"
#include "Bindings/Util/YesNoMaybeBinding.h"
#include "Bindings/Util/iVector2Binding.h"
#include "Bindings/VisibleObjectInfoBinding.h"
#include "Bindings/WeaponBinding.h"
#include "Bindings/WhoSeesMeBinding.h"
#include "Bindings/WorldEventStateQueryBinding.h"
#include "Bindings/WorldEventStateQueryListBinding.h"
#include "Bindings/ZoneManagerBinding.h"
#include "Bindings/ZoneManagerInterfaceTBinding.h"
#include "Bindings/ZoneMapBinding.h"
#include "Bindings/ZoneSpacialGridBinding.h"
#include "Bindings/physHitBinding.h"
#include "Bindings/Gui/BaseLayoutBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"
#include "Bindings/Util/StdMapBinding.h"
#include "Bindings/FitnessSelectorBinding.h"

namespace KenshiLua
{

void LuaBindings::registerAll(lua_State* L)
{
    installKenshiLuaTable(L);
    registerGlobals(L);

    // Register Enums
    registerEnumBindings(L);

    // Register templates centrally before classes are bound
    LektorPtrBinding<CombatTechniqueData*>::registerBinding(L, "lektor<CombatTechniqueData*>", CombatTechniqueDataBinding::getMetatableName());
    LektorPtrBinding<Item*>::registerBinding(L, "lektor<Item*>", ItemBinding::getMetatableName());
    LektorPtrBinding<InventorySection*>::registerBinding(L, "lektor<InventorySection*>", InventorySectionBinding::getMetatableName());
    LektorPtrBinding<GameData*>::registerBinding(L, "lektor<GameData*>", GameDataBinding::getMetatableName());
    LektorPtrBinding<RootObject*>::registerBinding(L, "lektor<RootObject*>", RootObjectBinding::getMetatableName());
    
    OgreUnorderedMapBinding<GameData*, float>::registerBinding(L, "ogre_unordered_map<GameData*, float>", GameDataBinding::getMetatableName(), nullptr);
    OgreUnorderedSetBinding<hand>::registerBinding(L, "ogre_unordered_set<hand>", handBinding::getMetatableName());
    OgreUnorderedSetBinding<GameData*>::registerBinding(L, "ogre_unordered_set<GameData*>", GameDataBinding::getMetatableName());
    OgreUnorderedSetBinding<TownBase*>::registerBinding(L, "ogre_unordered_set<TownBase*>", TownBaseBinding::getMetatableName());
    OgreUnorderedMapBinding<ZoneMap*, unsigned char>::registerBinding(L, "ogre_unordered_map<ZoneMap*, unsigned char>", ZoneMapBinding::getMetatableName(), nullptr);
    OgreUnorderedSetBinding<Character*>::registerBinding(L, "ogre_unordered_set<Character*>", CharacterBinding::getMetatableName());
    OgreUnorderedSetBinding<RootObject*>::registerBinding(L, "ogre_unordered_set<RootObject*>", RootObjectBinding::getMetatableName());
    OgreUnorderedMapBinding<RootObject*, float>::registerBinding(L, "ogre_unordered_map<RootObject*, float>", RootObjectBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<hand, float>::registerBinding(L, "ogre_unordered_map<hand, float>", handBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<hand, Character*>::registerBinding(L, "ogre_unordered_map<hand, Character*>", handBinding::getMetatableName(), CharacterBinding::getMetatableName());
    
    StdMapBinding<float, CombatTechniqueData*>::registerBinding(L, "OgreMap<float, CombatTechniqueData*>", nullptr, CombatTechniqueDataBinding::getMetatableName());
    StdMapBinding<CombatTechniqueData*, float>::registerBinding(L, "OgreMap<CombatTechniqueData*, float>", CombatTechniqueDataBinding::getMetatableName(), nullptr);
    StdMapBinding<float, GameData*>::registerBinding(L, "OgreMap<float, GameData*>", nullptr, GameDataBinding::getMetatableName());
    StdMapBinding<GameData*, float>::registerBinding(L, "OgreMap<GameData*, float>", GameDataBinding::getMetatableName(), nullptr);
    
    FitnessSelectorBinding<CombatTechniqueData*>::registerBinding(L, "KenshiLua.FitnessSelector_CombatTechniqueData", CombatTechniqueDataBinding::getMetatableName(), "OgreMap<float, CombatTechniqueData*>", "OgreMap<CombatTechniqueData*, float>");
    FitnessSelectorBinding<GameData*>::registerBinding(L, "KenshiLua.FitnessSelector_GameData", GameDataBinding::getMetatableName(), "OgreMap<float, GameData*>", "OgreMap<GameData*, float>");

    // Register Classes
    AABB2DBinding::registerBinding(L);
    AIOptionsBinding::registerBinding(L);
    AbstractMovementBaseBinding::registerBinding(L);
    ActivePlatoonBinding::registerBinding(L);
    AnimalInventoryLayoutBinding::registerBinding(L);
    AppearanceAnimalBinding::registerBinding(L);
    AppearanceBaseBinding::registerBinding(L);
    AppearanceHumanBinding::registerBinding(L);
    ArmourBinding::registerBinding(L);
    AttachedArrowManagerBinding::registerBinding(L);
    AttackSlotManagerBinding::registerBinding(L);
    BackThreadMessagesToMainTBinding::registerBinding(L);
    BountyBinding::registerBinding(L);
    BountyManagerBinding::registerBinding(L);
    BuildingSwapsBinding::registerBinding(L);
    BuildInventoryLayoutBinding::registerBinding(L);
    BuildMaterialBinding::registerBinding(L);
    BuildingBinding::registerBinding(L);
    BuildingContainerInventoryLayoutBinding::registerBinding(L);
    BuildingPlacementGroundTypeBinding::registerBinding(L);
    ConstructionStateBinding::registerBinding(L);
    ConsumptionItemBinding::registerBinding(L);
    CraftingBuildingBinding::registerBinding(L);
    CraftingInventoryLayoutBinding::registerBinding(L);
    DoorStuffBinding::registerBinding(L);
    FarmBatchBinding::registerBinding(L);
    FarmBuildingBinding::registerBinding(L);
    FootprintBinding::registerBinding(L);
    FootprintNodeBinding::registerBinding(L);
    FurnaceBuildingBinding::registerBinding(L);
    FurnaceInventoryLayoutBinding::registerBinding(L);
    GameDataGroupBinding::registerBinding(L);
    GatewayBuildingBinding::registerBinding(L);
    GeneratorBuildingBinding::registerBinding(L);
    GenericInventoryLayoutBinding::registerBinding(L);
    LightBuildingBinding::registerBinding(L);
    PreviewBuildingBinding::registerBinding(L);
    ProductionBuildingBinding::registerBinding(L);
    ProductionInventoryLayoutBinding::registerBinding(L);
    RainCollectorBuildingBinding::registerBinding(L);
    ResearchBuildingBinding::registerBinding(L);
    ResearchBuildingInventoryLayoutBinding::registerBinding(L);
    StorageBuildingBinding::registerBinding(L);
    TortureBuildingBinding::registerBinding(L);
    TurretBuildingBinding::registerBinding(L);
    UseableStuffBinding::registerBinding(L);
    WallBuildingBinding::registerBinding(L);
    WindGeneratorBuildingBinding::registerBinding(L);
    CameraClassBinding::registerBinding(L);
    CampaignRequestBinding::registerBinding(L);
    CampaignTriggerDataBinding::registerBinding(L);
    CharBodyBinding::registerBinding(L);
    CharMovementBinding::registerBinding(L);
    CharStatsBinding::registerBinding(L);
    CharacterAnimalBinding::registerBinding(L);
    CharacterBinding::registerBinding(L);
    CharacterHumanBinding::registerBinding(L);
    CharacterInventoryLayoutBinding::registerBinding(L);
    CombatClassBinding::registerBinding(L);
    CombatMovementControllerBinding::registerBinding(L);
    CombatTechniqueDataBinding::registerBinding(L);
    ContainerItemBinding::registerBinding(L);
    CreatelistItemBinding::registerBinding(L);
    CrossbowBinding::registerBinding(L);
    DamagesBinding::registerBinding(L);
    DataObjectContainerBinding::registerBinding(L);
    DelayedSpawnMsgBinding::registerBinding(L);
    DialogActionBinding::registerBinding(L);
    DialogChoiceListBinding::registerBinding(L);
    DialogConditionBinding::registerBinding(L);
    DialogDataManagerBinding::registerBinding(L);
    DialogLineDataBinding::registerBinding(L);
    DialogStateBinding::registerBinding(L);
    DialogueBinding::registerBinding(L);
    DialogueSpeechBubbleBinding::registerBinding(L);
    FactionBinding::registerBinding(L);
    FactionLeaderBinding::registerBinding(L);
    FactionManagerBinding::registerBinding(L);
    FactionRelationsBinding::registerBinding(L);
    FactionUniqueSquadManagerBinding::registerBinding(L);
    FactionWarMgrBinding::registerBinding(L);
    FactoryCallbackInterfaceBinding::registerBinding(L);
    FlagConditionBinding::registerBinding(L);
    FlockingToolsBinding::registerBinding(L);
    FormationMoverBinding::registerBinding(L);
    GameDataBinding::registerBinding(L);
    GameDataContainerBinding::registerBinding(L);
    GameDataCopyStandaloneBinding::registerBinding(L);
    GameDataHeaderBinding::registerBinding(L);
    GameDataManagerBinding::registerBinding(L);
    GameDataReferenceBinding::registerBinding(L);
    GameDataValuePairBinding::registerBinding(L);
    GameSaveStateBinding::registerBinding(L);
    GameWorldBinding::registerBinding(L);
    GameplayOptionsBinding::registerBinding(L);
    GearBinding::registerBinding(L);
    GlobalConstantsBinding::registerBinding(L);
    BackpackInventoryLayoutBinding::registerBinding(L);
    BoxBinding::registerBinding(L);
    BuildModeWindowBinding::registerBinding(L);
    BuildingCategoryBinding::registerBinding(L);
    BuildingGroupBinding::registerBinding(L);
    CharacterEditWindowBinding::registerBinding(L);
    CharacterStatsWindowBinding::registerBinding(L);
    CharacterTradingWindowBinding::registerBinding(L);
    ContextMenuBinding::registerBinding(L);
    ContextMenuGUIBinding::registerBinding(L);
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
    DialogueWindowBinding::registerBinding(L);
    FactionListWindowBinding::registerBinding(L);
    FactionRelationsLineBinding::registerBinding(L);
    FactionsScreenBinding::registerBinding(L);
    FloatingProgressBarBinding::registerBinding(L);
    FogEditorBinding::registerBinding(L);
    ForgottenGUIBinding::registerBinding(L);
    GUIWindowBinding::registerBinding(L);
    GameDataEditorWindowBinding::registerBinding(L);
    GamedataSelectionListBinding::registerBinding(L);
    GenericFixedInventoryLayoutBinding::registerBinding(L);
    ImportGameMenuBinding::registerBinding(L);
    InteriorModeButtonWindowBinding::registerBinding(L);
    InventoryGUIBinding::registerBinding(L);
    InventoryIconBinding::registerBinding(L);
    InventoryLayoutBinding::registerBinding(L);
    InventorySectionGUIBinding::registerBinding(L);
    InventoryTradeDataBinding::registerBinding(L);
    InventoryTraderGUIBinding::registerBinding(L);
    ItemListWindowBinding::registerBinding(L);
    LevelEditorBinding::registerBinding(L);
    ListScrollBarBinding::registerBinding(L);
    LoadSaveWindowBinding::registerBinding(L);
    LoadingWindowBinding::registerBinding(L);
    MainBarGUIBinding::registerBinding(L);
    MainTabPortraitPlatoonBinding::registerBinding(L);
    ManagementScreenBinding::registerBinding(L);
    MapMarkerCharacterBinding::registerBinding(L);
    MapMarkerTownBinding::registerBinding(L);
    MapScreenBinding::registerBinding(L);
    MessageBoxManagerBinding::registerBinding(L);
    MultiSliderBinding::registerBinding(L);
    NewGameOptionsWindowBinding::registerBinding(L);
    NewGameWindowBinding::registerBinding(L);
    NpcListWindowBinding::registerBinding(L);
    OpenSaveFileDialogBinding::registerBinding(L);
    OptionsWindowBinding::registerBinding(L);
    OrderCellViewBinding::registerBinding(L);
    OrderDataBinding::registerBinding(L);
    OrdersItemBoxBinding::registerBinding(L);
    OrdersPanelBinding::registerBinding(L);
    PortraitDataBinding::registerBinding(L);
    PortraitImageBinding::registerBinding(L);
    PortraitMainCellViewBinding::registerBinding(L);
    PortraitManagerBinding::registerBinding(L);
    PortraitSquadCellViewBinding::registerBinding(L);
    PortraitSquadItemBoxBinding::registerBinding(L);
    ProgressBarWidgetBinding::registerBinding(L);
    ProspectingWindowBinding::registerBinding(L);
    ResourceLinePanelBinding::registerBinding(L);
    ScreenLabelBinding::registerBinding(L);
    ScreenLabelDebugBinding::registerBinding(L);
    ScreenLabelInterfaceBinding::registerBinding(L);
    SliderBinding::registerBinding(L);
    SplashScreenBinding::registerBinding(L);
    SquadCellViewBinding::registerBinding(L);
    SquadDataBinding::registerBinding(L);
    SquadItemBoxBinding::registerBinding(L);
    SquadListWindowBinding::registerBinding(L);
    SquadManagementScreenBinding::registerBinding(L);
    StatBinding::registerBinding(L);
    StatGroupBinding::registerBinding(L);
    TitleScreenBinding::registerBinding(L);
    ToolTipBinding::registerBinding(L);
    ToolTipDynamicBinding::registerBinding(L);
    ToolTipFixedBinding::registerBinding(L);
    ToolTipInventoryBinding::registerBinding(L);
    ToolTipLineBinding::registerBinding(L);
    ToolTipStaticBinding::registerBinding(L);
    TownListWindowBinding::registerBinding(L);
    TradeResultBinding::registerBinding(L);
    TraderInventoryLayoutBinding::registerBinding(L);
    TransformWindowBinding::registerBinding(L);
    TutorialGUIBinding::registerBinding(L);
    TutorialGUILineBinding::registerBinding(L);
    TutorialItemBinding::registerBinding(L);
    TutorialSubItemBinding::registerBinding(L);
    TutorialpediaGUIBinding::registerBinding(L);
    HasRoomCacheBinding::registerBinding(L);
    HealthPartStatusBinding::registerBinding(L);
    ImpactPointBinding::registerBinding(L);
    InputHandlerBinding::registerBinding(L);
    InstanceIDBinding::registerBinding(L);
    InventoryBinding::registerBinding(L);
    InventoryItemBaseBinding::registerBinding(L);
    InventorySectionBinding::registerBinding(L);
    ItemBinding::registerBinding(L);
    ItemDataBinding::registerBinding(L);
    LimbsInventoryLayoutBinding::registerBinding(L);
    LimiterBinding::registerBinding(L);
    LockedArmourBinding::registerBinding(L);
    MainthreadStateReaderTBinding::registerBinding(L);
    MedianFilter2DVectorBinding::registerBinding(L);
    MedianFilterBinding::registerBinding(L);
    MedicalSystemBinding::registerBinding(L);
    MeshDataLookupBinding::registerBinding(L);
    MeshLoadDataBinding::registerBinding(L);
    ModInfoBinding::registerBinding(L);
    MotionFilterBinding::registerBinding(L);
    MyGuiBinding::registerBinding(L);
    NxUserControllerHitReportBinding::registerBinding(L);
    ObjectInstanceBinding::registerBinding(L);
    OptionsHolderBinding::registerBinding(L);
    OwnershipsBinding::registerBinding(L);
    ParticlePoolBinding::registerBinding(L);
    PlatoonBinding::registerBinding(L);
    PlayerInterfaceBinding::registerBinding(L);
    ProsperityManagerBinding::registerBinding(L);
    RaceDataBinding::registerBinding(L);
    RaceLimiterBinding::registerBinding(L);
    RelationDataBinding::registerBinding(L);
    RepetitionCounterBinding::registerBinding(L);
    ResourceLoadRequestMeshBinding::registerBinding(L);
    ResourceLoadRequestTextureBinding::registerBinding(L);
    ResourceLoaderBinding::registerBinding(L);
    RobotLimbItemBinding::registerBinding(L);
    RobotLimbsBinding::registerBinding(L);
    RootObjectBaseBinding::registerBinding(L);
    RootObjectBinding::registerBinding(L);
    RootObjectContainerBinding::registerBinding(L);
    RootObjectFactoryBinding::registerBinding(L);
    SaveFileSystemBinding::registerBinding(L);
    SaveManagerBinding::registerBinding(L);
    SectionItemBinding::registerBinding(L);
    SeenSomeoneBinding::registerBinding(L);
    SelectionBoxBinding::registerBinding(L);
    SenseItrBinding::registerBinding(L);
    SensoryDataBinding::registerBinding(L);
    ShopTraderBinding::registerBinding(L);
    ShopTraderInventoryBinding::registerBinding(L);
    ShopTraderInventorySectionBinding::registerBinding(L);
    SimpleTimeStamperBinding::registerBinding(L);
    SpecificItemLoadFirstBinding::registerBinding(L);
    SpeedGroupBinding::registerBinding(L);
    SpotBinding::registerBinding(L);
    SpottingPeopleMgrBinding::registerBinding(L);
    StateTBinding::registerBinding(L);
    SwordBinding::registerBinding(L);
    SysMessageBinding::registerBinding(L);
    TaskDataBinding::registerBinding(L);
    TaskStateDataBinding::registerBinding(L);
    TaskerBinding::registerBinding(L);
    TextureArrayLoadDataBinding::registerBinding(L);
    TextureLoadDataBinding::registerBinding(L);
    TownBaseBinding::registerBinding(L);
    TownBinding::registerBinding(L);
    TownBuildingsManagerBinding::registerBinding(L);
    TownPositionCacherBinding::registerBinding(L);
    TradeCultureBinding::registerBinding(L);
    UniqueSpawnDataBinding::registerBinding(L);
    handBinding::registerBinding(L);
    StringPairBinding::registerBinding(L);
    TimeOfDayBinding::registerBinding(L);
    YesNoMaybeBinding::registerBinding(L);
    iVector2Binding::registerBinding(L);
    VisibleObjectInfoBinding::registerBinding(L);
    WeaponBinding::registerBinding(L);
    WhoSeesMeBinding::registerBinding(L);
    WorldEventStateQueryBinding::registerBinding(L);
    WorldEventStateQueryListBinding::registerBinding(L);
    ZoneManagerBinding::registerBinding(L);
    ZoneManagerInterfaceTBinding::registerBinding(L);
    ZoneMapBinding::registerBinding(L);
    ZoneSpacialGridBinding::registerBinding(L);
    physHitBinding::registerBinding(L);

}
} // namespace KenshiLua
