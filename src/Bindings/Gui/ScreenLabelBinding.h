#pragma once

#include "kenshi/gui/ScreenLabel.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ScreenLabelBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ScreenLabel"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int setCaption(lua_State* L);
    static int _NV_setCaption(lua_State* L);
    static int setRisingSpeed(lua_State* L);
    static int _NV_setRisingSpeed(lua_State* L);
    static int setPosition(lua_State* L);
    static int _NV_setPosition(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int destroy(lua_State* L);
};
}