#include "pch.h"
<<<<<<< HEAD:src/Bindings/Equipment/InventoryBinding.cpp
#include "Bindings/Equipment/InventoryBinding.h"
#include "Bindings/Equipment/ItemBinding.h"
#include "Bindings/Core/RootObjectBinding.h"
#include "Bindings/Character/CharacterBinding.h"
=======
#include "Bindings/FactionBinding.h"

#include "kenshi\Inventory.h"
#include "InventoryBinding.h"
#include "RootObjectBinding.h"
#include "InventorySectionBinding.h"
#include "kenshi/Gear.h"
#include "WeaponBinding.h"
#include "kenshi/Item.h"
#include "ItemBinding.h"
>>>>>>> main:src/Bindings/InventoryBinding.cpp
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/InventorySectionBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/WeaponBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/Templates/LektorBinding.h"
#include "kenshi/GameSaveState.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/Templates/OgreUnorderedBinding.h"
#include "Bindings/HasRoomCacheBinding.h"
#include "Bindings/Templates/BoostUnorderedBinding.h"

namespace KenshiLua
{

static Inventory* getB(lua_State* L, int idx)
{
    return checkObject<Inventory>(L, idx, InventoryBinding::getMetatableName());
}

// --- Getters for Inventory ---
static int Inventory_get_hasRoomCache(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    return pushObject<Inventory::HasRoomCache>(L, b->hasRoomCache, HasRoomCacheBinding::getMetatableName());
}

static int Inventory_get__allItems(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    return pushObject<lektor<Item*>>(L, &b->_allItems, LektorPtrBinding<Item*>::metaName);
}

static int Inventory_get_sections(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    lua_newtable(L);
    typedef BoostUnorderedMapBinding<std::string, InventorySection*>::MapType SectionsMap;
    for (SectionsMap::const_iterator it = b->sections.begin(); it != b->sections.end(); ++it)
    {
        pushObject<InventorySection>(L, it->second, InventorySectionBinding::getMetatableName());
        lua_setfield(L, -2, it->first.c_str());
    }
    return 1;
}

<<<<<<< HEAD:src/Bindings/Equipment/InventoryBinding.cpp

    int InventoryBinding::gc(lua_State* L) { return noopGc(L); }

    int InventoryBinding::tostring(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        return genericTostringPtr(L, "%s", inv);
=======
static int Inventory_get_sectionsInSearchOrder(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    return pushObject<lektor<InventorySection*>>(L, &b->sectionsInSearchOrder, LektorPtrBinding<InventorySection*>::metaName);
}

static int Inventory_get_callbackObject(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    return pushObject<RootObject>(L, b->callbackObject, RootObjectBinding::getMetatableName());
}

static int Inventory_get_owner(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    return pushObject<RootObject>(L, b->owner, RootObjectBinding::getMetatableName());
}

static int Inventory_get_totalWeight(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    lua_pushnumber(L, b->totalWeight);
    return 1;
}

// --- Setters for Inventory ---
static int Inventory_set_hasRoomCache(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Inventory::HasRoomCache* cache = nullptr;
    if (!lua_isnil(L, 2)) {
        cache = checkObject<Inventory::HasRoomCache>(L, 2, HasRoomCacheBinding::getMetatableName());
>>>>>>> main:src/Bindings/InventoryBinding.cpp
    }
    b->hasRoomCache = cache;
    return 0;
}

static int Inventory_set__allItems(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    return luaL_error(L, "Read-only or unsupported setter type for _allItems");
}

static int Inventory_set_sections(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    return luaL_error(L, "Read-only or unsupported setter type for sections");
}

static int Inventory_set_sectionsInSearchOrder(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    return luaL_error(L, "Read-only or unsupported setter type for sectionsInSearchOrder");
}

static int Inventory_set_callbackObject(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    RootObject* obj = nullptr;
    if (!lua_isnil(L, 2)) {
        obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    }
    b->callbackObject = obj;
    return 0;
}

static int Inventory_set_owner(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    RootObject* obj = nullptr;
    if (!lua_isnil(L, 2)) {
        obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    }
    b->owner = obj;
    return 0;
}

static int Inventory_set_totalWeight(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    b->totalWeight = (float)luaL_checknumber(L, 2);
    return 0;
}

// --- Methods for Inventory ---
int InventoryBinding::_DESTRUCTOR(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    b->_DESTRUCTOR();
    return 0;
}

int InventoryBinding::clearAll(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    bool destroy = lua_toboolean(L, 2) != 0;
    bool skipUnique = lua_toboolean(L, 3) != 0;
    b->clearAll(destroy, skipUnique);
    return 0;
}

int InventoryBinding::notifyModified(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    b->notifyModified();
    return 0;
}

int InventoryBinding::initialiseNewSection(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    std::string name = luaL_checkstring(L, 2);
    int w = (int)luaL_checkinteger(L, 3);
    int h = (int)luaL_checkinteger(L, 4);
    AttachSlot limitSlot = (AttachSlot)luaL_checkinteger(L, 5);
    bool equipCallbacks = lua_toboolean(L, 6) != 0;
    bool isContainerSlot = lua_toboolean(L, 7) != 0;
    bool enabled = lua_toboolean(L, 8) != 0;
    int limit = (int)luaL_checkinteger(L, 9);
    InventorySection* result = b->initialiseNewSection(name, w, h, limitSlot, equipCallbacks, isContainerSlot, enabled, limit);
    return pushObject<InventorySection>(L, result, InventorySectionBinding::getMetatableName());
}

int InventoryBinding::_NV_initialiseNewSection(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    std::string name = luaL_checkstring(L, 2);
    int w = (int)luaL_checkinteger(L, 3);
    int h = (int)luaL_checkinteger(L, 4);
    AttachSlot limitSlot = (AttachSlot)luaL_checkinteger(L, 5);
    bool equipCallbacks = lua_toboolean(L, 6) != 0;
    bool isContainerSlot = lua_toboolean(L, 7) != 0;
    bool enabled = lua_toboolean(L, 8) != 0;
    int limit = (int)luaL_checkinteger(L, 9);
    InventorySection* result = b->_NV_initialiseNewSection(name, w, h, limitSlot, equipCallbacks, isContainerSlot, enabled, limit);
    return pushObject<InventorySection>(L, result, InventorySectionBinding::getMetatableName());
}

int InventoryBinding::removeAllSections(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    b->removeAllSections();
    return 0;
}

int InventoryBinding::getSection(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    std::string name = luaL_checkstring(L, 2);
    InventorySection* result = b->getSection(name);
    return pushObject<InventorySection>(L, result, InventorySectionBinding::getMetatableName());
}

int InventoryBinding::getSectionOfType(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    AttachSlot type = (AttachSlot)luaL_checkinteger(L, 2);
    InventorySection* result = b->getSectionOfType(type);
    return pushObject<InventorySection>(L, result, InventorySectionBinding::getMetatableName());
}

int InventoryBinding::resizeSection(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    InventorySection* sect = checkObject<InventorySection>(L, 2, InventorySectionBinding::getMetatableName());
    int w = (int)luaL_checkinteger(L, 3);
    int h = (int)luaL_checkinteger(L, 4);
    bool clearContent = lua_toboolean(L, 5) != 0;

    b->resizeSection(sect, w, h, clearContent);
    return 0;
}

int InventoryBinding::getCallbackCharacter(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    Character* result = b->getCallbackCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int InventoryBinding::hasItemType(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    itemType item = (itemType)luaL_checkinteger(L, 2);
    bool skipEquipped = lua_toboolean(L, 3) != 0;
    bool result = b->hasItemType(item, skipEquipped);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::hasStolenItems(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    bool result = b->hasStolenItems();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::getSecondaryWeapon(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    Weapon* result = b->getSecondaryWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int InventoryBinding::getPrimaryWeapon(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    Weapon* result = b->getPrimaryWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int InventoryBinding::hasItemFunction(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    ItemFunction type = (ItemFunction)luaL_checkinteger(L, 2);
    bool result = b->hasItemFunction(type);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::getBestItemWithFunction(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    ItemFunction type = (ItemFunction)luaL_checkinteger(L, 2);
    Item* result = b->getBestItemWithFunction(type);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int InventoryBinding::hasWeaponEquipped(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    bool result = b->hasWeaponEquipped();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::isAContainer(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    bool result = b->isAContainer();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::getOwner(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    RootObject* result = b->getOwner();
    return pushObject<RootObject>(L, result, RootObjectBinding::getMetatableName());
}

int InventoryBinding::isEmpty(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    bool result = b->isEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::recalculateTotalWeight(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    b->recalculateTotalWeight();
    return 0;
}

int InventoryBinding::getTotalWeight(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    float result = b->getTotalWeight();
    lua_pushnumber(L, result);
    return 1;
}

int InventoryBinding::getMoney(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    int result = b->getMoney();
    lua_pushinteger(L, result);
    return 1;
}

int InventoryBinding::takeMoney(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    int val = (int)luaL_checkinteger(L, 2);
    b->takeMoney(val);
    return 0;
}

int InventoryBinding::isVisible(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    bool result = b->isVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::refreshGui(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    b->refreshGui();
    return 0;
}

int InventoryBinding::_NV_refreshGui(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    b->_NV_refreshGui();
    return 0;
}

int InventoryBinding::autoArrange(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    b->autoArrange();
    return 0;
}

int InventoryBinding::getCallbackObject(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");

    RootObject* result = b->getCallbackObject();
    return pushObject<RootObject>(L, result, RootObjectBinding::getMetatableName());
}


int InventoryBinding::getHandle(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    const hand& result = b->getHandle();
    handBinding::push(L, result);
    return 1;
}

int InventoryBinding::addItem(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int quantity = (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) ? (int)luaL_checkinteger(L, 3) : 1;
    bool dropOnFail = (lua_gettop(L) >= 4 && !lua_isnil(L, 4)) ? (lua_toboolean(L, 4) != 0) : false;
    bool destroyOnFail = (lua_gettop(L) >= 5 && !lua_isnil(L, 5)) ? (lua_toboolean(L, 5) != 0) : false;
    bool result = b->addItem(item, quantity, dropOnFail, destroyOnFail);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::_NV_addItem(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int quantity = (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) ? (int)luaL_checkinteger(L, 3) : 1;
    bool dropOnFail = (lua_gettop(L) >= 4 && !lua_isnil(L, 4)) ? (lua_toboolean(L, 4) != 0) : false;
    bool destroyOnFail = (lua_gettop(L) >= 5 && !lua_isnil(L, 5)) ? (lua_toboolean(L, 5) != 0) : false;
    bool result = b->_NV_addItem(item, quantity, dropOnFail, destroyOnFail);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::tryAddItem(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int quantity = (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) ? (int)luaL_checkinteger(L, 3) : 1;
    bool result = b->tryAddItem(item, quantity);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::_NV_tryAddItem(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int quantity = (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) ? (int)luaL_checkinteger(L, 3) : 1;
    bool result = b->_NV_tryAddItem(item, quantity);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::removeItemDontDestroy_returnsItem(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int howmany = (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) ? (int)luaL_checkinteger(L, 3) : 1;
    bool returnCopyIfSomeLeft = (lua_gettop(L) >= 4 && !lua_isnil(L, 4)) ? (lua_toboolean(L, 4) != 0) : false;
    Item* result = b->removeItemDontDestroy_returnsItem(item, howmany, returnCopyIfSomeLeft);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int InventoryBinding::_NV_removeItemDontDestroy_returnsItem(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int howmany = (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) ? (int)luaL_checkinteger(L, 3) : 1;
    bool returnCopyIfSomeLeft = (lua_gettop(L) >= 4 && !lua_isnil(L, 4)) ? (lua_toboolean(L, 4) != 0) : false;
    Item* result = b->_NV_removeItemDontDestroy_returnsItem(item, howmany, returnCopyIfSomeLeft);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int InventoryBinding::removeItemAutoDestroy(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int howmany = (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) ? (int)luaL_checkinteger(L, 3) : 1;
    bool result = b->removeItemAutoDestroy(item, howmany);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::_NV_removeItemAutoDestroy(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int howmany = (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) ? (int)luaL_checkinteger(L, 3) : 1;
    bool result = b->_NV_removeItemAutoDestroy(item, howmany);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::dropItem(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    b->dropItem(item);
    return 0;
}

int InventoryBinding::_NV_dropItem(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    b->_NV_dropItem(item);
    return 0;
}

int InventoryBinding::getItem(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Item* result = b->getItem(data);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int InventoryBinding::_CONSTRUCTOR(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    RootObject* owner = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    Inventory* result = b->_CONSTRUCTOR(owner);
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int InventoryBinding::serialise(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* refList = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    GameData* result = b->serialise(container, refList);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int InventoryBinding::loadFrom(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    if (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) {
        GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
        GameData* inventoryState = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
        b->loadFrom(container, inventoryState);
    } else {
        GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
        b->loadFrom(state);
    }
    return 0;
}

int InventoryBinding::fillFromVendorList(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Faction* f = checkObject<Faction>(L, 3, FactionBinding::getMetatableName());
    if (lua_isuserdata(L, 2)) {
        lua_getmetatable(L, 2);
        luaL_getmetatable(L, GameDataBinding::getMetatableName());
        bool isGameData = lua_rawequal(L, -1, -2) != 0;
        lua_pop(L, 2);
<<<<<<< HEAD:src/Bindings/Equipment/InventoryBinding.cpp

        Inventory* inv = getInv(L, 1);
        if (!inv) { lua_pushnil(L); return 1; }

        // TODO std::map<GameData*, bool, std::less<GameData*>, std::allocator<std::pair<GameData*const, bool> > > itemStates; unsupported __index type from header line 156
        if (strcmp(key, "hasRoomCache") == 0) { lua_pushinteger(L, (lua_Integer)inv->hasRoomCache); return 1; }
        // TODO lektor<Item*> _allItems; unsupported __index type from header line 232
        // TODO boost::unordered::unordered_map<std::string, InventorySection*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, InventorySection*>, Ogre::GeneralAllocPolicy > > sections; unsupported __index type from header line 233
        // TODO lektor<InventorySection*> sectionsInSearchOrder; unsupported __index type from header line 234
        if (strcmp(key, "callbackObject") == 0) { return RootObjectBinding::pushRootObject(L, inv->callbackObject); }
        if (strcmp(key, "owner") == 0) { return RootObjectBinding::pushRootObject(L, inv->owner); }
        if (strcmp(key, "totalWeight") == 0) { lua_pushnumber(L, inv->totalWeight); return 1; }

        lua_pushnil(L);
        return 1;
=======
        if (isGameData) {
            GameData* vendorData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
            b->fillFromVendorList(vendorData, f);
        } else {
            lektor<GameData*>* list = LektorPtrBinding<GameData*>::get(L, 2);
            b->fillFromVendorList(*list, f);
        }
>>>>>>> main:src/Bindings/InventoryBinding.cpp
    }
    return 0;
}

<<<<<<< HEAD:src/Bindings/Equipment/InventoryBinding.cpp
    int InventoryBinding::newindex(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        // TODO std::map<GameData*, bool, std::less<GameData*>, std::allocator<std::pair<GameData*const, bool> > > itemStates; unsupported __newindex type from header line 156
        // TODO Inventory::HasRoomCache* hasRoomCache; unsupported __newindex type from header line 169
        // TODO lektor<Item*> _allItems; unsupported __newindex type from header line 232
        // TODO boost::unordered::unordered_map<std::string, InventorySection*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, InventorySection*>, Ogre::GeneralAllocPolicy > > sections; unsupported __newindex type from header line 233
        // TODO lektor<InventorySection*> sectionsInSearchOrder; unsupported __newindex type from header line 234
        // TODO RootObject* callbackObject; unsupported __newindex type from header line 235
        // TODO RootObject* owner; unsupported __newindex type from header line 236
        if (strcmp(key, "totalWeight") == 0) { inv->totalWeight = (float)luaL_checknumber(L, 3); return 0; }
=======
int InventoryBinding::getAllSectionsOfType(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    lektor<InventorySection*>* out = LektorPtrBinding<InventorySection*>::get(L, 2);
    AttachSlot type = (AttachSlot)luaL_checkinteger(L, 3);
    b->getAllSectionsOfType(*out, type);
    return 0;
}

int InventoryBinding::getAllSections(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    lektor<InventorySection*>& result = b->getAllSections();
    return pushObject<lektor<InventorySection*>>(L, &result, LektorPtrBinding<InventorySection*>::metaName);
}
>>>>>>> main:src/Bindings/InventoryBinding.cpp

int InventoryBinding::getExcessLoot(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    hand* me = checkObject<hand>(L, 2, handBinding::getMetatableName());
    lektor<Item*>* out = LektorPtrBinding<Item*>::get(L, 3);
    bool justAsking = lua_toboolean(L, 4) != 0;
    bool result = b->getExcessLoot(*me, *out, justAsking);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

<<<<<<< HEAD:src/Bindings/Equipment/InventoryBinding.cpp
    int InventoryBinding::_DESTRUCTOR(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        inv->_DESTRUCTOR();
        return 0;
    }

    int InventoryBinding::clearAll(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        bool destroy = lua_toboolean(L, 2) != 0;
        bool skipUnique = lua_toboolean(L, 3) != 0;
        inv->clearAll(destroy, skipUnique);
        return 0;
    }

    int InventoryBinding::notifyModified(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        inv->notifyModified();
        return 0;
    }

    int InventoryBinding::removeAllSections(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        inv->removeAllSections();
        return 0;
    }

    int InventoryBinding::getSection(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        std::string name = luaL_checkstring(L, 2);
        InventorySection* result = inv->getSection(name);
        return pushObject<InventorySection>(L, result, InventorySectionBinding::getMetatableName());
    }

    int InventoryBinding::getCallbackCharacter(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        Character* result = inv->getCallbackCharacter();
        return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
    }

    int InventoryBinding::hasItemType(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        itemType item = (itemType)luaL_checkinteger(L, 2);
        bool skipEquipped = lua_toboolean(L, 3) != 0;
        bool result = inv->hasItemType(item, skipEquipped);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int InventoryBinding::hasStolenItems(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        bool result = inv->hasStolenItems();
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int InventoryBinding::getSecondaryWeapon(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        Weapon* result = inv->getSecondaryWeapon();
        return ItemBinding::pushItem(L, (Item*)result);
    }

    int InventoryBinding::getPrimaryWeapon(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        Weapon* result = inv->getPrimaryWeapon();
        return ItemBinding::pushItem(L, (Item*)result);
    }


    int InventoryBinding::hasWeaponEquipped(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        bool result = inv->hasWeaponEquipped();
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int InventoryBinding::isAContainer(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        bool result = inv->isAContainer();
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int InventoryBinding::getOwner(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        RootObject* result = inv->getOwner();
        return RootObjectBinding::pushRootObject(L, result);
    }

    int InventoryBinding::isEmpty(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        bool result = inv->isEmpty();
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int InventoryBinding::recalculateTotalWeight(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        inv->recalculateTotalWeight();
        return 0;
    }

    int InventoryBinding::getTotalWeight(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        float result = inv->getTotalWeight();
        lua_pushnumber(L, result);
        return 1;
    }

    int InventoryBinding::getMoney(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        int result = inv->getMoney();
=======
int InventoryBinding::getResourceItems(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    ogre_unordered_set<GameData*>::type* out = OgreUnorderedSetBinding<GameData*>::get(L, 2);
    bool buildingMatsToo = lua_toboolean(L, 3) != 0;
    b->getResourceItems(*out, buildingMatsToo);
    return 0;
}

int InventoryBinding::getNumItems(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    if (lua_gettop(L) >= 2 && !lua_isnil(L, 2)) {
        GameData* itemType = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
        int result = b->getNumItems(itemType);
        lua_pushinteger(L, result);
    } else {
        int result = b->getNumItems();
>>>>>>> main:src/Bindings/InventoryBinding.cpp
        lua_pushinteger(L, result);
    }
    return 1;
}

<<<<<<< HEAD:src/Bindings/Equipment/InventoryBinding.cpp
    int InventoryBinding::takeMoney(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        int val = (int)luaL_checkinteger(L, 2);
        inv->takeMoney(val);
        return 0;
    }

    int InventoryBinding::isVisible(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        bool result = inv->isVisible();
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int InventoryBinding::refreshGui(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        inv->refreshGui();
        return 0;
    }

    int InventoryBinding::_NV_refreshGui(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        inv->_NV_refreshGui();
        return 0;
    }

    int InventoryBinding::autoArrange(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        inv->autoArrange();
        return 0;
    }

    int InventoryBinding::getCallbackObject(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        RootObject* result = inv->getCallbackObject();
        return RootObjectBinding::pushRootObject(L, result);
    }


    /*
    Skipped methods needing manual binding:
    line 125: Inventory* _CONSTRUCTOR(...) - unsupported arg type
    line 128: const hand& getHandle(...) - reference return type
    line 130: GameData* serialise(...) - unsupported arg type
    line 131: void loadFrom(...) - overloaded method
    line 132: void loadFrom(...) - overloaded method
    line 134: void fillFromVendorList(...) - overloaded method
    line 135: void fillFromVendorList(...) - overloaded method
    line 136: InventorySection* initialiseNewSection(...) - unsupported arg type
    line 137: InventorySection* _NV_initialiseNewSection(...) - unsupported arg type
    line 138: void resizeSection(...) - unsupported arg type
    line 141: InventorySection* getSectionOfType(...) - unsupported arg type
    line 142: void getAllSectionsOfType(...) - unsupported arg type
    line 143: lektor<InventorySection*>& getAllSections(...) - reference return type
    line 144: bool getExcessLoot(...) - unsupported arg type
    line 145: void getResourceItems(...) - unsupported arg type
    line 146: int getNumItems(...) - overloaded method
    line 147: int getNumItems(...) - overloaded method
    line 149: bool addItem(...) - unsupported arg type
    line 150: bool _NV_addItem(...) - unsupported arg type
    line 151: bool tryAddItem(...) - unsupported arg type
    line 152: bool _NV_tryAddItem(...) - unsupported arg type
    line 170: bool hasRoomForItem(...) - unsupported arg type
    line 171: bool _NV_hasRoomForItem(...) - unsupported arg type
    line 172: Item* removeItemDontDestroy_returnsItem(...) - unsupported arg type
    line 173: Item* _NV_removeItemDontDestroy_returnsItem(...) - unsupported arg type
    line 174: bool removeItemAutoDestroy(...) - unsupported arg type
    line 175: bool _NV_removeItemAutoDestroy(...) - unsupported arg type
    line 176: void dropItem(...) - unsupported arg type
    line 177: void _NV_dropItem(...) - unsupported arg type
    line 178: bool transferMouseItem(...) - unsupported arg type
    line 179: bool hasItem(...) - overloaded method
    line 180: bool hasItem(...) - overloaded method
    line 181: int countItems(...) - unsupported arg type
    line 182: Item* getItem(...) - unsupported arg type
    line 184: void getAllStolenItems(...) - unsupported arg type
    line 186: void getAllItemsOfType(...) - unsupported arg type
    line 187: void getEquippedWeapons(...) - unsupported arg type
    line 190: void getEquippedArmour(...) - unsupported arg type
    line 191: Item* takeOneItemOnly(...) - unsupported arg type
    line 192: bool deathCheck(...) - unsupported arg type
    line 193: bool takeItem_EntireStack(...) - overloaded method
    line 194: Item* takeItem_EntireStack(...) - overloaded method
    line 195: bool hasItemFunction(...) - unsupported arg type
    line 196: void getAllItemsWithFunction(...) - unsupported arg type
    line 197: Item* getBestItemWithFunction(...) - unsupported arg type
    line 198: Item* getBestItemWithLowestCharges(...) - overloaded method
    line 199: Item* getBestItemWithLowestCharges(...) - overloaded method
    line 200: Item* getBestFoodItem(...) - unsupported arg type
    line 201: int getNumFoodItems(...) - unsupported arg type
    line 202: Item* _getBestFoodItem(...) - unsupported arg type
    line 203: int _getNumFoodItems(...) - unsupported arg type
    line 205: bool equipItem(...) - unsupported arg type
    line 214: Item* buyItem(...) - unsupported arg type
    line 215: InventoryGUI* getInventoryGUI(...) - unsupported return type
    line 217: void _sectionAddItemCallback(...) - unsupported arg type
    line 218: void _NV__sectionAddItemCallback(...) - unsupported arg type
    line 219: void _sectionUpdateItemCallback(...) - unsupported arg type
    line 220: void _NV__sectionUpdateItemCallback(...) - unsupported arg type
    line 221: void _sectionRemoveItemCallback(...) - unsupported arg type
    line 222: void _NV__sectionRemoveItemCallback(...) - unsupported arg type
    line 227: const lektor<Item*>& getAllItems(...) - reference return type
    line 228: void _addToList(...) - unsupported arg type
    line 229: void _NV__addToList(...) - unsupported arg type
    line 230: void _removeFromList(...) - unsupported arg type
    line 231: void _NV__removeFromList(...) - unsupported arg type
    */

    void InventoryBinding::registerBinding(lua_State* L)
    {
        static const luaL_Reg meta[] = {
            { "__gc",       InventoryBinding::gc },
            { "__tostring", InventoryBinding::tostring },
            { 0, 0 }
        };
        static const luaL_Reg methods[] = {
            { "_DESTRUCTOR", InventoryBinding::_DESTRUCTOR },
            { "clearAll", InventoryBinding::clearAll },
            { "notifyModified", InventoryBinding::notifyModified },
            { "removeAllSections", InventoryBinding::removeAllSections },
            { "getSection", InventoryBinding::getSection },
            { "getCallbackCharacter", InventoryBinding::getCallbackCharacter },
            { "hasItemType", InventoryBinding::hasItemType },
            { "hasStolenItems", InventoryBinding::hasStolenItems },
            { "getSecondaryWeapon", InventoryBinding::getSecondaryWeapon },
            { "getPrimaryWeapon", InventoryBinding::getPrimaryWeapon },
            { "hasWeaponEquipped", InventoryBinding::hasWeaponEquipped },
            { "isAContainer", InventoryBinding::isAContainer },
            { "getOwner", InventoryBinding::getOwner },
            { "isEmpty", InventoryBinding::isEmpty },
            { "recalculateTotalWeight", InventoryBinding::recalculateTotalWeight },
            { "getTotalWeight", InventoryBinding::getTotalWeight },
            { "getMoney", InventoryBinding::getMoney },
            { "takeMoney", InventoryBinding::takeMoney },
            { "isVisible", InventoryBinding::isVisible },
            { "refreshGui", InventoryBinding::refreshGui },
            { "_NV_refreshGui", InventoryBinding::_NV_refreshGui },
            { "autoArrange", InventoryBinding::autoArrange },
            { "getCallbackObject", InventoryBinding::getCallbackObject },
            { 0, 0 }
        };

        registerClass(L, InventoryBinding::getMetatableName(),
            meta, methods,
            InventoryBinding::index,
            InventoryBinding::newindex);
    }

// ----------------------------------
// InventorySectionBinding
// ----------------------------------

    static InventorySection* getIS(lua_State* L, int idx)
    {
        return checkObject<InventorySection>(L, idx, InventorySectionBinding::getMetatableName());
    }

    int InventorySectionBinding::gc(lua_State* L) { return noopGc(L); }

    int InventorySectionBinding::tostring(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        return genericTostringPtr(L, "%s", s);
    }

    int InventorySectionBinding::index(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);

        luaL_getmetatable(L, InventorySectionBinding::getMetatableName());
        lua_getfield(L, -1, key);
        if (!lua_isnil(L, -1))
            return 1;
        lua_pop(L, 2);

        InventorySection* s = getIS(L, 1);
        if (!s) { lua_pushnil(L); return 1; }

        if (strcmp(key, "name") == 0) { lua_pushstring(L, s->name.c_str()); return 1; }
        if (strcmp(key, "width") == 0) { lua_pushinteger(L, s->width); return 1; }
        if (strcmp(key, "height") == 0) { lua_pushinteger(L, s->height); return 1; }
        if (strcmp(key, "armourOnly") == 0) { lua_pushboolean(L, s->armourOnly ? 1 : 0); return 1; }
        // TODO Ogre::vector<InventorySection::SectionItem>::type items; unsupported __index type from header line 94
        // TODO Array2d<Item> content; unsupported __index type from header line 95
        if (strcmp(key, "stackingBonusMin") == 0) { lua_pushinteger(L, s->stackingBonusMin); return 1; }
        if (strcmp(key, "stackingBonusMult") == 0) { lua_pushnumber(L, s->stackingBonusMult); return 1; }
        // TODO lektor<GameData*> veryLimitedSlot; unsupported __index type from header line 98
        if (strcmp(key, "itemsLimit") == 0) { lua_pushinteger(L, s->itemsLimit); return 1; }
        if (strcmp(key, "weightMultiplier") == 0) { lua_pushnumber(L, s->weightMultiplier); return 1; }
        if (strcmp(key, "totalWeight") == 0) { lua_pushnumber(L, s->totalWeight); return 1; }
        if (strcmp(key, "isAnEquippedItemSection") == 0) { lua_pushboolean(L, s->isAnEquippedItemSection ? 1 : 0); return 1; }
        if (strcmp(key, "limitedSlot") == 0) { lua_pushinteger(L, s->limitedSlot); return 1;}
        if (strcmp(key, "containerSlot") == 0) { lua_pushboolean(L, s->containerSlot ? 1 : 0); return 1; }

        // --- unique objects ---
        if (strcmp(key, "callbackObject") == 0) { 
            if (s->callbackObject) return RootObjectBinding::pushRootObject(L, s->callbackObject); else lua_pushnil(L); return 1;
        }
        if (strcmp(key, "parentInventory") == 0) {
            if (s->parentInventory) return pushObject<Inventory>(L, s->parentInventory, InventoryBinding::getMetatableName());
            lua_pushnil(L); return 1;
        }
        if (strcmp(key, "enabled") == 0) { lua_pushboolean(L, s->enabled ? 1 : 0); return 1; }

        lua_pushnil(L);
        return 1;
=======
int InventoryBinding::hasRoomForItem(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = b->hasRoomForItem(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::_NV_hasRoomForItem(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = b->_NV_hasRoomForItem(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::transferMouseItem(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool result = b->transferMouseItem(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::hasItem(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    if (lua_isuserdata(L, 2)) {
        lua_getmetatable(L, 2);
        luaL_getmetatable(L, GameDataBinding::getMetatableName());
        bool isGameData = lua_rawequal(L, -1, -2) != 0;
        lua_pop(L, 2);
        if (isGameData) {
            GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
            int quantity = (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) ? (int)luaL_checkinteger(L, 3) : 1;
            bool result = b->hasItem(data, quantity);
            lua_pushboolean(L, result ? 1 : 0);
        } else {
            Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
            bool result = b->hasItem(item);
            lua_pushboolean(L, result ? 1 : 0);
        }
    } else {
        lua_pushboolean(L, 0);
>>>>>>> main:src/Bindings/InventoryBinding.cpp
    }
    return 1;
}

<<<<<<< HEAD:src/Bindings/Equipment/InventoryBinding.cpp
    int InventorySectionBinding::newindex(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");
=======
int InventoryBinding::countItems(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    int result = b->countItems(item);
    lua_pushinteger(L, result);
    return 1;
}
>>>>>>> main:src/Bindings/InventoryBinding.cpp

int InventoryBinding::getAllStolenItems(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    lektor<Item*>* all = LektorPtrBinding<Item*>::get(L, 2);
    bool includeUnknown = lua_toboolean(L, 3) != 0;
    b->getAllStolenItems(*all, includeUnknown);
    return 0;
}

int InventoryBinding::getAllItemsOfType(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    lektor<Item*>* all = LektorPtrBinding<Item*>::get(L, 2);
    itemType ty = (itemType)luaL_checkinteger(L, 3);
    bool skipEquipped = lua_toboolean(L, 4) != 0;
    b->getAllItemsOfType(*all, ty, skipEquipped);
    return 0;
}

<<<<<<< HEAD:src/Bindings/Equipment/InventoryBinding.cpp
    int InventorySectionBinding::_DESTRUCTOR(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");
=======
int InventoryBinding::getEquippedWeapons(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    lektor<Item*>* all = LektorPtrBinding<Item*>::get(L, 2);
    b->getEquippedWeapons(*all);
    return 0;
}
>>>>>>> main:src/Bindings/InventoryBinding.cpp

int InventoryBinding::getEquippedArmour(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    lektor<Item*>* all = LektorPtrBinding<Item*>::get(L, 2);
    b->getEquippedArmour(*all);
    return 0;
}

<<<<<<< HEAD:src/Bindings/Equipment/InventoryBinding.cpp
    int InventorySectionBinding::notifyModified(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");
=======
int InventoryBinding::takeOneItemOnly(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Item* result = b->takeOneItemOnly(item);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}
>>>>>>> main:src/Bindings/InventoryBinding.cpp

int InventoryBinding::deathCheck(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool result = b->deathCheck(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

<<<<<<< HEAD:src/Bindings/Equipment/InventoryBinding.cpp
    int InventorySectionBinding::getItemAt(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        int x = (int)luaL_checkinteger(L, 2);
        int y = (int)luaL_checkinteger(L, 3);
        Item* result = s->getItemAt(x, y);
        return pushObject<Item>(L, result, ItemBinding::getMetatableName());
    }

    int InventorySectionBinding::hasItemType(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        itemType type = (itemType)luaL_checkinteger(L, 2);
        bool result = s->hasItemType(type);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int InventorySectionBinding::autoArrange(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        s->autoArrange();
        return 0;
    }

    int InventorySectionBinding::_NV_autoArrange(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        s->_NV_autoArrange();
        return 0;
    }

    int InventorySectionBinding::getNumItems(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        unsigned int result = s->getNumItems();
        lua_pushinteger(L, result);
        return 1;
    }

    int InventorySectionBinding::isEmpty(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        bool result = s->isEmpty();
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int InventorySectionBinding::clearAllItems(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        bool destroy = lua_toboolean(L, 2) != 0;
        bool skipUnique = lua_toboolean(L, 3) != 0;
        s->clearAllItems(destroy, skipUnique);
        return 0;
    }

    int InventorySectionBinding::applyStackingBonuses(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        int normalStackableAmount = (int)luaL_checkinteger(L, 2);
        int result = s->applyStackingBonuses(normalStackableAmount);
        lua_pushinteger(L, result);
        return 1;
    }

    int InventorySectionBinding::recalculateTotalWeight(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        s->recalculateTotalWeight();
        return 0;
    }

    int InventorySectionBinding::setWeightMultiplier(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        float mult = (float)luaL_checknumber(L, 2);
        s->setWeightMultiplier(mult);
        return 0;
    }

    int InventorySectionBinding::setStackingBonus(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        int minn = (int)luaL_checkinteger(L, 2);
        float mult = (float)luaL_checknumber(L, 3);
        s->setStackingBonus(minn, mult);
        return 0;
    }

    int InventorySectionBinding::getMaxStack(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        int result = s->getMaxStack();
        lua_pushinteger(L, result);
        return 1;
    }

    int InventorySectionBinding::clearVeryLimitedSlot(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        s->clearVeryLimitedSlot();
        return 0;
    }

    int InventorySectionBinding::getEnabled(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        bool result = s->getEnabled();
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int InventorySectionBinding::setEnabled(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        bool value = lua_toboolean(L, 2) != 0;
        s->setEnabled(value);
        return 0;
    }

    int InventorySectionBinding::setItemsLimitCount(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        int value = (int)luaL_checkinteger(L, 2);
        s->setItemsLimitCount(value);
        return 0;
    }

    int InventorySectionBinding::getItemsLimitReached(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        bool result = s->getItemsLimitReached();
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int InventorySectionBinding::getInventory(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        Inventory* result = s->getInventory();
        return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
    }

    int InventorySectionBinding::getFillPercentage(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        float result = s->getFillPercentage();
        lua_pushnumber(L, result);
        return 1;
    }

    int InventorySectionBinding::getItem(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        Item* result = s->getItem();
        return pushObject<Item>(L, result, ItemBinding::getMetatableName());
    }

    int InventorySectionBinding::resize(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        int w = (int)luaL_checkinteger(L, 2);
        int h = (int)luaL_checkinteger(L, 3);
        bool clearContent = lua_toboolean(L, 4) != 0;
        s->resize(w, h, clearContent);
        return 0;
    }

    /*
    Skipped methods needing manual binding:
    line 34: InventorySection* _CONSTRUCTOR(...) - unsupported arg type
    line 37: bool hasRoomForItem(...) - unsupported arg type
    line 38: bool _NV_hasRoomForItem(...) - unsupported arg type
    line 40: bool addItem(...) - unsupported arg type
    line 41: bool _NV_addItem(...) - unsupported arg type
    line 42: void _addItem(...) - unsupported arg type
    line 43: void _NV__addItem(...) - unsupported arg type
    line 46: bool hasItem(...) - overloaded method
    line 47: bool hasItem(...) - overloaded method
    line 51: void getAllItemsOfType(...) - overloaded method
    line 52: void getAllItemsOfType(...) - overloaded method
    line 53: void getAllItemsOfName(...) - unsupported arg type
    line 56: bool removeItem(...) - unsupported arg type
    line 58: bool canItemGoHere(...) - unsupported arg type
    line 59: bool getValidInventoryPosition(...) - unsupported arg type
    line 60: bool findNearestPlaceForItem(...) - unsupported arg type
    line 61: int getItemsInFootprint(...) - overloaded method
    line 62: int getItemsInFootprint(...) - overloaded method
    line 63: bool existsItemInFootprint(...) - unsupported arg type
    line 64: AttachSlot getLimitedSlot(...) - unsupported return type
    line 65: void setupContainerData(...) - unsupported arg type
    line 72: void addVeryLimitedSlot(...) - unsupported arg type
    line 74: const lektor<GameData*>& getVeryLimitedSlot(...) - reference return type
    line 75: bool isLimitedSlotCompatible(...) - overloaded method
    line 76: bool isLimitedSlotCompatible(...) - overloaded method
    line 85: const Ogre::vector<InventorySection::SectionItem>::type& getItems(...) - reference return type
    line 91: void setupEquipCallbacks(...) - unsupported arg type
    line 92: int numItemsInFootprint(...) - unsupported arg type
    */


    void InventorySectionBinding::registerBinding(lua_State* L)
    {
        static const luaL_Reg meta[] = {
            { "__gc",       InventorySectionBinding::gc },
            { "__tostring", InventorySectionBinding::tostring },
            { 0, 0 }
        };
        static const luaL_Reg methods[] = {
            { "_DESTRUCTOR", InventorySectionBinding::_DESTRUCTOR },
            { "notifyModified", InventorySectionBinding::notifyModified },
            { "getItemAt", InventorySectionBinding::getItemAt },
            { "hasItemType", InventorySectionBinding::hasItemType },
            { "autoArrange", InventorySectionBinding::autoArrange },
            { "_NV_autoArrange", InventorySectionBinding::_NV_autoArrange },
            { "getNumItems", InventorySectionBinding::getNumItems },
            { "isEmpty", InventorySectionBinding::isEmpty },
            { "clearAllItems", InventorySectionBinding::clearAllItems },
            { "applyStackingBonuses", InventorySectionBinding::applyStackingBonuses },
            { "recalculateTotalWeight", InventorySectionBinding::recalculateTotalWeight },
            { "setWeightMultiplier", InventorySectionBinding::setWeightMultiplier },
            { "setStackingBonus", InventorySectionBinding::setStackingBonus },
            { "getMaxStack", InventorySectionBinding::getMaxStack },
            { "clearVeryLimitedSlot", InventorySectionBinding::clearVeryLimitedSlot },
            { "getEnabled", InventorySectionBinding::getEnabled },
            { "setEnabled", InventorySectionBinding::setEnabled },
            { "setItemsLimitCount", InventorySectionBinding::setItemsLimitCount },
            { "getItemsLimitReached", InventorySectionBinding::getItemsLimitReached },
            { "getInventory", InventorySectionBinding::getInventory },
            { "getFillPercentage", InventorySectionBinding::getFillPercentage },
            { "getItem", InventorySectionBinding::getItem },
            { "resize", InventorySectionBinding::resize },
            { 0, 0 }
        };

        // Pass index/newindex as C functions so that dot-access to raw member
        // fields (e.g. inv.totalWeight) works alongside method call syntax.
        registerClass(L, InventorySectionBinding::getMetatableName(),
            meta, methods,
            InventorySectionBinding::index,
            InventorySectionBinding::newindex);
    }

// ---------------------------------
// SectionItemBinding
// ---------------------------------
    
    static InventorySection::SectionItem* getSecItem(lua_State* L, int idx)
    {
        return checkObject<InventorySection::SectionItem>(L, idx, SectionItemBinding::getMetatableName());
    }

    int SectionItemBinding::gc(lua_State* L) { return noopGc(L); }

    int SectionItemBinding::tostring(lua_State* L)
    {
        InventorySection::SectionItem* s = getSecItem(L, 1);
        return genericTostringPtr(L, "%s", s);
    }

    int SectionItemBinding::index(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);

        luaL_getmetatable(L, SectionItemBinding::getMetatableName());
        lua_getfield(L, -1, key);
        if (!lua_isnil(L, -1))
            return 1;
=======
int InventoryBinding::takeItem_EntireStack(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    if (lua_isuserdata(L, 2)) {
        lua_getmetatable(L, 2);
        luaL_getmetatable(L, GameDataBinding::getMetatableName());
        bool isGameData = lua_rawequal(L, -1, -2) != 0;
>>>>>>> main:src/Bindings/InventoryBinding.cpp
        lua_pop(L, 2);
        if (isGameData) {
            GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
            Item* result = b->takeItem_EntireStack(item);
            return pushObject<Item>(L, result, ItemBinding::getMetatableName());
        } else {
            Item* what = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
            bool result = b->takeItem_EntireStack(what);
            lua_pushboolean(L, result ? 1 : 0);
            return 1;
        }
    }
    return 0;
}

int InventoryBinding::getAllItemsWithFunction(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    lektor<Item*>* out = LektorPtrBinding<Item*>::get(L, 2);
    ItemFunction type = (ItemFunction)luaL_checkinteger(L, 3);
    b->getAllItemsWithFunction(*out, type);
    return 0;
}

int InventoryBinding::getBestItemWithLowestCharges(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    if (lua_isuserdata(L, 2)) {
        lua_getmetatable(L, 2);
        luaL_getmetatable(L, GameDataBinding::getMetatableName());
        bool isGameData = lua_rawequal(L, -1, -2) != 0;
        lua_pop(L, 2);
        if (isGameData) {
            GameData* what = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
            Item* result = b->getBestItemWithLowestCharges(what);
            return pushObject<Item>(L, result, ItemBinding::getMetatableName());
        }
    }
    ItemFunction type = (ItemFunction)luaL_checkinteger(L, 2);
    Item* result = b->getBestItemWithLowestCharges(type);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int InventoryBinding::getBestFoodItem(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Character* race = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    Item* result = b->getBestFoodItem(race);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int InventoryBinding::getNumFoodItems(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Character* race = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    int result = b->getNumFoodItems(race);
    lua_pushinteger(L, result);
    return 1;
}

int InventoryBinding::_getBestFoodItem(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    ItemFunction type = (ItemFunction)luaL_checkinteger(L, 2);
    Character* race = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    Item* result = b->_getBestFoodItem(type, race);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int InventoryBinding::_getNumFoodItems(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    ItemFunction type = (ItemFunction)luaL_checkinteger(L, 2);
    Character* race = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    int result = b->_getNumFoodItems(type, race);
    lua_pushinteger(L, result);
    return 1;
}

int InventoryBinding::equipItem(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool result = b->equipItem(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::buyItem(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* itemToBuy = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    RootObject* sendingTo = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    Item* result = b->buyItem(itemToBuy, sendingTo);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int InventoryBinding::getInventoryGUI(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    InventoryGUI* result = b->getInventoryGUI();
    if (result) {
        lua_pushlightuserdata(L, (void*)result);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

int InventoryBinding::_sectionAddItemCallback(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    b->_sectionAddItemCallback(item);
    return 0;
}

int InventoryBinding::_NV__sectionAddItemCallback(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    b->_NV__sectionAddItemCallback(item);
    return 0;
}

int InventoryBinding::_sectionUpdateItemCallback(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int quantity = (int)luaL_checkinteger(L, 3);
    b->_sectionUpdateItemCallback(item, quantity);
    return 0;
}

int InventoryBinding::_NV__sectionUpdateItemCallback(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int quantity = (int)luaL_checkinteger(L, 3);
    b->_NV__sectionUpdateItemCallback(item, quantity);
    return 0;
}

int InventoryBinding::_sectionRemoveItemCallback(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    b->_sectionRemoveItemCallback(item);
    return 0;
}

int InventoryBinding::_NV__sectionRemoveItemCallback(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    b->_NV__sectionRemoveItemCallback(item);
    return 0;
}

int InventoryBinding::_addToList(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    b->_addToList(item);
    return 0;
}

int InventoryBinding::_NV__addToList(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    b->_NV__addToList(item);
    return 0;
}

int InventoryBinding::_removeFromList(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool checkEverything = lua_toboolean(L, 3) != 0;
    b->_removeFromList(item, checkEverything);
    return 0;
}

int InventoryBinding::_NV__removeFromList(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool checkEverything = lua_toboolean(L, 3) != 0;
    b->_NV__removeFromList(item, checkEverything);
    return 0;
}

int InventoryBinding::getAllItems(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    const lektor<Item*>& result = b->getAllItems();
    return pushObject<lektor<Item*>>(L, const_cast<lektor<Item*>*>(&result), LektorPtrBinding<Item*>::metaName);
}

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

void InventoryBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       InventoryBinding::gc },
        { "__tostring", InventoryBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", InventoryBinding::_DESTRUCTOR },
        { "clearAll", InventoryBinding::clearAll },
        { "notifyModified", InventoryBinding::notifyModified },
        { "initialiseNewSection", InventoryBinding::initialiseNewSection },
        { "_NV_initialiseNewSection", InventoryBinding::_NV_initialiseNewSection },
        { "removeAllSections", InventoryBinding::removeAllSections },
        { "getSection", InventoryBinding::getSection },
        { "getSectionOfType", InventoryBinding::getSectionOfType },
        { "resizeSection", InventoryBinding::resizeSection },
        { "getCallbackCharacter", InventoryBinding::getCallbackCharacter },
        { "hasItemType", InventoryBinding::hasItemType },
        { "hasStolenItems", InventoryBinding::hasStolenItems },
        { "getSecondaryWeapon", InventoryBinding::getSecondaryWeapon },
        { "getPrimaryWeapon", InventoryBinding::getPrimaryWeapon },
        { "hasItemFunction", InventoryBinding::hasItemFunction },
        { "getBestItemWithFunction", InventoryBinding::getBestItemWithFunction },
        { "hasWeaponEquipped", InventoryBinding::hasWeaponEquipped },
        { "isAContainer", InventoryBinding::isAContainer },
        { "getOwner", InventoryBinding::getOwner },
        { "isEmpty", InventoryBinding::isEmpty },
        { "recalculateTotalWeight", InventoryBinding::recalculateTotalWeight },
        { "getTotalWeight", InventoryBinding::getTotalWeight },
        { "getMoney", InventoryBinding::getMoney },
        { "takeMoney", InventoryBinding::takeMoney },
        { "isVisible", InventoryBinding::isVisible },
        { "refreshGui", InventoryBinding::refreshGui },
        { "_NV_refreshGui", InventoryBinding::_NV_refreshGui },
        { "autoArrange", InventoryBinding::autoArrange },
        { "getCallbackObject", InventoryBinding::getCallbackObject },
        { "getHandle", InventoryBinding::getHandle },
        { "addItem", InventoryBinding::addItem },
        { "_NV_addItem", InventoryBinding::_NV_addItem },
        { "tryAddItem", InventoryBinding::tryAddItem },
        { "_NV_tryAddItem", InventoryBinding::_NV_tryAddItem },
        { "removeItemDontDestroy_returnsItem", InventoryBinding::removeItemDontDestroy_returnsItem },
        { "_NV_removeItemDontDestroy_returnsItem", InventoryBinding::_NV_removeItemDontDestroy_returnsItem },
        { "removeItemAutoDestroy", InventoryBinding::removeItemAutoDestroy },
        { "_NV_removeItemAutoDestroy", InventoryBinding::_NV_removeItemAutoDestroy },
        { "dropItem", InventoryBinding::dropItem },
        { "_NV_dropItem", InventoryBinding::_NV_dropItem },
        { "getItem", InventoryBinding::getItem },
        { "_CONSTRUCTOR", InventoryBinding::_CONSTRUCTOR },
        { "serialise", InventoryBinding::serialise },
        { "loadFrom", InventoryBinding::loadFrom },
        { "fillFromVendorList", InventoryBinding::fillFromVendorList },
        { "getAllSectionsOfType", InventoryBinding::getAllSectionsOfType },
        { "getAllSections", InventoryBinding::getAllSections },
        { "getExcessLoot", InventoryBinding::getExcessLoot },
        { "getResourceItems", InventoryBinding::getResourceItems },
        { "getNumItems", InventoryBinding::getNumItems },
        { "hasRoomForItem", InventoryBinding::hasRoomForItem },
        { "_NV_hasRoomForItem", InventoryBinding::_NV_hasRoomForItem },
        { "transferMouseItem", InventoryBinding::transferMouseItem },
        { "hasItem", InventoryBinding::hasItem },
        { "countItems", InventoryBinding::countItems },
        { "getAllStolenItems", InventoryBinding::getAllStolenItems },
        { "getAllItemsOfType", InventoryBinding::getAllItemsOfType },
        { "getEquippedWeapons", InventoryBinding::getEquippedWeapons },
        { "getEquippedArmour", InventoryBinding::getEquippedArmour },
        { "takeOneItemOnly", InventoryBinding::takeOneItemOnly },
        { "deathCheck", InventoryBinding::deathCheck },
        { "takeItem_EntireStack", InventoryBinding::takeItem_EntireStack },
        { "getAllItemsWithFunction", InventoryBinding::getAllItemsWithFunction },
        { "getBestItemWithLowestCharges", InventoryBinding::getBestItemWithLowestCharges },
        { "getBestFoodItem", InventoryBinding::getBestFoodItem },
        { "getNumFoodItems", InventoryBinding::getNumFoodItems },
        { "_getBestFoodItem", InventoryBinding::_getBestFoodItem },
        { "_getNumFoodItems", InventoryBinding::_getNumFoodItems },
        { "equipItem", InventoryBinding::equipItem },
        { "buyItem", InventoryBinding::buyItem },
        { "getInventoryGUI", InventoryBinding::getInventoryGUI },
        { "_sectionAddItemCallback", InventoryBinding::_sectionAddItemCallback },
        { "_NV__sectionAddItemCallback", InventoryBinding::_NV__sectionAddItemCallback },
        { "_sectionUpdateItemCallback", InventoryBinding::_sectionUpdateItemCallback },
        { "_NV__sectionUpdateItemCallback", InventoryBinding::_NV__sectionUpdateItemCallback },
        { "_sectionRemoveItemCallback", InventoryBinding::_sectionRemoveItemCallback },
        { "_NV__sectionRemoveItemCallback", InventoryBinding::_NV__sectionRemoveItemCallback },
        { "_addToList", InventoryBinding::_addToList },
        { "_NV__addToList", InventoryBinding::_NV__addToList },
        { "_removeFromList", InventoryBinding::_removeFromList },
        { "_NV__removeFromList", InventoryBinding::_NV__removeFromList },
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
    lua_pushcfunction(L, Inventory_get_hasRoomCache);
    lua_setfield(L, -2, "hasRoomCache");
    lua_pushcfunction(L, Inventory_get__allItems);
    lua_setfield(L, -2, "_allItems");
    lua_pushcfunction(L, Inventory_get_sections);
    lua_setfield(L, -2, "sections");
    lua_pushcfunction(L, Inventory_get_sectionsInSearchOrder);
    lua_setfield(L, -2, "sectionsInSearchOrder");
    lua_pushcfunction(L, Inventory_get_callbackObject);
    lua_setfield(L, -2, "callbackObject");
    lua_pushcfunction(L, Inventory_get_owner);
    lua_setfield(L, -2, "owner");
    lua_pushcfunction(L, Inventory_get_totalWeight);
    lua_setfield(L, -2, "totalWeight");
    lua_setfield(L, -2, "__getters"); // Bind to metatableUsage

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, Inventory_set_hasRoomCache);
    lua_setfield(L, -2, "hasRoomCache");
    lua_pushcfunction(L, Inventory_set__allItems);
    lua_setfield(L, -2, "_allItems");
    lua_pushcfunction(L, Inventory_set_sections);
    lua_setfield(L, -2, "sections");
    lua_pushcfunction(L, Inventory_set_sectionsInSearchOrder);
    lua_setfield(L, -2, "sectionsInSearchOrder");
    lua_pushcfunction(L, Inventory_set_callbackObject);
    lua_setfield(L, -2, "callbackObject");
    lua_pushcfunction(L, Inventory_set_owner);
    lua_setfield(L, -2, "owner");
    lua_pushcfunction(L, Inventory_set_totalWeight);
    lua_setfield(L, -2, "totalWeight");
    lua_setfield(L, -2, "__setters"); // Bind to metatable



    lua_pop(L, 1); // Pop the metatable off the stack
}

    // ----------------------------------
    // HasRoomCacheBinding
    // ----------------------------------
    
    static Inventory::HasRoomCache* getHRC(lua_State* L, int idx)
{
    return checkObject<Inventory::HasRoomCache>(L, idx, HasRoomCacheBinding::getMetatableName());
}

int HasRoomCacheBinding::gc(lua_State* L) { return noopGc(L); }

int HasRoomCacheBinding::tostring(lua_State* L)
{
    Inventory::HasRoomCache* hrc = getHRC(L, 1);
    return genericTostringPtr(L, "%s", hrc);
}

int HasRoomCacheBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, HasRoomCacheBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    Inventory::HasRoomCache* hrc = getHRC(L, 1);
    if (!hrc) { lua_pushnil(L); return 1; }

    // TODO std::map<GameData*, bool, std::less<GameData*>, std::allocator<std::pair<GameData*const, bool> > > itemStates; unsupported __index type from header line 156

    lua_pushnil(L);
    return 1;
}

int HasRoomCacheBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    Inventory::HasRoomCache* hrc = getHRC(L, 1);
    if (!hrc) return luaL_error(L, "HasRoomCache is nil");

    // TODO std::map<GameData*, bool, std::less<GameData*>, std::allocator<std::pair<GameData*const, bool> > > itemStates; unsupported __newindex type from header line 156

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int HasRoomCacheBinding::modified(lua_State* L)
{
    Inventory::HasRoomCache* hrc = getHRC(L, 1);
    if (!hrc) return luaL_error(L, "HasRoomCache is nil");

    hrc->modified();
    return 0;
}

int HasRoomCacheBinding::_DESTRUCTOR(lua_State* L)
{
    Inventory::HasRoomCache* hrc = getHRC(L, 1);
    if (!hrc) return luaL_error(L, "HasRoomCache is nil");

    hrc->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 158: bool knowsAbout(...) - unsupported arg type
  line 159: bool hasRoomFor(...) - unsupported arg type
  line 160: void remember(...) - unsupported arg type
  line 163: HasRoomCache* _CONSTRUCTOR(...) - unsupported return type
*/

void HasRoomCacheBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       HasRoomCacheBinding::gc },
        { "__tostring", HasRoomCacheBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "modified", HasRoomCacheBinding::modified },
        { "_DESTRUCTOR", HasRoomCacheBinding::_DESTRUCTOR },
        { 0, 0 }
    };
    registerClass(L, HasRoomCacheBinding::getMetatableName(), meta, methods, HasRoomCacheBinding::index, HasRoomCacheBinding::newindex);
}

} // namespace KenshiLua