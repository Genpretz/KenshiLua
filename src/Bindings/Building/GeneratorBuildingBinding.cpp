#include "pch.h"
#include <kenshi/Building/GeneratorBuilding.h>
#include "GeneratorBuildingBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/ProductionBuildingBinding.h"

namespace KenshiLua
{

static GeneratorBuilding* getInstance(lua_State* L, int idx)
{
    return checkObject<GeneratorBuilding>(L, idx, GeneratorBuildingBinding::getMetatableName());
}

// --- Getters for GeneratorBuilding ---
// --- Setters for GeneratorBuilding ---
int GeneratorBuildingBinding::getPowerOutput(lua_State* L)
{
    GeneratorBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GeneratorBuilding is nil");

    float result = instance->getPowerOutput();
    lua_pushnumber(L, result);
    return 1;
}

int GeneratorBuildingBinding::_NV_getPowerOutput(lua_State* L)
{
    GeneratorBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GeneratorBuilding is nil");

    float result = instance->_NV_getPowerOutput();
    lua_pushnumber(L, result);
    return 1;
}

int GeneratorBuildingBinding::getFuelConsumptionRate(lua_State* L)
{
    GeneratorBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GeneratorBuilding is nil");

    float result = instance->getFuelConsumptionRate();
    lua_pushnumber(L, result);
    return 1;
}

int GeneratorBuildingBinding::_NV_getFuelConsumptionRate(lua_State* L)
{
    GeneratorBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GeneratorBuilding is nil");

    float result = instance->_NV_getFuelConsumptionRate();
    lua_pushnumber(L, result);
    return 1;
}

int GeneratorBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    GeneratorBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GeneratorBuilding is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 11: GeneratorBuilding* _CONSTRUCTOR(...) - unsupported arg type
  line 14: void getGUIState(...) - unsupported arg type
  line 15: void _NV_getGUIState(...) - unsupported arg type
  line 16: float getInputValue(...) - unsupported arg type
  line 17: float _NV_getInputValue(...) - unsupported arg type
*/

int GeneratorBuildingBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int GeneratorBuildingBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.GeneratorBuilding object");
    return 1;
}

void GeneratorBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GeneratorBuildingBinding::gc },
        { "__tostring", GeneratorBuildingBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getPowerOutput", GeneratorBuildingBinding::getPowerOutput },
        { "_NV_getPowerOutput", GeneratorBuildingBinding::_NV_getPowerOutput },
        { "getFuelConsumptionRate", GeneratorBuildingBinding::getFuelConsumptionRate },
        { "_NV_getFuelConsumptionRate", GeneratorBuildingBinding::_NV_getFuelConsumptionRate },
        { "_DESTRUCTOR", GeneratorBuildingBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        GeneratorBuildingBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, GeneratorBuildingBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ProductionBuilding
    // setMetatableParent(L, GeneratorBuildingBinding::getMetatableName(), ProductionBuildingBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
