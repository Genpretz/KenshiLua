#include "pch.h"
#include "kenshi/Animation/RagdollAnimation.h"
#include "RagdollAnimation_RagdollAnimationTrackBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static_assert(offsetof(RagdollAnimation::RagdollAnimationTrack, active) == 0x0, "RagdollAnimationTrack::active offset mismatch");
static_assert(offsetof(RagdollAnimation::RagdollAnimationTrack, startRotation) == 0x4, "RagdollAnimationTrack::startRotation offset mismatch");
static_assert(offsetof(RagdollAnimation::RagdollAnimationTrack, endRotation) == 0x14, "RagdollAnimationTrack::endRotation offset mismatch");
static_assert(offsetof(RagdollAnimation::RagdollAnimationTrack, startPosition) == 0x24, "RagdollAnimationTrack::startPosition offset mismatch");
static_assert(offsetof(RagdollAnimation::RagdollAnimationTrack, endPosition) == 0x30, "RagdollAnimationTrack::endPosition offset mismatch");
static_assert(offsetof(RagdollAnimation::RagdollAnimationTrack, bone) == 0x40, "RagdollAnimationTrack::bone offset mismatch");

static RagdollAnimation::RagdollAnimationTrack* getInstance(lua_State* L, int idx)
{
    return checkObject<RagdollAnimation::RagdollAnimationTrack>(L, idx, RagdollAnimation_RagdollAnimationTrackBinding::getMetatableName());
}

static int RagdollAnimationTrack_get_active(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "RagdollAnimation::RagdollAnimationTrack is nil");
    lua_pushboolean(L, inst->active ? 1 : 0);
    return 1;
}

static int RagdollAnimationTrack_set_active(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "RagdollAnimation::RagdollAnimationTrack is nil");
    inst->active = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RagdollAnimationTrack_get_startRotation(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "RagdollAnimation::RagdollAnimationTrack is nil");
    pushQuaternion(L, inst->startRotation);
    return 1;
}

static int RagdollAnimationTrack_set_startRotation(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "RagdollAnimation::RagdollAnimationTrack is nil");
    readQuaternion(L, 2, inst->startRotation);
    return 0;
}

static int RagdollAnimationTrack_get_endRotation(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "RagdollAnimation::RagdollAnimationTrack is nil");
    pushQuaternion(L, inst->endRotation);
    return 1;
}

static int RagdollAnimationTrack_set_endRotation(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "RagdollAnimation::RagdollAnimationTrack is nil");
    readQuaternion(L, 2, inst->endRotation);
    return 0;
}

static int RagdollAnimationTrack_get_startPosition(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "RagdollAnimation::RagdollAnimationTrack is nil");
    pushVector3(L, inst->startPosition);
    return 1;
}

static int RagdollAnimationTrack_set_startPosition(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "RagdollAnimation::RagdollAnimationTrack is nil");
    readVector3(L, 2, inst->startPosition);
    return 0;
}

static int RagdollAnimationTrack_get_endPosition(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "RagdollAnimation::RagdollAnimationTrack is nil");
    pushVector3(L, inst->endPosition);
    return 1;
}

static int RagdollAnimationTrack_set_endPosition(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "RagdollAnimation::RagdollAnimationTrack is nil");
    readVector3(L, 2, inst->endPosition);
    return 0;
}

static int RagdollAnimationTrack_get_bone(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "RagdollAnimation::RagdollAnimationTrack is nil");
    lua_pushlightuserdata(L, (void*)inst->bone);
    return 1;
}

static int RagdollAnimationTrack_set_bone(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "RagdollAnimation::RagdollAnimationTrack is nil");
    inst->bone = (Ogre::OldBone*)lua_touserdata(L, 2);
    return 0;
}

int RagdollAnimation_RagdollAnimationTrackBinding::gc(lua_State* L)
{
    return 0;
}

int RagdollAnimation_RagdollAnimationTrackBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.RagdollAnimation.RagdollAnimationTrack object");
    return 1;
}

void RagdollAnimation_RagdollAnimationTrackBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RagdollAnimation_RagdollAnimationTrackBinding::gc },
        { "__tostring", RagdollAnimation_RagdollAnimationTrackBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L,
        RagdollAnimation_RagdollAnimationTrackBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, RagdollAnimation_RagdollAnimationTrackBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "active", RagdollAnimationTrack_get_active);
    registerGetter(L, "startRotation", RagdollAnimationTrack_get_startRotation);
    registerGetter(L, "endRotation", RagdollAnimationTrack_get_endRotation);
    registerGetter(L, "startPosition", RagdollAnimationTrack_get_startPosition);
    registerGetter(L, "endPosition", RagdollAnimationTrack_get_endPosition);
    registerGetter(L, "bone", RagdollAnimationTrack_get_bone);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "active", RagdollAnimationTrack_set_active);
    registerSetter(L, "startRotation", RagdollAnimationTrack_set_startRotation);
    registerSetter(L, "endRotation", RagdollAnimationTrack_set_endRotation);
    registerSetter(L, "startPosition", RagdollAnimationTrack_set_startPosition);
    registerSetter(L, "endPosition", RagdollAnimationTrack_set_endPosition);
    registerSetter(L, "bone", RagdollAnimationTrack_set_bone);
    lua_setfield(L, -2, "__setters");
    lua_pop(L, 1);
}

} // namespace KenshiLua
