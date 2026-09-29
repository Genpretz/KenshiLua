#pragma once

#include "kenshi/gui/OrdersPanel.h"

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

    static int update(lua_State* L);
    static int clear(lua_State* L);
    static int command(lua_State* L);
    static int refreshOrders(lua_State* L);
    static int moveJob(lua_State* L);
    static int removeJob(lua_State* L);
    static int notifyEndDropOrder(lua_State* L);
    static int setSpeed(lua_State* L);
    static int setSpeedImage(lua_State* L);
    static int toggleStealth(lua_State* L);
    static int toggleRanged(lua_State* L);
    static int speedPrevious(lua_State* L);
    static int speedNext(lua_State* L);
    static int blockmodeButton(lua_State* L);
    static int holdButtonCallback(lua_State* L);
    static int passiveButtonCallback(lua_State* L);
    static int chaseButtonCallback(lua_State* L);
    static int tauntButtonCallback(lua_State* L);
    static int medicButton(lua_State* L);
    static int liftButton(lua_State* L);
    static int prospectingButton(lua_State* L);
};
}