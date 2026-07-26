#include "pch.h"
#include "kenshi\CharMovement.h"
#include "FlockingToolsBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/CombatMovementControllerBinding.h"
#include "Bindings/SensoryDataBinding.h"

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
    return handBinding::push(L, instance->getOutOfTheWayOfCharacter);
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
    instance->getOutOfTheWayOfCharacter = *checkObject<hand>(L, 2, handBinding::getMetatableName());
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

int FlockingToolsBinding::_CONSTRUCTOR(lua_State* L)
{
    FlockingTools* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FlockingTools is nil");

    FlockingTools* result = instance->_CONSTRUCTOR();
    return pushObject<FlockingTools>(L, result, FlockingToolsBinding::getMetatableName());
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

/*
Skipped methods needing manual binding:
  line 242: float getDistanceToClosestCharacter(...) - non-string reference arg
  line 243: void getOutOfTheWay(...) - non-string reference arg
  line 245: float getRepulsionMagnitude(...) - static method
  line 246: Ogre::Vector3 getRepulsionVector(...) - static method
  line 247: void clampRepulsionVectorTo90Degrees(...) - static method
*/

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
        { "_CONSTRUCTOR", FlockingToolsBinding::_CONSTRUCTOR },
        { "create", FlockingToolsBinding::create },
        { "setCurrentPosition", FlockingToolsBinding::setCurrentPosition },
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