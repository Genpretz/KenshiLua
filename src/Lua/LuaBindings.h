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
};

// Free functions exposed as Lua globals.
int luaKenshiLog(lua_State* L);
int luaKenshiError(lua_State* L);
int luaKenshiVersion(lua_State* L);

} // namespace KenshiLua
