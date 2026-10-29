#pragma once

#include "kenshi/AI/AITaskSystem.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class OrdersReceiver_TaskRequestSimpleBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.OrdersReceiver_TaskRequestSimple"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int sameAs(lua_State* L);
};
}
