#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class DataPanelLineBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.DataPanelLine"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int setVisible(lua_State* L);
    static int _NV_setVisible(lua_State* L);
    static int setEnabled(lua_State* L);
    static int _NV_setEnabled(lua_State* L);
    static int refresh(lua_State* L);
    static int _NV_refresh(lua_State* L);
    static int resize(lua_State* L);
    static int _NV_resize(lua_State* L);
    static int getBottom(lua_State* L);
    static int _NV_getBottom(lua_State* L);
    static int getType(lua_State* L);
    static int getNumWidgets(lua_State* L);
    static int getWidget(lua_State* L);
};
}