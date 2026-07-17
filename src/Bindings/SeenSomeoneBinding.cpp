#include "pch.h"
#include "kenshi\SensoryData.h"
#include "SeenSomeoneBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/FactionBinding.h"

namespace KenshiLua
{

static SeenSomeone* getB(lua_State* L, int idx)
{
    return checkObject<SeenSomeone>(L, idx, SeenSomeoneBinding::getMetatableName());
}

// --- Getters for SeenSomeone ---
static int SeenSomeone_get_lastPosition(lua_State* L)
{
    SeenSomeone* b = getB(L, 1);
    if (!b) return luaL_error(L, "SeenSomeone is nil");
    pushVector3(L, b->lastPosition);
    return 1;
}

static int SeenSomeone_get_lastSeenTime(lua_State* L)
{
    SeenSomeone* b = getB(L, 1);
    if (!b) return luaL_error(L, "SeenSomeone is nil");
    // TODO: Unsupported type for lastSeenTime (TimeOfDay)
    return luaL_error(L, "Unsupported property 'lastSeenTime' (type: TimeOfDay)");
}

static int SeenSomeone_get_percievedFaction(lua_State* L)
{
    SeenSomeone* b = getB(L, 1);
    if (!b) return luaL_error(L, "SeenSomeone is nil");
    return pushObject<Faction>(L, b->percievedFaction, FactionBinding::getMetatableName());
}

static int SeenSomeone_get_percievedSlave(lua_State* L)
{
    SeenSomeone* b = getB(L, 1);
    if (!b) return luaL_error(L, "SeenSomeone is nil");
    lua_pushinteger(L, (lua_Integer)b->percievedSlave);
    return 1;
}

static int SeenSomeone_get_FOVScore(lua_State* L)
{
    SeenSomeone* b = getB(L, 1);
    if (!b) return luaL_error(L, "SeenSomeone is nil");
    lua_pushnumber(L, b->FOVScore);
    return 1;
}

static int SeenSomeone_get_type(lua_State* L)
{
    SeenSomeone* b = getB(L, 1);
    if (!b) return luaL_error(L, "SeenSomeone is nil");
    // TODO: Unsupported type for type (TagsClass<SenseType>)
    return luaL_error(L, "Unsupported property 'type' (type: TagsClass<SenseType>)");
}

static int SeenSomeone_get_canSee(lua_State* L)
{
    SeenSomeone* b = getB(L, 1);
    if (!b) return luaL_error(L, "SeenSomeone is nil");
    lua_pushboolean(L, b->canSee ? 1 : 0);
    return 1;
}

static int SeenSomeone_get_canHear(lua_State* L)
{
    SeenSomeone* b = getB(L, 1);
    if (!b) return luaL_error(L, "SeenSomeone is nil");
    lua_pushboolean(L, b->canHear ? 1 : 0);
    return 1;
}

static int SeenSomeone_get_alarmState(lua_State* L)
{
    SeenSomeone* b = getB(L, 1);
    if (!b) return luaL_error(L, "SeenSomeone is nil");
    lua_pushnumber(L, b->alarmState);
    return 1;
}

// --- Setters for SeenSomeone ---
static int SeenSomeone_set_lastPosition(lua_State* L)
{
    SeenSomeone* b = getB(L, 1);
    if (!b) return luaL_error(L, "SeenSomeone is nil");
    readVector3(L, 2, b->lastPosition);
    return 0;
}

static int SeenSomeone_set_lastSeenTime(lua_State* L)
{
    SeenSomeone* b = getB(L, 1);
    if (!b) return luaL_error(L, "SeenSomeone is nil");
    return luaL_error(L, "Read-only or unsupported setter type for lastSeenTime");
}

static int SeenSomeone_set_percievedFaction(lua_State* L)
{
    SeenSomeone* b = getB(L, 1);
    if (!b) return luaL_error(L, "SeenSomeone is nil");
    return luaL_error(L, "Read-only or unsupported setter type for percievedFaction");
}

static int SeenSomeone_set_percievedSlave(lua_State* L)
{
    SeenSomeone* b = getB(L, 1);
    if (!b) return luaL_error(L, "SeenSomeone is nil");
    b->percievedSlave = (SlaveStateEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int SeenSomeone_set_FOVScore(lua_State* L)
{
    SeenSomeone* b = getB(L, 1);
    if (!b) return luaL_error(L, "SeenSomeone is nil");
    b->FOVScore = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SeenSomeone_set_type(lua_State* L)
{
    SeenSomeone* b = getB(L, 1);
    if (!b) return luaL_error(L, "SeenSomeone is nil");
    return luaL_error(L, "Read-only or unsupported setter type for type");
}

static int SeenSomeone_set_canSee(lua_State* L)
{
    SeenSomeone* b = getB(L, 1);
    if (!b) return luaL_error(L, "SeenSomeone is nil");
    b->canSee = lua_toboolean(L, 2) != 0;
    return 0;
}

static int SeenSomeone_set_canHear(lua_State* L)
{
    SeenSomeone* b = getB(L, 1);
    if (!b) return luaL_error(L, "SeenSomeone is nil");
    b->canHear = lua_toboolean(L, 2) != 0;
    return 0;
}

static int SeenSomeone_set_alarmState(lua_State* L)
{
    SeenSomeone* b = getB(L, 1);
    if (!b) return luaL_error(L, "SeenSomeone is nil");
    b->alarmState = (float)luaL_checknumber(L, 2);
    return 0;
}

int SeenSomeoneBinding::lastSeenInSeconds(lua_State* L)
{
    SeenSomeone* b = getB(L, 1);
    if (!b) return luaL_error(L, "SeenSomeone is nil");

    float result = b->lastSeenInSeconds();
    lua_pushnumber(L, result);
    return 1;
}

int SeenSomeoneBinding::getPosition(lua_State* L)
{
    SeenSomeone* b = getB(L, 1);
    if (!b) return luaL_error(L, "SeenSomeone is nil");

    Ogre::Vector3 result = b->getPosition();
    pushVector3(L, result);
    return 1;
}

int SeenSomeoneBinding::getFaction(lua_State* L)
{
    SeenSomeone* b = getB(L, 1);
    if (!b) return luaL_error(L, "SeenSomeone is nil");

    Faction* result = b->getFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

/*
Skipped methods needing manual binding:
  line 45: SeenSomeone* _CONSTRUCTOR(...) - unsupported return type
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
    lua_pushcfunction(L, SeenSomeone_get_lastPosition);
    lua_setfield(L, -2, "lastPosition");
    lua_pushcfunction(L, SeenSomeone_get_lastSeenTime);
    lua_setfield(L, -2, "lastSeenTime");
    lua_pushcfunction(L, SeenSomeone_get_percievedFaction);
    lua_setfield(L, -2, "percievedFaction");
    lua_pushcfunction(L, SeenSomeone_get_percievedSlave);
    lua_setfield(L, -2, "percievedSlave");
    lua_pushcfunction(L, SeenSomeone_get_FOVScore);
    lua_setfield(L, -2, "FOVScore");
    lua_pushcfunction(L, SeenSomeone_get_type);
    lua_setfield(L, -2, "type");
    lua_pushcfunction(L, SeenSomeone_get_canSee);
    lua_setfield(L, -2, "canSee");
    lua_pushcfunction(L, SeenSomeone_get_canHear);
    lua_setfield(L, -2, "canHear");
    lua_pushcfunction(L, SeenSomeone_get_alarmState);
    lua_setfield(L, -2, "alarmState");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, SeenSomeone_set_lastPosition);
    lua_setfield(L, -2, "lastPosition");
    lua_pushcfunction(L, SeenSomeone_set_lastSeenTime);
    lua_setfield(L, -2, "lastSeenTime");
    lua_pushcfunction(L, SeenSomeone_set_percievedFaction);
    lua_setfield(L, -2, "percievedFaction");
    lua_pushcfunction(L, SeenSomeone_set_percievedSlave);
    lua_setfield(L, -2, "percievedSlave");
    lua_pushcfunction(L, SeenSomeone_set_FOVScore);
    lua_setfield(L, -2, "FOVScore");
    lua_pushcfunction(L, SeenSomeone_set_type);
    lua_setfield(L, -2, "type");
    lua_pushcfunction(L, SeenSomeone_set_canSee);
    lua_setfield(L, -2, "canSee");
    lua_pushcfunction(L, SeenSomeone_set_canHear);
    lua_setfield(L, -2, "canHear");
    lua_pushcfunction(L, SeenSomeone_set_alarmState);
    lua_setfield(L, -2, "alarmState");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua