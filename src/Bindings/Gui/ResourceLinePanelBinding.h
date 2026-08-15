#pragma once

#include "kenshi/gui/ManagementScreen.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ResourceLinePanelBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ResourceLinePanel"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getWidget(lua_State* L);
};
}