#pragma once

#include "kenshi/AI/AITaskSystem.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TaskMatchBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TaskMatch"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int constructor(lua_State* L);

    static int getTaskData(lua_State* L);
    static int key(lua_State* L);
    static int operator_assign(lua_State* L);
    static int reset(lua_State* L);
    static int operator_eq(lua_State* L);
    static int operator_ne(lua_State* L);
    static int sameAs(lua_State* L);
    static int operator_lt(lua_State* L);
    static int operator_bool(lua_State* L);
};
}
