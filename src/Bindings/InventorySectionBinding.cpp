#include "pch.h"
#include "kenshi\Inventory.h"
#include "InventorySectionBinding.h"
#include "RootObjectBinding.h"
#include "InventoryBinding.h"
#include "ItemBinding.h"
#include "Lua/BindingHelpers.h"
#include "GameDataBinding.h"

namespace KenshiLua
{

static InventorySection* getB(lua_State* L, int idx)
{
    return checkObject<InventorySection>(L, idx, InventorySectionBinding::getMetatableName());
}

// --- Getters for InventorySection ---
static int InventorySection_get_name(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    lua_pushstring(L, b->name.c_str());
    return 1;
}

static int InventorySection_get_width(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    lua_pushinteger(L, b->width);
    return 1;
}

static int InventorySection_get_height(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    lua_pushinteger(L, b->height);
    return 1;
}

static int InventorySection_get_armourOnly(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    lua_pushboolean(L, b->armourOnly ? 1 : 0);
    return 1;
}

static int InventorySection_get_items(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    // TODO: Unsupported type for items (Ogre::vector<InventorySection::SectionItem>::type)
    return luaL_error(L, "Unsupported property 'items' (type: Ogre::vector<InventorySection::SectionItem>::type)");
}

static int InventorySection_get_content(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    // TODO: Unsupported type for content (Array2d<Item>)
    return luaL_error(L, "Unsupported property 'content' (type: Array2d<Item>)");
}

static int InventorySection_get_stackingBonusMin(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    lua_pushinteger(L, b->stackingBonusMin);
    return 1;
}

static int InventorySection_get_stackingBonusMult(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    lua_pushnumber(L, b->stackingBonusMult);
    return 1;
}

static int InventorySection_get_veryLimitedSlot(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    // TODO: Unsupported type for veryLimitedSlot (lektor<GameData*>)
    return luaL_error(L, "Unsupported property 'veryLimitedSlot' (type: lektor<GameData*>)");
}

static int InventorySection_get_itemsLimit(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    lua_pushinteger(L, b->itemsLimit);
    return 1;
}

static int InventorySection_get_weightMultiplier(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    lua_pushnumber(L, b->weightMultiplier);
    return 1;
}

static int InventorySection_get_totalWeight(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    lua_pushnumber(L, b->totalWeight);
    return 1;
}

static int InventorySection_get_isAnEquippedItemSection(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    lua_pushboolean(L, b->isAnEquippedItemSection ? 1 : 0);
    return 1;
}

static int InventorySection_get_limitedSlot(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    lua_pushinteger(L, (lua_Integer)b->limitedSlot);
    return 1;
}

static int InventorySection_get_containerSlot(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    lua_pushboolean(L, b->containerSlot ? 1 : 0);
    return 1;
}

static int InventorySection_get_callbackObject(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    return pushObject<RootObject>(L, b->callbackObject, RootObjectBinding::getMetatableName());
}

static int InventorySection_get_parentInventory(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    return pushObject<Inventory>(L, b->parentInventory, InventoryBinding::getMetatableName());
}

static int InventorySection_get_enabled(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    lua_pushboolean(L, b->enabled ? 1 : 0);
    return 1;
}

// --- Setters for InventorySection ---
static int InventorySection_set_name(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    b->name = luaL_checkstring(L, 2);
    return 0;
}

static int InventorySection_set_width(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    b->width = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int InventorySection_set_height(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    b->height = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int InventorySection_set_armourOnly(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    b->armourOnly = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InventorySection_set_items(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    return luaL_error(L, "Read-only or unsupported setter type for items");
}

static int InventorySection_set_content(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    return luaL_error(L, "Read-only or unsupported setter type for content");
}

static int InventorySection_set_stackingBonusMin(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    b->stackingBonusMin = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int InventorySection_set_stackingBonusMult(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    b->stackingBonusMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int InventorySection_set_veryLimitedSlot(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    return luaL_error(L, "Read-only or unsupported setter type for veryLimitedSlot");
}

static int InventorySection_set_itemsLimit(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    b->itemsLimit = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int InventorySection_set_weightMultiplier(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    b->weightMultiplier = (float)luaL_checknumber(L, 2);
    return 0;
}

static int InventorySection_set_totalWeight(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    b->totalWeight = (float)luaL_checknumber(L, 2);
    return 0;
}

static int InventorySection_set_isAnEquippedItemSection(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    b->isAnEquippedItemSection = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InventorySection_set_limitedSlot(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    b->limitedSlot = (AttachSlot)luaL_checkinteger(L, 2);
    return 0;
}

static int InventorySection_set_containerSlot(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    b->containerSlot = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InventorySection_set_callbackObject(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    return luaL_error(L, "Read-only or unsupported setter type for callbackObject");
}

static int InventorySection_set_parentInventory(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    return luaL_error(L, "Read-only or unsupported setter type for parentInventory");
}

static int InventorySection_set_enabled(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    b->enabled = lua_toboolean(L, 2) != 0;
    return 0;
}

int InventorySectionBinding::_CONSTRUCTOR(lua_State* L)
{
    InventorySection* instance = getB(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    std::string name = luaL_checkstring(L, 2);
    int w = (int)luaL_checkinteger(L, 3);
    int h = (int)luaL_checkinteger(L, 4);
    int slot = (int)luaL_checkinteger(L, 5);
    Inventory* inventory = checkObject<Inventory>(L, 6, InventoryBinding::getMetatableName());
    bool containerSlot = lua_toboolean(L, 7) != 0;
    bool equipSlot = lua_toboolean(L, 8) != 0;
    bool enabled = lua_toboolean(L, 9) != 0;

    InventorySection* result = instance->_CONSTRUCTOR(name, w, h, (AttachSlot)slot, inventory, containerSlot, equipSlot, enabled);
    return pushObject<InventorySection>(L, result, InventorySectionBinding::getMetatableName());
}

int InventorySectionBinding::_DESTRUCTOR(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");

    b->_DESTRUCTOR();
    return 0;
}

int InventorySectionBinding::notifyModified(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");

    b->notifyModified();
    return 0;
}

int InventorySectionBinding::getItemAt(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");

    int x = (int)luaL_checkinteger(L, 2);
    int y = (int)luaL_checkinteger(L, 3);
    Item* result = b->getItemAt(x, y);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int InventorySectionBinding::hasItemType(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");

    itemType type = (itemType)luaL_checkinteger(L, 2);
    bool result = b->hasItemType(type);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionBinding::autoArrange(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");

    b->autoArrange();
    return 0;
}

int InventorySectionBinding::_NV_autoArrange(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");

    b->_NV_autoArrange();
    return 0;
}

int InventorySectionBinding::getNumItems(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");

    unsigned int result = b->getNumItems();
    lua_pushinteger(L, result);
    return 1;
}

int InventorySectionBinding::isEmpty(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");

    bool result = b->isEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionBinding::clearAllItems(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");

    bool destroy = lua_toboolean(L, 2) != 0;
    bool skipUnique = lua_toboolean(L, 3) != 0;
    b->clearAllItems(destroy, skipUnique);
    return 0;
}

int InventorySectionBinding::getLimitedSlot(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");

    AttachSlot result = b->getLimitedSlot();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int InventorySectionBinding::applyStackingBonuses(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");

    int normalStackableAmount = (int)luaL_checkinteger(L, 2);
    int result = b->applyStackingBonuses(normalStackableAmount);
    lua_pushinteger(L, result);
    return 1;
}

int InventorySectionBinding::recalculateTotalWeight(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");

    b->recalculateTotalWeight();
    return 0;
}

int InventorySectionBinding::setWeightMultiplier(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");

    float mult = (float)luaL_checknumber(L, 2);
    b->setWeightMultiplier(mult);
    return 0;
}

int InventorySectionBinding::setStackingBonus(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");

    int minn = (int)luaL_checkinteger(L, 2);
    float mult = (float)luaL_checknumber(L, 3);
    b->setStackingBonus(minn, mult);
    return 0;
}

int InventorySectionBinding::getMaxStack(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");

    int result = b->getMaxStack();
    lua_pushinteger(L, result);
    return 1;
}

int InventorySectionBinding::clearVeryLimitedSlot(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");

    b->clearVeryLimitedSlot();
    return 0;
}

int InventorySectionBinding::getEnabled(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");

    bool result = b->getEnabled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionBinding::setEnabled(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");

    bool value = lua_toboolean(L, 2) != 0;
    b->setEnabled(value);
    return 0;
}

int InventorySectionBinding::setItemsLimitCount(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");

    int value = (int)luaL_checkinteger(L, 2);
    b->setItemsLimitCount(value);
    return 0;
}

int InventorySectionBinding::getItemsLimitReached(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");

    bool result = b->getItemsLimitReached();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionBinding::getInventory(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");

    Inventory* result = b->getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int InventorySectionBinding::getFillPercentage(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");

    float result = b->getFillPercentage();
    lua_pushnumber(L, result);
    return 1;
}

int InventorySectionBinding::getItem(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");

    Item* result = b->getItem();
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int InventorySectionBinding::resize(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");

    int w = (int)luaL_checkinteger(L, 2);
    int h = (int)luaL_checkinteger(L, 3);
    bool clearContent = lua_toboolean(L, 4) != 0;
    b->resize(w, h, clearContent);
    return 0;
}

int InventorySectionBinding::hasItem_GameData(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    GameData* itemData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    if (!itemData) return luaL_error(L, "GameData is nil");
    bool result = b->hasItem(itemData);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionBinding::hasItem_Item(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    if (!item) return luaL_error(L, "Item is nil");
    bool result = b->hasItem(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionBinding::hasRoomForItem(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    GameData* itemData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    if (!itemData) return luaL_error(L, "GameData is nil");
    int quantity = (int)luaL_checkinteger(L, 3);
    bool result = b->hasRoomForItem(itemData, quantity);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionBinding::_NV_hasRoomForItem(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    GameData* itemData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    if (!itemData) return luaL_error(L, "GameData is nil");
    int quantity = (int)luaL_checkinteger(L, 3);
    bool result = b->_NV_hasRoomForItem(itemData, quantity);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionBinding::isLimitedSlotCompatible(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b)
        return luaL_error(L, "InventorySection is nil");

    if (GameData* gd = testObject<GameData>(L, 2, GameDataBinding::getMetatableName()))
    {
        lua_pushboolean(L, b->isLimitedSlotCompatible(gd));
        return 1;
    }

    if (Item* item = testObject<Item>(L, 2, ItemBinding::getMetatableName()))
    {
        lua_pushboolean(L, b->isLimitedSlotCompatible(item));
        return 1;
    }

    return luaL_error(
        L,
        "Expected GameData or Item for argument #2"
    );
}

int InventorySectionBinding::getValidInventoryPosition(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    if (!item) return luaL_error(L, "Item is nil");
    int x, y;
    bool result = b->getValidInventoryPosition(item, x, y);
    lua_pushboolean(L, result ? 1 : 0);
    lua_pushinteger(L, x);
    lua_pushinteger(L, y);
    return 3;
}

/*
Skipped methods needing manual binding:
  line 51: void getAllItemsOfType(...) - overloaded method
  line 52: void getAllItemsOfType(...) - overloaded method
  line 53: void getAllItemsOfName(...) - unsupported arg type
  line 59: bool getValidInventoryPosition(...) - unsupported arg type
  line 60: bool findNearestPlaceForItem(...) - unsupported arg type
  line 61: int getItemsInFootprint(...) - overloaded method
  line 62: int getItemsInFootprint(...) - overloaded method
  line 65: void setupContainerData(...) - unsupported arg type
  line 72: void addVeryLimitedSlot(...) - unsupported arg type
  line 74: const lektor<GameData*>& getVeryLimitedSlot(...) - reference return type
  line 85: const Ogre::vector<InventorySection::SectionItem>::type& getItems(...) - reference return type
  line 91: void setupEquipCallbacks(...) - unsupported arg type
  line 92: int numItemsInFootprint(...) - unsupported arg type
*/

int InventorySectionBinding::addItem(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int quantity = (int)luaL_checkinteger(L, 3);
    bool result = b->addItem(item, quantity);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionBinding::_NV_addItem(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int quantity = (int)luaL_checkinteger(L, 3);
    bool result = b->_NV_addItem(item, quantity);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionBinding::removeItem(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool result = b->removeItem(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionBinding::canItemGoHere(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int x = (int)luaL_checkinteger(L, 3);
    int y = (int)luaL_checkinteger(L, 4);
    bool result = b->canItemGoHere(item, x, y);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionBinding::existsItemInFootprint(lua_State* L)
{
    InventorySection* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventorySection is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int x = (int)luaL_checkinteger(L, 3);
    int y = (int)luaL_checkinteger(L, 4);
    bool result = b->existsItemInFootprint(item, x, y);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int InventorySectionBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.InventorySection object");
    return 1;
}

void InventorySectionBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       InventorySectionBinding::gc },
        { "__tostring", InventorySectionBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", InventorySectionBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", InventorySectionBinding::_DESTRUCTOR },
        { "notifyModified", InventorySectionBinding::notifyModified },
        { "getItemAt", InventorySectionBinding::getItemAt },
        { "hasRoomForItem", InventorySectionBinding::hasRoomForItem },
        { "_NV_hasRoomForItem", InventorySectionBinding::_NV_hasRoomForItem },
        { "hasItem", InventorySectionBinding::hasItem_Item },
        { "hasItem", InventorySectionBinding::hasItem_GameData },
        { "hasItemType", InventorySectionBinding::hasItemType },
        { "autoArrange", InventorySectionBinding::autoArrange },
        { "_NV_autoArrange", InventorySectionBinding::_NV_autoArrange },
        { "getNumItems", InventorySectionBinding::getNumItems },
        { "isEmpty", InventorySectionBinding::isEmpty },
        { "clearAllItems", InventorySectionBinding::clearAllItems },
        { "getLimitedSlot", InventorySectionBinding::getLimitedSlot },
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
        { "addItem", InventorySectionBinding::addItem },
        { "_NV_addItem", InventorySectionBinding::_NV_addItem },
        { "removeItem", InventorySectionBinding::removeItem },
        { "canItemGoHere", InventorySectionBinding::canItemGoHere },
        { "existsItemInFootprint", InventorySectionBinding::existsItemInFootprint },
        { "isLimitedSlotCompatible", InventorySectionBinding::isLimitedSlotCompatible },
        { "getValidInventoryPosition", InventorySectionBinding::getValidInventoryPosition },
        { 0, 0 }
    };

    registerClass(
        L, 
        InventorySectionBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, InventorySectionBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, InventorySection_get_name);
    lua_setfield(L, -2, "name");
    lua_pushcfunction(L, InventorySection_get_width);
    lua_setfield(L, -2, "width");
    lua_pushcfunction(L, InventorySection_get_height);
    lua_setfield(L, -2, "height");
    lua_pushcfunction(L, InventorySection_get_armourOnly);
    lua_setfield(L, -2, "armourOnly");
    lua_pushcfunction(L, InventorySection_get_items);
    lua_setfield(L, -2, "items");
    lua_pushcfunction(L, InventorySection_get_content);
    lua_setfield(L, -2, "content");
    lua_pushcfunction(L, InventorySection_get_stackingBonusMin);
    lua_setfield(L, -2, "stackingBonusMin");
    lua_pushcfunction(L, InventorySection_get_stackingBonusMult);
    lua_setfield(L, -2, "stackingBonusMult");
    lua_pushcfunction(L, InventorySection_get_veryLimitedSlot);
    lua_setfield(L, -2, "veryLimitedSlot");
    lua_pushcfunction(L, InventorySection_get_itemsLimit);
    lua_setfield(L, -2, "itemsLimit");
    lua_pushcfunction(L, InventorySection_get_weightMultiplier);
    lua_setfield(L, -2, "weightMultiplier");
    lua_pushcfunction(L, InventorySection_get_totalWeight);
    lua_setfield(L, -2, "totalWeight");
    lua_pushcfunction(L, InventorySection_get_isAnEquippedItemSection);
    lua_setfield(L, -2, "isAnEquippedItemSection");
    lua_pushcfunction(L, InventorySection_get_limitedSlot);
    lua_setfield(L, -2, "limitedSlot");
    lua_pushcfunction(L, InventorySection_get_containerSlot);
    lua_setfield(L, -2, "containerSlot");
    lua_pushcfunction(L, InventorySection_get_callbackObject);
    lua_setfield(L, -2, "callbackObject");
    lua_pushcfunction(L, InventorySection_get_parentInventory);
    lua_setfield(L, -2, "parentInventory");
    lua_pushcfunction(L, InventorySection_get_enabled);
    lua_setfield(L, -2, "enabled");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, InventorySection_set_name);
    lua_setfield(L, -2, "name");
    lua_pushcfunction(L, InventorySection_set_width);
    lua_setfield(L, -2, "width");
    lua_pushcfunction(L, InventorySection_set_height);
    lua_setfield(L, -2, "height");
    lua_pushcfunction(L, InventorySection_set_armourOnly);
    lua_setfield(L, -2, "armourOnly");
    lua_pushcfunction(L, InventorySection_set_items);
    lua_setfield(L, -2, "items");
    lua_pushcfunction(L, InventorySection_set_content);
    lua_setfield(L, -2, "content");
    lua_pushcfunction(L, InventorySection_set_stackingBonusMin);
    lua_setfield(L, -2, "stackingBonusMin");
    lua_pushcfunction(L, InventorySection_set_stackingBonusMult);
    lua_setfield(L, -2, "stackingBonusMult");
    lua_pushcfunction(L, InventorySection_set_veryLimitedSlot);
    lua_setfield(L, -2, "veryLimitedSlot");
    lua_pushcfunction(L, InventorySection_set_itemsLimit);
    lua_setfield(L, -2, "itemsLimit");
    lua_pushcfunction(L, InventorySection_set_weightMultiplier);
    lua_setfield(L, -2, "weightMultiplier");
    lua_pushcfunction(L, InventorySection_set_totalWeight);
    lua_setfield(L, -2, "totalWeight");
    lua_pushcfunction(L, InventorySection_set_isAnEquippedItemSection);
    lua_setfield(L, -2, "isAnEquippedItemSection");
    lua_pushcfunction(L, InventorySection_set_limitedSlot);
    lua_setfield(L, -2, "limitedSlot");
    lua_pushcfunction(L, InventorySection_set_containerSlot);
    lua_setfield(L, -2, "containerSlot");
    lua_pushcfunction(L, InventorySection_set_callbackObject);
    lua_setfield(L, -2, "callbackObject");
    lua_pushcfunction(L, InventorySection_set_parentInventory);
    lua_setfield(L, -2, "parentInventory");
    lua_pushcfunction(L, InventorySection_set_enabled);
    lua_setfield(L, -2, "enabled");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua