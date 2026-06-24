#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class MedianFilter2DVectorBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MedianFilter2DVector"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int setup(lua_State* L);
    static int reset(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}