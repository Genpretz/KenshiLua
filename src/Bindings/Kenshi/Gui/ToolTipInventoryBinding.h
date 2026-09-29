#pragma once

#include "kenshi/gui/ToolTip.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ToolTipInventoryBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ToolTipInventory"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int _setup(lua_State* L);
    static int _NV__setup(lua_State* L);
    static int setup(lua_State* L);
    static int _NV_setup(lua_State* L);
    static int show(lua_State* L);
    static int _NV_show(lua_State* L);
    static int setContent(lua_State* L);
    static int _NV_setContent(lua_State* L);
    static int clearData(lua_State* L);
    static int _NV_clearData(lua_State* L);
    static int mouseMoved(lua_State* L);
    static int setPosition(lua_State* L);
    static int _NV_setPosition(lua_State* L);
};
}