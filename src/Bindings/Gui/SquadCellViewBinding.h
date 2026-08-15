#pragma once

#include "kenshi/gui/SquadManagementScreen.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class SquadCellViewBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.SquadCellView"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int updateSquadSize(lua_State* L);
};
}