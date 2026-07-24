#include "pch.h"
#include <kenshi/gui/ContextMenu.h>
#include "ContextMenuGUIBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static ContextMenuGUI* getInstance(lua_State* L, int idx)
{
    return checkObject<ContextMenuGUI>(L, idx, ContextMenuGUIBinding::getMetatableName());
}

// --- Getters for ContextMenuGUI ---
static int ContextMenuGUI_get_contextMenuTarget(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");
    return handBinding::push(L, instance->contextMenuTarget);
}

static int ContextMenuGUI_get_name(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");
    lua_pushstring(L, instance->name.c_str());
    return 1;
}

static int ContextMenuGUI_get_nameText(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->nameText);
    return 1;
}

static int ContextMenuGUI_get_optionsList(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->optionsList);
    return 1;
}

// --- Setters for ContextMenuGUI ---
static int ContextMenuGUI_set_contextMenuTarget(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");
    instance->contextMenuTarget = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int ContextMenuGUI_set_name(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");
    instance->name = luaL_checkstring(L, 2);
    return 0;
}

int ContextMenuGUIBinding::_CONSTRUCTOR(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");

    ContextMenuGUI* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ContextMenuGUIBinding::_DESTRUCTOR(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ContextMenuGUIBinding::getMainWidget(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");

    MyGUI::Widget* result = instance->getMainWidget();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ContextMenuGUIBinding::getVisible(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");

    bool result = instance->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ContextMenuGUIBinding::setVisible(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->setVisible(visible);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 22: void show(...) - unsupported arg type
  line 23: void optionSelected(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 28: optionCoords (MyGUI::types::TCoord<int>) - unsupported type
  line 29: buttonCoords (MyGUI::types::TCoord<int>) - unsupported type
  line 30: valueCoords (MyGUI::types::TCoord<int>) - unsupported type
*/

int ContextMenuGUIBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ContextMenuGUIBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ContextMenuGUI object");
    return 1;
}

void ContextMenuGUIBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ContextMenuGUIBinding::gc },
        { "__tostring", ContextMenuGUIBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", ContextMenuGUIBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", ContextMenuGUIBinding::_DESTRUCTOR },
        { "getMainWidget", ContextMenuGUIBinding::getMainWidget },
        { "getVisible", ContextMenuGUIBinding::getVisible },
        { "setVisible", ContextMenuGUIBinding::setVisible },
        { 0, 0 }
    };

    registerClass(
        L, 
        ContextMenuGUIBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ContextMenuGUIBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "contextMenuTarget", ContextMenuGUI_get_contextMenuTarget);
    registerGetter(L, "name", ContextMenuGUI_get_name);
    registerGetter(L, "nameText", ContextMenuGUI_get_nameText);
    registerGetter(L, "optionsList", ContextMenuGUI_get_optionsList);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "contextMenuTarget", ContextMenuGUI_set_contextMenuTarget);
    registerSetter(L, "name", ContextMenuGUI_set_name);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseLayout
    // setMetatableParent(L, ContextMenuGUIBinding::getMetatableName(), wraps::BaseLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua