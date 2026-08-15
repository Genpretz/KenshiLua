#pragma once

#include "kenshi/gui/PortraitManager.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class PortraitSquadCellViewBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.PortraitSquadCellView"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int resize(lua_State* L);
    static int setName(lua_State* L);
};
}