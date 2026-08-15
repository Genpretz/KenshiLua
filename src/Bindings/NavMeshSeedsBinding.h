#pragma once

#include "kenshi/NavMeshGenerator.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class NavMeshSeedsBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.NavMeshSeeds"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int load(lua_State* L);
    static int save(lua_State* L);
    static int addSeedPoint(lua_State* L);
    static int removeSeedPoints(lua_State* L);
    static int clearSeedPoints(lua_State* L);
    static int removeIsland(lua_State* L);
    static int projectToTerrain(lua_State* L);
    static int getSeedPoints(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}