#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TownPositionCacherBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TownPositionCacher"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int stampUpdate(lua_State* L);
    static int needsUpdate(lua_State* L);
};
}
