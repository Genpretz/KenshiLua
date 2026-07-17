#pragma once
#include <kenshi/gui/InventoryGUI.h>


extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    typedef InventoryGUI::TradeResult TradeResult;
class TradeResultBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TradeResult"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int showMessage(lua_State* L);
};
}