#include "pch.h"
#include <kenshi/FactionRelations.h>
#include "RelationDataBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
typedef FactionRelations::RelationData RelationData;

static RelationData* getInstance(lua_State* L, int idx)
{
    return checkObject<RelationData>(L, idx, RelationDataBinding::getMetatableName());
}

// --- Getters for RelationData ---
static int RelationData_get_alliance(lua_State* L)
{
    RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    lua_pushboolean(L, instance->alliance ? 1 : 0);
    return 1;
}

static int RelationData_get_peaceTreaty(lua_State* L)
{
    RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    lua_pushboolean(L, instance->peaceTreaty ? 1 : 0);
    return 1;
}

static int RelationData_get_war(lua_State* L)
{
    RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    lua_pushboolean(L, instance->war ? 1 : 0);
    return 1;
}

static int RelationData_get_coexists(lua_State* L)
{
    RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    lua_pushboolean(L, instance->coexists ? 1 : 0);
    return 1;
}

static int RelationData_get_relation(lua_State* L)
{
    RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    lua_pushnumber(L, instance->relation);
    return 1;
}

static int RelationData_get_trustPositives(lua_State* L)
{
    RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    lua_pushnumber(L, instance->trustPositives);
    return 1;
}

static int RelationData_get_trustNegatives(lua_State* L)
{
    RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    lua_pushnumber(L, instance->trustNegatives);
    return 1;
}

static int RelationData_get_percievedStrength(lua_State* L)
{
    RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    lua_pushnumber(L, instance->percievedStrength);
    return 1;
}

static int RelationData_get_stateVariables(lua_State* L)
{
    RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    // TODO: Unsupported type for stateVariables (std::map<std::string, int, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, int>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'stateVariables' (type: std::map<std::string, int, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, int>, Ogre::GeneralAllocPolicy > >)");
}

// --- Setters for RelationData ---
static int RelationData_set_alliance(lua_State* L)
{
    RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    instance->alliance = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RelationData_set_peaceTreaty(lua_State* L)
{
    RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    instance->peaceTreaty = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RelationData_set_war(lua_State* L)
{
    RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    instance->war = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RelationData_set_coexists(lua_State* L)
{
    RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    instance->coexists = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RelationData_set_relation(lua_State* L)
{
    RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    instance->relation = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RelationData_set_trustPositives(lua_State* L)
{
    RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    instance->trustPositives = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RelationData_set_trustNegatives(lua_State* L)
{
    RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    instance->trustNegatives = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RelationData_set_percievedStrength(lua_State* L)
{
    RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    instance->percievedStrength = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RelationData_set_stateVariables(lua_State* L)
{
    RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for stateVariables");
}

int RelationDataBinding::_DESTRUCTOR(lua_State* L)
{
    RelationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RelationData is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 74: RelationData* _CONSTRUCTOR(...) - overloaded method
  line 76: RelationData* _CONSTRUCTOR(...) - overloaded method
  line 77: void save(...) - unsupported arg type
  line 78: void load(...) - unsupported arg type
  line 93: RelationData& operator=(...) - operator
*/

int RelationDataBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
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
        { "_DESTRUCTOR", RelationDataBinding::_DESTRUCTOR },
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
    lua_pushcfunction(L, RelationData_get_alliance);
    lua_setfield(L, -2, "alliance");
    lua_pushcfunction(L, RelationData_get_peaceTreaty);
    lua_setfield(L, -2, "peaceTreaty");
    lua_pushcfunction(L, RelationData_get_war);
    lua_setfield(L, -2, "war");
    lua_pushcfunction(L, RelationData_get_coexists);
    lua_setfield(L, -2, "coexists");
    lua_pushcfunction(L, RelationData_get_relation);
    lua_setfield(L, -2, "relation");
    lua_pushcfunction(L, RelationData_get_trustPositives);
    lua_setfield(L, -2, "trustPositives");
    lua_pushcfunction(L, RelationData_get_trustNegatives);
    lua_setfield(L, -2, "trustNegatives");
    lua_pushcfunction(L, RelationData_get_percievedStrength);
    lua_setfield(L, -2, "percievedStrength");
    lua_pushcfunction(L, RelationData_get_stateVariables);
    lua_setfield(L, -2, "stateVariables");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, RelationData_set_alliance);
    lua_setfield(L, -2, "alliance");
    lua_pushcfunction(L, RelationData_set_peaceTreaty);
    lua_setfield(L, -2, "peaceTreaty");
    lua_pushcfunction(L, RelationData_set_war);
    lua_setfield(L, -2, "war");
    lua_pushcfunction(L, RelationData_set_coexists);
    lua_setfield(L, -2, "coexists");
    lua_pushcfunction(L, RelationData_set_relation);
    lua_setfield(L, -2, "relation");
    lua_pushcfunction(L, RelationData_set_trustPositives);
    lua_setfield(L, -2, "trustPositives");
    lua_pushcfunction(L, RelationData_set_trustNegatives);
    lua_setfield(L, -2, "trustNegatives");
    lua_pushcfunction(L, RelationData_set_percievedStrength);
    lua_setfield(L, -2, "percievedStrength");
    lua_pushcfunction(L, RelationData_set_stateVariables);
    lua_setfield(L, -2, "stateVariables");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua