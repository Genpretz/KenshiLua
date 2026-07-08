#include "pch.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"

#include <kenshi/gui/FactionsScreen.h>
#include "FactionsScreenBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static FactionsScreen* getInstance(lua_State* L, int idx)
{
    return checkObject<FactionsScreen>(L, idx, FactionsScreenBinding::getMetatableName());
}

// --- Getters for FactionsScreen ---
static int FactionsScreen_get_mainWidget(lua_State* L)
{
    FactionsScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionsScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->mainWidget);
    return 1;
}

static int FactionsScreen_get_selectedFaction(lua_State* L)
{
    FactionsScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionsScreen is nil");
    return pushObject<Faction>(L, instance->selectedFaction, FactionBinding::getMetatableName());
}

static int FactionsScreen_get_scrollList(lua_State* L)
{
    FactionsScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionsScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->scrollList);
    return 1;
}

static int FactionsScreen_get_scrollListItemTop(lua_State* L)
{
    FactionsScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionsScreen is nil");
    lua_pushinteger(L, instance->scrollListItemTop);
    return 1;
}

static int FactionsScreen_get_scrollListItemWidth(lua_State* L)
{
    FactionsScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionsScreen is nil");
    lua_pushinteger(L, instance->scrollListItemWidth);
    return 1;
}

static int FactionsScreen_get_nameText(lua_State* L)
{
    FactionsScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionsScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->nameText);
    return 1;
}

static int FactionsScreen_get_infoPanel(lua_State* L)
{
    FactionsScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionsScreen is nil");
    return pushObject<DatapanelGUI>(L, instance->infoPanel, DatapanelGUIBinding::getMetatableName());
}

static int FactionsScreen_get_updateTimer(lua_State* L)
{
    FactionsScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionsScreen is nil");
    lua_pushnumber(L, instance->updateTimer);
    return 1;
}

// --- Setters for FactionsScreen ---
static int FactionsScreen_set_scrollListItemTop(lua_State* L)
{
    FactionsScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionsScreen is nil");
    instance->scrollListItemTop = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int FactionsScreen_set_scrollListItemWidth(lua_State* L)
{
    FactionsScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionsScreen is nil");
    instance->scrollListItemWidth = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int FactionsScreen_set_updateTimer(lua_State* L)
{
    FactionsScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionsScreen is nil");
    instance->updateTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

int FactionsScreenBinding::_DESTRUCTOR(lua_State* L)
{
    FactionsScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionsScreen is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int FactionsScreenBinding::getVisible(lua_State* L)
{
    FactionsScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionsScreen is nil");

    bool result = instance->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionsScreenBinding::clear(lua_State* L)
{
    FactionsScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionsScreen is nil");

    instance->clear();
    return 0;
}

int FactionsScreenBinding::update(lua_State* L)
{
    FactionsScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionsScreen is nil");

    instance->update();
    return 0;
}

int FactionsScreenBinding::refresh(lua_State* L)
{
    FactionsScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionsScreen is nil");

    instance->refresh();
    return 0;
}

int FactionsScreenBinding::updateInfo(lua_State* L)
{
    FactionsScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionsScreen is nil");

    instance->updateInfo();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 40: FactionsScreen* _CONSTRUCTOR(...) - unsupported arg type
  line 48: void notifyEditTextChange(...) - unsupported arg type
  line 49: void setFocus(...) - unsupported arg type
  line 50: void loseFocus(...) - unsupported arg type
  line 51: void factionLineSelected(...) - unsupported arg type
  line 52: void notifyMouseWheel(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 55: lines (std::map<Faction*, FactionsScreen::FactionRelationsLine*, std::less<Faction*>, Ogre::STLAllocator<std::pair<Faction*const, FactionsScreen::FactionRelationsLine*>, Ogre::GeneralAllocPolicy > >) - unsupported type
*/

int FactionsScreenBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int FactionsScreenBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FactionsScreen object");
    return 1;
}

void FactionsScreenBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FactionsScreenBinding::gc },
        { "__tostring", FactionsScreenBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", FactionsScreenBinding::_DESTRUCTOR },
        { "getVisible", FactionsScreenBinding::getVisible },
        { "clear", FactionsScreenBinding::clear },
        { "update", FactionsScreenBinding::update },
        { "refresh", FactionsScreenBinding::refresh },
        { "updateInfo", FactionsScreenBinding::updateInfo },
        { 0, 0 }
    };

    registerClass(
        L, 
        FactionsScreenBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FactionsScreenBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, FactionsScreen_get_mainWidget);
    lua_setfield(L, -2, "mainWidget");
    lua_pushcfunction(L, FactionsScreen_get_selectedFaction);
    lua_setfield(L, -2, "selectedFaction");
    lua_pushcfunction(L, FactionsScreen_get_scrollList);
    lua_setfield(L, -2, "scrollList");
    lua_pushcfunction(L, FactionsScreen_get_scrollListItemTop);
    lua_setfield(L, -2, "scrollListItemTop");
    lua_pushcfunction(L, FactionsScreen_get_scrollListItemWidth);
    lua_setfield(L, -2, "scrollListItemWidth");
    lua_pushcfunction(L, FactionsScreen_get_nameText);
    lua_setfield(L, -2, "nameText");
    lua_pushcfunction(L, FactionsScreen_get_infoPanel);
    lua_setfield(L, -2, "infoPanel");
    lua_pushcfunction(L, FactionsScreen_get_updateTimer);
    lua_setfield(L, -2, "updateTimer");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, FactionsScreen_set_scrollListItemTop);
    lua_setfield(L, -2, "scrollListItemTop");
    lua_pushcfunction(L, FactionsScreen_set_scrollListItemWidth);
    lua_setfield(L, -2, "scrollListItemWidth");
    lua_pushcfunction(L, FactionsScreen_set_updateTimer);
    lua_setfield(L, -2, "updateTimer");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua