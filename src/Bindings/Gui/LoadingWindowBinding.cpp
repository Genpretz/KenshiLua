#include "pch.h"
#include "kenshi\gui\LoadingWindow.h"
#include "LoadingWindowBinding.h"
#include "BaseLayoutBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static LoadingWindow* getInstance(lua_State* L, int idx)
{
    return checkObject<LoadingWindow>(L, idx, LoadingWindowBinding::getMetatableName());
}

// --- Getters for LoadingWindow ---
static int LoadingWindow_get_currentIndex(lua_State* L)
{
    LoadingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadingWindow is nil");
    lua_pushinteger(L, instance->currentIndex);
    return 1;
}

static int LoadingWindow_get_currentTime(lua_State* L)
{
    LoadingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadingWindow is nil");
    lua_pushnumber(L, instance->currentTime);
    return 1;
}

static int LoadingWindow_get_loadingText(lua_State* L)
{
    LoadingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadingWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->loadingText);
    return 1;
}

static int LoadingWindow_get_messageText(lua_State* L)
{
    LoadingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadingWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->messageText);
    return 1;
}

static int LoadingWindow_get_backgroundImage(lua_State* L)
{
    LoadingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadingWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->backgroundImage);
    return 1;
}

// --- Setters for LoadingWindow ---
static int LoadingWindow_set_currentIndex(lua_State* L)
{
    LoadingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadingWindow is nil");
    instance->currentIndex = (unsigned char)luaL_checkinteger(L, 2);
    return 0;
}

static int LoadingWindow_set_currentTime(lua_State* L)
{
    LoadingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadingWindow is nil");
    instance->currentTime = (float)luaL_checknumber(L, 2);
    return 0;
}

int LoadingWindowBinding::reload(lua_State* L)
{
    LoadingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadingWindow is nil");

    instance->reload();
    return 0;
}

int LoadingWindowBinding::setVisible(lua_State* L)
{
    LoadingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadingWindow is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->setVisible(visible);
    return 0;
}

int LoadingWindowBinding::getVisible(lua_State* L)
{
    LoadingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadingWindow is nil");

    bool result = instance->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int LoadingWindowBinding::show(lua_State* L)
{
    LoadingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadingWindow is nil");

    instance->show();
    return 0;
}

int LoadingWindowBinding::hide(lua_State* L)
{
    LoadingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadingWindow is nil");

    instance->hide();
    return 0;
}

int LoadingWindowBinding::_CONSTRUCTOR(lua_State* L)
{
    LoadingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadingWindow is nil");

    LoadingWindow* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int LoadingWindowBinding::_DESTRUCTOR(lua_State* L)
{
    LoadingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadingWindow is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int LoadingWindowBinding::frameEntered(lua_State* L)
{
    LoadingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadingWindow is nil");

    float _frame = (float)luaL_checknumber(L, 2);
    instance->frameEntered(_frame);
    return 0;
}

int LoadingWindowBinding::setRandomBackground(lua_State* L)
{
    LoadingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadingWindow is nil");

    instance->setRandomBackground();
    return 0;
}

int LoadingWindowBinding::setRandomTip(lua_State* L)
{
    LoadingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadingWindow is nil");

    instance->setRandomTip();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 10: LoadingWindow* getInstance(...) - static method
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - LoadingWindow_get_loadingText: MyGUI::TextBox* (unbound pointer)
  - LoadingWindow_get_messageText: MyGUI::EditBox* (unbound pointer)
  - LoadingWindow_get_backgroundImage: MyGUI::ImageBox* (unbound pointer)
  - LoadingWindowBinding::_CONSTRUCTOR: LoadingWindow* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 27: loadingStr (MyGUI::UString) - unsupported type
  line 31: tips (lektor<MyGUI::UString>) - unsupported type
*/

int LoadingWindowBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int LoadingWindowBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.LoadingWindow object");
    return 1;
}

void LoadingWindowBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       LoadingWindowBinding::gc },
        { "__tostring", LoadingWindowBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "reload", LoadingWindowBinding::reload },
        { "setVisible", LoadingWindowBinding::setVisible },
        { "getVisible", LoadingWindowBinding::getVisible },
        { "show", LoadingWindowBinding::show },
        { "hide", LoadingWindowBinding::hide },
        { "_CONSTRUCTOR", LoadingWindowBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", LoadingWindowBinding::_DESTRUCTOR },
        { "frameEntered", LoadingWindowBinding::frameEntered },
        { "setRandomBackground", LoadingWindowBinding::setRandomBackground },
        { "setRandomTip", LoadingWindowBinding::setRandomTip },
        { 0, 0 }
    };

    registerClass(
        L, 
        LoadingWindowBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, LoadingWindowBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "currentIndex", LoadingWindow_get_currentIndex);
    registerGetter(L, "currentTime", LoadingWindow_get_currentTime);
    registerGetter(L, "loadingText", LoadingWindow_get_loadingText);
    registerGetter(L, "messageText", LoadingWindow_get_messageText);
    registerGetter(L, "backgroundImage", LoadingWindow_get_backgroundImage);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "currentIndex", LoadingWindow_set_currentIndex);
    registerSetter(L, "currentTime", LoadingWindow_set_currentTime);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseLayout
    setMetatableParent(L, LoadingWindowBinding::getMetatableName(), wraps::BaseLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua