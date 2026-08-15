#pragma once

#include "kenshi/gui/CharacterTradingWindow.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TradeResultBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TradeResult"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int eq(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int showMessage(lua_State* L);
    static int ShowMessage(lua_State* L);
};
}