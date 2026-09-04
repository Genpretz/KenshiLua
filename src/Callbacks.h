#pragma once

#include <string>

// Forward declaration — avoids pulling in the full headers in every
// translation unit that only needs to call these dispatchers.
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
class UseableStuff;
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
class OrdersPanel;
class DataPanelLine_Button;
class InputHandler;
class GameWorld;
class Gear;
class Sword;
class Crossbow;
class Armour;
class LockedArmour;
class Weapon;
class Bounty;
class DataObjectContainer;
class Layout;
class DoorStuff;
class ProductionBuilding;
class CraftingBuilding;
class FarmBuilding;
class TurretBuilding;
class FurnaceBuilding;
class ResearchBuilding;
class PreviewBuilding;
class WallBuilding;
class CharacterHuman;
class CharacterAnimal;
class CharBody;
class TownBase;
class FactionLeader;
class FactionRelations;
class FactionUniqueSquadManager;
class ProsperityManager;
class StorageBuilding;
class LightBuilding;
class GeneratorBuilding;
class WindGeneratorBuilding;
class GatewayBuilding;
class TortureBuilding;
class RainCollectorBuilding;
class DataPanelLine;
class rendHit;
namespace wraps { class BaseLayout; }
namespace MyGUI { class Widget; }
template <typename T> class lektor;
namespace Ogre {
    class Vector3;
    class Quaternion;
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
// Lua signature:  function(inputHandler, keyCode)
// keyCode is the raw OIS::KeyCode cast to int.
void CallKeyDownCallbacks(InputHandler* thisptr, int keyCode);

// -----------------------------------------------------------
// Callbacks for hooks in GameWorld.h
// -----------------------------------------------------------

// Fired by GameWorld::charsUpdate hook.
// Lua event name: "onCharsUpdate"
// Lua signature:  function(gameWorld)
void CallCharsUpdateCallbacks(GameWorld* thisptr);

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
// Lua signature:  function(character, who)
void CallCharacterPickupObjectCallbacks(Character* character, Character* who);

// Fired by Character::getPickedUp hook.
// Lua event name: "onCharacterGetPickedUp"
// Lua signature:  function(character, byWhom)
void CallCharacterGetPickedUpCallbacks(Character* character, Character* byWhom);

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
// Lua signature:  function(character, cutDir, damage, attacker, attack, comboID)
void CallCharacterHitByMeleeCallbacks(Character* character, int cutDir, Damages* damage, Character* attacker, CombatTechniqueData* attack, int comboID);

// Fired by Character::_NV_gettingEaten hook.
// Lua event name: "onCharacterGettingEaten"
// Lua signature:  function(character, amount, eater)
void CallCharacterGettingEatenCallbacks(Character* character, float amount, Character* eater);

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
// Lua signature:  function(character, sectionName, item)
void CallCharacterEquipCallbacks(Character* character, const std::string& sectionName, Item* item);

// Fired by Character::_NV_unequipItem hook.
// Lua event name: "onCharacterUnequip"
// Lua signature:  function(character, sectionName, item)
void CallCharacterUnequipCallbacks(Character* character, const std::string& sectionName, Item* item);

// Fired by Character::_NV_ImStealingDoYouNotice hook.
// Lua event name: "onPlayerStealCheck"
// Lua signature:  function(character, stealFrom, item)
void CallCharacterStealNoticeCallbacks(Character* character, RootObject* stealFrom, Item* item);

// Fired by Character::_NV_smugglingTradeCheck hook.
// Lua event name: "onSmugglingTradeCheck"
// Lua signature:  function(character, item, who)
void CallCharacterSmugglingCheckCallbacks(Character* character, Item* item, Character* who);

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
// Lua signature:  function(charStats, range, weaponReach, lastAttack, opponentIsStationary, defaultAttack) -> CombatTechniqueData
CombatTechniqueData* CallCharStatsChooseAttackCallbacks(CharStats* stats, float range, float weaponReach, CombatTechniqueData* lastAttack, bool opponentIsStationary, CombatTechniqueData* defaultVal);

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
// Lua signature:  function(bountyManager, faction, againstWho, expiryTime, crimeType)
void CallCrimeWitnessedCallbacks(BountyManager* bountyMgr, Faction* against, const hand& againstWho, int expiryTime, int crimeType);

// -----------------------------------------------------------
// Callbacks for hooks in FactionRelations.h
// -----------------------------------------------------------

// Fired by FactionRelations::affectRelations hook.
// Lua event name: "onFactionRelationsAffected"
// Lua signature:  function(factionRelations, otherFaction, eventType, multiplier)
void CallFactionRelationsAffectedCallbacks(FactionRelations* factionRelations, Faction* other, int eventType, float multiplier);

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
// Lua signature:  function(medicalSystem, limb, createSeveredItem, forceVector)
void CallLimbAmputatedCallbacks(MedicalSystem* med, int limb, bool createSeveredItem, const Ogre::Vector3& force);

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
// Lua signature:  function(baseLayout, layoutName)
void CallBaseLayoutInitialiseCallbacks(wraps::BaseLayout* thisptr, const std::string& layout);

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
// Lua signature:  function(medicalSystem, skill)
void CallMedicalSystemKnockoutCallbacks(MedicalSystem* med, float skill);

// Fired by MedicalSystem::canGetUpWakeUp hook
// Lua event name: "onCharacterWakeUp"
// Lua signature:  function(medicalSystem) -> boolean
bool CallMedicalSystemCanGetUpWakeUpCallbacks(MedicalSystem* med, bool defaultVal = true);

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

// Fired by Building::_NV_buyMeCallback hook.
// Lua event name: "onBuildingBuyMeCallback"
// Lua signature:  function(building, result)
void CallBuildingBuyMeCallbackCallbacks(Building* building, int result);

// Fired by DataPanelLine_Button::pressCallback hook.
// Lua event name: "onDataPanelLineButtonPress"
// Lua signature:  function(button, sender)
void CallDataPanelLineButtonPressCallbacks(DataPanelLine_Button* button, MyGUI::Widget* sender);

// Fired by InventoryGUI::fencingConfirmationCallback hook.
// Lua event name: "onInventoryGUIFencingConfirmation"
// Lua signature:  function(gui, b)
void CallInventoryGUIFencingConfirmationCallbacks(InventoryGUI* gui, int b);

// Fired by OrdersPanel::blockmodeButton hook.
// Lua event name: "onOrdersPanelBlockModeButton"
// Lua signature:  function(panel, sender)
void CallOrdersPanelBlockModeButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender);

// Fired by OrdersPanel::holdButtonCallback hook.
// Lua event name: "onOrdersPanelHoldButton"
// Lua signature:  function(panel, sender)
void CallOrdersPanelHoldButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender);

// Fired by OrdersPanel::passiveButtonCallback hook.
// Lua event name: "onOrdersPanelPassiveButton"
// Lua signature:  function(panel, sender)
void CallOrdersPanelPassiveButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender);

// Fired by OrdersPanel::chaseButtonCallback hook.
// Lua event name: "onOrdersPanelChaseButton"
// Lua signature:  function(panel, sender)
void CallOrdersPanelChaseButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender);

// Fired by OrdersPanel::tauntButtonCallback hook.
// Lua event name: "onOrdersPanelTauntButton"
// Lua signature:  function(panel, sender)
void CallOrdersPanelTauntButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender);

// Fired by OrdersPanel::medicButton hook.
// Lua event name: "onOrdersPanelMedicButton"
// Lua signature:  function(panel, sender)
void CallOrdersPanelMedicButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender);

// Fired by OrdersPanel::liftButton hook.
// Lua event name: "onOrdersPanelLiftButton"
// Lua signature:  function(panel, sender)
void CallOrdersPanelLiftButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender);

// Fired by OrdersPanel::prospectingButton hook.
// Lua event name: "onOrdersPanelProspectingButton"
// Lua signature:  function(panel, sender)
void CallOrdersPanelProspectingButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender);

// Fired by Inventory::_NV__sectionAddItemCallback hook.
// Lua event name: "onInventorySectionAddItem"
// Lua signature:  function(inventory, item)
void CallInventorySectionAddItemCallbacks(Inventory* inventory, Item* item);

// Fired by Inventory::_NV__sectionRemoveItemCallback hook.
// Lua event name: "onInventorySectionRemoveItem"
// Lua signature:  function(inventory, item)
void CallInventorySectionRemoveItemCallbacks(Inventory* inventory, Item* item);

// Fired by Inventory::_NV__sectionUpdateItemCallback hook.
// Lua event name: "onInventorySectionUpdateItem"
// Lua signature:  function(inventory, item, prevQuantity)
void CallInventorySectionUpdateItemCallbacks(Inventory* inventory, Item* item, int prevQuantity);

// Fired by Inventory::_NV_dropItem hook.
// Lua event name: "onInventoryDropItem"
// Lua signature:  function(inventory, item)
void CallInventoryDropItemCallbacks(Inventory* inventory, Item* item);

// -----------------------------------------------------------
// Constructor Interceptor Callbacks
// -----------------------------------------------------------

// Fired by Character::_CONSTRUCTOR hook.
// Lua event name: "onCharacterConstructed"
// Lua signature:  function(character, dat, own, handle, defaultVal) -> Character
Character* CallCharacterConstructedCallbacks(Character* thisptr, GameData* dat, Faction* own, const hand& _handle, Character* defaultVal);

// Fired by Item::_CONSTRUCTOR hook.
// Lua event name: "onItemConstructed"
// Lua signature:  function(item, baseData, companyData, materialData, handle, defaultVal) -> Item
Item* CallItemConstructedCallbacks(Item* thisptr, GameData* baseData, GameData* companyData, GameData* _materialData, hand _handle, Item* defaultVal);

// Fired by Gear::_CONSTRUCTOR hook.
// Lua event name: "onGearConstructed"
// Lua signature:  function(gear, baseData, companyData, materialData, handle, level, uniform, defaultVal) -> Gear
Gear* CallGearConstructedCallbacks(Gear* thisptr, GameData* baseData, GameData* companyData, GameData* materialData, hand _handle, int _level, Faction* uniform, Gear* defaultVal);

// Fired by Sword::_CONSTRUCTOR hook.
// Lua event name: "onSwordConstructed"
// Lua signature:  function(sword, baseData, companyData, materialData, handle, level, defaultVal) -> Sword
Sword* CallSwordConstructedCallbacks(Sword* thisptr, GameData* baseData, GameData* companyData, GameData* materialData, hand _handle, int _level, Sword* defaultVal);

// Fired by Crossbow::_CONSTRUCTOR hook.
// Lua event name: "onCrossbowConstructed"
// Lua signature:  function(crossbow, baseData, handle, overallLevel, defaultVal) -> Crossbow
Crossbow* CallCrossbowConstructedCallbacks(Crossbow* thisptr, GameData* baseData, hand _handle, int _overalllevel, Crossbow* defaultVal);

// Fired by Armour::_CONSTRUCTOR hook.
// Lua event name: "onArmourConstructed"
// Lua signature:  function(armour, baseData, materialData, handle, uniformFlag, level, defaultVal) -> Armour
Armour* CallArmourConstructedCallbacks(Armour* thisptr, GameData* baseData, GameData* _materialData, hand _handle, Faction* _uniformFlag, int _level, Armour* defaultVal);

// Fired by LockedArmour::_CONSTRUCTOR hook.
// Lua event name: "onLockedArmourConstructed"
// Lua signature:  function(lockedArmour, baseData, materialData, handle, uniformFlag, level, defaultVal) -> LockedArmour
LockedArmour* CallLockedArmourConstructedCallbacks(LockedArmour* thisptr, GameData* baseData, GameData* _materialData, hand _handle, Faction* _uniformFlag, int _level, LockedArmour* defaultVal);

// Fired by Weapon::_CONSTRUCTOR hook.
// Lua event name: "onWeaponConstructed"
// Lua signature:  function(weapon, baseData, companyData, materialData, handle, level, defaultVal) -> Weapon
Weapon* CallWeaponConstructedCallbacks(Weapon* thisptr, GameData* baseData, GameData* companyData, GameData* materialData, hand _handle, int _level, Weapon* defaultVal);

// Fired by Building::_CONSTRUCTOR hook.
// Lua event name: "onBuildingConstructed"
// Lua signature:  function(building, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> Building
Building* CallBuildingConstructedCallbacks(Building* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, Building* defaultVal);

// Fired by Platoon::_CONSTRUCTOR hook.
// Lua event name: "onPlatoonConstructed"
// Lua signature:  function(platoon, faction, squadTemplate, platoonState, position, persistent, defaultVal) -> Platoon
Platoon* CallPlatoonConstructedCallbacks(Platoon* thisptr, Faction* f, GameData* _squadTemplate, GameData* platoonState, const Ogre::Vector3& p, bool _persistent, Platoon* defaultVal);

// Fired by ActivePlatoon::_CONSTRUCTOR hook.
// Lua event name: "onActivePlatoonConstructed"
// Lua signature:  function(activePlatoon, platoon, doc, faction, gameData, currentGoal, posOffset, defaultVal) -> ActivePlatoon
ActivePlatoon* CallActivePlatoonConstructedCallbacks(ActivePlatoon* thisptr, Platoon* my, DataObjectContainer* doc, Faction* f, GameData* d, Tasker* _currentGoal, const Ogre::Vector3& _posOffset, ActivePlatoon* defaultVal);

// Fired by Faction::_CONSTRUCTOR hook.
// Lua event name: "onFactionConstructed"
// Lua signature:  function(faction, name, defaultVal) -> Faction
Faction* CallFactionConstructedCallbacks(Faction* thisptr, const std::string& _name, Faction* defaultVal);

// Fired by Bounty::_CONSTRUCTOR hook.
// Lua event name: "onBountyConstructed"
// Lua signature:  function(bounty, defaultVal) -> Bounty
Bounty* CallBountyConstructedCallbacks(Bounty* thisptr, Bounty* defaultVal);

// Fired by Damages::_CONSTRUCTOR hook.
// Lua event name: "onDamagesConstructed"
// Lua signature:  function(damages, cut, blunt, pierce, bleed, armour, defaultVal) -> Damages
Damages* CallDamagesConstructedCallbacks(Damages* thisptr, float _cut, float _blunt, float _pierce, float bleed, float armour, Damages* defaultVal);

// Fired by Inventory::_CONSTRUCTOR hook.
// Lua event name: "onInventoryConstructed"
// Lua signature:  function(inventory, owner, defaultVal) -> Inventory
Inventory* CallInventoryConstructedCallbacks(Inventory* thisptr, RootObject* _owner, Inventory* defaultVal);

// Fired by DoorStuff::_CONSTRUCTOR hook.
// Lua event name: "onDoorStuffConstructed"
// Lua signature:  function(doorStuff, dat, position, orientation, participant, town, handle, isFurnitureOf, indoors, parent, defaultVal) -> DoorStuff
DoorStuff* CallDoorStuffConstructedCallbacks(DoorStuff* thisptr, GameData* dat, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, Building* par, DoorStuff* defaultVal);

// Fired by ProductionBuilding::_CONSTRUCTOR hook.
// Lua event name: "onProductionBuildingConstructed"
// Lua signature:  function(productionBuilding, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> ProductionBuilding
ProductionBuilding* CallProductionBuildingConstructedCallbacks(ProductionBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, ProductionBuilding* defaultVal);

// Fired by CraftingBuilding::_CONSTRUCTOR hook.
// Lua event name: "onCraftingBuildingConstructed"
// Lua signature:  function(craftingBuilding, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> CraftingBuilding
CraftingBuilding* CallCraftingBuildingConstructedCallbacks(CraftingBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, CraftingBuilding* defaultVal);

// Fired by FarmBuilding::_CONSTRUCTOR hook.
// Lua event name: "onFarmBuildingConstructed"
// Lua signature:  function(farmBuilding, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> FarmBuilding
FarmBuilding* CallFarmBuildingConstructedCallbacks(FarmBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, FarmBuilding* defaultVal);

// Fired by TurretBuilding::_CONSTRUCTOR hook.
// Lua event name: "onTurretBuildingConstructed"
// Lua signature:  function(turretBuilding, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> TurretBuilding
TurretBuilding* CallTurretBuildingConstructedCallbacks(TurretBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, TurretBuilding* defaultVal);

// Fired by FurnaceBuilding::_CONSTRUCTOR hook.
// Lua event name: "onFurnaceBuildingConstructed"
// Lua signature:  function(furnaceBuilding, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> FurnaceBuilding
FurnaceBuilding* CallFurnaceBuildingConstructedCallbacks(FurnaceBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, FurnaceBuilding* defaultVal);

// Fired by ResearchBuilding::_CONSTRUCTOR hook.
// Lua event name: "onResearchBuildingConstructed"
// Lua signature:  function(researchBuilding, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> ResearchBuilding
ResearchBuilding* CallResearchBuildingConstructedCallbacks(ResearchBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, ResearchBuilding* defaultVal);

// Fired by WallBuilding::_CONSTRUCTOR hook.
// Lua event name: "onWallBuildingConstructed"
// Lua signature:  function(wallBuilding, dat, position, orientation, participant, furnitureOf, town, handle, defaultVal) -> WallBuilding
WallBuilding* CallWallBuildingConstructedCallbacks(WallBuilding* thisptr, GameData* dat, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, Layout* furnitureOf, const hand& town, const hand& _handle, WallBuilding* defaultVal);

// Fired by PreviewBuilding::_CONSTRUCTOR hook.
// Lua event name: "onPreviewBuildingConstructed"
// Lua signature:  function(previewBuilding, data, furnitureParent, defaultVal) -> PreviewBuilding
PreviewBuilding* CallPreviewBuildingConstructedCallbacks(PreviewBuilding* thisptr, GameData* data, Building* _furnitureParent, PreviewBuilding* defaultVal);

// Fired by UseableStuff::_CONSTRUCTOR hook.
// Lua event name: "onUseableStuffConstructed"
// Lua signature:  function(useableStuff, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> UseableStuff
UseableStuff* CallUseableStuffConstructedCallbacks(UseableStuff* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, UseableStuff* defaultVal);

// Fired by StorageBuilding::_CONSTRUCTOR hook.
// Lua event name: "onStorageBuildingConstructed"
// Lua signature:  function(storageBuilding, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> StorageBuilding
StorageBuilding* CallStorageBuildingConstructedCallbacks(StorageBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, StorageBuilding* defaultVal);

// Fired by LightBuilding::_CONSTRUCTOR hook.
// Lua event name: "onLightBuildingConstructed"
// Lua signature:  function(lightBuilding, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> LightBuilding
LightBuilding* CallLightBuildingConstructedCallbacks(LightBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, LightBuilding* defaultVal);

// Fired by GeneratorBuilding::_CONSTRUCTOR hook.
// Lua event name: "onGeneratorBuildingConstructed"
// Lua signature:  function(generatorBuilding, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> GeneratorBuilding
GeneratorBuilding* CallGeneratorBuildingConstructedCallbacks(GeneratorBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, GeneratorBuilding* defaultVal);

// Fired by WindGeneratorBuilding::_CONSTRUCTOR hook.
// Lua event name: "onWindGeneratorBuildingConstructed"
// Lua signature:  function(windGeneratorBuilding, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> WindGeneratorBuilding
WindGeneratorBuilding* CallWindGeneratorBuildingConstructedCallbacks(WindGeneratorBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, WindGeneratorBuilding* defaultVal);

// Fired by GatewayBuilding::_CONSTRUCTOR hook.
// Lua event name: "onGatewayBuildingConstructed"
// Lua signature:  function(gatewayBuilding, dat, position, orientation, participant, town, handle, defaultVal) -> GatewayBuilding
GatewayBuilding* CallGatewayBuildingConstructedCallbacks(GatewayBuilding* thisptr, GameData* dat, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, GatewayBuilding* defaultVal);

// Fired by TortureBuilding::_CONSTRUCTOR hook.
// Lua event name: "onTortureBuildingConstructed"
// Lua signature:  function(tortureBuilding, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> TortureBuilding
TortureBuilding* CallTortureBuildingConstructedCallbacks(TortureBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* participant, const hand& town, const hand& handle, Layout* isfurnitureOf, Building* indoors, TortureBuilding* defaultVal);

// Fired by RainCollectorBuilding::_CONSTRUCTOR hook.
// Lua event name: "onRainCollectorBuildingConstructed"
// Lua signature:  function(rainCollectorBuilding, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> RainCollectorBuilding
RainCollectorBuilding* CallRainCollectorBuildingConstructedCallbacks(RainCollectorBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* participant, const hand& town, const hand& handle, Layout* isfurnitureOf, Building* indoors, RainCollectorBuilding* defaultVal);

// Fired by CharacterHuman::_CONSTRUCTOR hook.
// Lua event name: "onCharacterHumanConstructed"
// Lua signature:  function(characterHuman, data, faction, handle, defaultVal) -> CharacterHuman
CharacterHuman* CallCharacterHumanConstructedCallbacks(CharacterHuman* thisptr, GameData* d, Faction* f, const hand& _handle, CharacterHuman* defaultVal);

// Fired by CharacterAnimal::_CONSTRUCTOR hook.
// Lua event name: "onCharacterAnimalConstructed"
// Lua signature:  function(characterAnimal, data, faction, handle, defaultVal) -> CharacterAnimal
CharacterAnimal* CallCharacterAnimalConstructedCallbacks(CharacterAnimal* thisptr, GameData* d, Faction* f, const hand& _handle, CharacterAnimal* defaultVal);

// Fired by CharStats::_CONSTRUCTOR hook.
// Lua event name: "onCharStatsConstructed"
// Lua signature:  function(charStats, defaultVal) -> CharStats
CharStats* CallCharStatsConstructedCallbacks(CharStats* thisptr, CharStats* defaultVal);

// Fired by CharBody::_CONSTRUCTOR hook.
// Lua event name: "onCharBodyConstructed"
// Lua signature:  function(charBody, defaultVal) -> CharBody
CharBody* CallCharBodyConstructedCallbacks(CharBody* thisptr, CharBody* defaultVal);

// Fired by CharMovement::_CONSTRUCTOR hook.
// Lua event name: "onCharMovementConstructed"
// Lua signature:  function(charMovement, defaultVal) -> CharMovement
CharMovement* CallCharMovementConstructedCallbacks(CharMovement* thisptr, CharMovement* defaultVal);

// Fired by CombatClass::_CONSTRUCTOR hook.
// Lua event name: "onCombatClassConstructed"
// Lua signature:  function(combatClass, movement, ai, anim, character, stats, medical, defaultVal) -> CombatClass
CombatClass* CallCombatClassConstructedCallbacks(CombatClass* thisptr, CharMovement* m, void* a, void* an, Character* character, CharStats* st, MedicalSystem* _med, CombatClass* defaultVal);

// Fired by Town::_CONSTRUCTOR hook.
// Lua event name: "onTownConstructed"
// Lua signature:  function(town, data, defaultVal) -> Town
Town* CallTownConstructedCallbacks(Town* thisptr, GameData* d, Town* defaultVal);

// Fired by TownBase::_CONSTRUCTOR hook.
// Lua event name: "onTownBaseConstructed"
// Lua signature:  function(townBase, data, defaultVal) -> TownBase
TownBase* CallTownBaseConstructedCallbacks(TownBase* thisptr, GameData* d, TownBase* defaultVal);

// Fired by FactionLeader::_CONSTRUCTOR hook.
// Lua event name: "onFactionLeaderConstructed"
// Lua signature:  function(factionLeader, faction, defaultVal) -> FactionLeader
FactionLeader* CallFactionLeaderConstructedCallbacks(FactionLeader* thisptr, Faction* f, FactionLeader* defaultVal);

// Fired by FactionRelations::_CONSTRUCTOR hook.
// Lua event name: "onFactionRelationsConstructed"
// Lua signature:  function(factionRelations, defaultVal) -> FactionRelations
FactionRelations* CallFactionRelationsConstructedCallbacks(FactionRelations* thisptr, FactionRelations* defaultVal);

// Fired by FactionUniqueSquadManager::_CONSTRUCTOR hook.
// Lua event name: "onFactionUniqueSquadManagerConstructed"
// Lua signature:  function(factionUniqueSquadManager, defaultVal) -> FactionUniqueSquadManager
FactionUniqueSquadManager* CallFactionUniqueSquadManagerConstructedCallbacks(FactionUniqueSquadManager* thisptr, FactionUniqueSquadManager* defaultVal);

// Fired by ProsperityManager::_CONSTRUCTOR hook.
// Lua event name: "onProsperityManagerConstructed"
// Lua signature:  function(prosperityManager, defaultVal) -> ProsperityManager
ProsperityManager* CallProsperityManagerConstructedCallbacks(ProsperityManager* thisptr, ProsperityManager* defaultVal);

// Fired by InventoryItemBase::_CONSTRUCTOR hook.
// Lua event name: "onInventoryItemBaseConstructed"
// Lua signature:  function(inventoryItemBase, baseData, companyData, materialData, handle, defaultVal) -> InventoryItemBase
InventoryItemBase* CallInventoryItemBaseConstructedCallbacks(InventoryItemBase* thisptr, GameData* baseData, GameData* companyData, GameData* materialData, const hand& _handle, InventoryItemBase* defaultVal);

// Fired by MedicalSystem::_CONSTRUCTOR hook.
// Lua event name: "onMedicalSystemConstructed"
// Lua signature:  function(medicalSystem, character, defaultVal) -> MedicalSystem
MedicalSystem* CallMedicalSystemConstructedCallbacks(MedicalSystem* thisptr, Character* c, MedicalSystem* defaultVal);

// Fired by CombatTechniqueData::_CONSTRUCTOR hook.
// Lua event name: "onCombatTechniqueDataConstructed"
// Lua signature:  function(combatTechniqueData, data, defaultVal) -> CombatTechniqueData
CombatTechniqueData* CallCombatTechniqueDataConstructedCallbacks(CombatTechniqueData* thisptr, GameData* data, CombatTechniqueData* defaultVal);

// Fired by Dialogue::_CONSTRUCTOR hook.
// Lua event name: "onDialogueConstructed"
// Lua signature:  function(dialogue, defaultVal) -> Dialogue
Dialogue* CallDialogueConstructedCallbacks(Dialogue* thisptr, Dialogue* defaultVal);

// Fired by DialogLineData::_CONSTRUCTOR hook.
// Lua event name: "onDialogLineDataConstructed"
// Lua signature:  function(dialogLineData, data, defaultVal) -> DialogLineData
DialogLineData* CallDialogLineDataConstructedCallbacks(DialogLineData* thisptr, GameData* dat, DialogLineData* defaultVal);

// -----------------------------------------------------------
// Callbacks for hooks in Building/UseableStuff.h
// -----------------------------------------------------------

// Fired by UseableStuff::_NV_tryOperate hook.
// Lua event name: "onUseableStuffTryOperate"
// Lua signature:  function(useableStuff, userHandle, success)
void CallUseableStuffTryOperateCallbacks(UseableStuff* thisptr, const hand& h, bool success);

// Fired by UseableStuff::stopOperating hook.
// Lua event name: "onUseableStuffStopOperating"
// Lua signature:  function(useableStuff, userHandle)
void CallUseableStuffStopOperatingCallbacks(UseableStuff* thisptr, const hand& h);

// Fired by UseableStuff::occupantHandleChangedEvent hook.
// Lua event name: "onUseableStuffOccupantChanged"
// Lua signature:  function(useableStuff, newOccupantHandle)
void CallUseableStuffOccupantChangedCallbacks(UseableStuff* thisptr, const hand& h);

// Fired by UseableStuff::_NV_switchPowerOn hook.
// Lua event name: "onUseableStuffPowerSwitched"
// Lua signature:  function(useableStuff, on)
void CallUseableStuffPowerSwitchedCallbacks(UseableStuff* thisptr, bool on);

// Fired by UseableStuff::_NV_givePower hook.
// Lua event name: "onUseableStuffGivePower"
// Lua signature:  function(useableStuff, amount)
void CallUseableStuffGivePowerCallbacks(UseableStuff* thisptr, float amount);

// Fired by UseableStuff::_NV_getCostToUse hook.
// Lua event name: "onUseableStuffGetCostToUse"
// Lua signature:  function(useableStuff, who, defaultVal) -> integer
int CallUseableStuffGetCostToUseCallbacks(UseableStuff* thisptr, Character* who, int defaultVal);

// Fired by UseableStuff::_NV_couldIOperate hook.
// Lua event name: "onUseableStuffCouldIOperate"
// Lua signature:  function(useableStuff, userHandle, defaultVal) -> boolean
bool CallUseableStuffCouldIOperateCallbacks(const UseableStuff* thisptr, const hand& h, bool defaultVal);

// Fired by UseableStuff::_NV_dontNeedWorkRightNow hook.
// Lua event name: "onUseableStuffDontNeedWork"
// Lua signature:  function(useableStuff, defaultVal) -> boolean
bool CallUseableStuffDontNeedWorkCallbacks(const UseableStuff* thisptr, bool defaultVal);

// -----------------------------------------------------------
// Callbacks for hooks in Building/Building.h (Additional)
// -----------------------------------------------------------

// Fired by Building::_NV_notifyConstructionComplete hook.
// Lua event name: "onBuildingNotifyConstructionComplete"
// Lua signature:  function(building)
void CallBuildingNotifyConstructionCompleteCallbacks(Building* thisptr);

// Fired by Building::_NV_addConstructionProgress hook.
// Lua event name: "onBuildingAddConstructionProgress"
// Lua signature:  function(building, amount)
void CallBuildingAddConstructionProgressCallbacks(Building* thisptr, float amount);

// Fired by Building::_NV_setConstructionProgress hook.
// Lua event name: "onBuildingSetConstructionProgress"
// Lua signature:  function(building, amount)
void CallBuildingSetConstructionProgressCallbacks(Building* thisptr, float amount);

// Fired by Building::_NV_addDismantleProgress hook.
// Lua event name: "onBuildingAddDismantleProgress"
// Lua signature:  function(building, amount, defaultVal) -> boolean
bool CallBuildingAddDismantleProgressCallbacks(Building* thisptr, float amount, bool defaultVal);

// Fired by Building::_NV_notifyConstructionDismantling hook.
// Lua event name: "onBuildingNotifyConstructionDismantling"
// Lua signature:  function(building)
void CallBuildingNotifyConstructionDismantlingCallbacks(Building* thisptr);

// Fired by Building::_NV_upgrade hook.
// Lua event name: "onBuildingUpgrade"
// Lua signature:  function(building, line)
void CallBuildingUpgradeCallbacks(Building* thisptr, DataPanelLine* line);

// Fired by Building::_NV_canUpgrade hook.
// Lua event name: "onBuildingCanUpgrade"
// Lua signature:  function(building, defaultVal) -> GameData
GameData* CallBuildingCanUpgradeCallbacks(Building* thisptr, GameData* defaultVal);

// Fired by Building::destroyDoors hook.
// Lua event name: "onBuildingDestroyDoors"
// Lua signature:  function(building)
void CallBuildingDestroyDoorsCallbacks(Building* thisptr);

// Fired by Building::_NV_setFaction hook.
// Lua event name: "onBuildingSetFaction"
// Lua signature:  function(building, faction, activePlatoon)
void CallBuildingSetFactionCallbacks(Building* thisptr, Faction* p, ActivePlatoon* a);

// Fired by Building::setFloorVisibility hook.
// Lua event name: "onBuildingSetFloorVisibility"
// Lua signature:  function(building, floor, isVisible)
void CallBuildingSetFloorVisibilityCallbacks(Building* thisptr, int floor, bool vis);

// Fired by Building::_NV_switchLights hook.
// Lua event name: "onBuildingSwitchLights"
// Lua signature:  function(building, on)
void CallBuildingSwitchLightsCallbacks(Building* thisptr, bool on);

// Fired by Building::_NV_switchEffects hook.
// Lua event name: "onBuildingSwitchEffects"
// Lua signature:  function(building, on)
void CallBuildingSwitchEffectsCallbacks(Building* thisptr, bool on);

// Fired by Building::_NV_notifyEffect hook.
// Lua event name: "onBuildingNotifyEffect"
// Lua signature:  function(building, effectType, weatherType, strength)
void CallBuildingNotifyEffectCallbacks(Building* thisptr, int type, int what, float strength);

// -----------------------------------------------------------
// Callbacks for hooks in Building/WallBuilding.h
// -----------------------------------------------------------

// Fired by WallBuilding::_NV_hitByMeleeAttack hook.
// Lua event name: "onWallBuildingHitByMeleeAttack"
// Lua signature:  function(wallBuilding, cutDir, damage, attacker, attack, comboID)
void CallWallBuildingHitByMeleeAttackCallbacks(WallBuilding* thisptr, int cutDir, Damages* damage, Character* who, CombatTechniqueData* attack, int comboID);

// -----------------------------------------------------------
// Callbacks for hooks in Building/DoorStuff.h
// -----------------------------------------------------------

// Fired by DoorStuff::openDoor hook.
// Lua event name: "onDoorStuffOpenDoor"
// Lua signature:  function(doorStuff, defaultVal) -> boolean
bool CallDoorStuffOpenDoorCallbacks(DoorStuff* thisptr, bool defaultVal);

// Fired by DoorStuff::closeDoor hook.
// Lua event name: "onDoorStuffCloseDoor"
// Lua signature:  function(doorStuff, defaultVal) -> boolean
bool CallDoorStuffCloseDoorCallbacks(DoorStuff* thisptr, bool defaultVal);

// Fired by DoorStuff::lockDoor hook.
// Lua event name: "onDoorStuffLockDoor"
// Lua signature:  function(doorStuff)
void CallDoorStuffLockDoorCallbacks(DoorStuff* thisptr);

// Fired by DoorStuff::unlockDoor hook.
// Lua event name: "onDoorStuffUnlockDoor"
// Lua signature:  function(doorStuff)
void CallDoorStuffUnlockDoorCallbacks(DoorStuff* thisptr);

// Fired by DoorStuff::setDoorState hook.
// Lua event name: "onDoorStuffSetDoorState"
// Lua signature:  function(doorStuff, doorState)
void CallDoorStuffSetDoorStateCallbacks(DoorStuff* thisptr, int doorState);

// Fired by DoorStuff::_NV_hitByMeleeAttack hook.
// Lua event name: "onDoorStuffHitByMeleeAttack"
// Lua signature:  function(doorStuff, cutDir, damage, attacker, attack, comboID)
void CallDoorStuffHitByMeleeAttackCallbacks(DoorStuff* thisptr, int cutDir, Damages* damage, Character* who, CombatTechniqueData* attack, int comboID);

// -----------------------------------------------------------
// Callbacks for hooks in Building/ProductionBuilding.h
// -----------------------------------------------------------

// Fired by ProductionBuilding::_NV_operate hook.
// Lua event name: "onProductionBuildingOperate"
// Lua signature:  function(productionBuilding, worker, amount)
void CallProductionBuildingOperateCallbacks(ProductionBuilding* thisptr, Character* who, float amount);

// -----------------------------------------------------------
// Callbacks for hooks in Building/CraftingBuilding.h
// -----------------------------------------------------------

// Fired by CraftingBuilding::_NV_operate hook.
// Lua event name: "onCraftingBuildingOperate"
// Lua signature:  function(craftingBuilding, worker, amount)
void CallCraftingBuildingOperateCallbacks(CraftingBuilding* thisptr, Character* worker, float amount);

// Fired by CraftingBuilding::_NV_newCraftingButton hook.
// Lua event name: "onCraftingBuildingNewCraftingButton"
// Lua signature:  function(craftingBuilding, sender)
void CallCraftingBuildingNewCraftingButtonCallbacks(CraftingBuilding* thisptr, MyGUI::Widget* sender);

// Fired by CraftingBuilding::addFinishedCraftItem hook.
// Lua event name: "onCraftingBuildingAddFinishedCraftItem"
// Lua signature:  function(craftingBuilding, item)
void CallCraftingBuildingAddFinishedCraftItemCallbacks(CraftingBuilding* thisptr, Item* what);

// Fired by CraftingBuilding::notifyCraftFailiure hook.
// Lua event name: "onCraftingBuildingNotifyCraftFailure"
// Lua signature:  function(craftingBuilding)
void CallCraftingBuildingNotifyCraftFailureCallbacks(CraftingBuilding* thisptr);

// Fired by CraftingBuilding::destroyProductionItem hook.
// Lua event name: "onCraftingBuildingDestroyProductionItem"
// Lua signature:  function(craftingBuilding)
void CallCraftingBuildingDestroyProductionItemCallbacks(CraftingBuilding* thisptr);

// Fired by CraftingBuilding::_removeCraft hook.
// Lua event name: "onCraftingBuildingRemoveCraft"
// Lua signature:  function(craftingBuilding, index)
void CallCraftingBuildingRemoveCraftCallbacks(CraftingBuilding* thisptr, int index);

// -----------------------------------------------------------
// Callbacks for hooks in Building/FurnaceBuilding.h
// -----------------------------------------------------------

// Fired by FurnaceBuilding::_NV_operate hook.
// Lua event name: "onFurnaceBuildingOperate"
// Lua signature:  function(furnaceBuilding, worker, amount)
void CallFurnaceBuildingOperateCallbacks(FurnaceBuilding* thisptr, Character* worker, float amount);

// -----------------------------------------------------------
// Callbacks for hooks in Building/ResearchBuilding.h
// -----------------------------------------------------------

// Fired by ResearchBuilding::_NV_operate hook.
// Lua event name: "onResearchBuildingOperate"
// Lua signature:  function(researchBuilding, worker, amount)
void CallResearchBuildingOperateCallbacks(ResearchBuilding* thisptr, Character* worker, float amount);

// -----------------------------------------------------------
// Callbacks for hooks in Building/FarmBuilding.h
// -----------------------------------------------------------

// Fired by FarmBuilding::_NV_operate hook.
// Lua event name: "onFarmBuildingOperate"
// Lua signature:  function(farmBuilding, worker, amount)
void CallFarmBuildingOperateCallbacks(FarmBuilding* thisptr, Character* who, float amount);

// Fired by FarmBuilding::destroyAPlant hook.
// Lua event name: "onFarmBuildingDestroyAPlant"
// Lua signature:  function(farmBuilding, defaultVal) -> boolean
bool CallFarmBuildingDestroyAPlantCallbacks(FarmBuilding* thisptr, bool defaultVal);

// Fired by FarmBuilding::eat hook.
// Lua event name: "onFarmBuildingEat"
// Lua signature:  function(farmBuilding, rate)
void CallFarmBuildingEatCallbacks(FarmBuilding* thisptr, float rate);

// -----------------------------------------------------------
// Callbacks for hooks in Building/TurretBuilding.h
// -----------------------------------------------------------

// Fired by TurretBuilding::_NV_operate hook.
// Lua event name: "onTurretBuildingOperate"
// Lua signature:  function(turretBuilding, gunner, amount)
void CallTurretBuildingOperateCallbacks(TurretBuilding* thisptr, Character* gunner, float amount);

// Fired by TurretBuilding::aimAt hook.
// Lua event name: "onTurretBuildingAimAt"
// Lua signature:  function(turretBuilding, targetPos)
void CallTurretBuildingAimAtCallbacks(TurretBuilding* thisptr, const Ogre::Vector3& targetPos);

// -----------------------------------------------------------
// Callbacks for hooks in Building/UseableStuff.h (Additional)
// -----------------------------------------------------------

// Fired by UseableStuff::_NV_hitByMeleeAttack hook.
// Lua event name: "onUseableStuffHitByMeleeAttack"
// Lua signature:  function(useableStuff, cutDir, damage, attacker, attack, comboID)
void CallUseableStuffHitByMeleeAttackCallbacks(UseableStuff* thisptr, int cutDir, Damages* damage, Character* who, CombatTechniqueData* attack, int comboID);

// Fired by UseableStuff::takePowerFrom hook.
// Lua event name: "onUseableStuffTakePowerFrom"
// Lua signature:  function(useableStuff, amount, frameTime, defaultVal) -> number
float CallUseableStuffTakePowerFromCallbacks(UseableStuff* thisptr, float amount, float frameTime, float defaultVal);

// Fired by UseableStuff::_NV_togglePowerButton hook.
// Lua event name: "onUseableStuffTogglePowerButton"
// Lua signature:  function(useableStuff, line)
void CallUseableStuffTogglePowerButtonCallbacks(UseableStuff* thisptr, DataPanelLine* line);

// Fired by UseableStuff::_NV_toggleBattButton hook.
// Lua event name: "onUseableStuffToggleBattButton"
// Lua signature:  function(useableStuff, line)
void CallUseableStuffToggleBattButtonCallbacks(UseableStuff* thisptr, DataPanelLine* line);

// -----------------------------------------------------------
// Callbacks for hooks in PreviewBuilding
// -----------------------------------------------------------

// Fired by PreviewBuilding::_NV_placeFinalPreviewBuilding hook.
// Lua event name: "onPreviewBuildingPlaceFinalPreviewBuilding"
// Lua signature:  function(previewBuilding)
void CallPreviewBuildingPlaceFinalPreviewBuildingCallbacks(PreviewBuilding* thisptr);

// Fired by PreviewBuilding::_NV_placementVerification hook.
// Lua event name: "onPreviewBuildingPlacementVerification"
// Lua signature:  function(previewBuilding, defaultVal) -> boolean
bool CallPreviewBuildingPlacementVerificationCallbacks(PreviewBuilding* thisptr, bool defaultVal);

// Fired by PreviewBuilding::_NV_placePreview hook.
// Lua event name: "onPreviewBuildingPlacePreview"
// Lua signature:  function(previewBuilding, position, rotation, floorNumber)
void CallPreviewBuildingPlacePreviewCallbacks(PreviewBuilding* thisptr, const Ogre::Vector3& position, const Ogre::Quaternion& rotation, int floorNumber);

