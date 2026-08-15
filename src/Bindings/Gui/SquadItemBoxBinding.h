#pragma once

#include "kenshi/gui/SquadManagementScreen.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class SquadItemBoxBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.SquadItemBox"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int setCellSize(lua_State* L);
    static int getItemCount(lua_State* L);
};
}