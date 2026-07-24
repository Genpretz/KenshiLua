#include "pch.h"
#include "kenshi\gui\SquadManagementScreen.h"
#include "SquadManagementScreenBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/MyGuiBinding.h"
#include "Bindings/Gui/SquadDataBinding.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/Gui/ManagementScreenBinding.h"

namespace KenshiLua
{

static SquadManagementScreen* getInstance(lua_State* L, int idx)
{
    return checkObject<SquadManagementScreen>(L, idx, SquadManagementScreenBinding::getMetatableName());
}

// --- Getters for SquadManagementScreen ---
static int SquadManagementScreen_get_mainWidget(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->mainWidget);
    return 1;
}

static int SquadManagementScreen_get_btnAddSquad(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->btnAddSquad);
    return 1;
}

static int SquadManagementScreen_get_txtFactionSize(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->txtFactionSize);
    return 1;
}

static int SquadManagementScreen_get_factionSize(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");
    lua_pushinteger(L, instance->factionSize);
    return 1;
}

static int SquadManagementScreen_get_panelSquads(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->panelSquads);
    return 1;
}

static int SquadManagementScreen_get_panelDismiss(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->panelDismiss);
    return 1;
}

static int SquadManagementScreen_get_dismissChar(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");
    return pushObject<Character>(L, instance->dismissChar, CharacterBinding::getMetatableName());
}

static int SquadManagementScreen_get_faction(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");
    return pushObject<Faction>(L, instance->faction, FactionBinding::getMetatableName());
}

// --- Setters for SquadManagementScreen ---
static int SquadManagementScreen_set_factionSize(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");
    instance->factionSize = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int SquadManagementScreen_set_dismissChar(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");
    instance->dismissChar = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int SquadManagementScreen_set_faction(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");
    instance->faction = lua_isnoneornil(L, 2) ? nullptr : checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

int SquadManagementScreenBinding::_CONSTRUCTOR(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");

    ManagementScreen* screen = checkObject<ManagementScreen>(L, 2, ManagementScreenBinding::getMetatableName());
    SquadManagementScreen* result = instance->_CONSTRUCTOR(screen);
    return pushObject<SquadManagementScreen>(L, result, SquadManagementScreenBinding::getMetatableName());
}

int SquadManagementScreenBinding::_DESTRUCTOR(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int SquadManagementScreenBinding::getVisible(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");

    bool result = instance->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SquadManagementScreenBinding::update(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");

    instance->update();
    return 0;
}

int SquadManagementScreenBinding::reset(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");

    instance->reset();
    return 0;
}

int SquadManagementScreenBinding::refreshSquads(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");

    instance->refreshSquads();
    return 0;
}

int SquadManagementScreenBinding::notifyEndDropSquad(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");

    wraps::BaseLayout* _sender = nullptr;
    if (lua_isuserdata(L, 2)) {
        void* raw = lua_touserdata(L, 2);
        _sender = (wraps::BaseLayout*)(raw ? *(void**)raw : nullptr);
    } else if (lua_islightuserdata(L, 2)) {
        _sender = (wraps::BaseLayout*)lua_touserdata(L, 2);
    }
    MyGUI::DDItemInfo myGuiInfo;
    wraps::DDItemInfo _info(myGuiInfo);
    bool _result = lua_toboolean(L, 4) != 0;
    instance->notifyEndDropSquad(_sender, _info, _result);
    return 0;
}

int SquadManagementScreenBinding::notifyEndDropPortrait(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");

    wraps::BaseLayout* _sender = nullptr;
    if (lua_isuserdata(L, 2)) {
        void* raw = lua_touserdata(L, 2);
        _sender = (wraps::BaseLayout*)(raw ? *(void**)raw : nullptr);
    } else if (lua_islightuserdata(L, 2)) {
        _sender = (wraps::BaseLayout*)lua_touserdata(L, 2);
    }
    MyGUI::DDItemInfo myGuiInfo;
    wraps::DDItemInfo _info(myGuiInfo);
    bool _result = lua_toboolean(L, 4) != 0;
    instance->notifyEndDropPortrait(_sender, _info, _result);
    return 0;
}

int SquadManagementScreenBinding::removeSquad(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");

    SquadManagementScreen::SquadData* squad = checkObject<SquadManagementScreen::SquadData>(L, 2, SquadDataBinding::getMetatableName());
    instance->removeSquad(squad);
    return 0;
}

int SquadManagementScreenBinding::getSquad(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");

    ActivePlatoon* platoon = checkObject<ActivePlatoon>(L, 2, ActivePlatoonBinding::getMetatableName());
    SquadManagementScreen::SquadData* result = instance->getSquad(platoon);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int SquadManagementScreenBinding::dismissCharacter(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");

    int result = (int)luaL_checkinteger(L, 2);
    instance->dismissCharacter(result);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 161: void notifyStartDropSquad(...) - non-string reference arg
  line 162: void notifyRequestDropSquad(...) - non-string reference arg
  line 164: void notifyStartDropPortrait(...) - non-string reference arg
  line 165: void notifyRequestDropPortrait(...) - non-string reference arg
  line 167: void onAddSquad(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - SquadManagementScreen_get_mainWidget: MyGUI::Widget* (unbound pointer)
  - SquadManagementScreen_get_btnAddSquad: MyGUI::Button* (unbound pointer)
  - SquadManagementScreen_get_txtFactionSize: MyGUI::TextBox* (unbound pointer)
  - SquadManagementScreen_get_panelSquads: SquadManagementScreen::SquadItemBox* (unbound pointer)
  - SquadManagementScreen_get_panelDismiss: SquadManagementScreen::PortraitSquadItemBox* (unbound pointer)
  - SquadManagementScreenBinding::getSquad: SquadManagementScreen::SquadData* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 94: SquadData (class) - unsupported type
  line 95: SquadCellView (class) - unsupported type
  line 179: squads (std::map<ActivePlatoon*, SquadManagementScreen::SquadData*, std::less<ActivePlatoon*>, Ogre::STLAllocator<std::pair<ActivePlatoon*const, SquadManagementScreen::SquadData*>, Ogre::GeneralAllocPolicy > >) - unsupported type
*/

int SquadManagementScreenBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int SquadManagementScreenBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.SquadManagementScreen object");
    return 1;
}

void SquadManagementScreenBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SquadManagementScreenBinding::gc },
        { "__tostring", SquadManagementScreenBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", SquadManagementScreenBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", SquadManagementScreenBinding::_DESTRUCTOR },
        { "getVisible", SquadManagementScreenBinding::getVisible },
        { "update", SquadManagementScreenBinding::update },
        { "reset", SquadManagementScreenBinding::reset },
        { "refreshSquads", SquadManagementScreenBinding::refreshSquads },
        { "notifyEndDropSquad", SquadManagementScreenBinding::notifyEndDropSquad },
        { "notifyEndDropPortrait", SquadManagementScreenBinding::notifyEndDropPortrait },
        { "removeSquad", SquadManagementScreenBinding::removeSquad },
        { "getSquad", SquadManagementScreenBinding::getSquad },
        { "dismissCharacter", SquadManagementScreenBinding::dismissCharacter },
        { 0, 0 }
    };

    registerClass(
        L, 
        SquadManagementScreenBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SquadManagementScreenBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "mainWidget", SquadManagementScreen_get_mainWidget);
    registerGetter(L, "btnAddSquad", SquadManagementScreen_get_btnAddSquad);
    registerGetter(L, "txtFactionSize", SquadManagementScreen_get_txtFactionSize);
    registerGetter(L, "factionSize", SquadManagementScreen_get_factionSize);
    registerGetter(L, "panelSquads", SquadManagementScreen_get_panelSquads);
    registerGetter(L, "panelDismiss", SquadManagementScreen_get_panelDismiss);
    registerGetter(L, "dismissChar", SquadManagementScreen_get_dismissChar);
    registerGetter(L, "faction", SquadManagementScreen_get_faction);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "factionSize", SquadManagementScreen_set_factionSize);
    registerSetter(L, "dismissChar", SquadManagementScreen_set_dismissChar);
    registerSetter(L, "faction", SquadManagementScreen_set_faction);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua