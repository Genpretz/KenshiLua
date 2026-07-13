#include "pch.h"
#include "Bindings/FactionBinding.h"

#include "kenshi\Character.h"
#include "CharacterBinding.h"
#include "DialogueBinding.h"
#include "RaceDataBinding.h"
#include "InventoryBinding.h"
#include "SwordBinding.h"
#include "CharacterAnimalBinding.h"
#include "kenshi/Gear.h"
#include "WeaponBinding.h"
#include "CrossbowBinding.h"
#include "ItemBinding.h"
#include "LockedArmourBinding.h"
#include "GameDataBinding.h"
#include "kenshi/Inventory.h"
#include "kenshi/RaceData.h"
#include "kenshi/MedicalSystem.h"
#include "kenshi/Platoon.h"
#include "ContainerItemBinding.h"
#include "MedicalSystemBinding.h"
#include "OwnershipsBinding.h"

#include "Lua/BindingHelpers.h"
#include "Bindings/CharStatsBinding.h"
#include "Bindings/CharacterAnimalBinding.h"
#include "Bindings/ContainerItemBinding.h"
#include "Bindings/CrossbowBinding.h"
#include "Bindings/DialogueBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/LockedArmourBinding.h"
#include "Bindings/MedicalSystemBinding.h"
#include "Bindings/OwnershipsBinding.h"
#include "Bindings/PlatoonBinding.h"

#include "Bindings/Util/HandBinding.h"
#include "Bindings/BountyManagerBinding.h"
#include "Bindings/CharMovementBinding.h"
#include "Bindings/CharBodyBinding.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/WhoSeesMeBinding.h"
#include "Bindings/AppearanceBaseBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/GameDataCopyStandaloneBinding.h"
#include "Bindings/AttachedArrowManagerBinding.h"
#include "Bindings/Util/YesNoMaybeBinding.h"
#include <kenshi/gui/InventoryGUI.h>
#include "Bindings/Gui/InventoryLayoutBinding.h"
#include "Bindings/RootObjectBaseBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/DamagesBinding.h"
#include "Bindings/CombatTechniqueDataBinding.h"

#include "kenshi/CharacterHuman.h"
#include "kenshi/SensoryData.h"
#include "kenshi/Town.h"
#include "Bindings/CharacterHumanBinding.h"
#include "Bindings/SensoryDataBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/RootObjectBinding.h"

namespace KenshiLua
{

static Character* getB(lua_State* L, int idx)
{
    return checkObject<Character>(L, idx, CharacterBinding::getMetatableName());
}

// --- Getters for Character ---
static int Character_get_offscreenFrameTime(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushnumber(L, b->offscreenFrameTime);
    return 1;
}

static int Character_get_frameTIME(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushnumber(L, b->frameTIME);
    return 1;
}

static int Character_get_frameTIMEfour(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushnumber(L, b->frameTIMEfour);
    return 1;
}

static int Character_get_frameTIME_P(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushnumber(L, b->frameTIME_P);
    return 1;
}

static int Character_get_bodyDecayTimer(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushnumber(L, b->bodyDecayTimer);
    return 1;
}

static int Character_get_stealthMode(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, b->stealthMode ? 1 : 0);
    return 1;
}

static int Character_get__isOnARoof(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, b->_isOnARoof ? 1 : 0);
    return 1;
}

static int Character_get__lightLevel(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushnumber(L, b->_lightLevel);
    return 1;
}

static int Character_get_needsLightLevel(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, b->needsLightLevel ? 1 : 0);
    return 1;
}

static int Character_get__currentProneState(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, (lua_Integer)b->_currentProneState);
    return 1;
}

static int Character_get_isVisibleUpdateMode(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, b->isVisibleUpdateMode ? 1 : 0);
    return 1;
}

static int Character_get_setVisibleMsg(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, b->setVisibleMsg ? 1 : 0);
    return 1;
}

static int Character_get_stealthUnseen(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return pushObject<YesNoMaybe>(L, &b->stealthUnseen, YesNoMaybeBinding::getMetatableName());
}

static int Character_get_playerWantsMeToGetUp(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, b->playerWantsMeToGetUp ? 1 : 0);
    return 1;
}

static int Character_get_crimes(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return pushObject<BountyManager>(L, &b->crimes, BountyManagerBinding::getMetatableName());
}

static int Character_get_currentSkillUsing(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, (lua_Integer)b->currentSkillUsing);
    return 1;
}

static int Character_get_stateBroadcast(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    if (b->stateBroadcast) {
        lua_pushlightuserdata(L, b->stateBroadcast);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int Character_get_isVisibleAndNear(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, b->isVisibleAndNear ? 1 : 0);
    return 1;
}

static int Character_get_isOnScreen(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, b->isOnScreen ? 1 : 0);
    return 1;
}

static int Character_get_disguiseGUIFeedbacks(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_newtable(L);
    typedef ogre_unordered_map<Character::DisguiseGUIFeedback, float>::type MapType;
    for (MapType::const_iterator it = b->disguiseGUIFeedbacks.begin(); it != b->disguiseGUIFeedbacks.end(); ++it)
    {
        lua_pushinteger(L, (lua_Integer)it->first);
        lua_pushnumber(L, (lua_Number)it->second);
        lua_settable(L, -3);
    }
    return 1;
}

static int Character_get_whoSeesMeSneaking(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_newtable(L);
    typedef ogre_unordered_map<hand, Character::WhoSeesMe>::type MapType;
    for (MapType::const_iterator it = b->whoSeesMeSneaking.begin(); it != b->whoSeesMeSneaking.end(); ++it)
    {
        handBinding::push(L, it->first);
        pushObject<Character::WhoSeesMe>(L, const_cast<Character::WhoSeesMe*>(&it->second), WhoSeesMeBinding::getMetatableName());
        lua_settable(L, -3);
    }
    return 1;
}

static int Character_get_stealthMarkerArrows(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return pushObject<Character::AttachedArrowManager>(L, &b->stealthMarkerArrows, AttachedArrowManagerBinding::getMetatableName());
}

static int Character_get__isEngagedWithAPlayer(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, b->_isEngagedWithAPlayer ? 1 : 0);
    return 1;
}

static int Character_get_isUsingTurret(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return handBinding::push(L, b->isUsingTurret);
}

static int Character_get_isCurrentlyGettingUp(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, b->isCurrentlyGettingUp ? 1 : 0);
    return 1;
}

static int Character_get_isGettingEaten(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, b->isGettingEaten);
    return 1;
}

static int Character_get_dialogue(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return pushObject<Dialogue>(L, b->dialogue, DialogueBinding::getMetatableName());
}

static int Character_get_currentStumblePainAnimation(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushstring(L, b->currentStumblePainAnimation.c_str());
    return 1;
}

static int Character_get__isLiterallyUnderMeleeAttackRightNowForSure(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, b->_isLiterallyUnderMeleeAttackRightNowForSure ? 1 : 0);
    return 1;
}

static int Character_get__myMemory(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    if (b->_myMemory) {
        lua_pushlightuserdata(L, b->_myMemory);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int Character_get_lastGuyWhoDefeatedMe(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return handBinding::push(L, b->lastGuyWhoDefeatedMe);
}

static int Character_get_myRace(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return pushObject<RaceData>(L, b->myRace, RaceDataBinding::getMetatableName());
}

static int Character_get_inventory(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return pushObject<Inventory>(L, b->inventory, InventoryBinding::getMetatableName());
}

static int Character_get_rangedCombat(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    if (b->rangedCombat) {
        lua_pushlightuserdata(L, b->rangedCombat);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int Character_get_inSomething(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, (lua_Integer)b->inSomething);
    return 1;
}

static int Character_get_inWhat(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return handBinding::push(L, b->inWhat);
}

static int Character_get_isChained(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, b->isChained ? 1 : 0);
    return 1;
}

static int Character_get_slaveOwner(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return handBinding::push(L, b->slaveOwner);
}

static int Character_get_isCarryingSomething(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, b->isCarryingSomething ? 1 : 0);
    return 1;
}

static int Character_get_carringObjectLeftOrRight(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushstring(L, b->carringObjectLeftOrRight.c_str());
    return 1;
}

static int Character_get_isCarryingLeftSide(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, b->isCarryingLeftSide ? 1 : 0);
    return 1;
}

static int Character_get_carryingObject(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return handBinding::push(L, b->carryingObject);
}

static int Character_get_messages(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, (lua_Integer)b->messages);
    return 1;
}

static int Character_get_messageSubject(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return handBinding::push(L, b->messageSubject);
}

static int Character_get_ragdollNavmeshPosition(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    pushVector3(L, b->ragdollNavmeshPosition);
    return 1;
}

static int Character_get__isBeingCarried(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, b->_isBeingCarried ? 1 : 0);
    return 1;
}

static int Character_get_lastUsedWeaponCategory(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, (lua_Integer)b->lastUsedWeaponCategory);
    return 1;
}

static int Character_get_ragdollMessages(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    // TODO: Unsupported type for ragdollMessages (std::deque<Character::RagdollMsg, std::allocator<Character::RagdollMsg> >)
    return luaL_error(L, "Unsupported property 'ragdollMessages' (type: std::deque<Character::RagdollMsg, std::allocator<Character::RagdollMsg> >)");
}

static int Character_get_msgCarryMode(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    if (b->msgCarryMode) {
        lua_pushlightuserdata(L, b->msgCarryMode);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int Character_get_squadMemberID(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, b->squadMemberID);
    return 1;
}

static int Character_get_diplomacyMultiplier(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushnumber(L, b->diplomacyMultiplier);
    return 1;
}

static int Character_get__destinationInsideBuilding(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return handBinding::push(L, b->_destinationInsideBuilding);
}

static int Character_get__destinationInsideWalls(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, b->_destinationInsideWalls);
    return 1;
}

static int Character_get_animation(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    if (b->animation) {
        lua_pushlightuserdata(L, b->animation);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int Character_get_stats(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return pushObject<CharStats>(L, b->stats, CharStatsBinding::getMetatableName());
}

static int Character_get_medical(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return pushObject<MedicalSystem>(L, &b->medical, MedicalSystemBinding::getMetatableName());
}

static int Character_get_isPhysicalMode(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, b->isPhysicalMode ? 1 : 0);
    return 1;
}

static int Character_get_sex(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushstring(L, b->sex.c_str());
    return 1;
}

static int Character_get_nameTag(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    if (b->nameTag) {
        lua_pushlightuserdata(L, b->nameTag);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int Character_get_movement(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return pushObject<CharMovement>(L, b->movement, CharMovementBinding::getMetatableName());
}

static int Character_get_body(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return pushObject<CharBody>(L, b->body, CharBodyBinding::getMetatableName());
}

static int Character_get_ai(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    if (b->ai) {
        lua_pushlightuserdata(L, b->ai);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int Character_get_platoon(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return pushObject<ActivePlatoon>(L, b->platoon, ActivePlatoonBinding::getMetatableName());
}

static int Character_get_portraitIndex(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, b->portraitIndex);
    return 1;
}

static int Character_get_portraitSerial(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, b->portraitSerial);
    return 1;
}

static int Character_get_audioObject(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, (lua_Integer)b->audioObject);
    return 1;
}

static int Character_get_audioData(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    // TODO: Unsupported type for audioData (AkSoundPosition)
    return luaL_error(L, "Unsupported property 'audioData' (type: AkSoundPosition)");
}

static int Character_get_groundType(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, (lua_Integer)b->groundType);
    return 1;
}

static int Character_get_armourType(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, (lua_Integer)b->armourType);
    return 1;
}

static int Character_get_audioEmitter(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    if (b->audioEmitter) {
        lua_pushlightuserdata(L, b->audioEmitter);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int Character_get_terrainHeightPosition(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushnumber(L, b->terrainHeightPosition);
    return 1;
}

static int Character_get_inDoorsSetCooldown(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, b->inDoorsSetCooldown);
    return 1;
}

static int Character_get_activeEffects(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_newtable(L);
    for (uint32_t i = 0; i < b->activeEffects.size(); ++i)
    {
        lua_pushinteger(L, (lua_Integer)b->activeEffects[i].first);
        lua_pushnumber(L, (lua_Number)b->activeEffects[i].second);
        lua_settable(L, -3);
    }
    return 1;
}

static int Character_get_particleEffects(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    // TODO: Unsupported type for particleEffects (lektor<Effect*>)
    return luaL_error(L, "Unsupported property 'particleEffects' (type: lektor<Effect*>)");
}

static int Character_get_naturalWeapon(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return pushObject<Sword>(L, b->naturalWeapon, SwordBinding::getMetatableName());
}

// --- Setters for Character ---
static int Character_set_offscreenFrameTime(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->offscreenFrameTime = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Character_set_frameTIME(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->frameTIME = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Character_set_frameTIMEfour(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->frameTIMEfour = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Character_set_frameTIME_P(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->frameTIME_P = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Character_set_bodyDecayTimer(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->bodyDecayTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Character_set_stealthMode(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->stealthMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set__isOnARoof(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->_isOnARoof = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set__lightLevel(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->_lightLevel = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Character_set_needsLightLevel(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->needsLightLevel = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set__currentProneState(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->_currentProneState = (ProneState)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_isVisibleUpdateMode(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->isVisibleUpdateMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_setVisibleMsg(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->setVisibleMsg = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_stealthUnseen(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    YesNoMaybe* val = checkObject<YesNoMaybe>(L, 2, YesNoMaybeBinding::getMetatableName());
    if (val) {
        b->stealthUnseen = *val;
    }
    return 0;
}

static int Character_set_playerWantsMeToGetUp(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->playerWantsMeToGetUp = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_crimes(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    BountyManager* val = checkObject<BountyManager>(L, 2, BountyManagerBinding::getMetatableName());
    if (val) b->crimes = *val;
    return 0;
}

static int Character_set_currentSkillUsing(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->currentSkillUsing = (StatsEnumerated)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_stateBroadcast(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->stateBroadcast = (StateBroadcastData*)lua_touserdata(L, 2);
    return 0;
}

static int Character_set_isVisibleAndNear(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->isVisibleAndNear = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_isOnScreen(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->isOnScreen = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_disguiseGUIFeedbacks(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return luaL_error(L, "Read-only or unsupported setter type for disguiseGUIFeedbacks");
}

static int Character_set_whoSeesMeSneaking(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return luaL_error(L, "Read-only or unsupported setter type for whoSeesMeSneaking");
}

static int Character_set_stealthMarkerArrows(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return luaL_error(L, "Read-only property 'stealthMarkerArrows'");
}

static int Character_set__isEngagedWithAPlayer(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->_isEngagedWithAPlayer = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_isUsingTurret(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->isUsingTurret = checkObject<hand>(L, 2, handBinding::getMetatableName()) ? *checkObject<hand>(L, 2, handBinding::getMetatableName()) : hand();
    return 0;
}

static int Character_set_isCurrentlyGettingUp(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->isCurrentlyGettingUp = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_isGettingEaten(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->isGettingEaten = (unsigned char)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_dialogue(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->dialogue = checkObject<Dialogue>(L, 2, DialogueBinding::getMetatableName());
    return 0;
}

static int Character_set_currentStumblePainAnimation(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->currentStumblePainAnimation = luaL_checkstring(L, 2);
    return 0;
}

static int Character_set__isLiterallyUnderMeleeAttackRightNowForSure(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->_isLiterallyUnderMeleeAttackRightNowForSure = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set__myMemory(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->_myMemory = (CharacterMemory*)lua_touserdata(L, 2);
    return 0;
}

static int Character_set_lastGuyWhoDefeatedMe(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->lastGuyWhoDefeatedMe = checkObject<hand>(L, 2, handBinding::getMetatableName()) ? *checkObject<hand>(L, 2, handBinding::getMetatableName()) : hand();
    return 0;
}

static int Character_set_myRace(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->myRace = checkObject<RaceData>(L, 2, RaceDataBinding::getMetatableName());
    return 0;
}

static int Character_set_inventory(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->inventory = checkObject<Inventory>(L, 2, InventoryBinding::getMetatableName());
    return 0;
}

static int Character_set_rangedCombat(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->rangedCombat = (RangedCombatClass*)lua_touserdata(L, 2);
    return 0;
}

static int Character_set_inSomething(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->inSomething = (UseStuffState)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_inWhat(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->inWhat = checkObject<hand>(L, 2, handBinding::getMetatableName()) ? *checkObject<hand>(L, 2, handBinding::getMetatableName()) : hand();
    return 0;
}

static int Character_set_isChained(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->isChained = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_slaveOwner(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->slaveOwner = checkObject<hand>(L, 2, handBinding::getMetatableName()) ? *checkObject<hand>(L, 2, handBinding::getMetatableName()) : hand();
    return 0;
}

static int Character_set_isCarryingSomething(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->isCarryingSomething = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_carringObjectLeftOrRight(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->carringObjectLeftOrRight = luaL_checkstring(L, 2);
    return 0;
}

static int Character_set_isCarryingLeftSide(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->isCarryingLeftSide = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_carryingObject(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->carryingObject = checkObject<hand>(L, 2, handBinding::getMetatableName()) ? *checkObject<hand>(L, 2, handBinding::getMetatableName()) : hand();
    return 0;
}

static int Character_set_messages(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->messages = (Character::CharMessage)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_messageSubject(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->messageSubject = checkObject<hand>(L, 2, handBinding::getMetatableName()) ? *checkObject<hand>(L, 2, handBinding::getMetatableName()) : hand();
    return 0;
}

static int Character_set_ragdollNavmeshPosition(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    readVector3(L, 2, b->ragdollNavmeshPosition);
    return 0;
}

static int Character_set__isBeingCarried(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->_isBeingCarried = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_lastUsedWeaponCategory(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->lastUsedWeaponCategory = (WeaponCategory)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_ragdollMessages(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return luaL_error(L, "Read-only or unsupported setter type for ragdollMessages");
}

static int Character_set_msgCarryMode(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->msgCarryMode = (Character::CarryMsg*)lua_touserdata(L, 2);
    return 0;
}

static int Character_set_squadMemberID(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->squadMemberID = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_diplomacyMultiplier(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->diplomacyMultiplier = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Character_set__destinationInsideBuilding(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->_destinationInsideBuilding = checkObject<hand>(L, 2, handBinding::getMetatableName()) ? *checkObject<hand>(L, 2, handBinding::getMetatableName()) : hand();
    return 0;
}

static int Character_set__destinationInsideWalls(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->_destinationInsideWalls = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_animation(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->animation = (AnimationClass*)lua_touserdata(L, 2);
    return 0;
}

static int Character_set_stats(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->stats = checkObject<CharStats>(L, 2, CharStatsBinding::getMetatableName());
    return 0;
}

static int Character_set_medical(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    MedicalSystem* val = checkObject<MedicalSystem>(L, 2, MedicalSystemBinding::getMetatableName());
    if (val) b->medical = *val;
    return 0;
}

static int Character_set_isPhysicalMode(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->isPhysicalMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_sex(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->sex = luaL_checkstring(L, 2);
    return 0;
}

static int Character_set_nameTag(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->nameTag = (CharacterNameTag*)lua_touserdata(L, 2);
    return 0;
}

static int Character_set_movement(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->movement = checkObject<CharMovement>(L, 2, CharMovementBinding::getMetatableName());
    return 0;
}

static int Character_set_body(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->body = checkObject<CharBody>(L, 2, CharBodyBinding::getMetatableName());
    return 0;
}

static int Character_set_ai(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->ai = (AI*)lua_touserdata(L, 2);
    return 0;
}

static int Character_set_platoon(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->platoon = checkObject<ActivePlatoon>(L, 2, ActivePlatoonBinding::getMetatableName());
    return 0;
}

static int Character_set_portraitIndex(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->portraitIndex = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_portraitSerial(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->portraitSerial = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_audioObject(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->audioObject = (unsigned __int64)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_audioData(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return luaL_error(L, "Read-only or unsupported setter type for audioData");
}

static int Character_set_groundType(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->groundType = (GroundType)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_armourType(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->armourType = (ArmourType)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_audioEmitter(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->audioEmitter = (SoundEmitter*)lua_touserdata(L, 2);
    return 0;
}

static int Character_set_terrainHeightPosition(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->terrainHeightPosition = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Character_set_inDoorsSetCooldown(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->inDoorsSetCooldown = (char)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_activeEffects(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return luaL_error(L, "Read-only or unsupported setter type for activeEffects");
}

static int Character_set_particleEffects(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return luaL_error(L, "Read-only or unsupported setter type for particleEffects");
}

static int Character_set_naturalWeapon(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    b->naturalWeapon = checkObject<Sword>(L, 2, SwordBinding::getMetatableName());
    return 0;
}

int CharacterBinding::isImmuneToOffscreenMode(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isImmuneToOffscreenMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::init(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->init();
    return 0;
}

int CharacterBinding::_NV_init(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->_NV_init();
    return 0;
}

int CharacterBinding::_DESTRUCTOR(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->_DESTRUCTOR();
    return 0;
}

int CharacterBinding::isOnARoof(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isOnARoof();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isOnARoof(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->_NV_isOnARoof();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isOnAWall(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isOnAWall();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isOnAWall(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->_NV_isOnAWall();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getLightLevel(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->getLightLevel();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::getHPMultiplier(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->getHPMultiplier();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::_NV_getHPMultiplier(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->_NV_getHPMultiplier();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::healCompletely(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->healCompletely();
    return 0;
}

int CharacterBinding::resetRagdollNavmeshSafePos(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->resetRagdollNavmeshSafePos();
    return 0;
}

int CharacterBinding::setRagdollNavmeshSafePos(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->setRagdollNavmeshSafePos();
    return 0;
}

int CharacterBinding::getFrameTime(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->getFrameTime();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::frameSkip(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->frameSkip();
    return 0;
}

int CharacterBinding::getCurrentNoiseRange(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->getCurrentNoiseRange();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::isDestroyed(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isDestroyed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isDestroyed(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->_NV_isDestroyed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isLawEnforcement(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isLawEnforcement();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::canAssignBounties(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->canAssignBounties();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getDataType(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    itemType result = b->getDataType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::_NV_getDataType(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    itemType result = b->_NV_getDataType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::isDiplomaticStatus(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool factorInBiome = lua_toboolean(L, 2) != 0;
    bool result = b->isDiplomaticStatus(factorInBiome);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isLeadingAWarCampaign(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isLeadingAWarCampaign();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::wantsToTriggerCampaigns(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->wantsToTriggerCampaigns();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isUnique(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isUnique();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::canSpeakNormally(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->canSpeakNormally();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isAnimal(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    CharacterAnimal* result = b->isAnimal();
    return pushObject<CharacterAnimal>(L, result, CharacterAnimalBinding::getMetatableName());
}

int CharacterBinding::_NV_isAnimal(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    CharacterAnimal* result = b->_NV_isAnimal();
    return pushObject<CharacterAnimal>(L, result, CharacterAnimalBinding::getMetatableName());
}

int CharacterBinding::takeMoney(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    int n = (int)luaL_checkinteger(L, 2);
    bool result = b->takeMoney(n);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_takeMoney(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    int n = (int)luaL_checkinteger(L, 2);
    bool result = b->_NV_takeMoney(n);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getMoney(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    int result = b->getMoney();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterBinding::_NV_getMoney(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    int result = b->_NV_getMoney();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterBinding::setSquadMemberType(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    SquadMemberType memType = (SquadMemberType)luaL_checkinteger(L, 2);
    b->setSquadMemberType(memType);
    return 0;
}

int CharacterBinding::dailyUpdate(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->dailyUpdate();
    return 0;
}

int CharacterBinding::updateOnScreenCheck(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->updateOnScreenCheck();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::offscreenUpdate(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->offscreenUpdate();
    return 0;
}

int CharacterBinding::updateTimes(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->updateTimes();
    return 0;
}

int CharacterBinding::update(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->update();
    return 0;
}

int CharacterBinding::_NV_update(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->_NV_update();
    return 0;
}

int CharacterBinding::postUpdate(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->postUpdate();
    return 0;
}

int CharacterBinding::_NV_postUpdate(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->_NV_postUpdate();
    return 0;
}

int CharacterBinding::ragdollUpdatesUT(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->ragdollUpdatesUT();
    return 0;
}

int CharacterBinding::fourFrameUpdate(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->fourFrameUpdate();
    return 0;
}

int CharacterBinding::periodicUpdate(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->periodicUpdate();
    return 0;
}

int CharacterBinding::_NV_periodicUpdate(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->_NV_periodicUpdate();
    return 0;
}

int CharacterBinding::pausedUpdate(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->pausedUpdate();
    return 0;
}

int CharacterBinding::_NV_pausedUpdate(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->_NV_pausedUpdate();
    return 0;
}

int CharacterBinding::updateUT(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->updateUT();
    return 0;
}

int CharacterBinding::threadedUpdate(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->threadedUpdate();
    return 0;
}

int CharacterBinding::_NV_threadedUpdate(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->_NV_threadedUpdate();
    return 0;
}

int CharacterBinding::threadedUpdate4(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->threadedUpdate4();
    return 0;
}

int CharacterBinding::_NV_threadedUpdate4(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->_NV_threadedUpdate4();
    return 0;
}

int CharacterBinding::threadedUpdatePeriodic(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->threadedUpdatePeriodic();
    return 0;
}

int CharacterBinding::_NV_threadedUpdatePeriodic(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->_NV_threadedUpdatePeriodic();
    return 0;
}

int CharacterBinding::pathExists(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Ogre::Vector3 v;
    readVector3(L, 2, v);
    bool result = b->pathExists(v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::weatherUpdate(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float _a1 = (float)luaL_checknumber(L, 2);
    b->weatherUpdate(_a1);
    return 0;
}

int CharacterBinding::_NV_weatherUpdate(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float _a1 = (float)luaL_checknumber(L, 2);
    b->_NV_weatherUpdate(_a1);
    return 0;
}

int CharacterBinding::stealthUpdate(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float _time = (float)luaL_checknumber(L, 2);
    b->stealthUpdate(_time);
    return 0;
}

int CharacterBinding::getPerceptionMult(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->getPerceptionMult();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::isWithThePlayer(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isWithThePlayer();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isItSafeToGetUp(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isItSafeToGetUp();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::separateIntoMyOwnSquad(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool permanent = lua_toboolean(L, 2) != 0;
    Platoon* result = b->separateIntoMyOwnSquad(permanent);
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

int CharacterBinding::dropGearOnDeath(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool vampiricDeath = lua_toboolean(L, 2) != 0;
    b->dropGearOnDeath(vampiricDeath);
    return 0;
}

int CharacterBinding::getCurrentWeatherAffectStatus(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    WeatherAffecting result = b->getCurrentWeatherAffectStatus();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::getCurrentWeatherAffectStrength(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->getCurrentWeatherAffectStrength();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::getWaterLevel(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    WaterState::Enum result = b->getWaterLevel();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::setTerrainHeightPosition(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float height = (float)luaL_checknumber(L, 2);
    b->setTerrainHeightPosition(height);
    return 0;
}

int CharacterBinding::getTerrainHeightPosition(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->getTerrainHeightPosition();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::setDisguiseMessage(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Character::DisguiseGUIFeedback msg = (Character::DisguiseGUIFeedback)luaL_checkinteger(L, 2);
    b->setDisguiseMessage(msg);
    return 0;
}

int CharacterBinding::uniqueStateUpdate(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->uniqueStateUpdate();
    return 0;
}

int CharacterBinding::foodUpdate(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->foodUpdate();
    return 0;
}

int CharacterBinding::_NV_foodUpdate(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->_NV_foodUpdate();
    return 0;
}

int CharacterBinding::getPosition(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Ogre::Vector3 result = b->getPosition();
    pushVector3(L, result);
    return 1;
}

int CharacterBinding::_NV_getPosition(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Ogre::Vector3 result = b->_NV_getPosition();
    pushVector3(L, result);
    return 1;
}

int CharacterBinding::_getRawPosition(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Ogre::Vector3 result = b->_getRawPosition();
    pushVector3(L, result);
    return 1;
}

int CharacterBinding::getRawEntityPosition(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Ogre::Vector3 result = b->getRawEntityPosition();
    pushVector3(L, result);
    return 1;
}

int CharacterBinding::getMovementSpeed(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->getMovementSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::_NV_getMovementSpeed(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->_NV_getMovementSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::getMovementSpeedOrders(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    MoveSpeed result = b->getMovementSpeedOrders();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::_NV_getMovementSpeedOrders(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    MoveSpeed result = b->_NV_getMovementSpeedOrders();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::getMovementDirection(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Ogre::Vector3 result = b->getMovementDirection();
    pushVector3(L, result);
    return 1;
}

int CharacterBinding::_NV_getMovementDirection(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Ogre::Vector3 result = b->_NV_getMovementDirection();
    pushVector3(L, result);
    return 1;
}

int CharacterBinding::isPhysical(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isPhysical(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->_NV_isPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::setVisible(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->setVisible(on);
    return 0;
}

int CharacterBinding::_NV_setVisible(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->_NV_setVisible(on);
    return 0;
}

int CharacterBinding::getVisible(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_getVisible(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->_NV_getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::switchLights(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->switchLights(on);
    return 0;
}

int CharacterBinding::isDisabled(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isDisabled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isDisabled(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->_NV_isDisabled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::setInsideTownWalls(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    int s = (int)luaL_checkinteger(L, 2);
    b->setInsideTownWalls(s);
    return 0;
}

int CharacterBinding::_NV_setInsideTownWalls(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    int s = (int)luaL_checkinteger(L, 2);
    b->_NV_setInsideTownWalls(s);
    return 0;
}

int CharacterBinding::sheatheWeapon(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->sheatheWeapon();
    return 0;
}

int CharacterBinding::_NV_sheatheWeapon(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->_NV_sheatheWeapon();
    return 0;
}

int CharacterBinding::select(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->select();
    return 0;
}

int CharacterBinding::_NV_select(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->_NV_select();
    return 0;
}

int CharacterBinding::unselect(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->unselect();
    return 0;
}

int CharacterBinding::_NV_unselect(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->_NV_unselect();
    return 0;
}

int CharacterBinding::say_WithARepeatLimiter(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    std::string s = luaL_checkstring(L, 2);
    b->say_WithARepeatLimiter(s);
    return 0;
}

int CharacterBinding::_NV_say_WithARepeatLimiter(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    std::string s = luaL_checkstring(L, 2);
    b->_NV_say_WithARepeatLimiter(s);
    return 0;
}

int CharacterBinding::say(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    std::string s = luaL_checkstring(L, 2);
    b->say(s);
    return 0;
}

int CharacterBinding::_NV_say(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    std::string s = luaL_checkstring(L, 2);
    b->_NV_say(s);
    return 0;
}

int CharacterBinding::isInventoryVisible(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isInventoryVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isInventoryVisible(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->_NV_isInventoryVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getNumFoodItems(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    int result = b->getNumFoodItems();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterBinding::_NV_getNumFoodItems(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    int result = b->_NV_getNumFoodItems();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterBinding::hasSimilarItem(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    itemType ty = (itemType)luaL_checkinteger(L, 2);
    bool result = b->hasSimilarItem(ty);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_hasSimilarItem(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    itemType ty = (itemType)luaL_checkinteger(L, 2);
    bool result = b->_NV_hasSimilarItem(ty);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::ifImASmithShouldIDitchMyBackWeapon(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->ifImASmithShouldIDitchMyBackWeapon();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getInventory(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Inventory* result = b->getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int CharacterBinding::_NV_getInventory(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Inventory* result = b->_NV_getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int CharacterBinding::hasABackpackOn(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    ContainerItem* result = b->hasABackpackOn();
    return pushObject<ContainerItem>(L, result, ContainerItemBinding::getMetatableName());
}

int CharacterBinding::isATrader(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isATrader();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isFemale(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isFemale();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isFleeing(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isFleeing();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getRoughLevel(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    int result = b->getRoughLevel();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterBinding::setStandingOrder(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    MessageForB::StandingOrder orderID = (MessageForB::StandingOrder)luaL_checkinteger(L, 2);
    bool on = lua_toboolean(L, 3) != 0;
    b->setStandingOrder(orderID, on);
    return 0;
}

int CharacterBinding::_NV_setStandingOrder(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    MessageForB::StandingOrder orderID = (MessageForB::StandingOrder)luaL_checkinteger(L, 2);
    bool on = lua_toboolean(L, 3) != 0;
    b->_NV_setStandingOrder(orderID, on);
    return 0;
}

int CharacterBinding::getStandingOrder(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    MessageForB::StandingOrder orderID = (MessageForB::StandingOrder)luaL_checkinteger(L, 2);
    bool result = b->getStandingOrder(orderID);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::setStealthMode(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->setStealthMode(on);
    return 0;
}

int CharacterBinding::isStealthMode(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isStealthMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isStealthModeOrCrawling(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isStealthModeOrCrawling();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::declareDead(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->declareDead();
    return 0;
}

int CharacterBinding::removeJob(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    TaskType t = (TaskType)luaL_checkinteger(L, 2);
    b->removeJob(t);
    return 0;
}

int CharacterBinding::removePermajob(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    int t = (int)luaL_checkinteger(L, 2);
    b->removePermajob(t);
    return 0;
}

int CharacterBinding::clearPermajobs(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->clearPermajobs();
    return 0;
}

int CharacterBinding::movePermajob(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    int taskIdx = (int)luaL_checkinteger(L, 2);
    int targetIdx = (int)luaL_checkinteger(L, 3);
    b->movePermajob(taskIdx, targetIdx);
    return 0;
}

int CharacterBinding::getPermajob(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    int slot = (int)luaL_checkinteger(L, 2);
    TaskType result = b->getPermajob(slot);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::getPermajobCount(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    int result = b->getPermajobCount();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterBinding::endCombatMode(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->endCombatMode();
    return 0;
}

int CharacterBinding::getTotalRelativeStrengthOfAttackers(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->getTotalRelativeStrengthOfAttackers();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::_NV_getTotalRelativeStrengthOfAttackers(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->_NV_getTotalRelativeStrengthOfAttackers();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::isIndoorsRagdoll(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isIndoorsRagdoll();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isIndoorsRagdoll(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->_NV_isIndoorsRagdoll();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getIntendedAggression(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->getIntendedAggression();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::_NV_getIntendedAggression(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->_NV_getIntendedAggression();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::getPositionBip01(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Ogre::Vector3 result = b->getPositionBip01();
    pushVector3(L, result);
    return 1;
}

int CharacterBinding::amInsideTownWalls(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    int result = b->amInsideTownWalls();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterBinding::_NV_amInsideTownWalls(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    int result = b->_NV_amInsideTownWalls();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterBinding::setName(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    std::string name = luaL_checkstring(L, 2);
    b->setName(name);
    return 0;
}

int CharacterBinding::_NV_setName(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    std::string name = luaL_checkstring(L, 2);
    b->_NV_setName(name);
    return 0;
}

int CharacterBinding::setNameTagVisible(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool value = lua_toboolean(L, 2) != 0;
    b->setNameTagVisible(value);
    return 0;
}

int CharacterBinding::ragdollMode(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool on = lua_toboolean(L, 2) != 0;
    RagdollPart::Enum part = (RagdollPart::Enum)luaL_checkinteger(L, 3);
    b->ragdollMode(on, part);
    return 0;
}

int CharacterBinding::isRagdoll(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isRagdoll();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isDown(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isDown();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getRagdollPhysicsRootPos(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Ogre::Vector3 result = b->getRagdollPhysicsRootPos();
    pushVector3(L, result);
    return 1;
}

int CharacterBinding::amSomeoneWhoNeedsToEatToLive(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->amSomeoneWhoNeedsToEatToLive();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_amSomeoneWhoNeedsToEatToLive(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->_NV_amSomeoneWhoNeedsToEatToLive();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getMagicHungerSetting(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->getMagicHungerSetting();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::_NV_getMagicHungerSetting(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->_NV_getMagicHungerSetting();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::wantsToEatNow(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->wantsToEatNow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isKidnapped(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isKidnapped();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isKidnapped(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->_NV_isKidnapped();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isLiterallyUnconciousNotPretending(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isLiterallyUnconciousNotPretending();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isLiterallyUnconciousNotPretending(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->_NV_isLiterallyUnconciousNotPretending();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isUnconcious(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isUnconcious();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isUnconcious(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->_NV_isUnconcious();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isCrippled(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isCrippled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isCrippled(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->_NV_isCrippled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getProneState(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    ProneState result = b->getProneState();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::_NV_getProneState(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    ProneState result = b->_NV_getProneState();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::setProneState(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    ProneState p = (ProneState)luaL_checkinteger(L, 2);
    b->setProneState(p);
    return 0;
}

int CharacterBinding::_NV_setProneState(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    ProneState p = (ProneState)luaL_checkinteger(L, 2);
    b->_NV_setProneState(p);
    return 0;
}

int CharacterBinding::_killRagdoll(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool doItNow = lua_toboolean(L, 2) != 0;
    b->_killRagdoll(doItNow);
    return 0;
}

int CharacterBinding::setupAI(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->setupAI();
    return 0;
}

int CharacterBinding::clearAllAIGoals(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->clearAllAIGoals();
    return 0;
}

int CharacterBinding::setupPlatoonAI(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->setupPlatoonAI();
    return 0;
}

int CharacterBinding::setDestination(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    bool shift = lua_toboolean(L, 3) != 0;
    b->setDestination(pos, shift);
    return 0;
}

int CharacterBinding::sayALine(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    std::string line = luaL_checkstring(L, 2);
    bool force = lua_toboolean(L, 3) != 0;
    b->sayALine(line, force);
    return 0;
}

int CharacterBinding::hasDialogue(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->hasDialogue();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::willTalkToEnemies(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->willTalkToEnemies();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::relocationTeleport(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Ogre::Vector3 moveBy;
    readVector3(L, 2, moveBy);
    b->relocationTeleport(moveBy);
    return 0;
}

int CharacterBinding::teleportVisuallyOnly(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Ogre::Vector3 to;
    readVector3(L, 2, to);
    Ogre::Quaternion rot;
    readQuaternion(L, 3, rot);
    b->teleportVisuallyOnly(to, rot);
    return 0;
}

int CharacterBinding::teleportFromAnimation(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->teleportFromAnimation();
    return 0;
}

int CharacterBinding::stumbleState(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->stumbleState();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::setAge(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float f = (float)luaL_checknumber(L, 2);
    b->setAge(f);
    return 0;
}

int CharacterBinding::_NV_setAge(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float f = (float)luaL_checknumber(L, 2);
    b->_NV_setAge(f);
    return 0;
}

int CharacterBinding::getAge(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->getAge();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::_NV_getAge(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->_NV_getAge();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::getAge0to1(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->getAge0to1();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::_NV_getAge0to1(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->_NV_getAge0to1();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::getAgeString(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    std::string result = b->getAgeString();
    lua_pushstring(L, result.c_str());
    return 1;
}

int CharacterBinding::_NV_getAgeString(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    std::string result = b->_NV_getAgeString();
    lua_pushstring(L, result.c_str());
    return 1;
}

int CharacterBinding::getAgeInverse(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->getAgeInverse();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::_NV_getAgeInverse(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->_NV_getAgeInverse();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::reThinkCurrentAIAction(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->reThinkCurrentAIAction();
    return 0;
}

int CharacterBinding::getStats(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    CharStats* result = b->getStats();
    return pushObject<CharStats>(L, result, CharStatsBinding::getMetatableName());
}

int CharacterBinding::getMedical(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    MedicalSystem* result = b->getMedical();
    return pushObject<MedicalSystem>(L, result, MedicalSystemBinding::getMetatableName());
}

int CharacterBinding::getOwnerships(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Ownerships* result = b->getOwnerships();
    return pushObject<Ownerships>(L, result, OwnershipsBinding::getMetatableName());
}

int CharacterBinding::isInCombatMode(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool melee = lua_toboolean(L, 2) != 0;
    bool ranged = lua_toboolean(L, 3) != 0;
    bool result = b->isInCombatMode(melee, ranged);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isInRangedCombatMode(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isInRangedCombatMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isLiterallyUnderMeleeAttackRightNowForSure(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isLiterallyUnderMeleeAttackRightNowForSure();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_isLiterallyUnderMeleeAttackRightNowForSure_update(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->_isLiterallyUnderMeleeAttackRightNowForSure_update();
    return 0;
}

int CharacterBinding::isPrisonerFreeToGo(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isPrisonerFreeToGo();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::clearAllTempEnemyStatuses(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    CharacterPerceptionTags_ShortTerm tag = (CharacterPerceptionTags_ShortTerm)luaL_checkinteger(L, 2);
    b->clearAllTempEnemyStatuses(tag);
    return 0;
}

int CharacterBinding::lookatPosition(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Ogre::Vector3 v;
    readVector3(L, 2, v);
    bool fullbodyFacing = lua_toboolean(L, 3) != 0;
    b->lookatPosition(v, fullbodyFacing);
    return 0;
}

int CharacterBinding::_NV_lookatPosition(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Ogre::Vector3 v;
    readVector3(L, 2, v);
    bool fullbodyFacing = lua_toboolean(L, 3) != 0;
    b->_NV_lookatPosition(v, fullbodyFacing);
    return 0;
}

int CharacterBinding::getAllAttackersCount(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    int result = b->getAllAttackersCount();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterBinding::getRace(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    RaceData* result = b->getRace();
    return pushObject<RaceData>(L, result, RaceDataBinding::getMetatableName());
}

int CharacterBinding::_NV_getRace(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    RaceData* result = b->_NV_getRace();
    return pushObject<RaceData>(L, result, RaceDataBinding::getMetatableName());
}

int CharacterBinding::getRadius(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->getRadius();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::isPlayerCharacter(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isPlayerCharacter();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getTotalCarryWeight(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->getTotalCarryWeight();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::getCurrentWeapon(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Weapon* result = b->getCurrentWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int CharacterBinding::getThePreferredWeapon(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Weapon* result = b->getThePreferredWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int CharacterBinding::getRangedWeapon(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Crossbow* result = b->getRangedWeapon();
    return pushObject<Crossbow>(L, result, CrossbowBinding::getMetatableName());
}

int CharacterBinding::_NV_getRangedWeapon(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Crossbow* result = b->_NV_getRangedWeapon();
    return pushObject<Crossbow>(L, result, CrossbowBinding::getMetatableName());
}

int CharacterBinding::getUpperBodyArmour(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Item* result = b->getUpperBodyArmour();
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int CharacterBinding::getLowerBodyArmour(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Item* result = b->getLowerBodyArmour();
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int CharacterBinding::isInjured(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool robot = lua_toboolean(L, 2) != 0;
    bool result = b->isInjured(robot);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::shouldUseRangedWeapons(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->shouldUseRangedWeapons();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getBoneWorldPosition(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    std::string name = luaL_checkstring(L, 2);
    Ogre::Vector3 result = b->getBoneWorldPosition(name);
    pushVector3(L, result);
    return 1;
}

int CharacterBinding::hasPlatoon(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->hasPlatoon();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isInAPersistentPlatoon(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isInAPersistentPlatoon();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getSquadLeader(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Character* result = b->getSquadLeader();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int CharacterBinding::preventRagdollMode(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->preventRagdollMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::setSlaveAIJob(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->setSlaveAIJob(on);
    return 0;
}

int CharacterBinding::isChainedMode(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isChainedMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getChainedModeShackles(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    LockedArmour* result = b->getChainedModeShackles();
    return pushObject<LockedArmour>(L, result, LockedArmourBinding::getMetatableName());
}

int CharacterBinding::isSlave(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    SlaveStateEnum result = b->isSlave();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::isHeadShaven(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isHeadShaven();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isHeadShaven(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->_NV_isHeadShaven();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::runSlaveAnim(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    std::string anim = luaL_checkstring(L, 2);
    float speed = (float)luaL_checknumber(L, 3);
    float sync = (float)luaL_checknumber(L, 4);
    b->runSlaveAnim(anim, speed, sync);
    return 0;
}

int CharacterBinding::endSlaveAnim(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    std::string anim = luaL_checkstring(L, 2);
    b->endSlaveAnim(anim);
    return 0;
}

int CharacterBinding::updatePortraitGUIState(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->updatePortraitGUIState();
    return 0;
}

int CharacterBinding::slaveAttachToBoneMode(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    std::string bone = luaL_checkstring(L, 2);
    b->slaveAttachToBoneMode(bone);
    return 0;
}

int CharacterBinding::isDead(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isDead();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isBeingCarried(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->isBeingCarried();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::chooseCarryObjectLeftOrRight(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->chooseCarryObjectLeftOrRight();
    return 0;
}

int CharacterBinding::dropCarriedObject(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool ragdollHim = lua_toboolean(L, 2) != 0;
    bool removeOnly = lua_toboolean(L, 3) != 0;
    b->dropCarriedObject(ragdollHim, removeOnly);
    return 0;
}

int CharacterBinding::getDropped(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool ragdollHim = lua_toboolean(L, 2) != 0;
    bool hull = lua_toboolean(L, 3) != 0;
    b->getDropped(ragdollHim, hull);
    return 0;
}

int CharacterBinding::getDiplomacyMultiplier(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float result = b->getDiplomacyMultiplier();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::getDefaultTaskRepertoireEnum(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    unsigned int result = b->getDefaultTaskRepertoireEnum();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterBinding::_NV_getDefaultTaskRepertoireEnum(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    unsigned int result = b->_NV_getDefaultTaskRepertoireEnum();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterBinding::getPredictedPosition(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float secondsInFuture = (float)luaL_checknumber(L, 2);
    Ogre::Vector3 result = b->getPredictedPosition(secondsInFuture);
    pushVector3(L, result);
    return 1;
}

int CharacterBinding::carryModeT(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool on = lua_toboolean(L, 2) != 0;
    bool makeRagdoll = lua_toboolean(L, 3) != 0;
    bool makeHull = lua_toboolean(L, 4) != 0;
    b->carryModeT(on, makeRagdoll, makeHull);
    return 0;
}

int CharacterBinding::_carryMode(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool on = lua_toboolean(L, 2) != 0;
    bool makeRagdoll = lua_toboolean(L, 3) != 0;
    bool makeHull = lua_toboolean(L, 4) != 0;
    b->_carryMode(on, makeRagdoll, makeHull);
    return 0;
}

int CharacterBinding::recalculateTotalEquipmentSkillBonus(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->recalculateTotalEquipmentSkillBonus();
    return 0;
}

int CharacterBinding::setupAudio(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->setupAudio();
    return 0;
}

int CharacterBinding::_NV_setupAudio(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->_NV_setupAudio();
    return 0;
}

int CharacterBinding::setGroundType(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    GroundType t = (GroundType)luaL_checkinteger(L, 2);
    b->setGroundType(t);
    return 0;
}

int CharacterBinding::getGroundType(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    GroundType result = b->getGroundType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::calculateMainArmourType(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->calculateMainArmourType();
    return 0;
}

int CharacterBinding::getMainArmourType(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    ArmourType result = b->getMainArmourType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::getUniformColorScheme(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    GameData* result = b->getUniformColorScheme();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int CharacterBinding::canTakePlayerOrdersAtThisTime(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->canTakePlayerOrdersAtThisTime();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::stopAllEffects(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->stopAllEffects();
    return 0;
}

int CharacterBinding::notifyEffect(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    EffectType::Enum type = (EffectType::Enum)luaL_checkinteger(L, 2);
    WeatherAffecting what = (WeatherAffecting)luaL_checkinteger(L, 3);
    float strength = (float)luaL_checknumber(L, 4);
    b->notifyEffect(type, what, strength);
    return 0;
}

int CharacterBinding::_NV_notifyEffect(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    EffectType::Enum type = (EffectType::Enum)luaL_checkinteger(L, 2);
    WeatherAffecting what = (WeatherAffecting)luaL_checkinteger(L, 3);
    float strength = (float)luaL_checknumber(L, 4);
    b->_NV_notifyEffect(type, what, strength);
    return 0;
}

int CharacterBinding::validateInventorySections(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->validateInventorySections();
    return 0;
}

int CharacterBinding::_NV_validateInventorySections(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->_NV_validateInventorySections();
    return 0;
}

int CharacterBinding::processCharacterLoadTimeMessages(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->processCharacterLoadTimeMessages();
    return 0;
}

int CharacterBinding::wantsPathfinderActive(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->wantsPathfinderActive();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::createAnimationClass(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->createAnimationClass();
    return 0;
}

int CharacterBinding::createPhysical(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_createPhysical(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool result = b->_NV_createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::destroyPhysical(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->destroyPhysical();
    return 0;
}

int CharacterBinding::_NV_destroyPhysical(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->_NV_destroyPhysical();
    return 0;
}

int CharacterBinding::loadUnloadCheck(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->loadUnloadCheck();
    return 0;
}

int CharacterBinding::_NV_loadUnloadCheck(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->_NV_loadUnloadCheck();
    return 0;
}

int CharacterBinding::updateStateBroadcast(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    float time = (float)luaL_checknumber(L, 2);
    b->updateStateBroadcast(time);
    return 0;
}

int CharacterBinding::postRagdollCallback(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool on = lua_toboolean(L, 2) != 0;
    RagdollPart::Enum part = (RagdollPart::Enum)luaL_checkinteger(L, 3);
    b->postRagdollCallback(on, part);
    return 0;
}

int CharacterBinding::_NV_postRagdollCallback(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    bool on = lua_toboolean(L, 2) != 0;
    RagdollPart::Enum part = (RagdollPart::Enum)luaL_checkinteger(L, 3);
    b->_NV_postRagdollCallback(on, part);
    return 0;
}

int CharacterBinding::reCalculateNaturalWeapon(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->reCalculateNaturalWeapon();
    return 0;
}

int CharacterBinding::_NV_reCalculateNaturalWeapon(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    b->_NV_reCalculateNaturalWeapon();
    return 0;
}

int CharacterBinding::rememberCharacter(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    if (!who) return luaL_error(L, "Character argument is nil");

    bool is_long_term = false;
    CharacterPerceptionTags_ShortTerm st_tag = ST_NONE;
    CharacterPerceptionTags_LongTerm lt_tag = LT_NONE;

    if (lua_isnumber(L, 3))
    {
        int val = (int)lua_tointeger(L, 3);
        if (lua_toboolean(L, 4))
        {
            is_long_term = true;
            lt_tag = (CharacterPerceptionTags_LongTerm)val;
        }
        else
        {
            st_tag = (CharacterPerceptionTags_ShortTerm)val;
        }
    }
    else if (lua_isstring(L, 3))
    {
        std::string str = lua_tostring(L, 3);
        
        std::string target = "";
        for (size_t i = 0; i < str.length(); ++i) {
            char c = str[i];
            if (c >= 'a' && c <= 'z') target += (c - 'a' + 'A');
            else if (c == '_' || c == ' ' || c == '-') { /* skip */ }
            else target += c;
        }

        // Try Short-Term first
        lua_getglobal(L, "CharacterPerceptionTags_ShortTerm");
        if (lua_istable(L, -1))
        {
            lua_pushnil(L);
            while (lua_next(L, -2) != 0)
            {
                if (lua_isstring(L, -2))
                {
                    std::string key = lua_tostring(L, -2);
                    std::string norm_key = "";
                    for (size_t j = 0; j < key.length(); ++j) {
                        char c = key[j];
                        if (c >= 'a' && c <= 'z') norm_key += (c - 'a' + 'A');
                        else if (c == '_' || c == ' ' || c == '-') { /* skip */ }
                        else norm_key += c;
                    }
                    if (norm_key == target)
                    {
                        st_tag = (CharacterPerceptionTags_ShortTerm)lua_tointeger(L, -1);
                        lua_pop(L, 3); // pop value, key, and table
                        is_long_term = false;
                        goto resolved;
                    }
                }
                lua_pop(L, 1);
            }
        }
        lua_pop(L, 1);

        // Try Long-Term
        lua_getglobal(L, "CharacterPerceptionTags_LongTerm");
        if (lua_istable(L, -1))
        {
            lua_pushnil(L);
            while (lua_next(L, -2) != 0)
            {
                if (lua_isstring(L, -2))
                {
                    std::string key = lua_tostring(L, -2);
                    std::string norm_key = "";
                    for (size_t j = 0; j < key.length(); ++j) {
                        char c = key[j];
                        if (c >= 'a' && c <= 'z') norm_key += (c - 'a' + 'A');
                        else if (c == '_' || c == ' ' || c == '-') { /* skip */ }
                        else norm_key += c;
                    }
                    if (norm_key == target)
                    {
                        lt_tag = (CharacterPerceptionTags_LongTerm)lua_tointeger(L, -1);
                        lua_pop(L, 3); // pop value, key, and table
                        is_long_term = true;
                        goto resolved;
                    }
                }
                lua_pop(L, 1);
            }
        }
        lua_pop(L, 1);

        return luaL_error(L, "Unknown perception tag: %s", str.c_str());

    resolved:;
    }
    else
    {
        return luaL_error(L, "Tag must be an integer or string");
    }

    if (is_long_term)
    {
        b->rememberCharacter(who, lt_tag);
    }
    else
    {
        b->rememberCharacter(who, st_tag);
    }
    return 0;
}

int CharacterBinding::attackTarget(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    if (!who) return luaL_error(L, "Character argument is nil");

    b->attackTarget(who);
    return 0;
}

int CharacterBinding::isHuman(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    CharacterHuman* result = b->isHuman();
    return pushObject<CharacterHuman>(L, result, CharacterHumanBinding::getMetatableName());
}

int CharacterBinding::_NV_isHuman(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    CharacterHuman* result = b->_NV_isHuman();
    return pushObject<CharacterHuman>(L, result, CharacterHumanBinding::getMetatableName());
}

int CharacterBinding::isResident(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    TownBase* result = b->isResident();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int CharacterBinding::getSensoryData(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    SensoryData* result = b->getSensoryData();
    return pushObject<SensoryData>(L, result, SensoryDataBinding::getMetatableName());
}

int CharacterBinding::_NV_getSensoryData(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    SensoryData* result = b->_NV_getSensoryData();
    return pushObject<SensoryData>(L, result, SensoryDataBinding::getMetatableName());
}

int CharacterBinding::getCurrentTownLocation(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    TownBase* result = b->getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int CharacterBinding::_NV_getCurrentTownLocation(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    TownBase* result = b->_NV_getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int CharacterBinding::lineOfSightCheck(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    if (!who) return luaL_error(L, "Character argument is nil");
    lua_pushnumber(L, (lua_Number)b->lineOfSightCheck(who));
    return 1;
}

int CharacterBinding::isItOkForMeToLoot(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    RootObject* victim = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    lua_pushboolean(L, b->isItOkForMeToLoot(victim, item));
    return 1;
}

int CharacterBinding::_NV_isItOkForMeToLoot(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    RootObject* victim = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    lua_pushboolean(L, b->_NV_isItOkForMeToLoot(victim, item));
    return 1;
}

int CharacterBinding::ImStealingDoYouNotice(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    RootObject* stealFrom = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    lua_pushboolean(L, b->ImStealingDoYouNotice(stealFrom, item));
    return 1;
}

int CharacterBinding::_NV_ImStealingDoYouNotice(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    RootObject* stealFrom = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    lua_pushboolean(L, b->_NV_ImStealingDoYouNotice(stealFrom, item));
    return 1;
}

int CharacterBinding::getFencingSuccessChance(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    RootObject* thief = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    lua_pushnumber(L, b->getFencingSuccessChance(item, thief));
    return 1;
}

int CharacterBinding::stolenGoodsDetectionCheck(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    RootObject* thief = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    lua_pushboolean(L, b->stolenGoodsDetectionCheck(item, thief));
    return 1;
}

int CharacterBinding::_NV_stolenGoodsDetectionCheck(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    RootObject* thief = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    lua_pushboolean(L, b->_NV_stolenGoodsDetectionCheck(item, thief));
    return 1;
}

int CharacterBinding::sellingUniformDetectionCheck(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    Character* thief = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    lua_pushboolean(L, b->sellingUniformDetectionCheck(item, thief));
    return 1;
}

int CharacterBinding::_NV_sellingUniformDetectionCheck(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    Character* thief = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    lua_pushboolean(L, b->_NV_sellingUniformDetectionCheck(item, thief));
    return 1;
}

int CharacterBinding::smugglingTradeCheck(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    Character* who = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    lua_pushinteger(L, static_cast<int>(b->smugglingTradeCheck(item, who).key));
    return 1;
}

int CharacterBinding::_NV_smugglingTradeCheck(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    Character* who = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    lua_pushinteger(L, static_cast<int>(b->_NV_smugglingTradeCheck(item, who).key));
    return 1;
}

int CharacterBinding::eatItem(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Item* food = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    Inventory* from = checkObject<Inventory>(L, 3, InventoryBinding::getMetatableName());
    lua_pushboolean(L, b->eatItem(food, from));
    return 1;
}

int CharacterBinding::giveItem(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool dropOnFail = lua_toboolean(L, 3) != 0;
    bool destroyOnFail = lua_toboolean(L, 4) != 0;
    lua_pushboolean(L, b->giveItem(item, dropOnFail, destroyOnFail));
    return 1;
}

int CharacterBinding::_NV_giveItem(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool dropOnFail = lua_toboolean(L, 3) != 0;
    bool destroyOnFail = lua_toboolean(L, 4) != 0;
    lua_pushboolean(L, b->_NV_giveItem(item, dropOnFail, destroyOnFail));
    return 1;
}

int CharacterBinding::hasRoomForItem(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    lua_pushboolean(L, b->hasRoomForItem(item));
    return 1;
}

int CharacterBinding::_NV_hasRoomForItem(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    lua_pushboolean(L, b->_NV_hasRoomForItem(item));
    return 1;
}

int CharacterBinding::hasItem(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    lua_pushboolean(L, b->hasItem(item));
    return 1;
}

int CharacterBinding::_NV_hasItem(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    lua_pushboolean(L, b->_NV_hasItem(item));
    return 1;
}

int CharacterBinding::hasAmmoFor(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Crossbow* c = checkObject<Crossbow>(L, 2, CrossbowBinding::getMetatableName());
    lua_pushboolean(L, b->hasAmmoFor(c));
    return 1;
}

int CharacterBinding::_NV_hasAmmoFor(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Crossbow* c = checkObject<Crossbow>(L, 2, CrossbowBinding::getMetatableName());
    lua_pushboolean(L, b->_NV_hasAmmoFor(c));
    return 1;
}

int CharacterBinding::shouldIHelpThisGuy(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    lua_pushboolean(L, b->shouldIHelpThisGuy(who));
    return 1;
}

int CharacterBinding::shouldIScrewThisGuyOver(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    lua_pushboolean(L, b->shouldIScrewThisGuyOver(who));
    return 1;
}

int CharacterBinding::ILoveThisGuyBecauseOfStuffThatHappened(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    lua_pushboolean(L, b->ILoveThisGuyBecauseOfStuffThatHappened(who));
    return 1;
}

int CharacterBinding::IHateThisGuyBecauseOfStuffThatHappened(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    lua_pushboolean(L, b->IHateThisGuyBecauseOfStuffThatHappened(who));
    return 1;
}

int CharacterBinding::isEnemy(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool factorInDisguises = lua_toboolean(L, 3) != 0;
    lua_pushboolean(L, b->isEnemy(who, factorInDisguises));
    return 1;
}

int CharacterBinding::_NV_isEnemy(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool factorInDisguises = lua_toboolean(L, 3) != 0;
    lua_pushboolean(L, b->_NV_isEnemy(who, factorInDisguises));
    return 1;
}

int CharacterBinding::isAlly(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool factorInDisguises = lua_toboolean(L, 3) != 0;
    lua_pushboolean(L, b->isAlly(who, factorInDisguises));
    return 1;
}

int CharacterBinding::_NV_isAlly(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool factorInDisguises = lua_toboolean(L, 3) != 0;
    lua_pushboolean(L, b->_NV_isAlly(who, factorInDisguises));
    return 1;
}

int CharacterBinding::setHandle(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be a hand object");
    b->setHandle(*h);
    return 0;
}

int CharacterBinding::_NV_setHandle(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be a hand object");
    b->_NV_setHandle(*h);
    return 0;
}

int CharacterBinding::getStealingSuccessChance(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    RootObject* stealFrom = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    Character* victimOut = nullptr;
    float chance = b->getStealingSuccessChance(stealFrom, item, &victimOut);
    lua_pushnumber(L, (lua_Number)chance);
    if (victimOut)
        pushObject<Character>(L, victimOut, CharacterBinding::getMetatableName());
    else
        lua_pushnil(L);
    return 2;
}

int CharacterBinding::canGoIndoors(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Building* building = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    lua_pushboolean(L, b->canGoIndoors(building));
    return 1;
}

int CharacterBinding::_NV_canGoIndoors(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Building* building = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    lua_pushboolean(L, b->_NV_canGoIndoors(building));
    return 1;
}

int CharacterBinding::isIndoors(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return handBinding::push(L, b->isIndoors());
}

int CharacterBinding::_NV_isIndoors(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return handBinding::push(L, b->_NV_isIndoors());
}

int CharacterBinding::isStandingOnBuilding(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return handBinding::push(L, b->isStandingOnBuilding());
}

int CharacterBinding::_NV_isStandingOnBuilding(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return handBinding::push(L, b->_NV_isStandingOnBuilding());
}

int CharacterBinding::notifyIndoors(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    hand* in = checkObject<hand>(L, 2, handBinding::getMetatableName());
    if (!in) return luaL_error(L, "Argument 1 must be a hand object");
    b->notifyIndoors(*in);
    return 0;
}

int CharacterBinding::_NV_notifyIndoors(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    hand* in = checkObject<hand>(L, 2, handBinding::getMetatableName());
    if (!in) return luaL_error(L, "Argument 1 must be a hand object");
    b->_NV_notifyIndoors(*in);
    return 0;
}

int CharacterBinding::destinationIndoors(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    RootObject* r = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    return handBinding::push(L, b->destinationIndoors(r));
}

int CharacterBinding::setDestinationIndoors(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be a hand object");
    b->setDestinationIndoors(*h);
    return 0;
}

int CharacterBinding::getAppearanceData(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return pushObject<GameDataCopyStandalone>(L, b->getAppearanceData(), GameDataCopyStandaloneBinding::getMetatableName());
}

int CharacterBinding::setAppearanceData(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    GameDataCopyStandalone* data = checkObject<GameDataCopyStandalone>(L, 2, GameDataCopyStandaloneBinding::getMetatableName());
    b->setAppearanceData(data);
    return 0;
}

int CharacterBinding::setFaction(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    ActivePlatoon* ap = checkObject<ActivePlatoon>(L, 3, ActivePlatoonBinding::getMetatableName());
    b->setFaction(f, ap);
    return 0;
}

int CharacterBinding::_NV_setFaction(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    ActivePlatoon* ap = checkObject<ActivePlatoon>(L, 3, ActivePlatoonBinding::getMetatableName());
    b->_NV_setFaction(f, ap);
    return 0;
}

int CharacterBinding::getBody(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return pushObject<CharBody>(L, b->getBody(), CharBodyBinding::getMetatableName());
}

int CharacterBinding::getAttackTarget(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return handBinding::push(L, b->getAttackTarget());
}

int CharacterBinding::getMovement(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return pushObject<CharMovement>(L, b->getMovement(), CharMovementBinding::getMetatableName());
}

int CharacterBinding::getAppearance(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return pushObject<AppearanceBase>(L, b->getAppearance(), AppearanceBaseBinding::getMetatableName());
}

int CharacterBinding::getPlatoon(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return pushObject<ActivePlatoon>(L, b->getPlatoon(), ActivePlatoonBinding::getMetatableName());
}

int CharacterBinding::getCarryingObject(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    return handBinding::push(L, b->getCarryingObject());
}

int CharacterBinding::getAudioObject(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, (lua_Integer)b->getAudioObject());
    return 1;
}

int CharacterBinding::equipItem(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    std::string sectionName = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    b->equipItem(sectionName, item);
    return 0;
}

int CharacterBinding::_NV_equipItem(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    std::string sectionName = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    b->_NV_equipItem(sectionName, item);
    return 0;
}

int CharacterBinding::unequipItem(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    std::string sectionName = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    b->unequipItem(sectionName, item);
    return 0;
}

int CharacterBinding::_NV_unequipItem(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    std::string sectionName = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    b->_NV_unequipItem(sectionName, item);
    return 0;
}

int CharacterBinding::getStealthKOChance(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* victim = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool factors = lua_toboolean(L, 3) != 0;
    lua_pushnumber(L, (lua_Number)b->getStealthKOChance(victim, factors));
    return 1;
}

int CharacterBinding::getKidnappingChance(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* victim = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    lua_pushnumber(L, (lua_Number)b->getKidnappingChance(victim));
    return 1;
}

int CharacterBinding::getKidnappingEscapeChance_skill(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* captor = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    lua_pushnumber(L, (lua_Number)b->getKidnappingEscapeChance_skill(captor));
    return 1;
}

int CharacterBinding::getKidnappingEscapeChance_strength(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* captor = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    lua_pushnumber(L, (lua_Number)b->getKidnappingEscapeChance_strength(captor));
    return 1;
}

/*
Types requiring lightuserdata due to a lack of available bindings:
- StateBroadcastData* (used in stateBroadcast getter/setter, getStateBroadcast, _NV_getStateBroadcast)
- CharacterMemory* (used in _myMemory getter/setter)
- RangedCombatClass* (used in rangedCombat getter/setter)
- AnimationClass* (used in animation getter/setter, getAnimationClass)
- CharacterNameTag* (used in nameTag getter/setter)
- AI* (used in ai getter/setter, getAI)
- SoundEmitter* (used in audioEmitter getter/setter)
- Character::CarryMsg* (used in msgCarryMode getter/setter)
- Blackboard* (used in getBlackboard)
- OrdersReceiver* (used in getOrdersReciever)
- CampaignInstance* (used in isInAWarCampaign)
- Formation* (used in getFormation, _NV_getFormation, getEnemyFormation, _NV_getEnemyFormation)
- CombatClass* (used in getCombatClass)
- Ogre::Aabb* (used in getAABB, _NV_getAABB)
*/

/*
Skipped methods needing manual binding:
  line 187: Character* _CONSTRUCTOR(...) - unsupported arg type
  line 259: void formationUpdateCallback(...) - unsupported arg type
  line 352: GameSaveState serialise(...) - unsupported return type
  line 353: GameSaveState _NV_serialise(...) - unsupported return type
  line 354: void loadFromSerialise(...) - unsupported arg type
  line 355: void _NV_loadFromSerialise(...) - unsupported arg type
  line 356: void loadFromSerialisePostCreationStage(...) - unsupported arg type
  line 357: void _NV_loadFromSerialisePostCreationStage(...) - unsupported arg type
  line 358: bool setupInventorySections(...) - unsupported arg type
  line 359: bool _NV_setupInventorySections(...) - unsupported arg type
  line 388: void getGUIData(...) - unsupported arg type
  line 389: void _NV_getGUIData(...) - unsupported arg type
  line 411: bool hasItemsFrom(...) - unsupported arg type
  line 412: bool _NV_hasItemsFrom(...) - unsupported arg type
  line 427: float getLockpickChance(...) - unsupported arg type
  line 440: void updateGUIStatsDetails(...) - unsupported arg type
  line 441: void _printRaceXPBonusLine(...) - unsupported arg type
  line 451: const Tasker* getPermajobData(...) - unsupported return type
  line 509: bool giveBirth(...) - unsupported arg type
  line 510: bool _NV_giveBirth(...) - unsupported arg type
  line 528: void debugIndicateCharacters(...) - unsupported arg type
  line 532: void sendMessage(...) - unsupported arg type
  line 533: void attackingYou(...) - unsupported arg type
  line 534: bool iShotYou(...) - unsupported arg type
  line 537: bool gettingEaten(...) - unsupported arg type
  line 538: bool _NV_gettingEaten(...) - unsupported arg type
  line 539: void _startStumble(...) - unsupported arg type
  line 564: void getSquadMissionTarget(...) - unsupported arg type
  line 572: unsigned int conglomerateTagsFor(...) - unsupported arg type
  line 625: void setPrisonMode(...) - unsupported arg type
  line 626: void setBedMode(...) - unsupported arg type
  line 630: void setChainedMode(...) - unsupported arg type
  line 718: bool _ragdollMode(...) - non-string reference arg
  line 728: void calculateDestinationState(...) - unsupported arg type
  line 736: bool createComponents(...) - unsupported arg type
*/

static int Character_getIDForMemoryTagging(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    hand result = b->getIDForMemoryTagging();
    handBinding::push(L, result);
    return 1;
}

static int Character_getMySlaveOwner(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    hand result = b->getMySlaveOwner();
    handBinding::push(L, result);
    return 1;
}

static int Character_generateWeapon(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* manufacturer = nullptr;
    if (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) {
        manufacturer = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    }
    Item* result = b->generateWeapon(data, manufacturer);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

static int Character_getName(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    const std::string& result = b->getName();
    lua_pushstring(L, result.c_str());
    return 1;
}

static int Character__NV_getName(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    const std::string& result = b->_NV_getName();
    lua_pushstring(L, result.c_str());
    return 1;
}

static int Character_getAnimationClass(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    AnimationClass* result = b->getAnimationClass();
    if (result) {
        lua_pushlightuserdata(L, result);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int Character_getAI(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    AI* result = b->getAI();
    if (result) {
        lua_pushlightuserdata(L, result);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int Character_getCombatClass(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    CombatClass* result = b->getCombatClass();
    if (result) {
        lua_pushlightuserdata(L, result);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int Character_getBlackboard(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Blackboard* result = b->getBlackboard();
    if (result) {
        lua_pushlightuserdata(L, result);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int Character_getOrdersReciever(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    OrdersReceiver* result = b->getOrdersReciever();
    if (result) {
        lua_pushlightuserdata(L, result);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int Character_isMySlave(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* slave = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    lua_pushboolean(L, b->isMySlave(slave) ? 1 : 0);
    return 1;
}

static int Character_isMyFactionsSlave(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* slave = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    lua_pushboolean(L, b->isMyFactionsSlave(slave) ? 1 : 0);
    return 1;
}

static int Character_changeSlaveOwner(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    hand* newOwner = checkObject<hand>(L, 2, handBinding::getMetatableName());
    if (newOwner) {
        b->changeSlaveOwner(*newOwner);
    }
    return 0;
}

static int Character_pickupObject(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    b->pickupObject(who);
    return 0;
}

static int Character_getPickedUp(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* byWhom = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    b->getPickedUp(byWhom);
    return 0;
}

static int Character_wearingUniformOf(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    lua_pushboolean(L, b->wearingUniformOf(f) ? 1 : 0);
    return 1;
}

static int Character__NV_wearingUniformOf(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    lua_pushboolean(L, b->_NV_wearingUniformOf(f) ? 1 : 0);
    return 1;
}

static int Character_startEffect(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    GameData* effect = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    lua_pushboolean(L, b->startEffect(effect) ? 1 : 0);
    return 1;
}

static int Character_stopEffect(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    GameData* effect = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    lua_pushboolean(L, b->stopEffect(effect) ? 1 : 0);
    return 1;
}

static int Character_setEffectBT(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    GameData* effect = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool active = lua_toboolean(L, 3) != 0;
    b->setEffectBT(effect, active);
    return 0;
}

static int Character_teleport(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Ogre::Vector3 moveBy;
    readVector3(L, 2, moveBy);
    if (lua_gettop(L) >= 3 && !lua_isnil(L, 3))
    {
        Ogre::Quaternion rot;
        readQuaternion(L, 3, rot);
        b->teleport(moveBy, rot);
    }
    else
    {
        b->teleport(moveBy);
    }
    return 0;
}

static int Character_audioValue(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    const char* name = luaL_checkstring(L, 2);
    if (lua_isnumber(L, 3))
    {
        float value = (float)lua_tonumber(L, 3);
        b->audioValue(name, value);
    }
    else
    {
        const char* value = luaL_checkstring(L, 3);
        b->audioValue(name, value);
    }
    return 0;
}

static int Character_audioEvent(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    const char* name = luaL_checkstring(L, 2);
    SoundRange range = (SoundRange)luaL_checkinteger(L, 3);
    lua_pushboolean(L, b->audioEvent(name, range) ? 1 : 0);
    return 1;
}

static int Character_getPermajobName(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    int slot = (int)luaL_checkinteger(L, 2);
    const std::string& name = b->getPermajobName(slot);
    lua_pushstring(L, name.c_str());
    return 1;
}

static int Character_getAABB(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushlightuserdata(L, const_cast<Ogre::Aabb*>(&b->getAABB()));
    return 1;
}

static int Character__NV_getAABB(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lua_pushlightuserdata(L, const_cast<Ogre::Aabb*>(&b->_NV_getAABB()));
    return 1;
}

static int Character_getAllAttackers(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    lektor<hand> out;
    b->getAllAttackers(out);
    lua_newtable(L);
    for (uint32_t i = 0; i < out.count; ++i) {
        handBinding::push(L, out.stuff[i]);
        lua_rawseti(L, -2, i + 1);
    }
    if (out.stuff) {
        Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL>>::operator delete(out.stuff);
    }
    return 1;
}

static int Character_createInventoryLayout(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    InventoryLayout* result = b->createInventoryLayout();
    return pushObject<InventoryLayout>(L, result, InventoryLayoutBinding::getMetatableName());
}

static int Character__NV_createInventoryLayout(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    InventoryLayout* result = b->_NV_createInventoryLayout();
    return pushObject<InventoryLayout>(L, result, InventoryLayoutBinding::getMetatableName());
}

static int Character_isInAWarCampaign(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    CampaignInstance* result = b->isInAWarCampaign();
    if (result) {
        lua_pushlightuserdata(L, result);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int Character_getStateBroadcast(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    StateBroadcastData* result = b->getStateBroadcast();
    if (result) {
        lua_pushlightuserdata(L, result);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int Character__NV_getStateBroadcast(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    StateBroadcastData* result = b->_NV_getStateBroadcast();
    if (result) {
        lua_pushlightuserdata(L, result);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int Character_getFormation(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Formation* result = b->getFormation();
    if (result) {
        lua_pushlightuserdata(L, result);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int Character__NV_getFormation(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Formation* result = b->_NV_getFormation();
    if (result) {
        lua_pushlightuserdata(L, result);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int Character_getEnemyFormation(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Formation* result = b->getEnemyFormation();
    if (result) {
        lua_pushlightuserdata(L, result);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int Character__NV_getEnemyFormation(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Formation* result = b->_NV_getEnemyFormation();
    if (result) {
        lua_pushlightuserdata(L, result);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int Character_AIDestinationIndoorOutdoorCheck(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    RootObject* who = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    lua_pushboolean(L, b->AIDestinationIndoorOutdoorCheck(who) ? 1 : 0);
    return 1;
}

static int Character_notifyICanSeeYouSneaking(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    YesNoMaybe* seeing = checkObject<YesNoMaybe>(L, 3, YesNoMaybeBinding::getMetatableName());
    float maybeProgress01 = (float)luaL_checknumber(L, 4);
    if (seeing) {
        b->notifyICanSeeYouSneaking(who, *seeing, maybeProgress01);
    }
    return 0;
}

static int Character_addGoal(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    TaskType t = (TaskType)luaL_checkinteger(L, 2);
    RootObjectBase* subject = checkObject<RootObjectBase>(L, 3, RootObjectBaseBinding::getMetatableName());
    b->addGoal(t, subject);
    return 0;
}

static int Character_addJob(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    TaskType t = (TaskType)luaL_checkinteger(L, 2);
    RootObject* subject = nullptr;
    if (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) {
        subject = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    }
    bool shift = lua_toboolean(L, 4) != 0;
    bool addDontClear = lua_toboolean(L, 5) != 0;
    Ogre::Vector3 location = Ogre::Vector3::ZERO;
    if (lua_gettop(L) >= 6 && !lua_isnil(L, 6)) {
        readVector3(L, 6, location);
    }
    b->addJob(t, subject, shift, addDontClear, location);
    return 0;
}

static int Character_addOrder(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Building* dest = nullptr;
    if (!lua_isnil(L, 2)) {
        dest = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    }
    TaskType t = (TaskType)luaL_checkinteger(L, 3);
    RootObject* subject = nullptr;
    if (lua_gettop(L) >= 4 && !lua_isnil(L, 4)) {
        subject = checkObject<RootObject>(L, 4, RootObjectBinding::getMetatableName());
    }
    bool shift = lua_toboolean(L, 5) != 0;
    bool clear = lua_toboolean(L, 6) != 0;
    Ogre::Vector3 location = Ogre::Vector3::ZERO;
    if (lua_gettop(L) >= 7 && !lua_isnil(L, 7)) {
        readVector3(L, 7, location);
    }
    b->addOrder(dest, t, subject, shift, clear, location);
    return 0;
}

static int Character_updateLastTask(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Building* dest = nullptr;
    if (!lua_isnil(L, 2)) {
        dest = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    }
    TaskType t = (TaskType)luaL_checkinteger(L, 3);
    RootObject* subject = nullptr;
    if (lua_gettop(L) >= 4 && !lua_isnil(L, 4)) {
        subject = checkObject<RootObject>(L, 4, RootObjectBinding::getMetatableName());
    }
    Ogre::Vector3 location = Ogre::Vector3::ZERO;
    if (lua_gettop(L) >= 5 && !lua_isnil(L, 5)) {
        readVector3(L, 5, location);
    }
    b->updateLastTask(dest, t, subject, location);
    return 0;
}

static int Character__NV_updateLastTask(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Building* dest = nullptr;
    if (!lua_isnil(L, 2)) {
        dest = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    }
    TaskType t = (TaskType)luaL_checkinteger(L, 3);
    RootObject* subject = nullptr;
    if (lua_gettop(L) >= 4 && !lua_isnil(L, 4)) {
        subject = checkObject<RootObject>(L, 4, RootObjectBinding::getMetatableName());
    }
    Ogre::Vector3 location = Ogre::Vector3::ZERO;
    if (lua_gettop(L) >= 5 && !lua_isnil(L, 5)) {
        readVector3(L, 5, location);
    }
    b->_NV_updateLastTask(dest, t, subject, location);
    return 0;
}

static int Character_playerMoveOrderDefault(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Building* dest = nullptr;
    if (!lua_isnil(L, 2)) {
        dest = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    }
    RootObject* subject = nullptr;
    if (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) {
        subject = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    }
    Ogre::Vector3 location = Ogre::Vector3::ZERO;
    if (lua_gettop(L) >= 4 && !lua_isnil(L, 4)) {
        readVector3(L, 4, location);
    }
    b->playerMoveOrderDefault(dest, subject, location);
    return 0;
}

static int Character__NV_playerMoveOrderDefault(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Building* dest = nullptr;
    if (!lua_isnil(L, 2)) {
        dest = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    }
    RootObject* subject = nullptr;
    if (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) {
        subject = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    }
    Ogre::Vector3 location = Ogre::Vector3::ZERO;
    if (lua_gettop(L) >= 4 && !lua_isnil(L, 4)) {
        readVector3(L, 4, location);
    }
    b->_NV_playerMoveOrderDefault(dest, subject, location);
    return 0;
}

static int Character_destinationInsideWalls(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    RootObject* r = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    lua_pushinteger(L, b->destinationInsideWalls(r));
    return 1;
}

static int Character_sendDialogEvent(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    EventTriggerEnum what = (EventTriggerEnum)luaL_checkinteger(L, 3);
    lua_pushboolean(L, b->sendDialogEvent(target, what) ? 1 : 0);
    return 1;
}

static int Character_sendDialogEventOverride(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    EventTriggerEnum what = (EventTriggerEnum)luaL_checkinteger(L, 3);
    bool forceRepeat = lua_toboolean(L, 4) != 0;
    lua_pushboolean(L, b->sendDialogEventOverride(target, what, forceRepeat) ? 1 : 0);
    return 1;
}

static int Character_getCharacterMemoryTag(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    int mem = (int)luaL_checkinteger(L, 3);
    bool isLongTerm = true;
    if (lua_gettop(L) >= 4) {
        isLongTerm = lua_toboolean(L, 4) != 0;
    }
    if (isLongTerm) {
        lua_pushboolean(L, b->getCharacterMemoryTag(who, (CharacterPerceptionTags_LongTerm)mem) ? 1 : 0);
    } else {
        lua_pushboolean(L, b->getCharacterMemoryTag(who, (CharacterPerceptionTags_ShortTerm)mem) ? 1 : 0);
    }
    return 1;
}

static int Character__setPlatoon(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    ActivePlatoon* p = nullptr;
    if (lua_gettop(L) >= 2 && !lua_isnil(L, 2)) {
        p = checkObject<ActivePlatoon>(L, 2, ActivePlatoonBinding::getMetatableName());
    }
    int idnum = (int)luaL_checkinteger(L, 3);
    b->_setPlatoon(p, idnum);
    return 0;
}

static int Character_hitByMeleeAttack(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    CutDirection dir = (CutDirection)luaL_checkinteger(L, 2);
    Damages* damage = checkObject<Damages>(L, 3, DamagesBinding::getMetatableName());
    if (!damage) return luaL_error(L, "Damages is nil");
    Character* who = nullptr;
    if (lua_gettop(L) >= 4 && !lua_isnil(L, 4)) {
        who = checkObject<Character>(L, 4, CharacterBinding::getMetatableName());
    }
    CombatTechniqueData* attack = nullptr;
    if (lua_gettop(L) >= 5 && !lua_isnil(L, 5)) {
        attack = checkObject<CombatTechniqueData>(L, 5, CombatTechniqueDataBinding::getMetatableName());
    }
    int comboID = (int)luaL_checkinteger(L, 6);
    HitMaterialType result = b->hitByMeleeAttack(dir, *damage, who, attack, comboID);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

static int Character_getAttackOriginationDirection(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* attacker = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    CutOrigination result = b->getAttackOriginationDirection(attacker);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

static int Character_convertCutDirection(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    CutDirection cut = (CutDirection)luaL_checkinteger(L, 2);
    if (lua_isnumber(L, 3)) {
        CutOrigination from = (CutOrigination)lua_tointeger(L, 3);
        lua_pushinteger(L, (lua_Integer)b->convertCutDirection(cut, from));
    } else {
        Character* attacker = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
        lua_pushinteger(L, (lua_Integer)b->convertCutDirection(cut, attacker));
    }
    return 1;
}

static int Character_notifyTheCampaignOfAnAttack(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* attacker = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    b->notifyTheCampaignOfAnAttack(attacker);
    return 0;
}

static int Character_iShouldntAggravateThisTarget(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    lua_pushboolean(L, b->iShouldntAggravateThisTarget(target) ? 1 : 0);
    return 1;
}

static int Character_attackingYou(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* attacker = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool so = lua_toboolean(L, 3) != 0;
    bool doAwarenessCheck = lua_toboolean(L, 4) != 0;
    b->attackingYou(attacker, so, doAwarenessCheck);
    return 0;
}

static int Character_clearTempEnemyStatus(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* theEnemy = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    b->clearTempEnemyStatus(theEnemy);
    return 0;
}

static int Character_lastSeenInHoursAgo(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    lua_pushnumber(L, (lua_Number)b->lastSeenInHoursAgo(c));
    return 1;
}

static int Character_haveMetBefore(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* h = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    lua_pushboolean(L, b->haveMetBefore(h) ? 1 : 0);
    return 1;
}

static int Character_areYouGonnaGetMe(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    lua_pushboolean(L, b->areYouGonnaGetMe(who) ? 1 : 0);
    return 1;
}

static int Character_checkPlayerOrderForProblems(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    TaskType t = (TaskType)luaL_checkinteger(L, 2);
    RootObject* subject = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    lua_pushboolean(L, b->checkPlayerOrderForProblems(t, subject) ? 1 : 0);
    return 1;
}

static int Character_breakFollowOrderLoop(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    hand* start = checkObject<hand>(L, 2, handBinding::getMetatableName());
    if (start) {
        lua_pushboolean(L, b->breakFollowOrderLoop(*start) ? 1 : 0);
    } else {
        lua_pushboolean(L, 0);
    }
    return 1;
}

static int Character_drawWeapon(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    const char* anim = luaL_checkstring(L, 3);
    lua_pushboolean(L, b->drawWeapon(item, anim) ? 1 : 0);
    return 1;
}

static int Character_setRace(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    GameData* r = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    b->setRace(r);
    return 0;
}

static int Character__NV_setRace(lua_State* L)
{
    Character* b = getB(L, 1);
    if (!b) return luaL_error(L, "Character is nil");
    GameData* r = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    b->_NV_setRace(r);
    return 0;
}

int CharacterBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int CharacterBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Character object");
    return 1;
}

void CharacterBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CharacterBinding::gc },
        { "__tostring", CharacterBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "isImmuneToOffscreenMode", CharacterBinding::isImmuneToOffscreenMode },
        { "init", CharacterBinding::init },
        { "_NV_init", CharacterBinding::_NV_init },
        { "_DESTRUCTOR", CharacterBinding::_DESTRUCTOR },
        { "isOnARoof", CharacterBinding::isOnARoof },
        { "_NV_isOnARoof", CharacterBinding::_NV_isOnARoof },
        { "isOnAWall", CharacterBinding::isOnAWall },
        { "_NV_isOnAWall", CharacterBinding::_NV_isOnAWall },
        { "getLightLevel", CharacterBinding::getLightLevel },
        { "getHPMultiplier", CharacterBinding::getHPMultiplier },
        { "_NV_getHPMultiplier", CharacterBinding::_NV_getHPMultiplier },
        { "healCompletely", CharacterBinding::healCompletely },
        { "resetRagdollNavmeshSafePos", CharacterBinding::resetRagdollNavmeshSafePos },
        { "setRagdollNavmeshSafePos", CharacterBinding::setRagdollNavmeshSafePos },
        { "getFrameTime", CharacterBinding::getFrameTime },
        { "frameSkip", CharacterBinding::frameSkip },
        { "getCurrentNoiseRange", CharacterBinding::getCurrentNoiseRange },
        { "isDestroyed", CharacterBinding::isDestroyed },
        { "_NV_isDestroyed", CharacterBinding::_NV_isDestroyed },
        { "isLawEnforcement", CharacterBinding::isLawEnforcement },
        { "canAssignBounties", CharacterBinding::canAssignBounties },
        { "getDataType", CharacterBinding::getDataType },
        { "_NV_getDataType", CharacterBinding::_NV_getDataType },
        { "isDiplomaticStatus", CharacterBinding::isDiplomaticStatus },
        { "isLeadingAWarCampaign", CharacterBinding::isLeadingAWarCampaign },
        { "wantsToTriggerCampaigns", CharacterBinding::wantsToTriggerCampaigns },
        { "isUnique", CharacterBinding::isUnique },
        { "canSpeakNormally", CharacterBinding::canSpeakNormally },
        { "isAnimal", CharacterBinding::isAnimal },
        { "_NV_isAnimal", CharacterBinding::_NV_isAnimal },
        { "takeMoney", CharacterBinding::takeMoney },
        { "_NV_takeMoney", CharacterBinding::_NV_takeMoney },
        { "getMoney", CharacterBinding::getMoney },
        { "_NV_getMoney", CharacterBinding::_NV_getMoney },
        { "setSquadMemberType", CharacterBinding::setSquadMemberType },
        { "dailyUpdate", CharacterBinding::dailyUpdate },
        { "updateOnScreenCheck", CharacterBinding::updateOnScreenCheck },
        { "offscreenUpdate", CharacterBinding::offscreenUpdate },
        { "updateTimes", CharacterBinding::updateTimes },
        { "update", CharacterBinding::update },
        { "_NV_update", CharacterBinding::_NV_update },
        { "postUpdate", CharacterBinding::postUpdate },
        { "_NV_postUpdate", CharacterBinding::_NV_postUpdate },
        { "ragdollUpdatesUT", CharacterBinding::ragdollUpdatesUT },
        { "fourFrameUpdate", CharacterBinding::fourFrameUpdate },
        { "periodicUpdate", CharacterBinding::periodicUpdate },
        { "_NV_periodicUpdate", CharacterBinding::_NV_periodicUpdate },
        { "pausedUpdate", CharacterBinding::pausedUpdate },
        { "_NV_pausedUpdate", CharacterBinding::_NV_pausedUpdate },
        { "updateUT", CharacterBinding::updateUT },
        { "threadedUpdate", CharacterBinding::threadedUpdate },
        { "_NV_threadedUpdate", CharacterBinding::_NV_threadedUpdate },
        { "threadedUpdate4", CharacterBinding::threadedUpdate4 },
        { "_NV_threadedUpdate4", CharacterBinding::_NV_threadedUpdate4 },
        { "threadedUpdatePeriodic", CharacterBinding::threadedUpdatePeriodic },
        { "_NV_threadedUpdatePeriodic", CharacterBinding::_NV_threadedUpdatePeriodic },
        { "pathExists", CharacterBinding::pathExists },
        { "weatherUpdate", CharacterBinding::weatherUpdate },
        { "_NV_weatherUpdate", CharacterBinding::_NV_weatherUpdate },
        { "stealthUpdate", CharacterBinding::stealthUpdate },
        { "getPerceptionMult", CharacterBinding::getPerceptionMult },
        { "isWithThePlayer", CharacterBinding::isWithThePlayer },
        { "isItSafeToGetUp", CharacterBinding::isItSafeToGetUp },
        { "separateIntoMyOwnSquad", CharacterBinding::separateIntoMyOwnSquad },
        { "dropGearOnDeath", CharacterBinding::dropGearOnDeath },
        { "getCurrentWeatherAffectStatus", CharacterBinding::getCurrentWeatherAffectStatus },
        { "getCurrentWeatherAffectStrength", CharacterBinding::getCurrentWeatherAffectStrength },
        { "getWaterLevel", CharacterBinding::getWaterLevel },
        { "setTerrainHeightPosition", CharacterBinding::setTerrainHeightPosition },
        { "getTerrainHeightPosition", CharacterBinding::getTerrainHeightPosition },
        { "setDisguiseMessage", CharacterBinding::setDisguiseMessage },
        { "uniqueStateUpdate", CharacterBinding::uniqueStateUpdate },
        { "foodUpdate", CharacterBinding::foodUpdate },
        { "_NV_foodUpdate", CharacterBinding::_NV_foodUpdate },
        { "getPosition", CharacterBinding::getPosition },
        { "_NV_getPosition", CharacterBinding::_NV_getPosition },
        { "_getRawPosition", CharacterBinding::_getRawPosition },
        { "getRawEntityPosition", CharacterBinding::getRawEntityPosition },
        { "getMovementSpeed", CharacterBinding::getMovementSpeed },
        { "_NV_getMovementSpeed", CharacterBinding::_NV_getMovementSpeed },
        { "getMovementSpeedOrders", CharacterBinding::getMovementSpeedOrders },
        { "_NV_getMovementSpeedOrders", CharacterBinding::_NV_getMovementSpeedOrders },
        { "getMovementDirection", CharacterBinding::getMovementDirection },
        { "_NV_getMovementDirection", CharacterBinding::_NV_getMovementDirection },
        { "isPhysical", CharacterBinding::isPhysical },
        { "_NV_isPhysical", CharacterBinding::_NV_isPhysical },
        { "setVisible", CharacterBinding::setVisible },
        { "_NV_setVisible", CharacterBinding::_NV_setVisible },
        { "getVisible", CharacterBinding::getVisible },
        { "_NV_getVisible", CharacterBinding::_NV_getVisible },
        { "switchLights", CharacterBinding::switchLights },
        { "isDisabled", CharacterBinding::isDisabled },
        { "_NV_isDisabled", CharacterBinding::_NV_isDisabled },
        { "setInsideTownWalls", CharacterBinding::setInsideTownWalls },
        { "_NV_setInsideTownWalls", CharacterBinding::_NV_setInsideTownWalls },
        { "sheatheWeapon", CharacterBinding::sheatheWeapon },
        { "_NV_sheatheWeapon", CharacterBinding::_NV_sheatheWeapon },
        { "select", CharacterBinding::select },
        { "_NV_select", CharacterBinding::_NV_select },
        { "unselect", CharacterBinding::unselect },
        { "_NV_unselect", CharacterBinding::_NV_unselect },
        { "say_WithARepeatLimiter", CharacterBinding::say_WithARepeatLimiter },
        { "_NV_say_WithARepeatLimiter", CharacterBinding::_NV_say_WithARepeatLimiter },
        { "say", CharacterBinding::say },
        { "_NV_say", CharacterBinding::_NV_say },
        { "isInventoryVisible", CharacterBinding::isInventoryVisible },
        { "_NV_isInventoryVisible", CharacterBinding::_NV_isInventoryVisible },
        { "getNumFoodItems", CharacterBinding::getNumFoodItems },
        { "_NV_getNumFoodItems", CharacterBinding::_NV_getNumFoodItems },
        { "hasSimilarItem", CharacterBinding::hasSimilarItem },
        { "_NV_hasSimilarItem", CharacterBinding::_NV_hasSimilarItem },
        { "ifImASmithShouldIDitchMyBackWeapon", CharacterBinding::ifImASmithShouldIDitchMyBackWeapon },
        { "getInventory", CharacterBinding::getInventory },
        { "_NV_getInventory", CharacterBinding::_NV_getInventory },
        { "hasABackpackOn", CharacterBinding::hasABackpackOn },
        { "isATrader", CharacterBinding::isATrader },
        { "isFemale", CharacterBinding::isFemale },
        { "isFleeing", CharacterBinding::isFleeing },
        { "getRoughLevel", CharacterBinding::getRoughLevel },
        { "setStandingOrder", CharacterBinding::setStandingOrder },
        { "_NV_setStandingOrder", CharacterBinding::_NV_setStandingOrder },
        { "getStandingOrder", CharacterBinding::getStandingOrder },
        { "setStealthMode", CharacterBinding::setStealthMode },
        { "isStealthMode", CharacterBinding::isStealthMode },
        { "isStealthModeOrCrawling", CharacterBinding::isStealthModeOrCrawling },
        { "declareDead", CharacterBinding::declareDead },
        { "removeJob", CharacterBinding::removeJob },
        { "removePermajob", CharacterBinding::removePermajob },
        { "clearPermajobs", CharacterBinding::clearPermajobs },
        { "movePermajob", CharacterBinding::movePermajob },
        { "getPermajob", CharacterBinding::getPermajob },
        { "getPermajobCount", CharacterBinding::getPermajobCount },
        { "endCombatMode", CharacterBinding::endCombatMode },
        { "getTotalRelativeStrengthOfAttackers", CharacterBinding::getTotalRelativeStrengthOfAttackers },
        { "_NV_getTotalRelativeStrengthOfAttackers", CharacterBinding::_NV_getTotalRelativeStrengthOfAttackers },
        { "isIndoorsRagdoll", CharacterBinding::isIndoorsRagdoll },
        { "_NV_isIndoorsRagdoll", CharacterBinding::_NV_isIndoorsRagdoll },
        { "getIntendedAggression", CharacterBinding::getIntendedAggression },
        { "_NV_getIntendedAggression", CharacterBinding::_NV_getIntendedAggression },
        { "getPositionBip01", CharacterBinding::getPositionBip01 },
        { "amInsideTownWalls", CharacterBinding::amInsideTownWalls },
        { "_NV_amInsideTownWalls", CharacterBinding::_NV_amInsideTownWalls },
        { "setName", CharacterBinding::setName },
        { "_NV_setName", CharacterBinding::_NV_setName },
        { "setNameTagVisible", CharacterBinding::setNameTagVisible },
        { "ragdollMode", CharacterBinding::ragdollMode },
        { "isRagdoll", CharacterBinding::isRagdoll },
        { "isDown", CharacterBinding::isDown },
        { "getRagdollPhysicsRootPos", CharacterBinding::getRagdollPhysicsRootPos },
        { "amSomeoneWhoNeedsToEatToLive", CharacterBinding::amSomeoneWhoNeedsToEatToLive },
        { "_NV_amSomeoneWhoNeedsToEatToLive", CharacterBinding::_NV_amSomeoneWhoNeedsToEatToLive },
        { "getMagicHungerSetting", CharacterBinding::getMagicHungerSetting },
        { "_NV_getMagicHungerSetting", CharacterBinding::_NV_getMagicHungerSetting },
        { "wantsToEatNow", CharacterBinding::wantsToEatNow },
        { "isKidnapped", CharacterBinding::isKidnapped },
        { "_NV_isKidnapped", CharacterBinding::_NV_isKidnapped },
        { "isLiterallyUnconciousNotPretending", CharacterBinding::isLiterallyUnconciousNotPretending },
        { "_NV_isLiterallyUnconciousNotPretending", CharacterBinding::_NV_isLiterallyUnconciousNotPretending },
        { "isUnconcious", CharacterBinding::isUnconcious },
        { "_NV_isUnconcious", CharacterBinding::_NV_isUnconcious },
        { "isCrippled", CharacterBinding::isCrippled },
        { "_NV_isCrippled", CharacterBinding::_NV_isCrippled },
        { "getProneState", CharacterBinding::getProneState },
        { "_NV_getProneState", CharacterBinding::_NV_getProneState },
        { "setProneState", CharacterBinding::setProneState },
        { "_NV_setProneState", CharacterBinding::_NV_setProneState },
        { "_killRagdoll", CharacterBinding::_killRagdoll },
        { "setupAI", CharacterBinding::setupAI },
        { "clearAllAIGoals", CharacterBinding::clearAllAIGoals },
        { "setupPlatoonAI", CharacterBinding::setupPlatoonAI },
        { "setDestination", CharacterBinding::setDestination },
        { "sayALine", CharacterBinding::sayALine },
        { "hasDialogue", CharacterBinding::hasDialogue },
        { "willTalkToEnemies", CharacterBinding::willTalkToEnemies },
        { "relocationTeleport", CharacterBinding::relocationTeleport },
        { "teleportVisuallyOnly", CharacterBinding::teleportVisuallyOnly },
        { "teleportFromAnimation", CharacterBinding::teleportFromAnimation },
        { "stumbleState", CharacterBinding::stumbleState },
        { "setAge", CharacterBinding::setAge },
        { "_NV_setAge", CharacterBinding::_NV_setAge },
        { "getAge", CharacterBinding::getAge },
        { "_NV_getAge", CharacterBinding::_NV_getAge },
        { "getAge0to1", CharacterBinding::getAge0to1 },
        { "_NV_getAge0to1", CharacterBinding::_NV_getAge0to1 },
        { "getAgeString", CharacterBinding::getAgeString },
        { "_NV_getAgeString", CharacterBinding::_NV_getAgeString },
        { "getAgeInverse", CharacterBinding::getAgeInverse },
        { "_NV_getAgeInverse", CharacterBinding::_NV_getAgeInverse },
        { "reThinkCurrentAIAction", CharacterBinding::reThinkCurrentAIAction },
        { "getStats", CharacterBinding::getStats },
        { "getMedical", CharacterBinding::getMedical },
        { "getOwnerships", CharacterBinding::getOwnerships },
        { "isInCombatMode", CharacterBinding::isInCombatMode },
        { "isInRangedCombatMode", CharacterBinding::isInRangedCombatMode },
        { "isLiterallyUnderMeleeAttackRightNowForSure", CharacterBinding::isLiterallyUnderMeleeAttackRightNowForSure },
        { "_isLiterallyUnderMeleeAttackRightNowForSure_update", CharacterBinding::_isLiterallyUnderMeleeAttackRightNowForSure_update },
        { "isPrisonerFreeToGo", CharacterBinding::isPrisonerFreeToGo },
        { "clearAllTempEnemyStatuses", CharacterBinding::clearAllTempEnemyStatuses },
        { "lookatPosition", CharacterBinding::lookatPosition },
        { "_NV_lookatPosition", CharacterBinding::_NV_lookatPosition },
        { "getAllAttackersCount", CharacterBinding::getAllAttackersCount },
        { "getRace", CharacterBinding::getRace },
        { "_NV_getRace", CharacterBinding::_NV_getRace },
        { "getRadius", CharacterBinding::getRadius },
        { "isPlayerCharacter", CharacterBinding::isPlayerCharacter },
        { "getTotalCarryWeight", CharacterBinding::getTotalCarryWeight },
        { "getCurrentWeapon", CharacterBinding::getCurrentWeapon },
        { "getThePreferredWeapon", CharacterBinding::getThePreferredWeapon },
        { "getRangedWeapon", CharacterBinding::getRangedWeapon },
        { "_NV_getRangedWeapon", CharacterBinding::_NV_getRangedWeapon },
        { "getUpperBodyArmour", CharacterBinding::getUpperBodyArmour },
        { "getLowerBodyArmour", CharacterBinding::getLowerBodyArmour },
        { "isInjured", CharacterBinding::isInjured },
        { "shouldUseRangedWeapons", CharacterBinding::shouldUseRangedWeapons },
        { "getBoneWorldPosition", CharacterBinding::getBoneWorldPosition },
        { "hasPlatoon", CharacterBinding::hasPlatoon },
        { "isInAPersistentPlatoon", CharacterBinding::isInAPersistentPlatoon },
        { "getSquadLeader", CharacterBinding::getSquadLeader },
        { "preventRagdollMode", CharacterBinding::preventRagdollMode },
        { "setSlaveAIJob", CharacterBinding::setSlaveAIJob },
        { "isChainedMode", CharacterBinding::isChainedMode },
        { "getChainedModeShackles", CharacterBinding::getChainedModeShackles },
        { "isSlave", CharacterBinding::isSlave },
        { "isHeadShaven", CharacterBinding::isHeadShaven },
        { "_NV_isHeadShaven", CharacterBinding::_NV_isHeadShaven },
        { "runSlaveAnim", CharacterBinding::runSlaveAnim },
        { "endSlaveAnim", CharacterBinding::endSlaveAnim },
        { "updatePortraitGUIState", CharacterBinding::updatePortraitGUIState },
        { "slaveAttachToBoneMode", CharacterBinding::slaveAttachToBoneMode },
        { "isDead", CharacterBinding::isDead },
        { "isBeingCarried", CharacterBinding::isBeingCarried },
        { "chooseCarryObjectLeftOrRight", CharacterBinding::chooseCarryObjectLeftOrRight },
        { "dropCarriedObject", CharacterBinding::dropCarriedObject },
        { "getDropped", CharacterBinding::getDropped },
        { "getDiplomacyMultiplier", CharacterBinding::getDiplomacyMultiplier },
        { "getDefaultTaskRepertoireEnum", CharacterBinding::getDefaultTaskRepertoireEnum },
        { "_NV_getDefaultTaskRepertoireEnum", CharacterBinding::_NV_getDefaultTaskRepertoireEnum },
        { "getPredictedPosition", CharacterBinding::getPredictedPosition },
        { "carryModeT", CharacterBinding::carryModeT },
        { "_carryMode", CharacterBinding::_carryMode },
        { "recalculateTotalEquipmentSkillBonus", CharacterBinding::recalculateTotalEquipmentSkillBonus },
        { "setupAudio", CharacterBinding::setupAudio },
        { "_NV_setupAudio", CharacterBinding::_NV_setupAudio },
        { "setGroundType", CharacterBinding::setGroundType },
        { "getGroundType", CharacterBinding::getGroundType },
        { "calculateMainArmourType", CharacterBinding::calculateMainArmourType },
        { "getMainArmourType", CharacterBinding::getMainArmourType },
        { "getUniformColorScheme", CharacterBinding::getUniformColorScheme },
        { "canTakePlayerOrdersAtThisTime", CharacterBinding::canTakePlayerOrdersAtThisTime },
        { "stopAllEffects", CharacterBinding::stopAllEffects },
        { "notifyEffect", CharacterBinding::notifyEffect },
        { "_NV_notifyEffect", CharacterBinding::_NV_notifyEffect },
        { "validateInventorySections", CharacterBinding::validateInventorySections },
        { "_NV_validateInventorySections", CharacterBinding::_NV_validateInventorySections },
        { "processCharacterLoadTimeMessages", CharacterBinding::processCharacterLoadTimeMessages },
        { "wantsPathfinderActive", CharacterBinding::wantsPathfinderActive },
        { "createAnimationClass", CharacterBinding::createAnimationClass },
        { "createPhysical", CharacterBinding::createPhysical },
        { "_NV_createPhysical", CharacterBinding::_NV_createPhysical },
        { "destroyPhysical", CharacterBinding::destroyPhysical },
        { "_NV_destroyPhysical", CharacterBinding::_NV_destroyPhysical },
        { "loadUnloadCheck", CharacterBinding::loadUnloadCheck },
        { "_NV_loadUnloadCheck", CharacterBinding::_NV_loadUnloadCheck },
        { "updateStateBroadcast", CharacterBinding::updateStateBroadcast },
        { "postRagdollCallback", CharacterBinding::postRagdollCallback },
        { "_NV_postRagdollCallback", CharacterBinding::_NV_postRagdollCallback },
        { "reCalculateNaturalWeapon", CharacterBinding::reCalculateNaturalWeapon },
        { "_NV_reCalculateNaturalWeapon", CharacterBinding::_NV_reCalculateNaturalWeapon },
        { "rememberCharacter", CharacterBinding::rememberCharacter },
        { "attackTarget", CharacterBinding::attackTarget },
        { "isHuman", CharacterBinding::isHuman },
        { "_NV_isHuman", CharacterBinding::_NV_isHuman },
        { "isResident", CharacterBinding::isResident },
        { "getSensoryData", CharacterBinding::getSensoryData },
        { "_NV_getSensoryData", CharacterBinding::_NV_getSensoryData },
        { "getCurrentTownLocation", CharacterBinding::getCurrentTownLocation },
        { "_NV_getCurrentTownLocation", CharacterBinding::_NV_getCurrentTownLocation },
        { "lineOfSightCheck", CharacterBinding::lineOfSightCheck },
        { "isItOkForMeToLoot", CharacterBinding::isItOkForMeToLoot },
        { "_NV_isItOkForMeToLoot", CharacterBinding::_NV_isItOkForMeToLoot },
        { "ImStealingDoYouNotice", CharacterBinding::ImStealingDoYouNotice },
        { "_NV_ImStealingDoYouNotice", CharacterBinding::_NV_ImStealingDoYouNotice },
        { "getFencingSuccessChance", CharacterBinding::getFencingSuccessChance },
        { "stolenGoodsDetectionCheck", CharacterBinding::stolenGoodsDetectionCheck },
        { "_NV_stolenGoodsDetectionCheck", CharacterBinding::_NV_stolenGoodsDetectionCheck },
        { "sellingUniformDetectionCheck", CharacterBinding::sellingUniformDetectionCheck },
        { "_NV_sellingUniformDetectionCheck", CharacterBinding::_NV_sellingUniformDetectionCheck },
        { "smugglingTradeCheck", CharacterBinding::smugglingTradeCheck },
        { "_NV_smugglingTradeCheck", CharacterBinding::_NV_smugglingTradeCheck },
        { "eatItem", CharacterBinding::eatItem },
        { "giveItem", CharacterBinding::giveItem },
        { "_NV_giveItem", CharacterBinding::_NV_giveItem },
        { "hasRoomForItem", CharacterBinding::hasRoomForItem },
        { "_NV_hasRoomForItem", CharacterBinding::_NV_hasRoomForItem },
        { "hasItem", CharacterBinding::hasItem },
        { "_NV_hasItem", CharacterBinding::_NV_hasItem },
        { "hasAmmoFor", CharacterBinding::hasAmmoFor },
        { "_NV_hasAmmoFor", CharacterBinding::_NV_hasAmmoFor },
        { "shouldIHelpThisGuy", CharacterBinding::shouldIHelpThisGuy },
        { "shouldIScrewThisGuyOver", CharacterBinding::shouldIScrewThisGuyOver },
        { "ILoveThisGuyBecauseOfStuffThatHappened", CharacterBinding::ILoveThisGuyBecauseOfStuffThatHappened },
        { "IHateThisGuyBecauseOfStuffThatHappened", CharacterBinding::IHateThisGuyBecauseOfStuffThatHappened },
        { "isEnemy", CharacterBinding::isEnemy },
        { "_NV_isEnemy", CharacterBinding::_NV_isEnemy },
        { "isAlly", CharacterBinding::isAlly },
        { "_NV_isAlly", CharacterBinding::_NV_isAlly },
        { "setHandle", CharacterBinding::setHandle },
        { "_NV_setHandle", CharacterBinding::_NV_setHandle },
        { "getStealingSuccessChance", CharacterBinding::getStealingSuccessChance },
        { "canGoIndoors", CharacterBinding::canGoIndoors },
        { "_NV_canGoIndoors", CharacterBinding::_NV_canGoIndoors },
        { "isIndoors", CharacterBinding::isIndoors },
        { "_NV_isIndoors", CharacterBinding::_NV_isIndoors },
        { "isStandingOnBuilding", CharacterBinding::isStandingOnBuilding },
        { "_NV_isStandingOnBuilding", CharacterBinding::_NV_isStandingOnBuilding },
        { "notifyIndoors", CharacterBinding::notifyIndoors },
        { "_NV_notifyIndoors", CharacterBinding::_NV_notifyIndoors },
        { "destinationIndoors", CharacterBinding::destinationIndoors },
        { "setDestinationIndoors", CharacterBinding::setDestinationIndoors },
        { "getAppearanceData", CharacterBinding::getAppearanceData },
        { "setAppearanceData", CharacterBinding::setAppearanceData },
        { "setFaction", CharacterBinding::setFaction },
        { "_NV_setFaction", CharacterBinding::_NV_setFaction },
        { "getBody", CharacterBinding::getBody },
        { "getAttackTarget", CharacterBinding::getAttackTarget },
        { "getMovement", CharacterBinding::getMovement },
        { "getAppearance", CharacterBinding::getAppearance },
        { "getPlatoon", CharacterBinding::getPlatoon },
        { "getCarryingObject", CharacterBinding::getCarryingObject },
        { "getAudioObject", CharacterBinding::getAudioObject },
        { "equipItem", CharacterBinding::equipItem },
        { "_NV_equipItem", CharacterBinding::_NV_equipItem },
        { "unequipItem", CharacterBinding::unequipItem },
        { "_NV_unequipItem", CharacterBinding::_NV_unequipItem },
        { "getStealthKOChance", CharacterBinding::getStealthKOChance },
        { "getKidnappingChance", CharacterBinding::getKidnappingChance },
        { "getKidnappingEscapeChance_skill", CharacterBinding::getKidnappingEscapeChance_skill },
        { "getKidnappingEscapeChance_strength", CharacterBinding::getKidnappingEscapeChance_strength },
        { "getIDForMemoryTagging", Character_getIDForMemoryTagging },
        { "getMySlaveOwner", Character_getMySlaveOwner },
        { "generateWeapon", Character_generateWeapon },
        { "getName", Character_getName },
        { "_NV_getName", Character__NV_getName },
        { "getAnimationClass", Character_getAnimationClass },
        { "getAI", Character_getAI },
        { "getCombatClass", Character_getCombatClass },
        { "getBlackboard", Character_getBlackboard },
        { "getOrdersReciever", Character_getOrdersReciever },
        { "isMySlave", Character_isMySlave },
        { "isMyFactionsSlave", Character_isMyFactionsSlave },
        { "changeSlaveOwner", Character_changeSlaveOwner },
        { "pickupObject", Character_pickupObject },
        { "getPickedUp", Character_getPickedUp },
        { "wearingUniformOf", Character_wearingUniformOf },
        { "_NV_wearingUniformOf", Character__NV_wearingUniformOf },
        { "startEffect", Character_startEffect },
        { "stopEffect", Character_stopEffect },
        { "setEffectBT", Character_setEffectBT },
        { "teleport", Character_teleport },
        { "audioValue", Character_audioValue },
        { "audioEvent", Character_audioEvent },
        { "getPermajobName", Character_getPermajobName },
        { "getAABB", Character_getAABB },
        { "_NV_getAABB", Character__NV_getAABB },
        { "getAllAttackers", Character_getAllAttackers },
        { "createInventoryLayout", Character_createInventoryLayout },
        { "_NV_createInventoryLayout", Character__NV_createInventoryLayout },
        { "isInAWarCampaign", Character_isInAWarCampaign },
        { "getStateBroadcast", Character_getStateBroadcast },
        { "_NV_getStateBroadcast", Character__NV_getStateBroadcast },
        { "getFormation", Character_getFormation },
        { "_NV_getFormation", Character__NV_getFormation },
        { "getEnemyFormation", Character_getEnemyFormation },
        { "_NV_getEnemyFormation", Character__NV_getEnemyFormation },
        { "AIDestinationIndoorOutdoorCheck", Character_AIDestinationIndoorOutdoorCheck },
        { "notifyICanSeeYouSneaking", Character_notifyICanSeeYouSneaking },
        { "addGoal", Character_addGoal },
        { "addJob", Character_addJob },
        { "addOrder", Character_addOrder },
        { "updateLastTask", Character_updateLastTask },
        { "_NV_updateLastTask", Character__NV_updateLastTask },
        { "playerMoveOrderDefault", Character_playerMoveOrderDefault },
        { "_NV_playerMoveOrderDefault", Character__NV_playerMoveOrderDefault },
        { "destinationInsideWalls", Character_destinationInsideWalls },
        { "sendDialogEvent", Character_sendDialogEvent },
        { "sendDialogEventOverride", Character_sendDialogEventOverride },
        { "getCharacterMemoryTag", Character_getCharacterMemoryTag },
        { "_setPlatoon", Character__setPlatoon },
        { "hitByMeleeAttack", Character_hitByMeleeAttack },
        { "getAttackOriginationDirection", Character_getAttackOriginationDirection },
        { "convertCutDirection", Character_convertCutDirection },
        { "notifyTheCampaignOfAnAttack", Character_notifyTheCampaignOfAnAttack },
        { "iShouldntAggravateThisTarget", Character_iShouldntAggravateThisTarget },
        { "attackingYou", Character_attackingYou },
        { "clearTempEnemyStatus", Character_clearTempEnemyStatus },
        { "lastSeenInHoursAgo", Character_lastSeenInHoursAgo },
        { "haveMetBefore", Character_haveMetBefore },
        { "areYouGonnaGetMe", Character_areYouGonnaGetMe },
        { "checkPlayerOrderForProblems", Character_checkPlayerOrderForProblems },
        { "breakFollowOrderLoop", Character_breakFollowOrderLoop },
        { "drawWeapon", Character_drawWeapon },
        { "setRace", Character_setRace },
        { "_NV_setRace", Character__NV_setRace },
        { 0, 0 }
    };

    registerClass(
        L, 
        CharacterBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CharacterBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, Character_get_offscreenFrameTime);
    lua_setfield(L, -2, "offscreenFrameTime");
    lua_pushcfunction(L, Character_get_frameTIME);
    lua_setfield(L, -2, "frameTIME");
    lua_pushcfunction(L, Character_get_frameTIMEfour);
    lua_setfield(L, -2, "frameTIMEfour");
    lua_pushcfunction(L, Character_get_frameTIME_P);
    lua_setfield(L, -2, "frameTIME_P");
    lua_pushcfunction(L, Character_get_bodyDecayTimer);
    lua_setfield(L, -2, "bodyDecayTimer");
    lua_pushcfunction(L, Character_get_stealthMode);
    lua_setfield(L, -2, "stealthMode");
    lua_pushcfunction(L, Character_get__isOnARoof);
    lua_setfield(L, -2, "_isOnARoof");
    lua_pushcfunction(L, Character_get__lightLevel);
    lua_setfield(L, -2, "_lightLevel");
    lua_pushcfunction(L, Character_get_needsLightLevel);
    lua_setfield(L, -2, "needsLightLevel");
    lua_pushcfunction(L, Character_get__currentProneState);
    lua_setfield(L, -2, "_currentProneState");
    lua_pushcfunction(L, Character_get_isVisibleUpdateMode);
    lua_setfield(L, -2, "isVisibleUpdateMode");
    lua_pushcfunction(L, Character_get_setVisibleMsg);
    lua_setfield(L, -2, "setVisibleMsg");
    lua_pushcfunction(L, Character_get_stealthUnseen);
    lua_setfield(L, -2, "stealthUnseen");
    lua_pushcfunction(L, Character_get_playerWantsMeToGetUp);
    lua_setfield(L, -2, "playerWantsMeToGetUp");
    lua_pushcfunction(L, Character_get_crimes);
    lua_setfield(L, -2, "crimes");
    lua_pushcfunction(L, Character_get_currentSkillUsing);
    lua_setfield(L, -2, "currentSkillUsing");
    lua_pushcfunction(L, Character_get_stateBroadcast);
    lua_setfield(L, -2, "stateBroadcast");
    lua_pushcfunction(L, Character_get_isVisibleAndNear);
    lua_setfield(L, -2, "isVisibleAndNear");
    lua_pushcfunction(L, Character_get_isOnScreen);
    lua_setfield(L, -2, "isOnScreen");
    lua_pushcfunction(L, Character_get_disguiseGUIFeedbacks);
    lua_setfield(L, -2, "disguiseGUIFeedbacks");
    lua_pushcfunction(L, Character_get_whoSeesMeSneaking);
    lua_setfield(L, -2, "whoSeesMeSneaking");
    lua_pushcfunction(L, Character_get_stealthMarkerArrows);
    lua_setfield(L, -2, "stealthMarkerArrows");
    lua_pushcfunction(L, Character_get__isEngagedWithAPlayer);
    lua_setfield(L, -2, "_isEngagedWithAPlayer");
    lua_pushcfunction(L, Character_get_isUsingTurret);
    lua_setfield(L, -2, "isUsingTurret");
    lua_pushcfunction(L, Character_get_isCurrentlyGettingUp);
    lua_setfield(L, -2, "isCurrentlyGettingUp");
    lua_pushcfunction(L, Character_get_isGettingEaten);
    lua_setfield(L, -2, "isGettingEaten");
    lua_pushcfunction(L, Character_get_dialogue);
    lua_setfield(L, -2, "dialogue");
    lua_pushcfunction(L, Character_get_currentStumblePainAnimation);
    lua_setfield(L, -2, "currentStumblePainAnimation");
    lua_pushcfunction(L, Character_get__isLiterallyUnderMeleeAttackRightNowForSure);
    lua_setfield(L, -2, "_isLiterallyUnderMeleeAttackRightNowForSure");
    lua_pushcfunction(L, Character_get__myMemory);
    lua_setfield(L, -2, "_myMemory");
    lua_pushcfunction(L, Character_get_lastGuyWhoDefeatedMe);
    lua_setfield(L, -2, "lastGuyWhoDefeatedMe");
    lua_pushcfunction(L, Character_get_myRace);
    lua_setfield(L, -2, "myRace");
    lua_pushcfunction(L, Character_get_inventory);
    lua_setfield(L, -2, "inventory");
    lua_pushcfunction(L, Character_get_rangedCombat);
    lua_setfield(L, -2, "rangedCombat");
    lua_pushcfunction(L, Character_get_inSomething);
    lua_setfield(L, -2, "inSomething");
    lua_pushcfunction(L, Character_get_inWhat);
    lua_setfield(L, -2, "inWhat");
    lua_pushcfunction(L, Character_get_isChained);
    lua_setfield(L, -2, "isChained");
    lua_pushcfunction(L, Character_get_slaveOwner);
    lua_setfield(L, -2, "slaveOwner");
    lua_pushcfunction(L, Character_get_isCarryingSomething);
    lua_setfield(L, -2, "isCarryingSomething");
    lua_pushcfunction(L, Character_get_carringObjectLeftOrRight);
    lua_setfield(L, -2, "carringObjectLeftOrRight");
    lua_pushcfunction(L, Character_get_isCarryingLeftSide);
    lua_setfield(L, -2, "isCarryingLeftSide");
    lua_pushcfunction(L, Character_get_carryingObject);
    lua_setfield(L, -2, "carryingObject");
    lua_pushcfunction(L, Character_get_messages);
    lua_setfield(L, -2, "messages");
    lua_pushcfunction(L, Character_get_messageSubject);
    lua_setfield(L, -2, "messageSubject");
    lua_pushcfunction(L, Character_get_ragdollNavmeshPosition);
    lua_setfield(L, -2, "ragdollNavmeshPosition");
    lua_pushcfunction(L, Character_get__isBeingCarried);
    lua_setfield(L, -2, "_isBeingCarried");
    lua_pushcfunction(L, Character_get_lastUsedWeaponCategory);
    lua_setfield(L, -2, "lastUsedWeaponCategory");
    lua_pushcfunction(L, Character_get_ragdollMessages);
    lua_setfield(L, -2, "ragdollMessages");
    lua_pushcfunction(L, Character_get_msgCarryMode);
    lua_setfield(L, -2, "msgCarryMode");
    lua_pushcfunction(L, Character_get_squadMemberID);
    lua_setfield(L, -2, "squadMemberID");
    lua_pushcfunction(L, Character_get_diplomacyMultiplier);
    lua_setfield(L, -2, "diplomacyMultiplier");
    lua_pushcfunction(L, Character_get__destinationInsideBuilding);
    lua_setfield(L, -2, "_destinationInsideBuilding");
    lua_pushcfunction(L, Character_get__destinationInsideWalls);
    lua_setfield(L, -2, "_destinationInsideWalls");
    lua_pushcfunction(L, Character_get_animation);
    lua_setfield(L, -2, "animation");
    lua_pushcfunction(L, Character_get_stats);
    lua_setfield(L, -2, "stats");
    lua_pushcfunction(L, Character_get_medical);
    lua_setfield(L, -2, "medical");
    lua_pushcfunction(L, Character_get_isPhysicalMode);
    lua_setfield(L, -2, "isPhysicalMode");
    lua_pushcfunction(L, Character_get_sex);
    lua_setfield(L, -2, "sex");
    lua_pushcfunction(L, Character_get_nameTag);
    lua_setfield(L, -2, "nameTag");
    lua_pushcfunction(L, Character_get_movement);
    lua_setfield(L, -2, "movement");
    lua_pushcfunction(L, Character_get_body);
    lua_setfield(L, -2, "body");
    lua_pushcfunction(L, Character_get_ai);
    lua_setfield(L, -2, "ai");
    lua_pushcfunction(L, Character_get_platoon);
    lua_setfield(L, -2, "platoon");
    lua_pushcfunction(L, Character_get_portraitIndex);
    lua_setfield(L, -2, "portraitIndex");
    lua_pushcfunction(L, Character_get_portraitSerial);
    lua_setfield(L, -2, "portraitSerial");
    lua_pushcfunction(L, Character_get_audioObject);
    lua_setfield(L, -2, "audioObject");
    lua_pushcfunction(L, Character_get_audioData);
    lua_setfield(L, -2, "audioData");
    lua_pushcfunction(L, Character_get_groundType);
    lua_setfield(L, -2, "groundType");
    lua_pushcfunction(L, Character_get_armourType);
    lua_setfield(L, -2, "armourType");
    lua_pushcfunction(L, Character_get_audioEmitter);
    lua_setfield(L, -2, "audioEmitter");
    lua_pushcfunction(L, Character_get_terrainHeightPosition);
    lua_setfield(L, -2, "terrainHeightPosition");
    lua_pushcfunction(L, Character_get_inDoorsSetCooldown);
    lua_setfield(L, -2, "inDoorsSetCooldown");
    lua_pushcfunction(L, Character_get_activeEffects);
    lua_setfield(L, -2, "activeEffects");
    lua_pushcfunction(L, Character_get_particleEffects);
    lua_setfield(L, -2, "particleEffects");
    lua_pushcfunction(L, Character_get_naturalWeapon);
    lua_setfield(L, -2, "naturalWeapon");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, Character_set_offscreenFrameTime);
    lua_setfield(L, -2, "offscreenFrameTime");
    lua_pushcfunction(L, Character_set_frameTIME);
    lua_setfield(L, -2, "frameTIME");
    lua_pushcfunction(L, Character_set_frameTIMEfour);
    lua_setfield(L, -2, "frameTIMEfour");
    lua_pushcfunction(L, Character_set_frameTIME_P);
    lua_setfield(L, -2, "frameTIME_P");
    lua_pushcfunction(L, Character_set_bodyDecayTimer);
    lua_setfield(L, -2, "bodyDecayTimer");
    lua_pushcfunction(L, Character_set_stealthMode);
    lua_setfield(L, -2, "stealthMode");
    lua_pushcfunction(L, Character_set__isOnARoof);
    lua_setfield(L, -2, "_isOnARoof");
    lua_pushcfunction(L, Character_set__lightLevel);
    lua_setfield(L, -2, "_lightLevel");
    lua_pushcfunction(L, Character_set_needsLightLevel);
    lua_setfield(L, -2, "needsLightLevel");
    lua_pushcfunction(L, Character_set__currentProneState);
    lua_setfield(L, -2, "_currentProneState");
    lua_pushcfunction(L, Character_set_isVisibleUpdateMode);
    lua_setfield(L, -2, "isVisibleUpdateMode");
    lua_pushcfunction(L, Character_set_setVisibleMsg);
    lua_setfield(L, -2, "setVisibleMsg");
    lua_pushcfunction(L, Character_set_stealthUnseen);
    lua_setfield(L, -2, "stealthUnseen");
    lua_pushcfunction(L, Character_set_playerWantsMeToGetUp);
    lua_setfield(L, -2, "playerWantsMeToGetUp");
    lua_pushcfunction(L, Character_set_crimes);
    lua_setfield(L, -2, "crimes");
    lua_pushcfunction(L, Character_set_currentSkillUsing);
    lua_setfield(L, -2, "currentSkillUsing");
    lua_pushcfunction(L, Character_set_stateBroadcast);
    lua_setfield(L, -2, "stateBroadcast");
    lua_pushcfunction(L, Character_set_isVisibleAndNear);
    lua_setfield(L, -2, "isVisibleAndNear");
    lua_pushcfunction(L, Character_set_isOnScreen);
    lua_setfield(L, -2, "isOnScreen");
    lua_pushcfunction(L, Character_set_disguiseGUIFeedbacks);
    lua_setfield(L, -2, "disguiseGUIFeedbacks");
    lua_pushcfunction(L, Character_set_whoSeesMeSneaking);
    lua_setfield(L, -2, "whoSeesMeSneaking");
    lua_pushcfunction(L, Character_set_stealthMarkerArrows);
    lua_setfield(L, -2, "stealthMarkerArrows");
    lua_pushcfunction(L, Character_set__isEngagedWithAPlayer);
    lua_setfield(L, -2, "_isEngagedWithAPlayer");
    lua_pushcfunction(L, Character_set_isUsingTurret);
    lua_setfield(L, -2, "isUsingTurret");
    lua_pushcfunction(L, Character_set_isCurrentlyGettingUp);
    lua_setfield(L, -2, "isCurrentlyGettingUp");
    lua_pushcfunction(L, Character_set_isGettingEaten);
    lua_setfield(L, -2, "isGettingEaten");
    lua_pushcfunction(L, Character_set_dialogue);
    lua_setfield(L, -2, "dialogue");
    lua_pushcfunction(L, Character_set_currentStumblePainAnimation);
    lua_setfield(L, -2, "currentStumblePainAnimation");
    lua_pushcfunction(L, Character_set__isLiterallyUnderMeleeAttackRightNowForSure);
    lua_setfield(L, -2, "_isLiterallyUnderMeleeAttackRightNowForSure");
    lua_pushcfunction(L, Character_set__myMemory);
    lua_setfield(L, -2, "_myMemory");
    lua_pushcfunction(L, Character_set_lastGuyWhoDefeatedMe);
    lua_setfield(L, -2, "lastGuyWhoDefeatedMe");
    lua_pushcfunction(L, Character_set_myRace);
    lua_setfield(L, -2, "myRace");
    lua_pushcfunction(L, Character_set_inventory);
    lua_setfield(L, -2, "inventory");
    lua_pushcfunction(L, Character_set_rangedCombat);
    lua_setfield(L, -2, "rangedCombat");
    lua_pushcfunction(L, Character_set_inSomething);
    lua_setfield(L, -2, "inSomething");
    lua_pushcfunction(L, Character_set_inWhat);
    lua_setfield(L, -2, "inWhat");
    lua_pushcfunction(L, Character_set_isChained);
    lua_setfield(L, -2, "isChained");
    lua_pushcfunction(L, Character_set_slaveOwner);
    lua_setfield(L, -2, "slaveOwner");
    lua_pushcfunction(L, Character_set_isCarryingSomething);
    lua_setfield(L, -2, "isCarryingSomething");
    lua_pushcfunction(L, Character_set_carringObjectLeftOrRight);
    lua_setfield(L, -2, "carringObjectLeftOrRight");
    lua_pushcfunction(L, Character_set_isCarryingLeftSide);
    lua_setfield(L, -2, "isCarryingLeftSide");
    lua_pushcfunction(L, Character_set_carryingObject);
    lua_setfield(L, -2, "carryingObject");
    lua_pushcfunction(L, Character_set_messages);
    lua_setfield(L, -2, "messages");
    lua_pushcfunction(L, Character_set_messageSubject);
    lua_setfield(L, -2, "messageSubject");
    lua_pushcfunction(L, Character_set_ragdollNavmeshPosition);
    lua_setfield(L, -2, "ragdollNavmeshPosition");
    lua_pushcfunction(L, Character_set__isBeingCarried);
    lua_setfield(L, -2, "_isBeingCarried");
    lua_pushcfunction(L, Character_set_lastUsedWeaponCategory);
    lua_setfield(L, -2, "lastUsedWeaponCategory");
    lua_pushcfunction(L, Character_set_ragdollMessages);
    lua_setfield(L, -2, "ragdollMessages");
    lua_pushcfunction(L, Character_set_msgCarryMode);
    lua_setfield(L, -2, "msgCarryMode");
    lua_pushcfunction(L, Character_set_squadMemberID);
    lua_setfield(L, -2, "squadMemberID");
    lua_pushcfunction(L, Character_set_diplomacyMultiplier);
    lua_setfield(L, -2, "diplomacyMultiplier");
    lua_pushcfunction(L, Character_set__destinationInsideBuilding);
    lua_setfield(L, -2, "_destinationInsideBuilding");
    lua_pushcfunction(L, Character_set__destinationInsideWalls);
    lua_setfield(L, -2, "_destinationInsideWalls");
    lua_pushcfunction(L, Character_set_animation);
    lua_setfield(L, -2, "animation");
    lua_pushcfunction(L, Character_set_stats);
    lua_setfield(L, -2, "stats");
    lua_pushcfunction(L, Character_set_medical);
    lua_setfield(L, -2, "medical");
    lua_pushcfunction(L, Character_set_isPhysicalMode);
    lua_setfield(L, -2, "isPhysicalMode");
    lua_pushcfunction(L, Character_set_sex);
    lua_setfield(L, -2, "sex");
    lua_pushcfunction(L, Character_set_nameTag);
    lua_setfield(L, -2, "nameTag");
    lua_pushcfunction(L, Character_set_movement);
    lua_setfield(L, -2, "movement");
    lua_pushcfunction(L, Character_set_body);
    lua_setfield(L, -2, "body");
    lua_pushcfunction(L, Character_set_ai);
    lua_setfield(L, -2, "ai");
    lua_pushcfunction(L, Character_set_platoon);
    lua_setfield(L, -2, "platoon");
    lua_pushcfunction(L, Character_set_portraitIndex);
    lua_setfield(L, -2, "portraitIndex");
    lua_pushcfunction(L, Character_set_portraitSerial);
    lua_setfield(L, -2, "portraitSerial");
    lua_pushcfunction(L, Character_set_audioObject);
    lua_setfield(L, -2, "audioObject");
    lua_pushcfunction(L, Character_set_audioData);
    lua_setfield(L, -2, "audioData");
    lua_pushcfunction(L, Character_set_groundType);
    lua_setfield(L, -2, "groundType");
    lua_pushcfunction(L, Character_set_armourType);
    lua_setfield(L, -2, "armourType");
    lua_pushcfunction(L, Character_set_audioEmitter);
    lua_setfield(L, -2, "audioEmitter");
    lua_pushcfunction(L, Character_set_terrainHeightPosition);
    lua_setfield(L, -2, "terrainHeightPosition");
    lua_pushcfunction(L, Character_set_inDoorsSetCooldown);
    lua_setfield(L, -2, "inDoorsSetCooldown");
    lua_pushcfunction(L, Character_set_activeEffects);
    lua_setfield(L, -2, "activeEffects");
    lua_pushcfunction(L, Character_set_particleEffects);
    lua_setfield(L, -2, "particleEffects");
    lua_pushcfunction(L, Character_set_naturalWeapon);
    lua_setfield(L, -2, "naturalWeapon");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua