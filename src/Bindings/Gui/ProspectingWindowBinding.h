#pragma once

#include "kenshi/gui/ProspectingWindow.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ProspectingWindowBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ProspectingWindow"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int showT(lua_State* L);
    static int _show(lua_State* L);
    static int hide(lua_State* L);
    static int getVisible(lua_State* L);
    static int updateCameraMarker(lua_State* L);
    static int updateMap(lua_State* L);
    static int refresh(lua_State* L);
    static int clear(lua_State* L);
    static int worldToMapCoords(lua_State* L);
    static int getSingleton(lua_State* L);
};
}