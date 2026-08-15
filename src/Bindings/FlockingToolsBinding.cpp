#include "pch.h"
#include "kenshi\CharMovement.h"
#include "FlockingToolsBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/CombatMovementControllerBinding.h"
#include "Bindings/SensoryDataBinding.h"
#include "Bindings/Util/HandBinding.h"

namespace KenshiLua
{

static FlockingTools* getInstance(lua_State* L, int idx)
{
    return checkObject<FlockingTools>(L, idx, FlockingToolsBinding::getMetatableName());
}

// --- Getters for FlockingTools ---
static int FlockingTools_get_getOutOfTheWayOfCharacter(lua_State* L)
{
    FlockingTools* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FlockingTools is nil");
    return HandBinding::push(L, instance->getOutOfTheWayOfCharacter);
}

static int FlockingTools_get_currentPosition(lua_State* L)
{
    FlockingTools* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FlockingTools is nil");
    pushVector3(L, instance->currentPosition);
    return 1;
}

static int FlockingTools_get_me(lua_State* L)
{
    FlockingTools* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FlockingTools is nil");
    return pushObject<Character>(L, instance->me, CharacterBinding::getMetatableName());
}

static int FlockingTools_get_combatMover(lua_State* L)
{
    FlockingTools* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FlockingTools is nil");
    return pushObject<CombatMovementController>(L, instance->combatMover, CombatMovementControllerBinding::getMetatableName());
}

// --- Setters for FlockingTools ---
static int FlockingTools_set_getOutOfTheWayOfCharacter(lua_State* L)
{
    FlockingTools* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FlockingTools is nil");
    instance->getOutOfTheWayOfCharacter = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int FlockingTools_set_currentPosition(lua_State* L)
{
    FlockingTools* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FlockingTools is nil");
    readVector3(L, 2, instance->currentPosition);
    return 0;
}

static int FlockingTools_set_me(lua_State* L)
{
    FlockingTools* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FlockingTools is nil");
    instance->me = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int FlockingTools_set_combatMover(lua_State* L)
{
    FlockingTools* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FlockingTools is nil");
    instance->combatMover = lua_isnoneornil(L, 2) ? nullptr : checkObject<CombatMovementController>(L, 2, CombatMovementControllerBinding::getMetatableName());
    return 0;
}

int FlockingToolsBinding::create(lua_State* L)
{
    FlockingTools* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FlockingTools is nil");

    Character* chme = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    CombatMovementController* c = checkObject<CombatMovementController>(L, 3, CombatMovementControllerBinding::getMetatableName());
    instance->create(chme, c);
    return 0;
}

int FlockingToolsBinding::setCurrentPosition(lua_State* L)
{
    FlockingTools* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FlockingTools is nil");

    Ogre::Vector3 _pos;
    readVector3(L, 2, _pos);
    instance->setCurrentPosition(_pos);
    return 0;
}

int FlockingToolsBinding::calculateCurrentRepulsionVector(lua_State* L)
{
    FlockingTools* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FlockingTools is nil");

    float MAX_DISTANCE = (float)luaL_checknumber(L, 2);
    Ogre::Vector3 desiredDirection;
    readVector3(L, 3, desiredDirection);
    Character* skip = checkObject<Character>(L, 4, CharacterBinding::getMetatableName());
    bool includeEnemies = lua_toboolean(L, 5) != 0;
    bool includeFriends = lua_toboolean(L, 6) != 0;
    bool strafeOnly = lua_toboolean(L, 7) != 0;
    Ogre::Vector3 result = instance->calculateCurrentRepulsionVector(MAX_DISTANCE, desiredDirection, skip, includeEnemies, includeFriends, strafeOnly);
    pushVector3(L, result);
    return 1;
}

int FlockingToolsBinding::getSensoryData(lua_State* L)
{
    FlockingTools* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FlockingTools is nil");

    SensoryData* result = instance->getSensoryData();
    return pushObject<SensoryData>(L, result, SensoryDataBinding::getMetatableName());
}

int FlockingToolsBinding::getDistanceToClosestCharacter(lua_State* L)
{
    FlockingTools* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FlockingTools is nil");

    bool enemies = lua_toboolean(L, 2) != 0;
    bool allies = lua_toboolean(L, 3) != 0;
    hand* skip = checkObject<hand>(L, 4, HandBinding::getMetatableName());
    float result = instance->getDistanceToClosestCharacter(enemies, allies, *skip);
    lua_pushnumber(L, result);
    return 1;
}

int FlockingToolsBinding::getOutOfTheWay(lua_State* L)
{
    FlockingTools* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FlockingTools is nil");

    hand* caller = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    instance->getOutOfTheWay(*caller);
    return 0;
}

int FlockingToolsBinding::getRepulsionMagnitude(lua_State* L)
{
    Ogre::Vector3 mypos, repulsionPoint;
    readVector3(L, 1, mypos);
    readVector3(L, 2, repulsionPoint);
    float MAX_DISTANCE = (float)luaL_checknumber(L, 3);
    float distance = (float)luaL_checknumber(L, 4);
    float result = FlockingTools::getRepulsionMagnitude(mypos, repulsionPoint, MAX_DISTANCE, distance);
    lua_pushnumber(L, result);
    return 1;
}

int FlockingToolsBinding::getRepulsionVector(lua_State* L)
{
    Ogre::Vector3 mypos, repulsionPoint;
    readVector3(L, 1, mypos);
    readVector3(L, 2, repulsionPoint);
    float MAX_DISTANCE = (float)luaL_checknumber(L, 3);
    float distance = (float)luaL_checknumber(L, 4);
    Ogre::Vector3 result = FlockingTools::getRepulsionVector(mypos, repulsionPoint, MAX_DISTANCE, distance);
    pushVector3(L, result);
    return 1;
}

int FlockingToolsBinding::clampRepulsionVectorTo90Degrees(lua_State* L)
{
    Ogre::Vector3 repulsionVector, desiredDirection;
    readVector3(L, 1, repulsionVector);
    readVector3(L, 2, desiredDirection);
    bool alwaysStrafe = lua_toboolean(L, 3) != 0;
    FlockingTools::clampRepulsionVectorTo90Degrees(repulsionVector, desiredDirection, alwaysStrafe);
    pushVector3(L, repulsionVector);
    return 1;
}

int FlockingToolsBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int FlockingToolsBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FlockingTools object");
    return 1;
}

void FlockingToolsBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FlockingToolsBinding::gc },
        { "__tostring", FlockingToolsBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "create", FlockingToolsBinding::create },
        { "getDistanceToClosestCharacter", FlockingToolsBinding::getDistanceToClosestCharacter },
        { "getOutOfTheWay", FlockingToolsBinding::getOutOfTheWay },
        { "setCurrentPosition", FlockingToolsBinding::setCurrentPosition },
        { "getRepulsionMagnitude", FlockingToolsBinding::getRepulsionMagnitude },
        { "getRepulsionVector", FlockingToolsBinding::getRepulsionVector },
        { "clampRepulsionVectorTo90Degrees", FlockingToolsBinding::clampRepulsionVectorTo90Degrees },
        { "calculateCurrentRepulsionVector", FlockingToolsBinding::calculateCurrentRepulsionVector },
        { "getSensoryData", FlockingToolsBinding::getSensoryData },
        { 0, 0 }
    };

    registerClass(
        L, 
        FlockingToolsBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FlockingToolsBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "getOutOfTheWayOfCharacter", FlockingTools_get_getOutOfTheWayOfCharacter);
    registerGetter(L, "currentPosition", FlockingTools_get_currentPosition);
    registerGetter(L, "me", FlockingTools_get_me);
    registerGetter(L, "combatMover", FlockingTools_get_combatMover);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "getOutOfTheWayOfCharacter", FlockingTools_set_getOutOfTheWayOfCharacter);
    registerSetter(L, "currentPosition", FlockingTools_set_currentPosition);
    registerSetter(L, "me", FlockingTools_set_me);
    registerSetter(L, "combatMover", FlockingTools_set_combatMover);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua