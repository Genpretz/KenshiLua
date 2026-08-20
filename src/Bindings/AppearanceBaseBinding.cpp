#include "pch.h"
#include "kenshi\Appearance.h"
#include "AppearanceBaseBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataCopyStandaloneBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/Util/OgreFastArrayBinding.h"

namespace KenshiLua
{
typedef OgreFastArrayPtrBinding<Harpoon*> HarpoonFastArrayBinding;
typedef OgreFastArrayPtrBinding<AttachedEffect*> AttachedEffectFastArrayBinding;
typedef OgreFastArrayPtrBinding<Wound*> WoundFastArrayBinding;

static AppearanceBase* getInstance(lua_State* L, int idx)
{
    return checkObject<AppearanceBase>(L, idx, AppearanceBaseBinding::getMetatableName());
}

// --- Getters for AppearanceBase ---
static int AppearanceBase_get_slots(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    lua_pushlightuserdata(L, (void*)instance->slots);
    return 1;
}

static int AppearanceBase_get_msgClearHarpoons(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    lua_pushboolean(L, instance->msgClearHarpoons ? 1 : 0);
    return 1;
}

static int AppearanceBase_get_woundsListMutex(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    lua_pushlightuserdata(L, (void*)&instance->woundsListMutex);
    return 1;
}

static int AppearanceBase_get_body(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    lua_pushlightuserdata(L, (void*)instance->body);
    return 1;
}

static int AppearanceBase_get_bodyLoader(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    lua_pushlightuserdata(L, (void*)instance->bodyLoader);
    return 1;
}

static int AppearanceBase_get_isCreatingBody(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    lua_pushboolean(L, instance->isCreatingBody ? 1 : 0);
    return 1;
}

static int AppearanceBase_get_bodyRadius(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    lua_pushnumber(L, instance->bodyRadius);
    return 1;
}

static int AppearanceBase_get_me(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    return pushObject<Character>(L, instance->me, CharacterBinding::getMetatableName());
}

static int AppearanceBase_get_visible(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    lua_pushboolean(L, instance->visible ? 1 : 0);
    return 1;
}

static int AppearanceBase_get_bodyFilename(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    lua_pushstring(L, instance->bodyFilename.c_str());
    return 1;
}

static int AppearanceBase_get_animation(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    lua_pushlightuserdata(L, (void*)instance->animation);
    return 1;
}

static int AppearanceBase_get_female(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    lua_pushboolean(L, instance->female ? 1 : 0);
    return 1;
}

static int AppearanceBase_get_updatedAttachments(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    lua_pushboolean(L, instance->updatedAttachments ? 1 : 0);
    return 1;
}

static int AppearanceBase_get_updatedAppearanceData(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    lua_pushboolean(L, instance->updatedAppearanceData ? 1 : 0);
    return 1;
}

static int AppearanceBase_get_updateBody(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    lua_pushboolean(L, instance->updateBody ? 1 : 0);
    return 1;
}

static int AppearanceBase_get_suid(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    lua_pushinteger(L, instance->suid);
    return 1;
}

static int AppearanceBase_get_appearanceData(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    return pushObject<GameDataCopyStandalone>(L, instance->appearanceData, GameDataCopyStandaloneBinding::getMetatableName());
}

static int AppearanceBase_get_raceData(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    return pushObject<GameData>(L, instance->raceData, GameDataBinding::getMetatableName());
}

static int AppearanceBase_get_factionColor(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    return pushObject<GameData>(L, instance->factionColor, GameDataBinding::getMetatableName());
}

static int AppearanceBase_get_hairStyle(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    return pushObject<GameData>(L, instance->hairStyle, GameDataBinding::getMetatableName());
}

static int AppearanceBase_get_shaved(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    lua_pushboolean(L, instance->shaved ? 1 : 0);
    return 1;
}

static int AppearanceBase_get_waterLineFadeTimer(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    lua_pushnumber(L, instance->waterLineFadeTimer);
    return 1;
}

static int AppearanceBase_get_barefoot(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    lua_pushboolean(L, instance->barefoot ? 1 : 0);
    return 1;
}

static int AppearanceBase_get_hideAttachments(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    lua_pushboolean(L, instance->hideAttachments ? 1 : 0);
    return 1;
}

static int AppearanceBase_get_characterHeight(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    lua_pushnumber(L, instance->characterHeight);
    return 1;
}

static int AppearanceBase_get_characterHeightSpeedMultiplier(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    lua_pushnumber(L, instance->characterHeightSpeedMultiplier);
    return 1;
}

static int AppearanceBase_get_characterHeight_0to1(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    lua_pushnumber(L, instance->characterHeight_0to1);
    return 1;
}

static int AppearanceBase_get_waterline(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    pushVector4(L, instance->waterline);
    return 1;
}

static int AppearanceBase_get_attachedHarpoons(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    return pushObject<HarpoonFastArrayBinding::ArrayType>(L, &instance->attachedHarpoons, "Ogre::FastArray<Harpoon*>");
}

static int AppearanceBase_get_attachedEffects(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    return pushObject<AttachedEffectFastArrayBinding::ArrayType>(L, &instance->attachedEffects, "Ogre::FastArray<AttachedEffect*>");
}

static int AppearanceBase_get_attachedEffectsToRemove(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    return pushObject<AttachedEffectFastArrayBinding::ArrayType>(L, &instance->attachedEffectsToRemove, "Ogre::FastArray<AttachedEffect*>");
}

static int AppearanceBase_get_woundsList(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    return pushObject<WoundFastArrayBinding::ArrayType>(L, &instance->woundsList, "Ogre::FastArray<Wound*>");
}

// --- Setters for AppearanceBase ---
static int AppearanceBase_set_attachedHarpoons(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    if (lua_isnoneornil(L, 2))
    {
        instance->attachedHarpoons.clear();
        return 0;
    }
    auto* src = HarpoonFastArrayBinding::get(L, 2);
    if (!src) return luaL_error(L, "Argument 2 to set attachedHarpoons must be Ogre::FastArray<Harpoon*>");
    instance->attachedHarpoons = *src;
    return 0;
}

static int AppearanceBase_set_attachedEffects(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    if (lua_isnoneornil(L, 2))
    {
        instance->attachedEffects.clear();
        return 0;
    }
    auto* src = AttachedEffectFastArrayBinding::get(L, 2);
    if (!src) return luaL_error(L, "Argument 2 to set attachedEffects must be Ogre::FastArray<AttachedEffect*>");
    instance->attachedEffects = *src;
    return 0;
}

static int AppearanceBase_set_attachedEffectsToRemove(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    if (lua_isnoneornil(L, 2))
    {
        instance->attachedEffectsToRemove.clear();
        return 0;
    }
    auto* src = AttachedEffectFastArrayBinding::get(L, 2);
    if (!src) return luaL_error(L, "Argument 2 to set attachedEffectsToRemove must be Ogre::FastArray<AttachedEffect*>");
    instance->attachedEffectsToRemove = *src;
    return 0;
}

static int AppearanceBase_set_woundsList(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    if (lua_isnoneornil(L, 2))
    {
        instance->woundsList.clear();
        return 0;
    }
    auto* src = WoundFastArrayBinding::get(L, 2);
    if (!src) return luaL_error(L, "Argument 2 to set woundsList must be Ogre::FastArray<Wound*>");
    instance->woundsList = *src;
    return 0;
}

static int AppearanceBase_set_msgClearHarpoons(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    instance->msgClearHarpoons = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AppearanceBase_set_woundsListMutex(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    return luaL_error(L, "woundsListMutex is read-only");
}

static int AppearanceBase_set_isCreatingBody(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    instance->isCreatingBody = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AppearanceBase_set_bodyRadius(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    instance->bodyRadius = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AppearanceBase_set_me(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    instance->me = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int AppearanceBase_set_visible(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    instance->visible = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AppearanceBase_set_bodyFilename(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    instance->bodyFilename = luaL_checkstring(L, 2);
    return 0;
}

static int AppearanceBase_set_female(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    instance->female = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AppearanceBase_set_updatedAttachments(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    instance->updatedAttachments = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AppearanceBase_set_updatedAppearanceData(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    instance->updatedAppearanceData = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AppearanceBase_set_updateBody(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    instance->updateBody = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AppearanceBase_set_suid(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    instance->suid = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int AppearanceBase_set_appearanceData(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    instance->appearanceData = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameDataCopyStandalone>(L, 2, GameDataCopyStandaloneBinding::getMetatableName());
    return 0;
}

static int AppearanceBase_set_raceData(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    instance->raceData = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int AppearanceBase_set_factionColor(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    instance->factionColor = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int AppearanceBase_set_hairStyle(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    instance->hairStyle = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int AppearanceBase_set_shaved(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    instance->shaved = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AppearanceBase_set_waterLineFadeTimer(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    instance->waterLineFadeTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AppearanceBase_set_barefoot(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    instance->barefoot = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AppearanceBase_set_hideAttachments(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    instance->hideAttachments = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AppearanceBase_set_characterHeight(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    instance->characterHeight = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AppearanceBase_set_characterHeightSpeedMultiplier(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    instance->characterHeightSpeedMultiplier = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AppearanceBase_set_characterHeight_0to1(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    instance->characterHeight_0to1 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AppearanceBase_set_waterline(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");
    readVector4(L, 2, instance->waterline);
    return 0;
}

int AppearanceBaseBinding::updateAnimationTransforms(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    instance->updateAnimationTransforms();
    return 0;
}

int AppearanceBaseBinding::forceUpdateAnimationTransforms(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    instance->forceUpdateAnimationTransforms();
    return 0;
}

int AppearanceBaseBinding::update(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    instance->update();
    return 0;
}

int AppearanceBaseBinding::_NV_update(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    instance->_NV_update();
    return 0;
}

int AppearanceBaseBinding::periodicUpdate(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    instance->periodicUpdate();
    return 0;
}

int AppearanceBaseBinding::_NV_periodicUpdate(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    instance->_NV_periodicUpdate();
    return 0;
}

int AppearanceBaseBinding::setAppearanceData(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    GameDataCopyStandalone* data = checkObject<GameDataCopyStandalone>(L, 2, GameDataCopyStandaloneBinding::getMetatableName());
    instance->setAppearanceData(data);
    return 0;
}

int AppearanceBaseBinding::getAppearanceData(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    GameDataCopyStandalone* result = instance->getAppearanceData();
    return pushObject<GameDataCopyStandalone>(L, result, GameDataCopyStandaloneBinding::getMetatableName());
}

int AppearanceBaseBinding::activate(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    instance->activate();
    return 0;
}

int AppearanceBaseBinding::_NV_activate(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    instance->_NV_activate();
    return 0;
}

int AppearanceBaseBinding::deactivate(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    instance->deactivate();
    return 0;
}

int AppearanceBaseBinding::_NV_deactivate(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    instance->_NV_deactivate();
    return 0;
}

int AppearanceBaseBinding::isFemale(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    bool result = instance->isFemale();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::setGender(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    bool _female = lua_toboolean(L, 2) != 0;
    instance->setGender(_female);
    return 0;
}

int AppearanceBaseBinding::_NV_setGender(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    bool _female = lua_toboolean(L, 2) != 0;
    instance->_NV_setGender(_female);
    return 0;
}

int AppearanceBaseBinding::getRace(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    GameData* result = instance->getRace();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int AppearanceBaseBinding::attachEffect(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    const std::string boneName = luaL_checkstring(L, 3);
    Ogre::Vector3 offsetPosition;
    readVector3(L, 4, offsetPosition);
    Ogre::Quaternion offsetOrientation;
    readQuaternion(L, 5, offsetOrientation);
    bool manual = lua_toboolean(L, 6) != 0;
    float baseEmission = (float)luaL_checknumber(L, 7);
    AttachedEffect* result = instance->attachEffect(data, boneName, offsetPosition, offsetOrientation, manual, baseEmission);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int AppearanceBaseBinding::getAttachedEntity(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    const std::string slot = luaL_checkstring(L, 2);
    AttachedEntity* result = instance->getAttachedEntity(slot);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int AppearanceBaseBinding::detachAllHarpoonsT(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    instance->detachAllHarpoonsT();
    return 0;
}

int AppearanceBaseBinding::_detachAllHarpoons(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    instance->_detachAllHarpoons();
    return 0;
}

int AppearanceBaseBinding::updateWetness(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    bool force = lua_toboolean(L, 2) != 0;
    instance->updateWetness(force);
    return 0;
}

int AppearanceBaseBinding::updateBloodyness(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    instance->updateBloodyness();
    return 0;
}

int AppearanceBaseBinding::getAttachmentPosition(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    const std::string slot = luaL_checkstring(L, 2);
    Ogre::Vector3 pos;
    readVector3(L, 3, pos);
    Ogre::Quaternion rot;
    readQuaternion(L, 4, rot);
    bool result = instance->getAttachmentPosition(slot, pos, rot);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::hasSlot(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    const std::string slot = luaL_checkstring(L, 2);
    bool result = instance->hasSlot(slot);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::getNormalisedCharacterHeight(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    float result = instance->getNormalisedCharacterHeight();
    lua_pushnumber(L, result);
    return 1;
}

int AppearanceBaseBinding::getCharacterHeight(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    float result = instance->getCharacterHeight();
    lua_pushnumber(L, result);
    return 1;
}

int AppearanceBaseBinding::getAnimationSystem(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    AnimationClass* result = instance->getAnimationSystem();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int AppearanceBaseBinding::getSceneNode(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    Ogre::SceneNode* result = instance->getSceneNode();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int AppearanceBaseBinding::getSkeleton(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    Ogre::OldSkeletonInstance* result = instance->getSkeleton();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int AppearanceBaseBinding::getBody(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    Ogre::Entity* result = instance->getBody();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int AppearanceBaseBinding::getBodyRadius(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    float result = instance->getBodyRadius();
    lua_pushnumber(L, result);
    return 1;
}

int AppearanceBaseBinding::failedToLoad(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    bool result = instance->failedToLoad();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::getBonePosition(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    const std::string boneName = luaL_checkstring(L, 2);
    Ogre::Vector3 result = instance->getBonePosition(boneName);
    pushVector3(L, result);
    return 1;
}

int AppearanceBaseBinding::getBoneOrientation(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    const std::string boneName = luaL_checkstring(L, 2);
    Ogre::Quaternion result = instance->getBoneOrientation(boneName);
    pushQuaternion(L, result);
    return 1;
}

int AppearanceBaseBinding::getVertexWorldPosition(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    const std::string boneName = luaL_checkstring(L, 2);
    const int vertex = (int)luaL_checkinteger(L, 3);
    Ogre::Vector3 result = instance->getVertexWorldPosition(boneName, vertex);
    pushVector3(L, result);
    return 1;
}

int AppearanceBaseBinding::getRandomVertex(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    const std::string boneName = luaL_checkstring(L, 2);
    MeshDataLookup::Dir direction = (MeshDataLookup::Dir)luaL_checkinteger(L, 3);
    int result = instance->getRandomVertex(boneName, direction);
    lua_pushinteger(L, result);
    return 1;
}

int AppearanceBaseBinding::notifyDirty(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    instance->notifyDirty();
    return 0;
}

int AppearanceBaseBinding::reload(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    instance->reload();
    return 0;
}

int AppearanceBaseBinding::serialise(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->serialise(state);
    return 0;
}

int AppearanceBaseBinding::updateAppearance(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    instance->updateAppearance();
    return 0;
}

int AppearanceBaseBinding::_NV_updateAppearance(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    instance->_NV_updateAppearance();
    return 0;
}

int AppearanceBaseBinding::updatePortrait(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    instance->updatePortrait();
    return 0;
}

int AppearanceBaseBinding::updateMovementScale(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    instance->updateMovementScale();
    return 0;
}

int AppearanceBaseBinding::switchLights(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->switchLights(on);
    return 0;
}

int AppearanceBaseBinding::hasLights(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    bool result = instance->hasLights();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::attachItem_Hair(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    const std::string slot = luaL_checkstring(L, 3);
    bool result = instance->attachItem_Hair(data, slot);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::shaveHead(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->shaveHead(on);
    return 0;
}

int AppearanceBaseBinding::isShaved(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    bool result = instance->isShaved();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::setFlayed(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setFlayed(on);
    return 0;
}

int AppearanceBaseBinding::_NV_setFlayed(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_setFlayed(on);
    return 0;
}

int AppearanceBaseBinding::isFlayed(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    bool result = instance->isFlayed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::_NV_isFlayed(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    bool result = instance->_NV_isFlayed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::isBarefoot(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    bool result = instance->isBarefoot();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::_NV_isBarefoot(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    bool result = instance->_NV_isBarefoot();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::setVisible(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->setVisible(value);
    return 0;
}

int AppearanceBaseBinding::getVisible(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    bool result = instance->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::getAttachmentsLoaded(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    bool result = instance->getAttachmentsLoaded();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::setAttachmentsVisible(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->setAttachmentsVisible(visible);
    return 0;
}

int AppearanceBaseBinding::_NV_setAttachmentsVisible(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->_NV_setAttachmentsVisible(visible);
    return 0;
}

int AppearanceBaseBinding::createBody(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    instance->createBody();
    return 0;
}

int AppearanceBaseBinding::buildAttachments(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    instance->buildAttachments();
    return 0;
}

int AppearanceBaseBinding::setHairTexture(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    const std::string name = luaL_checkstring(L, 2);
    int channel = (int)luaL_checkinteger(L, 3);
    int alpha = (int)luaL_checkinteger(L, 4);
    Ogre::Vector3 colour;
    readVector3(L, 5, colour);
    bool beard = lua_toboolean(L, 6) != 0;
    instance->setHairTexture(name, channel, alpha, colour, beard);
    return 0;
}

int AppearanceBaseBinding::createAttachedObject(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    AttachedEntity* result = instance->createAttachedObject(item);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int AppearanceBaseBinding::updateOverlap(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    instance->updateOverlap();
    return 0;
}

int AppearanceBaseBinding::updateCharaterTexture(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    instance->updateCharaterTexture();
    return 0;
}

int AppearanceBaseBinding::getCharacterHeightSpeedMultiplier(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    float result = instance->getCharacterHeightSpeedMultiplier();
    lua_pushnumber(L, result);
    return 1;
}

int AppearanceBaseBinding::attachItem(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    if (!item) return luaL_error(L, "Argument 2 to attachItem must be an Item");

    if (lua_isstring(L, 4))
    {
        std::string mesh = luaL_checkstring(L, 3);
        std::string slot = luaL_checkstring(L, 4);
        bool result = instance->attachItem(item, mesh, slot);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }
    else
    {
        std::string slot = lua_isstring(L, 3) ? lua_tostring(L, 3) : "";
        bool result = instance->attachItem(item, slot);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }
}

int AppearanceBaseBinding::detachItem(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    if (Item* item = testObject<Item>(L, 2, ItemBinding::getMetatableName()))
    {
        bool result = instance->detachItem(item);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }
    else if (lua_isstring(L, 2))
    {
        std::string slot = lua_tostring(L, 2);
        bool result = instance->detachItem(slot);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }
    return luaL_error(L, "Argument 2 to detachItem must be an Item or slot string");
}

int AppearanceBaseBinding::getVertexPosition(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    int index = (int)luaL_checkinteger(L, 2);
    pushVector3(L, instance->getVertexPosition(index));
    return 1;
}

int AppearanceBaseBinding::getRandomVertexPosition(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    std::string boneName = luaL_checkstring(L, 2);
    MeshDataLookup::Dir direction = (MeshDataLookup::Dir)luaL_checkinteger(L, 3);
    pushVector3(L, instance->getRandomVertexPosition(boneName, direction));
    return 1;
}

int AppearanceBaseBinding::chooseBodyMesh(lua_State* L)
{
    AppearanceBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceBase is nil");

    const std::string& result = instance->chooseBodyMesh();
    lua_pushlstring(L, result.c_str(), result.size());
    return 1;
}

/*
Skipped methods needing manual binding:
  line 92: void addWound(...) - unsupported arg type
  line 93: void removeWound(...) - unsupported arg type
  line 96: bool attachHarpoon(...) - unsupported arg type
  line 101: bool detachHarpoon(...) - unsupported arg type
  line 104: void removeEffect(...) - unsupported arg type
  line 132: void getLights(...) - unsupported arg type
  line 148: void buildBody(...) - unsupported arg type
  line 150: void createEntity(...) - unsupported arg type
  line 151: void createPhysicsAttachment(...) - unsupported arg type
  line 152: void createEntityCallback(...) - unsupported arg type
  line 153: void attachEntity(...) - unsupported arg type
  line 154: bool getSlotPosition(...) - unsupported arg type
  line 155: void setupItemMaterial(...) - unsupported arg type
  line 156: void setupHairMaterial(...) - unsupported arg type
  line 158: void setupCharacterEntityTexture(...) - unsupported arg type
  line 159: void _NV_setupCharacterEntityTexture(...) - unsupported arg type
  line 161: bool affectsPortrait(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - AppearanceBase_get_slots: const boost::unordered::unordered_map<std::string, AttachmentData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, AttachmentData*>, Ogre::GeneralAllocPolicy > >* (unbound pointer)
  - AppearanceBase_get_body: Ogre::Entity* (unbound pointer)
  - AppearanceBase_get_bodyLoader: Ogre::Entity* (unbound pointer)
  - AppearanceBase_get_animation: AnimationClass* (unbound pointer)
  - AppearanceBaseBinding::attachEffect: AttachedEffect* (unbound pointer)
  - AppearanceBaseBinding::getAttachedEntity: AttachedEntity* (unbound pointer)
  - AppearanceBaseBinding::getAnimationSystem: AnimationClass* (unbound pointer)
  - AppearanceBaseBinding::getSceneNode: Ogre::SceneNode* (unbound pointer)
  - AppearanceBaseBinding::getSkeleton: Ogre::OldSkeletonInstance* (unbound pointer)
  - AppearanceBaseBinding::getBody: Ogre::Entity* (unbound pointer)
  - AppearanceBaseBinding::createAttachedObject: AttachedEntity* (unbound pointer)
  - HarpoonFastArrayBinding: Harpoon* (unbound pointer element)
  - AttachedEffectFastArrayBinding: AttachedEffect* (unbound pointer element)
  - WoundFastArrayBinding: Wound* (unbound pointer element)
*/

/*
Skipped properties needing manual binding:
  line 63: attachedObjects (boost::unordered::unordered_map<std::string, AttachedEntity*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, AttachedEntity*>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 172: bodyMaterial (Ogre::SharedPtr<Ogre::Material>) - unsupported type
*/

int AppearanceBaseBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int AppearanceBaseBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AppearanceBase object");
    return 1;
}

void AppearanceBaseBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AppearanceBaseBinding::gc },
        { "__tostring", AppearanceBaseBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "updateAnimationTransforms", AppearanceBaseBinding::updateAnimationTransforms },
        { "forceUpdateAnimationTransforms", AppearanceBaseBinding::forceUpdateAnimationTransforms },
        { "update", AppearanceBaseBinding::update },
        { "_NV_update", AppearanceBaseBinding::_NV_update },
        { "periodicUpdate", AppearanceBaseBinding::periodicUpdate },
        { "_NV_periodicUpdate", AppearanceBaseBinding::_NV_periodicUpdate },
        { "setAppearanceData", AppearanceBaseBinding::setAppearanceData },
        { "getAppearanceData", AppearanceBaseBinding::getAppearanceData },
        { "activate", AppearanceBaseBinding::activate },
        { "_NV_activate", AppearanceBaseBinding::_NV_activate },
        { "deactivate", AppearanceBaseBinding::deactivate },
        { "_NV_deactivate", AppearanceBaseBinding::_NV_deactivate },
        { "isFemale", AppearanceBaseBinding::isFemale },
        { "setGender", AppearanceBaseBinding::setGender },
        { "_NV_setGender", AppearanceBaseBinding::_NV_setGender },
        { "getRace", AppearanceBaseBinding::getRace },
        { "attachEffect", AppearanceBaseBinding::attachEffect },
        { "getAttachedEntity", AppearanceBaseBinding::getAttachedEntity },
        { "detachAllHarpoonsT", AppearanceBaseBinding::detachAllHarpoonsT },
        { "_detachAllHarpoons", AppearanceBaseBinding::_detachAllHarpoons },
        { "updateWetness", AppearanceBaseBinding::updateWetness },
        { "updateBloodyness", AppearanceBaseBinding::updateBloodyness },
        { "getAttachmentPosition", AppearanceBaseBinding::getAttachmentPosition },
        { "hasSlot", AppearanceBaseBinding::hasSlot },
        { "getNormalisedCharacterHeight", AppearanceBaseBinding::getNormalisedCharacterHeight },
        { "getCharacterHeight", AppearanceBaseBinding::getCharacterHeight },
        { "getAnimationSystem", AppearanceBaseBinding::getAnimationSystem },
        { "getSceneNode", AppearanceBaseBinding::getSceneNode },
        { "getSkeleton", AppearanceBaseBinding::getSkeleton },
        { "getBody", AppearanceBaseBinding::getBody },
        { "getBodyRadius", AppearanceBaseBinding::getBodyRadius },
        { "failedToLoad", AppearanceBaseBinding::failedToLoad },
        { "getBonePosition", AppearanceBaseBinding::getBonePosition },
        { "getBoneOrientation", AppearanceBaseBinding::getBoneOrientation },
        { "getVertexWorldPosition", AppearanceBaseBinding::getVertexWorldPosition },
        { "getRandomVertex", AppearanceBaseBinding::getRandomVertex },
        { "notifyDirty", AppearanceBaseBinding::notifyDirty },
        { "reload", AppearanceBaseBinding::reload },
        { "serialise", AppearanceBaseBinding::serialise },
        { "updateAppearance", AppearanceBaseBinding::updateAppearance },
        { "_NV_updateAppearance", AppearanceBaseBinding::_NV_updateAppearance },
        { "updatePortrait", AppearanceBaseBinding::updatePortrait },
        { "updateMovementScale", AppearanceBaseBinding::updateMovementScale },
        { "switchLights", AppearanceBaseBinding::switchLights },
        { "hasLights", AppearanceBaseBinding::hasLights },
        { "attachItem_Hair", AppearanceBaseBinding::attachItem_Hair },
        { "shaveHead", AppearanceBaseBinding::shaveHead },
        { "isShaved", AppearanceBaseBinding::isShaved },
        { "setFlayed", AppearanceBaseBinding::setFlayed },
        { "_NV_setFlayed", AppearanceBaseBinding::_NV_setFlayed },
        { "isFlayed", AppearanceBaseBinding::isFlayed },
        { "_NV_isFlayed", AppearanceBaseBinding::_NV_isFlayed },
        { "isBarefoot", AppearanceBaseBinding::isBarefoot },
        { "_NV_isBarefoot", AppearanceBaseBinding::_NV_isBarefoot },
        { "setVisible", AppearanceBaseBinding::setVisible },
        { "getVisible", AppearanceBaseBinding::getVisible },
        { "getAttachmentsLoaded", AppearanceBaseBinding::getAttachmentsLoaded },
        { "setAttachmentsVisible", AppearanceBaseBinding::setAttachmentsVisible },
        { "_NV_setAttachmentsVisible", AppearanceBaseBinding::_NV_setAttachmentsVisible },
        { "createBody", AppearanceBaseBinding::createBody },
        { "buildAttachments", AppearanceBaseBinding::buildAttachments },
        { "setHairTexture", AppearanceBaseBinding::setHairTexture },
        { "createAttachedObject", AppearanceBaseBinding::createAttachedObject },
        { "updateOverlap", AppearanceBaseBinding::updateOverlap },
        { "updateCharaterTexture", AppearanceBaseBinding::updateCharaterTexture },
        { "getCharacterHeightSpeedMultiplier", AppearanceBaseBinding::getCharacterHeightSpeedMultiplier },
        { "attachItem", AppearanceBaseBinding::attachItem },
        { "detachItem", AppearanceBaseBinding::detachItem },
        { "getVertexPosition", AppearanceBaseBinding::getVertexPosition },
        { "getRandomVertexPosition", AppearanceBaseBinding::getRandomVertexPosition },
        { "chooseBodyMesh", AppearanceBaseBinding::chooseBodyMesh },
        { 0, 0 }
    };

    registerClass(
        L, 
        AppearanceBaseBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AppearanceBaseBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "slots", AppearanceBase_get_slots);
    registerGetter(L, "msgClearHarpoons", AppearanceBase_get_msgClearHarpoons);
    registerGetter(L, "woundsListMutex", AppearanceBase_get_woundsListMutex);
    registerGetter(L, "body", AppearanceBase_get_body);
    registerGetter(L, "bodyLoader", AppearanceBase_get_bodyLoader);
    registerGetter(L, "isCreatingBody", AppearanceBase_get_isCreatingBody);
    registerGetter(L, "bodyRadius", AppearanceBase_get_bodyRadius);
    registerGetter(L, "me", AppearanceBase_get_me);
    registerGetter(L, "visible", AppearanceBase_get_visible);
    registerGetter(L, "bodyFilename", AppearanceBase_get_bodyFilename);
    registerGetter(L, "animation", AppearanceBase_get_animation);
    registerGetter(L, "female", AppearanceBase_get_female);
    registerGetter(L, "updatedAttachments", AppearanceBase_get_updatedAttachments);
    registerGetter(L, "updatedAppearanceData", AppearanceBase_get_updatedAppearanceData);
    registerGetter(L, "updateBody", AppearanceBase_get_updateBody);
    registerGetter(L, "suid", AppearanceBase_get_suid);
    registerGetter(L, "appearanceData", AppearanceBase_get_appearanceData);
    registerGetter(L, "raceData", AppearanceBase_get_raceData);
    registerGetter(L, "factionColor", AppearanceBase_get_factionColor);
    registerGetter(L, "hairStyle", AppearanceBase_get_hairStyle);
    registerGetter(L, "shaved", AppearanceBase_get_shaved);
    registerGetter(L, "waterLineFadeTimer", AppearanceBase_get_waterLineFadeTimer);
    registerGetter(L, "waterline", AppearanceBase_get_waterline);
    registerGetter(L, "barefoot", AppearanceBase_get_barefoot);
    registerGetter(L, "hideAttachments", AppearanceBase_get_hideAttachments);
    registerGetter(L, "characterHeight", AppearanceBase_get_characterHeight);
    registerGetter(L, "characterHeightSpeedMultiplier", AppearanceBase_get_characterHeightSpeedMultiplier);
    registerGetter(L, "characterHeight_0to1", AppearanceBase_get_characterHeight_0to1);
    registerGetter(L, "attachedHarpoons", AppearanceBase_get_attachedHarpoons);
    registerGetter(L, "attachedEffects", AppearanceBase_get_attachedEffects);
    registerGetter(L, "attachedEffectsToRemove", AppearanceBase_get_attachedEffectsToRemove);
    registerGetter(L, "woundsList", AppearanceBase_get_woundsList);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "msgClearHarpoons", AppearanceBase_set_msgClearHarpoons);
    registerSetter(L, "woundsListMutex", AppearanceBase_set_woundsListMutex);
    registerSetter(L, "isCreatingBody", AppearanceBase_set_isCreatingBody);
    registerSetter(L, "bodyRadius", AppearanceBase_set_bodyRadius);
    registerSetter(L, "me", AppearanceBase_set_me);
    registerSetter(L, "visible", AppearanceBase_set_visible);
    registerSetter(L, "bodyFilename", AppearanceBase_set_bodyFilename);
    registerSetter(L, "female", AppearanceBase_set_female);
    registerSetter(L, "updatedAttachments", AppearanceBase_set_updatedAttachments);
    registerSetter(L, "updatedAppearanceData", AppearanceBase_set_updatedAppearanceData);
    registerSetter(L, "updateBody", AppearanceBase_set_updateBody);
    registerSetter(L, "suid", AppearanceBase_set_suid);
    registerSetter(L, "appearanceData", AppearanceBase_set_appearanceData);
    registerSetter(L, "raceData", AppearanceBase_set_raceData);
    registerSetter(L, "factionColor", AppearanceBase_set_factionColor);
    registerSetter(L, "hairStyle", AppearanceBase_set_hairStyle);
    registerSetter(L, "shaved", AppearanceBase_set_shaved);
    registerSetter(L, "waterLineFadeTimer", AppearanceBase_set_waterLineFadeTimer);
    registerSetter(L, "waterline", AppearanceBase_set_waterline);
    registerSetter(L, "barefoot", AppearanceBase_set_barefoot);
    registerSetter(L, "hideAttachments", AppearanceBase_set_hideAttachments);
    registerSetter(L, "characterHeight", AppearanceBase_set_characterHeight);
    registerSetter(L, "characterHeightSpeedMultiplier", AppearanceBase_set_characterHeightSpeedMultiplier);
    registerSetter(L, "characterHeight_0to1", AppearanceBase_set_characterHeight_0to1);
    registerSetter(L, "attachedHarpoons", AppearanceBase_set_attachedHarpoons);
    registerSetter(L, "attachedEffects", AppearanceBase_set_attachedEffects);
    registerSetter(L, "attachedEffectsToRemove", AppearanceBase_set_attachedEffectsToRemove);
    registerSetter(L, "woundsList", AppearanceBase_set_woundsList);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    HarpoonFastArrayBinding::registerBinding(L, "Ogre::FastArray<Harpoon*>", nullptr);
    AttachedEffectFastArrayBinding::registerBinding(L, "Ogre::FastArray<AttachedEffect*>", nullptr);
    WoundFastArrayBinding::registerBinding(L, "Ogre::FastArray<Wound*>", nullptr);

    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, AppearanceBaseBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua