#pragma once

#include <string>

extern "C" {
#include <lua.h>
}

namespace KenshiLua
{

// Single entry point - registers every Lua class binding, every global, and
// the small free-function library (log, error, version).
class LuaBindings
{
public:
    static void registerAll(lua_State* L);
    static void registerLektor(lua_State* L);
    static void registerOgreUnordered(lua_State* L);
    static void registerSTL(lua_State* L);
    static void registerStdSet(lua_State* L);
    static void registerStdMap(lua_State* L);
    static void registerStdDeque(lua_State* L);
    static void registerFitnessSelector(lua_State* L);
    static void registerClasses(lua_State* L);
};

void installKenshiLuaTable(lua_State* L);

// Free functions exposed as Lua globals.
int luaKenshiLog(lua_State* L);
int luaKenshiLogDebug(lua_State* L);
int luaKenshiLogWarn(lua_State* L);
int luaKenshiLogError(lua_State* L);
int luaKenshiError(lua_State* L);
int luaKenshiVersion(lua_State* L);

} // namespace KenshiLua
