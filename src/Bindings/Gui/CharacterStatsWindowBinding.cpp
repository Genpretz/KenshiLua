#include "pch.h"
#include "Bindings/CharacterStatsWindowBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/CharacterStatsWindow.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static CharacterStatsWindow* getS(lua_State* L, int idx)
{
    return checkObject<CharacterStatsWindow>(L, idx, CharacterStatsWindowBinding::getMetatableName());
}

int CharacterStatsWindowBinding::gc(lua_State* L) { return noopGc(L); }

int CharacterStatsWindowBinding::tostring(lua_State* L)
{
    CharacterStatsWindow* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int CharacterStatsWindowBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, CharacterStatsWindowBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    CharacterStatsWindow* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    if (strcmp(key, "character") == 0) { return pushObject<Character>(L, s->character, CharacterBinding::getMetatableName()); }
    if (strcmp(key, "statsSum") == 0) { lua_pushinteger(L, s->statsSum); return 1; }
    // TODO StatsEnumerated statProgress; unsupported __index type from header line 93
    if (strcmp(key, "currentStatIdDescription") == 0) { lua_pushstring(L, s->currentStatIdDescription.c_str()); return 1; }
    // TODO DatapanelGUI* attributesDatapanel; unsupported __index type from header line 95
    // TODO DatapanelGUI* skills1Datapanel; unsupported __index type from header line 96
    // TODO DatapanelGUI* skills2Datapanel; unsupported __index type from header line 97
    // TODO DatapanelGUI* skills3Datapanel; unsupported __index type from header line 98
    // TODO DatapanelGUI* skills4Datapanel; unsupported __index type from header line 99
    // TODO DatapanelGUI* statsDatapanel; unsupported __index type from header line 100
    // TODO DatapanelGUI* description1Datapanel; unsupported __index type from header line 101
    // TODO DatapanelGUI* description2Datapanel; unsupported __index type from header line 102
    if (strcmp(key, "autoUpdateMode") == 0) { lua_pushboolean(L, s->autoUpdateMode ? 1 : 0); return 1; }

    lua_pushnil(L);
    return 1;
}

int CharacterStatsWindowBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    CharacterStatsWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterStatsWindow is nil");

    // TODO Character* character; unsupported __newindex type from header line 91
    if (strcmp(key, "statsSum") == 0) { s->statsSum = (int)luaL_checkinteger(L, 3); return 0; }
    // TODO StatsEnumerated statProgress; unsupported __newindex type from header line 93
    if (strcmp(key, "currentStatIdDescription") == 0) { s->currentStatIdDescription = luaL_checkstring(L, 3); return 0; }
    // TODO DatapanelGUI* attributesDatapanel; unsupported __newindex type from header line 95
    // TODO DatapanelGUI* skills1Datapanel; unsupported __newindex type from header line 96
    // TODO DatapanelGUI* skills2Datapanel; unsupported __newindex type from header line 97
    // TODO DatapanelGUI* skills3Datapanel; unsupported __newindex type from header line 98
    // TODO DatapanelGUI* skills4Datapanel; unsupported __newindex type from header line 99
    // TODO DatapanelGUI* statsDatapanel; unsupported __newindex type from header line 100
    // TODO DatapanelGUI* description1Datapanel; unsupported __newindex type from header line 101
    // TODO DatapanelGUI* description2Datapanel; unsupported __newindex type from header line 102
    if (strcmp(key, "autoUpdateMode") == 0) { s->autoUpdateMode = lua_toboolean(L, 3) != 0; return 0; }

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int CharacterStatsWindowBinding::_DESTRUCTOR(lua_State* L)
{
    CharacterStatsWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterStatsWindow is nil");

    s->_DESTRUCTOR();
    return 0;
}

int CharacterStatsWindowBinding::clear(lua_State* L)
{
    CharacterStatsWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterStatsWindow is nil");

    s->clear();
    return 0;
}

int CharacterStatsWindowBinding::_NV_clear(lua_State* L)
{
    CharacterStatsWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterStatsWindow is nil");

    s->_NV_clear();
    return 0;
}

int CharacterStatsWindowBinding::create(lua_State* L)
{
    CharacterStatsWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterStatsWindow is nil");

    s->create();
    return 0;
}

int CharacterStatsWindowBinding::_NV_create(lua_State* L)
{
    CharacterStatsWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterStatsWindow is nil");

    s->_NV_create();
    return 0;
}

int CharacterStatsWindowBinding::update(lua_State* L)
{
    CharacterStatsWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterStatsWindow is nil");

    s->update();
    return 0;
}

int CharacterStatsWindowBinding::_NV_update(lua_State* L)
{
    CharacterStatsWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterStatsWindow is nil");

    s->_NV_update();
    return 0;
}

int CharacterStatsWindowBinding::show(lua_State* L)
{
    CharacterStatsWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterStatsWindow is nil");

    bool on = lua_toboolean(L, 2) != 0;
    s->show(on);
    return 0;
}

int CharacterStatsWindowBinding::_NV_show(lua_State* L)
{
    CharacterStatsWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterStatsWindow is nil");

    bool on = lua_toboolean(L, 2) != 0;
    s->_NV_show(on);
    return 0;
}

int CharacterStatsWindowBinding::isVisible(lua_State* L)
{
    CharacterStatsWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterStatsWindow is nil");

    bool result = s->isVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterStatsWindowBinding::_NV_isVisible(lua_State* L)
{
    CharacterStatsWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterStatsWindow is nil");

    bool result = s->_NV_isVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterStatsWindowBinding::setAutoUpdateMode(lua_State* L)
{
    CharacterStatsWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterStatsWindow is nil");

    bool on = lua_toboolean(L, 2) != 0;
    s->setAutoUpdateMode(on);
    return 0;
}

int CharacterStatsWindowBinding::setupStats(lua_State* L)
{
    CharacterStatsWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterStatsWindow is nil");

    s->setupStats();
    return 0;
}

int CharacterStatsWindowBinding::updateStats(lua_State* L)
{
    CharacterStatsWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterStatsWindow is nil");

    s->updateStats();
    return 0;
}

int CharacterStatsWindowBinding::clearDesctiption(lua_State* L)
{
    CharacterStatsWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterStatsWindow is nil");

    s->clearDesctiption();
    return 0;
}

int CharacterStatsWindowBinding::sumStats(lua_State* L)
{
    CharacterStatsWindow* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharacterStatsWindow is nil");

    int result = s->sumStats();
    lua_pushinteger(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 68: CharacterStatsWindow* _CONSTRUCTOR(...) - unsupported return type
  line 81: void autoChangeSelectedObject(...) - unsupported arg type
  line 82: void _NV_autoChangeSelectedObject(...) - unsupported arg type
  line 88: void closeWindow(...) - pointer arg
  line 89: void statMouseOver(...) - pointer arg
  line 90: DatapanelGUI* getStatsPanel(...) - unsupported return type
  line 104: void addStat(...) - static method
  line 105: CharacterStatsWindow::Stat* getStat(...) - static method
  line 106: CharacterStatsWindow::Stat* getStatById(...) - static method
  line 107: void BuildStats(...) - static method
*/

void CharacterStatsWindowBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CharacterStatsWindowBinding::gc },
        { "__tostring", CharacterStatsWindowBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", CharacterStatsWindowBinding::_DESTRUCTOR },
        { "clear", CharacterStatsWindowBinding::clear },
        { "_NV_clear", CharacterStatsWindowBinding::_NV_clear },
        { "create", CharacterStatsWindowBinding::create },
        { "_NV_create", CharacterStatsWindowBinding::_NV_create },
        { "update", CharacterStatsWindowBinding::update },
        { "_NV_update", CharacterStatsWindowBinding::_NV_update },
        { "show", CharacterStatsWindowBinding::show },
        { "_NV_show", CharacterStatsWindowBinding::_NV_show },
        { "isVisible", CharacterStatsWindowBinding::isVisible },
        { "_NV_isVisible", CharacterStatsWindowBinding::_NV_isVisible },
        { "setAutoUpdateMode", CharacterStatsWindowBinding::setAutoUpdateMode },
        { "setupStats", CharacterStatsWindowBinding::setupStats },
        { "updateStats", CharacterStatsWindowBinding::updateStats },
        { "clearDesctiption", CharacterStatsWindowBinding::clearDesctiption },
        { "sumStats", CharacterStatsWindowBinding::sumStats },
        { 0, 0 }
    };
    registerClass(L, CharacterStatsWindowBinding::getMetatableName(), meta, methods, CharacterStatsWindowBinding::index, CharacterStatsWindowBinding::newindex);
}

} // namespace KenshiLua