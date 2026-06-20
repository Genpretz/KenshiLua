#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ImpactPointBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ImpactPoint"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);
    
    static int __CONSTRUCTOR(lua_State* L);
    static int assign(lua_State* L);
};
}