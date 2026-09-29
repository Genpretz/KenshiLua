#pragma once

#include "kenshi/gui/TitleScreen.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TitleScreenBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TitleScreen"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int clear(lua_State* L);
    static int _NV_clear(lua_State* L);
    static int show(lua_State* L);
    static int _NV_show(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int closeTheOtherBits(lua_State* L);
    static int setCreditsVisible(lua_State* L);
    static int getSingleton(lua_State* L);
    static int loadGame(lua_State* L);
    static int importGame(lua_State* L);
    static int showOptions(lua_State* L);
    static int credits(lua_State* L);
    static int exitGame(lua_State* L);
    static int continueGame(lua_State* L);
    static int hover(lua_State* L);
};
}