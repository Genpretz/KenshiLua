#pragma once

#include <string>
#include "Lua/ContainerBinding.h"

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
    static void registerContainers(lua_State* L);
    static void collectStdContainers(ContainerBindingList& definitions);
    static void collectLektor(ContainerBindingList& definitions);
    static void collectOgreUnordered(ContainerBindingList& definitions);
    static void collectBoostContainers(ContainerBindingList& definitions);
    static void collectArrays(ContainerBindingList& definitions);
    static void collectFitnessSelectors(ContainerBindingList& definitions);
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
