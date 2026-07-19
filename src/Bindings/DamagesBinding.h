#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class DamagesBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Damages"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int multiply(lua_State* L);
    static int total(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}
