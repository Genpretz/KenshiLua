#pragma once

#include "kenshi/gui/InventoryGUI.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class BackpackInventoryLayoutBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.BackpackInventoryLayout"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

};
}