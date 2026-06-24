#include "pch.h"
#include "Lua/LuaBindings.h"
#include "Lua/LuaUtils.h"
#include "Lua/LuaState.h"
#include "Lua/Logger.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/HandBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/DialogueBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/TownBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/GearBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/Building/BuildMaterialBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/Building/BuildingPlacementGroundTypeBinding.h"
#include "Bindings/Building/ConstructionStateBinding.h"
#include "Bindings/Building/FootprintBinding.h"
#include "Bindings/Building/FootprintNodeBinding.h"
#include "Bindings/Building/PreviewBuildingBinding.h"
#include "Bindings/GameWorldBinding.h"
#include "Bindings/PlayerInterfaceBinding.h"
#include "Bindings/GlobalBinding.h"
#include "Bindings/CharStatsBinding.h"
#include "Bindings/DamagesBinding.h"
#include "Bindings/MedicalSystemBinding.h"
#include "Bindings/InputHandlerBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/EnumBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/RaceDataBinding.h"
#include "Bindings/BountyBinding.h"
#include "Bindings/BountyManagerBinding.h"
#include "Bindings/CameraClassBinding.h"
#include "Bindings/MyGuiBinding.h"
#include "Bindings/CharacterAnimalBinding.h"
#include "Bindings/InventoryItemBaseBinding.h"
#include "Bindings/WeaponBinding.h"
#include "Bindings/SwordBinding.h"
#include "Bindings/ArmourBinding.h"
#include "Bindings/LockedArmourBinding.h"
#include "Bindings/CrossbowBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/InventorySectionBinding.h"
#include "Bindings/SectionItemBinding.h"
#include "Bindings/AnimalInventoryLayoutBinding.h"
//#include "Bindings/ShopTraderBinding.h"
#include "Lua/Benchmark.h"
#include <string>
#include <cstdio>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

static const luaL_Reg KenshiLuaLib[] = {
    { "log", luaKenshiLog },
    { "error", luaKenshiError },
    { "version", luaKenshiVersion },
    { "runBenchmark", luaKenshiRunBenchmark },
    { NULL, NULL }
};

void LuaBindings::registerAll(lua_State* L)
{
    for (const luaL_Reg* lib = KenshiLuaLib; lib->name; lib++) {
        lua_pushcfunction(L, lib->func);
        lua_setglobal(L, lib->name);
    }

    // Order: dependency-free metatables first; ones that reference others afterwards when possible
    RootObjectBinding::registerBinding(L);
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
    //ShopTraderBinding::registerBinding(L);
    AnimalInventoryLayoutBinding::registerBinding(L);
    CharacterAnimalBinding::registerBinding(L);

	registerEnumBindings(L);
    registerGlobals(L);

    // Configure class metatable inheritance chains
    setPlayableParent(L, "KenshiLua.CharacterAnimal", "KenshiLua.Character");
    setPlayableParent(L, "KenshiLua.Character", "KenshiLua.RootObject");
    setPlayableParent(L, "KenshiLua.RootObject", "KenshiLua.RootObjectBase");

    setPlayableParent(L, "KenshiLua.Platoon", "KenshiLua.RootObjectBase");
    setPlayableParent(L, "KenshiLua.Town", "KenshiLua.TownBase");
    setPlayableParent(L, "KenshiLua.TownBase", "KenshiLua.RootObject");

    setPlayableParent(L, "KenshiLua.Item", "KenshiLua.InventoryItemBase");
    setPlayableParent(L, "KenshiLua.InventoryItemBase", "KenshiLua.RootObject");
    setPlayableParent(L, "KenshiLua.Gear", "KenshiLua.Item");
    setPlayableParent(L, "KenshiLua.Weapon", "KenshiLua.Gear");
    setPlayableParent(L, "KenshiLua.Sword", "KenshiLua.Weapon");
    setPlayableParent(L, "KenshiLua.Crossbow", "KenshiLua.Weapon");
    setPlayableParent(L, "KenshiLua.Armour", "KenshiLua.Gear");
    setPlayableParent(L, "KenshiLua.LockedArmour", "KenshiLua.Armour");
}

int luaKenshiLog(lua_State* L)
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
    logToFile(msg);
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

int luaKenshiVersion(lua_State* L) { lua_pushstring(L, "KenshiLua 0.1.0"); return 1; }

} // namespace KenshiLua
