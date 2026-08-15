#pragma once

#include "kenshi/gui/LevelEditor.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class NpcListWindowBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.NpcListWindow"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int itemSelected(lua_State* L);
    static int _NV_itemSelected(lua_State* L);
};
}