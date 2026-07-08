#include "pch.h"
#include "Bindings/ItemBinding.h"

#include <kenshi/gui/InventoryGUI.h>
#include "InventoryIconBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static InventoryIcon* getInstance(lua_State* L, int idx)
{
    return checkObject<InventoryIcon>(L, idx, InventoryIconBinding::getMetatableName());
}

// --- Getters for InventoryIcon ---
static int InventoryIcon_get_item(lua_State* L)
{
    InventoryIcon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryIcon is nil");
    return pushObject<Item>(L, instance->item, ItemBinding::getMetatableName());
}

static int InventoryIcon_get_image(lua_State* L)
{
    InventoryIcon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryIcon is nil");
    lua_pushlightuserdata(L, (void*)instance->image);
    return 1;
}

static int InventoryIcon_get_quantityText(lua_State* L)
{
    InventoryIcon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryIcon is nil");
    lua_pushlightuserdata(L, (void*)instance->quantityText);
    return 1;
}

static int InventoryIcon_get_chargesProgress(lua_State* L)
{
    InventoryIcon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryIcon is nil");
    lua_pushlightuserdata(L, (void*)instance->chargesProgress);
    return 1;
}

// --- Setters for InventoryIcon ---
int InventoryIconBinding::update(lua_State* L)
{
    InventoryIcon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryIcon is nil");

    instance->update();
    return 0;
}

int InventoryIconBinding::getWidget(lua_State* L)
{
    InventoryIcon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryIcon is nil");

    MyGUI::Widget* result = instance->getWidget();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int InventoryIconBinding::_DESTRUCTOR(lua_State* L)
{
    InventoryIcon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryIcon is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 23: InventoryIcon* _CONSTRUCTOR(...) - unsupported arg type
  line 24: void setPosition(...) - unsupported arg type
  line 25: MyGUI::types::TSize<int> getSize(...) - unsupported return type
  line 28: void createIconImage(...) - static method
  line 29: MyGUI::types::TSize<int> getItemSize(...) - static method
  line 30: MyGUI::types::TPoint<int> getItemPosition(...) - static method
*/

int InventoryIconBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int InventoryIconBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.InventoryIcon object");
    return 1;
}

void InventoryIconBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       InventoryIconBinding::gc },
        { "__tostring", InventoryIconBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "update", InventoryIconBinding::update },
        { "getWidget", InventoryIconBinding::getWidget },
        { "_DESTRUCTOR", InventoryIconBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        InventoryIconBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, InventoryIconBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, InventoryIcon_get_item);
    lua_setfield(L, -2, "item");
    lua_pushcfunction(L, InventoryIcon_get_image);
    lua_setfield(L, -2, "image");
    lua_pushcfunction(L, InventoryIcon_get_quantityText);
    lua_setfield(L, -2, "quantityText");
    lua_pushcfunction(L, InventoryIcon_get_chargesProgress);
    lua_setfield(L, -2, "chargesProgress");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseLayout
    // // // // // // // // // setMetatableParent(L, InventoryIconBinding::getMetatableName(), wraps::BaseLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua