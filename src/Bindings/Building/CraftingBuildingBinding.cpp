#include "pch.h"
class CraftingItem {};
#include <kenshi/Building/CraftingBuilding.h>
#include "CraftingBuildingBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/Building/ProductionBuildingBinding.h"
#include "Bindings/Util/HandBinding.h"

namespace KenshiLua
{

static CraftingBuilding* getInstance(lua_State* L, int idx)
{
    return checkObject<CraftingBuilding>(L, idx, CraftingBuildingBinding::getMetatableName());
}

// --- Getters for CraftingBuilding ---
static int CraftingBuilding_get_maxCraftLevel(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    lua_pushinteger(L, instance->maxCraftLevel);
    return 1;
}

static int CraftingBuilding_get_crafting(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    // TODO: Unsupported type for crafting (std::deque<CraftingItem, std::allocator<CraftingItem> >)
    return luaL_error(L, "Unsupported property 'crafting' (type: std::deque<CraftingItem, std::allocator<CraftingItem> >)");
}

static int CraftingBuilding_get_specialCraftItemType(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    lua_pushinteger(L, (lua_Integer)instance->specialCraftItemType);
    return 1;
}

static int CraftingBuilding_get_repeat(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    lua_pushboolean(L, instance->repeat ? 1 : 0);
    return 1;
}

static int CraftingBuilding_get_whosCrafting(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    return handBinding::push(L, instance->whosCrafting);
}

static int CraftingBuilding_get_itemCrafted(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    lua_pushboolean(L, instance->itemCrafted ? 1 : 0);
    return 1;
}

static int CraftingBuilding_get_failiureNotified(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    lua_pushboolean(L, instance->failiureNotified ? 1 : 0);
    return 1;
}

static int CraftingBuilding_get_biggestCraftableItem(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    return pushObject<GameData>(L, instance->biggestCraftableItem, GameDataBinding::getMetatableName());
}

static int CraftingBuilding_get_outItem(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    return pushObject<Item>(L, instance->outItem, ItemBinding::getMetatableName());
}

static int CraftingBuilding_get_inItems(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    lua_createtable(L, instance->inItems.size(), 0);
    for (uint32_t i = 0; i < instance->inItems.size(); ++i) {
        pushObject<Item>(L, instance->inItems[i], ItemBinding::getMetatableName());
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

static int CraftingBuilding_get_partialItems(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    // TODO: Unsupported type for partialItems (ogre_unordered_map<GameData*, float>::type)
    return luaL_error(L, "Unsupported property 'partialItems' (type: ogre_unordered_map<GameData*, float>::type)");
}

// --- Setters for CraftingBuilding ---
static int CraftingBuilding_set_maxCraftLevel(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    instance->maxCraftLevel = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CraftingBuilding_set_crafting(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for crafting");
}

static int CraftingBuilding_set_specialCraftItemType(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    instance->specialCraftItemType = (itemType)luaL_checkinteger(L, 2);
    return 0;
}

static int CraftingBuilding_set_repeat(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    instance->repeat = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CraftingBuilding_set_whosCrafting(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    instance->whosCrafting = *val;
    return 0;
}

static int CraftingBuilding_set_itemCrafted(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    instance->itemCrafted = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CraftingBuilding_set_failiureNotified(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    instance->failiureNotified = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CraftingBuilding_set_biggestCraftableItem(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for biggestCraftableItem");
}

static int CraftingBuilding_set_outItem(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for outItem");
}

static int CraftingBuilding_set_inItems(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for inItems");
}

static int CraftingBuilding_set_partialItems(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for partialItems");
}

int CraftingBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int CraftingBuildingBinding::createInventoryLayout(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    InventoryLayout* result = instance->createInventoryLayout();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int CraftingBuildingBinding::_NV_createInventoryLayout(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    InventoryLayout* result = instance->_NV_createInventoryLayout();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int CraftingBuildingBinding::update(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    instance->update();
    return 0;
}

int CraftingBuildingBinding::_NV_update(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    instance->_NV_update();
    return 0;
}

int CraftingBuildingBinding::givePower(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    float amount = (float)luaL_checknumber(L, 2);
    instance->givePower(amount);
    return 0;
}

int CraftingBuildingBinding::_NV_givePower(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    float amount = (float)luaL_checknumber(L, 2);
    instance->_NV_givePower(amount);
    return 0;
}

int CraftingBuildingBinding::hasCraftingQueued(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    bool result = instance->hasCraftingQueued();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CraftingBuildingBinding::_NV_hasCraftingQueued(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    bool result = instance->_NV_hasCraftingQueued();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CraftingBuildingBinding::isProductionFull(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    bool result = instance->isProductionFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CraftingBuildingBinding::_NV_isProductionFull(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    bool result = instance->_NV_isProductionFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CraftingBuildingBinding::getProductionItemData(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    GameData* result = instance->getProductionItemData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int CraftingBuildingBinding::_NV_getProductionItemData(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    GameData* result = instance->_NV_getProductionItemData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int CraftingBuildingBinding::getCurrentProductionQuantity(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    int result = instance->getCurrentProductionQuantity();
    lua_pushinteger(L, result);
    return 1;
}

int CraftingBuildingBinding::_NV_getCurrentProductionQuantity(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    int result = instance->_NV_getCurrentProductionQuantity();
    lua_pushinteger(L, result);
    return 1;
}

int CraftingBuildingBinding::isAnyInputsInvalidType(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    bool result = instance->isAnyInputsInvalidType();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CraftingBuildingBinding::_NV_isAnyInputsInvalidType(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    bool result = instance->_NV_isAnyInputsInvalidType();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CraftingBuildingBinding::notifyCraftFailiure(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    instance->notifyCraftFailiure();
    return 0;
}

int CraftingBuildingBinding::_removeCraft(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    int index = (int)luaL_checkinteger(L, 2);
    instance->_removeCraft(index);
    return 0;
}

int CraftingBuildingBinding::getCraft(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    int id = (int)luaL_checkinteger(L, 2);
    CraftingItem* result = instance->getCraft(id);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int CraftingBuildingBinding::destroyProductionItem(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    instance->destroyProductionItem();
    return 0;
}

int CraftingBuildingBinding::getCriticalSuccessWeapon(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    int normalWeaponLevel = (int)luaL_checkinteger(L, 2);
    GameData* result = instance->getCriticalSuccessWeapon(normalWeaponLevel);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int CraftingBuildingBinding::setupFromData(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    instance->setupFromData();
    return 0;
}

int CraftingBuildingBinding::_NV_setupFromData(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    instance->_NV_setupFromData();
    return 0;
}

int CraftingBuildingBinding::updateOutput(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    instance->updateOutput(rate);
    return 0;
}

int CraftingBuildingBinding::_NV_updateOutput(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    instance->_NV_updateOutput(rate);
    return 0;
}

int CraftingBuildingBinding::updateInventoryWindow(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    instance->updateInventoryWindow();
    return 0;
}

int CraftingBuildingBinding::_NV_updateInventoryWindow(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    instance->_NV_updateInventoryWindow();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 50: CraftingBuilding* _CONSTRUCTOR(...) - unsupported arg type
  line 57: void operate(...) - unsupported arg type
  line 58: void _NV_operate(...) - unsupported arg type
  line 61: void getGUIData(...) - unsupported arg type
  line 62: void _NV_getGUIData(...) - unsupported arg type
  line 63: GameSaveState serialise(...) - unsupported return type
  line 64: GameSaveState _NV_serialise(...) - unsupported return type
  line 65: void loadFromSerialise(...) - unsupported arg type
  line 66: void _NV_loadFromSerialise(...) - unsupported arg type
  line 77: void newCraftingButton(...) - unsupported arg type
  line 78: void _NV_newCraftingButton(...) - unsupported arg type
  line 79: void addFinishedCraftItem(...) - unsupported arg type
  line 81: bool tryOperate(...) - unsupported arg type
  line 82: bool _NV_tryOperate(...) - unsupported arg type
  line 83: GameData* playerManufacturerData(...) - static method
  line 84: void getAvailableCrafts(...) - unsupported arg type
  line 85: CraftingItem* _addCraft(...) - unsupported arg type
  line 96: GameData* predictCraftersBestWeapon(...) - unsupported arg type
  line 97: float calculateCriticalChance(...) - unsupported arg type
  line 99: void getItemsWeWantRidOf(...) - unsupported arg type
  line 100: void _NV_getItemsWeWantRidOf(...) - unsupported arg type
  line 101: bool canHaveSomeOfThese(...) - unsupported arg type
  line 102: bool _NV_canHaveSomeOfThese(...) - unsupported arg type
  line 107: float getPlayerCraftedWeaponLevel(...) - unsupported arg type
  line 108: void getGUIState(...) - unsupported arg type
  line 109: void _NV_getGUIState(...) - unsupported arg type
  line 112: void setProductionItem(...) - unsupported arg type
  line 113: void _NV_setProductionItem(...) - unsupported arg type
*/

int CraftingBuildingBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int CraftingBuildingBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CraftingBuilding object");
    return 1;
}

void CraftingBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CraftingBuildingBinding::gc },
        { "__tostring", CraftingBuildingBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", CraftingBuildingBinding::_DESTRUCTOR },
        { "createInventoryLayout", CraftingBuildingBinding::createInventoryLayout },
        { "_NV_createInventoryLayout", CraftingBuildingBinding::_NV_createInventoryLayout },
        { "update", CraftingBuildingBinding::update },
        { "_NV_update", CraftingBuildingBinding::_NV_update },
        { "givePower", CraftingBuildingBinding::givePower },
        { "_NV_givePower", CraftingBuildingBinding::_NV_givePower },
        { "hasCraftingQueued", CraftingBuildingBinding::hasCraftingQueued },
        { "_NV_hasCraftingQueued", CraftingBuildingBinding::_NV_hasCraftingQueued },
        { "isProductionFull", CraftingBuildingBinding::isProductionFull },
        { "_NV_isProductionFull", CraftingBuildingBinding::_NV_isProductionFull },
        { "getProductionItemData", CraftingBuildingBinding::getProductionItemData },
        { "_NV_getProductionItemData", CraftingBuildingBinding::_NV_getProductionItemData },
        { "getCurrentProductionQuantity", CraftingBuildingBinding::getCurrentProductionQuantity },
        { "_NV_getCurrentProductionQuantity", CraftingBuildingBinding::_NV_getCurrentProductionQuantity },
        { "isAnyInputsInvalidType", CraftingBuildingBinding::isAnyInputsInvalidType },
        { "_NV_isAnyInputsInvalidType", CraftingBuildingBinding::_NV_isAnyInputsInvalidType },
        { "notifyCraftFailiure", CraftingBuildingBinding::notifyCraftFailiure },
        { "_removeCraft", CraftingBuildingBinding::_removeCraft },
        { "getCraft", CraftingBuildingBinding::getCraft },
        { "destroyProductionItem", CraftingBuildingBinding::destroyProductionItem },
        { "getCriticalSuccessWeapon", CraftingBuildingBinding::getCriticalSuccessWeapon },
        { "setupFromData", CraftingBuildingBinding::setupFromData },
        { "_NV_setupFromData", CraftingBuildingBinding::_NV_setupFromData },
        { "updateOutput", CraftingBuildingBinding::updateOutput },
        { "_NV_updateOutput", CraftingBuildingBinding::_NV_updateOutput },
        { "updateInventoryWindow", CraftingBuildingBinding::updateInventoryWindow },
        { "_NV_updateInventoryWindow", CraftingBuildingBinding::_NV_updateInventoryWindow },
        { 0, 0 }
    };

    registerClass(
        L, 
        CraftingBuildingBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CraftingBuildingBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, CraftingBuilding_get_maxCraftLevel);
    lua_setfield(L, -2, "maxCraftLevel");
    lua_pushcfunction(L, CraftingBuilding_get_crafting);
    lua_setfield(L, -2, "crafting");
    lua_pushcfunction(L, CraftingBuilding_get_specialCraftItemType);
    lua_setfield(L, -2, "specialCraftItemType");
    lua_pushcfunction(L, CraftingBuilding_get_repeat);
    lua_setfield(L, -2, "repeat");
    lua_pushcfunction(L, CraftingBuilding_get_whosCrafting);
    lua_setfield(L, -2, "whosCrafting");
    lua_pushcfunction(L, CraftingBuilding_get_itemCrafted);
    lua_setfield(L, -2, "itemCrafted");
    lua_pushcfunction(L, CraftingBuilding_get_failiureNotified);
    lua_setfield(L, -2, "failiureNotified");
    lua_pushcfunction(L, CraftingBuilding_get_biggestCraftableItem);
    lua_setfield(L, -2, "biggestCraftableItem");
    lua_pushcfunction(L, CraftingBuilding_get_outItem);
    lua_setfield(L, -2, "outItem");
    lua_pushcfunction(L, CraftingBuilding_get_inItems);
    lua_setfield(L, -2, "inItems");
    lua_pushcfunction(L, CraftingBuilding_get_partialItems);
    lua_setfield(L, -2, "partialItems");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, CraftingBuilding_set_maxCraftLevel);
    lua_setfield(L, -2, "maxCraftLevel");
    lua_pushcfunction(L, CraftingBuilding_set_crafting);
    lua_setfield(L, -2, "crafting");
    lua_pushcfunction(L, CraftingBuilding_set_specialCraftItemType);
    lua_setfield(L, -2, "specialCraftItemType");
    lua_pushcfunction(L, CraftingBuilding_set_repeat);
    lua_setfield(L, -2, "repeat");
    lua_pushcfunction(L, CraftingBuilding_set_whosCrafting);
    lua_setfield(L, -2, "whosCrafting");
    lua_pushcfunction(L, CraftingBuilding_set_itemCrafted);
    lua_setfield(L, -2, "itemCrafted");
    lua_pushcfunction(L, CraftingBuilding_set_failiureNotified);
    lua_setfield(L, -2, "failiureNotified");
    lua_pushcfunction(L, CraftingBuilding_set_biggestCraftableItem);
    lua_setfield(L, -2, "biggestCraftableItem");
    lua_pushcfunction(L, CraftingBuilding_set_outItem);
    lua_setfield(L, -2, "outItem");
    lua_pushcfunction(L, CraftingBuilding_set_inItems);
    lua_setfield(L, -2, "inItems");
    lua_pushcfunction(L, CraftingBuilding_set_partialItems);
    lua_setfield(L, -2, "partialItems");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ProductionBuilding
    setMetatableParent(L, CraftingBuildingBinding::getMetatableName(), ProductionBuildingBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua