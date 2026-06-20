#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ResearchBuildingBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ResearchBuilding"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int dontNeedWorkRightNow(lua_State* L);
    static int _NV_dontNeedWorkRightNow(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int notifyConstructionComplete(lua_State* L);
    static int _NV_notifyConstructionComplete(lua_State* L);
    static int getTechLevel(lua_State* L);
    static int _NV_getTechLevel(lua_State* L);
};
}