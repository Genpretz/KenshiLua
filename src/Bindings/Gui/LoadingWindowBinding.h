#pragma once

#include "kenshi/gui/LoadingWindow.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class LoadingWindowBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.LoadingWindow"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int reload(lua_State* L);
    static int setVisible(lua_State* L);
    static int getVisible(lua_State* L);
    static int show(lua_State* L);
    static int hide(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int frameEntered(lua_State* L);
    static int setRandomBackground(lua_State* L);
    static int setRandomTip(lua_State* L);
    static int getInstance(lua_State* L);
};
}