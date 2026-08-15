#pragma once

#include "kenshi/FoliageSystem.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class FoliageSystemBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.FoliageSystem"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int update(lua_State* L);
    static int getCollisionHash(lua_State* L);
    static int setupGrass(lua_State* L);
    static int setupFoliage(lua_State* L);
    static int spawn(lua_State* L);
    static int randomInt(lua_State* L);
    static int random(lua_State* L);
};
}