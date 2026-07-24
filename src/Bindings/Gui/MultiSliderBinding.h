#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class MultiSliderBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MultiSlider"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int initialiseOverride(lua_State* L);
    static int shutdownOverride(lua_State* L);
};
}