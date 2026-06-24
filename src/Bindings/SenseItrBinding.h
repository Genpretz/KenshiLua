#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class SenseItrBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.SenseItr"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getCharacter(lua_State* L);
    static int ended(lua_State* L);
    static int increment(lua_State* L);
};
}