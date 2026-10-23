#include "pch.h"
#include "kenshi/Animation/AnimationClass.h"
#include "AnimationClassBaseBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/CharMovementBinding.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/CombatTechniqueDataBinding.h"
#include "Bindings/Kenshi/Util/BoostUnorderedBinding.h"
#include "Bindings/Kenshi/Util/StdMapBinding.h"

namespace KenshiLua
{

static_assert(offsetof(AnimationClassBase, boneInitialWorldPositions) == 0x10, "AnimationClassBase::boneInitialWorldPositions offset does not match the game");
static_assert(offsetof(AnimationClassBase, desiredOrientation) == 0x78, "AnimationClassBase::desiredOrientation offset does not match the game");
static_assert(offsetof(AnimationClassBase, movement) == 0xC0, "AnimationClassBase::movement offset does not match the game");
static_assert(offsetof(AnimationClassBase, layer) == 0xD0, "AnimationClassBase::layer offset does not match the game");
static_assert(sizeof(AnimationClassBase) == 0xE8, "AnimationClassBase size does not match the game");

// Registered by GameDataBinding.
typedef BoostUnorderedMapBinding<std::string, Ogre::Vector3> BoneVector3MapBinding;
// Registered by LuaBindings::registerStdMap.
typedef StdMapBinding<std::string, Ogre::Quaternion> BoneQuaternionMapBinding;

static AnimationClassBase* getInstance(lua_State* L, int idx)
{
    return checkObject<AnimationClassBase>(L, idx, AnimationClassBaseBinding::getMetatableName());
}

// --- Getters for AnimationClassBase ---
static int AnimationClassBase_get_zeroOutTheBlending(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    lua_pushboolean(L, instance->zeroOutTheBlending ? 1 : 0);
    return 1;
}

static int AnimationClassBase_get_boneInitialWorldPositions(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    return BoneVector3MapBinding::push(L, &instance->boneInitialWorldPositions);
}

static int AnimationClassBase_get_boneInitialWorldOrientations(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    return pushObject<BoneQuaternionMapBinding::MapType>(L, &instance->boneInitialWorldOrientations, BoneQuaternionMapBinding::getMetatableName());
}

static int AnimationClassBase_get_desiredOrientation(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    pushQuaternion(L, instance->desiredOrientation);
    return 1;
}

static int AnimationClassBase_get_isActivated(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    lua_pushboolean(L, instance->isActivated ? 1 : 0);
    return 1;
}

static int AnimationClassBase_get_activateFlag(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    lua_pushboolean(L, instance->activateFlag ? 1 : 0);
    return 1;
}

static int AnimationClassBase_get_lastAnimRelocation(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    pushVector3(L, instance->lastAnimRelocation);
    return 1;
}

static int AnimationClassBase_get_rootBonePosition(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    pushVector3(L, instance->rootBonePosition);
    return 1;
}

static int AnimationClassBase_get_isVisible(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    lua_pushboolean(L, instance->isVisible ? 1 : 0);
    return 1;
}

static int AnimationClassBase_get_isIdle(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    lua_pushboolean(L, instance->isIdle ? 1 : 0);
    return 1;
}

static int AnimationClassBase_get_movement(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    return pushObject<CharMovement>(L, instance->movement, CharMovementBinding::getMetatableName());
}

static int AnimationClassBase_get_masterTime(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    lua_pushnumber(L, instance->masterTime);
    return 1;
}

static int AnimationClassBase_get_masterSpeed(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    lua_pushnumber(L, instance->masterSpeed);
    return 1;
}

// --- Setters for AnimationClassBase ---
static int AnimationClassBase_set_zeroOutTheBlending(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    instance->zeroOutTheBlending = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationClassBase_set_boneInitialWorldPositions(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    instance->boneInitialWorldPositions = *BoneVector3MapBinding::getInstance(L, 2);
    return 0;
}

static int AnimationClassBase_set_boneInitialWorldOrientations(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    instance->boneInitialWorldOrientations = *BoneQuaternionMapBinding::getInstance(L, 2);
    return 0;
}

static int AnimationClassBase_set_desiredOrientation(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    readQuaternion(L, 2, instance->desiredOrientation);
    return 0;
}

static int AnimationClassBase_set_isActivated(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    instance->isActivated = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationClassBase_set_activateFlag(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    instance->activateFlag = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationClassBase_set_lastAnimRelocation(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    readVector3(L, 2, instance->lastAnimRelocation);
    return 0;
}

static int AnimationClassBase_set_rootBonePosition(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    readVector3(L, 2, instance->rootBonePosition);
    return 0;
}

static int AnimationClassBase_set_isVisible(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    instance->isVisible = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationClassBase_set_isIdle(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    instance->isIdle = lua_toboolean(L, 2) != 0;
    return 0;
}

// create() stores movement and the animation layers keep their own copy; a null
// movement is dereferenced by the update path.
static int AnimationClassBase_set_movement(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    instance->movement = checkObject<CharMovement>(L, 2, CharMovementBinding::getMetatableName());
    return 0;
}

static int AnimationClassBase_set_masterTime(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    instance->masterTime = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationClassBase_set_masterSpeed(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");
    instance->masterSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

int AnimationClassBaseBinding::setVisible(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setVisible(on);
    return 0;
}

int AnimationClassBaseBinding::getVisible(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    bool result = instance->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBaseBinding::stopAllAnimation(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    bool hardStop = lua_toboolean(L, 2) != 0;
    instance->stopAllAnimation(hardStop);
    return 0;
}

int AnimationClassBaseBinding::clearAllAnimationUT(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    instance->clearAllAnimationUT();
    return 0;
}

int AnimationClassBaseBinding::getBoneWorldOrientation(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    const std::string name = luaL_checkstring(L, 2);
    Ogre::Quaternion result = instance->getBoneWorldOrientation(name);
    pushQuaternion(L, result);
    return 1;
}

int AnimationClassBaseBinding::getBoneWorldPosition(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    const std::string name = luaL_checkstring(L, 2);
    float scale = (float)luaL_checknumber(L, 3);
    Ogre::Vector3 result = instance->getBoneWorldPosition(name, scale);
    pushVector3(L, result);
    return 1;
}

int AnimationClassBaseBinding::getHasBone(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    const std::string name = luaL_checkstring(L, 2);
    bool result = instance->getHasBone(name);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBaseBinding::hasAnimation(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    const std::string s = luaL_checkstring(L, 2);
    bool result = instance->hasAnimation(s);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBaseBinding::getSceneNodePosition(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    const Ogre::Vector3 result = instance->getSceneNodePosition();
    pushVector3(L, result);
    return 1;
}

int AnimationClassBaseBinding::getSceneNodeOrientation(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    const Ogre::Quaternion result = instance->getSceneNodeOrientation();
    pushQuaternion(L, result);
    return 1;
}

int AnimationClassBaseBinding::getBoneLocalOrientation(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    const std::string name = luaL_checkstring(L, 2);
    Ogre::Quaternion result = instance->getBoneLocalOrientation(name);
    pushQuaternion(L, result);
    return 1;
}

int AnimationClassBaseBinding::getBoneLocalPosition(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    const std::string name = luaL_checkstring(L, 2);
    Ogre::Vector3 result = instance->getBoneLocalPosition(name);
    pushVector3(L, result);
    return 1;
}

int AnimationClassBaseBinding::getRootBoneWorldPosition(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    const Ogre::Vector3& result = instance->getRootBoneWorldPosition();
    pushVector3(L, result);
    return 1;
}

int AnimationClassBaseBinding::getRootBoneLocalPosition(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    Ogre::Vector3 result = instance->getRootBoneLocalPosition();
    pushVector3(L, result);
    return 1;
}

int AnimationClassBaseBinding::getBoneInitialLocalPosition(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    const std::string name = luaL_checkstring(L, 2);
    Ogre::Vector3 result = instance->getBoneInitialLocalPosition(name);
    pushVector3(L, result);
    return 1;
}

int AnimationClassBaseBinding::getBoneInitialLocalOrientation(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    const std::string name = luaL_checkstring(L, 2);
    Ogre::Quaternion result = instance->getBoneInitialLocalOrientation(name);
    pushQuaternion(L, result);
    return 1;
}

int AnimationClassBaseBinding::getBoneInitialWorldPosition(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    const std::string name = luaL_checkstring(L, 2);
    const Ogre::Vector3& result = instance->getBoneInitialWorldPosition(name);
    pushVector3(L, result);
    return 1;
}

int AnimationClassBaseBinding::getBoneInitialWorldOrientation(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    const std::string name = luaL_checkstring(L, 2);
    const Ogre::Quaternion& result = instance->getBoneInitialWorldOrientation(name);
    pushQuaternion(L, result);
    return 1;
}

int AnimationClassBaseBinding::resetOrientation(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    instance->resetOrientation();
    return 0;
}

int AnimationClassBaseBinding::getAnimationProgress(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    if (lua_type(L, 2) == LUA_TSTRING) {
        const std::string name = lua_tostring(L, 2);
        lua_pushnumber(L, instance->getAnimationProgress(name));
        return 1;
    }
    if (CombatTechniqueData* name = testObject<CombatTechniqueData>(L, 2, CombatTechniqueDataBinding::getMetatableName())) {
        lua_pushnumber(L, instance->getAnimationProgress(name));
        return 1;
    }
    return luaL_error(L, "Argument 2 to getAnimationProgress must be a string or CombatTechniqueData, got %s", luaL_typename(L, 2));
}

int AnimationClassBaseBinding::getOrientation(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    Ogre::Quaternion result = instance->getOrientation();
    pushQuaternion(L, result);
    return 1;
}

int AnimationClassBaseBinding::setVerticalPosition(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    float hpos = (float)luaL_checknumber(L, 2);
    instance->setVerticalPosition(hpos);
    return 0;
}

int AnimationClassBaseBinding::getAudioObject(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    unsigned __int64 result = instance->getAudioObject();
    lua_pushinteger(L, static_cast<lua_Integer>(result));
    return 1;
}

int AnimationClassBaseBinding::getCharacter(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    Character* result = instance->getCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int AnimationClassBaseBinding::_NV_getCharacter(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    Character* result = instance->_NV_getCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int AnimationClassBaseBinding::setMasterTimeSpeed(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    float speed = (float)luaL_checknumber(L, 2);
    instance->setMasterTimeSpeed(speed);
    return 0;
}

int AnimationClassBaseBinding::getMasterTimeSpeed(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    float result = instance->getMasterTimeSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int AnimationClassBaseBinding::getMasterTime(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    float result = instance->getMasterTime();
    lua_pushnumber(L, result);
    return 1;
}

int AnimationClassBaseBinding::isVisibleEntity(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    bool result = instance->isVisibleEntity();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBaseBinding::initBoneInitialWorldPositions(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    instance->initBoneInitialWorldPositions();
    return 0;
}

int AnimationClassBaseBinding::isAnimationPlaying(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    const std::string name = luaL_checkstring(L, 2);
    bool result = instance->isAnimationPlaying(name);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationClassBaseBinding::getTotalActionAnimationWeight(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    float result = instance->getTotalActionAnimationWeight();
    lua_pushnumber(L, result);
    return 1;
}

int AnimationClassBaseBinding::stillPlayingAnActionOrSomething(lua_State* L)
{
    AnimationClassBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationClassBase is nil");

    bool result = instance->stillPlayingAnActionOrSomething();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 85: void create(...) - appends five new AnimationLayers each call; Lua cannot construct an AnimationClassBase, and calling it on a live instance duplicates the layers
  line 93: Ogre::OldBone* _getBone(...) - unbound pointer
  line 108: float getAnimationProgress(AnimationData*) - unbound pointer argument; the string and CombatTechniqueData overloads are bound
  line 236: AnimationClassBase::SingleAnimation* getAnimationPlaying_animName(...) - unbound pointer
  line 237: AnimationClassBase::SingleAnimation* getAnimationPlaying_datName(...) - unbound pointer
  line 238: AnimationClassBase::SingleAnimation* getAnimationPlaying(CombatTechniqueData*) - unbound pointer
  line 239: AnimationClassBase::SingleAnimation* getAnimationPlaying(AnimationData*) - unbound pointer
  line 241: float getAnimationCurrentWeight(AnimationData*) - unbound pointer argument
  line 244: Ogre::AnimationState* getAnimationState(...) - unbound pointer
  line 245: Ogre::Animation* getAnimation(...) - unbound pointer
  line 246: AnimationData* getAnimation_Medic(...) - unbound pointer
  line 247: AnimationData* getAnimation_Lockpick(...) - unbound pointer
  line 248: AnimationData* getAnimationData(...) - unbound pointer
*/

/*
Skipped properties needing manual binding:
  line 131: body (Ogre::Entity*) - unbound pointer
  line 132: node (Ogre::SceneNode*) - unbound pointer
  line 133: skeleton (Ogre::OldSkeletonInstance*) - unbound pointer
  line 249: layer (lektor<AnimationClassBase::AnimationLayer*>) - AnimationLayer is unbound; the destructor deletes each layer
*/

int AnimationClassBaseBinding::gc(lua_State* L)
{
    // Borrowed from the owning Character
    return 0;
}

int AnimationClassBaseBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AnimationClassBase object");
    return 1;
}

void AnimationClassBaseBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AnimationClassBaseBinding::gc },
        { "__tostring", AnimationClassBaseBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setVisible", AnimationClassBaseBinding::setVisible },
        { "getVisible", AnimationClassBaseBinding::getVisible },
        { "stopAllAnimation", AnimationClassBaseBinding::stopAllAnimation },
        { "clearAllAnimationUT", AnimationClassBaseBinding::clearAllAnimationUT },
        { "getBoneWorldOrientation", AnimationClassBaseBinding::getBoneWorldOrientation },
        { "getBoneWorldPosition", AnimationClassBaseBinding::getBoneWorldPosition },
        { "getHasBone", AnimationClassBaseBinding::getHasBone },
        { "hasAnimation", AnimationClassBaseBinding::hasAnimation },
        { "getSceneNodePosition", AnimationClassBaseBinding::getSceneNodePosition },
        { "getSceneNodeOrientation", AnimationClassBaseBinding::getSceneNodeOrientation },
        { "getBoneLocalOrientation", AnimationClassBaseBinding::getBoneLocalOrientation },
        { "getBoneLocalPosition", AnimationClassBaseBinding::getBoneLocalPosition },
        { "getRootBoneWorldPosition", AnimationClassBaseBinding::getRootBoneWorldPosition },
        { "getRootBoneLocalPosition", AnimationClassBaseBinding::getRootBoneLocalPosition },
        { "getBoneInitialLocalPosition", AnimationClassBaseBinding::getBoneInitialLocalPosition },
        { "getBoneInitialLocalOrientation", AnimationClassBaseBinding::getBoneInitialLocalOrientation },
        { "getBoneInitialWorldPosition", AnimationClassBaseBinding::getBoneInitialWorldPosition },
        { "getBoneInitialWorldOrientation", AnimationClassBaseBinding::getBoneInitialWorldOrientation },
        { "resetOrientation", AnimationClassBaseBinding::resetOrientation },
        { "getAnimationProgress", AnimationClassBaseBinding::getAnimationProgress },
        { "getOrientation", AnimationClassBaseBinding::getOrientation },
        { "setVerticalPosition", AnimationClassBaseBinding::setVerticalPosition },
        { "getAudioObject", AnimationClassBaseBinding::getAudioObject },
        { "getCharacter", AnimationClassBaseBinding::getCharacter },
        { "_NV_getCharacter", AnimationClassBaseBinding::_NV_getCharacter },
        { "setMasterTimeSpeed", AnimationClassBaseBinding::setMasterTimeSpeed },
        { "getMasterTimeSpeed", AnimationClassBaseBinding::getMasterTimeSpeed },
        { "getMasterTime", AnimationClassBaseBinding::getMasterTime },
        { "isVisibleEntity", AnimationClassBaseBinding::isVisibleEntity },
        { "initBoneInitialWorldPositions", AnimationClassBaseBinding::initBoneInitialWorldPositions },
        { "isAnimationPlaying", AnimationClassBaseBinding::isAnimationPlaying },
        { "getTotalActionAnimationWeight", AnimationClassBaseBinding::getTotalActionAnimationWeight },
        { "stillPlayingAnActionOrSomething", AnimationClassBaseBinding::stillPlayingAnActionOrSomething },
        { 0, 0 }
    };

    registerClass(
        L,
        AnimationClassBaseBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AnimationClassBaseBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "zeroOutTheBlending", AnimationClassBase_get_zeroOutTheBlending);
    registerGetter(L, "boneInitialWorldPositions", AnimationClassBase_get_boneInitialWorldPositions);
    registerGetter(L, "boneInitialWorldOrientations", AnimationClassBase_get_boneInitialWorldOrientations);
    registerGetter(L, "desiredOrientation", AnimationClassBase_get_desiredOrientation);
    registerGetter(L, "isActivated", AnimationClassBase_get_isActivated);
    registerGetter(L, "activateFlag", AnimationClassBase_get_activateFlag);
    registerGetter(L, "lastAnimRelocation", AnimationClassBase_get_lastAnimRelocation);
    registerGetter(L, "rootBonePosition", AnimationClassBase_get_rootBonePosition);
    registerGetter(L, "isVisible", AnimationClassBase_get_isVisible);
    registerGetter(L, "isIdle", AnimationClassBase_get_isIdle);
    registerGetter(L, "movement", AnimationClassBase_get_movement);
    registerGetter(L, "masterTime", AnimationClassBase_get_masterTime);
    registerGetter(L, "masterSpeed", AnimationClassBase_get_masterSpeed);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "zeroOutTheBlending", AnimationClassBase_set_zeroOutTheBlending);
    registerSetter(L, "boneInitialWorldPositions", AnimationClassBase_set_boneInitialWorldPositions);
    registerSetter(L, "boneInitialWorldOrientations", AnimationClassBase_set_boneInitialWorldOrientations);
    registerSetter(L, "desiredOrientation", AnimationClassBase_set_desiredOrientation);
    registerSetter(L, "isActivated", AnimationClassBase_set_isActivated);
    registerSetter(L, "activateFlag", AnimationClassBase_set_activateFlag);
    registerSetter(L, "lastAnimRelocation", AnimationClassBase_set_lastAnimRelocation);
    registerSetter(L, "rootBonePosition", AnimationClassBase_set_rootBonePosition);
    registerSetter(L, "isVisible", AnimationClassBase_set_isVisible);
    registerSetter(L, "isIdle", AnimationClassBase_set_isIdle);
    registerSetter(L, "movement", AnimationClassBase_set_movement);
    registerSetter(L, "masterTime", AnimationClassBase_set_masterTime);
    registerSetter(L, "masterSpeed", AnimationClassBase_set_masterSpeed);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
