#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class RepetitionCounterBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.RepetitionCounter"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int setup(lua_State* L);
    static int count(lua_State* L);
    static int getTimeSinceLastTrigger(lua_State* L);
    static int getCount(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}