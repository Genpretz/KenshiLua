#include "pch.h"
#include "Bindings/CraftingBuildingBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/CraftingBuilding.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static CraftingBuilding* getS(lua_State* L, int idx)
{
    return checkObject<CraftingBuilding>(L, idx, CraftingBuildingBinding::getMetatableName());
}

int CraftingBuildingBinding::gc(lua_State* L) { return noopGc(L); }

int CraftingBuildingBinding::tostring(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int CraftingBuildingBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, CraftingBuildingBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    CraftingBuilding* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    if (strcmp(key, "maxCraftLevel") == 0) { lua_pushinteger(L, s->maxCraftLevel); return 1; }
    // TODO std::deque<CraftingItem, std::allocator<CraftingItem> > crafting; unsupported __index type from header line 92
    if (strcmp(key, "specialCraftItemType") == 0) { lua_pushinteger(L, (lua_Integer)s->specialCraftItemType); return 1; }
    if (strcmp(key, "repeat") == 0) { lua_pushboolean(L, s->repeat ? 1 : 0); return 1; }
    // TODO hand whosCrafting; unsupported __index type from header line 95
    if (strcmp(key, "itemCrafted") == 0) { lua_pushboolean(L, s->itemCrafted ? 1 : 0); return 1; }
    if (strcmp(key, "failiureNotified") == 0) { lua_pushboolean(L, s->failiureNotified ? 1 : 0); return 1; }
    if (strcmp(key, "biggestCraftableItem") == 0) { return pushObject<GameData>(L, s->biggestCraftableItem, GameDataBinding::getMetatableName()); }
    if (strcmp(key, "outItem") == 0) { return pushObject<Item>(L, s->outItem, ItemBinding::getMetatableName()); }
    // TODO lektor<Item*> inItems; unsupported __index type from header line 118
    // TODO ogre_unordered_map<GameData*, float>::type partialItems; unsupported __index type from header line 119

    lua_pushnil(L);
    return 1;
}

int CraftingBuildingBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    if (strcmp(key, "maxCraftLevel") == 0) { s->maxCraftLevel = (int)luaL_checkinteger(L, 3); return 0; }
    // TODO std::deque<CraftingItem, std::allocator<CraftingItem> > crafting; unsupported __newindex type from header line 92
    if (strcmp(key, "specialCraftItemType") == 0) { s->specialCraftItemType = (itemType)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "repeat") == 0) { s->repeat = lua_toboolean(L, 3) != 0; return 0; }
    // TODO hand whosCrafting; unsupported __newindex type from header line 95
    if (strcmp(key, "itemCrafted") == 0) { s->itemCrafted = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "failiureNotified") == 0) { s->failiureNotified = lua_toboolean(L, 3) != 0; return 0; }
    // TODO GameData* biggestCraftableItem; unsupported __newindex type from header line 116
    // TODO Item* outItem; unsupported __newindex type from header line 117
    // TODO lektor<Item*> inItems; unsupported __newindex type from header line 118
    // TODO ogre_unordered_map<GameData*, float>::type partialItems; unsupported __newindex type from header line 119

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int CraftingBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    s->_DESTRUCTOR();
    return 0;
}

int CraftingBuildingBinding::update(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    s->update();
    return 0;
}

int CraftingBuildingBinding::_NV_update(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    s->_NV_update();
    return 0;
}

int CraftingBuildingBinding::givePower(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    float amount = (float)luaL_checknumber(L, 2);
    s->givePower(amount);
    return 0;
}

int CraftingBuildingBinding::_NV_givePower(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    float amount = (float)luaL_checknumber(L, 2);
    s->_NV_givePower(amount);
    return 0;
}

int CraftingBuildingBinding::hasCraftingQueued(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    bool result = s->hasCraftingQueued();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CraftingBuildingBinding::_NV_hasCraftingQueued(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    bool result = s->_NV_hasCraftingQueued();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CraftingBuildingBinding::isProductionFull(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    bool result = s->isProductionFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CraftingBuildingBinding::_NV_isProductionFull(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    bool result = s->_NV_isProductionFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CraftingBuildingBinding::getProductionItemData(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    GameData result = s->getProductionItemData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int CraftingBuildingBinding::_NV_getProductionItemData(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    GameData result = s->_NV_getProductionItemData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int CraftingBuildingBinding::getCurrentProductionQuantity(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    int result = s->getCurrentProductionQuantity();
    lua_pushinteger(L, result);
    return 1;
}

int CraftingBuildingBinding::_NV_getCurrentProductionQuantity(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    int result = s->_NV_getCurrentProductionQuantity();
    lua_pushinteger(L, result);
    return 1;
}

int CraftingBuildingBinding::isAnyInputsInvalidType(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    bool result = s->isAnyInputsInvalidType();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CraftingBuildingBinding::_NV_isAnyInputsInvalidType(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    bool result = s->_NV_isAnyInputsInvalidType();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CraftingBuildingBinding::notifyCraftFailiure(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    s->notifyCraftFailiure();
    return 0;
}

int CraftingBuildingBinding::_removeCraft(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    int index = (int)luaL_checkinteger(L, 2);
    s->_removeCraft(index);
    return 0;
}

int CraftingBuildingBinding::destroyProductionItem(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    s->destroyProductionItem();
    return 0;
}

int CraftingBuildingBinding::getCriticalSuccessWeapon(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    int normalWeaponLevel = (int)luaL_checkinteger(L, 2);
    GameData result = s->getCriticalSuccessWeapon(normalWeaponLevel);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int CraftingBuildingBinding::setupFromData(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    s->setupFromData();
    return 0;
}

int CraftingBuildingBinding::_NV_setupFromData(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    s->_NV_setupFromData();
    return 0;
}

int CraftingBuildingBinding::updateOutput(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    s->updateOutput(rate);
    return 0;
}

int CraftingBuildingBinding::_NV_updateOutput(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    s->_NV_updateOutput(rate);
    return 0;
}

int CraftingBuildingBinding::updateInventoryWindow(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    s->updateInventoryWindow();
    return 0;
}

int CraftingBuildingBinding::_NV_updateInventoryWindow(lua_State* L)
{
    CraftingBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "CraftingBuilding is nil");

    s->_NV_updateInventoryWindow();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 50: CraftingBuilding* _CONSTRUCTOR(...) - unsupported return type
  line 53: InventoryLayout* createInventoryLayout(...) - unsupported return type
  line 54: InventoryLayout* _NV_createInventoryLayout(...) - unsupported return type
  line 57: void operate(...) - unsupported arg type
  line 58: void _NV_operate(...) - unsupported arg type
  line 61: void getGUIData(...) - unsupported arg type
  line 62: void _NV_getGUIData(...) - unsupported arg type
  line 63: GameSaveState serialise(...) - unsupported return type
  line 64: GameSaveState _NV_serialise(...) - unsupported return type
  line 65: void loadFromSerialise(...) - unsupported arg type
  line 66: void _NV_loadFromSerialise(...) - unsupported arg type
  line 77: void newCraftingButton(...) - pointer arg
  line 78: void _NV_newCraftingButton(...) - pointer arg
  line 79: void addFinishedCraftItem(...) - unsupported arg type
  line 81: bool tryOperate(...) - unsupported arg type
  line 82: bool _NV_tryOperate(...) - unsupported arg type
  line 83: GameData* playerManufacturerData(...) - static method
  line 84: void getAvailableCrafts(...) - unsupported arg type
  line 85: CraftingItem* _addCraft(...) - unsupported return type
  line 87: CraftingItem* getCraft(...) - unsupported return type
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

void CraftingBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CraftingBuildingBinding::gc },
        { "__tostring", CraftingBuildingBinding::tostring },
        { "__index",    CraftingBuildingBinding::index },
        { "__newindex", CraftingBuildingBinding::newindex },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", CraftingBuildingBinding::_DESTRUCTOR },
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
    registerClass(L, CraftingBuildingBinding::getMetatableName(), meta, methods);
}

} // namespace KenshiLua