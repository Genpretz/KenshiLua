#include "pch.h"
#include <kenshi/gui/CharacterTradingWindow.h>
#include "CharacterTradingWindowBinding.h"
#include "GUIWindowBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static CharacterTradingWindow* getInstance(lua_State* L, int idx)
{
    return checkObject<CharacterTradingWindow>(L, idx, CharacterTradingWindowBinding::getMetatableName());
}

// --- Getters for CharacterTradingWindow ---
static int CharacterTradingWindow_get_tradingHandler(lua_State* L)
{
    CharacterTradingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterTradingWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->tradingHandler);
    return 1;
}

static int CharacterTradingWindow_get_charactersBox(lua_State* L)
{
    CharacterTradingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterTradingWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->charactersBox);
    return 1;
}

static int CharacterTradingWindow_get_confirmBtn(lua_State* L)
{
    CharacterTradingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterTradingWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->confirmBtn);
    return 1;
}

static int CharacterTradingWindow_get_currentTotalText(lua_State* L)
{
    CharacterTradingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterTradingWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->currentTotalText);
    return 1;
}

static int CharacterTradingWindow_get_selectedCountText(lua_State* L)
{
    CharacterTradingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterTradingWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->selectedCountText);
    return 1;
}

// --- Setters for CharacterTradingWindow ---
int CharacterTradingWindowBinding::_DESTRUCTOR(lua_State* L)
{
    CharacterTradingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterTradingWindow is nil");

    instance->~CharacterTradingWindow();
    return 0;
}

int CharacterTradingWindowBinding::show(lua_State* L)
{
    CharacterTradingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterTradingWindow is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->show(on);
    return 0;
}

int CharacterTradingWindowBinding::_NV_show(lua_State* L)
{
    CharacterTradingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterTradingWindow is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->show(on);
    return 0;
}

int CharacterTradingWindowBinding::isVisible(lua_State* L)
{
    CharacterTradingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterTradingWindow is nil");

    bool result = instance->isVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterTradingWindowBinding::_NV_isVisible(lua_State* L)
{
    CharacterTradingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterTradingWindow is nil");

    bool result = instance->isVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterTradingWindowBinding::update(lua_State* L)
{
    CharacterTradingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterTradingWindow is nil");

    instance->update();
    return 0;
}

int CharacterTradingWindowBinding::_NV_update(lua_State* L)
{
    CharacterTradingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterTradingWindow is nil");

    instance->update();
    return 0;
}

int CharacterTradingWindowBinding::close(lua_State* L)
{
    CharacterTradingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterTradingWindow is nil");

    instance->close();
    return 0;
}

int CharacterTradingWindowBinding::_NV_close(lua_State* L)
{
    CharacterTradingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterTradingWindow is nil");

    instance->close();
    return 0;
}

int CharacterTradingWindowBinding::updateSelected(lua_State* L)
{
    // Private and non-exported in SDK
    return 0;
}

/*
Skipped methods needing manual binding:
  line 16: CharacterTradingWindow* _CONSTRUCTOR(...) - unsupported arg type
  line 29: void confirmButton(...) - unsupported arg type
  line 30: void cancelButton(...) - unsupported arg type
  line 31: void notifyMouseWheel(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 33: tradingBoxes (Ogre::FastArray<CharacterTradingBox*>) - unsupported type
*/

int CharacterTradingWindowBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int CharacterTradingWindowBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CharacterTradingWindow object");
    return 1;
}

void CharacterTradingWindowBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CharacterTradingWindowBinding::gc },
        { "__tostring", CharacterTradingWindowBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", CharacterTradingWindowBinding::_DESTRUCTOR },
        { "show", CharacterTradingWindowBinding::show },
        // { "_NV_show", CharacterTradingWindowBinding::_NV_show },
        { "isVisible", CharacterTradingWindowBinding::isVisible },
        // { "_NV_isVisible", CharacterTradingWindowBinding::_NV_isVisible },
        { "update", CharacterTradingWindowBinding::update },
        // { "_NV_update", CharacterTradingWindowBinding::_NV_update },
        { "close", CharacterTradingWindowBinding::close },
        // { "_NV_close", CharacterTradingWindowBinding::_NV_close },
        // { "updateSelected", CharacterTradingWindowBinding::updateSelected },
        { 0, 0 }
    };

    registerClass(
        L, 
        CharacterTradingWindowBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CharacterTradingWindowBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, CharacterTradingWindow_get_tradingHandler);
    lua_setfield(L, -2, "tradingHandler");
    lua_pushcfunction(L, CharacterTradingWindow_get_charactersBox);
    lua_setfield(L, -2, "charactersBox");
    lua_pushcfunction(L, CharacterTradingWindow_get_confirmBtn);
    lua_setfield(L, -2, "confirmBtn");
    lua_pushcfunction(L, CharacterTradingWindow_get_currentTotalText);
    lua_setfield(L, -2, "currentTotalText");
    lua_pushcfunction(L, CharacterTradingWindow_get_selectedCountText);
    lua_setfield(L, -2, "selectedCountText");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to GUIWindow
    setMetatableParent(L, CharacterTradingWindowBinding::getMetatableName(), GUIWindowBinding::getMetatableName());

        // Wire up inheritance
    setMetatableParent(L, CharacterTradingWindowBinding::getMetatableName(), GUIWindowBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua