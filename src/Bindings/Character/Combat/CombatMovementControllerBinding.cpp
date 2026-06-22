#include "pch.h"
#include "Bindings/Character/Combat/CombatMovementControllerBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/CharMovement.h>
#include "Bindings/Character/CharStatsBinding.h"

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static CombatMovementController* getS(lua_State* L, int idx)
{
    return checkObject<CombatMovementController>(L, idx, CombatMovementControllerBinding::getMetatableName());
}

int CombatMovementControllerBinding::gc(lua_State* L) { return noopGc(L); }

int CombatMovementControllerBinding::tostring(lua_State* L)
{
    CombatMovementController* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int CombatMovementControllerBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, CombatMovementControllerBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    CombatMovementController* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    // TODO ogre_unordered_map<hand, float>::type characterCollisions; unsupported __index type from header line 289
    // TODO CharMovement* movement; unsupported __index type from header line 291
    if (strcmp(key, "movement") == 0) {
        if (s->movement) {
            lua_pushlightuserdata(L, s->movement);
            return 1;
        } else {
            lua_pushnil(L);
            return 1;
        }
    }
    if (strcmp(key, "chaseMode") == 0) { lua_pushboolean(L, s->chaseMode ? 1 : 0); return 1; }
    if (strcmp(key, "chaseStateTimer") == 0) { lua_pushnumber(L, s->chaseStateTimer); return 1; }
    if (strcmp(key, "hasForcedWP") == 0) { lua_pushboolean(L, s->hasForcedWP ? 1 : 0); return 1; }
    // TODO Ogre::Vector3 forcedWP; unsupported __index type from header line 306
    // TODO MotionFilter flockFilterX; unsupported __index type from header line 308
    // TODO MotionFilter flockFilterZ; unsupported __index type from header line 309
    // TODO FlockingTools* flockingControl; unsupported __index type from header line 312
    if (strcmp(key, "stats") == 0) { return pushObject<CharStats>(L, s->stats, CharStatsBinding::getMetatableName()); }
    if (strcmp(key, "radius") == 0) { lua_pushnumber(L, s->radius); return 1; }
    if (strcmp(key, "jogMode") == 0) { lua_pushboolean(L, s->jogMode ? 1 : 0); return 1; }
    if (strcmp(key, "TOTALREPULSION_DAMPING") == 0) { lua_pushnumber(L, s->TOTALREPULSION_DAMPING); return 1; }
    if (strcmp(key, "STRAFE_STATE_DAMPING") == 0) { lua_pushnumber(L, s->STRAFE_STATE_DAMPING); return 1; }
    if (strcmp(key, "STRAFE_THRESHOLD") == 0) { lua_pushnumber(L, s->STRAFE_THRESHOLD); return 1; }
    if (strcmp(key, "FORWARD_THRESHOLD") == 0) { lua_pushnumber(L, s->FORWARD_THRESHOLD); return 1; }
    if (strcmp(key, "MIN_RANGE_FW") == 0) { lua_pushnumber(L, s->MIN_RANGE_FW); return 1; }
    if (strcmp(key, "ENEMY_DIST") == 0) { lua_pushnumber(L, s->ENEMY_DIST); return 1; }
    if (strcmp(key, "ALLY_DIST") == 0) { lua_pushnumber(L, s->ALLY_DIST); return 1; }
    if (strcmp(key, "STOP_THRESHOLD") == 0) { lua_pushnumber(L, s->STOP_THRESHOLD); return 1; }
    if (strcmp(key, "START_THRESHOLD") == 0) { lua_pushnumber(L, s->START_THRESHOLD); return 1; }
    if (strcmp(key, "ACCEL_RATE_COMBATMODE") == 0) { lua_pushnumber(L, s->ACCEL_RATE_COMBATMODE); return 1; }
    if (strcmp(key, "meiMin") == 0) { lua_pushnumber(L, s->meiMin); return 1; }
    if (strcmp(key, "circlingSpeed") == 0) { lua_pushnumber(L, s->circlingSpeed); return 1; }
    if (strcmp(key, "combatMinDistance") == 0) { lua_pushnumber(L, s->combatMinDistance); return 1; }
    if (strcmp(key, "combatMaxDistance") == 0) { lua_pushnumber(L, s->combatMaxDistance); return 1; }
    if (strcmp(key, "strafeStateTimer") == 0) { lua_pushnumber(L, s->strafeStateTimer); return 1; }
    if (strcmp(key, "strafing") == 0) { lua_pushboolean(L, s->strafing ? 1 : 0); return 1; }
    if (strcmp(key, "powerThrough") == 0) { lua_pushboolean(L, s->powerThrough ? 1 : 0); return 1; }
    if (strcmp(key, "canStrafe") == 0) { lua_pushboolean(L, s->canStrafe ? 1 : 0); return 1; }
    if (strcmp(key, "speedLimit") == 0) { lua_pushnumber(L, s->speedLimit); return 1; }
    if (strcmp(key, "currentAccelSpeed") == 0) { lua_pushnumber(L, s->currentAccelSpeed); return 1; }
    // TODO hand lookAtCharacter; unsupported __index type from header line 337
    // TODO hand combatTarget; unsupported __index type from header line 338

    lua_pushnil(L);
    return 1;
}

int CombatMovementControllerBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    CombatMovementController* s = getS(L, 1);
    if (!s) return luaL_error(L, "CombatMovementController is nil");

    // TODO ogre_unordered_map<hand, float>::type characterCollisions; unsupported __newindex type from header line 289
    // TODO CharMovement* movement; unsupported __newindex type from header line 291
    if (strcmp(key, "chaseMode") == 0) { s->chaseMode = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "chaseStateTimer") == 0) { s->chaseStateTimer = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "hasForcedWP") == 0) { s->hasForcedWP = lua_toboolean(L, 3) != 0; return 0; }
    // TODO Ogre::Vector3 forcedWP; unsupported __newindex type from header line 306
    // TODO MotionFilter flockFilterX; unsupported __newindex type from header line 308
    // TODO MotionFilter flockFilterZ; unsupported __newindex type from header line 309
    // TODO FlockingTools* flockingControl; unsupported __newindex type from header line 312
    // TODO CharStats* stats; unsupported __newindex type from header line 313
    if (strcmp(key, "radius") == 0) { s->radius = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "jogMode") == 0) { s->jogMode = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "TOTALREPULSION_DAMPING") == 0) { s->TOTALREPULSION_DAMPING = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "STRAFE_STATE_DAMPING") == 0) { s->STRAFE_STATE_DAMPING = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "STRAFE_THRESHOLD") == 0) { s->STRAFE_THRESHOLD = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "FORWARD_THRESHOLD") == 0) { s->FORWARD_THRESHOLD = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "MIN_RANGE_FW") == 0) { s->MIN_RANGE_FW = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "ENEMY_DIST") == 0) { s->ENEMY_DIST = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "ALLY_DIST") == 0) { s->ALLY_DIST = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "STOP_THRESHOLD") == 0) { s->STOP_THRESHOLD = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "START_THRESHOLD") == 0) { s->START_THRESHOLD = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "ACCEL_RATE_COMBATMODE") == 0) { s->ACCEL_RATE_COMBATMODE = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "meiMin") == 0) { s->meiMin = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "circlingSpeed") == 0) { s->circlingSpeed = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "combatMinDistance") == 0) { s->combatMinDistance = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "combatMaxDistance") == 0) { s->combatMaxDistance = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "strafeStateTimer") == 0) { s->strafeStateTimer = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "strafing") == 0) { s->strafing = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "powerThrough") == 0) { s->powerThrough = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "canStrafe") == 0) { s->canStrafe = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "speedLimit") == 0) { s->speedLimit = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "currentAccelSpeed") == 0) { s->currentAccelSpeed = (float)luaL_checknumber(L, 3); return 0; }
    // TODO hand lookAtCharacter; unsupported __newindex type from header line 337
    // TODO hand combatTarget; unsupported __newindex type from header line 338

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int CombatMovementControllerBinding::collisionUpdate(lua_State* L)
{
    CombatMovementController* s = getS(L, 1);
    if (!s) return luaL_error(L, "CombatMovementController is nil");

    float time = (float)luaL_checknumber(L, 2);
    s->collisionUpdate(time);
    return 0;
}

int CombatMovementControllerBinding::areTherePeopleInMyWay(lua_State* L)
{
    CombatMovementController* s = getS(L, 1);
    if (!s) return luaL_error(L, "CombatMovementController is nil");

    bool result = s->areTherePeopleInMyWay();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatMovementControllerBinding::disable(lua_State* L)
{
    CombatMovementController* s = getS(L, 1);
    if (!s) return luaL_error(L, "CombatMovementController is nil");

    s->disable();
    return 0;
}

int CombatMovementControllerBinding::_DESTRUCTOR(lua_State* L)
{
    CombatMovementController* s = getS(L, 1);
    if (!s) return luaL_error(L, "CombatMovementController is nil");

    s->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 288: CombatMovementController* _CONSTRUCTOR(...) - unsupported return type
  line 293: bool chasingModeCheck(...) - unsupported arg type
  line 295: void create(...) - unsupported arg type
  line 297: void addACharacterObstruction(...) - unsupported arg type
  line 298: void setupCombatMovementVariables(...) - unsupported arg type
  line 299: void combatMovementUpdate(...) - unsupported arg type
  line 300: void combatMovementUpdate_crippleMode(...) - unsupported arg type
  line 301: Ogre::Vector3 getUrgentVelocities(...) - unsupported return type
  line 302: void checkWeDontCollideWithCharacters(...) - unsupported arg type
  line 303: bool checkCharacterCollision(...) - unsupported arg type
  line 304: void setForcedWP(...) - unsupported arg type
  line 307: void getGUIData(...) - unsupported arg type
  line 310: void combatMovementOffensive(...) - unsupported arg type
  line 327: void combatMovementAnimationUpdate(...) - unsupported arg type
*/

void CombatMovementControllerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CombatMovementControllerBinding::gc },
        { "__tostring", CombatMovementControllerBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "collisionUpdate", CombatMovementControllerBinding::collisionUpdate },
        { "areTherePeopleInMyWay", CombatMovementControllerBinding::areTherePeopleInMyWay },
        { "disable", CombatMovementControllerBinding::disable },
        { "_DESTRUCTOR", CombatMovementControllerBinding::_DESTRUCTOR },
        { 0, 0 }
    };
    registerClass(L, CombatMovementControllerBinding::getMetatableName(), meta, methods, CombatMovementControllerBinding::index, CombatMovementControllerBinding::newindex);
}

} // namespace KenshiLua