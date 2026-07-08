#include "pch.h"
#include "Bindings/Gui/GUIWindowBinding.h"

#include <kenshi/gui/TutorialGUI.h>
#include "TutorialpediaGUIBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static TutorialpediaGUI* getInstance(lua_State* L, int idx)
{
    return checkObject<TutorialpediaGUI>(L, idx, TutorialpediaGUIBinding::getMetatableName());
}

// --- Getters for TutorialpediaGUI ---
static int TutorialpediaGUI_get_currentItem(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->currentItem);
    return 1;
}

static int TutorialpediaGUI_get_currentItemIndex(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");
    lua_pushinteger(L, instance->currentItemIndex);
    return 1;
}

static int TutorialpediaGUI_get_tutorialsList(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->tutorialsList);
    return 1;
}

static int TutorialpediaGUI_get_descriptionText(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->descriptionText);
    return 1;
}

static int TutorialpediaGUI_get_activateButton(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->activateButton);
    return 1;
}

static int TutorialpediaGUI_get_prevButton(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->prevButton);
    return 1;
}

static int TutorialpediaGUI_get_nextButton(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->nextButton);
    return 1;
}

static int TutorialpediaGUI_get_pagingText(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->pagingText);
    return 1;
}

// --- Setters for TutorialpediaGUI ---
static int TutorialpediaGUI_set_currentItemIndex(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");
    instance->currentItemIndex = (int)luaL_checkinteger(L, 2);
    return 0;
}

int TutorialpediaGUIBinding::show(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->show(value);
    return 0;
}

int TutorialpediaGUIBinding::_NV_show(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->_NV_show(value);
    return 0;
}

int TutorialpediaGUIBinding::clear(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");

    instance->clear();
    return 0;
}

int TutorialpediaGUIBinding::_NV_clear(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");

    instance->_NV_clear();
    return 0;
}

int TutorialpediaGUIBinding::isVisible(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");

    bool result = instance->isVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TutorialpediaGUIBinding::_NV_isVisible(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");

    bool result = instance->_NV_isVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TutorialpediaGUIBinding::_CONSTRUCTOR(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");

    TutorialpediaGUI* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TutorialpediaGUIBinding::_DESTRUCTOR(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int TutorialpediaGUIBinding::setup(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");

    instance->setup();
    return 0;
}

int TutorialpediaGUIBinding::updateCurrentItem(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");

    instance->updateCurrentItem();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 217: void tutorialSelectedEvent(...) - unsupported arg type
  line 218: void tutorialPrevEvent(...) - unsupported arg type
  line 219: void tutorialNextEvent(...) - unsupported arg type
  line 220: void tutorialActivateButtonEvent(...) - unsupported arg type
  line 221: void tutorialWindowButton(...) - unsupported arg type
*/

int TutorialpediaGUIBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TutorialpediaGUIBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TutorialpediaGUI object");
    return 1;
}

void TutorialpediaGUIBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TutorialpediaGUIBinding::gc },
        { "__tostring", TutorialpediaGUIBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "show", TutorialpediaGUIBinding::show },
        { "_NV_show", TutorialpediaGUIBinding::_NV_show },
        { "clear", TutorialpediaGUIBinding::clear },
        { "_NV_clear", TutorialpediaGUIBinding::_NV_clear },
        { "isVisible", TutorialpediaGUIBinding::isVisible },
        { "_NV_isVisible", TutorialpediaGUIBinding::_NV_isVisible },
        { "_CONSTRUCTOR", TutorialpediaGUIBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", TutorialpediaGUIBinding::_DESTRUCTOR },
        { "setup", TutorialpediaGUIBinding::setup },
        { "updateCurrentItem", TutorialpediaGUIBinding::updateCurrentItem },
        { 0, 0 }
    };

    registerClass(
        L, 
        TutorialpediaGUIBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TutorialpediaGUIBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, TutorialpediaGUI_get_currentItem);
    lua_setfield(L, -2, "currentItem");
    lua_pushcfunction(L, TutorialpediaGUI_get_currentItemIndex);
    lua_setfield(L, -2, "currentItemIndex");
    lua_pushcfunction(L, TutorialpediaGUI_get_tutorialsList);
    lua_setfield(L, -2, "tutorialsList");
    lua_pushcfunction(L, TutorialpediaGUI_get_descriptionText);
    lua_setfield(L, -2, "descriptionText");
    lua_pushcfunction(L, TutorialpediaGUI_get_activateButton);
    lua_setfield(L, -2, "activateButton");
    lua_pushcfunction(L, TutorialpediaGUI_get_prevButton);
    lua_setfield(L, -2, "prevButton");
    lua_pushcfunction(L, TutorialpediaGUI_get_nextButton);
    lua_setfield(L, -2, "nextButton");
    lua_pushcfunction(L, TutorialpediaGUI_get_pagingText);
    lua_setfield(L, -2, "pagingText");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, TutorialpediaGUI_set_currentItemIndex);
    lua_setfield(L, -2, "currentItemIndex");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to GUIWindow
    setMetatableParent(L, TutorialpediaGUIBinding::getMetatableName(), GUIWindowBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua