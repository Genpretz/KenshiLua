#include "pch.h"
#include <kenshi/gui/InventoryGUI.h>
#include "InventorySectionGUIBinding.h"
#include "Lua/BindingHelpers.h"

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
}

// --- Setters for InventorySectionGUI ---
int InventorySectionGUIBinding::_DESTRUCTOR(lua_State* L)
{
    InventorySectionGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySectionGUI is nil");

    instance->_DESTRUCTOR();
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

int InventorySectionGUIBinding::getWidget(lua_State* L)
{
    InventorySectionGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySectionGUI is nil");

    MyGUI::Widget* result = instance->getWidget();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int InventorySectionGUIBinding::setEnabled(lua_State* L)
{
    InventorySectionGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventorySectionGUI is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->setEnabled(value);
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
Skipped methods needing manual binding:
  line 46: InventorySectionGUI* _CONSTRUCTOR(...) - unsupported arg type
  line 50: MyGUI::types::TPoint<int> getItemAbsolutePosition(...) - unsupported return type
  line 52: MyGUI::types::TPoint<int> getPositionSlot(...) - unsupported return type
  line 53: bool getBestPositionSlot(...) - unsupported arg type
  line 55: void refreshIcons(...) - unsupported arg type
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
        { "_DESTRUCTOR", InventorySectionGUIBinding::_DESTRUCTOR },
        { "hasMouse", InventorySectionGUIBinding::hasMouse },
        { "getWidget", InventorySectionGUIBinding::getWidget },
        { "setEnabled", InventorySectionGUIBinding::setEnabled },
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
    lua_pushcfunction(L, InventorySectionGUI_get_widget);
    lua_setfield(L, -2, "widget");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua