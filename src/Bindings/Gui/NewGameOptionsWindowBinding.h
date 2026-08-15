#pragma once

#include "kenshi/gui/NewGameOptionsWindow.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class NewGameOptionsWindowBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.NewGameOptionsWindow"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int setVisible(lua_State* L);
    static int getVisible(lua_State* L);
    static int setPosition(lua_State* L);
    static int update(lua_State* L);
};
}