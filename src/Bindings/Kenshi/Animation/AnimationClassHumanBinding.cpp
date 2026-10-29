#include "pch.h"
#include "kenshi/Animation/AnimationClassHuman.h"
#include "AnimationClassHumanBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Animation/AnimationClassBinding.h"
#include "Bindings/Kenshi/WeaponBinding.h"

namespace KenshiLua
{

static_assert(offsetof(AnimationClassHuman, usingRightArm) == 0x300, "AnimationClassHuman::usingRightArm offset mismatch");
static_assert(offsetof(AnimationClassHuman, stanceAnimation) == 0x308, "AnimationClassHuman::stanceAnimation offset mismatch");
static_assert(offsetof(AnimationClassHuman, lookDirection) == 0x330, "AnimationClassHuman::lookDirection offset mismatch");
static_assert(offsetof(AnimationClassHuman, hipspos) == 0x33C, "AnimationClassHuman::hipspos offset mismatch");
static_assert(offsetof(AnimationClassHuman, breatheTimer) == 0x348, "AnimationClassHuman::breatheTimer offset mismatch");

static AnimationClassHuman* getInstance(lua_State* L, int idx)
{
    return checkObject<AnimationClassHuman>(L, idx, AnimationClassHumanBinding::getMetatableName());
}

static int AnimationClassHuman_get_usingRightArm(lua_State* L)
{
    AnimationClassHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassHuman is nil");
    lua_pushboolean(L, instance->usingRightArm ? 1 : 0);
    return 1;
}

static int AnimationClassHuman_set_usingRightArm(lua_State* L)
{
    AnimationClassHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassHuman is nil");
    instance->usingRightArm = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationClassHuman_get_usingLeftArm(lua_State* L)
{
    AnimationClassHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassHuman is nil");
    lua_pushboolean(L, instance->usingLeftArm ? 1 : 0);
    return 1;
}

static int AnimationClassHuman_set_usingLeftArm(lua_State* L)
{
    AnimationClassHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassHuman is nil");
    instance->usingLeftArm = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationClassHuman_get_disabledRightArm(lua_State* L)
{
    AnimationClassHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassHuman is nil");
    lua_pushboolean(L, instance->disabledRightArm ? 1 : 0);
    return 1;
}

static int AnimationClassHuman_set_disabledRightArm(lua_State* L)
{
    AnimationClassHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassHuman is nil");
    instance->disabledRightArm = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationClassHuman_get_disabledLeftArm(lua_State* L)
{
    AnimationClassHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassHuman is nil");
    lua_pushboolean(L, instance->disabledLeftArm ? 1 : 0);
    return 1;
}

static int AnimationClassHuman_set_disabledLeftArm(lua_State* L)
{
    AnimationClassHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassHuman is nil");
    instance->disabledLeftArm = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationClassHuman_get_stanceAnimation(lua_State* L)
{
    AnimationClassHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassHuman is nil");
    lua_pushlstring(L, instance->stanceAnimation.c_str(), instance->stanceAnimation.size());
    return 1;
}

static int AnimationClassHuman_set_stanceAnimation(lua_State* L)
{
    AnimationClassHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassHuman is nil");
    size_t len = 0;
    const char* str = luaL_checklstring(L, 2, &len);
    instance->stanceAnimation.assign(str, len);
    return 0;
}

static int AnimationClassHuman_get_lookDirection(lua_State* L)
{
    AnimationClassHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassHuman is nil");
    pushVector3(L, instance->lookDirection);
    return 1;
}

static int AnimationClassHuman_set_lookDirection(lua_State* L)
{
    AnimationClassHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassHuman is nil");
    readVector3(L, 2, instance->lookDirection);
    return 0;
}

static int AnimationClassHuman_get_hipspos(lua_State* L)
{
    AnimationClassHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassHuman is nil");
    pushVector3(L, instance->hipspos);
    return 1;
}

static int AnimationClassHuman_set_hipspos(lua_State* L)
{
    AnimationClassHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassHuman is nil");
    readVector3(L, 2, instance->hipspos);
    return 0;
}

static int AnimationClassHuman_get_breatheTimer(lua_State* L)
{
    AnimationClassHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassHuman is nil");
    lua_pushnumber(L, instance->breatheTimer);
    return 1;
}

static int AnimationClassHuman_set_breatheTimer(lua_State* L)
{
    AnimationClassHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassHuman is nil");
    instance->breatheTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

int AnimationClassHumanBinding::isHuman(lua_State* L)
{
    AnimationClassHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassHuman is nil");
    AnimationClassHuman* result = instance->isHuman();
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<AnimationClassHuman>(L, result, AnimationClassHumanBinding::getMetatableName());
}

int AnimationClassHumanBinding::_NV_isHuman(lua_State* L)
{
    AnimationClassHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassHuman is nil");
    AnimationClassHuman* result = instance->_NV_isHuman();
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<AnimationClassHuman>(L, result, AnimationClassHumanBinding::getMetatableName());
}

int AnimationClassHumanBinding::setEquipmentInHand(lua_State* L)
{
    AnimationClassHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassHuman is nil");
    bool left = lua_toboolean(L, 2) != 0;
    bool right = lua_toboolean(L, 3) != 0;
    Weapon* what = lua_isnoneornil(L, 4) ? nullptr : checkObject<Weapon>(L, 4, WeaponBinding::getMetatableName());
    instance->setEquipmentInHand(left, right, what);
    return 0;
}

int AnimationClassHumanBinding::gc(lua_State* L)
{
    return noopGc(L);
}

int AnimationClassHumanBinding::tostring(lua_State* L)
{
    AnimationClassHuman* instance = getInstance(L, 1);
    if (!instance) {
        lua_pushstring(L, "AnimationClassHuman(nil)");
    } else {
        lua_pushfstring(L, "AnimationClassHuman(%p)", instance);
    }
    return 1;
}

void AnimationClassHumanBinding::registerBinding(lua_State* L)
{
    luaL_Reg meta[] = {
        { "__gc", AnimationClassHumanBinding::gc },
        { "__tostring", AnimationClassHumanBinding::tostring },
        { 0, 0 }
    };

    luaL_Reg methods[] = {
        { "isHuman", AnimationClassHumanBinding::isHuman },
        { "_NV_isHuman", AnimationClassHumanBinding::_NV_isHuman },
        { "setEquipmentInHand", AnimationClassHumanBinding::setEquipmentInHand },
        { 0, 0 }
    };

    registerClass(
        L,
        AnimationClassHumanBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AnimationClassHumanBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "usingRightArm", AnimationClassHuman_get_usingRightArm);
    registerGetter(L, "usingLeftArm", AnimationClassHuman_get_usingLeftArm);
    registerGetter(L, "disabledRightArm", AnimationClassHuman_get_disabledRightArm);
    registerGetter(L, "disabledLeftArm", AnimationClassHuman_get_disabledLeftArm);
    registerGetter(L, "stanceAnimation", AnimationClassHuman_get_stanceAnimation);
    registerGetter(L, "lookDirection", AnimationClassHuman_get_lookDirection);
    registerGetter(L, "hipspos", AnimationClassHuman_get_hipspos);
    registerGetter(L, "breatheTimer", AnimationClassHuman_get_breatheTimer);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "usingRightArm", AnimationClassHuman_set_usingRightArm);
    registerSetter(L, "usingLeftArm", AnimationClassHuman_set_usingLeftArm);
    registerSetter(L, "disabledRightArm", AnimationClassHuman_set_disabledRightArm);
    registerSetter(L, "disabledLeftArm", AnimationClassHuman_set_disabledLeftArm);
    registerSetter(L, "stanceAnimation", AnimationClassHuman_set_stanceAnimation);
    registerSetter(L, "lookDirection", AnimationClassHuman_set_lookDirection);
    registerSetter(L, "hipspos", AnimationClassHuman_set_hipspos);
    registerSetter(L, "breatheTimer", AnimationClassHuman_set_breatheTimer);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
