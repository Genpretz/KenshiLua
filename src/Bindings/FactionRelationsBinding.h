#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class FactionRelationsBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.FactionRelations"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int setupPhase2(lua_State* L);
    static int isEnemyByDefault(lua_State* L);
    static int reset(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}