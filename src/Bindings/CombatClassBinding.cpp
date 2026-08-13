#include "pch.h"
#include "kenshi\CombatClass.h"
#include "CombatClassBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharMovementBinding.h"
#include "Bindings/CharStatsBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/CombatTechniqueDataBinding.h"
#include "Bindings/DamagesBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/MedicalSystemBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"
#include "Bindings/AttackSlotManagerBinding.h"

namespace KenshiLua
{

typedef OgreUnorderedMapBinding<swordStateEnum, CombatState*> SwordStateMapBinding;

static CombatClass* getInstance(lua_State* L, int idx)
{
    return checkObject<CombatClass>(L, idx, CombatClassBinding::getMetatableName());
}

// --- Getters for CombatClass ---
static int CombatClass_get_attackSlots(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    return pushObject<CombatClass::AttackSlotManager>(L, &instance->attackSlots, AttackSlotManagerBinding::getMetatableName());
}

static int CombatClass_get_wantsToBlock(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushboolean(L, instance->wantsToBlock ? 1 : 0);
    return 1;
}

static int CombatClass_get_isStumbleBlocking(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushboolean(L, instance->isStumbleBlocking ? 1 : 0);
    return 1;
}

static int CombatClass_get_stumbleTimer(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushnumber(L, instance->stumbleTimer);
    return 1;
}

static int CombatClass_get_whenCanStopStumble(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushnumber(L, instance->whenCanStopStumble);
    return 1;
}

static int CombatClass_get_stumbleForce(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushnumber(L, instance->stumbleForce);
    return 1;
}

static int CombatClass_get_combatModeActive(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushboolean(L, instance->combatModeActive ? 1 : 0);
    return 1;
}

static int CombatClass_get_lastCombatModeTimeStamp(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushnumber(L, instance->lastCombatModeTimeStamp);
    return 1;
}

static int CombatClass_get__isAttacking(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushnumber(L, instance->_isAttacking);
    return 1;
}

static int CombatClass_get_inDeadTime(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushboolean(L, instance->inDeadTime ? 1 : 0);
    return 1;
}

static int CombatClass_get_deadTimer(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushnumber(L, instance->deadTimer);
    return 1;
}

static int CombatClass_get_stateTimer(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushnumber(L, instance->stateTimer);
    return 1;
}

static int CombatClass_get_currentTechnique(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    return pushObject<CombatTechniqueData>(L, instance->currentTechnique, CombatTechniqueDataBinding::getMetatableName());
}

static int CombatClass_get_currentTechniqueHasFinished(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushboolean(L, instance->currentTechniqueHasFinished ? 1 : 0);
    return 1;
}

static int CombatClass_get_attackStartPos(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    pushVector3(L, instance->attackStartPos);
    return 1;
}

static int CombatClass_get_frameTIME(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushnumber(L, instance->frameTIME);
    return 1;
}

static int CombatClass_get_movement(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    return pushObject<CharMovement>(L, instance->movement, CharMovementBinding::getMetatableName());
}

static int CombatClass_get_ai(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushlightuserdata(L, (void*)instance->ai);
    return 1;
}

static int CombatClass_get_animation(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushlightuserdata(L, (void*)instance->animation);
    return 1;
}

static int CombatClass_get_me(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    return pushObject<Character>(L, instance->me, CharacterBinding::getMetatableName());
}

static int CombatClass_get_stats(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    return pushObject<CharStats>(L, instance->stats, CharStatsBinding::getMetatableName());
}

static int CombatClass_get_medical(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    return pushObject<MedicalSystem>(L, instance->medical, MedicalSystemBinding::getMetatableName());
}

static int CombatClass_get_myRadiusX(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushnumber(L, instance->myRadiusX);
    return 1;
}

static int CombatClass_get_blockingTarget(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    return pushObject<Character>(L, instance->blockingTarget, CharacterBinding::getMetatableName());
}

static int CombatClass_get_blockingTargetH(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    return HandBinding::push(L, instance->blockingTargetH);
}

static int CombatClass_get_targetsInAttackZone(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    return pushObject<lektor<hand>>(L, &instance->targetsInAttackZone, LektorValueReadOnlyBinding<hand>::metaName);
}

static int CombatClass_get_attackersH(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    return pushObject<lektor<hand>>(L, &instance->attackersH, LektorValueReadOnlyBinding<hand>::metaName);
}

static int CombatClass_get_threats(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    return pushObject<lektor<Character*>>(L, &instance->threats, LektorPtrBinding<Character*>::metaName);
}

static int CombatClass_get_threatsH(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    return pushObject<lektor<hand>>(L, &instance->threatsH, LektorValueReadOnlyBinding<hand>::metaName);
}

static int CombatClass_get_notifiedThreats(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    return pushObject<lektor<hand>>(L, &instance->notifiedThreats, LektorValueReadOnlyBinding<hand>::metaName);
}

static int CombatClass_get_lastIncomingAttackComboSection(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushinteger(L, instance->lastIncomingAttackComboSection);
    return 1;
}

static int CombatClass_get_calculatedTargetsInAttackZoneThisFrame(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushboolean(L, instance->calculatedTargetsInAttackZoneThisFrame ? 1 : 0);
    return 1;
}

static int CombatClass_get_combatState(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushinteger(L, (lua_Integer)instance->combatState);
    return 1;
}

static int CombatClass_get_nextMove(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushinteger(L, (lua_Integer)instance->nextMove);
    return 1;
}

static int CombatClass_get_numEnemiesWaitingForMe1(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushinteger(L, instance->numEnemiesWaitingForMe1);
    return 1;
}

static int CombatClass_get_numEnemiesWaitingForMe2(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushinteger(L, instance->numEnemiesWaitingForMe2);
    return 1;
}

static int CombatClass_get_waitCountAlternator(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushboolean(L, instance->waitCountAlternator ? 1 : 0);
    return 1;
}

static int CombatClass_get_currentComboSection(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushinteger(L, instance->currentComboSection);
    return 1;
}

static int CombatClass_get_lastComboSection(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushinteger(L, instance->lastComboSection);
    return 1;
}

static int CombatClass_get_lastSoundIndex(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushinteger(L, instance->lastSoundIndex);
    return 1;
}

static int CombatClass_get_techniqueIntegrityCheckTimer(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushnumber(L, instance->techniqueIntegrityCheckTimer);
    return 1;
}

static int CombatClass_get_MEI_MIN(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushnumber(L, instance->MEI_MIN);
    return 1;
}

static int CombatClass_get_MEI_MAX(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushnumber(L, instance->MEI_MAX);
    return 1;
}

static int CombatClass_get_MINIMUM_DISTANCE_TO_OTHERS(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushnumber(L, instance->MINIMUM_DISTANCE_TO_OTHERS);
    return 1;
}

static int CombatClass_get_BLOCKING_MEI_DISTANCE_MIN(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushnumber(L, instance->BLOCKING_MEI_DISTANCE_MIN);
    return 1;
}

static int CombatClass_get_BLOCKING_MEI_DISTANCE_MAX(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    lua_pushnumber(L, instance->BLOCKING_MEI_DISTANCE_MAX);
    return 1;
}

static int CombatClass_get_currentTarget(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    return pushObject<Character>(L, instance->currentTarget, CharacterBinding::getMetatableName());
}

static int CombatClass_get_currentTargetHandle(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    return HandBinding::push(L, instance->currentTargetHandle);
}

static int CombatClass_get_stateMap(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    return pushObject<SwordStateMapBinding::MapType>(L, &instance->stateMap, "ogre_unordered_map<swordStateEnum, CombatState*>");
}

// --- Setters for CombatClass ---
static int CombatClass_set_attackSlots(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    CombatClass::AttackSlotManager* val = checkObject<CombatClass::AttackSlotManager>(L, 2, AttackSlotManagerBinding::getMetatableName());
    if (!val) return luaL_error(L, "Expected AttackSlotManager object");
    instance->attackSlots = *val;
    return 0;
}

static int CombatClass_set_wantsToBlock(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->wantsToBlock = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatClass_set_isStumbleBlocking(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->isStumbleBlocking = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatClass_set_stumbleTimer(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->stumbleTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatClass_set_whenCanStopStumble(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->whenCanStopStumble = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatClass_set_stumbleForce(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->stumbleForce = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatClass_set_combatModeActive(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->combatModeActive = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatClass_set_lastCombatModeTimeStamp(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->lastCombatModeTimeStamp = (double)luaL_checknumber(L, 2);
    return 0;
}

static int CombatClass_set__isAttacking(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->_isAttacking = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatClass_set_inDeadTime(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->inDeadTime = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatClass_set_deadTimer(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->deadTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatClass_set_stateTimer(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->stateTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatClass_set_currentTechnique(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->currentTechnique = lua_isnoneornil(L, 2) ? nullptr : checkObject<CombatTechniqueData>(L, 2, CombatTechniqueDataBinding::getMetatableName());
    return 0;
}

static int CombatClass_set_currentTechniqueHasFinished(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->currentTechniqueHasFinished = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatClass_set_attackStartPos(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    readVector3(L, 2, instance->attackStartPos);
    return 0;
}

static int CombatClass_set_frameTIME(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->frameTIME = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatClass_set_movement(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->movement = lua_isnoneornil(L, 2) ? nullptr : checkObject<CharMovement>(L, 2, CharMovementBinding::getMetatableName());
    return 0;
}

static int CombatClass_set_me(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->me = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int CombatClass_set_stats(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->stats = lua_isnoneornil(L, 2) ? nullptr : checkObject<CharStats>(L, 2, CharStatsBinding::getMetatableName());
    return 0;
}

static int CombatClass_set_medical(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->medical = lua_isnoneornil(L, 2) ? nullptr : checkObject<MedicalSystem>(L, 2, MedicalSystemBinding::getMetatableName());
    return 0;
}

static int CombatClass_set_myRadiusX(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->myRadiusX = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatClass_set_blockingTarget(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->blockingTarget = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int CombatClass_set_blockingTargetH(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->blockingTargetH = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int CombatClass_set_attackersH(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    auto* val = checkObject<lektor<hand>>(L, 2, LektorValueReadOnlyBinding<hand>::metaName);
    if (val) instance->attackersH = *val;
    return 0;
}

static int CombatClass_set_threats(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    auto* val = checkObject<lektor<Character*>>(L, 2, LektorPtrBinding<Character*>::metaName);
    if (val) instance->threats = *val;
    return 0;
}

static int CombatClass_set_threatsH(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    auto* val = checkObject<lektor<hand>>(L, 2, LektorValueReadOnlyBinding<hand>::metaName);
    if (val) instance->threatsH = *val;
    return 0;
}

static int CombatClass_set_notifiedThreats(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    auto* val = checkObject<lektor<hand>>(L, 2, LektorValueReadOnlyBinding<hand>::metaName);
    if (val) instance->notifiedThreats = *val;
    return 0;
}

static int CombatClass_set_currentTargetHandle(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (h) instance->currentTargetHandle = *h;
    return 0;
}

static int CombatClass_set_lastIncomingAttackComboSection(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->lastIncomingAttackComboSection = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CombatClass_set_calculatedTargetsInAttackZoneThisFrame(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->calculatedTargetsInAttackZoneThisFrame = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatClass_set_combatState(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->combatState = (swordStateEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int CombatClass_set_nextMove(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->nextMove = (swordStateEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int CombatClass_set_numEnemiesWaitingForMe1(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->numEnemiesWaitingForMe1 = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CombatClass_set_numEnemiesWaitingForMe2(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->numEnemiesWaitingForMe2 = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CombatClass_set_waitCountAlternator(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->waitCountAlternator = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatClass_set_currentComboSection(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->currentComboSection = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CombatClass_set_lastComboSection(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->lastComboSection = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CombatClass_set_lastSoundIndex(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->lastSoundIndex = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CombatClass_set_techniqueIntegrityCheckTimer(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->techniqueIntegrityCheckTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatClass_set_MEI_MIN(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->MEI_MIN = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatClass_set_MEI_MAX(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->MEI_MAX = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatClass_set_MINIMUM_DISTANCE_TO_OTHERS(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->MINIMUM_DISTANCE_TO_OTHERS = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatClass_set_BLOCKING_MEI_DISTANCE_MIN(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->BLOCKING_MEI_DISTANCE_MIN = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatClass_set_BLOCKING_MEI_DISTANCE_MAX(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->BLOCKING_MEI_DISTANCE_MAX = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatClass_set_currentTarget(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->currentTarget = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int CombatClass_set_stateMap(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    auto* val = SwordStateMapBinding::get(L, 2);
    if (val) instance->stateMap = *val;
    return 0;
}

int CombatClassBinding::_DESTRUCTOR(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int CombatClassBinding::isAI(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    bool result = instance->isAI();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatClassBinding::_NV_isAI(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    bool result = instance->_NV_isAI();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatClassBinding::go(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    float _frameTime = (float)luaL_checknumber(L, 2);
    instance->go(_frameTime);
    return 0;
}

int CombatClassBinding::_NV_go(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    float _frameTime = (float)luaL_checknumber(L, 2);
    instance->_NV_go(_frameTime);
    return 0;
}

int CombatClassBinding::getCombatState(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    swordStateEnum result = instance->getCombatState();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CombatClassBinding::getBlockStateEnum(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    swordStateEnum result = instance->getBlockStateEnum();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CombatClassBinding::periodicUpdate(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->periodicUpdate(time);
    return 0;
}

int CombatClassBinding::_NV_periodicUpdate(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->_NV_periodicUpdate(time);
    return 0;
}

int CombatClassBinding::isAttacking(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float result = instance->isAttacking(who);
    lua_pushnumber(L, result);
    return 1;
}

int CombatClassBinding::informOfFreeAttackSlot(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    Character* _a1 = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->informOfFreeAttackSlot(_a1);
    return 0;
}

int CombatClassBinding::_NV_informOfFreeAttackSlot(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    Character* _a1 = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->_NV_informOfFreeAttackSlot(_a1);
    return 0;
}

int CombatClassBinding::isStationary(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    bool result = instance->isStationary();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatClassBinding::_getAttackTarget(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    hand result = instance->_getAttackTarget();
    return HandBinding::push(L, result);
}

int CombatClassBinding::isFightingAnAllyOfMine(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->isFightingAnAllyOfMine(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatClassBinding::getCurrentTechnique(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    CombatTechniqueData* result = instance->getCurrentTechnique();
    return pushObject<CombatTechniqueData>(L, result, CombatTechniqueDataBinding::getMetatableName());
}

int CombatClassBinding::getCurrentTechniqueSection(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    int result = instance->getCurrentTechniqueSection();
    lua_pushinteger(L, result);
    return 1;
}

int CombatClassBinding::getMeiMin(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    float result = instance->getMeiMin();
    lua_pushnumber(L, result);
    return 1;
}

int CombatClassBinding::areYouFightingAndInNeedOfHelp(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    float result = instance->areYouFightingAndInNeedOfHelp();
    lua_pushnumber(L, result);
    return 1;
}

int CombatClassBinding::getNumOpponents(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    int result = instance->getNumOpponents();
    lua_pushinteger(L, result);
    return 1;
}

int CombatClassBinding::getTotalRelativeStrengthOfAttackers(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    float result = instance->getTotalRelativeStrengthOfAttackers();
    lua_pushnumber(L, result);
    return 1;
}

int CombatClassBinding::_isInCombatMode(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    bool result = instance->_isInCombatMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatClassBinding::checkForBadHandles(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    instance->checkForBadHandles();
    return 0;
}

int CombatClassBinding::addAttackerH(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->addAttackerH(c);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatClassBinding::isInAttackerListH(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->isInAttackerListH(c);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatClassBinding::removeAttackerH(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->removeAttackerH(c);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatClassBinding::getAttackAimAdjustmentThreshold(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    Character* target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float result = instance->getAttackAimAdjustmentThreshold(target);
    lua_pushnumber(L, result);
    return 1;
}

int CombatClassBinding::getNumWaitingAttackers(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    int result = instance->getNumWaitingAttackers();
    lua_pushinteger(L, result);
    return 1;
}

int CombatClassBinding::readyToFinishCombatMode(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    bool result = instance->readyToFinishCombatMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatClassBinding::getTimeSinceLastCombatModeInHours(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    float result = instance->getTimeSinceLastCombatModeInHours();
    lua_pushnumber(L, result);
    return 1;
}

int CombatClassBinding::hasFocusedTarget(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    hand result = instance->hasFocusedTarget();
    return HandBinding::push(L, result);
}

int CombatClassBinding::_NV_hasFocusedTarget(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    hand result = instance->_NV_hasFocusedTarget();
    return HandBinding::push(L, result);
}

int CombatClassBinding::changeState(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    swordStateEnum newState = (swordStateEnum)luaL_checkinteger(L, 2);
    float minTime = (float)luaL_checknumber(L, 3);
    instance->changeState(newState, minTime);
    return 0;
}

int CombatClassBinding::getStateClass(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    swordStateEnum state = (swordStateEnum)luaL_checkinteger(L, 2);
    CombatState* result = instance->getStateClass(state);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int CombatClassBinding::_NV_getStateClass(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    swordStateEnum state = (swordStateEnum)luaL_checkinteger(L, 2);
    CombatState* result = instance->_NV_getStateClass(state);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int CombatClassBinding::update(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    float frameTIME = (float)luaL_checknumber(L, 2);
    instance->update(frameTIME);
    return 0;
}

int CombatClassBinding::_NV_update(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    float frameTIME = (float)luaL_checknumber(L, 2);
    instance->_NV_update(frameTIME);
    return 0;
}

int CombatClassBinding::getMeiMax(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    float result = instance->getMeiMax();
    lua_pushnumber(L, result);
    return 1;
}

int CombatClassBinding::startupState(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    bool result = instance->startupState();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatClassBinding::_NV_startupState(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    bool result = instance->_NV_startupState();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatClassBinding::stumbleState(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    instance->stumbleState();
    return 0;
}

int CombatClassBinding::_isAttackingUpdate(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    float result = instance->_isAttackingUpdate();
    lua_pushnumber(L, result);
    return 1;
}

int CombatClassBinding::canBlock(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    bool result = instance->canBlock();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatClassBinding::attackState(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    bool result = instance->attackState();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatClassBinding::_NV_attackState(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    bool result = instance->_NV_attackState();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatClassBinding::checkForNeedBlock(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    float thresholdMyAttack = (float)luaL_checknumber(L, 2);
    float thresholdIncomingAttack = (float)luaL_checknumber(L, 3);
    bool result = instance->checkForNeedBlock(thresholdMyAttack, thresholdIncomingAttack);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatClassBinding::setCombatState(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    swordStateEnum state = (swordStateEnum)luaL_checkinteger(L, 2);
    instance->setCombatState(state);
    return 0;
}

int CombatClassBinding::initialiseBlock(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    bool isStumbling = lua_toboolean(L, 2) != 0;
    bool result = instance->initialiseBlock(isStumbling);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatClassBinding::blockState(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    bool stumbleBlocking = lua_toboolean(L, 2) != 0;
    bool result = instance->blockState(stumbleBlocking);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatClassBinding::_NV_blockState(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    bool stumbleBlocking = lua_toboolean(L, 2) != 0;
    bool result = instance->_NV_blockState(stumbleBlocking);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatClassBinding::blockWaitingState(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    instance->blockWaitingState();
    return 0;
}

int CombatClassBinding::attackImpactCheck(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    instance->attackImpactCheck();
    return 0;
}

int CombatClassBinding::calculateTargetsInAttackZone(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    instance->calculateTargetsInAttackZone();
    return 0;
}

int CombatClassBinding::isInAttackZone(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->isInAttackZone(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatClassBinding::getNearestEnemyInAttackZone(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    Character* result = instance->getNearestEnemyInAttackZone();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int CombatClassBinding::notifyBlockNeeded(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    instance->notifyBlockNeeded();
    return 0;
}

int CombatClassBinding::weaponReach(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    float result = instance->weaponReach();
    lua_pushnumber(L, result);
    return 1;
}

int CombatClassBinding::gotMoreImportantThingsToDoThanFightingYou(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->gotMoreImportantThingsToDoThanFightingYou(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatClassBinding::_NV_gotMoreImportantThingsToDoThanFightingYou(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->_NV_gotMoreImportantThingsToDoThanFightingYou(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatClassBinding::setAttackTarget(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->setAttackTarget(c);
    return 0;
}

int CombatClassBinding::setAttackTargetHandle(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->setAttackTargetHandle(c);
    return 0;
}

int CombatClassBinding::lookatTarget(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    Character* target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->lookatTarget(target);
    return 0;
}

int CombatClassBinding::packPtrsToHandles(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    instance->packPtrsToHandles();
    return 0;
}

int CombatClassBinding::_NV_packPtrsToHandles(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    instance->_NV_packPtrsToHandles();
    return 0;
}

int CombatClassBinding::unpackHandlesToPtrs(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    instance->unpackHandlesToPtrs();
    return 0;
}

int CombatClassBinding::_NV_unpackHandlesToPtrs(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    instance->_NV_unpackHandlesToPtrs();
    return 0;
}


// --- Static Methods ---
int CombatClassBinding::setup(lua_State* L)
{
    CombatClass::setup();
    return 0;
}

int CombatClassBinding::destroy(lua_State* L)
{
    CombatClass::destroy();
    return 0;
}

int CombatClassBinding::getCombatEffect(lua_State* L)
{
    Character* attacker = checkObject<Character>(L, 1, CharacterBinding::getMetatableName());
    Character* victim = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    Damages* damage = checkObject<Damages>(L, 3, DamagesBinding::getMetatableName());
    if (!damage) return luaL_error(L, "Expected Damages");
    HitMaterialType hitType = (HitMaterialType)luaL_checkinteger(L, 4);

    GameData* res = CombatClass::getCombatEffect(attacker, victim, *damage, hitType);
    return pushObject<GameData>(L, res, GameDataBinding::getMetatableName());
}

int CombatClassBinding::addEffect(lua_State* L)
{
    GameData* effectData = checkObject<GameData>(L, 1, GameDataBinding::getMetatableName());
    hand* character = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!character) return luaL_error(L, "Expected hand");
    const char* boneName = luaL_checkstring(L, 3);
    Ogre::Vector3 pos;
    readVector3(L, 4, pos);
    Ogre::Quaternion rot;
    readQuaternion(L, 5, rot);

    CombatClass::addEffect(effectData, *character, boneName, pos, rot);
    return 0;
}

int CombatClassBinding::shiftEffects(lua_State* L)
{
    Ogre::Vector3 shift;
    readVector3(L, 1, shift);
    CombatClass::shiftEffects(shift);
    return 0;
}

int CombatClassBinding::updateEffects(lua_State* L)
{
    CombatClass::updateEffects();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 64: bool initCombatMode(...) - non-string reference arg
  line 65: bool _NV_initCombatMode(...) - non-string reference arg
  line 72: swordStateEnum whoAttacksYouOrMe(...) - non-string reference arg
  line 73: HitMaterialType _iHitYouAreYouHit(...) - non-string reference arg
  line 74: void _getHit(...) - non-string reference arg
  line 75: void _blockHit(...) - non-string reference arg
  line 87: lektor<hand>& getAttackers(...) - reference return type
  line 134: void youDoKnowImAttackingYouRight(...) - non-string reference arg
  line 149: CombatClass* _CONSTRUCTOR(...) - unsupported arg type
  line 201: void assessIncomingAttacks(...) - unsupported arg type
  line 212: void calculateCurrentTechniqueSection(...) - non-string reference arg
  line 220: Character* getBiggestThreat(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - CombatClass_get_ai: AI* (unbound pointer)
  - CombatClass_get_animation: AnimationClass* (unbound pointer)
  - CombatClassBinding::getStateClass: CombatState* (unbound pointer)
  - CombatClassBinding::_NV_getStateClass: CombatState* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 198: targetsInAttackZone (lektor<hand>) - unsupported type
  line 205: attackersH (lektor<hand>) - unsupported type
  line 209: threats (lektor<Character*>) - unsupported type
  line 210: threatsH (lektor<hand>) - unsupported type
  line 211: notifiedThreats (lektor<hand>) - unsupported type
*/

int CombatClassBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int CombatClassBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CombatClass object");
    return 1;
}

void CombatClassBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CombatClassBinding::gc },
        { "__tostring", CombatClassBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", CombatClassBinding::_DESTRUCTOR },
        { "isAI", CombatClassBinding::isAI },
        { "_NV_isAI", CombatClassBinding::_NV_isAI },
        { "go", CombatClassBinding::go },
        { "_NV_go", CombatClassBinding::_NV_go },
        { "getCombatState", CombatClassBinding::getCombatState },
        { "getBlockStateEnum", CombatClassBinding::getBlockStateEnum },
        { "periodicUpdate", CombatClassBinding::periodicUpdate },
        { "_NV_periodicUpdate", CombatClassBinding::_NV_periodicUpdate },
        { "isAttacking", CombatClassBinding::isAttacking },
        { "informOfFreeAttackSlot", CombatClassBinding::informOfFreeAttackSlot },
        { "_NV_informOfFreeAttackSlot", CombatClassBinding::_NV_informOfFreeAttackSlot },
        { "isStationary", CombatClassBinding::isStationary },
        { "_getAttackTarget", CombatClassBinding::_getAttackTarget },
        { "isFightingAnAllyOfMine", CombatClassBinding::isFightingAnAllyOfMine },
        { "getCurrentTechnique", CombatClassBinding::getCurrentTechnique },
        { "getCurrentTechniqueSection", CombatClassBinding::getCurrentTechniqueSection },
        { "getMeiMin", CombatClassBinding::getMeiMin },
        { "areYouFightingAndInNeedOfHelp", CombatClassBinding::areYouFightingAndInNeedOfHelp },
        { "getNumOpponents", CombatClassBinding::getNumOpponents },
        { "getTotalRelativeStrengthOfAttackers", CombatClassBinding::getTotalRelativeStrengthOfAttackers },
        { "_isInCombatMode", CombatClassBinding::_isInCombatMode },
        { "checkForBadHandles", CombatClassBinding::checkForBadHandles },
        { "addAttackerH", CombatClassBinding::addAttackerH },
        { "isInAttackerListH", CombatClassBinding::isInAttackerListH },
        { "removeAttackerH", CombatClassBinding::removeAttackerH },
        { "getAttackAimAdjustmentThreshold", CombatClassBinding::getAttackAimAdjustmentThreshold },
        { "getNumWaitingAttackers", CombatClassBinding::getNumWaitingAttackers },
        { "readyToFinishCombatMode", CombatClassBinding::readyToFinishCombatMode },
        { "getTimeSinceLastCombatModeInHours", CombatClassBinding::getTimeSinceLastCombatModeInHours },
        { "hasFocusedTarget", CombatClassBinding::hasFocusedTarget },
        { "_NV_hasFocusedTarget", CombatClassBinding::_NV_hasFocusedTarget },
        { "changeState", CombatClassBinding::changeState },
        { "getStateClass", CombatClassBinding::getStateClass },
        { "_NV_getStateClass", CombatClassBinding::_NV_getStateClass },
        { "update", CombatClassBinding::update },
        { "_NV_update", CombatClassBinding::_NV_update },
        { "getMeiMax", CombatClassBinding::getMeiMax },
        { "startupState", CombatClassBinding::startupState },
        { "_NV_startupState", CombatClassBinding::_NV_startupState },
        { "stumbleState", CombatClassBinding::stumbleState },
        { "_isAttackingUpdate", CombatClassBinding::_isAttackingUpdate },
        { "canBlock", CombatClassBinding::canBlock },
        { "attackState", CombatClassBinding::attackState },
        { "_NV_attackState", CombatClassBinding::_NV_attackState },
        { "checkForNeedBlock", CombatClassBinding::checkForNeedBlock },
        { "setCombatState", CombatClassBinding::setCombatState },
        { "initialiseBlock", CombatClassBinding::initialiseBlock },
        { "blockState", CombatClassBinding::blockState },
        { "_NV_blockState", CombatClassBinding::_NV_blockState },
        { "blockWaitingState", CombatClassBinding::blockWaitingState },
        { "attackImpactCheck", CombatClassBinding::attackImpactCheck },
        { "calculateTargetsInAttackZone", CombatClassBinding::calculateTargetsInAttackZone },
        { "isInAttackZone", CombatClassBinding::isInAttackZone },
        { "getNearestEnemyInAttackZone", CombatClassBinding::getNearestEnemyInAttackZone },
        { "notifyBlockNeeded", CombatClassBinding::notifyBlockNeeded },
        { "weaponReach", CombatClassBinding::weaponReach },
        { "gotMoreImportantThingsToDoThanFightingYou", CombatClassBinding::gotMoreImportantThingsToDoThanFightingYou },
        { "_NV_gotMoreImportantThingsToDoThanFightingYou", CombatClassBinding::_NV_gotMoreImportantThingsToDoThanFightingYou },
        { "setAttackTarget", CombatClassBinding::setAttackTarget },
        { "setAttackTargetHandle", CombatClassBinding::setAttackTargetHandle },
        { "lookatTarget", CombatClassBinding::lookatTarget },
        { "packPtrsToHandles", CombatClassBinding::packPtrsToHandles },
        { "_NV_packPtrsToHandles", CombatClassBinding::_NV_packPtrsToHandles },
        { "unpackHandlesToPtrs", CombatClassBinding::unpackHandlesToPtrs },
        { "_NV_unpackHandlesToPtrs", CombatClassBinding::_NV_unpackHandlesToPtrs },
        { 0, 0 }
    };

    registerClass(
        L, 
        CombatClassBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CombatClassBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "attackSlots", CombatClass_get_attackSlots);
    registerGetter(L, "wantsToBlock", CombatClass_get_wantsToBlock);
    registerGetter(L, "isStumbleBlocking", CombatClass_get_isStumbleBlocking);
    registerGetter(L, "stumbleTimer", CombatClass_get_stumbleTimer);
    registerGetter(L, "whenCanStopStumble", CombatClass_get_whenCanStopStumble);
    registerGetter(L, "stumbleForce", CombatClass_get_stumbleForce);
    registerGetter(L, "combatModeActive", CombatClass_get_combatModeActive);
    registerGetter(L, "lastCombatModeTimeStamp", CombatClass_get_lastCombatModeTimeStamp);
    registerGetter(L, "_isAttacking", CombatClass_get__isAttacking);
    registerGetter(L, "inDeadTime", CombatClass_get_inDeadTime);
    registerGetter(L, "deadTimer", CombatClass_get_deadTimer);
    registerGetter(L, "stateTimer", CombatClass_get_stateTimer);
    registerGetter(L, "currentTechnique", CombatClass_get_currentTechnique);
    registerGetter(L, "currentTechniqueHasFinished", CombatClass_get_currentTechniqueHasFinished);
    registerGetter(L, "attackStartPos", CombatClass_get_attackStartPos);
    registerGetter(L, "frameTIME", CombatClass_get_frameTIME);
    registerGetter(L, "movement", CombatClass_get_movement);
    registerGetter(L, "ai", CombatClass_get_ai);
    registerGetter(L, "animation", CombatClass_get_animation);
    registerGetter(L, "me", CombatClass_get_me);
    registerGetter(L, "stats", CombatClass_get_stats);
    registerGetter(L, "medical", CombatClass_get_medical);
    registerGetter(L, "myRadiusX", CombatClass_get_myRadiusX);
    registerGetter(L, "blockingTarget", CombatClass_get_blockingTarget);
    registerGetter(L, "blockingTargetH", CombatClass_get_blockingTargetH);
    registerGetter(L, "lastIncomingAttackComboSection", CombatClass_get_lastIncomingAttackComboSection);
    registerGetter(L, "calculatedTargetsInAttackZoneThisFrame", CombatClass_get_calculatedTargetsInAttackZoneThisFrame);
    registerGetter(L, "combatState", CombatClass_get_combatState);
    registerGetter(L, "nextMove", CombatClass_get_nextMove);
    registerGetter(L, "numEnemiesWaitingForMe1", CombatClass_get_numEnemiesWaitingForMe1);
    registerGetter(L, "numEnemiesWaitingForMe2", CombatClass_get_numEnemiesWaitingForMe2);
    registerGetter(L, "waitCountAlternator", CombatClass_get_waitCountAlternator);
    registerGetter(L, "currentComboSection", CombatClass_get_currentComboSection);
    registerGetter(L, "lastComboSection", CombatClass_get_lastComboSection);
    registerGetter(L, "lastSoundIndex", CombatClass_get_lastSoundIndex);
    registerGetter(L, "techniqueIntegrityCheckTimer", CombatClass_get_techniqueIntegrityCheckTimer);
    registerGetter(L, "MEI_MIN", CombatClass_get_MEI_MIN);
    registerGetter(L, "MEI_MAX", CombatClass_get_MEI_MAX);
    registerGetter(L, "MINIMUM_DISTANCE_TO_OTHERS", CombatClass_get_MINIMUM_DISTANCE_TO_OTHERS);
    registerGetter(L, "BLOCKING_MEI_DISTANCE_MIN", CombatClass_get_BLOCKING_MEI_DISTANCE_MIN);
    registerGetter(L, "BLOCKING_MEI_DISTANCE_MAX", CombatClass_get_BLOCKING_MEI_DISTANCE_MAX);
    registerGetter(L, "currentTarget", CombatClass_get_currentTarget);
    registerGetter(L, "currentTargetHandle", CombatClass_get_currentTargetHandle);
    registerGetter(L, "stateMap", CombatClass_get_stateMap);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "attackSlots", CombatClass_set_attackSlots);
    registerSetter(L, "wantsToBlock", CombatClass_set_wantsToBlock);
    registerSetter(L, "isStumbleBlocking", CombatClass_set_isStumbleBlocking);
    registerSetter(L, "stumbleTimer", CombatClass_set_stumbleTimer);
    registerSetter(L, "whenCanStopStumble", CombatClass_set_whenCanStopStumble);
    registerSetter(L, "stumbleForce", CombatClass_set_stumbleForce);
    registerSetter(L, "combatModeActive", CombatClass_set_combatModeActive);
    registerSetter(L, "lastCombatModeTimeStamp", CombatClass_set_lastCombatModeTimeStamp);
    registerSetter(L, "_isAttacking", CombatClass_set__isAttacking);
    registerSetter(L, "inDeadTime", CombatClass_set_inDeadTime);
    registerSetter(L, "deadTimer", CombatClass_set_deadTimer);
    registerSetter(L, "stateTimer", CombatClass_set_stateTimer);
    registerSetter(L, "currentTechnique", CombatClass_set_currentTechnique);
    registerSetter(L, "currentTechniqueHasFinished", CombatClass_set_currentTechniqueHasFinished);
    registerSetter(L, "attackStartPos", CombatClass_set_attackStartPos);
    registerSetter(L, "frameTIME", CombatClass_set_frameTIME);
    registerSetter(L, "movement", CombatClass_set_movement);
    registerSetter(L, "me", CombatClass_set_me);
    registerSetter(L, "stats", CombatClass_set_stats);
    registerSetter(L, "medical", CombatClass_set_medical);
    registerSetter(L, "myRadiusX", CombatClass_set_myRadiusX);
    registerSetter(L, "blockingTarget", CombatClass_set_blockingTarget);
    registerSetter(L, "blockingTargetH", CombatClass_set_blockingTargetH);
    registerSetter(L, "lastIncomingAttackComboSection", CombatClass_set_lastIncomingAttackComboSection);
    registerSetter(L, "calculatedTargetsInAttackZoneThisFrame", CombatClass_set_calculatedTargetsInAttackZoneThisFrame);
    registerSetter(L, "combatState", CombatClass_set_combatState);
    registerSetter(L, "nextMove", CombatClass_set_nextMove);
    registerSetter(L, "numEnemiesWaitingForMe1", CombatClass_set_numEnemiesWaitingForMe1);
    registerSetter(L, "numEnemiesWaitingForMe2", CombatClass_set_numEnemiesWaitingForMe2);
    registerSetter(L, "waitCountAlternator", CombatClass_set_waitCountAlternator);
    registerSetter(L, "currentComboSection", CombatClass_set_currentComboSection);
    registerSetter(L, "lastComboSection", CombatClass_set_lastComboSection);
    registerSetter(L, "lastSoundIndex", CombatClass_set_lastSoundIndex);
    registerSetter(L, "techniqueIntegrityCheckTimer", CombatClass_set_techniqueIntegrityCheckTimer);
    registerSetter(L, "MEI_MIN", CombatClass_set_MEI_MIN);
    registerSetter(L, "MEI_MAX", CombatClass_set_MEI_MAX);
    registerSetter(L, "MINIMUM_DISTANCE_TO_OTHERS", CombatClass_set_MINIMUM_DISTANCE_TO_OTHERS);
    registerSetter(L, "BLOCKING_MEI_DISTANCE_MIN", CombatClass_set_BLOCKING_MEI_DISTANCE_MIN);
    registerSetter(L, "BLOCKING_MEI_DISTANCE_MAX", CombatClass_set_BLOCKING_MEI_DISTANCE_MAX);
    registerSetter(L, "currentTarget", CombatClass_set_currentTarget);
    registerSetter(L, "currentTargetHandle", CombatClass_set_currentTargetHandle);
    registerSetter(L, "stateMap", CombatClass_set_stateMap);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, CombatClassBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack

    SwordStateMapBinding::registerBinding(L, "ogre_unordered_map<swordStateEnum, CombatState*>", nullptr, nullptr);

/*
LIGHTUSERDATA DEPENDENCIES:
  - CombatClass_get_ai / CombatClass_set_ai: AI* (unbound pointer)
  - CombatClass_get_animation / CombatClass_set_animation: AnimationClass* (unbound pointer)
  - CombatClass::getStateClass: CombatState* (unbound pointer)
*/

    // Register global table for static methods
    lua_newtable(L);
    lua_pushcfunction(L, CombatClassBinding::setup);
    lua_setfield(L, -2, "setup");
    lua_pushcfunction(L, CombatClassBinding::destroy);
    lua_setfield(L, -2, "destroy");
    lua_pushcfunction(L, CombatClassBinding::getCombatEffect);
    lua_setfield(L, -2, "getCombatEffect");
    lua_pushcfunction(L, CombatClassBinding::addEffect);
    lua_setfield(L, -2, "addEffect");
    lua_pushcfunction(L, CombatClassBinding::shiftEffects);
    lua_setfield(L, -2, "shiftEffects");
    lua_pushcfunction(L, CombatClassBinding::updateEffects);
    lua_setfield(L, -2, "updateEffects");
    lua_setglobal(L, "CombatClass");
}

} // namespace KenshiLua