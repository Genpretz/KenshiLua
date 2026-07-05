#include "pch.h"
#include "kenshi\Appearance.h"
#include "AppearanceBaseBinding.h"
#include "CharacterBinding.h"
#include "GameDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{

static AppearanceBase* getB(lua_State* L, int idx)
{
    return checkObject<AppearanceBase>(L, idx, AppearanceBaseBinding::getMetatableName());
}

// --- Getters for AppearanceBase ---
static int AppearanceBase_get_slots(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    // TODO: Unsupported type for slots (const boost::unordered::unordered_map<std::string, AttachmentData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, AttachmentData*>, Ogre::GeneralAllocPolicy > >*)
    return luaL_error(L, "Unsupported property 'slots' (type: const boost::unordered::unordered_map<std::string, AttachmentData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, AttachmentData*>, Ogre::GeneralAllocPolicy > >*)");
}

static int AppearanceBase_get_attachedObjects(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    // TODO: Unsupported type for attachedObjects (boost::unordered::unordered_map<std::string, AttachedEntity*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, AttachedEntity*>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'attachedObjects' (type: boost::unordered::unordered_map<std::string, AttachedEntity*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, AttachedEntity*>, Ogre::GeneralAllocPolicy > >)");
}

static int AppearanceBase_get_attachedHarpoons(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    // TODO: Unsupported type for attachedHarpoons (Ogre::FastArray<Harpoon*>)
    return luaL_error(L, "Unsupported property 'attachedHarpoons' (type: Ogre::FastArray<Harpoon*>)");
}

static int AppearanceBase_get_msgClearHarpoons(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    lua_pushboolean(L, b->msgClearHarpoons ? 1 : 0);
    return 1;
}

static int AppearanceBase_get_attachedEffects(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    // TODO: Unsupported type for attachedEffects (Ogre::FastArray<AttachedEffect*>)
    return luaL_error(L, "Unsupported property 'attachedEffects' (type: Ogre::FastArray<AttachedEffect*>)");
}

static int AppearanceBase_get_attachedEffectsToRemove(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    // TODO: Unsupported type for attachedEffectsToRemove (Ogre::FastArray<AttachedEffect*>)
    return luaL_error(L, "Unsupported property 'attachedEffectsToRemove' (type: Ogre::FastArray<AttachedEffect*>)");
}

static int AppearanceBase_get_woundsList(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    // TODO: Unsupported type for woundsList (Ogre::FastArray<Wound*>)
    return luaL_error(L, "Unsupported property 'woundsList' (type: Ogre::FastArray<Wound*>)");
}

static int AppearanceBase_get_woundsListMutex(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    // boost::shared_mutex cannot be returned directly to Lua
    lua_pushnil(L);
    return 1;
}

static int AppearanceBase_get_body(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    // TODO: Unsupported type for body (Ogre::Entity*)
    return luaL_error(L, "Unsupported property 'body' (type: Ogre::Entity*)");
}

static int AppearanceBase_get_bodyLoader(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    // TODO: Unsupported type for bodyLoader (Ogre::Entity*)
    return luaL_error(L, "Unsupported property 'bodyLoader' (type: Ogre::Entity*)");
}

static int AppearanceBase_get_isCreatingBody(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    lua_pushboolean(L, b->isCreatingBody ? 1 : 0);
    return 1;
}

static int AppearanceBase_get_bodyRadius(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    lua_pushnumber(L, b->bodyRadius);
    return 1;
}

static int AppearanceBase_get_me(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    return pushObject<Character>(L, b->me, CharacterBinding::getMetatableName());
}

static int AppearanceBase_get_visible(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    lua_pushboolean(L, b->visible ? 1 : 0);
    return 1;
}

static int AppearanceBase_get_bodyFilename(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    lua_pushstring(L, b->bodyFilename.c_str());
    return 1;
}

static int AppearanceBase_get_bodyMaterial(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    // TODO: Unsupported type for bodyMaterial (Ogre::SharedPtr<Ogre::Material>)
    return luaL_error(L, "Unsupported property 'bodyMaterial' (type: Ogre::SharedPtr<Ogre::Material>)");
}

static int AppearanceBase_get_animation(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    // TODO: Unsupported type for animation (AnimationClass*)
    return luaL_error(L, "Unsupported property 'animation' (type: AnimationClass*)");
}

static int AppearanceBase_get_female(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    lua_pushboolean(L, b->female ? 1 : 0);
    return 1;
}

static int AppearanceBase_get_updatedAttachments(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    lua_pushboolean(L, b->updatedAttachments ? 1 : 0);
    return 1;
}

static int AppearanceBase_get_updatedAppearanceData(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    lua_pushboolean(L, b->updatedAppearanceData ? 1 : 0);
    return 1;
}

static int AppearanceBase_get_updateBody(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    lua_pushboolean(L, b->updateBody ? 1 : 0);
    return 1;
}

static int AppearanceBase_get_suid(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    lua_pushinteger(L, b->suid);
    return 1;
}

static int AppearanceBase_get_appearanceData(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    // TODO: Unsupported type for appearanceData (GameDataCopyStandalone*)
    return luaL_error(L, "Unsupported property 'appearanceData' (type: GameDataCopyStandalone*)");
}

static int AppearanceBase_get_raceData(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    return pushObject<GameData>(L, b->raceData, GameDataBinding::getMetatableName());
}

static int AppearanceBase_get_factionColor(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    return pushObject<GameData>(L, b->factionColor, GameDataBinding::getMetatableName());
}

static int AppearanceBase_get_hairStyle(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    return pushObject<GameData>(L, b->hairStyle, GameDataBinding::getMetatableName());
}

static int AppearanceBase_get_shaved(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    lua_pushboolean(L, b->shaved ? 1 : 0);
    return 1;
}

static int AppearanceBase_get_waterline(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    // TODO: Unsupported type for waterline (Ogre::Vector4)
    return luaL_error(L, "Unsupported property 'waterline' (type: Ogre::Vector4)");
}

static int AppearanceBase_get_waterLineFadeTimer(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    lua_pushnumber(L, b->waterLineFadeTimer);
    return 1;
}

static int AppearanceBase_get_barefoot(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    lua_pushboolean(L, b->barefoot ? 1 : 0);
    return 1;
}

static int AppearanceBase_get_hideAttachments(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    lua_pushboolean(L, b->hideAttachments ? 1 : 0);
    return 1;
}

static int AppearanceBase_get_characterHeight(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    lua_pushnumber(L, b->characterHeight);
    return 1;
}

static int AppearanceBase_get_characterHeightSpeedMultiplier(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    lua_pushnumber(L, b->characterHeightSpeedMultiplier);
    return 1;
}

static int AppearanceBase_get_characterHeight_0to1(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    lua_pushnumber(L, b->characterHeight_0to1);
    return 1;
}

// --- Setters for AppearanceBase ---
static int AppearanceBase_set_slots(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for slots");
}

static int AppearanceBase_set_attachedObjects(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for attachedObjects");
}

static int AppearanceBase_set_attachedHarpoons(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for attachedHarpoons");
}

static int AppearanceBase_set_msgClearHarpoons(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    b->msgClearHarpoons = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AppearanceBase_set_attachedEffects(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for attachedEffects");
}

static int AppearanceBase_set_attachedEffectsToRemove(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for attachedEffectsToRemove");
}

static int AppearanceBase_set_woundsList(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for woundsList");
}

static int AppearanceBase_set_woundsListMutex(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for woundsListMutex");
}

static int AppearanceBase_set_body(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for body");
}

static int AppearanceBase_set_bodyLoader(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for bodyLoader");
}

static int AppearanceBase_set_isCreatingBody(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    b->isCreatingBody = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AppearanceBase_set_bodyRadius(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    b->bodyRadius = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AppearanceBase_set_me(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for me");
}

static int AppearanceBase_set_visible(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    b->visible = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AppearanceBase_set_bodyFilename(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    b->bodyFilename = luaL_checkstring(L, 2);
    return 0;
}

static int AppearanceBase_set_bodyMaterial(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for bodyMaterial");
}

static int AppearanceBase_set_animation(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for animation");
}

static int AppearanceBase_set_female(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    b->female = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AppearanceBase_set_updatedAttachments(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    b->updatedAttachments = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AppearanceBase_set_updatedAppearanceData(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    b->updatedAppearanceData = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AppearanceBase_set_updateBody(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    b->updateBody = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AppearanceBase_set_suid(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    b->suid = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int AppearanceBase_set_appearanceData(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for appearanceData");
}

static int AppearanceBase_set_raceData(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for raceData");
}

static int AppearanceBase_set_factionColor(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for factionColor");
}

static int AppearanceBase_set_hairStyle(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for hairStyle");
}

static int AppearanceBase_set_shaved(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    b->shaved = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AppearanceBase_set_waterline(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for waterline");
}

static int AppearanceBase_set_waterLineFadeTimer(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    b->waterLineFadeTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AppearanceBase_set_barefoot(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    b->barefoot = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AppearanceBase_set_hideAttachments(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    b->hideAttachments = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AppearanceBase_set_characterHeight(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    b->characterHeight = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AppearanceBase_set_characterHeightSpeedMultiplier(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    b->characterHeightSpeedMultiplier = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AppearanceBase_set_characterHeight_0to1(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");
    b->characterHeight_0to1 = (float)luaL_checknumber(L, 2);
    return 0;
}

// --- Methods for AppearanceBase ---
int AppearanceBaseBinding::_DESTRUCTOR(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    b->_DESTRUCTOR();
    return 0;
}

int AppearanceBaseBinding::updateAnimationTransforms(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    b->updateAnimationTransforms();
    return 0;
}

int AppearanceBaseBinding::forceUpdateAnimationTransforms(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    b->forceUpdateAnimationTransforms();
    return 0;
}

int AppearanceBaseBinding::update(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    b->update();
    return 0;
}

int AppearanceBaseBinding::_NV_update(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    b->_NV_update();
    return 0;
}

int AppearanceBaseBinding::periodicUpdate(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    b->periodicUpdate();
    return 0;
}

int AppearanceBaseBinding::_NV_periodicUpdate(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    b->_NV_periodicUpdate();
    return 0;
}

int AppearanceBaseBinding::activate(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    b->activate();
    return 0;
}

int AppearanceBaseBinding::_NV_activate(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    b->_NV_activate();
    return 0;
}

int AppearanceBaseBinding::deactivate(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    b->deactivate();
    return 0;
}

int AppearanceBaseBinding::_NV_deactivate(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    b->_NV_deactivate();
    return 0;
}

int AppearanceBaseBinding::isFemale(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    bool result = b->isFemale();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::setGender(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    bool _female = lua_toboolean(L, 2) != 0;
    b->setGender(_female);
    return 0;
}

int AppearanceBaseBinding::_NV_setGender(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    bool _female = lua_toboolean(L, 2) != 0;
    b->_NV_setGender(_female);
    return 0;
}

int AppearanceBaseBinding::getRace(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    GameData* result = b->getRace();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int AppearanceBaseBinding::detachAllHarpoonsT(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    b->detachAllHarpoonsT();
    return 0;
}

int AppearanceBaseBinding::_detachAllHarpoons(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    b->_detachAllHarpoons();
    return 0;
}

int AppearanceBaseBinding::updateWetness(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    bool force = lua_toboolean(L, 2) != 0;
    b->updateWetness(force);
    return 0;
}

int AppearanceBaseBinding::updateBloodyness(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    b->updateBloodyness();
    return 0;
}

int AppearanceBaseBinding::getAttachmentPosition(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    std::string slot = luaL_checkstring(L, 2);
    Ogre::Vector3 pos;
    readVector3(L, 3, pos);
    Ogre::Quaternion rot;
    readQuaternion(L, 4, rot);
    bool result = b->getAttachmentPosition(slot, pos, rot);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::hasSlot(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    std::string slot = luaL_checkstring(L, 2);
    bool result = b->hasSlot(slot);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::getNormalisedCharacterHeight(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    float result = b->getNormalisedCharacterHeight();
    lua_pushnumber(L, result);
    return 1;
}

int AppearanceBaseBinding::getCharacterHeight(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    float result = b->getCharacterHeight();
    lua_pushnumber(L, result);
    return 1;
}

int AppearanceBaseBinding::getBodyRadius(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    float result = b->getBodyRadius();
    lua_pushnumber(L, result);
    return 1;
}

int AppearanceBaseBinding::failedToLoad(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    bool result = b->failedToLoad();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::getBonePosition(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    std::string boneName = luaL_checkstring(L, 2);
    Ogre::Vector3 result = b->getBonePosition(boneName);
    pushVector3(L, result);
    return 1;
}

int AppearanceBaseBinding::getBoneOrientation(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    std::string boneName = luaL_checkstring(L, 2);
    Ogre::Quaternion result = b->getBoneOrientation(boneName);
    pushQuaternion(L, result);
    return 1;
}

int AppearanceBaseBinding::getVertexWorldPosition(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    std::string boneName = luaL_checkstring(L, 2);
    int vertex = (int)luaL_checkinteger(L, 3);
    Ogre::Vector3 result = b->getVertexWorldPosition(boneName, vertex);
    pushVector3(L, result);
    return 1;
}

int AppearanceBaseBinding::getRandomVertex(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    std::string boneName = luaL_checkstring(L, 2);
    MeshDataLookup::Dir direction = (MeshDataLookup::Dir)luaL_checkinteger(L, 3);
    int result = b->getRandomVertex(boneName, direction);
    lua_pushinteger(L, result);
    return 1;
}

int AppearanceBaseBinding::notifyDirty(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    b->notifyDirty();
    return 0;
}

int AppearanceBaseBinding::reload(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    b->reload();
    return 0;
}

int AppearanceBaseBinding::updateAppearance(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    b->updateAppearance();
    return 0;
}

int AppearanceBaseBinding::_NV_updateAppearance(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    b->_NV_updateAppearance();
    return 0;
}

int AppearanceBaseBinding::updatePortrait(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    b->updatePortrait();
    return 0;
}

int AppearanceBaseBinding::updateMovementScale(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    b->updateMovementScale();
    return 0;
}

int AppearanceBaseBinding::switchLights(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->switchLights(on);
    return 0;
}

int AppearanceBaseBinding::hasLights(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    bool result = b->hasLights();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::shaveHead(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->shaveHead(on);
    return 0;
}

int AppearanceBaseBinding::isShaved(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    bool result = b->isShaved();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::setFlayed(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->setFlayed(on);
    return 0;
}

int AppearanceBaseBinding::_NV_setFlayed(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->_NV_setFlayed(on);
    return 0;
}

int AppearanceBaseBinding::isFlayed(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    bool result = b->isFlayed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::_NV_isFlayed(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    bool result = b->_NV_isFlayed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::isBarefoot(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    bool result = b->isBarefoot();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::_NV_isBarefoot(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    bool result = b->_NV_isBarefoot();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::setVisible(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    bool value = lua_toboolean(L, 2) != 0;
    b->setVisible(value);
    return 0;
}

int AppearanceBaseBinding::getVisible(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    bool result = b->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::getAttachmentsLoaded(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    bool result = b->getAttachmentsLoaded();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceBaseBinding::setAttachmentsVisible(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    b->setAttachmentsVisible(visible);
    return 0;
}

int AppearanceBaseBinding::_NV_setAttachmentsVisible(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    b->_NV_setAttachmentsVisible(visible);
    return 0;
}

int AppearanceBaseBinding::createBody(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    b->createBody();
    return 0;
}

int AppearanceBaseBinding::buildAttachments(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    b->buildAttachments();
    return 0;
}

int AppearanceBaseBinding::setHairTexture(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    std::string name = luaL_checkstring(L, 2);
    int channel = (int)luaL_checkinteger(L, 3);
    int alpha = (int)luaL_checkinteger(L, 4);
    Ogre::Vector3 colour;
    readVector3(L, 5, colour);
    bool beard = lua_toboolean(L, 6) != 0;
    b->setHairTexture(name, channel, alpha, colour, beard);
    return 0;
}

int AppearanceBaseBinding::updateOverlap(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    b->updateOverlap();
    return 0;
}

int AppearanceBaseBinding::updateCharaterTexture(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    b->updateCharaterTexture();
    return 0;
}

int AppearanceBaseBinding::getCharacterHeightSpeedMultiplier(lua_State* L)
{
    AppearanceBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceBase is nil");

    float result = b->getCharacterHeightSpeedMultiplier();
    lua_pushnumber(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 72: AppearanceBase* _CONSTRUCTOR(...) - unsupported return type
  line 81: void setAppearanceData(...) - unsupported arg type
  line 82: GameDataCopyStandalone* getAppearanceData(...) - unsupported return type
  line 91: const std::string& chooseBodyMesh(...) - reference return type
  line 92: void addWound(...) - unsupported arg type
  line 93: void removeWound(...) - unsupported arg type
  line 94: bool attachItem(...) - overloaded method
  line 95: bool attachItem(...) - overloaded method
  line 96: bool attachHarpoon(...) - unsupported arg type
  line 97: AttachedEffect* attachEffect(...) - unsupported return type
  line 98: AttachedEntity* getAttachedEntity(...) - unsupported return type
  line 99: bool detachItem(...) - overloaded method
  line 100: bool detachItem(...) - overloaded method
  line 101: bool detachHarpoon(...) - unsupported arg type
  line 104: void removeEffect(...) - unsupported arg type
  line 111: AnimationClass* getAnimationSystem(...) - unsupported return type
  line 112: Ogre::SceneNode* getSceneNode(...) - unsupported return type
  line 113: Ogre::OldSkeletonInstance* getSkeleton(...) - unsupported return type
  line 114: Ogre::Entity* getBody(...) - unsupported return type
  line 119: const Ogre::Vector3& getVertexPosition(...) - reference return type
  line 122: const Ogre::Vector3& getRandomVertexPosition(...) - reference return type
  line 125: void serialise(...) - unsupported arg type
  line 132: void getLights(...) - unsupported arg type
  line 133: bool attachItem_Hair(...) - unsupported arg type
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
  line 160: AttachedEntity* createAttachedObject(...) - unsupported return type
  line 161: bool affectsPortrait(...) - unsupported arg type
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
        { "_DESTRUCTOR", AppearanceBaseBinding::_DESTRUCTOR },
        { "updateAnimationTransforms", AppearanceBaseBinding::updateAnimationTransforms },
        { "forceUpdateAnimationTransforms", AppearanceBaseBinding::forceUpdateAnimationTransforms },
        { "update", AppearanceBaseBinding::update },
        { "_NV_update", AppearanceBaseBinding::_NV_update },
        { "periodicUpdate", AppearanceBaseBinding::periodicUpdate },
        { "_NV_periodicUpdate", AppearanceBaseBinding::_NV_periodicUpdate },
        { "activate", AppearanceBaseBinding::activate },
        { "_NV_activate", AppearanceBaseBinding::_NV_activate },
        { "deactivate", AppearanceBaseBinding::deactivate },
        { "_NV_deactivate", AppearanceBaseBinding::_NV_deactivate },
        { "isFemale", AppearanceBaseBinding::isFemale },
        { "setGender", AppearanceBaseBinding::setGender },
        { "_NV_setGender", AppearanceBaseBinding::_NV_setGender },
        { "getRace", AppearanceBaseBinding::getRace },
        { "detachAllHarpoonsT", AppearanceBaseBinding::detachAllHarpoonsT },
        { "_detachAllHarpoons", AppearanceBaseBinding::_detachAllHarpoons },
        { "updateWetness", AppearanceBaseBinding::updateWetness },
        { "updateBloodyness", AppearanceBaseBinding::updateBloodyness },
        { "getAttachmentPosition", AppearanceBaseBinding::getAttachmentPosition },
        { "hasSlot", AppearanceBaseBinding::hasSlot },
        { "getNormalisedCharacterHeight", AppearanceBaseBinding::getNormalisedCharacterHeight },
        { "getCharacterHeight", AppearanceBaseBinding::getCharacterHeight },
        { "getBodyRadius", AppearanceBaseBinding::getBodyRadius },
        { "failedToLoad", AppearanceBaseBinding::failedToLoad },
        { "getBonePosition", AppearanceBaseBinding::getBonePosition },
        { "getBoneOrientation", AppearanceBaseBinding::getBoneOrientation },
        { "getVertexWorldPosition", AppearanceBaseBinding::getVertexWorldPosition },
        { "getRandomVertex", AppearanceBaseBinding::getRandomVertex },
        { "notifyDirty", AppearanceBaseBinding::notifyDirty },
        { "reload", AppearanceBaseBinding::reload },
        { "updateAppearance", AppearanceBaseBinding::updateAppearance },
        { "_NV_updateAppearance", AppearanceBaseBinding::_NV_updateAppearance },
        { "updatePortrait", AppearanceBaseBinding::updatePortrait },
        { "updateMovementScale", AppearanceBaseBinding::updateMovementScale },
        { "switchLights", AppearanceBaseBinding::switchLights },
        { "hasLights", AppearanceBaseBinding::hasLights },
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
        { "updateOverlap", AppearanceBaseBinding::updateOverlap },
        { "updateCharaterTexture", AppearanceBaseBinding::updateCharaterTexture },
        { "getCharacterHeightSpeedMultiplier", AppearanceBaseBinding::getCharacterHeightSpeedMultiplier },
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
    lua_pushcfunction(L, AppearanceBase_get_slots);
    lua_setfield(L, -2, "slots");
    lua_pushcfunction(L, AppearanceBase_get_attachedObjects);
    lua_setfield(L, -2, "attachedObjects");
    lua_pushcfunction(L, AppearanceBase_get_attachedHarpoons);
    lua_setfield(L, -2, "attachedHarpoons");
    lua_pushcfunction(L, AppearanceBase_get_msgClearHarpoons);
    lua_setfield(L, -2, "msgClearHarpoons");
    lua_pushcfunction(L, AppearanceBase_get_attachedEffects);
    lua_setfield(L, -2, "attachedEffects");
    lua_pushcfunction(L, AppearanceBase_get_attachedEffectsToRemove);
    lua_setfield(L, -2, "attachedEffectsToRemove");
    lua_pushcfunction(L, AppearanceBase_get_woundsList);
    lua_setfield(L, -2, "woundsList");
    lua_pushcfunction(L, AppearanceBase_get_woundsListMutex);
    lua_setfield(L, -2, "woundsListMutex");
    lua_pushcfunction(L, AppearanceBase_get_body);
    lua_setfield(L, -2, "body");
    lua_pushcfunction(L, AppearanceBase_get_bodyLoader);
    lua_setfield(L, -2, "bodyLoader");
    lua_pushcfunction(L, AppearanceBase_get_isCreatingBody);
    lua_setfield(L, -2, "isCreatingBody");
    lua_pushcfunction(L, AppearanceBase_get_bodyRadius);
    lua_setfield(L, -2, "bodyRadius");
    lua_pushcfunction(L, AppearanceBase_get_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, AppearanceBase_get_visible);
    lua_setfield(L, -2, "visible");
    lua_pushcfunction(L, AppearanceBase_get_bodyFilename);
    lua_setfield(L, -2, "bodyFilename");
    lua_pushcfunction(L, AppearanceBase_get_bodyMaterial);
    lua_setfield(L, -2, "bodyMaterial");
    lua_pushcfunction(L, AppearanceBase_get_animation);
    lua_setfield(L, -2, "animation");
    lua_pushcfunction(L, AppearanceBase_get_female);
    lua_setfield(L, -2, "female");
    lua_pushcfunction(L, AppearanceBase_get_updatedAttachments);
    lua_setfield(L, -2, "updatedAttachments");
    lua_pushcfunction(L, AppearanceBase_get_updatedAppearanceData);
    lua_setfield(L, -2, "updatedAppearanceData");
    lua_pushcfunction(L, AppearanceBase_get_updateBody);
    lua_setfield(L, -2, "updateBody");
    lua_pushcfunction(L, AppearanceBase_get_suid);
    lua_setfield(L, -2, "suid");
    lua_pushcfunction(L, AppearanceBase_get_appearanceData);
    lua_setfield(L, -2, "appearanceData");
    lua_pushcfunction(L, AppearanceBase_get_raceData);
    lua_setfield(L, -2, "raceData");
    lua_pushcfunction(L, AppearanceBase_get_factionColor);
    lua_setfield(L, -2, "factionColor");
    lua_pushcfunction(L, AppearanceBase_get_hairStyle);
    lua_setfield(L, -2, "hairStyle");
    lua_pushcfunction(L, AppearanceBase_get_shaved);
    lua_setfield(L, -2, "shaved");
    lua_pushcfunction(L, AppearanceBase_get_waterline);
    lua_setfield(L, -2, "waterline");
    lua_pushcfunction(L, AppearanceBase_get_waterLineFadeTimer);
    lua_setfield(L, -2, "waterLineFadeTimer");
    lua_pushcfunction(L, AppearanceBase_get_barefoot);
    lua_setfield(L, -2, "barefoot");
    lua_pushcfunction(L, AppearanceBase_get_hideAttachments);
    lua_setfield(L, -2, "hideAttachments");
    lua_pushcfunction(L, AppearanceBase_get_characterHeight);
    lua_setfield(L, -2, "characterHeight");
    lua_pushcfunction(L, AppearanceBase_get_characterHeightSpeedMultiplier);
    lua_setfield(L, -2, "characterHeightSpeedMultiplier");
    lua_pushcfunction(L, AppearanceBase_get_characterHeight_0to1);
    lua_setfield(L, -2, "characterHeight_0to1");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, AppearanceBase_set_slots);
    lua_setfield(L, -2, "slots");
    lua_pushcfunction(L, AppearanceBase_set_attachedObjects);
    lua_setfield(L, -2, "attachedObjects");
    lua_pushcfunction(L, AppearanceBase_set_attachedHarpoons);
    lua_setfield(L, -2, "attachedHarpoons");
    lua_pushcfunction(L, AppearanceBase_set_msgClearHarpoons);
    lua_setfield(L, -2, "msgClearHarpoons");
    lua_pushcfunction(L, AppearanceBase_set_attachedEffects);
    lua_setfield(L, -2, "attachedEffects");
    lua_pushcfunction(L, AppearanceBase_set_attachedEffectsToRemove);
    lua_setfield(L, -2, "attachedEffectsToRemove");
    lua_pushcfunction(L, AppearanceBase_set_woundsList);
    lua_setfield(L, -2, "woundsList");
    lua_pushcfunction(L, AppearanceBase_set_woundsListMutex);
    lua_setfield(L, -2, "woundsListMutex");
    lua_pushcfunction(L, AppearanceBase_set_body);
    lua_setfield(L, -2, "body");
    lua_pushcfunction(L, AppearanceBase_set_bodyLoader);
    lua_setfield(L, -2, "bodyLoader");
    lua_pushcfunction(L, AppearanceBase_set_isCreatingBody);
    lua_setfield(L, -2, "isCreatingBody");
    lua_pushcfunction(L, AppearanceBase_set_bodyRadius);
    lua_setfield(L, -2, "bodyRadius");
    lua_pushcfunction(L, AppearanceBase_set_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, AppearanceBase_set_visible);
    lua_setfield(L, -2, "visible");
    lua_pushcfunction(L, AppearanceBase_set_bodyFilename);
    lua_setfield(L, -2, "bodyFilename");
    lua_pushcfunction(L, AppearanceBase_set_bodyMaterial);
    lua_setfield(L, -2, "bodyMaterial");
    lua_pushcfunction(L, AppearanceBase_set_animation);
    lua_setfield(L, -2, "animation");
    lua_pushcfunction(L, AppearanceBase_set_female);
    lua_setfield(L, -2, "female");
    lua_pushcfunction(L, AppearanceBase_set_updatedAttachments);
    lua_setfield(L, -2, "updatedAttachments");
    lua_pushcfunction(L, AppearanceBase_set_updatedAppearanceData);
    lua_setfield(L, -2, "updatedAppearanceData");
    lua_pushcfunction(L, AppearanceBase_set_updateBody);
    lua_setfield(L, -2, "updateBody");
    lua_pushcfunction(L, AppearanceBase_set_suid);
    lua_setfield(L, -2, "suid");
    lua_pushcfunction(L, AppearanceBase_set_appearanceData);
    lua_setfield(L, -2, "appearanceData");
    lua_pushcfunction(L, AppearanceBase_set_raceData);
    lua_setfield(L, -2, "raceData");
    lua_pushcfunction(L, AppearanceBase_set_factionColor);
    lua_setfield(L, -2, "factionColor");
    lua_pushcfunction(L, AppearanceBase_set_hairStyle);
    lua_setfield(L, -2, "hairStyle");
    lua_pushcfunction(L, AppearanceBase_set_shaved);
    lua_setfield(L, -2, "shaved");
    lua_pushcfunction(L, AppearanceBase_set_waterline);
    lua_setfield(L, -2, "waterline");
    lua_pushcfunction(L, AppearanceBase_set_waterLineFadeTimer);
    lua_setfield(L, -2, "waterLineFadeTimer");
    lua_pushcfunction(L, AppearanceBase_set_barefoot);
    lua_setfield(L, -2, "barefoot");
    lua_pushcfunction(L, AppearanceBase_set_hideAttachments);
    lua_setfield(L, -2, "hideAttachments");
    lua_pushcfunction(L, AppearanceBase_set_characterHeight);
    lua_setfield(L, -2, "characterHeight");
    lua_pushcfunction(L, AppearanceBase_set_characterHeightSpeedMultiplier);
    lua_setfield(L, -2, "characterHeightSpeedMultiplier");
    lua_pushcfunction(L, AppearanceBase_set_characterHeight_0to1);
    lua_setfield(L, -2, "characterHeight_0to1");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua