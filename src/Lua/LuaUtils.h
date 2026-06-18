#pragma once

#include <string>

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
namespace LuaUtils
{

int luaLog(lua_State* L);

int luaError(lua_State* L);

int luaPrint(lua_State* L);

void registerBasicBindings(lua_State* L);

std::string luaToString(lua_State* L, int idx);

int luaRequireSafe(lua_State* L);

bool executeChunk(lua_State* L, int ref);

} // namespace LuaUtils
} // namespace KenshiLua