#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class SelectionBoxBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.SelectionBox"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int cancel(lua_State* L);
    static int isActive(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}