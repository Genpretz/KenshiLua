#include "pch.h"
#include <kenshi/Building/GeneratorBuilding.h>
#include "WindGeneratorBuildingBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/GeneratorBuildingBinding.h"

namespace KenshiLua
{

static WindGeneratorBuilding* getInstance(lua_State* L, int idx)
{
    return checkObject<WindGeneratorBuilding>(L, idx, WindGeneratorBuildingBinding::getMetatableName());
}

// --- Getters for WindGeneratorBuilding ---
// --- Setters for WindGeneratorBuilding ---
int WindGeneratorBuildingBinding::getPowerOutput(lua_State* L)
{
    WindGeneratorBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WindGeneratorBuilding is nil");

    float result = instance->getPowerOutput();
    lua_pushnumber(L, result);
    return 1;
}

int WindGeneratorBuildingBinding::_NV_getPowerOutput(lua_State* L)
{
    WindGeneratorBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WindGeneratorBuilding is nil");

    float result = instance->_NV_getPowerOutput();
    lua_pushnumber(L, result);
    return 1;
}

int WindGeneratorBuildingBinding::getSoundIntensity(lua_State* L)
{
    WindGeneratorBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WindGeneratorBuilding is nil");

    float result = instance->getSoundIntensity();
    lua_pushnumber(L, result);
    return 1;
}

int WindGeneratorBuildingBinding::_NV_getSoundIntensity(lua_State* L)
{
    WindGeneratorBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WindGeneratorBuilding is nil");

    float result = instance->_NV_getSoundIntensity();
    lua_pushnumber(L, result);
    return 1;
}

int WindGeneratorBuildingBinding::isAnyInputsEmpty(lua_State* L)
{
    WindGeneratorBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WindGeneratorBuilding is nil");

    bool result = instance->isAnyInputsEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WindGeneratorBuildingBinding::_NV_isAnyInputsEmpty(lua_State* L)
{
    WindGeneratorBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WindGeneratorBuilding is nil");

    bool result = instance->_NV_isAnyInputsEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WindGeneratorBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    WindGeneratorBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WindGeneratorBuilding is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 32: WindGeneratorBuilding* _CONSTRUCTOR(...) - unsupported arg type
  line 35: void getGUIState(...) - unsupported arg type
  line 36: void _NV_getGUIState(...) - unsupported arg type
  line 37: void getGUIPower(...) - unsupported arg type
  line 38: void _NV_getGUIPower(...) - unsupported arg type
*/

int WindGeneratorBuildingBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int WindGeneratorBuildingBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.WindGeneratorBuilding object");
    return 1;
}

void WindGeneratorBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       WindGeneratorBuildingBinding::gc },
        { "__tostring", WindGeneratorBuildingBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getPowerOutput", WindGeneratorBuildingBinding::getPowerOutput },
        { "_NV_getPowerOutput", WindGeneratorBuildingBinding::_NV_getPowerOutput },
        { "getSoundIntensity", WindGeneratorBuildingBinding::getSoundIntensity },
        { "_NV_getSoundIntensity", WindGeneratorBuildingBinding::_NV_getSoundIntensity },
        { "isAnyInputsEmpty", WindGeneratorBuildingBinding::isAnyInputsEmpty },
        { "_NV_isAnyInputsEmpty", WindGeneratorBuildingBinding::_NV_isAnyInputsEmpty },
        { "_DESTRUCTOR", WindGeneratorBuildingBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        WindGeneratorBuildingBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, WindGeneratorBuildingBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to GeneratorBuilding
    // setMetatableParent(L, WindGeneratorBuildingBinding::getMetatableName(), GeneratorBuildingBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
