#pragma once

#include "kenshi/AI/AITaskSystem.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TaskRequestBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TaskRequest"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int constructor(lua_State* L);
    static int sameAs(lua_State* L);
    static int operator_eq(lua_State* L);
    static int operator_assign(lua_State* L);
};
}
