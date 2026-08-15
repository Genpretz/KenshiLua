#pragma once

#include "kenshi/gui/DataPanelLine.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class DataPanelLine_FactionBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.DataPanelLine_Faction"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int createMe(lua_State* L);
    static int _NV_createMe(lua_State* L);
};
}