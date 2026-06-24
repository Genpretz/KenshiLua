#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class RootObjectFactoryBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.RootObjectFactory"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int mainThreadUpdate(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}