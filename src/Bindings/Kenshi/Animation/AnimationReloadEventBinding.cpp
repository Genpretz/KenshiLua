#include "pch.h"
#include "kenshi/Animation/AnimationEvent.h"
#include "AnimationReloadEventBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/CharacterBinding.h"

namespace KenshiLua
{

static AnimationReloadEvent* getInstance(lua_State* L, int idx)
{
    return checkObject<AnimationReloadEvent>(L, idx, AnimationReloadEventBinding::getMetatableName());
}

int AnimationReloadEventBinding::trigger(lua_State* L)
{
    AnimationReloadEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationReloadEvent is nil");

    Character* character = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->trigger(character);
    return 0;
}

int AnimationReloadEventBinding::_NV_trigger(lua_State* L)
{
    AnimationReloadEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationReloadEvent is nil");

    Character* character = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->_NV_trigger(character);
    return 0;
}

int AnimationReloadEventBinding::gc(lua_State* L)
{
    return 0;
}

int AnimationReloadEventBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AnimationReloadEvent object");
    return 1;
}

void AnimationReloadEventBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AnimationReloadEventBinding::gc },
        { "__tostring", AnimationReloadEventBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "trigger",     AnimationReloadEventBinding::trigger },
        { "_NV_trigger", AnimationReloadEventBinding::_NV_trigger },
        { 0, 0 }
    };

    registerClass(
        L,
        AnimationReloadEventBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );
}

} // namespace KenshiLua
