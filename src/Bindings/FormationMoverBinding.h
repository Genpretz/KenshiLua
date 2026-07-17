#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class FormationMoverBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.FormationMover"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int update(lua_State* L);
    static int stopFormationMode(lua_State* L);
};
}