#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class GUIWindowBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.GUIWindow"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int clear(lua_State* L);
    static int _NV_clear(lua_State* L);
    static int show(lua_State* L);
    static int setPositionReal(lua_State* L);
    static int _NV_setPositionReal(lua_State* L);
    static int setPosition(lua_State* L);
    static int _NV_setPosition(lua_State* L);
    static int getWidth(lua_State* L);
    static int _NV_getWidth(lua_State* L);
    static int getHeight(lua_State* L);
    static int _NV_getHeight(lua_State* L);
    static int getWidthReal(lua_State* L);
    static int _NV_getWidthReal(lua_State* L);
    static int getHeightReal(lua_State* L);
    static int _NV_getHeightReal(lua_State* L);
    static int isVisible(lua_State* L);
    static int _NV_isVisible(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int getWidget(lua_State* L);
    static int resize(lua_State* L);
    static int _NV_resize(lua_State* L);
};
}