#include "pch.h"
#include "kenshi\gui\SquadManagementScreen.h"
#include "SquadDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/ActivePlatoonBinding.h"

namespace KenshiLua
{

typedef SquadManagementScreen::SquadData SquadData;

static SquadData* getInstance(lua_State* L, int idx)
{
    return checkObject<SquadData>(L, idx, SquadDataBinding::getMetatableName());
}

// --- Getters for SquadData ---
static int SquadData_get_platoon(lua_State* L)
{
    SquadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadData is nil");
    return pushObject<ActivePlatoon>(L, instance->platoon, ActivePlatoonBinding::getMetatableName());
}

// --- Setters for SquadData ---
static int SquadData_set_platoon(lua_State* L)
{
    SquadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadData is nil");
    instance->platoon = lua_isnoneornil(L, 2) ? nullptr : checkObject<ActivePlatoon>(L, 2, ActivePlatoonBinding::getMetatableName());
    return 0;
}

int SquadDataBinding::_CONSTRUCTOR(lua_State* L)
{
    SquadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadData is nil");

    ActivePlatoon* platoon = checkObject<ActivePlatoon>(L, 2, ActivePlatoonBinding::getMetatableName());
    SquadData* result = instance->_CONSTRUCTOR(platoon);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int SquadDataBinding::_DESTRUCTOR(lua_State* L)
{
    SquadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadData is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int SquadDataBinding::setName(lua_State* L)
{
    SquadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadData is nil");

    const std::string name = luaL_checkstring(L, 2);
    instance->setName(name);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 157: const std::string& getName(...) - reference return type
*/

int SquadDataBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int SquadDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.SquadData object");
    return 1;
}

void SquadDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SquadDataBinding::gc },
        { "__tostring", SquadDataBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", SquadDataBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", SquadDataBinding::_DESTRUCTOR },
        { "setName", SquadDataBinding::setName },
        { 0, 0 }
    };

    registerClass(
        L, 
        SquadDataBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SquadDataBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "platoon", SquadData_get_platoon);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "platoon", SquadData_set_platoon);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua