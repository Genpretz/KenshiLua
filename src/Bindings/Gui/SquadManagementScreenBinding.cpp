#include "pch.h"
#include "kenshi\gui\SquadManagementScreen.h"
#include "SquadManagementScreenBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/MyGuiBinding.h"
#include "Bindings/Gui/SquadDataBinding.h"
#include "Bindings/Gui/SquadItemBoxBinding.h"
#include "Bindings/Gui/PortraitSquadItemBoxBinding.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/Gui/ManagementScreenBinding.h"
#include "Bindings/Util/StdMapBinding.h"

namespace KenshiLua
{

typedef StdMapBinding<ActivePlatoon*, SquadManagementScreen::SquadData*> SquadsMapBinding;

static SquadManagementScreen* getInstance(lua_State* L, int idx)
{
    return checkObject<SquadManagementScreen>(L, idx, SquadManagementScreenBinding::getMetatableName());
}

// --- Getters for SquadManagementScreen ---
static int SquadManagementScreen_get_mainWidget(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->mainWidget, MyGuiBinding::getMetatableName());
}

static int SquadManagementScreen_get_btnAddSquad(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->btnAddSquad, MyGuiBinding::getMetatableName());
}

static int SquadManagementScreen_get_txtFactionSize(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->txtFactionSize, MyGuiBinding::getMetatableName());
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
    return pushObject<SquadManagementScreen::SquadItemBox>(L, instance->panelSquads, SquadItemBoxBinding::getMetatableName());
}

static int SquadManagementScreen_get_panelDismiss(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");
    return pushObject<SquadManagementScreen::PortraitSquadItemBox>(L, instance->panelDismiss, PortraitSquadItemBoxBinding::getMetatableName());
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

static int SquadManagementScreen_get_squads(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");
    return pushObject<SquadsMapBinding::MapType>(L, &instance->squads, SquadsMapBinding::getMetatableName());
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

static int SquadManagementScreen_set_panelSquads(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");
    instance->panelSquads = lua_isnoneornil(L, 2) ? nullptr : checkObject<SquadManagementScreen::SquadItemBox>(L, 2, SquadItemBoxBinding::getMetatableName());
    return 0;
}

static int SquadManagementScreen_set_panelDismiss(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");
    instance->panelDismiss = lua_isnoneornil(L, 2) ? nullptr : checkObject<SquadManagementScreen::PortraitSquadItemBox>(L, 2, PortraitSquadItemBoxBinding::getMetatableName());
    return 0;
}

static int SquadManagementScreen_set_squads(lua_State* L)
{
    SquadManagementScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadManagementScreen is nil");
    auto* val = checkObject<SquadsMapBinding::MapType>(L, 2, SquadsMapBinding::getMetatableName());
    if (val) instance->squads = *val;
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
    return pushObject<SquadManagementScreen::SquadData>(L, result, SquadDataBinding::getMetatableName());
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
    SquadsMapBinding::registerBinding(L, "std::map<ActivePlatoon*, SquadData*>", ActivePlatoonBinding::getMetatableName(), SquadDataBinding::getMetatableName());

    static const luaL_Reg meta[] = {
        { "__gc",       SquadManagementScreenBinding::gc },
        { "__tostring", SquadManagementScreenBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
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
    registerGetter(L, "squads", SquadManagementScreen_get_squads);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "factionSize", SquadManagementScreen_set_factionSize);
    registerSetter(L, "panelSquads", SquadManagementScreen_set_panelSquads);
    registerSetter(L, "panelDismiss", SquadManagementScreen_set_panelDismiss);
    registerSetter(L, "dismissChar", SquadManagementScreen_set_dismissChar);
    registerSetter(L, "faction", SquadManagementScreen_set_faction);
    registerSetter(L, "squads", SquadManagementScreen_set_squads);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua