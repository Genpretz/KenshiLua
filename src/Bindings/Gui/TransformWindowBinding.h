#pragma once

#include "kenshi/gui/TransformWindow.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TransformWindowBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TransformWindow"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int setCaption(lua_State* L);
    static int updateState(lua_State* L);
    static int close(lua_State* L);
    static int refresh(lua_State* L);
    static int updateGizmo(lua_State* L);
    static int isActive(lua_State* L);
    static int isVisible(lua_State* L);
    static int hasChanged(lua_State* L);
    static int clearChangedFlag(lua_State* L);
    static int getMode(lua_State* L);
    static int setMode(lua_State* L);
    static int getLastZone(lua_State* L);
    static int getZone(lua_State* L);
    static int changeMode(lua_State* L);
    static int changeCoord(lua_State* L);
    static int changeValue(lua_State* L);
    static int reset(lua_State* L);
    static int revert(lua_State* L);
    static int getSingleton(lua_State* L);
};
}