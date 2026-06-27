#pragma once

extern "C" {
#include <lua.h>
}

namespace KenshiLua
{
    int luaCheckLuaScriptReferences(lua_State* L);
    int luaGetGameData(lua_State* L);
    void InstallLuaScriptCheckerHooks();
}

