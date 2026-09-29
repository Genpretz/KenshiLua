#pragma once

#include "kenshi/gui/ToolTip.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ToolTipBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ToolTip"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int hide(lua_State* L);
    static int _NV_hide(lua_State* L);
    static int getVisible(lua_State* L);
    static int setVisible(lua_State* L);
    static int _NV_setVisible(lua_State* L);
    static int addLine(lua_State* L);
    static int clearLines(lua_State* L);
    static int setup_hand(lua_State* L);
    static int setup_gamedata(lua_State* L);
    static int setup_stringpairs(lua_State* L);
    static int setup_text(lua_State* L);
    static int clear(lua_State* L);
    static int _NV_clear(lua_State* L);
    static int _setup(lua_State* L);
    static int _NV__setup(lua_State* L);
    static int clearData(lua_State* L);
    static int _NV_clearData(lua_State* L);
    static int show(lua_State* L);
    static int _NV_show(lua_State* L);
    static int setContent(lua_State* L);
    static int _NV_setContent(lua_State* L);
    static int showText(lua_State* L);
    static int showMultiLine(lua_State* L);
    static int showGameData_hand(lua_State* L);
    static int showGameData_widget(lua_State* L);
    static int setPosition(lua_State* L);
    static int _NV_setPosition(lua_State* L);
};
}