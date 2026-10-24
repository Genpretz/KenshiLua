#pragma once

#include "kenshi/Tasker.h"
#include "kenshi/AI/AI.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TargetWithScoreBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TargetWithScore"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int constructor(lua_State* L);
    static int operator_assign(lua_State* L);
};
}
