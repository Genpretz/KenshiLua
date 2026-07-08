#include "pch.h"
#include <kenshi/gui/TutorialGUI.h>
#include "TutorialGUIBinding.h"
#include "GUIWindowBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static TutorialGUI* getInstance(lua_State* L, int idx)
{
    return checkObject<TutorialGUI>(L, idx, TutorialGUIBinding::getMetatableName());
}

// --- Getters for TutorialGUI ---
static int TutorialGUI_get_highlightItem(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");
    lua_pushinteger(L, (lua_Integer)instance->highlightItem);
    return 1;
}

static int TutorialGUI_get_highlightItemWidget(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->highlightItemWidget);
    return 1;
}

static int TutorialGUI_get_highlightPanel(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->highlightPanel);
    return 1;
}

static int TutorialGUI_get_highlightDirection(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");
    lua_pushinteger(L, instance->highlightDirection);
    return 1;
}

static int TutorialGUI_get_highlightAlpha(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");
    lua_pushnumber(L, instance->highlightAlpha);
    return 1;
}

static int TutorialGUI_get_window(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->window);
    return 1;
}

static int TutorialGUI_get_windowPrevButton(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->windowPrevButton);
    return 1;
}

static int TutorialGUI_get_windowNextButton(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->windowNextButton);
    return 1;
}

static int TutorialGUI_get_windowText(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->windowText);
    return 1;
}

static int TutorialGUI_get_dismissButton(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->dismissButton);
    return 1;
}

static int TutorialGUI_get_pagingText(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->pagingText);
    return 1;
}

static int TutorialGUI_get_tooltipsPanel(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->tooltipsPanel);
    return 1;
}

static int TutorialGUI_get_currentTutorialItem(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->currentTutorialItem);
    return 1;
}

static int TutorialGUI_get_flashNewItem(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");
    lua_pushboolean(L, instance->flashNewItem ? 1 : 0);
    return 1;
}

static int TutorialGUI_get_enabled(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");
    lua_pushboolean(L, instance->enabled ? 1 : 0);
    return 1;
}

// --- Setters for TutorialGUI ---
static int TutorialGUI_set_highlightItem(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");
    instance->highlightItem = (TutorialGUI::HighlightItem)luaL_checkinteger(L, 2);
    return 0;
}

static int TutorialGUI_set_highlightDirection(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");
    instance->highlightDirection = (char)luaL_checkinteger(L, 2);
    return 0;
}

static int TutorialGUI_set_highlightAlpha(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");
    instance->highlightAlpha = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TutorialGUI_set_flashNewItem(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");
    instance->flashNewItem = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TutorialGUI_set_enabled(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");
    instance->enabled = lua_toboolean(L, 2) != 0;
    return 0;
}

int TutorialGUIBinding::_CONSTRUCTOR(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");

    TutorialGUI* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TutorialGUIBinding::_DESTRUCTOR(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int TutorialGUIBinding::clear(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");

    instance->clear();
    return 0;
}

int TutorialGUIBinding::_NV_clear(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");

    instance->_NV_clear();
    return 0;
}

int TutorialGUIBinding::startHighlight(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");

    TutorialGUI::HighlightItem item = (TutorialGUI::HighlightItem)luaL_checkinteger(L, 2);
    instance->startHighlight(item);
    return 0;
}

int TutorialGUIBinding::endHighlight(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");

    instance->endHighlight();
    return 0;
}

int TutorialGUIBinding::_setHightlightCoords(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");

    instance->_setHightlightCoords();
    return 0;
}

int TutorialGUIBinding::update(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");

    instance->update();
    return 0;
}

int TutorialGUIBinding::_NV_update(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");

    instance->_NV_update();
    return 0;
}

int TutorialGUIBinding::setEnabled(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->setEnabled(value);
    return 0;
}

int TutorialGUIBinding::show(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->show(value);
    return 0;
}

int TutorialGUIBinding::_NV_show(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->_NV_show(value);
    return 0;
}

int TutorialGUIBinding::arrangeList(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");

    instance->arrangeList();
    return 0;
}

int TutorialGUIBinding::refreshUI(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");

    instance->refreshUI();
    return 0;
}

int TutorialGUIBinding::closeTutorialWindow(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");

    instance->closeTutorialWindow();
    return 0;
}

int TutorialGUIBinding::updateCurrentItem(lua_State* L)
{
    TutorialGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUI is nil");

    instance->updateCurrentItem();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 164: void addTutorialsToList(...) - unsupported arg type
  line 165: void removeTutorialFromList(...) - unsupported arg type
  line 168: void windowButtonEvent(...) - unsupported arg type
  line 169: void windowPrevEvent(...) - unsupported arg type
  line 170: void windowNextEvent(...) - unsupported arg type
  line 171: void dismissButtonEvent(...) - unsupported arg type
  line 172: void tooltipOpen(...) - unsupported arg type
  line 173: void tooltipClose(...) - unsupported arg type
  line 174: void showTutorialWindow(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 190: activeTutorialsList (Ogre::vector<TutorialGUI::TutorialGUILine*>::type) - unsupported type
  line 191: activeTutorials (ogre_unordered_map<TutorialItem*, TutorialGUI::TutorialGUILine*>::type) - unsupported type
*/

int TutorialGUIBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TutorialGUIBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TutorialGUI object");
    return 1;
}

void TutorialGUIBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TutorialGUIBinding::gc },
        { "__tostring", TutorialGUIBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", TutorialGUIBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", TutorialGUIBinding::_DESTRUCTOR },
        { "clear", TutorialGUIBinding::clear },
        { "_NV_clear", TutorialGUIBinding::_NV_clear },
        { "startHighlight", TutorialGUIBinding::startHighlight },
        { "endHighlight", TutorialGUIBinding::endHighlight },
        { "_setHightlightCoords", TutorialGUIBinding::_setHightlightCoords },
        { "update", TutorialGUIBinding::update },
        { "_NV_update", TutorialGUIBinding::_NV_update },
        { "setEnabled", TutorialGUIBinding::setEnabled },
        { "show", TutorialGUIBinding::show },
        { "_NV_show", TutorialGUIBinding::_NV_show },
        { "arrangeList", TutorialGUIBinding::arrangeList },
        { "refreshUI", TutorialGUIBinding::refreshUI },
        { "closeTutorialWindow", TutorialGUIBinding::closeTutorialWindow },
        { "updateCurrentItem", TutorialGUIBinding::updateCurrentItem },
        { 0, 0 }
    };

    registerClass(
        L, 
        TutorialGUIBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TutorialGUIBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, TutorialGUI_get_highlightItem);
    lua_setfield(L, -2, "highlightItem");
    lua_pushcfunction(L, TutorialGUI_get_highlightItemWidget);
    lua_setfield(L, -2, "highlightItemWidget");
    lua_pushcfunction(L, TutorialGUI_get_highlightPanel);
    lua_setfield(L, -2, "highlightPanel");
    lua_pushcfunction(L, TutorialGUI_get_highlightDirection);
    lua_setfield(L, -2, "highlightDirection");
    lua_pushcfunction(L, TutorialGUI_get_highlightAlpha);
    lua_setfield(L, -2, "highlightAlpha");
    lua_pushcfunction(L, TutorialGUI_get_window);
    lua_setfield(L, -2, "window");
    lua_pushcfunction(L, TutorialGUI_get_windowPrevButton);
    lua_setfield(L, -2, "windowPrevButton");
    lua_pushcfunction(L, TutorialGUI_get_windowNextButton);
    lua_setfield(L, -2, "windowNextButton");
    lua_pushcfunction(L, TutorialGUI_get_windowText);
    lua_setfield(L, -2, "windowText");
    lua_pushcfunction(L, TutorialGUI_get_dismissButton);
    lua_setfield(L, -2, "dismissButton");
    lua_pushcfunction(L, TutorialGUI_get_pagingText);
    lua_setfield(L, -2, "pagingText");
    lua_pushcfunction(L, TutorialGUI_get_tooltipsPanel);
    lua_setfield(L, -2, "tooltipsPanel");
    lua_pushcfunction(L, TutorialGUI_get_currentTutorialItem);
    lua_setfield(L, -2, "currentTutorialItem");
    lua_pushcfunction(L, TutorialGUI_get_flashNewItem);
    lua_setfield(L, -2, "flashNewItem");
    lua_pushcfunction(L, TutorialGUI_get_enabled);
    lua_setfield(L, -2, "enabled");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, TutorialGUI_set_highlightItem);
    lua_setfield(L, -2, "highlightItem");
    lua_pushcfunction(L, TutorialGUI_set_highlightDirection);
    lua_setfield(L, -2, "highlightDirection");
    lua_pushcfunction(L, TutorialGUI_set_highlightAlpha);
    lua_setfield(L, -2, "highlightAlpha");
    lua_pushcfunction(L, TutorialGUI_set_flashNewItem);
    lua_setfield(L, -2, "flashNewItem");
    lua_pushcfunction(L, TutorialGUI_set_enabled);
    lua_setfield(L, -2, "enabled");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to GUIWindow
    setMetatableParent(L, TutorialGUIBinding::getMetatableName(), GUIWindowBinding::getMetatableName());

        // Wire up inheritance
    setMetatableParent(L, TutorialGUIBinding::getMetatableName(), GUIWindowBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua