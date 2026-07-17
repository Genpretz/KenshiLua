#pragma once
#include <kenshi/gui/InventoryGUI.h>


extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    typedef InventoryGUI::InventoryTradeData InventoryTradeData;
class InventoryTradeDataBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.InventoryTradeData"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int isValid(lua_State* L);
};
}