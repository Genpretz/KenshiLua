#include "pch.h"

#include "Callbacks.h"
#include "Gui/GuiManager.h"
#include "Hooks.h"
#include "Logger.h"
#include "DialogueScriptBridge.h"

#include <core/Functions.h>
#include <kenshi/Character.h>
#include <kenshi/CharMovement.h>
#include <kenshi/GameWorld.h>
#include <kenshi/CharStats.h>
#include <kenshi/Platoon.h>
#include <kenshi/Item.h>
#include <kenshi/PlayerInterface.h>
#include <kenshi/Faction.h>
#include <kenshi/Damages.h>
#include <kenshi/gui/TitleScreen.h>
#include <kenshi/gui/InventoryGUI.h>
#include <kenshi/gui/BuildModeWindow.h>
#include <kenshi/gui/SquadManagementScreen.h>
#include <kenshi/gui/ManagementScreen.h>
#include <kenshi/InputHandler.h>
#include <kenshi/util/YesNoMaybe.h>
#include <kenshi/BountyManager.h>
#include <kenshi/Building/Building.h>
#include <kenshi/FactionRelations.h>
#include <kenshi/MedicalSystem.h>
#include <kenshi/gui/DialogueWindow.h>
#include <kenshi/Dialogue.h>
#include <kenshi/Enums.h>
#include <kenshi/Inventory.h>
#include <kenshi/RootObjectFactory.h>
#include <kenshi/Town.h>
#include <kenshi/GameSaveState.h>
#include <kenshi/gui/DataPanelLine.h>
#include <kenshi/gui/OrdersPanel.h>

#include <cstddef>

// ---------------------------------------------------------------------------
// Generic hook installer
//
// Wraps KenshiLib::AddHook with the bookkeeping every hook needs:
//   - skip if already installed (orig pointer already set)
//   - bail with a logged error if the address can't be resolved
//   - bail with a logged error if AddHook itself fails
//   - log success
// ---------------------------------------------------------------------------

template <typename T>
static bool InstallHookT(const char* name, intptr_t addr, T hookFn, T* origStorage)
{
    if (*origStorage)
        return true; // already installed

    if (!addr)
    {
        KenshiLua::logToFileErrorf("Error: Could not resolve address for %s.", name);
        return false;
    }
    
    KenshiLib::HookStatus status = KenshiLib::AddHook(addr, hookFn, origStorage);
    if (status != KenshiLib::SUCCESS)
    {
        KenshiLua::logToFileErrorf("Error: AddHook failed for %s (status %d).", name, (int)status);
        return false;
    }

    KenshiLua::logToFileDebugf("Hook installed: %s", name);
    return true;
}

// ToDo: Should this be a macro?
#define DEFINE_HOOK_INSTALLER(fnName, displayName, addrExpr, hookFn, origVar) \
    static bool fnName() \
    { \
        return InstallHookT(displayName, (intptr_t)(addrExpr), &hookFn, &origVar); \
    }


// ---------------------------------------------------------------------------
// Hooks for InputHandler.h
// ---------------------------------------------------------------------------

static void (*InputHandler_keyDownEvent_orig)(InputHandler* thisptr, OIS::KeyCode key) = NULL;

static void InputHandler_keyDownEvent_hook(InputHandler* thisptr, OIS::KeyCode key)
{
    InputHandler_keyDownEvent_orig(thisptr, key);

    KenshiLua::GuiManager::get().checkKeyboardShortcut(key, thisptr);

    CallKeyDownCallbacks(static_cast<int>(key));
}

DEFINE_HOOK_INSTALLER(InstallHook_InputHandler_KeyDown,
    "InputHandler::keyDownEvent",
    KenshiLib::GetRealAddress(&InputHandler::keyDownEvent),
    InputHandler_keyDownEvent_hook, InputHandler_keyDownEvent_orig)


// ---------------------------------------------------------------------------
// Hooks for GameWorld.h
// ---------------------------------------------------------------------------

static void (*GameWorld_charsUpdate_orig)(GameWorld* thisptr) = NULL;

static void GameWorld_charsUpdate_hook(GameWorld* thisptr)
{
    GameWorld_charsUpdate_orig(thisptr);
    CallCharsUpdateCallbacks();
}

DEFINE_HOOK_INSTALLER(InstallHook_GameWorld_CharsUpdate,
    "GameWorld::charsUpdate",
    KenshiLib::GetRealAddress(&GameWorld::charsUpdate),
    GameWorld_charsUpdate_hook, GameWorld_charsUpdate_orig)


// ---------------------------------------------------------------------------
// Hooks for Character.h
// ---------------------------------------------------------------------------

static void (*Character_say_orig)(Character*, const std::string&) = NULL;

static void Character_say_hook(Character* thisptr, const std::string& message)
{
    Character_say_orig(thisptr, message);
    CallCharacterSayCallbacks(thisptr, message);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_Say,
    "Character::_NV_say",
    KenshiLib::GetRealAddress(&Character::_NV_say),
    Character_say_hook, Character_say_orig)

static void (*Character_select_orig)(Character*) = NULL;

static void Character_select_hook(Character* thisptr)
{
    Character_select_orig(thisptr);
    CallCharacterSelectCallbacks(thisptr);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_Select,
    "Character::_NV_select",
    KenshiLib::GetRealAddress(&Character::_NV_select),
    Character_select_hook, Character_select_orig)

static void (*Character_unselect_orig)(Character* thisptr) = NULL;

static void Character_unselect_hook(Character* thisptr)
{
    Character_unselect_orig(thisptr);
    CallCharacterUnselectCallbacks(thisptr);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_Unselect,
    "Character::_NV_unselect",
    KenshiLib::GetRealAddress(&Character::_NV_unselect),
    Character_unselect_hook, Character_unselect_orig)

static void (*Character_declareDead_orig)(Character*) = NULL;

static void Character_declareDead_hook(Character* thisptr)
{
    Character_declareDead_orig(thisptr);
    CallCharacterDeclareDeadCallbacks(thisptr);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_DeclareDead,
    "Character::declareDead",
    KenshiLib::GetRealAddress(&Character::declareDead),
    Character_declareDead_hook, Character_declareDead_orig)

static void (*Character_pickupObject_orig)(Character* thisptr, Character* character) = NULL;

static void Character_pickupObject_hook(Character* thisptr, Character* character)
{
    Character_pickupObject_orig(thisptr, character);
    CallCharacterPickupObjectCallbacks(character);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_PickupObject,
    "Character::pickupObject",
    KenshiLib::GetRealAddress(&Character::pickupObject),
    Character_pickupObject_hook, Character_pickupObject_orig)

static void (*Character_getPickedUp_orig)(Character* thisptr, Character* byWhom) = NULL;

static void Character_getPickedUp_hook(Character* thisptr, Character* byWhom)
{
    Character_getPickedUp_orig(thisptr, byWhom);
    CallCharacterGetPickedUpCallbacks(byWhom);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_GetPickedUp,
    "Character::getPickedUp",
    KenshiLib::GetRealAddress(&Character::getPickedUp),
    Character_getPickedUp_hook, Character_getPickedUp_orig)

static void (*Character_takeMoney_orig)(Character*, int) = NULL;

static void Character_takeMoney_hook(Character* thisptr, int amount)
{
    Character_takeMoney_orig(thisptr, amount);
    CallCharacterTakeMoneyCallbacks(thisptr, amount);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_TakeMoney,
    "Character::_NV_takeMoney",
    KenshiLib::GetRealAddress(&Character::_NV_takeMoney),
    Character_takeMoney_hook, Character_takeMoney_orig)

static void (*Character_eatItem_orig)(Character*, Item*, Inventory*) = NULL;

static void Character_eatItem_hook(Character* thisptr, Item* food, Inventory* from)
{
    Character_eatItem_orig(thisptr, food, from);
    CallCharacterEatCallbacks(thisptr, food, from);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_EatItem,
    "Character::eatItem",
    KenshiLib::GetRealAddress(&Character::eatItem),
    Character_eatItem_hook, Character_eatItem_orig)

static void (*Character_hitByMeleeAttack_orig)(Character*, Character*, Damages*, int, CombatTechniqueData*, int) = NULL;

static void Character_hitByMeleeAttack_hook(Character* thisptr, Character* attacker, Damages* damage, int cutDir, CombatTechniqueData* attack, int comboID)
{
    Character_hitByMeleeAttack_orig(thisptr, attacker, damage, cutDir, attack, comboID);
    CallCharacterHitByMeleeCallbacks(thisptr, attacker, damage, cutDir, attack, comboID);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_HitByMeleeAttack,
    "Character::_NV_hitByMeleeAttack",
    KenshiLib::GetRealAddress(&Character::_NV_hitByMeleeAttack),
    Character_hitByMeleeAttack_hook, Character_hitByMeleeAttack_orig)

static void (*Character_gettingEaten_orig)(Character*, Character*, float) = NULL;

static void Character_gettingEaten_hook(Character* thisptr, Character* eater, float amount)
{
    Character_gettingEaten_orig(thisptr, eater, amount);
    CallCharacterGettingEatenCallbacks(thisptr, eater, amount);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_GettingEaten,
    "Character::_NV_gettingEaten",
    KenshiLib::GetRealAddress(&Character::_NV_gettingEaten),
    Character_gettingEaten_hook, Character_gettingEaten_orig)

static void (*Character_setStandingOrder_orig)(Character*, int, bool) = NULL;

static void Character_setStandingOrder_hook(Character* thisptr, int orderID, bool on)
{
    Character_setStandingOrder_orig(thisptr, orderID, on);
    CallCharacterStandingOrderChangedCallbacks(thisptr, orderID, on);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_SetStandingOrder,
    "Character::_NV_setStandingOrder",
    KenshiLib::GetRealAddress(&Character::_NV_setStandingOrder),
    Character_setStandingOrder_hook, Character_setStandingOrder_orig)

static void (*Character_setFaction_orig)(Character*, Faction*, ActivePlatoon*) = NULL;

static void Character_setFaction_hook(Character* thisptr, Faction* faction, ActivePlatoon* platoon)
{
    Character_setFaction_orig(thisptr, faction, platoon);
    CallCharacterFactionChangedCallbacks(thisptr, faction, platoon);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_SetFaction,
    "Character::_NV_setFaction",
    KenshiLib::GetRealAddress(&Character::_NV_setFaction),
    Character_setFaction_hook, Character_setFaction_orig)

static void (*Character_equipItem_orig)(Character*, const std::string&, Item*) = NULL;

static void Character_equipItem_hook(Character* thisptr, const std::string& sectionName, Item* item)
{
    Character_equipItem_orig(thisptr, sectionName, item);
    CallCharacterEquipCallbacks(thisptr, sectionName, item);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_EquipItem,
    "Character::_NV_equipItem",
    KenshiLib::GetRealAddress(&Character::_NV_equipItem),
    Character_equipItem_hook, Character_equipItem_orig)

static void (*Character_unequipItem_orig)(Character*, const std::string&, Item*) = NULL;

static void Character_unequipItem_hook(Character* thisptr, const std::string& sectionName, Item* item)
{
    Character_unequipItem_orig(thisptr, sectionName, item);
    CallCharacterUnequipCallbacks(thisptr, sectionName, item);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_UnequipItem,
    "Character::_NV_unequipItem",
    KenshiLib::GetRealAddress(&Character::_NV_unequipItem),
    Character_unequipItem_hook, Character_unequipItem_orig)

static void (*Character_ImStealingDoYouNotice_orig)(Character*, RootObject*, Item*, bool) = NULL;

static void Character_ImStealingDoYouNotice_hook(Character* thisptr, RootObject* stealFrom, Item* item, bool noticed)
{
    Character_ImStealingDoYouNotice_orig(thisptr, stealFrom, item, noticed);
    CallCharacterStealNoticeCallbacks(thisptr, stealFrom, item, noticed);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_ImStealingDoYouNotice,
    "Character::_NV_ImStealingDoYouNotice",
    KenshiLib::GetRealAddress(&Character::_NV_ImStealingDoYouNotice),
    Character_ImStealingDoYouNotice_hook, Character_ImStealingDoYouNotice_orig)

static void (*Character_smugglingTradeCheck_orig)(Character*, Item*, Character*, int) = NULL;

static void Character_smugglingTradeCheck_hook(Character* thisptr, Item* item, Character* who, int result)
{
    Character_smugglingTradeCheck_orig(thisptr, item, who, result);
    CallCharacterSmugglingCheckCallbacks(thisptr, item, who, result);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_SmugglingTradeCheck,
    "Character::_NV_smugglingTradeCheck",
    KenshiLib::GetRealAddress(&Character::_NV_smugglingTradeCheck),
    Character_smugglingTradeCheck_hook, Character_smugglingTradeCheck_orig)

static void (*Character_NV_init_orig)(Character*) = NULL;

static void Character_NV_init_hook(Character* thisptr)
{
    Character_NV_init_orig(thisptr);
    CallCharacterInitCallbacks(thisptr);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_NV_init,
    "Character::_NV_init",
    KenshiLib::GetRealAddress(&Character::_NV_init),
    Character_NV_init_hook, Character_NV_init_orig)

static bool (*Character_isItOkForMeToLoot_orig)(Character*, RootObject*, Item*) = NULL;

static bool Character_isItOkForMeToLoot_hook(Character* thisptr, RootObject* victim, Item* item)
{
    bool current = Character_isItOkForMeToLoot_orig(thisptr, victim, item);
    return CallCharacterIsItOkForMeToLootCallbacks(thisptr, victim, item, current);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_isItOkForMeToLoot,
    "Character::isItOkForMeToLoot",
    KenshiLib::GetRealAddress(&Character::isItOkForMeToLoot),
    Character_isItOkForMeToLoot_hook, Character_isItOkForMeToLoot_orig)

static float (*Character_getFencingSuccessChance_orig)(Character*, Item*, RootObject*) = NULL;

static float Character_getFencingSuccessChance_hook(Character* thisptr, Item* item, RootObject* thief)
{
    float current = Character_getFencingSuccessChance_orig(thisptr, item, thief);
    return CallCharacterGetFencingSuccessChanceCallbacks(thisptr, item, thief, current);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_getFencingSuccessChance,
    "Character::getFencingSuccessChance",
    KenshiLib::GetRealAddress(&Character::getFencingSuccessChance),
    Character_getFencingSuccessChance_hook, Character_getFencingSuccessChance_orig)

static void (*Character_changeSlaveOwner_orig)(Character*, const hand&) = NULL;

static void Character_changeSlaveOwner_hook(Character* thisptr, const hand& newOwner)
{
    Character_changeSlaveOwner_orig(thisptr, newOwner);
    CallCharacterSlaveOwnerChangedCallbacks(thisptr, newOwner);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_changeSlaveOwner,
    "Character::changeSlaveOwner",
    KenshiLib::GetRealAddress(&Character::changeSlaveOwner),
    Character_changeSlaveOwner_hook, Character_changeSlaveOwner_orig)

static void (*Character_setChainedMode_orig)(Character*, bool, const hand&) = NULL;

static void Character_setChainedMode_hook(Character* thisptr, bool on, const hand& owner)
{
    Character_setChainedMode_orig(thisptr, on, owner);
    CallCharacterChainedModeChangedCallbacks(thisptr, on, owner);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_setChainedMode,
    "Character::setChainedMode",
    KenshiLib::GetRealAddress(&Character::setChainedMode),
    Character_setChainedMode_hook, Character_setChainedMode_orig)

static void (*Character_NV_notifyIndoors_orig)(Character*, const hand&) = NULL;

static void Character_NV_notifyIndoors_hook(Character* thisptr, const hand& in)
{
    Character_NV_notifyIndoors_orig(thisptr, in);
    CallCharacterIndoorsChangedCallbacks(thisptr, in);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_NV_notifyIndoors,
    "Character::_NV_notifyIndoors",
    KenshiLib::GetRealAddress(&Character::_NV_notifyIndoors),
    Character_NV_notifyIndoors_hook, Character_NV_notifyIndoors_orig)


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

static void (*CharStats_ChooseAttack_orig)(CharStats*, float, float, CombatTechniqueData*, bool, CombatTechniqueData*) = NULL;

static void CharStats_ChooseAttack_hook(CharStats* thisptr, float range, float weaponReach, CombatTechniqueData* lastAttack, bool opponentIsStationary, CombatTechniqueData* chosenAttack)
{
    CharStats_ChooseAttack_orig(thisptr, range, weaponReach, lastAttack, opponentIsStationary, chosenAttack);
    CallCharStatsChooseAttackCallbacks(thisptr, range, weaponReach, lastAttack, opponentIsStationary, chosenAttack);
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


// ---------------------------------------------------------------------------
// Hooks for PlayerInterface.h
// ---------------------------------------------------------------------------

static void (*PlayerInterface_recruit_orig)(PlayerInterface*, Character*, bool) = NULL;

static void PlayerInterface_recruit_hook(PlayerInterface* thisptr, Character* character, bool editor)
{
    PlayerInterface_recruit_orig(thisptr, character, editor);
    CallPlayerRecruitCallbacks(thisptr, character, editor);
}

DEFINE_HOOK_INSTALLER(InstallHook_PlayerInterface_Recruit,
    "PlayerInterface::recruit",
    KenshiLib::GetRealAddress(static_cast<bool (PlayerInterface::*)(Character*, bool)>(&PlayerInterface::recruit)),
    PlayerInterface_recruit_hook, PlayerInterface_recruit_orig)

static void (*PlayerInterface_selectObject_orig)(PlayerInterface*, RootObject*, bool) = NULL;

static void PlayerInterface_selectObject_hook(PlayerInterface* thisptr, RootObject* obj, bool modifier)
{
    PlayerInterface_selectObject_orig(thisptr, obj, modifier);
    CallPlayerSelectCallbacks(thisptr, obj, modifier);
}

DEFINE_HOOK_INSTALLER(InstallHook_PlayerInterface_SelectObject,
    "PlayerInterface::selectObject",
    KenshiLib::GetRealAddress(&PlayerInterface::selectObject),
    PlayerInterface_selectObject_hook, PlayerInterface_selectObject_orig)

static void (*PlayerInterface_newPlayerTaskSelectedCharacters_orig)(PlayerInterface*, TaskType, const hand&, Building*, const Ogre::Vector3&, bool) = NULL;

static void PlayerInterface_newPlayerTaskSelectedCharacters_hook(PlayerInterface* thisptr, TaskType t, const hand& targetH, Building* destinationIndoors, const Ogre::Vector3& clickpos, bool addDontClear)
{
    PlayerInterface_newPlayerTaskSelectedCharacters_orig(thisptr, t, targetH, destinationIndoors, clickpos, addDontClear);
    CallPlayerOrderGivenCallbacks(thisptr, static_cast<int>(t), targetH, destinationIndoors, clickpos, addDontClear);
}

DEFINE_HOOK_INSTALLER(InstallHook_PlayerInterface_NewPlayerTaskSelectedCharacters,
    "PlayerInterface::newPlayerTaskSelectedCharacters",
    KenshiLib::GetRealAddress(&PlayerInterface::newPlayerTaskSelectedCharacters),
    PlayerInterface_newPlayerTaskSelectedCharacters_hook, PlayerInterface_newPlayerTaskSelectedCharacters_orig)

static void (*PlayerInterface_addJobSelectedCharacters_orig)(PlayerInterface*, TaskType, RootObject*, bool, bool, const Ogre::Vector3&) = NULL;

static void PlayerInterface_addJobSelectedCharacters_hook(PlayerInterface* thisptr, TaskType task, RootObject* subject, bool shift, bool add, const Ogre::Vector3& location)
{
    PlayerInterface_addJobSelectedCharacters_orig(thisptr, task, subject, shift, add, location);
    CallPlayerInterfaceAddJobSelectedCharactersCallbacks(thisptr, static_cast<int>(task), subject, shift, add, location);
}

DEFINE_HOOK_INSTALLER(InstallHook_PlayerInterface_addJobSelectedCharacters,
    "PlayerInterface::addJobSelectedCharacters",
    KenshiLib::GetRealAddress(&PlayerInterface::addJobSelectedCharacters),
    PlayerInterface_addJobSelectedCharacters_hook, PlayerInterface_addJobSelectedCharacters_orig)

static void (*PlayerInterface_addOrderSelectedCharacters_orig)(PlayerInterface*, Building*, TaskType, RootObject*, bool, bool, const Ogre::Vector3&) = NULL;

static void PlayerInterface_addOrderSelectedCharacters_hook(PlayerInterface* thisptr, Building* destinationIndoors, TaskType task, RootObject* subject, bool shift, bool addDontClear, const Ogre::Vector3& location)
{
    PlayerInterface_addOrderSelectedCharacters_orig(thisptr, destinationIndoors, task, subject, shift, addDontClear, location);
    CallPlayerInterfaceAddOrderSelectedCharactersCallbacks(thisptr, destinationIndoors, static_cast<int>(task), subject, shift, addDontClear, location);
}

DEFINE_HOOK_INSTALLER(InstallHook_PlayerInterface_addOrderSelectedCharacters,
    "PlayerInterface::addOrderSelectedCharacters",
    KenshiLib::GetRealAddress(&PlayerInterface::addOrderSelectedCharacters),
    PlayerInterface_addOrderSelectedCharacters_hook, PlayerInterface_addOrderSelectedCharacters_orig)

static void (*PlayerInterface_activateCharacterEditMode_orig)(PlayerInterface*, Character*) = NULL;

static void PlayerInterface_activateCharacterEditMode_hook(PlayerInterface* thisptr, Character* character)
{
    PlayerInterface_activateCharacterEditMode_orig(thisptr, character);
    CallPlayerActivateCharacterEditModeCallbacks(thisptr, character);
}

DEFINE_HOOK_INSTALLER(InstallHook_PlayerInterface_activateCharacterEditMode,
    "PlayerInterface::activateCharacterEditMode",
    KenshiLib::GetRealAddress(&PlayerInterface::activateCharacterEditMode),
    PlayerInterface_activateCharacterEditMode_hook, PlayerInterface_activateCharacterEditMode_orig)

static ActivePlatoon* (*PlayerInterface_createSquad_orig)(PlayerInterface*) = NULL;

static ActivePlatoon* PlayerInterface_createSquad_hook(PlayerInterface* thisptr)
{
    ActivePlatoon* newSquad = PlayerInterface_createSquad_orig(thisptr);
    CallPlayerCreateSquadCallbacks(thisptr, newSquad);
    return newSquad;
}

DEFINE_HOOK_INSTALLER(InstallHook_PlayerInterface_createSquad,
    "PlayerInterface::createSquad",
    KenshiLib::GetRealAddress(&PlayerInterface::createSquad),
    PlayerInterface_createSquad_hook, PlayerInterface_createSquad_orig)

static void (*PlayerInterface_encounterFaction_orig)(PlayerInterface*, Faction*) = NULL;

static void PlayerInterface_encounterFaction_hook(PlayerInterface* thisptr, Faction* faction)
{
    PlayerInterface_encounterFaction_orig(thisptr, faction);
    CallPlayerEncounterFactionCallbacks(thisptr, faction);
}

DEFINE_HOOK_INSTALLER(InstallHook_PlayerInterface_encounterFaction,
    "PlayerInterface::encounterFaction",
    KenshiLib::GetRealAddress(&PlayerInterface::encounterFaction),
    PlayerInterface_encounterFaction_hook, PlayerInterface_encounterFaction_orig)


// ---------------------------------------------------------------------------
// Hooks for Platoon.h
// ---------------------------------------------------------------------------

static void (*ActivePlatoon_addActiveObject_orig)(ActivePlatoon*, RootObject*) = NULL;

static void ActivePlatoon_addActiveObject_hook(ActivePlatoon* thisptr, RootObject* c)
{
    ActivePlatoon_addActiveObject_orig(thisptr, c);
    CallPlatoonMemberAddedCallbacks(thisptr, c);
}

DEFINE_HOOK_INSTALLER(InstallHook_ActivePlatoon_AddActiveObject,
    "ActivePlatoon::_NV_addActiveObject",
    KenshiLib::GetRealAddress(&ActivePlatoon::_NV_addActiveObject),
    ActivePlatoon_addActiveObject_hook, ActivePlatoon_addActiveObject_orig)

static void (*ActivePlatoon_removeObject_orig)(ActivePlatoon*, RootObject*) = NULL;

static void ActivePlatoon_removeObject_hook(ActivePlatoon* thisptr, RootObject* c)
{
    ActivePlatoon_removeObject_orig(thisptr, c);
    CallPlatoonMemberRemovedCallbacks(thisptr, c);
}

DEFINE_HOOK_INSTALLER(InstallHook_ActivePlatoon_RemoveObject,
    "ActivePlatoon::_NV_removeObject",
    KenshiLib::GetRealAddress(&ActivePlatoon::_NV_removeObject),
    ActivePlatoon_removeObject_hook, ActivePlatoon_removeObject_orig)

static void (*Platoon_taskIsComplete_orig)(Platoon*, Tasker*) = NULL;

static void Platoon_taskIsComplete_hook(Platoon* thisptr, Tasker* t)
{
    Platoon_taskIsComplete_orig(thisptr, t);
    CallPlatoonTaskCompleteCallbacks(thisptr, t);
}

DEFINE_HOOK_INSTALLER(InstallHook_Platoon_TaskIsComplete,
    "Platoon::taskIsComplete",
    KenshiLib::GetRealAddress(&Platoon::taskIsComplete),
    Platoon_taskIsComplete_hook, Platoon_taskIsComplete_orig)

static bool (*Platoon_iBuyStolenGoods_orig)(Platoon*, Item*) = NULL;

static bool Platoon_iBuyStolenGoods_hook(Platoon* thisptr, Item* what)
{
    bool current = Platoon_iBuyStolenGoods_orig(thisptr, what);
    return CallPlatoonIBuyStolenGoodsCallbacks(thisptr, what, current);
}

DEFINE_HOOK_INSTALLER(InstallHook_Platoon_iBuyStolenGoods,
    "Platoon::iBuyStolenGoods",
    KenshiLib::GetRealAddress(&Platoon::iBuyStolenGoods),
    Platoon_iBuyStolenGoods_hook, Platoon_iBuyStolenGoods_orig)

static bool (*Platoon_iBuyIllegalGoods_orig)(Platoon*) = NULL;

static bool Platoon_iBuyIllegalGoods_hook(Platoon* thisptr)
{
    bool current = Platoon_iBuyIllegalGoods_orig(thisptr);
    return CallPlatoonIBuyIllegalGoodsCallbacks(thisptr, current);
}

DEFINE_HOOK_INSTALLER(InstallHook_Platoon_iBuyIllegalGoods,
    "Platoon::iBuyIllegalGoods",
    KenshiLib::GetRealAddress(&Platoon::iBuyIllegalGoods),
    Platoon_iBuyIllegalGoods_hook, Platoon_iBuyIllegalGoods_orig)


// ---------------------------------------------------------------------------
// Hooks for Item.h
// ---------------------------------------------------------------------------

static void (*Item_notifyTheftFrom_orig)(Item*, RootObject*) = NULL;

static void Item_notifyTheftFrom_hook(Item* thisptr, RootObject* obj)
{
    Item_notifyTheftFrom_orig(thisptr, obj);
    CallItemStolenCallbacks(thisptr, obj);
}

DEFINE_HOOK_INSTALLER(InstallHook_Item_NotifyTheftFrom,
    "Item::_NV_notifyTheftFrom",
    KenshiLib::GetRealAddress(static_cast<void (Item::*)(RootObject*)>(&Item::_NV_notifyTheftFrom)),
    Item_notifyTheftFrom_hook, Item_notifyTheftFrom_orig)


// ---------------------------------------------------------------------------
// Hooks for Inventory.h / InventoryItemBase.h
// ---------------------------------------------------------------------------

static InventorySection* (*Inventory_getSectionOfType_orig)(Inventory*, int) = NULL;

static InventorySection* Inventory_getSectionOfType_hook(Inventory* thisptr, int type)
{
    InventorySection* current = Inventory_getSectionOfType_orig(thisptr, type);
    InventorySection* overrideSection = CallInventoryGetSectionOfTypeCallbacks(thisptr, type);
    return overrideSection ? overrideSection : current;
}

DEFINE_HOOK_INSTALLER(InstallHook_Inventory_getSectionOfType,
    "Inventory::getSectionOfType",
    KenshiLib::GetRealAddress(&Inventory::getSectionOfType),
    Inventory_getSectionOfType_hook, Inventory_getSectionOfType_orig)

static Item* (*Inventory_getBestFoodItem_orig)(const Inventory*, Character*) = NULL;

static Item* Inventory_getBestFoodItem_hook(const Inventory* thisptr, Character* race)
{
    Item* current = Inventory_getBestFoodItem_orig(thisptr, race);
    Item* overrideFood = CallInventoryGetBestFoodItemCallbacks(const_cast<Inventory*>(thisptr), race);
    return overrideFood ? overrideFood : current;
}

DEFINE_HOOK_INSTALLER(InstallHook_Inventory_getBestFoodItem,
    "Inventory::getBestFoodItem",
    KenshiLib::GetRealAddress(&Inventory::getBestFoodItem),
    Inventory_getBestFoodItem_hook, Inventory_getBestFoodItem_orig)

static int (*InventoryItemBase_getValueSingle_orig)(const InventoryItemBase*, bool) = NULL;

static int InventoryItemBase_getValueSingle_hook(const InventoryItemBase* thisptr, bool isPlayer)
{
    int current = InventoryItemBase_getValueSingle_orig(thisptr, isPlayer);
    return CallInventoryItemBaseGetValueSingleCallbacks(thisptr, isPlayer, current);
}

DEFINE_HOOK_INSTALLER(InstallHook_InventoryItemBase_getValueSingle,
    "InventoryItemBase::getValueSingle",
    KenshiLib::GetRealAddress(&InventoryItemBase::_NV_getValueSingle),
    InventoryItemBase_getValueSingle_hook, InventoryItemBase_getValueSingle_orig)

static bool (*Inventory_NV_addItem_orig)(Inventory*, Item*, int, bool, bool) = NULL;

static bool Inventory_NV_addItem_hook(Inventory* thisptr, Item* item, int quantity, bool dropOnFail, bool destroyOnFail)
{
    if (!CallInventoryAddItemCallbacks(thisptr, item, quantity, dropOnFail, destroyOnFail))
        return false;
    return Inventory_NV_addItem_orig(thisptr, item, quantity, dropOnFail, destroyOnFail);
}

DEFINE_HOOK_INSTALLER(InstallHook_Inventory_NV_addItem,
    "Inventory::_NV_addItem",
    KenshiLib::GetRealAddress(static_cast<bool (Inventory::*)(Item*, int, bool, bool)>(&Inventory::_NV_addItem)),
    Inventory_NV_addItem_hook, Inventory_NV_addItem_orig)

static Item* (*Inventory_NV_removeItemDontDestroy_returnsItem_orig)(Inventory*, Item*, int, bool) = NULL;

static Item* Inventory_NV_removeItemDontDestroy_returnsItem_hook(Inventory* thisptr, Item* it, int howmany, bool returnCopyIfSomeLeft)
{
    Item* current = Inventory_NV_removeItemDontDestroy_returnsItem_orig(thisptr, it, howmany, returnCopyIfSomeLeft);
    Item* overrideItem = CallInventoryRemoveItemCallbacks(thisptr, it, howmany, returnCopyIfSomeLeft);
    return overrideItem ? overrideItem : current;
}

DEFINE_HOOK_INSTALLER(InstallHook_Inventory_NV_removeItemDontDestroy_returnsItem,
    "Inventory::_NV_removeItemDontDestroy_returnsItem",
    KenshiLib::GetRealAddress(static_cast<Item* (Inventory::*)(Item*, int, bool)>(&Inventory::_NV_removeItemDontDestroy_returnsItem)),
    Inventory_NV_removeItemDontDestroy_returnsItem_hook, Inventory_NV_removeItemDontDestroy_returnsItem_orig)

static Item* (*Inventory_buyItem_orig)(Inventory*, Item*, RootObject*) = NULL;

static Item* Inventory_buyItem_hook(Inventory* thisptr, Item* itemToBuy, RootObject* sendingTo)
{
    Item* current = Inventory_buyItem_orig(thisptr, itemToBuy, sendingTo);
    Item* overrideItem = CallInventoryBuyItemCallbacks(thisptr, itemToBuy, sendingTo);
    return overrideItem ? overrideItem : current;
}

DEFINE_HOOK_INSTALLER(InstallHook_Inventory_buyItem,
    "Inventory::buyItem",
    KenshiLib::GetRealAddress(&Inventory::buyItem),
    Inventory_buyItem_hook, Inventory_buyItem_orig)


// ---------------------------------------------------------------------------
// Hooks for BountyManager.h
// ---------------------------------------------------------------------------

static void (*BountyManager_notifyCrimeWitnessed_orig)(Character*, Faction*, const hand&, int, int) = NULL;

static void BountyManager_notifyCrimeWitnessed_hook(Character* character, Faction* against, const hand& againstWho, int expiryTime, int crimeType)
{
    BountyManager_notifyCrimeWitnessed_orig(character, against, againstWho, expiryTime, crimeType);
    CallCrimeWitnessedCallbacks(character, against, againstWho, expiryTime, crimeType);
}

DEFINE_HOOK_INSTALLER(InstallHook_BountyManager_NotifyCrimeWitnessed,
    "BountyManager::notifyCrimeWitnessed",
    KenshiLib::GetRealAddress(&BountyManager::notifyCrimeWitnessed),
    BountyManager_notifyCrimeWitnessed_hook, BountyManager_notifyCrimeWitnessed_orig)


// ---------------------------------------------------------------------------
// Hooks for FactionRelations.h
// ---------------------------------------------------------------------------

static void (*FactionRelations_affectRelations_orig)(Faction*, Faction*, int, float) = NULL;

static void FactionRelations_affectRelations_hook(Faction* faction, Faction* other, int eventType, float multiplier)
{
    FactionRelations_affectRelations_orig(faction, other, eventType, multiplier);
    CallFactionRelationsAffectedCallbacks(faction, other, eventType, multiplier);
}

DEFINE_HOOK_INSTALLER(InstallHook_FactionRelations_AffectRelations,
    "FactionRelations::affectRelations",
    KenshiLib::GetRealAddress(static_cast<void (FactionRelations::*)(Faction*, FactionRelations::FactionEvent, float)>(&FactionRelations::affectRelations)),
    FactionRelations_affectRelations_hook, FactionRelations_affectRelations_orig)


// ---------------------------------------------------------------------------
// Hooks for Faction.h
// ---------------------------------------------------------------------------

static GameData* (*Faction_chooseARace_orig)(Faction*, GameData*, GameData*) = NULL;

static GameData* Faction_chooseARace_hook(Faction* thisptr, GameData* character, GameData* squadTemplate)
{
    GameData* current = Faction_chooseARace_orig(thisptr, character, squadTemplate);
    return CallFactionChooseARaceCallbacks(thisptr, character, squadTemplate, current);
}

DEFINE_HOOK_INSTALLER(InstallHook_Faction_chooseARace,
    "Faction::chooseARace",
    KenshiLib::GetRealAddress(&Faction::chooseARace),
    Faction_chooseARace_hook, Faction_chooseARace_orig)

static GameData* (*Faction_getBuildingReplacement_orig)(Faction*, GameData*) = NULL;

static GameData* Faction_getBuildingReplacement_hook(Faction* thisptr, GameData* building)
{
    GameData* current = Faction_getBuildingReplacement_orig(thisptr, building);
    return CallFactionGetBuildingReplacementCallbacks(thisptr, building, current);
}

DEFINE_HOOK_INSTALLER(InstallHook_Faction_getBuildingReplacement,
    "Faction::getBuildingReplacement",
    KenshiLib::GetRealAddress(&Faction::getBuildingReplacement),
    Faction_getBuildingReplacement_hook, Faction_getBuildingReplacement_orig)

static Platoon* (*Faction_createNewEmptyActivePlatoon_orig)(Faction*, GameData*, bool, const Ogre::Vector3&) = NULL;

static Platoon* Faction_createNewEmptyActivePlatoon_hook(Faction* thisptr, GameData* squadTemplate, bool permanent, const Ogre::Vector3& p)
{
    Platoon* platoon = Faction_createNewEmptyActivePlatoon_orig(thisptr, squadTemplate, permanent, p);
    CallFactionActivePlatoonCreatedCallbacks(thisptr, platoon);
    return platoon;
}

DEFINE_HOOK_INSTALLER(InstallHook_Faction_createNewEmptyActivePlatoon,
    "Faction::createNewEmptyActivePlatoon",
    KenshiLib::GetRealAddress(&Faction::createNewEmptyActivePlatoon),
    Faction_createNewEmptyActivePlatoon_hook, Faction_createNewEmptyActivePlatoon_orig)

static void (*Faction_destroyPlatoon_orig)(Faction*, Platoon*) = NULL;

static void Faction_destroyPlatoon_hook(Faction* thisptr, Platoon* platoon)
{
    Faction_destroyPlatoon_orig(thisptr, platoon);
    CallFactionPlatoonDestroyedCallbacks(thisptr, platoon);
}

DEFINE_HOOK_INSTALLER(InstallHook_Faction_destroyPlatoon,
    "Faction::destroyPlatoon",
    KenshiLib::GetRealAddress(&Faction::destroyPlatoon),
    Faction_destroyPlatoon_hook, Faction_destroyPlatoon_orig)


// ---------------------------------------------------------------------------
// Hooks for MedicalSystem.h
// ---------------------------------------------------------------------------

static void (*MedicalSystem_amputate_orig)(Character*, int, bool, const Ogre::Vector3&) = NULL;

static void MedicalSystem_amputate_hook(Character* character, int limb, bool createSeveredItem, const Ogre::Vector3& force)
{
    MedicalSystem_amputate_orig(character, limb, createSeveredItem, force);
    CallLimbAmputatedCallbacks(character, limb, createSeveredItem, force);
}

DEFINE_HOOK_INSTALLER(InstallHook_MedicalSystem_Amputate,
    "MedicalSystem::amputate",
    KenshiLib::GetRealAddress(&MedicalSystem::amputate),
    MedicalSystem_amputate_hook, MedicalSystem_amputate_orig)

static void (*MedicalSystem_knockout_orig)(MedicalSystem*, float) = NULL;

static void MedicalSystem_knockout_hook(MedicalSystem* thisptr, float skill)
{
    MedicalSystem_knockout_orig(thisptr, skill);
    CallMedicalSystemKnockoutCallbacks(thisptr, skill);
}

DEFINE_HOOK_INSTALLER(InstallHook_MedicalSystem_knockout,
    "MedicalSystem::knockout",
    KenshiLib::GetRealAddress(&MedicalSystem::knockout),
    MedicalSystem_knockout_hook, MedicalSystem_knockout_orig)

static bool (*MedicalSystem_canGetUpWakeUp_orig)(MedicalSystem*) = NULL;

static bool MedicalSystem_canGetUpWakeUp_hook(MedicalSystem* thisptr)
{
    bool current = MedicalSystem_canGetUpWakeUp_orig(thisptr);
    return CallMedicalSystemCanGetUpWakeUpCallbacks(thisptr) ? current : false;
}

DEFINE_HOOK_INSTALLER(InstallHook_MedicalSystem_canGetUpWakeUp,
    "MedicalSystem::canGetUpWakeUp",
    KenshiLib::GetRealAddress(&MedicalSystem::canGetUpWakeUp),
    MedicalSystem_canGetUpWakeUp_hook, MedicalSystem_canGetUpWakeUp_orig)


// ---------------------------------------------------------------------------
// Hooks for gui/DialogueWindow.h
// ---------------------------------------------------------------------------

static void (*DialogueWindow_show_orig)(DialogueWindow*, Dialogue*) = NULL;

static void DialogueWindow_show_hook(DialogueWindow* thisptr, Dialogue* dialogue)
{
    DialogueWindow_show_orig(thisptr, dialogue);
    CallDialogueWindowShowCallbacks(thisptr, dialogue);
}

DEFINE_HOOK_INSTALLER(InstallHook_DialogueWindow_Show,
    "DialogueWindow::show",
    KenshiLib::GetRealAddress(static_cast<void (DialogueWindow::*)(Dialogue*)>(&DialogueWindow::show)),
    DialogueWindow_show_hook, DialogueWindow_show_orig)


// ---------------------------------------------------------------------------
// Hooks for Dialogue.h
// ---------------------------------------------------------------------------

static void (*Dialogue_doActions_orig)(Dialogue*, DialogLineData*) = NULL;

static void Dialogue_doActions_hook(Dialogue* thisptr, DialogLineData* dialogLine)
{
    Dialogue_doActions_orig(thisptr, dialogLine);

    if (thisptr && dialogLine)
    {
        KenshiLua::DialogueScriptBridge(thisptr, dialogLine);
    }

    CallDialogueDoActionsCallbacks(thisptr, dialogLine);
}

DEFINE_HOOK_INSTALLER(InstallHook_Dialogue_DoActions,
    "Dialogue::_doActions",
    KenshiLib::GetRealAddress(&Dialogue::_doActions),
    Dialogue_doActions_hook, Dialogue_doActions_orig)

static void (*Dialogue_say_orig)(Dialogue*, DialogLineData*) = NULL;

static void Dialogue_say_hook(Dialogue* thisptr, DialogLineData* dialogLine)
{
    Dialogue_say_orig(thisptr, dialogLine);
    CallDialogueSayCallbacks(thisptr, dialogLine);
}

DEFINE_HOOK_INSTALLER(InstallHook_Dialogue_Say,
    "Dialogue::say",
    KenshiLib::GetRealAddress(static_cast<void (Dialogue::*)(DialogLineData*)>(&Dialogue::say)),
    Dialogue_say_hook, Dialogue_say_orig)

static void (*Dialogue_endDialogue_orig)(Dialogue*, bool) = NULL;

static void Dialogue_endDialogue_hook(Dialogue* thisptr, bool definitelyTheEnd)
{
    Dialogue_endDialogue_orig(thisptr, definitelyTheEnd);
    CallDialogueEndDialogueCallbacks(thisptr, definitelyTheEnd);
}

DEFINE_HOOK_INSTALLER(InstallHook_Dialogue_endDialogue,
    "Dialogue::endDialogue",
    KenshiLib::GetRealAddress(&Dialogue::endDialogue),
    Dialogue_endDialogue_hook, Dialogue_endDialogue_orig)

static bool (*Dialogue__checkCondition_orig)(Dialogue*, DialogConditionEnum, ComparisonEnum, int, Character*, Character*) = NULL;

static bool Dialogue__checkCondition_hook(Dialogue* thisptr, DialogConditionEnum conditionName, ComparisonEnum compareBy, int val, Character* target, Character* actualConversationTarget)
{
    bool current = Dialogue__checkCondition_orig(thisptr, conditionName, compareBy, val, target, actualConversationTarget);
    return CallDialogueCheckConditionCallbacks(thisptr, conditionName, compareBy, val, target, actualConversationTarget, current);
}

DEFINE_HOOK_INSTALLER(InstallHook_Dialogue__checkCondition,
    "Dialogue::_checkCondition",
    KenshiLib::GetRealAddress(&Dialogue::_checkCondition),
    Dialogue__checkCondition_hook, Dialogue__checkCondition_orig)

static bool (*Dialogue_startConversation_orig)(Dialogue*, Character*, DialogLineData*, EventTriggerEnum, bool) = NULL;

static bool Dialogue_startConversation_hook(Dialogue* thisptr, Character* target, DialogLineData* _talk, EventTriggerEnum ev, bool force)
{
    bool current = Dialogue_startConversation_orig(thisptr, target, _talk, ev, force);
    return CallDialogueStartConversationCallbacks(thisptr, target, _talk, ev, force, current);
}

DEFINE_HOOK_INSTALLER(InstallHook_Dialogue_startConversation,
    "Dialogue::startConversation",
    KenshiLib::GetRealAddress(&Dialogue::startConversation),
    Dialogue_startConversation_hook, Dialogue_startConversation_orig)

static void (*Dialogue__endPlayerConversation_orig)(Dialogue*, bool) = NULL;

static void Dialogue__endPlayerConversation_hook(Dialogue* thisptr, bool finished)
{
    Dialogue__endPlayerConversation_orig(thisptr, finished);
    CallDialogueEndPlayerConversationCallbacks(thisptr, finished);
}

DEFINE_HOOK_INSTALLER(InstallHook_Dialogue__endPlayerConversation,
    "Dialogue::_endPlayerConversation",
    KenshiLib::GetRealAddress(&Dialogue::_endPlayerConversation),
    Dialogue__endPlayerConversation_hook, Dialogue__endPlayerConversation_orig)

static bool (*Dialogue_startPlayerConversation_orig)(Dialogue*, Character*, DialogLineData*) = NULL;

static bool Dialogue_startPlayerConversation_hook(Dialogue* thisptr, Character* target, DialogLineData* _talk)
{
    bool current = Dialogue_startPlayerConversation_orig(thisptr, target, _talk);
    return CallDialogueStartPlayerConversationCallbacks(thisptr, target, _talk, current);
}

DEFINE_HOOK_INSTALLER(InstallHook_Dialogue_startPlayerConversation,
    "Dialogue::startPlayerConversation",
    KenshiLib::GetRealAddress(&Dialogue::startPlayerConversation),
    Dialogue_startPlayerConversation_hook, Dialogue_startPlayerConversation_orig)

static bool (*Dialogue_sendEvent_orig)(Dialogue*, Character*, EventTriggerEnum) = NULL;

static bool Dialogue_sendEvent_hook(Dialogue* thisptr, Character* who, EventTriggerEnum what)
{
    bool current = Dialogue_sendEvent_orig(thisptr, who, what);
    return CallDialogueSendEventCallbacks(thisptr, who, what, current);
}

DEFINE_HOOK_INSTALLER(InstallHook_Dialogue_sendEvent,
    "Dialogue::sendEvent",
    KenshiLib::GetRealAddress(&Dialogue::sendEvent),
    Dialogue_sendEvent_hook, Dialogue_sendEvent_orig)

static void (*Dialogue_stopEvent_orig)(Dialogue*, EventTriggerEnum) = NULL;

static void Dialogue_stopEvent_hook(Dialogue* thisptr, EventTriggerEnum what)
{
    Dialogue_stopEvent_orig(thisptr, what);
    CallDialogueStopEventCallbacks(thisptr, what);
}

DEFINE_HOOK_INSTALLER(InstallHook_Dialogue_stopEvent,
    "Dialogue::stopEvent",
    KenshiLib::GetRealAddress(&Dialogue::stopEvent),
    Dialogue_stopEvent_hook, Dialogue_stopEvent_orig)


// ---------------------------------------------------------------------------
// Hooks for RootObjectFactory.h
// ---------------------------------------------------------------------------

static void (*RootObjectFactory_chooseMyClothing_orig)(lektor<GameData*>&, GameData*, const std::string&, RaceData*, bool) = NULL;

static void RootObjectFactory_chooseMyClothing_hook(lektor<GameData*>& gear, GameData* dataList, const std::string& listName, RaceData* race, bool noShoes)
{
    RootObjectFactory_chooseMyClothing_orig(gear, dataList, listName, race, noShoes);
    CallChooseMyClothingCallbacks(gear, dataList, listName, race, noShoes);
}

DEFINE_HOOK_INSTALLER(InstallHook_RootObjectFactory_chooseMyClothing,
    "RootObjectFactory::chooseMyClothing",
    KenshiLib::GetRealAddress(&RootObjectFactory::chooseMyClothing),
    RootObjectFactory_chooseMyClothing_hook, RootObjectFactory_chooseMyClothing_orig)


// ---------------------------------------------------------------------------
// Hooks for mygui/common/baselayout/BaseLayout.h
// ---------------------------------------------------------------------------

static void (*BaseLayout_initialise_orig)(wraps::BaseLayout*, const std::string&, MyGUI::Widget*, bool, bool) = NULL;

static void BaseLayout_initialise_hook(wraps::BaseLayout* thisptr, const std::string& layout, MyGUI::Widget* parent, bool throwException, bool createChildren)
{
    BaseLayout_initialise_orig(thisptr, layout, parent, throwException, createChildren);
    CallBaseLayoutInitialiseCallbacks(layout);
}

DEFINE_HOOK_INSTALLER(InstallHook_BaseLayout_initialise,
    "wraps::BaseLayout::initialise",
    KenshiLib::GetRealAddress(static_cast<void (wraps::BaseLayout::*)(const std::string&, MyGUI::Widget*, bool, bool)>(&wraps::BaseLayout::initialise)),
    BaseLayout_initialise_hook, BaseLayout_initialise_orig)


// ---------------------------------------------------------------------------
// Hooks for Ownerships.h
// ---------------------------------------------------------------------------

static bool (*Ownerships_canIUseThisBuilding_orig)(Ownerships*, Building*, Character*) = NULL;

static bool Ownerships_canIUseThisBuilding_hook(Ownerships* thisptr, Building* b, Character* me)
{
    bool current = Ownerships_canIUseThisBuilding_orig(thisptr, b, me);
    return CallOwnershipsCanIUseThisBuildingCallbacks(thisptr, b, me, current);
}

DEFINE_HOOK_INSTALLER(InstallHook_Ownerships_canIUseThisBuilding,
    "Ownerships::canIUseThisBuilding",
    KenshiLib::GetRealAddress(&Ownerships::canIUseThisBuilding),
    Ownerships_canIUseThisBuilding_hook, Ownerships_canIUseThisBuilding_orig)


// ---------------------------------------------------------------------------
// Hooks for Building/Building.h
// ---------------------------------------------------------------------------

static bool (*Building_isPublic_orig)(const Building*) = NULL;

static bool Building_isPublic_hook(const Building* thisptr)
{
    bool current = Building_isPublic_orig(thisptr);
    return CallBuildingIsPublicCallbacks(thisptr, current);
}

DEFINE_HOOK_INSTALLER(InstallHook_Building_isPublic,
    "Building::isPublic",
    KenshiLib::GetRealAddress(&Building::isPublic),
    Building_isPublic_hook, Building_isPublic_orig)

static bool (*Building_isForSale_orig)(Building*) = NULL;

static bool Building_isForSale_hook(Building* thisptr)
{
    bool current = Building_isForSale_orig(thisptr);
    return CallBuildingIsForSaleCallbacks(thisptr, current);
}

DEFINE_HOOK_INSTALLER(InstallHook_Building_isForSale,
    "Building::isForSale",
    KenshiLib::GetRealAddress(&Building::isForSale),
    Building_isForSale_hook, Building_isForSale_orig)

static int (*Building_calculateSaleValue_orig)(Building*) = NULL;

static int Building_calculateSaleValue_hook(Building* thisptr)
{
    int current = Building_calculateSaleValue_orig(thisptr);
    return CallBuildingCalculateSaleValueCallbacks(thisptr, current);
}

DEFINE_HOOK_INSTALLER(InstallHook_Building_calculateSaleValue,
    "Building::calculateSaleValue",
    KenshiLib::GetRealAddress(&Building::calculateSaleValue),
    Building_calculateSaleValue_hook, Building_calculateSaleValue_orig)

static void (*Building_NV_onBuildingLoaded_orig)(Building*) = NULL;

static void Building_NV_onBuildingLoaded_hook(Building* thisptr)
{
    Building_NV_onBuildingLoaded_orig(thisptr);
    CallBuildingLoadedCallbacks(thisptr);
}

DEFINE_HOOK_INSTALLER(InstallHook_Building_NV_onBuildingLoaded,
    "Building::_NV_onBuildingLoaded",
    KenshiLib::GetRealAddress(&Building::_NV_onBuildingLoaded),
    Building_NV_onBuildingLoaded_hook, Building_NV_onBuildingLoaded_orig)

static void (*Building_NV_setBroken_orig)(Building*, bool) = NULL;

static void Building_NV_setBroken_hook(Building* thisptr, bool broken)
{
    Building_NV_setBroken_orig(thisptr, broken);
    CallBuildingBrokenChangedCallbacks(thisptr, broken);
}

DEFINE_HOOK_INSTALLER(InstallHook_Building_NV_setBroken,
    "Building::_NV_setBroken",
    KenshiLib::GetRealAddress(&Building::_NV_setBroken),
    Building_NV_setBroken_hook, Building_NV_setBroken_orig)


// ---------------------------------------
// Hooks for CharMovement.h
// ---------------------------------------

static bool (*CharMovement_isRunning_orig)(CharMovement*) = NULL;

static bool CharMovement_isRunning_hook(CharMovement* thisptr)
{
    bool current = CharMovement_isRunning_orig(thisptr);
    return CallCharMovementIsRunningCallbacks(thisptr, current);
}

DEFINE_HOOK_INSTALLER(InstallHook_CharMovement_isRunning,
    "CharMovement::isRunning",
    KenshiLib::GetRealAddress(&CharMovement::isRunning),
    CharMovement_isRunning_hook, CharMovement_isRunning_orig)

static bool (*CharMovement_isRunningAway_orig)(CharMovement*, const Ogre::Vector3& from) = NULL;

static bool CharMovement_isRunningAway_hook(CharMovement* thisptr, const Ogre::Vector3& from)
{
    bool current = CharMovement_isRunningAway_orig(thisptr, from);
    return CallCharMovementIsRunningAwayCallbacks(thisptr, from, current);
}

DEFINE_HOOK_INSTALLER(InstallHook_CharMovement_isRunningAway,
    "CharMovement::isRunningAway",
    KenshiLib::GetRealAddress(&CharMovement::isRunningAway),
    CharMovement_isRunningAway_hook, CharMovement_isRunningAway_orig)



static void (*Building_setResidentSquad_orig)(Building*, Platoon*) = NULL;

static void Building_setResidentSquad_hook(Building* thisptr, Platoon* who)
{
    Building_setResidentSquad_orig(thisptr, who);
    CallBuildingSetResidentSquadCallbacks(thisptr, who);
}

DEFINE_HOOK_INSTALLER(InstallHook_Building_setResidentSquad,
    "Building::setResidentSquad",
    KenshiLib::GetRealAddress(&Building::setResidentSquad),
    Building_setResidentSquad_hook, Building_setResidentSquad_orig)

static void (*Building_addAnInternalBuilding_orig)(Building*, Building*) = NULL;

static void Building_addAnInternalBuilding_hook(Building* thisptr, Building* b)
{
    Building_addAnInternalBuilding_orig(thisptr, b);
    CallBuildingAddInternalBuildingCallbacks(thisptr, b);
}

DEFINE_HOOK_INSTALLER(InstallHook_Building_addAnInternalBuilding,
    "Building::addAnInternalBuilding",
    KenshiLib::GetRealAddress(&Building::addAnInternalBuilding),
    Building_addAnInternalBuilding_hook, Building_addAnInternalBuilding_orig)

static void (*InventoryGUI_addTradePartner_orig)(InventoryGUI*, bool, bool, bool, const hand&) = NULL;

static void InventoryGUI_addTradePartner_hook(InventoryGUI* tradeWith, bool payment, bool canDrop, bool isPlayer, const hand& who)
{
    InventoryGUI_addTradePartner_orig(tradeWith, payment, canDrop, isPlayer, who);
    CallInventoryAddTradePartnerCallbacks(tradeWith, payment, canDrop, isPlayer, who);
}

DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_addTradePartner,
    "InventoryGUI::addTradePartner",
    KenshiLib::GetRealAddress(&InventoryGUI::addTradePartner),
    InventoryGUI_addTradePartner_hook, InventoryGUI_addTradePartner_orig)

static void (*BuildModeWindow_confirm_orig)(BuildModeWindow*, MyGUI::Widget*) = NULL;

static void BuildModeWindow_confirm_hook(BuildModeWindow* thisptr, MyGUI::Widget* sender)
{
    BuildModeWindow_confirm_orig(thisptr, sender);
    CallBuildModeWindowConfirmCallbacks(thisptr, sender);
}

DEFINE_HOOK_INSTALLER(InstallHook_BuildModeWindow_confirm,
    "BuildModeWindow::confirm",
    KenshiLib::GetRealAddress(&BuildModeWindow::confirm),
    BuildModeWindow_confirm_hook, BuildModeWindow_confirm_orig)

static void (*SquadManagementScreen_removeSquad_orig)(SquadManagementScreen*, SquadManagementScreen::SquadData*) = NULL;

static void SquadManagementScreen_removeSquad_hook(SquadManagementScreen* thisptr, SquadManagementScreen::SquadData* squad)
{
    SquadManagementScreen_removeSquad_orig(thisptr, squad);
    CallSquadManagementScreenRemoveSquadCallbacks(thisptr, squad);
}

DEFINE_HOOK_INSTALLER(InstallHook_SquadManagementScreen_removeSquad,
    "SquadManagementScreen::removeSquad",
    KenshiLib::GetRealAddress(&SquadManagementScreen::removeSquad),
    SquadManagementScreen_removeSquad_hook, SquadManagementScreen_removeSquad_orig)

static void (*ManagementScreen_addMessage_orig)(ManagementScreen*, const std::string&, const std::string&, MessageLogColor) = NULL;

static void ManagementScreen_addMessage_hook(ManagementScreen* thisptr, const std::string& owner, const std::string& message, MessageLogColor isPlayer)
{
    ManagementScreen_addMessage_orig(thisptr, owner, message, isPlayer);
    CallManagementScreenAddMessageCallbacks(thisptr, owner, message, static_cast<int>(isPlayer));
}

DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_addMessage,
    "ManagementScreen::addMessage",
    KenshiLib::GetRealAddress(&ManagementScreen::addMessage),
    ManagementScreen_addMessage_hook, ManagementScreen_addMessage_orig)

static void (*TitleScreen_loadGame_orig)(TitleScreen*, MyGUI::Widget*) = NULL;

static void TitleScreen_loadGame_hook(TitleScreen* thisptr, MyGUI::Widget* sender)
{
    TitleScreen_loadGame_orig(thisptr, sender);
    CallTitleScreenLoadGameCallbacks(thisptr, sender);
}

DEFINE_HOOK_INSTALLER(InstallHook_TitleScreen_loadGame,
    "TitleScreen::loadGame",
    KenshiLib::GetRealAddress(&TitleScreen::loadGame),
    TitleScreen_loadGame_hook, TitleScreen_loadGame_orig)

static void (*Character_addGoal_orig)(Character*, TaskType, RootObjectBase*) = NULL;

static void Character_addGoal_hook(Character* thisptr, TaskType t, RootObjectBase* subject)
{
    Character_addGoal_orig(thisptr, t, subject);
    CallCharacterAddGoalCallbacks(thisptr, static_cast<int>(t), static_cast<RootObject*>(subject));
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_addGoal,
    "Character::addGoal",
    KenshiLib::GetRealAddress(&Character::addGoal),
    Character_addGoal_hook, Character_addGoal_orig)

static void (*Character_addJob_orig)(Character*, TaskType, RootObject*, bool, bool, const Ogre::Vector3&) = NULL;

static void Character_addJob_hook(Character* thisptr, TaskType t, RootObject* subject, bool shift, bool addDontClear, const Ogre::Vector3& location)
{
    Character_addJob_orig(thisptr, t, subject, shift, addDontClear, location);
    CallCharacterAddJobCallbacks(thisptr, static_cast<int>(t), subject, shift, addDontClear, location);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_addJob,
    "Character::addJob",
    KenshiLib::GetRealAddress(&Character::addJob),
    Character_addJob_hook, Character_addJob_orig)

static void (*Character_addOrder_orig)(Character*, Building*, TaskType, RootObject*, bool, bool, const Ogre::Vector3&) = NULL;

static void Character_addOrder_hook(Character* thisptr, Building* dest, TaskType t, RootObject* subject, bool shift, bool clear, const Ogre::Vector3& location)
{
    Character_addOrder_orig(thisptr, dest, t, subject, shift, clear, location);
    CallCharacterAddOrderCallbacks(thisptr, dest, static_cast<int>(t), subject, shift, clear, location);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_addOrder,
    "Character::addOrder",
    KenshiLib::GetRealAddress(&Character::addOrder),
    Character_addOrder_hook, Character_addOrder_orig)

static void (*Character_removeJob_orig)(Character*, TaskType) = NULL;

static void Character_removeJob_hook(Character* thisptr, TaskType t)
{
    Character_removeJob_orig(thisptr, t);
    CallCharacterRemoveJobCallbacks(thisptr, static_cast<int>(t));
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_removeJob,
    "Character::removeJob",
    KenshiLib::GetRealAddress(&Character::removeJob),
    Character_removeJob_hook, Character_removeJob_orig)

// ---------------------------------------------------------------------------
// Serialization Hooks
// ---------------------------------------------------------------------------

// PlayerInterface
static void (*PlayerInterface_serialise_orig)(PlayerInterface*, GameData*) = NULL;
static void PlayerInterface_serialise_hook(PlayerInterface* thisptr, GameData* data)
{
    PlayerInterface_serialise_orig(thisptr, data);
    CallPlayerInterfaceSerialiseCallbacks(thisptr, data);
}
DEFINE_HOOK_INSTALLER(InstallHook_PlayerInterface_serialise,
    "PlayerInterface::serialise",
    KenshiLib::GetRealAddress(&PlayerInterface::serialise),
    PlayerInterface_serialise_hook, PlayerInterface_serialise_orig)

static void (*PlayerInterface_loadFromSerialise_orig)(PlayerInterface*, GameData*) = NULL;
static void PlayerInterface_loadFromSerialise_hook(PlayerInterface* thisptr, GameData* data)
{
    PlayerInterface_loadFromSerialise_orig(thisptr, data);
    CallPlayerInterfaceLoadFromSerialiseCallbacks(thisptr, data);
}
DEFINE_HOOK_INSTALLER(InstallHook_PlayerInterface_loadFromSerialise,
    "PlayerInterface::loadFromSerialise",
    KenshiLib::GetRealAddress(&PlayerInterface::loadFromSerialise),
    PlayerInterface_loadFromSerialise_hook, PlayerInterface_loadFromSerialise_orig)

// Character
static GameSaveState (*Character_NV_serialise_orig)(Character*, GameDataContainer*, GameData*, PosRotPair*) = NULL;
static GameSaveState Character_NV_serialise_hook(Character* thisptr, GameDataContainer* container, GameData* refList, PosRotPair* offsetPosToSubtract)
{
    GameSaveState res = Character_NV_serialise_orig(thisptr, container, refList, offsetPosToSubtract);
    CallCharacterSerialiseCallbacks(thisptr, container, refList);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_NV_serialise,
    "Character::_NV_serialise",
    KenshiLib::GetRealAddress(&Character::_NV_serialise),
    Character_NV_serialise_hook, Character_NV_serialise_orig)

static void (*Character_NV_loadFromSerialise_orig)(Character*, GameSaveState*) = NULL;
static void Character_NV_loadFromSerialise_hook(Character* thisptr, GameSaveState* state)
{
    Character_NV_loadFromSerialise_orig(thisptr, state);
    CallCharacterLoadFromSerialiseCallbacks(thisptr, state);
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_NV_loadFromSerialise,
    "Character::_NV_loadFromSerialise",
    KenshiLib::GetRealAddress(&Character::_NV_loadFromSerialise),
    Character_NV_loadFromSerialise_hook, Character_NV_loadFromSerialise_orig)

static void (*Character_NV_loadFromSerialisePostCreationStage_orig)(Character*, GameSaveState*) = NULL;
static void Character_NV_loadFromSerialisePostCreationStage_hook(Character* thisptr, GameSaveState* gd)
{
    Character_NV_loadFromSerialisePostCreationStage_orig(thisptr, gd);
    CallCharacterLoadFromSerialisePostCreationStageCallbacks(thisptr, gd);
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_NV_loadFromSerialisePostCreationStage,
    "Character::_NV_loadFromSerialisePostCreationStage",
    KenshiLib::GetRealAddress(&Character::_NV_loadFromSerialisePostCreationStage),
    Character_NV_loadFromSerialisePostCreationStage_hook, Character_NV_loadFromSerialisePostCreationStage_orig)

// Building
static GameSaveState (*Building_NV_serialise_orig)(Building*, GameDataContainer*, GameData*, PosRotPair*) = NULL;
static GameSaveState Building_NV_serialise_hook(Building* thisptr, GameDataContainer* container, GameData* refList, PosRotPair* offsetPosToSubtract)
{
    GameSaveState res = Building_NV_serialise_orig(thisptr, container, refList, offsetPosToSubtract);
    CallBuildingSerialiseCallbacks(thisptr, container, refList);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_NV_serialise,
    "Building::_NV_serialise",
    KenshiLib::GetRealAddress(&Building::_NV_serialise),
    Building_NV_serialise_hook, Building_NV_serialise_orig)

static void (*Building_NV_loadFromSerialise_orig)(Building*, GameSaveState*) = NULL;
static void Building_NV_loadFromSerialise_hook(Building* thisptr, GameSaveState* savestate)
{
    Building_NV_loadFromSerialise_orig(thisptr, savestate);
    CallBuildingLoadFromSerialiseCallbacks(thisptr, savestate);
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_NV_loadFromSerialise,
    "Building::_NV_loadFromSerialise",
    KenshiLib::GetRealAddress(&Building::_NV_loadFromSerialise),
    Building_NV_loadFromSerialise_hook, Building_NV_loadFromSerialise_orig)

// Platoon
static void (*Platoon_NV_loadFromSerialise_orig)(Platoon*, GameSaveState*) = NULL;
static void Platoon_NV_loadFromSerialise_hook(Platoon* thisptr, GameSaveState* state)
{
    Platoon_NV_loadFromSerialise_orig(thisptr, state);
    CallPlatoonLoadFromSerialiseCallbacks(thisptr, state);
}
DEFINE_HOOK_INSTALLER(InstallHook_Platoon_NV_loadFromSerialise,
    "Platoon::_NV_loadFromSerialise",
    KenshiLib::GetRealAddress(&Platoon::_NV_loadFromSerialise),
    Platoon_NV_loadFromSerialise_hook, Platoon_NV_loadFromSerialise_orig)

// Town
static void (*Town_NV_loadFromSerialise_orig)(Town*, GameSaveState*) = NULL;
static void Town_NV_loadFromSerialise_hook(Town* thisptr, GameSaveState* state)
{
    Town_NV_loadFromSerialise_orig(thisptr, state);
    CallTownLoadFromSerialiseCallbacks(thisptr, state);
}
DEFINE_HOOK_INSTALLER(InstallHook_Town_NV_loadFromSerialise,
    "Town::_NV_loadFromSerialise",
    KenshiLib::GetRealAddress(&Town::_NV_loadFromSerialise),
    Town_NV_loadFromSerialise_hook, Town_NV_loadFromSerialise_orig)

// Building buyMeCallback
static void (*Building_NV_buyMeCallback_orig)(Building*, int) = NULL;
static void Building_NV_buyMeCallback_hook(Building* thisptr, int result)
{
    Building_NV_buyMeCallback_orig(thisptr, result);
    CallBuildingBuyMeCallbackCallbacks(thisptr, result);
}
DEFINE_HOOK_INSTALLER(InstallHook_Building_NV_buyMeCallback,
    "Building::_NV_buyMeCallback",
    KenshiLib::GetRealAddress(&Building::_NV_buyMeCallback),
    Building_NV_buyMeCallback_hook, Building_NV_buyMeCallback_orig)

// DataPanelLine_Button pressCallback
static void (*DataPanelLine_Button_pressCallback_orig)(DataPanelLine_Button*, MyGUI::Widget*) = NULL;
static void DataPanelLine_Button_pressCallback_hook(DataPanelLine_Button* thisptr, MyGUI::Widget* sender)
{
    DataPanelLine_Button_pressCallback_orig(thisptr, sender);
    CallDataPanelLineButtonPressCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Button_pressCallback,
    "DataPanelLine_Button::pressCallback",
    KenshiLib::GetRealAddress(&DataPanelLine_Button::pressCallback),
    DataPanelLine_Button_pressCallback_hook, DataPanelLine_Button_pressCallback_orig)

// InventoryGUI fencingConfirmationCallback
static void (*InventoryGUI_fencingConfirmationCallback_orig)(InventoryGUI*, int) = NULL;
static void InventoryGUI_fencingConfirmationCallback_hook(InventoryGUI* thisptr, int b)
{
    InventoryGUI_fencingConfirmationCallback_orig(thisptr, b);
    CallInventoryGUIFencingConfirmationCallbacks(thisptr, b);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_fencingConfirmationCallback,
    "InventoryGUI::fencingConfirmationCallback",
    KenshiLib::GetRealAddress(&InventoryGUI::fencingConfirmationCallback),
    InventoryGUI_fencingConfirmationCallback_hook, InventoryGUI_fencingConfirmationCallback_orig)

// OrdersPanel callbacks
static void (*OrdersPanel_blockmodeButton_orig)(OrdersPanel*, MyGUI::Widget*) = NULL;
static void OrdersPanel_blockmodeButton_hook(OrdersPanel* thisptr, MyGUI::Widget* sender)
{
    OrdersPanel_blockmodeButton_orig(thisptr, sender);
    CallOrdersPanelBlockModeButtonCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_blockmodeButton,
    "OrdersPanel::blockmodeButton",
    KenshiLib::GetRealAddress(&OrdersPanel::blockmodeButton),
    OrdersPanel_blockmodeButton_hook, OrdersPanel_blockmodeButton_orig)

static void (*OrdersPanel_holdButtonCallback_orig)(OrdersPanel*, MyGUI::Widget*) = NULL;
static void OrdersPanel_holdButtonCallback_hook(OrdersPanel* thisptr, MyGUI::Widget* sender)
{
    OrdersPanel_holdButtonCallback_orig(thisptr, sender);
    CallOrdersPanelHoldButtonCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_holdButtonCallback,
    "OrdersPanel::holdButtonCallback",
    KenshiLib::GetRealAddress(&OrdersPanel::holdButtonCallback),
    OrdersPanel_holdButtonCallback_hook, OrdersPanel_holdButtonCallback_orig)

static void (*OrdersPanel_passiveButtonCallback_orig)(OrdersPanel*, MyGUI::Widget*) = NULL;
static void OrdersPanel_passiveButtonCallback_hook(OrdersPanel* thisptr, MyGUI::Widget* sender)
{
    OrdersPanel_passiveButtonCallback_orig(thisptr, sender);
    CallOrdersPanelPassiveButtonCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_passiveButtonCallback,
    "OrdersPanel::passiveButtonCallback",
    KenshiLib::GetRealAddress(&OrdersPanel::passiveButtonCallback),
    OrdersPanel_passiveButtonCallback_hook, OrdersPanel_passiveButtonCallback_orig)

static void (*OrdersPanel_chaseButtonCallback_orig)(OrdersPanel*, MyGUI::Widget*) = NULL;
static void OrdersPanel_chaseButtonCallback_hook(OrdersPanel* thisptr, MyGUI::Widget* sender)
{
    OrdersPanel_chaseButtonCallback_orig(thisptr, sender);
    CallOrdersPanelChaseButtonCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_chaseButtonCallback,
    "OrdersPanel::chaseButtonCallback",
    KenshiLib::GetRealAddress(&OrdersPanel::chaseButtonCallback),
    OrdersPanel_chaseButtonCallback_hook, OrdersPanel_chaseButtonCallback_orig)

static void (*OrdersPanel_tauntButtonCallback_orig)(OrdersPanel*, MyGUI::Widget*) = NULL;
static void OrdersPanel_tauntButtonCallback_hook(OrdersPanel* thisptr, MyGUI::Widget* sender)
{
    OrdersPanel_tauntButtonCallback_orig(thisptr, sender);
    CallOrdersPanelTauntButtonCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_tauntButtonCallback,
    "OrdersPanel::tauntButtonCallback",
    KenshiLib::GetRealAddress(&OrdersPanel::tauntButtonCallback),
    OrdersPanel_tauntButtonCallback_hook, OrdersPanel_tauntButtonCallback_orig)

static void (*OrdersPanel_medicButton_orig)(OrdersPanel*, MyGUI::Widget*) = NULL;
static void OrdersPanel_medicButton_hook(OrdersPanel* thisptr, MyGUI::Widget* sender)
{
    OrdersPanel_medicButton_orig(thisptr, sender);
    CallOrdersPanelMedicButtonCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_medicButton,
    "OrdersPanel::medicButton",
    KenshiLib::GetRealAddress(&OrdersPanel::medicButton),
    OrdersPanel_medicButton_hook, OrdersPanel_medicButton_orig)

static void (*OrdersPanel_liftButton_orig)(OrdersPanel*, MyGUI::Widget*) = NULL;
static void OrdersPanel_liftButton_hook(OrdersPanel* thisptr, MyGUI::Widget* sender)
{
    OrdersPanel_liftButton_orig(thisptr, sender);
    CallOrdersPanelLiftButtonCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_liftButton,
    "OrdersPanel::liftButton",
    KenshiLib::GetRealAddress(&OrdersPanel::liftButton),
    OrdersPanel_liftButton_hook, OrdersPanel_liftButton_orig)

static void (*OrdersPanel_prospectingButton_orig)(OrdersPanel*, MyGUI::Widget*) = NULL;
static void OrdersPanel_prospectingButton_hook(OrdersPanel* thisptr, MyGUI::Widget* sender)
{
    OrdersPanel_prospectingButton_orig(thisptr, sender);
    CallOrdersPanelProspectingButtonCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_prospectingButton,
    "OrdersPanel::prospectingButton",
    KenshiLib::GetRealAddress(&OrdersPanel::prospectingButton),
    OrdersPanel_prospectingButton_hook, OrdersPanel_prospectingButton_orig)

// Inventory section and item callbacks
static void (*Inventory_NV_sectionAddItemCallback_orig)(Inventory*, Item*) = NULL;
static void Inventory_NV_sectionAddItemCallback_hook(Inventory* thisptr, Item* item)
{
    Inventory_NV_sectionAddItemCallback_orig(thisptr, item);
    CallInventorySectionAddItemCallbacks(thisptr, item);
}
DEFINE_HOOK_INSTALLER(InstallHook_Inventory_NV_sectionAddItemCallback,
    "Inventory::_NV__sectionAddItemCallback",
    KenshiLib::GetRealAddress(&Inventory::_NV__sectionAddItemCallback),
    Inventory_NV_sectionAddItemCallback_hook, Inventory_NV_sectionAddItemCallback_orig)

static void (*Inventory_NV_sectionRemoveItemCallback_orig)(Inventory*, Item*) = NULL;
static void Inventory_NV_sectionRemoveItemCallback_hook(Inventory* thisptr, Item* item)
{
    Inventory_NV_sectionRemoveItemCallback_orig(thisptr, item);
    CallInventorySectionRemoveItemCallbacks(thisptr, item);
}
DEFINE_HOOK_INSTALLER(InstallHook_Inventory_NV_sectionRemoveItemCallback,
    "Inventory::_NV__sectionRemoveItemCallback",
    KenshiLib::GetRealAddress(&Inventory::_NV__sectionRemoveItemCallback),
    Inventory_NV_sectionRemoveItemCallback_hook, Inventory_NV_sectionRemoveItemCallback_orig)

static void (*Inventory_NV_sectionUpdateItemCallback_orig)(Inventory*, Item*, int) = NULL;
static void Inventory_NV_sectionUpdateItemCallback_hook(Inventory* thisptr, Item* item, int prevQuantity)
{
    Inventory_NV_sectionUpdateItemCallback_orig(thisptr, item, prevQuantity);
    CallInventorySectionUpdateItemCallbacks(thisptr, item, prevQuantity);
}
DEFINE_HOOK_INSTALLER(InstallHook_Inventory_NV_sectionUpdateItemCallback,
    "Inventory::_NV__sectionUpdateItemCallback",
    KenshiLib::GetRealAddress(&Inventory::_NV__sectionUpdateItemCallback),
    Inventory_NV_sectionUpdateItemCallback_hook, Inventory_NV_sectionUpdateItemCallback_orig)

static void (*Inventory_NV_dropItem_orig)(Inventory*, Item*) = NULL;
static void Inventory_NV_dropItem_hook(Inventory* thisptr, Item* item)
{
    Inventory_NV_dropItem_orig(thisptr, item);
    CallInventoryDropItemCallbacks(thisptr, item);
}
DEFINE_HOOK_INSTALLER(InstallHook_Inventory_NV_dropItem,
    "Inventory::_NV_dropItem",
    KenshiLib::GetRealAddress(&Inventory::_NV_dropItem),
    Inventory_NV_dropItem_hook, Inventory_NV_dropItem_orig)







// ---------------------------------------------------------------------------
// Hook registry
// ---------------------------------------------------------------------------

namespace KenshiLua
{
    struct EventHookRegistryEntry
    {
        const char* eventName;
        bool (*install)();
    };

    static const EventHookRegistryEntry g_eventHookRegistry[] = {
        // InputHandler.h
        { "onKeyDown",                                      InstallHook_InputHandler_KeyDown },

        // GameWorld.h          
        { "onCharsUpdate",                                  InstallHook_GameWorld_CharsUpdate },

        // Character.h          
        { "onCharacterSay",                                 InstallHook_Character_Say },
        { "onCharacterSelect",                              InstallHook_Character_Select },
        { "onCharacterUnselect",                            InstallHook_Character_Unselect },
        { "onCharacterDeath",                               InstallHook_Character_DeclareDead },
        { "onCharacterPickupObject",                        InstallHook_Character_PickupObject },
        { "onCharacterGetPickedUp",                         InstallHook_Character_GetPickedUp },
        { "onCharacterTakeMoney",                           InstallHook_Character_TakeMoney },
        { "onCharacterEat",                                 InstallHook_Character_EatItem },
        { "onCharacterHitByMelee",                          InstallHook_Character_HitByMeleeAttack },
        { "onCharacterGettingEaten",                        InstallHook_Character_GettingEaten },
        { "onCharacterStandingOrderChanged",                InstallHook_Character_SetStandingOrder },
        { "onCharacterFactionChanged",                      InstallHook_Character_SetFaction },
        { "onCharacterEquip",                               InstallHook_Character_EquipItem },
        { "onCharacterUnequip",                             InstallHook_Character_UnequipItem },
        { "onPlayerStealCheck",                             InstallHook_Character_ImStealingDoYouNotice },
        { "onSmugglingTradeCheck",                          InstallHook_Character_SmugglingTradeCheck },
        { "onCharacterInit",                                InstallHook_Character_NV_init },
        { "onCharacterLootCheck",                           InstallHook_Character_isItOkForMeToLoot },
        { "onGetFencingChance",                             InstallHook_Character_getFencingSuccessChance },
        { "onSlaveOwnerChanged",                            InstallHook_Character_changeSlaveOwner },
        { "onChainedModeChanged",                           InstallHook_Character_setChainedMode },
        { "onCharacterIndoorsChanged",                      InstallHook_Character_NV_notifyIndoors },
        { "onCharacterAddGoal",                             InstallHook_Character_addGoal },
        { "onCharacterAddJob",                              InstallHook_Character_addJob },
        { "onCharacterAddOrder",                            InstallHook_Character_addOrder },
        { "onCharacterRemoveJob",                           InstallHook_Character_removeJob },
        { "onCharacterSerialise",                           InstallHook_Character_NV_serialise },
        { "onCharacterLoadFromSerialise",                   InstallHook_Character_NV_loadFromSerialise },
        { "onCharacterLoadFromSerialisePostCreationStage",  InstallHook_Character_NV_loadFromSerialisePostCreationStage },

        // CharStats.h
        { "setHoldLocation",                                InstallHook_CharStats_SetHoldLocation },
        { "clearHoldLocation",                              InstallHook_CharStats_ClearHoldLocation },
        { "chooseAttack",                                   InstallHook_CharStats_ChooseAttack },
        { "xpRunning",                                      InstallHook_CharStats_XpRunning },
        { "xpFirstAid",                                     InstallHook_CharStats_XpFirstAid },
        { "xpStealth",                                      InstallHook_CharStats_XpStealth },
        { "xpToughness_GetUpEvent",                         InstallHook_CharStats_XpToughness_GetUpEvent },
        { "xpToughness_RagdollEvent",                       InstallHook_CharStats_XpToughness_RagdollEvent },
        { "xpToughness_PunchSomething",                     InstallHook_CharStats_XpToughness_PunchSomething },
        { "xpEngineering",                                  InstallHook_CharStats_XpEngineering },
        { "xpLockpicking",                                  InstallHook_CharStats_XpLockpicking },
        { "onGetStat",                                      InstallHook_CharStats_getStat },
        { "onCharStatsXpStatEvent",                         InstallHook_CharStats_xpStat_eventBased },
        { "onCharStatsXpDodgeEvent",                        InstallHook_CharStats_xpDodgeEvent },

        // PlayerInterface.h            
        { "onPlayerRecruit",                                InstallHook_PlayerInterface_Recruit },
        { "onPlayerSelectObject",                           InstallHook_PlayerInterface_SelectObject },
        { "onPlayerOrderGiven",                             InstallHook_PlayerInterface_NewPlayerTaskSelectedCharacters },
        { "onPlayerActivateCharacterEditMode",              InstallHook_PlayerInterface_activateCharacterEditMode },
        { "onPlayerCreateSquad",                            InstallHook_PlayerInterface_createSquad },
        { "onPlayerAddJobSelectedCharacters",               InstallHook_PlayerInterface_addJobSelectedCharacters },
        { "onPlayerAddOrderSelectedCharacters",             InstallHook_PlayerInterface_addOrderSelectedCharacters },
        { "onFactionEncountered",                           InstallHook_PlayerInterface_encounterFaction },
        { "onPlayerSerialise",                              InstallHook_PlayerInterface_serialise },
        { "onPlayerLoadFromSerialise",                      InstallHook_PlayerInterface_loadFromSerialise },

        // Platoon.h            
        { "onPlatoonMemberAdded",                           InstallHook_ActivePlatoon_AddActiveObject },
        { "onPlatoonMemberRemoved",                         InstallHook_ActivePlatoon_RemoveObject },
        { "onPlatoonTaskComplete",                          InstallHook_Platoon_TaskIsComplete },
        { "onPlatoonIBuyStolenGoods",                       InstallHook_Platoon_iBuyStolenGoods },
        { "onPlatoonIBuyIllegalGoods",                      InstallHook_Platoon_iBuyIllegalGoods },
        { "onPlatoonLoadFromSerialise",                     InstallHook_Platoon_NV_loadFromSerialise },
        { "onBuildingUseCheck",                             InstallHook_Ownerships_canIUseThisBuilding },

        // Item.h           
        { "onItemStolen",                                   InstallHook_Item_NotifyTheftFrom },

        // Inventory.h / InventoryItemBase.h            
        { "onInventoryGetSectionOfType",                    InstallHook_Inventory_getSectionOfType },
        { "onInventoryGetBestFoodItem",                     InstallHook_Inventory_getBestFoodItem },
        { "onItemGetValueSingle",                           InstallHook_InventoryItemBase_getValueSingle },
        { "onInventoryAddItem",                             InstallHook_Inventory_NV_addItem },
        { "onInventoryRemoveItem",                          InstallHook_Inventory_NV_removeItemDontDestroy_returnsItem },
        { "onItemBought",                                   InstallHook_Inventory_buyItem },
        { "onInventorySectionAddItem",                      InstallHook_Inventory_NV_sectionAddItemCallback },
        { "onInventorySectionRemoveItem",                   InstallHook_Inventory_NV_sectionRemoveItemCallback },
        { "onInventorySectionUpdateItem",                   InstallHook_Inventory_NV_sectionUpdateItemCallback },
        { "onInventoryDropItem",                            InstallHook_Inventory_NV_dropItem },

        // BountyManager.h          
        { "onCrimeWitnessed",                               InstallHook_BountyManager_NotifyCrimeWitnessed },

        // FactionRelations.h           
        { "onFactionRelationsAffected",                     InstallHook_FactionRelations_AffectRelations },

        // Faction.h            
        { "onFactionChooseRace",                            InstallHook_Faction_chooseARace },
        { "onFactionGetBuildingReplacement",                InstallHook_Faction_getBuildingReplacement },
        { "onActivePlatoonCreated",                         InstallHook_Faction_createNewEmptyActivePlatoon },
        { "onPlatoonDestroyed",                             InstallHook_Faction_destroyPlatoon },

        // MedicalSystem.h          
        { "onLimbAmputated",                                InstallHook_MedicalSystem_Amputate },
        { "onCharacterKnockedOut",                          InstallHook_MedicalSystem_knockout },
        { "onCharacterWakeUp",                              InstallHook_MedicalSystem_canGetUpWakeUp },

        // gui/DialogueWindow.h         
        { "onDialogueWindowShow",                           InstallHook_DialogueWindow_Show },

        // Dialogue.h           
        { "onDialogueDoActions",                            InstallHook_Dialogue_DoActions },
        { "onDialogueSay",                                  InstallHook_Dialogue_Say },
        { "onDialogueEndDialogue",                          InstallHook_Dialogue_endDialogue },
        { "onDialogueCheckCondition",                       InstallHook_Dialogue__checkCondition },
        { "onDialogueStartConversation",                    InstallHook_Dialogue_startConversation },
        { "onDialogueEndPlayerConversation",                InstallHook_Dialogue__endPlayerConversation },
        { "onDialogueStartPlayerConversation",              InstallHook_Dialogue_startPlayerConversation },
        { "onDialogueSendEvent",                            InstallHook_Dialogue_sendEvent },
        { "onDialogueStopEvent",                            InstallHook_Dialogue_stopEvent },

        // RootObjectFactory.h          
        { "onChooseMyClothing",                             InstallHook_RootObjectFactory_chooseMyClothing },

        // mygui/common/baselayout/BaseLayout.h         
        { "onBaseLayoutInitialise",                         InstallHook_BaseLayout_initialise },

        // Building/Building.h          
        { "onBuildingIsPublic",                             InstallHook_Building_isPublic },
        { "onBuildingIsForSale",                            InstallHook_Building_isForSale },
        { "onBuildingCalculateSaleValue",                   InstallHook_Building_calculateSaleValue },
        { "onBuildingLoaded",                               InstallHook_Building_NV_onBuildingLoaded },
        { "onBuildingBrokenChanged",                        InstallHook_Building_NV_setBroken },
        { "onBuildingSetResidentSquad",                     InstallHook_Building_setResidentSquad },
        { "onBuildingAddInternalBuilding",                  InstallHook_Building_addAnInternalBuilding },
        { "onBuildingSerialise",                            InstallHook_Building_NV_serialise },
        { "onBuildingLoadFromSerialise",                    InstallHook_Building_NV_loadFromSerialise },
        { "onBuildingBuyMeCallback",                        InstallHook_Building_NV_buyMeCallback },



        // CharMovement.h           
        { "onCharMovementIsRunning",                        InstallHook_CharMovement_isRunning },
        { "onCharMovementIsRunningAway",                    InstallHook_CharMovement_isRunningAway },

        // InventoryGUI.h
        { "onInventoryAddTradePartner",                     InstallHook_InventoryGUI_addTradePartner },
        { "onInventoryGUIFencingConfirmation",              InstallHook_InventoryGUI_fencingConfirmationCallback },

        // OrdersPanel.h
        { "onOrdersPanelBlockModeButton",                   InstallHook_OrdersPanel_blockmodeButton },
        { "onOrdersPanelHoldButton",                        InstallHook_OrdersPanel_holdButtonCallback },
        { "onOrdersPanelPassiveButton",                     InstallHook_OrdersPanel_passiveButtonCallback },
        { "onOrdersPanelChaseButton",                       InstallHook_OrdersPanel_chaseButtonCallback },
        { "onOrdersPanelTauntButton",                       InstallHook_OrdersPanel_tauntButtonCallback },
        { "onOrdersPanelMedicButton",                       InstallHook_OrdersPanel_medicButton },
        { "onOrdersPanelLiftButton",                        InstallHook_OrdersPanel_liftButton },
        { "onOrdersPanelProspectingButton",                 InstallHook_OrdersPanel_prospectingButton },

        // Misc
        { "onBuildModeConfirm",                             InstallHook_BuildModeWindow_confirm },
        { "onSquadRemoved",                                 InstallHook_SquadManagementScreen_removeSquad },
        { "onManagementScreenMessageAdded",                 InstallHook_ManagementScreen_addMessage },
        { "onTitleScreenLoadGame",                          InstallHook_TitleScreen_loadGame },
        { "onTownLoadFromSerialise",                        InstallHook_Town_NV_loadFromSerialise },
        { "onDataPanelLineButtonPress",                     InstallHook_DataPanelLine_Button_pressCallback },

    };

    static const size_t g_eventHookRegistryCount = sizeof(g_eventHookRegistry) / sizeof(g_eventHookRegistry[0]);

    bool InstallHookForEvent(const std::string& eventName)
    {
        for (size_t i = 0; i < g_eventHookRegistryCount; ++i)
        {
            if (eventName == g_eventHookRegistry[i].eventName)
            {
                return g_eventHookRegistry[i].install();
            }
        }
        return false;
    }

} // namespace KenshiLua