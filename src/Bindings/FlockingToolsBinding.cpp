#include "pch.h"
#include "kenshi\CharMovement.h"
#include "FlockingToolsBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"

namespace KenshiLua
{

static FlockingTools* getB(lua_State* L, int idx)
{
    return checkObject<FlockingTools>(L, idx, FlockingToolsBinding::getMetatableName());
}

// --- Getters for FlockingTools ---
static int FlockingTools_get_getOutOfTheWayOfCharacter(lua_State* L)
{
    FlockingTools* b = getB(L, 1);
    if (!b) return luaL_error(L, "FlockingTools is nil");
    // TODO: Unsupported type for getOutOfTheWayOfCharacter (hand)
    return luaL_error(L, "Unsupported property 'getOutOfTheWayOfCharacter' (type: hand)");
}

static int FlockingTools_get_currentPosition(lua_State* L)
{
    FlockingTools* b = getB(L, 1);
    if (!b) return luaL_error(L, "FlockingTools is nil");
    pushVector3(L, b->currentPosition);
    return 1;
}

static int FlockingTools_get_me(lua_State* L)
{
    FlockingTools* b = getB(L, 1);
    if (!b) return luaL_error(L, "FlockingTools is nil");
    return pushObject<Character>(L, b->me, CharacterBinding::getMetatableName());
}

static int FlockingTools_get_combatMover(lua_State* L)
{
    FlockingTools* b = getB(L, 1);
    if (!b) return luaL_error(L, "FlockingTools is nil");
    // TODO: Unsupported type for combatMover (CombatMovementController*)
    return luaL_error(L, "Unsupported property 'combatMover' (type: CombatMovementController*)");
}

// --- Setters for FlockingTools ---
static int FlockingTools_set_getOutOfTheWayOfCharacter(lua_State* L)
{
    FlockingTools* b = getB(L, 1);
    if (!b) return luaL_error(L, "FlockingTools is nil");
    return luaL_error(L, "Read-only or unsupported setter type for getOutOfTheWayOfCharacter");
}

static int FlockingTools_set_currentPosition(lua_State* L)
{
    FlockingTools* b = getB(L, 1);
    if (!b) return luaL_error(L, "FlockingTools is nil");
    readVector3(L, 2, b->currentPosition);
    return 0;
}

static int FlockingTools_set_me(lua_State* L)
{
    FlockingTools* b = getB(L, 1);
    if (!b) return luaL_error(L, "FlockingTools is nil");
    return luaL_error(L, "Read-only or unsupported setter type for me");
}

static int FlockingTools_set_combatMover(lua_State* L)
{
    FlockingTools* b = getB(L, 1);
    if (!b) return luaL_error(L, "FlockingTools is nil");
    return luaL_error(L, "Read-only or unsupported setter type for combatMover");
}

int FlockingToolsBinding::_CONSTRUCTOR(lua_State* L)
{
    FlockingTools* b = getB(L, 1);
    if (!b) return luaL_error(L, "FlockingTools is nil");

    FlockingTools* result = b->_CONSTRUCTOR();
    return pushObject<FlockingTools>(L, result, FlockingToolsBinding::getMetatableName());
}

int FlockingToolsBinding::setCurrentPosition(lua_State* L)
{
    FlockingTools* b = getB(L, 1);
    if (!b) return luaL_error(L, "FlockingTools is nil");

    Ogre::Vector3 _pos;
    readVector3(L, 2, _pos);
    b->setCurrentPosition(_pos);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 241: void create(...) - unsupported arg type
  line 242: float getDistanceToClosestCharacter(...) - unsupported arg type
  line 243: void getOutOfTheWay(...) - unsupported arg type
  line 245: float getRepulsionMagnitude(...) - static method
  line 246: Ogre::Vector3 getRepulsionVector(...) - static method
  line 247: void clampRepulsionVectorTo90Degrees(...) - static method
  line 248: Ogre::Vector3 calculateCurrentRepulsionVector(...) - unsupported arg type
  line 249: SensoryData* getSensoryData(...) - unsupported return type
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
        { "setCurrentPosition", FlockingToolsBinding::setCurrentPosition },
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
    lua_pushcfunction(L, FlockingTools_get_getOutOfTheWayOfCharacter);
    lua_setfield(L, -2, "getOutOfTheWayOfCharacter");
    lua_pushcfunction(L, FlockingTools_get_currentPosition);
    lua_setfield(L, -2, "currentPosition");
    lua_pushcfunction(L, FlockingTools_get_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, FlockingTools_get_combatMover);
    lua_setfield(L, -2, "combatMover");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, FlockingTools_set_getOutOfTheWayOfCharacter);
    lua_setfield(L, -2, "getOutOfTheWayOfCharacter");
    lua_pushcfunction(L, FlockingTools_set_currentPosition);
    lua_setfield(L, -2, "currentPosition");
    lua_pushcfunction(L, FlockingTools_set_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, FlockingTools_set_combatMover);
    lua_setfield(L, -2, "combatMover");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua