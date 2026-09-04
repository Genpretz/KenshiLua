#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class PointerManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.PointerManager"; }
    static void registerBinding(lua_State* L);

    static int getInstance(lua_State* L);
    static int setPointer(lua_State* L);
    static int clearPointer(lua_State* L);
    static int getVisible(lua_State* L);
    static int setVisible(lua_State* L);
    static int isVisible(lua_State* L);
    static int getDefaultPointer(lua_State* L);
    static int setDefaultPointer(lua_State* L);
    static int getLayerName(lua_State* L);
    static int setLayerName(lua_State* L);
};

} // namespace KenshiLua
