#include "pch.h"
#include "kenshi\gui\InventoryGUI.h"
#include "InventoryIconBinding.h"
#include "BaseLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/Util/iVector2Binding.h"

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
static int InventoryIcon_set_item(lua_State* L)
{
    InventoryIcon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryIcon is nil");
    instance->item = lua_isnoneornil(L, 2) ? nullptr : checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    return 0;
}

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

int InventoryIconBinding::setPosition(lua_State* L)
{
    InventoryIcon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryIcon is nil");

    int left = (int)luaL_checkinteger(L, 2);
    int top = (int)luaL_checkinteger(L, 3);
    instance->setPosition(MyGUI::types::TPoint<int>(left, top));
    return 0;
}

int InventoryIconBinding::getSize(lua_State* L)
{
    InventoryIcon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryIcon is nil");

    MyGUI::types::TSize<int> sz = instance->getSize();
    lua_pushinteger(L, sz.width);
    lua_pushinteger(L, sz.height);
    return 2;
}

int InventoryIconBinding::createIconImage(lua_State* L)
{
    int idx = (testObject<InventoryIcon>(L, 1, InventoryIconBinding::getMetatableName()) != nullptr) ? 2 : 1;
    Item* item = checkObject<Item>(L, idx, ItemBinding::getMetatableName());
    if (!item) return luaL_error(L, "Argument %d to createIconImage must be an Item", idx);

    std::string name;
    iVector2 size;
    InventoryIcon::createIconImage(item, name, size);

    lua_pushlstring(L, name.c_str(), name.size());
    pushValue<iVector2>(L, size, iVector2Binding::getMetatableName());
    return 2;
}

int InventoryIconBinding::getItemSize(lua_State* L)
{
    int idx = (testObject<InventoryIcon>(L, 1, InventoryIconBinding::getMetatableName()) != nullptr) ? 2 : 1;
    GameData* itemData = checkObject<GameData>(L, idx, GameDataBinding::getMetatableName());
    if (!itemData) return luaL_error(L, "Argument %d to getItemSize must be a GameData", idx);

    MyGUI::types::TSize<int> sz = InventoryIcon::getItemSize(itemData);
    lua_pushinteger(L, sz.width);
    lua_pushinteger(L, sz.height);
    return 2;
}

int InventoryIconBinding::getItemPosition(lua_State* L)
{
    int idx = (testObject<InventoryIcon>(L, 1, InventoryIconBinding::getMetatableName()) != nullptr) ? 2 : 1;
    int x = (int)luaL_checkinteger(L, idx);
    int y = (int)luaL_checkinteger(L, idx + 1);

    MyGUI::types::TPoint<int> pt = InventoryIcon::getItemPosition(x, y);
    lua_pushinteger(L, pt.left);
    lua_pushinteger(L, pt.top);
    return 2;
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - InventoryIcon_get_image: MyGUI::ImageBox* (unbound pointer)
  - InventoryIcon_get_quantityText: MyGUI::TextBox* (unbound pointer)
  - InventoryIcon_get_chargesProgress: MyGUI::Widget* (unbound pointer)
  - InventoryIconBinding::getWidget: MyGUI::Widget* (unbound pointer)
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
        { "setPosition", InventoryIconBinding::setPosition },
        { "getSize", InventoryIconBinding::getSize },
        { "createIconImage", InventoryIconBinding::createIconImage },
        { "getItemSize", InventoryIconBinding::getItemSize },
        { "getItemPosition", InventoryIconBinding::getItemPosition },
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
    registerGetter(L, "item", InventoryIcon_get_item);
    registerGetter(L, "image", InventoryIcon_get_image);
    registerGetter(L, "quantityText", InventoryIcon_get_quantityText);
    registerGetter(L, "chargesProgress", InventoryIcon_get_chargesProgress);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "item", InventoryIcon_set_item);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseLayout
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, InventoryIconBinding::getMetatableName(), wraps::BaseLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack

    // Register global class table for static methods
    lua_getglobal(L, "InventoryIcon");
    if (!lua_istable(L, -1))
    {
        lua_pop(L, 1);
        lua_newtable(L);
    }
    registerStaticMethod(L, "createIconImage", InventoryIconBinding::createIconImage);
    registerStaticMethod(L, "getItemSize", InventoryIconBinding::getItemSize);
    registerStaticMethod(L, "getItemPosition", InventoryIconBinding::getItemPosition);
    lua_setglobal(L, "InventoryIcon");
}

} // namespace KenshiLua