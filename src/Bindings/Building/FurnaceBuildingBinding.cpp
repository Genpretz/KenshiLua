#include "pch.h"
#include <kenshi/Building/FurnaceBuilding.h>
#include "FurnaceBuildingBinding.h"
#include "ProductionBuildingBinding.h"
#include "Bindings/Gui/InventoryLayoutBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/Gui/DataPanelLineBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/Util/LektorBinding.h"
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
    return pushObject<InventoryLayout>(L, result, InventoryLayoutBinding::getMetatableName());
}

int FurnaceBuildingBinding::_NV_createInventoryLayout(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");

    InventoryLayout* result = instance->_NV_createInventoryLayout();
    return pushObject<InventoryLayout>(L, result, InventoryLayoutBinding::getMetatableName());
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

int FurnaceBuildingBinding::limitInputsOutputRate(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    bool result = instance->limitInputsOutputRate(rate);
    lua_pushboolean(L, result ? 1 : 0);
    lua_pushnumber(L, rate);
    return 2;
}

int FurnaceBuildingBinding::_NV_limitInputsOutputRate(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    bool result = instance->_NV_limitInputsOutputRate(rate);
    lua_pushboolean(L, result ? 1 : 0);
    lua_pushnumber(L, rate);
    return 2;
}

int FurnaceBuildingBinding::getGUIData(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");
    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIData(datapanel, category);
    return 0;
}

int FurnaceBuildingBinding::_NV_getGUIData(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");
    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIData(datapanel, category);
    return 0;
}

int FurnaceBuildingBinding::getInputValue(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    float result = instance->getInputValue(item);
    lua_pushnumber(L, result);
    return 1;
}

int FurnaceBuildingBinding::_NV_getInputValue(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    float result = instance->_NV_getInputValue(item);
    lua_pushnumber(L, result);
    return 1;
}

int FurnaceBuildingBinding::getResourcesNeededBecauseNotFull(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");
    lektor<GameData*>* out = LektorPtrBinding<GameData*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to getResourcesNeededBecauseNotFull must be lektor<GameData*>");
    instance->getResourcesNeededBecauseNotFull(*out);
    return 0;
}

int FurnaceBuildingBinding::_NV_getResourcesNeededBecauseNotFull(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");
    lektor<GameData*>* out = LektorPtrBinding<GameData*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to _NV_getResourcesNeededBecauseNotFull must be lektor<GameData*>");
    instance->_NV_getResourcesNeededBecauseNotFull(*out);
    return 0;
}

int FurnaceBuildingBinding::getResourcesNeededBecauseEmpty(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");
    lektor<GameData*>* out = LektorPtrBinding<GameData*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to getResourcesNeededBecauseEmpty must be lektor<GameData*>");
    instance->getResourcesNeededBecauseEmpty(*out);
    return 0;
}

int FurnaceBuildingBinding::_NV_getResourcesNeededBecauseEmpty(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");
    lektor<GameData*>* out = LektorPtrBinding<GameData*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to _NV_getResourcesNeededBecauseEmpty must be lektor<GameData*>");
    instance->_NV_getResourcesNeededBecauseEmpty(*out);
    return 0;
}

int FurnaceBuildingBinding::canHaveSomeOfThese(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");
    GameData* input = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->canHaveSomeOfThese(input);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FurnaceBuildingBinding::_NV_canHaveSomeOfThese(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");
    GameData* input = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->_NV_canHaveSomeOfThese(input);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FurnaceBuildingBinding::incinerate(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");
    DataPanelLine* line = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->incinerate(line);
    return 0;
}

int FurnaceBuildingBinding::operate(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");
    Character* stats = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float amount = (float)luaL_checknumber(L, 3);
    instance->operate(stats, amount);
    return 0;
}

int FurnaceBuildingBinding::_NV_operate(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");
    Character* stats = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float amount = (float)luaL_checknumber(L, 3);
    instance->_NV_operate(stats, amount);
    return 0;
}

int FurnaceBuildingBinding::getIronAmountInItem(lua_State* L)
{
    FurnaceBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceBuilding is nil");
    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    float result = instance->getIronAmountInItem(data);
    lua_pushnumber(L, result);
    return 1;
}

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
        { "updateInputs", FurnaceBuildingBinding::updateInputs },
        { "_NV_updateInputs", FurnaceBuildingBinding::_NV_updateInputs },
        { "updateOutput", FurnaceBuildingBinding::updateOutput },
        { "_NV_updateOutput", FurnaceBuildingBinding::_NV_updateOutput },
        { "limitInputsOutputRate", FurnaceBuildingBinding::limitInputsOutputRate },
        { "_NV_limitInputsOutputRate", FurnaceBuildingBinding::_NV_limitInputsOutputRate },
        { "getGUIData", FurnaceBuildingBinding::getGUIData },
        { "_NV_getGUIData", FurnaceBuildingBinding::_NV_getGUIData },
        { "getInputValue", FurnaceBuildingBinding::getInputValue },
        { "_NV_getInputValue", FurnaceBuildingBinding::_NV_getInputValue },
        { "getResourcesNeededBecauseNotFull", FurnaceBuildingBinding::getResourcesNeededBecauseNotFull },
        { "_NV_getResourcesNeededBecauseNotFull", FurnaceBuildingBinding::_NV_getResourcesNeededBecauseNotFull },
        { "getResourcesNeededBecauseEmpty", FurnaceBuildingBinding::getResourcesNeededBecauseEmpty },
        { "_NV_getResourcesNeededBecauseEmpty", FurnaceBuildingBinding::_NV_getResourcesNeededBecauseEmpty },
        { "canHaveSomeOfThese", FurnaceBuildingBinding::canHaveSomeOfThese },
        { "_NV_canHaveSomeOfThese", FurnaceBuildingBinding::_NV_canHaveSomeOfThese },
        { "incinerate", FurnaceBuildingBinding::incinerate },
        { "operate", FurnaceBuildingBinding::operate },
        { "_NV_operate", FurnaceBuildingBinding::_NV_operate },
        { "getIronAmountInItem", FurnaceBuildingBinding::getIronAmountInItem },
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
    registerGetter(L, "active", FurnaceBuilding_get_active);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "active", FurnaceBuilding_set_active);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ProductionBuilding
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, FurnaceBuildingBinding::getMetatableName(), ProductionBuildingBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
