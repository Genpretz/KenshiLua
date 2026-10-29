#include "pch.h"
#include "kenshi/Animation/AnimationEvent.h"
#include "AnimationEventBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/CharacterBinding.h"

namespace KenshiLua
{

static AnimationEvent* getInstance(lua_State* L, int idx)
{
    return checkObject<AnimationEvent>(L, idx, AnimationEventBinding::getMetatableName());
}

int AnimationEventBinding::trigger(lua_State* L)
{
    AnimationEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationEvent is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->trigger(c);
    return 0;
}

int AnimationEventBinding::_NV_trigger(lua_State* L)
{
    AnimationEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationEvent is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->_NV_trigger(c);
    return 0;
}

int AnimationEventBinding::finish(lua_State* L)
{
    AnimationEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationEvent is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->finish(c);
    return 0;
}

int AnimationEventBinding::_NV_finish(lua_State* L)
{
    AnimationEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationEvent is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->_NV_finish(c);
    return 0;
}

int AnimationEventBinding::toString(lua_State* L)
{
    AnimationEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationEvent is nil");

    std::string result = instance->toString();
    lua_pushstring(L, result.c_str());
    return 1;
}

int AnimationEventBinding::_NV_toString(lua_State* L)
{
    AnimationEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationEvent is nil");

    std::string result = instance->_NV_toString();
    lua_pushstring(L, result.c_str());
    return 1;
}

int AnimationEventBinding::gc(lua_State* L)
{
    return 0;
}

int AnimationEventBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AnimationEvent object");
    return 1;
}

void AnimationEventBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AnimationEventBinding::gc },
        { "__tostring", AnimationEventBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "trigger",     AnimationEventBinding::trigger },
        { "_NV_trigger", AnimationEventBinding::_NV_trigger },
        { "finish",      AnimationEventBinding::finish },
        { "_NV_finish",  AnimationEventBinding::_NV_finish },
        { "toString",    AnimationEventBinding::toString },
        { "_NV_toString",AnimationEventBinding::_NV_toString },
        { 0, 0 }
    };

    registerClass(
        L,
        AnimationEventBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );
}

} // namespace KenshiLua
