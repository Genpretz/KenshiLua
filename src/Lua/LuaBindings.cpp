#include "pch.h"
#include "Lua/LuaBindings.h"
#include "Lua/LuaUtils.h"
#include "Lua/LuaState.h"
#include "Lua/Logger.h"
#include "Lua/Benchmark.h"
#include "Bindings/Utility/HandBinding.h"
#include "Bindings/Character/CharacterBinding.h"
#include "Bindings/Dialogue/DialogueBinding.h"
#include "Bindings/World/FactionBinding.h"
#include "Bindings/World/TownBinding.h"
#include "Bindings/Equipment/ItemBinding.h"
#include "Bindings/Equipment/GearBinding.h"
#include "Bindings/Equipment/InventoryBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/World/GameWorldBinding.h"
#include "Bindings/Core/PlayerInterfaceBinding.h"
#include "Bindings/Core/GlobalBinding.h"
#include "Bindings/Character/CharStatsBinding.h"
#include "Bindings/System/DamagesBinding.h"
#include "Bindings/System/MedicalSystemBinding.h"
#include "Bindings/Core/InputHandlerBinding.h"
#include "Bindings/World/PlatoonBinding.h"
#include "Bindings/Core/GameDataBinding.h"
#include "Bindings/Utility/OgreUnorderedBinding.h"
#include "Bindings/Core/EnumBinding.h"
#include "Bindings/Core/RootObjectBinding.h"
#include "Bindings/Character/RaceDataBinding.h"
#include "Bindings/System/BountyBinding.h"
#include "Bindings/System/BountyManagerBinding.h"
#include "Bindings/Gui/CameraClassBinding.h"
#include "Bindings/Gui/MyGuiBinding.h"
#include "Bindings/Character/CharacterAnimalBinding.h"
#include "Bindings/Character/ShopTraderBinding.h"
#include "Bindings/Character/CharBodyBinding.h"
#include "Bindings/Character/Combat/CombatMovementControllerBinding.h"
#include "Bindings/Character/Combat/ImpactPointBinding.h"
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

    HandBinding::registerBinding(L);
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
    BuildingBinding::registerBinding(L);
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
    registerOgreUnorderedBindings(L);
    MyGuiBinding::registerBinding(L);
    ShopTraderBinding::registerBinding(L);
    AnimalInventoryLayoutBinding::registerBinding(L);
    CharacterAnimalBinding::registerBinding(L);
    CharBodyBinding::registerBinding(L);
    CombatMovementControllerBinding::registerBinding(L);
    ImpactPointBinding::registerBinding(L);

	registerEnums(L);
    registerGlobals(L);
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