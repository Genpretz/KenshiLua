#pragma once
#include <kenshi/ZoneManager.h>


extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    typedef ZoneMap::StateT StateT;
class StateTBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.StateT"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
};
}