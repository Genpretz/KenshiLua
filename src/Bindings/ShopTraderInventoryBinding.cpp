#include "pch.h"
#include "kenshi\ShopTraderInventory.h"
#include "ShopTraderInventoryBinding.h"
#include "InventoryBinding.h"
#include "InventorySectionBinding.h"
#include "ItemBinding.h"
#include "RootObjectBinding.h"
#include "ShopTraderInventorySectionBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"
#include "Bindings/Util/OgreVectorBinding.h"

namespace KenshiLua
{

static ShopTraderInventory* getInstance(lua_State* L, int idx)
{
    return checkObject<ShopTraderInventory>(L, idx, ShopTraderInventoryBinding::getMetatableName());
}

// --- Getters for ShopTraderInventory ---
static int ShopTraderInventory_get_inventories(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");
    return pushObject<ogre_unordered_map<hand, InventorySection*>::type>(
        L, &instance->inventories, OgreUnorderedMapBinding<hand, InventorySection*>::getMetatableName());
}

static int ShopTraderInventory_get_section(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");
    return pushObject<ShopTraderInventorySection>(L, instance->section, ShopTraderInventorySectionBinding::getMetatableName());
}

// --- Setters for ShopTraderInventory ---
static int ShopTraderInventory_set_inventories(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");
    ogre_unordered_map<hand, InventorySection*>::type* val = 
        OgreUnorderedMapBinding<hand, InventorySection*>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'inventories' must be ogre_unordered_map<hand, InventorySection*>");
    instance->inventories = *val;
    return 0;
}

static int ShopTraderInventory_set_section(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");
    instance->section = lua_isnoneornil(L, 2) ? nullptr : checkObject<ShopTraderInventorySection>(L, 2, ShopTraderInventorySectionBinding::getMetatableName());
    return 0;
}

int ShopTraderInventoryBinding::_DESTRUCTOR(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ShopTraderInventoryBinding::updateInventory(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");

    instance->updateInventory();
    return 0;
}

int ShopTraderInventoryBinding::_NV_updateInventory(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");

    instance->_NV_updateInventory();
    return 0;
}

int ShopTraderInventoryBinding::refreshGui(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");

    instance->refreshGui();
    return 0;
}

int ShopTraderInventoryBinding::_NV_refreshGui(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");

    instance->_NV_refreshGui();
    return 0;
}

int ShopTraderInventoryBinding::initialiseNewSection(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");

    std::string name = luaL_checkstring(L, 2);
    int w = (int)luaL_checkinteger(L, 3);
    int h = (int)luaL_checkinteger(L, 4);
    AttachSlot _a4 = (AttachSlot)luaL_checkinteger(L, 5);
    bool equipCallbacks = lua_toboolean(L, 6) != 0;
    bool _a6 = lua_toboolean(L, 7) != 0;
    bool _a7 = lua_toboolean(L, 8) != 0;
    int _a8 = (int)luaL_checkinteger(L, 9);
    InventorySection* result = instance->initialiseNewSection(name, w, h, _a4, equipCallbacks, _a6, _a7, _a8);
    return pushObject<InventorySection>(L, result, InventorySectionBinding::getMetatableName());
}

int ShopTraderInventoryBinding::_NV_initialiseNewSection(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");

    std::string name = luaL_checkstring(L, 2);
    int w = (int)luaL_checkinteger(L, 3);
    int h = (int)luaL_checkinteger(L, 4);
    AttachSlot _a4 = (AttachSlot)luaL_checkinteger(L, 5);
    bool equipCallbacks = lua_toboolean(L, 6) != 0;
    bool _a6 = lua_toboolean(L, 7) != 0;
    bool _a7 = lua_toboolean(L, 8) != 0;
    int _a8 = (int)luaL_checkinteger(L, 9);
    InventorySection* result = instance->_NV_initialiseNewSection(name, w, h, _a4, equipCallbacks, _a6, _a7, _a8);
    return pushObject<InventorySection>(L, result, InventorySectionBinding::getMetatableName());
}

int ShopTraderInventoryBinding::_CONSTRUCTOR(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");
    RootObject* owner = lua_isnoneornil(L, 2) ? nullptr : checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    Ogre::vector<InventorySection*>::type* inventoriesList = checkObject<Ogre::vector<InventorySection*>::type>(L, 3, "KenshiLua.OgreVectorInventorySectionPtr");
    if (!inventoriesList) return luaL_error(L, "Argument 3 to _CONSTRUCTOR must be OgreVectorInventorySectionPtr");
    ShopTraderInventory* result = instance->_CONSTRUCTOR(owner, *inventoriesList);
    return pushObject<ShopTraderInventory>(L, result, ShopTraderInventoryBinding::getMetatableName());
}

int ShopTraderInventoryBinding::dropItem(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    instance->dropItem(item);
    return 0;
}

int ShopTraderInventoryBinding::_NV_dropItem(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    instance->_NV_dropItem(item);
    return 0;
}

int ShopTraderInventoryBinding::_addItem(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int quantity = (int)luaL_checkinteger(L, 3);
    bool result = instance->_addItem(item, quantity);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ShopTraderInventoryBinding::_NV__addItem(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int quantity = (int)luaL_checkinteger(L, 3);
    bool result = instance->_NV__addItem(item, quantity);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ShopTraderInventoryBinding::_addItemToInventories(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool result = instance->_addItemToInventories(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ShopTraderInventoryBinding::_removeItemFromInventories(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int quantity = (int)luaL_checkinteger(L, 3);
    instance->_removeItemFromInventories(item, quantity);
    return 0;
}

int ShopTraderInventoryBinding::_sectionAddItemCallback(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    instance->_sectionAddItemCallback(item);
    return 0;
}

int ShopTraderInventoryBinding::_NV__sectionAddItemCallback(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    instance->_NV__sectionAddItemCallback(item);
    return 0;
}

int ShopTraderInventoryBinding::_sectionUpdateItemCallback(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int prevQuantity = (int)luaL_checkinteger(L, 3);
    instance->_sectionUpdateItemCallback(item, prevQuantity);
    return 0;
}

int ShopTraderInventoryBinding::_NV__sectionUpdateItemCallback(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int prevQuantity = (int)luaL_checkinteger(L, 3);
    instance->_NV__sectionUpdateItemCallback(item, prevQuantity);
    return 0;
}

int ShopTraderInventoryBinding::_sectionRemoveItemCallback(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    instance->_sectionRemoveItemCallback(item);
    return 0;
}

int ShopTraderInventoryBinding::_NV__sectionRemoveItemCallback(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    instance->_NV__sectionRemoveItemCallback(item);
    return 0;
}

/*
Skipped methods/members needing manual RVA offset binding if required:
  - static bool Updating (RVA = 0x2132458, unexported static symbol)
*/

int ShopTraderInventoryBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ShopTraderInventoryBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ShopTraderInventory object");
    return 1;
}

void ShopTraderInventoryBinding::registerBinding(lua_State* L)
{
    OgreUnorderedMapBinding<hand, InventorySection*>::registerBinding(
        L, "KenshiLua.HandInventorySectionMap", HandBinding::getMetatableName(), InventorySectionBinding::getMetatableName());
    OgreVectorValueBinding<InventorySection*>::registerBinding(
        L, "KenshiLua.OgreVectorInventorySectionPtr", InventorySectionBinding::getMetatableName());

    static const luaL_Reg meta[] = {
        { "__gc",       ShopTraderInventoryBinding::gc },
        { "__tostring", ShopTraderInventoryBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", ShopTraderInventoryBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", ShopTraderInventoryBinding::_DESTRUCTOR },
        { "updateInventory", ShopTraderInventoryBinding::updateInventory },
        { "_NV_updateInventory", ShopTraderInventoryBinding::_NV_updateInventory },
        { "dropItem", ShopTraderInventoryBinding::dropItem },
        { "_NV_dropItem", ShopTraderInventoryBinding::_NV_dropItem },
        { "refreshGui", ShopTraderInventoryBinding::refreshGui },
        { "_NV_refreshGui", ShopTraderInventoryBinding::_NV_refreshGui },
        { "initialiseNewSection", ShopTraderInventoryBinding::initialiseNewSection },
        { "_NV_initialiseNewSection", ShopTraderInventoryBinding::_NV_initialiseNewSection },
        { "_addItem", ShopTraderInventoryBinding::_addItem },
        { "_NV__addItem", ShopTraderInventoryBinding::_NV__addItem },
        { "_addItemToInventories", ShopTraderInventoryBinding::_addItemToInventories },
        { "_removeItemFromInventories", ShopTraderInventoryBinding::_removeItemFromInventories },
        { "_sectionAddItemCallback", ShopTraderInventoryBinding::_sectionAddItemCallback },
        { "_NV__sectionAddItemCallback", ShopTraderInventoryBinding::_NV__sectionAddItemCallback },
        { "_sectionUpdateItemCallback", ShopTraderInventoryBinding::_sectionUpdateItemCallback },
        { "_NV__sectionUpdateItemCallback", ShopTraderInventoryBinding::_NV__sectionUpdateItemCallback },
        { "_sectionRemoveItemCallback", ShopTraderInventoryBinding::_sectionRemoveItemCallback },
        { "_NV__sectionRemoveItemCallback", ShopTraderInventoryBinding::_NV__sectionRemoveItemCallback },
        { 0, 0 }
    };

    registerClass(
        L, 
        ShopTraderInventoryBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ShopTraderInventoryBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, ShopTraderInventory_get_inventories);
    lua_setfield(L, -2, "inventories");
    lua_pushcfunction(L, ShopTraderInventory_get_section);
    lua_setfield(L, -2, "section");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, ShopTraderInventory_set_inventories);
    lua_setfield(L, -2, "inventories");
    lua_pushcfunction(L, ShopTraderInventory_set_section);
    lua_setfield(L, -2, "section");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Inventory
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, ShopTraderInventoryBinding::getMetatableName(), InventoryBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
