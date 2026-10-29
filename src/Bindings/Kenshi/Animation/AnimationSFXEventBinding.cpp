#include "pch.h"
#include "kenshi/Animation/AnimationEvent.h"
#include "AnimationSFXEventBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/CharacterBinding.h"

namespace KenshiLua
{

static_assert(offsetof(AnimationSFXEvent, name) == 0x8, "AnimationSFXEvent::name offset mismatch");
static_assert(offsetof(AnimationSFXEvent, key) == 0x30, "AnimationSFXEvent::key offset mismatch");
static_assert(offsetof(AnimationSFXEvent, value) == 0x58, "AnimationSFXEvent::value offset mismatch");
static_assert(offsetof(AnimationSFXEvent, stop) == 0x80, "AnimationSFXEvent::stop offset mismatch");
static_assert(offsetof(AnimationSFXEvent, isFootstep) == 0xA8, "AnimationSFXEvent::isFootstep offset mismatch");

static AnimationSFXEvent* getInstance(lua_State* L, int idx)
{
    return checkObject<AnimationSFXEvent>(L, idx, AnimationSFXEventBinding::getMetatableName());
}

static int AnimationSFXEvent_get_name(lua_State* L)
{
    AnimationSFXEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationSFXEvent is nil");
    lua_pushstring(L, instance->name.c_str());
    return 1;
}

static int AnimationSFXEvent_set_name(lua_State* L)
{
    AnimationSFXEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationSFXEvent is nil");
    instance->name = luaL_checkstring(L, 2);
    return 0;
}

static int AnimationSFXEvent_get_key(lua_State* L)
{
    AnimationSFXEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationSFXEvent is nil");
    lua_pushstring(L, instance->key.c_str());
    return 1;
}

static int AnimationSFXEvent_set_key(lua_State* L)
{
    AnimationSFXEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationSFXEvent is nil");
    instance->key = luaL_checkstring(L, 2);
    return 0;
}

static int AnimationSFXEvent_get_value(lua_State* L)
{
    AnimationSFXEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationSFXEvent is nil");
    lua_pushstring(L, instance->value.c_str());
    return 1;
}

static int AnimationSFXEvent_set_value(lua_State* L)
{
    AnimationSFXEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationSFXEvent is nil");
    instance->value = luaL_checkstring(L, 2);
    return 0;
}

static int AnimationSFXEvent_get_stop(lua_State* L)
{
    AnimationSFXEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationSFXEvent is nil");
    lua_pushstring(L, instance->stop.c_str());
    return 1;
}

static int AnimationSFXEvent_set_stop(lua_State* L)
{
    AnimationSFXEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationSFXEvent is nil");
    instance->stop = luaL_checkstring(L, 2);
    return 0;
}

static int AnimationSFXEvent_get_isFootstep(lua_State* L)
{
    AnimationSFXEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationSFXEvent is nil");
    lua_pushboolean(L, instance->isFootstep ? 1 : 0);
    return 1;
}

static int AnimationSFXEvent_set_isFootstep(lua_State* L)
{
    AnimationSFXEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationSFXEvent is nil");
    instance->isFootstep = lua_toboolean(L, 2) != 0;
    return 0;
}

int AnimationSFXEventBinding::trigger(lua_State* L)
{
    AnimationSFXEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationSFXEvent is nil");

    Character* character = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->trigger(character);
    return 0;
}

int AnimationSFXEventBinding::_NV_trigger(lua_State* L)
{
    AnimationSFXEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationSFXEvent is nil");

    Character* character = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->_NV_trigger(character);
    return 0;
}

int AnimationSFXEventBinding::finish(lua_State* L)
{
    AnimationSFXEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationSFXEvent is nil");

    Character* character = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->finish(character);
    return 0;
}

int AnimationSFXEventBinding::_NV_finish(lua_State* L)
{
    AnimationSFXEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationSFXEvent is nil");

    Character* character = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->_NV_finish(character);
    return 0;
}

int AnimationSFXEventBinding::toString(lua_State* L)
{
    AnimationSFXEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationSFXEvent is nil");

    std::string result = instance->toString();
    lua_pushstring(L, result.c_str());
    return 1;
}

int AnimationSFXEventBinding::_NV_toString(lua_State* L)
{
    AnimationSFXEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationSFXEvent is nil");

    std::string result = instance->_NV_toString();
    lua_pushstring(L, result.c_str());
    return 1;
}

int AnimationSFXEventBinding::gc(lua_State* L)
{
    return 0;
}

int AnimationSFXEventBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AnimationSFXEvent object");
    return 1;
}

void AnimationSFXEventBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AnimationSFXEventBinding::gc },
        { "__tostring", AnimationSFXEventBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "trigger",     AnimationSFXEventBinding::trigger },
        { "_NV_trigger", AnimationSFXEventBinding::_NV_trigger },
        { "finish",      AnimationSFXEventBinding::finish },
        { "_NV_finish",  AnimationSFXEventBinding::_NV_finish },
        { "toString",    AnimationSFXEventBinding::toString },
        { "_NV_toString",AnimationSFXEventBinding::_NV_toString },
        { 0, 0 }
    };

    registerClass(
        L,
        AnimationSFXEventBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AnimationSFXEventBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "name", AnimationSFXEvent_get_name);
    registerGetter(L, "key", AnimationSFXEvent_get_key);
    registerGetter(L, "value", AnimationSFXEvent_get_value);
    registerGetter(L, "stop", AnimationSFXEvent_get_stop);
    registerGetter(L, "isFootstep", AnimationSFXEvent_get_isFootstep);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "name", AnimationSFXEvent_set_name);
    registerSetter(L, "key", AnimationSFXEvent_set_key);
    registerSetter(L, "value", AnimationSFXEvent_set_value);
    registerSetter(L, "stop", AnimationSFXEvent_set_stop);
    registerSetter(L, "isFootstep", AnimationSFXEvent_set_isFootstep);
    lua_setfield(L, -2, "__setters");
    lua_pop(L, 1);
}

} // namespace KenshiLua
