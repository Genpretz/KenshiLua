#include "pch.h"
#include "kenshi\CharMovement.h"
#include "CombatMovementControllerBinding.h"
#include "FlockingToolsBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharStatsBinding.h"
#include "Bindings/FlockingToolsBinding.h"
#include "Bindings/HandBinding.h"

namespace KenshiLua
{

static CombatMovementController* getB(lua_State* L, int idx)
{
    return checkObject<CombatMovementController>(L, idx, CombatMovementControllerBinding::getMetatableName());
}

// --- Getters for CombatMovementController ---
static int CombatMovementController_get_characterCollisions(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    // TODO: Unsupported type for characterCollisions (ogre_unordered_map<hand, float>::type)
    return luaL_error(L, "Unsupported property 'characterCollisions' (type: ogre_unordered_map<hand, float>::type)");
}

static int CombatMovementController_get_movement(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    // TODO: Unsupported type for movement (CharMovement*)
    return luaL_error(L, "Unsupported property 'movement' (type: CharMovement*)");
}

static int CombatMovementController_get_chaseMode(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushboolean(L, b->chaseMode ? 1 : 0);
    return 1;
}

static int CombatMovementController_get_chaseStateTimer(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, b->chaseStateTimer);
    return 1;
}

static int CombatMovementController_get_hasForcedWP(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushboolean(L, b->hasForcedWP ? 1 : 0);
    return 1;
}

static int CombatMovementController_get_forcedWP(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    pushVector3(L, b->forcedWP);
    return 1;
}

static int CombatMovementController_get_flockFilterX(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    // TODO: Unsupported type for flockFilterX (MotionFilter)
    return luaL_error(L, "Unsupported property 'flockFilterX' (type: MotionFilter)");
}

static int CombatMovementController_get_flockFilterZ(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    // TODO: Unsupported type for flockFilterZ (MotionFilter)
    return luaL_error(L, "Unsupported property 'flockFilterZ' (type: MotionFilter)");
}

static int CombatMovementController_get_flockingControl(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    return pushObject<FlockingTools>(L, b->flockingControl, FlockingToolsBinding::getMetatableName());
}

static int CombatMovementController_get_stats(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    return pushObject<CharStats>(L, b->stats, CharStatsBinding::getMetatableName());
}

static int CombatMovementController_get_radius(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, b->radius);
    return 1;
}

static int CombatMovementController_get_jogMode(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushboolean(L, b->jogMode ? 1 : 0);
    return 1;
}

static int CombatMovementController_get_TOTALREPULSION_DAMPING(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, b->TOTALREPULSION_DAMPING);
    return 1;
}

static int CombatMovementController_get_STRAFE_STATE_DAMPING(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, b->STRAFE_STATE_DAMPING);
    return 1;
}

static int CombatMovementController_get_STRAFE_THRESHOLD(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, b->STRAFE_THRESHOLD);
    return 1;
}

static int CombatMovementController_get_FORWARD_THRESHOLD(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, b->FORWARD_THRESHOLD);
    return 1;
}

static int CombatMovementController_get_MIN_RANGE_FW(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, b->MIN_RANGE_FW);
    return 1;
}

static int CombatMovementController_get_ENEMY_DIST(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, b->ENEMY_DIST);
    return 1;
}

static int CombatMovementController_get_ALLY_DIST(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, b->ALLY_DIST);
    return 1;
}

static int CombatMovementController_get_STOP_THRESHOLD(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, b->STOP_THRESHOLD);
    return 1;
}

static int CombatMovementController_get_START_THRESHOLD(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, b->START_THRESHOLD);
    return 1;
}

static int CombatMovementController_get_ACCEL_RATE_COMBATMODE(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, b->ACCEL_RATE_COMBATMODE);
    return 1;
}

static int CombatMovementController_get_meiMin(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, b->meiMin);
    return 1;
}

static int CombatMovementController_get_circlingSpeed(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, b->circlingSpeed);
    return 1;
}

static int CombatMovementController_get_combatMinDistance(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, b->combatMinDistance);
    return 1;
}

static int CombatMovementController_get_combatMaxDistance(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, b->combatMaxDistance);
    return 1;
}

static int CombatMovementController_get_strafeStateTimer(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, b->strafeStateTimer);
    return 1;
}

static int CombatMovementController_get_strafing(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushboolean(L, b->strafing ? 1 : 0);
    return 1;
}

static int CombatMovementController_get_powerThrough(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushboolean(L, b->powerThrough ? 1 : 0);
    return 1;
}

static int CombatMovementController_get_canStrafe(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushboolean(L, b->canStrafe ? 1 : 0);
    return 1;
}

static int CombatMovementController_get_speedLimit(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, b->speedLimit);
    return 1;
}

static int CombatMovementController_get_currentAccelSpeed(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, b->currentAccelSpeed);
    return 1;
}

static int CombatMovementController_get_lookAtCharacter(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    return handBinding::push(L, b->lookAtCharacter);
}

static int CombatMovementController_get_combatTarget(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    return handBinding::push(L, b->combatTarget);
}

// --- Setters for CombatMovementController ---
static int CombatMovementController_set_characterCollisions(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    return luaL_error(L, "Read-only or unsupported setter type for characterCollisions");
}

static int CombatMovementController_set_movement(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    return luaL_error(L, "Read-only or unsupported setter type for movement");
}

static int CombatMovementController_set_chaseMode(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->chaseMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatMovementController_set_chaseStateTimer(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->chaseStateTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_hasForcedWP(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->hasForcedWP = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatMovementController_set_forcedWP(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    readVector3(L, 2, b->forcedWP);
    return 0;
}

static int CombatMovementController_set_flockFilterX(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    return luaL_error(L, "Read-only or unsupported setter type for flockFilterX");
}

static int CombatMovementController_set_flockFilterZ(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    return luaL_error(L, "Read-only or unsupported setter type for flockFilterZ");
}

static int CombatMovementController_set_flockingControl(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    return luaL_error(L, "Read-only or unsupported setter type for flockingControl");
}

static int CombatMovementController_set_stats(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    return luaL_error(L, "Read-only or unsupported setter type for stats");
}

static int CombatMovementController_set_radius(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->radius = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_jogMode(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->jogMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatMovementController_set_TOTALREPULSION_DAMPING(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->TOTALREPULSION_DAMPING = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_STRAFE_STATE_DAMPING(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->STRAFE_STATE_DAMPING = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_STRAFE_THRESHOLD(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->STRAFE_THRESHOLD = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_FORWARD_THRESHOLD(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->FORWARD_THRESHOLD = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_MIN_RANGE_FW(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->MIN_RANGE_FW = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_ENEMY_DIST(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->ENEMY_DIST = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_ALLY_DIST(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->ALLY_DIST = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_STOP_THRESHOLD(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->STOP_THRESHOLD = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_START_THRESHOLD(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->START_THRESHOLD = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_ACCEL_RATE_COMBATMODE(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->ACCEL_RATE_COMBATMODE = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_meiMin(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->meiMin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_circlingSpeed(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->circlingSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_combatMinDistance(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->combatMinDistance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_combatMaxDistance(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->combatMaxDistance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_strafeStateTimer(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->strafeStateTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_strafing(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->strafing = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatMovementController_set_powerThrough(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->powerThrough = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatMovementController_set_canStrafe(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->canStrafe = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatMovementController_set_speedLimit(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->speedLimit = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_currentAccelSpeed(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    b->currentAccelSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_lookAtCharacter(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->lookAtCharacter = *val;
    return 0;
}

static int CombatMovementController_set_combatTarget(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->combatTarget = *val;
    return 0;
}

int CombatMovementControllerBinding::collisionUpdate(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");

    float time = (float)luaL_checknumber(L, 2);
    b->collisionUpdate(time);
    return 0;
}

int CombatMovementControllerBinding::areTherePeopleInMyWay(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");

    bool result = b->areTherePeopleInMyWay();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatMovementControllerBinding::getUrgentVelocities(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    Ogre::Vector3 facingDir;
    readVector3(L, 3, facingDir);
    Ogre::Vector3 result = b->getUrgentVelocities(pos, facingDir);
    pushVector3(L, result);
    return 1;
}

int CombatMovementControllerBinding::checkWeDontCollideWithCharacters(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    Ogre::Vector3 newpos;
    readVector3(L, 3, newpos);
    b->checkWeDontCollideWithCharacters(pos, newpos);
    return 0;
}

int CombatMovementControllerBinding::checkCharacterCollision(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    Ogre::Vector3 movement;
    readVector3(L, 3, movement);
    bool result = b->checkCharacterCollision(pos, movement);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatMovementControllerBinding::setForcedWP(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");

    Ogre::Vector3 v;
    readVector3(L, 2, v);
    b->setForcedWP(v);
    return 0;
}

int CombatMovementControllerBinding::disable(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");

    b->disable();
    return 0;
}

int CombatMovementControllerBinding::_DESTRUCTOR(lua_State* L)
{
    CombatMovementController* b = getB(L, 1);
    if (!b) return luaL_error(L, "CombatMovementController is nil");

    b->_DESTRUCTOR();
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
  line 307: void getGUIData(...) - unsupported arg type
  line 310: void combatMovementOffensive(...) - unsupported arg type
  line 327: void combatMovementAnimationUpdate(...) - unsupported arg type
*/

int CombatMovementControllerBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int CombatMovementControllerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CombatMovementController object");
    return 1;
}

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
        { "getUrgentVelocities", CombatMovementControllerBinding::getUrgentVelocities },
        { "checkWeDontCollideWithCharacters", CombatMovementControllerBinding::checkWeDontCollideWithCharacters },
        { "checkCharacterCollision", CombatMovementControllerBinding::checkCharacterCollision },
        { "setForcedWP", CombatMovementControllerBinding::setForcedWP },
        { "disable", CombatMovementControllerBinding::disable },
        { "_DESTRUCTOR", CombatMovementControllerBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        CombatMovementControllerBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CombatMovementControllerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, CombatMovementController_get_characterCollisions);
    lua_setfield(L, -2, "characterCollisions");
    lua_pushcfunction(L, CombatMovementController_get_movement);
    lua_setfield(L, -2, "movement");
    lua_pushcfunction(L, CombatMovementController_get_chaseMode);
    lua_setfield(L, -2, "chaseMode");
    lua_pushcfunction(L, CombatMovementController_get_chaseStateTimer);
    lua_setfield(L, -2, "chaseStateTimer");
    lua_pushcfunction(L, CombatMovementController_get_hasForcedWP);
    lua_setfield(L, -2, "hasForcedWP");
    lua_pushcfunction(L, CombatMovementController_get_forcedWP);
    lua_setfield(L, -2, "forcedWP");
    lua_pushcfunction(L, CombatMovementController_get_flockFilterX);
    lua_setfield(L, -2, "flockFilterX");
    lua_pushcfunction(L, CombatMovementController_get_flockFilterZ);
    lua_setfield(L, -2, "flockFilterZ");
    lua_pushcfunction(L, CombatMovementController_get_flockingControl);
    lua_setfield(L, -2, "flockingControl");
    lua_pushcfunction(L, CombatMovementController_get_stats);
    lua_setfield(L, -2, "stats");
    lua_pushcfunction(L, CombatMovementController_get_radius);
    lua_setfield(L, -2, "radius");
    lua_pushcfunction(L, CombatMovementController_get_jogMode);
    lua_setfield(L, -2, "jogMode");
    lua_pushcfunction(L, CombatMovementController_get_TOTALREPULSION_DAMPING);
    lua_setfield(L, -2, "TOTALREPULSION_DAMPING");
    lua_pushcfunction(L, CombatMovementController_get_STRAFE_STATE_DAMPING);
    lua_setfield(L, -2, "STRAFE_STATE_DAMPING");
    lua_pushcfunction(L, CombatMovementController_get_STRAFE_THRESHOLD);
    lua_setfield(L, -2, "STRAFE_THRESHOLD");
    lua_pushcfunction(L, CombatMovementController_get_FORWARD_THRESHOLD);
    lua_setfield(L, -2, "FORWARD_THRESHOLD");
    lua_pushcfunction(L, CombatMovementController_get_MIN_RANGE_FW);
    lua_setfield(L, -2, "MIN_RANGE_FW");
    lua_pushcfunction(L, CombatMovementController_get_ENEMY_DIST);
    lua_setfield(L, -2, "ENEMY_DIST");
    lua_pushcfunction(L, CombatMovementController_get_ALLY_DIST);
    lua_setfield(L, -2, "ALLY_DIST");
    lua_pushcfunction(L, CombatMovementController_get_STOP_THRESHOLD);
    lua_setfield(L, -2, "STOP_THRESHOLD");
    lua_pushcfunction(L, CombatMovementController_get_START_THRESHOLD);
    lua_setfield(L, -2, "START_THRESHOLD");
    lua_pushcfunction(L, CombatMovementController_get_ACCEL_RATE_COMBATMODE);
    lua_setfield(L, -2, "ACCEL_RATE_COMBATMODE");
    lua_pushcfunction(L, CombatMovementController_get_meiMin);
    lua_setfield(L, -2, "meiMin");
    lua_pushcfunction(L, CombatMovementController_get_circlingSpeed);
    lua_setfield(L, -2, "circlingSpeed");
    lua_pushcfunction(L, CombatMovementController_get_combatMinDistance);
    lua_setfield(L, -2, "combatMinDistance");
    lua_pushcfunction(L, CombatMovementController_get_combatMaxDistance);
    lua_setfield(L, -2, "combatMaxDistance");
    lua_pushcfunction(L, CombatMovementController_get_strafeStateTimer);
    lua_setfield(L, -2, "strafeStateTimer");
    lua_pushcfunction(L, CombatMovementController_get_strafing);
    lua_setfield(L, -2, "strafing");
    lua_pushcfunction(L, CombatMovementController_get_powerThrough);
    lua_setfield(L, -2, "powerThrough");
    lua_pushcfunction(L, CombatMovementController_get_canStrafe);
    lua_setfield(L, -2, "canStrafe");
    lua_pushcfunction(L, CombatMovementController_get_speedLimit);
    lua_setfield(L, -2, "speedLimit");
    lua_pushcfunction(L, CombatMovementController_get_currentAccelSpeed);
    lua_setfield(L, -2, "currentAccelSpeed");
    lua_pushcfunction(L, CombatMovementController_get_lookAtCharacter);
    lua_setfield(L, -2, "lookAtCharacter");
    lua_pushcfunction(L, CombatMovementController_get_combatTarget);
    lua_setfield(L, -2, "combatTarget");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, CombatMovementController_set_characterCollisions);
    lua_setfield(L, -2, "characterCollisions");
    lua_pushcfunction(L, CombatMovementController_set_movement);
    lua_setfield(L, -2, "movement");
    lua_pushcfunction(L, CombatMovementController_set_chaseMode);
    lua_setfield(L, -2, "chaseMode");
    lua_pushcfunction(L, CombatMovementController_set_chaseStateTimer);
    lua_setfield(L, -2, "chaseStateTimer");
    lua_pushcfunction(L, CombatMovementController_set_hasForcedWP);
    lua_setfield(L, -2, "hasForcedWP");
    lua_pushcfunction(L, CombatMovementController_set_forcedWP);
    lua_setfield(L, -2, "forcedWP");
    lua_pushcfunction(L, CombatMovementController_set_flockFilterX);
    lua_setfield(L, -2, "flockFilterX");
    lua_pushcfunction(L, CombatMovementController_set_flockFilterZ);
    lua_setfield(L, -2, "flockFilterZ");
    lua_pushcfunction(L, CombatMovementController_set_flockingControl);
    lua_setfield(L, -2, "flockingControl");
    lua_pushcfunction(L, CombatMovementController_set_stats);
    lua_setfield(L, -2, "stats");
    lua_pushcfunction(L, CombatMovementController_set_radius);
    lua_setfield(L, -2, "radius");
    lua_pushcfunction(L, CombatMovementController_set_jogMode);
    lua_setfield(L, -2, "jogMode");
    lua_pushcfunction(L, CombatMovementController_set_TOTALREPULSION_DAMPING);
    lua_setfield(L, -2, "TOTALREPULSION_DAMPING");
    lua_pushcfunction(L, CombatMovementController_set_STRAFE_STATE_DAMPING);
    lua_setfield(L, -2, "STRAFE_STATE_DAMPING");
    lua_pushcfunction(L, CombatMovementController_set_STRAFE_THRESHOLD);
    lua_setfield(L, -2, "STRAFE_THRESHOLD");
    lua_pushcfunction(L, CombatMovementController_set_FORWARD_THRESHOLD);
    lua_setfield(L, -2, "FORWARD_THRESHOLD");
    lua_pushcfunction(L, CombatMovementController_set_MIN_RANGE_FW);
    lua_setfield(L, -2, "MIN_RANGE_FW");
    lua_pushcfunction(L, CombatMovementController_set_ENEMY_DIST);
    lua_setfield(L, -2, "ENEMY_DIST");
    lua_pushcfunction(L, CombatMovementController_set_ALLY_DIST);
    lua_setfield(L, -2, "ALLY_DIST");
    lua_pushcfunction(L, CombatMovementController_set_STOP_THRESHOLD);
    lua_setfield(L, -2, "STOP_THRESHOLD");
    lua_pushcfunction(L, CombatMovementController_set_START_THRESHOLD);
    lua_setfield(L, -2, "START_THRESHOLD");
    lua_pushcfunction(L, CombatMovementController_set_ACCEL_RATE_COMBATMODE);
    lua_setfield(L, -2, "ACCEL_RATE_COMBATMODE");
    lua_pushcfunction(L, CombatMovementController_set_meiMin);
    lua_setfield(L, -2, "meiMin");
    lua_pushcfunction(L, CombatMovementController_set_circlingSpeed);
    lua_setfield(L, -2, "circlingSpeed");
    lua_pushcfunction(L, CombatMovementController_set_combatMinDistance);
    lua_setfield(L, -2, "combatMinDistance");
    lua_pushcfunction(L, CombatMovementController_set_combatMaxDistance);
    lua_setfield(L, -2, "combatMaxDistance");
    lua_pushcfunction(L, CombatMovementController_set_strafeStateTimer);
    lua_setfield(L, -2, "strafeStateTimer");
    lua_pushcfunction(L, CombatMovementController_set_strafing);
    lua_setfield(L, -2, "strafing");
    lua_pushcfunction(L, CombatMovementController_set_powerThrough);
    lua_setfield(L, -2, "powerThrough");
    lua_pushcfunction(L, CombatMovementController_set_canStrafe);
    lua_setfield(L, -2, "canStrafe");
    lua_pushcfunction(L, CombatMovementController_set_speedLimit);
    lua_setfield(L, -2, "speedLimit");
    lua_pushcfunction(L, CombatMovementController_set_currentAccelSpeed);
    lua_setfield(L, -2, "currentAccelSpeed");
    lua_pushcfunction(L, CombatMovementController_set_lookAtCharacter);
    lua_setfield(L, -2, "lookAtCharacter");
    lua_pushcfunction(L, CombatMovementController_set_combatTarget);
    lua_setfield(L, -2, "combatTarget");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua