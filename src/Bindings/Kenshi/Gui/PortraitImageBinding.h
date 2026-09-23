#pragma once

#include "kenshi/gui/PortraitManager.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class PortraitImageBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.PortraitImage"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

};
}