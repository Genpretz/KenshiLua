#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TortureBuildingBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TortureBuilding"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getFunctionStuff(lua_State* L);
    static int _NV_getFunctionStuff(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}