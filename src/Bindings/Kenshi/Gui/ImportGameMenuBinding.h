#pragma once

#include "kenshi/gui/LoadSaveWindow.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ImportGameMenuBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ImportGameMenu"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int select(lua_State* L);
    static int _NV_select(lua_State* L);
};
}