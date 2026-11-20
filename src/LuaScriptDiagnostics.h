#pragma once

struct lua_State;

namespace KenshiLua
{
    int luaCheckLuaScriptReferences(lua_State* L);
}
