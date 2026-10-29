#pragma once

#include "kenshi/AI/AITaskSystem.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class AITaskSytem_FailedTaskBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AITaskSytem_FailedTask"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};
}
