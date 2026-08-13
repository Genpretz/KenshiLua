#include "pch.h"
#include "kenshi\Inventory.h"
#include "InventorySectionBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "GameDataBinding.h"
#include "InventoryBinding.h"
#include "ItemBinding.h"
#include "RootObjectBinding.h"

namespace KenshiLua
{

static InventorySection* getInstance(lua_State* L, int idx)
{
    return checkObject<InventorySection>(L, idx, InventorySectionBinding::getMetatableName());
}

// --- Getters for InventorySection ---
static int InventorySection_get_name(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    lua_pushstring(L, instance->name.c_str());
    return 1;
}

static int InventorySection_get_width(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    lua_pushinteger(L, instance->width);
    return 1;
}

static int InventorySection_get_height(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    lua_pushinteger(L, instance->height);
    return 1;
}

static int InventorySection_get_armourOnly(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    lua_pushboolean(L, instance->armourOnly ? 1 : 0);
    return 1;
}

static int InventorySection_get_stackingBonusMin(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    lua_pushinteger(L, instance->stackingBonusMin);
    return 1;
}

static int InventorySection_get_stackingBonusMult(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    lua_pushnumber(L, instance->stackingBonusMult);
    return 1;
}

static int InventorySection_get_itemsLimit(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    lua_pushinteger(L, instance->itemsLimit);
    return 1;
}

static int InventorySection_get_weightMultiplier(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    lua_pushnumber(L, instance->weightMultiplier);
    return 1;
}

static int InventorySection_get_totalWeight(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    lua_pushnumber(L, instance->totalWeight);
    return 1;
}

static int InventorySection_get_isAnEquippedItemSection(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    lua_pushboolean(L, instance->isAnEquippedItemSection ? 1 : 0);
    return 1;
}

static int InventorySection_get_limitedSlot(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    lua_pushinteger(L, (lua_Integer)instance->limitedSlot);
    return 1;
}

static int InventorySection_get_containerSlot(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    lua_pushboolean(L, instance->containerSlot ? 1 : 0);
    return 1;
}

static int InventorySection_get_callbackObject(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    return pushObject<RootObject>(L, instance->callbackObject, RootObjectBinding::getMetatableName());
}

static int InventorySection_get_parentInventory(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    return pushObject<Inventory>(L, instance->parentInventory, InventoryBinding::getMetatableName());
}

static int InventorySection_get_enabled(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    lua_pushboolean(L, instance->enabled ? 1 : 0);
    return 1;
}

// --- Setters for InventorySection ---
static int InventorySection_set_name(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    instance->name = luaL_checkstring(L, 2);
    return 0;
}

static int InventorySection_set_width(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    instance->width = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int InventorySection_set_height(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    instance->height = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int InventorySection_set_armourOnly(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    instance->armourOnly = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InventorySection_set_stackingBonusMin(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    instance->stackingBonusMin = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int InventorySection_set_stackingBonusMult(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    instance->stackingBonusMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int InventorySection_set_itemsLimit(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    instance->itemsLimit = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int InventorySection_set_weightMultiplier(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    instance->weightMultiplier = (float)luaL_checknumber(L, 2);
    return 0;
}

static int InventorySection_set_totalWeight(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    instance->totalWeight = (float)luaL_checknumber(L, 2);
    return 0;
}

static int InventorySection_set_isAnEquippedItemSection(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    instance->isAnEquippedItemSection = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InventorySection_set_limitedSlot(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    instance->limitedSlot = (AttachSlot)luaL_checkinteger(L, 2);
    return 0;
}

static int InventorySection_set_containerSlot(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    instance->containerSlot = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InventorySection_set_callbackObject(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    instance->callbackObject = lua_isnoneornil(L, 2) ? nullptr : checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    return 0;
}

static int InventorySection_set_parentInventory(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    instance->parentInventory = lua_isnoneornil(L, 2) ? nullptr : checkObject<Inventory>(L, 2, InventoryBinding::getMetatableName());
    return 0;
}

static int InventorySection_set_enabled(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    instance->enabled = lua_toboolean(L, 2) != 0;
    return 0;
}

int InventorySectionBinding::_CONSTRUCTOR(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    const std::string _name = luaL_checkstring(L, 2);
    int _w = (int)luaL_checkinteger(L, 3);
    int _h = (int)luaL_checkinteger(L, 4);
    AttachSlot slot = (AttachSlot)luaL_checkinteger(L, 5);
    Inventory* inv = checkObject<Inventory>(L, 6, InventoryBinding::getMetatableName());
    bool _containerSlot = lua_toboolean(L, 7) != 0;
    bool _equipSlot = lua_toboolean(L, 8) != 0;
    bool enabled = lua_toboolean(L, 9) != 0;
    InventorySection* result = instance->_CONSTRUCTOR(_name, _w, _h, slot, inv, _containerSlot, _equipSlot, enabled);
    return pushObject<InventorySection>(L, result, InventorySectionBinding::getMetatableName());
}

int InventorySectionBinding::_DESTRUCTOR(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int InventorySectionBinding::hasRoomForItem(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    GameData* _itemData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    int quantity = (int)luaL_checkinteger(L, 3);
    bool result = instance->hasRoomForItem(_itemData, quantity);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionBinding::_NV_hasRoomForItem(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    GameData* _itemData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    int quantity = (int)luaL_checkinteger(L, 3);
    bool result = instance->_NV_hasRoomForItem(_itemData, quantity);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionBinding::notifyModified(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    instance->notifyModified();
    return 0;
}

int InventorySectionBinding::addItem(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    Item* itemToAdd = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int quantity = (int)luaL_checkinteger(L, 3);
    bool result = instance->addItem(itemToAdd, quantity);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionBinding::_NV_addItem(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    Item* itemToAdd = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int quantity = (int)luaL_checkinteger(L, 3);
    bool result = instance->_NV_addItem(itemToAdd, quantity);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionBinding::_addItem(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int x = (int)luaL_checkinteger(L, 3);
    int y = (int)luaL_checkinteger(L, 4);
    instance->_addItem(item, x, y);
    return 0;
}

int InventorySectionBinding::_NV__addItem(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int x = (int)luaL_checkinteger(L, 3);
    int y = (int)luaL_checkinteger(L, 4);
    instance->_NV__addItem(item, x, y);
    return 0;
}

int InventorySectionBinding::getItemAt(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    int x = (int)luaL_checkinteger(L, 2);
    int y = (int)luaL_checkinteger(L, 3);
    Item* result = instance->getItemAt(x, y);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int InventorySectionBinding::hasItemType(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    itemType type = (itemType)luaL_checkinteger(L, 2);
    bool result = instance->hasItemType(type);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionBinding::autoArrange(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    instance->autoArrange();
    return 0;
}

int InventorySectionBinding::_NV_autoArrange(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    instance->_NV_autoArrange();
    return 0;
}

int InventorySectionBinding::getNumItems(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    unsigned int result = instance->getNumItems();
    lua_pushinteger(L, result);
    return 1;
}

int InventorySectionBinding::isEmpty(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    bool result = instance->isEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionBinding::removeItem(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool result = instance->removeItem(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionBinding::clearAllItems(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    bool destroy = lua_toboolean(L, 2) != 0;
    bool skipUnique = lua_toboolean(L, 3) != 0;
    instance->clearAllItems(destroy, skipUnique);
    return 0;
}

int InventorySectionBinding::canItemGoHere(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int x = (int)luaL_checkinteger(L, 3);
    int y = (int)luaL_checkinteger(L, 4);
    bool result = instance->canItemGoHere(item, x, y);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionBinding::existsItemInFootprint(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int x = (int)luaL_checkinteger(L, 3);
    int y = (int)luaL_checkinteger(L, 4);
    bool result = instance->existsItemInFootprint(item, x, y);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionBinding::getLimitedSlot(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    AttachSlot result = instance->getLimitedSlot();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int InventorySectionBinding::setupContainerData(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->setupContainerData(data);
    return 0;
}

int InventorySectionBinding::applyStackingBonuses(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    int normalStackableAmount = (int)luaL_checkinteger(L, 2);
    int result = instance->applyStackingBonuses(normalStackableAmount);
    lua_pushinteger(L, result);
    return 1;
}

int InventorySectionBinding::recalculateTotalWeight(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    instance->recalculateTotalWeight();
    return 0;
}

int InventorySectionBinding::setWeightMultiplier(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    float mult = (float)luaL_checknumber(L, 2);
    instance->setWeightMultiplier(mult);
    return 0;
}

int InventorySectionBinding::setStackingBonus(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    int minn = (int)luaL_checkinteger(L, 2);
    float mult = (float)luaL_checknumber(L, 3);
    instance->setStackingBonus(minn, mult);
    return 0;
}

int InventorySectionBinding::getMaxStack(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    int result = instance->getMaxStack();
    lua_pushinteger(L, result);
    return 1;
}

int InventorySectionBinding::addVeryLimitedSlot(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->addVeryLimitedSlot(item);
    return 0;
}

int InventorySectionBinding::clearVeryLimitedSlot(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    instance->clearVeryLimitedSlot();
    return 0;
}

int InventorySectionBinding::getEnabled(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    bool result = instance->getEnabled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionBinding::setEnabled(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->setEnabled(value);
    return 0;
}

int InventorySectionBinding::setItemsLimitCount(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    int value = (int)luaL_checkinteger(L, 2);
    instance->setItemsLimitCount(value);
    return 0;
}

int InventorySectionBinding::getItemsLimitReached(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    bool result = instance->getItemsLimitReached();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionBinding::getInventory(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    Inventory* result = instance->getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int InventorySectionBinding::getFillPercentage(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    float result = instance->getFillPercentage();
    lua_pushnumber(L, result);
    return 1;
}

int InventorySectionBinding::getItem(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    Item* result = instance->getItem();
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int InventorySectionBinding::setupEquipCallbacks(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    RootObject* owner = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->setupEquipCallbacks(owner);
    return 0;
}

int InventorySectionBinding::numItemsInFootprint(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int x = (int)luaL_checkinteger(L, 3);
    int y = (int)luaL_checkinteger(L, 4);
    int result = instance->numItemsInFootprint(item, x, y);
    lua_pushinteger(L, result);
    return 1;
}

int InventorySectionBinding::resize(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");

    int w = (int)luaL_checkinteger(L, 2);
    int h = (int)luaL_checkinteger(L, 3);
    bool clearContent = lua_toboolean(L, 4) != 0;
    instance->resize(w, h, clearContent);
    return 0;
}

/*
Skipped methods/members needing manual RVA offset binding if required:
  - const Ogre::vector<InventorySection::SectionItem>::type& getItems(...) - reference return type
*/

/*
Skipped properties needing manual binding:
  line 94: items (Ogre::vector<InventorySection::SectionItem>::type) - unsupported type
  line 95: content (Array2d<Item>) - unsupported type
*/

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



static int InventorySection_get_content(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    // TODO: Unsupported type for content (Array2d<Item>)
    return luaL_error(L, "Unsupported property 'content' (type: Array2d<Item>)");
}


static int InventorySection_get_items(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    // TODO: Unsupported type for items (Ogre::vector<InventorySection::SectionItem>::type)
    return luaL_error(L, "Unsupported property 'items' (type: Ogre::vector<InventorySection::SectionItem>::type)");
}


static int InventorySection_get_veryLimitedSlot(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    return pushObject<lektor<GameData*>>(L, &instance->veryLimitedSlot, LektorPtrBinding<GameData*>::metaName);
}


static int InventorySection_set_content(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    return luaL_error(L, "Read-only or unsupported setter type for content");
}


static int InventorySection_set_items(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    return luaL_error(L, "Read-only or unsupported setter type for items");
}


static int InventorySection_set_veryLimitedSlot(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    lektor<GameData*>* val = LektorPtrBinding<GameData*>::get(L, 2);
    if (!val) return luaL_error(L, "Expected lektor<GameData*>");
    instance->veryLimitedSlot = *val;
    return 0;
}


int InventorySectionBinding::getValidInventoryPosition(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    if (!item) return luaL_error(L, "Item is nil");
    int x, y;
    bool result = instance->getValidInventoryPosition(item, x, y);
    lua_pushboolean(L, result ? 1 : 0);
    lua_pushinteger(L, x);
    lua_pushinteger(L, y);
    return 3;
}


int InventorySectionBinding::hasItem_GameData(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    GameData* itemData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    if (!itemData) return luaL_error(L, "GameData is nil");
    bool result = instance->hasItem(itemData);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}


int InventorySectionBinding::hasItem_Item(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    if (!item) return luaL_error(L, "Item is nil");
    bool result = instance->hasItem(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}


int InventorySectionBinding::isLimitedSlotCompatible(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance)
        return luaL_error(L, "InventorySection is nil");

    if (GameData* gd = testObject<GameData>(L, 2, GameDataBinding::getMetatableName()))
    {
        lua_pushboolean(L, instance->isLimitedSlotCompatible(gd));
        return 1;
    }

    if (Item* item = testObject<Item>(L, 2, ItemBinding::getMetatableName()))
    {
        lua_pushboolean(L, instance->isLimitedSlotCompatible(item));
        return 1;
    }

    return luaL_error(
        L,
        "Expected GameData or Item for argument #2"
    );
}

int InventorySectionBinding::getAllItemsOfType(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    lektor<Item*>* list = LektorPtrBinding<Item*>::get(L, 2);
    if (!list) return luaL_error(L, "Argument 2 to getAllItemsOfType must be lektor<Item*>");

    if (Item* item = testObject<Item>(L, 3, ItemBinding::getMetatableName()))
    {
        instance->getAllItemsOfType(*list, item);
        return 0;
    }
    if (lua_isnumber(L, 3))
    {
        itemType type = (itemType)luaL_checkinteger(L, 3);
        instance->getAllItemsOfType(*list, type);
        return 0;
    }
    return luaL_error(L, "Argument 3 to getAllItemsOfType must be Item or itemType (enum)");
}

int InventorySectionBinding::getAllItemsOfName(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    lektor<Item*>* list = LektorPtrBinding<Item*>::get(L, 2);
    if (!list) return luaL_error(L, "Argument 2 to getAllItemsOfName must be lektor<Item*>");
    const std::string itemName = luaL_checkstring(L, 3);
    instance->getAllItemsOfName(*list, itemName);
    return 0;
}

int InventorySectionBinding::findNearestPlaceForItem(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    if (!item) return luaL_error(L, "Argument 2 to findNearestPlaceForItem must be Item");
    int x = 0, y = 0;
    bool result = instance->findNearestPlaceForItem(item, x, y);
    lua_pushboolean(L, result ? 1 : 0);
    lua_pushinteger(L, x);
    lua_pushinteger(L, y);
    return 3;
}

int InventorySectionBinding::getItemsInFootprint(lua_State* L)
{
    InventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySection is nil");
    lektor<Item*>* out = LektorPtrBinding<Item*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to getItemsInFootprint must be lektor<Item*>");

    if (Item* item = testObject<Item>(L, 3, ItemBinding::getMetatableName()))
    {
        int x = (int)luaL_checkinteger(L, 4);
        int y = (int)luaL_checkinteger(L, 5);
        int result = instance->getItemsInFootprint(*out, item, x, y);
        lua_pushinteger(L, result);
        return 1;
    }
    int itemWidth = (int)luaL_checkinteger(L, 3);
    int itemHeight = (int)luaL_checkinteger(L, 4);
    int x = (int)luaL_checkinteger(L, 5);
    int y = (int)luaL_checkinteger(L, 6);
    int result = instance->getItemsInFootprint(*out, itemWidth, itemHeight, x, y);
    lua_pushinteger(L, result);
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
        { "hasRoomForItem", InventorySectionBinding::hasRoomForItem },
        { "_NV_hasRoomForItem", InventorySectionBinding::_NV_hasRoomForItem },
        { "notifyModified", InventorySectionBinding::notifyModified },
        { "addItem", InventorySectionBinding::addItem },
        { "_NV_addItem", InventorySectionBinding::_NV_addItem },
        { "_addItem", InventorySectionBinding::_addItem },
        { "_NV__addItem", InventorySectionBinding::_NV__addItem },
        { "getItemAt", InventorySectionBinding::getItemAt },
        { "hasItemType", InventorySectionBinding::hasItemType },
        { "autoArrange", InventorySectionBinding::autoArrange },
        { "_NV_autoArrange", InventorySectionBinding::_NV_autoArrange },
        { "getNumItems", InventorySectionBinding::getNumItems },
        { "isEmpty", InventorySectionBinding::isEmpty },
        { "removeItem", InventorySectionBinding::removeItem },
        { "clearAllItems", InventorySectionBinding::clearAllItems },
        { "canItemGoHere", InventorySectionBinding::canItemGoHere },
        { "existsItemInFootprint", InventorySectionBinding::existsItemInFootprint },
        { "getLimitedSlot", InventorySectionBinding::getLimitedSlot },
        { "setupContainerData", InventorySectionBinding::setupContainerData },
        { "applyStackingBonuses", InventorySectionBinding::applyStackingBonuses },
        { "recalculateTotalWeight", InventorySectionBinding::recalculateTotalWeight },
        { "setWeightMultiplier", InventorySectionBinding::setWeightMultiplier },
        { "setStackingBonus", InventorySectionBinding::setStackingBonus },
        { "getMaxStack", InventorySectionBinding::getMaxStack },
        { "addVeryLimitedSlot", InventorySectionBinding::addVeryLimitedSlot },
        { "clearVeryLimitedSlot", InventorySectionBinding::clearVeryLimitedSlot },
        { "getEnabled", InventorySectionBinding::getEnabled },
        { "setEnabled", InventorySectionBinding::setEnabled },
        { "setItemsLimitCount", InventorySectionBinding::setItemsLimitCount },
        { "getItemsLimitReached", InventorySectionBinding::getItemsLimitReached },
        { "getInventory", InventorySectionBinding::getInventory },
        { "getFillPercentage", InventorySectionBinding::getFillPercentage },
        { "getItem", InventorySectionBinding::getItem },
        { "setupEquipCallbacks", InventorySectionBinding::setupEquipCallbacks },
        { "numItemsInFootprint", InventorySectionBinding::numItemsInFootprint },
        { "resize", InventorySectionBinding::resize },
        { "hasItem", InventorySectionBinding::hasItem_Item },
        { "hasItem", InventorySectionBinding::hasItem_GameData },
        { "isLimitedSlotCompatible", InventorySectionBinding::isLimitedSlotCompatible },
        { "getValidInventoryPosition", InventorySectionBinding::getValidInventoryPosition },
        { "getAllItemsOfType", InventorySectionBinding::getAllItemsOfType },
        { "getAllItemsOfName", InventorySectionBinding::getAllItemsOfName },
        { "findNearestPlaceForItem", InventorySectionBinding::findNearestPlaceForItem },
        { "getItemsInFootprint", InventorySectionBinding::getItemsInFootprint },
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
    registerGetter(L, "name", InventorySection_get_name);
    registerGetter(L, "width", InventorySection_get_width);
    registerGetter(L, "height", InventorySection_get_height);
    registerGetter(L, "armourOnly", InventorySection_get_armourOnly);
    registerGetter(L, "stackingBonusMin", InventorySection_get_stackingBonusMin);
    registerGetter(L, "stackingBonusMult", InventorySection_get_stackingBonusMult);
    registerGetter(L, "itemsLimit", InventorySection_get_itemsLimit);
    registerGetter(L, "weightMultiplier", InventorySection_get_weightMultiplier);
    registerGetter(L, "totalWeight", InventorySection_get_totalWeight);
    registerGetter(L, "isAnEquippedItemSection", InventorySection_get_isAnEquippedItemSection);
    registerGetter(L, "limitedSlot", InventorySection_get_limitedSlot);
    registerGetter(L, "containerSlot", InventorySection_get_containerSlot);
    registerGetter(L, "callbackObject", InventorySection_get_callbackObject);
    registerGetter(L, "parentInventory", InventorySection_get_parentInventory);
    registerGetter(L, "enabled", InventorySection_get_enabled);
    registerGetter(L, "content", InventorySection_get_content);
    registerGetter(L, "veryLimitedSlot", InventorySection_get_veryLimitedSlot);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "name", InventorySection_set_name);
    registerSetter(L, "width", InventorySection_set_width);
    registerSetter(L, "height", InventorySection_set_height);
    registerSetter(L, "armourOnly", InventorySection_set_armourOnly);
    registerSetter(L, "stackingBonusMin", InventorySection_set_stackingBonusMin);
    registerSetter(L, "stackingBonusMult", InventorySection_set_stackingBonusMult);
    registerSetter(L, "itemsLimit", InventorySection_set_itemsLimit);
    registerSetter(L, "weightMultiplier", InventorySection_set_weightMultiplier);
    registerSetter(L, "totalWeight", InventorySection_set_totalWeight);
    registerSetter(L, "isAnEquippedItemSection", InventorySection_set_isAnEquippedItemSection);
    registerSetter(L, "limitedSlot", InventorySection_set_limitedSlot);
    registerSetter(L, "containerSlot", InventorySection_set_containerSlot);
    registerSetter(L, "callbackObject", InventorySection_set_callbackObject);
    registerSetter(L, "parentInventory", InventorySection_set_parentInventory);
    registerSetter(L, "enabled", InventorySection_set_enabled);
    registerSetter(L, "content", InventorySection_set_content);
    registerSetter(L, "veryLimitedSlot", InventorySection_set_veryLimitedSlot);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua