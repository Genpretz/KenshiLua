#pragma once

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

    static int _DESTRUCTOR(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int hide(lua_State* L);
    static int _NV_hide(lua_State* L);
    static int getVisible(lua_State* L);
    static int setVisible(lua_State* L);
    static int _NV_setVisible(lua_State* L);
    static int addLine(lua_State* L);
    static int clearLines(lua_State* L);
};
}