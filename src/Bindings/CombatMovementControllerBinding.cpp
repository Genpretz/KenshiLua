#include "pch.h"
#include "kenshi\CharMovement.h"
#include "CombatMovementControllerBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharMovementBinding.h"
#include "Bindings/CharStatsBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/FlockingToolsBinding.h"
#include "Bindings/MotionFilterBinding.h"

namespace KenshiLua
{

static CombatMovementController* getInstance(lua_State* L, int idx)
{
    return checkObject<CombatMovementController>(L, idx, CombatMovementControllerBinding::getMetatableName());
}

// --- Getters for CombatMovementController ---
static int CombatMovementController_get_movement(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    return pushObject<CharMovement>(L, instance->movement, CharMovementBinding::getMetatableName());
}

static int CombatMovementController_get_chaseMode(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushboolean(L, instance->chaseMode ? 1 : 0);
    return 1;
}

static int CombatMovementController_get_chaseStateTimer(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, instance->chaseStateTimer);
    return 1;
}

static int CombatMovementController_get_hasForcedWP(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushboolean(L, instance->hasForcedWP ? 1 : 0);
    return 1;
}

static int CombatMovementController_get_forcedWP(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    pushVector3(L, instance->forcedWP);
    return 1;
}

static int CombatMovementController_get_flockFilterX(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    return pushObject<MotionFilter>(L, &instance->flockFilterX, MotionFilterBinding::getMetatableName());
}

static int CombatMovementController_get_flockFilterZ(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    return pushObject<MotionFilter>(L, &instance->flockFilterZ, MotionFilterBinding::getMetatableName());
}

static int CombatMovementController_get_flockingControl(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    return pushObject<FlockingTools>(L, instance->flockingControl, FlockingToolsBinding::getMetatableName());
}

static int CombatMovementController_get_stats(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    return pushObject<CharStats>(L, instance->stats, CharStatsBinding::getMetatableName());
}

static int CombatMovementController_get_radius(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, instance->radius);
    return 1;
}

static int CombatMovementController_get_jogMode(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushboolean(L, instance->jogMode ? 1 : 0);
    return 1;
}

static int CombatMovementController_get_TOTALREPULSION_DAMPING(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, instance->TOTALREPULSION_DAMPING);
    return 1;
}

static int CombatMovementController_get_STRAFE_STATE_DAMPING(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, instance->STRAFE_STATE_DAMPING);
    return 1;
}

static int CombatMovementController_get_STRAFE_THRESHOLD(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, instance->STRAFE_THRESHOLD);
    return 1;
}

static int CombatMovementController_get_FORWARD_THRESHOLD(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, instance->FORWARD_THRESHOLD);
    return 1;
}

static int CombatMovementController_get_MIN_RANGE_FW(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, instance->MIN_RANGE_FW);
    return 1;
}

static int CombatMovementController_get_ENEMY_DIST(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, instance->ENEMY_DIST);
    return 1;
}

static int CombatMovementController_get_ALLY_DIST(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, instance->ALLY_DIST);
    return 1;
}

static int CombatMovementController_get_STOP_THRESHOLD(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, instance->STOP_THRESHOLD);
    return 1;
}

static int CombatMovementController_get_START_THRESHOLD(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, instance->START_THRESHOLD);
    return 1;
}

static int CombatMovementController_get_ACCEL_RATE_COMBATMODE(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, instance->ACCEL_RATE_COMBATMODE);
    return 1;
}

static int CombatMovementController_get_meiMin(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, instance->meiMin);
    return 1;
}

static int CombatMovementController_get_circlingSpeed(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, instance->circlingSpeed);
    return 1;
}

static int CombatMovementController_get_combatMinDistance(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, instance->combatMinDistance);
    return 1;
}

static int CombatMovementController_get_combatMaxDistance(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, instance->combatMaxDistance);
    return 1;
}

static int CombatMovementController_get_strafeStateTimer(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, instance->strafeStateTimer);
    return 1;
}

static int CombatMovementController_get_strafing(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushboolean(L, instance->strafing ? 1 : 0);
    return 1;
}

static int CombatMovementController_get_powerThrough(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushboolean(L, instance->powerThrough ? 1 : 0);
    return 1;
}

static int CombatMovementController_get_canStrafe(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushboolean(L, instance->canStrafe ? 1 : 0);
    return 1;
}

static int CombatMovementController_get_speedLimit(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, instance->speedLimit);
    return 1;
}

static int CombatMovementController_get_currentAccelSpeed(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    lua_pushnumber(L, instance->currentAccelSpeed);
    return 1;
}

static int CombatMovementController_get_lookAtCharacter(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    return HandBinding::push(L, instance->lookAtCharacter);
}

static int CombatMovementController_get_combatTarget(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    return HandBinding::push(L, instance->combatTarget);
}

// --- Setters for CombatMovementController ---
static int CombatMovementController_set_movement(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->movement = lua_isnoneornil(L, 2) ? nullptr : checkObject<CharMovement>(L, 2, CharMovementBinding::getMetatableName());
    return 0;
}

static int CombatMovementController_set_chaseMode(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->chaseMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatMovementController_set_chaseStateTimer(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->chaseStateTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_hasForcedWP(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->hasForcedWP = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatMovementController_set_forcedWP(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    readVector3(L, 2, instance->forcedWP);
    return 0;
}

static int CombatMovementController_set_flockFilterX(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->flockFilterX = *checkObject<MotionFilter>(L, 2, MotionFilterBinding::getMetatableName());
    return 0;
}

static int CombatMovementController_set_flockFilterZ(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->flockFilterZ = *checkObject<MotionFilter>(L, 2, MotionFilterBinding::getMetatableName());
    return 0;
}

static int CombatMovementController_set_flockingControl(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->flockingControl = lua_isnoneornil(L, 2) ? nullptr : checkObject<FlockingTools>(L, 2, FlockingToolsBinding::getMetatableName());
    return 0;
}

static int CombatMovementController_set_stats(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->stats = lua_isnoneornil(L, 2) ? nullptr : checkObject<CharStats>(L, 2, CharStatsBinding::getMetatableName());
    return 0;
}

static int CombatMovementController_set_radius(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->radius = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_jogMode(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->jogMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatMovementController_set_TOTALREPULSION_DAMPING(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->TOTALREPULSION_DAMPING = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_STRAFE_STATE_DAMPING(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->STRAFE_STATE_DAMPING = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_STRAFE_THRESHOLD(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->STRAFE_THRESHOLD = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_FORWARD_THRESHOLD(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->FORWARD_THRESHOLD = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_MIN_RANGE_FW(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->MIN_RANGE_FW = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_ENEMY_DIST(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->ENEMY_DIST = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_ALLY_DIST(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->ALLY_DIST = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_STOP_THRESHOLD(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->STOP_THRESHOLD = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_START_THRESHOLD(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->START_THRESHOLD = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_ACCEL_RATE_COMBATMODE(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->ACCEL_RATE_COMBATMODE = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_meiMin(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->meiMin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_circlingSpeed(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->circlingSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_combatMinDistance(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->combatMinDistance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_combatMaxDistance(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->combatMaxDistance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_strafeStateTimer(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->strafeStateTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_strafing(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->strafing = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatMovementController_set_powerThrough(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->powerThrough = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatMovementController_set_canStrafe(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->canStrafe = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatMovementController_set_speedLimit(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->speedLimit = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_currentAccelSpeed(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->currentAccelSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatMovementController_set_lookAtCharacter(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->lookAtCharacter = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int CombatMovementController_set_combatTarget(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");
    instance->combatTarget = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

int CombatMovementControllerBinding::_CONSTRUCTOR(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");

    CombatMovementController* result = instance->_CONSTRUCTOR();
    return pushObject<CombatMovementController>(L, result, CombatMovementControllerBinding::getMetatableName());
}

int CombatMovementControllerBinding::collisionUpdate(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->collisionUpdate(time);
    return 0;
}

int CombatMovementControllerBinding::chasingModeCheck(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");

    Character* whoTarget = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->chasingModeCheck(whoTarget);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatMovementControllerBinding::create(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");

    FlockingTools* flock = checkObject<FlockingTools>(L, 2, FlockingToolsBinding::getMetatableName());
    CharMovement* move = checkObject<CharMovement>(L, 3, CharMovementBinding::getMetatableName());
    CharStats* med = checkObject<CharStats>(L, 4, CharStatsBinding::getMetatableName());
    bool strafe = lua_toboolean(L, 5) != 0;
    instance->create(flock, move, med, strafe);
    return 0;
}

int CombatMovementControllerBinding::areTherePeopleInMyWay(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");

    bool result = instance->areTherePeopleInMyWay();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatMovementControllerBinding::addACharacterObstruction(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->addACharacterObstruction(c);
    return 0;
}

int CombatMovementControllerBinding::setupCombatMovementVariables(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");

    Character* me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->setupCombatMovementVariables(me);
    return 0;
}

int CombatMovementControllerBinding::combatMovementUpdate(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");

    float frametime = (float)luaL_checknumber(L, 2);
    Ogre::Vector3 currentPos;
    readVector3(L, 3, currentPos);
    Ogre::Vector3 currentDirIn;
    readVector3(L, 4, currentDirIn);
    bool isCurrentlyMoving = lua_toboolean(L, 5) != 0;
    Ogre::Vector3 repulsionVector;
    readVector3(L, 6, repulsionVector);
    Ogre::Vector3 facingDirOut;
    readVector3(L, 7, facingDirOut);
    bool defensive = lua_toboolean(L, 8) != 0;
    swordStateEnum combatState = (swordStateEnum)luaL_checkinteger(L, 9);
    float raceSpeedMult = (float)luaL_checknumber(L, 10);
    instance->combatMovementUpdate(frametime, currentPos, currentDirIn, isCurrentlyMoving, repulsionVector, facingDirOut, defensive, combatState, raceSpeedMult);
    return 0;
}

int CombatMovementControllerBinding::combatMovementUpdate_crippleMode(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");

    float frametime = (float)luaL_checknumber(L, 2);
    Ogre::Vector3 currentPos;
    readVector3(L, 3, currentPos);
    Ogre::Vector3 currentDirIn;
    readVector3(L, 4, currentDirIn);
    bool isCurrentlyMoving = lua_toboolean(L, 5) != 0;
    Ogre::Vector3 repulsionVector;
    readVector3(L, 6, repulsionVector);
    Ogre::Vector3 facingDirOut;
    readVector3(L, 7, facingDirOut);
    bool defensive = lua_toboolean(L, 8) != 0;
    swordStateEnum combatState = (swordStateEnum)luaL_checkinteger(L, 9);
    float raceSpeedMult = (float)luaL_checknumber(L, 10);
    instance->combatMovementUpdate_crippleMode(frametime, currentPos, currentDirIn, isCurrentlyMoving, repulsionVector, facingDirOut, defensive, combatState, raceSpeedMult);
    return 0;
}

int CombatMovementControllerBinding::getUrgentVelocities(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    Ogre::Vector3 facingDir;
    readVector3(L, 3, facingDir);
    Ogre::Vector3 result = instance->getUrgentVelocities(pos, facingDir);
    pushVector3(L, result);
    return 1;
}

int CombatMovementControllerBinding::checkWeDontCollideWithCharacters(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    Ogre::Vector3 newpos;
    readVector3(L, 3, newpos);
    instance->checkWeDontCollideWithCharacters(pos, newpos);
    return 0;
}

int CombatMovementControllerBinding::checkCharacterCollision(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    Ogre::Vector3 movement;
    readVector3(L, 3, movement);
    bool result = instance->checkCharacterCollision(pos, movement);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatMovementControllerBinding::setForcedWP(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");

    Ogre::Vector3 v;
    readVector3(L, 2, v);
    instance->setForcedWP(v);
    return 0;
}

int CombatMovementControllerBinding::getGUIData(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");

    DatapanelGUI* panel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIData(panel, category);
    return 0;
}

int CombatMovementControllerBinding::disable(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");

    instance->disable();
    return 0;
}

int CombatMovementControllerBinding::_DESTRUCTOR(lua_State* L)
{
    CombatMovementController* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatMovementController is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 310: void combatMovementOffensive(...) - non-string reference arg
  line 327: void combatMovementAnimationUpdate(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 289: characterCollisions (ogre_unordered_map<hand, float>::type) - unsupported type
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
        { "_CONSTRUCTOR", CombatMovementControllerBinding::_CONSTRUCTOR },
        { "collisionUpdate", CombatMovementControllerBinding::collisionUpdate },
        { "chasingModeCheck", CombatMovementControllerBinding::chasingModeCheck },
        { "create", CombatMovementControllerBinding::create },
        { "areTherePeopleInMyWay", CombatMovementControllerBinding::areTherePeopleInMyWay },
        { "addACharacterObstruction", CombatMovementControllerBinding::addACharacterObstruction },
        { "setupCombatMovementVariables", CombatMovementControllerBinding::setupCombatMovementVariables },
        { "combatMovementUpdate", CombatMovementControllerBinding::combatMovementUpdate },
        { "combatMovementUpdate_crippleMode", CombatMovementControllerBinding::combatMovementUpdate_crippleMode },
        { "getUrgentVelocities", CombatMovementControllerBinding::getUrgentVelocities },
        { "checkWeDontCollideWithCharacters", CombatMovementControllerBinding::checkWeDontCollideWithCharacters },
        { "checkCharacterCollision", CombatMovementControllerBinding::checkCharacterCollision },
        { "setForcedWP", CombatMovementControllerBinding::setForcedWP },
        { "getGUIData", CombatMovementControllerBinding::getGUIData },
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
    registerGetter(L, "movement", CombatMovementController_get_movement);
    registerGetter(L, "chaseMode", CombatMovementController_get_chaseMode);
    registerGetter(L, "chaseStateTimer", CombatMovementController_get_chaseStateTimer);
    registerGetter(L, "hasForcedWP", CombatMovementController_get_hasForcedWP);
    registerGetter(L, "forcedWP", CombatMovementController_get_forcedWP);
    registerGetter(L, "flockFilterX", CombatMovementController_get_flockFilterX);
    registerGetter(L, "flockFilterZ", CombatMovementController_get_flockFilterZ);
    registerGetter(L, "flockingControl", CombatMovementController_get_flockingControl);
    registerGetter(L, "stats", CombatMovementController_get_stats);
    registerGetter(L, "radius", CombatMovementController_get_radius);
    registerGetter(L, "jogMode", CombatMovementController_get_jogMode);
    registerGetter(L, "TOTALREPULSION_DAMPING", CombatMovementController_get_TOTALREPULSION_DAMPING);
    registerGetter(L, "STRAFE_STATE_DAMPING", CombatMovementController_get_STRAFE_STATE_DAMPING);
    registerGetter(L, "STRAFE_THRESHOLD", CombatMovementController_get_STRAFE_THRESHOLD);
    registerGetter(L, "FORWARD_THRESHOLD", CombatMovementController_get_FORWARD_THRESHOLD);
    registerGetter(L, "MIN_RANGE_FW", CombatMovementController_get_MIN_RANGE_FW);
    registerGetter(L, "ENEMY_DIST", CombatMovementController_get_ENEMY_DIST);
    registerGetter(L, "ALLY_DIST", CombatMovementController_get_ALLY_DIST);
    registerGetter(L, "STOP_THRESHOLD", CombatMovementController_get_STOP_THRESHOLD);
    registerGetter(L, "START_THRESHOLD", CombatMovementController_get_START_THRESHOLD);
    registerGetter(L, "ACCEL_RATE_COMBATMODE", CombatMovementController_get_ACCEL_RATE_COMBATMODE);
    registerGetter(L, "meiMin", CombatMovementController_get_meiMin);
    registerGetter(L, "circlingSpeed", CombatMovementController_get_circlingSpeed);
    registerGetter(L, "combatMinDistance", CombatMovementController_get_combatMinDistance);
    registerGetter(L, "combatMaxDistance", CombatMovementController_get_combatMaxDistance);
    registerGetter(L, "strafeStateTimer", CombatMovementController_get_strafeStateTimer);
    registerGetter(L, "strafing", CombatMovementController_get_strafing);
    registerGetter(L, "powerThrough", CombatMovementController_get_powerThrough);
    registerGetter(L, "canStrafe", CombatMovementController_get_canStrafe);
    registerGetter(L, "speedLimit", CombatMovementController_get_speedLimit);
    registerGetter(L, "currentAccelSpeed", CombatMovementController_get_currentAccelSpeed);
    registerGetter(L, "lookAtCharacter", CombatMovementController_get_lookAtCharacter);
    registerGetter(L, "combatTarget", CombatMovementController_get_combatTarget);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "movement", CombatMovementController_set_movement);
    registerSetter(L, "chaseMode", CombatMovementController_set_chaseMode);
    registerSetter(L, "chaseStateTimer", CombatMovementController_set_chaseStateTimer);
    registerSetter(L, "hasForcedWP", CombatMovementController_set_hasForcedWP);
    registerSetter(L, "forcedWP", CombatMovementController_set_forcedWP);
    registerSetter(L, "flockFilterX", CombatMovementController_set_flockFilterX);
    registerSetter(L, "flockFilterZ", CombatMovementController_set_flockFilterZ);
    registerSetter(L, "flockingControl", CombatMovementController_set_flockingControl);
    registerSetter(L, "stats", CombatMovementController_set_stats);
    registerSetter(L, "radius", CombatMovementController_set_radius);
    registerSetter(L, "jogMode", CombatMovementController_set_jogMode);
    registerSetter(L, "TOTALREPULSION_DAMPING", CombatMovementController_set_TOTALREPULSION_DAMPING);
    registerSetter(L, "STRAFE_STATE_DAMPING", CombatMovementController_set_STRAFE_STATE_DAMPING);
    registerSetter(L, "STRAFE_THRESHOLD", CombatMovementController_set_STRAFE_THRESHOLD);
    registerSetter(L, "FORWARD_THRESHOLD", CombatMovementController_set_FORWARD_THRESHOLD);
    registerSetter(L, "MIN_RANGE_FW", CombatMovementController_set_MIN_RANGE_FW);
    registerSetter(L, "ENEMY_DIST", CombatMovementController_set_ENEMY_DIST);
    registerSetter(L, "ALLY_DIST", CombatMovementController_set_ALLY_DIST);
    registerSetter(L, "STOP_THRESHOLD", CombatMovementController_set_STOP_THRESHOLD);
    registerSetter(L, "START_THRESHOLD", CombatMovementController_set_START_THRESHOLD);
    registerSetter(L, "ACCEL_RATE_COMBATMODE", CombatMovementController_set_ACCEL_RATE_COMBATMODE);
    registerSetter(L, "meiMin", CombatMovementController_set_meiMin);
    registerSetter(L, "circlingSpeed", CombatMovementController_set_circlingSpeed);
    registerSetter(L, "combatMinDistance", CombatMovementController_set_combatMinDistance);
    registerSetter(L, "combatMaxDistance", CombatMovementController_set_combatMaxDistance);
    registerSetter(L, "strafeStateTimer", CombatMovementController_set_strafeStateTimer);
    registerSetter(L, "strafing", CombatMovementController_set_strafing);
    registerSetter(L, "powerThrough", CombatMovementController_set_powerThrough);
    registerSetter(L, "canStrafe", CombatMovementController_set_canStrafe);
    registerSetter(L, "speedLimit", CombatMovementController_set_speedLimit);
    registerSetter(L, "currentAccelSpeed", CombatMovementController_set_currentAccelSpeed);
    registerSetter(L, "lookAtCharacter", CombatMovementController_set_lookAtCharacter);
    registerSetter(L, "combatTarget", CombatMovementController_set_combatTarget);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua