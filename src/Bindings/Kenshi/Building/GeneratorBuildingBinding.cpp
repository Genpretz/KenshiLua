#include "pch.h"
#include <kenshi/Building/GeneratorBuilding.h>
#include "GeneratorBuildingBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Building/ProductionBuildingBinding.h"
#include "Bindings/Kenshi/Gui/DatapanelGUIBinding.h"
#include "Bindings/Kenshi/ItemBinding.h"

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

int GeneratorBuildingBinding::getGUIState(lua_State* L)
{
    GeneratorBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GeneratorBuilding is nil");
    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIState(datapanel, category);
    return 0;
}

int GeneratorBuildingBinding::_NV_getGUIState(lua_State* L)
{
    GeneratorBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GeneratorBuilding is nil");
    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIState(datapanel, category);
    return 0;
}

int GeneratorBuildingBinding::getInputValue(lua_State* L)
{
    GeneratorBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GeneratorBuilding is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    float result = instance->getInputValue(item);
    lua_pushnumber(L, result);
    return 1;
}

int GeneratorBuildingBinding::_NV_getInputValue(lua_State* L)
{
    GeneratorBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GeneratorBuilding is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    float result = instance->_NV_getInputValue(item);
    lua_pushnumber(L, result);
    return 1;
}

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
        { "getGUIState", GeneratorBuildingBinding::getGUIState },
        { "_NV_getGUIState", GeneratorBuildingBinding::_NV_getGUIState },
        { "getInputValue", GeneratorBuildingBinding::getInputValue },
        { "_NV_getInputValue", GeneratorBuildingBinding::_NV_getInputValue },
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
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, GeneratorBuildingBinding::getMetatableName(), ProductionBuildingBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua