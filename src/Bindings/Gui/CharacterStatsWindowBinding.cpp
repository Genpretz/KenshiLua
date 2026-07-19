#include "pch.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"

#include <kenshi/gui/CharacterStatsWindow.h>
#include "CharacterStatsWindowBinding.h"
#include "GUIWindowBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static CharacterStatsWindow* getInstance(lua_State* L, int idx)
{
    return checkObject<CharacterStatsWindow>(L, idx, CharacterStatsWindowBinding::getMetatableName());
}

// --- Getters for CharacterStatsWindow ---
static int CharacterStatsWindow_get_character(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");
    return pushObject<Character>(L, instance->character, CharacterBinding::getMetatableName());
}

static int CharacterStatsWindow_get_statsSum(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");
    lua_pushinteger(L, instance->statsSum);
    return 1;
}

static int CharacterStatsWindow_get_statProgress(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");
    lua_pushinteger(L, (lua_Integer)instance->statProgress);
    return 1;
}

static int CharacterStatsWindow_get_currentStatIdDescription(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");
    lua_pushstring(L, instance->currentStatIdDescription.c_str());
    return 1;
}

static int CharacterStatsWindow_get_attributesDatapanel(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");
    return pushObject<DatapanelGUI>(L, instance->attributesDatapanel, DatapanelGUIBinding::getMetatableName());
}

static int CharacterStatsWindow_get_skills1Datapanel(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");
    return pushObject<DatapanelGUI>(L, instance->skills1Datapanel, DatapanelGUIBinding::getMetatableName());
}

static int CharacterStatsWindow_get_skills2Datapanel(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");
    return pushObject<DatapanelGUI>(L, instance->skills2Datapanel, DatapanelGUIBinding::getMetatableName());
}

static int CharacterStatsWindow_get_skills3Datapanel(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");
    return pushObject<DatapanelGUI>(L, instance->skills3Datapanel, DatapanelGUIBinding::getMetatableName());
}

static int CharacterStatsWindow_get_skills4Datapanel(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");
    return pushObject<DatapanelGUI>(L, instance->skills4Datapanel, DatapanelGUIBinding::getMetatableName());
}

static int CharacterStatsWindow_get_statsDatapanel(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");
    return pushObject<DatapanelGUI>(L, instance->statsDatapanel, DatapanelGUIBinding::getMetatableName());
}

static int CharacterStatsWindow_get_description1Datapanel(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");
    return pushObject<DatapanelGUI>(L, instance->description1Datapanel, DatapanelGUIBinding::getMetatableName());
}

static int CharacterStatsWindow_get_description2Datapanel(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");
    return pushObject<DatapanelGUI>(L, instance->description2Datapanel, DatapanelGUIBinding::getMetatableName());
}

static int CharacterStatsWindow_get_autoUpdateMode(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");
    lua_pushboolean(L, instance->autoUpdateMode ? 1 : 0);
    return 1;
}

// --- Setters for CharacterStatsWindow ---
static int CharacterStatsWindow_set_statsSum(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");
    instance->statsSum = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CharacterStatsWindow_set_statProgress(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");
    instance->statProgress = (StatsEnumerated)luaL_checkinteger(L, 2);
    return 0;
}

static int CharacterStatsWindow_set_currentStatIdDescription(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");
    instance->currentStatIdDescription = luaL_checkstring(L, 2);
    return 0;
}

static int CharacterStatsWindow_set_autoUpdateMode(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");
    instance->autoUpdateMode = lua_toboolean(L, 2) != 0;
    return 0;
}

int CharacterStatsWindowBinding::_DESTRUCTOR(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int CharacterStatsWindowBinding::clear(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");

    instance->clear();
    return 0;
}

int CharacterStatsWindowBinding::_NV_clear(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");

    instance->_NV_clear();
    return 0;
}

int CharacterStatsWindowBinding::create(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");

    instance->create();
    return 0;
}

int CharacterStatsWindowBinding::_NV_create(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");

    instance->_NV_create();
    return 0;
}

int CharacterStatsWindowBinding::update(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");

    instance->update();
    return 0;
}

int CharacterStatsWindowBinding::_NV_update(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");

    instance->_NV_update();
    return 0;
}

int CharacterStatsWindowBinding::show(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->show(on);
    return 0;
}

int CharacterStatsWindowBinding::_NV_show(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_show(on);
    return 0;
}

int CharacterStatsWindowBinding::isVisible(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");

    bool result = instance->isVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterStatsWindowBinding::_NV_isVisible(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");

    bool result = instance->_NV_isVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterStatsWindowBinding::setAutoUpdateMode(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setAutoUpdateMode(on);
    return 0;
}

int CharacterStatsWindowBinding::setupStats(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");

    instance->setupStats();
    return 0;
}

int CharacterStatsWindowBinding::updateStats(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");

    instance->updateStats();
    return 0;
}

int CharacterStatsWindowBinding::clearDesctiption(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");

    instance->clearDesctiption();
    return 0;
}

int CharacterStatsWindowBinding::sumStats(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");

    int result = instance->sumStats();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterStatsWindowBinding::getStatsPanel(lua_State* L)
{
    CharacterStatsWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterStatsWindow is nil");

    CharacterStatsWindow::StatGroup::Group group = (CharacterStatsWindow::StatGroup::Group)luaL_checkinteger(L, 2);
    DatapanelGUI* result = instance->getStatsPanel(group);
    return pushObject<DatapanelGUI>(L, result, DatapanelGUIBinding::getMetatableName());
}

/*
Skipped methods needing manual binding:
  line 68: CharacterStatsWindow* _CONSTRUCTOR(...) - unsupported arg type
  line 81: void autoChangeSelectedObject(...) - unsupported arg type
  line 82: void _NV_autoChangeSelectedObject(...) - unsupported arg type
  line 88: void closeWindow(...) - unsupported arg type
  line 89: void statMouseOver(...) - unsupported arg type
  line 104: void addStat(...) - static method
  line 105: CharacterStatsWindow::Stat* getStat(...) - static method
  line 106: CharacterStatsWindow::Stat* getStatById(...) - static method
  line 107: void BuildStats(...) - static method
*/

int CharacterStatsWindowBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int CharacterStatsWindowBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CharacterStatsWindow object");
    return 1;
}

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
        { "getStatsPanel", CharacterStatsWindowBinding::getStatsPanel },
        { 0, 0 }
    };

    registerClass(
        L, 
        CharacterStatsWindowBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CharacterStatsWindowBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, CharacterStatsWindow_get_character);
    lua_setfield(L, -2, "character");
    lua_pushcfunction(L, CharacterStatsWindow_get_statsSum);
    lua_setfield(L, -2, "statsSum");
    lua_pushcfunction(L, CharacterStatsWindow_get_statProgress);
    lua_setfield(L, -2, "statProgress");
    lua_pushcfunction(L, CharacterStatsWindow_get_currentStatIdDescription);
    lua_setfield(L, -2, "currentStatIdDescription");
    lua_pushcfunction(L, CharacterStatsWindow_get_attributesDatapanel);
    lua_setfield(L, -2, "attributesDatapanel");
    lua_pushcfunction(L, CharacterStatsWindow_get_skills1Datapanel);
    lua_setfield(L, -2, "skills1Datapanel");
    lua_pushcfunction(L, CharacterStatsWindow_get_skills2Datapanel);
    lua_setfield(L, -2, "skills2Datapanel");
    lua_pushcfunction(L, CharacterStatsWindow_get_skills3Datapanel);
    lua_setfield(L, -2, "skills3Datapanel");
    lua_pushcfunction(L, CharacterStatsWindow_get_skills4Datapanel);
    lua_setfield(L, -2, "skills4Datapanel");
    lua_pushcfunction(L, CharacterStatsWindow_get_statsDatapanel);
    lua_setfield(L, -2, "statsDatapanel");
    lua_pushcfunction(L, CharacterStatsWindow_get_description1Datapanel);
    lua_setfield(L, -2, "description1Datapanel");
    lua_pushcfunction(L, CharacterStatsWindow_get_description2Datapanel);
    lua_setfield(L, -2, "description2Datapanel");
    lua_pushcfunction(L, CharacterStatsWindow_get_autoUpdateMode);
    lua_setfield(L, -2, "autoUpdateMode");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, CharacterStatsWindow_set_statsSum);
    lua_setfield(L, -2, "statsSum");
    lua_pushcfunction(L, CharacterStatsWindow_set_statProgress);
    lua_setfield(L, -2, "statProgress");
    lua_pushcfunction(L, CharacterStatsWindow_set_currentStatIdDescription);
    lua_setfield(L, -2, "currentStatIdDescription");
    lua_pushcfunction(L, CharacterStatsWindow_set_autoUpdateMode);
    lua_setfield(L, -2, "autoUpdateMode");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to GUIWindow
    // setMetatableParent(L, CharacterStatsWindowBinding::getMetatableName(), GUIWindowBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
