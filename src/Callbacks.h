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
class BountyManager;
class DialogueWindow;
class Dialogue;
class DialogLineData;
class GameData;
class RaceData;
class InventorySection;
class Ownerships;
class InventoryItemBase;
class CharMovement;
class InventoryGUI;
class BuildModeWindow;
class SquadManagementScreen;
class ManagementScreen;
class TitleScreen;
class MedicalSystem;
class GameDataContainer;
class GameSaveState;
class Town;
namespace MyGUI { class Widget; }
template <typename T> class lektor;
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
// Callbacks for hooks in InputHandler.h
// -----------------------------------------------------------

// Fired by InputHandler::keyDownEvent hook.
// Lua event name: "onKeyDown"
// Lua signature:  function(keyCode)
// keyCode is the raw OIS::KeyCode cast to int.
void CallKeyDownCallbacks(int keyCode);

// -----------------------------------------------------------
// Callbacks for hooks in GameWorld.h
// -----------------------------------------------------------

// Fired by GameWorld::charsUpdate hook.
// Lua event name: "onCharsUpdate"
// Lua signature:  function()
void CallCharsUpdateCallbacks();

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

// Fired by Character::_NV_init hook
// Lua event name: "onCharacterInit"
// Lua signature:  function(character)
void CallCharacterInitCallbacks(Character* character);

// Fired by Character::isItOkForMeToLoot hook
// Lua event name: "onCharacterLootCheck"
// Lua signature:  function(me, victim, item, defaultVal) -> boolean
bool CallCharacterIsItOkForMeToLootCallbacks(Character* me, RootObject* victim, Item* item, bool defaultVal);

// Fired by Character::getFencingSuccessChance hook
// Lua event name: "onGetFencingChance"
// Lua signature:  function(merchant, item, thief, defaultVal) -> number
float CallCharacterGetFencingSuccessChanceCallbacks(Character* merchant, Item* item, RootObject* thief, float defaultVal);

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

// Fired by CharStats::getStat hook
// Lua event name: "onGetStat"
// Lua signature:  function(stats, statType, unmodified, defaultVal) -> number
float CallCharStatsGetStatCallbacks(const CharStats* stats, int what, bool unmodified, float defaultVal);

// -----------------------------------------------------------
// Callbacks for hooks in PlayerInterface.h
// -----------------------------------------------------------

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

// -----------------------------------------------------------
// Callbacks for hooks in Platoon.h
// -----------------------------------------------------------

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

// Fired by Platoon::iBuyStolenGoods hook
// Lua event name: "onPlatoonIBuyStolenGoods"
// Lua signature:  function(platoon, item, defaultVal) -> boolean
bool CallPlatoonIBuyStolenGoodsCallbacks(Platoon* platoon, Item* what, bool defaultVal);

// Fired by Platoon::iBuyIllegalGoods hook
// Lua event name: "onPlatoonIBuyIllegalGoods"
// Lua signature:  function(platoon, defaultVal) -> boolean
bool CallPlatoonIBuyIllegalGoodsCallbacks(Platoon* platoon, bool defaultVal);

// Fired by Ownerships::canIUseThisBuilding hook
// Lua event name: "onBuildingUseCheck"
// Lua signature:  function(ownerships, building, character, defaultVal) -> boolean
bool CallOwnershipsCanIUseThisBuildingCallbacks(Ownerships* ownerships, Building* b, Character* me, bool defaultVal);

// -----------------------------------------------------------
// Callbacks for hooks in Item.h
// -----------------------------------------------------------

// Fired by Item::_NV_notifyTheftFrom hook.
// Lua event name: "onItemStolen"
// Lua signature:  function(item, victim)
void CallItemStolenCallbacks(Item* item, RootObject* obj);

// -----------------------------------------------------------
// Callbacks for hooks in Inventory.h / InventoryItemBase.h
// -----------------------------------------------------------

// Fired by Inventory::getSectionOfType hook
// Lua event name: "onInventoryGetSectionOfType"
// Lua signature:  function(inventory, type) -> InventorySection
InventorySection* CallInventoryGetSectionOfTypeCallbacks(Inventory* inventory, int type);

// Fired by Inventory::getBestFoodItem hook
// Lua event name: "onInventoryGetBestFoodItem"
// Lua signature:  function(inventory, race) -> Item
Item* CallInventoryGetBestFoodItemCallbacks(Inventory* inventory, Character* race);

// Fired by Inventory::getBaseValueSingle hook
// Lua event name: "onItemGetValueSingle"
// Lua signature:  function(item, isPlayer, defaultVal) -> integer
int CallInventoryItemBaseGetValueSingleCallbacks(const InventoryItemBase* item, bool isPlayer, int defaultVal);

// -----------------------------------------------------------
// Callbacks for hooks in BountyManager.h
// -----------------------------------------------------------

// Fired by BountyManager::notifyCrimeWitnessed hook.
// Lua event name: "onCrimeWitnessed"
// Lua signature:  function(character, faction, againstWho, expiryTime, crimeType)
void CallCrimeWitnessedCallbacks(Character* character, Faction* against, const hand& againstWho, int expiryTime, int crimeType);

// -----------------------------------------------------------
// Callbacks for hooks in FactionRelations.h
// -----------------------------------------------------------

// Fired by FactionRelations::affectRelations hook.
// Lua event name: "onFactionRelationsAffected"
// Lua signature:  function(faction, otherFaction, eventType, multiplier)
void CallFactionRelationsAffectedCallbacks(Faction* faction, Faction* other, int eventType, float multiplier);

// -----------------------------------------------------------
// Callbacks for hooks in Faction.h
// -----------------------------------------------------------

// Fired by Faction::chooseARace hook
// Lua event name: "onFactionChooseRace"
// Lua signature:  function(faction, character, squadTemplate, defaultVal) -> GameData
GameData* CallFactionChooseARaceCallbacks(Faction* faction, GameData* character, GameData* squadTemplate, GameData* defaultVal);

// Fired by Faction::getBuildingReplacement hook
// Lua event name: "onFactionGetBuildingReplacement"
// Lua signature:  function(faction, building, defaultVal) -> GameData
GameData* CallFactionGetBuildingReplacementCallbacks(Faction* faction, GameData* building, GameData* defaultVal);

// -----------------------------------------------------------
// Callbacks for hooks in MedicalSystem.h
// -----------------------------------------------------------

// Fired by MedicalSystem::amputate hook.
// Lua event name: "onLimbAmputated"
// Lua signature:  function(character, limb, createSeveredItem, forceVector)
void CallLimbAmputatedCallbacks(Character* character, int limb, bool createSeveredItem, const Ogre::Vector3& force);

// -----------------------------------------------------------
// Callbacks for hooks in gui/DialogueWindow.h
// -----------------------------------------------------------

// Fired by DialogueWindow::show hook.
// Lua event name: "onDialogueWindowShow"
// Lua signature:  function(dialogueWindow, dialogue)
void CallDialogueWindowShowCallbacks(DialogueWindow* thisptr, Dialogue* dialogue);

// -----------------------------------------------------------
// Callbacks for hooks in Dialogue.h
// -----------------------------------------------------------

// Fired by Dialogue::_doActions hook.
// Lua event name: "onDialogueDoActions"
// Lua signature:  function(dialogue, dialogLine)
void CallDialogueDoActionsCallbacks(Dialogue* thisptr, DialogLineData* dialogLine);

// Fired by Dialogue::say hook.
// Lua event name: "onDialogueSay"
// Lua signature:  function(dialogue, dialogLine)
void CallDialogueSayCallbacks(Dialogue* thisptr, DialogLineData* dialogLine);

// Fired by Dialogue::endDialogue hook.
// Lua event name: "onDialogueEndDialogue"
// Lua signature:  function(dialogue, definitelyTheEnd)
void CallDialogueEndDialogueCallbacks(Dialogue* dialogue, bool definitelyTheEnd);

// Fired by Dialogue::_checkCondition hook.
// Lua event name: "onDialogueCheckCondition"
// Lua signature:  function(dialogue, conditionName, compareBy, val, target, actualConversationTarget, defaultVal) -> boolean
bool CallDialogueCheckConditionCallbacks(Dialogue* dialogue, DialogConditionEnum conditionName, ComparisonEnum compareBy, int val, Character* target, Character* actualConversationTarget, bool defaultVal);

// Fired by Dialogue::startConversation hook.
// Lua event name: "onDialogueStartConversation"
// Lua signature:  function(dialogue, target, talk, ev, force, defaultVal) -> boolean
bool CallDialogueStartConversationCallbacks(Dialogue* dialogue, Character* target, DialogLineData* talk, EventTriggerEnum ev, bool force, bool defaultVal);

// Fired by Dialogue::_endPlayerConversation hook.
// Lua event name: "onDialogueEndPlayerConversation"
// Lua signature:  function(dialogue, finished)
void CallDialogueEndPlayerConversationCallbacks(Dialogue* dialogue, bool finished);

// Fired by Dialogue::startPlayerConversation hook.
// Lua event name: "onDialogueStartPlayerConversation"
// Lua signature:  function(dialogue, target, talk, defaultVal) -> boolean
bool CallDialogueStartPlayerConversationCallbacks(Dialogue* dialogue, Character* target, DialogLineData* talk, bool defaultVal);

// Fired by Dialogue::sendEvent hook.
// Lua event name: "onDialogueSendEvent"
// Lua signature:  function(dialogue, who, what, defaultVal) -> boolean
bool CallDialogueSendEventCallbacks(Dialogue* dialogue, Character* who, EventTriggerEnum what, bool defaultVal);

// Fired by Dialogue::stopEvent hook.
// Lua event name: "onDialogueStopEvent"
// Lua signature:  function(dialogue, what)
void CallDialogueStopEventCallbacks(Dialogue* dialogue, EventTriggerEnum what);

// -----------------------------------------------------------
// Callbacks for hooks in RootObjectFactory.h
// -----------------------------------------------------------

// Fired by RootObjectFactory::chooseMyClothing hook
// Lua event name: "onChooseMyClothing"
// Lua signature:  function(gearLektor, dataList, listName, race, noShoes)
void CallChooseMyClothingCallbacks(lektor<GameData*>& gear, GameData* dataList, const std::string& listName, RaceData* race, bool noShoes);

// -----------------------------------------------------------
// Callbacks for hooks in mygui/common/baselayout/BaseLayout.h
// -----------------------------------------------------------

// Fired by wraps::BaseLayout::initialise hook
// Lua event name: "onBaseLayoutInitialise"
// Lua signature:  function(layoutName)
void CallBaseLayoutInitialiseCallbacks(const std::string& layout);

// -----------------------------------------------------------
// Callbacks for hooks in Building/Building.h
// -----------------------------------------------------------

// Fired by Building::isPublic hook
// Lua event name: "onBuildingIsPublic"
// Lua signature:  function(building, defaultVal) -> boolean
bool CallBuildingIsPublicCallbacks(const Building* b, bool defaultVal);

// Fired by Building::isForSale hook
// Lua event name: "onBuildingIsForSale"
// Lua signature:  function(building, defaultVal) -> boolean
bool CallBuildingIsForSaleCallbacks(Building* b, bool defaultVal);

// Fired by Building::calculateSaleValue hook
// Lua event name: "onBuildingCalculateSaleValue"
// Lua signature:  function(building, defaultVal) -> integer
int CallBuildingCalculateSaleValueCallbacks(Building* b, int defaultVal);

//---------------------------------------------------------
// Callbacks for hooks in CharMovement.h
//---------------------------------------------------------

// Fired by CharMovement::isRunning hook
// Lua event name: "onCharMovementIsRunning"
// Lua signature:  function(charMovement, defaultVal) -> boolean
bool CallCharMovementIsRunningCallbacks(CharMovement* thisptr, bool defaultVal);

// Fired by CharMovement::isRunningAway hook
// Lua event name: "onCharMovementIsRunningAway"
// Lua signature:  function(charMovement, from, defaultVal) -> boolean
bool CallCharMovementIsRunningAwayCallbacks(CharMovement* thisptr, const Ogre::Vector3& from, bool defaultVal);

// Fired by CharStats::xpStat_eventBased hook
// Lua event name: "onCharStatsXpStatEvent"
// Lua signature:  function(charStats, statType, amount)
void CallCharStatsXpStatEventBasedCallbacks(CharStats* stats, int stat, float amount);

// Fired by CharStats::xpDodgeEvent hook
// Lua event name: "onCharStatsXpDodgeEvent"
// Lua signature:  function(charStats, enemySkill, successful)
void CallCharStatsXpDodgeEventCallbacks(CharStats* stats, float enemySkill, bool successful);

// Fired by PlayerInterface::activateCharacterEditMode hook
// Lua event name: "onPlayerActivateCharacterEditMode"
// Lua signature:  function(player, character)
void CallPlayerActivateCharacterEditModeCallbacks(PlayerInterface* player, Character* character);

// Fired by PlayerInterface::createSquad hook
// Lua event name: "onPlayerCreateSquad"
// Lua signature:  function(player, newSquad)
void CallPlayerCreateSquadCallbacks(PlayerInterface* player, ActivePlatoon* newSquad);

// Fired by Building::setResidentSquad hook
// Lua event name: "onBuildingSetResidentSquad"
// Lua signature:  function(building, platoon)
void CallBuildingSetResidentSquadCallbacks(Building* building, Platoon* who);

// Fired by Building::addAnInternalBuilding hook
// Lua event name: "onBuildingAddInternalBuilding"
// Lua signature:  function(building, internalBuilding)
void CallBuildingAddInternalBuildingCallbacks(Building* building, Building* b);

// Fired by InventoryGUI::addTradePartner hook
// Lua event name: "onInventoryAddTradePartner"
// Lua signature:  function(tradeWith, payment, canDrop, isPlayer, whoHand)
void CallInventoryAddTradePartnerCallbacks(InventoryGUI* tradeWith, bool payment, bool canDrop, bool isPlayer, const hand& who);

// Fired by BuildModeWindow::confirm hook
// Lua event name: "onBuildModeConfirm"
// Lua signature:  function(buildModeWindow, widget)
void CallBuildModeWindowConfirmCallbacks(BuildModeWindow* window, MyGUI::Widget* sender);

// Fired by SquadManagementScreen::removeSquad hook
// Lua event name: "onSquadRemoved"
// Lua signature:  function(squadManagementScreen, squadData)
void CallSquadManagementScreenRemoveSquadCallbacks(SquadManagementScreen* screen, void* squadData);

// Fired by ManagementScreen::addMessage hook
// Lua event name: "onManagementScreenMessageAdded"
// Lua signature:  function(managementScreen, owner, message, logColor)
void CallManagementScreenAddMessageCallbacks(ManagementScreen* screen, const std::string& owner, const std::string& message, int logColor);

// Fired by TitleScreen::loadGame hook
// Lua event name: "onTitleScreenLoadGame"
// Lua signature:  function(titleScreen, widget)
void CallTitleScreenLoadGameCallbacks(TitleScreen* titleScreen, MyGUI::Widget* sender);

// Fired by Character::addGoal hook
// Lua event name: "onCharacterAddGoal"
// Lua signature:  function(character, taskType, subject)
void CallCharacterAddGoalCallbacks(Character* character, int task, RootObject* subject);

// Fired by Character::addJob hook
// Lua event name: "onCharacterAddJob"
// Lua signature:  function(character, taskType, subject, shift, addDontClear, location)
void CallCharacterAddJobCallbacks(Character* character, int task, RootObject* subject, bool shift, bool addDontClear, const Ogre::Vector3& location);

// Fired by Character::addOrder hook
// Lua event name: "onCharacterAddOrder"
// Lua signature:  function(character, destBuilding, taskType, subject, shift, clear, location)
void CallCharacterAddOrderCallbacks(Character* character, Building* dest, int task, RootObject* subject, bool shift, bool clear, const Ogre::Vector3& location);

// Fired by Character::removeJob hook
// Lua event name: "onCharacterRemoveJob"
// Lua signature:  function(character, taskType)
void CallCharacterRemoveJobCallbacks(Character* character, int task);

// Fired by PlayerInterface::addJobSelectedCharacters hook
// Lua event name: "onPlayerAddJobSelectedCharacters"
// Lua signature:  function(player, taskType, subject, shift, add, location)
void CallPlayerInterfaceAddJobSelectedCharactersCallbacks(PlayerInterface* player, int task, RootObject* subject, bool shift, bool add, const Ogre::Vector3& location);

// Fired by PlayerInterface::addOrderSelectedCharacters hook
// Lua event name: "onPlayerAddOrderSelectedCharacters"
// Lua signature:  function(player, destinationIndoors, taskType, subject, shift, addDontClear, location)
void CallPlayerInterfaceAddOrderSelectedCharactersCallbacks(PlayerInterface* player, Building* destinationIndoors, int task, RootObject* subject, bool shift, bool addDontClear, const Ogre::Vector3& location);

// Fired by MedicalSystem::knockout hook
// Lua event name: "onCharacterKnockedOut"
// Lua signature:  function(character, skill)
void CallMedicalSystemKnockoutCallbacks(MedicalSystem* med, float skill);

// Fired by MedicalSystem::canGetUpWakeUp hook
// Lua event name: "onCharacterWakeUp"
// Lua signature:  function(character) -> boolean
bool CallMedicalSystemCanGetUpWakeUpCallbacks(MedicalSystem* med);

// Fired by Inventory::addItem hook
// Lua event name: "onInventoryAddItem"
// Lua signature:  function(inventory, item, quantity, dropOnFail, destroyOnFail) -> boolean
bool CallInventoryAddItemCallbacks(Inventory* inv, Item* item, int quantity, bool dropOnFail, bool destroyOnFail);

// Fired by Inventory::removeItemDontDestroy_returnsItem hook
// Lua event name: "onInventoryRemoveItem"
// Lua signature:  function(inventory, item, howmany, returnCopyIfSomeLeft) -> Item
Item* CallInventoryRemoveItemCallbacks(Inventory* inv, Item* item, int howmany, bool returnCopyIfSomeLeft);

// Fired by Inventory::buyItem hook
// Lua event name: "onItemBought"
// Lua signature:  function(buyerInventory, item, sendingTo) -> Item
Item* CallInventoryBuyItemCallbacks(Inventory* inv, Item* item, RootObject* sender);

// Fired by Faction::createNewEmptyActivePlatoon hook
// Lua event name: "onActivePlatoonCreated"
// Lua signature:  function(faction, platoon)
void CallFactionActivePlatoonCreatedCallbacks(Faction* faction, Platoon* platoon);

// Fired by Faction::destroyPlatoon hook
// Lua event name: "onPlatoonDestroyed"
// Lua signature:  function(faction, platoon)
void CallFactionPlatoonDestroyedCallbacks(Faction* faction, Platoon* platoon);

// Fired by PlayerInterface::encounterFaction hook
// Lua event name: "onFactionEncountered"
// Lua signature:  function(player, faction)
void CallPlayerEncounterFactionCallbacks(PlayerInterface* player, Faction* faction);

// Fired by Character::changeSlaveOwner hook
// Lua event name: "onSlaveOwnerChanged"
// Lua signature:  function(slave, newOwnerHandle)
void CallCharacterSlaveOwnerChangedCallbacks(Character* slave, const hand& newOwner);

// Fired by Character::setChainedMode hook
// Lua event name: "onChainedModeChanged"
// Lua signature:  function(character, on, ownerHandle)
void CallCharacterChainedModeChangedCallbacks(Character* character, bool on, const hand& owner);

// Fired by Character::notifyIndoors hook
// Lua event name: "onCharacterIndoorsChanged"
// Lua signature:  function(character, indoorsHandle)
void CallCharacterIndoorsChangedCallbacks(Character* character, const hand& indoors);

// Fired by Building::onBuildingLoaded hook
// Lua event name: "onBuildingLoaded"
// Lua signature:  function(building)
void CallBuildingLoadedCallbacks(Building* building);

// Fired by Building::setBroken hook
// Lua event name: "onBuildingBrokenChanged"
// Lua signature:  function(building, broken)
void CallBuildingBrokenChangedCallbacks(Building* building, bool broken);

// -----------------------------------------------------------
// Callbacks for Serialization
// -----------------------------------------------------------

// Fired by PlayerInterface::serialise hook.
// Lua event name: "onPlayerSerialise"
// Lua signature:  function(player, gameData)
void CallPlayerInterfaceSerialiseCallbacks(PlayerInterface* player, GameData* data);

// Fired by PlayerInterface::loadFromSerialise hook.
// Lua event name: "onPlayerLoadFromSerialise"
// Lua signature:  function(player, gameData)
void CallPlayerInterfaceLoadFromSerialiseCallbacks(PlayerInterface* player, GameData* data);

// Fired by Character::_NV_serialise hook.
// Lua event name: "onCharacterSerialise"
// Lua signature:  function(character, container, refList)
void CallCharacterSerialiseCallbacks(Character* character, GameDataContainer* container, GameData* refList);

// Fired by Character::_NV_loadFromSerialise hook.
// Lua event name: "onCharacterLoadFromSerialise"
// Lua signature:  function(character, saveState)
void CallCharacterLoadFromSerialiseCallbacks(Character* character, GameSaveState* state);

// Fired by Character::_NV_loadFromSerialisePostCreationStage hook.
// Lua event name: "onCharacterLoadFromSerialisePostCreationStage"
// Lua signature:  function(character, saveState)
void CallCharacterLoadFromSerialisePostCreationStageCallbacks(Character* character, GameSaveState* state);

// Fired by Building::_NV_serialise hook.
// Lua event name: "onBuildingSerialise"
// Lua signature:  function(building, container, refList)
void CallBuildingSerialiseCallbacks(Building* building, GameDataContainer* container, GameData* refList);

// Fired by Building::_NV_loadFromSerialise hook.
// Lua event name: "onBuildingLoadFromSerialise"
// Lua signature:  function(building, saveState)
void CallBuildingLoadFromSerialiseCallbacks(Building* building, GameSaveState* state);

// Fired by Platoon::_NV_loadFromSerialise hook.
// Lua event name: "onPlatoonLoadFromSerialise"
// Lua signature:  function(platoon, saveState)
void CallPlatoonLoadFromSerialiseCallbacks(Platoon* platoon, GameSaveState* state);

// Fired by Town::_NV_loadFromSerialise hook.
// Lua event name: "onTownLoadFromSerialise"
// Lua signature:  function(town, saveState)
void CallTownLoadFromSerialiseCallbacks(Town* town, GameSaveState* state);
