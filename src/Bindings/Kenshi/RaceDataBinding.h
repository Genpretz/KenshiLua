#pragma once

#include "kenshi/RaceData.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class RaceDataBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.RaceData"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getRaceData(lua_State* L);
    static int isRelatedRace(lua_State* L);
    static int isSpecificRace(lua_State* L);
    static int getStatMod(lua_State* L);
    static int isImmune(lua_State* L);
    static int canEat(lua_State* L);
};
}