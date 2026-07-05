#include "pch.h"
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
#include "Bindings/Util/LektorBinding.h"

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
    lua_pushinteger(L, (lua_Integer)b->hasRoomCache);
    return 1;
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
    typedef boost::unordered::unordered_map<std::string, InventorySection*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, InventorySection*>, Ogre::GeneralAllocPolicy > > SectionsMap;
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
    return luaL_error(L, "Read-only or unsupported setter type for hasRoomCache");
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
    return luaL_error(L, "Read-only or unsupported setter type for callbackObject");
}

static int Inventory_set_owner(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    return luaL_error(L, "Read-only or unsupported setter type for owner");
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

/*
Skipped methods needing manual binding:
  line 125: Inventory* _CONSTRUCTOR(...) - unsupported arg type
  line 128: const hand& getHandle(...) - reference return type
  line 130: GameData* serialise(...) - unsupported arg type
  line 131: void loadFrom(...) - overloaded method
  line 132: void loadFrom(...) - overloaded method
  line 134: void fillFromVendorList(...) - overloaded method
  line 135: void fillFromVendorList(...) - overloaded method
  line 138: void resizeSection(...) - unsupported arg type
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
  line 196: void getAllItemsWithFunction(...) - unsupported arg type
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

static int Inventory_getHandle(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    const hand& result = b->getHandle();
    handBinding::push(L, result);
    return 1;
}

static int Inventory_addItem(lua_State* L)
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

static int Inventory__NV_addItem(lua_State* L)
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

static int Inventory_tryAddItem(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int quantity = (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) ? (int)luaL_checkinteger(L, 3) : 1;
    bool result = b->tryAddItem(item, quantity);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

static int Inventory__NV_tryAddItem(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int quantity = (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) ? (int)luaL_checkinteger(L, 3) : 1;
    bool result = b->_NV_tryAddItem(item, quantity);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

static int Inventory_removeItemDontDestroy_returnsItem(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int howmany = (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) ? (int)luaL_checkinteger(L, 3) : 1;
    bool returnCopyIfSomeLeft = (lua_gettop(L) >= 4 && !lua_isnil(L, 4)) ? (lua_toboolean(L, 4) != 0) : false;
    Item* result = b->removeItemDontDestroy_returnsItem(item, howmany, returnCopyIfSomeLeft);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

static int Inventory__NV_removeItemDontDestroy_returnsItem(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int howmany = (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) ? (int)luaL_checkinteger(L, 3) : 1;
    bool returnCopyIfSomeLeft = (lua_gettop(L) >= 4 && !lua_isnil(L, 4)) ? (lua_toboolean(L, 4) != 0) : false;
    Item* result = b->_NV_removeItemDontDestroy_returnsItem(item, howmany, returnCopyIfSomeLeft);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

static int Inventory_removeItemAutoDestroy(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int howmany = (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) ? (int)luaL_checkinteger(L, 3) : 1;
    bool result = b->removeItemAutoDestroy(item, howmany);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

static int Inventory__NV_removeItemAutoDestroy(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int howmany = (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) ? (int)luaL_checkinteger(L, 3) : 1;
    bool result = b->_NV_removeItemAutoDestroy(item, howmany);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

static int Inventory_dropItem(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    b->dropItem(item);
    return 0;
}

static int Inventory__NV_dropItem(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    b->_NV_dropItem(item);
    return 0;
}

static int Inventory_getItem(lua_State* L)
{
    Inventory* b = getB(L, 1);
    if (!b) return luaL_error(L, "Inventory is nil");
    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Item* result = b->getItem(data);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
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
        { "getHandle", Inventory_getHandle },
        { "addItem", Inventory_addItem },
        { "_NV_addItem", Inventory__NV_addItem },
        { "tryAddItem", Inventory_tryAddItem },
        { "_NV_tryAddItem", Inventory__NV_tryAddItem },
        { "removeItemDontDestroy_returnsItem", Inventory_removeItemDontDestroy_returnsItem },
        { "_NV_removeItemDontDestroy_returnsItem", Inventory__NV_removeItemDontDestroy_returnsItem },
        { "removeItemAutoDestroy", Inventory_removeItemAutoDestroy },
        { "_NV_removeItemAutoDestroy", Inventory__NV_removeItemAutoDestroy },
        { "dropItem", Inventory_dropItem },
        { "_NV_dropItem", Inventory__NV_dropItem },
        { "getItem", Inventory_getItem },
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
    lua_setfield(L, -2, "__getters"); // Bind to metatable

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

    LektorPtrBinding<Item*>::registerBinding(L, "lektor<Item*>", ItemBinding::getMetatableName());
    LektorPtrBinding<InventorySection*>::registerBinding(L, "lektor<InventorySection*>", InventorySectionBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua