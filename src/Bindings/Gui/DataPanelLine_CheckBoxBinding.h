#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class DataPanelLine_CheckBoxBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.DataPanelLine_CheckBox"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int refresh(lua_State* L);
    static int _NV_refresh(lua_State* L);
    static int setValue(lua_State* L);
    static int getTextBox(lua_State* L);
    static int getCheckBox(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}