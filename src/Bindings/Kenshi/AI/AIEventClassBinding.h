#pragma once

#include "kenshi/AI/AIEventClass.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class AIEventClassBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AIEventClass"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int update(lua_State* L);
};
}
