#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class SquadManagementScreenBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.SquadManagementScreen"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int getVisible(lua_State* L);
    static int update(lua_State* L);
    static int reset(lua_State* L);
    static int refreshSquads(lua_State* L);
    static int notifyEndDropSquad(lua_State* L);
    static int notifyEndDropPortrait(lua_State* L);
    static int removeSquad(lua_State* L);
    static int getSquad(lua_State* L);
    static int dismissCharacter(lua_State* L);
};
}