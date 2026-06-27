#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class DataPanelLine_DropBoxBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.DataPanelLine_DropBox"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int addAValue(lua_State* L);
    static int getSelectedValue(lua_State* L);
    static int setSelectedValue(lua_State* L);
    static int getSelectedText(lua_State* L);
    static int clearValues(lua_State* L);
    static int getComboBox(lua_State* L);
    static int refresh(lua_State* L);
    static int _NV_refresh(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}