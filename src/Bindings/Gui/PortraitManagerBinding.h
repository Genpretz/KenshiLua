#pragma once

#include "kenshi/gui/PortraitManager.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class PortraitManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.PortraitManager"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int init(lua_State* L);
    static int destroy(lua_State* L);
    static int setUpdateEnabled(lua_State* L);
    static int reloadPortraits(lua_State* L);
    static int reloadTexture(lua_State* L);
    static int saveTexture(lua_State* L);
    static int clearPortraits(lua_State* L);
    static int getCharacterFlashing(lua_State* L);
    static int getCharacterInCombat(lua_State* L);
    static int getCharacterDown(lua_State* L);
    static int getSquadFlashing(lua_State* L);
    static int getPortrait(lua_State* L);
    static int updatePortrait(lua_State* L);
    static int updatePortraitImage(lua_State* L);
    static int setImageWidget(lua_State* L);
    static int getInstance(lua_State* L);
};
}