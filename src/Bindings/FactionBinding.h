#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

class Faction;

namespace KenshiLua
{

Faction* getFactionFromLua(lua_State* L, int idx);

class FactionBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Faction"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int getName(lua_State* L);
    static int setName(lua_State* L);
    static int isThePlayer(lua_State* L);
    static int isNotARealFaction(lua_State* L);
    static int isAntiSlavery(lua_State* L);
    static int isALawEnforcementFaction(lua_State* L);
    static int getLawEnforcementFaction(lua_State* L);
    static int getFactionSize(lua_State* L);
    static int getNumPlatoons(lua_State* L);
    static int getProsperityMultiplier(lua_State* L);
    static int getRoadPreference(lua_State* L);
    static int getRelation(lua_State* L);
    static int setRelation(lua_State* L);
    static int declareWar(lua_State* L);
    static int declarePeace(lua_State* L);
    static int createPlatoon(lua_State* L);
};

} // namespace KenshiLua
