#include "pch.h"
#include <kenshi/Building/ResearchBuilding.h>
#include "ResearchBuildingBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/UseableStuffBinding.h"

namespace KenshiLua
{

static ResearchBuilding* getInstance(lua_State* L, int idx)
{
    return checkObject<ResearchBuilding>(L, idx, ResearchBuildingBinding::getMetatableName());
}

// --- Getters for ResearchBuilding ---
// --- Setters for ResearchBuilding ---
int ResearchBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    ResearchBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchBuilding is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ResearchBuildingBinding::dontNeedWorkRightNow(lua_State* L)
{
    ResearchBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchBuilding is nil");

    bool result = instance->dontNeedWorkRightNow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ResearchBuildingBinding::_NV_dontNeedWorkRightNow(lua_State* L)
{
    ResearchBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchBuilding is nil");

    bool result = instance->_NV_dontNeedWorkRightNow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ResearchBuildingBinding::getDefaultTask(lua_State* L)
{
    ResearchBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchBuilding is nil");

    TaskType result = instance->getDefaultTask();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ResearchBuildingBinding::_NV_getDefaultTask(lua_State* L)
{
    ResearchBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchBuilding is nil");

    TaskType result = instance->_NV_getDefaultTask();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ResearchBuildingBinding::update(lua_State* L)
{
    ResearchBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchBuilding is nil");

    instance->update();
    return 0;
}

int ResearchBuildingBinding::_NV_update(lua_State* L)
{
    ResearchBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchBuilding is nil");

    instance->_NV_update();
    return 0;
}

int ResearchBuildingBinding::notifyConstructionComplete(lua_State* L)
{
    ResearchBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchBuilding is nil");

    instance->notifyConstructionComplete();
    return 0;
}

int ResearchBuildingBinding::_NV_notifyConstructionComplete(lua_State* L)
{
    ResearchBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchBuilding is nil");

    instance->_NV_notifyConstructionComplete();
    return 0;
}

int ResearchBuildingBinding::getTechLevel(lua_State* L)
{
    ResearchBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchBuilding is nil");

    int result = instance->getTechLevel();
    lua_pushinteger(L, result);
    return 1;
}

int ResearchBuildingBinding::_NV_getTechLevel(lua_State* L)
{
    ResearchBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchBuilding is nil");

    int result = instance->_NV_getTechLevel();
    lua_pushinteger(L, result);
    return 1;
}

int ResearchBuildingBinding::createInventoryLayout(lua_State* L)
{
    ResearchBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchBuilding is nil");

    InventoryLayout* result = instance->createInventoryLayout();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ResearchBuildingBinding::_NV_createInventoryLayout(lua_State* L)
{
    ResearchBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchBuilding is nil");

    InventoryLayout* result = instance->_NV_createInventoryLayout();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 31: ResearchBuilding* _CONSTRUCTOR(...) - unsupported arg type
  line 40: void operate(...) - unsupported arg type
  line 41: void _NV_operate(...) - unsupported arg type
  line 44: void getGUIData(...) - unsupported arg type
  line 45: void _NV_getGUIData(...) - unsupported arg type
  line 50: void showResearchWindow(...) - unsupported arg type
*/

int ResearchBuildingBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ResearchBuildingBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ResearchBuilding object");
    return 1;
}

void ResearchBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ResearchBuildingBinding::gc },
        { "__tostring", ResearchBuildingBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", ResearchBuildingBinding::_DESTRUCTOR },
        { "dontNeedWorkRightNow", ResearchBuildingBinding::dontNeedWorkRightNow },
        { "_NV_dontNeedWorkRightNow", ResearchBuildingBinding::_NV_dontNeedWorkRightNow },
        { "getDefaultTask", ResearchBuildingBinding::getDefaultTask },
        { "_NV_getDefaultTask", ResearchBuildingBinding::_NV_getDefaultTask },
        { "update", ResearchBuildingBinding::update },
        { "_NV_update", ResearchBuildingBinding::_NV_update },
        { "notifyConstructionComplete", ResearchBuildingBinding::notifyConstructionComplete },
        { "_NV_notifyConstructionComplete", ResearchBuildingBinding::_NV_notifyConstructionComplete },
        { "getTechLevel", ResearchBuildingBinding::getTechLevel },
        { "_NV_getTechLevel", ResearchBuildingBinding::_NV_getTechLevel },
        { "createInventoryLayout", ResearchBuildingBinding::createInventoryLayout },
        { "_NV_createInventoryLayout", ResearchBuildingBinding::_NV_createInventoryLayout },
        { 0, 0 }
    };

    registerClass(
        L, 
        ResearchBuildingBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ResearchBuildingBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to UseableStuff
    // setMetatableParent(L, ResearchBuildingBinding::getMetatableName(), UseableStuffBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
