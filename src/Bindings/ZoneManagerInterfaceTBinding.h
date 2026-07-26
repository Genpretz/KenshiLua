#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ZoneManagerInterfaceTBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ZoneManagerInterfaceT"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int isZoneLoadedT(lua_State* L);
    static int isZoneBeingLoadedT(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
};
}