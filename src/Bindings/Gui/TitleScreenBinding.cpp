#include "pch.h"
#include "kenshi\gui\TitleScreen.h"
#include "TitleScreenBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/GUIWindowBinding.h"
#include "Bindings/Gui/NewGameWindowBinding.h"

namespace KenshiLua
{

static TitleScreen* getInstance(lua_State* L, int idx)
{
    return checkObject<TitleScreen>(L, idx, TitleScreenBinding::getMetatableName());
}

// --- Getters for TitleScreen ---
static int TitleScreen_get_newGameWindow(lua_State* L)
{
    TitleScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TitleScreen is nil");
    return pushObject<NewGameWindow>(L, instance->newGameWindow, NewGameWindowBinding::getMetatableName());
}

static int TitleScreen_get_creditsPanel(lua_State* L)
{
    TitleScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TitleScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->creditsPanel);
    return 1;
}

static int TitleScreen_get_creditsText(lua_State* L)
{
    TitleScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TitleScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->creditsText);
    return 1;
}

static int TitleScreen_get_creditsLoaded(lua_State* L)
{
    TitleScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TitleScreen is nil");
    lua_pushboolean(L, instance->creditsLoaded ? 1 : 0);
    return 1;
}

static int TitleScreen_get_creditsPosition(lua_State* L)
{
    TitleScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TitleScreen is nil");
    lua_pushnumber(L, instance->creditsPosition);
    return 1;
}

// --- Setters for TitleScreen ---
static int TitleScreen_set_newGameWindow(lua_State* L)
{
    TitleScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TitleScreen is nil");
    instance->newGameWindow = lua_isnoneornil(L, 2) ? nullptr : checkObject<NewGameWindow>(L, 2, NewGameWindowBinding::getMetatableName());
    return 0;
}

static int TitleScreen_set_creditsLoaded(lua_State* L)
{
    TitleScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TitleScreen is nil");
    instance->creditsLoaded = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TitleScreen_set_creditsPosition(lua_State* L)
{
    TitleScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TitleScreen is nil");
    instance->creditsPosition = (float)luaL_checknumber(L, 2);
    return 0;
}

int TitleScreenBinding::_CONSTRUCTOR(lua_State* L)
{
    TitleScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TitleScreen is nil");

    TitleScreen* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TitleScreenBinding::_DESTRUCTOR(lua_State* L)
{
    TitleScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TitleScreen is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int TitleScreenBinding::clear(lua_State* L)
{
    TitleScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TitleScreen is nil");

    instance->clear();
    return 0;
}

int TitleScreenBinding::_NV_clear(lua_State* L)
{
    TitleScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TitleScreen is nil");

    instance->_NV_clear();
    return 0;
}

int TitleScreenBinding::show(lua_State* L)
{
    TitleScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TitleScreen is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->show(on);
    return 0;
}

int TitleScreenBinding::_NV_show(lua_State* L)
{
    TitleScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TitleScreen is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_show(on);
    return 0;
}

int TitleScreenBinding::update(lua_State* L)
{
    TitleScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TitleScreen is nil");

    instance->update();
    return 0;
}

int TitleScreenBinding::_NV_update(lua_State* L)
{
    TitleScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TitleScreen is nil");

    instance->_NV_update();
    return 0;
}

int TitleScreenBinding::closeTheOtherBits(lua_State* L)
{
    TitleScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TitleScreen is nil");

    bool result = instance->closeTheOtherBits();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TitleScreenBinding::setCreditsVisible(lua_State* L)
{
    TitleScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TitleScreen is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->setCreditsVisible(value);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 19: TitleScreen* getSingleton(...) - static method
  line 32: void loadGame(...) - unsupported arg type
  line 33: void importGame(...) - unsupported arg type
  line 34: void showOptions(...) - unsupported arg type
  line 35: void credits(...) - unsupported arg type
  line 36: void exitGame(...) - unsupported arg type
  line 38: void continueGame(...) - unsupported arg type
  line 39: void hover(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - TitleScreen_get_creditsPanel: MyGUI::Widget* (unbound pointer)
  - TitleScreen_get_creditsText: MyGUI::TextBox* (unbound pointer)
  - TitleScreenBinding::_CONSTRUCTOR: TitleScreen* (unbound pointer)
*/

int TitleScreenBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TitleScreenBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TitleScreen object");
    return 1;
}

void TitleScreenBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TitleScreenBinding::gc },
        { "__tostring", TitleScreenBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", TitleScreenBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", TitleScreenBinding::_DESTRUCTOR },
        { "clear", TitleScreenBinding::clear },
        { "_NV_clear", TitleScreenBinding::_NV_clear },
        { "show", TitleScreenBinding::show },
        { "_NV_show", TitleScreenBinding::_NV_show },
        { "update", TitleScreenBinding::update },
        { "_NV_update", TitleScreenBinding::_NV_update },
        { "closeTheOtherBits", TitleScreenBinding::closeTheOtherBits },
        { "setCreditsVisible", TitleScreenBinding::setCreditsVisible },
        { 0, 0 }
    };

    registerClass(
        L, 
        TitleScreenBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TitleScreenBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "newGameWindow", TitleScreen_get_newGameWindow);
    registerGetter(L, "creditsPanel", TitleScreen_get_creditsPanel);
    registerGetter(L, "creditsText", TitleScreen_get_creditsText);
    registerGetter(L, "creditsLoaded", TitleScreen_get_creditsLoaded);
    registerGetter(L, "creditsPosition", TitleScreen_get_creditsPosition);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "newGameWindow", TitleScreen_set_newGameWindow);
    registerSetter(L, "creditsLoaded", TitleScreen_set_creditsLoaded);
    registerSetter(L, "creditsPosition", TitleScreen_set_creditsPosition);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to GUIWindow
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, TitleScreenBinding::getMetatableName(), GUIWindowBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua