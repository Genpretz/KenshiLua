#include "pch.h"
#include "kenshi\CharMovement.h"
#include "CharMovementBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/AbstractMovementBaseBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/CombatMovementControllerBinding.h"
#include "Bindings/FlockingToolsBinding.h"
#include "Bindings/FormationMoverBinding.h"
#include "Bindings/RootObjectBaseBinding.h"
#include "Bindings/physHitBinding.h"
#include "Bindings/Util/HandBinding.h"

namespace KenshiLua
{

static CharMovement* getInstance(lua_State* L, int idx)
{
    return checkObject<CharMovement>(L, idx, CharMovementBinding::getMetatableName());
}

// --- Getters for CharMovement ---
static int CharMovement_get_flockingVector(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    pushVector3(L, instance->flockingVector);
    return 1;
}

static int CharMovement_get_combatMover(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    return pushObject<CombatMovementController>(L, &instance->combatMover, CombatMovementControllerBinding::getMetatableName());
}

static int CharMovement_get_combatMover2(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    return pushObject<FormationMover>(L, &instance->combatMover2, FormationMoverBinding::getMetatableName());
}

static int CharMovement_get_flockingTools(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    return pushObject<FlockingTools>(L, &instance->flockingTools, FlockingToolsBinding::getMetatableName());
}

static int CharMovement_get_formation(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    lua_pushlightuserdata(L, (void*)instance->formation);
    return 1;
}

static int CharMovement_get_enemyFormation(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    lua_pushlightuserdata(L, (void*)instance->enemyFormation);
    return 1;
}

static int CharMovement_get_havokCharacter(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    lua_pushlightuserdata(L, (void*)instance->havokCharacter);
    return 1;
}

static int CharMovement_get_tracer(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    lua_pushlightuserdata(L, (void*)instance->tracer);
    return 1;
}

static int CharMovement_get_dontEverRecreateMe(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    lua_pushboolean(L, instance->dontEverRecreateMe ? 1 : 0);
    return 1;
}

static int CharMovement_get_floorGroup(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    lua_pushinteger(L, instance->floorGroup);
    return 1;
}

static int CharMovement_get_building(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    return HandBinding::push(L, instance->building);
}

static int CharMovement_get_initCheck(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    lua_pushboolean(L, instance->initCheck ? 1 : 0);
    return 1;
}

static int CharMovement_get__combatMoveSpeedMult(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    lua_pushnumber(L, instance->_combatMoveSpeedMult);
    return 1;
}

static int CharMovement_get_destinationLoaded(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    lua_pushboolean(L, instance->destinationLoaded ? 1 : 0);
    return 1;
}

static int CharMovement_get_footprintRadius(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    lua_pushnumber(L, instance->footprintRadius);
    return 1;
}

static int CharMovement_get_edgeTarget(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    lua_pushinteger(L, instance->edgeTarget);
    return 1;
}

static int CharMovement_get__lastOffMeshCheck(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    lua_pushnumber(L, instance->_lastOffMeshCheck);
    return 1;
}

static int CharMovement_get_movingToEdge(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    lua_pushboolean(L, instance->movingToEdge ? 1 : 0);
    return 1;
}

static int CharMovement_get_lastStepTime(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    lua_pushnumber(L, instance->lastStepTime);
    return 1;
}

static int CharMovement_get_animationOverride(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    lua_pushboolean(L, instance->animationOverride ? 1 : 0);
    return 1;
}

static int CharMovement_get_trackingAnimRelocationVector(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    pushVector3(L, instance->trackingAnimRelocationVector);
    return 1;
}

static int CharMovement_get_desiredMotion(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    pushVector3(L, instance->desiredMotion);
    return 1;
}

static int CharMovement_get_moveLimit(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    lua_pushnumber(L, instance->moveLimit);
    return 1;
}

static int CharMovement_get_animation(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    lua_pushlightuserdata(L, (void*)instance->animation);
    return 1;
}

static int CharMovement_get_character(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    return pushObject<Character>(L, instance->character, CharacterBinding::getMetatableName());
}

static int CharMovement_get_clickHull(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    lua_pushlightuserdata(L, (void*)instance->clickHull);
    return 1;
}

// --- Setters for CharMovement ---
static int CharMovement_set_flockingVector(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    readVector3(L, 2, instance->flockingVector);
    return 0;
}

static int CharMovement_set_combatMover(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    instance->combatMover = *checkObject<CombatMovementController>(L, 2, CombatMovementControllerBinding::getMetatableName());
    return 0;
}

static int CharMovement_set_combatMover2(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    instance->combatMover2 = *checkObject<FormationMover>(L, 2, FormationMoverBinding::getMetatableName());
    return 0;
}

static int CharMovement_set_flockingTools(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    instance->flockingTools = *checkObject<FlockingTools>(L, 2, FlockingToolsBinding::getMetatableName());
    return 0;
}

static int CharMovement_set_dontEverRecreateMe(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    instance->dontEverRecreateMe = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharMovement_set_floorGroup(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    instance->floorGroup = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CharMovement_set_building(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    instance->building = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int CharMovement_set_initCheck(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    instance->initCheck = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharMovement_set__combatMoveSpeedMult(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    instance->_combatMoveSpeedMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharMovement_set_destinationLoaded(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    instance->destinationLoaded = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharMovement_set_footprintRadius(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    instance->footprintRadius = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharMovement_set_edgeTarget(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    instance->edgeTarget = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CharMovement_set__lastOffMeshCheck(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    instance->_lastOffMeshCheck = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharMovement_set_movingToEdge(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    instance->movingToEdge = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharMovement_set_lastStepTime(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    instance->lastStepTime = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharMovement_set_animationOverride(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    instance->animationOverride = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharMovement_set_trackingAnimRelocationVector(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    readVector3(L, 2, instance->trackingAnimRelocationVector);
    return 0;
}

static int CharMovement_set_desiredMotion(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    readVector3(L, 2, instance->desiredMotion);
    return 0;
}

static int CharMovement_set_moveLimit(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    instance->moveLimit = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharMovement_set_character(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    instance->character = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int CharMovement_set_formation(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    instance->formation = lua_isnoneornil(L, 2) ? nullptr : (Formation*)lua_touserdata(L, 2);
    return 0;
}

static int CharMovement_set_enemyFormation(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    instance->enemyFormation = lua_isnoneornil(L, 2) ? nullptr : (Formation*)lua_touserdata(L, 2);
    return 0;
}

static int CharMovement_set_havokCharacter(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    instance->havokCharacter = lua_isnoneornil(L, 2) ? nullptr : (HavokCharacter*)lua_touserdata(L, 2);
    return 0;
}

static int CharMovement_set_tracer(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    instance->tracer = lua_isnoneornil(L, 2) ? nullptr : (ConstantTracerT*)lua_touserdata(L, 2);
    return 0;
}

static int CharMovement_set_animation(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    instance->animation = lua_isnoneornil(L, 2) ? nullptr : (AnimationClass*)lua_touserdata(L, 2);
    return 0;
}

static int CharMovement_set_clickHull(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    instance->clickHull = lua_isnoneornil(L, 2) ? nullptr : (PhysicsHullT*)lua_touserdata(L, 2);
    return 0;
}

static int CharMovement_get_movementMode(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    lua_pushinteger(L, (lua_Integer)instance->movementMode);
    return 1;
}

static int CharMovement_set_movementMode(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");
    instance->movementMode = (MovementMode)luaL_checkinteger(L, 2);
    return 0;
}

int CharMovementBinding::_CONSTRUCTOR(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    CharMovement* result = instance->_CONSTRUCTOR();
    return pushObject<CharMovement>(L, result, CharMovementBinding::getMetatableName());
}

int CharMovementBinding::_DESTRUCTOR(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int CharMovementBinding::_setPositionAndTeleport(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    int floor = (int)luaL_checkinteger(L, 3);
    instance->_setPositionAndTeleport(p, floor);
    return 0;
}

int CharMovementBinding::_NV__setPositionAndTeleport(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    int floor = (int)luaL_checkinteger(L, 3);
    instance->_NV__setPositionAndTeleport(p, floor);
    return 0;
}

int CharMovementBinding::_setPositionDirectionAndTeleport(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 position;
    readVector3(L, 2, position);
    Ogre::Quaternion orientation;
    readQuaternion(L, 3, orientation);
    instance->_setPositionDirectionAndTeleport(position, orientation);
    return 0;
}

int CharMovementBinding::_NV__setPositionDirectionAndTeleport(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 position;
    readVector3(L, 2, position);
    Ogre::Quaternion orientation;
    readQuaternion(L, 3, orientation);
    instance->_NV__setPositionDirectionAndTeleport(position, orientation);
    return 0;
}

int CharMovementBinding::_setPositionSimple(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    instance->_setPositionSimple(p);
    return 0;
}

int CharMovementBinding::_NV__setPositionSimple(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    instance->_NV__setPositionSimple(p);
    return 0;
}

int CharMovementBinding::isRunning(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    bool result = instance->isRunning();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::isRunningAway(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 from;
    readVector3(L, 2, from);
    bool result = instance->isRunningAway(from);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::trackAnimationMovement(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->trackAnimationMovement(on);
    return 0;
}

int CharMovementBinding::getHandle(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    hand result = instance->getHandle();
    return HandBinding::push(L, result);
}

int CharMovementBinding::_NV_getHandle(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    hand result = instance->_NV_getHandle();
    return HandBinding::push(L, result);
}

int CharMovementBinding::handleChanged(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    instance->handleChanged();
    return 0;
}

int CharMovementBinding::_NV_handleChanged(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    instance->_NV_handleChanged();
    return 0;
}

int CharMovementBinding::getRadius(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    float result = instance->getRadius();
    lua_pushnumber(L, result);
    return 1;
}

int CharMovementBinding::update(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    float _TIME = (float)luaL_checknumber(L, 2);
    instance->update(_TIME);
    return 0;
}

int CharMovementBinding::_NV_update(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    float _TIME = (float)luaL_checknumber(L, 2);
    instance->_NV_update(_TIME);
    return 0;
}

int CharMovementBinding::pausedUpdate(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    instance->pausedUpdate();
    return 0;
}

int CharMovementBinding::twoFrameUpdate(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    float _TIME = (float)luaL_checknumber(L, 2);
    instance->twoFrameUpdate(_TIME);
    return 0;
}

int CharMovementBinding::postAnimationUpdate(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    instance->postAnimationUpdate();
    return 0;
}

int CharMovementBinding::periodicUpdate(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->periodicUpdate(time);
    return 0;
}

int CharMovementBinding::predictNextPosition(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    bool accurate = lua_toboolean(L, 2) != 0;
    Ogre::Vector3 result = instance->predictNextPosition(accurate);
    pushVector3(L, result);
    return 1;
}

int CharMovementBinding::getMaximumPossibleMovement(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    float result = instance->getMaximumPossibleMovement();
    lua_pushnumber(L, result);
    return 1;
}

int CharMovementBinding::faceDirection(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 dir;
    readVector3(L, 2, dir);
    instance->faceDirection(dir);
    return 0;
}

int CharMovementBinding::_NV_faceDirection(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 dir;
    readVector3(L, 2, dir);
    instance->_NV_faceDirection(dir);
    return 0;
}

int CharMovementBinding::lookatPosition(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    instance->lookatPosition(pos);
    return 0;
}

int CharMovementBinding::_NV_lookatPosition(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    instance->_NV_lookatPosition(pos);
    return 0;
}

int CharMovementBinding::pathOk(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    bool result = instance->pathOk();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::_NV_pathOk(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    bool result = instance->_NV_pathOk();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::pathFailed(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    bool result = instance->pathFailed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::_NV_pathFailed(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    bool result = instance->_NV_pathFailed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::isDestinationReached(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    bool result = instance->isDestinationReached();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::_NV_isDestinationReached(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    bool result = instance->_NV_isDestinationReached();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::isIdle(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    bool result = instance->isIdle();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::_NV_isIdle(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    bool result = instance->_NV_isIdle();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::playerMoveOrderWhileInCombatMode(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    bool result = instance->playerMoveOrderWhileInCombatMode(pos);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::_NV_playerMoveOrderWhileInCombatMode(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    bool result = instance->_NV_playerMoveOrderWhileInCombatMode(pos);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::halt(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    instance->halt();
    return 0;
}

int CharMovementBinding::_NV_halt(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    instance->_NV_halt();
    return 0;
}

int CharMovementBinding::invalidatePath(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    instance->invalidatePath();
    return 0;
}

int CharMovementBinding::movedBy(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    instance->movedBy(pos);
    return 0;
}

int CharMovementBinding::isCombatMovementBlockedByCharacters(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    bool result = instance->isCombatMovementBlockedByCharacters();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::destroy(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    instance->destroy();
    return 0;
}

int CharMovementBinding::restore(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    instance->restore();
    return 0;
}

int CharMovementBinding::refreshClickHull(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    instance->refreshClickHull();
    return 0;
}

int CharMovementBinding::teleportCollisionHull(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 _pos;
    readVector3(L, 2, _pos);
    instance->teleportCollisionHull(_pos);
    return 0;
}

int CharMovementBinding::getCurrentFloor(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    int result = instance->getCurrentFloor();
    lua_pushinteger(L, result);
    return 1;
}

int CharMovementBinding::isIndoorsHideMeCheck(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    bool result = instance->isIndoorsHideMeCheck();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::isIndoors(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    bool result = instance->isIndoors();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::manualMovement(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 v;
    readVector3(L, 2, v);
    instance->manualMovement(v);
    return 0;
}

int CharMovementBinding::_NV_manualMovement(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 v;
    readVector3(L, 2, v);
    instance->_NV_manualMovement(v);
    return 0;
}

int CharMovementBinding::isInsideBuildingLoadedInterior(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    bool result = instance->isInsideBuildingLoadedInterior();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::hasClickHull(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    bool result = instance->hasClickHull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::isTrackingAnimationMode(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    bool result = instance->isTrackingAnimationMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::isWaypointMoveMode(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    bool result = instance->isWaypointMoveMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::setDirectMovement(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    Ogre::Vector3 d;
    readVector3(L, 2, d);
    float limit = (float)luaL_checknumber(L, 3);
    instance->setDirectMovement(d, limit);
    return 0;
}

int CharMovementBinding::getLastGroundTraceResultMT(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    physHit result = instance->getLastGroundTraceResultMT();
    return pushValue<physHit>(L, result, physHitBinding::getMetatableName());
}

int CharMovementBinding::getCharacter(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    Character* result = instance->getCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int CharMovementBinding::toGround(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    bool result = instance->toGround();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharMovementBinding::updateGroundMaterial(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    instance->updateGroundMaterial();
    return 0;
}

int CharMovementBinding::getCombatMoveSpeedMult(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    float result = instance->getCombatMoveSpeedMult();
    lua_pushnumber(L, result);
    return 1;
}

int CharMovementBinding::setMovementMode(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    MovementMode mode = (MovementMode)luaL_checkinteger(L, 2);
    instance->setMovementMode(mode);
    return 0;
}

int CharMovementBinding::isStandingOnSomething(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    const hand& h = instance->isStandingOnSomething();
    return HandBinding::push(L, h);
}

int CharMovementBinding::combatMovementOffensive(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    hand* target = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    float minDistance = (float)luaL_checknumber(L, 3);
    float maxDistance = (float)luaL_checknumber(L, 4);
    float circle = (float)luaL_checknumber(L, 5);
    bool power = lua_toboolean(L, 6) != 0;
    float speedLimit = (float)luaL_checknumber(L, 7);

    instance->combatMovementOffensive(*target, minDistance, maxDistance, circle, power, speedLimit);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 390: void create(...) - unsupported arg type
  line 391: void _NV_create(...) - unsupported arg type
  line 407: void formationUpdateCallback(...) - non-string reference arg
  line 448: void setPatrolInput(...) - unsupported arg type
  line 449: void _NV_setPatrolInput(...) - unsupported arg type
  line 457: Ogre::Aabb getAABB(...) - unsupported return type
  line 473: NxControllerAction onShapeHit(...) - unsupported return type
  line 474: NxControllerAction _NV_onShapeHit(...) - unsupported return type
  line 475: NxControllerAction onControllerHit(...) - unsupported return type
  line 476: NxControllerAction _NV_onControllerHit(...) - unsupported return type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - CharMovement_get_formation / CharMovement_set_formation: Formation* (unbound pointer)
  - CharMovement_get_enemyFormation / CharMovement_set_enemyFormation: Formation* (unbound pointer)
  - CharMovement_get_havokCharacter / CharMovement_set_havokCharacter: HavokCharacter* (unbound pointer)
  - CharMovement_get_tracer / CharMovement_set_tracer: ConstantTracerT* (unbound pointer)
  - CharMovement_get_animation / CharMovement_set_animation: AnimationClass* (unbound pointer)
  - CharMovement_get_clickHull / CharMovement_set_clickHull: PhysicsHullT* (unbound pointer)
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

int CharMovementBinding::_NV_setDestination(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    if (Character* who = testObject<Character>(L, 2, CharacterBinding::getMetatableName())) {
        UpdatePriority pri = (UpdatePriority)luaL_optinteger(L, 3, 0);
        instance->_NV_setDestination(who, pri);
        return 0;
    }
    if (Building* who = testObject<Building>(L, 2, BuildingBinding::getMetatableName())) {
        UpdatePriority pri = (UpdatePriority)luaL_optinteger(L, 3, 0);
        instance->_NV_setDestination(who, pri);
        return 0;
    }
    if (RootObjectBase* target = testObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName())) {
        UpdatePriority pri = (UpdatePriority)luaL_optinteger(L, 3, 0);
        instance->_NV_setDestination(target, pri);
        return 0;
    }
    if (lua_istable(L, 2)) {
        Ogre::Vector3 dest;
        readVector3(L, 2, dest);
        UpdatePriority pri = (UpdatePriority)luaL_optinteger(L, 3, 0);
        bool notVertical = lua_toboolean(L, 4) != 0;
        instance->_NV_setDestination(dest, pri, notVertical);
        return 0;
    }

    return luaL_error(L, "Argument 2 to _NV_setDestination must be a Vector3 table, Character, Building, or RootObjectBase, got %s", luaL_typename(L, 2));
}

int CharMovementBinding::setDestination(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    if (Character* who = testObject<Character>(L, 2, CharacterBinding::getMetatableName())) {
        UpdatePriority pri = (UpdatePriority)luaL_optinteger(L, 3, 0);
        instance->setDestination(who, pri);
        return 0;
    }
    if (Building* who = testObject<Building>(L, 2, BuildingBinding::getMetatableName())) {
        UpdatePriority pri = (UpdatePriority)luaL_optinteger(L, 3, 0);
        instance->setDestination(who, pri);
        return 0;
    }
    if (RootObjectBase* target = testObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName())) {
        UpdatePriority pri = (UpdatePriority)luaL_optinteger(L, 3, 0);
        instance->setDestination(target, pri);
        return 0;
    }
    if (lua_istable(L, 2)) {
        Ogre::Vector3 dest;
        readVector3(L, 2, dest);
        UpdatePriority pri = (UpdatePriority)luaL_optinteger(L, 3, 0);
        bool notVertical = lua_toboolean(L, 4) != 0;
        instance->setDestination(dest, pri, notVertical);
        return 0;
    }

    return luaL_error(L, "Argument 2 to setDestination must be a Vector3 table, Character, Building, or RootObjectBase, got %s", luaL_typename(L, 2));
}

int CharMovementBinding::setLookatTarget(lua_State* L)
{
    CharMovement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharMovement is nil");

    hand* lookatCharacter = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    instance->setLookatTarget(*lookatCharacter);
    return 0;
}

void CharMovementBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CharMovementBinding::gc },
        { "__tostring", CharMovementBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", CharMovementBinding::_CONSTRUCTOR },
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
        { "getHandle", CharMovementBinding::getHandle },
        { "_NV_getHandle", CharMovementBinding::_NV_getHandle },
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
        { "getLastGroundTraceResultMT", CharMovementBinding::getLastGroundTraceResultMT },
        { "getCharacter", CharMovementBinding::getCharacter },
        { "toGround", CharMovementBinding::toGround },
        { "updateGroundMaterial", CharMovementBinding::updateGroundMaterial },
        { "getCombatMoveSpeedMult", CharMovementBinding::getCombatMoveSpeedMult },
        { "setDestination", CharMovementBinding::setDestination },
        { "_NV_setDestination", CharMovementBinding::_NV_setDestination },
        { "setLookatTarget", CharMovementBinding::setLookatTarget },
        { "setMovementMode", CharMovementBinding::setMovementMode },
        { "isStandingOnSomething", CharMovementBinding::isStandingOnSomething },
        { "combatMovementOffensive", CharMovementBinding::combatMovementOffensive },
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
    registerGetter(L, "flockingVector", CharMovement_get_flockingVector);
    registerGetter(L, "combatMover", CharMovement_get_combatMover);
    registerGetter(L, "combatMover2", CharMovement_get_combatMover2);
    registerGetter(L, "flockingTools", CharMovement_get_flockingTools);
    registerGetter(L, "formation", CharMovement_get_formation);
    registerGetter(L, "enemyFormation", CharMovement_get_enemyFormation);
    registerGetter(L, "havokCharacter", CharMovement_get_havokCharacter);
    registerGetter(L, "tracer", CharMovement_get_tracer);
    registerGetter(L, "dontEverRecreateMe", CharMovement_get_dontEverRecreateMe);
    registerGetter(L, "floorGroup", CharMovement_get_floorGroup);
    registerGetter(L, "building", CharMovement_get_building);
    registerGetter(L, "initCheck", CharMovement_get_initCheck);
    registerGetter(L, "_combatMoveSpeedMult", CharMovement_get__combatMoveSpeedMult);
    registerGetter(L, "destinationLoaded", CharMovement_get_destinationLoaded);
    registerGetter(L, "footprintRadius", CharMovement_get_footprintRadius);
    registerGetter(L, "edgeTarget", CharMovement_get_edgeTarget);
    registerGetter(L, "_lastOffMeshCheck", CharMovement_get__lastOffMeshCheck);
    registerGetter(L, "movingToEdge", CharMovement_get_movingToEdge);
    registerGetter(L, "lastStepTime", CharMovement_get_lastStepTime);
    registerGetter(L, "animationOverride", CharMovement_get_animationOverride);
    registerGetter(L, "trackingAnimRelocationVector", CharMovement_get_trackingAnimRelocationVector);
    registerGetter(L, "desiredMotion", CharMovement_get_desiredMotion);
    registerGetter(L, "moveLimit", CharMovement_get_moveLimit);
    registerGetter(L, "animation", CharMovement_get_animation);
    registerGetter(L, "character", CharMovement_get_character);
    registerGetter(L, "clickHull", CharMovement_get_clickHull);
    registerGetter(L, "movementMode", CharMovement_get_movementMode);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "flockingVector", CharMovement_set_flockingVector);
    registerSetter(L, "combatMover", CharMovement_set_combatMover);
    registerSetter(L, "combatMover2", CharMovement_set_combatMover2);
    registerSetter(L, "flockingTools", CharMovement_set_flockingTools);
    registerSetter(L, "formation", CharMovement_set_formation);
    registerSetter(L, "enemyFormation", CharMovement_set_enemyFormation);
    registerSetter(L, "havokCharacter", CharMovement_set_havokCharacter);
    registerSetter(L, "tracer", CharMovement_set_tracer);
    registerSetter(L, "dontEverRecreateMe", CharMovement_set_dontEverRecreateMe);
    registerSetter(L, "floorGroup", CharMovement_set_floorGroup);
    registerSetter(L, "building", CharMovement_set_building);
    registerSetter(L, "initCheck", CharMovement_set_initCheck);
    registerSetter(L, "_combatMoveSpeedMult", CharMovement_set__combatMoveSpeedMult);
    registerSetter(L, "destinationLoaded", CharMovement_set_destinationLoaded);
    registerSetter(L, "footprintRadius", CharMovement_set_footprintRadius);
    registerSetter(L, "edgeTarget", CharMovement_set_edgeTarget);
    registerSetter(L, "_lastOffMeshCheck", CharMovement_set__lastOffMeshCheck);
    registerSetter(L, "movingToEdge", CharMovement_set_movingToEdge);
    registerSetter(L, "lastStepTime", CharMovement_set_lastStepTime);
    registerSetter(L, "animationOverride", CharMovement_set_animationOverride);
    registerSetter(L, "trackingAnimRelocationVector", CharMovement_set_trackingAnimRelocationVector);
    registerSetter(L, "desiredMotion", CharMovement_set_desiredMotion);
    registerSetter(L, "moveLimit", CharMovement_set_moveLimit);
    registerSetter(L, "animation", CharMovement_set_animation);
    registerSetter(L, "character", CharMovement_set_character);
    registerSetter(L, "clickHull", CharMovement_set_clickHull);
    registerSetter(L, "movementMode", CharMovement_set_movementMode);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to AbstractMovementBase
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, CharMovementBinding::getMetatableName(), AbstractMovementBaseBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua