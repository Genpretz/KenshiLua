#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class Blackboard_TaskInfoBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Blackboard_TaskInfo"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int constructor(lua_State* L);
    static int operator_assign(lua_State* L);
};
}
