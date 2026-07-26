#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ZoneSpacialGridBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ZoneSpacialGrid"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int add(lua_State* L);
    static int remove(lua_State* L);
    static int update(lua_State* L);
    static int addZone(lua_State* L);
    static int removeZone(lua_State* L);
    static int getZoneKey(lua_State* L);
    static int getCellKey(lua_State* L);
    static int getFullKey(lua_State* L);
    static int initialiseGrid(lua_State* L);
};
}