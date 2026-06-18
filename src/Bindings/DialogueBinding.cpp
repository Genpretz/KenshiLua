#include "pch.h"
#include "Bindings/DialogueBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/HandBinding.h"
#include "Bindings/CharStatsBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Dialogue.h>
#include <kenshi/Character.h>
#include <kenshi/util/hand.h>

namespace KenshiLua
{

static Dialogue* getD(lua_State* L, int idx)
{
    return checkObject<Dialogue>(L, idx, DialogueBinding::getMetatableName());
}

int DialogueBinding::gc(lua_State* L)       { return noopGc(L); }

int DialogueBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    // 1. Check the metatable first so obj:method() syntax continues to work.
    luaL_getmetatable(L, DialogueBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;   // found a method - return it
    lua_pop(L, 2);  // pop nil result + metatable

    // 2. Fall through to raw member variable access.
    Dialogue* d = getD(L, 1);
    if (!d) { lua_pushnil(L); return 1; }

    // --- boolean members ---
    if (strcmp(key, "hasEnded") == 0 || strcmp(key, "_hasEnded") == 0) { lua_pushboolean(L, d->_hasEnded ? 1 : 0); return 1; }
    if (strcmp(key, "shouting") == 0) { lua_pushboolean(L, d->shouting ? 1 : 0); return 1; }
    if (strcmp(key, "staysOnScreen") == 0) { lua_pushboolean(L, d->staysOnScreen ? 1 : 0); return 1; }

    // --- unique object members ---
    if (strcmp(key, "character") == 0 || strcmp(key, "me") == 0) {
        return pushObject<Character>(L, d->me, CharacterBinding::getMetatableName());
    }
    if (strcmp(key, "conversationTarget") == 0) {
        return HandBinding::pushHand(L, d->conversationTarget);
    }
    if (strcmp(key, "stats") == 0) {
        return pushObject<CharStats>(L, d->stats, CharStatsBinding::getMetatableName());
    }

    lua_pushnil(L);
    return 1;
}

int DialogueBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    Dialogue* d = getD(L, 1);
    if (!d) return luaL_error(L, "Dialogue is nil");

    // --- writable properties ---
    if (strcmp(key, "shouting") == 0) {
        d->shouting = (lua_toboolean(L, 3) != 0);
        return 0;
    }
    if (strcmp(key, "staysOnScreen") == 0) {
        d->staysOnScreen = (lua_toboolean(L, 3) != 0);
        return 0;
    }

    return luaL_error(L, "Dialogue: field '%s' is read-only or does not exist", key);
}
int DialogueBinding::tostring(lua_State* L) { return genericTostringPtr(L, "Dialogue", (void*)getD(L, 1)); }

int DialogueBinding::getCharacter(lua_State* L)
{
    Dialogue* d = getD(L, 1);
    if (!d) { lua_pushnil(L); return 1; }
    return pushObject<Character>(L, d->me, CharacterBinding::getMetatableName());
}

int DialogueBinding::getConversationTarget(lua_State* L)
{
    Dialogue* d = getD(L, 1);
    if (!d) { lua_pushnil(L); return 1; }
    hand h = d->conversationTarget;
    if (!h.isValid()) { lua_pushnil(L); return 1; }
    return pushObject<Character>(L, h.getCharacter(), CharacterBinding::getMetatableName());
}

int DialogueBinding::hasDialogueEvent(lua_State* L)
{
    Dialogue* d = getD(L, 1);
    if (!d) { lua_pushboolean(L, 0); return 1; }
    int ev = (int)luaL_checkinteger(L, 2);
    lua_pushboolean(L, d->hasDialogueEvent((EventTriggerEnum)ev) ? 1 : 0);
    return 1;
}

int DialogueBinding::willTalkToEnemies(lua_State* L)    { Dialogue* d = getD(L, 1); lua_pushboolean(L, d && d->willTalkToEnemies() ? 1 : 0); return 1; }
int DialogueBinding::conversationHasEnded(lua_State* L) { Dialogue* d = getD(L, 1); lua_pushboolean(L, !d || d->conversationHasEnded() ? 1 : 0); return 1; }

int DialogueBinding::sendEvent(lua_State* L)
{
    Dialogue* d = getD(L, 1);
    if (!d) return luaL_error(L, "Dialogue is nil");
    Character* target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    if (!target) return luaL_error(L, "Target Character expected");
    int ev = (int)luaL_checkinteger(L, 3);
    lua_pushboolean(L, d->sendEvent(target, (EventTriggerEnum)ev) ? 1 : 0);
    return 1;
}

int DialogueBinding::sendEventOverride(lua_State* L)
{
    Dialogue* d = getD(L, 1);
    if (!d) return luaL_error(L, "Dialogue is nil");
    Character* target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    if (!target) return luaL_error(L, "Target Character expected");
    int ev = (int)luaL_checkinteger(L, 3);
    bool force = lua_toboolean(L, 4) != 0;
    lua_pushboolean(L, d->sendEventOverride(target, (EventTriggerEnum)ev, force) ? 1 : 0);
    return 1;
}

int DialogueBinding::endDialogue(lua_State* L)
{
    Dialogue* d = getD(L, 1);
    if (!d) return 0;
    bool definitelyEnd = lua_toboolean(L, 2) != 0;
    d->endDialogue(definitelyEnd);
    return 0;
}

int DialogueBinding::isValid(lua_State* L)
{
    Dialogue* d = getD(L, 1);
    lua_pushboolean(L, d && d->me ? 1 : 0);
    return 1;
}

void DialogueBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DialogueBinding::gc },
        { "__tostring", DialogueBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getCharacter",           DialogueBinding::getCharacter },
        { "getConversationTarget",  DialogueBinding::getConversationTarget },
        { "hasDialogueEvent",       DialogueBinding::hasDialogueEvent },
        { "willTalkToEnemies",      DialogueBinding::willTalkToEnemies },
        { "conversationHasEnded",   DialogueBinding::conversationHasEnded },
        { "sendEvent",              DialogueBinding::sendEvent },
        { "sendEventOverride",      DialogueBinding::sendEventOverride },
        { "endDialogue",            DialogueBinding::endDialogue },
        { "isValid",                DialogueBinding::isValid },
        { 0, 0 }
    };
    registerClass(L, DialogueBinding::getMetatableName(), meta, methods, DialogueBinding::index, DialogueBinding::newindex);
}

} // namespace KenshiLua
