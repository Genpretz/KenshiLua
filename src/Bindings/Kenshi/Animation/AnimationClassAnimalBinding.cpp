#include "pch.h"
#include "kenshi/Animation/AnimationClassAnimal.h"
#include "AnimationClassAnimalBinding.h"
#include "AnimationClassHumanBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Animation/AnimationClassBinding.h"

namespace KenshiLua
{

static_assert(offsetof(AnimationClassAnimal, maxTurnSpeed) == 0x300, "AnimationClassAnimal::maxTurnSpeed offset mismatch");
static_assert(offsetof(AnimationClassAnimal, _isTurningFar) == 0x304, "AnimationClassAnimal::_isTurningFar offset mismatch");
static_assert(offsetof(AnimationClassAnimal, lastRot) == 0x308, "AnimationClassAnimal::lastRot offset mismatch");

static AnimationClassAnimal* getInstance(lua_State* L, int idx)
{
    return checkObject<AnimationClassAnimal>(L, idx, AnimationClassAnimalBinding::getMetatableName());
}

static int AnimationClassAnimal_get_maxTurnSpeed(lua_State* L)
{
    AnimationClassAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassAnimal is nil");
    lua_pushnumber(L, instance->maxTurnSpeed);
    return 1;
}

static int AnimationClassAnimal_set_maxTurnSpeed(lua_State* L)
{
    AnimationClassAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassAnimal is nil");
    instance->maxTurnSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationClassAnimal_get__isTurningFar(lua_State* L)
{
    AnimationClassAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassAnimal is nil");
    lua_pushboolean(L, instance->_isTurningFar ? 1 : 0);
    return 1;
}

static int AnimationClassAnimal_set__isTurningFar(lua_State* L)
{
    AnimationClassAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassAnimal is nil");
    instance->_isTurningFar = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationClassAnimal_get_lastRot(lua_State* L)
{
    AnimationClassAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassAnimal is nil");
    pushQuaternion(L, instance->lastRot);
    return 1;
}

static int AnimationClassAnimal_set_lastRot(lua_State* L)
{
    AnimationClassAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassAnimal is nil");
    readQuaternion(L, 2, instance->lastRot);
    return 0;
}

int AnimationClassAnimalBinding::isHuman(lua_State* L)
{
    AnimationClassAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassAnimal is nil");
    AnimationClassHuman* result = instance->isHuman();
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<AnimationClassHuman>(L, result, AnimationClassHumanBinding::getMetatableName());
}

int AnimationClassAnimalBinding::_NV_isHuman(lua_State* L)
{
    AnimationClassAnimal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassAnimal is nil");
    AnimationClassHuman* result = instance->_NV_isHuman();
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<AnimationClassHuman>(L, result, AnimationClassHumanBinding::getMetatableName());
}

int AnimationClassAnimalBinding::gc(lua_State* L)
{
    return noopGc(L);
}

int AnimationClassAnimalBinding::tostring(lua_State* L)
{
    AnimationClassAnimal* instance = getInstance(L, 1);
    if (!instance) {
        lua_pushstring(L, "AnimationClassAnimal(nil)");
    } else {
        lua_pushfstring(L, "AnimationClassAnimal(%p)", instance);
    }
    return 1;
}

void AnimationClassAnimalBinding::registerBinding(lua_State* L)
{
    luaL_Reg meta[] = {
        { "__gc", AnimationClassAnimalBinding::gc },
        { "__tostring", AnimationClassAnimalBinding::tostring },
        { 0, 0 }
    };

    luaL_Reg methods[] = {
        { "isHuman", AnimationClassAnimalBinding::isHuman },
        { "_NV_isHuman", AnimationClassAnimalBinding::_NV_isHuman },
        { 0, 0 }
    };

    registerClass(
        L,
        AnimationClassAnimalBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AnimationClassAnimalBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "maxTurnSpeed", AnimationClassAnimal_get_maxTurnSpeed);
    registerGetter(L, "_isTurningFar", AnimationClassAnimal_get__isTurningFar);
    registerGetter(L, "lastRot", AnimationClassAnimal_get_lastRot);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "maxTurnSpeed", AnimationClassAnimal_set_maxTurnSpeed);
    registerSetter(L, "_isTurningFar", AnimationClassAnimal_set__isTurningFar);
    registerSetter(L, "lastRot", AnimationClassAnimal_set_lastRot);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
