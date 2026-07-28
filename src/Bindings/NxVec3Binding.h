#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class NxVec3Binding
{
public:
    static const char* getMetatableName() { return "KenshiLua.NxVec3"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int zero(lua_State* L);
    static int isZero(lua_State* L);
    static int normalize(lua_State* L);
    static int setMagnitude(lua_State* L);
    static int closestAxis(lua_State* L);
    static int isFinite(lua_State* L);
    static int magnitude(lua_State* L);
    static int magnitudeSquared(lua_State* L);
};
}