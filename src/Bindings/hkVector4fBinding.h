#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class hkVector4fBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.hkVector4f"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int setZero(lua_State* L);
    static int zeroComponent(lua_State* L);
    static int setInt24W(lua_State* L);
    static int getInt24W(lua_State* L);
    static int getInt16W(lua_State* L);
    static int setZero4(lua_State* L);
    static int normalize3(lua_State* L);
};
}