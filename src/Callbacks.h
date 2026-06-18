#pragma once

#include <string>

// Forward declaration — avoids pulling in the full headers in every
// TU that only needs to call these dispatchers.
class Character;
class CharStats;
class CombatTechniqueData;
class YesNoMaybe;
class Item;
class Inventory;
class Faction;
class ActivePlatoon;
class RootObject;
class Damages;
class Platoon;
class Tasker;
class Building;
class PlayerInterface;
class hand;
namespace Ogre {
    class Vector3;
}

// ---------------------------------------------------------------------------
// Callback dispatchers
//
// Each function is called directly from a hook in Hooks.cpp and forwards the
// event (with typed arguments) into the KenshiLua EventSystem so that any
// registered Lua handlers are invoked.
//
// These are plain free functions (no namespace) so that Hooks.cpp can include
// this header without depending on any KenshiLua internal headers.
// ---------------------------------------------------------------------------

// -----------------------------------------------------------
// Callbacks for hooks in Character.h
// -----------------------------------------------------------

// Fired by Character::declareDead hook.
// Lua event name: "onCharacterDeath"
// Lua signature:  function(character)
void CallCharacterDeclareDeadCallbacks(Character* character);

// Fired by Character::_NV_select hook.
// Lua event name: "onCharacterSelect"
// Lua signature:  function(character)
void CallCharacterSelectCallbacks(Character* character);

// Fired by Character::_NV_unselect hook.
// Lua event name: "onCharacterUnselect"
// Lua signature:  function(character)
void CallCharacterUnselectCallbacks(Character* character);

// Fired by Character::_NV_say hook.
// Lua event name: "onCharacterSay"
// Lua signature:  function(character, message)
// Returning false from the handler suppresses remaining handlers.
void CallCharacterSayCallbacks(Character* character, const std::string& message);

// Fired by Character::pickupObject hook.
// Lua event name: "onCharacterPickupObject"
// Lua signature:  function(character)
void CallCharacterPickupObjectCallbacks(Character* character);

// Fired by Character::getPickedUp hook.
// Lua event name: "onCharacterGetPickedUp"
// Lua signature:  function(character)
void CallCharacterGetPickedUpCallbacks(Character* byWhom);

// -----------------------------------------------------------
// Callback for hook in GameWorld.h
// -----------------------------------------------------------

// Fired by GameWorld::charsUpdate hook.
// Lua event name: "onCharsUpdate"
// Lua signature:  function()
void CallCharsUpdateCallbacks();

// -----------------------------------------------------------
// Callbacks for hooks in InputHandler.h
// -----------------------------------------------------------

// Fired by InputHandler::keyDownEvent hook.
// Lua event name: "onKeyDown"
// Lua signature:  function(keyCode)
// keyCode is the raw OIS::KeyCode cast to int.
void CallKeyDownCallbacks(int keyCode);

// -----------------------------------------------------------
// Callbacks for hooks in CharStats.h
// -----------------------------------------------------------

// Fired by CharStats::setHoldLocation hook.
// Lua event name: "setHoldLocation"
// Lua signature:  function(charStats, vector3Table)
void CallCharStatsSetHoldLocationCallbacks(CharStats* stats, const Ogre::Vector3& v);

// Fired by CharStats::clearHoldLocation hook.
// Lua event name: "clearHoldLocation"
// Lua signature:  function(charStats)
void CallCharStatsClearHoldLocationCallbacks(CharStats* stats);

// Fired by CharStats::chooseAttack hook.
// Lua event name: "chooseAttack"
// Lua signature:  function(charStats, range, weaponReach, lastAttack, opponentIsStationary, chosenAttack)
void CallCharStatsChooseAttackCallbacks(CharStats* stats, float range, float weaponReach, CombatTechniqueData* lastAttack, bool opponentIsStationary, CombatTechniqueData* chosenAttack);

// Fired by CharStats::xpRunning hook.
// Lua event name: "xpRunning"
// Lua signature:  function(charStats, time, speed)
void CallCharStatsXpRunningCallbacks(CharStats* stats, float time, float speed);

// Fired by CharStats::xpFirstAid hook.
// Lua event name: "xpFirstAid"
// Lua signature:  function(charStats, patient, time, medicStat)
void CallCharStatsXpFirstAidCallbacks(CharStats* stats, Character* patient, float time, int medicStat);

// Fired by CharStats::xpStealth hook.
// Lua event name: "xpStealth"
// Lua signature:  function(charStats, time, enemiesAbout, seen, isMoving)
void CallCharStatsXpStealthCallbacks(CharStats* stats, float time, bool enemiesAbout, YesNoMaybe seen, bool isMoving);

// Fired by CharStats::xpToughness_GetUpEvent hook.
// Lua event name: "xpToughness_GetUpEvent"
// Lua signature:  function(charStats)
void CallCharStatsXpToughness_GetUpEventCallbacks(CharStats* stats);

// Fired by CharStats::xpToughness_RagdollEvent hook.
// Lua event name: "xpToughness_RagdollEvent"
// Lua signature:  function(charStats)
void CallCharStatsXpToughness_RagdollEventCallbacks(CharStats* stats);

// Fired by CharStats::xpToughness_PunchSomething hook.
// Lua event name: "xpToughness_PunchSomething"
// Lua signature:  function(charStats, mat)
void CallCharStatsXpToughness_PunchSomethingCallbacks(CharStats* stats, int mat);

// Fired by CharStats::xpEngineering hook.
// Lua event name: "xpEngineering"
// Lua signature:  function(charStats, time)
void CallCharStatsXpEngineeringCallbacks(CharStats* stats, float time);

// Fired by CharStats::xpLockpicking hook.
// Lua event name: "xpLockpicking"
// Lua signature:  function(charStats, lockLevel, success)
void CallCharStatsXpLockpickingCallbacks(CharStats* stats, int lockLevel, bool success);

// Fired by Character::_NV_takeMoney hook.
// Lua event name: "onCharacterTakeMoney"
// Lua signature:  function(character, amount)
void CallCharacterTakeMoneyCallbacks(Character* character, int amount);

// Fired by Character::eatItem hook.
// Lua event name: "onCharacterEat"
// Lua signature:  function(character, foodItem, inventory)
void CallCharacterEatCallbacks(Character* character, Item* food, Inventory* from);

// Fired by Character::_NV_hitByMeleeAttack hook.
// Lua event name: "onCharacterHitByMelee"
// Lua signature:  function(character, attacker, damage, cutDir, attack, comboID)
void CallCharacterHitByMeleeCallbacks(Character* character, Character* attacker, Damages* damage, int cutDir, CombatTechniqueData* attack, int comboID);

// Fired by Character::_NV_gettingEaten hook.
// Lua event name: "onCharacterGettingEaten"
// Lua signature:  function(character, eater, amount)
void CallCharacterGettingEatenCallbacks(Character* character, Character* eater, float amount);

// Fired by Character::_NV_setStandingOrder hook.
// Lua event name: "onCharacterStandingOrderChanged"
// Lua signature:  function(character, orderID, enabled)
void CallCharacterStandingOrderChangedCallbacks(Character* character, int orderID, bool on);

// Fired by Character::_NV_setFaction hook.
// Lua event name: "onCharacterFactionChanged"
// Lua signature:  function(character, faction, platoon)
void CallCharacterFactionChangedCallbacks(Character* character, Faction* faction, ActivePlatoon* platoon);

// Fired by Character::_NV_equipItem hook.
// Lua event name: "onCharacterEquip"
// Lua signature:  function(character, item, slotName)
void CallCharacterEquipCallbacks(Character* character, const std::string& sectionName, Item* item);

// Fired by Character::_NV_unequipItem hook.
// Lua event name: "onCharacterUnequip"
// Lua signature:  function(character, item, slotName)
void CallCharacterUnequipCallbacks(Character* character, const std::string& sectionName, Item* item);

// Fired by Character::_NV_ImStealingDoYouNotice hook.
// Lua event name: "onPlayerStealCheck"
// Lua signature:  function(thief, victim, item, noticed)
void CallCharacterStealNoticeCallbacks(Character* character, RootObject* stealFrom, Item* item, bool noticed);

// Fired by Character::_NV_smugglingTradeCheck hook.
// Lua event name: "onSmugglingTradeCheck"
// Lua signature:  function(contrabandist, examiner, item, result)
void CallCharacterSmugglingCheckCallbacks(Character* character, Item* item, Character* who, int result);

// Fired by PlayerInterface::recruit hook.
// Lua event name: "onPlayerRecruit"
// Lua signature:  function(character, isEditor)
void CallPlayerRecruitCallbacks(PlayerInterface* player, Character* character, bool editor);

// Fired by PlayerInterface::selectObject hook.
// Lua event name: "onPlayerSelectObject"
// Lua signature:  function(selectedObject, modifierKeyActive)
void CallPlayerSelectCallbacks(PlayerInterface* player, RootObject* obj, bool modifier);

// Fired by PlayerInterface::newPlayerTaskSelectedCharacters hook.
// Lua event name: "onPlayerOrderGiven"
// Lua signature:  function(taskType, targetHandle, destinationBuilding, clickPos, queueOrder)
void CallPlayerOrderGivenCallbacks(PlayerInterface* player, int taskType, const hand& targetH, Building* destinationIndoors, const Ogre::Vector3& clickpos, bool addDontClear);

// Fired by ActivePlatoon::_NV_addActiveObject hook.
// Lua event name: "onPlatoonMemberAdded"
// Lua signature:  function(platoon, character)
void CallPlatoonMemberAddedCallbacks(ActivePlatoon* platoon, RootObject* c);

// Fired by ActivePlatoon::_NV_removeObject hook.
// Lua event name: "onPlatoonMemberRemoved"
// Lua signature:  function(platoon, character)
void CallPlatoonMemberRemovedCallbacks(ActivePlatoon* platoon, RootObject* c);

// Fired by Platoon::taskIsComplete hook.
// Lua event name: "onPlatoonTaskComplete"
// Lua signature:  function(platoon, completedTask)
void CallPlatoonTaskCompleteCallbacks(Platoon* platoon, Tasker* t);

// Fired by Item::_NV_notifyTheftFrom hook.
// Lua event name: "onItemStolen"
// Lua signature:  function(item, victim)
void CallItemStolenCallbacks(Item* item, RootObject* obj);


