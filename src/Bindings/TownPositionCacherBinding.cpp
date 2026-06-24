#include "pch.h"
#include "kenshi\Town.h"
#include "TownPositionCacherBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

typedef TownBase::TownPositionCacher TownPositionCacher;

static TownPositionCacher* getB(lua_State* L, int idx)
{
    return checkObject<TownPositionCacher>(L, idx, TownPositionCacherBinding::getMetatableName());
}

// --- Getters for TownPositionCacher ---
static int TownPositionCacher_get_lastUpdateStamp(lua_State* L)
{
    TownPositionCacher* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownPositionCacher is nil");
    // TODO: Unsupported type for lastUpdateStamp (TimeOfDay)
    lua_pushnil(L);
    return 1;
}

static int TownPositionCacher_get_updateRateInHours(lua_State* L)
{
    TownPositionCacher* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownPositionCacher is nil");
    lua_pushnumber(L, b->updateRateInHours);
    return 1;
}

static int TownPositionCacher_get_pos(lua_State* L)
{
    TownPositionCacher* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownPositionCacher is nil");
    pushVector3(L, b->pos);
    return 1;
}

// --- Setters for TownPositionCacher ---
static int TownPositionCacher_set_lastUpdateStamp(lua_State* L)
{
    TownPositionCacher* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownPositionCacher is nil");
    return luaL_error(L, "Read-only or unsupported setter type for lastUpdateStamp");
}

static int TownPositionCacher_set_updateRateInHours(lua_State* L)
{
    TownPositionCacher* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownPositionCacher is nil");
    b->updateRateInHours = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TownPositionCacher_set_pos(lua_State* L)
{
    TownPositionCacher* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownPositionCacher is nil");
    readVector3(L, 2, b->pos);
    return 0;
}

int TownPositionCacherBinding::stampUpdate(lua_State* L)
{
    TownPositionCacher* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownPositionCacher is nil");

    b->stampUpdate();
    return 0;
}

int TownPositionCacherBinding::needsUpdate(lua_State* L)
{
    TownPositionCacher* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownPositionCacher is nil");

    bool result = b->needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 198: TownPositionCacher* _CONSTRUCTOR(...) - unsupported return type
*/

int TownPositionCacherBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TownPositionCacherBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TownPositionCacher object");
    return 1;
}

void TownPositionCacherBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TownPositionCacherBinding::gc },
        { "__tostring", TownPositionCacherBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "stampUpdate", TownPositionCacherBinding::stampUpdate },
        { "needsUpdate", TownPositionCacherBinding::needsUpdate },
        { 0, 0 }
    };

    registerClass(
        L, 
        TownPositionCacherBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TownPositionCacherBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, TownPositionCacher_get_lastUpdateStamp);
    lua_setfield(L, -2, "lastUpdateStamp");
    lua_pushcfunction(L, TownPositionCacher_get_updateRateInHours);
    lua_setfield(L, -2, "updateRateInHours");
    lua_pushcfunction(L, TownPositionCacher_get_pos);
    lua_setfield(L, -2, "pos");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, TownPositionCacher_set_lastUpdateStamp);
    lua_setfield(L, -2, "lastUpdateStamp");
    lua_pushcfunction(L, TownPositionCacher_set_updateRateInHours);
    lua_setfield(L, -2, "updateRateInHours");
    lua_pushcfunction(L, TownPositionCacher_set_pos);
    lua_setfield(L, -2, "pos");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua