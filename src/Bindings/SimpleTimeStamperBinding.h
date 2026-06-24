#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class SimpleTimeStamperBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.SimpleTimeStamper"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getTime(lua_State* L);
    static int stampTime(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}