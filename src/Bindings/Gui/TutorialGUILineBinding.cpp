#include "pch.h"
#include <kenshi/gui/TutorialGUI.h>
#include "TutorialGUILineBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
    typedef TutorialGUI::TutorialGUILine TutorialGUILine;

static TutorialGUILine* getInstance(lua_State* L, int idx)
{
    return checkObject<TutorialGUILine>(L, idx, TutorialGUILineBinding::getMetatableName());
}

// --- Getters for TutorialGUILine ---
static int TutorialGUILine_get_nameButton(lua_State* L)
{
    TutorialGUILine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUILine is nil");
    lua_pushlightuserdata(L, (void*)instance->nameButton);
    return 1;
}

static int TutorialGUILine_get_closeButton(lua_State* L)
{
    TutorialGUILine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUILine is nil");
    lua_pushlightuserdata(L, (void*)instance->closeButton);
    return 1;
}

static int TutorialGUILine_get_flashWidget(lua_State* L)
{
    TutorialGUILine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUILine is nil");
    lua_pushlightuserdata(L, (void*)instance->flashWidget);
    return 1;
}

// --- Setters for TutorialGUILine ---
int TutorialGUILineBinding::updateHighlight(lua_State* L)
{
    TutorialGUILine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUILine is nil");

    float time = (float)luaL_checknumber(L, 2);
    bool result = instance->updateHighlight(time);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TutorialGUILineBinding::_DESTRUCTOR(lua_State* L)
{
    TutorialGUILine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialGUILine is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 98: TutorialGUILine* _CONSTRUCTOR(...) - unsupported arg type
*/

int TutorialGUILineBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TutorialGUILineBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TutorialGUILine object");
    return 1;
}

void TutorialGUILineBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TutorialGUILineBinding::gc },
        { "__tostring", TutorialGUILineBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "updateHighlight", TutorialGUILineBinding::updateHighlight },
        { "_DESTRUCTOR", TutorialGUILineBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        TutorialGUILineBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TutorialGUILineBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, TutorialGUILine_get_nameButton);
    lua_setfield(L, -2, "nameButton");
    lua_pushcfunction(L, TutorialGUILine_get_closeButton);
    lua_setfield(L, -2, "closeButton");
    lua_pushcfunction(L, TutorialGUILine_get_flashWidget);
    lua_setfield(L, -2, "flashWidget");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseLayout
    // setMetatableParent(L, TutorialGUILineBinding::getMetatableName(), wraps::BaseLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua