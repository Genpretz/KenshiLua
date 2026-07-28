#include "pch.h"
#include "kenshi\gui\NewGameWindow.h"
#include "NewGameWindowBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/Gui/GUIWindowBinding.h"
#include "Bindings/Gui/NewGameOptionsWindowBinding.h"

namespace KenshiLua
{

static NewGameWindow* getInstance(lua_State* L, int idx)
{
    return checkObject<NewGameWindow>(L, idx, NewGameWindowBinding::getMetatableName());
}

// --- Getters for NewGameWindow ---
static int NewGameWindow_get_currentStart(lua_State* L)
{
    NewGameWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameWindow is nil");
    lua_pushinteger(L, instance->currentStart);
    return 1;
}

static int NewGameWindow_get_startInfo(lua_State* L)
{
    NewGameWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameWindow is nil");
    return pushObject<DatapanelGUI>(L, instance->startInfo, DatapanelGUIBinding::getMetatableName());
}

static int NewGameWindow_get_startNameTextBox(lua_State* L)
{
    NewGameWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->startNameTextBox);
    return 1;
}

static int NewGameWindow_get_newGameOptions(lua_State* L)
{
    NewGameWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameWindow is nil");
    return pushObject<NewGameOptionsWindow>(L, instance->newGameOptions, NewGameOptionsWindowBinding::getMetatableName());
}

// --- Setters for NewGameWindow ---
static int NewGameWindow_set_currentStart(lua_State* L)
{
    NewGameWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameWindow is nil");
    instance->currentStart = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int NewGameWindow_set_startInfo(lua_State* L)
{
    NewGameWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameWindow is nil");
    instance->startInfo = lua_isnoneornil(L, 2) ? nullptr : checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    return 0;
}

static int NewGameWindow_set_newGameOptions(lua_State* L)
{
    NewGameWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameWindow is nil");
    instance->newGameOptions = lua_isnoneornil(L, 2) ? nullptr : checkObject<NewGameOptionsWindow>(L, 2, NewGameOptionsWindowBinding::getMetatableName());
    return 0;
}

int NewGameWindowBinding::_CONSTRUCTOR(lua_State* L)
{
    NewGameWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameWindow is nil");

    NewGameWindow* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int NewGameWindowBinding::_DESTRUCTOR(lua_State* L)
{
    NewGameWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameWindow is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int NewGameWindowBinding::setVisible(lua_State* L)
{
    NewGameWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameWindow is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->setVisible(visible);
    return 0;
}

int NewGameWindowBinding::getVisible(lua_State* L)
{
    NewGameWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameWindow is nil");

    bool result = instance->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int NewGameWindowBinding::setRealPosition(lua_State* L)
{
    NewGameWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameWindow is nil");

    float x = (float)luaL_checknumber(L, 2);
    float y = (float)luaL_checknumber(L, 3);
    instance->setRealPosition(x, y);
    return 0;
}

int NewGameWindowBinding::setPosition(lua_State* L)
{
    NewGameWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameWindow is nil");

    int x = (int)luaL_checkinteger(L, 2);
    int y = (int)luaL_checkinteger(L, 3);
    instance->setPosition(x, y);
    return 0;
}

int NewGameWindowBinding::_NV_setPosition(lua_State* L)
{
    NewGameWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameWindow is nil");

    int x = (int)luaL_checkinteger(L, 2);
    int y = (int)luaL_checkinteger(L, 3);
    instance->_NV_setPosition(x, y);
    return 0;
}

int NewGameWindowBinding::show(lua_State* L)
{
    NewGameWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameWindow is nil");

    bool _a1 = lua_toboolean(L, 2) != 0;
    instance->show(_a1);
    return 0;
}

int NewGameWindowBinding::_NV_show(lua_State* L)
{
    NewGameWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameWindow is nil");

    bool _a1 = lua_toboolean(L, 2) != 0;
    instance->_NV_show(_a1);
    return 0;
}

int NewGameWindowBinding::update(lua_State* L)
{
    NewGameWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameWindow is nil");

    instance->update();
    return 0;
}

int NewGameWindowBinding::_NV_update(lua_State* L)
{
    NewGameWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameWindow is nil");

    instance->_NV_update();
    return 0;
}

int NewGameWindowBinding::loadData(lua_State* L)
{
    NewGameWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameWindow is nil");

    instance->loadData();
    return 0;
}

int NewGameWindowBinding::updateCurrentData(lua_State* L)
{
    NewGameWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NewGameWindow is nil");

    instance->updateCurrentData();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 25: void showWindow(...) - unsupported arg type
  line 32: void close(...) - unsupported arg type
  line 33: void prevStart(...) - unsupported arg type
  line 34: void nextStart(...) - unsupported arg type
  line 35: void newGameStart(...) - unsupported arg type
  line 36: void toggleAdvancedOptions(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - NewGameWindow_get_startNameTextBox: MyGUI::TextBox* (unbound pointer)
  - NewGameWindowBinding::_CONSTRUCTOR: NewGameWindow* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 40: startsData (Ogre::FastArray<GameData*>) - unsupported type
*/

int NewGameWindowBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int NewGameWindowBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.NewGameWindow object");
    return 1;
}

void NewGameWindowBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       NewGameWindowBinding::gc },
        { "__tostring", NewGameWindowBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", NewGameWindowBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", NewGameWindowBinding::_DESTRUCTOR },
        { "setVisible", NewGameWindowBinding::setVisible },
        { "getVisible", NewGameWindowBinding::getVisible },
        { "setRealPosition", NewGameWindowBinding::setRealPosition },
        { "setPosition", NewGameWindowBinding::setPosition },
        { "_NV_setPosition", NewGameWindowBinding::_NV_setPosition },
        { "show", NewGameWindowBinding::show },
        { "_NV_show", NewGameWindowBinding::_NV_show },
        { "update", NewGameWindowBinding::update },
        { "_NV_update", NewGameWindowBinding::_NV_update },
        { "loadData", NewGameWindowBinding::loadData },
        { "updateCurrentData", NewGameWindowBinding::updateCurrentData },
        { 0, 0 }
    };

    registerClass(
        L, 
        NewGameWindowBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, NewGameWindowBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "currentStart", NewGameWindow_get_currentStart);
    registerGetter(L, "startInfo", NewGameWindow_get_startInfo);
    registerGetter(L, "startNameTextBox", NewGameWindow_get_startNameTextBox);
    registerGetter(L, "newGameOptions", NewGameWindow_get_newGameOptions);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "currentStart", NewGameWindow_set_currentStart);
    registerSetter(L, "startInfo", NewGameWindow_set_startInfo);
    registerSetter(L, "newGameOptions", NewGameWindow_set_newGameOptions);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to GUIWindow
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, NewGameWindowBinding::getMetatableName(), GUIWindowBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua