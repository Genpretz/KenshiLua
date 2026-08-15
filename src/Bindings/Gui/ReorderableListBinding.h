#pragma once

#include "kenshi/gui/CharacterEditWindow.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ReorderableListBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ReorderableList"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int clear(lua_State* L);
    static int refresh(lua_State* L);
    static int notifyEndDrop(lua_State* L);
    static int notifyRemoved(lua_State* L);
};
}