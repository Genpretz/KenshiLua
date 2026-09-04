#include "pch.h"
#include "Hooks_Common.h"

// ---------------------------------------------------------------------------
// Hooks for CharStats.h
// ---------------------------------------------------------------------------

static void (*CharStats_SetHoldLocation_orig)(CharStats*, const Ogre::Vector3&) = NULL;
static void CharStats_SetHoldLocation_hook(CharStats* thisptr, const Ogre::Vector3& v)
{
    CharStats_SetHoldLocation_orig(thisptr, v);
    CallCharStatsSetHoldLocationCallbacks(thisptr, v);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharStats_SetHoldLocation,
    "CharStats::setHoldLocation",
    KenshiLib::GetRealAddress(&CharStats::setHoldLocation),
    CharStats_SetHoldLocation_hook, CharStats_SetHoldLocation_orig)

static void (*CharStats_ClearHoldLocation_orig)(CharStats*) = NULL;
static void CharStats_ClearHoldLocation_hook(CharStats* thisptr)
{
    CharStats_ClearHoldLocation_orig(thisptr);
    CallCharStatsClearHoldLocationCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharStats_ClearHoldLocation,
    "CharStats::clearHoldLocation",
    KenshiLib::GetRealAddress(&CharStats::clearHoldLocation),
    CharStats_ClearHoldLocation_hook, CharStats_ClearHoldLocation_orig)

static CombatTechniqueData* (*CharStats_ChooseAttack_orig)(CharStats*, float, float, CombatTechniqueData*, bool) = NULL;
static CombatTechniqueData* CharStats_ChooseAttack_hook(CharStats* thisptr, float range, float weaponReach, CombatTechniqueData* lastAttack, bool opponentIsStationary)
{
    CombatTechniqueData* current = CharStats_ChooseAttack_orig(thisptr, range, weaponReach, lastAttack, opponentIsStationary);
    CombatTechniqueData* overrideAttack = CallCharStatsChooseAttackCallbacks(thisptr, range, weaponReach, lastAttack, opponentIsStationary, current);
    return overrideAttack ? overrideAttack : current;
}
DEFINE_HOOK_INSTALLER(InstallHook_CharStats_ChooseAttack,
    "CharStats::chooseAttack",
    KenshiLib::GetRealAddress(&CharStats::chooseAttack),
    CharStats_ChooseAttack_hook, CharStats_ChooseAttack_orig)

static void (*CharStats_XpRunning_orig)(CharStats*, float, float) = NULL;
static void CharStats_XpRunning_hook(CharStats* thisptr, float time, float speed)
{
    CharStats_XpRunning_orig(thisptr, time, speed);
    CallCharStatsXpRunningCallbacks(thisptr, time, speed);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharStats_XpRunning,
    "CharStats::xpRunning",
    KenshiLib::GetRealAddress(&CharStats::xpRunning),
    CharStats_XpRunning_hook, CharStats_XpRunning_orig)

static void (*CharStats_XpFirstAid_orig)(CharStats*, Character*, float, int) = NULL;
static void CharStats_XpFirstAid_hook(CharStats* thisptr, Character* patient, float time, int medicStat)
{
    CharStats_XpFirstAid_orig(thisptr, patient, time, medicStat);
    CallCharStatsXpFirstAidCallbacks(thisptr, patient, time, medicStat);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharStats_XpFirstAid,
    "CharStats::xpFirstAid",
    KenshiLib::GetRealAddress(&CharStats::xpFirstAid),
    CharStats_XpFirstAid_hook, CharStats_XpFirstAid_orig)

static void (*CharStats_XpStealth_orig)(CharStats*, float, bool, YesNoMaybe, bool) = NULL;
static void CharStats_XpStealth_hook(CharStats* thisptr, float time, bool enemiesAbout, YesNoMaybe seen, bool isMoving)
{
    CharStats_XpStealth_orig(thisptr, time, enemiesAbout, seen, isMoving);
    CallCharStatsXpStealthCallbacks(thisptr, time, enemiesAbout, seen, isMoving);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharStats_XpStealth,
    "CharStats::xpStealth",
    KenshiLib::GetRealAddress(&CharStats::xpStealth),
    CharStats_XpStealth_hook, CharStats_XpStealth_orig)

static void (*CharStats_XpToughness_GetUpEvent_orig)(CharStats*) = NULL;
static void CharStats_XpToughness_GetUpEvent_hook(CharStats* thisptr)
{
    CharStats_XpToughness_GetUpEvent_orig(thisptr);
    CallCharStatsXpToughness_GetUpEventCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharStats_XpToughness_GetUpEvent,
    "CharStats::xpToughness_GetUpEvent",
    KenshiLib::GetRealAddress(&CharStats::xpToughness_GetUpEvent),
    CharStats_XpToughness_GetUpEvent_hook, CharStats_XpToughness_GetUpEvent_orig)

static void (*CharStats_XpToughness_RagdollEvent_orig)(CharStats*) = NULL;
static void CharStats_XpToughness_RagdollEvent_hook(CharStats* thisptr)
{
    CharStats_XpToughness_RagdollEvent_orig(thisptr);
    CallCharStatsXpToughness_RagdollEventCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharStats_XpToughness_RagdollEvent,
    "CharStats::xpToughness_RagdollEvent",
    KenshiLib::GetRealAddress(&CharStats::xpToughness_RagdollEvent),
    CharStats_XpToughness_RagdollEvent_hook, CharStats_XpToughness_RagdollEvent_orig)

static void (*CharStats_XpToughness_PunchSomething_orig)(CharStats*, int) = NULL;
static void CharStats_XpToughness_PunchSomething_hook(CharStats* thisptr, int mat)
{
    CharStats_XpToughness_PunchSomething_orig(thisptr, mat);
    CallCharStatsXpToughness_PunchSomethingCallbacks(thisptr, mat);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharStats_XpToughness_PunchSomething,
    "CharStats::xpToughness_PunchSomething",
    KenshiLib::GetRealAddress(&CharStats::xpToughness_PunchSomething),
    CharStats_XpToughness_PunchSomething_hook, CharStats_XpToughness_PunchSomething_orig)

static void (*CharStats_XpEngineering_orig)(CharStats*, float) = NULL;
static void CharStats_XpEngineering_hook(CharStats* thisptr, float time)
{
    CharStats_XpEngineering_orig(thisptr, time);
    CallCharStatsXpEngineeringCallbacks(thisptr, time);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharStats_XpEngineering,
    "CharStats::xpEngineering",
    KenshiLib::GetRealAddress(&CharStats::xpEngineering),
    CharStats_XpEngineering_hook, CharStats_XpEngineering_orig)

static void (*CharStats_XpLockpicking_orig)(CharStats*, int, bool) = NULL;
static void CharStats_XpLockpicking_hook(CharStats* thisptr, int lockLevel, bool success)
{
    CharStats_XpLockpicking_orig(thisptr, lockLevel, success);
    CallCharStatsXpLockpickingCallbacks(thisptr, lockLevel, success);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharStats_XpLockpicking,
    "CharStats::xpLockpicking",
    KenshiLib::GetRealAddress(&CharStats::xpLockpicking),
    CharStats_XpLockpicking_hook, CharStats_XpLockpicking_orig)

static float (*CharStats_getStat_orig)(const CharStats*, StatsEnumerated, bool) = NULL;
static float CharStats_getStat_hook(const CharStats* thisptr, StatsEnumerated what, bool unmodified)
{
    float current = CharStats_getStat_orig(thisptr, what, unmodified);
    return CallCharStatsGetStatCallbacks(thisptr, static_cast<int>(what), unmodified, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharStats_getStat,
    "CharStats::getStat",
    KenshiLib::GetRealAddress(&CharStats::getStat),
    CharStats_getStat_hook, CharStats_getStat_orig)

static void (*CharStats_xpStat_eventBased_orig)(CharStats*, StatsEnumerated, float) = NULL;
static void CharStats_xpStat_eventBased_hook(CharStats* thisptr, StatsEnumerated st, float amount)
{
    CharStats_xpStat_eventBased_orig(thisptr, st, amount);
    CallCharStatsXpStatEventBasedCallbacks(thisptr, static_cast<int>(st), amount);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharStats_xpStat_eventBased,
    "CharStats::xpStat_eventBased",
    KenshiLib::GetRealAddress(&CharStats::xpStat_eventBased),
    CharStats_xpStat_eventBased_hook, CharStats_xpStat_eventBased_orig)

static void (*CharStats_xpDodgeEvent_orig)(CharStats*, float, bool) = NULL;
static void CharStats_xpDodgeEvent_hook(CharStats* thisptr, float enemySkill, bool successful)
{
    CharStats_xpDodgeEvent_orig(thisptr, enemySkill, successful);
    CallCharStatsXpDodgeEventCallbacks(thisptr, enemySkill, successful);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharStats_xpDodgeEvent,
    "CharStats::xpDodgeEvent",
    KenshiLib::GetRealAddress(&CharStats::xpDodgeEvent),
    CharStats_xpDodgeEvent_hook, CharStats_xpDodgeEvent_orig)

static CharStats* (*CharStats_CONSTRUCTOR_orig)(CharStats*) = NULL;
static CharStats* CharStats_CONSTRUCTOR_hook(CharStats* thisptr)
{
    CharStats* res = CharStats_CONSTRUCTOR_orig(thisptr);
    CharStats* overrideRes = CallCharStatsConstructedCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_CharStats_CONSTRUCTOR,
    "CharStats::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&CharStats::_CONSTRUCTOR),
    CharStats_CONSTRUCTOR_hook, CharStats_CONSTRUCTOR_orig)

