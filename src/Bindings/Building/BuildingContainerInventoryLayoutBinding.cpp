#include "pch.h"
#include <kenshi/Building/StorageBuilding.h>
#include "BuildingContainerInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/GenericInventoryLayoutBinding.h"

namespace KenshiLua
{

static BuildingContainerInventoryLayout* getInstance(lua_State* L, int idx)
{
    return checkObject<BuildingContainerInventoryLayout>(L, idx, BuildingContainerInventoryLayoutBinding::getMetatableName());
}

// --- Getters for BuildingContainerInventoryLayout ---
static int BuildingContainerInventoryLayout_get_capacityText(lua_State* L)
{
    BuildingContainerInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildingContainerInventoryLayout is nil");
    lua_pushlightuserdata(L, (void*)instance->capacityText);
    return 1;
}

// --- Setters for BuildingContainerInventoryLayout ---
static int BuildingContainerInventoryLayout_set_capacityText(lua_State* L)
{
    BuildingContainerInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildingContainerInventoryLayout is nil");
    return luaL_error(L, "Read-only or unsupported setter type for capacityText");
}

int BuildingContainerInventoryLayoutBinding::_CONSTRUCTOR(lua_State* L)
{
    BuildingContainerInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildingContainerInventoryLayout is nil");

    BuildingContainerInventoryLayout* result = instance->_CONSTRUCTOR();
    return pushObject<BuildingContainerInventoryLayout>(L, result, BuildingContainerInventoryLayoutBinding::getMetatableName());
}

int BuildingContainerInventoryLayoutBinding::setCapacity(lua_State* L)
{
    BuildingContainerInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildingContainerInventoryLayout is nil");

    int value = (int)luaL_checkinteger(L, 2);
    bool full = lua_toboolean(L, 3) != 0;
    instance->setCapacity(value, full);
    return 0;
}

int BuildingContainerInventoryLayoutBinding::_DESTRUCTOR(lua_State* L)
{
    BuildingContainerInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildingContainerInventoryLayout is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 16: void setupSections(...) - unsupported arg type
  line 17: void _NV_setupSections(...) - unsupported arg type
*/

int BuildingContainerInventoryLayoutBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int BuildingContainerInventoryLayoutBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.BuildingContainerInventoryLayout object");
    return 1;
}

void BuildingContainerInventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BuildingContainerInventoryLayoutBinding::gc },
        { "__tostring", BuildingContainerInventoryLayoutBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", BuildingContainerInventoryLayoutBinding::_CONSTRUCTOR },
        { "setCapacity", BuildingContainerInventoryLayoutBinding::setCapacity },
        { "_DESTRUCTOR", BuildingContainerInventoryLayoutBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        BuildingContainerInventoryLayoutBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, BuildingContainerInventoryLayoutBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, BuildingContainerInventoryLayout_get_capacityText);
    lua_setfield(L, -2, "capacityText");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, BuildingContainerInventoryLayout_set_capacityText);
    lua_setfield(L, -2, "capacityText");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to GenericInventoryLayout
    // setMetatableParent(L, BuildingContainerInventoryLayoutBinding::getMetatableName(), GenericInventoryLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
