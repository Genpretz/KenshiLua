#include "pch.h"
#include <kenshi\CharBody.h>
#include "Bindings/CharBodyBinding.h"
#include "Bindings/CombatClassBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/CharStatsBinding.h"
#include "Bindings/CharMovementBinding.h"
#include "Bindings/TaskerBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/RootObjectBaseBinding.h"
#include "Bindings/TownBaseBinding.h"

namespace KenshiLua
{

static CharBody* getInstance(lua_State* L, int idx)
{
    return checkObject<CharBody>(L, idx, CharBodyBinding::getMetatableName());
}

// --- Getters for CharBody ---
static int CharBody_get_combatClass(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    return pushObject<CombatClass>(L, instance->combatClass, CombatClassBinding::getMetatableName());
}

static int CharBody_get_animation(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    lua_pushlightuserdata(L, (void*)instance->animation);
    return 1;
}

static int CharBody_get_character(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    return pushObject<Character>(L, instance->character, CharacterBinding::getMetatableName());
}

static int CharBody_get_stats(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    return pushObject<CharStats>(L, instance->stats, CharStatsBinding::getMetatableName());
}

static int CharBody_get_target(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    return handBinding::push(L, instance->target);
}

static int CharBody_get_gotItem(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    lua_pushboolean(L, instance->gotItem ? 1 : 0);
    return 1;
}

static int CharBody_get_crouched(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    lua_pushboolean(L, instance->crouched ? 1 : 0);
    return 1;
}

static int CharBody_get_jogMode(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    lua_pushboolean(L, instance->jogMode ? 1 : 0);
    return 1;
}

static int CharBody_get_arbitraryCatchupDist(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    lua_pushnumber(L, instance->arbitraryCatchupDist);
    return 1;
}

// Update with actual binding metatable
static int CharBody_get_ai(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    lua_pushlightuserdata(L, (void*)instance->ai);
    return 1;
}

static int CharBody_get_movement(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    return pushObject<CharMovement>(L, instance->movement, CharMovementBinding::getMetatableName());
}

static int CharBody_get_frameTIME(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    lua_pushnumber(L, instance->frameTIME);
    return 1;
}

static int CharBody_get_currentAction(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    return pushObject<Tasker>(L, instance->currentAction, TaskerBinding::getMetatableName());
}

static int CharBody_get_amIdle(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    lua_pushboolean(L, instance->amIdle ? 1 : 0);
    return 1;
}

// --- Setters for CharBody ---
static int CharBody_set_combatClass(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    instance->combatClass = lua_isnoneornil(L, 2) ? nullptr : checkObject<CombatClass>(L, 2, CombatClassBinding::getMetatableName());
    return 0;
}

static int CharBody_set_character(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    instance->character = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int CharBody_set_stats(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    instance->stats = lua_isnoneornil(L, 2) ? nullptr : checkObject<CharStats>(L, 2, CharStatsBinding::getMetatableName());
    return 0;
}

static int CharBody_set_target(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    instance->target = *val;
    return 0;
}

static int CharBody_set_gotItem(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    instance->gotItem = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharBody_set_crouched(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    instance->crouched = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharBody_set_jogMode(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    instance->jogMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharBody_set_arbitraryCatchupDist(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    instance->arbitraryCatchupDist = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharBody_set_movement(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    instance->movement = lua_isnoneornil(L, 2) ? nullptr : checkObject<CharMovement>(L, 2, CharMovementBinding::getMetatableName());
    return 0;
}

static int CharBody_set_frameTIME(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    instance->frameTIME = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharBody_set_currentAction(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    instance->currentAction = lua_isnoneornil(L, 2) ? nullptr : checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    return 0;
}

static int CharBody_set_amIdle(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    instance->amIdle = lua_toboolean(L, 2) != 0;
    return 0;
}

int CharBodyBinding::_CONSTRUCTOR(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    CharBody* result = instance->_CONSTRUCTOR();
    return pushObject<CharBody>(L, result, CharBodyBinding::getMetatableName());
}

int CharBodyBinding::_DESTRUCTOR(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int CharBodyBinding::update(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    float _time = (float)luaL_checknumber(L, 2);
    instance->update(_time);
    return 0;
}

int CharBodyBinding::_NV_update(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    float _time = (float)luaL_checknumber(L, 2);
    instance->_NV_update(_time);
    return 0;
}

int CharBodyBinding::periodicUpdate(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->periodicUpdate(time);
    return 0;
}

int CharBodyBinding::notifyBodyTaskComplete(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    instance->notifyBodyTaskComplete();
    return 0;
}

int CharBodyBinding::notifyTaskComplete(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    instance->notifyTaskComplete();
    return 0;
}

int CharBodyBinding::_NV_notifyTaskComplete(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    instance->_NV_notifyTaskComplete();
    return 0;
}

int CharBodyBinding::notifyTaskImpossible(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    instance->notifyTaskImpossible();
    return 0;
}

int CharBodyBinding::_NV_notifyTaskImpossible(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    instance->_NV_notifyTaskImpossible();
    return 0;
}

int CharBodyBinding::getCombatClass(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    CombatClass* result = instance->getCombatClass();
    return pushObject<CombatClass>(L, result, CombatClassBinding::getMetatableName());
}

int CharBodyBinding::isCrouched(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    bool result = instance->isCrouched();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharBodyBinding::getPosition(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    Ogre::Vector3 result = instance->getPosition();
    pushVector3(L, result);
    return 1;
}

int CharBodyBinding::_NV_getPosition(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    Ogre::Vector3 result = instance->_NV_getPosition();
    pushVector3(L, result);
    return 1;
}

int CharBodyBinding::getName(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    std::string result = instance->getName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int CharBodyBinding::isCharacter(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    bool result = instance->isCharacter();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharBodyBinding::_NV_isCharacter(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    bool result = instance->_NV_isCharacter();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharBodyBinding::getCharacter(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    Character* result = instance->getCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int CharBodyBinding::_NV_getCharacter(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    Character* result = instance->_NV_getCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int CharBodyBinding::getCharBody(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    CharBody* result = instance->getCharBody();
    return pushObject<CharBody>(L, result, CharBodyBinding::getMetatableName());
}

int CharBodyBinding::_NV_getCharBody(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    CharBody* result = instance->_NV_getCharBody();
    return pushObject<CharBody>(L, result, CharBodyBinding::getMetatableName());
}

int CharBodyBinding::getUpFromRagdoll(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    std::string animationName = luaL_checkstring(L, 2);
    instance->getUpFromRagdoll(animationName);
    return 0;
}

int CharBodyBinding::getPlatoon(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    Platoon* result = instance->getPlatoon();
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

int CharBodyBinding::_NV_getPlatoon(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    Platoon* result = instance->_NV_getPlatoon();
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

int CharBodyBinding::getCurrentAction(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    Tasker* result = instance->getCurrentAction();
    return pushObject<Tasker>(L, result, TaskerBinding::getMetatableName());
}

int CharBodyBinding::getCurrentActionOrMessage(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    Tasker* result = instance->getCurrentActionOrMessage();
    return pushObject<Tasker>(L, result, TaskerBinding::getMetatableName());
}

int CharBodyBinding::endAction(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    instance->endAction();
    return 0;
}

int CharBodyBinding::isIdle(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    bool result = instance->isIdle();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharBodyBinding::getFaction(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    Faction* result = instance->getFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int CharBodyBinding::_endAction(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    instance->_endAction();
    return 0;
}

int CharBodyBinding::_NV__endAction(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    instance->_NV__endAction();
    return 0;
}
static int CharBody_getHandle(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    hand result = instance->getHandle();
    handBinding::push(L, result);
    return 1;
}

static int CharBody_getCurrentSubject(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");
    hand result = instance->getCurrentSubject();
    handBinding::push(L, result);
    return 1;
}

int CharBodyBinding::create(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    CharMovement* m = lua_isnoneornil(L, 2) ? nullptr : checkObject<CharMovement>(L, 2, CharMovementBinding::getMetatableName());
    AI* a = lua_isnoneornil(L, 3) ? nullptr : (AI*)lua_touserdata(L, 3);
    AnimationClass* an = lua_isnoneornil(L, 4) ? nullptr : (AnimationClass*)lua_touserdata(L, 4);
    Character* c = lua_isnoneornil(L, 5) ? nullptr : checkObject<Character>(L, 5, CharacterBinding::getMetatableName());
    CharStats* st = lua_isnoneornil(L, 6) ? nullptr : checkObject<CharStats>(L, 6, CharStatsBinding::getMetatableName());

    instance->create(m, a, an, c, st);
    return 0;
}

int CharBodyBinding::setCurrentAction(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    if (lua_isnumber(L, 2))
    {
        TaskType t = (TaskType)luaL_checkinteger(L, 2);
        RootObject* target = lua_isnoneornil(L, 3) ? nullptr : checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
        bool result = instance->setCurrentAction(t, target);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }
    else
    {
        Tasker* startActionMsg = lua_isnoneornil(L, 2) ? nullptr : checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
        bool result = instance->setCurrentAction(startActionMsg);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }
}

int CharBodyBinding::_NV_setCurrentAction(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    if (lua_isnumber(L, 2))
    {
        TaskType t = (TaskType)luaL_checkinteger(L, 2);
        RootObject* target = lua_isnoneornil(L, 3) ? nullptr : checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
        bool result = instance->_NV_setCurrentAction(t, target);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }
    else
    {
        Tasker* startActionMsg = lua_isnoneornil(L, 2) ? nullptr : checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
        bool result = instance->_NV_setCurrentAction(startActionMsg);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }
}

int CharBodyBinding::notifyPathImpossible(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
    instance->notifyPathImpossible(*h);
    return 0;
}

int CharBodyBinding::_NV_notifyPathImpossible(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
    instance->_NV_notifyPathImpossible(*h);
    return 0;
}

int CharBodyBinding::_move(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    RootObjectBase* who = lua_isnoneornil(L, 2) ? nullptr : checkObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName());
    Ogre::Vector3 location;
    readVector3(L, 3, location);

    instance->_move(who, location);
    return 0;
}

int CharBodyBinding::_patrol(lua_State* L)
{
    CharBody* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharBody is nil");

    Tasker* task = lua_isnoneornil(L, 2) ? nullptr : checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    int end = (int)luaL_checkinteger(L, 3);
    Ogre::Vector3 pos;
    readVector3(L, 4, pos);
    PatrolInfo* area = lua_isnoneornil(L, 5) ? nullptr : (PatrolInfo*)lua_touserdata(L, 5);
    AITaskSytem* taskSys = lua_isnoneornil(L, 6) ? nullptr : (AITaskSytem*)lua_touserdata(L, 6);
    TownBase* town = lua_isnoneornil(L, 7) ? nullptr : checkObject<TownBase>(L, 7, TownBaseBinding::getMetatableName());

    instance->_patrol(task, end, pos, area, taskSys, town);
    return 0;
}

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
        { "_CONSTRUCTOR", CharBodyBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", CharBodyBinding::_DESTRUCTOR },
        { "update", CharBodyBinding::update },
        { "_NV_update", CharBodyBinding::_NV_update },
        { "periodicUpdate", CharBodyBinding::periodicUpdate },
        { "notifyBodyTaskComplete", CharBodyBinding::notifyBodyTaskComplete },
        { "notifyTaskComplete", CharBodyBinding::notifyTaskComplete },
        { "_NV_notifyTaskComplete", CharBodyBinding::_NV_notifyTaskComplete },
        { "notifyTaskImpossible", CharBodyBinding::notifyTaskImpossible },
        { "_NV_notifyTaskImpossible", CharBodyBinding::_NV_notifyTaskImpossible },
        { "getCombatClass", CharBodyBinding::getCombatClass },
        { "isCrouched", CharBodyBinding::isCrouched },
        { "getPosition", CharBodyBinding::getPosition },
        { "_NV_getPosition", CharBodyBinding::_NV_getPosition },
        { "getName", CharBodyBinding::getName },
        { "isCharacter", CharBodyBinding::isCharacter },
        { "_NV_isCharacter", CharBodyBinding::_NV_isCharacter },
        { "getCharacter", CharBodyBinding::getCharacter },
        { "_NV_getCharacter", CharBodyBinding::_NV_getCharacter },
        { "getCharBody", CharBodyBinding::getCharBody },
        { "_NV_getCharBody", CharBodyBinding::_NV_getCharBody },
        { "getUpFromRagdoll", CharBodyBinding::getUpFromRagdoll },
        { "getPlatoon", CharBodyBinding::getPlatoon },
        { "_NV_getPlatoon", CharBodyBinding::_NV_getPlatoon },
        { "getCurrentAction", CharBodyBinding::getCurrentAction },
        { "getCurrentActionOrMessage", CharBodyBinding::getCurrentActionOrMessage },
        { "endAction", CharBodyBinding::endAction },
        { "isIdle", CharBodyBinding::isIdle },
        { "getFaction", CharBodyBinding::getFaction },
        { "_endAction", CharBodyBinding::_endAction },
        { "_NV__endAction", CharBodyBinding::_NV__endAction },
        { "create", CharBodyBinding::create },
        { "setCurrentAction", CharBodyBinding::setCurrentAction },
        { "_NV_setCurrentAction", CharBodyBinding::_NV_setCurrentAction },
        { "notifyPathImpossible", CharBodyBinding::notifyPathImpossible },
        { "_NV_notifyPathImpossible", CharBodyBinding::_NV_notifyPathImpossible },
        { "_move", CharBodyBinding::_move },
        { "_patrol", CharBodyBinding::_patrol },
        { "getHandle", CharBody_getHandle },
        { "getCurrentSubject", CharBody_getCurrentSubject },
        { 0, 0 }
    };

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
    //lua_pushcfunction(L, CharBody_set_animation);
    //lua_setfield(L, -2, "animation");
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
    // lua_pushcfunction(L, CharBody_set_ai);
    // lua_setfield(L, -2, "ai");
    lua_pushcfunction(L, CharBody_set_movement);
    lua_setfield(L, -2, "movement");
    lua_pushcfunction(L, CharBody_set_frameTIME);
    lua_setfield(L, -2, "frameTIME");
    lua_pushcfunction(L, CharBody_set_currentAction);
    lua_setfield(L, -2, "currentAction");
    lua_pushcfunction(L, CharBody_set_amIdle);
    lua_setfield(L, -2, "amIdle");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, CharBodyBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua