#include "pch.h"
#include "kenshi\havokcharacter.h"
#include "HavokCharacterBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/SensoryDataBinding.h"
#include "Bindings/Util/HandBinding.h"

namespace KenshiLua
{

static HavokCharacter* getInstance(lua_State* L, int idx)
{
    return checkObject<HavokCharacter>(L, idx, HavokCharacterBinding::getMetatableName());
}

// --- Getters for HavokCharacter ---
static int HavokCharacter_get_startingFace(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    lua_pushinteger(L, instance->startingFace);
    return 1;
}

static int HavokCharacter_get_currentFace(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    lua_pushinteger(L, instance->currentFace);
    return 1;
}

static int HavokCharacter_get_nextEdge(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    lua_pushinteger(L, instance->nextEdge);
    return 1;
}

static int HavokCharacter_get_radius(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    lua_pushnumber(L, instance->radius);
    return 1;
}

static int HavokCharacter_get_waterModifier(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    lua_pushnumber(L, instance->waterModifier);
    return 1;
}

static int HavokCharacter_get_acceleration(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    lua_pushnumber(L, instance->acceleration);
    return 1;
}

static int HavokCharacter_get_desiredSpeed(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    lua_pushnumber(L, instance->desiredSpeed);
    return 1;
}

static int HavokCharacter_get_positionChanged(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    lua_pushboolean(L, instance->positionChanged ? 1 : 0);
    return 1;
}

static int HavokCharacter_get_timeOffPath(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    lua_pushnumber(L, instance->timeOffPath);
    return 1;
}

static int HavokCharacter_get_characterState(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    lua_pushinteger(L, (lua_Integer)instance->characterState);
    return 1;
}

static int HavokCharacter_get_lastState(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    lua_pushinteger(L, (lua_Integer)instance->lastState);
    return 1;
}

static int HavokCharacter_get_pathState(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    lua_pushinteger(L, (lua_Integer)instance->pathState);
    return 1;
}

static int HavokCharacter_get_handle(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    return HandBinding::push(L, instance->handle);
}

static int HavokCharacter_get_collided(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    return HandBinding::push(L, instance->collided);
}

static int HavokCharacter_get_sensoryData(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    return pushObject<SensoryData>(L, instance->sensoryData, SensoryDataBinding::getMetatableName());
}

static int HavokCharacter_get_resolveFlag(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    lua_pushinteger(L, instance->resolveFlag);
    return 1;
}

// --- Setters for HavokCharacter ---
static int HavokCharacter_set_startingFace(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    instance->startingFace = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int HavokCharacter_set_currentFace(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    instance->currentFace = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int HavokCharacter_set_nextEdge(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    instance->nextEdge = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int HavokCharacter_set_radius(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    instance->radius = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HavokCharacter_set_waterModifier(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    instance->waterModifier = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HavokCharacter_set_acceleration(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    instance->acceleration = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HavokCharacter_set_desiredSpeed(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    instance->desiredSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HavokCharacter_set_positionChanged(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    instance->positionChanged = lua_toboolean(L, 2) != 0;
    return 0;
}

static int HavokCharacter_set_timeOffPath(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    instance->timeOffPath = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HavokCharacter_set_characterState(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    instance->characterState = (HavokCharacter::CharacterState)luaL_checkinteger(L, 2);
    return 0;
}

static int HavokCharacter_set_lastState(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    instance->lastState = (HavokCharacter::CharacterState)luaL_checkinteger(L, 2);
    return 0;
}

static int HavokCharacter_set_pathState(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    instance->pathState = (HavokCharacter::PathState)luaL_checkinteger(L, 2);
    return 0;
}

static int HavokCharacter_set_handle(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    instance->handle = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int HavokCharacter_set_collided(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    instance->collided = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int HavokCharacter_set_sensoryData(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    instance->sensoryData = lua_isnoneornil(L, 2) ? nullptr : checkObject<SensoryData>(L, 2, SensoryDataBinding::getMetatableName());
    return 0;
}

static int HavokCharacter_set_resolveFlag(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");
    instance->resolveFlag = (char)luaL_checkinteger(L, 2);
    return 0;
}

int HavokCharacterBinding::setPosition(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    unsigned int key = (unsigned int)luaL_checkinteger(L, 3);
    instance->setPosition(p, key);
    return 0;
}

int HavokCharacterBinding::getPosition(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    Ogre::Vector3 result = instance->getPosition();
    pushVector3(L, result);
    return 1;
}

int HavokCharacterBinding::setVelocity(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    Ogre::Vector3 v;
    readVector3(L, 2, v);
    instance->setVelocity(v);
    return 0;
}

int HavokCharacterBinding::getVelocity(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    Ogre::Vector3 result = instance->getVelocity();
    pushVector3(L, result);
    return 1;
}

int HavokCharacterBinding::getWaypointDirection(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    Ogre::Vector3 result = instance->getWaypointDirection();
    pushVector3(L, result);
    return 1;
}

int HavokCharacterBinding::getDirectionMoved(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    Ogre::Vector3 result = instance->getDirectionMoved();
    pushVector3(L, result);
    return 1;
}

int HavokCharacterBinding::setWaterModifier(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    float m = (float)luaL_checknumber(L, 2);
    instance->setWaterModifier(m);
    return 0;
}

int HavokCharacterBinding::setManualMode(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setManualMode(on);
    return 0;
}

int HavokCharacterBinding::setDesiredSpeed(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    float speed = (float)luaL_checknumber(L, 2);
    instance->setDesiredSpeed(speed);
    return 0;
}

int HavokCharacterBinding::getState(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    HavokCharacter::CharacterState result = instance->getState();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int HavokCharacterBinding::getPathState(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    HavokCharacter::PathState result = instance->getPathState();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int HavokCharacterBinding::isOnNavmesh(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    bool result = instance->isOnNavmesh();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int HavokCharacterBinding::getClosestPoint(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    Ogre::Vector3 target;
    readVector3(L, 2, target);
    float max = (float)luaL_checknumber(L, 3);
    Building* building = checkObject<Building>(L, 4, BuildingBinding::getMetatableName());
    Ogre::Vector3 result = instance->getClosestPoint(target, max, building);
    pushVector3(L, result);
    return 1;
}

int HavokCharacterBinding::requestPath(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    Ogre::Vector3 goal;
    readVector3(L, 2, goal);
    int priority = (int)luaL_checkinteger(L, 3);
    instance->requestPath(goal, priority);
    return 0;
}

int HavokCharacterBinding::clearPath(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    instance->clearPath();
    return 0;
}

int HavokCharacterBinding::update(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->update(time);
    return 0;
}

int HavokCharacterBinding::moveAlongPath(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    float time = (float)luaL_checknumber(L, 2);
    bool result = instance->moveAlongPath(time);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int HavokCharacterBinding::handleCollision(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    bool result = instance->handleCollision();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int HavokCharacterBinding::invalidate(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    int rid = (int)luaL_checkinteger(L, 2);
    instance->invalidate(rid);
    return 0;
}

int HavokCharacterBinding::_getFaceKey(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    unsigned int result = instance->_getFaceKey();
    lua_pushinteger(L, result);
    return 1;
}

int HavokCharacterBinding::pullThroughVertex(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    int side = (int)luaL_checkinteger(L, 2);
    int index = (int)luaL_checkinteger(L, 3);
    int result = instance->pullThroughVertex(side, index);
    lua_pushinteger(L, result);
    return 1;
}

int HavokCharacterBinding::updateNextEdge(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    int result = instance->updateNextEdge();
    lua_pushinteger(L, result);
    return 1;
}

int HavokCharacterBinding::resolveProblems(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    instance->resolveProblems();
    return 0;
}

int HavokCharacterBinding::atGoal(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    bool result = instance->atGoal();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int HavokCharacterBinding::getCollidedCharacter(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    return HandBinding::push(L, instance->getCollidedCharacter());
}

int HavokCharacterBinding::setHandle(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (h) instance->setHandle(*h);
    return 0;
}

int HavokCharacterBinding::calculateFuturePosition(lua_State* L)
{
    HavokCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HavokCharacter is nil");

    float distance = (float)luaL_checknumber(L, 2);
    Ogre::Vector3 result = instance->calculateFuturePosition(distance);
    pushVector3(L, result);
    return 1;
}

int HavokCharacterBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int HavokCharacterBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.HavokCharacter object");
    return 1;
}

void HavokCharacterBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       HavokCharacterBinding::gc },
        { "__tostring", HavokCharacterBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setPosition", HavokCharacterBinding::setPosition },
        { "getPosition", HavokCharacterBinding::getPosition },
        { "setVelocity", HavokCharacterBinding::setVelocity },
        { "getVelocity", HavokCharacterBinding::getVelocity },
        { "getWaypointDirection", HavokCharacterBinding::getWaypointDirection },
        { "getDirectionMoved", HavokCharacterBinding::getDirectionMoved },
        { "setWaterModifier", HavokCharacterBinding::setWaterModifier },
        { "setManualMode", HavokCharacterBinding::setManualMode },
        { "setDesiredSpeed", HavokCharacterBinding::setDesiredSpeed },
        { "getState", HavokCharacterBinding::getState },
        { "getPathState", HavokCharacterBinding::getPathState },
        { "isOnNavmesh", HavokCharacterBinding::isOnNavmesh },
        { "getClosestPoint", HavokCharacterBinding::getClosestPoint },
        { "requestPath", HavokCharacterBinding::requestPath },
        { "clearPath", HavokCharacterBinding::clearPath },
        { "update", HavokCharacterBinding::update },
        { "moveAlongPath", HavokCharacterBinding::moveAlongPath },
        { "handleCollision", HavokCharacterBinding::handleCollision },
        { "invalidate", HavokCharacterBinding::invalidate },
        { "_getFaceKey", HavokCharacterBinding::_getFaceKey },
        { "pullThroughVertex", HavokCharacterBinding::pullThroughVertex },
        { "updateNextEdge", HavokCharacterBinding::updateNextEdge },
        { "resolveProblems", HavokCharacterBinding::resolveProblems },
        { "atGoal", HavokCharacterBinding::atGoal },
        { "getCollidedCharacter", HavokCharacterBinding::getCollidedCharacter },
        { "setHandle", HavokCharacterBinding::setHandle },
        { "calculateFuturePosition", HavokCharacterBinding::calculateFuturePosition },
        { 0, 0 }
    };

    registerClass(
        L, 
        HavokCharacterBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, HavokCharacterBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "startingFace", HavokCharacter_get_startingFace);
    registerGetter(L, "currentFace", HavokCharacter_get_currentFace);
    registerGetter(L, "nextEdge", HavokCharacter_get_nextEdge);
    registerGetter(L, "radius", HavokCharacter_get_radius);
    registerGetter(L, "waterModifier", HavokCharacter_get_waterModifier);
    registerGetter(L, "acceleration", HavokCharacter_get_acceleration);
    registerGetter(L, "desiredSpeed", HavokCharacter_get_desiredSpeed);
    registerGetter(L, "positionChanged", HavokCharacter_get_positionChanged);
    registerGetter(L, "timeOffPath", HavokCharacter_get_timeOffPath);
    registerGetter(L, "characterState", HavokCharacter_get_characterState);
    registerGetter(L, "lastState", HavokCharacter_get_lastState);
    registerGetter(L, "pathState", HavokCharacter_get_pathState);
    registerGetter(L, "handle", HavokCharacter_get_handle);
    registerGetter(L, "collided", HavokCharacter_get_collided);
    registerGetter(L, "sensoryData", HavokCharacter_get_sensoryData);
    registerGetter(L, "resolveFlag", HavokCharacter_get_resolveFlag);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "startingFace", HavokCharacter_set_startingFace);
    registerSetter(L, "currentFace", HavokCharacter_set_currentFace);
    registerSetter(L, "nextEdge", HavokCharacter_set_nextEdge);
    registerSetter(L, "radius", HavokCharacter_set_radius);
    registerSetter(L, "waterModifier", HavokCharacter_set_waterModifier);
    registerSetter(L, "acceleration", HavokCharacter_set_acceleration);
    registerSetter(L, "desiredSpeed", HavokCharacter_set_desiredSpeed);
    registerSetter(L, "positionChanged", HavokCharacter_set_positionChanged);
    registerSetter(L, "timeOffPath", HavokCharacter_set_timeOffPath);
    registerSetter(L, "characterState", HavokCharacter_set_characterState);
    registerSetter(L, "lastState", HavokCharacter_set_lastState);
    registerSetter(L, "pathState", HavokCharacter_set_pathState);
    registerSetter(L, "handle", HavokCharacter_set_handle);
    registerSetter(L, "collided", HavokCharacter_set_collided);
    registerSetter(L, "sensoryData", HavokCharacter_set_sensoryData);
    registerSetter(L, "resolveFlag", HavokCharacter_set_resolveFlag);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua