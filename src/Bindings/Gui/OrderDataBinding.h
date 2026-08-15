#pragma once

#include "kenshi/gui/OrdersPanel.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class OrderDataBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.OrderData"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int set(lua_State* L);
    static int updateText(lua_State* L);
};
}