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
#include <cstdlib>

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
    { "getLuaVersion", luaKenshiGetLuaVersion },
    { "toJSON", luaKenshiToJSON },
    { "fromJSON", luaKenshiFromJSON },
    { "runBenchmark", luaKenshiRunBenchmark },
    { NULL, NULL }
};

void LuaBindings::registerAll(lua_State* L)
{
    luaL_newlib(L, KenshiLuaLib);
    lua_setglobal(L, "KenshiLua");

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

int luaKenshiGetLuaVersion(lua_State* L)
{
    // Returns the Lua version string (e.g., "Lua 5.5")
    lua_pushstring(L, LUA_VERSION);
    return 1;
}

int luaKenshiToJSON(lua_State* L)
{
    // Stack: 1 = value to encode
    // Uses Lua 5.5's json.encode if available, otherwise falls back to simple conversion
    if (luaL_getmetafield(L, 1, "__name") != 0) {
        // Complex type - try to use json library if available
        luaL_getsubtable(L, LUA_REGISTRYINDEX, "_LOADED");
        lua_getfield(L, -1, "json");
        if (lua_istable(L, -1)) {
            lua_getfield(L, -1, "encode");
            if (lua_isfunction(L, -1)) {
                lua_pushvalue(L, 1);
                if (lua_pcall(L, 1, 1, 0) == LUA_OK) {
                    return 1;
                }
            }
        }
    }

    // Fallback: simple string representation for basic types
    switch (lua_type(L, 1)) {
    case LUA_TNIL:
        lua_pushstring(L, "null");
        return 1;
    case LUA_TBOOLEAN:
        lua_pushstring(L, lua_toboolean(L, 1) ? "true" : "false");
        return 1;
    case LUA_TNUMBER:
        lua_pushvalue(L, 1);
        lua_tostring(L, -1);
        return 1;
    case LUA_TSTRING:
        lua_pushvalue(L, 1);
        return 1;
    default:
        luaL_error(L, "Cannot convert %s to JSON", lua_typename(L, lua_type(L, 1)));
        return 0;
    }
}

int luaKenshiFromJSON(lua_State* L)
{
    // Stack: 1 = JSON string to decode
    const char* json_str = luaL_checkstring(L, 1);

    // Try to use json library if available
    luaL_getsubtable(L, LUA_REGISTRYINDEX, "_LOADED");
    lua_getfield(L, -1, "json");
    if (lua_istable(L, -1)) {
        lua_getfield(L, -1, "decode");
        if (lua_isfunction(L, -1)) {
            lua_pushstring(L, json_str);
            if (lua_pcall(L, 1, 1, 0) == LUA_OK) {
                return 1;
            }
        }
    }

    // Fallback: simple parsing for literals
    lua_pop(L, 2);  // Remove json table and registry subtable

    if (strcmp(json_str, "null") == 0) {
        lua_pushnil(L);
        return 1;
    } else if (strcmp(json_str, "true") == 0) {
        lua_pushboolean(L, 1);
        return 1;
    } else if (strcmp(json_str, "false") == 0) {
        lua_pushboolean(L, 0);
        return 1;
    } else if (json_str[0] == '"' && json_str[strlen(json_str) - 1] == '"') {
        // String literal
        lua_pushlstring(L, json_str + 1, strlen(json_str) - 2);
        return 1;
    } else {
        // Try to parse as number
        char* endptr = nullptr;
        lua_Number num = strtod(json_str, &endptr);
        if (endptr != json_str && *endptr == '\0') {
            lua_pushnumber(L, num);
            return 1;
        }
    }

    luaL_error(L, "Failed to decode JSON string: %s", json_str);
    return 0;
}

int luaKenshiVersion(lua_State* L) { lua_pushstring(L, "KenshiLua 0.2.0 (Lua 5.5)"); return 1; }

} // namespace KenshiLua