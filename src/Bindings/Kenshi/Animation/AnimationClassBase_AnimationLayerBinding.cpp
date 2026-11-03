#include "pch.h"
#include "kenshi/Animation/AnimationClass.h"
#include "AnimationClassBase_AnimationLayerBinding.h"
#include "AnimationClassBase_SingleAnimationBinding.h"
#include "AnimationClassBaseBinding.h"
#include "AnimationDataBinding.h"
#include "Bindings/Kenshi/CharMovementBinding.h"
#include "Bindings/Kenshi/Combat/CombatTechniqueDataBinding.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

typedef AnimationClassBase::AnimationLayer AnimationLayer;
typedef AnimationClassBase::SingleAnimation SingleAnimation;

static_assert(offsetof(AnimationLayer, addList) == 0x0, "AnimationLayer::addList offset mismatch");
static_assert(offsetof(AnimationLayer, removeList) == 0x18, "AnimationLayer::removeList offset mismatch");
static_assert(offsetof(AnimationLayer, body) == 0x30, "AnimationLayer::body offset mismatch");
static_assert(offsetof(AnimationLayer, movement) == 0x38, "AnimationLayer::movement offset mismatch");
static_assert(offsetof(AnimationLayer, fadeRate) == 0x40, "AnimationLayer::fadeRate offset mismatch");
static_assert(offsetof(AnimationLayer, animationClass) == 0x48, "AnimationLayer::animationClass offset mismatch");

static AnimationLayer* getInstance(lua_State* L, int idx)
{
    return checkObject<AnimationLayer>(L, idx, AnimationClassBase_AnimationLayerBinding::getMetatableName());
}

static int AnimationLayer_get_addList(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    return pushObject<lektor<SingleAnimation*>>(L, &instance->addList, "lektor<SingleAnimation*>");
}

static int AnimationLayer_get_removeList(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    return pushObject<lektor<SingleAnimation*>>(L, &instance->removeList, "lektor<SingleAnimation*>");
}

static int AnimationLayer_get_body(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    if (!instance->body) { lua_pushnil(L); return 1; }
    lua_pushlightuserdata(L, (void*)instance->body);
    return 1;
}

static int AnimationLayer_get_movement(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    if (!instance->movement) { lua_pushnil(L); return 1; }
    return pushObject<CharMovement>(L, instance->movement, CharMovementBinding::getMetatableName());
}

static int AnimationLayer_set_movement(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    instance->movement = lua_isnoneornil(L, 2) ? nullptr : checkObject<CharMovement>(L, 2, CharMovementBinding::getMetatableName());
    return 0;
}

static int AnimationLayer_get_fadeRate(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    lua_pushnumber(L, (lua_Number)instance->fadeRate);
    return 1;
}

static int AnimationLayer_set_fadeRate(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    instance->fadeRate = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationLayer_get_animationClass(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    if (!instance->animationClass) { lua_pushnil(L); return 1; }
    return pushObject<AnimationClassBase>(L, instance->animationClass, AnimationClassBaseBinding::getMetatableName());
}

static int AnimationLayer_set_animationClass(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    instance->animationClass = lua_isnoneornil(L, 2) ? nullptr : checkObject<AnimationClassBase>(L, 2, AnimationClassBaseBinding::getMetatableName());
    return 0;
}

int AnimationClassBase_AnimationLayerBinding::addToRemoveList(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    SingleAnimation* anim = checkObject<SingleAnimation>(L, 2, AnimationClassBase_SingleAnimationBinding::getMetatableName());
    instance->addToRemoveList(anim);
    return 0;
}

int AnimationClassBase_AnimationLayerBinding::clearLists(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    instance->clearLists();
    return 0;
}

int AnimationClassBase_AnimationLayerBinding::_clearListsSafe(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    instance->_clearListsSafe();
    return 0;
}

int AnimationClassBase_AnimationLayerBinding::randomiseAnimationPosition(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    const char* name = luaL_checkstring(L, 2);
    instance->randomiseAnimationPosition(name ? name : "");
    return 0;
}

int AnimationClassBase_AnimationLayerBinding::isAnimationInRemoveList(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    AnimationData* ad = checkObject<AnimationData>(L, 2, AnimationDataBinding::getMetatableName());
    SingleAnimation* res = instance->isAnimationInRemoveList(ad);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<SingleAnimation>(L, res, AnimationClassBase_SingleAnimationBinding::getMetatableName());
}

int AnimationClassBase_AnimationLayerBinding::isAnimationInAddList(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    if (lua_isstring(L, 2)) {
        const char* s = lua_tostring(L, 2);
        SingleAnimation* res = instance->isAnimationInAddList(std::string(s ? s : ""));
        if (!res) { lua_pushnil(L); return 1; }
        return pushObject<SingleAnimation>(L, res, AnimationClassBase_SingleAnimationBinding::getMetatableName());
    }
    CombatTechniqueData* ctd = testObject<CombatTechniqueData>(L, 2, CombatTechniqueDataBinding::getMetatableName());
    if (ctd) {
        SingleAnimation* res = instance->isAnimationInAddList(ctd);
        if (!res) { lua_pushnil(L); return 1; }
        return pushObject<SingleAnimation>(L, res, AnimationClassBase_SingleAnimationBinding::getMetatableName());
    }
    AnimationData* ad = testObject<AnimationData>(L, 2, AnimationDataBinding::getMetatableName());
    if (ad) {
        SingleAnimation* res = instance->isAnimationInAddList(ad);
        if (!res) { lua_pushnil(L); return 1; }
        return pushObject<SingleAnimation>(L, res, AnimationClassBase_SingleAnimationBinding::getMetatableName());
    }
    return luaL_error(L, "Argument 2 to isAnimationInAddList must be string, CombatTechniqueData, or AnimationData");
}

int AnimationClassBase_AnimationLayerBinding::isAnimationInAddList_Datname(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    const char* s = luaL_checkstring(L, 2);
    SingleAnimation* res = instance->isAnimationInAddList_Datname(std::string(s ? s : ""));
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<SingleAnimation>(L, res, AnimationClassBase_SingleAnimationBinding::getMetatableName());
}

int AnimationClassBase_AnimationLayerBinding::takeFromRemoveList(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    const char* s = luaL_checkstring(L, 2);
    SingleAnimation* res = instance->takeFromRemoveList(std::string(s ? s : ""));
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<SingleAnimation>(L, res, AnimationClassBase_SingleAnimationBinding::getMetatableName());
}

int AnimationClassBase_AnimationLayerBinding::takeFromAddList(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    if (lua_isstring(L, 2)) {
        const char* s = lua_tostring(L, 2);
        SingleAnimation* res = instance->takeFromAddList(std::string(s ? s : ""));
        if (!res) { lua_pushnil(L); return 1; }
        return pushObject<SingleAnimation>(L, res, AnimationClassBase_SingleAnimationBinding::getMetatableName());
    }
    AnimationData* ad = testObject<AnimationData>(L, 2, AnimationDataBinding::getMetatableName());
    if (ad) {
        SingleAnimation* res = instance->takeFromAddList(ad);
        if (!res) { lua_pushnil(L); return 1; }
        return pushObject<SingleAnimation>(L, res, AnimationClassBase_SingleAnimationBinding::getMetatableName());
    }
    return luaL_error(L, "Argument 2 to takeFromAddList must be string or AnimationData");
}

int AnimationClassBase_AnimationLayerBinding::getTotalAnimationWeight(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    if (lua_gettop(L) >= 4) {
        bool thisLayer = lua_toboolean(L, 2) != 0;
        bool wholeBody = lua_toboolean(L, 3) != 0;
        bool includeRemovelist = lua_toboolean(L, 4) != 0;
        float res = instance->getTotalAnimationWeight(thisLayer, wholeBody, includeRemovelist);
        lua_pushnumber(L, (lua_Number)res);
        return 1;
    }
    CharacterAnimCategory cat = (CharacterAnimCategory)luaL_checkinteger(L, 2);
    float res = instance->getTotalAnimationWeight(cat);
    lua_pushnumber(L, (lua_Number)res);
    return 1;
}

int AnimationClassBase_AnimationLayerBinding::getTotalActionAnimationWeight(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    float res = instance->getTotalActionAnimationWeight();
    lua_pushnumber(L, (lua_Number)res);
    return 1;
}

int AnimationClassBase_AnimationLayerBinding::stillPlayingAnActionOrSomething(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    lua_pushboolean(L, instance->stillPlayingAnActionOrSomething() ? 1 : 0);
    return 1;
}

int AnimationClassBase_AnimationLayerBinding::getCurrentAnimationWeight(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    const char* s = luaL_checkstring(L, 2);
    float res = instance->getCurrentAnimationWeight(std::string(s ? s : ""));
    lua_pushnumber(L, (lua_Number)res);
    return 1;
}

int AnimationClassBase_AnimationLayerBinding::updateAnimationSpeed(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    const char* s = luaL_checkstring(L, 2);
    float speed = (float)luaL_checknumber(L, 3);
    instance->updateAnimationSpeed(std::string(s ? s : ""), speed);
    return 0;
}

int AnimationClassBase_AnimationLayerBinding::removeAnimation(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    if (lua_isstring(L, 2)) {
        const char* s = lua_tostring(L, 2);
        instance->removeAnimation(std::string(s ? s : ""));
        return 0;
    }
    AnimationData* ad = testObject<AnimationData>(L, 2, AnimationDataBinding::getMetatableName());
    if (ad) {
        instance->removeAnimation(ad);
        return 0;
    }
    return luaL_error(L, "Argument 2 to removeAnimation must be string or AnimationData");
}

int AnimationClassBase_AnimationLayerBinding::update2frame(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    instance->update2frame();
    return 0;
}

int AnimationClassBase_AnimationLayerBinding::moveAllToRemoveList(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    instance->moveAllToRemoveList();
    return 0;
}

int AnimationClassBase_AnimationLayerBinding::endAllAnimations(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    instance->endAllAnimations();
    return 0;
}

int AnimationClassBase_AnimationLayerBinding::stopActionAnimations(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    instance->stopActionAnimations();
    return 0;
}

int AnimationClassBase_AnimationLayerBinding::stopAllAnimation(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    bool hardStop = lua_toboolean(L, 2) != 0;
    instance->stopAllAnimation(hardStop);
    return 0;
}

int AnimationClassBase_AnimationLayerBinding::stopAllAnimationThatMovesFromOrigin(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    instance->stopAllAnimationThatMovesFromOrigin();
    return 0;
}

int AnimationClassBase_AnimationLayerBinding::clearAllAnimationUT(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    instance->clearAllAnimationUT();
    return 0;
}

int AnimationClassBase_AnimationLayerBinding::getAnimTime(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    lua_pushnumber(L, (lua_Number)instance->getAnimTime());
    return 1;
}

int AnimationClassBase_AnimationLayerBinding::usingRightArm(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    lua_pushboolean(L, instance->usingRightArm() ? 1 : 0);
    return 1;
}

int AnimationClassBase_AnimationLayerBinding::usingLeftArm(lua_State* L)
{
    AnimationLayer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationLayer is nil");
    lua_pushboolean(L, instance->usingLeftArm() ? 1 : 0);
    return 1;
}

int AnimationClassBase_AnimationLayerBinding::gc(lua_State* L)
{
    return 0;
}

int AnimationClassBase_AnimationLayerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AnimationClassBase.AnimationLayer object");
    return 1;
}

void AnimationClassBase_AnimationLayerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AnimationClassBase_AnimationLayerBinding::gc },
        { "__tostring", AnimationClassBase_AnimationLayerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "addToRemoveList", AnimationClassBase_AnimationLayerBinding::addToRemoveList },
        { "clearLists", AnimationClassBase_AnimationLayerBinding::clearLists },
        { "_clearListsSafe", AnimationClassBase_AnimationLayerBinding::_clearListsSafe },
        { "randomiseAnimationPosition", AnimationClassBase_AnimationLayerBinding::randomiseAnimationPosition },
        { "isAnimationInRemoveList", AnimationClassBase_AnimationLayerBinding::isAnimationInRemoveList },
        { "isAnimationInAddList", AnimationClassBase_AnimationLayerBinding::isAnimationInAddList },
        { "isAnimationInAddList_Datname", AnimationClassBase_AnimationLayerBinding::isAnimationInAddList_Datname },
        { "takeFromRemoveList", AnimationClassBase_AnimationLayerBinding::takeFromRemoveList },
        { "takeFromAddList", AnimationClassBase_AnimationLayerBinding::takeFromAddList },
        { "getTotalAnimationWeight", AnimationClassBase_AnimationLayerBinding::getTotalAnimationWeight },
        { "getTotalActionAnimationWeight", AnimationClassBase_AnimationLayerBinding::getTotalActionAnimationWeight },
        { "stillPlayingAnActionOrSomething", AnimationClassBase_AnimationLayerBinding::stillPlayingAnActionOrSomething },
        { "getCurrentAnimationWeight", AnimationClassBase_AnimationLayerBinding::getCurrentAnimationWeight },
        { "updateAnimationSpeed", AnimationClassBase_AnimationLayerBinding::updateAnimationSpeed },
        { "removeAnimation", AnimationClassBase_AnimationLayerBinding::removeAnimation },
        { "update2frame", AnimationClassBase_AnimationLayerBinding::update2frame },
        { "moveAllToRemoveList", AnimationClassBase_AnimationLayerBinding::moveAllToRemoveList },
        { "endAllAnimations", AnimationClassBase_AnimationLayerBinding::endAllAnimations },
        { "stopActionAnimations", AnimationClassBase_AnimationLayerBinding::stopActionAnimations },
        { "stopAllAnimation", AnimationClassBase_AnimationLayerBinding::stopAllAnimation },
        { "stopAllAnimationThatMovesFromOrigin", AnimationClassBase_AnimationLayerBinding::stopAllAnimationThatMovesFromOrigin },
        { "clearAllAnimationUT", AnimationClassBase_AnimationLayerBinding::clearAllAnimationUT },
        { "getAnimTime", AnimationClassBase_AnimationLayerBinding::getAnimTime },
        { "usingRightArm", AnimationClassBase_AnimationLayerBinding::usingRightArm },
        { "usingLeftArm", AnimationClassBase_AnimationLayerBinding::usingLeftArm },
        { 0, 0 }
    };

    registerClass(
        L,
        AnimationClassBase_AnimationLayerBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AnimationClassBase_AnimationLayerBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "addList", AnimationLayer_get_addList);
    registerGetter(L, "removeList", AnimationLayer_get_removeList);
    registerGetter(L, "body", AnimationLayer_get_body);
    registerGetter(L, "movement", AnimationLayer_get_movement);
    registerGetter(L, "fadeRate", AnimationLayer_get_fadeRate);
    registerGetter(L, "animationClass", AnimationLayer_get_animationClass);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "movement", AnimationLayer_set_movement);
    registerSetter(L, "fadeRate", AnimationLayer_set_fadeRate);
    registerSetter(L, "animationClass", AnimationLayer_set_animationClass);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);

}

} // namespace KenshiLua

