#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class PortraitDataBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.PortraitData"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getCharacter(lua_State* L);
    static int update(lua_State* L);
    static int forceUpdate(lua_State* L);
    static int isSelected(lua_State* L);
    static int isDown(lua_State* L);
    static int getBackgroundImageName(lua_State* L);
    static int getBackOverlayImageName(lua_State* L);
    static int getFrontOverlayImageName(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}