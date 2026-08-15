#include "pch.h"
#include "kenshi\Town.h"
#include "TownPositionCacherBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Util/TimeOfDayBinding.h"

namespace KenshiLua
{

static TownPositionCacher* getInstance(lua_State* L, int idx)
{
    return checkObject<TownPositionCacher>(L, idx, TownPositionCacherBinding::getMetatableName());
}

// --- Getters for TownPositionCacher ---
static int TownPositionCacher_get_lastUpdateStamp(lua_State* L)
{
    TownPositionCacher* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownPositionCacher is nil");
    return pushObject<TimeOfDay>(L, &instance->lastUpdateStamp, TimeOfDayBinding::getMetatableName());
}

static int TownPositionCacher_get_updateRateInHours(lua_State* L)
{
    TownPositionCacher* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownPositionCacher is nil");
    lua_pushnumber(L, instance->updateRateInHours);
    return 1;
}

static int TownPositionCacher_get_pos(lua_State* L)
{
    TownPositionCacher* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownPositionCacher is nil");
    pushVector3(L, instance->pos);
    return 1;
}

// --- Setters for TownPositionCacher ---
static int TownPositionCacher_set_lastUpdateStamp(lua_State* L)
{
    TownPositionCacher* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownPositionCacher is nil");
    instance->lastUpdateStamp = *checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    return 0;
}

static int TownPositionCacher_set_updateRateInHours(lua_State* L)
{
    TownPositionCacher* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownPositionCacher is nil");
    instance->updateRateInHours = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TownPositionCacher_set_pos(lua_State* L)
{
    TownPositionCacher* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownPositionCacher is nil");
    readVector3(L, 2, instance->pos);
    return 0;
}

int TownPositionCacherBinding::stampUpdate(lua_State* L)
{
    TownPositionCacher* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownPositionCacher is nil");

    instance->stampUpdate();
    return 0;
}

int TownPositionCacherBinding::needsUpdate(lua_State* L)
{
    TownPositionCacher* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownPositionCacher is nil");

    bool result = instance->needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

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
    registerGetter(L, "lastUpdateStamp", TownPositionCacher_get_lastUpdateStamp);
    registerGetter(L, "updateRateInHours", TownPositionCacher_get_updateRateInHours);
    registerGetter(L, "pos", TownPositionCacher_get_pos);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "lastUpdateStamp", TownPositionCacher_set_lastUpdateStamp);
    registerSetter(L, "updateRateInHours", TownPositionCacher_set_updateRateInHours);
    registerSetter(L, "pos", TownPositionCacher_set_pos);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua