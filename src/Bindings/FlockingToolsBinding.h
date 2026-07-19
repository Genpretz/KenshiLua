#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class FlockingToolsBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.FlockingTools"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int setCurrentPosition(lua_State* L);
};
}
