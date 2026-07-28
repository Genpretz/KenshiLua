#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class EntDataBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.EntData"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int createEntity1(lua_State* L);
    static int createEntity2(lua_State* L);
    static int selectBiomeEntity(lua_State* L);
    static int isLoaded(lua_State* L);
};
}