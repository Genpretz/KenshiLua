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

    static int setupPhase1(lua_State* L);
    static int save(lua_State* L);
    static int _NV_save(lua_State* L);
    static int load(lua_State* L);
    static int _NV_load(lua_State* L);
    static int _isAlly(lua_State* L);
    static int _isEnemy(lua_State* L);
    static int isEnemy(lua_State* L);
    static int setEnemy(lua_State* L);
    static int _NV_setEnemy(lua_State* L);
    static int isAlly(lua_State* L);
    static int isCoexisting(lua_State* L);
    static int getFactionRelation(lua_State* L);
    static int getFactionRelationMultiplier(lua_State* L);
    static int getFactionRelationMultiplierInverse(lua_State* L);
    static int setRelation(lua_State* L);
    static int affectRelations(lua_State* L);
    static int _NV_affectRelations(lua_State* L);
    static int affectTrust(lua_State* L);
    static int _NV_affectTrust(lua_State* L);
    static int setNoLongerEnemies(lua_State* L);
    static int _NV_setNoLongerEnemies(lua_State* L);
    static int declareWar(lua_State* L);
    static int _NV_declareWar(lua_State* L);
    static int affectReputation(lua_State* L);
    static int _NV_affectReputation(lua_State* L);
    static int getRelationData(lua_State* L);
    static int _NV_getRelationData(lua_State* L);
    static int getGUIData(lua_State* L);
    static int getRelationsData(lua_State* L);
    static int checkStateCondition(lua_State* L);
};
}
