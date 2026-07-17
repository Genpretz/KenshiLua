#include "pch.h"
#include "Bindings/FactionBinding.h"

#include "kenshi\Inventory.h"
#include "InventoryBinding.h"
#include "RootObjectBinding.h"
#include "InventorySectionBinding.h"
#include "kenshi/Gear.h"
#include "WeaponBinding.h"
#include "kenshi/Item.h"
#include "ItemBinding.h"
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
        if (isGameData) {
            GameData* vendorData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
            b->fillFromVendorList(vendorData, f);
        } else {
            lektor<GameData*>* list = LektorPtrBinding<GameData*>::get(L, 2);
            b->fillFromVendorList(*list, f);
        }
    }
    return 0;
}

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
        lua_pushinteger(L, result);
    }
    return 1;
}

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
    }
    return 1;
}

int InventoryBinding::countItems(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    int result = b->countItems(item);
    lua_pushinteger(L, result);
    return 1;
}

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

int InventoryBinding::getEquippedWeapons(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    lektor<Item*>* all = LektorPtrBinding<Item*>::get(L, 2);
    b->getEquippedWeapons(*all);
    return 0;
}

int InventoryBinding::getEquippedArmour(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    lektor<Item*>* all = LektorPtrBinding<Item*>::get(L, 2);
    b->getEquippedArmour(*all);
    return 0;
}

int InventoryBinding::takeOneItemOnly(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Item* result = b->takeOneItemOnly(item);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int InventoryBinding::deathCheck(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool result = b->deathCheck(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryBinding::takeItem_EntireStack(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    if (lua_isuserdata(L, 2)) {
        lua_getmetatable(L, 2);
        luaL_getmetatable(L, GameDataBinding::getMetatableName());
        bool isGameData = lua_rawequal(L, -1, -2) != 0;
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

} // namespace KenshiLua