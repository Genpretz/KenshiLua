#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class WorldEventStateQueryBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.WorldEventStateQuery"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int isTrue(lua_State* L);
};
}
