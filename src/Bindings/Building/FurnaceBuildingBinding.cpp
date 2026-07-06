#include "pch.h"
#include <kenshi/Building/FurnaceBuilding.h>
#include "FurnaceBuildingBinding.h"
#include "ProductionBuildingBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static FurnaceBuilding* getInstance(lua_State* L, int idx)
{
    return checkObject<FurnaceBuilding>(L, idx, FurnaceBuildingBinding::getMetatableName());
}

// --- Getters for FurnaceBuilding ---
static int FurnaceBuilding_get_active(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");
    lua_pushboolean(L, instance->active ? 1 : 0);
    return 1;
}

// --- Setters for FurnaceBuilding ---
static int FurnaceBuilding_set_active(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");
    instance->active = lua_toboolean(L, 2) != 0;
    return 0;
}

// --- Methods for FurnaceBuilding
int FurnaceBuildingBinding::createInventoryLayout(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");

    InventoryLayout* result = instance->createInventoryLayout();
    if (result) lua_pushlightuserdata(L, (void*)result); else lua_pushnil(L);
    return 1;
}

int FurnaceBuildingBinding::_NV_createInventoryLayout(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");

    InventoryLayout* result = instance->_NV_createInventoryLayout();
    if (result) lua_pushlightuserdata(L, (void*)result); else lua_pushnil(L);
    return 1;
}

int FurnaceBuildingBinding::setupFromData(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");

    instance->setupFromData();
    return 0;
}

int FurnaceBuildingBinding::_NV_setupFromData(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");

    instance->_NV_setupFromData();
    return 0;
}

int FurnaceBuildingBinding::getInputValueTotal(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");

    float result = instance->getInputValueTotal();
    lua_pushnumber(L, result);
    return 1;
}

int FurnaceBuildingBinding::getDefaultTask(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");

    TaskType result = instance->getDefaultTask();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int FurnaceBuildingBinding::_NV_getDefaultTask(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");

    TaskType result = instance->_NV_getDefaultTask();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int FurnaceBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int FurnaceBuildingBinding::updateInputs(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    instance->updateInputs(rate);
    return 0;
}

int FurnaceBuildingBinding::_NV_updateInputs(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    instance->_NV_updateInputs(rate);
    return 0;
}

int FurnaceBuildingBinding::updateOutput(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    instance->updateOutput(rate);
    return 0;
}

int FurnaceBuildingBinding::_NV_updateOutput(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    instance->_NV_updateOutput(rate);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 29: void getGUIData(...) - unsupported arg type
  line 30: void _NV_getGUIData(...) - unsupported arg type
  line 32: float getInputValue(...) - unsupported arg type
  line 33: float _NV_getInputValue(...) - unsupported arg type
  line 36: void getResourcesNeededBecauseNotFull(...) - unsupported arg type
  line 37: void _NV_getResourcesNeededBecauseNotFull(...) - unsupported arg type
  line 38: void getResourcesNeededBecauseEmpty(...) - unsupported arg type
  line 39: void _NV_getResourcesNeededBecauseEmpty(...) - unsupported arg type
  line 40: bool canHaveSomeOfThese(...) - unsupported arg type
  line 41: bool _NV_canHaveSomeOfThese(...) - unsupported arg type
  line 42: void incinerate(...) - unsupported arg type
  line 45: FurnaceBuilding* _CONSTRUCTOR(...) - unsupported arg type
  line 48: void operate(...) - unsupported arg type
  line 49: void _NV_operate(...) - unsupported arg type
  line 54: bool limitInputsOutputRate(...) - non-string reference arg
  line 55: bool _NV_limitInputsOutputRate(...) - non-string reference arg
  line 56: float getIronAmountInItem(...) - unsupported arg type
*/

int FurnaceBuildingBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int FurnaceBuildingBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FurnaceBuilding object");
    return 1;
}

void FurnaceBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FurnaceBuildingBinding::gc },
        { "__tostring", FurnaceBuildingBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "createInventoryLayout", FurnaceBuildingBinding::createInventoryLayout },
        { "_NV_createInventoryLayout", FurnaceBuildingBinding::_NV_createInventoryLayout },
        { "setupFromData", FurnaceBuildingBinding::setupFromData },
        { "_NV_setupFromData", FurnaceBuildingBinding::_NV_setupFromData },
        { "getInputValueTotal", FurnaceBuildingBinding::getInputValueTotal },
        { "getDefaultTask", FurnaceBuildingBinding::getDefaultTask },
        { "_NV_getDefaultTask", FurnaceBuildingBinding::_NV_getDefaultTask },
        { "_DESTRUCTOR", FurnaceBuildingBinding::_DESTRUCTOR },
        { "updateInputs", FurnaceBuildingBinding::updateInputs },
        { "_NV_updateInputs", FurnaceBuildingBinding::_NV_updateInputs },
        { "updateOutput", FurnaceBuildingBinding::updateOutput },
        { "_NV_updateOutput", FurnaceBuildingBinding::_NV_updateOutput },
        { 0, 0 }
    };

    registerClass(
        L, 
        FurnaceBuildingBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FurnaceBuildingBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, FurnaceBuilding_get_active);
    lua_setfield(L, -2, "active");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, FurnaceBuilding_set_active);
    lua_setfield(L, -2, "active");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ProductionBuilding
    setMetatableParent(L, FurnaceBuildingBinding::getMetatableName(), ProductionBuildingBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua