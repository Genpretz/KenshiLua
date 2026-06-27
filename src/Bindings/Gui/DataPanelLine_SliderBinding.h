#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class DataPanelLine_SliderBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.DataPanelLine_Slider"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int setValue(lua_State* L);
    static int getValue(lua_State* L);
    static int refresh(lua_State* L);
    static int _NV_refresh(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}