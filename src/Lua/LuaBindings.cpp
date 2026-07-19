#include "pch.h"
#include "Lua/LuaBindings.h"
#include "Lua/LuaState.h"
#include "Lua/BindingHelpers.h"
#include "Benchmark.h"
#include "DialogueScriptBridge.h"
#include "EventSystem.h"
#include "Gui/GuiManager.h"
#include "Logger.h"
#include "ScriptLoader.h"
#include "Bindings/Templates/StdMapBinding.h"
#include "Bindings/FitnessSelectorBinding.h"
#include "Bindings/Templates/LektorBinding.h"
#include "Bindings/Templates/OgreUnorderedBinding.h"
#include <kenshi/CombatTechniqueData.h>
#include <kenshi/GameData.h>
#include <kenshi/Item.h>
#include <kenshi/Inventory.h>
#include "Bindings/AbstractMovementBaseBinding.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/AnimalInventoryLayoutBinding.h"
#include "Bindings/ArmourBinding.h"
#include "Bindings/BountyBinding.h"
#include "Bindings/BountyManagerBinding.h"
#include "Bindings/Building/BuildInventoryLayoutBinding.h"
#include "Bindings/Building/BuildMaterialBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/Building/BuildingContainerInventoryLayoutBinding.h"
#include "Bindings/Building/BuildingPlacementGroundTypeBinding.h"
#include "Bindings/Building/ConsumptionItemBinding.h"
#include "Bindings/Building/ConstructionStateBinding.h"
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
#include "Bindings/GameplayOptionsBinding.h"
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
#include "Bindings/CharBodyBinding.h"
#include "Bindings/CharacterAnimalBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/CharMovementBinding.h"
#include "Bindings/CharStatsBinding.h"
#include "Bindings/CombatMovementControllerBinding.h"
#include "Bindings/CombatTechniqueDataBinding.h"
#include "Bindings/ContainerItemBinding.h"
#include "Bindings/CrossbowBinding.h"
#include "Bindings/DamagesBinding.h"
#include "Bindings/DialogActionBinding.h"
#include "Bindings/DialogChoiceListBinding.h"
#include "Bindings/DialogConditionBinding.h"
#include "Bindings/DialogLineDataBinding.h"
#include "Bindings/DialogueBinding.h"
#include "Bindings/DialogStateBinding.h"
#include "Bindings/EnumBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/FactionLeaderBinding.h"
#include "Bindings/FactionManagerBinding.h"
#include "Bindings/FactionRelationsBinding.h"
#include "Bindings/FlockingToolsBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataReferenceBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/GameWorldBinding.h"
#include "Bindings/GearBinding.h"
#include "Bindings/RobotLimbItemBinding.h"
#include "Bindings/RootObjectBinding.h"
#include <kenshi/RootObject.h>
#include "Bindings/GlobalBinding.h"
#include "Bindings/OptionsHolderBinding.h"
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
#include "Bindings/Gui/GUIWindowBinding.h"
#include "Bindings/HealthPartStatusBinding.h"
#include "Bindings/ImpactPointBinding.h"
#include "Bindings/InputHandlerBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/InventoryItemBaseBinding.h"
#include "Bindings/InventorySectionBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/LockedArmourBinding.h"
#include "Bindings/MedianFilter2DVectorBinding.h"
#include "Bindings/MedicalSystemBinding.h"
#include "Bindings/ModInfoBinding.h"
#include "Bindings/MyGuiBinding.h"
#include "Bindings/ObjectInstanceBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/PlayerInterfaceBinding.h"
#include "Bindings/RaceDataBinding.h"
#include "Bindings/RelationDataBinding.h"
#include "Bindings/RootObjectBaseBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/RootObjectFactoryBinding.h"
#include "Bindings/SectionItemBinding.h"
#include "Bindings/ShopTraderBinding.h"
#include "Bindings/ShopTraderInventoryBinding.h"
#include "Bindings/ShopTraderInventorySectionBinding.h"
#include "Bindings/SpeedGroupBinding.h"
#include "Bindings/SwordBinding.h"
#include "Bindings/TaskerBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/TownBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/StringPairBinding.h"
#include "Bindings/Util/TimeOfDayBinding.h"
#include "Bindings/Util/YesNoMaybeBinding.h"
#include "Bindings/Util/iVector2Binding.h"
#include "Bindings/WeaponBinding.h"
#include "Bindings/AABB2DBinding.h"
#include "Bindings/BackThreadMessagesToMainTBinding.h"
#include "Bindings/Gui/BackpackInventoryLayoutBinding.h"
#include "Bindings/Gui/BuildModeWindowBinding.h"
#include "Bindings/Gui/BuildingCategoryBinding.h"
#include "Bindings/Gui/BuildingGroupBinding.h"
#include "Bindings/Gui/CharacterStatsWindowBinding.h"
#include "Bindings/Gui/CharacterTradingWindowBinding.h"
#include "Bindings/Gui/FactionRelationsLineBinding.h"
#include "Bindings/Gui/FactionsScreenBinding.h"
#include "Bindings/Gui/ForgottenGUIBinding.h"
#include "Bindings/Gui/GameDataEditorWindowBinding.h"
#include "Bindings/Gui/GenericFixedInventoryLayoutBinding.h"
#include "Bindings/Gui/InventoryGUIBinding.h"
#include "Bindings/Gui/InventoryIconBinding.h"
#include "Bindings/Gui/InventoryLayoutBinding.h"
#include "Bindings/Gui/InventorySectionGUIBinding.h"
#include "Bindings/Gui/InventoryTradeDataBinding.h"
#include "Bindings/Gui/MainBarGUIBinding.h"
#include "Bindings/Gui/MainTabPortraitPlatoonBinding.h"
#include "Bindings/Gui/OpenSaveFileDialogBinding.h"
#include "Bindings/Gui/OptionsWindowBinding.h"
#include "Bindings/Gui/OrderCellViewBinding.h"
#include "Bindings/Gui/OrderDataBinding.h"
#include "Bindings/Gui/OrdersItemBoxBinding.h"
#include "Bindings/Gui/OrdersPanelBinding.h"
#include "Bindings/Gui/StatBinding.h"
#include "Bindings/Gui/StatGroupBinding.h"
#include "Bindings/Gui/ToolTipBinding.h"
#include "Bindings/Gui/ToolTipDynamicBinding.h"
#include "Bindings/Gui/ToolTipFixedBinding.h"
#include "Bindings/Gui/ToolTipInventoryBinding.h"
#include "Bindings/Gui/ToolTipLineBinding.h"
#include "Bindings/Gui/ToolTipStaticBinding.h"
#include "Bindings/Gui/TradeResultBinding.h"
#include "Bindings/Gui/TransformWindowBinding.h"
#include "Bindings/Gui/TutorialGUIBinding.h"
#include "Bindings/Gui/TutorialGUILineBinding.h"
#include "Bindings/Gui/TutorialItemBinding.h"
#include "Bindings/Gui/TutorialSubItemBinding.h"
#include "Bindings/Gui/TutorialpediaGUIBinding.h"
#include "Bindings/MainthreadStateReaderTBinding.h"
#include "Bindings/ParticlePoolBinding.h"
#include "Bindings/StateTBinding.h"
#include "Bindings/TradeCultureBinding.h"
#include "Bindings/ZoneManagerBinding.h"
#include "Bindings/ZoneManagerInterfaceTBinding.h"
#include "Bindings/ZoneMapBinding.h"
#include "Bindings/ZoneSpacialGridBinding.h"
#include "Bindings/AttackSlotManagerBinding.h"
#include "Bindings/CombatClassBinding.h"
#include "Bindings/FactionUniqueSquadManagerBinding.h"
#include "Bindings/GlobalConstantsBinding.h"
#include "Bindings/InstanceIDBinding.h"
#include "Bindings/MeshLoadDataBinding.h"
#include "Bindings/ProsperityManagerBinding.h"
#include "Bindings/ResourceLoadRequestMeshBinding.h"
#include "Bindings/ResourceLoadRequestTextureBinding.h"
#include "Bindings/ResourceLoaderBinding.h"
#include "Bindings/SaveFileSystemBinding.h"
#include "Bindings/SaveManagerBinding.h"
#include "Bindings/TextureArrayLoadDataBinding.h"
#include "Bindings/TextureLoadDataBinding.h"
#include "Bindings/UniqueSpawnDataBinding.h"

#include <string>
#include <cstdio>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

static int lua_reloadMods(lua_State* L)
{
    ScriptLoader::get().reloadAll(L);
    lua_pushinteger(L, (lua_Integer)ScriptLoader::get().scripts().size());
    return 1;
}

static int lua_toggleGui(lua_State* L)
{
    GuiManager::get().toggle();
    return 0;
}

static void installKenshiLuaTable(lua_State* L)
{
    // KenshiLua.* namespace for management helpers.
    lua_getglobal(L, "KenshiLua");
    if (!lua_istable(L, -1)) {
        lua_pop(L, 1);
        lua_newtable(L);
    }

    lua_pushcfunction(L, lua_reloadMods);
    lua_setfield(L, -2, "reloadMods");

    lua_pushcfunction(L, lua_toggleGui);
    lua_setfield(L, -2, "toggleGui");

    // Aliases for the existing global event-handler functions.
    lua_pushcfunction(L, luaRegisterHandler);
    lua_setfield(L, -2, "registerHandler");

    lua_pushcfunction(L, luaUnregisterHandler);
    lua_setfield(L, -2, "unregisterHandler");

    // Version check helper.
    lua_pushcfunction(L, luaKenshiVersion);
    lua_setfield(L, -2, "version");

    lua_pushcfunction(L, luaKenshiRunBenchmark);
    lua_setfield(L, -2, "runBenchmark");

    lua_pushcfunction(L, luaCheckLuaScriptReferences);
    lua_setfield(L, -2, "checkLuaScriptReferences");

    lua_pushcfunction(L, luaKenshiLog);
    lua_setfield(L, -2, "log");

    lua_pushcfunction(L, luaKenshiLogDebug);
    lua_setfield(L, -2, "logDebug");

    lua_pushcfunction(L, luaKenshiLogWarn);
    lua_setfield(L, -2, "warn");
    lua_pushcfunction(L, luaKenshiLogWarn);
    lua_setfield(L, -2, "logWarn");

    lua_pushcfunction(L, luaKenshiLogError);
    lua_setfield(L, -2, "logError");

    lua_pushcfunction(L, luaKenshiError);
    lua_setfield(L, -2, "error");

    lua_setglobal(L, "KenshiLua");
}

static const luaL_Reg KenshiLuaLib[] = {
    // Add global functions here, e.g.:
    // { "myGlobalFunc", luaMyGlobalFunc },
    { NULL, NULL }
};

void LuaBindings::registerAll(lua_State* L)
{
    for (const luaL_Reg* lib = KenshiLuaLib; lib->name; lib++) {
        lua_pushcfunction(L, lib->func);
        lua_setglobal(L, lib->name);
    }

    // Order: try to register dependency-free metatables first; ones that reference others afterwards when possible
    RootObjectBaseBinding::registerBinding(L);
    RootObjectBinding::registerBinding(L);
    RootObjectFactoryBinding::registerBinding(L);
    RaceDataBinding::registerBinding(L);
    BountyBinding::registerBinding(L);
    BountyManagerBinding::registerBinding(L);
    CameraClassBinding::registerBinding(L);

    handBinding::registerBinding(L);
    PlatoonBinding::registerBinding(L);
    FactionBinding::registerBinding(L);
    InventoryItemBaseBinding::registerBinding(L);
    ItemBinding::registerBinding(L);
    RobotLimbItemBinding::registerBinding(L);
    GearBinding::registerBinding(L);
    WeaponBinding::registerBinding(L);
    SwordBinding::registerBinding(L);
    ArmourBinding::registerBinding(L);
    LockedArmourBinding::registerBinding(L);
    CrossbowBinding::registerBinding(L);
    FootprintBinding::registerBinding(L);
    FootprintNodeBinding::registerBinding(L);
    ConstructionStateBinding::registerBinding(L);
    BuildingPlacementGroundTypeBinding::registerBinding(L);
    BuildMaterialBinding::registerBinding(L);
    BuildingBinding::registerBinding(L);
    PreviewBuildingBinding::registerBinding(L);
    TownBaseBinding::registerBinding(L);
    TownBinding::registerBinding(L);
    MedicalSystemBinding::registerBinding(L);
    CharStatsBinding::registerBinding(L);
    
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

    CombatTechniqueDataBinding::registerBinding(L);
    ImpactPointBinding::registerBinding(L);
    DamagesBinding::registerBinding(L);
    InventoryBinding::registerBinding(L);
    InventorySectionBinding::registerBinding(L);
    SectionItemBinding::registerBinding(L);
    CharacterBinding::registerBinding(L);
    DialogueBinding::registerBinding(L);
    PlayerInterfaceBinding::registerBinding(L);
    InputHandlerBinding::registerBinding(L);
    GameWorldBinding::registerBinding(L);
    GameDataBinding::registerBinding(L);
    GameDataReferenceBinding::registerBinding(L);
    GameSaveStateBinding::registerBinding(L);
    MyGuiBinding::registerBinding(L);
    FactionRelationsBinding::registerBinding(L);
    RelationDataBinding::registerBinding(L);
    FactionLeaderBinding::registerBinding(L);
    DialogueWindowBinding::registerBinding(L);
    GUIWindowBinding::registerBinding(L);
    DatapanelGUIBinding::registerBinding(L);
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

    DoorStuffBinding::registerBinding(L);
    FarmBatchBinding::registerBinding(L);
    FarmBuildingBinding::registerBinding(L);
    FurnaceBuildingBinding::registerBinding(L);
    FurnaceInventoryLayoutBinding::registerBinding(L);
    GameplayOptionsBinding::registerBinding(L);
    GatewayBuildingBinding::registerBinding(L);
    LightBuildingBinding::registerBinding(L);
    RainCollectorBuildingBinding::registerBinding(L);
    TortureBuildingBinding::registerBinding(L);
    TradeCultureBinding::registerBinding(L);
    TurretBuildingBinding::registerBinding(L);
    WallBuildingBinding::registerBinding(L);

    UseableStuffBinding::registerBinding(L);
    StorageBuildingBinding::registerBinding(L);
    ProductionBuildingBinding::registerBinding(L);
    CraftingBuildingBinding::registerBinding(L);
    GeneratorBuildingBinding::registerBinding(L);
    WindGeneratorBuildingBinding::registerBinding(L);

    AABB2DBinding::registerBinding(L);
    BackThreadMessagesToMainTBinding::registerBinding(L);
    BackpackInventoryLayoutBinding::registerBinding(L);
    BuildModeWindowBinding::registerBinding(L);
    BuildingCategoryBinding::registerBinding(L);
    BuildingGroupBinding::registerBinding(L);
    CharacterStatsWindowBinding::registerBinding(L);
    CharacterTradingWindowBinding::registerBinding(L);
    FactionRelationsLineBinding::registerBinding(L);
    FactionsScreenBinding::registerBinding(L);
    ForgottenGUIBinding::registerBinding(L);
    GameDataEditorWindowBinding::registerBinding(L);
    GenericFixedInventoryLayoutBinding::registerBinding(L);
    InventoryGUIBinding::registerBinding(L);
    InventoryIconBinding::registerBinding(L);
    InventoryLayoutBinding::registerBinding(L);
    InventorySectionGUIBinding::registerBinding(L);
    InventoryTradeDataBinding::registerBinding(L);
    MainBarGUIBinding::registerBinding(L);
    MainTabPortraitPlatoonBinding::registerBinding(L);
    MainthreadStateReaderTBinding::registerBinding(L);
    OpenSaveFileDialogBinding::registerBinding(L);
    OptionsWindowBinding::registerBinding(L);
    OrderCellViewBinding::registerBinding(L);
    OrderDataBinding::registerBinding(L);
    OrdersItemBoxBinding::registerBinding(L);
    OrdersPanelBinding::registerBinding(L);
    ParticlePoolBinding::registerBinding(L);
    StatBinding::registerBinding(L);
    StatGroupBinding::registerBinding(L);
    StateTBinding::registerBinding(L);
    ToolTipBinding::registerBinding(L);
    ToolTipDynamicBinding::registerBinding(L);
    ToolTipFixedBinding::registerBinding(L);
    ToolTipInventoryBinding::registerBinding(L);
    ToolTipLineBinding::registerBinding(L);
    ToolTipStaticBinding::registerBinding(L);
    TradeResultBinding::registerBinding(L);
    TransformWindowBinding::registerBinding(L);
    TutorialGUIBinding::registerBinding(L);
    TutorialGUILineBinding::registerBinding(L);
    TutorialItemBinding::registerBinding(L);
    TutorialSubItemBinding::registerBinding(L);
    TutorialpediaGUIBinding::registerBinding(L);
    ZoneManagerBinding::registerBinding(L);
    ZoneManagerInterfaceTBinding::registerBinding(L);
    ZoneMapBinding::registerBinding(L);
    ZoneSpacialGridBinding::registerBinding(L);
    ResearchBuildingBinding::registerBinding(L);
    ResearchBuildingInventoryLayoutBinding::registerBinding(L);
    GenericInventoryLayoutBinding::registerBinding(L);
    BuildingContainerInventoryLayoutBinding::registerBinding(L);
    BuildInventoryLayoutBinding::registerBinding(L);
    ProductionInventoryLayoutBinding::registerBinding(L);
    CraftingInventoryLayoutBinding::registerBinding(L);
    GameDataGroupBinding::registerBinding(L);
    ConsumptionItemBinding::registerBinding(L);

    ShopTraderBinding::registerBinding(L);
    AnimalInventoryLayoutBinding::registerBinding(L);
    CharacterAnimalBinding::registerBinding(L);

    AbstractMovementBaseBinding::registerBinding(L);
    CharMovementBinding::registerBinding(L);
    ActivePlatoonBinding::registerBinding(L);
    CharBodyBinding::registerBinding(L);
    CombatMovementControllerBinding::registerBinding(L);
    ContainerItemBinding::registerBinding(L);
    DialogChoiceListBinding::registerBinding(L);
    DialogConditionBinding::registerBinding(L);
    DialogActionBinding::registerBinding(L);
    DialogLineDataBinding::registerBinding(L);
    DialogStateBinding::registerBinding(L);
    FactionManagerBinding::registerBinding(L);
    FlockingToolsBinding::registerBinding(L);
    MedianFilter2DVectorBinding::registerBinding(L);
    ObjectInstanceBinding::registerBinding(L);
    SpeedGroupBinding::registerBinding(L);
    TaskerBinding::registerBinding(L);
    HealthPartStatusBinding::registerBinding(L);
    ModInfoBinding::registerBinding(L);
    OptionsHolderBinding::registerBinding(L);
    StringPairBinding::registerBinding(L);
    TimeOfDayBinding::registerBinding(L);
    YesNoMaybeBinding::registerBinding(L);
    iVector2Binding::registerBinding(L);

    AttackSlotManagerBinding::registerBinding(L);
    CombatClassBinding::registerBinding(L);
    FactionUniqueSquadManagerBinding::registerBinding(L);
    GlobalConstantsBinding::registerBinding(L);
    InstanceIDBinding::registerBinding(L);
    MeshLoadDataBinding::registerBinding(L);
    ProsperityManagerBinding::registerBinding(L);
    ResourceLoadRequestMeshBinding::registerBinding(L);
    ResourceLoadRequestTextureBinding::registerBinding(L);
    ResourceLoaderBinding::registerBinding(L);
    SaveFileSystemBinding::registerBinding(L);
    SaveManagerBinding::registerBinding(L);
    TextureArrayLoadDataBinding::registerBinding(L);
    TextureLoadDataBinding::registerBinding(L);
    UniqueSpawnDataBinding::registerBinding(L);

	registerEnumBindings(L);
    registerGlobals(L);

    // Configure class metatable inheritance chains
    setMetatableParent(L, CharacterAnimalBinding::getMetatableName(), CharacterBinding::getMetatableName());
    setMetatableParent(L, CharacterBinding::getMetatableName(), RootObjectBinding::getMetatableName());
    setMetatableParent(L, RootObjectBinding::getMetatableName(), RootObjectBaseBinding::getMetatableName());

    setMetatableParent(L, PlatoonBinding::getMetatableName(), RootObjectBaseBinding::getMetatableName());
    setMetatableParent(L, ActivePlatoonBinding::getMetatableName(), PlatoonBinding::getMetatableName());
    setMetatableParent(L, CharMovementBinding::getMetatableName(), AbstractMovementBaseBinding::getMetatableName());

    setMetatableParent(L, TownBinding::getMetatableName(), TownBaseBinding::getMetatableName());
    setMetatableParent(L, TownBaseBinding::getMetatableName(), RootObjectBinding::getMetatableName());

    setMetatableParent(L, ItemBinding::getMetatableName(), InventoryItemBaseBinding::getMetatableName());
    setMetatableParent(L, InventoryItemBaseBinding::getMetatableName(), RootObjectBinding::getMetatableName());
    setMetatableParent(L, GearBinding::getMetatableName(), ItemBinding::getMetatableName());
    setMetatableParent(L, WeaponBinding::getMetatableName(), GearBinding::getMetatableName());
    setMetatableParent(L, SwordBinding::getMetatableName(), WeaponBinding::getMetatableName());
    setMetatableParent(L, CrossbowBinding::getMetatableName(), WeaponBinding::getMetatableName());
    setMetatableParent(L, ArmourBinding::getMetatableName(), GearBinding::getMetatableName());
    setMetatableParent(L, LockedArmourBinding::getMetatableName(), ArmourBinding::getMetatableName());

    // GUI and Dialog chains
    setMetatableParent(L, DialogueWindowBinding::getMetatableName(), GUIWindowBinding::getMetatableName());
    setMetatableParent(L, DatapanelGUIBinding::getMetatableName(), GUIWindowBinding::getMetatableName());
    setMetatableParent(L, OptionsWindowBinding::getMetatableName(), GUIWindowBinding::getMetatableName());
    setMetatableParent(L, InventoryGUIBinding::getMetatableName(), GUIWindowBinding::getMetatableName());
    setMetatableParent(L, MainBarGUIBinding::getMetatableName(), GUIWindowBinding::getMetatableName());
    setMetatableParent(L, BuildModeWindowBinding::getMetatableName(), GUIWindowBinding::getMetatableName());
    setMetatableParent(L, CharacterStatsWindowBinding::getMetatableName(), GUIWindowBinding::getMetatableName());
    setMetatableParent(L, CharacterTradingWindowBinding::getMetatableName(), GUIWindowBinding::getMetatableName());
    setMetatableParent(L, TutorialGUIBinding::getMetatableName(), GUIWindowBinding::getMetatableName());
    setMetatableParent(L, TutorialpediaGUIBinding::getMetatableName(), GUIWindowBinding::getMetatableName());

    // ToolTip chains
    setMetatableParent(L, ToolTipDynamicBinding::getMetatableName(), ToolTipBinding::getMetatableName());
    setMetatableParent(L, ToolTipFixedBinding::getMetatableName(), ToolTipBinding::getMetatableName());
    setMetatableParent(L, ToolTipInventoryBinding::getMetatableName(), ToolTipBinding::getMetatableName());
    setMetatableParent(L, ToolTipStaticBinding::getMetatableName(), ToolTipBinding::getMetatableName());
    
    // DataPanelLine chains
    setMetatableParent(L, DataPanelLine_FactionBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_ResearchBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_ButtonBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_SliderEditableBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_TextBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_TextEditableBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_SliderBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_ProgressBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_CheckBoxBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_DropBoxBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());
    setMetatableParent(L, DataPanelLine_KeyConfigBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());

    // Building chains
    setMetatableParent(L, BuildingBinding::getMetatableName(), RootObjectBinding::getMetatableName());
    setMetatableParent(L, UseableStuffBinding::getMetatableName(), BuildingBinding::getMetatableName());
    setMetatableParent(L, StorageBuildingBinding::getMetatableName(), UseableStuffBinding::getMetatableName());
    setMetatableParent(L, ProductionBuildingBinding::getMetatableName(), StorageBuildingBinding::getMetatableName());
    setMetatableParent(L, CraftingBuildingBinding::getMetatableName(), ProductionBuildingBinding::getMetatableName());
    setMetatableParent(L, GeneratorBuildingBinding::getMetatableName(), ProductionBuildingBinding::getMetatableName());
    setMetatableParent(L, WindGeneratorBuildingBinding::getMetatableName(), GeneratorBuildingBinding::getMetatableName());
    setMetatableParent(L, ResearchBuildingBinding::getMetatableName(), UseableStuffBinding::getMetatableName());
    setMetatableParent(L, DoorStuffBinding::getMetatableName(), BuildingBinding::getMetatableName());
    setMetatableParent(L, GatewayBuildingBinding::getMetatableName(), BuildingBinding::getMetatableName());
    setMetatableParent(L, WallBuildingBinding::getMetatableName(), BuildingBinding::getMetatableName());
    setMetatableParent(L, FootprintNodeBinding::getMetatableName(), FootprintBinding::getMetatableName());
    setMetatableParent(L, FarmBuildingBinding::getMetatableName(), ProductionBuildingBinding::getMetatableName());
    setMetatableParent(L, FurnaceBuildingBinding::getMetatableName(), ProductionBuildingBinding::getMetatableName());
    setMetatableParent(L, RainCollectorBuildingBinding::getMetatableName(), ProductionBuildingBinding::getMetatableName());
    setMetatableParent(L, TortureBuildingBinding::getMetatableName(), ProductionBuildingBinding::getMetatableName());
    setMetatableParent(L, LightBuildingBinding::getMetatableName(), UseableStuffBinding::getMetatableName());
    setMetatableParent(L, TurretBuildingBinding::getMetatableName(), UseableStuffBinding::getMetatableName());
    
    // Layout chains
    setMetatableParent(L, BuildingContainerInventoryLayoutBinding::getMetatableName(), GenericInventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, ProductionInventoryLayoutBinding::getMetatableName(), BuildInventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, CraftingInventoryLayoutBinding::getMetatableName(), BuildInventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, ResearchBuildingInventoryLayoutBinding::getMetatableName(), GenericInventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, FurnaceInventoryLayoutBinding::getMetatableName(), BuildInventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, BackpackInventoryLayoutBinding::getMetatableName(), GenericFixedInventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, GenericFixedInventoryLayoutBinding::getMetatableName(), InventoryLayoutBinding::getMetatableName());

    // Inventory chains
    setMetatableParent(L, "KenshiLua.ShopTraderInventoryLayout", GenericInventoryLayoutBinding::getMetatableName());
    setMetatableParent(L, ShopTraderInventoryBinding::getMetatableName(), InventoryBinding::getMetatableName());
    setMetatableParent(L, ShopTraderInventorySectionBinding::getMetatableName(), InventorySectionBinding::getMetatableName());

    // Other chains
    setMetatableParent(L, ShopTraderBinding::getMetatableName(), RootObjectBinding::getMetatableName());
    setMetatableParent(L, ZoneManagerBinding::getMetatableName(), ZoneManagerInterfaceTBinding::getMetatableName());
    setMetatableParent(L, TextureArrayLoadDataBinding::getMetatableName(), TextureLoadDataBinding::getMetatableName());

    installKenshiLuaTable(L);
}

static std::string formatLuaArgs(lua_State* L)
{
    int n = lua_gettop(L);
    std::string msg;
    for (int i = 1; i <= n; i++) {
        if (i > 1) msg += " ";
        switch (lua_type(L, i)) {
        case LUA_TSTRING: msg += lua_tostring(L, i); break;
        case LUA_TNUMBER:
            if (lua_isinteger(L, i)) {
                char buf[32]; _snprintf(buf, sizeof(buf), "%lld", (long long)lua_tointeger(L, i));
                msg += buf;
            } else {
                char buf[64]; _snprintf(buf, sizeof(buf), "%.14g", lua_tonumber(L, i));
                msg += buf;
            }
            break;
        case LUA_TBOOLEAN: msg += lua_toboolean(L, i) ? "true" : "false"; break;
        case LUA_TNIL: msg += "nil"; break;
        default:
            char buf[64]; _snprintf(buf, sizeof(buf), "%s:%p", lua_typename(L, lua_type(L, i)), lua_topointer(L, i));
            msg += buf;
            break;
        }
    }
    return msg;
}

int luaKenshiLog(lua_State* L)
{
    logToFile(formatLuaArgs(L));
    return 0;
}

int luaKenshiLogDebug(lua_State* L)
{
    logToFileDebug(formatLuaArgs(L));
    return 0;
}

int luaKenshiLogWarn(lua_State* L)
{
    logToFile(LogLevel_Warn, formatLuaArgs(L));
    return 0;
}

int luaKenshiLogError(lua_State* L)
{
    logToFile(LogLevel_Error, formatLuaArgs(L));
    return 0;
}

int luaKenshiError(lua_State* L)
{
    int n = lua_gettop(L);
    std::string msg = "Lua Error: ";
    for (int i = 1; i <= n; i++) {
        if (i > 1) msg += " ";
        switch (lua_type(L, i)) {
        case LUA_TSTRING: msg += lua_tostring(L, i); break;
        default:
            {
                char buf[64]; _snprintf(buf, sizeof(buf), "%s:%p", lua_typename(L, lua_type(L, i)), lua_topointer(L, i));
                msg += buf;
            }
            break;
        }
    }
    logToFile(LogLevel_Error, msg);
    lua_settop(L, 0);
    lua_pushlstring(L, msg.c_str(), msg.size());
    return lua_error(L);
}

int luaKenshiVersion(lua_State* L) { lua_pushstring(L, "KenshiLua 0.2.1"); return 1; }

} // namespace KenshiLua
