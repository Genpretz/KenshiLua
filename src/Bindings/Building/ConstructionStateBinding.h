#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ConstructionStateBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ConstructionState"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int materialsEmpty(lua_State* L);
    static int isOverThreshold(lua_State* L);
    static int getHealthBarProgress(lua_State* L);
    static int getConstructionMaterialProgress(lua_State* L);
    static int getHealthBarActual(lua_State* L);
    static int getTotalMats(lua_State* L);
    static int getTotalMatsPresent(lua_State* L);
    static int needMats(lua_State* L);
};
}