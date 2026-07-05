#include "pch.h"
#include "kenshi\ShopTraderInventory.h"
#include "ShopTraderInventoryBinding.h"
#include "InventoryBinding.h"
#include "InventorySectionBinding.h"
#include "ItemBinding.h"
#include "Lua/BindingHelpers.h"

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
    // TODO: Unsupported type for inventories (ogre_unordered_map<hand, InventorySection*>::type)
    lua_pushnil(L);
    return 1;
}

static int ShopTraderInventory_get_section(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");
    lua_pushlightuserdata(L, (void*)instance->section);
    return 1;
}

// --- Setters for ShopTraderInventory ---
static int ShopTraderInventory_set_inventories(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");
    return luaL_error(L, "Read-only or unsupported setter type for inventories");
}

static int ShopTraderInventory_set_section(lua_State* L)
{
    ShopTraderInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventory is nil");
    return luaL_error(L, "Read-only or unsupported setter type for section");
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

/*
Skipped methods needing manual binding:
  line 28: ShopTraderInventory* _CONSTRUCTOR(...) - unsupported arg type
  line 33: void dropItem(...) - unsupported arg type
  line 34: void _NV_dropItem(...) - unsupported arg type
  line 39: bool _addItem(...) - unsupported arg type
  line 40: bool _NV__addItem(...) - unsupported arg type
  line 41: bool _addItemToInventories(...) - unsupported arg type
  line 42: void _removeItemFromInventories(...) - unsupported arg type
  line 43: void _sectionAddItemCallback(...) - unsupported arg type
  line 44: void _NV__sectionAddItemCallback(...) - unsupported arg type
  line 45: void _sectionUpdateItemCallback(...) - unsupported arg type
  line 46: void _NV__sectionUpdateItemCallback(...) - unsupported arg type
  line 47: void _sectionRemoveItemCallback(...) - unsupported arg type
  line 48: void _NV__sectionRemoveItemCallback(...) - unsupported arg type
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
    static const luaL_Reg meta[] = {
        { "__gc",       ShopTraderInventoryBinding::gc },
        { "__tostring", ShopTraderInventoryBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", ShopTraderInventoryBinding::_DESTRUCTOR },
        { "updateInventory", ShopTraderInventoryBinding::updateInventory },
        { "_NV_updateInventory", ShopTraderInventoryBinding::_NV_updateInventory },
        { "refreshGui", ShopTraderInventoryBinding::refreshGui },
        { "_NV_refreshGui", ShopTraderInventoryBinding::_NV_refreshGui },
        { "initialiseNewSection", ShopTraderInventoryBinding::initialiseNewSection },
        { "_NV_initialiseNewSection", ShopTraderInventoryBinding::_NV_initialiseNewSection },
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
    setMetatableParent(L, ShopTraderInventoryBinding::getMetatableName(), InventoryBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua