#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class SeenSomeoneBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.SeenSomeone"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int lastSeenInSeconds(lua_State* L);
    static int getPosition(lua_State* L);
    static int getFaction(lua_State* L);
};
}
