#pragma once

#include "kenshi/gui/LoadSaveWindow.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class LoadSaveWindowBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.LoadSaveWindow"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int select(lua_State* L);
    static int _NV_select(lua_State* L);
    static int getWidget(lua_State* L);
    static int deleteSelectedSave(lua_State* L);
    static int addOption(lua_State* L);
    static int enableOption(lua_State* L);
    static int getOptions(lua_State* L);
};
}