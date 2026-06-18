#include "pch.h"
#include "Bindings/CharBodyBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/CharStatsBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/CharBody.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static CharBody* getS(lua_State* L, int idx)
{
    return checkObject<CharBody>(L, idx, CharBodyBinding::getMetatableName());
}

int CharBodyBinding::gc(lua_State* L) { return noopGc(L); }

int CharBodyBinding::tostring(lua_State* L)
{
    CharBody* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int CharBodyBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, CharBodyBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    CharBody* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    // TODO CombatClass* combatClass; unsupported __index type from header line 58
    // TODO AnimationClass* animation; unsupported __index type from header line 59
    if (strcmp(key, "character") == 0) { return pushObject<Character>(L, s->character, CharacterBinding::getMetatableName()); }
    if (strcmp(key, "stats") == 0) { return pushObject<CharStats>(L, s->stats, CharStatsBinding::getMetatableName()); }
    // TODO hand target; unsupported __index type from header line 62
    if (strcmp(key, "gotItem") == 0) { lua_pushboolean(L, s->gotItem ? 1 : 0); return 1; }
    if (strcmp(key, "crouched") == 0) { lua_pushboolean(L, s->crouched ? 1 : 0); return 1; }
    if (strcmp(key, "jogMode") == 0) { lua_pushboolean(L, s->jogMode ? 1 : 0); return 1; }
    if (strcmp(key, "arbitraryCatchupDist") == 0) { lua_pushnumber(L, s->arbitraryCatchupDist); return 1; }
    // TODO AI* ai; unsupported __index type from header line 74
    // TODO CharMovement* movement; unsupported __index type from header line 75
    if (strcmp(key, "frameTIME") == 0) { lua_pushnumber(L, s->frameTIME); return 1; }
    // TODO Tasker* currentAction; unsupported __index type from header line 82
    if (strcmp(key, "amIdle") == 0) { lua_pushboolean(L, s->amIdle ? 1 : 0); return 1; }

    lua_pushnil(L);
    return 1;
}

int CharBodyBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    // TODO CombatClass* combatClass; unsupported __newindex type from header line 58
    // TODO AnimationClass* animation; unsupported __newindex type from header line 59
    // TODO Character* character; unsupported __newindex type from header line 60
    // TODO CharStats* stats; unsupported __newindex type from header line 61
    // TODO hand target; unsupported __newindex type from header line 62
    if (strcmp(key, "gotItem") == 0) { s->gotItem = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "crouched") == 0) { s->crouched = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "jogMode") == 0) { s->jogMode = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "arbitraryCatchupDist") == 0) { s->arbitraryCatchupDist = (float)luaL_checknumber(L, 3); return 0; }
    // TODO AI* ai; unsupported __newindex type from header line 74
    // TODO CharMovement* movement; unsupported __newindex type from header line 75
    if (strcmp(key, "frameTIME") == 0) { s->frameTIME = (float)luaL_checknumber(L, 3); return 0; }
    // TODO Tasker* currentAction; unsupported __newindex type from header line 82
    if (strcmp(key, "amIdle") == 0) { s->amIdle = lua_toboolean(L, 3) != 0; return 0; }

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int CharBodyBinding::_CONSTRUCTOR(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    CharBody* result = s->_CONSTRUCTOR();
    return pushObject<CharBody>(L, result, CharBodyBinding::getMetatableName());
}

int CharBodyBinding::_DESTRUCTOR(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    s->_DESTRUCTOR();
    return 0;
}

int CharBodyBinding::update(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    float _time = (float)luaL_checknumber(L, 2);
    s->update(_time);
    return 0;
}

int CharBodyBinding::_NV_update(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    float _time = (float)luaL_checknumber(L, 2);
    s->_NV_update(_time);
    return 0;
}

int CharBodyBinding::periodicUpdate(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    float time = (float)luaL_checknumber(L, 2);
    s->periodicUpdate(time);
    return 0;
}

int CharBodyBinding::notifyBodyTaskComplete(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    s->notifyBodyTaskComplete();
    return 0;
}

int CharBodyBinding::notifyTaskComplete(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    s->notifyTaskComplete();
    return 0;
}

int CharBodyBinding::_NV_notifyTaskComplete(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    s->_NV_notifyTaskComplete();
    return 0;
}

int CharBodyBinding::notifyTaskImpossible(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    s->notifyTaskImpossible();
    return 0;
}

int CharBodyBinding::_NV_notifyTaskImpossible(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    s->_NV_notifyTaskImpossible();
    return 0;
}

int CharBodyBinding::isCrouched(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    bool result = s->isCrouched();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharBodyBinding::getName(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    std::string result = s->getName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int CharBodyBinding::isCharacter(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    bool result = s->isCharacter();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharBodyBinding::_NV_isCharacter(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    bool result = s->_NV_isCharacter();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharBodyBinding::getCharacter(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    Character* result = s->getCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int CharBodyBinding::_NV_getCharacter(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    Character* result = s->_NV_getCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int CharBodyBinding::getCharBody(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    CharBody* result = s->getCharBody();
    return pushObject<CharBody>(L, result, CharBodyBinding::getMetatableName());
}

int CharBodyBinding::_NV_getCharBody(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    CharBody* result = s->_NV_getCharBody();
    return pushObject<CharBody>(L, result, CharBodyBinding::getMetatableName());
}

int CharBodyBinding::getUpFromRagdoll(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    std::string animationName = luaL_checkstring(L, 2);
    s->getUpFromRagdoll(animationName);
    return 0;
}

int CharBodyBinding::getPlatoon(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    Platoon* result = s->getPlatoon();
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

int CharBodyBinding::_NV_getPlatoon(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    Platoon* result = s->_NV_getPlatoon();
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

int CharBodyBinding::endAction(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    s->endAction();
    return 0;
}

int CharBodyBinding::isIdle(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    bool result = s->isIdle();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharBodyBinding::getFaction(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    Faction* result = s->getFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int CharBodyBinding::_endAction(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    s->_endAction();
    return 0;
}

int CharBodyBinding::_NV__endAction(lua_State* L)
{
    CharBody* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharBody is nil");

    s->_NV__endAction();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 29: void create(...) - unsupported arg type
  line 33: bool setCurrentAction(...) - overloaded method
  line 34: bool _NV_setCurrentAction(...) - overloaded method
  line 35: bool setCurrentAction(...) - overloaded method
  line 36: bool _NV_setCurrentAction(...) - overloaded method
  line 42: void notifyPathImpossible(...) - unsupported arg type
  line 43: void _NV_notifyPathImpossible(...) - unsupported arg type
  line 44: CombatClass* getCombatClass(...) - unsupported return type
  line 46: Ogre::Vector3 getPosition(...) - unsupported return type
  line 47: Ogre::Vector3 _NV_getPosition(...) - unsupported return type
  line 67: Tasker* getCurrentAction(...) - unsupported return type
  line 68: Tasker* getCurrentActionOrMessage(...) - unsupported return type
  line 72: hand getHandle(...) - unsupported return type
  line 76: void _move(...) - unsupported arg type
  line 77: void _patrol(...) - unsupported arg type
  line 78: hand getCurrentSubject(...) - unsupported return type
*/

void CharBodyBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CharBodyBinding::gc },
        { "__tostring", CharBodyBinding::tostring },
        { "__index",    CharBodyBinding::index },
        { "__newindex", CharBodyBinding::newindex },
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
        { "isCrouched", CharBodyBinding::isCrouched },
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
        { "endAction", CharBodyBinding::endAction },
        { "isIdle", CharBodyBinding::isIdle },
        { "getFaction", CharBodyBinding::getFaction },
        { "_endAction", CharBodyBinding::_endAction },
        { "_NV__endAction", CharBodyBinding::_NV__endAction },
        { 0, 0 }
    };
    registerClass(L, CharBodyBinding::getMetatableName(), meta, methods);
}

} // namespace KenshiLua