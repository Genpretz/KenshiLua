#include "pch.h"
#include "Bindings/TitleScreenBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Titlescreen.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static TitleScreen* getS(lua_State* L, int idx)
{
    return checkObject<TitleScreen>(L, idx, TitleScreenBinding::getMetatableName());
}

int TitleScreenBinding::gc(lua_State* L) { return noopGc(L); }

int TitleScreenBinding::tostring(lua_State* L)
{
    TitleScreen* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int TitleScreenBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, TitleScreenBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    TitleScreen* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    // TODO NewGameWindow* newGameWindow; unsupported __index type from header line 41
    if (strcmp(key, "creditsPanel") == 0) { lua_pushinteger(L, (lua_Integer)s->creditsPanel); return 1; }
    if (strcmp(key, "creditsText") == 0) { lua_pushinteger(L, (lua_Integer)s->creditsText); return 1; }
    if (strcmp(key, "creditsLoaded") == 0) { lua_pushboolean(L, s->creditsLoaded ? 1 : 0); return 1; }
    if (strcmp(key, "creditsPosition") == 0) { lua_pushnumber(L, s->creditsPosition); return 1; }

    lua_pushnil(L);
    return 1;
}

int TitleScreenBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    TitleScreen* s = getS(L, 1);
    if (!s) return luaL_error(L, "TitleScreen is nil");

    // TODO NewGameWindow* newGameWindow; unsupported __newindex type from header line 41
    // TODO MyGUI::Widget* creditsPanel; unsupported __newindex type from header line 42
    // TODO MyGUI::TextBox* creditsText; unsupported __newindex type from header line 43
    if (strcmp(key, "creditsLoaded") == 0) { s->creditsLoaded = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "creditsPosition") == 0) { s->creditsPosition = (float)luaL_checknumber(L, 3); return 0; }

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int TitleScreenBinding::_DESTRUCTOR(lua_State* L)
{
    TitleScreen* s = getS(L, 1);
    if (!s) return luaL_error(L, "TitleScreen is nil");

    s->_DESTRUCTOR();
    return 0;
}

int TitleScreenBinding::clear(lua_State* L)
{
    TitleScreen* s = getS(L, 1);
    if (!s) return luaL_error(L, "TitleScreen is nil");

    s->clear();
    return 0;
}

int TitleScreenBinding::_NV_clear(lua_State* L)
{
    TitleScreen* s = getS(L, 1);
    if (!s) return luaL_error(L, "TitleScreen is nil");

    s->_NV_clear();
    return 0;
}

int TitleScreenBinding::show(lua_State* L)
{
    TitleScreen* s = getS(L, 1);
    if (!s) return luaL_error(L, "TitleScreen is nil");

    bool on = lua_toboolean(L, 2) != 0;
    s->show(on);
    return 0;
}

int TitleScreenBinding::_NV_show(lua_State* L)
{
    TitleScreen* s = getS(L, 1);
    if (!s) return luaL_error(L, "TitleScreen is nil");

    bool on = lua_toboolean(L, 2) != 0;
    s->_NV_show(on);
    return 0;
}

int TitleScreenBinding::update(lua_State* L)
{
    TitleScreen* s = getS(L, 1);
    if (!s) return luaL_error(L, "TitleScreen is nil");

    s->update();
    return 0;
}

int TitleScreenBinding::_NV_update(lua_State* L)
{
    TitleScreen* s = getS(L, 1);
    if (!s) return luaL_error(L, "TitleScreen is nil");

    s->_NV_update();
    return 0;
}

int TitleScreenBinding::closeTheOtherBits(lua_State* L)
{
    TitleScreen* s = getS(L, 1);
    if (!s) return luaL_error(L, "TitleScreen is nil");

    bool result = s->closeTheOtherBits();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TitleScreenBinding::setCreditsVisible(lua_State* L)
{
    TitleScreen* s = getS(L, 1);
    if (!s) return luaL_error(L, "TitleScreen is nil");

    bool value = lua_toboolean(L, 2) != 0;
    s->setCreditsVisible(value);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 19: TitleScreen* getSingleton(...) - static method
  line 22: TitleScreen* _CONSTRUCTOR(...) - unsupported return type
  line 32: void loadGame(...) - pointer arg
  line 33: void importGame(...) - pointer arg
  line 34: void showOptions(...) - pointer arg
  line 35: void credits(...) - pointer arg
  line 36: void exitGame(...) - pointer arg
  line 38: void continueGame(...) - pointer arg
  line 39: void hover(...) - pointer arg
*/

void TitleScreenBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TitleScreenBinding::gc },
        { "__tostring", TitleScreenBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
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
    registerClass(L, TitleScreenBinding::getMetatableName(), meta, methods, TitleScreenBinding::index, TitleScreenBinding::newindex);
}

} // namespace KenshiLua