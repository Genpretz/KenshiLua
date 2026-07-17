#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class AABB2DBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AABB2D"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int setNull(lua_State* L);
    static int pointWithin(lua_State* L);
    static int inflate(lua_State* L);
    static int sizeX(lua_State* L);
    static int sizeY(lua_State* L);
};
}