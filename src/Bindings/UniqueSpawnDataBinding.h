#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class UniqueSpawnDataBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.UniqueSpawnData"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int currentNumber(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}
