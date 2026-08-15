#pragma once

#include "kenshi/gui/InventoryTraderGUI.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class InventoryTraderGUIBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.InventoryTraderGUI"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int getInventory(lua_State* L);
    static int _NV_getInventory(lua_State* L);
    static int getCallbackCharacter(lua_State* L);
    static int _NV_getCallbackCharacter(lua_State* L);
    static int getCallbackObject(lua_State* L);
    static int _NV_getCallbackObject(lua_State* L);
    static int refreshSection(lua_State* L);
    static int _NV_refreshSection(lua_State* L);
};
}