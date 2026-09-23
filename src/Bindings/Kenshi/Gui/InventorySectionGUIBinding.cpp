#include "pch.h"
#include "kenshi\gui\InventoryGUI.h"
#include "InventorySectionGUIBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/InventorySectionBinding.h"
#include "Bindings/Kenshi/ItemBinding.h"
#include "Bindings/MyGUI/TypesBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"

namespace KenshiLua
{

static InventorySectionGUI* getInstance(lua_State* L, int idx)
{
    return checkObject<InventorySectionGUI>(L, idx, InventorySectionGUIBinding::getMetatableName());
}

// --- Getters for InventorySectionGUI ---
static int InventorySectionGUI_get_widget(lua_State* L)
{
    InventorySectionGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySectionGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->widget);
    return 1;
    return MyGUIBindings::pushWidget(L, instance->widget);
}

// --- Setters for InventorySectionGUI ---
static int InventorySectionGUI_set_widget(lua_State* L)
{
    InventorySectionGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySectionGUI is nil");
    instance->widget = lua_isnoneornil(L, 2) ? nullptr : WidgetBinding::getWidget(L, 2);
    return 0;
}

int InventorySectionGUIBinding::hasMouse(lua_State* L)
{
    InventorySectionGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySectionGUI is nil");

    bool result = instance->hasMouse();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventorySectionGUIBinding::getItemAbsolutePosition(lua_State* L)
{
    InventorySectionGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySectionGUI is nil");

    int x = (int)luaL_checkinteger(L, 2);
    int y = (int)luaL_checkinteger(L, 3);
    MyGUI::IntPoint result = instance->getItemAbsolutePosition(x, y);
    return pushValue<MyGUI::IntPoint>(L, result, IntPointBinding::getMetatableName());
}

int InventorySectionGUIBinding::getWidget(lua_State* L)
{
    InventorySectionGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySectionGUI is nil");

    MyGUI::Widget* result = instance->getWidget();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
    return MyGUIBindings::pushWidget(L, result);
}

int InventorySectionGUIBinding::getPositionSlot(lua_State* L)
{
    InventorySectionGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySectionGUI is nil");

    MyGUI::IntPoint position = MyGUIBindings::readIntPoint(L, 2);
    InventorySection* section = checkObject<InventorySection>(L, 3, InventorySectionBinding::getMetatableName());
    bool round = lua_toboolean(L, 4) != 0;

    MyGUI::IntPoint result = instance->getPositionSlot(position, section, round);
    return pushValue<MyGUI::IntPoint>(L, result, IntPointBinding::getMetatableName());
}

int InventorySectionGUIBinding::getBestPositionSlot(lua_State* L)
{
    InventorySectionGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySectionGUI is nil");

    MyGUI::IntPoint position = MyGUIBindings::readIntPoint(L, 2);
    InventorySection* section = checkObject<InventorySection>(L, 3, InventorySectionBinding::getMetatableName());
    Item* item = checkObject<Item>(L, 4, ItemBinding::getMetatableName());

    MyGUI::IntPoint slot(0, 0);
    bool result = instance->getBestPositionSlot(position, section, item, slot);
    lua_pushboolean(L, result ? 1 : 0);
    pushValue<MyGUI::IntPoint>(L, slot, IntPointBinding::getMetatableName());
    return 2;
}

int InventorySectionGUIBinding::setEnabled(lua_State* L)
{
    InventorySectionGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySectionGUI is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->setEnabled(value);
    return 0;
}

int InventorySectionGUIBinding::refreshIcons(lua_State* L)
{
    InventorySectionGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySectionGUI is nil");

    InventorySection* section = checkObject<InventorySection>(L, 2, InventorySectionBinding::getMetatableName());
    instance->refreshIcons(section);
    return 0;
}

int InventorySectionGUIBinding::update(lua_State* L)
{
    InventorySectionGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySectionGUI is nil");

    instance->update();
    return 0;
}


/*
LIGHTUSERDATA DEPENDENCIES:
  - InventorySectionGUI_get_widget: MyGUI::Widget* (unbound pointer)
  - InventorySectionGUIBinding::getWidget: MyGUI::Widget* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 58: itemsIcons (Ogre::vector<InventoryIcon*>::type) - unsupported type
*/

int InventorySectionGUIBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int InventorySectionGUIBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.InventorySectionGUI object");
    return 1;
}

void InventorySectionGUIBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       InventorySectionGUIBinding::gc },
        { "__tostring", InventorySectionGUIBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "hasMouse", InventorySectionGUIBinding::hasMouse },
        { "getItemAbsolutePosition", InventorySectionGUIBinding::getItemAbsolutePosition },
        { "getWidget", InventorySectionGUIBinding::getWidget },
        { "getPositionSlot", InventorySectionGUIBinding::getPositionSlot },
        { "getBestPositionSlot", InventorySectionGUIBinding::getBestPositionSlot },
        { "setEnabled", InventorySectionGUIBinding::setEnabled },
        { "refreshIcons", InventorySectionGUIBinding::refreshIcons },
        { "update", InventorySectionGUIBinding::update },
        { 0, 0 }
    };

    registerClass(
        L, 
        InventorySectionGUIBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, InventorySectionGUIBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "widget", InventorySectionGUI_get_widget);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "widget", InventorySectionGUI_set_widget);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua