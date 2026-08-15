#pragma once

#include "kenshi/FactionUniqueSquadManager.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class FactionUniqueSquadManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.FactionUniqueSquadManager"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int clearAndReset(lua_State* L);
    static int initialiseNew(lua_State* L);
    static int chooseRandomSquadToSpawn(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int serialise(lua_State* L);
    static int load(lua_State* L);
    static int getGUIData(lua_State* L);
    static int getExistingSquadsFor(lua_State* L);
    static int spawnNewUniqueSquad(lua_State* L);
};
}