#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace wraps
{
class BaseLayoutBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.BaseLayout"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

};
}