#include "pch.h"
#include "kenshi\gui\ScreenLabel.h"
#include "ProgressBarWidgetBinding.h"
#include "BaseLayoutBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
typedef FloatingProgressBar::ProgressBarWidget ProgressBarWidget;


static ProgressBarWidget* getInstance(lua_State* L, int idx)
{
    return checkObject<ProgressBarWidget>(L, idx, ProgressBarWidgetBinding::getMetatableName());
}

// --- Getters for ProgressBarWidget ---
static int ProgressBarWidget_get_bar(lua_State* L)
{
    ProgressBarWidget* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProgressBarWidget is nil");
    lua_pushlightuserdata(L, (void*)instance->bar);
    return 1;
}

static int ProgressBarWidget_get_label(lua_State* L)
{
    ProgressBarWidget* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProgressBarWidget is nil");
    lua_pushlightuserdata(L, (void*)instance->label);
    return 1;
}

// --- Setters for ProgressBarWidget ---
int ProgressBarWidgetBinding::_CONSTRUCTOR(lua_State* L)
{
    ProgressBarWidget* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProgressBarWidget is nil");

    ProgressBarWidget* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ProgressBarWidgetBinding::_DESTRUCTOR(lua_State* L)
{
    ProgressBarWidget* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProgressBarWidget is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ProgressBarWidgetBinding::setVisible(lua_State* L)
{
    ProgressBarWidget* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProgressBarWidget is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->setVisible(value);
    return 0;
}

int ProgressBarWidgetBinding::setProgress(lua_State* L)
{
    ProgressBarWidget* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProgressBarWidget is nil");

    int value = (int)luaL_checkinteger(L, 2);
    instance->setProgress(value);
    return 0;
}

int ProgressBarWidgetBinding::setPosition(lua_State* L)
{
    ProgressBarWidget* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProgressBarWidget is nil");

    int x = (int)luaL_checkinteger(L, 2);
    int y = (int)luaL_checkinteger(L, 3);
    instance->setPosition(x, y);
    return 0;
}

int ProgressBarWidgetBinding::setCaption(lua_State* L)
{
    ProgressBarWidget* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProgressBarWidget is nil");

    const std::string value = luaL_checkstring(L, 2);
    instance->setCaption(value);
    return 0;
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - ProgressBarWidget_get_bar: MyGUI::ProgressBar* (unbound pointer)
  - ProgressBarWidget_get_label: MyGUI::TextBox* (unbound pointer)
  - ProgressBarWidgetBinding::_CONSTRUCTOR: ProgressBarWidget* (unbound pointer)
*/

int ProgressBarWidgetBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ProgressBarWidgetBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ProgressBarWidget object");
    return 1;
}

void ProgressBarWidgetBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ProgressBarWidgetBinding::gc },
        { "__tostring", ProgressBarWidgetBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", ProgressBarWidgetBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", ProgressBarWidgetBinding::_DESTRUCTOR },
        { "setVisible", ProgressBarWidgetBinding::setVisible },
        { "setProgress", ProgressBarWidgetBinding::setProgress },
        { "setPosition", ProgressBarWidgetBinding::setPosition },
        { "setCaption", ProgressBarWidgetBinding::setCaption },
        { 0, 0 }
    };

    registerClass(
        L, 
        ProgressBarWidgetBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ProgressBarWidgetBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "bar", ProgressBarWidget_get_bar);
    registerGetter(L, "label", ProgressBarWidget_get_label);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseLayout
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, ProgressBarWidgetBinding::getMetatableName(), wraps::BaseLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua