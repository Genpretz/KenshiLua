#include "pch.h"
#include "kenshi/Animation/AnimationClass.h"
#include "AnimationClassBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Animation/AnimationDataBinding.h"
#include "Bindings/Kenshi/AppearanceBaseBinding.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/CombatTechniqueDataBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/GameDataCopyStandaloneBinding.h"
#include "Bindings/Kenshi/Gui/DatapanelGUIBinding.h"
#include "Bindings/Kenshi/ItemBinding.h"
#include "Bindings/Kenshi/MotionFilterBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"

namespace KenshiLua
{

static_assert(offsetof(AnimationClass, appearance) == 0xE8, "AnimationClass::appearance offset does not match the game");
static_assert(offsetof(AnimationClass, animationRequirements) == 0xF0, "AnimationClass::animationRequirements offset does not match the game");
static_assert(offsetof(AnimationClass, strafeBlendFilter) == 0x2B8, "AnimationClass::strafeBlendFilter offset does not match the game");
static_assert(offsetof(AnimationClass, me) == 0x2D8, "AnimationClass::me offset does not match the game");
static_assert(offsetof(AnimationClass, defaultIdleAnimation) == 0x2E0, "AnimationClass::defaultIdleAnimation offset does not match the game");
static_assert(offsetof(AnimationClass, ragdollParts) == 0x2F8, "AnimationClass::ragdollParts offset does not match the game");

static AnimationClass* getInstance(lua_State* L, int idx)
{
    return checkObject<AnimationClass>(L, idx, AnimationClassBinding::getMetatableName());
}

// --- Getters for AnimationClass ---
static int AnimationClass_get_appearance(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");
    return pushObject<AppearanceBase>(L, instance->appearance, AppearanceBaseBinding::getMetatableName());
}

static int AnimationClass_get_strafeBlendFilter(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");
    return pushObject<MotionFilter>(L, instance->strafeBlendFilter, MotionFilterBinding::getMetatableName());
}

static int AnimationClass_get_feetHeight(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");
    lua_pushnumber(L, instance->feetHeight);
    return 1;
}

static int AnimationClass_get_bootHeight(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");
    lua_pushnumber(L, instance->bootHeight);
    return 1;
}

static int AnimationClass_get_totalActionWeight(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");
    lua_pushnumber(L, instance->totalActionWeight);
    return 1;
}

static int AnimationClass_get_disableRagdollKinematics(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");
    lua_pushinteger(L, instance->disableRagdollKinematics);
    return 1;
}

static int AnimationClass_get_me(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");
    return pushObject<Character>(L, instance->me, CharacterBinding::getMetatableName());
}

static int AnimationClass_get_defaultIdleAnimation(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");
    return pushObject<AnimationData>(L, instance->defaultIdleAnimation, AnimationDataBinding::getMetatableName());
}

static int AnimationClass_get_ragdollParts(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");
    lua_pushinteger(L, (lua_Integer)instance->ragdollParts);
    return 1;
}

// --- Setters for AnimationClass ---
// appearance and strafeBlendFilter are read-only: ~AnimationClass deletes both,
// so assigning a borrowed object would be freed twice.
static int AnimationClass_set_feetHeight(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");
    instance->feetHeight = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationClass_set_bootHeight(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");
    instance->bootHeight = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationClass_set_totalActionWeight(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");
    instance->totalActionWeight = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationClass_set_disableRagdollKinematics(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");
    instance->disableRagdollKinematics = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int AnimationClass_set_me(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");
    instance->me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

// getIdleAnimation null-checks defaultIdleAnimation before using it.
static int AnimationClass_set_defaultIdleAnimation(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");
    instance->defaultIdleAnimation = lua_isnoneornil(L, 2) ? nullptr : checkObject<AnimationData>(L, 2, AnimationDataBinding::getMetatableName());
    return 0;
}

static int AnimationClass_set_ragdollParts(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");
    instance->ragdollParts = (RagdollPart::Enum)luaL_checkinteger(L, 2);
    return 0;
}

int AnimationClassBinding::debugGetAllAnimations(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    DatapanelGUI* panel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    instance->debugGetAllAnimations(panel);
    return 0;
}

int AnimationClassBinding::startStumble(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    // startStumble ignores a null anim.
    AnimationData* anim = lua_isnoneornil(L, 2) ? nullptr : checkObject<AnimationData>(L, 2, AnimationDataBinding::getMetatableName());
    instance->startStumble(anim);
    return 0;
}

int AnimationClassBinding::endStumble(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    instance->endStumble();
    return 0;
}

int AnimationClassBinding::currentlyStumbling(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool result = instance->currentlyStumbling();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBinding::getCurrentlyStumbleAnim(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    AnimationData* result = instance->getCurrentlyStumbleAnim();
    return pushObject<AnimationData>(L, result, AnimationDataBinding::getMetatableName());
}

int AnimationClassBinding::isCurrentlyIncapableOfWaypointMovemode(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool result = instance->isCurrentlyIncapableOfWaypointMovemode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBinding::threadSafeRagdollUpdateUT(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    instance->threadSafeRagdollUpdateUT();
    return 0;
}

int AnimationClassBinding::update(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    float frameTIME = (float)luaL_checknumber(L, 2);
    instance->update(frameTIME);
    return 0;
}

int AnimationClassBinding::_NV_update(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    float frameTIME = (float)luaL_checknumber(L, 2);
    instance->_NV_update(frameTIME);
    return 0;
}

int AnimationClassBinding::calculatePositionWithWaterHeight(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    float result = instance->calculatePositionWithWaterHeight();
    lua_pushnumber(L, result);
    return 1;
}

int AnimationClassBinding::updateAnimationCharacterEditor(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->updateAnimationCharacterEditor(time);
    return 0;
}

int AnimationClassBinding::updateThreaded(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    float frameTIME = (float)luaL_checknumber(L, 2);
    instance->updateThreaded(frameTIME);
    return 0;
}

int AnimationClassBinding::rotationUpdate(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    float frameTime = (float)luaL_checknumber(L, 2);
    instance->rotationUpdate(frameTime);
    return 0;
}

int AnimationClassBinding::_NV_rotationUpdate(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    float frameTime = (float)luaL_checknumber(L, 2);
    instance->_NV_rotationUpdate(frameTime);
    return 0;
}

int AnimationClassBinding::updateAnimationTransforms(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    instance->updateAnimationTransforms();
    return 0;
}

int AnimationClassBinding::setPosition(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    if (lua_isnoneornil(L, 3)) {
        instance->setPosition(pos);
        return 0;
    }
    if (!lua_istable(L, 3))
        return luaL_error(L, "Argument 3 to setPosition must be a Quaternion or Vector3 table, got %s", luaL_typename(L, 3));

    // A Quaternion table carries w (or four array entries); a Vector3 table never does.
    lua_getfield(L, 3, "w");
    bool isQuaternion = !lua_isnil(L, -1) || lua_objlen(L, 3) == 4;
    lua_pop(L, 1);
    if (isQuaternion) {
        Ogre::Quaternion dir;
        readQuaternion(L, 3, dir);
        instance->setPosition(pos, dir);
    } else {
        Ogre::Vector3 dir;
        readVector3(L, 3, dir);
        instance->setPosition(pos, dir);
    }
    return 0;
}

int AnimationClassBinding::getPosition(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    Ogre::Vector3 pos(0.0f, 0.0f, 0.0f);
    bool result = instance->getPosition(pos);
    lua_pushboolean(L, result ? 1 : 0);
    pushVector3(L, pos);
    return 2;
}

int AnimationClassBinding::rotateEntityAroundBone(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    const std::string bone = luaL_checkstring(L, 2);
    Ogre::Vector3 dir;
    readVector3(L, 3, dir);
    Ogre::Vector3 result = instance->rotateEntityAroundBone(bone, dir);
    pushVector3(L, result);
    return 1;
}

int AnimationClassBinding::getBoneScale(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    const std::string bonename = luaL_checkstring(L, 2);
    const Ogre::Vector3& result = instance->getBoneScale(bonename);
    pushVector3(L, result);
    return 1;
}

int AnimationClassBinding::deactivateVisuals(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    instance->deactivateVisuals();
    return 0;
}

int AnimationClassBinding::getIsActivated(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool result = instance->getIsActivated();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBinding::resetBody(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    instance->resetBody();
    return 0;
}

int AnimationClassBinding::restartAction(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    const std::string name = luaL_checkstring(L, 2);
    bool result = instance->restartAction(name);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBinding::playAction(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    if (AnimationData* anim = testObject<AnimationData>(L, 2, AnimationDataBinding::getMetatableName())) {
        float speedMult = (float)luaL_checknumber(L, 3);
        float initialWeight = (float)luaL_checknumber(L, 4);
        bool isStumble = lua_toboolean(L, 5) != 0;
        instance->playAction(anim, speedMult, initialWeight, isStumble);
        return 0;
    }
    if (lua_type(L, 2) != LUA_TSTRING)
        return luaL_error(L, "Argument 2 to playAction must be a string or AnimationData, got %s", luaL_typename(L, 2));
    const char* dataname = lua_tostring(L, 2);
    float speedMult = (float)luaL_checknumber(L, 3);
    float initialWeight = (float)luaL_checknumber(L, 4);
    bool isStumble = lua_toboolean(L, 5) != 0;
    instance->playAction(dataname, speedMult, initialWeight, isStumble);
    return 0;
}

int AnimationClassBinding::stopAction(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool result;
    if (lua_isnoneornil(L, 2)) {
        result = instance->stopAction();
    } else {
        const std::string name = luaL_checkstring(L, 2);
        result = instance->stopAction(name);
    }
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBinding::setAnimationMoveSpeed(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    float speed = (float)luaL_checknumber(L, 2);
    instance->setAnimationMoveSpeed(speed);
    return 0;
}

int AnimationClassBinding::setStrafeSpeed(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    float speed = (float)luaL_checknumber(L, 2);
    instance->setStrafeSpeed(speed);
    return 0;
}

int AnimationClassBinding::setCombatMode(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setCombatMode(on);
    return 0;
}

int AnimationClassBinding::setWeatherType(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    WeatherAffecting w = (WeatherAffecting)luaL_checkinteger(L, 2);
    float stren = (float)luaL_checknumber(L, 3);
    bool doWeatherAnimation = lua_toboolean(L, 4) != 0;
    instance->setWeatherType(w, stren, doWeatherAnimation);
    return 0;
}

int AnimationClassBinding::getWeatherType(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    lua_pushinteger(L, (lua_Integer)instance->getWeatherType());
    return 1;
}

int AnimationClassBinding::getWeatherStrength(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    float result = instance->getWeatherStrength();
    lua_pushnumber(L, result);
    return 1;
}

int AnimationClassBinding::setStealthMode(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setStealthMode(on);
    return 0;
}

int AnimationClassBinding::setMaximumSpeed(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    float speed = (float)luaL_checknumber(L, 2);
    instance->setMaximumSpeed(speed);
    return 0;
}

int AnimationClassBinding::getMaximumSpeed(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    float result = instance->getMaximumSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int AnimationClassBinding::isLinearAnimationDone_byName(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    const std::string name = luaL_checkstring(L, 2);
    bool result = instance->isLinearAnimationDone_byName(name);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBinding::isLinearAnimationDone(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    // isLinearAnimationDone returns true for a null anim.
    AnimationData* anim = lua_isnoneornil(L, 2) ? nullptr : checkObject<AnimationData>(L, 2, AnimationDataBinding::getMetatableName());
    bool result = instance->isLinearAnimationDone(anim);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBinding::getFootHeight(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    float result = instance->getFootHeight();
    lua_pushnumber(L, result);
    return 1;
}

int AnimationClassBinding::calculateFeetHeight(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    instance->calculateFeetHeight();
    return 0;
}

int AnimationClassBinding::setBootHeight(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    float h = (float)luaL_checknumber(L, 2);
    instance->setBootHeight(h);
    return 0;
}

int AnimationClassBinding::isBeingCarried(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool result = instance->isBeingCarried();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBinding::isTotallyRagdoll(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool result = instance->isTotallyRagdoll();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBinding::notifyRagdollNeedsAnUpdate(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    instance->notifyRagdollNeedsAnUpdate();
    return 0;
}

int AnimationClassBinding::setCarryMode(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool ed = lua_toboolean(L, 2) != 0;
    bool left = lua_toboolean(L, 3) != 0;
    bool right = lua_toboolean(L, 4) != 0;
    instance->setCarryMode(ed, left, right);
    return 0;
}

int AnimationClassBinding::setCombatModeLegsIdle(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setCombatModeLegsIdle(on);
    return 0;
}

int AnimationClassBinding::setCombatModeUpperIdle(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setCombatModeUpperIdle(on);
    return 0;
}

int AnimationClassBinding::isRagdoll(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool result = instance->isRagdoll();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBinding::ragdollAnimateTo(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    const char* targetAnimationName = luaL_checkstring(L, 2);
    float duration = (float)luaL_checknumber(L, 3);
    instance->ragdollAnimateTo(targetAnimationName, duration);
    return 0;
}

int AnimationClassBinding::isRagdollAnimated(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool result = instance->isRagdollAnimated();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBinding::ragdollModeUT(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool on = lua_toboolean(L, 2) != 0;
    Ogre::Vector3 momentum;
    readVector3(L, 3, momentum);
    RagdollPart::Enum part = (RagdollPart::Enum)luaL_checkinteger(L, 4);
    const char* physicsFile = luaL_checkstring(L, 5);
    Character* me = checkObject<Character>(L, 6, CharacterBinding::getMetatableName());
    instance->ragdollModeUT(on, momentum, part, physicsFile, me);
    return 0;
}

int AnimationClassBinding::_NV_ragdollModeUT(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool on = lua_toboolean(L, 2) != 0;
    Ogre::Vector3 momentum;
    readVector3(L, 3, momentum);
    RagdollPart::Enum part = (RagdollPart::Enum)luaL_checkinteger(L, 4);
    const char* physicsFile = luaL_checkstring(L, 5);
    Character* me = checkObject<Character>(L, 6, CharacterBinding::getMetatableName());
    instance->_NV_ragdollModeUT(on, momentum, part, physicsFile, me);
    return 0;
}

int AnimationClassBinding::postRagdollCreationCallbackMT(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->postRagdollCreationCallbackMT(on);
    return 0;
}

int AnimationClassBinding::_NV_postRagdollCreationCallbackMT(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_postRagdollCreationCallbackMT(on);
    return 0;
}

int AnimationClassBinding::hasRagdollPart(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    RagdollPart::Enum part = (RagdollPart::Enum)luaL_checkinteger(L, 2);
    bool result = instance->hasRagdollPart(part);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBinding::isPhysical(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool result = instance->isPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBinding::getHeight(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    float result = instance->getHeight();
    lua_pushnumber(L, result);
    return 1;
}

int AnimationClassBinding::randomiseAnimationPosition(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    instance->randomiseAnimationPosition();
    return 0;
}

int AnimationClassBinding::beingCarriedUpdate(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    Ogre::Quaternion rot;
    readQuaternion(L, 3, rot);
    Ogre::Vector3 result = instance->beingCarriedUpdate(pos, rot);
    pushVector3(L, result);
    return 1;
}

int AnimationClassBinding::rangedCombatModeUpdate(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    Ogre::Vector3 targetpos;
    readVector3(L, 2, targetpos);
    instance->rangedCombatModeUpdate(targetpos);
    return 0;
}

// AnimationData forms by argument count: (anim, speed, blend), (anim, speed, lay, blend), (anim, speed, lay, blend, ext).
int AnimationClassBinding::runAnimation(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    if (AnimationData* anim = testObject<AnimationData>(L, 2, AnimationDataBinding::getMetatableName())) {
        float speed = (float)luaL_checknumber(L, 3);
        int top = lua_gettop(L);
        if (top <= 4) {
            float blend = (float)luaL_checknumber(L, 4);
            instance->runAnimation(anim, speed, blend);
            return 0;
        }
        AnimationLayerEnum lay = (AnimationLayerEnum)luaL_checkinteger(L, 4);
        float blend = (float)luaL_checknumber(L, 5);
        if (top >= 6) {
            const char* ext = luaL_checkstring(L, 6);
            instance->runAnimation(anim, speed, lay, blend, ext);
        } else {
            instance->runAnimation(anim, speed, lay, blend);
        }
        return 0;
    }
    if (lua_type(L, 2) != LUA_TSTRING)
        return luaL_error(L, "Argument 2 to runAnimation must be a string or AnimationData, got %s", luaL_typename(L, 2));
    const char* name = lua_tostring(L, 2);
    float speed = (float)luaL_checknumber(L, 3);
    float blend = (float)luaL_checknumber(L, 4);
    instance->runAnimation(name, speed, blend);
    return 0;
}

int AnimationClassBinding::runAnimation_manualTiming(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    AnimationData* anim = checkObject<AnimationData>(L, 2, AnimationDataBinding::getMetatableName());
    float time01 = (float)luaL_checknumber(L, 3);
    float blend = (float)luaL_checknumber(L, 4);
    instance->runAnimation_manualTiming(anim, time01, blend);
    return 0;
}

int AnimationClassBinding::endCombatAnimation(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    instance->endCombatAnimation();
    return 0;
}

int AnimationClassBinding::runCombatAnimation(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    CombatTechniqueData* anim = checkObject<CombatTechniqueData>(L, 2, CombatTechniqueDataBinding::getMetatableName());
    float speed = (float)luaL_checknumber(L, 3);
    const std::string additionalString = luaL_checkstring(L, 4);
    instance->runCombatAnimation(anim, speed, additionalString);
    return 0;
}

int AnimationClassBinding::startCombatAnimation(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    CombatTechniqueData* anim = checkObject<CombatTechniqueData>(L, 2, CombatTechniqueDataBinding::getMetatableName());
    float speed = (float)luaL_checknumber(L, 3);
    const std::string additionalString = luaL_checkstring(L, 4);
    instance->startCombatAnimation(anim, speed, additionalString);
    return 0;
}

int AnimationClassBinding::startAnimation(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    if (AnimationData* dat = testObject<AnimationData>(L, 2, AnimationDataBinding::getMetatableName())) {
        float speed = (float)luaL_checknumber(L, 3);
        float startWeight = (float)luaL_checknumber(L, 4);
        instance->startAnimation(dat, speed, startWeight);
        return 0;
    }
    if (lua_type(L, 2) != LUA_TSTRING)
        return luaL_error(L, "Argument 2 to startAnimation must be a string or AnimationData, got %s", luaL_typename(L, 2));
    const char* anim = lua_tostring(L, 2);
    float speed = (float)luaL_checknumber(L, 3);
    float startWeight = (float)luaL_checknumber(L, 4);
    instance->startAnimation(anim, speed, startWeight);
    return 0;
}

int AnimationClassBinding::stopAnimation(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    if (AnimationData* ad = testObject<AnimationData>(L, 2, AnimationDataBinding::getMetatableName())) {
        instance->stopAnimation(ad);
        return 0;
    }
    if (lua_type(L, 2) != LUA_TSTRING)
        return luaL_error(L, "Argument 2 to stopAnimation must be a string or AnimationData, got %s", luaL_typename(L, 2));
    const std::string anim = lua_tostring(L, 2);
    instance->stopAnimation(anim);
    return 0;
}

int AnimationClassBinding::activateVisuals(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    instance->activateVisuals();
    return 0;
}

// Both forms look the name up with operator[], so an unknown name adds a null entry to
// myAnimList->allAnims; the engine's own iteration of allAnims skips null entries.
int AnimationClassBinding::getAnimationData(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    if (lua_type(L, 2) == LUA_TSTRING) {
        const char* name = lua_tostring(L, 2);
        AnimationData* result = instance->getAnimationData(name);
        return pushObject<AnimationData>(L, result, AnimationDataBinding::getMetatableName());
    }
    if (GameData* dat = testObject<GameData>(L, 2, GameDataBinding::getMetatableName())) {
        AnimationData* result = instance->getAnimationData(dat);
        return pushObject<AnimationData>(L, result, AnimationDataBinding::getMetatableName());
    }
    return luaL_error(L, "Argument 2 to getAnimationData must be a string or GameData, got %s", luaL_typename(L, 2));
}

int AnimationClassBinding::_NV_getAnimationData(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    if (lua_type(L, 2) == LUA_TSTRING) {
        const char* name = lua_tostring(L, 2);
        AnimationData* result = instance->_NV_getAnimationData(name);
        return pushObject<AnimationData>(L, result, AnimationDataBinding::getMetatableName());
    }
    if (GameData* dat = testObject<GameData>(L, 2, GameDataBinding::getMetatableName())) {
        AnimationData* result = instance->_NV_getAnimationData(dat);
        return pushObject<AnimationData>(L, result, AnimationDataBinding::getMetatableName());
    }
    return luaL_error(L, "Argument 2 to _NV_getAnimationData must be a string or GameData, got %s", luaL_typename(L, 2));
}

int AnimationClassBinding::getAnimationDataByOgreName(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    const std::string name = luaL_checkstring(L, 2);
    AnimationData* result = instance->getAnimationDataByOgreName(name);
    return pushObject<AnimationData>(L, result, AnimationDataBinding::getMetatableName());
}

int AnimationClassBinding::_NV_getAnimationDataByOgreName(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    const std::string name = luaL_checkstring(L, 2);
    AnimationData* result = instance->_NV_getAnimationDataByOgreName(name);
    return pushObject<AnimationData>(L, result, AnimationDataBinding::getMetatableName());
}

int AnimationClassBinding::estimateAnimationTime(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    const std::string name = luaL_checkstring(L, 2);
    float result = instance->estimateAnimationTime(name);
    lua_pushnumber(L, result);
    return 1;
}

int AnimationClassBinding::notifyRelocatedAnimLoop(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    instance->notifyRelocatedAnimLoop();
    return 0;
}

int AnimationClassBinding::serialiseAppearance(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->serialiseAppearance(state);
    return 0;
}

int AnimationClassBinding::setAppearanceData(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    GameDataCopyStandalone* data = checkObject<GameDataCopyStandalone>(L, 2, GameDataCopyStandaloneBinding::getMetatableName());
    instance->setAppearanceData(data);
    return 0;
}

int AnimationClassBinding::getAppearanceData(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    GameDataCopyStandalone* result = instance->getAppearanceData();
    return pushObject<GameDataCopyStandalone>(L, result, GameDataCopyStandaloneBinding::getMetatableName());
}

int AnimationClassBinding::getAudioObject(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    unsigned __int64 result = instance->getAudioObject();
    lua_pushinteger(L, static_cast<lua_Integer>(result));
    return 1;
}

int AnimationClassBinding::_NV_getAudioObject(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    unsigned __int64 result = instance->_NV_getAudioObject();
    lua_pushinteger(L, static_cast<lua_Integer>(result));
    return 1;
}

int AnimationClassBinding::playSlaveAnim(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    const char* name = luaL_checkstring(L, 2);
    float speedMult = (float)luaL_checknumber(L, 3);
    float sync = (float)luaL_checknumber(L, 4);
    float startWeight = (float)luaL_checknumber(L, 5);
    instance->playSlaveAnim(name, speedMult, sync, startWeight);
    return 0;
}

int AnimationClassBinding::runSlaveAnim(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    const char* name = luaL_checkstring(L, 2);
    float speedMult = (float)luaL_checknumber(L, 3);
    float sync = (float)luaL_checknumber(L, 4);
    float startWeight = (float)luaL_checknumber(L, 5);
    instance->runSlaveAnim(name, speedMult, sync, startWeight);
    return 0;
}

int AnimationClassBinding::endSlaveAnim(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    const std::string anim = luaL_checkstring(L, 2);
    instance->endSlaveAnim(anim);
    return 0;
}

int AnimationClassBinding::isSlaveAnimating(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool result = instance->isSlaveAnimating();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBinding::setSlaveHandle(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    instance->setSlaveHandle(*h);
    return 0;
}

int AnimationClassBinding::slaveAttachToBoneMode(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    const std::string bone = luaL_checkstring(L, 2);
    instance->slaveAttachToBoneMode(bone);
    return 0;
}

int AnimationClassBinding::isSlaveAttachToBoneMode(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    const std::string& result = instance->isSlaveAttachToBoneMode();
    lua_pushstring(L, result.c_str());
    return 1;
}

int AnimationClassBinding::getCharacter(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    Character* result = instance->getCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int AnimationClassBinding::_NV_getCharacter(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    Character* result = instance->_NV_getCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int AnimationClassBinding::setLegDamage(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    float left = (float)luaL_checknumber(L, 2);
    float right = (float)luaL_checknumber(L, 3);
    instance->setLegDamage(left, right);
    return 0;
}

int AnimationClassBinding::_NV_setLegDamage(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    float left = (float)luaL_checknumber(L, 2);
    float right = (float)luaL_checknumber(L, 3);
    instance->_NV_setLegDamage(left, right);
    return 0;
}

int AnimationClassBinding::setDesiredPainOverlayAnimOverride(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    const std::string anim = luaL_checkstring(L, 2);
    instance->setDesiredPainOverlayAnimOverride(anim);
    return 0;
}

int AnimationClassBinding::_NV_setDesiredPainOverlayAnimOverride(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    const std::string anim = luaL_checkstring(L, 2);
    instance->_NV_setDesiredPainOverlayAnimOverride(anim);
    return 0;
}

int AnimationClassBinding::ragdollTheWeapons(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    const char* slotname = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    bool attach = lua_toboolean(L, 4) != 0;
    instance->ragdollTheWeapons(slotname, item, attach);
    return 0;
}

int AnimationClassBinding::_NV_ragdollTheWeapons(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    const char* slotname = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    bool attach = lua_toboolean(L, 4) != 0;
    instance->_NV_ragdollTheWeapons(slotname, item, attach);
    return 0;
}

int AnimationClassBinding::setStance(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool crouch = lua_toboolean(L, 2) != 0;
    bool prone = lua_toboolean(L, 3) != 0;
    instance->setStance(crouch, prone);
    return 0;
}

int AnimationClassBinding::_NV_setStance(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool crouch = lua_toboolean(L, 2) != 0;
    bool prone = lua_toboolean(L, 3) != 0;
    instance->_NV_setStance(crouch, prone);
    return 0;
}

int AnimationClassBinding::setStanceAnimation(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    StanceEnum _a1 = (StanceEnum)luaL_checkinteger(L, 2);
    instance->setStanceAnimation(_a1);
    return 0;
}

int AnimationClassBinding::_NV_setStanceAnimation(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    StanceEnum _a1 = (StanceEnum)luaL_checkinteger(L, 2);
    instance->_NV_setStanceAnimation(_a1);
    return 0;
}

int AnimationClassBinding::setEquipmentInHand(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool l = lua_toboolean(L, 2) != 0;
    bool r = lua_toboolean(L, 3) != 0;
    instance->setEquipmentInHand(l, r);
    return 0;
}

int AnimationClassBinding::_NV_setEquipmentInHand(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool l = lua_toboolean(L, 2) != 0;
    bool r = lua_toboolean(L, 3) != 0;
    instance->_NV_setEquipmentInHand(l, r);
    return 0;
}

int AnimationClassBinding::isTurning(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool result = instance->isTurning();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBinding::_NV_isTurning(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool result = instance->_NV_isTurning();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBinding::isTurningFar(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool result = instance->isTurningFar();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBinding::_NV_isTurningFar(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool result = instance->_NV_isTurningFar();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBinding::lookAt(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    Ogre::Vector3 position;
    readVector3(L, 2, position);
    bool result = instance->lookAt(position);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBinding::_NV_lookAt(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    Ogre::Vector3 position;
    readVector3(L, 2, position);
    bool result = instance->_NV_lookAt(position);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBinding::getLookDirection(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    Ogre::Vector3 result = instance->getLookDirection();
    pushVector3(L, result);
    return 1;
}

int AnimationClassBinding::_NV_getLookDirection(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    Ogre::Vector3 result = instance->_NV_getLookDirection();
    pushVector3(L, result);
    return 1;
}

int AnimationClassBinding::chooseStumbleAnim(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    // bodypart keys myAnimList's stumble map, which inserts an entry for a missing key.
    GameData* bodypart = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    CutOrigination hitFrom = (CutOrigination)luaL_checkinteger(L, 3);
    bool bigone = lua_toboolean(L, 4) != 0;
    AnimationData* result = instance->chooseStumbleAnim(bodypart, hitFrom, bigone);
    return pushObject<AnimationData>(L, result, AnimationDataBinding::getMetatableName());
}

int AnimationClassBinding::getIdleAnimation(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    AnimationData* result = instance->getIdleAnimation();
    return pushObject<AnimationData>(L, result, AnimationDataBinding::getMetatableName());
}

int AnimationClassBinding::_NV_getIdleAnimation(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    AnimationData* result = instance->_NV_getIdleAnimation();
    return pushObject<AnimationData>(L, result, AnimationDataBinding::getMetatableName());
}

int AnimationClassBinding::getFloatingAnim(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    AnimationData* result = instance->getFloatingAnim();
    return pushObject<AnimationData>(L, result, AnimationDataBinding::getMetatableName());
}

int AnimationClassBinding::_NV_getFloatingAnim(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    AnimationData* result = instance->_NV_getFloatingAnim();
    return pushObject<AnimationData>(L, result, AnimationDataBinding::getMetatableName());
}

int AnimationClassBinding::getStandingUpAnim(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    AnimationData* result = instance->getStandingUpAnim();
    return pushObject<AnimationData>(L, result, AnimationDataBinding::getMetatableName());
}

int AnimationClassBinding::_NV_getStandingUpAnim(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    AnimationData* result = instance->_NV_getStandingUpAnim();
    return pushObject<AnimationData>(L, result, AnimationDataBinding::getMetatableName());
}

int AnimationClassBinding::hasAction(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool result = instance->hasAction();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBinding::animationSelection(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    float _TIME = (float)luaL_checknumber(L, 2);
    instance->animationSelection(_TIME);
    return 0;
}

int AnimationClassBinding::animationSelectionCombatMode(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    float _TIME = (float)luaL_checknumber(L, 2);
    instance->animationSelectionCombatMode(_TIME);
    return 0;
}

int AnimationClassBinding::_NV_animationSelectionCombatMode(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    float _TIME = (float)luaL_checknumber(L, 2);
    instance->_NV_animationSelectionCombatMode(_TIME);
    return 0;
}

int AnimationClassBinding::runStrafe(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    // runStrafe clears the strafe weight for a null strafe.
    AnimationData* strafe = lua_isnoneornil(L, 2) ? nullptr : checkObject<AnimationData>(L, 2, AnimationDataBinding::getMetatableName());
    float weightLimit = (float)luaL_checknumber(L, 3);
    instance->runStrafe(strafe, weightLimit);
    return 0;
}

int AnimationClassBinding::_NV_runStrafe(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    // runStrafe clears the strafe weight for a null strafe.
    AnimationData* strafe = lua_isnoneornil(L, 2) ? nullptr : checkObject<AnimationData>(L, 2, AnimationDataBinding::getMetatableName());
    float weightLimit = (float)luaL_checknumber(L, 3);
    instance->_NV_runStrafe(strafe, weightLimit);
    return 0;
}

int AnimationClassBinding::overlaidAnimationSelection(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    instance->overlaidAnimationSelection();
    return 0;
}

int AnimationClassBinding::_NV_overlaidAnimationSelection(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    instance->_NV_overlaidAnimationSelection();
    return 0;
}

int AnimationClassBinding::processTurnAnim(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool result = instance->processTurnAnim();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBinding::_NV_processTurnAnim(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool result = instance->_NV_processTurnAnim();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBinding::breathing(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool armsToo = lua_toboolean(L, 2) != 0;
    instance->breathing(armsToo);
    return 0;
}

int AnimationClassBinding::_NV_breathing(lua_State* L)
{
    AnimationClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClass is nil");

    bool armsToo = lua_toboolean(L, 2) != 0;
    instance->_NV_breathing(armsToo);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 411: AnimationClassHuman* isHuman(...) - unbound pointer
  line 413: bool create(...) - initialisation only; Lua cannot construct an AnimationClass, and AnimationClassBase::create appends new layers on a live instance
  line 436: void setBodyEntity(Ogre::Entity*) - unbound pointer argument
  line 466: RagdollClass* getRagdoll(...) - unbound pointer
  line 467: RagdollClass* _NV_getRagdoll(...) - unbound pointer
  line 469: bool setupRagdoll(Scythe::SkeletonData*) - unbound pointer argument
  line 494: AnimationEvents* getEvents(...) - unbound pointer
  line 502: AnimsListsManager::AnimList* getAnimationDatasList(...) - AnimsListsManager::AnimList is unbound
  line 521: void setDesiredPainOverlayAnims(std::set<StringValuePair, ...>) - StringValuePair is unbound
  line 522: void _NV_setDesiredPainOverlayAnims(std::set<StringValuePair, ...>) - StringValuePair is unbound
  line 566: void chooseAnims(...) - AnimationChoices, lektor<AnimationData*>, and AnimationRequirement are unbound
  line 567: AnimationChoices chooseRandomAnim(...) - AnimationChoices, lektor<AnimationData*>, and AnimationRequirement are unbound
  line 568: float scoreAnim(...) - AnimationRequirement is unbound
  line 569: void processMoveAnims(...) - lektor<AnimationData*> and AnimationRequirement are unbound
  line 570: bool processActionAnims(...) - boost::unordered_map<std::string, AnimationData*> and AnimationRequirement are unbound
  line 571: void processIdleAnims(...) - lektor<AnimationData*> and AnimationRequirement are unbound
  line 572: void processCombatIdleAnims(...) - lektor<AnimationData*> and AnimationRequirement are unbound
*/

/*
Skipped properties needing manual binding:
  line 549: animationRequirements (AnimationRequirement) - unbound type
  line 551: myAnimList (AnimsListsManager::AnimList*) - unbound pointer
  line 576: ragdoll (RagdollClass*) - unbound pointer
  line 577: ragdollAnimation (RagdollAnimation*) - unbound pointer; ~AnimationClass deletes it
*/

int AnimationClassBinding::gc(lua_State* L)
{
    // Borrowed from the owning Character
    return 0;
}

int AnimationClassBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AnimationClass object");
    return 1;
}

void AnimationClassBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AnimationClassBinding::gc },
        { "__tostring", AnimationClassBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "debugGetAllAnimations", AnimationClassBinding::debugGetAllAnimations },
        { "startStumble", AnimationClassBinding::startStumble },
        { "endStumble", AnimationClassBinding::endStumble },
        { "currentlyStumbling", AnimationClassBinding::currentlyStumbling },
        { "getCurrentlyStumbleAnim", AnimationClassBinding::getCurrentlyStumbleAnim },
        { "isCurrentlyIncapableOfWaypointMovemode", AnimationClassBinding::isCurrentlyIncapableOfWaypointMovemode },
        { "threadSafeRagdollUpdateUT", AnimationClassBinding::threadSafeRagdollUpdateUT },
        { "update", AnimationClassBinding::update },
        { "_NV_update", AnimationClassBinding::_NV_update },
        { "calculatePositionWithWaterHeight", AnimationClassBinding::calculatePositionWithWaterHeight },
        { "updateAnimationCharacterEditor", AnimationClassBinding::updateAnimationCharacterEditor },
        { "updateThreaded", AnimationClassBinding::updateThreaded },
        { "rotationUpdate", AnimationClassBinding::rotationUpdate },
        { "_NV_rotationUpdate", AnimationClassBinding::_NV_rotationUpdate },
        { "updateAnimationTransforms", AnimationClassBinding::updateAnimationTransforms },
        { "setPosition", AnimationClassBinding::setPosition },
        { "getPosition", AnimationClassBinding::getPosition },
        { "rotateEntityAroundBone", AnimationClassBinding::rotateEntityAroundBone },
        { "getBoneScale", AnimationClassBinding::getBoneScale },
        { "deactivateVisuals", AnimationClassBinding::deactivateVisuals },
        { "getIsActivated", AnimationClassBinding::getIsActivated },
        { "resetBody", AnimationClassBinding::resetBody },
        { "restartAction", AnimationClassBinding::restartAction },
        { "playAction", AnimationClassBinding::playAction },
        { "stopAction", AnimationClassBinding::stopAction },
        { "setAnimationMoveSpeed", AnimationClassBinding::setAnimationMoveSpeed },
        { "setStrafeSpeed", AnimationClassBinding::setStrafeSpeed },
        { "setCombatMode", AnimationClassBinding::setCombatMode },
        { "setWeatherType", AnimationClassBinding::setWeatherType },
        { "getWeatherType", AnimationClassBinding::getWeatherType },
        { "getWeatherStrength", AnimationClassBinding::getWeatherStrength },
        { "setStealthMode", AnimationClassBinding::setStealthMode },
        { "setMaximumSpeed", AnimationClassBinding::setMaximumSpeed },
        { "getMaximumSpeed", AnimationClassBinding::getMaximumSpeed },
        { "isLinearAnimationDone_byName", AnimationClassBinding::isLinearAnimationDone_byName },
        { "isLinearAnimationDone", AnimationClassBinding::isLinearAnimationDone },
        { "getFootHeight", AnimationClassBinding::getFootHeight },
        { "calculateFeetHeight", AnimationClassBinding::calculateFeetHeight },
        { "setBootHeight", AnimationClassBinding::setBootHeight },
        { "isBeingCarried", AnimationClassBinding::isBeingCarried },
        { "isTotallyRagdoll", AnimationClassBinding::isTotallyRagdoll },
        { "notifyRagdollNeedsAnUpdate", AnimationClassBinding::notifyRagdollNeedsAnUpdate },
        { "setCarryMode", AnimationClassBinding::setCarryMode },
        { "setCombatModeLegsIdle", AnimationClassBinding::setCombatModeLegsIdle },
        { "setCombatModeUpperIdle", AnimationClassBinding::setCombatModeUpperIdle },
        { "isRagdoll", AnimationClassBinding::isRagdoll },
        { "ragdollAnimateTo", AnimationClassBinding::ragdollAnimateTo },
        { "isRagdollAnimated", AnimationClassBinding::isRagdollAnimated },
        { "ragdollModeUT", AnimationClassBinding::ragdollModeUT },
        { "_NV_ragdollModeUT", AnimationClassBinding::_NV_ragdollModeUT },
        { "postRagdollCreationCallbackMT", AnimationClassBinding::postRagdollCreationCallbackMT },
        { "_NV_postRagdollCreationCallbackMT", AnimationClassBinding::_NV_postRagdollCreationCallbackMT },
        { "hasRagdollPart", AnimationClassBinding::hasRagdollPart },
        { "isPhysical", AnimationClassBinding::isPhysical },
        { "getHeight", AnimationClassBinding::getHeight },
        { "randomiseAnimationPosition", AnimationClassBinding::randomiseAnimationPosition },
        { "beingCarriedUpdate", AnimationClassBinding::beingCarriedUpdate },
        { "rangedCombatModeUpdate", AnimationClassBinding::rangedCombatModeUpdate },
        { "runAnimation", AnimationClassBinding::runAnimation },
        { "runAnimation_manualTiming", AnimationClassBinding::runAnimation_manualTiming },
        { "endCombatAnimation", AnimationClassBinding::endCombatAnimation },
        { "runCombatAnimation", AnimationClassBinding::runCombatAnimation },
        { "startCombatAnimation", AnimationClassBinding::startCombatAnimation },
        { "startAnimation", AnimationClassBinding::startAnimation },
        { "stopAnimation", AnimationClassBinding::stopAnimation },
        { "activateVisuals", AnimationClassBinding::activateVisuals },
        { "getAnimationData", AnimationClassBinding::getAnimationData },
        { "_NV_getAnimationData", AnimationClassBinding::_NV_getAnimationData },
        { "getAnimationDataByOgreName", AnimationClassBinding::getAnimationDataByOgreName },
        { "_NV_getAnimationDataByOgreName", AnimationClassBinding::_NV_getAnimationDataByOgreName },
        { "estimateAnimationTime", AnimationClassBinding::estimateAnimationTime },
        { "notifyRelocatedAnimLoop", AnimationClassBinding::notifyRelocatedAnimLoop },
        { "serialiseAppearance", AnimationClassBinding::serialiseAppearance },
        { "setAppearanceData", AnimationClassBinding::setAppearanceData },
        { "getAppearanceData", AnimationClassBinding::getAppearanceData },
        { "getAudioObject", AnimationClassBinding::getAudioObject },
        { "_NV_getAudioObject", AnimationClassBinding::_NV_getAudioObject },
        { "playSlaveAnim", AnimationClassBinding::playSlaveAnim },
        { "runSlaveAnim", AnimationClassBinding::runSlaveAnim },
        { "endSlaveAnim", AnimationClassBinding::endSlaveAnim },
        { "isSlaveAnimating", AnimationClassBinding::isSlaveAnimating },
        { "setSlaveHandle", AnimationClassBinding::setSlaveHandle },
        { "slaveAttachToBoneMode", AnimationClassBinding::slaveAttachToBoneMode },
        { "isSlaveAttachToBoneMode", AnimationClassBinding::isSlaveAttachToBoneMode },
        { "getCharacter", AnimationClassBinding::getCharacter },
        { "_NV_getCharacter", AnimationClassBinding::_NV_getCharacter },
        { "setLegDamage", AnimationClassBinding::setLegDamage },
        { "_NV_setLegDamage", AnimationClassBinding::_NV_setLegDamage },
        { "setDesiredPainOverlayAnimOverride", AnimationClassBinding::setDesiredPainOverlayAnimOverride },
        { "_NV_setDesiredPainOverlayAnimOverride", AnimationClassBinding::_NV_setDesiredPainOverlayAnimOverride },
        { "ragdollTheWeapons", AnimationClassBinding::ragdollTheWeapons },
        { "_NV_ragdollTheWeapons", AnimationClassBinding::_NV_ragdollTheWeapons },
        { "setStance", AnimationClassBinding::setStance },
        { "_NV_setStance", AnimationClassBinding::_NV_setStance },
        { "setStanceAnimation", AnimationClassBinding::setStanceAnimation },
        { "_NV_setStanceAnimation", AnimationClassBinding::_NV_setStanceAnimation },
        { "setEquipmentInHand", AnimationClassBinding::setEquipmentInHand },
        { "_NV_setEquipmentInHand", AnimationClassBinding::_NV_setEquipmentInHand },
        { "isTurning", AnimationClassBinding::isTurning },
        { "_NV_isTurning", AnimationClassBinding::_NV_isTurning },
        { "isTurningFar", AnimationClassBinding::isTurningFar },
        { "_NV_isTurningFar", AnimationClassBinding::_NV_isTurningFar },
        { "lookAt", AnimationClassBinding::lookAt },
        { "_NV_lookAt", AnimationClassBinding::_NV_lookAt },
        { "getLookDirection", AnimationClassBinding::getLookDirection },
        { "_NV_getLookDirection", AnimationClassBinding::_NV_getLookDirection },
        { "chooseStumbleAnim", AnimationClassBinding::chooseStumbleAnim },
        { "getIdleAnimation", AnimationClassBinding::getIdleAnimation },
        { "_NV_getIdleAnimation", AnimationClassBinding::_NV_getIdleAnimation },
        { "getFloatingAnim", AnimationClassBinding::getFloatingAnim },
        { "_NV_getFloatingAnim", AnimationClassBinding::_NV_getFloatingAnim },
        { "getStandingUpAnim", AnimationClassBinding::getStandingUpAnim },
        { "_NV_getStandingUpAnim", AnimationClassBinding::_NV_getStandingUpAnim },
        { "hasAction", AnimationClassBinding::hasAction },
        { "animationSelection", AnimationClassBinding::animationSelection },
        { "animationSelectionCombatMode", AnimationClassBinding::animationSelectionCombatMode },
        { "_NV_animationSelectionCombatMode", AnimationClassBinding::_NV_animationSelectionCombatMode },
        { "runStrafe", AnimationClassBinding::runStrafe },
        { "_NV_runStrafe", AnimationClassBinding::_NV_runStrafe },
        { "overlaidAnimationSelection", AnimationClassBinding::overlaidAnimationSelection },
        { "_NV_overlaidAnimationSelection", AnimationClassBinding::_NV_overlaidAnimationSelection },
        { "processTurnAnim", AnimationClassBinding::processTurnAnim },
        { "_NV_processTurnAnim", AnimationClassBinding::_NV_processTurnAnim },
        { "breathing", AnimationClassBinding::breathing },
        { "_NV_breathing", AnimationClassBinding::_NV_breathing },
        { 0, 0 }
    };

    registerClass(
        L,
        AnimationClassBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AnimationClassBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "appearance", AnimationClass_get_appearance);
    registerGetter(L, "strafeBlendFilter", AnimationClass_get_strafeBlendFilter);
    registerGetter(L, "feetHeight", AnimationClass_get_feetHeight);
    registerGetter(L, "bootHeight", AnimationClass_get_bootHeight);
    registerGetter(L, "totalActionWeight", AnimationClass_get_totalActionWeight);
    registerGetter(L, "disableRagdollKinematics", AnimationClass_get_disableRagdollKinematics);
    registerGetter(L, "me", AnimationClass_get_me);
    registerGetter(L, "defaultIdleAnimation", AnimationClass_get_defaultIdleAnimation);
    registerGetter(L, "ragdollParts", AnimationClass_get_ragdollParts);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "feetHeight", AnimationClass_set_feetHeight);
    registerSetter(L, "bootHeight", AnimationClass_set_bootHeight);
    registerSetter(L, "totalActionWeight", AnimationClass_set_totalActionWeight);
    registerSetter(L, "disableRagdollKinematics", AnimationClass_set_disableRagdollKinematics);
    registerSetter(L, "me", AnimationClass_set_me);
    registerSetter(L, "defaultIdleAnimation", AnimationClass_set_defaultIdleAnimation);
    registerSetter(L, "ragdollParts", AnimationClass_set_ragdollParts);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
