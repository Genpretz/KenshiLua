#pragma once

#include "kenshi/gui/ToolTip.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ToolTipFixedBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ToolTipFixed"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int setVisible(lua_State* L);
    static int _NV_setVisible(lua_State* L);
    static int clear(lua_State* L);
    static int _NV_clear(lua_State* L);
    static int setBottomPosition(lua_State* L);
    static int setPosition(lua_State* L);
    static int _NV_setPosition(lua_State* L);
    static int _setup(lua_State* L);
    static int _NV__setup(lua_State* L);
    static int mouseMoved(lua_State* L);
};
}