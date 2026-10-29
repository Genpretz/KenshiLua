#include "pch.h"
#include "kenshi/Animation/AnimationClass.h"
#include "AnimationClassBase_SingleAnimationBinding.h"
#include "AnimationClassBaseBinding.h"
#include "AnimationDataBinding.h"
#include "AnimationEventsBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

typedef AnimationClassBase::SingleAnimation SingleAnimation;

static_assert(offsetof(SingleAnimation, animName) == 0x0, "SingleAnimation::animName offset mismatch");
static_assert(offsetof(SingleAnimation, mainState) == 0x28, "SingleAnimation::mainState offset mismatch");
static_assert(offsetof(SingleAnimation, animationData) == 0x30, "SingleAnimation::animationData offset mismatch");
static_assert(offsetof(SingleAnimation, animationClass) == 0x38, "SingleAnimation::animationClass offset mismatch");
static_assert(offsetof(SingleAnimation, speed) == 0x40, "SingleAnimation::speed offset mismatch");
static_assert(offsetof(SingleAnimation, weight) == 0x44, "SingleAnimation::weight offset mismatch");
static_assert(offsetof(SingleAnimation, desiredWeight) == 0x48, "SingleAnimation::desiredWeight offset mismatch");
static_assert(offsetof(SingleAnimation, synchOffset) == 0x4C, "SingleAnimation::synchOffset offset mismatch");
static_assert(offsetof(SingleAnimation, currentFrameTime) == 0x50, "SingleAnimation::currentFrameTime offset mismatch");
static_assert(offsetof(SingleAnimation, currentFrameTime01) == 0x54, "SingleAnimation::currentFrameTime01 offset mismatch");
static_assert(offsetof(SingleAnimation, acceptableEndTime01) == 0x58, "SingleAnimation::acceptableEndTime01 offset mismatch");
static_assert(offsetof(SingleAnimation, isAWholeBodyAction) == 0x5C, "SingleAnimation::isAWholeBodyAction offset mismatch");
static_assert(offsetof(SingleAnimation, looped) == 0x5D, "SingleAnimation::looped offset mismatch");
static_assert(offsetof(SingleAnimation, synchSlave) == 0x5E, "SingleAnimation::synchSlave offset mismatch");
static_assert(offsetof(SingleAnimation, normalise) == 0x5F, "SingleAnimation::normalise offset mismatch");
static_assert(offsetof(SingleAnimation, msgSetToReversePosition) == 0x60, "SingleAnimation::msgSetToReversePosition offset mismatch");
static_assert(offsetof(SingleAnimation, msgHardStop) == 0x61, "SingleAnimation::msgHardStop offset mismatch");
static_assert(offsetof(SingleAnimation, reversePlayOnFadeOut) == 0x62, "SingleAnimation::reversePlayOnFadeOut offset mismatch");
static_assert(offsetof(SingleAnimation, usingRightArm) == 0x63, "SingleAnimation::usingRightArm offset mismatch");
static_assert(offsetof(SingleAnimation, usingLeftArm) == 0x64, "SingleAnimation::usingLeftArm offset mismatch");
static_assert(offsetof(SingleAnimation, _breakWhenEnded) == 0x65, "SingleAnimation::_breakWhenEnded offset mismatch");
static_assert(offsetof(SingleAnimation, autoRemove) == 0x66, "SingleAnimation::autoRemove offset mismatch");
static_assert(offsetof(SingleAnimation, stillWanted) == 0x67, "SingleAnimation::stillWanted offset mismatch");
static_assert(offsetof(SingleAnimation, movesFromOrigin) == 0x68, "SingleAnimation::movesFromOrigin offset mismatch");
static_assert(offsetof(SingleAnimation, events) == 0x70, "SingleAnimation::events offset mismatch");

static SingleAnimation* getInstance(lua_State* L, int idx)
{
    return checkObject<SingleAnimation>(L, idx, AnimationClassBase_SingleAnimationBinding::getMetatableName());
}

static int SingleAnimation_get_animName(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushstring(L, instance->animName.c_str());
    return 1;
}

static int SingleAnimation_set_animName(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    const char* str = luaL_checkstring(L, 2);
    instance->animName = str ? str : "";
    return 0;
}

static int SingleAnimation_get_mainState(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    if (!instance->mainState) { lua_pushnil(L); return 1; }
    lua_pushlightuserdata(L, (void*)instance->mainState);
    return 1;
}

static int SingleAnimation_get_animationData(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    if (!instance->animationData) { lua_pushnil(L); return 1; }
    return pushObject<AnimationData>(L, const_cast<AnimationData*>(instance->animationData), AnimationDataBinding::getMetatableName());
}

static int SingleAnimation_set_animationData(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    instance->animationData = lua_isnoneornil(L, 2) ? nullptr : checkObject<AnimationData>(L, 2, AnimationDataBinding::getMetatableName());
    return 0;
}

static int SingleAnimation_get_animationClass(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    if (!instance->animationClass) { lua_pushnil(L); return 1; }
    return pushObject<AnimationClassBase>(L, instance->animationClass, AnimationClassBaseBinding::getMetatableName());
}

static int SingleAnimation_set_animationClass(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    instance->animationClass = lua_isnoneornil(L, 2) ? nullptr : checkObject<AnimationClassBase>(L, 2, AnimationClassBaseBinding::getMetatableName());
    return 0;
}

static int SingleAnimation_get_speed(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushnumber(L, (lua_Number)instance->speed);
    return 1;
}

static int SingleAnimation_set_speed(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    instance->speed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SingleAnimation_get_weight(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushnumber(L, (lua_Number)instance->weight);
    return 1;
}

static int SingleAnimation_set_weight(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    instance->weight = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SingleAnimation_get_desiredWeight(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushnumber(L, (lua_Number)instance->desiredWeight);
    return 1;
}

static int SingleAnimation_set_desiredWeight(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    instance->desiredWeight = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SingleAnimation_get_synchOffset(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushnumber(L, (lua_Number)instance->synchOffset);
    return 1;
}

static int SingleAnimation_set_synchOffset(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    instance->synchOffset = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SingleAnimation_get_currentFrameTime(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushnumber(L, (lua_Number)instance->currentFrameTime);
    return 1;
}

static int SingleAnimation_set_currentFrameTime(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    instance->currentFrameTime = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SingleAnimation_get_currentFrameTime01(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushnumber(L, (lua_Number)instance->currentFrameTime01);
    return 1;
}

static int SingleAnimation_set_currentFrameTime01(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    instance->currentFrameTime01 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SingleAnimation_get_acceptableEndTime01(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushnumber(L, (lua_Number)instance->acceptableEndTime01);
    return 1;
}

static int SingleAnimation_set_acceptableEndTime01(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    instance->acceptableEndTime01 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SingleAnimation_get_isAWholeBodyAction(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushboolean(L, instance->isAWholeBodyAction ? 1 : 0);
    return 1;
}

static int SingleAnimation_set_isAWholeBodyAction(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    instance->isAWholeBodyAction = lua_toboolean(L, 2) != 0;
    return 0;
}

static int SingleAnimation_get_looped(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushboolean(L, instance->looped ? 1 : 0);
    return 1;
}

static int SingleAnimation_set_looped(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    instance->looped = lua_toboolean(L, 2) != 0;
    return 0;
}

static int SingleAnimation_get_synchSlave(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushboolean(L, instance->synchSlave ? 1 : 0);
    return 1;
}

static int SingleAnimation_set_synchSlave(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    instance->synchSlave = lua_toboolean(L, 2) != 0;
    return 0;
}

static int SingleAnimation_get_normalise(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushboolean(L, instance->normalise ? 1 : 0);
    return 1;
}

static int SingleAnimation_set_normalise(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    instance->normalise = lua_toboolean(L, 2) != 0;
    return 0;
}

static int SingleAnimation_get_msgSetToReversePosition(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushboolean(L, instance->msgSetToReversePosition ? 1 : 0);
    return 1;
}

static int SingleAnimation_set_msgSetToReversePosition(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    instance->msgSetToReversePosition = lua_toboolean(L, 2) != 0;
    return 0;
}

static int SingleAnimation_get_msgHardStop(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushboolean(L, instance->msgHardStop ? 1 : 0);
    return 1;
}

static int SingleAnimation_set_msgHardStop(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    instance->msgHardStop = lua_toboolean(L, 2) != 0;
    return 0;
}

static int SingleAnimation_get_reversePlayOnFadeOut(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushboolean(L, instance->reversePlayOnFadeOut ? 1 : 0);
    return 1;
}

static int SingleAnimation_set_reversePlayOnFadeOut(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    instance->reversePlayOnFadeOut = lua_toboolean(L, 2) != 0;
    return 0;
}

static int SingleAnimation_get_usingRightArm(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushboolean(L, instance->usingRightArm ? 1 : 0);
    return 1;
}

static int SingleAnimation_set_usingRightArm(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    instance->usingRightArm = lua_toboolean(L, 2) != 0;
    return 0;
}

static int SingleAnimation_get_usingLeftArm(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushboolean(L, instance->usingLeftArm ? 1 : 0);
    return 1;
}

static int SingleAnimation_set_usingLeftArm(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    instance->usingLeftArm = lua_toboolean(L, 2) != 0;
    return 0;
}

static int SingleAnimation_get__breakWhenEnded(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushboolean(L, instance->_breakWhenEnded ? 1 : 0);
    return 1;
}

static int SingleAnimation_set__breakWhenEnded(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    instance->_breakWhenEnded = lua_toboolean(L, 2) != 0;
    return 0;
}

static int SingleAnimation_get_autoRemove(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushboolean(L, instance->autoRemove ? 1 : 0);
    return 1;
}

static int SingleAnimation_set_autoRemove(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    instance->autoRemove = lua_toboolean(L, 2) != 0;
    return 0;
}

static int SingleAnimation_get_stillWanted(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushboolean(L, instance->stillWanted ? 1 : 0);
    return 1;
}

static int SingleAnimation_set_stillWanted(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    instance->stillWanted = lua_toboolean(L, 2) != 0;
    return 0;
}

static int SingleAnimation_get_movesFromOrigin(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushboolean(L, instance->movesFromOrigin ? 1 : 0);
    return 1;
}

static int SingleAnimation_set_movesFromOrigin(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    instance->movesFromOrigin = lua_toboolean(L, 2) != 0;
    return 0;
}

static int SingleAnimation_get_events(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    return pushObject<AnimationEvents>(L, &instance->events, AnimationEventsBinding::getMetatableName());
}

int AnimationClassBase_SingleAnimationBinding::getAnimTime(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushnumber(L, (lua_Number)instance->getAnimTime());
    return 1;
}

int AnimationClassBase_SingleAnimationBinding::hasSound(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushboolean(L, instance->hasSound() ? 1 : 0);
    return 1;
}

int AnimationClassBase_SingleAnimationBinding::_disable(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    instance->_disable();
    return 0;
}

int AnimationClassBase_SingleAnimationBinding::disable(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    instance->disable();
    return 0;
}

int AnimationClassBase_SingleAnimationBinding::notStartedYet(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushboolean(L, instance->notStartedYet() ? 1 : 0);
    return 1;
}

int AnimationClassBase_SingleAnimationBinding::isACombatAnimation(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushboolean(L, instance->isACombatAnimation() ? 1 : 0);
    return 1;
}

int AnimationClassBase_SingleAnimationBinding::isABlockAnimation(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushboolean(L, instance->isABlockAnimation() ? 1 : 0);
    return 1;
}

int AnimationClassBase_SingleAnimationBinding::initialiseMainState(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    lua_pushboolean(L, instance->initialiseMainState() ? 1 : 0);
    return 1;
}

int AnimationClassBase_SingleAnimationBinding::fade(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    float frameTIME = (float)luaL_checknumber(L, 2);
    float blendrate = (float)luaL_checknumber(L, 3);
    lua_pushboolean(L, instance->fade(frameTIME, blendrate) ? 1 : 0);
    return 1;
}

int AnimationClassBase_SingleAnimationBinding::update(lua_State* L)
{
    SingleAnimation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SingleAnimation is nil");
    float masterTime = (float)luaL_checknumber(L, 2);
    float frameTIME = (float)luaL_checknumber(L, 3);
    bool playSounds = lua_toboolean(L, 4) != 0;
    instance->update(masterTime, frameTIME, playSounds);
    return 0;
}

int AnimationClassBase_SingleAnimationBinding::gc(lua_State* L)
{
    return 0;
}

int AnimationClassBase_SingleAnimationBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AnimationClassBase.SingleAnimation object");
    return 1;
}

void AnimationClassBase_SingleAnimationBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AnimationClassBase_SingleAnimationBinding::gc },
        { "__tostring", AnimationClassBase_SingleAnimationBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getAnimTime", AnimationClassBase_SingleAnimationBinding::getAnimTime },
        { "hasSound", AnimationClassBase_SingleAnimationBinding::hasSound },
        { "_disable", AnimationClassBase_SingleAnimationBinding::_disable },
        { "disable", AnimationClassBase_SingleAnimationBinding::disable },
        { "notStartedYet", AnimationClassBase_SingleAnimationBinding::notStartedYet },
        { "isACombatAnimation", AnimationClassBase_SingleAnimationBinding::isACombatAnimation },
        { "isABlockAnimation", AnimationClassBase_SingleAnimationBinding::isABlockAnimation },
        { "initialiseMainState", AnimationClassBase_SingleAnimationBinding::initialiseMainState },
        { "fade", AnimationClassBase_SingleAnimationBinding::fade },
        { "update", AnimationClassBase_SingleAnimationBinding::update },
        { 0, 0 }
    };

    registerClass(
        L,
        AnimationClassBase_SingleAnimationBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AnimationClassBase_SingleAnimationBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "animName", SingleAnimation_get_animName);
    registerGetter(L, "mainState", SingleAnimation_get_mainState);
    registerGetter(L, "animationData", SingleAnimation_get_animationData);
    registerGetter(L, "animationClass", SingleAnimation_get_animationClass);
    registerGetter(L, "speed", SingleAnimation_get_speed);
    registerGetter(L, "weight", SingleAnimation_get_weight);
    registerGetter(L, "desiredWeight", SingleAnimation_get_desiredWeight);
    registerGetter(L, "synchOffset", SingleAnimation_get_synchOffset);
    registerGetter(L, "currentFrameTime", SingleAnimation_get_currentFrameTime);
    registerGetter(L, "currentFrameTime01", SingleAnimation_get_currentFrameTime01);
    registerGetter(L, "acceptableEndTime01", SingleAnimation_get_acceptableEndTime01);
    registerGetter(L, "isAWholeBodyAction", SingleAnimation_get_isAWholeBodyAction);
    registerGetter(L, "looped", SingleAnimation_get_looped);
    registerGetter(L, "synchSlave", SingleAnimation_get_synchSlave);
    registerGetter(L, "normalise", SingleAnimation_get_normalise);
    registerGetter(L, "msgSetToReversePosition", SingleAnimation_get_msgSetToReversePosition);
    registerGetter(L, "msgHardStop", SingleAnimation_get_msgHardStop);
    registerGetter(L, "reversePlayOnFadeOut", SingleAnimation_get_reversePlayOnFadeOut);
    registerGetter(L, "usingRightArm", SingleAnimation_get_usingRightArm);
    registerGetter(L, "usingLeftArm", SingleAnimation_get_usingLeftArm);
    registerGetter(L, "_breakWhenEnded", SingleAnimation_get__breakWhenEnded);
    registerGetter(L, "autoRemove", SingleAnimation_get_autoRemove);
    registerGetter(L, "stillWanted", SingleAnimation_get_stillWanted);
    registerGetter(L, "movesFromOrigin", SingleAnimation_get_movesFromOrigin);
    registerGetter(L, "events", SingleAnimation_get_events);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "animName", SingleAnimation_set_animName);
    registerSetter(L, "animationData", SingleAnimation_set_animationData);
    registerSetter(L, "animationClass", SingleAnimation_set_animationClass);
    registerSetter(L, "speed", SingleAnimation_set_speed);
    registerSetter(L, "weight", SingleAnimation_set_weight);
    registerSetter(L, "desiredWeight", SingleAnimation_set_desiredWeight);
    registerSetter(L, "synchOffset", SingleAnimation_set_synchOffset);
    registerSetter(L, "currentFrameTime", SingleAnimation_set_currentFrameTime);
    registerSetter(L, "currentFrameTime01", SingleAnimation_set_currentFrameTime01);
    registerSetter(L, "acceptableEndTime01", SingleAnimation_set_acceptableEndTime01);
    registerSetter(L, "isAWholeBodyAction", SingleAnimation_set_isAWholeBodyAction);
    registerSetter(L, "looped", SingleAnimation_set_looped);
    registerSetter(L, "synchSlave", SingleAnimation_set_synchSlave);
    registerSetter(L, "normalise", SingleAnimation_set_normalise);
    registerSetter(L, "msgSetToReversePosition", SingleAnimation_set_msgSetToReversePosition);
    registerSetter(L, "msgHardStop", SingleAnimation_set_msgHardStop);
    registerSetter(L, "reversePlayOnFadeOut", SingleAnimation_set_reversePlayOnFadeOut);
    registerSetter(L, "usingRightArm", SingleAnimation_set_usingRightArm);
    registerSetter(L, "usingLeftArm", SingleAnimation_set_usingLeftArm);
    registerSetter(L, "_breakWhenEnded", SingleAnimation_set__breakWhenEnded);
    registerSetter(L, "autoRemove", SingleAnimation_set_autoRemove);
    registerSetter(L, "stillWanted", SingleAnimation_set_stillWanted);
    registerSetter(L, "movesFromOrigin", SingleAnimation_set_movesFromOrigin);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua

