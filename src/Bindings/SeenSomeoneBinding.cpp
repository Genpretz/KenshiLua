#include "pch.h"
#include "kenshi\SensoryData.h"
#include "SeenSomeoneBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/Util/TimeOfDayBinding.h"

namespace KenshiLua
{

static SeenSomeone* getInstance(lua_State* L, int idx)
{
    return checkObject<SeenSomeone>(L, idx, SeenSomeoneBinding::getMetatableName());
}

// --- Getters for SeenSomeone ---
static int SeenSomeone_get_lastPosition(lua_State* L)
{
    SeenSomeone* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeenSomeone is nil");
    pushVector3(L, instance->lastPosition);
    return 1;
}

static int SeenSomeone_get_lastSeenTime(lua_State* L)
{
    SeenSomeone* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeenSomeone is nil");
    return pushObject<TimeOfDay>(L, &instance->lastSeenTime, TimeOfDayBinding::getMetatableName());
}

static int SeenSomeone_get_percievedFaction(lua_State* L)
{
    SeenSomeone* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeenSomeone is nil");
    return pushObject<Faction>(L, instance->percievedFaction, FactionBinding::getMetatableName());
}

static int SeenSomeone_get_percievedSlave(lua_State* L)
{
    SeenSomeone* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeenSomeone is nil");
    lua_pushinteger(L, (lua_Integer)instance->percievedSlave);
    return 1;
}

static int SeenSomeone_get_FOVScore(lua_State* L)
{
    SeenSomeone* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeenSomeone is nil");
    lua_pushnumber(L, instance->FOVScore);
    return 1;
}

static int SeenSomeone_get_canSee(lua_State* L)
{
    SeenSomeone* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeenSomeone is nil");
    lua_pushboolean(L, instance->canSee ? 1 : 0);
    return 1;
}

static int SeenSomeone_get_canHear(lua_State* L)
{
    SeenSomeone* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeenSomeone is nil");
    lua_pushboolean(L, instance->canHear ? 1 : 0);
    return 1;
}

static int SeenSomeone_get_alarmState(lua_State* L)
{
    SeenSomeone* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeenSomeone is nil");
    lua_pushnumber(L, instance->alarmState);
    return 1;
}

// --- Setters for SeenSomeone ---
static int SeenSomeone_set_lastPosition(lua_State* L)
{
    SeenSomeone* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeenSomeone is nil");
    readVector3(L, 2, instance->lastPosition);
    return 0;
}

static int SeenSomeone_set_lastSeenTime(lua_State* L)
{
    SeenSomeone* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeenSomeone is nil");
    instance->lastSeenTime = *checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    return 0;
}

static int SeenSomeone_set_percievedFaction(lua_State* L)
{
    SeenSomeone* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeenSomeone is nil");
    instance->percievedFaction = lua_isnoneornil(L, 2) ? nullptr : checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

static int SeenSomeone_set_percievedSlave(lua_State* L)
{
    SeenSomeone* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeenSomeone is nil");
    instance->percievedSlave = (SlaveStateEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int SeenSomeone_set_FOVScore(lua_State* L)
{
    SeenSomeone* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeenSomeone is nil");
    instance->FOVScore = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SeenSomeone_set_canSee(lua_State* L)
{
    SeenSomeone* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeenSomeone is nil");
    instance->canSee = lua_toboolean(L, 2) != 0;
    return 0;
}

static int SeenSomeone_set_canHear(lua_State* L)
{
    SeenSomeone* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeenSomeone is nil");
    instance->canHear = lua_toboolean(L, 2) != 0;
    return 0;
}

static int SeenSomeone_set_alarmState(lua_State* L)
{
    SeenSomeone* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeenSomeone is nil");
    instance->alarmState = (float)luaL_checknumber(L, 2);
    return 0;
}

int SeenSomeoneBinding::lastSeenInSeconds(lua_State* L)
{
    SeenSomeone* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeenSomeone is nil");

    float result = instance->lastSeenInSeconds();
    lua_pushnumber(L, result);
    return 1;
}

int SeenSomeoneBinding::getPosition(lua_State* L)
{
    SeenSomeone* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeenSomeone is nil");

    Ogre::Vector3 result = instance->getPosition();
    pushVector3(L, result);
    return 1;
}

int SeenSomeoneBinding::getFaction(lua_State* L)
{
    SeenSomeone* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeenSomeone is nil");

    Faction* result = instance->getFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

/*
Skipped properties needing manual binding:
  line 51: type (TagsClass<SenseType>) - unsupported type
*/

int SeenSomeoneBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int SeenSomeoneBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.SeenSomeone object");
    return 1;
}



static int SeenSomeone_get_type(lua_State* L)
{
    SeenSomeone* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeenSomeone is nil");
    lua_pushinteger(L, (lua_Integer)instance->type.flags);
    return 1;
}


static int SeenSomeone_set_type(lua_State* L)
{
    SeenSomeone* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeenSomeone is nil");
    instance->type.flags = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}


void SeenSomeoneBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SeenSomeoneBinding::gc },
        { "__tostring", SeenSomeoneBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "lastSeenInSeconds", SeenSomeoneBinding::lastSeenInSeconds },
        { "getPosition", SeenSomeoneBinding::getPosition },
        { "getFaction", SeenSomeoneBinding::getFaction },
        { 0, 0 }
    };

    registerClass(
        L, 
        SeenSomeoneBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SeenSomeoneBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "lastPosition", SeenSomeone_get_lastPosition);
    registerGetter(L, "lastSeenTime", SeenSomeone_get_lastSeenTime);
    registerGetter(L, "percievedFaction", SeenSomeone_get_percievedFaction);
    registerGetter(L, "percievedSlave", SeenSomeone_get_percievedSlave);
    registerGetter(L, "FOVScore", SeenSomeone_get_FOVScore);
    registerGetter(L, "canSee", SeenSomeone_get_canSee);
    registerGetter(L, "canHear", SeenSomeone_get_canHear);
    registerGetter(L, "alarmState", SeenSomeone_get_alarmState);
        registerGetter(L, "type", SeenSomeone_get_type);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "lastPosition", SeenSomeone_set_lastPosition);
    registerSetter(L, "lastSeenTime", SeenSomeone_set_lastSeenTime);
    registerSetter(L, "percievedFaction", SeenSomeone_set_percievedFaction);
    registerSetter(L, "percievedSlave", SeenSomeone_set_percievedSlave);
    registerSetter(L, "FOVScore", SeenSomeone_set_FOVScore);
    registerSetter(L, "canSee", SeenSomeone_set_canSee);
    registerSetter(L, "canHear", SeenSomeone_set_canHear);
    registerSetter(L, "alarmState", SeenSomeone_set_alarmState);
        registerSetter(L, "type", SeenSomeone_set_type);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua