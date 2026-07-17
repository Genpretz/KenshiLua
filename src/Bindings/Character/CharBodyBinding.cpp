<<<<<<< HEAD:src/Bindings/Character/CharBodyBinding.cpp
﻿#include "pch.h"
#include "Bindings/Character/CharBodyBinding.h"
#include "Bindings/Character/CharacterBinding.h"
#include "Bindings/World/FactionBinding.h"
#include "Bindings/World/PlatoonBinding.h"
#include "Bindings/Character/CharStatsBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/CharBody.h>

#include <cstring>
#include <cstdio>
=======
#include "pch.h"
#include "kenshi\CharBody.h"
#include "CharBodyBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharStatsBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "TaskerBinding.h"
>>>>>>> main:src/Bindings/CharBodyBinding.cpp

namespace KenshiLua
{

static CharBody* getB(lua_State* L, int idx)
{
    return checkObject<CharBody>(L, idx, CharBodyBinding::getMetatableName());
}

// --- Getters for CharBody ---
static int CharBody_get_combatClass(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    // TODO: Unsupported type for combatClass (CombatClass*)
    return luaL_error(L, "Unsupported property 'combatClass' (type: CombatClass*)");
}

static int CharBody_get_animation(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    // TODO: Unsupported type for animation (AnimationClass*)
    return luaL_error(L, "Unsupported property 'animation' (type: AnimationClass*)");
}

static int CharBody_get_character(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    return pushObject<Character>(L, b->character, CharacterBinding::getMetatableName());
}

static int CharBody_get_stats(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    return pushObject<CharStats>(L, b->stats, CharStatsBinding::getMetatableName());
}

static int CharBody_get_target(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    return handBinding::push(L, b->target);
}

static int CharBody_get_gotItem(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    lua_pushboolean(L, b->gotItem ? 1 : 0);
    return 1;
}

static int CharBody_get_crouched(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    lua_pushboolean(L, b->crouched ? 1 : 0);
    return 1;
}

static int CharBody_get_jogMode(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    lua_pushboolean(L, b->jogMode ? 1 : 0);
    return 1;
}

static int CharBody_get_arbitraryCatchupDist(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    lua_pushnumber(L, b->arbitraryCatchupDist);
    return 1;
}

static int CharBody_get_ai(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    // TODO: Unsupported type for ai (AI*)
    return luaL_error(L, "Unsupported property 'ai' (type: AI*)");
}

static int CharBody_get_movement(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    // TODO: Unsupported type for movement (CharMovement*)
    return luaL_error(L, "Unsupported property 'movement' (type: CharMovement*)");
}

static int CharBody_get_frameTIME(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    lua_pushnumber(L, b->frameTIME);
    return 1;
}

static int CharBody_get_currentAction(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    // TODO: Unsupported type for currentAction (Tasker*)
    return luaL_error(L, "Unsupported property 'currentAction' (type: Tasker*)");
}

static int CharBody_get_amIdle(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    lua_pushboolean(L, b->amIdle ? 1 : 0);
    return 1;
}

// --- Setters for CharBody ---
static int CharBody_set_combatClass(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    return luaL_error(L, "Read-only or unsupported setter type for combatClass");
}

static int CharBody_set_animation(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    return luaL_error(L, "Read-only or unsupported setter type for animation");
}

static int CharBody_set_character(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    return luaL_error(L, "Read-only or unsupported setter type for character");
}

static int CharBody_set_stats(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    return luaL_error(L, "Read-only or unsupported setter type for stats");
}

static int CharBody_set_target(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->target = *val;
    return 0;
}

static int CharBody_set_gotItem(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    b->gotItem = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharBody_set_crouched(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    b->crouched = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharBody_set_jogMode(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    b->jogMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharBody_set_arbitraryCatchupDist(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    b->arbitraryCatchupDist = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharBody_set_ai(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    return luaL_error(L, "Read-only or unsupported setter type for ai");
}

static int CharBody_set_movement(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    return luaL_error(L, "Read-only or unsupported setter type for movement");
}

static int CharBody_set_frameTIME(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    b->frameTIME = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharBody_set_currentAction(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    return luaL_error(L, "Read-only or unsupported setter type for currentAction");
}

static int CharBody_set_amIdle(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    b->amIdle = lua_toboolean(L, 2) != 0;
    return 0;
}

int CharBodyBinding::_DESTRUCTOR(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    b->_DESTRUCTOR();
    return 0;
}

int CharBodyBinding::update(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    float _time = (float)luaL_checknumber(L, 2);
    b->update(_time);
    return 0;
}

int CharBodyBinding::_NV_update(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    float _time = (float)luaL_checknumber(L, 2);
    b->_NV_update(_time);
    return 0;
}

int CharBodyBinding::periodicUpdate(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    float time = (float)luaL_checknumber(L, 2);
    b->periodicUpdate(time);
    return 0;
}

int CharBodyBinding::notifyBodyTaskComplete(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    b->notifyBodyTaskComplete();
    return 0;
}

int CharBodyBinding::notifyTaskComplete(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    b->notifyTaskComplete();
    return 0;
}

int CharBodyBinding::_NV_notifyTaskComplete(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    b->_NV_notifyTaskComplete();
    return 0;
}

int CharBodyBinding::notifyTaskImpossible(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    b->notifyTaskImpossible();
    return 0;
}

int CharBodyBinding::_NV_notifyTaskImpossible(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    b->_NV_notifyTaskImpossible();
    return 0;
}

int CharBodyBinding::isCrouched(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    bool result = b->isCrouched();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharBodyBinding::getPosition(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    Ogre::Vector3 result = b->getPosition();
    pushVector3(L, result);
    return 1;
}

int CharBodyBinding::_NV_getPosition(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    Ogre::Vector3 result = b->_NV_getPosition();
    pushVector3(L, result);
    return 1;
}

int CharBodyBinding::getName(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    std::string result = b->getName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int CharBodyBinding::isCharacter(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    bool result = b->isCharacter();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharBodyBinding::_NV_isCharacter(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    bool result = b->_NV_isCharacter();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharBodyBinding::getCharacter(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    Character* result = b->getCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int CharBodyBinding::_NV_getCharacter(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    Character* result = b->_NV_getCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int CharBodyBinding::getUpFromRagdoll(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    std::string animationName = luaL_checkstring(L, 2);
    b->getUpFromRagdoll(animationName);
    return 0;
}

int CharBodyBinding::getPlatoon(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    Platoon* result = b->getPlatoon();
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

int CharBodyBinding::_NV_getPlatoon(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    Platoon* result = b->_NV_getPlatoon();
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

int CharBodyBinding::endAction(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    b->endAction();
    return 0;
}

int CharBodyBinding::isIdle(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    bool result = b->isIdle();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharBodyBinding::getFaction(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    Faction* result = b->getFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int CharBodyBinding::_endAction(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    b->_endAction();
    return 0;
}

int CharBodyBinding::_NV__endAction(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");

    b->_NV__endAction();
    return 0;
}

static int CharBody_getCurrentAction(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    Tasker* result = b->getCurrentAction();
    return pushObject<Tasker>(L, result, TaskerBinding::getMetatableName());
}

static int CharBody_getCurrentActionOrMessage(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    Tasker* result = b->getCurrentActionOrMessage();
    return pushObject<Tasker>(L, result, TaskerBinding::getMetatableName());
}

static int CharBody_getHandle(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    hand result = b->getHandle();
    handBinding::push(L, result);
    return 1;
}

static int CharBody_getCurrentSubject(lua_State* L)
{
    CharBody* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharBody is nil");
    hand result = b->getCurrentSubject();
    handBinding::push(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 26: CharBody* _CONSTRUCTOR(...) - unsupported return type
  line 29: void create(...) - unsupported arg type
  line 33: bool setCurrentAction(...) - overloaded method
  line 34: bool _NV_setCurrentAction(...) - overloaded method
  line 35: bool setCurrentAction(...) - overloaded method
  line 36: bool _NV_setCurrentAction(...) - overloaded method
  line 42: void notifyPathImpossible(...) - unsupported arg type
  line 43: void _NV_notifyPathImpossible(...) - unsupported arg type
  line 44: CombatClass* getCombatClass(...) - unsupported return type
  line 53: CharBody* getCharBody(...) - unsupported return type
  line 54: CharBody* _NV_getCharBody(...) - unsupported return type
  line 76: void _move(...) - unsupported arg type
  line 77: void _patrol(...) - unsupported arg type
*/

int CharBodyBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int CharBodyBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CharBody object");
    return 1;
}

void CharBodyBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CharBodyBinding::gc },
        { "__tostring", CharBodyBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", CharBodyBinding::_DESTRUCTOR },
        { "update", CharBodyBinding::update },
        { "_NV_update", CharBodyBinding::_NV_update },
        { "periodicUpdate", CharBodyBinding::periodicUpdate },
        { "notifyBodyTaskComplete", CharBodyBinding::notifyBodyTaskComplete },
        { "notifyTaskComplete", CharBodyBinding::notifyTaskComplete },
        { "_NV_notifyTaskComplete", CharBodyBinding::_NV_notifyTaskComplete },
        { "notifyTaskImpossible", CharBodyBinding::notifyTaskImpossible },
        { "_NV_notifyTaskImpossible", CharBodyBinding::_NV_notifyTaskImpossible },
        { "isCrouched", CharBodyBinding::isCrouched },
        { "getPosition", CharBodyBinding::getPosition },
        { "_NV_getPosition", CharBodyBinding::_NV_getPosition },
        { "getName", CharBodyBinding::getName },
        { "isCharacter", CharBodyBinding::isCharacter },
        { "_NV_isCharacter", CharBodyBinding::_NV_isCharacter },
        { "getCharacter", CharBodyBinding::getCharacter },
        { "_NV_getCharacter", CharBodyBinding::_NV_getCharacter },
        { "getUpFromRagdoll", CharBodyBinding::getUpFromRagdoll },
        { "getPlatoon", CharBodyBinding::getPlatoon },
        { "_NV_getPlatoon", CharBodyBinding::_NV_getPlatoon },
        { "endAction", CharBodyBinding::endAction },
        { "isIdle", CharBodyBinding::isIdle },
        { "getFaction", CharBodyBinding::getFaction },
        { "_endAction", CharBodyBinding::_endAction },
        { "_NV__endAction", CharBodyBinding::_NV__endAction },
        { "getCurrentAction", CharBody_getCurrentAction },
        { "getCurrentActionOrMessage", CharBody_getCurrentActionOrMessage },
        { "getHandle", CharBody_getHandle },
        { "getCurrentSubject", CharBody_getCurrentSubject },
        { 0, 0 }
    };
<<<<<<< HEAD:src/Bindings/Character/CharBodyBinding.cpp
    registerClass(L, CharBodyBinding::getMetatableName(), meta, methods, CharBodyBinding::index, CharBodyBinding::newindex);
=======

    registerClass(
        L, 
        CharBodyBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CharBodyBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, CharBody_get_combatClass);
    lua_setfield(L, -2, "combatClass");
    lua_pushcfunction(L, CharBody_get_animation);
    lua_setfield(L, -2, "animation");
    lua_pushcfunction(L, CharBody_get_character);
    lua_setfield(L, -2, "character");
    lua_pushcfunction(L, CharBody_get_stats);
    lua_setfield(L, -2, "stats");
    lua_pushcfunction(L, CharBody_get_target);
    lua_setfield(L, -2, "target");
    lua_pushcfunction(L, CharBody_get_gotItem);
    lua_setfield(L, -2, "gotItem");
    lua_pushcfunction(L, CharBody_get_crouched);
    lua_setfield(L, -2, "crouched");
    lua_pushcfunction(L, CharBody_get_jogMode);
    lua_setfield(L, -2, "jogMode");
    lua_pushcfunction(L, CharBody_get_arbitraryCatchupDist);
    lua_setfield(L, -2, "arbitraryCatchupDist");
    lua_pushcfunction(L, CharBody_get_ai);
    lua_setfield(L, -2, "ai");
    lua_pushcfunction(L, CharBody_get_movement);
    lua_setfield(L, -2, "movement");
    lua_pushcfunction(L, CharBody_get_frameTIME);
    lua_setfield(L, -2, "frameTIME");
    lua_pushcfunction(L, CharBody_get_currentAction);
    lua_setfield(L, -2, "currentAction");
    lua_pushcfunction(L, CharBody_get_amIdle);
    lua_setfield(L, -2, "amIdle");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, CharBody_set_combatClass);
    lua_setfield(L, -2, "combatClass");
    lua_pushcfunction(L, CharBody_set_animation);
    lua_setfield(L, -2, "animation");
    lua_pushcfunction(L, CharBody_set_character);
    lua_setfield(L, -2, "character");
    lua_pushcfunction(L, CharBody_set_stats);
    lua_setfield(L, -2, "stats");
    lua_pushcfunction(L, CharBody_set_target);
    lua_setfield(L, -2, "target");
    lua_pushcfunction(L, CharBody_set_gotItem);
    lua_setfield(L, -2, "gotItem");
    lua_pushcfunction(L, CharBody_set_crouched);
    lua_setfield(L, -2, "crouched");
    lua_pushcfunction(L, CharBody_set_jogMode);
    lua_setfield(L, -2, "jogMode");
    lua_pushcfunction(L, CharBody_set_arbitraryCatchupDist);
    lua_setfield(L, -2, "arbitraryCatchupDist");
    lua_pushcfunction(L, CharBody_set_ai);
    lua_setfield(L, -2, "ai");
    lua_pushcfunction(L, CharBody_set_movement);
    lua_setfield(L, -2, "movement");
    lua_pushcfunction(L, CharBody_set_frameTIME);
    lua_setfield(L, -2, "frameTIME");
    lua_pushcfunction(L, CharBody_set_currentAction);
    lua_setfield(L, -2, "currentAction");
    lua_pushcfunction(L, CharBody_set_amIdle);
    lua_setfield(L, -2, "amIdle");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
>>>>>>> main:src/Bindings/CharBodyBinding.cpp
}

} // namespace KenshiLua