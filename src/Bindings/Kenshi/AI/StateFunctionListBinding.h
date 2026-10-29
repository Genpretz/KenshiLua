#pragma once

#include "kenshi/Tasker.h"
#include "kenshi/AI/AI.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class StateFunctionListBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.StateFunctionList"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int isTrue(lua_State* L);
    static int hasState(lua_State* L);
};
}
