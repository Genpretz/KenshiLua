#include "pch.h"
#include "kenshi\Character.h"
#include "kenshi/GameSaveState.h"
#include "CharacterBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/AppearanceBaseBinding.h"
#include "Bindings/BountyManagerBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/CharBodyBinding.h"
#include "Bindings/CharMovementBinding.h"
#include "Bindings/CharStatsBinding.h"
#include "Bindings/CharacterAnimalBinding.h"
#include "Bindings/CharacterHumanBinding.h"
#include "Bindings/CombatClassBinding.h"
#include "Bindings/CombatTechniqueDataBinding.h"
#include "Bindings/ContainerItemBinding.h"
#include "Bindings/CrossbowBinding.h"
#include "Bindings/DamagesBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/DialogueBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/GameDataCopyStandaloneBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/Gui/InventoryLayoutBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/LockedArmourBinding.h"
#include "Bindings/MedicalSystemBinding.h"
#include "Bindings/OwnershipsBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/RaceDataBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/RootObjectBaseBinding.h"
#include "Bindings/SensoryDataBinding.h"
#include "Bindings/Building/StorageBuildingBinding.h"
#include "Bindings/SwordBinding.h"
#include "Bindings/TaskerBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/Building/UseableStuffBinding.h"
#include "Bindings/WeaponBinding.h"
#include "Bindings/Util/YesNoMaybeBinding.h"
#include "Bindings/WhoSeesMeBinding.h"
#include "Bindings/AttachedArrowManagerBinding.h"
#include "Bindings/Templates/LektorBinding.h"
#include "Bindings/Templates/OgreUnorderedBinding.h"


namespace KenshiLua
{

static Character* getInstance(lua_State* L, int idx)
{
    return checkObject<Character>(L, idx, CharacterBinding::getMetatableName());
}

// --- Getters for Character ---
static int Character_get_offscreenFrameTime(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushnumber(L, instance->offscreenFrameTime);
    return 1;
}

static int Character_get_frameTIME(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushnumber(L, instance->frameTIME);
    return 1;
}

static int Character_get_frameTIMEfour(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushnumber(L, instance->frameTIMEfour);
    return 1;
}

static int Character_get_frameTIME_P(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushnumber(L, instance->frameTIME_P);
    return 1;
}

static int Character_get_bodyDecayTimer(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushnumber(L, instance->bodyDecayTimer);
    return 1;
}

static int Character_get_stealthMode(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, instance->stealthMode ? 1 : 0);
    return 1;
}

static int Character_get__isOnARoof(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, instance->_isOnARoof ? 1 : 0);
    return 1;
}

static int Character_get__lightLevel(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushnumber(L, instance->_lightLevel);
    return 1;
}

static int Character_get_needsLightLevel(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, instance->needsLightLevel ? 1 : 0);
    return 1;
}

static int Character_get__currentProneState(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, (lua_Integer)instance->_currentProneState);
    return 1;
}

static int Character_get_isVisibleUpdateMode(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, instance->isVisibleUpdateMode ? 1 : 0);
    return 1;
}

static int Character_get_setVisibleMsg(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, instance->setVisibleMsg ? 1 : 0);
    return 1;
}

static int Character_get_stealthUnseen(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    return pushObject<YesNoMaybe>(L, &instance->stealthUnseen, YesNoMaybeBinding::getMetatableName());
}

static int Character_get_playerWantsMeToGetUp(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, instance->playerWantsMeToGetUp ? 1 : 0);
    return 1;
}

static int Character_get_crimes(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    return pushObject<BountyManager>(L, &instance->crimes, BountyManagerBinding::getMetatableName());
}

static int Character_get_currentSkillUsing(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, (lua_Integer)instance->currentSkillUsing);
    return 1;
}

static int Character_get_stateBroadcast(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushlightuserdata(L, (void*)instance->stateBroadcast);
    return 1;
}

static int Character_get_isVisibleAndNear(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, instance->isVisibleAndNear ? 1 : 0);
    return 1;
}

static int Character_get_isOnScreen(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, instance->isOnScreen ? 1 : 0);
    return 1;
}

static int Character_get_stealthMarkerArrows(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    return pushObject<Character::AttachedArrowManager>(L, &instance->stealthMarkerArrows, AttachedArrowManagerBinding::getMetatableName());
}

static int Character_get__isEngagedWithAPlayer(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, instance->_isEngagedWithAPlayer ? 1 : 0);
    return 1;
}

static int Character_get_isUsingTurret(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    return handBinding::push(L, instance->isUsingTurret);
}

static int Character_get_isCurrentlyGettingUp(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, instance->isCurrentlyGettingUp ? 1 : 0);
    return 1;
}

static int Character_get_isGettingEaten(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, instance->isGettingEaten);
    return 1;
}

static int Character_get_dialogue(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    return pushObject<Dialogue>(L, instance->dialogue, DialogueBinding::getMetatableName());
}

static int Character_get_currentStumblePainAnimation(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushstring(L, instance->currentStumblePainAnimation.c_str());
    return 1;
}

static int Character_get__isLiterallyUnderMeleeAttackRightNowForSure(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, instance->_isLiterallyUnderMeleeAttackRightNowForSure ? 1 : 0);
    return 1;
}

static int Character_get__myMemory(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushlightuserdata(L, (void*)instance->_myMemory);
    return 1;
}

static int Character_get_lastGuyWhoDefeatedMe(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    return handBinding::push(L, instance->lastGuyWhoDefeatedMe);
}

static int Character_get_myRace(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    return pushObject<RaceData>(L, instance->myRace, RaceDataBinding::getMetatableName());
}

static int Character_get_inventory(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    return pushObject<Inventory>(L, instance->inventory, InventoryBinding::getMetatableName());
}

static int Character_get_rangedCombat(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushlightuserdata(L, (void*)instance->rangedCombat);
    return 1;
}

static int Character_get_inWhat(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    return handBinding::push(L, instance->inWhat);
}

static int Character_get_isChained(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, instance->isChained ? 1 : 0);
    return 1;
}

static int Character_get_slaveOwner(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    return handBinding::push(L, instance->slaveOwner);
}

static int Character_get_isCarryingSomething(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, instance->isCarryingSomething ? 1 : 0);
    return 1;
}

static int Character_get_carringObjectLeftOrRight(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushstring(L, instance->carringObjectLeftOrRight.c_str());
    return 1;
}

static int Character_get_isCarryingLeftSide(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, instance->isCarryingLeftSide ? 1 : 0);
    return 1;
}

static int Character_get_carryingObject(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    return handBinding::push(L, instance->carryingObject);
}

static int Character_get_messages(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, (lua_Integer)instance->messages);
    return 1;
}

static int Character_get_messageSubject(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    return handBinding::push(L, instance->messageSubject);
}

static int Character_get_ragdollNavmeshPosition(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    pushVector3(L, instance->ragdollNavmeshPosition);
    return 1;
}

static int Character_get__isBeingCarried(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, instance->_isBeingCarried ? 1 : 0);
    return 1;
}

static int Character_get_lastUsedWeaponCategory(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, (lua_Integer)instance->lastUsedWeaponCategory);
    return 1;
}

static int Character_get_msgCarryMode(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushlightuserdata(L, (void*)instance->msgCarryMode);
    return 1;
}

static int Character_get_squadMemberID(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, instance->squadMemberID);
    return 1;
}

static int Character_get_diplomacyMultiplier(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushnumber(L, instance->diplomacyMultiplier);
    return 1;
}

static int Character_get__destinationInsideBuilding(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    return handBinding::push(L, instance->_destinationInsideBuilding);
}

static int Character_get__destinationInsideWalls(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, instance->_destinationInsideWalls);
    return 1;
}

static int Character_get_animation(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushlightuserdata(L, (void*)instance->animation);
    return 1;
}

static int Character_get_stats(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    return pushObject<CharStats>(L, instance->stats, CharStatsBinding::getMetatableName());
}

static int Character_get_medical(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    return pushObject<MedicalSystem>(L, &instance->medical, MedicalSystemBinding::getMetatableName());
}

static int Character_get_isPhysicalMode(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushboolean(L, instance->isPhysicalMode ? 1 : 0);
    return 1;
}

static int Character_get_sex(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushstring(L, instance->sex.c_str());
    return 1;
}

static int Character_get_nameTag(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushlightuserdata(L, (void*)instance->nameTag);
    return 1;
}

static int Character_get_movement(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    return pushObject<CharMovement>(L, instance->movement, CharMovementBinding::getMetatableName());
}

static int Character_get_body(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    return pushObject<CharBody>(L, instance->body, CharBodyBinding::getMetatableName());
}

static int Character_get_ai(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushlightuserdata(L, (void*)instance->ai);
    return 1;
}

static int Character_get_platoon(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    return pushObject<ActivePlatoon>(L, instance->platoon, ActivePlatoonBinding::getMetatableName());
}

static int Character_get_portraitIndex(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, instance->portraitIndex);
    return 1;
}

static int Character_get_portraitSerial(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, instance->portraitSerial);
    return 1;
}

static int Character_get_groundType(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, (lua_Integer)instance->groundType);
    return 1;
}

static int Character_get_armourType(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, (lua_Integer)instance->armourType);
    return 1;
}

static int Character_get_audioEmitter(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushlightuserdata(L, (void*)instance->audioEmitter);
    return 1;
}

static int Character_get_terrainHeightPosition(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushnumber(L, instance->terrainHeightPosition);
    return 1;
}

static int Character_get_inDoorsSetCooldown(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, instance->inDoorsSetCooldown);
    return 1;
}

static int Character_get_naturalWeapon(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    return pushObject<Sword>(L, instance->naturalWeapon, SwordBinding::getMetatableName());
}

// --- Setters for Character ---
static int Character_set_offscreenFrameTime(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->offscreenFrameTime = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Character_set_frameTIME(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->frameTIME = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Character_set_frameTIMEfour(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->frameTIMEfour = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Character_set_frameTIME_P(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->frameTIME_P = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Character_set_bodyDecayTimer(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->bodyDecayTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Character_set_stealthMode(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->stealthMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set__isOnARoof(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->_isOnARoof = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set__lightLevel(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->_lightLevel = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Character_set_needsLightLevel(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->needsLightLevel = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set__currentProneState(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->_currentProneState = (ProneState)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_isVisibleUpdateMode(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->isVisibleUpdateMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_setVisibleMsg(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->setVisibleMsg = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_stealthUnseen(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->stealthUnseen = *checkObject<YesNoMaybe>(L, 2, YesNoMaybeBinding::getMetatableName());
    return 0;
}

static int Character_set_playerWantsMeToGetUp(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->playerWantsMeToGetUp = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_crimes(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->crimes = *checkObject<BountyManager>(L, 2, BountyManagerBinding::getMetatableName());
    return 0;
}

static int Character_set_currentSkillUsing(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->currentSkillUsing = (StatsEnumerated)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_isVisibleAndNear(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->isVisibleAndNear = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_isOnScreen(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->isOnScreen = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_stealthMarkerArrows(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    return luaL_error(L, "Read-only property 'stealthMarkerArrows'");
}

static int Character_set__isEngagedWithAPlayer(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->_isEngagedWithAPlayer = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_isUsingTurret(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->isUsingTurret = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int Character_set_isCurrentlyGettingUp(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->isCurrentlyGettingUp = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_isGettingEaten(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->isGettingEaten = (unsigned char)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_dialogue(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->dialogue = lua_isnoneornil(L, 2) ? nullptr : checkObject<Dialogue>(L, 2, DialogueBinding::getMetatableName());
    return 0;
}

static int Character_set_currentStumblePainAnimation(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->currentStumblePainAnimation = luaL_checkstring(L, 2);
    return 0;
}

static int Character_set__isLiterallyUnderMeleeAttackRightNowForSure(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->_isLiterallyUnderMeleeAttackRightNowForSure = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_lastGuyWhoDefeatedMe(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->lastGuyWhoDefeatedMe = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int Character_set_myRace(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->myRace = lua_isnoneornil(L, 2) ? nullptr : checkObject<RaceData>(L, 2, RaceDataBinding::getMetatableName());
    return 0;
}

static int Character_set_inventory(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->inventory = lua_isnoneornil(L, 2) ? nullptr : checkObject<Inventory>(L, 2, InventoryBinding::getMetatableName());
    return 0;
}

static int Character_set_inWhat(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->inWhat = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int Character_set_isChained(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->isChained = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_slaveOwner(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->slaveOwner = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int Character_set_isCarryingSomething(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->isCarryingSomething = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_carringObjectLeftOrRight(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->carringObjectLeftOrRight = luaL_checkstring(L, 2);
    return 0;
}

static int Character_set_isCarryingLeftSide(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->isCarryingLeftSide = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_carryingObject(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->carryingObject = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int Character_set_messages(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->messages = (Character::CharMessage)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_messageSubject(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->messageSubject = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int Character_set_ragdollNavmeshPosition(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    readVector3(L, 2, instance->ragdollNavmeshPosition);
    return 0;
}

static int Character_set__isBeingCarried(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->_isBeingCarried = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_lastUsedWeaponCategory(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->lastUsedWeaponCategory = (WeaponCategory)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_squadMemberID(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->squadMemberID = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_diplomacyMultiplier(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->diplomacyMultiplier = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Character_set__destinationInsideBuilding(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->_destinationInsideBuilding = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int Character_set__destinationInsideWalls(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->_destinationInsideWalls = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_stats(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->stats = lua_isnoneornil(L, 2) ? nullptr : checkObject<CharStats>(L, 2, CharStatsBinding::getMetatableName());
    return 0;
}

static int Character_set_medical(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->medical = *checkObject<MedicalSystem>(L, 2, MedicalSystemBinding::getMetatableName());
    return 0;
}

static int Character_set_isPhysicalMode(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->isPhysicalMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Character_set_sex(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->sex = luaL_checkstring(L, 2);
    return 0;
}

static int Character_set_movement(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->movement = lua_isnoneornil(L, 2) ? nullptr : checkObject<CharMovement>(L, 2, CharMovementBinding::getMetatableName());
    return 0;
}

static int Character_set_body(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->body = lua_isnoneornil(L, 2) ? nullptr : checkObject<CharBody>(L, 2, CharBodyBinding::getMetatableName());
    return 0;
}

static int Character_set_platoon(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->platoon = lua_isnoneornil(L, 2) ? nullptr : checkObject<ActivePlatoon>(L, 2, ActivePlatoonBinding::getMetatableName());
    return 0;
}

static int Character_set_portraitIndex(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->portraitIndex = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_portraitSerial(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->portraitSerial = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_groundType(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->groundType = (GroundType)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_armourType(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->armourType = (ArmourType)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_terrainHeightPosition(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->terrainHeightPosition = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Character_set_inDoorsSetCooldown(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->inDoorsSetCooldown = (char)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_naturalWeapon(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->naturalWeapon = lua_isnoneornil(L, 2) ? nullptr : checkObject<Sword>(L, 2, SwordBinding::getMetatableName());
    return 0;
}

int CharacterBinding::isImmuneToOffscreenMode(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isImmuneToOffscreenMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::init(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->init();
    return 0;
}

int CharacterBinding::_NV_init(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->_NV_init();
    return 0;
}

int CharacterBinding::_DESTRUCTOR(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int CharacterBinding::isOnARoof(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isOnARoof();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isOnARoof(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->_NV_isOnARoof();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isOnAWall(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isOnAWall();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isOnAWall(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->_NV_isOnAWall();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getLightLevel(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->getLightLevel();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::getHPMultiplier(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->getHPMultiplier();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::_NV_getHPMultiplier(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->_NV_getHPMultiplier();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::healCompletely(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->healCompletely();
    return 0;
}

int CharacterBinding::resetRagdollNavmeshSafePos(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->resetRagdollNavmeshSafePos();
    return 0;
}

int CharacterBinding::setRagdollNavmeshSafePos(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->setRagdollNavmeshSafePos();
    return 0;
}

int CharacterBinding::getFrameTime(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->getFrameTime();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::frameSkip(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->frameSkip();
    return 0;
}

int CharacterBinding::getCurrentNoiseRange(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->getCurrentNoiseRange();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::isDestroyed(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isDestroyed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isDestroyed(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->_NV_isDestroyed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isLawEnforcement(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isLawEnforcement();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::canAssignBounties(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->canAssignBounties();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getDataType(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    itemType result = instance->getDataType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::_NV_getDataType(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    itemType result = instance->_NV_getDataType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::isDiplomaticStatus(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool factorInBiome = lua_toboolean(L, 2) != 0;
    bool result = instance->isDiplomaticStatus(factorInBiome);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isLeadingAWarCampaign(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isLeadingAWarCampaign();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isInAWarCampaign(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    CampaignInstance* result = instance->isInAWarCampaign();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int CharacterBinding::wantsToTriggerCampaigns(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->wantsToTriggerCampaigns();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isUnique(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isUnique();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::canSpeakNormally(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->canSpeakNormally();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isAnimal(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    CharacterAnimal* result = instance->isAnimal();
    return pushObject<CharacterAnimal>(L, result, CharacterAnimalBinding::getMetatableName());
}

int CharacterBinding::_NV_isAnimal(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    CharacterAnimal* result = instance->_NV_isAnimal();
    return pushObject<CharacterAnimal>(L, result, CharacterAnimalBinding::getMetatableName());
}

int CharacterBinding::isHuman(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    CharacterHuman* result = instance->isHuman();
    return pushObject<CharacterHuman>(L, result, CharacterHumanBinding::getMetatableName());
}

int CharacterBinding::_NV_isHuman(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    CharacterHuman* result = instance->_NV_isHuman();
    return pushObject<CharacterHuman>(L, result, CharacterHumanBinding::getMetatableName());
}

int CharacterBinding::takeMoney(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    int n = (int)luaL_checkinteger(L, 2);
    bool result = instance->takeMoney(n);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_takeMoney(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    int n = (int)luaL_checkinteger(L, 2);
    bool result = instance->_NV_takeMoney(n);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getMoney(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    int result = instance->getMoney();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterBinding::_NV_getMoney(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    int result = instance->_NV_getMoney();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterBinding::setSquadMemberType(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    SquadMemberType memType = (SquadMemberType)luaL_checkinteger(L, 2);
    instance->setSquadMemberType(memType);
    return 0;
}

int CharacterBinding::isResident(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    TownBase* result = instance->isResident();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int CharacterBinding::dailyUpdate(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->dailyUpdate();
    return 0;
}

int CharacterBinding::updateOnScreenCheck(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->updateOnScreenCheck();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::offscreenUpdate(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->offscreenUpdate();
    return 0;
}

int CharacterBinding::updateTimes(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->updateTimes();
    return 0;
}

int CharacterBinding::getSensoryData(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    SensoryData* result = instance->getSensoryData();
    return pushObject<SensoryData>(L, result, SensoryDataBinding::getMetatableName());
}

int CharacterBinding::_NV_getSensoryData(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    SensoryData* result = instance->_NV_getSensoryData();
    return pushObject<SensoryData>(L, result, SensoryDataBinding::getMetatableName());
}

int CharacterBinding::getStateBroadcast(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    StateBroadcastData* result = instance->getStateBroadcast();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int CharacterBinding::_NV_getStateBroadcast(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    StateBroadcastData* result = instance->_NV_getStateBroadcast();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int CharacterBinding::getFormation(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Formation* result = instance->getFormation();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int CharacterBinding::_NV_getFormation(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Formation* result = instance->_NV_getFormation();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int CharacterBinding::getEnemyFormation(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Formation* result = instance->getEnemyFormation();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int CharacterBinding::_NV_getEnemyFormation(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Formation* result = instance->_NV_getEnemyFormation();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int CharacterBinding::AIDestinationIndoorOutdoorCheck(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    RootObject* who = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = instance->AIDestinationIndoorOutdoorCheck(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::update(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->update();
    return 0;
}

int CharacterBinding::_NV_update(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->_NV_update();
    return 0;
}

int CharacterBinding::postUpdate(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->postUpdate();
    return 0;
}

int CharacterBinding::_NV_postUpdate(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->_NV_postUpdate();
    return 0;
}

int CharacterBinding::ragdollUpdatesUT(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->ragdollUpdatesUT();
    return 0;
}

int CharacterBinding::fourFrameUpdate(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->fourFrameUpdate();
    return 0;
}

int CharacterBinding::periodicUpdate(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->periodicUpdate();
    return 0;
}

int CharacterBinding::_NV_periodicUpdate(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->_NV_periodicUpdate();
    return 0;
}

int CharacterBinding::pausedUpdate(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->pausedUpdate();
    return 0;
}

int CharacterBinding::_NV_pausedUpdate(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->_NV_pausedUpdate();
    return 0;
}

int CharacterBinding::updateUT(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->updateUT();
    return 0;
}

int CharacterBinding::threadedUpdate(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->threadedUpdate();
    return 0;
}

int CharacterBinding::_NV_threadedUpdate(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->_NV_threadedUpdate();
    return 0;
}

int CharacterBinding::threadedUpdate4(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->threadedUpdate4();
    return 0;
}

int CharacterBinding::_NV_threadedUpdate4(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->_NV_threadedUpdate4();
    return 0;
}

int CharacterBinding::threadedUpdatePeriodic(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->threadedUpdatePeriodic();
    return 0;
}

int CharacterBinding::_NV_threadedUpdatePeriodic(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->_NV_threadedUpdatePeriodic();
    return 0;
}

int CharacterBinding::pathExists(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Ogre::Vector3 v;
    readVector3(L, 2, v);
    bool result = instance->pathExists(v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::weatherUpdate(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float _a1 = (float)luaL_checknumber(L, 2);
    instance->weatherUpdate(_a1);
    return 0;
}

int CharacterBinding::_NV_weatherUpdate(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float _a1 = (float)luaL_checknumber(L, 2);
    instance->_NV_weatherUpdate(_a1);
    return 0;
}

int CharacterBinding::stealthUpdate(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float _time = (float)luaL_checknumber(L, 2);
    instance->stealthUpdate(_time);
    return 0;
}

int CharacterBinding::lineOfSightCheck(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float result = instance->lineOfSightCheck(who);
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::getPerceptionMult(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->getPerceptionMult();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::isWithThePlayer(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isWithThePlayer();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::notifyICanSeeYouSneaking(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    YesNoMaybe seeing = *checkObject<YesNoMaybe>(L, 3, YesNoMaybeBinding::getMetatableName());
    float maybeProgress01 = (float)luaL_checknumber(L, 4);
    instance->notifyICanSeeYouSneaking(who, seeing, maybeProgress01);
    return 0;
}

int CharacterBinding::isItSafeToGetUp(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isItSafeToGetUp();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::separateIntoMyOwnSquad(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool permanent = lua_toboolean(L, 2) != 0;
    Platoon* result = instance->separateIntoMyOwnSquad(permanent);
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

int CharacterBinding::dropGearOnDeath(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool vampiricDeath = lua_toboolean(L, 2) != 0;
    instance->dropGearOnDeath(vampiricDeath);
    return 0;
}

int CharacterBinding::isItOkForMeToLoot(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    RootObject* _victim = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    bool result = instance->isItOkForMeToLoot(_victim, item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isItOkForMeToLoot(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    RootObject* _victim = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    bool result = instance->_NV_isItOkForMeToLoot(_victim, item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::ImStealingDoYouNotice(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    RootObject* stealFrom = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    bool result = instance->ImStealingDoYouNotice(stealFrom, item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_ImStealingDoYouNotice(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    RootObject* stealFrom = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    bool result = instance->_NV_ImStealingDoYouNotice(stealFrom, item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getFencingSuccessChance(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    RootObject* thief = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    float result = instance->getFencingSuccessChance(item, thief);
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::stolenGoodsDetectionCheck(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    RootObject* thief = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    bool result = instance->stolenGoodsDetectionCheck(item, thief);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_stolenGoodsDetectionCheck(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    RootObject* thief = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    bool result = instance->_NV_stolenGoodsDetectionCheck(item, thief);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::sellingUniformDetectionCheck(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    Character* thief = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    bool result = instance->sellingUniformDetectionCheck(item, thief);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_sellingUniformDetectionCheck(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    Character* thief = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    bool result = instance->_NV_sellingUniformDetectionCheck(item, thief);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::smugglingTradeCheck(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    Character* who = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    YesNoMaybe result = instance->smugglingTradeCheck(item, who);
    return pushObject<YesNoMaybe>(L, &result, YesNoMaybeBinding::getMetatableName());
}

int CharacterBinding::_NV_smugglingTradeCheck(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    Character* who = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    YesNoMaybe result = instance->_NV_smugglingTradeCheck(item, who);
    return pushObject<YesNoMaybe>(L, &result, YesNoMaybeBinding::getMetatableName());
}

int CharacterBinding::getStealingSuccessChance(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    RootObject* stealFrom = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    Character* victimOut = nullptr;
    float chance = instance->getStealingSuccessChance(stealFrom, item, &victimOut);
    lua_pushnumber(L, (lua_Number)chance);
    if (victimOut)
        pushObject<Character>(L, victimOut, CharacterBinding::getMetatableName());
    else
        lua_pushnil(L);
    return 2;
}

int CharacterBinding::getCurrentWeatherAffectStatus(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    WeatherAffecting result = instance->getCurrentWeatherAffectStatus();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::getCurrentWeatherAffectStrength(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->getCurrentWeatherAffectStrength();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::getWaterLevel(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    WaterState::Enum result = instance->getWaterLevel();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::setTerrainHeightPosition(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float height = (float)luaL_checknumber(L, 2);
    instance->setTerrainHeightPosition(height);
    return 0;
}

int CharacterBinding::getTerrainHeightPosition(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->getTerrainHeightPosition();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::setDisguiseMessage(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character::DisguiseGUIFeedback msg = (Character::DisguiseGUIFeedback)luaL_checkinteger(L, 2);
    instance->setDisguiseMessage(msg);
    return 0;
}

int CharacterBinding::uniqueStateUpdate(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->uniqueStateUpdate();
    return 0;
}

int CharacterBinding::foodUpdate(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->foodUpdate();
    return 0;
}

int CharacterBinding::_NV_foodUpdate(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->_NV_foodUpdate();
    return 0;
}

int CharacterBinding::eatItem(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Item* food = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    Inventory* from = checkObject<Inventory>(L, 3, InventoryBinding::getMetatableName());
    bool result = instance->eatItem(food, from);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::loadFromSerialise(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->loadFromSerialise(state);
    return 0;
}

int CharacterBinding::_NV_loadFromSerialise(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->_NV_loadFromSerialise(state);
    return 0;
}

int CharacterBinding::loadFromSerialisePostCreationStage(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    GameSaveState* gd = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->loadFromSerialisePostCreationStage(gd);
    return 0;
}

int CharacterBinding::_NV_loadFromSerialisePostCreationStage(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    GameSaveState* gd = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->_NV_loadFromSerialisePostCreationStage(gd);
    return 0;
}

int CharacterBinding::setupInventorySections(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    bool result = instance->setupInventorySections(state);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_setupInventorySections(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    bool result = instance->_NV_setupInventorySections(state);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getPosition(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Ogre::Vector3 result = instance->getPosition();
    pushVector3(L, result);
    return 1;
}

int CharacterBinding::_NV_getPosition(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Ogre::Vector3 result = instance->_NV_getPosition();
    pushVector3(L, result);
    return 1;
}

int CharacterBinding::_getRawPosition(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Ogre::Vector3 result = instance->_getRawPosition();
    pushVector3(L, result);
    return 1;
}

int CharacterBinding::getRawEntityPosition(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Ogre::Vector3 result = instance->getRawEntityPosition();
    pushVector3(L, result);
    return 1;
}

int CharacterBinding::getMovementSpeed(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->getMovementSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::_NV_getMovementSpeed(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->_NV_getMovementSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::getMovementSpeedOrders(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    MoveSpeed result = instance->getMovementSpeedOrders();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::_NV_getMovementSpeedOrders(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    MoveSpeed result = instance->_NV_getMovementSpeedOrders();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::getMovementDirection(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Ogre::Vector3 result = instance->getMovementDirection();
    pushVector3(L, result);
    return 1;
}

int CharacterBinding::_NV_getMovementDirection(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Ogre::Vector3 result = instance->_NV_getMovementDirection();
    pushVector3(L, result);
    return 1;
}

int CharacterBinding::isPhysical(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isPhysical(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->_NV_isPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::setVisible(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setVisible(on);
    return 0;
}

int CharacterBinding::_NV_setVisible(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_setVisible(on);
    return 0;
}

int CharacterBinding::getVisible(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_getVisible(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->_NV_getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::switchLights(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->switchLights(on);
    return 0;
}

int CharacterBinding::isDisabled(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isDisabled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isDisabled(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->_NV_isDisabled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::setInsideTownWalls(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    int s = (int)luaL_checkinteger(L, 2);
    instance->setInsideTownWalls(s);
    return 0;
}

int CharacterBinding::_NV_setInsideTownWalls(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    int s = (int)luaL_checkinteger(L, 2);
    instance->_NV_setInsideTownWalls(s);
    return 0;
}

int CharacterBinding::sheatheWeapon(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->sheatheWeapon();
    return 0;
}

int CharacterBinding::_NV_sheatheWeapon(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->_NV_sheatheWeapon();
    return 0;
}

int CharacterBinding::select(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->select();
    return 0;
}

int CharacterBinding::_NV_select(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->_NV_select();
    return 0;
}

int CharacterBinding::unselect(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->unselect();
    return 0;
}

int CharacterBinding::_NV_unselect(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->_NV_unselect();
    return 0;
}

int CharacterBinding::getGUIData(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIData(datapanel, category);
    return 0;
}

int CharacterBinding::_NV_getGUIData(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIData(datapanel, category);
    return 0;
}

int CharacterBinding::getCurrentTownLocation(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    TownBase* result = instance->getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int CharacterBinding::_NV_getCurrentTownLocation(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    TownBase* result = instance->_NV_getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int CharacterBinding::say_WithARepeatLimiter(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    const std::string s = luaL_checkstring(L, 2);
    instance->say_WithARepeatLimiter(s);
    return 0;
}

int CharacterBinding::_NV_say_WithARepeatLimiter(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    const std::string s = luaL_checkstring(L, 2);
    instance->_NV_say_WithARepeatLimiter(s);
    return 0;
}

int CharacterBinding::say(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    const std::string s = luaL_checkstring(L, 2);
    instance->say(s);
    return 0;
}

int CharacterBinding::_NV_say(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    const std::string s = luaL_checkstring(L, 2);
    instance->_NV_say(s);
    return 0;
}

int CharacterBinding::isInventoryVisible(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isInventoryVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isInventoryVisible(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->_NV_isInventoryVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::giveItem(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool dropOnFail = lua_toboolean(L, 3) != 0;
    bool destroyOnFail = lua_toboolean(L, 4) != 0;
    bool result = instance->giveItem(item, dropOnFail, destroyOnFail);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_giveItem(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool dropOnFail = lua_toboolean(L, 3) != 0;
    bool destroyOnFail = lua_toboolean(L, 4) != 0;
    bool result = instance->_NV_giveItem(item, dropOnFail, destroyOnFail);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::hasRoomForItem(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->hasRoomForItem(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_hasRoomForItem(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->_NV_hasRoomForItem(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::hasItem(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->hasItem(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_hasItem(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->_NV_hasItem(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::hasAmmoFor(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Crossbow* c = checkObject<Crossbow>(L, 2, CrossbowBinding::getMetatableName());
    bool result = instance->hasAmmoFor(c);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_hasAmmoFor(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Crossbow* c = checkObject<Crossbow>(L, 2, CrossbowBinding::getMetatableName());
    bool result = instance->_NV_hasAmmoFor(c);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getNumFoodItems(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    int result = instance->getNumFoodItems();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterBinding::_NV_getNumFoodItems(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    int result = instance->_NV_getNumFoodItems();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterBinding::hasSimilarItem(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    itemType ty = (itemType)luaL_checkinteger(L, 2);
    bool result = instance->hasSimilarItem(ty);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_hasSimilarItem(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    itemType ty = (itemType)luaL_checkinteger(L, 2);
    bool result = instance->_NV_hasSimilarItem(ty);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::ifImASmithShouldIDitchMyBackWeapon(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->ifImASmithShouldIDitchMyBackWeapon();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getInventory(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Inventory* result = instance->getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int CharacterBinding::_NV_getInventory(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Inventory* result = instance->_NV_getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int CharacterBinding::hasABackpackOn(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    ContainerItem* result = instance->hasABackpackOn();
    return pushObject<ContainerItem>(L, result, ContainerItemBinding::getMetatableName());
}

int CharacterBinding::isATrader(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isATrader();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isFemale(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isFemale();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isFleeing(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isFleeing();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::createInventoryLayout(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    InventoryLayout* result = instance->createInventoryLayout();
    return pushObject<InventoryLayout>(L, result, InventoryLayoutBinding::getMetatableName());
}

int CharacterBinding::_NV_createInventoryLayout(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    InventoryLayout* result = instance->_NV_createInventoryLayout();
    return pushObject<InventoryLayout>(L, result, InventoryLayoutBinding::getMetatableName());
}

int CharacterBinding::getStealthKOChance(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* victim = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool factors = lua_toboolean(L, 3) != 0;
    float result = instance->getStealthKOChance(victim, factors);
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::getKidnappingChance(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* victim = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float result = instance->getKidnappingChance(victim);
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::getKidnappingEscapeChance_skill(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* captor = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float result = instance->getKidnappingEscapeChance_skill(captor);
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::getKidnappingEscapeChance_strength(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* captor = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float result = instance->getKidnappingEscapeChance_strength(captor);
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::shouldIHelpThisGuy(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->shouldIHelpThisGuy(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::shouldIScrewThisGuyOver(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->shouldIScrewThisGuyOver(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::ILoveThisGuyBecauseOfStuffThatHappened(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->ILoveThisGuyBecauseOfStuffThatHappened(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::IHateThisGuyBecauseOfStuffThatHappened(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->IHateThisGuyBecauseOfStuffThatHappened(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getRoughLevel(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    int result = instance->getRoughLevel();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterBinding::setStandingOrder(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    MessageForB::StandingOrder orderID = (MessageForB::StandingOrder)luaL_checkinteger(L, 2);
    bool on = lua_toboolean(L, 3) != 0;
    instance->setStandingOrder(orderID, on);
    return 0;
}

int CharacterBinding::_NV_setStandingOrder(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    MessageForB::StandingOrder orderID = (MessageForB::StandingOrder)luaL_checkinteger(L, 2);
    bool on = lua_toboolean(L, 3) != 0;
    instance->_NV_setStandingOrder(orderID, on);
    return 0;
}

int CharacterBinding::getStandingOrder(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    MessageForB::StandingOrder orderID = (MessageForB::StandingOrder)luaL_checkinteger(L, 2);
    bool result = instance->getStandingOrder(orderID);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::setStealthMode(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setStealthMode(on);
    return 0;
}

int CharacterBinding::isStealthMode(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isStealthMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isStealthModeOrCrawling(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isStealthModeOrCrawling();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::declareDead(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->declareDead();
    return 0;
}

int CharacterBinding::updateGUIStatsDetails(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    const std::string name = luaL_checkstring(L, 3);
    int statId = (int)luaL_checkinteger(L, 4);
    instance->updateGUIStatsDetails(datapanel, name, statId);
    return 0;
}

int CharacterBinding::_printRaceXPBonusLine(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    DatapanelGUI* panel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    StatsEnumerated s = (StatsEnumerated)luaL_checkinteger(L, 3);
    instance->_printRaceXPBonusLine(panel, s);
    return 0;
}

int CharacterBinding::addGoal(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    TaskType t = (TaskType)luaL_checkinteger(L, 2);
    RootObjectBase* subject = checkObject<RootObjectBase>(L, 3, RootObjectBaseBinding::getMetatableName());
    instance->addGoal(t, subject);
    return 0;
}

int CharacterBinding::addJob(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    TaskType t = (TaskType)luaL_checkinteger(L, 2);
    RootObject* subject = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    bool shift = lua_toboolean(L, 4) != 0;
    bool addDontClear = lua_toboolean(L, 5) != 0;
    Ogre::Vector3 location;
    readVector3(L, 6, location);
    instance->addJob(t, subject, shift, addDontClear, location);
    return 0;
}

int CharacterBinding::removeJob(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    TaskType t = (TaskType)luaL_checkinteger(L, 2);
    instance->removeJob(t);
    return 0;
}

int CharacterBinding::removePermajob(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    int t = (int)luaL_checkinteger(L, 2);
    instance->removePermajob(t);
    return 0;
}

int CharacterBinding::clearPermajobs(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->clearPermajobs();
    return 0;
}

int CharacterBinding::movePermajob(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    int taskIdx = (int)luaL_checkinteger(L, 2);
    int targetIdx = (int)luaL_checkinteger(L, 3);
    instance->movePermajob(taskIdx, targetIdx);
    return 0;
}

int CharacterBinding::getPermajob(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    int slot = (int)luaL_checkinteger(L, 2);
    TaskType result = instance->getPermajob(slot);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::getPermajobData(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    int slot = (int)luaL_checkinteger(L, 2);
    const Tasker* result = instance->getPermajobData(slot);
    return pushObject<Tasker>(L, const_cast<Tasker*>(result), TaskerBinding::getMetatableName());
}

int CharacterBinding::getPermajobCount(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    int result = instance->getPermajobCount();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterBinding::addOrder(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Building* dest = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    TaskType t = (TaskType)luaL_checkinteger(L, 3);
    RootObject* subject = checkObject<RootObject>(L, 4, RootObjectBinding::getMetatableName());
    bool shift = lua_toboolean(L, 5) != 0;
    bool clear = lua_toboolean(L, 6) != 0;
    Ogre::Vector3 location;
    readVector3(L, 7, location);
    instance->addOrder(dest, t, subject, shift, clear, location);
    return 0;
}

int CharacterBinding::updateLastTask(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Building* dest = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    TaskType t = (TaskType)luaL_checkinteger(L, 3);
    RootObject* subject = checkObject<RootObject>(L, 4, RootObjectBinding::getMetatableName());
    Ogre::Vector3 location;
    readVector3(L, 5, location);
    instance->updateLastTask(dest, t, subject, location);
    return 0;
}

int CharacterBinding::_NV_updateLastTask(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Building* dest = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    TaskType t = (TaskType)luaL_checkinteger(L, 3);
    RootObject* subject = checkObject<RootObject>(L, 4, RootObjectBinding::getMetatableName());
    Ogre::Vector3 location;
    readVector3(L, 5, location);
    instance->_NV_updateLastTask(dest, t, subject, location);
    return 0;
}

int CharacterBinding::playerMoveOrderDefault(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Building* dest = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    RootObject* subject = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    Ogre::Vector3 location;
    readVector3(L, 4, location);
    instance->playerMoveOrderDefault(dest, subject, location);
    return 0;
}

int CharacterBinding::_NV_playerMoveOrderDefault(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Building* dest = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    RootObject* subject = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    Ogre::Vector3 location;
    readVector3(L, 4, location);
    instance->_NV_playerMoveOrderDefault(dest, subject, location);
    return 0;
}

int CharacterBinding::endCombatMode(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->endCombatMode();
    return 0;
}

int CharacterBinding::getTotalRelativeStrengthOfAttackers(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->getTotalRelativeStrengthOfAttackers();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::_NV_getTotalRelativeStrengthOfAttackers(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->_NV_getTotalRelativeStrengthOfAttackers();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::canGoIndoors(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Building* b = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    bool result = instance->canGoIndoors(b);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_canGoIndoors(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Building* b = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    bool result = instance->_NV_canGoIndoors(b);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isIndoorsRagdoll(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isIndoorsRagdoll();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isIndoorsRagdoll(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->_NV_isIndoorsRagdoll();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::destinationIndoors(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    RootObject* r = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    hand result = instance->destinationIndoors(r);
    return handBinding::push(L, result);
}

int CharacterBinding::destinationInsideWalls(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    RootObject* r = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    int result = instance->destinationInsideWalls(r);
    lua_pushinteger(L, result);
    return 1;
}

int CharacterBinding::getIntendedAggression(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->getIntendedAggression();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::_NV_getIntendedAggression(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->_NV_getIntendedAggression();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::getPositionBip01(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Ogre::Vector3 result = instance->getPositionBip01();
    pushVector3(L, result);
    return 1;
}

int CharacterBinding::amInsideTownWalls(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    int result = instance->amInsideTownWalls();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterBinding::_NV_amInsideTownWalls(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    int result = instance->_NV_amInsideTownWalls();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterBinding::setName(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    const std::string name = luaL_checkstring(L, 2);
    instance->setName(name);
    return 0;
}

int CharacterBinding::_NV_setName(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    const std::string name = luaL_checkstring(L, 2);
    instance->_NV_setName(name);
    return 0;
}

int CharacterBinding::setNameTagVisible(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->setNameTagVisible(value);
    return 0;
}

int CharacterBinding::ragdollMode(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool on = lua_toboolean(L, 2) != 0;
    RagdollPart::Enum part = (RagdollPart::Enum)luaL_checkinteger(L, 3);
    instance->ragdollMode(on, part);
    return 0;
}

int CharacterBinding::isRagdoll(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isRagdoll();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isDown(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isDown();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getRagdollPhysicsRootPos(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Ogre::Vector3 result = instance->getRagdollPhysicsRootPos();
    pushVector3(L, result);
    return 1;
}

int CharacterBinding::amSomeoneWhoNeedsToEatToLive(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->amSomeoneWhoNeedsToEatToLive();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_amSomeoneWhoNeedsToEatToLive(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->_NV_amSomeoneWhoNeedsToEatToLive();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getMagicHungerSetting(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->getMagicHungerSetting();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::_NV_getMagicHungerSetting(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->_NV_getMagicHungerSetting();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::wantsToEatNow(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->wantsToEatNow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isKidnapped(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isKidnapped();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isKidnapped(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->_NV_isKidnapped();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isLiterallyUnconciousNotPretending(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isLiterallyUnconciousNotPretending();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isLiterallyUnconciousNotPretending(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->_NV_isLiterallyUnconciousNotPretending();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isUnconcious(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isUnconcious();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isUnconcious(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->_NV_isUnconcious();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isCrippled(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isCrippled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isCrippled(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->_NV_isCrippled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getProneState(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    ProneState result = instance->getProneState();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::_NV_getProneState(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    ProneState result = instance->_NV_getProneState();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::setProneState(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    ProneState p = (ProneState)luaL_checkinteger(L, 2);
    instance->setProneState(p);
    return 0;
}

int CharacterBinding::_NV_setProneState(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    ProneState p = (ProneState)luaL_checkinteger(L, 2);
    instance->_NV_setProneState(p);
    return 0;
}

int CharacterBinding::_killRagdoll(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool doItNow = lua_toboolean(L, 2) != 0;
    instance->_killRagdoll(doItNow);
    return 0;
}

int CharacterBinding::giveBirth(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    GameDataCopyStandalone* appearance = checkObject<GameDataCopyStandalone>(L, 2, GameDataCopyStandaloneBinding::getMetatableName());
    Ogre::Vector3 position;
    readVector3(L, 3, position);
    Ogre::Quaternion rotation;
    readQuaternion(L, 4, rotation);
    GameSaveState* state = checkObject<GameSaveState>(L, 5, GameSaveStateBinding::getMetatableName());
    ActivePlatoon* tempplatoonptr = checkObject<ActivePlatoon>(L, 6, ActivePlatoonBinding::getMetatableName());
    Faction* _faction = checkObject<Faction>(L, 7, FactionBinding::getMetatableName());
    bool result = instance->giveBirth(appearance, position, rotation, state, tempplatoonptr, _faction);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_giveBirth(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    GameDataCopyStandalone* appearance = checkObject<GameDataCopyStandalone>(L, 2, GameDataCopyStandaloneBinding::getMetatableName());
    Ogre::Vector3 position;
    readVector3(L, 3, position);
    Ogre::Quaternion rotation;
    readQuaternion(L, 4, rotation);
    GameSaveState* state = checkObject<GameSaveState>(L, 5, GameSaveStateBinding::getMetatableName());
    ActivePlatoon* tempplatoonptr = checkObject<ActivePlatoon>(L, 6, ActivePlatoonBinding::getMetatableName());
    Faction* _faction = checkObject<Faction>(L, 7, FactionBinding::getMetatableName());
    bool result = instance->_NV_giveBirth(appearance, position, rotation, state, tempplatoonptr, _faction);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::setupAI(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->setupAI();
    return 0;
}

int CharacterBinding::clearAllAIGoals(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->clearAllAIGoals();
    return 0;
}

int CharacterBinding::setupPlatoonAI(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->setupPlatoonAI();
    return 0;
}

int CharacterBinding::setAppearanceData(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    GameDataCopyStandalone* data = checkObject<GameDataCopyStandalone>(L, 2, GameDataCopyStandaloneBinding::getMetatableName());
    instance->setAppearanceData(data);
    return 0;
}

int CharacterBinding::getAppearanceData(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    GameDataCopyStandalone* result = instance->getAppearanceData();
    return pushObject<GameDataCopyStandalone>(L, result, GameDataCopyStandaloneBinding::getMetatableName());
}

int CharacterBinding::setDestination(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    bool shift = lua_toboolean(L, 3) != 0;
    instance->setDestination(pos, shift);
    return 0;
}

int CharacterBinding::sendDialogEventOverride(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    EventTriggerEnum what = (EventTriggerEnum)luaL_checkinteger(L, 3);
    bool forceRepeat = lua_toboolean(L, 4) != 0;
    bool result = instance->sendDialogEventOverride(target, what, forceRepeat);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::sendDialogEvent(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    EventTriggerEnum what = (EventTriggerEnum)luaL_checkinteger(L, 3);
    bool result = instance->sendDialogEvent(target, what);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::sayALine(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    const std::string line = luaL_checkstring(L, 2);
    bool force = lua_toboolean(L, 3) != 0;
    instance->sayALine(line, force);
    return 0;
}

int CharacterBinding::hasDialogue(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->hasDialogue();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::willTalkToEnemies(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->willTalkToEnemies();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::relocationTeleport(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Ogre::Vector3 moveBy;
    readVector3(L, 2, moveBy);
    instance->relocationTeleport(moveBy);
    return 0;
}

int CharacterBinding::teleportVisuallyOnly(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Ogre::Vector3 to;
    readVector3(L, 2, to);
    Ogre::Quaternion rot;
    readQuaternion(L, 3, rot);
    instance->teleportVisuallyOnly(to, rot);
    return 0;
}

int CharacterBinding::teleportFromAnimation(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->teleportFromAnimation();
    return 0;
}

int CharacterBinding::attackTarget(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->attackTarget(who);
    return 0;
}

int CharacterBinding::notifyTheCampaignOfAnAttack(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* attacker = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->notifyTheCampaignOfAnAttack(attacker);
    return 0;
}

int CharacterBinding::iShouldntAggravateThisTarget(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->iShouldntAggravateThisTarget(target);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::sendMessage(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    CharacterMessage message = (CharacterMessage)luaL_checkinteger(L, 2);
    RootObject* sender = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    RootObject* subject = checkObject<RootObject>(L, 4, RootObjectBinding::getMetatableName());
    instance->sendMessage(message, sender, subject);
    return 0;
}

int CharacterBinding::attackingYou(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* attacker = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool so = lua_toboolean(L, 3) != 0;
    bool doAwarenessCheck = lua_toboolean(L, 4) != 0;
    instance->attackingYou(attacker, so, doAwarenessCheck);
    return 0;
}

int CharacterBinding::gettingEaten(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float amount = (float)luaL_checknumber(L, 2);
    Character* eater = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    bool result = instance->gettingEaten(amount, eater);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_gettingEaten(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float amount = (float)luaL_checknumber(L, 2);
    Character* eater = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    bool result = instance->_NV_gettingEaten(amount, eater);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getAttackOriginationDirection(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* attacker = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    CutOrigination result = instance->getAttackOriginationDirection(attacker);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::stumbleState(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->stumbleState();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::setAge(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float f = (float)luaL_checknumber(L, 2);
    instance->setAge(f);
    return 0;
}

int CharacterBinding::_NV_setAge(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float f = (float)luaL_checknumber(L, 2);
    instance->_NV_setAge(f);
    return 0;
}

int CharacterBinding::setFaction(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    ActivePlatoon* a = checkObject<ActivePlatoon>(L, 3, ActivePlatoonBinding::getMetatableName());
    instance->setFaction(p, a);
    return 0;
}

int CharacterBinding::_NV_setFaction(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    ActivePlatoon* a = checkObject<ActivePlatoon>(L, 3, ActivePlatoonBinding::getMetatableName());
    instance->_NV_setFaction(p, a);
    return 0;
}

int CharacterBinding::getAge(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->getAge();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::_NV_getAge(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->_NV_getAge();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::getAge0to1(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->getAge0to1();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::_NV_getAge0to1(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->_NV_getAge0to1();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::getAgeString(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    std::string result = instance->getAgeString();
    lua_pushstring(L, result.c_str());
    return 1;
}

int CharacterBinding::_NV_getAgeString(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    std::string result = instance->_NV_getAgeString();
    lua_pushstring(L, result.c_str());
    return 1;
}

int CharacterBinding::getAgeInverse(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->getAgeInverse();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::_NV_getAgeInverse(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->_NV_getAgeInverse();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::reThinkCurrentAIAction(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->reThinkCurrentAIAction();
    return 0;
}

int CharacterBinding::getBody(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    CharBody* result = instance->getBody();
    return pushObject<CharBody>(L, result, CharBodyBinding::getMetatableName());
}

int CharacterBinding::getCombatClass(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    CombatClass* result = instance->getCombatClass();
    return pushObject<CombatClass>(L, result, CombatClassBinding::getMetatableName());
}

int CharacterBinding::getStats(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    CharStats* result = instance->getStats();
    return pushObject<CharStats>(L, result, CharStatsBinding::getMetatableName());
}

int CharacterBinding::getMedical(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    MedicalSystem* result = instance->getMedical();
    return pushObject<MedicalSystem>(L, result, MedicalSystemBinding::getMetatableName());
}

int CharacterBinding::getOwnerships(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Ownerships* result = instance->getOwnerships();
    return pushObject<Ownerships>(L, result, OwnershipsBinding::getMetatableName());
}

int CharacterBinding::getAI(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    AI* result = instance->getAI();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int CharacterBinding::getAttackTarget(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    hand result = instance->getAttackTarget();
    return handBinding::push(L, result);
}

int CharacterBinding::isInCombatMode(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool melee = lua_toboolean(L, 2) != 0;
    bool ranged = lua_toboolean(L, 3) != 0;
    bool result = instance->isInCombatMode(melee, ranged);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isInRangedCombatMode(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isInRangedCombatMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isLiterallyUnderMeleeAttackRightNowForSure(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isLiterallyUnderMeleeAttackRightNowForSure();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_isLiterallyUnderMeleeAttackRightNowForSure_update(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->_isLiterallyUnderMeleeAttackRightNowForSure_update();
    return 0;
}

int CharacterBinding::conglomerateTagsFor(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    unsigned int result = instance->conglomerateTagsFor(who);
    lua_pushinteger(L, result);
    return 1;
}

int CharacterBinding::isPrisonerFreeToGo(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isPrisonerFreeToGo();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::clearTempEnemyStatus(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* theEnemy = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->clearTempEnemyStatus(theEnemy);
    return 0;
}

int CharacterBinding::clearAllTempEnemyStatuses(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    CharacterPerceptionTags_ShortTerm tag = (CharacterPerceptionTags_ShortTerm)luaL_checkinteger(L, 2);
    instance->clearAllTempEnemyStatuses(tag);
    return 0;
}

int CharacterBinding::lastSeenInHoursAgo(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float result = instance->lastSeenInHoursAgo(c);
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::haveMetBefore(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* h = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->haveMetBefore(h);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getIDForMemoryTagging(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    hand result = instance->getIDForMemoryTagging();
    return handBinding::push(L, result);
}

int CharacterBinding::getMovement(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    CharMovement* result = instance->getMovement();
    return pushObject<CharMovement>(L, result, CharMovementBinding::getMetatableName());
}

int CharacterBinding::lookatPosition(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Ogre::Vector3 v;
    readVector3(L, 2, v);
    bool fullbodyFacing = lua_toboolean(L, 3) != 0;
    instance->lookatPosition(v, fullbodyFacing);
    return 0;
}

int CharacterBinding::_NV_lookatPosition(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Ogre::Vector3 v;
    readVector3(L, 2, v);
    bool fullbodyFacing = lua_toboolean(L, 3) != 0;
    instance->_NV_lookatPosition(v, fullbodyFacing);
    return 0;
}

int CharacterBinding::areYouGonnaGetMe(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->areYouGonnaGetMe(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getAllAttackersCount(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    int result = instance->getAllAttackersCount();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterBinding::getRace(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    RaceData* result = instance->getRace();
    return pushObject<RaceData>(L, result, RaceDataBinding::getMetatableName());
}

int CharacterBinding::_NV_getRace(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    RaceData* result = instance->_NV_getRace();
    return pushObject<RaceData>(L, result, RaceDataBinding::getMetatableName());
}

int CharacterBinding::setRace(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    GameData* r = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->setRace(r);
    return 0;
}

int CharacterBinding::_NV_setRace(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    GameData* r = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_NV_setRace(r);
    return 0;
}

int CharacterBinding::getRadius(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->getRadius();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::isPlayerCharacter(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isPlayerCharacter();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::checkPlayerOrderForProblems(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    TaskType t = (TaskType)luaL_checkinteger(L, 2);
    RootObject* subject = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    bool result = instance->checkPlayerOrderForProblems(t, subject);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getTotalCarryWeight(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->getTotalCarryWeight();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::getCurrentWeapon(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Weapon* result = instance->getCurrentWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int CharacterBinding::getThePreferredWeapon(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Weapon* result = instance->getThePreferredWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int CharacterBinding::getRangedWeapon(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Crossbow* result = instance->getRangedWeapon();
    return pushObject<Crossbow>(L, result, CrossbowBinding::getMetatableName());
}

int CharacterBinding::_NV_getRangedWeapon(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Crossbow* result = instance->_NV_getRangedWeapon();
    return pushObject<Crossbow>(L, result, CrossbowBinding::getMetatableName());
}

int CharacterBinding::drawWeapon(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Item* _a1 = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    std::string _a2 = luaL_checkstring(L, 3);
    bool result = instance->drawWeapon(_a1, _a2);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getUpperBodyArmour(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Item* result = instance->getUpperBodyArmour();
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int CharacterBinding::getLowerBodyArmour(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Item* result = instance->getLowerBodyArmour();
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int CharacterBinding::isInjured(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool robot = lua_toboolean(L, 2) != 0;
    bool result = instance->isInjured(robot);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::shouldUseRangedWeapons(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->shouldUseRangedWeapons();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getBoneWorldPosition(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    const std::string name = luaL_checkstring(L, 2);
    Ogre::Vector3 result = instance->getBoneWorldPosition(name);
    pushVector3(L, result);
    return 1;
}

int CharacterBinding::getAppearance(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    AppearanceBase* result = instance->getAppearance();
    return pushObject<AppearanceBase>(L, result, AppearanceBaseBinding::getMetatableName());
}

int CharacterBinding::_setPlatoon(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    ActivePlatoon* p = checkObject<ActivePlatoon>(L, 2, ActivePlatoonBinding::getMetatableName());
    int idnum = (int)luaL_checkinteger(L, 3);
    instance->_setPlatoon(p, idnum);
    return 0;
}

int CharacterBinding::getPlatoon(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    ActivePlatoon* result = instance->getPlatoon();
    return pushObject<ActivePlatoon>(L, result, ActivePlatoonBinding::getMetatableName());
}

int CharacterBinding::hasPlatoon(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->hasPlatoon();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isInAPersistentPlatoon(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isInAPersistentPlatoon();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getBlackboard(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Blackboard* result = instance->getBlackboard();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int CharacterBinding::getSquadLeader(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* result = instance->getSquadLeader();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int CharacterBinding::getOrdersReciever(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    OrdersReceiver* result = instance->getOrdersReciever();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int CharacterBinding::preventRagdollMode(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->preventRagdollMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::setPrisonMode(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool on = lua_toboolean(L, 2) != 0;
    UseableStuff* h = checkObject<UseableStuff>(L, 3, UseableStuffBinding::getMetatableName());
    instance->setPrisonMode(on, h);
    return 0;
}

int CharacterBinding::setBedMode(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool on = lua_toboolean(L, 2) != 0;
    UseableStuff* h = checkObject<UseableStuff>(L, 3, UseableStuffBinding::getMetatableName());
    instance->setBedMode(on, h);
    return 0;
}

int CharacterBinding::setSlaveAIJob(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setSlaveAIJob(on);
    return 0;
}

int CharacterBinding::isChainedMode(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isChainedMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getChainedModeShackles(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    LockedArmour* result = instance->getChainedModeShackles();
    return pushObject<LockedArmour>(L, result, LockedArmourBinding::getMetatableName());
}

int CharacterBinding::getMySlaveOwner(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    hand result = instance->getMySlaveOwner();
    return handBinding::push(L, result);
}

int CharacterBinding::isSlave(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    SlaveStateEnum result = instance->isSlave();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::isMySlave(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* slave = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->isMySlave(slave);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isMyFactionsSlave(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* slave = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->isMyFactionsSlave(slave);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isHeadShaven(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isHeadShaven();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isHeadShaven(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->_NV_isHeadShaven();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::runSlaveAnim(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    const std::string anim = luaL_checkstring(L, 2);
    float speed = (float)luaL_checknumber(L, 3);
    float sync = (float)luaL_checknumber(L, 4);
    instance->runSlaveAnim(anim, speed, sync);
    return 0;
}

int CharacterBinding::endSlaveAnim(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    const std::string anim = luaL_checkstring(L, 2);
    instance->endSlaveAnim(anim);
    return 0;
}

int CharacterBinding::updatePortraitGUIState(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->updatePortraitGUIState();
    return 0;
}

int CharacterBinding::pickupObject(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->pickupObject(who);
    return 0;
}

int CharacterBinding::getPickedUp(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* byWhom = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->getPickedUp(byWhom);
    return 0;
}

int CharacterBinding::slaveAttachToBoneMode(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    const std::string bone = luaL_checkstring(L, 2);
    instance->slaveAttachToBoneMode(bone);
    return 0;
}

int CharacterBinding::isDead(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isDead();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isBeingCarried(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->isBeingCarried();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getCarryingObject(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    hand result = instance->getCarryingObject();
    return handBinding::push(L, result);
}

int CharacterBinding::chooseCarryObjectLeftOrRight(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->chooseCarryObjectLeftOrRight();
    return 0;
}

int CharacterBinding::dropCarriedObject(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool ragdollHim = lua_toboolean(L, 2) != 0;
    bool removeOnly = lua_toboolean(L, 3) != 0;
    instance->dropCarriedObject(ragdollHim, removeOnly);
    return 0;
}

int CharacterBinding::getDropped(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool ragdollHim = lua_toboolean(L, 2) != 0;
    bool hull = lua_toboolean(L, 3) != 0;
    instance->getDropped(ragdollHim, hull);
    return 0;
}

int CharacterBinding::getDiplomacyMultiplier(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float result = instance->getDiplomacyMultiplier();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::isEnemy(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool factorInDisguises = lua_toboolean(L, 3) != 0;
    bool result = instance->isEnemy(who, factorInDisguises);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isEnemy(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool factorInDisguises = lua_toboolean(L, 3) != 0;
    bool result = instance->_NV_isEnemy(who, factorInDisguises);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::isAlly(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool factorInDisguises = lua_toboolean(L, 3) != 0;
    bool result = instance->isAlly(who, factorInDisguises);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_isAlly(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool factorInDisguises = lua_toboolean(L, 3) != 0;
    bool result = instance->_NV_isAlly(who, factorInDisguises);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getDefaultTaskRepertoireEnum(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    unsigned int result = instance->getDefaultTaskRepertoireEnum();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterBinding::_NV_getDefaultTaskRepertoireEnum(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    unsigned int result = instance->_NV_getDefaultTaskRepertoireEnum();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterBinding::getAnimationClass(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    AnimationClass* result = instance->getAnimationClass();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int CharacterBinding::getPredictedPosition(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float secondsInFuture = (float)luaL_checknumber(L, 2);
    Ogre::Vector3 result = instance->getPredictedPosition(secondsInFuture);
    pushVector3(L, result);
    return 1;
}

int CharacterBinding::carryModeT(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool on = lua_toboolean(L, 2) != 0;
    bool makeRagdoll = lua_toboolean(L, 3) != 0;
    bool makeHull = lua_toboolean(L, 4) != 0;
    instance->carryModeT(on, makeRagdoll, makeHull);
    return 0;
}

int CharacterBinding::_carryMode(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool on = lua_toboolean(L, 2) != 0;
    bool makeRagdoll = lua_toboolean(L, 3) != 0;
    bool makeHull = lua_toboolean(L, 4) != 0;
    instance->_carryMode(on, makeRagdoll, makeHull);
    return 0;
}

int CharacterBinding::recalculateTotalEquipmentSkillBonus(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->recalculateTotalEquipmentSkillBonus();
    return 0;
}

int CharacterBinding::setupAudio(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->setupAudio();
    return 0;
}

int CharacterBinding::_NV_setupAudio(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->_NV_setupAudio();
    return 0;
}

int CharacterBinding::audioEvent(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    const char* name = luaL_checkstring(L, 2);
    SoundRange range = (SoundRange)luaL_checkinteger(L, 3);
    bool result = instance->audioEvent(name, range);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::setGroundType(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    GroundType t = (GroundType)luaL_checkinteger(L, 2);
    instance->setGroundType(t);
    return 0;
}

int CharacterBinding::getGroundType(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    GroundType result = instance->getGroundType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::calculateMainArmourType(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->calculateMainArmourType();
    return 0;
}

int CharacterBinding::getMainArmourType(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    ArmourType result = instance->getMainArmourType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::wearingUniformOf(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    bool result = instance->wearingUniformOf(f);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_wearingUniformOf(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    bool result = instance->_NV_wearingUniformOf(f);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getUniformColorScheme(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    GameData* result = instance->getUniformColorScheme();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int CharacterBinding::canTakePlayerOrdersAtThisTime(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->canTakePlayerOrdersAtThisTime();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::startEffect(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    GameData* effect = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->startEffect(effect);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::stopEffect(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    GameData* effect = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->stopEffect(effect);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::stopAllEffects(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->stopAllEffects();
    return 0;
}

int CharacterBinding::notifyEffect(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    EffectType::Enum type = (EffectType::Enum)luaL_checkinteger(L, 2);
    WeatherAffecting what = (WeatherAffecting)luaL_checkinteger(L, 3);
    float strength = (float)luaL_checknumber(L, 4);
    instance->notifyEffect(type, what, strength);
    return 0;
}

int CharacterBinding::_NV_notifyEffect(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    EffectType::Enum type = (EffectType::Enum)luaL_checkinteger(L, 2);
    WeatherAffecting what = (WeatherAffecting)luaL_checkinteger(L, 3);
    float strength = (float)luaL_checknumber(L, 4);
    instance->_NV_notifyEffect(type, what, strength);
    return 0;
}

int CharacterBinding::equipItem(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    const std::string sectionName = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    instance->equipItem(sectionName, item);
    return 0;
}

int CharacterBinding::_NV_equipItem(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    const std::string sectionName = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    instance->_NV_equipItem(sectionName, item);
    return 0;
}

int CharacterBinding::unequipItem(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    const std::string sectionName = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    instance->unequipItem(sectionName, item);
    return 0;
}

int CharacterBinding::_NV_unequipItem(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    const std::string sectionName = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    instance->_NV_unequipItem(sectionName, item);
    return 0;
}

int CharacterBinding::validateInventorySections(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->validateInventorySections();
    return 0;
}

int CharacterBinding::_NV_validateInventorySections(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->_NV_validateInventorySections();
    return 0;
}

int CharacterBinding::processCharacterLoadTimeMessages(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->processCharacterLoadTimeMessages();
    return 0;
}

int CharacterBinding::wantsPathfinderActive(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->wantsPathfinderActive();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::createAnimationClass(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->createAnimationClass();
    return 0;
}

int CharacterBinding::calculateDestinationState(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    Building* dest = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    RootObject* subject = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    Ogre::Vector3 v;
    readVector3(L, 4, v);
    instance->calculateDestinationState(dest, subject, v);
    return 0;
}

int CharacterBinding::generateWeapon(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    GameData* weapon = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* manufacturer = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    Item* result = instance->generateWeapon(weapon, manufacturer);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int CharacterBinding::createPhysical(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_createPhysical(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool result = instance->_NV_createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::destroyPhysical(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->destroyPhysical();
    return 0;
}

int CharacterBinding::_NV_destroyPhysical(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->_NV_destroyPhysical();
    return 0;
}

int CharacterBinding::createComponents(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    GameDataCopyStandalone* appearance = checkObject<GameDataCopyStandalone>(L, 2, GameDataCopyStandaloneBinding::getMetatableName());
    bool result = instance->createComponents(appearance);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::loadUnloadCheck(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->loadUnloadCheck();
    return 0;
}

int CharacterBinding::_NV_loadUnloadCheck(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->_NV_loadUnloadCheck();
    return 0;
}

int CharacterBinding::updateStateBroadcast(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->updateStateBroadcast(time);
    return 0;
}

int CharacterBinding::setEffectBT(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    GameData* effect = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool active = lua_toboolean(L, 3) != 0;
    instance->setEffectBT(effect, active);
    return 0;
}

int CharacterBinding::postRagdollCallback(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool on = lua_toboolean(L, 2) != 0;
    RagdollPart::Enum part = (RagdollPart::Enum)luaL_checkinteger(L, 3);
    instance->postRagdollCallback(on, part);
    return 0;
}

int CharacterBinding::_NV_postRagdollCallback(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    bool on = lua_toboolean(L, 2) != 0;
    RagdollPart::Enum part = (RagdollPart::Enum)luaL_checkinteger(L, 3);
    instance->_NV_postRagdollCallback(on, part);
    return 0;
}

int CharacterBinding::reCalculateNaturalWeapon(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->reCalculateNaturalWeapon();
    return 0;
}

int CharacterBinding::_NV_reCalculateNaturalWeapon(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

    instance->_NV_reCalculateNaturalWeapon();
    return 0;
}

/*
Skipped methods needing manual binding:
  None. All methods from the skipped list have been successfully bound.
*/

/*
Skipped properties needing manual binding:
  line 717: ragdollMessages (std::deque<Character::RagdollMsg, std::allocator<Character::RagdollMsg> >) - unsupported type
  line 753: audioData (AkSoundPosition) - unsupported type
  line 760: particleEffects (lektor<Effect*>) - unsupported type
*/

static int Character_get_disguiseGUIFeedbacks(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_newtable(L);
    typedef ogre_unordered_map<Character::DisguiseGUIFeedback, float>::type MapType;
    for (MapType::const_iterator it = instance->disguiseGUIFeedbacks.begin(); it != instance->disguiseGUIFeedbacks.end(); ++it)
    {
        lua_pushinteger(L, (lua_Integer)it->first);
        lua_pushnumber(L, (lua_Number)it->second);
        lua_settable(L, -3);
    }
    return 1;
}

static int Character_get_whoSeesMeSneaking(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_newtable(L);
    typedef ogre_unordered_map<hand, Character::WhoSeesMe>::type MapType;
    for (MapType::const_iterator it = instance->whoSeesMeSneaking.begin(); it != instance->whoSeesMeSneaking.end(); ++it)
    {
        handBinding::push(L, it->first);
        pushObject<Character::WhoSeesMe>(L, const_cast<Character::WhoSeesMe*>(&it->second), WhoSeesMeBinding::getMetatableName());
        lua_settable(L, -3);
    }
    return 1;
}

static int Character_get_inSomething(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, (lua_Integer)instance->inSomething);
    return 1;
}

static int Character_get_audioObject(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, (lua_Integer)instance->audioObject);
    return 1;
}

static int Character_get_activeEffects(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_newtable(L);
    for (uint32_t i = 0; i < instance->activeEffects.size(); ++i)
    {
        lua_pushinteger(L, (lua_Integer)instance->activeEffects[i].first);
        lua_pushnumber(L, (lua_Number)instance->activeEffects[i].second);
        lua_settable(L, -3);
    }
    return 1;
}

static int Character_set_stateBroadcast(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->stateBroadcast = (StateBroadcastData*)lua_touserdata(L, 2);
    return 0;
}

static int Character_set__myMemory(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->_myMemory = (CharacterMemory*)lua_touserdata(L, 2);
    return 0;
}

static int Character_set_rangedCombat(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->rangedCombat = (RangedCombatClass*)lua_touserdata(L, 2);
    return 0;
}

static int Character_set_inSomething(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->inSomething = (UseStuffState)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_msgCarryMode(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->msgCarryMode = (Character::CarryMsg*)lua_touserdata(L, 2);
    return 0;
}

static int Character_set_animation(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->animation = (AnimationClass*)lua_touserdata(L, 2);
    return 0;
}

static int Character_set_nameTag(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->nameTag = (CharacterNameTag*)lua_touserdata(L, 2);
    return 0;
}

static int Character_set_ai(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->ai = (AI*)lua_touserdata(L, 2);
    return 0;
}

static int Character_set_audioObject(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->audioObject = (unsigned __int64)luaL_checkinteger(L, 2);
    return 0;
}

static int Character_set_audioEmitter(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    instance->audioEmitter = (SoundEmitter*)lua_touserdata(L, 2);
    return 0;
}


// --- Method Functions
int CharacterBinding::rememberCharacter(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");

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
        instance->rememberCharacter(who, lt_tag);
    }
    else
    {
        instance->rememberCharacter(who, st_tag);
    }
    return 0;
}

int CharacterBinding::setHandle(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be a hand object");
    instance->setHandle(*h);
    return 0;
}

int CharacterBinding::_NV_setHandle(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be a hand object");
    instance->_NV_setHandle(*h);
    return 0;
}

int CharacterBinding::isIndoors(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    return handBinding::push(L, instance->isIndoors());
}

int CharacterBinding::_NV_isIndoors(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    return handBinding::push(L, instance->_NV_isIndoors());
}

int CharacterBinding::isStandingOnBuilding(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    return handBinding::push(L, instance->isStandingOnBuilding());
}

int CharacterBinding::_NV_isStandingOnBuilding(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    return handBinding::push(L, instance->_NV_isStandingOnBuilding());
}

int CharacterBinding::notifyIndoors(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    hand* in = checkObject<hand>(L, 2, handBinding::getMetatableName());
    if (!in) return luaL_error(L, "Argument 1 must be a hand object");
    instance->notifyIndoors(*in);
    return 0;
}

int CharacterBinding::_NV_notifyIndoors(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    hand* in = checkObject<hand>(L, 2, handBinding::getMetatableName());
    if (!in) return luaL_error(L, "Argument 1 must be a hand object");
    instance->_NV_notifyIndoors(*in);
    return 0;
}

int CharacterBinding::setDestinationIndoors(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be a hand object");
    instance->setDestinationIndoors(*h);
    return 0;
}

int CharacterBinding::getAudioObject(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushinteger(L, (lua_Integer)instance->getAudioObject());
    return 1;
}

int CharacterBinding::getName(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    const std::string& result = instance->getName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int CharacterBinding::_NV_getName(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    const std::string& result = instance->_NV_getName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int CharacterBinding::changeSlaveOwner(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    hand* newOwner = checkObject<hand>(L, 2, handBinding::getMetatableName());
    if (newOwner) {
        instance->changeSlaveOwner(*newOwner);
    }
    return 0;
}

int CharacterBinding::teleport(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    Ogre::Vector3 moveBy;
    readVector3(L, 2, moveBy);
    if (lua_gettop(L) >= 3 && !lua_isnil(L, 3))
    {
        Ogre::Quaternion rot;
        readQuaternion(L, 3, rot);
        instance->teleport(moveBy, rot);
    }
    else
    {
        instance->teleport(moveBy);
    }
    return 0;
}

int CharacterBinding::audioValue(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    const char* name = luaL_checkstring(L, 2);
    if (lua_isnumber(L, 3))
    {
        float value = (float)lua_tonumber(L, 3);
        instance->audioValue(name, value);
    }
    else
    {
        const char* value = luaL_checkstring(L, 3);
        instance->audioValue(name, value);
    }
    return 0;
}

int CharacterBinding::getPermajobName(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    int slot = (int)luaL_checkinteger(L, 2);
    const std::string& name = instance->getPermajobName(slot);
    lua_pushstring(L, name.c_str());
    return 1;
}

int CharacterBinding::getAABB(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushlightuserdata(L, const_cast<Ogre::Aabb*>(&instance->getAABB()));
    return 1;
}

int CharacterBinding::_NV_getAABB(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lua_pushlightuserdata(L, const_cast<Ogre::Aabb*>(&instance->_NV_getAABB()));
    return 1;
}

int CharacterBinding::getAllAttackers(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lektor<hand> out;
    instance->getAllAttackers(out);
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

int CharacterBinding::getCharacterMemoryTag(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    int mem = (int)luaL_checkinteger(L, 3);
    bool isLongTerm = true;
    if (lua_gettop(L) >= 4) {
        isLongTerm = lua_toboolean(L, 4) != 0;
    }
    if (isLongTerm) {
        lua_pushboolean(L, instance->getCharacterMemoryTag(who, (CharacterPerceptionTags_LongTerm)mem) ? 1 : 0);
    } else {
        lua_pushboolean(L, instance->getCharacterMemoryTag(who, (CharacterPerceptionTags_ShortTerm)mem) ? 1 : 0);
    }
    return 1;
}

int CharacterBinding::hitByMeleeAttack(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
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
    HitMaterialType result = instance->hitByMeleeAttack(dir, *damage, who, attack, comboID);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharacterBinding::convertCutDirection(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    CutDirection cut = (CutDirection)luaL_checkinteger(L, 2);
    if (lua_isnumber(L, 3)) {
        CutOrigination from = (CutOrigination)lua_tointeger(L, 3);
        lua_pushinteger(L, (lua_Integer)instance->convertCutDirection(cut, from));
    } else {
        Character* attacker = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
        lua_pushinteger(L, (lua_Integer)instance->convertCutDirection(cut, attacker));
    }
    return 1;
}

int CharacterBinding::breakFollowOrderLoop(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    hand* start = checkObject<hand>(L, 2, handBinding::getMetatableName());
    if (start) {
        lua_pushboolean(L, instance->breakFollowOrderLoop(*start) ? 1 : 0);
    } else {
        lua_pushboolean(L, 0);
    }
    return 1;
}

int CharacterBinding::_CONSTRUCTOR(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    GameData* dat = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Faction* own = checkObject<Faction>(L, 3, FactionBinding::getMetatableName());
    hand* _handle = checkObject<hand>(L, 4, handBinding::getMetatableName());
    if (!_handle) return luaL_error(L, "Argument 3 must be a hand object");
    Character* result = instance->_CONSTRUCTOR(dat, own, *_handle);
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int CharacterBinding::formationUpdateCallback(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    hand* target = checkObject<hand>(L, 3, handBinding::getMetatableName());
    if (!target) return luaL_error(L, "Argument 2 must be a hand object");
    Ogre::Vector3 heading;
    readVector3(L, 4, heading);
    Formation* from = (Formation*)lua_touserdata(L, 5);
    instance->formationUpdateCallback(pos, *target, heading, from);
    return 0;
}

int CharacterBinding::serialise(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* refList = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    PosRotPair* offset = (PosRotPair*)lua_touserdata(L, 4);
    GameSaveState result = instance->serialise(container, refList, offset);
    GameSaveState* heapResult = new GameSaveState(result);
    return pushObject<GameSaveState>(L, heapResult, GameSaveStateBinding::getMetatableName());
}

int CharacterBinding::_NV_serialise(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* refList = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    PosRotPair* offset = (PosRotPair*)lua_touserdata(L, 4);
    GameSaveState result = instance->_NV_serialise(container, refList, offset);
    GameSaveState* heapResult = new GameSaveState(result);
    return pushObject<GameSaveState>(L, heapResult, GameSaveStateBinding::getMetatableName());
}

int CharacterBinding::hasItemsFrom(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    StorageBuilding* from = checkObject<StorageBuilding>(L, 2, StorageBuildingBinding::getMetatableName());
    ogre_unordered_set<GameData*>::type* allTheOnesWeHave = OgreUnorderedSetBinding<GameData*>::get(L, 3);
    if (!allTheOnesWeHave) return luaL_error(L, "Argument 2 must be an OgreUnorderedSet");
    bool result = instance->hasItemsFrom(from, *allTheOnesWeHave);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_NV_hasItemsFrom(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    StorageBuilding* from = checkObject<StorageBuilding>(L, 2, StorageBuildingBinding::getMetatableName());
    ogre_unordered_set<GameData*>::type* allTheOnesWeHave = OgreUnorderedSetBinding<GameData*>::get(L, 3);
    if (!allTheOnesWeHave) return luaL_error(L, "Argument 2 must be an OgreUnorderedSet");
    bool result = instance->_NV_hasItemsFrom(from, *allTheOnesWeHave);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::getLockpickChance(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    DoorLock* victim = (DoorLock*)lua_touserdata(L, 2);
    float result = instance->getLockpickChance(victim);
    lua_pushnumber(L, result);
    return 1;
}

int CharacterBinding::debugIndicateCharacters(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    lektor<Character*>* list = LektorPtrBinding<Character*>::get(L, 2);
    if (!list) return luaL_error(L, "Argument 1 must be a lektor<Character*>");
    instance->debugIndicateCharacters(*list);
    return 0;
}

int CharacterBinding::iShotYou(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    Character* attacker = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    Harpoon* poon = (Harpoon*)lua_touserdata(L, 3);
    bool onPurpose = lua_toboolean(L, 4) != 0;
    bool result = instance->iShotYou(attacker, poon, onPurpose);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterBinding::_startStumble(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    CutDirection dir = (CutDirection)luaL_checkinteger(L, 2);
    Damages* damage = checkObject<Damages>(L, 3, DamagesBinding::getMetatableName());
    if (!damage) return luaL_error(L, "Argument 2 must be a Damages object");
    GameData* bodyPart = checkObject<GameData>(L, 4, GameDataBinding::getMetatableName());
    Character* attacker = checkObject<Character>(L, 5, CharacterBinding::getMetatableName());
    instance->_startStumble(dir, *damage, bodyPart, attacker);
    return 0;
}

int CharacterBinding::getSquadMissionTarget(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    hand result;
    instance->getSquadMissionTarget(result);
    return handBinding::push(L, result);
}

int CharacterBinding::setChainedMode(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    bool on = lua_toboolean(L, 2) != 0;
    hand* owner = checkObject<hand>(L, 3, handBinding::getMetatableName());
    if (!owner) return luaL_error(L, "Argument 2 must be a hand object");
    instance->setChainedMode(on, *owner);
    return 0;
}

int CharacterBinding::_ragdollMode(lua_State* L)
{
    Character* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Character is nil");
    bool on = false;
    RagdollPart::Enum part = (RagdollPart::Enum)0;
    if (lua_istable(L, 2))
    {
        lua_getfield(L, 2, "on");
        on = lua_toboolean(L, -1) != 0;
        lua_pop(L, 1);
        lua_getfield(L, 2, "part");
        part = (RagdollPart::Enum)luaL_checkinteger(L, -1);
        lua_pop(L, 1);
    }
    else
    {
        on = lua_toboolean(L, 2) != 0;
        part = (RagdollPart::Enum)luaL_checkinteger(L, 3);
    }
    Character::RagdollMsg msg(on, part);
    bool result = instance->_ragdollMode(msg);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
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
        { "isInAWarCampaign", CharacterBinding::isInAWarCampaign },
        { "wantsToTriggerCampaigns", CharacterBinding::wantsToTriggerCampaigns },
        { "isUnique", CharacterBinding::isUnique },
        { "canSpeakNormally", CharacterBinding::canSpeakNormally },
        { "isAnimal", CharacterBinding::isAnimal },
        { "_NV_isAnimal", CharacterBinding::_NV_isAnimal },
        { "isHuman", CharacterBinding::isHuman },
        { "_NV_isHuman", CharacterBinding::_NV_isHuman },
        { "takeMoney", CharacterBinding::takeMoney },
        { "_NV_takeMoney", CharacterBinding::_NV_takeMoney },
        { "getMoney", CharacterBinding::getMoney },
        { "_NV_getMoney", CharacterBinding::_NV_getMoney },
        { "setSquadMemberType", CharacterBinding::setSquadMemberType },
        { "isResident", CharacterBinding::isResident },
        { "dailyUpdate", CharacterBinding::dailyUpdate },
        { "updateOnScreenCheck", CharacterBinding::updateOnScreenCheck },
        { "offscreenUpdate", CharacterBinding::offscreenUpdate },
        { "updateTimes", CharacterBinding::updateTimes },
        { "getSensoryData", CharacterBinding::getSensoryData },
        { "_NV_getSensoryData", CharacterBinding::_NV_getSensoryData },
        { "getStateBroadcast", CharacterBinding::getStateBroadcast },
        { "_NV_getStateBroadcast", CharacterBinding::_NV_getStateBroadcast },
        { "getFormation", CharacterBinding::getFormation },
        { "_NV_getFormation", CharacterBinding::_NV_getFormation },
        { "getEnemyFormation", CharacterBinding::getEnemyFormation },
        { "_NV_getEnemyFormation", CharacterBinding::_NV_getEnemyFormation },
        { "AIDestinationIndoorOutdoorCheck", CharacterBinding::AIDestinationIndoorOutdoorCheck },
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
        { "lineOfSightCheck", CharacterBinding::lineOfSightCheck },
        { "getPerceptionMult", CharacterBinding::getPerceptionMult },
        { "isWithThePlayer", CharacterBinding::isWithThePlayer },
        { "notifyICanSeeYouSneaking", CharacterBinding::notifyICanSeeYouSneaking },
        { "isItSafeToGetUp", CharacterBinding::isItSafeToGetUp },
        { "separateIntoMyOwnSquad", CharacterBinding::separateIntoMyOwnSquad },
        { "dropGearOnDeath", CharacterBinding::dropGearOnDeath },
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
        { "getStealingSuccessChance", CharacterBinding::getStealingSuccessChance },
        { "getCurrentWeatherAffectStatus", CharacterBinding::getCurrentWeatherAffectStatus },
        { "getCurrentWeatherAffectStrength", CharacterBinding::getCurrentWeatherAffectStrength },
        { "getWaterLevel", CharacterBinding::getWaterLevel },
        { "setTerrainHeightPosition", CharacterBinding::setTerrainHeightPosition },
        { "getTerrainHeightPosition", CharacterBinding::getTerrainHeightPosition },
        { "setDisguiseMessage", CharacterBinding::setDisguiseMessage },
        { "uniqueStateUpdate", CharacterBinding::uniqueStateUpdate },
        { "foodUpdate", CharacterBinding::foodUpdate },
        { "_NV_foodUpdate", CharacterBinding::_NV_foodUpdate },
        { "eatItem", CharacterBinding::eatItem },
        { "loadFromSerialise", CharacterBinding::loadFromSerialise },
        { "_NV_loadFromSerialise", CharacterBinding::_NV_loadFromSerialise },
        { "loadFromSerialisePostCreationStage", CharacterBinding::loadFromSerialisePostCreationStage },
        { "_NV_loadFromSerialisePostCreationStage", CharacterBinding::_NV_loadFromSerialisePostCreationStage },
        { "setupInventorySections", CharacterBinding::setupInventorySections },
        { "_NV_setupInventorySections", CharacterBinding::_NV_setupInventorySections },
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
        { "getGUIData", CharacterBinding::getGUIData },
        { "_NV_getGUIData", CharacterBinding::_NV_getGUIData },
        { "getCurrentTownLocation", CharacterBinding::getCurrentTownLocation },
        { "_NV_getCurrentTownLocation", CharacterBinding::_NV_getCurrentTownLocation },
        { "say_WithARepeatLimiter", CharacterBinding::say_WithARepeatLimiter },
        { "_NV_say_WithARepeatLimiter", CharacterBinding::_NV_say_WithARepeatLimiter },
        { "say", CharacterBinding::say },
        { "_NV_say", CharacterBinding::_NV_say },
        { "isInventoryVisible", CharacterBinding::isInventoryVisible },
        { "_NV_isInventoryVisible", CharacterBinding::_NV_isInventoryVisible },
        { "giveItem", CharacterBinding::giveItem },
        { "_NV_giveItem", CharacterBinding::_NV_giveItem },
        { "hasRoomForItem", CharacterBinding::hasRoomForItem },
        { "_NV_hasRoomForItem", CharacterBinding::_NV_hasRoomForItem },
        { "hasItem", CharacterBinding::hasItem },
        { "_NV_hasItem", CharacterBinding::_NV_hasItem },
        { "hasAmmoFor", CharacterBinding::hasAmmoFor },
        { "_NV_hasAmmoFor", CharacterBinding::_NV_hasAmmoFor },
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
        { "createInventoryLayout", CharacterBinding::createInventoryLayout },
        { "_NV_createInventoryLayout", CharacterBinding::_NV_createInventoryLayout },
        { "getStealthKOChance", CharacterBinding::getStealthKOChance },
        { "getKidnappingChance", CharacterBinding::getKidnappingChance },
        { "getKidnappingEscapeChance_skill", CharacterBinding::getKidnappingEscapeChance_skill },
        { "getKidnappingEscapeChance_strength", CharacterBinding::getKidnappingEscapeChance_strength },
        { "shouldIHelpThisGuy", CharacterBinding::shouldIHelpThisGuy },
        { "shouldIScrewThisGuyOver", CharacterBinding::shouldIScrewThisGuyOver },
        { "ILoveThisGuyBecauseOfStuffThatHappened", CharacterBinding::ILoveThisGuyBecauseOfStuffThatHappened },
        { "IHateThisGuyBecauseOfStuffThatHappened", CharacterBinding::IHateThisGuyBecauseOfStuffThatHappened },
        { "getRoughLevel", CharacterBinding::getRoughLevel },
        { "setStandingOrder", CharacterBinding::setStandingOrder },
        { "_NV_setStandingOrder", CharacterBinding::_NV_setStandingOrder },
        { "getStandingOrder", CharacterBinding::getStandingOrder },
        { "setStealthMode", CharacterBinding::setStealthMode },
        { "isStealthMode", CharacterBinding::isStealthMode },
        { "isStealthModeOrCrawling", CharacterBinding::isStealthModeOrCrawling },
        { "declareDead", CharacterBinding::declareDead },
        { "updateGUIStatsDetails", CharacterBinding::updateGUIStatsDetails },
        { "_printRaceXPBonusLine", CharacterBinding::_printRaceXPBonusLine },
        { "addGoal", CharacterBinding::addGoal },
        { "addJob", CharacterBinding::addJob },
        { "removeJob", CharacterBinding::removeJob },
        { "removePermajob", CharacterBinding::removePermajob },
        { "clearPermajobs", CharacterBinding::clearPermajobs },
        { "movePermajob", CharacterBinding::movePermajob },
        { "getPermajob", CharacterBinding::getPermajob },
        { "getPermajobData", CharacterBinding::getPermajobData },
        { "getPermajobCount", CharacterBinding::getPermajobCount },
        { "addOrder", CharacterBinding::addOrder },
        { "updateLastTask", CharacterBinding::updateLastTask },
        { "_NV_updateLastTask", CharacterBinding::_NV_updateLastTask },
        { "playerMoveOrderDefault", CharacterBinding::playerMoveOrderDefault },
        { "_NV_playerMoveOrderDefault", CharacterBinding::_NV_playerMoveOrderDefault },
        { "endCombatMode", CharacterBinding::endCombatMode },
        { "getTotalRelativeStrengthOfAttackers", CharacterBinding::getTotalRelativeStrengthOfAttackers },
        { "_NV_getTotalRelativeStrengthOfAttackers", CharacterBinding::_NV_getTotalRelativeStrengthOfAttackers },
        { "canGoIndoors", CharacterBinding::canGoIndoors },
        { "_NV_canGoIndoors", CharacterBinding::_NV_canGoIndoors },
        { "isIndoorsRagdoll", CharacterBinding::isIndoorsRagdoll },
        { "_NV_isIndoorsRagdoll", CharacterBinding::_NV_isIndoorsRagdoll },
        { "destinationIndoors", CharacterBinding::destinationIndoors },
        { "destinationInsideWalls", CharacterBinding::destinationInsideWalls },
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
        { "giveBirth", CharacterBinding::giveBirth },
        { "_NV_giveBirth", CharacterBinding::_NV_giveBirth },
        { "setupAI", CharacterBinding::setupAI },
        { "clearAllAIGoals", CharacterBinding::clearAllAIGoals },
        { "setupPlatoonAI", CharacterBinding::setupPlatoonAI },
        { "setAppearanceData", CharacterBinding::setAppearanceData },
        { "getAppearanceData", CharacterBinding::getAppearanceData },
        { "setDestination", CharacterBinding::setDestination },
        { "sendDialogEventOverride", CharacterBinding::sendDialogEventOverride },
        { "sendDialogEvent", CharacterBinding::sendDialogEvent },
        { "sayALine", CharacterBinding::sayALine },
        { "hasDialogue", CharacterBinding::hasDialogue },
        { "willTalkToEnemies", CharacterBinding::willTalkToEnemies },
        { "relocationTeleport", CharacterBinding::relocationTeleport },
        { "teleportVisuallyOnly", CharacterBinding::teleportVisuallyOnly },
        { "teleportFromAnimation", CharacterBinding::teleportFromAnimation },
        { "attackTarget", CharacterBinding::attackTarget },
        { "notifyTheCampaignOfAnAttack", CharacterBinding::notifyTheCampaignOfAnAttack },
        { "iShouldntAggravateThisTarget", CharacterBinding::iShouldntAggravateThisTarget },
        { "sendMessage", CharacterBinding::sendMessage },
        { "attackingYou", CharacterBinding::attackingYou },
        { "gettingEaten", CharacterBinding::gettingEaten },
        { "_NV_gettingEaten", CharacterBinding::_NV_gettingEaten },
        { "getAttackOriginationDirection", CharacterBinding::getAttackOriginationDirection },
        { "stumbleState", CharacterBinding::stumbleState },
        { "setAge", CharacterBinding::setAge },
        { "_NV_setAge", CharacterBinding::_NV_setAge },
        { "setFaction", CharacterBinding::setFaction },
        { "_NV_setFaction", CharacterBinding::_NV_setFaction },
        { "getAge", CharacterBinding::getAge },
        { "_NV_getAge", CharacterBinding::_NV_getAge },
        { "getAge0to1", CharacterBinding::getAge0to1 },
        { "_NV_getAge0to1", CharacterBinding::_NV_getAge0to1 },
        { "getAgeString", CharacterBinding::getAgeString },
        { "_NV_getAgeString", CharacterBinding::_NV_getAgeString },
        { "getAgeInverse", CharacterBinding::getAgeInverse },
        { "_NV_getAgeInverse", CharacterBinding::_NV_getAgeInverse },
        { "reThinkCurrentAIAction", CharacterBinding::reThinkCurrentAIAction },
        { "getBody", CharacterBinding::getBody },
        { "getCombatClass", CharacterBinding::getCombatClass },
        { "getStats", CharacterBinding::getStats },
        { "getMedical", CharacterBinding::getMedical },
        { "getOwnerships", CharacterBinding::getOwnerships },
        { "getAI", CharacterBinding::getAI },
        { "getAttackTarget", CharacterBinding::getAttackTarget },
        { "isInCombatMode", CharacterBinding::isInCombatMode },
        { "isInRangedCombatMode", CharacterBinding::isInRangedCombatMode },
        { "isLiterallyUnderMeleeAttackRightNowForSure", CharacterBinding::isLiterallyUnderMeleeAttackRightNowForSure },
        { "_isLiterallyUnderMeleeAttackRightNowForSure_update", CharacterBinding::_isLiterallyUnderMeleeAttackRightNowForSure_update },
        { "conglomerateTagsFor", CharacterBinding::conglomerateTagsFor },
        { "isPrisonerFreeToGo", CharacterBinding::isPrisonerFreeToGo },
        { "clearTempEnemyStatus", CharacterBinding::clearTempEnemyStatus },
        { "clearAllTempEnemyStatuses", CharacterBinding::clearAllTempEnemyStatuses },
        { "lastSeenInHoursAgo", CharacterBinding::lastSeenInHoursAgo },
        { "haveMetBefore", CharacterBinding::haveMetBefore },
        { "getIDForMemoryTagging", CharacterBinding::getIDForMemoryTagging },
        { "getMovement", CharacterBinding::getMovement },
        { "lookatPosition", CharacterBinding::lookatPosition },
        { "_NV_lookatPosition", CharacterBinding::_NV_lookatPosition },
        { "areYouGonnaGetMe", CharacterBinding::areYouGonnaGetMe },
        { "getAllAttackersCount", CharacterBinding::getAllAttackersCount },
        { "getRace", CharacterBinding::getRace },
        { "_NV_getRace", CharacterBinding::_NV_getRace },
        { "setRace", CharacterBinding::setRace },
        { "_NV_setRace", CharacterBinding::_NV_setRace },
        { "getRadius", CharacterBinding::getRadius },
        { "isPlayerCharacter", CharacterBinding::isPlayerCharacter },
        { "checkPlayerOrderForProblems", CharacterBinding::checkPlayerOrderForProblems },
        { "getTotalCarryWeight", CharacterBinding::getTotalCarryWeight },
        { "getCurrentWeapon", CharacterBinding::getCurrentWeapon },
        { "getThePreferredWeapon", CharacterBinding::getThePreferredWeapon },
        { "getRangedWeapon", CharacterBinding::getRangedWeapon },
        { "_NV_getRangedWeapon", CharacterBinding::_NV_getRangedWeapon },
        { "drawWeapon", CharacterBinding::drawWeapon },
        { "getUpperBodyArmour", CharacterBinding::getUpperBodyArmour },
        { "getLowerBodyArmour", CharacterBinding::getLowerBodyArmour },
        { "isInjured", CharacterBinding::isInjured },
        { "shouldUseRangedWeapons", CharacterBinding::shouldUseRangedWeapons },
        { "getBoneWorldPosition", CharacterBinding::getBoneWorldPosition },
        { "getAppearance", CharacterBinding::getAppearance },
        { "_setPlatoon", CharacterBinding::_setPlatoon },
        { "getPlatoon", CharacterBinding::getPlatoon },
        { "hasPlatoon", CharacterBinding::hasPlatoon },
        { "isInAPersistentPlatoon", CharacterBinding::isInAPersistentPlatoon },
        { "getBlackboard", CharacterBinding::getBlackboard },
        { "getSquadLeader", CharacterBinding::getSquadLeader },
        { "getOrdersReciever", CharacterBinding::getOrdersReciever },
        { "preventRagdollMode", CharacterBinding::preventRagdollMode },
        { "setPrisonMode", CharacterBinding::setPrisonMode },
        { "setBedMode", CharacterBinding::setBedMode },
        { "setSlaveAIJob", CharacterBinding::setSlaveAIJob },
        { "isChainedMode", CharacterBinding::isChainedMode },
        { "getChainedModeShackles", CharacterBinding::getChainedModeShackles },
        { "getMySlaveOwner", CharacterBinding::getMySlaveOwner },
        { "isSlave", CharacterBinding::isSlave },
        { "isMySlave", CharacterBinding::isMySlave },
        { "isMyFactionsSlave", CharacterBinding::isMyFactionsSlave },
        { "isHeadShaven", CharacterBinding::isHeadShaven },
        { "_NV_isHeadShaven", CharacterBinding::_NV_isHeadShaven },
        { "runSlaveAnim", CharacterBinding::runSlaveAnim },
        { "endSlaveAnim", CharacterBinding::endSlaveAnim },
        { "updatePortraitGUIState", CharacterBinding::updatePortraitGUIState },
        { "pickupObject", CharacterBinding::pickupObject },
        { "getPickedUp", CharacterBinding::getPickedUp },
        { "slaveAttachToBoneMode", CharacterBinding::slaveAttachToBoneMode },
        { "isDead", CharacterBinding::isDead },
        { "isBeingCarried", CharacterBinding::isBeingCarried },
        { "getCarryingObject", CharacterBinding::getCarryingObject },
        { "chooseCarryObjectLeftOrRight", CharacterBinding::chooseCarryObjectLeftOrRight },
        { "dropCarriedObject", CharacterBinding::dropCarriedObject },
        { "getDropped", CharacterBinding::getDropped },
        { "getDiplomacyMultiplier", CharacterBinding::getDiplomacyMultiplier },
        { "isEnemy", CharacterBinding::isEnemy },
        { "_NV_isEnemy", CharacterBinding::_NV_isEnemy },
        { "isAlly", CharacterBinding::isAlly },
        { "_NV_isAlly", CharacterBinding::_NV_isAlly },
        { "getDefaultTaskRepertoireEnum", CharacterBinding::getDefaultTaskRepertoireEnum },
        { "_NV_getDefaultTaskRepertoireEnum", CharacterBinding::_NV_getDefaultTaskRepertoireEnum },
        { "getAnimationClass", CharacterBinding::getAnimationClass },
        { "getPredictedPosition", CharacterBinding::getPredictedPosition },
        { "carryModeT", CharacterBinding::carryModeT },
        { "_carryMode", CharacterBinding::_carryMode },
        { "recalculateTotalEquipmentSkillBonus", CharacterBinding::recalculateTotalEquipmentSkillBonus },
        { "setupAudio", CharacterBinding::setupAudio },
        { "_NV_setupAudio", CharacterBinding::_NV_setupAudio },
        { "audioEvent", CharacterBinding::audioEvent },
        { "setGroundType", CharacterBinding::setGroundType },
        { "getGroundType", CharacterBinding::getGroundType },
        { "calculateMainArmourType", CharacterBinding::calculateMainArmourType },
        { "getMainArmourType", CharacterBinding::getMainArmourType },
        { "wearingUniformOf", CharacterBinding::wearingUniformOf },
        { "_NV_wearingUniformOf", CharacterBinding::_NV_wearingUniformOf },
        { "getUniformColorScheme", CharacterBinding::getUniformColorScheme },
        { "canTakePlayerOrdersAtThisTime", CharacterBinding::canTakePlayerOrdersAtThisTime },
        { "startEffect", CharacterBinding::startEffect },
        { "stopEffect", CharacterBinding::stopEffect },
        { "stopAllEffects", CharacterBinding::stopAllEffects },
        { "notifyEffect", CharacterBinding::notifyEffect },
        { "_NV_notifyEffect", CharacterBinding::_NV_notifyEffect },
        { "equipItem", CharacterBinding::equipItem },
        { "_NV_equipItem", CharacterBinding::_NV_equipItem },
        { "unequipItem", CharacterBinding::unequipItem },
        { "_NV_unequipItem", CharacterBinding::_NV_unequipItem },
        { "validateInventorySections", CharacterBinding::validateInventorySections },
        { "_NV_validateInventorySections", CharacterBinding::_NV_validateInventorySections },
        { "processCharacterLoadTimeMessages", CharacterBinding::processCharacterLoadTimeMessages },
        { "wantsPathfinderActive", CharacterBinding::wantsPathfinderActive },
        { "createAnimationClass", CharacterBinding::createAnimationClass },
        { "calculateDestinationState", CharacterBinding::calculateDestinationState },
        { "generateWeapon", CharacterBinding::generateWeapon },
        { "createPhysical", CharacterBinding::createPhysical },
        { "_NV_createPhysical", CharacterBinding::_NV_createPhysical },
        { "destroyPhysical", CharacterBinding::destroyPhysical },
        { "_NV_destroyPhysical", CharacterBinding::_NV_destroyPhysical },
        { "createComponents", CharacterBinding::createComponents },
        { "loadUnloadCheck", CharacterBinding::loadUnloadCheck },
        { "_NV_loadUnloadCheck", CharacterBinding::_NV_loadUnloadCheck },
        { "updateStateBroadcast", CharacterBinding::updateStateBroadcast },
        { "setEffectBT", CharacterBinding::setEffectBT },
        { "postRagdollCallback", CharacterBinding::postRagdollCallback },
        { "_NV_postRagdollCallback", CharacterBinding::_NV_postRagdollCallback },
        { "reCalculateNaturalWeapon", CharacterBinding::reCalculateNaturalWeapon },
        { "_NV_reCalculateNaturalWeapon", CharacterBinding::_NV_reCalculateNaturalWeapon },
        { "rememberCharacter", CharacterBinding::rememberCharacter },
        { "setHandle", CharacterBinding::setHandle },
        { "_NV_setHandle", CharacterBinding::_NV_setHandle },
        { "isIndoors", CharacterBinding::isIndoors },
        { "_NV_isIndoors", CharacterBinding::_NV_isIndoors },
        { "isStandingOnBuilding", CharacterBinding::isStandingOnBuilding },
        { "_NV_isStandingOnBuilding", CharacterBinding::_NV_isStandingOnBuilding },
        { "notifyIndoors", CharacterBinding::notifyIndoors },
        { "_NV_notifyIndoors", CharacterBinding::_NV_notifyIndoors },
        { "setDestinationIndoors", CharacterBinding::setDestinationIndoors },
        { "getAudioObject", CharacterBinding::getAudioObject },
        { "getName", CharacterBinding::getName },
        { "_NV_getName", CharacterBinding::_NV_getName },
        { "changeSlaveOwner", CharacterBinding::changeSlaveOwner },
        { "teleport", CharacterBinding::teleport },
        { "audioValue", CharacterBinding::audioValue },
        { "getPermajobName", CharacterBinding::getPermajobName },
        { "getAABB", CharacterBinding::getAABB },
        { "_NV_getAABB", CharacterBinding::_NV_getAABB },
        { "getAllAttackers", CharacterBinding::getAllAttackers },
        { "getCharacterMemoryTag", CharacterBinding::getCharacterMemoryTag },
        { "hitByMeleeAttack", CharacterBinding::hitByMeleeAttack },
        { "convertCutDirection", CharacterBinding::convertCutDirection },
        { "breakFollowOrderLoop", CharacterBinding::breakFollowOrderLoop },
        { "_CONSTRUCTOR", CharacterBinding::_CONSTRUCTOR },
        { "formationUpdateCallback", CharacterBinding::formationUpdateCallback },
        { "serialise", CharacterBinding::serialise },
        { "_NV_serialise", CharacterBinding::_NV_serialise },
        { "hasItemsFrom", CharacterBinding::hasItemsFrom },
        { "_NV_hasItemsFrom", CharacterBinding::_NV_hasItemsFrom },
        { "getLockpickChance", CharacterBinding::getLockpickChance },
        { "debugIndicateCharacters", CharacterBinding::debugIndicateCharacters },
        { "iShotYou", CharacterBinding::iShotYou },
        { "_startStumble", CharacterBinding::_startStumble },
        { "getSquadMissionTarget", CharacterBinding::getSquadMissionTarget },
        { "setChainedMode", CharacterBinding::setChainedMode },
        { "_ragdollMode", CharacterBinding::_ragdollMode },
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
    lua_pushcfunction(L, Character_get_naturalWeapon);
    lua_setfield(L, -2, "naturalWeapon");
    lua_pushcfunction(L, Character_get_disguiseGUIFeedbacks);
    lua_setfield(L, -2, "disguiseGUIFeedbacks");
    lua_pushcfunction(L, Character_get_whoSeesMeSneaking);
    lua_setfield(L, -2, "whoSeesMeSneaking");
    lua_pushcfunction(L, Character_get_inSomething);
    lua_setfield(L, -2, "inSomething");
    lua_pushcfunction(L, Character_get_audioObject);
    lua_setfield(L, -2, "audioObject");
    lua_pushcfunction(L, Character_get_activeEffects);
    lua_setfield(L, -2, "activeEffects");
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
    lua_pushcfunction(L, Character_set_isVisibleAndNear);
    lua_setfield(L, -2, "isVisibleAndNear");
    lua_pushcfunction(L, Character_set_isOnScreen);
    lua_setfield(L, -2, "isOnScreen");
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
    lua_pushcfunction(L, Character_set_lastGuyWhoDefeatedMe);
    lua_setfield(L, -2, "lastGuyWhoDefeatedMe");
    lua_pushcfunction(L, Character_set_myRace);
    lua_setfield(L, -2, "myRace");
    lua_pushcfunction(L, Character_set_inventory);
    lua_setfield(L, -2, "inventory");
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
    lua_pushcfunction(L, Character_set_squadMemberID);
    lua_setfield(L, -2, "squadMemberID");
    lua_pushcfunction(L, Character_set_diplomacyMultiplier);
    lua_setfield(L, -2, "diplomacyMultiplier");
    lua_pushcfunction(L, Character_set__destinationInsideBuilding);
    lua_setfield(L, -2, "_destinationInsideBuilding");
    lua_pushcfunction(L, Character_set__destinationInsideWalls);
    lua_setfield(L, -2, "_destinationInsideWalls");
    lua_pushcfunction(L, Character_set_stats);
    lua_setfield(L, -2, "stats");
    lua_pushcfunction(L, Character_set_medical);
    lua_setfield(L, -2, "medical");
    lua_pushcfunction(L, Character_set_isPhysicalMode);
    lua_setfield(L, -2, "isPhysicalMode");
    lua_pushcfunction(L, Character_set_sex);
    lua_setfield(L, -2, "sex");
    lua_pushcfunction(L, Character_set_movement);
    lua_setfield(L, -2, "movement");
    lua_pushcfunction(L, Character_set_body);
    lua_setfield(L, -2, "body");
    lua_pushcfunction(L, Character_set_platoon);
    lua_setfield(L, -2, "platoon");
    lua_pushcfunction(L, Character_set_portraitIndex);
    lua_setfield(L, -2, "portraitIndex");
    lua_pushcfunction(L, Character_set_portraitSerial);
    lua_setfield(L, -2, "portraitSerial");
    lua_pushcfunction(L, Character_set_groundType);
    lua_setfield(L, -2, "groundType");
    lua_pushcfunction(L, Character_set_armourType);
    lua_setfield(L, -2, "armourType");
    lua_pushcfunction(L, Character_set_terrainHeightPosition);
    lua_setfield(L, -2, "terrainHeightPosition");
    lua_pushcfunction(L, Character_set_inDoorsSetCooldown);
    lua_setfield(L, -2, "inDoorsSetCooldown");
    lua_pushcfunction(L, Character_set_naturalWeapon);
    lua_setfield(L, -2, "naturalWeapon");
    lua_pushcfunction(L, Character_set_stateBroadcast);
    lua_setfield(L, -2, "stateBroadcast");
    lua_pushcfunction(L, Character_set__myMemory);
    lua_setfield(L, -2, "_myMemory");
    lua_pushcfunction(L, Character_set_rangedCombat);
    lua_setfield(L, -2, "rangedCombat");
    lua_pushcfunction(L, Character_set_inSomething);
    lua_setfield(L, -2, "inSomething");
    lua_pushcfunction(L, Character_set_msgCarryMode);
    lua_setfield(L, -2, "msgCarryMode");
    lua_pushcfunction(L, Character_set_animation);
    lua_setfield(L, -2, "animation");
    lua_pushcfunction(L, Character_set_nameTag);
    lua_setfield(L, -2, "nameTag");
    lua_pushcfunction(L, Character_set_ai);
    lua_setfield(L, -2, "ai");
    lua_pushcfunction(L, Character_set_audioObject);
    lua_setfield(L, -2, "audioObject");
    lua_pushcfunction(L, Character_set_audioEmitter);
    lua_setfield(L, -2, "audioEmitter");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to RootObject
    // setMetatableParent(L, CharacterBinding::getMetatableName(), RootObjectBinding::getMetatableName());

    LektorPtrBinding<Character*>::registerBinding(L, "lektor<Character*>", CharacterBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua