#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class OrdersPanelBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.OrdersPanel"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int clear(lua_State* L);
    static int command(lua_State* L);
    static int refreshOrders(lua_State* L);
    static int moveJob(lua_State* L);
    static int setSpeed(lua_State* L);
    static int setSpeedImage(lua_State* L);
};
}