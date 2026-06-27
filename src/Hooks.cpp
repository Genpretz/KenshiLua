#include "pch.h"

#include "Callbacks.h"
#include "Gui/InitializeGui.h"
#include "Hooks.h"
#include "Lua/Logger.h"

#include <kenshi/Character.h>
#include <kenshi/GameWorld.h>
#include <kenshi/CharStats.h>
#include <kenshi/Platoon.h>
#include <kenshi/Item.h>
#include <kenshi/PlayerInterface.h>
#include <kenshi/Faction.h>
#include <kenshi/Damages.h>
#include <kenshi/gui/TitleScreen.h>
#include <kenshi/InputHandler.h>
#include <kenshi/util/YesNoMaybe.h>
#include <kenshi/BountyManager.h>
#include <kenshi/FactionRelations.h>
#include <kenshi/MedicalSystem.h>
#include <kenshi/gui/DialogueWindow.h>
#include <kenshi/Dialogue.h>
#include "core/Functions.h"

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
        KenshiLua::logToFilef("Could not resolve address for %s.", name);
        return false;
    }
    
    KenshiLib::HookStatus status = KenshiLib::AddHook(addr, hookFn, origStorage);
    if (status != KenshiLib::SUCCESS)
    {
        KenshiLua::logToFilef("AddHook failed for %s (status %d).", name, (int)status);
        return false;
    }

    KenshiLua::logToFilef("Hook installed: %s", name);
    return true;
}

// Defines a small static "installer" function for one hook.
#define DEFINE_HOOK_INSTALLER(fnName, displayName, addrExpr, hookFn, origVar) \
    static bool fnName() \
    { \
        return InstallHookT(displayName, (intptr_t)(addrExpr), &hookFn, &origVar); \
    }

// ---------------------------------------------------------------------------
// Hook: Character::say
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

// ---------------------------------------------------------------------------
// Hook: Character::_NV_select
// ---------------------------------------------------------------------------

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

// ---------------------------------------------------------------------------
// Hook: Character::_NV_unselect
// ---------------------------------------------------------------------------

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

// ---------------------------------------------------------------------------
// Hook: Character::declareDead
// ---------------------------------------------------------------------------

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

// ---------------------------------------------------------------------------
// Hook: Character::pickupObject
// ---------------------------------------------------------------------------

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

// ---------------------------------------------------------------------------
// Hook: Character::getPickedUp
// ---------------------------------------------------------------------------

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

// ---------------------------------------------------------------------------
// Hook: InputHandler::keyDownEvent
// ---------------------------------------------------------------------------

static void (*InputHandler_keyDownEvent_orig)(InputHandler* thisptr, OIS::KeyCode key) = NULL;

static void InputHandler_keyDownEvent_hook(InputHandler* thisptr, OIS::KeyCode key)
{
    InputHandler_keyDownEvent_orig(thisptr, key);

    if (key == OIS::KC_L && thisptr->ctrl && thisptr->shift)
        KenshiLua::KenshiLuaGui::get().toggle();

    CallKeyDownCallbacks(static_cast<int>(key));
}

DEFINE_HOOK_INSTALLER(InstallHook_InputHandler_KeyDown,
    "InputHandler::keyDownEvent",
    KenshiLib::GetRealAddress(&InputHandler::keyDownEvent),
    InputHandler_keyDownEvent_hook, InputHandler_keyDownEvent_orig)

// ---------------------------------------------------------------------------
// Hook: GameWorld::charsUpdate
// ---------------------------------------------------------------------------

static void (*GameWorld_charsUpdate_orig)(GameWorld*) = NULL;

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
// Hook: CharStats::setHoldLocation
// ---------------------------------------------------------------------------

static void (*CharStats_setHoldLocation_orig)(CharStats*, const Ogre::Vector3&) = NULL;

static void CharStats_setHoldLocation_hook(CharStats* thisptr, const Ogre::Vector3& v)
{
    CharStats_setHoldLocation_orig(thisptr, v);
    CallCharStatsSetHoldLocationCallbacks(thisptr, v);
}

DEFINE_HOOK_INSTALLER(InstallHook_CharStats_SetHoldLocation,
    "CharStats::setHoldLocation",
    KenshiLib::GetRealAddress(&CharStats::setHoldLocation),
    CharStats_setHoldLocation_hook, CharStats_setHoldLocation_orig)

// ---------------------------------------------------------------------------
// Hook: CharStats::clearHoldLocation
// ---------------------------------------------------------------------------

static void (*CharStats_clearHoldLocation_orig)(CharStats*) = NULL;

static void CharStats_clearHoldLocation_hook(CharStats* thisptr)
{
    CharStats_clearHoldLocation_orig(thisptr);
    CallCharStatsClearHoldLocationCallbacks(thisptr);
}

DEFINE_HOOK_INSTALLER(InstallHook_CharStats_ClearHoldLocation,
    "CharStats::clearHoldLocation",
    KenshiLib::GetRealAddress(&CharStats::clearHoldLocation),
    CharStats_clearHoldLocation_hook, CharStats_clearHoldLocation_orig)

// ---------------------------------------------------------------------------
// Hook: CharStats::chooseAttack
// ---------------------------------------------------------------------------

static CombatTechniqueData* (*CharStats_chooseAttack_orig)(CharStats*, float, float, CombatTechniqueData*, bool) = NULL;

static CombatTechniqueData* CharStats_chooseAttack_hook(CharStats* thisptr, float range, float weaponReach, CombatTechniqueData* lastAttack, bool opponentIsStationary)
{
    CombatTechniqueData* res = CharStats_chooseAttack_orig(thisptr, range, weaponReach, lastAttack, opponentIsStationary);
    CallCharStatsChooseAttackCallbacks(thisptr, range, weaponReach, lastAttack, opponentIsStationary, res);
    return res;
}

DEFINE_HOOK_INSTALLER(InstallHook_CharStats_ChooseAttack,
    "CharStats::chooseAttack",
    KenshiLib::GetRealAddress(&CharStats::chooseAttack),
    CharStats_chooseAttack_hook, CharStats_chooseAttack_orig)

// ---------------------------------------------------------------------------
// Hook: CharStats::xpRunning
// ---------------------------------------------------------------------------

static void (*CharStats_xpRunning_orig)(CharStats*, float, float) = NULL;

static void CharStats_xpRunning_hook(CharStats* thisptr, float time, float speed)
{
    CharStats_xpRunning_orig(thisptr, time, speed);
    CallCharStatsXpRunningCallbacks(thisptr, time, speed);
}

DEFINE_HOOK_INSTALLER(InstallHook_CharStats_XpRunning,
    "CharStats::xpRunning",
    KenshiLib::GetRealAddress(&CharStats::xpRunning),
    CharStats_xpRunning_hook, CharStats_xpRunning_orig)

// ---------------------------------------------------------------------------
// Hook: CharStats::xpFirstAid
// ---------------------------------------------------------------------------

static void (*CharStats_xpFirstAid_orig)(CharStats*, Character*, float, StatsEnumerated) = NULL;

static void CharStats_xpFirstAid_hook(CharStats* thisptr, Character* patient, float time, StatsEnumerated medicStat)
{
    CharStats_xpFirstAid_orig(thisptr, patient, time, medicStat);
    CallCharStatsXpFirstAidCallbacks(thisptr, patient, time, static_cast<int>(medicStat));
}

DEFINE_HOOK_INSTALLER(InstallHook_CharStats_XpFirstAid,
    "CharStats::xpFirstAid",
    KenshiLib::GetRealAddress(&CharStats::xpFirstAid),
    CharStats_xpFirstAid_hook, CharStats_xpFirstAid_orig)

// ---------------------------------------------------------------------------
// Hook: CharStats::xpStealth
// ---------------------------------------------------------------------------

static void (*CharStats_xpStealth_orig)(CharStats*, float time, bool enemiesAbout, YesNoMaybe seen, bool) = NULL;

static void CharStats_xpStealth_hook(CharStats* thisptr, float time, bool enemiesAbout, YesNoMaybe seen, bool isMoving)
{
    CharStats_xpStealth_orig(thisptr, time, enemiesAbout, seen, isMoving);
    CallCharStatsXpStealthCallbacks(thisptr, time, enemiesAbout, seen, isMoving);
}

DEFINE_HOOK_INSTALLER(InstallHook_CharStats_XpStealth,
    "CharStats::xpStealth",
    KenshiLib::GetRealAddress(&CharStats::xpStealth),
    CharStats_xpStealth_hook, CharStats_xpStealth_orig)

// ---------------------------------------------------------------------------
// Hook: CharStats::xpToughness_GetUpEvent
// ---------------------------------------------------------------------------

static void (*CharStats_xpToughness_GetUpEvent_orig)(CharStats*) = NULL;

static void CharStats_xpToughness_GetUpEvent_hook(CharStats* thisptr)
{
    CharStats_xpToughness_GetUpEvent_orig(thisptr);
    CallCharStatsXpToughness_GetUpEventCallbacks(thisptr);
}

DEFINE_HOOK_INSTALLER(InstallHook_CharStats_XpToughness_GetUpEvent,
    "CharStats::xpToughness_GetUpEvent",
    KenshiLib::GetRealAddress(&CharStats::xpToughness_GetUpEvent),
    CharStats_xpToughness_GetUpEvent_hook, CharStats_xpToughness_GetUpEvent_orig)

// ---------------------------------------------------------------------------
// Hook: CharStats::xpToughness_RagdollEvent
// ---------------------------------------------------------------------------

static void (*CharStats_xpToughness_RagdollEvent_orig)(CharStats*) = NULL;

static void CharStats_xpToughness_RagdollEvent_hook(CharStats* thisptr)
{
    CharStats_xpToughness_RagdollEvent_orig(thisptr);
    CallCharStatsXpToughness_RagdollEventCallbacks(thisptr);
}

DEFINE_HOOK_INSTALLER(InstallHook_CharStats_XpToughness_RagdollEvent,
    "CharStats::xpToughness_RagdollEvent",
    KenshiLib::GetRealAddress(&CharStats::xpToughness_RagdollEvent),
    CharStats_xpToughness_RagdollEvent_hook, CharStats_xpToughness_RagdollEvent_orig)

// ---------------------------------------------------------------------------
// Hook: CharStats::xpToughness_PunchSomething
// ---------------------------------------------------------------------------

static void (*CharStats_xpToughness_PunchSomething_orig)(CharStats*, HitMaterialType) = NULL;

static void CharStats_xpToughness_PunchSomething_hook(CharStats* thisptr, HitMaterialType mat)
{
    CharStats_xpToughness_PunchSomething_orig(thisptr, mat);
    CallCharStatsXpToughness_PunchSomethingCallbacks(thisptr, static_cast<int>(mat));
}

DEFINE_HOOK_INSTALLER(InstallHook_CharStats_XpToughness_PunchSomething,
    "CharStats::xpToughness_PunchSomething",
    KenshiLib::GetRealAddress(&CharStats::xpToughness_PunchSomething),
    CharStats_xpToughness_PunchSomething_hook, CharStats_xpToughness_PunchSomething_orig)

// ---------------------------------------------------------------------------
// Hook: CharStats::xpEngineering
// ---------------------------------------------------------------------------

static void (*CharStats_xpEngineering_orig)(CharStats*, float) = NULL;

static void CharStats_xpEngineering_hook(CharStats* thisptr, float time)
{
    CharStats_xpEngineering_orig(thisptr, time);
    CallCharStatsXpEngineeringCallbacks(thisptr, time);
}

DEFINE_HOOK_INSTALLER(InstallHook_CharStats_XpEngineering,
    "CharStats::xpEngineering",
    KenshiLib::GetRealAddress(&CharStats::xpEngineering),
    CharStats_xpEngineering_hook, CharStats_xpEngineering_orig)

// ---------------------------------------------------------------------------
// Hook: CharStats::xpLockpicking
// ---------------------------------------------------------------------------

static void (*CharStats_xpLockpicking_orig)(CharStats*, int, bool) = NULL;

static void CharStats_xpLockpicking_hook(CharStats* thisptr, int lockLevel, bool success)
{
    CharStats_xpLockpicking_orig(thisptr, lockLevel, success);
    CallCharStatsXpLockpickingCallbacks(thisptr, lockLevel, success);
}

DEFINE_HOOK_INSTALLER(InstallHook_CharStats_XpLockpicking,
    "CharStats::xpLockpicking",
    KenshiLib::GetRealAddress(&CharStats::xpLockpicking),
    CharStats_xpLockpicking_hook, CharStats_xpLockpicking_orig)

// ---------------------------------------------------------------------------
// Hook: Character::_NV_takeMoney
// ---------------------------------------------------------------------------

static bool (*Character_takeMoney_orig)(Character*, int) = NULL;

static bool Character_takeMoney_hook(Character* thisptr, int n)
{
    bool res = Character_takeMoney_orig(thisptr, n);
    CallCharacterTakeMoneyCallbacks(thisptr, n);
    return res;
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_TakeMoney,
    "Character::_NV_takeMoney",
    KenshiLib::GetRealAddress(&Character::_NV_takeMoney),
    Character_takeMoney_hook, Character_takeMoney_orig)

// ---------------------------------------------------------------------------
// Hook: Character::eatItem
// ---------------------------------------------------------------------------

static bool (*Character_eatItem_orig)(Character*, Item*, Inventory*) = NULL;

static bool Character_eatItem_hook(Character* thisptr, Item* food, Inventory* from)
{
    bool res = Character_eatItem_orig(thisptr, food, from);
    CallCharacterEatCallbacks(thisptr, food, from);
    return res;
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_EatItem,
    "Character::eatItem",
    KenshiLib::GetRealAddress(&Character::eatItem),
    Character_eatItem_hook, Character_eatItem_orig)

// ---------------------------------------------------------------------------
// Hook: Character::_NV_hitByMeleeAttack
// ---------------------------------------------------------------------------

static HitMaterialType (*Character_hitByMeleeAttack_orig)(Character*, CutDirection, Damages&, Character*, CombatTechniqueData*, int) = NULL;

static HitMaterialType Character_hitByMeleeAttack_hook(Character* thisptr, CutDirection dir, Damages& damage, Character* who, CombatTechniqueData* attack, int comboID)
{
    HitMaterialType res = Character_hitByMeleeAttack_orig(thisptr, dir, damage, who, attack, comboID);
    CallCharacterHitByMeleeCallbacks(thisptr, who, &damage, static_cast<int>(dir), attack, comboID);
    return res;
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_HitByMeleeAttack,
    "Character::_NV_hitByMeleeAttack",
    KenshiLib::GetRealAddress(&Character::_NV_hitByMeleeAttack),
    Character_hitByMeleeAttack_hook, Character_hitByMeleeAttack_orig)

// ---------------------------------------------------------------------------
// Hook: Character::_NV_gettingEaten
// ---------------------------------------------------------------------------

static bool (*Character_gettingEaten_orig)(Character*, float, Character*) = NULL;

static bool Character_gettingEaten_hook(Character* thisptr, float amount, Character* eater)
{
    bool res = Character_gettingEaten_orig(thisptr, amount, eater);
    CallCharacterGettingEatenCallbacks(thisptr, eater, amount);
    return res;
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_GettingEaten,
    "Character::_NV_gettingEaten",
    KenshiLib::GetRealAddress(&Character::_NV_gettingEaten),
    Character_gettingEaten_hook, Character_gettingEaten_orig)

// ---------------------------------------------------------------------------
// Hook: Character::_NV_setStandingOrder
// ---------------------------------------------------------------------------

static void (*Character_setStandingOrder_orig)(Character*, MessageForB::StandingOrder, bool) = NULL;

static void Character_setStandingOrder_hook(Character* thisptr, MessageForB::StandingOrder orderID, bool on)
{
    Character_setStandingOrder_orig(thisptr, orderID, on);
    CallCharacterStandingOrderChangedCallbacks(thisptr, static_cast<int>(orderID), on);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_SetStandingOrder,
    "Character::_NV_setStandingOrder",
    KenshiLib::GetRealAddress(&Character::_NV_setStandingOrder),
    Character_setStandingOrder_hook, Character_setStandingOrder_orig)

// ---------------------------------------------------------------------------
// Hook: Character::_NV_setFaction
// ---------------------------------------------------------------------------

static void (*Character_setFaction_orig)(Character*, Faction*, ActivePlatoon*) = NULL;

static void Character_setFaction_hook(Character* thisptr, Faction* p, ActivePlatoon* a)
{
    Character_setFaction_orig(thisptr, p, a);
    CallCharacterFactionChangedCallbacks(thisptr, p, a);
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_SetFaction,
    "Character::_NV_setFaction",
    KenshiLib::GetRealAddress(&Character::_NV_setFaction),
    Character_setFaction_hook, Character_setFaction_orig)

// ---------------------------------------------------------------------------
// Hook: Character::_NV_equipItem
// ---------------------------------------------------------------------------

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

// ---------------------------------------------------------------------------
// Hook: Character::_NV_unequipItem
// ---------------------------------------------------------------------------

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

// ---------------------------------------------------------------------------
// Hook: Character::_NV_ImStealingDoYouNotice
// ---------------------------------------------------------------------------

static bool (*Character_ImStealingDoYouNotice_orig)(Character*, RootObject*, Item*) = NULL;

static bool Character_ImStealingDoYouNotice_hook(Character* thisptr, RootObject* stealFrom, Item* item)
{
    bool res = Character_ImStealingDoYouNotice_orig(thisptr, stealFrom, item);
    CallCharacterStealNoticeCallbacks(thisptr, stealFrom, item, res);
    return res;
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_ImStealingDoYouNotice,
    "Character::_NV_ImStealingDoYouNotice",
    KenshiLib::GetRealAddress(&Character::_NV_ImStealingDoYouNotice),
    Character_ImStealingDoYouNotice_hook, Character_ImStealingDoYouNotice_orig)

// ---------------------------------------------------------------------------
// Hook: Character::_NV_smugglingTradeCheck
// ---------------------------------------------------------------------------

static YesNoMaybe (*Character_smugglingTradeCheck_orig)(Character*, Item*, Character*) = NULL;

static YesNoMaybe Character_smugglingTradeCheck_hook(Character* thisptr, Item* item, Character* who)
{
    YesNoMaybe res = Character_smugglingTradeCheck_orig(thisptr, item, who);
    CallCharacterSmugglingCheckCallbacks(thisptr, item, who, static_cast<int>(res.key));
    return res;
}

DEFINE_HOOK_INSTALLER(InstallHook_Character_SmugglingTradeCheck,
    "Character::_NV_smugglingTradeCheck",
    KenshiLib::GetRealAddress(&Character::_NV_smugglingTradeCheck),
    Character_smugglingTradeCheck_hook, Character_smugglingTradeCheck_orig)

// ---------------------------------------------------------------------------
// Hook: PlayerInterface::recruit
// ---------------------------------------------------------------------------

static bool (*PlayerInterface_recruit_orig)(PlayerInterface*, Character*, bool) = NULL;

static bool PlayerInterface_recruit_hook(PlayerInterface* thisptr, Character* character, bool editor)
{
    bool res = PlayerInterface_recruit_orig(thisptr, character, editor);
    CallPlayerRecruitCallbacks(thisptr, character, editor);
    return res;
}

DEFINE_HOOK_INSTALLER(InstallHook_PlayerInterface_Recruit,
    "PlayerInterface::recruit",
    KenshiLib::GetRealAddress(static_cast<bool (PlayerInterface::*)(Character*, bool)>(&PlayerInterface::recruit)),
    PlayerInterface_recruit_hook, PlayerInterface_recruit_orig)

// ---------------------------------------------------------------------------
// Hook: PlayerInterface::selectObject
// ---------------------------------------------------------------------------

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

// ---------------------------------------------------------------------------
// Hook: PlayerInterface::newPlayerTaskSelectedCharacters
// ---------------------------------------------------------------------------

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

// ---------------------------------------------------------------------------
// Hook: ActivePlatoon::_NV_addActiveObject
// ---------------------------------------------------------------------------

static bool (*ActivePlatoon_addActiveObject_orig)(ActivePlatoon*, RootObject*) = NULL;

static bool ActivePlatoon_addActiveObject_hook(ActivePlatoon* thisptr, RootObject* c)
{
    bool res = ActivePlatoon_addActiveObject_orig(thisptr, c);
    CallPlatoonMemberAddedCallbacks(thisptr, c);
    return res;
}

DEFINE_HOOK_INSTALLER(InstallHook_ActivePlatoon_AddActiveObject,
    "ActivePlatoon::_NV_addActiveObject",
    KenshiLib::GetRealAddress(&ActivePlatoon::_NV_addActiveObject),
    ActivePlatoon_addActiveObject_hook, ActivePlatoon_addActiveObject_orig)

// ---------------------------------------------------------------------------
// Hook: ActivePlatoon::_NV_removeObject
// ---------------------------------------------------------------------------

static bool (*ActivePlatoon_removeObject_orig)(ActivePlatoon*, RootObject*) = NULL;

static bool ActivePlatoon_removeObject_hook(ActivePlatoon* thisptr, RootObject* c)
{
    bool res = ActivePlatoon_removeObject_orig(thisptr, c);
    CallPlatoonMemberRemovedCallbacks(thisptr, c);
    return res;
}

DEFINE_HOOK_INSTALLER(InstallHook_ActivePlatoon_RemoveObject,
    "ActivePlatoon::_NV_removeObject",
    KenshiLib::GetRealAddress(&ActivePlatoon::_NV_removeObject),
    ActivePlatoon_removeObject_hook, ActivePlatoon_removeObject_orig)

// ---------------------------------------------------------------------------
// Hook: Platoon::taskIsComplete
// ---------------------------------------------------------------------------

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

// ---------------------------------------------------------------------------
// Hook: Item::_NV_notifyTheftFrom
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
// Hook: BountyManager::notifyCrimeWitnessed
// ---------------------------------------------------------------------------

static void (*BountyManager_notifyCrimeWitnessed_orig)(BountyManager*, Faction*, const hand&, int, CrimeEnum) = NULL;

static void BountyManager_notifyCrimeWitnessed_hook(BountyManager* thisptr, Faction* against, const hand& againstWho, int expirytime, CrimeEnum what)
{
    BountyManager_notifyCrimeWitnessed_orig(thisptr, against, againstWho, expirytime, what);
    CallCrimeWitnessedCallbacks(thisptr->me, against, againstWho, expirytime, static_cast<int>(what));
}

DEFINE_HOOK_INSTALLER(InstallHook_BountyManager_NotifyCrimeWitnessed,
    "BountyManager::notifyCrimeWitnessed",
    KenshiLib::GetRealAddress(&BountyManager::notifyCrimeWitnessed),
    BountyManager_notifyCrimeWitnessed_hook, BountyManager_notifyCrimeWitnessed_orig)

// ---------------------------------------------------------------------------
// Hook: FactionRelations::affectRelations
// ---------------------------------------------------------------------------

static void (*FactionRelations_affectRelations_orig)(FactionRelations*, Faction*, FactionRelations::FactionEvent, float) = NULL;

static void FactionRelations_affectRelations_hook(FactionRelations* thisptr, Faction* p, FactionRelations::FactionEvent e, float mult)
{
    FactionRelations_affectRelations_orig(thisptr, p, e, mult);
    CallFactionRelationsAffectedCallbacks(thisptr->me, p, static_cast<int>(e), mult);
}

DEFINE_HOOK_INSTALLER(InstallHook_FactionRelations_AffectRelations,
    "FactionRelations::_NV_affectRelations",
    KenshiLib::GetRealAddress(static_cast<void (FactionRelations::*)(Faction*, FactionRelations::FactionEvent, float)>(&FactionRelations::_NV_affectRelations)),
    FactionRelations_affectRelations_hook, FactionRelations_affectRelations_orig)

// ---------------------------------------------------------------------------
// Hook: MedicalSystem::amputate
// ---------------------------------------------------------------------------

static void (*MedicalSystem_amputate_orig)(MedicalSystem*, RobotLimbs::Limb, bool, const Ogre::Vector3&) = NULL;

static void MedicalSystem_amputate_hook(MedicalSystem* thisptr, RobotLimbs::Limb limb, bool createSeveredItem, const Ogre::Vector3& force)
{
    MedicalSystem_amputate_orig(thisptr, limb, createSeveredItem, force);
    CallLimbAmputatedCallbacks(thisptr->me, static_cast<int>(limb), createSeveredItem, force);
}

DEFINE_HOOK_INSTALLER(InstallHook_MedicalSystem_Amputate,
    "MedicalSystem::amputate",
    KenshiLib::GetRealAddress(&MedicalSystem::amputate),
    MedicalSystem_amputate_hook, MedicalSystem_amputate_orig)

// ---------------------------------------------------------------------------
// Hook: DialogueWindow::show
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
// Hook registry
//
// Each entry is {display name, installer function}. Adding a new hook means
// writing the _orig pointer + _hook function + DEFINE_HOOK_INSTALLER line
// above, then adding one entry here.
// ---------------------------------------------------------------------------

namespace KenshiLua
{

    struct HookRegistryEntry
    {
        const char* name;
        bool (*install)();
    };

    static const HookRegistryEntry g_hookRegistry[] = {
        { "InputHandler::keyDownEvent",                         InstallHook_InputHandler_KeyDown },
        { "GameWorld::charsUpdate",                             InstallHook_GameWorld_CharsUpdate },
        { "Character::_NV_select",                              InstallHook_Character_Select },
        { "Character::_NV_unselect",                            InstallHook_Character_Unselect },
        { "Character::declareDead",                             InstallHook_Character_DeclareDead },
        { "Character::_NV_say",                                 InstallHook_Character_Say },
        { "Character::pickupObject",                            InstallHook_Character_PickupObject },
        { "Character::getPickedUp",                             InstallHook_Character_GetPickedUp },
        { "CharStats::setHoldLocation",                         InstallHook_CharStats_SetHoldLocation },
        { "CharStats::clearHoldLocation",                       InstallHook_CharStats_ClearHoldLocation },
        { "CharStats::chooseAttack",                            InstallHook_CharStats_ChooseAttack },
        { "CharStats::xpRunning",                               InstallHook_CharStats_XpRunning },
        { "CharStats::xpFirstAid",                              InstallHook_CharStats_XpFirstAid },
        { "CharStats::xpStealth",                               InstallHook_CharStats_XpStealth },
        { "CharStats::xpToughness_GetUpEvent",                  InstallHook_CharStats_XpToughness_GetUpEvent },
        { "CharStats::xpToughness_RagdollEvent",                InstallHook_CharStats_XpToughness_RagdollEvent },
        { "CharStats::xpToughness_PunchSomething",              InstallHook_CharStats_XpToughness_PunchSomething },
        { "CharStats::xpEngineering",                           InstallHook_CharStats_XpEngineering },
        { "CharStats::xpLockpicking",                           InstallHook_CharStats_XpLockpicking },
        { "Character::_NV_takeMoney",                           InstallHook_Character_TakeMoney },
        { "Character::eatItem",                                 InstallHook_Character_EatItem },
        { "Character::_NV_hitByMeleeAttack",                    InstallHook_Character_HitByMeleeAttack },
        { "Character::_NV_gettingEaten",                        InstallHook_Character_GettingEaten },
        { "Character::_NV_setStandingOrder",                    InstallHook_Character_SetStandingOrder },
        { "Character::_NV_setFaction",                          InstallHook_Character_SetFaction },
        { "Character::_NV_equipItem",                           InstallHook_Character_EquipItem },
        { "Character::_NV_unequipItem",                         InstallHook_Character_UnequipItem },
        { "Character::_NV_ImStealingDoYouNotice",               InstallHook_Character_ImStealingDoYouNotice },
        { "Character::_NV_smugglingTradeCheck",                 InstallHook_Character_SmugglingTradeCheck },
        { "PlayerInterface::recruit",                           InstallHook_PlayerInterface_Recruit },
        { "PlayerInterface::selectObject",                      InstallHook_PlayerInterface_SelectObject },
        { "PlayerInterface::newPlayerTaskSelectedCharacters",   InstallHook_PlayerInterface_NewPlayerTaskSelectedCharacters },
        { "ActivePlatoon::_NV_addActiveObject",                 InstallHook_ActivePlatoon_AddActiveObject },
        { "ActivePlatoon::_NV_removeObject",                    InstallHook_ActivePlatoon_RemoveObject },
        { "Platoon::taskIsComplete",                            InstallHook_Platoon_TaskIsComplete },
        { "Item::_NV_notifyTheftFrom",                          InstallHook_Item_NotifyTheftFrom },
        { "BountyManager::notifyCrimeWitnessed",                InstallHook_BountyManager_NotifyCrimeWitnessed },
        { "FactionRelations::_NV_affectRelations",              InstallHook_FactionRelations_AffectRelations },
        { "MedicalSystem::amputate",                            InstallHook_MedicalSystem_Amputate },
        { "DialogueWindow::show",                               InstallHook_DialogueWindow_Show },
    };

    static const size_t g_hookRegistryCount = sizeof(g_hookRegistry) / sizeof(g_hookRegistry[0]);

    bool InstallAllHooks()
    {
        bool ok = true;
        for (size_t i = 0; i < g_hookRegistryCount; ++i)
        {
            if (!g_hookRegistry[i].install())
                ok = false;
        }

        if (ok)
            KenshiLua::logToFile("All hooks installed successfully.");
        else
            KenshiLua::logToFile("One or more hooks failed - see errors above.");

        return ok;
    }

    struct EventHookRegistryEntry
    {
        const char* eventName;
        bool (*install)();
    };

    static const EventHookRegistryEntry g_eventHookRegistry[] = {
        { "onKeyDown",                          InstallHook_InputHandler_KeyDown },
        { "onCharsUpdate",                      InstallHook_GameWorld_CharsUpdate },
        { "onCharacterSelect",                  InstallHook_Character_Select },
        { "onCharacterUnselect",                InstallHook_Character_Unselect },
        { "onCharacterDeath",                   InstallHook_Character_DeclareDead },
        { "onCharacterSay",                     InstallHook_Character_Say },
        { "onCharacterPickupObject",            InstallHook_Character_PickupObject },
        { "onCharacterGetPickedUp",             InstallHook_Character_GetPickedUp },
        { "setHoldLocation",                    InstallHook_CharStats_SetHoldLocation },
        { "clearHoldLocation",                  InstallHook_CharStats_ClearHoldLocation },
        { "chooseAttack",                       InstallHook_CharStats_ChooseAttack },
        { "xpRunning",                          InstallHook_CharStats_XpRunning },
        { "xpFirstAid",                         InstallHook_CharStats_XpFirstAid },
        { "xpStealth",                          InstallHook_CharStats_XpStealth },
        { "xpToughness_GetUpEvent",             InstallHook_CharStats_XpToughness_GetUpEvent },
        { "xpToughness_RagdollEvent",           InstallHook_CharStats_XpToughness_RagdollEvent },
        { "xpToughness_PunchSomething",         InstallHook_CharStats_XpToughness_PunchSomething },
        { "xpEngineering",                      InstallHook_CharStats_XpEngineering },
        { "xpLockpicking",                      InstallHook_CharStats_XpLockpicking },
        { "onCharacterTakeMoney",               InstallHook_Character_TakeMoney },
        { "onCharacterEat",                     InstallHook_Character_EatItem },
        { "onCharacterHitByMelee",              InstallHook_Character_HitByMeleeAttack },
        { "onCharacterGettingEaten",            InstallHook_Character_GettingEaten },
        { "onCharacterStandingOrderChanged",    InstallHook_Character_SetStandingOrder },
        { "onCharacterFactionChanged",          InstallHook_Character_SetFaction },
        { "onCharacterEquip",                   InstallHook_Character_EquipItem },
        { "onCharacterUnequip",                 InstallHook_Character_UnequipItem },
        { "onPlayerStealCheck",                 InstallHook_Character_ImStealingDoYouNotice },
        { "onSmugglingTradeCheck",              InstallHook_Character_SmugglingTradeCheck },
        { "onPlayerRecruit",                    InstallHook_PlayerInterface_Recruit },
        { "onPlayerSelectObject",               InstallHook_PlayerInterface_SelectObject },
        { "onPlayerOrderGiven",                 InstallHook_PlayerInterface_NewPlayerTaskSelectedCharacters },
        { "onPlatoonMemberAdded",               InstallHook_ActivePlatoon_AddActiveObject },
        { "onPlatoonMemberRemoved",             InstallHook_ActivePlatoon_RemoveObject },
        { "onPlatoonTaskComplete",              InstallHook_Platoon_TaskIsComplete },
        { "onItemStolen",                       InstallHook_Item_NotifyTheftFrom },
        { "onCrimeWitnessed",                   InstallHook_BountyManager_NotifyCrimeWitnessed },
        { "onFactionRelationsAffected",         InstallHook_FactionRelations_AffectRelations },
        { "onLimbAmputated",                    InstallHook_MedicalSystem_Amputate },
        { "onDialogueWindowShow",               InstallHook_DialogueWindow_Show },
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