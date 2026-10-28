#include "pch.h"
#include "kenshi/Animation/AnimationEvent.h"
#include "AnimationGroundEventBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/CharacterBinding.h"

namespace KenshiLua
{

static_assert(offsetof(AnimationGroundEvent, bone) == 0x8, "AnimationGroundEvent::bone offset mismatch");

static AnimationGroundEvent* getInstance(lua_State* L, int idx)
{
    return checkObject<AnimationGroundEvent>(L, idx, AnimationGroundEventBinding::getMetatableName());
}

static int AnimationGroundEvent_get_bone(lua_State* L)
{
    AnimationGroundEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationGroundEvent is nil");
    lua_pushstring(L, instance->bone.c_str());
    return 1;
}

static int AnimationGroundEvent_set_bone(lua_State* L)
{
    AnimationGroundEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationGroundEvent is nil");
    instance->bone = luaL_checkstring(L, 2);
    return 0;
}

int AnimationGroundEventBinding::trigger(lua_State* L)
{
    AnimationGroundEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationGroundEvent is nil");

    Character* character = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->trigger(character);
    return 0;
}

int AnimationGroundEventBinding::_NV_trigger(lua_State* L)
{
    AnimationGroundEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationGroundEvent is nil");

    Character* character = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->_NV_trigger(character);
    return 0;
}

int AnimationGroundEventBinding::toString(lua_State* L)
{
    AnimationGroundEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationGroundEvent is nil");

    std::string result = instance->toString();
    lua_pushstring(L, result.c_str());
    return 1;
}

int AnimationGroundEventBinding::_NV_toString(lua_State* L)
{
    AnimationGroundEvent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationGroundEvent is nil");

    std::string result = instance->_NV_toString();
    lua_pushstring(L, result.c_str());
    return 1;
}

int AnimationGroundEventBinding::gc(lua_State* L)
{
    return 0;
}

int AnimationGroundEventBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AnimationGroundEvent object");
    return 1;
}

void AnimationGroundEventBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AnimationGroundEventBinding::gc },
        { "__tostring", AnimationGroundEventBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "trigger",     AnimationGroundEventBinding::trigger },
        { "_NV_trigger", AnimationGroundEventBinding::_NV_trigger },
        { "toString",    AnimationGroundEventBinding::toString },
        { "_NV_toString",AnimationGroundEventBinding::_NV_toString },
        { 0, 0 }
    };

    registerClass(
        L,
        AnimationGroundEventBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AnimationGroundEventBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "bone", AnimationGroundEvent_get_bone);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "bone", AnimationGroundEvent_set_bone);
    lua_setfield(L, -2, "__setters");
    lua_pop(L, 1);
}

} // namespace KenshiLua
