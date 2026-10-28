#include "pch.h"
#include "kenshi/Animation/RagdollAnimation.h"
#include "RagdollAnimationBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Animation/AnimationClassBinding.h"

namespace KenshiLua
{

static_assert(offsetof(RagdollAnimation, animationClass) == 0x0, "RagdollAnimation::animationClass offset mismatch");
static_assert(offsetof(RagdollAnimation, targetAnimationName) == 0x8, "RagdollAnimation::targetAnimationName offset mismatch");
static_assert(offsetof(RagdollAnimation, skeleton) == 0x30, "RagdollAnimation::skeleton offset mismatch");
static_assert(offsetof(RagdollAnimation, entity) == 0x38, "RagdollAnimation::entity offset mismatch");
static_assert(offsetof(RagdollAnimation, tracks) == 0x40, "RagdollAnimation::tracks offset mismatch");
static_assert(offsetof(RagdollAnimation, firstUpdate) == 0x60, "RagdollAnimation::firstUpdate offset mismatch");
static_assert(offsetof(RagdollAnimation, animating) == 0x61, "RagdollAnimation::animating offset mismatch");
static_assert(offsetof(RagdollAnimation, endTime) == 0x64, "RagdollAnimation::endTime offset mismatch");
static_assert(offsetof(RagdollAnimation, curTime) == 0x68, "RagdollAnimation::curTime offset mismatch");

static RagdollAnimation* getInstance(lua_State* L, int idx)
{
    return checkObject<RagdollAnimation>(L, idx, RagdollAnimationBinding::getMetatableName());
}

static int RagdollAnimation_get_animationClass(lua_State* L)
{
    RagdollAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RagdollAnimation is nil");
    if (!instance->animationClass) { lua_pushnil(L); return 1; }
    return pushObject<AnimationClass>(L, instance->animationClass, AnimationClassBinding::getMetatableName());
}

static int RagdollAnimation_get_targetAnimationName(lua_State* L)
{
    RagdollAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RagdollAnimation is nil");
    lua_pushstring(L, instance->targetAnimationName.c_str());
    return 1;
}

static int RagdollAnimation_set_targetAnimationName(lua_State* L)
{
    RagdollAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RagdollAnimation is nil");
    instance->targetAnimationName = luaL_checkstring(L, 2);
    return 0;
}

static int RagdollAnimation_get_skeleton(lua_State* L)
{
    RagdollAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RagdollAnimation is nil");
    lua_pushlightuserdata(L, (void*)instance->skeleton);
    return 1;
}

static int RagdollAnimation_get_entity(lua_State* L)
{
    RagdollAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RagdollAnimation is nil");
    lua_pushlightuserdata(L, (void*)instance->entity);
    return 1;
}

static int RagdollAnimation_get_firstUpdate(lua_State* L)
{
    RagdollAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RagdollAnimation is nil");
    lua_pushboolean(L, instance->firstUpdate ? 1 : 0);
    return 1;
}

static int RagdollAnimation_set_firstUpdate(lua_State* L)
{
    RagdollAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RagdollAnimation is nil");
    instance->firstUpdate = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RagdollAnimation_get_animating(lua_State* L)
{
    RagdollAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RagdollAnimation is nil");
    lua_pushboolean(L, instance->animating ? 1 : 0);
    return 1;
}

static int RagdollAnimation_set_animating(lua_State* L)
{
    RagdollAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RagdollAnimation is nil");
    instance->animating = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RagdollAnimation_get_endTime(lua_State* L)
{
    RagdollAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RagdollAnimation is nil");
    lua_pushnumber(L, instance->endTime);
    return 1;
}

static int RagdollAnimation_set_endTime(lua_State* L)
{
    RagdollAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RagdollAnimation is nil");
    instance->endTime = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RagdollAnimation_get_curTime(lua_State* L)
{
    RagdollAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RagdollAnimation is nil");
    lua_pushnumber(L, instance->curTime);
    return 1;
}

static int RagdollAnimation_set_curTime(lua_State* L)
{
    RagdollAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RagdollAnimation is nil");
    instance->curTime = (float)luaL_checknumber(L, 2);
    return 0;
}

int RagdollAnimationBinding::isAnimating(lua_State* L)
{
    RagdollAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RagdollAnimation is nil");

    bool result = instance->isAnimating();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RagdollAnimationBinding::update(lua_State* L)
{
    RagdollAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RagdollAnimation is nil");

    instance->update();
    return 0;
}

int RagdollAnimationBinding::setTargetAnimation(lua_State* L)
{
    RagdollAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RagdollAnimation is nil");

    Ogre::Entity* ent = (Ogre::Entity*)lua_touserdata(L, 2);
    Ogre::OldSkeletonInstance* skel = (Ogre::OldSkeletonInstance*)lua_touserdata(L, 3);
    Ogre::Animation* animation = (Ogre::Animation*)lua_touserdata(L, 4);
    float duration = (float)luaL_checknumber(L, 5);

    instance->setTargetAnimation(ent, skel, animation, duration);
    return 0;
}

int RagdollAnimationBinding::getTargetAnimation(lua_State* L)
{
    RagdollAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RagdollAnimation is nil");

    const std::string& result = instance->getTargetAnimation();
    lua_pushstring(L, result.c_str());
    return 1;
}

int RagdollAnimationBinding::getAnimationTime(lua_State* L)
{
    RagdollAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RagdollAnimation is nil");

    float result = instance->getAnimationTime();
    lua_pushnumber(L, result);
    return 1;
}

int RagdollAnimationBinding::gc(lua_State* L)
{
    return 0;
}

int RagdollAnimationBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.RagdollAnimation object");
    return 1;
}

void RagdollAnimationBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RagdollAnimationBinding::gc },
        { "__tostring", RagdollAnimationBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "isAnimating",        RagdollAnimationBinding::isAnimating },
        { "update",             RagdollAnimationBinding::update },
        { "setTargetAnimation", RagdollAnimationBinding::setTargetAnimation },
        { "getTargetAnimation", RagdollAnimationBinding::getTargetAnimation },
        { "getAnimationTime",   RagdollAnimationBinding::getAnimationTime },
        { 0, 0 }
    };

    registerClass(
        L,
        RagdollAnimationBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, RagdollAnimationBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "animationClass", RagdollAnimation_get_animationClass);
    registerGetter(L, "targetAnimationName", RagdollAnimation_get_targetAnimationName);
    registerGetter(L, "skeleton", RagdollAnimation_get_skeleton);
    registerGetter(L, "entity", RagdollAnimation_get_entity);
    registerGetter(L, "firstUpdate", RagdollAnimation_get_firstUpdate);
    registerGetter(L, "animating", RagdollAnimation_get_animating);
    registerGetter(L, "endTime", RagdollAnimation_get_endTime);
    registerGetter(L, "curTime", RagdollAnimation_get_curTime);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "targetAnimationName", RagdollAnimation_set_targetAnimationName);
    registerSetter(L, "firstUpdate", RagdollAnimation_set_firstUpdate);
    registerSetter(L, "animating", RagdollAnimation_set_animating);
    registerSetter(L, "endTime", RagdollAnimation_set_endTime);
    registerSetter(L, "curTime", RagdollAnimation_set_curTime);
    lua_setfield(L, -2, "__setters");
    lua_pop(L, 1);
}

} // namespace KenshiLua
