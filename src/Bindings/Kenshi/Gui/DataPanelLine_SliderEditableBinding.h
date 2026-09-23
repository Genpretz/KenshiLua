#pragma once

#include "kenshi/gui/DataPanelLine.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class DataPanelLine_SliderEditableBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.DataPanelLine_SliderEditable"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int setEditableValuePtr(lua_State* L);
    static int getSlider(lua_State* L);
    static int getEditBox(lua_State* L);
    static int setValue(lua_State* L);
    static int refresh(lua_State* L);
    static int _NV_refresh(lua_State* L);
    static int setPrecision(lua_State* L);
    static int createMe(lua_State* L);
    static int _NV_createMe(lua_State* L);
};
}