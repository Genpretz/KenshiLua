#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

class RaceData;

namespace KenshiLua
{

class RaceDataBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.RaceData"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    // Methods
    static int isRelatedRace(lua_State* L);
    static int canEat(lua_State* L);
    static int isImmune(lua_State* L);
};

} // namespace KenshiLua
