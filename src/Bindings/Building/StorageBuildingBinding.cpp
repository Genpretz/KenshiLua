#include "pch.h"
#include "Bindings/StorageBuildingBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/StorageBuilding.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static StorageBuilding* getS(lua_State* L, int idx)
{
    return checkObject<StorageBuilding>(L, idx, StorageBuildingBinding::getMetatableName());
}

int StorageBuildingBinding::gc(lua_State* L) { return noopGc(L); }

int StorageBuildingBinding::tostring(lua_State* L)
{
    StorageBuilding* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int StorageBuildingBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, StorageBuildingBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    StorageBuilding* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    if (strcmp(key, "specialItemTypesOnly") == 0) { lua_pushinteger(L, (lua_Integer)s->specialItemTypesOnly); return 1; }
    if (strcmp(key, "endOfTheLine") == 0) { lua_pushboolean(L, s->endOfTheLine ? 1 : 0); return 1; }
    if (strcmp(key, "productionItem") == 0) { lua_pushinteger(L, (lua_Integer)s->productionItem); return 1; }
    // TODO lektor<StorageBuilding::ConsumptionItem*> manyLimitItems; unsupported __index type from header line 92

    lua_pushnil(L);
    return 1;
}

int StorageBuildingBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    StorageBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "StorageBuilding is nil");

    if (strcmp(key, "specialItemTypesOnly") == 0) { s->specialItemTypesOnly = (itemType)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "endOfTheLine") == 0) { s->endOfTheLine = lua_toboolean(L, 3) != 0; return 0; }
    // TODO StorageBuilding::ConsumptionItem* productionItem; unsupported __newindex type from header line 91
    // TODO lektor<StorageBuilding::ConsumptionItem*> manyLimitItems; unsupported __newindex type from header line 92

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int StorageBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    StorageBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "StorageBuilding is nil");

    s->_DESTRUCTOR();
    return 0;
}

int StorageBuildingBinding::update(lua_State* L)
{
    StorageBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "StorageBuilding is nil");

    s->update();
    return 0;
}

int StorageBuildingBinding::_NV_update(lua_State* L)
{
    StorageBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "StorageBuilding is nil");

    s->_NV_update();
    return 0;
}

int StorageBuildingBinding::getProductionItemData(lua_State* L)
{
    StorageBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "StorageBuilding is nil");

    GameData result = s->getProductionItemData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int StorageBuildingBinding::_NV_getProductionItemData(lua_State* L)
{
    StorageBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "StorageBuilding is nil");

    GameData result = s->_NV_getProductionItemData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int StorageBuildingBinding::getProductionItem(lua_State* L)
{
    StorageBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "StorageBuilding is nil");

    StorageBuilding::ConsumptionItem result = s->getProductionItem();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int StorageBuildingBinding::getCurrentProductionQuantity(lua_State* L)
{
    StorageBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "StorageBuilding is nil");

    int result = s->getCurrentProductionQuantity();
    lua_pushinteger(L, result);
    return 1;
}

int StorageBuildingBinding::_NV_getCurrentProductionQuantity(lua_State* L)
{
    StorageBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "StorageBuilding is nil");

    int result = s->_NV_getCurrentProductionQuantity();
    lua_pushinteger(L, result);
    return 1;
}

int StorageBuildingBinding::isAnyInputsEmpty(lua_State* L)
{
    StorageBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "StorageBuilding is nil");

    bool result = s->isAnyInputsEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StorageBuildingBinding::_NV_isAnyInputsEmpty(lua_State* L)
{
    StorageBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "StorageBuilding is nil");

    bool result = s->_NV_isAnyInputsEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StorageBuildingBinding::isAnyInputsFull(lua_State* L)
{
    StorageBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "StorageBuilding is nil");

    bool result = s->isAnyInputsFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StorageBuildingBinding::_NV_isAnyInputsFull(lua_State* L)
{
    StorageBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "StorageBuilding is nil");

    bool result = s->_NV_isAnyInputsFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StorageBuildingBinding::isProductionFull(lua_State* L)
{
    StorageBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "StorageBuilding is nil");

    bool result = s->isProductionFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StorageBuildingBinding::_NV_isProductionFull(lua_State* L)
{
    StorageBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "StorageBuilding is nil");

    bool result = s->_NV_isProductionFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StorageBuildingBinding::isProductionEmpty(lua_State* L)
{
    StorageBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "StorageBuilding is nil");

    bool result = s->isProductionEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StorageBuildingBinding::_NV_isProductionEmpty(lua_State* L)
{
    StorageBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "StorageBuilding is nil");

    bool result = s->_NV_isProductionEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StorageBuildingBinding::getNumConsumtionItems(lua_State* L)
{
    StorageBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "StorageBuilding is nil");

    int result = s->getNumConsumtionItems();
    lua_pushinteger(L, result);
    return 1;
}

int StorageBuildingBinding::_NV_getNumConsumtionItems(lua_State* L)
{
    StorageBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "StorageBuilding is nil");

    int result = s->_NV_getNumConsumtionItems();
    lua_pushinteger(L, result);
    return 1;
}

int StorageBuildingBinding::getConsumtionItems(lua_State* L)
{
    StorageBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "StorageBuilding is nil");

    int id = (int)luaL_checkinteger(L, 2);
    StorageBuilding::ConsumptionItem result = s->getConsumtionItems(id);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int StorageBuildingBinding::_NV_getConsumtionItems(lua_State* L)
{
    StorageBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "StorageBuilding is nil");

    int id = (int)luaL_checkinteger(L, 2);
    StorageBuilding::ConsumptionItem result = s->_NV_getConsumtionItems(id);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int StorageBuildingBinding::limitedByType(lua_State* L)
{
    StorageBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "StorageBuilding is nil");

    bool result = s->limitedByType();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StorageBuildingBinding::updateInventoryWindow(lua_State* L)
{
    StorageBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "StorageBuilding is nil");

    s->updateInventoryWindow();
    return 0;
}

int StorageBuildingBinding::_NV_updateInventoryWindow(lua_State* L)
{
    StorageBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "StorageBuilding is nil");

    s->_NV_updateInventoryWindow();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 48: StorageBuilding* _CONSTRUCTOR(...) - unsupported return type
  line 51: StorageBuilding* getFunctionStuff(...) - unsupported return type
  line 52: StorageBuilding* _NV_getFunctionStuff(...) - unsupported return type
  line 53: UseableStuff* getUseableStuff(...) - unsupported return type
  line 54: UseableStuff* _NV_getUseableStuff(...) - unsupported return type
  line 57: TaskType getDefaultTask(...) - unsupported return type
  line 58: TaskType _NV_getDefaultTask(...) - unsupported return type
  line 59: void getItemsWeWantRidOf(...) - unsupported arg type
  line 60: void _NV_getItemsWeWantRidOf(...) - unsupported arg type
  line 66: bool canHaveSomeOfThese(...) - unsupported arg type
  line 67: bool _NV_canHaveSomeOfThese(...) - unsupported arg type
  line 68: void getResourcesNeededBecauseEmpty(...) - unsupported arg type
  line 69: void _NV_getResourcesNeededBecauseEmpty(...) - unsupported arg type
  line 70: void getResourcesNeededBecauseNotFull(...) - unsupported arg type
  line 71: void _NV_getResourcesNeededBecauseNotFull(...) - unsupported arg type
  line 84: void getConsumtionItems_inStock(...) - unsupported arg type
*/

void StorageBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       StorageBuildingBinding::gc },
        { "__tostring", StorageBuildingBinding::tostring },
        { "__index",    StorageBuildingBinding::index },
        { "__newindex", StorageBuildingBinding::newindex },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", StorageBuildingBinding::_DESTRUCTOR },
        { "update", StorageBuildingBinding::update },
        { "_NV_update", StorageBuildingBinding::_NV_update },
        { "getProductionItemData", StorageBuildingBinding::getProductionItemData },
        { "_NV_getProductionItemData", StorageBuildingBinding::_NV_getProductionItemData },
        { "getProductionItem", StorageBuildingBinding::getProductionItem },
        { "getCurrentProductionQuantity", StorageBuildingBinding::getCurrentProductionQuantity },
        { "_NV_getCurrentProductionQuantity", StorageBuildingBinding::_NV_getCurrentProductionQuantity },
        { "isAnyInputsEmpty", StorageBuildingBinding::isAnyInputsEmpty },
        { "_NV_isAnyInputsEmpty", StorageBuildingBinding::_NV_isAnyInputsEmpty },
        { "isAnyInputsFull", StorageBuildingBinding::isAnyInputsFull },
        { "_NV_isAnyInputsFull", StorageBuildingBinding::_NV_isAnyInputsFull },
        { "isProductionFull", StorageBuildingBinding::isProductionFull },
        { "_NV_isProductionFull", StorageBuildingBinding::_NV_isProductionFull },
        { "isProductionEmpty", StorageBuildingBinding::isProductionEmpty },
        { "_NV_isProductionEmpty", StorageBuildingBinding::_NV_isProductionEmpty },
        { "getNumConsumtionItems", StorageBuildingBinding::getNumConsumtionItems },
        { "_NV_getNumConsumtionItems", StorageBuildingBinding::_NV_getNumConsumtionItems },
        { "getConsumtionItems", StorageBuildingBinding::getConsumtionItems },
        { "_NV_getConsumtionItems", StorageBuildingBinding::_NV_getConsumtionItems },
        { "limitedByType", StorageBuildingBinding::limitedByType },
        { "updateInventoryWindow", StorageBuildingBinding::updateInventoryWindow },
        { "_NV_updateInventoryWindow", StorageBuildingBinding::_NV_updateInventoryWindow },
        { 0, 0 }
    };
    registerClass(L, StorageBuildingBinding::getMetatableName(), meta, methods);
}

} // namespace KenshiLua