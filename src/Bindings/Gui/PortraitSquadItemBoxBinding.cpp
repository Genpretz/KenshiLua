#include "pch.h"
#include "kenshi\gui\SquadManagementScreen.h"
#include "PortraitSquadItemBoxBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
typedef SquadManagementScreen::PortraitSquadItemBox PortraitSquadItemBox;


static PortraitSquadItemBox* getInstance(lua_State* L, int idx)
{
    return checkObject<PortraitSquadItemBox>(L, idx, PortraitSquadItemBoxBinding::getMetatableName());
}

// --- Getters for PortraitSquadItemBox ---
static int PortraitSquadItemBox_get_squad(lua_State* L)
{
    PortraitSquadItemBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitSquadItemBox is nil");
    lua_pushlightuserdata(L, (void*)instance->squad);
    return 1;
}

static int PortraitSquadItemBox_get_squadView(lua_State* L)
{
    PortraitSquadItemBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitSquadItemBox is nil");
    lua_pushlightuserdata(L, (void*)instance->squadView);
    return 1;
}

// --- Setters for PortraitSquadItemBox ---
int PortraitSquadItemBoxBinding::_DESTRUCTOR(lua_State* L)
{
    PortraitSquadItemBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitSquadItemBox is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int PortraitSquadItemBoxBinding::getItemCount(lua_State* L)
{
    PortraitSquadItemBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitSquadItemBox is nil");

    int result = instance->getItemCount();
    lua_pushinteger(L, result);
    return 1;
}

int PortraitSquadItemBoxBinding::update(lua_State* L)
{
    PortraitSquadItemBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitSquadItemBox is nil");

    instance->update();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 102: PortraitSquadItemBox* _CONSTRUCTOR(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - PortraitSquadItemBox_get_squad: SquadManagementScreen::SquadData* (unbound pointer)
  - PortraitSquadItemBox_get_squadView: SquadManagementScreen::SquadCellView* (unbound pointer)
*/

int PortraitSquadItemBoxBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int PortraitSquadItemBoxBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.PortraitSquadItemBox object");
    return 1;
}

void PortraitSquadItemBoxBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       PortraitSquadItemBoxBinding::gc },
        { "__tostring", PortraitSquadItemBoxBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", PortraitSquadItemBoxBinding::_DESTRUCTOR },
        { "getItemCount", PortraitSquadItemBoxBinding::getItemCount },
        { "update", PortraitSquadItemBoxBinding::update },
        { 0, 0 }
    };

    registerClass(
        L, 
        PortraitSquadItemBoxBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, PortraitSquadItemBoxBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "squad", PortraitSquadItemBox_get_squad);
    registerGetter(L, "squadView", PortraitSquadItemBox_get_squadView);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseItemBox<SquadManagementScreen::PortraitSquadCellView>
    // setMetatableParent(L, PortraitSquadItemBoxBinding::getMetatableName(), wraps::BaseItemBox<SquadManagementScreen::PortraitSquadCellView>Binding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua