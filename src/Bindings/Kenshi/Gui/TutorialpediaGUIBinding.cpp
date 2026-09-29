#include "pch.h"
#include "kenshi\gui\TutorialGUI.h"
#include "TutorialpediaGUIBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/MyGUI/MyGUIBinding.h"
#include "Bindings/MyGUI/ListBoxBinding.h"
#include "Bindings/MyGUI/WindowBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h" 
#include "Bindings/Kenshi/Gui/GUIWindowBinding.h"
#include "Bindings/Kenshi/Gui/TutorialItemBinding.h"

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
    return pushObject<TutorialItem>(L, instance->currentItem, TutorialItemBinding::getMetatableName());
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
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->tutorialsList, MyGUIBinding::getMetatableName());
}

static int TutorialpediaGUI_get_descriptionText(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->descriptionText, MyGUIBinding::getMetatableName());
}

static int TutorialpediaGUI_get_activateButton(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->activateButton, MyGUIBinding::getMetatableName());
}

static int TutorialpediaGUI_get_prevButton(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->prevButton, MyGUIBinding::getMetatableName());
}

static int TutorialpediaGUI_get_nextButton(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->nextButton, MyGUIBinding::getMetatableName());
}

static int TutorialpediaGUI_get_pagingText(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->pagingText, MyGUIBinding::getMetatableName());
}

// --- Setters for TutorialpediaGUI ---
static int TutorialpediaGUI_set_currentItem(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");
    instance->currentItem = lua_isnoneornil(L, 2) ? nullptr : checkObject<TutorialItem>(L, 2, TutorialItemBinding::getMetatableName());
    return 0;
}

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

int TutorialpediaGUIBinding::tutorialSelectedEvent(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");

    MyGUI::ListBox* sender = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::ListBox>(L, 2, ListBoxBinding::getMetatableName());
    size_t index = (size_t)luaL_checkinteger(L, 3);
    instance->tutorialSelectedEvent(sender, index);
    return 0;
}

int TutorialpediaGUIBinding::tutorialPrevEvent(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");

    MyGUI::Widget* sender = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->tutorialPrevEvent(sender);
    return 0;
}

int TutorialpediaGUIBinding::tutorialNextEvent(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");

    MyGUI::Widget* sender = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->tutorialNextEvent(sender);
    return 0;
}

int TutorialpediaGUIBinding::tutorialActivateButtonEvent(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");

    MyGUI::Widget* sender = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->tutorialActivateButtonEvent(sender);
    return 0;
}

int TutorialpediaGUIBinding::tutorialWindowButton(lua_State* L)
{
    TutorialpediaGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialpediaGUI is nil");

    MyGUI::Window* sender = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Window>(L, 2, WindowBinding::getMetatableName());
    std::string name = luaL_checkstring(L, 3);
    instance->tutorialWindowButton(sender, name);
    return 0;
}


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
        { "setup", TutorialpediaGUIBinding::setup },
        { "updateCurrentItem", TutorialpediaGUIBinding::updateCurrentItem },
        { "tutorialSelectedEvent", TutorialpediaGUIBinding::tutorialSelectedEvent },
        { "tutorialPrevEvent", TutorialpediaGUIBinding::tutorialPrevEvent },
        { "tutorialNextEvent", TutorialpediaGUIBinding::tutorialNextEvent },
        { "tutorialActivateButtonEvent", TutorialpediaGUIBinding::tutorialActivateButtonEvent },
        { "tutorialWindowButton", TutorialpediaGUIBinding::tutorialWindowButton },
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
    registerGetter(L, "currentItem", TutorialpediaGUI_get_currentItem);
    registerGetter(L, "currentItemIndex", TutorialpediaGUI_get_currentItemIndex);
    registerGetter(L, "tutorialsList", TutorialpediaGUI_get_tutorialsList);
    registerGetter(L, "descriptionText", TutorialpediaGUI_get_descriptionText);
    registerGetter(L, "activateButton", TutorialpediaGUI_get_activateButton);
    registerGetter(L, "prevButton", TutorialpediaGUI_get_prevButton);
    registerGetter(L, "nextButton", TutorialpediaGUI_get_nextButton);
    registerGetter(L, "pagingText", TutorialpediaGUI_get_pagingText);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "currentItem", TutorialpediaGUI_set_currentItem);
    registerSetter(L, "currentItemIndex", TutorialpediaGUI_set_currentItemIndex);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to GUIWindow
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, TutorialpediaGUIBinding::getMetatableName(), GUIWindowBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua