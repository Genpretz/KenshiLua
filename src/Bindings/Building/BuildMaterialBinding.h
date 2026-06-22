#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class BuildMaterialBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.BuildMaterial"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int getMaterialsBarProgress(lua_State* L);
    static int getNumRemaining(lua_State* L);
};
}