#include "pch.h"
#include "Lua/LuaBindings.h"
#include "Lua/LuaState.h"
#include "Lua/BindingHelpers.h"
#include "Benchmark.h"
#include "DialogueScriptBridge.h"
#include "EventSystem.h"
#include "Gui.h"
#include "Logger.h"
#include "ScriptLoader.h"

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
#include "Bindings/Building/TradeCultureBinding.h"
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
#include "Bindings/GameWorldBinding.h"
#include "Bindings/GearBinding.h"
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
    ScriptEditor::get().toggle();
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

	registerEnumBindings(L);
    registerGlobals(L);

    // Configure class metatable inheritance chains
    setMetatableParent(L, "KenshiLua.CharacterAnimal", "KenshiLua.Character");
    setMetatableParent(L, "KenshiLua.Character", "KenshiLua.RootObject");
    setMetatableParent(L, "KenshiLua.RootObject", "KenshiLua.RootObjectBase");

    setMetatableParent(L, "KenshiLua.Platoon", "KenshiLua.RootObjectBase");
    setMetatableParent(L, "KenshiLua.ActivePlatoon", "KenshiLua.Platoon");
    setMetatableParent(L, "KenshiLua.CharMovement", "KenshiLua.AbstractMovementBase");

    setMetatableParent(L, "KenshiLua.Town", "KenshiLua.TownBase");
    setMetatableParent(L, "KenshiLua.TownBase", "KenshiLua.RootObject");

    setMetatableParent(L, "KenshiLua.Item", "KenshiLua.InventoryItemBase");
    setMetatableParent(L, "KenshiLua.InventoryItemBase", "KenshiLua.RootObject");
    setMetatableParent(L, "KenshiLua.Gear", "KenshiLua.Item");
    setMetatableParent(L, "KenshiLua.Weapon", "KenshiLua.Gear");
    setMetatableParent(L, "KenshiLua.Sword", "KenshiLua.Weapon");
    setMetatableParent(L, "KenshiLua.Crossbow", "KenshiLua.Weapon");
    setMetatableParent(L, "KenshiLua.Armour", "KenshiLua.Gear");
    setMetatableParent(L, "KenshiLua.LockedArmour", "KenshiLua.Armour");

    // GUI and Dialog chains
    setMetatableParent(L, "KenshiLua.DialogueWindow", "KenshiLua.GUIWindow");
    setMetatableParent(L, "KenshiLua.DatapanelGUI", "KenshiLua.GUIWindow");
    
    // DataPanelLine chains
    setMetatableParent(L, "KenshiLua.DataPanelLine_Faction", "KenshiLua.DataPanelLine");
    setMetatableParent(L, "KenshiLua.DataPanelLine_Research", "KenshiLua.DataPanelLine");
    setMetatableParent(L, "KenshiLua.DataPanelLine_Button", "KenshiLua.DataPanelLine");
    setMetatableParent(L, "KenshiLua.DataPanelLine_SliderEditable", "KenshiLua.DataPanelLine");
    setMetatableParent(L, "KenshiLua.DataPanelLine_Text", "KenshiLua.DataPanelLine");
    setMetatableParent(L, "KenshiLua.DataPanelLine_TextEditable", "KenshiLua.DataPanelLine");
    setMetatableParent(L, "KenshiLua.DataPanelLine_Slider", "KenshiLua.DataPanelLine");
    setMetatableParent(L, "KenshiLua.DataPanelLine_Progress", "KenshiLua.DataPanelLine");
    setMetatableParent(L, "KenshiLua.DataPanelLine_CheckBox", "KenshiLua.DataPanelLine");
    setMetatableParent(L, "KenshiLua.DataPanelLine_DropBox", "KenshiLua.DataPanelLine");
    setMetatableParent(L, "KenshiLua.DataPanelLine_KeyConfig", "KenshiLua.DataPanelLine");

    // Building chains
    setMetatableParent(L, "KenshiLua.UseableStuff", "KenshiLua.Building");
    setMetatableParent(L, "KenshiLua.StorageBuilding", "KenshiLua.UseableStuff");
    setMetatableParent(L, "KenshiLua.ProductionBuilding", "KenshiLua.StorageBuilding");
    setMetatableParent(L, "KenshiLua.CraftingBuilding", "KenshiLua.ProductionBuilding");
    setMetatableParent(L, "KenshiLua.GeneratorBuilding", "KenshiLua.ProductionBuilding");
    setMetatableParent(L, "KenshiLua.WindGeneratorBuilding", "KenshiLua.GeneratorBuilding");
    setMetatableParent(L, "KenshiLua.ResearchBuilding", "KenshiLua.UseableStuff");
    
    // Layout chains
    setMetatableParent(L, "KenshiLua.BuildingContainerInventoryLayout", "KenshiLua.GenericInventoryLayout");
    setMetatableParent(L, "KenshiLua.ProductionInventoryLayout", "KenshiLua.BuildInventoryLayout");
    setMetatableParent(L, "KenshiLua.CraftingInventoryLayout", "KenshiLua.BuildInventoryLayout");
    setMetatableParent(L, "KenshiLua.ResearchBuildingInventoryLayout", "KenshiLua.GenericInventoryLayout");

    // Inventory chains
    setMetatableParent(L, "KenshiLua.ShopTraderInventoryLayout", "KenshiLua.GenericInventoryLayout");

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
    logToFile(msg);
    lua_settop(L, 0);
    lua_pushlstring(L, msg.c_str(), msg.size());
    return lua_error(L);
}

int luaKenshiVersion(lua_State* L) { lua_pushstring(L, "KenshiLua 0.2.0"); return 1; }

} // namespace KenshiLua
