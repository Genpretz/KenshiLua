#pragma once

#include "kenshi/gui/InventoryGUI.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TraderInventoryLayoutBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TraderInventoryLayout"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

};
}