#include "pch.h"
#include <kenshi/Building/TortureBuilding.h>
#include "TortureBuildingBinding.h"
#include "ProductionBuildingBinding.h"
#include "StorageBuildingBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static TortureBuilding* getInstance(lua_State* L, int idx)
{
    return checkObject<TortureBuilding>(L, idx, TortureBuildingBinding::getMetatableName());
}

// --- Getters for TortureBuilding ---
static int TortureBuilding_get_timer(lua_State* L)
{
    TortureBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TortureBuilding is nil");
    lua_pushnumber(L, instance->timer);
    return 1;
}

// --- Setters for TortureBuilding ---
static int TortureBuilding_set_timer(lua_State* L)
{
    TortureBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TortureBuilding is nil");
    instance->timer = (float)luaL_checknumber(L, 2);
    return 0;
}

// --- Methods for TortureBuilding ---
int TortureBuildingBinding::getFunctionStuff(lua_State* L)
{
    TortureBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TortureBuilding is nil");

    StorageBuilding* result = instance->getFunctionStuff();
    return pushObject<StorageBuilding>(L, result, StorageBuildingBinding::getMetatableName());
}

int TortureBuildingBinding::_NV_getFunctionStuff(lua_State* L)
{
    TortureBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TortureBuilding is nil");

    StorageBuilding* result = instance->_NV_getFunctionStuff();
    return pushObject<StorageBuilding>(L, result, StorageBuildingBinding::getMetatableName());
}

int TortureBuildingBinding::update(lua_State* L)
{
    TortureBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TortureBuilding is nil");

    instance->update();
    return 0;
}

int TortureBuildingBinding::_NV_update(lua_State* L)
{
    TortureBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TortureBuilding is nil");

    instance->_NV_update();
    return 0;
}

int TortureBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    TortureBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TortureBuilding is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 11: TortureBuilding* _CONSTRUCTOR(...) - unsupported arg type
*/

int TortureBuildingBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TortureBuildingBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TortureBuilding object");
    return 1;
}

void TortureBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TortureBuildingBinding::gc },
        { "__tostring", TortureBuildingBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getFunctionStuff", TortureBuildingBinding::getFunctionStuff },
        { "_NV_getFunctionStuff", TortureBuildingBinding::_NV_getFunctionStuff },
        { "update", TortureBuildingBinding::update },
        { "_NV_update", TortureBuildingBinding::_NV_update },
        { "_DESTRUCTOR", TortureBuildingBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        TortureBuildingBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TortureBuildingBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, TortureBuilding_get_timer);
    lua_setfield(L, -2, "timer");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, TortureBuilding_set_timer);
    lua_setfield(L, -2, "timer");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ProductionBuilding
    // setMetatableParent(L, TortureBuildingBinding::getMetatableName(), ProductionBuildingBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
