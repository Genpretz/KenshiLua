#include "pch.h"
#include "kenshi\FactionRelations.h"
#include "RelationDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{

static FactionRelations::RelationData* getInstance(lua_State* L, int idx)
{
    return checkObject<FactionRelations::RelationData>(L, idx, RelationDataBinding::getMetatableName());
}

// --- Getters for RelationData ---
static int RelationData_get_alliance(lua_State* L)
{
    FactionRelations::RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    lua_pushboolean(L, instance->alliance ? 1 : 0);
    return 1;
}

static int RelationData_get_peaceTreaty(lua_State* L)
{
    FactionRelations::RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    lua_pushboolean(L, instance->peaceTreaty ? 1 : 0);
    return 1;
}

static int RelationData_get_war(lua_State* L)
{
    FactionRelations::RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    lua_pushboolean(L, instance->war ? 1 : 0);
    return 1;
}

static int RelationData_get_coexists(lua_State* L)
{
    FactionRelations::RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    lua_pushboolean(L, instance->coexists ? 1 : 0);
    return 1;
}

static int RelationData_get_relation(lua_State* L)
{
    FactionRelations::RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    lua_pushnumber(L, instance->relation);
    return 1;
}

static int RelationData_get_trustPositives(lua_State* L)
{
    FactionRelations::RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    lua_pushnumber(L, instance->trustPositives);
    return 1;
}

static int RelationData_get_trustNegatives(lua_State* L)
{
    FactionRelations::RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    lua_pushnumber(L, instance->trustNegatives);
    return 1;
}

static int RelationData_get_percievedStrength(lua_State* L)
{
    FactionRelations::RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    lua_pushnumber(L, instance->percievedStrength);
    return 1;
}

// --- Setters for RelationData ---
static int RelationData_set_alliance(lua_State* L)
{
    FactionRelations::RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    instance->alliance = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RelationData_set_peaceTreaty(lua_State* L)
{
    FactionRelations::RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    instance->peaceTreaty = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RelationData_set_war(lua_State* L)
{
    FactionRelations::RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    instance->war = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RelationData_set_coexists(lua_State* L)
{
    FactionRelations::RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    instance->coexists = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RelationData_set_relation(lua_State* L)
{
    FactionRelations::RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    instance->relation = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RelationData_set_trustPositives(lua_State* L)
{
    FactionRelations::RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    instance->trustPositives = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RelationData_set_trustNegatives(lua_State* L)
{
    FactionRelations::RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    instance->trustNegatives = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RelationData_set_percievedStrength(lua_State* L)
{
    FactionRelations::RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    instance->percievedStrength = (float)luaL_checknumber(L, 2);
    return 0;
}

int RelationDataBinding::save(lua_State* L)
{
    FactionRelations::RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");

    GameData* factionsList = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    const std::string ID = luaL_checkstring(L, 3);
    Faction* who = checkObject<Faction>(L, 4, FactionBinding::getMetatableName());
    instance->save(factionsList, ID, who);
    return 0;
}

int RelationDataBinding::load(lua_State* L)
{
    FactionRelations::RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");

    GameData* gamestate_faction = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    const std::string ID = luaL_checkstring(L, 3);
    Faction* who = checkObject<Faction>(L, 4, FactionBinding::getMetatableName());
    instance->load(gamestate_faction, ID, who);
    return 0;
}

int RelationDataBinding::gc(lua_State* L)
{
    return 0;
}

int RelationDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.RelationData object");
    return 1;
}

void RelationDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RelationDataBinding::gc },
        { "__tostring", RelationDataBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "save", RelationDataBinding::save },
        { "load", RelationDataBinding::load },
        { 0, 0 }
    };

    registerClass(
        L, 
        RelationDataBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, RelationDataBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "alliance", RelationData_get_alliance);
    registerGetter(L, "peaceTreaty", RelationData_get_peaceTreaty);
    registerGetter(L, "war", RelationData_get_war);
    registerGetter(L, "coexists", RelationData_get_coexists);
    registerGetter(L, "relation", RelationData_get_relation);
    registerGetter(L, "trustPositives", RelationData_get_trustPositives);
    registerGetter(L, "trustNegatives", RelationData_get_trustNegatives);
    registerGetter(L, "percievedStrength", RelationData_get_percievedStrength);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "alliance", RelationData_set_alliance);
    registerSetter(L, "peaceTreaty", RelationData_set_peaceTreaty);
    registerSetter(L, "war", RelationData_set_war);
    registerSetter(L, "coexists", RelationData_set_coexists);
    registerSetter(L, "relation", RelationData_set_relation);
    registerSetter(L, "trustPositives", RelationData_set_trustPositives);
    registerSetter(L, "trustNegatives", RelationData_set_trustNegatives);
    registerSetter(L, "percievedStrength", RelationData_set_percievedStrength);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua