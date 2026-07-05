#include "pch.h"
#include "kenshi\ShopTraderInventory.h"
#include "ShopTraderInventorySectionBinding.h"
#include "InventoryBinding.h"
#include "InventorySectionBinding.h"
#include "ItemBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static ShopTraderInventorySection* getInstance(lua_State* L, int idx)
{
    return checkObject<ShopTraderInventorySection>(L, idx, ShopTraderInventorySectionBinding::getMetatableName());
}

// --- Getters for ShopTraderInventorySection ---
// --- Setters for ShopTraderInventorySection ---
int ShopTraderInventorySectionBinding::autoArrange(lua_State* L)
{
    ShopTraderInventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventorySection is nil");

    instance->autoArrange();
    return 0;
}

int ShopTraderInventorySectionBinding::_NV_autoArrange(lua_State* L)
{
    ShopTraderInventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventorySection is nil");

    instance->_NV_autoArrange();
    return 0;
}

int ShopTraderInventorySectionBinding::_DESTRUCTOR(lua_State* L)
{
    ShopTraderInventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventorySection is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ShopTraderInventorySectionBinding::_CONSTRUCTOR(lua_State* L)
{
    ShopTraderInventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventorySection is nil");
    std::string name = luaL_checkstring(L, 2);
    int w = (int)luaL_checkinteger(L, 3);
    int h = (int)luaL_checkinteger(L, 4);
    Inventory* inventory = checkObject<Inventory>(L, 5, InventoryBinding::getMetatableName());

    ShopTraderInventorySection* result = instance->_CONSTRUCTOR(name, w, h, inventory);
    return pushObject<ShopTraderInventorySection>(L, result, ShopTraderInventorySectionBinding::getMetatableName());
}

int ShopTraderInventorySectionBinding::addItem(lua_State* L)
{
    ShopTraderInventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventorySection is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int quantity = (int)luaL_checkinteger(L, 3);
    bool result = instance->addItem(item, quantity);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ShopTraderInventorySectionBinding::_NV_addItem(lua_State* L)
{
    ShopTraderInventorySection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ShopTraderInventorySection is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int quantity = (int)luaL_checkinteger(L, 3);
    bool result = instance->_NV_addItem(item, quantity);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ShopTraderInventorySectionBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ShopTraderInventorySectionBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ShopTraderInventorySection object");
    return 1;
}

void ShopTraderInventorySectionBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ShopTraderInventorySectionBinding::gc },
        { "__tostring", ShopTraderInventorySectionBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "autoArrange", ShopTraderInventorySectionBinding::autoArrange },
        { "_NV_autoArrange", ShopTraderInventorySectionBinding::_NV_autoArrange },
        { "_DESTRUCTOR", ShopTraderInventorySectionBinding::_DESTRUCTOR },
        { "addItem", ShopTraderInventorySectionBinding::addItem },
        { "_NV_addItem", ShopTraderInventorySectionBinding::_NV_addItem },
        { "_CONSTRUCTOR", ShopTraderInventorySectionBinding::_CONSTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        ShopTraderInventorySectionBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ShopTraderInventorySectionBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to InventorySection
    setMetatableParent(L, ShopTraderInventorySectionBinding::getMetatableName(), InventorySectionBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua