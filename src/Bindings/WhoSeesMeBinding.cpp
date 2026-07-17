#include "pch.h"
#include "kenshi\Character.h"
#include "WhoSeesMeBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

typedef Character::WhoSeesMe WhoSeesMe;

static WhoSeesMe* getB(lua_State* L, int idx)
{
    return checkObject<WhoSeesMe>(L, idx, WhoSeesMeBinding::getMetatableName());
}

// --- Getters for WhoSeesMe ---
static int WhoSeesMe_get_lastUpdated(lua_State* L)
{
    WhoSeesMe* b = getB(L, 1);
    if (!b) return luaL_error(L, "WhoSeesMe is nil");
    lua_pushnumber(L, b->lastUpdated);
    return 1;
}

static int WhoSeesMe_get_seeState(lua_State* L)
{
    WhoSeesMe* b = getB(L, 1);
    if (!b) return luaL_error(L, "WhoSeesMe is nil");
    // TODO: Unsupported type for seeState (YesNoMaybe)
    return luaL_error(L, "Unsupported property 'seeState' (type: YesNoMaybe)");
}

static int WhoSeesMe_get_progressOfMaybe(lua_State* L)
{
    WhoSeesMe* b = getB(L, 1);
    if (!b) return luaL_error(L, "WhoSeesMe is nil");
    lua_pushnumber(L, b->progressOfMaybe);
    return 1;
}

// --- Setters for WhoSeesMe ---
static int WhoSeesMe_set_lastUpdated(lua_State* L)
{
    WhoSeesMe* b = getB(L, 1);
    if (!b) return luaL_error(L, "WhoSeesMe is nil");
    b->lastUpdated = (double)luaL_checknumber(L, 2);
    return 0;
}

static int WhoSeesMe_set_seeState(lua_State* L)
{
    WhoSeesMe* b = getB(L, 1);
    if (!b) return luaL_error(L, "WhoSeesMe is nil");
    return luaL_error(L, "Read-only or unsupported setter type for seeState");
}

static int WhoSeesMe_set_progressOfMaybe(lua_State* L)
{
    WhoSeesMe* b = getB(L, 1);
    if (!b) return luaL_error(L, "WhoSeesMe is nil");
    b->progressOfMaybe = (float)luaL_checknumber(L, 2);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 322: WhoSeesMe* _CONSTRUCTOR(...) - overloaded method
  line 324: WhoSeesMe* _CONSTRUCTOR(...) - overloaded method
*/

int WhoSeesMeBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int WhoSeesMeBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.WhoSeesMe object");
    return 1;
}

void WhoSeesMeBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       WhoSeesMeBinding::gc },
        { "__tostring", WhoSeesMeBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        WhoSeesMeBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, WhoSeesMeBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, WhoSeesMe_get_lastUpdated);
    lua_setfield(L, -2, "lastUpdated");
    lua_pushcfunction(L, WhoSeesMe_get_seeState);
    lua_setfield(L, -2, "seeState");
    lua_pushcfunction(L, WhoSeesMe_get_progressOfMaybe);
    lua_setfield(L, -2, "progressOfMaybe");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, WhoSeesMe_set_lastUpdated);
    lua_setfield(L, -2, "lastUpdated");
    lua_pushcfunction(L, WhoSeesMe_set_seeState);
    lua_setfield(L, -2, "seeState");
    lua_pushcfunction(L, WhoSeesMe_set_progressOfMaybe);
    lua_setfield(L, -2, "progressOfMaybe");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua