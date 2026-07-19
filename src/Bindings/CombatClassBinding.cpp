#include "pch.h"
#include "kenshi\CombatClass.h"
#include "CombatClassBinding.h"
#include "Lua/BindingHelpers.h"
#include "CombatTechniqueDataBinding.h"
#include "CharMovementBinding.h"
#include "CharacterBinding.h"
#include "CharStatsBinding.h"
#include "MedicalSystemBinding.h"
#include "AttackSlotManagerBinding.h"

namespace KenshiLua
{

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

// --- Setters for CombatClass ---
static int CombatClass_set_attackSlots(lua_State* L)
{
    return luaL_error(L, "Read-only or unsupported setter type for attackSlots");
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

static int CombatClass_set_myRadiusX(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");
    instance->myRadiusX = (float)luaL_checknumber(L, 2);
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

int CombatClassBinding::isStationary(lua_State* L)
{
    CombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatClass is nil");

    bool result = instance->isStationary();
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

/*
Skipped methods needing manual binding:
  line 64: bool initCombatMode(...) - unsupported arg type
  line 65: bool _NV_initCombatMode(...) - unsupported arg type
  line 72: swordStateEnum whoAttacksYouOrMe(...) - unsupported arg type
  line 73: HitMaterialType _iHitYouAreYouHit(...) - unsupported arg type
  line 74: void _getHit(...) - unsupported arg type
  line 75: void _blockHit(...) - unsupported arg type
  line 76: float isAttacking(...) - unsupported arg type
  line 77: void informOfFreeAttackSlot(...) - unsupported arg type
  line 78: void _NV_informOfFreeAttackSlot(...) - unsupported arg type
  line 80: hand _getAttackTarget(...) - unsupported return type
  line 81: bool isFightingAnAllyOfMine(...) - unsupported arg type
  line 87: lektor<hand>& getAttackers(...) - reference return type
  line 93: bool addAttackerH(...) - unsupported arg type
  line 94: bool isInAttackerListH(...) - unsupported arg type
  line 95: bool removeAttackerH(...) - unsupported arg type
  line 134: void youDoKnowImAttackingYouRight(...) - unsupported arg type
  line 135: float getAttackAimAdjustmentThreshold(...) - unsupported arg type
  line 139: void setup(...) - static method
  line 140: void destroy(...) - static method
  line 141: GameData* getCombatEffect(...) - static method
  line 142: void addEffect(...) - static method
  line 143: void shiftEffects(...) - static method
  line 144: void updateEffects(...) - static method
  line 145: hand hasFocusedTarget(...) - unsupported return type
  line 146: hand _NV_hasFocusedTarget(...) - unsupported return type
  line 149: CombatClass* _CONSTRUCTOR(...) - unsupported arg type
  line 199: bool isInAttackZone(...) - unsupported arg type
  line 201: void assessIncomingAttacks(...) - unsupported arg type
  line 212: void calculateCurrentTechniqueSection(...) - non-string reference arg
  line 220: Character* getBiggestThreat(...) - unsupported arg type
  line 221: bool gotMoreImportantThingsToDoThanFightingYou(...) - unsupported arg type
  line 222: bool _NV_gotMoreImportantThingsToDoThanFightingYou(...) - unsupported arg type
  line 226: void setAttackTarget(...) - unsupported arg type
  line 227: void setAttackTargetHandle(...) - unsupported arg type
  line 230: void lookatTarget(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 153: stateMap (ogre_unordered_map<swordStateEnum, CombatState*>::type) - unsupported type
  line 192: blockingTargetH (hand) - unsupported type
  line 198: targetsInAttackZone (lektor<hand>) - unsupported type
  line 205: attackersH (lektor<hand>) - unsupported type
  line 209: threats (lektor<Character*>) - unsupported type
  line 210: threatsH (lektor<hand>) - unsupported type
  line 211: notifiedThreats (lektor<hand>) - unsupported type
  line 229: currentTargetHandle (hand) - unsupported type
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
        { "isStationary", CombatClassBinding::isStationary },
        { "getCurrentTechnique", CombatClassBinding::getCurrentTechnique },
        { "getCurrentTechniqueSection", CombatClassBinding::getCurrentTechniqueSection },
        { "getMeiMin", CombatClassBinding::getMeiMin },
        { "areYouFightingAndInNeedOfHelp", CombatClassBinding::areYouFightingAndInNeedOfHelp },
        { "getNumOpponents", CombatClassBinding::getNumOpponents },
        { "getTotalRelativeStrengthOfAttackers", CombatClassBinding::getTotalRelativeStrengthOfAttackers },
        { "_isInCombatMode", CombatClassBinding::_isInCombatMode },
        { "checkForBadHandles", CombatClassBinding::checkForBadHandles },
        { "getNumWaitingAttackers", CombatClassBinding::getNumWaitingAttackers },
        { "readyToFinishCombatMode", CombatClassBinding::readyToFinishCombatMode },
        { "getTimeSinceLastCombatModeInHours", CombatClassBinding::getTimeSinceLastCombatModeInHours },
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
        { "getNearestEnemyInAttackZone", CombatClassBinding::getNearestEnemyInAttackZone },
        { "notifyBlockNeeded", CombatClassBinding::notifyBlockNeeded },
        { "weaponReach", CombatClassBinding::weaponReach },
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
    lua_pushcfunction(L, CombatClass_get_attackSlots);
    lua_setfield(L, -2, "attackSlots");
    lua_pushcfunction(L, CombatClass_get_wantsToBlock);
    lua_setfield(L, -2, "wantsToBlock");
    lua_pushcfunction(L, CombatClass_get_isStumbleBlocking);
    lua_setfield(L, -2, "isStumbleBlocking");
    lua_pushcfunction(L, CombatClass_get_stumbleTimer);
    lua_setfield(L, -2, "stumbleTimer");
    lua_pushcfunction(L, CombatClass_get_whenCanStopStumble);
    lua_setfield(L, -2, "whenCanStopStumble");
    lua_pushcfunction(L, CombatClass_get_stumbleForce);
    lua_setfield(L, -2, "stumbleForce");
    lua_pushcfunction(L, CombatClass_get_combatModeActive);
    lua_setfield(L, -2, "combatModeActive");
    lua_pushcfunction(L, CombatClass_get_lastCombatModeTimeStamp);
    lua_setfield(L, -2, "lastCombatModeTimeStamp");
    lua_pushcfunction(L, CombatClass_get__isAttacking);
    lua_setfield(L, -2, "_isAttacking");
    lua_pushcfunction(L, CombatClass_get_inDeadTime);
    lua_setfield(L, -2, "inDeadTime");
    lua_pushcfunction(L, CombatClass_get_deadTimer);
    lua_setfield(L, -2, "deadTimer");
    lua_pushcfunction(L, CombatClass_get_stateTimer);
    lua_setfield(L, -2, "stateTimer");
    lua_pushcfunction(L, CombatClass_get_currentTechnique);
    lua_setfield(L, -2, "currentTechnique");
    lua_pushcfunction(L, CombatClass_get_currentTechniqueHasFinished);
    lua_setfield(L, -2, "currentTechniqueHasFinished");
    lua_pushcfunction(L, CombatClass_get_attackStartPos);
    lua_setfield(L, -2, "attackStartPos");
    lua_pushcfunction(L, CombatClass_get_frameTIME);
    lua_setfield(L, -2, "frameTIME");
    lua_pushcfunction(L, CombatClass_get_movement);
    lua_setfield(L, -2, "movement");
    lua_pushcfunction(L, CombatClass_get_ai);
    lua_setfield(L, -2, "ai");
    lua_pushcfunction(L, CombatClass_get_animation);
    lua_setfield(L, -2, "animation");
    lua_pushcfunction(L, CombatClass_get_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, CombatClass_get_stats);
    lua_setfield(L, -2, "stats");
    lua_pushcfunction(L, CombatClass_get_medical);
    lua_setfield(L, -2, "medical");
    lua_pushcfunction(L, CombatClass_get_myRadiusX);
    lua_setfield(L, -2, "myRadiusX");
    lua_pushcfunction(L, CombatClass_get_blockingTarget);
    lua_setfield(L, -2, "blockingTarget");
    lua_pushcfunction(L, CombatClass_get_lastIncomingAttackComboSection);
    lua_setfield(L, -2, "lastIncomingAttackComboSection");
    lua_pushcfunction(L, CombatClass_get_calculatedTargetsInAttackZoneThisFrame);
    lua_setfield(L, -2, "calculatedTargetsInAttackZoneThisFrame");
    lua_pushcfunction(L, CombatClass_get_combatState);
    lua_setfield(L, -2, "combatState");
    lua_pushcfunction(L, CombatClass_get_nextMove);
    lua_setfield(L, -2, "nextMove");
    lua_pushcfunction(L, CombatClass_get_numEnemiesWaitingForMe1);
    lua_setfield(L, -2, "numEnemiesWaitingForMe1");
    lua_pushcfunction(L, CombatClass_get_numEnemiesWaitingForMe2);
    lua_setfield(L, -2, "numEnemiesWaitingForMe2");
    lua_pushcfunction(L, CombatClass_get_waitCountAlternator);
    lua_setfield(L, -2, "waitCountAlternator");
    lua_pushcfunction(L, CombatClass_get_currentComboSection);
    lua_setfield(L, -2, "currentComboSection");
    lua_pushcfunction(L, CombatClass_get_lastComboSection);
    lua_setfield(L, -2, "lastComboSection");
    lua_pushcfunction(L, CombatClass_get_lastSoundIndex);
    lua_setfield(L, -2, "lastSoundIndex");
    lua_pushcfunction(L, CombatClass_get_techniqueIntegrityCheckTimer);
    lua_setfield(L, -2, "techniqueIntegrityCheckTimer");
    lua_pushcfunction(L, CombatClass_get_MEI_MIN);
    lua_setfield(L, -2, "MEI_MIN");
    lua_pushcfunction(L, CombatClass_get_MEI_MAX);
    lua_setfield(L, -2, "MEI_MAX");
    lua_pushcfunction(L, CombatClass_get_MINIMUM_DISTANCE_TO_OTHERS);
    lua_setfield(L, -2, "MINIMUM_DISTANCE_TO_OTHERS");
    lua_pushcfunction(L, CombatClass_get_BLOCKING_MEI_DISTANCE_MIN);
    lua_setfield(L, -2, "BLOCKING_MEI_DISTANCE_MIN");
    lua_pushcfunction(L, CombatClass_get_BLOCKING_MEI_DISTANCE_MAX);
    lua_setfield(L, -2, "BLOCKING_MEI_DISTANCE_MAX");
    lua_pushcfunction(L, CombatClass_get_currentTarget);
    lua_setfield(L, -2, "currentTarget");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, CombatClass_set_attackSlots);
    lua_setfield(L, -2, "attackSlots");
    lua_pushcfunction(L, CombatClass_set_wantsToBlock);
    lua_setfield(L, -2, "wantsToBlock");
    lua_pushcfunction(L, CombatClass_set_isStumbleBlocking);
    lua_setfield(L, -2, "isStumbleBlocking");
    lua_pushcfunction(L, CombatClass_set_stumbleTimer);
    lua_setfield(L, -2, "stumbleTimer");
    lua_pushcfunction(L, CombatClass_set_whenCanStopStumble);
    lua_setfield(L, -2, "whenCanStopStumble");
    lua_pushcfunction(L, CombatClass_set_stumbleForce);
    lua_setfield(L, -2, "stumbleForce");
    lua_pushcfunction(L, CombatClass_set_combatModeActive);
    lua_setfield(L, -2, "combatModeActive");
    lua_pushcfunction(L, CombatClass_set_lastCombatModeTimeStamp);
    lua_setfield(L, -2, "lastCombatModeTimeStamp");
    lua_pushcfunction(L, CombatClass_set__isAttacking);
    lua_setfield(L, -2, "_isAttacking");
    lua_pushcfunction(L, CombatClass_set_inDeadTime);
    lua_setfield(L, -2, "inDeadTime");
    lua_pushcfunction(L, CombatClass_set_deadTimer);
    lua_setfield(L, -2, "deadTimer");
    lua_pushcfunction(L, CombatClass_set_stateTimer);
    lua_setfield(L, -2, "stateTimer");
    lua_pushcfunction(L, CombatClass_set_currentTechniqueHasFinished);
    lua_setfield(L, -2, "currentTechniqueHasFinished");
    lua_pushcfunction(L, CombatClass_set_attackStartPos);
    lua_setfield(L, -2, "attackStartPos");
    lua_pushcfunction(L, CombatClass_set_frameTIME);
    lua_setfield(L, -2, "frameTIME");
    lua_pushcfunction(L, CombatClass_set_myRadiusX);
    lua_setfield(L, -2, "myRadiusX");
    lua_pushcfunction(L, CombatClass_set_lastIncomingAttackComboSection);
    lua_setfield(L, -2, "lastIncomingAttackComboSection");
    lua_pushcfunction(L, CombatClass_set_calculatedTargetsInAttackZoneThisFrame);
    lua_setfield(L, -2, "calculatedTargetsInAttackZoneThisFrame");
    lua_pushcfunction(L, CombatClass_set_combatState);
    lua_setfield(L, -2, "combatState");
    lua_pushcfunction(L, CombatClass_set_nextMove);
    lua_setfield(L, -2, "nextMove");
    lua_pushcfunction(L, CombatClass_set_numEnemiesWaitingForMe1);
    lua_setfield(L, -2, "numEnemiesWaitingForMe1");
    lua_pushcfunction(L, CombatClass_set_numEnemiesWaitingForMe2);
    lua_setfield(L, -2, "numEnemiesWaitingForMe2");
    lua_pushcfunction(L, CombatClass_set_waitCountAlternator);
    lua_setfield(L, -2, "waitCountAlternator");
    lua_pushcfunction(L, CombatClass_set_currentComboSection);
    lua_setfield(L, -2, "currentComboSection");
    lua_pushcfunction(L, CombatClass_set_lastComboSection);
    lua_setfield(L, -2, "lastComboSection");
    lua_pushcfunction(L, CombatClass_set_lastSoundIndex);
    lua_setfield(L, -2, "lastSoundIndex");
    lua_pushcfunction(L, CombatClass_set_techniqueIntegrityCheckTimer);
    lua_setfield(L, -2, "techniqueIntegrityCheckTimer");
    lua_pushcfunction(L, CombatClass_set_MEI_MIN);
    lua_setfield(L, -2, "MEI_MIN");
    lua_pushcfunction(L, CombatClass_set_MEI_MAX);
    lua_setfield(L, -2, "MEI_MAX");
    lua_pushcfunction(L, CombatClass_set_MINIMUM_DISTANCE_TO_OTHERS);
    lua_setfield(L, -2, "MINIMUM_DISTANCE_TO_OTHERS");
    lua_pushcfunction(L, CombatClass_set_BLOCKING_MEI_DISTANCE_MIN);
    lua_setfield(L, -2, "BLOCKING_MEI_DISTANCE_MIN");
    lua_pushcfunction(L, CombatClass_set_BLOCKING_MEI_DISTANCE_MAX);
    lua_setfield(L, -2, "BLOCKING_MEI_DISTANCE_MAX");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, CombatClassBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
