#include "pch.h"
#include "kenshi\CharMovement.h"
#include "CharMovementBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static CharMovement* getB(lua_State* L, int idx)
{
    return checkObject<CharMovement>(L, idx, CharMovementBinding::getMetatableName());
}

// --- Getters for CharMovement ---
static int CharMovement_get_flockingVector(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    pushVector3(L, b->flockingVector);
    return 1;
}

static int CharMovement_get_combatMover(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    // TODO: Unsupported type for combatMover (CombatMovementController)
    lua_pushnil(L);
    return 1;
}

static int CharMovement_get_combatMover2(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    // TODO: Unsupported type for combatMover2 (FormationMover)
    lua_pushnil(L);
    return 1;
}

static int CharMovement_get_flockingTools(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    // TODO: Unsupported type for flockingTools (FlockingTools)
    lua_pushnil(L);
    return 1;
}

static int CharMovement_get_formation(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    // TODO: Unsupported type for formation (Formation*)
    lua_pushnil(L);
    return 1;
}

static int CharMovement_get_enemyFormation(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    // TODO: Unsupported type for enemyFormation (Formation*)
    lua_pushnil(L);
    return 1;
}

static int CharMovement_get_havokCharacter(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    // TODO: Unsupported type for havokCharacter (HavokCharacter*)
    lua_pushnil(L);
    return 1;
}

static int CharMovement_get_tracer(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    // TODO: Unsupported type for tracer (ConstantTracerT*)
    lua_pushnil(L);
    return 1;
}

static int CharMovement_get_dontEverRecreateMe(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    lua_pushboolean(L, b->dontEverRecreateMe ? 1 : 0);
    return 1;
}

static int CharMovement_get_floorGroup(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    lua_pushinteger(L, b->floorGroup);
    return 1;
}

static int CharMovement_get_building(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    // TODO: Unsupported type for building (hand)
    lua_pushnil(L);
    return 1;
}

static int CharMovement_get_initCheck(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    lua_pushboolean(L, b->initCheck ? 1 : 0);
    return 1;
}

static int CharMovement_get__combatMoveSpeedMult(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    lua_pushnumber(L, b->_combatMoveSpeedMult);
    return 1;
}

static int CharMovement_get_destinationLoaded(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    lua_pushboolean(L, b->destinationLoaded ? 1 : 0);
    return 1;
}

static int CharMovement_get_footprintRadius(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    lua_pushnumber(L, b->footprintRadius);
    return 1;
}

static int CharMovement_get_edgeTarget(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    lua_pushinteger(L, b->edgeTarget);
    return 1;
}

static int CharMovement_get__lastOffMeshCheck(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    lua_pushnumber(L, b->_lastOffMeshCheck);
    return 1;
}

static int CharMovement_get_movingToEdge(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    lua_pushboolean(L, b->movingToEdge ? 1 : 0);
    return 1;
}

static int CharMovement_get_lastStepTime(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    lua_pushnumber(L, b->lastStepTime);
    return 1;
}

static int CharMovement_get_movementMode(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    // TODO: Unsupported type for movementMode (MovementMode)
    lua_pushnil(L);
    return 1;
}

static int CharMovement_get_animationOverride(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    lua_pushboolean(L, b->animationOverride ? 1 : 0);
    return 1;
}

static int CharMovement_get_trackingAnimRelocationVector(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    pushVector3(L, b->trackingAnimRelocationVector);
    return 1;
}

static int CharMovement_get_desiredMotion(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    pushVector3(L, b->desiredMotion);
    return 1;
}

static int CharMovement_get_moveLimit(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    lua_pushnumber(L, b->moveLimit);
    return 1;
}

static int CharMovement_get_animation(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    // TODO: Unsupported type for animation (AnimationClass*)
    lua_pushnil(L);
    return 1;
}

static int CharMovement_get_character(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    return pushObject<Character>(L, b->character, CharacterBinding::getMetatableName());
}

static int CharMovement_get_clickHull(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    // TODO: Unsupported type for clickHull (PhysicsHullT*)
    lua_pushnil(L);
    return 1;
}

// --- Setters for CharMovement ---
static int CharMovement_set_flockingVector(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    readVector3(L, 2, b->flockingVector);
    return 0;
}

static int CharMovement_set_combatMover(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    return luaL_error(L, "Read-only or unsupported setter type for combatMover");
}

static int CharMovement_set_combatMover2(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    return luaL_error(L, "Read-only or unsupported setter type for combatMover2");
}

static int CharMovement_set_flockingTools(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    return luaL_error(L, "Read-only or unsupported setter type for flockingTools");
}

static int CharMovement_set_formation(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    return luaL_error(L, "Read-only or unsupported setter type for formation");
}

static int CharMovement_set_enemyFormation(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    return luaL_error(L, "Read-only or unsupported setter type for enemyFormation");
}

static int CharMovement_set_havokCharacter(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    return luaL_error(L, "Read-only or unsupported setter type for havokCharacter");
}

static int CharMovement_set_tracer(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    return luaL_error(L, "Read-only or unsupported setter type for tracer");
}

static int CharMovement_set_dontEverRecreateMe(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    b->dontEverRecreateMe = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharMovement_set_floorGroup(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    b->floorGroup = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CharMovement_set_building(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    return luaL_error(L, "Read-only or unsupported setter type for building");
}

static int CharMovement_set_initCheck(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    b->initCheck = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharMovement_set__combatMoveSpeedMult(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    b->_combatMoveSpeedMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharMovement_set_destinationLoaded(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    b->destinationLoaded = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharMovement_set_footprintRadius(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    b->footprintRadius = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharMovement_set_edgeTarget(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    b->edgeTarget = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CharMovement_set__lastOffMeshCheck(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    b->_lastOffMeshCheck = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharMovement_set_movingToEdge(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    b->movingToEdge = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharMovement_set_lastStepTime(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    b->lastStepTime = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharMovement_set_movementMode(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    return luaL_error(L, "Read-only or unsupported setter type for movementMode");
}

static int CharMovement_set_animationOverride(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    b->animationOverride = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharMovement_set_trackingAnimRelocationVector(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    readVector3(L, 2, b->trackingAnimRelocationVector);
    return 0;
}

static int CharMovement_set_desiredMotion(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    readVector3(L, 2, b->desiredMotion);
    return 0;
}

static int CharMovement_set_moveLimit(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    b->moveLimit = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharMovement_set_animation(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    return luaL_error(L, "Read-only or unsupported setter type for animation");
}

static int CharMovement_set_character(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    return luaL_error(L, "Read-only or unsupported setter type for character");
}

static int CharMovement_set_clickHull(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");
    return luaL_error(L, "Read-only or unsupported setter type for clickHull");
}

int CharMovementBinding::_DESTRUCTOR(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    b->_DESTRUCTOR();
    return 0;
}

int CharMovementBinding::_setPositionAndTeleport(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    int floor = (int)luaL_checkinteger(L, 3);
    b->_setPositionAndTeleport(p, floor);
    return 0;
}

int CharMovementBinding::_NV__setPositionAndTeleport(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    int floor = (int)luaL_checkinteger(L, 3);
    b->_NV__setPositionAndTeleport(p, floor);
    return 0;
}

int CharMovementBinding::_setPositionDirectionAndTeleport(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 position;
    readVector3(L, 2, position);
    Ogre::Quaternion orientation;
    readQuaternion(L, 3, orientation);
    b->_setPositionDirectionAndTeleport(position, orientation);
    return 0;
}

int CharMovementBinding::_NV__setPositionDirectionAndTeleport(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 position;
    readVector3(L, 2, position);
    Ogre::Quaternion orientation;
    readQuaternion(L, 3, orientation);
    b->_NV__setPositionDirectionAndTeleport(position, orientation);
    return 0;
}

int CharMovementBinding::_setPositionSimple(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    b->_setPositionSimple(p);
    return 0;
}

int CharMovementBinding::_NV__setPositionSimple(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    b->_NV__setPositionSimple(p);
    return 0;
}

int CharMovementBinding::isRunning(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    bool result = b->isRunning();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::isRunningAway(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 from;
    readVector3(L, 2, from);
    bool result = b->isRunningAway(from);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::trackAnimationMovement(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->trackAnimationMovement(on);
    return 0;
}

int CharMovementBinding::handleChanged(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    b->handleChanged();
    return 0;
}

int CharMovementBinding::_NV_handleChanged(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    b->_NV_handleChanged();
    return 0;
}

int CharMovementBinding::getRadius(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    float result = b->getRadius();
    lua_pushnumber(L, result);
    return 1;
}

int CharMovementBinding::update(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    float _TIME = (float)luaL_checknumber(L, 2);
    b->update(_TIME);
    return 0;
}

int CharMovementBinding::_NV_update(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    float _TIME = (float)luaL_checknumber(L, 2);
    b->_NV_update(_TIME);
    return 0;
}

int CharMovementBinding::pausedUpdate(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    b->pausedUpdate();
    return 0;
}

int CharMovementBinding::twoFrameUpdate(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    float _TIME = (float)luaL_checknumber(L, 2);
    b->twoFrameUpdate(_TIME);
    return 0;
}

int CharMovementBinding::postAnimationUpdate(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    b->postAnimationUpdate();
    return 0;
}

int CharMovementBinding::periodicUpdate(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    float time = (float)luaL_checknumber(L, 2);
    b->periodicUpdate(time);
    return 0;
}

int CharMovementBinding::predictNextPosition(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    bool accurate = lua_toboolean(L, 2) != 0;
    Ogre::Vector3 result = b->predictNextPosition(accurate);
    pushVector3(L, result);
    return 1;
}

int CharMovementBinding::getMaximumPossibleMovement(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    float result = b->getMaximumPossibleMovement();
    lua_pushnumber(L, result);
    return 1;
}

int CharMovementBinding::faceDirection(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 dir;
    readVector3(L, 2, dir);
    b->faceDirection(dir);
    return 0;
}

int CharMovementBinding::_NV_faceDirection(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 dir;
    readVector3(L, 2, dir);
    b->_NV_faceDirection(dir);
    return 0;
}

int CharMovementBinding::lookatPosition(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    b->lookatPosition(pos);
    return 0;
}

int CharMovementBinding::_NV_lookatPosition(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    b->_NV_lookatPosition(pos);
    return 0;
}

int CharMovementBinding::pathOk(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    bool result = b->pathOk();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::_NV_pathOk(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    bool result = b->_NV_pathOk();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::pathFailed(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    bool result = b->pathFailed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::_NV_pathFailed(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    bool result = b->_NV_pathFailed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::isDestinationReached(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    bool result = b->isDestinationReached();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::_NV_isDestinationReached(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    bool result = b->_NV_isDestinationReached();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::isIdle(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    bool result = b->isIdle();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::_NV_isIdle(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    bool result = b->_NV_isIdle();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::playerMoveOrderWhileInCombatMode(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    bool result = b->playerMoveOrderWhileInCombatMode(pos);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::_NV_playerMoveOrderWhileInCombatMode(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    bool result = b->_NV_playerMoveOrderWhileInCombatMode(pos);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::halt(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    b->halt();
    return 0;
}

int CharMovementBinding::_NV_halt(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    b->_NV_halt();
    return 0;
}

int CharMovementBinding::invalidatePath(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    b->invalidatePath();
    return 0;
}

int CharMovementBinding::movedBy(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    b->movedBy(pos);
    return 0;
}

int CharMovementBinding::isCombatMovementBlockedByCharacters(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    bool result = b->isCombatMovementBlockedByCharacters();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::destroy(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    b->destroy();
    return 0;
}

int CharMovementBinding::restore(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    b->restore();
    return 0;
}

int CharMovementBinding::refreshClickHull(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    b->refreshClickHull();
    return 0;
}

int CharMovementBinding::teleportCollisionHull(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 _pos;
    readVector3(L, 2, _pos);
    b->teleportCollisionHull(_pos);
    return 0;
}

int CharMovementBinding::getCurrentFloor(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    int result = b->getCurrentFloor();
    lua_pushinteger(L, result);
    return 1;
}

int CharMovementBinding::isIndoorsHideMeCheck(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    bool result = b->isIndoorsHideMeCheck();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::isIndoors(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    bool result = b->isIndoors();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::manualMovement(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 v;
    readVector3(L, 2, v);
    b->manualMovement(v);
    return 0;
}

int CharMovementBinding::_NV_manualMovement(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 v;
    readVector3(L, 2, v);
    b->_NV_manualMovement(v);
    return 0;
}

int CharMovementBinding::isInsideBuildingLoadedInterior(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    bool result = b->isInsideBuildingLoadedInterior();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::hasClickHull(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    bool result = b->hasClickHull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::isTrackingAnimationMode(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    bool result = b->isTrackingAnimationMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::isWaypointMoveMode(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    bool result = b->isWaypointMoveMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::setDirectMovement(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 d;
    readVector3(L, 2, d);
    float limit = (float)luaL_checknumber(L, 3);
    b->setDirectMovement(d, limit);
    return 0;
}

int CharMovementBinding::getCharacter(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    Character* result = b->getCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int CharMovementBinding::toGround(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    bool result = b->toGround();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::updateGroundMaterial(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    b->updateGroundMaterial();
    return 0;
}

int CharMovementBinding::getCombatMoveSpeedMult(lua_State* L)
{
    CharMovement* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharMovement is nil");

    float result = b->getCombatMoveSpeedMult();
    lua_pushnumber(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 387: CharMovement* _CONSTRUCTOR(...) - unsupported return type
  line 390: void create(...) - unsupported arg type
  line 391: void _NV_create(...) - unsupported arg type
  line 407: void formationUpdateCallback(...) - unsupported arg type
  line 409: hand getHandle(...) - unsupported return type
  line 410: hand _NV_getHandle(...) - unsupported return type
  line 434: const hand& isStandingOnSomething(...) - reference return type
  line 435: void setDestination(...) - overloaded method
  line 436: void _NV_setDestination(...) - overloaded method
  line 437: void setDestination(...) - overloaded method
  line 438: void _NV_setDestination(...) - overloaded method
  line 439: void setDestination(...) - overloaded method
  line 440: void _NV_setDestination(...) - overloaded method
  line 441: void setDestination(...) - overloaded method
  line 442: void _NV_setDestination(...) - overloaded method
  line 448: void setPatrolInput(...) - unsupported arg type
  line 449: void _NV_setPatrolInput(...) - unsupported arg type
  line 451: void combatMovementOffensive(...) - unsupported arg type
  line 453: void setLookatTarget(...) - unsupported arg type
  line 457: Ogre::Aabb getAABB(...) - unsupported return type
  line 469: void setMovementMode(...) - unsupported arg type
  line 471: physHit getLastGroundTraceResultMT(...) - unsupported return type
  line 473: NxControllerAction onShapeHit(...) - unsupported return type
  line 474: NxControllerAction _NV_onShapeHit(...) - unsupported return type
  line 475: NxControllerAction onControllerHit(...) - unsupported return type
  line 476: NxControllerAction _NV_onControllerHit(...) - unsupported return type
*/

int CharMovementBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int CharMovementBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CharMovement object");
    return 1;
}

void CharMovementBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CharMovementBinding::gc },
        { "__tostring", CharMovementBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", CharMovementBinding::_DESTRUCTOR },
        { "_setPositionAndTeleport", CharMovementBinding::_setPositionAndTeleport },
        { "_NV__setPositionAndTeleport", CharMovementBinding::_NV__setPositionAndTeleport },
        { "_setPositionDirectionAndTeleport", CharMovementBinding::_setPositionDirectionAndTeleport },
        { "_NV__setPositionDirectionAndTeleport", CharMovementBinding::_NV__setPositionDirectionAndTeleport },
        { "_setPositionSimple", CharMovementBinding::_setPositionSimple },
        { "_NV__setPositionSimple", CharMovementBinding::_NV__setPositionSimple },
        { "isRunning", CharMovementBinding::isRunning },
        { "isRunningAway", CharMovementBinding::isRunningAway },
        { "trackAnimationMovement", CharMovementBinding::trackAnimationMovement },
        { "handleChanged", CharMovementBinding::handleChanged },
        { "_NV_handleChanged", CharMovementBinding::_NV_handleChanged },
        { "getRadius", CharMovementBinding::getRadius },
        { "update", CharMovementBinding::update },
        { "_NV_update", CharMovementBinding::_NV_update },
        { "pausedUpdate", CharMovementBinding::pausedUpdate },
        { "twoFrameUpdate", CharMovementBinding::twoFrameUpdate },
        { "postAnimationUpdate", CharMovementBinding::postAnimationUpdate },
        { "periodicUpdate", CharMovementBinding::periodicUpdate },
        { "predictNextPosition", CharMovementBinding::predictNextPosition },
        { "getMaximumPossibleMovement", CharMovementBinding::getMaximumPossibleMovement },
        { "faceDirection", CharMovementBinding::faceDirection },
        { "_NV_faceDirection", CharMovementBinding::_NV_faceDirection },
        { "lookatPosition", CharMovementBinding::lookatPosition },
        { "_NV_lookatPosition", CharMovementBinding::_NV_lookatPosition },
        { "pathOk", CharMovementBinding::pathOk },
        { "_NV_pathOk", CharMovementBinding::_NV_pathOk },
        { "pathFailed", CharMovementBinding::pathFailed },
        { "_NV_pathFailed", CharMovementBinding::_NV_pathFailed },
        { "isDestinationReached", CharMovementBinding::isDestinationReached },
        { "_NV_isDestinationReached", CharMovementBinding::_NV_isDestinationReached },
        { "isIdle", CharMovementBinding::isIdle },
        { "_NV_isIdle", CharMovementBinding::_NV_isIdle },
        { "playerMoveOrderWhileInCombatMode", CharMovementBinding::playerMoveOrderWhileInCombatMode },
        { "_NV_playerMoveOrderWhileInCombatMode", CharMovementBinding::_NV_playerMoveOrderWhileInCombatMode },
        { "halt", CharMovementBinding::halt },
        { "_NV_halt", CharMovementBinding::_NV_halt },
        { "invalidatePath", CharMovementBinding::invalidatePath },
        { "movedBy", CharMovementBinding::movedBy },
        { "isCombatMovementBlockedByCharacters", CharMovementBinding::isCombatMovementBlockedByCharacters },
        { "destroy", CharMovementBinding::destroy },
        { "restore", CharMovementBinding::restore },
        { "refreshClickHull", CharMovementBinding::refreshClickHull },
        { "teleportCollisionHull", CharMovementBinding::teleportCollisionHull },
        { "getCurrentFloor", CharMovementBinding::getCurrentFloor },
        { "isIndoorsHideMeCheck", CharMovementBinding::isIndoorsHideMeCheck },
        { "isIndoors", CharMovementBinding::isIndoors },
        { "manualMovement", CharMovementBinding::manualMovement },
        { "_NV_manualMovement", CharMovementBinding::_NV_manualMovement },
        { "isInsideBuildingLoadedInterior", CharMovementBinding::isInsideBuildingLoadedInterior },
        { "hasClickHull", CharMovementBinding::hasClickHull },
        { "isTrackingAnimationMode", CharMovementBinding::isTrackingAnimationMode },
        { "isWaypointMoveMode", CharMovementBinding::isWaypointMoveMode },
        { "setDirectMovement", CharMovementBinding::setDirectMovement },
        { "getCharacter", CharMovementBinding::getCharacter },
        { "toGround", CharMovementBinding::toGround },
        { "updateGroundMaterial", CharMovementBinding::updateGroundMaterial },
        { "getCombatMoveSpeedMult", CharMovementBinding::getCombatMoveSpeedMult },
        { 0, 0 }
    };

    registerClass(
        L, 
        CharMovementBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CharMovementBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, CharMovement_get_flockingVector);
    lua_setfield(L, -2, "flockingVector");
    lua_pushcfunction(L, CharMovement_get_combatMover);
    lua_setfield(L, -2, "combatMover");
    lua_pushcfunction(L, CharMovement_get_combatMover2);
    lua_setfield(L, -2, "combatMover2");
    lua_pushcfunction(L, CharMovement_get_flockingTools);
    lua_setfield(L, -2, "flockingTools");
    lua_pushcfunction(L, CharMovement_get_formation);
    lua_setfield(L, -2, "formation");
    lua_pushcfunction(L, CharMovement_get_enemyFormation);
    lua_setfield(L, -2, "enemyFormation");
    lua_pushcfunction(L, CharMovement_get_havokCharacter);
    lua_setfield(L, -2, "havokCharacter");
    lua_pushcfunction(L, CharMovement_get_tracer);
    lua_setfield(L, -2, "tracer");
    lua_pushcfunction(L, CharMovement_get_dontEverRecreateMe);
    lua_setfield(L, -2, "dontEverRecreateMe");
    lua_pushcfunction(L, CharMovement_get_floorGroup);
    lua_setfield(L, -2, "floorGroup");
    lua_pushcfunction(L, CharMovement_get_building);
    lua_setfield(L, -2, "building");
    lua_pushcfunction(L, CharMovement_get_initCheck);
    lua_setfield(L, -2, "initCheck");
    lua_pushcfunction(L, CharMovement_get__combatMoveSpeedMult);
    lua_setfield(L, -2, "_combatMoveSpeedMult");
    lua_pushcfunction(L, CharMovement_get_destinationLoaded);
    lua_setfield(L, -2, "destinationLoaded");
    lua_pushcfunction(L, CharMovement_get_footprintRadius);
    lua_setfield(L, -2, "footprintRadius");
    lua_pushcfunction(L, CharMovement_get_edgeTarget);
    lua_setfield(L, -2, "edgeTarget");
    lua_pushcfunction(L, CharMovement_get__lastOffMeshCheck);
    lua_setfield(L, -2, "_lastOffMeshCheck");
    lua_pushcfunction(L, CharMovement_get_movingToEdge);
    lua_setfield(L, -2, "movingToEdge");
    lua_pushcfunction(L, CharMovement_get_lastStepTime);
    lua_setfield(L, -2, "lastStepTime");
    lua_pushcfunction(L, CharMovement_get_movementMode);
    lua_setfield(L, -2, "movementMode");
    lua_pushcfunction(L, CharMovement_get_animationOverride);
    lua_setfield(L, -2, "animationOverride");
    lua_pushcfunction(L, CharMovement_get_trackingAnimRelocationVector);
    lua_setfield(L, -2, "trackingAnimRelocationVector");
    lua_pushcfunction(L, CharMovement_get_desiredMotion);
    lua_setfield(L, -2, "desiredMotion");
    lua_pushcfunction(L, CharMovement_get_moveLimit);
    lua_setfield(L, -2, "moveLimit");
    lua_pushcfunction(L, CharMovement_get_animation);
    lua_setfield(L, -2, "animation");
    lua_pushcfunction(L, CharMovement_get_character);
    lua_setfield(L, -2, "character");
    lua_pushcfunction(L, CharMovement_get_clickHull);
    lua_setfield(L, -2, "clickHull");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, CharMovement_set_flockingVector);
    lua_setfield(L, -2, "flockingVector");
    lua_pushcfunction(L, CharMovement_set_combatMover);
    lua_setfield(L, -2, "combatMover");
    lua_pushcfunction(L, CharMovement_set_combatMover2);
    lua_setfield(L, -2, "combatMover2");
    lua_pushcfunction(L, CharMovement_set_flockingTools);
    lua_setfield(L, -2, "flockingTools");
    lua_pushcfunction(L, CharMovement_set_formation);
    lua_setfield(L, -2, "formation");
    lua_pushcfunction(L, CharMovement_set_enemyFormation);
    lua_setfield(L, -2, "enemyFormation");
    lua_pushcfunction(L, CharMovement_set_havokCharacter);
    lua_setfield(L, -2, "havokCharacter");
    lua_pushcfunction(L, CharMovement_set_tracer);
    lua_setfield(L, -2, "tracer");
    lua_pushcfunction(L, CharMovement_set_dontEverRecreateMe);
    lua_setfield(L, -2, "dontEverRecreateMe");
    lua_pushcfunction(L, CharMovement_set_floorGroup);
    lua_setfield(L, -2, "floorGroup");
    lua_pushcfunction(L, CharMovement_set_building);
    lua_setfield(L, -2, "building");
    lua_pushcfunction(L, CharMovement_set_initCheck);
    lua_setfield(L, -2, "initCheck");
    lua_pushcfunction(L, CharMovement_set__combatMoveSpeedMult);
    lua_setfield(L, -2, "_combatMoveSpeedMult");
    lua_pushcfunction(L, CharMovement_set_destinationLoaded);
    lua_setfield(L, -2, "destinationLoaded");
    lua_pushcfunction(L, CharMovement_set_footprintRadius);
    lua_setfield(L, -2, "footprintRadius");
    lua_pushcfunction(L, CharMovement_set_edgeTarget);
    lua_setfield(L, -2, "edgeTarget");
    lua_pushcfunction(L, CharMovement_set__lastOffMeshCheck);
    lua_setfield(L, -2, "_lastOffMeshCheck");
    lua_pushcfunction(L, CharMovement_set_movingToEdge);
    lua_setfield(L, -2, "movingToEdge");
    lua_pushcfunction(L, CharMovement_set_lastStepTime);
    lua_setfield(L, -2, "lastStepTime");
    lua_pushcfunction(L, CharMovement_set_movementMode);
    lua_setfield(L, -2, "movementMode");
    lua_pushcfunction(L, CharMovement_set_animationOverride);
    lua_setfield(L, -2, "animationOverride");
    lua_pushcfunction(L, CharMovement_set_trackingAnimRelocationVector);
    lua_setfield(L, -2, "trackingAnimRelocationVector");
    lua_pushcfunction(L, CharMovement_set_desiredMotion);
    lua_setfield(L, -2, "desiredMotion");
    lua_pushcfunction(L, CharMovement_set_moveLimit);
    lua_setfield(L, -2, "moveLimit");
    lua_pushcfunction(L, CharMovement_set_animation);
    lua_setfield(L, -2, "animation");
    lua_pushcfunction(L, CharMovement_set_character);
    lua_setfield(L, -2, "character");
    lua_pushcfunction(L, CharMovement_set_clickHull);
    lua_setfield(L, -2, "clickHull");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua