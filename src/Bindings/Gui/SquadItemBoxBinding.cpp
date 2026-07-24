#include "pch.h"
#include "kenshi\gui\SquadManagementScreen.h"
#include "SquadItemBoxBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

typedef SquadManagementScreen::SquadItemBox SquadItemBox;

static SquadItemBox* getInstance(lua_State* L, int idx)
{
    return checkObject<SquadItemBox>(L, idx, SquadItemBoxBinding::getMetatableName());
}

// --- Getters for SquadItemBox ---
// --- Setters for SquadItemBox ---
int SquadItemBoxBinding::_DESTRUCTOR(lua_State* L)
{
    SquadItemBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadItemBox is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int SquadItemBoxBinding::setCellSize(lua_State* L)
{
    SquadItemBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadItemBox is nil");

    int width = (int)luaL_checkinteger(L, 2);
    int height = (int)luaL_checkinteger(L, 3);
    instance->setCellSize(width, height);
    return 0;
}

int SquadItemBoxBinding::getItemCount(lua_State* L)
{
    SquadItemBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadItemBox is nil");

    int result = instance->getItemCount();
    lua_pushinteger(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 141: SquadItemBox* _CONSTRUCTOR(...) - unsupported arg type
*/

int SquadItemBoxBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int SquadItemBoxBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.SquadItemBox object");
    return 1;
}

void SquadItemBoxBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SquadItemBoxBinding::gc },
        { "__tostring", SquadItemBoxBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", SquadItemBoxBinding::_DESTRUCTOR },
        { "setCellSize", SquadItemBoxBinding::setCellSize },
        { "getItemCount", SquadItemBoxBinding::getItemCount },
        { 0, 0 }
    };

    registerClass(
        L, 
        SquadItemBoxBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SquadItemBoxBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseItemBox<SquadManagementScreen::SquadCellView>
    // setMetatableParent(L, SquadItemBoxBinding::getMetatableName(), wraps::BaseItemBox<SquadManagementScreen::SquadCellView>Binding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua