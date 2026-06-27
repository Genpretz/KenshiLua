#include "pch.h"
#include <kenshi/FactionRelations.h>
#include "FactionRelationsBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/FactionBinding.h"

namespace KenshiLua
{

static FactionRelations* getInstance(lua_State* L, int idx)
{
    return checkObject<FactionRelations>(L, idx, FactionRelationsBinding::getMetatableName());
}

// --- Getters for FactionRelations ---
static int FactionRelations_get_me(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    return pushObject<Faction>(L, instance->me, FactionBinding::getMetatableName());
}

static int FactionRelations_get_playerRank(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    lua_pushinteger(L, instance->playerRank);
    return 1;
}

static int FactionRelations_get_globalReputationTrust(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    lua_pushnumber(L, instance->globalReputationTrust);
    return 1;
}

static int FactionRelations_get_globalReputationForBadassery(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    lua_pushnumber(L, instance->globalReputationForBadassery);
    return 1;
}

static int FactionRelations_get__factionRelations(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    // TODO: Unsupported type for _factionRelations (ogre_unordered_map<Faction*, RelationData>::type)
    lua_pushnil(L);
    return 1;
}

static int FactionRelations_get_defaultFactionRelation(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    lua_pushnumber(L, instance->defaultFactionRelation);
    return 1;
}

// --- Setters for FactionRelations ---
static int FactionRelations_set_me(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    return luaL_error(L, "Read-only or unsupported setter type for me");
}

static int FactionRelations_set_playerRank(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    instance->playerRank = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int FactionRelations_set_globalReputationTrust(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    instance->globalReputationTrust = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FactionRelations_set_globalReputationForBadassery(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    instance->globalReputationForBadassery = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FactionRelations_set__factionRelations(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    return luaL_error(L, "Read-only or unsupported setter type for _factionRelations");
}

static int FactionRelations_set_defaultFactionRelation(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    instance->defaultFactionRelation = (float)luaL_checknumber(L, 2);
    return 0;
}

int FactionRelationsBinding::_CONSTRUCTOR(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");

    FactionRelations* result = instance->_CONSTRUCTOR();
    return pushObject<FactionRelations>(L, result, FactionRelationsBinding::getMetatableName());
}

int FactionRelationsBinding::setupPhase2(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");

    instance->setupPhase2();
    return 0;
}

int FactionRelationsBinding::isEnemyByDefault(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");

    bool result = instance->isEnemyByDefault();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionRelationsBinding::reset(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");

    instance->reset();
    return 0;
}

int FactionRelationsBinding::update(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");

    instance->update();
    return 0;
}

int FactionRelationsBinding::_NV_update(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");

    instance->_NV_update();
    return 0;
}

int FactionRelationsBinding::_DESTRUCTOR(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 18: void setupPhase1(...) - unsupported arg type
  line 22: void save(...) - unsupported arg type
  line 23: void _NV_save(...) - unsupported arg type
  line 24: void load(...) - unsupported arg type
  line 25: void _NV_load(...) - unsupported arg type
  line 28: bool _isAlly(...) - unsupported arg type
  line 29: bool _isEnemy(...) - unsupported arg type
  line 30: bool isEnemy(...) - unsupported arg type
  line 31: void setEnemy(...) - unsupported arg type
  line 32: void _NV_setEnemy(...) - unsupported arg type
  line 33: bool isAlly(...) - unsupported arg type
  line 34: bool isCoexisting(...) - unsupported arg type
  line 35: float getFactionRelation(...) - unsupported arg type
  line 36: float getFactionRelationMultiplier(...) - unsupported arg type
  line 37: float getFactionRelationMultiplierInverse(...) - unsupported arg type
  line 38: void setRelation(...) - unsupported arg type
  line 56: void affectRelations(...) - overloaded method
  line 57: void _NV_affectRelations(...) - overloaded method
  line 58: void affectRelations(...) - overloaded method
  line 59: void _NV_affectRelations(...) - overloaded method
  line 60: void affectTrust(...) - unsupported arg type
  line 61: void _NV_affectTrust(...) - unsupported arg type
  line 62: void setNoLongerEnemies(...) - unsupported arg type
  line 63: void _NV_setNoLongerEnemies(...) - unsupported arg type
  line 64: void declareWar(...) - unsupported arg type
  line 65: void _NV_declareWar(...) - unsupported arg type
  line 66: void affectReputation(...) - unsupported arg type
  line 67: void _NV_affectReputation(...) - unsupported arg type
  line 98: RelationData* getRelationData(...) - unsupported arg type
  line 99: RelationData* _NV_getRelationData(...) - unsupported arg type
  line 100: void getGUIData(...) - unsupported arg type
  line 101: void getRelationsData(...) - unsupported arg type
  line 104: bool checkStateCondition(...) - unsupported arg type
*/

int FactionRelationsBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int FactionRelationsBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FactionRelations object");
    return 1;
}

void FactionRelationsBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FactionRelationsBinding::gc },
        { "__tostring", FactionRelationsBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", FactionRelationsBinding::_CONSTRUCTOR },
        { "setupPhase2", FactionRelationsBinding::setupPhase2 },
        { "isEnemyByDefault", FactionRelationsBinding::isEnemyByDefault },
        { "reset", FactionRelationsBinding::reset },
        { "update", FactionRelationsBinding::update },
        { "_NV_update", FactionRelationsBinding::_NV_update },
        { "_DESTRUCTOR", FactionRelationsBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        FactionRelationsBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FactionRelationsBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, FactionRelations_get_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, FactionRelations_get_playerRank);
    lua_setfield(L, -2, "playerRank");
    lua_pushcfunction(L, FactionRelations_get_globalReputationTrust);
    lua_setfield(L, -2, "globalReputationTrust");
    lua_pushcfunction(L, FactionRelations_get_globalReputationForBadassery);
    lua_setfield(L, -2, "globalReputationForBadassery");
    lua_pushcfunction(L, FactionRelations_get__factionRelations);
    lua_setfield(L, -2, "_factionRelations");
    lua_pushcfunction(L, FactionRelations_get_defaultFactionRelation);
    lua_setfield(L, -2, "defaultFactionRelation");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, FactionRelations_set_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, FactionRelations_set_playerRank);
    lua_setfield(L, -2, "playerRank");
    lua_pushcfunction(L, FactionRelations_set_globalReputationTrust);
    lua_setfield(L, -2, "globalReputationTrust");
    lua_pushcfunction(L, FactionRelations_set_globalReputationForBadassery);
    lua_setfield(L, -2, "globalReputationForBadassery");
    lua_pushcfunction(L, FactionRelations_set__factionRelations);
    lua_setfield(L, -2, "_factionRelations");
    lua_pushcfunction(L, FactionRelations_set_defaultFactionRelation);
    lua_setfield(L, -2, "defaultFactionRelation");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua