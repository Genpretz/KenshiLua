#include "pch.h"
#include "kenshi/Animation/AnimationClass.h"
#include "AnimationEventsBinding.h"
#include "AnimationEventBinding.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static_assert(offsetof(AnimationEvents, events) == 0x0, "AnimationEvents::events offset mismatch");
static_assert(offsetof(AnimationEvents, lastFrame) == 0x18, "AnimationEvents::lastFrame offset mismatch");
static_assert(offsetof(AnimationEvents, nextEvent) == 0x1C, "AnimationEvents::nextEvent offset mismatch");
static_assert(offsetof(AnimationEvents, character) == 0x20, "AnimationEvents::character offset mismatch");

static AnimationEvents* getInstance(lua_State* L, int idx)
{
    return checkObject<AnimationEvents>(L, idx, AnimationEventsBinding::getMetatableName());
}

static int AnimationEvents_get_lastFrame(lua_State* L)
{
    AnimationEvents* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationEvents is nil");
    lua_pushnumber(L, (lua_Number)instance->lastFrame);
    return 1;
}

static int AnimationEvents_set_lastFrame(lua_State* L)
{
    AnimationEvents* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationEvents is nil");
    instance->lastFrame = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationEvents_get_nextEvent(lua_State* L)
{
    AnimationEvents* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationEvents is nil");
    lua_pushinteger(L, (lua_Integer)instance->nextEvent);
    return 1;
}

static int AnimationEvents_set_nextEvent(lua_State* L)
{
    AnimationEvents* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationEvents is nil");
    instance->nextEvent = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int AnimationEvents_get_character(lua_State* L)
{
    AnimationEvents* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationEvents is nil");
    if (!instance->character) { lua_pushnil(L); return 1; }
    return pushObject<Character>(L, instance->character, CharacterBinding::getMetatableName());
}

static int AnimationEvents_set_character(lua_State* L)
{
    AnimationEvents* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationEvents is nil");
    instance->character = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

int AnimationEventsBinding::setInitialFrame(lua_State* L)
{
    AnimationEvents* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationEvents is nil");
    float f = (float)luaL_checknumber(L, 2);
    instance->setInitialFrame(f);
    return 0;
}

int AnimationEventsBinding::update(lua_State* L)
{
    AnimationEvents* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationEvents is nil");
    float frame = (float)luaL_checknumber(L, 2);
    bool sound = lua_toboolean(L, 3) != 0;
    instance->update(frame, sound);
    return 0;
}

int AnimationEventsBinding::addEvent(lua_State* L)
{
    AnimationEvents* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationEvents is nil");
    float time = (float)luaL_checknumber(L, 3);
    AnimationEvent* ev = testObject<AnimationEvent>(L, 2, AnimationEventBinding::getMetatableName());
    if (ev) {
        instance->addEvent(ev, time);
        return 0;
    }
    GameData* gd = testObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    if (gd) {
        instance->addEvent(gd, time);
        return 0;
    }
    return luaL_error(L, "Argument 2 to addEvent must be AnimationEvent or GameData");
}

int AnimationEventsBinding::size(lua_State* L)
{
    AnimationEvents* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationEvents is nil");
    lua_pushinteger(L, (lua_Integer)instance->size());
    return 1;
}

int AnimationEventsBinding::gc(lua_State* L)
{
    return 0;
}

int AnimationEventsBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AnimationEvents object");
    return 1;
}

void AnimationEventsBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AnimationEventsBinding::gc },
        { "__tostring", AnimationEventsBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setInitialFrame", AnimationEventsBinding::setInitialFrame },
        { "update", AnimationEventsBinding::update },
        { "addEvent", AnimationEventsBinding::addEvent },
        { "size", AnimationEventsBinding::size },
        { 0, 0 }
    };

    registerClass(
        L,
        AnimationEventsBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AnimationEventsBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "lastFrame", AnimationEvents_get_lastFrame);
    registerGetter(L, "nextEvent", AnimationEvents_get_nextEvent);
    registerGetter(L, "character", AnimationEvents_get_character);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "lastFrame", AnimationEvents_set_lastFrame);
    registerSetter(L, "nextEvent", AnimationEvents_set_nextEvent);
    registerSetter(L, "character", AnimationEvents_set_character);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua

