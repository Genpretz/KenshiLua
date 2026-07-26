#include "pch.h"
#include "kenshi\gui\NewGameOptionsWindow.h"
#include "NewGameOptionsWindowBinding.h"
#include "BaseLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/GameplayOptionsBinding.h"
#include "Bindings/Gui/ToolTipBinding.h"

namespace KenshiLua
{

static NewGameOptionsWindow* getInstance(lua_State* L, int idx)
{
    return checkObject<NewGameOptionsWindow>(L, idx, NewGameOptionsWindowBinding::getMetatableName());
}

// --- Getters for NewGameOptionsWindow ---
static int NewGameOptionsWindow_get_optionsPanel(lua_State* L)
{
    NewGameOptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameOptionsWindow is nil");
    return pushObject<DatapanelGUI>(L, instance->optionsPanel, DatapanelGUIBinding::getMetatableName());
}

static int NewGameOptionsWindow_get_tooltip(lua_State* L)
{
    NewGameOptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameOptionsWindow is nil");
    return pushObject<ToolTip>(L, instance->tooltip, ToolTipBinding::getMetatableName());
}

// --- Setters for NewGameOptionsWindow ---
static int NewGameOptionsWindow_set_optionsPanel(lua_State* L)
{
    NewGameOptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameOptionsWindow is nil");
    instance->optionsPanel = lua_isnoneornil(L, 2) ? nullptr : checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    return 0;
}

static int NewGameOptionsWindow_set_tooltip(lua_State* L)
{
    NewGameOptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameOptionsWindow is nil");
    instance->tooltip = lua_isnoneornil(L, 2) ? nullptr : checkObject<ToolTip>(L, 2, ToolTipBinding::getMetatableName());
    return 0;
}

int NewGameOptionsWindowBinding::_CONSTRUCTOR(lua_State* L)
{
    NewGameOptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameOptionsWindow is nil");

    NewGameOptionsWindow* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int NewGameOptionsWindowBinding::_DESTRUCTOR(lua_State* L)
{
    NewGameOptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameOptionsWindow is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int NewGameOptionsWindowBinding::setVisible(lua_State* L)
{
    NewGameOptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameOptionsWindow is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->setVisible(visible);
    return 0;
}

int NewGameOptionsWindowBinding::getVisible(lua_State* L)
{
    NewGameOptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameOptionsWindow is nil");

    bool result = instance->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int NewGameOptionsWindowBinding::setPosition(lua_State* L)
{
    NewGameOptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameOptionsWindow is nil");

    int x = (int)luaL_checkinteger(L, 2);
    int y = (int)luaL_checkinteger(L, 3);
    instance->setPosition(x, y);
    return 0;
}

int NewGameOptionsWindowBinding::update(lua_State* L)
{
    NewGameOptionsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameOptionsWindow is nil");

    instance->update();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 22: void setOptions(...) - non-string reference arg
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - NewGameOptionsWindowBinding::_CONSTRUCTOR: NewGameOptionsWindow* (unbound pointer)
*/

int NewGameOptionsWindowBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int NewGameOptionsWindowBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.NewGameOptionsWindow object");
    return 1;
}

void NewGameOptionsWindowBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       NewGameOptionsWindowBinding::gc },
        { "__tostring", NewGameOptionsWindowBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", NewGameOptionsWindowBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", NewGameOptionsWindowBinding::_DESTRUCTOR },
        { "setVisible", NewGameOptionsWindowBinding::setVisible },
        { "getVisible", NewGameOptionsWindowBinding::getVisible },
        { "setPosition", NewGameOptionsWindowBinding::setPosition },
        { "update", NewGameOptionsWindowBinding::update },
        { 0, 0 }
    };

    registerClass(
        L, 
        NewGameOptionsWindowBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, NewGameOptionsWindowBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "optionsPanel", NewGameOptionsWindow_get_optionsPanel);
    registerGetter(L, "tooltip", NewGameOptionsWindow_get_tooltip);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "optionsPanel", NewGameOptionsWindow_set_optionsPanel);
    registerSetter(L, "tooltip", NewGameOptionsWindow_set_tooltip);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseLayout
    setMetatableParent(L, NewGameOptionsWindowBinding::getMetatableName(), wraps::BaseLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua