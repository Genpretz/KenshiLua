#include "pch.h"
#include "kenshi\Inventory.h"
#include "InventoryBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/Gui/InventoryGUIBinding.h"
#include "Bindings/InventorySectionBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/WeaponBinding.h"
#include "Bindings/Inventory_HasRoomCacheBinding.h"
#include "Bindings/Util/BoostUnorderedBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"
#include "InventorySectionBinding.h"
#include "ItemBinding.h"
#include "RootObjectBinding.h"
#include "WeaponBinding.h"
#include "kenshi/GameSaveState.h"
#include "kenshi/Gear.h"
#include "kenshi/Item.h"

namespace KenshiLua
{

static Inventory* getInstance(lua_State* L, int idx)
{
    return checkObject<Inventory>(L, idx, InventoryBinding::getMetatableName());
}

// --- Getters for Inventory ---
static int Inventory_get_hasRoomCache(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    return pushObject<Inventory::HasRoomCache>(L, instance->hasRoomCache, Inventory_HasRoomCacheBinding::getMetatableName());
}

static int Inventory_get_callbackObject(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    return pushObject<RootObject>(L, instance->callbackObject, RootObjectBinding::getMetatableName());
}

static int Inventory_get_owner(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    return pushObject<RootObject>(L, instance->owner, RootObjectBinding::getMetatableName());
}

static int Inventory_get_totalWeight(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    lua_pushnumber(L, instance->totalWeight);
    return 1;
}

// --- Setters for Inventory ---
static int Inventory_set_callbackObject(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    instance->callbackObject = lua_isnoneornil(L, 2) ? nullptr : checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    return 0;
}

static int Inventory_set_owner(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    instance->owner = lua_isnoneornil(L, 2) ? nullptr : checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    return 0;
}

static int Inventory_set_totalWeight(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    instance->totalWeight = (float)luaL_checknumber(L, 2);
    return 0;
}

int InventoryBinding::_CONSTRUCTOR(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    RootObject* _owner = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    Inventory* result = instance->_CONSTRUCTOR(_owner);
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int InventoryBinding::_DESTRUCTOR(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int InventoryBinding::clearAll(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    bool destroy = lua_toboolean(L, 2) != 0;
    bool skipUnique = lua_toboolean(L, 3) != 0;
    instance->clearAll(destroy, skipUnique);
    return 0;
}

int InventoryBinding::serialise(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* refList = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    GameData* result = instance->serialise(container, refList);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int InventoryBinding::notifyModified(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    instance->notifyModified();
    return 0;
}

int InventoryBinding::initialiseNewSection(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    const std::string name = luaL_checkstring(L, 2);
    int w = (int)luaL_checkinteger(L, 3);
    int h = (int)luaL_checkinteger(L, 4);
    AttachSlot limitSlot = (AttachSlot)luaL_checkinteger(L, 5);
    bool equipCallbacks = lua_toboolean(L, 6) != 0;
    bool isContainerSlot = lua_toboolean(L, 7) != 0;
    bool enabled = lua_toboolean(L, 8) != 0;
    int limit = (int)luaL_checkinteger(L, 9);
    InventorySection* result = instance->initialiseNewSection(name, w, h, limitSlot, equipCallbacks, isContainerSlot, enabled, limit);
    return pushObject<InventorySection>(L, result, InventorySectionBinding::getMetatableName());
}

int InventoryBinding::_NV_initialiseNewSection(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    const std::string name = luaL_checkstring(L, 2);
    int w = (int)luaL_checkinteger(L, 3);
    int h = (int)luaL_checkinteger(L, 4);
    AttachSlot limitSlot = (AttachSlot)luaL_checkinteger(L, 5);
    bool equipCallbacks = lua_toboolean(L, 6) != 0;
    bool isContainerSlot = lua_toboolean(L, 7) != 0;
    bool enabled = lua_toboolean(L, 8) != 0;
    int limit = (int)luaL_checkinteger(L, 9);
    InventorySection* result = instance->_NV_initialiseNewSection(name, w, h, limitSlot, equipCallbacks, isContainerSlot, enabled, limit);
    return pushObject<InventorySection>(L, result, InventorySectionBinding::getMetatableName());
}

int InventoryBinding::resizeSection(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    InventorySection* sect = checkObject<InventorySection>(L, 2, InventorySectionBinding::getMetatableName());
    int w = (int)luaL_checkinteger(L, 3);
    int h = (int)luaL_checkinteger(L, 4);
    bool clearContent = lua_toboolean(L, 5) != 0;
    instance->resizeSection(sect, w, h, clearContent);
    return 0;
}

int InventoryBinding::removeAllSections(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    instance->removeAllSections();
    return 0;
}

int InventoryBinding::getSection(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    const std::string name = luaL_checkstring(L, 2);
    InventorySection* result = instance->getSection(name);
    return pushObject<InventorySection>(L, result, InventorySectionBinding::getMetatableName());
}

int InventoryBinding::getSectionOfType(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    AttachSlot type = (AttachSlot)luaL_checkinteger(L, 2);
    InventorySection* result = instance->getSectionOfType(type);
    return pushObject<InventorySection>(L, result, InventorySectionBinding::getMetatableName());
}

int InventoryBinding::getCallbackCharacter(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Character* result = instance->getCallbackCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int InventoryBinding::addItem(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int quantity = (int)luaL_checkinteger(L, 3);
    bool dropOnFail = lua_toboolean(L, 4) != 0;
    bool destroyOnFail = lua_toboolean(L, 5) != 0;
    bool result = instance->addItem(item, quantity, dropOnFail, destroyOnFail);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::_NV_addItem(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int quantity = (int)luaL_checkinteger(L, 3);
    bool dropOnFail = lua_toboolean(L, 4) != 0;
    bool destroyOnFail = lua_toboolean(L, 5) != 0;
    bool result = instance->_NV_addItem(item, quantity, dropOnFail, destroyOnFail);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::tryAddItem(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int quantity = (int)luaL_checkinteger(L, 3);
    bool result = instance->tryAddItem(item, quantity);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::_NV_tryAddItem(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int quantity = (int)luaL_checkinteger(L, 3);
    bool result = instance->_NV_tryAddItem(item, quantity);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::hasRoomForItem(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->hasRoomForItem(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::_NV_hasRoomForItem(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->_NV_hasRoomForItem(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::removeItemDontDestroy_returnsItem(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Item* it = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int howmany = (int)luaL_checkinteger(L, 3);
    bool returnCopyIfSomeLeft = lua_toboolean(L, 4) != 0;
    Item* result = instance->removeItemDontDestroy_returnsItem(it, howmany, returnCopyIfSomeLeft);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int InventoryBinding::_NV_removeItemDontDestroy_returnsItem(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Item* it = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int howmany = (int)luaL_checkinteger(L, 3);
    bool returnCopyIfSomeLeft = lua_toboolean(L, 4) != 0;
    Item* result = instance->_NV_removeItemDontDestroy_returnsItem(it, howmany, returnCopyIfSomeLeft);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int InventoryBinding::removeItemAutoDestroy(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Item* it = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int howmany = (int)luaL_checkinteger(L, 3);
    bool result = instance->removeItemAutoDestroy(it, howmany);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::_NV_removeItemAutoDestroy(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Item* it = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int howmany = (int)luaL_checkinteger(L, 3);
    bool result = instance->_NV_removeItemAutoDestroy(it, howmany);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::dropItem(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Item* it = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    instance->dropItem(it);
    return 0;
}

int InventoryBinding::_NV_dropItem(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Item* it = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    instance->_NV_dropItem(it);
    return 0;
}

int InventoryBinding::transferMouseItem(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool result = instance->transferMouseItem(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::countItems(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    int result = instance->countItems(item);
    lua_pushinteger(L, result);
    return 1;
}

int InventoryBinding::getItem(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Item* result = instance->getItem(item);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int InventoryBinding::hasItemType(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    itemType item = (itemType)luaL_checkinteger(L, 2);
    bool skipEquipped = lua_toboolean(L, 3) != 0;
    bool result = instance->hasItemType(item, skipEquipped);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::hasStolenItems(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    bool result = instance->hasStolenItems();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::getSecondaryWeapon(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Weapon* result = instance->getSecondaryWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int InventoryBinding::getPrimaryWeapon(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Weapon* result = instance->getPrimaryWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int InventoryBinding::takeOneItemOnly(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Item* result = instance->takeOneItemOnly(item);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int InventoryBinding::deathCheck(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool result = instance->deathCheck(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::hasItemFunction(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    ItemFunction type = (ItemFunction)luaL_checkinteger(L, 2);
    bool result = instance->hasItemFunction(type);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::getBestItemWithFunction(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    ItemFunction type = (ItemFunction)luaL_checkinteger(L, 2);
    Item* result = instance->getBestItemWithFunction(type);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int InventoryBinding::getBestFoodItem(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Character* race = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    Item* result = instance->getBestFoodItem(race);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int InventoryBinding::getNumFoodItems(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Character* race = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    int result = instance->getNumFoodItems(race);
    lua_pushinteger(L, result);
    return 1;
}

int InventoryBinding::_getBestFoodItem(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    ItemFunction type = (ItemFunction)luaL_checkinteger(L, 2);
    Character* race = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    Item* result = instance->_getBestFoodItem(type, race);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int InventoryBinding::_getNumFoodItems(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    ItemFunction type = (ItemFunction)luaL_checkinteger(L, 2);
    Character* race = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    int result = instance->_getNumFoodItems(type, race);
    lua_pushinteger(L, result);
    return 1;
}

int InventoryBinding::hasWeaponEquipped(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    bool result = instance->hasWeaponEquipped();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::equipItem(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool result = instance->equipItem(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::isAContainer(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    bool result = instance->isAContainer();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::getOwner(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    RootObject* result = instance->getOwner();
    return pushObject<RootObject>(L, result, RootObjectBinding::getMetatableName());
}

int InventoryBinding::isEmpty(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    bool result = instance->isEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::recalculateTotalWeight(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    instance->recalculateTotalWeight();
    return 0;
}

int InventoryBinding::getTotalWeight(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    float result = instance->getTotalWeight();
    lua_pushnumber(L, result);
    return 1;
}

int InventoryBinding::getMoney(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    int result = instance->getMoney();
    lua_pushinteger(L, result);
    return 1;
}

int InventoryBinding::takeMoney(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    int val = (int)luaL_checkinteger(L, 2);
    instance->takeMoney(val);
    return 0;
}

int InventoryBinding::buyItem(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Item* itemToBuy = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    RootObject* sendingTo = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    Item* result = instance->buyItem(itemToBuy, sendingTo);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int InventoryBinding::getInventoryGUI(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    InventoryGUI* result = instance->getInventoryGUI();
    return pushObject<InventoryGUI>(L, result, InventoryGUIBinding::getMetatableName());
}

int InventoryBinding::isVisible(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    bool result = instance->isVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::_sectionAddItemCallback(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    instance->_sectionAddItemCallback(item);
    return 0;
}

int InventoryBinding::_NV__sectionAddItemCallback(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    instance->_NV__sectionAddItemCallback(item);
    return 0;
}

int InventoryBinding::_sectionUpdateItemCallback(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Item* _a1 = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int _a2 = (int)luaL_checkinteger(L, 3);
    instance->_sectionUpdateItemCallback(_a1, _a2);
    return 0;
}

int InventoryBinding::_NV__sectionUpdateItemCallback(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Item* _a1 = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int _a2 = (int)luaL_checkinteger(L, 3);
    instance->_NV__sectionUpdateItemCallback(_a1, _a2);
    return 0;
}

int InventoryBinding::_sectionRemoveItemCallback(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    instance->_sectionRemoveItemCallback(item);
    return 0;
}

int InventoryBinding::_NV__sectionRemoveItemCallback(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    instance->_NV__sectionRemoveItemCallback(item);
    return 0;
}

int InventoryBinding::refreshGui(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    instance->refreshGui();
    return 0;
}

int InventoryBinding::_NV_refreshGui(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    instance->_NV_refreshGui();
    return 0;
}

int InventoryBinding::autoArrange(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    instance->autoArrange();
    return 0;
}

int InventoryBinding::getCallbackObject(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    RootObject* result = instance->getCallbackObject();
    return pushObject<RootObject>(L, result, RootObjectBinding::getMetatableName());
}

int InventoryBinding::_addToList(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    instance->_addToList(item);
    return 0;
}

int InventoryBinding::_NV__addToList(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    instance->_NV__addToList(item);
    return 0;
}

int InventoryBinding::_removeFromList(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool checkEverything = lua_toboolean(L, 3) != 0;
    instance->_removeFromList(item, checkEverything);
    return 0;
}

int InventoryBinding::_NV__removeFromList(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool checkEverything = lua_toboolean(L, 3) != 0;
    instance->_NV__removeFromList(item, checkEverything);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 128: const hand& getHandle(...) - reference return type
  line 131: void loadFrom(...) - overloaded method
  line 132: void loadFrom(...) - overloaded method
  line 134: void fillFromVendorList(...) - overloaded method
  line 135: void fillFromVendorList(...) - overloaded method
  line 142: void getAllSectionsOfType(...) - unsupported arg type
  line 143: lektor<InventorySection*>& getAllSections(...) - reference return type
  line 144: bool getExcessLoot(...) - non-string reference arg
  line 145: void getResourceItems(...) - unsupported arg type
  line 146: int getNumItems(...) - overloaded method
  line 147: int getNumItems(...) - overloaded method
  line 179: bool hasItem(...) - overloaded method
  line 180: bool hasItem(...) - overloaded method
  line 184: void getAllStolenItems(...) - unsupported arg type
  line 186: void getAllItemsOfType(...) - unsupported arg type
  line 187: void getEquippedWeapons(...) - unsupported arg type
  line 190: void getEquippedArmour(...) - unsupported arg type
  line 193: bool takeItem_EntireStack(...) - overloaded method
  line 194: Item* takeItem_EntireStack(...) - overloaded method
  line 196: void getAllItemsWithFunction(...) - unsupported arg type
  line 198: Item* getBestItemWithLowestCharges(...) - overloaded method
  line 199: Item* getBestItemWithLowestCharges(...) - overloaded method
  line 227: const lektor<Item*>& getAllItems(...) - reference return type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - Inventory_get_hasRoomCache: Inventory::HasRoomCache* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 232: _allItems (lektor<Item*>) - unsupported type
  line 233: sections (boost::unordered::unordered_map<std::string, InventorySection*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, InventorySection*>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 234: sectionsInSearchOrder (lektor<InventorySection*>) - unsupported type
*/

int InventoryBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int InventoryBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Inventory object");
    return 1;
}



static int Inventory_get__allItems(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    return pushObject<lektor<Item*>>(L, &instance->_allItems, LektorPtrBinding<Item*>::metaName);
}


static int Inventory_get_sections(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    lua_newtable(L);
    typedef BoostUnorderedMapBinding<std::string, InventorySection*>::MapType SectionsMap;
    for (SectionsMap::const_iterator it = instance->sections.begin(); it != instance->sections.end(); ++it)
    {
        pushObject<InventorySection>(L, it->second, InventorySectionBinding::getMetatableName());
        lua_setfield(L, -2, it->first.c_str());
    }
    return 1;
}


static int Inventory_get_sectionsInSearchOrder(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    return pushObject<lektor<InventorySection*>>(L, &instance->sectionsInSearchOrder, LektorPtrBinding<InventorySection*>::metaName);
}


static int Inventory_set__allItems(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    return luaL_error(L, "Read-only or unsupported setter type for _allItems");
}


static int Inventory_set_hasRoomCache(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    instance->hasRoomCache = lua_isnoneornil(L, 2) ? nullptr : checkObject<Inventory::HasRoomCache>(L, 2, Inventory_HasRoomCacheBinding::getMetatableName());
    return 0;
}


static int Inventory_set_sections(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    return luaL_error(L, "Read-only or unsupported setter type for sections");
}


static int Inventory_set_sectionsInSearchOrder(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    return luaL_error(L, "Read-only or unsupported setter type for sectionsInSearchOrder");
}


int InventoryBinding::fillFromVendorList(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    Faction* f = checkObject<Faction>(L, 3, FactionBinding::getMetatableName());
    if (lua_isuserdata(L, 2)) {
        lua_getmetatable(L, 2);
        luaL_getmetatable(L, GameDataBinding::getMetatableName());
        bool isGameData = lua_rawequal(L, -1, -2) != 0;
        lua_pop(L, 2);
        if (isGameData) {
            GameData* vendorData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
            instance->fillFromVendorList(vendorData, f);
        } else {
            lektor<GameData*>* list = LektorPtrBinding<GameData*>::get(L, 2);
            instance->fillFromVendorList(*list, f);
        }
    }
    return 0;
}


int InventoryBinding::getAllItems(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    const lektor<Item*>& result = instance->getAllItems();
    return pushObject<lektor<Item*>>(L, const_cast<lektor<Item*>*>(&result), LektorPtrBinding<Item*>::metaName);
}


int InventoryBinding::getAllItemsOfType(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    lektor<Item*>* all = LektorPtrBinding<Item*>::get(L, 2);
    itemType ty = (itemType)luaL_checkinteger(L, 3);
    bool skipEquipped = lua_toboolean(L, 4) != 0;
    instance->getAllItemsOfType(*all, ty, skipEquipped);
    return 0;
}


int InventoryBinding::getAllItemsWithFunction(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    lektor<Item*>* out = LektorPtrBinding<Item*>::get(L, 2);
    ItemFunction type = (ItemFunction)luaL_checkinteger(L, 3);
    instance->getAllItemsWithFunction(*out, type);
    return 0;
}


int InventoryBinding::getAllSections(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    lektor<InventorySection*>& result = instance->getAllSections();
    return pushObject<lektor<InventorySection*>>(L, &result, LektorPtrBinding<InventorySection*>::metaName);
}


int InventoryBinding::getAllSectionsOfType(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    lektor<InventorySection*>* out = LektorPtrBinding<InventorySection*>::get(L, 2);
    AttachSlot type = (AttachSlot)luaL_checkinteger(L, 3);
    instance->getAllSectionsOfType(*out, type);
    return 0;
}


int InventoryBinding::getAllStolenItems(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    lektor<Item*>* all = LektorPtrBinding<Item*>::get(L, 2);
    bool includeUnknown = lua_toboolean(L, 3) != 0;
    instance->getAllStolenItems(*all, includeUnknown);
    return 0;
}


int InventoryBinding::getBestItemWithLowestCharges(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    if (lua_isuserdata(L, 2)) {
        lua_getmetatable(L, 2);
        luaL_getmetatable(L, GameDataBinding::getMetatableName());
        bool isGameData = lua_rawequal(L, -1, -2) != 0;
        lua_pop(L, 2);
        if (isGameData) {
            GameData* what = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
            Item* result = instance->getBestItemWithLowestCharges(what);
            return pushObject<Item>(L, result, ItemBinding::getMetatableName());
        }
    }
    ItemFunction type = (ItemFunction)luaL_checkinteger(L, 2);
    Item* result = instance->getBestItemWithLowestCharges(type);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}


int InventoryBinding::getEquippedArmour(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    lektor<Item*>* all = LektorPtrBinding<Item*>::get(L, 2);
    instance->getEquippedArmour(*all);
    return 0;
}


int InventoryBinding::getEquippedWeapons(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    lektor<Item*>* all = LektorPtrBinding<Item*>::get(L, 2);
    instance->getEquippedWeapons(*all);
    return 0;
}


int InventoryBinding::getExcessLoot(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    hand* me = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    lektor<Item*>* out = LektorPtrBinding<Item*>::get(L, 3);
    bool justAsking = lua_toboolean(L, 4) != 0;
    bool result = instance->getExcessLoot(*me, *out, justAsking);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}


int InventoryBinding::getHandle(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    const hand& result = instance->getHandle();
    HandBinding::push(L, result);
    return 1;
}


int InventoryBinding::getNumItems(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    if (lua_gettop(L) >= 2 && !lua_isnil(L, 2)) {
        GameData* itemType = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
        int result = instance->getNumItems(itemType);
        lua_pushinteger(L, result);
    } else {
        int result = instance->getNumItems();
        lua_pushinteger(L, result);
    }
    return 1;
}


int InventoryBinding::getResourceItems(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    ogre_unordered_set<GameData*>::type* out = OgreUnorderedSetBinding<GameData*>::get(L, 2);
    bool buildingMatsToo = lua_toboolean(L, 3) != 0;
    instance->getResourceItems(*out, buildingMatsToo);
    return 0;
}


int InventoryBinding::hasItem(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    if (lua_isuserdata(L, 2)) {
        lua_getmetatable(L, 2);
        luaL_getmetatable(L, GameDataBinding::getMetatableName());
        bool isGameData = lua_rawequal(L, -1, -2) != 0;
        lua_pop(L, 2);
        if (isGameData) {
            GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
            int quantity = (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) ? (int)luaL_checkinteger(L, 3) : 1;
            bool result = instance->hasItem(data, quantity);
            lua_pushboolean(L, result ? 1 : 0);
        } else {
            Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
            bool result = instance->hasItem(item);
            lua_pushboolean(L, result ? 1 : 0);
        }
    } else {
        lua_pushboolean(L, 0);
    }
    return 1;
}


int InventoryBinding::loadFrom(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    if (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) {
        GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
        GameData* inventoryState = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
        instance->loadFrom(container, inventoryState);
    } else {
        GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
        instance->loadFrom(state);
    }
    return 0;
}


int InventoryBinding::takeItem_EntireStack(lua_State* L)
{
    Inventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Inventory is nil");
    if (lua_isuserdata(L, 2)) {
        lua_getmetatable(L, 2);
        luaL_getmetatable(L, GameDataBinding::getMetatableName());
        bool isGameData = lua_rawequal(L, -1, -2) != 0;
        lua_pop(L, 2);
        if (isGameData) {
            GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
            Item* result = instance->takeItem_EntireStack(item);
            return pushObject<Item>(L, result, ItemBinding::getMetatableName());
        } else {
            Item* what = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
            bool result = instance->takeItem_EntireStack(what);
            lua_pushboolean(L, result ? 1 : 0);
            return 1;
        }
    }
    return 0;
}


void InventoryBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       InventoryBinding::gc },
        { "__tostring", InventoryBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", InventoryBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", InventoryBinding::_DESTRUCTOR },
        { "clearAll", InventoryBinding::clearAll },
        { "serialise", InventoryBinding::serialise },
        { "notifyModified", InventoryBinding::notifyModified },
        { "initialiseNewSection", InventoryBinding::initialiseNewSection },
        { "_NV_initialiseNewSection", InventoryBinding::_NV_initialiseNewSection },
        { "resizeSection", InventoryBinding::resizeSection },
        { "removeAllSections", InventoryBinding::removeAllSections },
        { "getSection", InventoryBinding::getSection },
        { "getSectionOfType", InventoryBinding::getSectionOfType },
        { "getCallbackCharacter", InventoryBinding::getCallbackCharacter },
        { "addItem", InventoryBinding::addItem },
        { "_NV_addItem", InventoryBinding::_NV_addItem },
        { "tryAddItem", InventoryBinding::tryAddItem },
        { "_NV_tryAddItem", InventoryBinding::_NV_tryAddItem },
        { "hasRoomForItem", InventoryBinding::hasRoomForItem },
        { "_NV_hasRoomForItem", InventoryBinding::_NV_hasRoomForItem },
        { "removeItemDontDestroy_returnsItem", InventoryBinding::removeItemDontDestroy_returnsItem },
        { "_NV_removeItemDontDestroy_returnsItem", InventoryBinding::_NV_removeItemDontDestroy_returnsItem },
        { "removeItemAutoDestroy", InventoryBinding::removeItemAutoDestroy },
        { "_NV_removeItemAutoDestroy", InventoryBinding::_NV_removeItemAutoDestroy },
        { "dropItem", InventoryBinding::dropItem },
        { "_NV_dropItem", InventoryBinding::_NV_dropItem },
        { "transferMouseItem", InventoryBinding::transferMouseItem },
        { "countItems", InventoryBinding::countItems },
        { "getItem", InventoryBinding::getItem },
        { "hasItemType", InventoryBinding::hasItemType },
        { "hasStolenItems", InventoryBinding::hasStolenItems },
        { "getSecondaryWeapon", InventoryBinding::getSecondaryWeapon },
        { "getPrimaryWeapon", InventoryBinding::getPrimaryWeapon },
        { "takeOneItemOnly", InventoryBinding::takeOneItemOnly },
        { "deathCheck", InventoryBinding::deathCheck },
        { "hasItemFunction", InventoryBinding::hasItemFunction },
        { "getBestItemWithFunction", InventoryBinding::getBestItemWithFunction },
        { "getBestFoodItem", InventoryBinding::getBestFoodItem },
        { "getNumFoodItems", InventoryBinding::getNumFoodItems },
        { "_getBestFoodItem", InventoryBinding::_getBestFoodItem },
        { "_getNumFoodItems", InventoryBinding::_getNumFoodItems },
        { "hasWeaponEquipped", InventoryBinding::hasWeaponEquipped },
        { "equipItem", InventoryBinding::equipItem },
        { "isAContainer", InventoryBinding::isAContainer },
        { "getOwner", InventoryBinding::getOwner },
        { "isEmpty", InventoryBinding::isEmpty },
        { "recalculateTotalWeight", InventoryBinding::recalculateTotalWeight },
        { "getTotalWeight", InventoryBinding::getTotalWeight },
        { "getMoney", InventoryBinding::getMoney },
        { "takeMoney", InventoryBinding::takeMoney },
        { "buyItem", InventoryBinding::buyItem },
        { "getInventoryGUI", InventoryBinding::getInventoryGUI },
        { "isVisible", InventoryBinding::isVisible },
        { "_sectionAddItemCallback", InventoryBinding::_sectionAddItemCallback },
        { "_NV__sectionAddItemCallback", InventoryBinding::_NV__sectionAddItemCallback },
        { "_sectionUpdateItemCallback", InventoryBinding::_sectionUpdateItemCallback },
        { "_NV__sectionUpdateItemCallback", InventoryBinding::_NV__sectionUpdateItemCallback },
        { "_sectionRemoveItemCallback", InventoryBinding::_sectionRemoveItemCallback },
        { "_NV__sectionRemoveItemCallback", InventoryBinding::_NV__sectionRemoveItemCallback },
        { "refreshGui", InventoryBinding::refreshGui },
        { "_NV_refreshGui", InventoryBinding::_NV_refreshGui },
        { "autoArrange", InventoryBinding::autoArrange },
        { "getCallbackObject", InventoryBinding::getCallbackObject },
        { "_addToList", InventoryBinding::_addToList },
        { "_NV__addToList", InventoryBinding::_NV__addToList },
        { "_removeFromList", InventoryBinding::_removeFromList },
        { "_NV__removeFromList", InventoryBinding::_NV__removeFromList },
                { "getHandle", InventoryBinding::getHandle },
        { "loadFrom", InventoryBinding::loadFrom },
        { "fillFromVendorList", InventoryBinding::fillFromVendorList },
        { "getAllSectionsOfType", InventoryBinding::getAllSectionsOfType },
        { "getAllSections", InventoryBinding::getAllSections },
        { "getExcessLoot", InventoryBinding::getExcessLoot },
        { "getResourceItems", InventoryBinding::getResourceItems },
        { "getNumItems", InventoryBinding::getNumItems },
        { "hasItem", InventoryBinding::hasItem },
        { "getAllStolenItems", InventoryBinding::getAllStolenItems },
        { "getAllItemsOfType", InventoryBinding::getAllItemsOfType },
        { "getEquippedWeapons", InventoryBinding::getEquippedWeapons },
        { "getEquippedArmour", InventoryBinding::getEquippedArmour },
        { "takeItem_EntireStack", InventoryBinding::takeItem_EntireStack },
        { "getAllItemsWithFunction", InventoryBinding::getAllItemsWithFunction },
        { "getBestItemWithLowestCharges", InventoryBinding::getBestItemWithLowestCharges },
        { "getAllItems", InventoryBinding::getAllItems },
        { 0, 0 }
    };

    registerClass(
        L, 
        InventoryBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, InventoryBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "hasRoomCache", Inventory_get_hasRoomCache);
    registerGetter(L, "callbackObject", Inventory_get_callbackObject);
    registerGetter(L, "owner", Inventory_get_owner);
    registerGetter(L, "totalWeight", Inventory_get_totalWeight);
    registerGetter(L, "_allItems", Inventory_get__allItems);
    registerGetter(L, "sections", Inventory_get_sections);
    registerGetter(L, "sectionsInSearchOrder", Inventory_get_sectionsInSearchOrder);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "callbackObject", Inventory_set_callbackObject);
    registerSetter(L, "owner", Inventory_set_owner);
    registerSetter(L, "totalWeight", Inventory_set_totalWeight);
    registerSetter(L, "_allItems", Inventory_set__allItems);
    registerSetter(L, "hasRoomCache", Inventory_set_hasRoomCache);
    registerSetter(L, "sections", Inventory_set_sections);
    registerSetter(L, "sectionsInSearchOrder", Inventory_set_sectionsInSearchOrder);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, InventoryBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua