#pragma once

#include <string>
#include <kenshi/Character.h>

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
class InventoryLayout;
class BuildModeWindow;
class SquadManagementScreen;
class ManagementScreen;
class TitleScreen;
class MedicalSystem;
class GameDataContainer;
class GameSaveState;
class GameDataCopyStandalone;
class Town;
class OrdersPanel;
class ContextMenu;
class ContextMenuGUI;
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
class AppearanceManager;
class CombatMovementController;
class WorldEventStateQuery;
class GenericFixedInventoryLayout;
class RootObjectFactory;
class FactionManager;
class FactionWarMgr;
class ZoneMap;
class ZoneManager;
class LimbsInventoryLayout;
class RobotLimbs;
class ShopTrader;
class RootObjectBase;
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
// Lua event name: "InputHandler::keyDownEvent"
// Lua signature:  function(self, keyCode)
// keyCode is the raw OIS::KeyCode cast to int.
void CallKeyDownCallbacks(InputHandler* thisptr, int keyCode);

// -----------------------------------------------------------
// Callbacks for hooks in GameWorld.h
// -----------------------------------------------------------

// Fired by GameWorld::charsUpdate hook.
// Lua event name: "GameWorld::charsUpdate"
// Lua signature:  function(self)
void CallCharsUpdateCallbacks(GameWorld* thisptr);

// -----------------------------------------------------------
// Callbacks for hooks in Character.h
// -----------------------------------------------------------

// Fired by Character::declareDead hook.
// Lua event name: "Character::declareDead"
// Lua signature:  function(self)
void CallCharacterDeclareDeadCallbacks(Character* character);

// Fired by Character::_NV_select hook.
// Lua event name: "Character::_NV_select"
// Lua signature:  function(self)
void CallCharacterSelectCallbacks(Character* character);

// Fired by Character::_NV_unselect hook.
// Lua event name: "Character::_NV_unselect"
// Lua signature:  function(self)
void CallCharacterUnselectCallbacks(Character* character);

// Fired by Character::_NV_say hook.
// Lua event name: "Character::_NV_say"
// Lua signature:  function(self, message)
// Returning false from the handler suppresses remaining handlers.
void CallCharacterSayCallbacks(Character* character, const std::string& message);

// Fired by Character::pickupObject hook.
// Lua event name: "Character::pickupObject"
// Lua signature:  function(self, who)
void CallCharacterPickupObjectCallbacks(Character* character, Character* who);

// Fired by Character::getPickedUp hook.
// Lua event name: "Character::getPickedUp"
// Lua signature:  function(self, byWhom)
void CallCharacterGetPickedUpCallbacks(Character* character, Character* byWhom);

// Fired by Character::_NV_takeMoney hook.
// Lua event name: "Character::_NV_takeMoney"
// Lua signature:  function(self, amount)
void CallCharacterTakeMoneyCallbacks(Character* character, int amount);

// Fired by Character::eatItem hook.
// Lua event name: "Character::eatItem"
// Lua signature:  function(self, foodItem, inventory)
void CallCharacterEatCallbacks(Character* character, Item* food, Inventory* from);

// Fired by Character::_NV_hitByMeleeAttack hook.
// Lua event name: "Character::_NV_hitByMeleeAttack"
// Lua signature:  function(self, cutDir, damage, attacker, attack, comboID)
void CallCharacterHitByMeleeCallbacks(Character* character, int cutDir, Damages* damage, Character* attacker, CombatTechniqueData* attack, int comboID);

// Fired by Character::_NV_gettingEaten hook.
// Lua event name: "Character::_NV_gettingEaten"
// Lua signature:  function(self, amount, eater)
void CallCharacterGettingEatenCallbacks(Character* character, float amount, Character* eater);

// Fired by Character::_NV_setStandingOrder hook.
// Lua event name: "Character::_NV_setStandingOrder"
// Lua signature:  function(self, orderID, enabled)
void CallCharacterStandingOrderChangedCallbacks(Character* character, int orderID, bool on);

// Fired by Character::_NV_setFaction hook.
// Lua event name: "Character::_NV_setFaction"
// Lua signature:  function(self, faction, platoon)
void CallCharacterFactionChangedCallbacks(Character* character, Faction* faction, ActivePlatoon* platoon);

// Fired by Character::_NV_equipItem hook.
// Lua event name: "Character::_NV_equipItem"
// Lua signature:  function(self, sectionName, item)
void CallCharacterEquipCallbacks(Character* character, const std::string& sectionName, Item* item);

// Fired by Character::_NV_unequipItem hook.
// Lua event name: "Character::_NV_unequipItem"
// Lua signature:  function(self, sectionName, item)
void CallCharacterUnequipCallbacks(Character* character, const std::string& sectionName, Item* item);

// Fired by Character::_NV_ImStealingDoYouNotice hook.
// Lua event name: "Character::_NV_ImStealingDoYouNotice"
// Lua signature:  function(self, stealFrom, item)
void CallCharacterStealNoticeCallbacks(Character* character, RootObject* stealFrom, Item* item);

// Fired by Character::_NV_smugglingTradeCheck hook.
// Lua event name: "Character::_NV_smugglingTradeCheck"
// Lua signature:  function(self, item, who)
void CallCharacterSmugglingCheckCallbacks(Character* character, Item* item, Character* who);

// Fired by Character::_NV_init hook
// Lua event name: "Character::_NV_init"
// Lua signature:  function(self)
void CallCharacterInitCallbacks(Character* character);

// Fired by Character::_NV_isItOkForMeToLoot hook
// Lua event name: "Character::_NV_isItOkForMeToLoot"
// Lua signature:  function(self, victim, item, defaultVal) -> boolean
bool CallCharacterIsItOkForMeToLootCallbacks(Character* me, RootObject* victim, Item* item, bool defaultVal);

// Fired by Character::getFencingSuccessChance hook
// Lua event name: "Character::getFencingSuccessChance"
// Lua signature:  function(self, item, thief, defaultVal) -> number
float CallCharacterGetFencingSuccessChanceCallbacks(Character* merchant, Item* item, RootObject* thief, float defaultVal);

// -----------------------------------------------------------
// Callbacks for hooks in CharStats.h
// -----------------------------------------------------------

// Fired by CharStats::setHoldLocation hook.
// Lua event name: "CharStats::setHoldLocation"
// Lua signature:  function(self, vector3Table)
void CallCharStatsSetHoldLocationCallbacks(CharStats* stats, const Ogre::Vector3& v);

// Fired by CharStats::clearHoldLocation hook.
// Lua event name: "CharStats::clearHoldLocation"
// Lua signature:  function(self)
void CallCharStatsClearHoldLocationCallbacks(CharStats* stats);

// Fired by CharStats::chooseAttack hook.
// Lua event name: "CharStats::chooseAttack"
// Lua signature:  function(self, range, weaponReach, lastAttack, opponentIsStationary, defaultAttack) -> CombatTechniqueData
CombatTechniqueData* CallCharStatsChooseAttackCallbacks(CharStats* stats, float range, float weaponReach, CombatTechniqueData* lastAttack, bool opponentIsStationary, CombatTechniqueData* defaultVal);

// Fired by CharStats::xpRunning hook.
// Lua event name: "CharStats::xpRunning"
// Lua signature:  function(self, time, speed)
void CallCharStatsXpRunningCallbacks(CharStats* stats, float time, float speed);

// Fired by CharStats::xpFirstAid hook.
// Lua event name: "CharStats::xpFirstAid"
// Lua signature:  function(self, patient, time, medicStat)
void CallCharStatsXpFirstAidCallbacks(CharStats* stats, Character* patient, float time, int medicStat);

// Fired by CharStats::xpStealth hook.
// Lua event name: "CharStats::xpStealth"
// Lua signature:  function(self, time, enemiesAbout, seen, isMoving)
void CallCharStatsXpStealthCallbacks(CharStats* stats, float time, bool enemiesAbout, YesNoMaybe seen, bool isMoving);

// Fired by CharStats::xpToughness_GetUpEvent hook.
// Lua event name: "CharStats::xpToughness_GetUpEvent"
// Lua signature:  function(self)
void CallCharStatsXpToughness_GetUpEventCallbacks(CharStats* stats);

// Fired by CharStats::xpToughness_RagdollEvent hook.
// Lua event name: "CharStats::xpToughness_RagdollEvent"
// Lua signature:  function(self)
void CallCharStatsXpToughness_RagdollEventCallbacks(CharStats* stats);

// Fired by CharStats::xpToughness_PunchSomething hook.
// Lua event name: "CharStats::xpToughness_PunchSomething"
// Lua signature:  function(self, mat)
void CallCharStatsXpToughness_PunchSomethingCallbacks(CharStats* stats, int mat);

// Fired by CharStats::xpEngineering hook.
// Lua event name: "CharStats::xpEngineering"
// Lua signature:  function(self, time)
void CallCharStatsXpEngineeringCallbacks(CharStats* stats, float time);

// Fired by CharStats::xpLockpicking hook.
// Lua event name: "CharStats::xpLockpicking"
// Lua signature:  function(self, lockLevel, success)
void CallCharStatsXpLockpickingCallbacks(CharStats* stats, int lockLevel, bool success);

// Fired by CharStats::getStat hook
// Lua event name: "CharStats::getStat"
// Lua signature:  function(self, statType, unmodified, defaultVal) -> number
float CallCharStatsGetStatCallbacks(const CharStats* stats, int what, bool unmodified, float defaultVal);

// -----------------------------------------------------------
// Callbacks for hooks in PlayerInterface.h
// -----------------------------------------------------------

// Fired by PlayerInterface::recruit hook.
// Lua event name: "PlayerInterface::recruit"
// Lua signature:  function(self, character, isEditor)
void CallPlayerRecruitCallbacks(PlayerInterface* player, Character* character, bool editor);

// Fired by PlayerInterface::selectObject hook.
// Lua event name: "PlayerInterface::selectObject"
// Lua signature:  function(self, obj, modifier)
void CallPlayerSelectCallbacks(PlayerInterface* player, RootObject* obj, bool modifier);

// Fired by PlayerInterface::newPlayerTaskSelectedCharacters hook.
// Lua event name: "PlayerInterface::newPlayerTaskSelectedCharacters"
// Lua signature:  function(self, taskType, targetHandle, destinationBuilding, clickPos, queueOrder)
void CallPlayerOrderGivenCallbacks(PlayerInterface* player, int taskType, const hand& targetH, Building* destinationIndoors, const Ogre::Vector3& clickpos, bool addDontClear);

// -----------------------------------------------------------
// Callbacks for hooks in Platoon.h
// -----------------------------------------------------------

// Fired by ActivePlatoon::_NV_addActiveObject hook.
// Lua event name: "ActivePlatoon::_NV_addActiveObject"
// Lua signature:  function(self, character)
void CallPlatoonMemberAddedCallbacks(ActivePlatoon* platoon, RootObject* c);

// Fired by ActivePlatoon::_NV_removeObject hook.
// Lua event name: "ActivePlatoon::_NV_removeObject"
// Lua signature:  function(self, character)
void CallPlatoonMemberRemovedCallbacks(ActivePlatoon* platoon, RootObject* c);

// Fired by Platoon::taskIsComplete hook.
// Lua event name: "Platoon::taskIsComplete"
// Lua signature:  function(self, completedTask)
void CallPlatoonTaskCompleteCallbacks(Platoon* platoon, Tasker* t);

// Fired by Platoon::iBuyStolenGoods hook
// Lua event name: "Platoon::iBuyStolenGoods"
// Lua signature:  function(self, item, defaultVal) -> boolean
bool CallPlatoonIBuyStolenGoodsCallbacks(Platoon* platoon, Item* what, bool defaultVal);

// Fired by Platoon::iBuyIllegalGoods hook
// Lua event name: "Platoon::iBuyIllegalGoods"
// Lua signature:  function(self, defaultVal) -> boolean
bool CallPlatoonIBuyIllegalGoodsCallbacks(Platoon* platoon, bool defaultVal);

// Fired by Ownerships::canIUseThisBuilding hook
// Lua event name: "Ownerships::canIUseThisBuilding"
// Lua signature:  function(self, building, character, defaultVal) -> boolean
bool CallOwnershipsCanIUseThisBuildingCallbacks(Ownerships* ownerships, Building* b, Character* me, bool defaultVal);

// -----------------------------------------------------------
// Callbacks for hooks in Item.h
// -----------------------------------------------------------

// Fired by Item::_NV_notifyTheftFrom hook.
// Lua event name: "Item::_NV_notifyTheftFrom"
// Lua signature:  function(self, victim)
void CallItemStolenCallbacks(Item* item, RootObject* obj);

// -----------------------------------------------------------
// Callbacks for hooks in Inventory.h / InventoryItemBase.h
// -----------------------------------------------------------

// Fired by Inventory::getSectionOfType hook
// Lua event name: "Inventory::getSectionOfType"
// Lua signature:  function(self, type) -> InventorySection
InventorySection* CallInventoryGetSectionOfTypeCallbacks(Inventory* inventory, int type);

// Fired by Inventory::getBestFoodItem hook
// Lua event name: "Inventory::getBestFoodItem"
// Lua signature:  function(self, race) -> Item
Item* CallInventoryGetBestFoodItemCallbacks(Inventory* inventory, Character* race);

// Fired by Inventory::getBaseValueSingle hook
// Lua event name: "InventoryItemBase::getValueSingle"
// Lua signature:  function(self, isPlayer, defaultVal) -> integer
int CallInventoryItemBaseGetValueSingleCallbacks(const InventoryItemBase* item, bool isPlayer, int defaultVal);

// -----------------------------------------------------------
// Callbacks for hooks in BountyManager.h
// -----------------------------------------------------------

// Fired by BountyManager::notifyCrimeWitnessed hook.
// Lua event name: "BountyManager::notifyCrimeWitnessed"
// Lua signature:  function(self, faction, againstWho, expiryTime, crimeType)
void CallCrimeWitnessedCallbacks(BountyManager* bountyMgr, Faction* against, const hand& againstWho, int expiryTime, int crimeType);

// -----------------------------------------------------------
// Callbacks for hooks in FactionRelations.h
// -----------------------------------------------------------

// Fired by FactionRelations::affectRelations hook.
// Lua event name: "FactionRelations::affectRelations"
// Lua signature:  function(self, otherFaction, eventType, multiplier)
void CallFactionRelationsAffectedCallbacks(FactionRelations* factionRelations, Faction* other, int eventType, float multiplier);

// -----------------------------------------------------------
// Callbacks for hooks in Faction.h
// -----------------------------------------------------------

// Fired by Faction::chooseARace hook
// Lua event name: "Faction::chooseARace"
// Lua signature:  function(self, character, squadTemplate, defaultVal) -> GameData
GameData* CallFactionChooseARaceCallbacks(Faction* faction, GameData* character, GameData* squadTemplate, GameData* defaultVal);

// Fired by Faction::getBuildingReplacement hook
// Lua event name: "Faction::getBuildingReplacement"
// Lua signature:  function(self, building, defaultVal) -> GameData
GameData* CallFactionGetBuildingReplacementCallbacks(Faction* faction, GameData* building, GameData* defaultVal);

// -----------------------------------------------------------
// Callbacks for hooks in MedicalSystem.h
// -----------------------------------------------------------

// Fired by MedicalSystem::amputate hook.
// Lua event name: "MedicalSystem::amputate"
// Lua signature:  function(self, limb, createSeveredItem, forceVector)
void CallLimbAmputatedCallbacks(MedicalSystem* med, int limb, bool createSeveredItem, const Ogre::Vector3& force);

// -----------------------------------------------------------
// Callbacks for hooks in gui/DialogueWindow.h
// -----------------------------------------------------------

// Fired by DialogueWindow::show hook.
// Lua event name: "DialogueWindow::show"
// Lua signature:  function(self, dialogue)
void CallDialogueWindowShowCallbacks(DialogueWindow* thisptr, Dialogue* dialogue);

// -----------------------------------------------------------
// Callbacks for hooks in Dialogue.h
// -----------------------------------------------------------

// Fired by Dialogue::_doActions hook.
// Lua event name: "Dialogue::_doActions"
// Lua signature:  function(self, dialogLine)
void CallDialogueDoActionsCallbacks(Dialogue* thisptr, DialogLineData* dialogLine);

// Fired by Dialogue::say hook.
// Lua event name: "Dialogue::say"
// Lua signature:  function(self, dialogLine)
void CallDialogueSayCallbacks(Dialogue* thisptr, DialogLineData* dialogLine);

// Fired by Dialogue::endDialogue hook.
// Lua event name: "Dialogue::endDialogue"
// Lua signature:  function(self, definitelyTheEnd)
void CallDialogueEndDialogueCallbacks(Dialogue* dialogue, bool definitelyTheEnd);

// Fired by Dialogue::_checkCondition hook.
// Lua event name: "Dialogue::_checkCondition"
// Lua signature:  function(self, conditionName, compareBy, val, target, actualConversationTarget, defaultVal) -> boolean
bool CallDialogueCheckConditionCallbacks(Dialogue* dialogue, DialogConditionEnum conditionName, ComparisonEnum compareBy, int val, Character* target, Character* actualConversationTarget, bool defaultVal);

// Fired by Dialogue::startConversation hook.
// Lua event name: "Dialogue::startConversation"
// Lua signature:  function(self, target, talk, ev, force, defaultVal) -> boolean
bool CallDialogueStartConversationCallbacks(Dialogue* dialogue, Character* target, DialogLineData* talk, EventTriggerEnum ev, bool force, bool defaultVal);

// Fired by Dialogue::_endPlayerConversation hook.
// Lua event name: "Dialogue::_endPlayerConversation"
// Lua signature:  function(self, finished)
void CallDialogueEndPlayerConversationCallbacks(Dialogue* dialogue, bool finished);

// Fired by Dialogue::startPlayerConversation hook.
// Lua event name: "Dialogue::startPlayerConversation"
// Lua signature:  function(self, target, talk, defaultVal) -> boolean
bool CallDialogueStartPlayerConversationCallbacks(Dialogue* dialogue, Character* target, DialogLineData* talk, bool defaultVal);

// Fired by Dialogue::sendEvent hook.
// Lua event name: "Dialogue::sendEvent"
// Lua signature:  function(self, who, what, defaultVal) -> boolean
bool CallDialogueSendEventCallbacks(Dialogue* dialogue, Character* who, EventTriggerEnum what, bool defaultVal);

// Fired by Dialogue::stopEvent hook.
// Lua event name: "Dialogue::stopEvent"
// Lua signature:  function(self, what)
void CallDialogueStopEventCallbacks(Dialogue* dialogue, EventTriggerEnum what);

// -----------------------------------------------------------
// Callbacks for hooks in RootObjectFactory.h
// -----------------------------------------------------------

// Fired by RootObjectFactory::chooseMyClothing hook
// Lua event name: "RootObjectFactory::chooseMyClothing"
// Lua signature:  function(gearLektor, dataList, listName, race, noShoes)
void CallChooseMyClothingCallbacks(lektor<GameData*>& gear, GameData* dataList, const std::string& listName, RaceData* race, bool noShoes);

// -----------------------------------------------------------
// Callbacks for hooks in mygui/common/baselayout/BaseLayout.h
// -----------------------------------------------------------

// Fired by wraps::BaseLayout::initialise hook
// Lua event name: "wraps::BaseLayout::initialise"
// Lua signature:  function(self, layoutName)
void CallBaseLayoutInitialiseCallbacks(wraps::BaseLayout* thisptr, const std::string& layout);

// -----------------------------------------------------------
// Callbacks for hooks in Building/Building.h
// -----------------------------------------------------------

// Fired by Building::_NV_isPublic hook
// Lua event name: "Building::_NV_isPublic"
// Lua signature:  function(self, defaultVal) -> boolean
bool CallBuildingIsPublicCallbacks(const Building* b, bool defaultVal);

// Fired by Building::_NV_isForSale hook
// Lua event name: "Building::_NV_isForSale"
// Lua signature:  function(self, defaultVal) -> boolean
bool CallBuildingIsForSaleCallbacks(Building* b, bool defaultVal);

// Fired by Building::calculateSaleValue hook
// Lua event name: "Building::calculateSaleValue"
// Lua signature:  function(self, defaultVal) -> integer
int CallBuildingCalculateSaleValueCallbacks(Building* b, int defaultVal);

//---------------------------------------------------------
// Callbacks for hooks in CharMovement.h
//---------------------------------------------------------

// Fired by CharMovement::isRunning hook
// Lua event name: "CharMovement::isRunning"
// Lua signature:  function(self, defaultVal) -> boolean
bool CallCharMovementIsRunningCallbacks(CharMovement* thisptr, bool defaultVal);

// Fired by CharMovement::isRunningAway hook
// Lua event name: "CharMovement::isRunningAway"
// Lua signature:  function(self, from, defaultVal) -> boolean
bool CallCharMovementIsRunningAwayCallbacks(CharMovement* thisptr, const Ogre::Vector3& from, bool defaultVal);

// Fired by CharStats::xpStat_eventBased hook
// Lua event name: "CharStats::xpStat_eventBased"
// Lua signature:  function(self, statType, amount)
void CallCharStatsXpStatEventBasedCallbacks(CharStats* stats, int stat, float amount);

// Fired by CharStats::xpDodgeEvent hook
// Lua event name: "CharStats::xpDodgeEvent"
// Lua signature:  function(self, enemySkill, successful)
void CallCharStatsXpDodgeEventCallbacks(CharStats* stats, float enemySkill, bool successful);

// Fired by PlayerInterface::activateCharacterEditMode hook
// Lua event name: "PlayerInterface::activateCharacterEditMode"
// Lua signature:  function(self, character)
void CallPlayerActivateCharacterEditModeCallbacks(PlayerInterface* player, Character* character);

// Fired by PlayerInterface::createSquad hook
// Lua event name: "PlayerInterface::createSquad"
// Lua signature:  function(self, newSquad)
void CallPlayerCreateSquadCallbacks(PlayerInterface* player, ActivePlatoon* newSquad);

// Fired by Building::setResidentSquad hook
// Lua event name: "Building::setResidentSquad"
// Lua signature:  function(self, platoon)
void CallBuildingSetResidentSquadCallbacks(Building* building, Platoon* who);

// Fired by Building::addAnInternalBuilding hook
// Lua event name: "Building::addAnInternalBuilding"
// Lua signature:  function(self, internalBuilding)
void CallBuildingAddInternalBuildingCallbacks(Building* building, Building* b);

// Fired by InventoryGUI::addTradePartner hook
// Lua event name: "InventoryGUI::addTradePartner"
// Lua signature:  function(self, payment, canDrop, isPlayer, whoHand)
void CallInventoryAddTradePartnerCallbacks(InventoryGUI* tradeWith, bool payment, bool canDrop, bool isPlayer, const hand& who);

// Fired by BuildModeWindow::confirm hook
// Lua event name: "BuildModeWindow::confirm"
// Lua signature:  function(self, widget)
void CallBuildModeWindowConfirmCallbacks(BuildModeWindow* window, MyGUI::Widget* sender);

// Fired by SquadManagementScreen::removeSquad hook
// Lua event name: "SquadManagementScreen::removeSquad"
// Lua signature:  function(self, squadData)
void CallSquadManagementScreenRemoveSquadCallbacks(SquadManagementScreen* screen, void* squadData);

// Fired by ManagementScreen::addMessage hook
// Lua event name: "ManagementScreen::addMessage"
// Lua signature:  function(self, owner, message, logColor)
void CallManagementScreenAddMessageCallbacks(ManagementScreen* screen, const std::string& owner, const std::string& message, int logColor);

// Fired by TitleScreen::loadGame hook
// Lua event name: "TitleScreen::loadGame"
// Lua signature:  function(self, widget)
void CallTitleScreenLoadGameCallbacks(TitleScreen* titleScreen, MyGUI::Widget* sender);

// Fired by Character::addGoal hook
// Lua event name: "Character::addGoal"
// Lua signature:  function(self, taskType, subject)
void CallCharacterAddGoalCallbacks(Character* character, int task, RootObject* subject);

// Fired by Character::addJob hook
// Lua event name: "Character::addJob"
// Lua signature:  function(self, taskType, subject, shift, addDontClear, location)
void CallCharacterAddJobCallbacks(Character* character, int task, RootObject* subject, bool shift, bool addDontClear, const Ogre::Vector3& location);

// Fired by Character::addOrder hook
// Lua event name: "Character::addOrder"
// Lua signature:  function(self, destBuilding, taskType, subject, shift, clear, location)
void CallCharacterAddOrderCallbacks(Character* character, Building* dest, int task, RootObject* subject, bool shift, bool clear, const Ogre::Vector3& location);

// Fired by Character::removeJob hook
// Lua event name: "Character::removeJob"
// Lua signature:  function(self, taskType)
void CallCharacterRemoveJobCallbacks(Character* character, int task);

// Fired by PlayerInterface::addJobSelectedCharacters hook
// Lua event name: "PlayerInterface::addJobSelectedCharacters"
// Lua signature:  function(self, taskType, subject, shift, add, location)
void CallPlayerInterfaceAddJobSelectedCharactersCallbacks(PlayerInterface* player, int task, RootObject* subject, bool shift, bool add, const Ogre::Vector3& location);

// Fired by PlayerInterface::addOrderSelectedCharacters hook
// Lua event name: "PlayerInterface::addOrderSelectedCharacters"
// Lua signature:  function(self, destinationIndoors, taskType, subject, shift, addDontClear, location)
void CallPlayerInterfaceAddOrderSelectedCharactersCallbacks(PlayerInterface* player, Building* destinationIndoors, int task, RootObject* subject, bool shift, bool addDontClear, const Ogre::Vector3& location);

// Fired by MedicalSystem::knockout hook
// Lua event name: "MedicalSystem::knockout"
// Lua signature:  function(self, skill)
void CallMedicalSystemKnockoutCallbacks(MedicalSystem* med, float skill);

// Fired by MedicalSystem::canGetUpWakeUp hook
// Lua event name: "MedicalSystem::canGetUpWakeUp"
// Lua signature:  function(self, defaultVal) -> boolean
bool CallMedicalSystemCanGetUpWakeUpCallbacks(MedicalSystem* med, bool defaultVal = true);

// Fired by Inventory::addItem hook
// Lua event name: "Inventory::_NV_addItem"
// Lua signature:  function(self, item, quantity, dropOnFail, destroyOnFail) -> boolean
bool CallInventoryAddItemCallbacks(Inventory* inv, Item* item, int quantity, bool dropOnFail, bool destroyOnFail);

// Fired by Inventory::removeItemDontDestroy_returnsItem hook
// Lua event name: "Inventory::_NV_removeItemDontDestroy_returnsItem"
// Lua signature:  function(self, item, howmany, returnCopyIfSomeLeft) -> Item
Item* CallInventoryRemoveItemCallbacks(Inventory* inv, Item* item, int howmany, bool returnCopyIfSomeLeft);

// Fired by Inventory::buyItem hook
// Lua event name: "Inventory::buyItem"
// Lua signature:  function(self, item, sendingTo) -> Item
Item* CallInventoryBuyItemCallbacks(Inventory* inv, Item* item, RootObject* sender);

// Fired by Faction::createNewEmptyActivePlatoon hook
// Lua event name: "Faction::createNewEmptyActivePlatoon"
// Lua signature:  function(self, platoon)
void CallFactionActivePlatoonCreatedCallbacks(Faction* faction, Platoon* platoon);

// Fired by Faction::destroyPlatoon hook
// Lua event name: "Faction::destroyPlatoon"
// Lua signature:  function(self, platoon)
void CallFactionPlatoonDestroyedCallbacks(Faction* faction, Platoon* platoon);

// Fired by PlayerInterface::encounterFaction hook
// Lua event name: "PlayerInterface::encounterFaction"
// Lua signature:  function(self, faction)
void CallPlayerEncounterFactionCallbacks(PlayerInterface* player, Faction* faction);

// Fired by Character::changeSlaveOwner hook
// Lua event name: "Character::changeSlaveOwner"
// Lua signature:  function(self, newOwnerHandle)
void CallCharacterSlaveOwnerChangedCallbacks(Character* slave, const hand& newOwner);

// Fired by Character::setChainedMode hook
// Lua event name: "Character::setChainedMode"
// Lua signature:  function(self, on, ownerHandle)
void CallCharacterChainedModeChangedCallbacks(Character* character, bool on, const hand& owner);

// Fired by Building::onBuildingLoaded hook
// Lua event name: "Building::_NV_onBuildingLoaded"
// Lua signature:  function(self)
void CallBuildingLoadedCallbacks(Building* building);

// Fired by Building::setBroken hook
// Lua event name: "Building::_NV_setBroken"
// Lua signature:  function(self, broken)
void CallBuildingBrokenChangedCallbacks(Building* building, bool broken);

// -----------------------------------------------------------
// Callbacks for Serialization
// -----------------------------------------------------------

// Fired by PlayerInterface::serialise hook.
// Lua event name: "PlayerInterface::serialise"
// Lua signature:  function(self, gameData)
void CallPlayerInterfaceSerialiseCallbacks(PlayerInterface* player, GameData* data);

// Fired by PlayerInterface::loadFromSerialise hook.
// Lua event name: "PlayerInterface::loadFromSerialise"
// Lua signature:  function(self, gameData)
void CallPlayerInterfaceLoadFromSerialiseCallbacks(PlayerInterface* player, GameData* data);

// Fired by Character::_NV_serialise hook.
// Lua event name: "Character::_NV_serialise"
// Lua signature:  function(self, container, refList)
void CallCharacterSerialiseCallbacks(Character* character, GameDataContainer* container, GameData* refList);

// Fired by Character::_NV_loadFromSerialise hook.
// Lua event name: "Character::_NV_loadFromSerialise"
// Lua signature:  function(self, saveState)
void CallCharacterLoadFromSerialiseCallbacks(Character* character, GameSaveState* state);

// Fired by Character::_NV_loadFromSerialisePostCreationStage hook.
// Lua event name: "Character::_NV_loadFromSerialisePostCreationStage"
// Lua signature:  function(self, saveState)
void CallCharacterLoadFromSerialisePostCreationStageCallbacks(Character* character, GameSaveState* state);

// Fired by Building::_NV_serialise hook.
// Lua event name: "Building::_NV_serialise"
// Lua signature:  function(self, container, refList)
void CallBuildingSerialiseCallbacks(Building* building, GameDataContainer* container, GameData* refList);

// Fired by Building::_NV_loadFromSerialise hook.
// Lua event name: "Building::_NV_loadFromSerialise"
// Lua signature:  function(self, saveState)
void CallBuildingLoadFromSerialiseCallbacks(Building* building, GameSaveState* state);

// Fired by Platoon::_NV_loadFromSerialise hook.
// Lua event name: "Platoon::_NV_loadFromSerialise"
// Lua signature:  function(self, saveState)
void CallPlatoonLoadFromSerialiseCallbacks(Platoon* platoon, GameSaveState* state);

// Fired by Town::_NV_loadFromSerialise hook.
// Lua event name: "Town::_NV_loadFromSerialise"
// Lua signature:  function(self, saveState)
void CallTownLoadFromSerialiseCallbacks(Town* town, GameSaveState* state);

// Fired by Building::_NV_buyMeCallback hook.
// Lua event name: "Building::_NV_buyMeCallback"
// Lua signature:  function(self, result)
void CallBuildingBuyMeCallbackCallbacks(Building* building, int result);

// Fired by DataPanelLine_Button::pressCallback hook.
// Lua event name: "DataPanelLine_Button::pressCallback"
// Lua signature:  function(self, sender)
void CallDataPanelLineButtonPressCallbacks(DataPanelLine_Button* button, MyGUI::Widget* sender);

// Fired by InventoryGUI::fencingConfirmationCallback hook.
// Lua event name: "InventoryGUI::fencingConfirmationCallback"
// Lua signature:  function(self, b)
void CallInventoryGUIFencingConfirmationCallbacks(InventoryGUI* gui, int b);

// Fired by OrdersPanel::blockmodeButton hook.
// Lua event name: "OrdersPanel::blockmodeButton"
// Lua signature:  function(self, sender)
void CallOrdersPanelBlockModeButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender);

// Fired by OrdersPanel::holdButtonCallback hook.
// Lua event name: "OrdersPanel::holdButtonCallback"
// Lua signature:  function(self, sender)
void CallOrdersPanelHoldButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender);

// Fired by OrdersPanel::passiveButtonCallback hook.
// Lua event name: "OrdersPanel::passiveButtonCallback"
// Lua signature:  function(self, sender)
void CallOrdersPanelPassiveButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender);

// Fired by OrdersPanel::chaseButtonCallback hook.
// Lua event name: "OrdersPanel::chaseButtonCallback"
// Lua signature:  function(self, sender)
void CallOrdersPanelChaseButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender);

// Fired by OrdersPanel::tauntButtonCallback hook.
// Lua event name: "OrdersPanel::tauntButtonCallback"
// Lua signature:  function(self, sender)
void CallOrdersPanelTauntButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender);

// Fired by OrdersPanel::medicButton hook.
// Lua event name: "OrdersPanel::medicButton"
// Lua signature:  function(self, sender)
void CallOrdersPanelMedicButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender);

// Fired by OrdersPanel::liftButton hook.
// Lua event name: "OrdersPanel::liftButton"
// Lua signature:  function(self, sender)
void CallOrdersPanelLiftButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender);

// Fired by OrdersPanel::prospectingButton hook.
// Lua event name: "OrdersPanel::prospectingButton"
// Lua signature:  function(self, sender)
void CallOrdersPanelProspectingButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender);

// Fired by ContextMenu::showContextMenu hook, after the original call returns.
// `on` and `what` are the original arguments: the requested visibility and the target, which can be nil.
// Lua event name: "ContextMenu::showContextMenu"
// Lua signature:  function(self, on, what)
void CallContextMenuShowContextMenuCallbacks(ContextMenu* menu, bool on, RootObject* what);

// Fired by ContextMenuGUI::show hook, after the original call returns.
// ordersList is borrowed from the engine and valid only during the callback; do not modify it.
// Lua event name: "ContextMenuGUI::show"
// Lua signature:  function(self, ordersList, name, offset)
void CallContextMenuGUIShowCallbacks(ContextMenuGUI* menuGUI, const lektor<int>& ordersList, const std::string& name, bool offset);

// Fired by Inventory::_NV__sectionAddItemCallback hook.
// Lua event name: "Inventory::_NV__sectionAddItemCallback"
// Lua signature:  function(self, item)
void CallInventorySectionAddItemCallbacks(Inventory* inventory, Item* item);

// Fired by Inventory::_NV__sectionRemoveItemCallback hook.
// Lua event name: "Inventory::_NV__sectionRemoveItemCallback"
// Lua signature:  function(self, item)
void CallInventorySectionRemoveItemCallbacks(Inventory* inventory, Item* item);

// Fired by Inventory::_NV__sectionUpdateItemCallback hook.
// Lua event name: "Inventory::_NV__sectionUpdateItemCallback"
// Lua signature:  function(self, item, prevQuantity)
void CallInventorySectionUpdateItemCallbacks(Inventory* inventory, Item* item, int prevQuantity);

// Fired by Inventory::_NV_dropItem hook.
// Lua event name: "Inventory::_NV_dropItem"
// Lua signature:  function(self, item)
void CallInventoryDropItemCallbacks(Inventory* inventory, Item* item);

// -----------------------------------------------------------
// Constructor Interceptor Callbacks
// -----------------------------------------------------------

// Fired by Character::_CONSTRUCTOR hook.
// Lua event name: "Character::_CONSTRUCTOR"
// Lua signature:  function(self, dat, own, handle, defaultVal) -> Character
Character* CallCharacterConstructedCallbacks(Character* thisptr, GameData* dat, Faction* own, const hand& _handle, Character* defaultVal);

// Fired by Item::_CONSTRUCTOR hook.
// Lua event name: "Item::_CONSTRUCTOR"
// Lua signature:  function(self, baseData, companyData, materialData, handle, defaultVal) -> Item
Item* CallItemConstructedCallbacks(Item* thisptr, GameData* baseData, GameData* companyData, GameData* _materialData, hand _handle, Item* defaultVal);

// Fired by Gear::_CONSTRUCTOR hook.
// Lua event name: "Gear::_CONSTRUCTOR"
// Lua signature:  function(self, baseData, companyData, materialData, handle, level, uniform, defaultVal) -> Gear
Gear* CallGearConstructedCallbacks(Gear* thisptr, GameData* baseData, GameData* companyData, GameData* materialData, hand _handle, int _level, Faction* uniform, Gear* defaultVal);

// Fired by Sword::_CONSTRUCTOR hook.
// Lua event name: "Sword::_CONSTRUCTOR"
// Lua signature:  function(self, baseData, companyData, materialData, handle, level, defaultVal) -> Sword
Sword* CallSwordConstructedCallbacks(Sword* thisptr, GameData* baseData, GameData* companyData, GameData* materialData, hand _handle, int _level, Sword* defaultVal);

// Fired by Crossbow::_CONSTRUCTOR hook.
// Lua event name: "Crossbow::_CONSTRUCTOR"
// Lua signature:  function(self, baseData, handle, overallLevel, defaultVal) -> Crossbow
Crossbow* CallCrossbowConstructedCallbacks(Crossbow* thisptr, GameData* baseData, hand _handle, int _overalllevel, Crossbow* defaultVal);

// Fired by Armour::_CONSTRUCTOR hook.
// Lua event name: "Armour::_CONSTRUCTOR"
// Lua signature:  function(self, baseData, materialData, handle, uniformFlag, level, defaultVal) -> Armour
Armour* CallArmourConstructedCallbacks(Armour* thisptr, GameData* baseData, GameData* _materialData, hand _handle, Faction* _uniformFlag, int _level, Armour* defaultVal);

// Fired by LockedArmour::_CONSTRUCTOR hook.
// Lua event name: "LockedArmour::_CONSTRUCTOR"
// Lua signature:  function(self, baseData, materialData, handle, uniformFlag, level, defaultVal) -> LockedArmour
LockedArmour* CallLockedArmourConstructedCallbacks(LockedArmour* thisptr, GameData* baseData, GameData* _materialData, hand _handle, Faction* _uniformFlag, int _level, LockedArmour* defaultVal);

// Fired by Weapon::_CONSTRUCTOR hook.
// Lua event name: "Weapon::_CONSTRUCTOR"
// Lua signature:  function(self, baseData, companyData, materialData, handle, level, defaultVal) -> Weapon
Weapon* CallWeaponConstructedCallbacks(Weapon* thisptr, GameData* baseData, GameData* companyData, GameData* materialData, hand _handle, int _level, Weapon* defaultVal);

// Fired by Building::_CONSTRUCTOR hook.
// Lua event name: "Building::_CONSTRUCTOR"
// Lua signature:  function(self, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> Building
Building* CallBuildingConstructedCallbacks(Building* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, Building* defaultVal);

// Fired by Platoon::_CONSTRUCTOR hook.
// Lua event name: "Platoon::_CONSTRUCTOR"
// Lua signature:  function(self, faction, squadTemplate, platoonState, position, persistent, defaultVal) -> Platoon
Platoon* CallPlatoonConstructedCallbacks(Platoon* thisptr, Faction* f, GameData* _squadTemplate, GameData* platoonState, const Ogre::Vector3& p, bool _persistent, Platoon* defaultVal);

// Fired by ActivePlatoon::_CONSTRUCTOR hook.
// Lua event name: "ActivePlatoon::_CONSTRUCTOR"
// Lua signature:  function(self, platoon, doc, faction, gameData, currentGoal, posOffset, defaultVal) -> ActivePlatoon
ActivePlatoon* CallActivePlatoonConstructedCallbacks(ActivePlatoon* thisptr, Platoon* my, DataObjectContainer* doc, Faction* f, GameData* d, Tasker* _currentGoal, const Ogre::Vector3& _posOffset, ActivePlatoon* defaultVal);

// Fired by Faction::_CONSTRUCTOR hook.
// Lua event name: "Faction::_CONSTRUCTOR"
// Lua signature:  function(self, name, defaultVal) -> Faction
Faction* CallFactionConstructedCallbacks(Faction* thisptr, const std::string& _name, Faction* defaultVal);

// Fired by Bounty::_CONSTRUCTOR hook.
// Lua event name: "Bounty::_CONSTRUCTOR"
// Lua signature:  function(self, defaultVal) -> Bounty
Bounty* CallBountyConstructedCallbacks(Bounty* thisptr, Bounty* defaultVal);

// Fired by Damages::_CONSTRUCTOR hook.
// Lua event name: "Damages::_CONSTRUCTOR"
// Lua signature:  function(self, cut, blunt, pierce, bleed, armour, defaultVal) -> Damages
Damages* CallDamagesConstructedCallbacks(Damages* thisptr, float _cut, float _blunt, float _pierce, float bleed, float armour, Damages* defaultVal);

// Fired by Inventory::_CONSTRUCTOR hook.
// Lua event name: "Inventory::_CONSTRUCTOR"
// Lua signature:  function(self, owner, defaultVal) -> Inventory
Inventory* CallInventoryConstructedCallbacks(Inventory* thisptr, RootObject* _owner, Inventory* defaultVal);

// Fired by DoorStuff::_CONSTRUCTOR hook.
// Lua event name: "DoorStuff::_CONSTRUCTOR"
// Lua signature:  function(self, dat, position, orientation, participant, town, handle, isFurnitureOf, indoors, parent, defaultVal) -> DoorStuff
DoorStuff* CallDoorStuffConstructedCallbacks(DoorStuff* thisptr, GameData* dat, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, Building* par, DoorStuff* defaultVal);

// Fired by ProductionBuilding::_CONSTRUCTOR hook.
// Lua event name: "ProductionBuilding::_CONSTRUCTOR"
// Lua signature:  function(self, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> ProductionBuilding
ProductionBuilding* CallProductionBuildingConstructedCallbacks(ProductionBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, ProductionBuilding* defaultVal);

// Fired by CraftingBuilding::_CONSTRUCTOR hook.
// Lua event name: "CraftingBuilding::_CONSTRUCTOR"
// Lua signature:  function(self, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> CraftingBuilding
CraftingBuilding* CallCraftingBuildingConstructedCallbacks(CraftingBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, CraftingBuilding* defaultVal);

// Fired by FarmBuilding::_CONSTRUCTOR hook.
// Lua event name: "FarmBuilding::_CONSTRUCTOR"
// Lua signature:  function(self, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> FarmBuilding
FarmBuilding* CallFarmBuildingConstructedCallbacks(FarmBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, FarmBuilding* defaultVal);

// Fired by TurretBuilding::_CONSTRUCTOR hook.
// Lua event name: "TurretBuilding::_CONSTRUCTOR"
// Lua signature:  function(self, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> TurretBuilding
TurretBuilding* CallTurretBuildingConstructedCallbacks(TurretBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, TurretBuilding* defaultVal);

// Fired by FurnaceBuilding::_CONSTRUCTOR hook.
// Lua event name: "FurnaceBuilding::_CONSTRUCTOR"
// Lua signature:  function(self, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> FurnaceBuilding
FurnaceBuilding* CallFurnaceBuildingConstructedCallbacks(FurnaceBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, FurnaceBuilding* defaultVal);

// Fired by ResearchBuilding::_CONSTRUCTOR hook.
// Lua event name: "ResearchBuilding::_CONSTRUCTOR"
// Lua signature:  function(self, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> ResearchBuilding
ResearchBuilding* CallResearchBuildingConstructedCallbacks(ResearchBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, ResearchBuilding* defaultVal);

// Fired by WallBuilding::_CONSTRUCTOR hook.
// Lua event name: "WallBuilding::_CONSTRUCTOR"
// Lua signature:  function(self, dat, position, orientation, participant, furnitureOf, town, handle, defaultVal) -> WallBuilding
WallBuilding* CallWallBuildingConstructedCallbacks(WallBuilding* thisptr, GameData* dat, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, Layout* furnitureOf, const hand& town, const hand& _handle, WallBuilding* defaultVal);

// Fired by PreviewBuilding::_CONSTRUCTOR hook.
// Lua event name: "PreviewBuilding::_CONSTRUCTOR"
// Lua signature:  function(self, data, furnitureParent, defaultVal) -> PreviewBuilding
PreviewBuilding* CallPreviewBuildingConstructedCallbacks(PreviewBuilding* thisptr, GameData* data, Building* _furnitureParent, PreviewBuilding* defaultVal);

// Fired by UseableStuff::_CONSTRUCTOR hook.
// Lua event name: "UseableStuff::_CONSTRUCTOR"
// Lua signature:  function(self, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> UseableStuff
UseableStuff* CallUseableStuffConstructedCallbacks(UseableStuff* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, UseableStuff* defaultVal);

// Fired by StorageBuilding::_CONSTRUCTOR hook.
// Lua event name: "StorageBuilding::_CONSTRUCTOR"
// Lua signature:  function(self, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> StorageBuilding
StorageBuilding* CallStorageBuildingConstructedCallbacks(StorageBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, StorageBuilding* defaultVal);

// Fired by LightBuilding::_CONSTRUCTOR hook.
// Lua event name: "LightBuilding::_CONSTRUCTOR"
// Lua signature:  function(self, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> LightBuilding
LightBuilding* CallLightBuildingConstructedCallbacks(LightBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, LightBuilding* defaultVal);

// Fired by GeneratorBuilding::_CONSTRUCTOR hook.
// Lua event name: "GeneratorBuilding::_CONSTRUCTOR"
// Lua signature:  function(self, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> GeneratorBuilding
GeneratorBuilding* CallGeneratorBuildingConstructedCallbacks(GeneratorBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, GeneratorBuilding* defaultVal);

// Fired by WindGeneratorBuilding::_CONSTRUCTOR hook.
// Lua event name: "WindGeneratorBuilding::_CONSTRUCTOR"
// Lua signature:  function(self, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> WindGeneratorBuilding
WindGeneratorBuilding* CallWindGeneratorBuildingConstructedCallbacks(WindGeneratorBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, WindGeneratorBuilding* defaultVal);

// Fired by GatewayBuilding::_CONSTRUCTOR hook.
// Lua event name: "GatewayBuilding::_CONSTRUCTOR"
// Lua signature:  function(self, dat, position, orientation, participant, town, handle, defaultVal) -> GatewayBuilding
GatewayBuilding* CallGatewayBuildingConstructedCallbacks(GatewayBuilding* thisptr, GameData* dat, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, GatewayBuilding* defaultVal);

// Fired by TortureBuilding::_CONSTRUCTOR hook.
// Lua event name: "TortureBuilding::_CONSTRUCTOR"
// Lua signature:  function(self, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> TortureBuilding
TortureBuilding* CallTortureBuildingConstructedCallbacks(TortureBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* participant, const hand& town, const hand& handle, Layout* isfurnitureOf, Building* indoors, TortureBuilding* defaultVal);

// Fired by RainCollectorBuilding::_CONSTRUCTOR hook.
// Lua event name: "RainCollectorBuilding::_CONSTRUCTOR"
// Lua signature:  function(self, data, position, orientation, participant, town, handle, isFurnitureOf, indoors, defaultVal) -> RainCollectorBuilding
RainCollectorBuilding* CallRainCollectorBuildingConstructedCallbacks(RainCollectorBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* participant, const hand& town, const hand& handle, Layout* isfurnitureOf, Building* indoors, RainCollectorBuilding* defaultVal);

// Fired by CharacterHuman::_CONSTRUCTOR hook.
// Lua event name: "CharacterHuman::_CONSTRUCTOR"
// Lua signature:  function(self, data, faction, handle, defaultVal) -> CharacterHuman
CharacterHuman* CallCharacterHumanConstructedCallbacks(CharacterHuman* thisptr, GameData* d, Faction* f, const hand& _handle, CharacterHuman* defaultVal);

// Fired by CharacterAnimal::_CONSTRUCTOR hook.
// Lua event name: "CharacterAnimal::_CONSTRUCTOR"
// Lua signature:  function(self, data, faction, handle, age, defaultVal) -> CharacterAnimal
CharacterAnimal* CallCharacterAnimalConstructedCallbacks(CharacterAnimal* thisptr, GameData* d, Faction* f, const hand& _handle, float _age, CharacterAnimal* defaultVal);

// Fired by CharStats::_CONSTRUCTOR hook.
// Lua event name: "CharStats::_CONSTRUCTOR"
// Lua signature:  function(self, defaultVal) -> CharStats
CharStats* CallCharStatsConstructedCallbacks(CharStats* thisptr, CharStats* defaultVal);

// Fired by CharBody::_CONSTRUCTOR hook.
// Lua event name: "CharBody::_CONSTRUCTOR"
// Lua signature:  function(self, defaultVal) -> CharBody
CharBody* CallCharBodyConstructedCallbacks(CharBody* thisptr, CharBody* defaultVal);

// Fired by CharMovement::_CONSTRUCTOR hook.
// Lua event name: "CharMovement::_CONSTRUCTOR"
// Lua signature:  function(self, defaultVal) -> CharMovement
CharMovement* CallCharMovementConstructedCallbacks(CharMovement* thisptr, CharMovement* defaultVal);

// Fired by CombatClass::_CONSTRUCTOR hook.
// Lua event name: "CombatClass::_CONSTRUCTOR"
// Lua signature:  function(self, movement, ai, anim, character, stats, medical, defaultVal) -> CombatClass
CombatClass* CallCombatClassConstructedCallbacks(CombatClass* thisptr, CharMovement* m, void* a, void* an, Character* character, CharStats* st, MedicalSystem* _med, CombatClass* defaultVal);

// Fired by Town::_CONSTRUCTOR hook.
// Lua event name: "Town::_CONSTRUCTOR"
// Lua signature:  function(self, data, defaultVal) -> Town
Town* CallTownConstructedCallbacks(Town* thisptr, GameData* d, Town* defaultVal);

// Fired by TownBase::_CONSTRUCTOR hook.
// Lua event name: "TownBase::_CONSTRUCTOR"
// Lua signature:  function(self, data, defaultVal) -> TownBase
TownBase* CallTownBaseConstructedCallbacks(TownBase* thisptr, GameData* d, TownBase* defaultVal);

// Fired by FactionLeader::_CONSTRUCTOR hook.
// Lua event name: "FactionLeader::_CONSTRUCTOR"
// Lua signature:  function(self, faction, defaultVal) -> FactionLeader
FactionLeader* CallFactionLeaderConstructedCallbacks(FactionLeader* thisptr, Faction* f, FactionLeader* defaultVal);

// Fired by FactionRelations::_CONSTRUCTOR hook.
// Lua event name: "FactionRelations::_CONSTRUCTOR"
// Lua signature:  function(self, defaultVal) -> FactionRelations
FactionRelations* CallFactionRelationsConstructedCallbacks(FactionRelations* thisptr, FactionRelations* defaultVal);

// Fired by FactionUniqueSquadManager::_CONSTRUCTOR hook.
// Lua event name: "FactionUniqueSquadManager::_CONSTRUCTOR"
// Lua signature:  function(self, defaultVal) -> FactionUniqueSquadManager
FactionUniqueSquadManager* CallFactionUniqueSquadManagerConstructedCallbacks(FactionUniqueSquadManager* thisptr, FactionUniqueSquadManager* defaultVal);

// Fired by ProsperityManager::_CONSTRUCTOR hook.
// Lua event name: "ProsperityManager::_CONSTRUCTOR"
// Lua signature:  function(self, defaultVal) -> ProsperityManager
ProsperityManager* CallProsperityManagerConstructedCallbacks(ProsperityManager* thisptr, ProsperityManager* defaultVal);

// Fired by InventoryItemBase::_CONSTRUCTOR hook.
// Lua event name: "InventoryItemBase::_CONSTRUCTOR"
// Lua signature:  function(self, baseData, companyData, materialData, handle, defaultVal) -> InventoryItemBase
InventoryItemBase* CallInventoryItemBaseConstructedCallbacks(InventoryItemBase* thisptr, GameData* baseData, GameData* companyData, GameData* materialData, const hand& _handle, InventoryItemBase* defaultVal);

// Fired by MedicalSystem::_CONSTRUCTOR hook.
// Lua event name: "MedicalSystem::_CONSTRUCTOR"
// Lua signature:  function(self, defaultVal) -> MedicalSystem
MedicalSystem* CallMedicalSystemConstructedCallbacks(MedicalSystem* thisptr, MedicalSystem* defaultVal);

// Fired by CombatTechniqueData::_CONSTRUCTOR hook.
// Lua event name: "CombatTechniqueData::_CONSTRUCTOR"
// Lua signature:  function(self, data, defaultVal) -> CombatTechniqueData
CombatTechniqueData* CallCombatTechniqueDataConstructedCallbacks(CombatTechniqueData* thisptr, GameData* data, CombatTechniqueData* defaultVal);

// Fired by Dialogue::_CONSTRUCTOR hook.
// Lua event name: "Dialogue::_CONSTRUCTOR"
// Lua signature:  function(self, defaultVal) -> Dialogue
Dialogue* CallDialogueConstructedCallbacks(Dialogue* thisptr, Dialogue* defaultVal);

// Fired by DialogLineData::_CONSTRUCTOR hook.
// Lua event name: "DialogLineData::_CONSTRUCTOR"
// Lua signature:  function(self, data, defaultVal) -> DialogLineData
DialogLineData* CallDialogLineDataConstructedCallbacks(DialogLineData* thisptr, GameData* dat, DialogLineData* defaultVal);

// Fired by GameData::_CONSTRUCTOR hook.
// Lua event name: "GameData::_CONSTRUCTOR"
// Lua signature:  function(self, defaultVal) -> GameData
GameData* CallGameDataConstructedCallbacks(GameData* thisptr, GameData* defaultVal);

// Fired by Tasker::_CONSTRUCTOR hook.
// Lua event name: "Tasker::_CONSTRUCTOR"
// Lua signature:  function(self, defaultVal) -> Tasker
Tasker* CallTaskerConstructedCallbacks(Tasker* thisptr, Tasker* defaultVal);

// Fired by AppearanceManager::_CONSTRUCTOR hook.
// Lua event name: "AppearanceManager::_CONSTRUCTOR"
// Lua signature:  function(self, defaultVal) -> AppearanceManager
AppearanceManager* CallAppearanceManagerConstructedCallbacks(AppearanceManager* thisptr, AppearanceManager* defaultVal);

// Fired by CombatMovementController::_CONSTRUCTOR hook.
// Lua event name: "CombatMovementController::_CONSTRUCTOR"
// Lua signature:  function(self, defaultVal) -> CombatMovementController
CombatMovementController* CallCombatMovementControllerConstructedCallbacks(CombatMovementController* thisptr, CombatMovementController* defaultVal);

// Fired by WorldEventStateQuery::_CONSTRUCTOR hook.
// Lua event name: "WorldEventStateQuery::_CONSTRUCTOR"
// Lua signature:  function(self, defaultVal) -> WorldEventStateQuery
WorldEventStateQuery* CallWorldEventStateQueryConstructedCallbacks(WorldEventStateQuery* thisptr, WorldEventStateQuery* defaultVal);

// Fired by DialogueWindow::_CONSTRUCTOR hook.
// Lua event name: "DialogueWindow::_CONSTRUCTOR"
// Lua signature:  function(self, defaultVal) -> DialogueWindow
DialogueWindow* CallDialogueWindowConstructedCallbacks(DialogueWindow* thisptr, DialogueWindow* defaultVal);

// Fired by InventoryGUI::_CONSTRUCTOR hook.
// Lua event name: "InventoryGUI::_CONSTRUCTOR"
// Lua signature:  function(self, inventory, layout, callback, defaultVal) -> InventoryGUI
InventoryGUI* CallInventoryGUIConstructedCallbacks(InventoryGUI* thisptr, Inventory* inventory, InventoryLayout* layout, RootObject* callback, InventoryGUI* defaultVal);

// Fired by GenericFixedInventoryLayout::_CONSTRUCTOR hook.
// Lua event name: "GenericFixedInventoryLayout::_CONSTRUCTOR"
// Lua signature:  function(self, defaultVal) -> GenericFixedInventoryLayout
GenericFixedInventoryLayout* CallGenericFixedInventoryLayoutConstructedCallbacks(GenericFixedInventoryLayout* thisptr, GenericFixedInventoryLayout* defaultVal);

// Lua event name: "GameWorld::_CONSTRUCTOR"
// Lua signature: function(self, defaultVal) -> GameWorld
GameWorld* CallGameWorldConstructedCallbacks(GameWorld* thisptr, GameWorld* defaultVal);
// Lua event name: "PlayerInterface::_CONSTRUCTOR"
// Lua signature: function(self, defaultVal) -> PlayerInterface
PlayerInterface* CallPlayerInterfaceConstructedCallbacks(PlayerInterface* thisptr, PlayerInterface* defaultVal);
// Lua event name: "InputHandler::_CONSTRUCTOR"
// Lua signature: function(self, defaultVal) -> InputHandler
InputHandler* CallInputHandlerConstructedCallbacks(InputHandler* thisptr, InputHandler* defaultVal);
// Lua event name: "RootObjectFactory::_CONSTRUCTOR"
// Lua signature: function(self, defaultVal) -> RootObjectFactory
RootObjectFactory* CallRootObjectFactoryConstructedCallbacks(RootObjectFactory* thisptr, RootObjectFactory* defaultVal);
// Lua event name: "FactionManager::_CONSTRUCTOR"
// Lua signature: function(self, defaultVal) -> FactionManager
FactionManager* CallFactionManagerConstructedCallbacks(FactionManager* thisptr, FactionManager* defaultVal);
// Lua event name: "FactionWarMgr::_CONSTRUCTOR"
// Lua signature: function(self, faction, defaultVal) -> FactionWarMgr
FactionWarMgr* CallFactionWarMgrConstructedCallbacks(FactionWarMgr* thisptr, Faction* faction, FactionWarMgr* defaultVal);
// Lua event name: "BountyManager::_CONSTRUCTOR"
// Lua signature: function(self, character, defaultVal) -> BountyManager
BountyManager* CallBountyManagerConstructedCallbacks(BountyManager* thisptr, Character* character, BountyManager* defaultVal);
// Lua event name: "ZoneMap::_CONSTRUCTOR"
// Lua signature: function(self, defaultVal) -> ZoneMap
ZoneMap* CallZoneMapConstructedCallbacks(ZoneMap* thisptr, ZoneMap* defaultVal);
// Lua event name: "ZoneManager::_CONSTRUCTOR"
// Lua signature: function(self, defaultVal) -> ZoneManager
ZoneManager* CallZoneManagerConstructedCallbacks(ZoneManager* thisptr, ZoneManager* defaultVal);
// Lua event name: "Character::AttachedArrowManager::_CONSTRUCTOR"
// Lua signature: function(self, defaultVal) -> AttachedArrowManager
Character::AttachedArrowManager* CallAttachedArrowManagerConstructedCallbacks(Character::AttachedArrowManager* thisptr, Character::AttachedArrowManager* defaultVal);
// Lua event name: "LimbsInventoryLayout::_CONSTRUCTOR"
// Lua signature: function(self, character, defaultVal) -> LimbsInventoryLayout
LimbsInventoryLayout* CallLimbsInventoryLayoutConstructedCallbacks(LimbsInventoryLayout* thisptr, Character* character, LimbsInventoryLayout* defaultVal);
// Lua event name: "RobotLimbs::_CONSTRUCTOR"
// Lua signature: function(self, character, defaultVal) -> RobotLimbs
RobotLimbs* CallRobotLimbsConstructedCallbacks(RobotLimbs* thisptr, Character* character, RobotLimbs* defaultVal);
// Lua event name: "ShopTrader::_CONSTRUCTOR"
// Lua signature: function(self, character, defaultVal) -> ShopTrader
ShopTrader* CallShopTraderConstructedCallbacks(ShopTrader* thisptr, Character* character, ShopTrader* defaultVal);
// Lua event name: "RootObjectBase::_CONSTRUCTOR"
// Lua signature: function(self, data, faction, handle, defaultVal) -> RootObjectBase
RootObjectBase* CallRootObjectBaseConstructedCallbacks(RootObjectBase* thisptr, GameData* data, Faction* faction, hand handle, RootObjectBase* defaultVal);
// Lua event name: "RootObject::_CONSTRUCTOR"
// Lua signature: function(self, data, faction, handle, defaultVal) -> RootObject
RootObject* CallRootObjectConstructedCallbacks(RootObject* thisptr, GameData* data, Faction* faction, hand handle, RootObject* defaultVal);

// -----------------------------------------------------------
// Callbacks for hooks in Building/UseableStuff.h
// -----------------------------------------------------------

// Fired by UseableStuff::_NV_tryOperate hook.
// Lua event name: "UseableStuff::_NV_tryOperate"
// Lua signature:  function(self, userHandle, success)
void CallUseableStuffTryOperateCallbacks(UseableStuff* thisptr, const hand& h, bool success);

// Fired by UseableStuff::stopOperating hook.
// Lua event name: "UseableStuff::stopOperating"
// Lua signature:  function(self, userHandle)
void CallUseableStuffStopOperatingCallbacks(UseableStuff* thisptr, const hand& h);

// Fired by UseableStuff::occupantHandleChangedEvent hook.
// Lua event name: "UseableStuff::occupantHandleChangedEvent"
// Lua signature:  function(self, newOccupantHandle)
void CallUseableStuffOccupantChangedCallbacks(UseableStuff* thisptr, const hand& h);

// Fired by UseableStuff::_NV_switchPowerOn hook.
// Lua event name: "UseableStuff::_NV_switchPowerOn"
// Lua signature:  function(self, on)
void CallUseableStuffPowerSwitchedCallbacks(UseableStuff* thisptr, bool on);

// Fired by UseableStuff::_NV_givePower hook.
// Lua event name: "UseableStuff::_NV_givePower"
// Lua signature:  function(self, amount)
void CallUseableStuffGivePowerCallbacks(UseableStuff* thisptr, float amount);

// Fired by UseableStuff::_NV_getCostToUse hook.
// Lua event name: "UseableStuff::_NV_getCostToUse"
// Lua signature:  function(self, who, defaultVal) -> integer
int CallUseableStuffGetCostToUseCallbacks(UseableStuff* thisptr, Character* who, int defaultVal);

// Fired by UseableStuff::_NV_couldIOperate hook.
// Lua event name: "UseableStuff::_NV_couldIOperate"
// Lua signature:  function(self, userHandle, defaultVal) -> boolean
bool CallUseableStuffCouldIOperateCallbacks(const UseableStuff* thisptr, const hand& h, bool defaultVal);

// Fired by UseableStuff::_NV_dontNeedWorkRightNow hook.
// Lua event name: "UseableStuff::_NV_dontNeedWorkRightNow"
// Lua signature:  function(self, defaultVal) -> boolean
bool CallUseableStuffDontNeedWorkCallbacks(const UseableStuff* thisptr, bool defaultVal);

// -----------------------------------------------------------
// Callbacks for hooks in Building/Building.h (Additional)
// -----------------------------------------------------------

// Fired by Building::_NV_notifyConstructionComplete hook.
// Lua event name: "Building::_NV_notifyConstructionComplete"
// Lua signature:  function(self)
void CallBuildingNotifyConstructionCompleteCallbacks(Building* thisptr);

// Fired by Building::_NV_addConstructionProgress hook.
// Lua event name: "Building::_NV_addConstructionProgress"
// Lua signature:  function(self, amount)
void CallBuildingAddConstructionProgressCallbacks(Building* thisptr, float amount);

// Fired by Building::_NV_setConstructionProgress hook.
// Lua event name: "Building::_NV_setConstructionProgress"
// Lua signature:  function(self, amount)
void CallBuildingSetConstructionProgressCallbacks(Building* thisptr, float amount);

// Fired by Building::_NV_addDismantleProgress hook.
// Lua event name: "Building::_NV_addDismantleProgress"
// Lua signature:  function(self, amount, defaultVal) -> boolean
bool CallBuildingAddDismantleProgressCallbacks(Building* thisptr, float amount, bool defaultVal);

// Fired by Building::_NV_notifyConstructionDismantling hook.
// Lua event name: "Building::_NV_notifyConstructionDismantling"
// Lua signature:  function(self)
void CallBuildingNotifyConstructionDismantlingCallbacks(Building* thisptr);

// Fired by Building::_NV_upgrade hook.
// Lua event name: "Building::_NV_upgrade"
// Lua signature:  function(self, line)
void CallBuildingUpgradeCallbacks(Building* thisptr, DataPanelLine* line);

// Fired by Building::_NV_canUpgrade hook.
// Lua event name: "Building::_NV_canUpgrade"
// Lua signature:  function(self, defaultVal) -> GameData
GameData* CallBuildingCanUpgradeCallbacks(Building* thisptr, GameData* defaultVal);

// Fired by Building::destroyDoors hook.
// Lua event name: "Building::destroyDoors"
// Lua signature:  function(self)
void CallBuildingDestroyDoorsCallbacks(Building* thisptr);

// Fired by Building::_NV_setFaction hook.
// Lua event name: "Building::_NV_setFaction"
// Lua signature:  function(self, faction, activePlatoon)
void CallBuildingSetFactionCallbacks(Building* thisptr, Faction* p, ActivePlatoon* a);

// Fired by Building::setFloorVisibility hook.
// Lua event name: "Building::setFloorVisibility"
// Lua signature:  function(self, floor, isVisible)
void CallBuildingSetFloorVisibilityCallbacks(Building* thisptr, int floor, bool vis);

// Fired by Building::_NV_switchLights hook.
// Lua event name: "Building::_NV_switchLights"
// Lua signature:  function(self, on)
void CallBuildingSwitchLightsCallbacks(Building* thisptr, bool on);

// Fired by Building::_NV_switchEffects hook.
// Lua event name: "Building::_NV_switchEffects"
// Lua signature:  function(self, on)
void CallBuildingSwitchEffectsCallbacks(Building* thisptr, bool on);

// Fired by Building::_NV_notifyEffect hook.
// Lua event name: "Building::_NV_notifyEffect"
// Lua signature:  function(self, effectType, weatherType, strength)
void CallBuildingNotifyEffectCallbacks(Building* thisptr, int type, int what, float strength);

// -----------------------------------------------------------
// Callbacks for hooks in Building/WallBuilding.h
// -----------------------------------------------------------

// Fired by WallBuilding::_NV_hitByMeleeAttack hook.
// Lua event name: "WallBuilding::_NV_hitByMeleeAttack"
// Lua signature:  function(self, cutDir, damage, attacker, attack, comboID)
void CallWallBuildingHitByMeleeAttackCallbacks(WallBuilding* thisptr, int cutDir, Damages* damage, Character* who, CombatTechniqueData* attack, int comboID);

// -----------------------------------------------------------
// Callbacks for hooks in Building/DoorStuff.h
// -----------------------------------------------------------

// Fired by DoorStuff::openDoor hook.
// Lua event name: "DoorStuff::openDoor"
// Lua signature:  function(self, defaultVal) -> boolean
bool CallDoorStuffOpenDoorCallbacks(DoorStuff* thisptr, bool defaultVal);

// Fired by DoorStuff::closeDoor hook.
// Lua event name: "DoorStuff::closeDoor"
// Lua signature:  function(self, defaultVal) -> boolean
bool CallDoorStuffCloseDoorCallbacks(DoorStuff* thisptr, bool defaultVal);

// Fired by DoorStuff::lockDoor hook.
// Lua event name: "DoorStuff::lockDoor"
// Lua signature:  function(self)
void CallDoorStuffLockDoorCallbacks(DoorStuff* thisptr);

// Fired by DoorStuff::unlockDoor hook.
// Lua event name: "DoorStuff::unlockDoor"
// Lua signature:  function(self)
void CallDoorStuffUnlockDoorCallbacks(DoorStuff* thisptr);

// Fired by DoorStuff::setDoorState hook.
// Lua event name: "DoorStuff::setDoorState"
// Lua signature:  function(self, doorState)
void CallDoorStuffSetDoorStateCallbacks(DoorStuff* thisptr, int doorState);

// Fired by DoorStuff::_NV_hitByMeleeAttack hook.
// Lua event name: "DoorStuff::_NV_hitByMeleeAttack"
// Lua signature:  function(self, cutDir, damage, attacker, attack, comboID)
void CallDoorStuffHitByMeleeAttackCallbacks(DoorStuff* thisptr, int cutDir, Damages* damage, Character* who, CombatTechniqueData* attack, int comboID);

// -----------------------------------------------------------
// Callbacks for hooks in Building/ProductionBuilding.h
// -----------------------------------------------------------

// Fired by ProductionBuilding::_NV_operate hook.
// Lua event name: "ProductionBuilding::_NV_operate"
// Lua signature:  function(self, worker, amount)
void CallProductionBuildingOperateCallbacks(ProductionBuilding* thisptr, Character* who, float amount);

// -----------------------------------------------------------
// Callbacks for hooks in Building/CraftingBuilding.h
// -----------------------------------------------------------

// Fired by CraftingBuilding::_NV_operate hook.
// Lua event name: "CraftingBuilding::_NV_operate"
// Lua signature:  function(self, worker, amount)
void CallCraftingBuildingOperateCallbacks(CraftingBuilding* thisptr, Character* worker, float amount);

// Fired by CraftingBuilding::_NV_newCraftingButton hook.
// Lua event name: "CraftingBuilding::_NV_newCraftingButton"
// Lua signature:  function(self, sender)
void CallCraftingBuildingNewCraftingButtonCallbacks(CraftingBuilding* thisptr, MyGUI::Widget* sender);

// Fired by CraftingBuilding::addFinishedCraftItem hook.
// Lua event name: "CraftingBuilding::addFinishedCraftItem"
// Lua signature:  function(self, item)
void CallCraftingBuildingAddFinishedCraftItemCallbacks(CraftingBuilding* thisptr, Item* what);

// Fired by CraftingBuilding::notifyCraftFailiure hook.
// Lua event name: "CraftingBuilding::notifyCraftFailiure"
// Lua signature:  function(self)
void CallCraftingBuildingNotifyCraftFailureCallbacks(CraftingBuilding* thisptr);

// Fired by CraftingBuilding::destroyProductionItem hook.
// Lua event name: "CraftingBuilding::destroyProductionItem"
// Lua signature:  function(self)
void CallCraftingBuildingDestroyProductionItemCallbacks(CraftingBuilding* thisptr);

// Fired by CraftingBuilding::_removeCraft hook.
// Lua event name: "CraftingBuilding::_removeCraft"
// Lua signature:  function(self, index)
void CallCraftingBuildingRemoveCraftCallbacks(CraftingBuilding* thisptr, int index);

// -----------------------------------------------------------
// Callbacks for hooks in Building/FurnaceBuilding.h
// -----------------------------------------------------------

// Fired by FurnaceBuilding::_NV_operate hook.
// Lua event name: "FurnaceBuilding::_NV_operate"
// Lua signature:  function(self, worker, amount)
void CallFurnaceBuildingOperateCallbacks(FurnaceBuilding* thisptr, Character* worker, float amount);

// -----------------------------------------------------------
// Callbacks for hooks in Building/ResearchBuilding.h
// -----------------------------------------------------------

// Fired by ResearchBuilding::_NV_operate hook.
// Lua event name: "ResearchBuilding::_NV_operate"
// Lua signature:  function(self, worker, amount)
void CallResearchBuildingOperateCallbacks(ResearchBuilding* thisptr, Character* worker, float amount);

// -----------------------------------------------------------
// Callbacks for hooks in Building/FarmBuilding.h
// -----------------------------------------------------------

// Fired by FarmBuilding::_NV_operate hook.
// Lua event name: "FarmBuilding::_NV_operate"
// Lua signature:  function(self, worker, amount)
void CallFarmBuildingOperateCallbacks(FarmBuilding* thisptr, Character* who, float amount);

// Fired by FarmBuilding::destroyAPlant hook.
// Lua event name: "FarmBuilding::destroyAPlant"
// Lua signature:  function(self, defaultVal) -> boolean
bool CallFarmBuildingDestroyAPlantCallbacks(FarmBuilding* thisptr, bool defaultVal);

// Fired by FarmBuilding::eat hook.
// Lua event name: "FarmBuilding::eat"
// Lua signature:  function(self, rate)
void CallFarmBuildingEatCallbacks(FarmBuilding* thisptr, float rate);

// -----------------------------------------------------------
// Callbacks for hooks in Building/TurretBuilding.h
// -----------------------------------------------------------

// Fired by TurretBuilding::_NV_operate hook.
// Lua event name: "TurretBuilding::_NV_operate"
// Lua signature:  function(self, gunner, amount)
void CallTurretBuildingOperateCallbacks(TurretBuilding* thisptr, Character* gunner, float amount);

// Fired by TurretBuilding::aimAt hook.
// Lua event name: "TurretBuilding::aimAt"
// Lua signature:  function(self, targetPos)
void CallTurretBuildingAimAtCallbacks(TurretBuilding* thisptr, const Ogre::Vector3& targetPos);

// -----------------------------------------------------------
// Callbacks for hooks in Building/UseableStuff.h (Additional)
// -----------------------------------------------------------

// Fired by UseableStuff::_NV_hitByMeleeAttack hook.
// Lua event name: "UseableStuff::_NV_hitByMeleeAttack"
// Lua signature:  function(self, cutDir, damage, attacker, attack, comboID)
void CallUseableStuffHitByMeleeAttackCallbacks(UseableStuff* thisptr, int cutDir, Damages* damage, Character* who, CombatTechniqueData* attack, int comboID);

// Fired by UseableStuff::takePowerFrom hook.
// Lua event name: "UseableStuff::takePowerFrom"
// Lua signature:  function(self, amount, frameTime, defaultVal) -> number
float CallUseableStuffTakePowerFromCallbacks(UseableStuff* thisptr, float amount, float frameTime, float defaultVal);

// Fired by UseableStuff::_NV_togglePowerButton hook.
// Lua event name: "UseableStuff::_NV_togglePowerButton"
// Lua signature:  function(self, line)
void CallUseableStuffTogglePowerButtonCallbacks(UseableStuff* thisptr, DataPanelLine* line);

// Fired by UseableStuff::_NV_toggleBattButton hook.
// Lua event name: "UseableStuff::_NV_toggleBattButton"
// Lua signature:  function(self, line)
void CallUseableStuffToggleBattButtonCallbacks(UseableStuff* thisptr, DataPanelLine* line);

// -----------------------------------------------------------
// Callbacks for hooks in PreviewBuilding
// -----------------------------------------------------------

// Fired by PreviewBuilding::_NV_placeFinalPreviewBuilding hook.
// Lua event name: "PreviewBuilding::_NV_placeFinalPreviewBuilding"
// Lua signature:  function(self)
void CallPreviewBuildingPlaceFinalPreviewBuildingCallbacks(PreviewBuilding* thisptr);

// Fired by PreviewBuilding::_NV_placementVerification hook.
// Lua event name: "PreviewBuilding::_NV_placementVerification"
// Lua signature:  function(self, defaultVal) -> boolean
bool CallPreviewBuildingPlacementVerificationCallbacks(PreviewBuilding* thisptr, bool defaultVal);

// Fired by PreviewBuilding::_NV_placePreview hook.
// Lua event name: "PreviewBuilding::_NV_placePreview"
// Lua signature:  function(self, position, rotation, floorNumber)
void CallPreviewBuildingPlacePreviewCallbacks(PreviewBuilding* thisptr, const Ogre::Vector3& position, const Ogre::Quaternion& rotation, int floorNumber);

// -----------------------------------------------------------
// Callbacks for hooks in CharacterAnimal.h
// -----------------------------------------------------------

// Fired by CharacterAnimal::_NV_isAnimal hook after the original call.
// Lua event name: "CharacterAnimal::_NV_isAnimal"
// Lua signature:  function(self, result)
void CallCharacterAnimalIsAnimalCallbacks(CharacterAnimal* thisptr, CharacterAnimal* result);

// Fired by CharacterAnimal::_NV_createAnimationClass hook after the original call.
// Lua event name: "CharacterAnimal::_NV_createAnimationClass"
// Lua signature:  function(self)
void CallCharacterAnimalCreateAnimationClassCallbacks(CharacterAnimal* thisptr);

// Fired by CharacterAnimal::_NV_drawWeapon hook after the original call.
// Lua event name: "CharacterAnimal::_NV_drawWeapon"
// Lua signature:  function(self, item, lastSlot, success)
void CallCharacterAnimalDrawWeaponCallbacks(CharacterAnimal* thisptr, Item* item, const std::string& lastSlot, bool success);

// Fired by CharacterAnimal::_NV_sheatheWeapon hook after the original call.
// Lua event name: "CharacterAnimal::_NV_sheatheWeapon"
// Lua signature:  function(self)
void CallCharacterAnimalSheatheWeaponCallbacks(CharacterAnimal* thisptr);

// Fired by CharacterAnimal::_NV_getCurrentWeapon hook.
// Lua event name: "CharacterAnimal::_NV_getCurrentWeapon"
// Lua signature:  function(self, defaultVal) -> Weapon
// Returning nil or a non-Weapon value keeps defaultVal.
Weapon* CallCharacterAnimalGetCurrentWeaponCallbacks(CharacterAnimal* thisptr, Weapon* defaultVal);

// Fired by CharacterAnimal::_NV_getThePreferredWeapon hook.
// Lua event name: "CharacterAnimal::_NV_getThePreferredWeapon"
// Lua signature:  function(self, defaultVal) -> Weapon
// Returning nil or a non-Weapon value keeps defaultVal.
Weapon* CallCharacterAnimalGetThePreferredWeaponCallbacks(CharacterAnimal* thisptr, Weapon* defaultVal);

// Fired by CharacterAnimal::_NV_createInventoryLayout hook after the original call.
// Lua event name: "CharacterAnimal::_NV_createInventoryLayout"
// Lua signature:  function(self, layout)
void CallCharacterAnimalCreateInventoryLayoutCallbacks(CharacterAnimal* thisptr, InventoryLayout* layout);

// Fired by CharacterAnimal::_NV_giveBirth hook after the original call.
// Lua event name: "CharacterAnimal::_NV_giveBirth"
// Lua signature:  function(self, appearance, position, rotation, state, tempPlatoon, faction, success)
void CallCharacterAnimalGiveBirthCallbacks(CharacterAnimal* thisptr, GameDataCopyStandalone* appearance, const Ogre::Vector3& position, const Ogre::Quaternion& rotation, GameSaveState* state, ActivePlatoon* tempplatoonptr, Faction* _faction, bool success);

// Fired by CharacterAnimal::_NV_setupInventorySections hook after the original call.
// Lua event name: "CharacterAnimal::_NV_setupInventorySections"
// Lua signature:  function(self, state, success)
void CallCharacterAnimalSetupInventorySectionsCallbacks(CharacterAnimal* thisptr, GameSaveState* state, bool success);

// Fired by CharacterAnimal::_NV_setupAudio hook after the original call.
// Lua event name: "CharacterAnimal::_NV_setupAudio"
// Lua signature:  function(self)
void CallCharacterAnimalSetupAudioCallbacks(CharacterAnimal* thisptr);

// Fired by CharacterAnimal::_NV_periodicUpdate hook after the original call.
// Lua event name: "CharacterAnimal::_NV_periodicUpdate"
// Lua signature:  function(self)
void CallCharacterAnimalPeriodicUpdateCallbacks(CharacterAnimal* thisptr);

// Fired by CharacterAnimal::_NV_setAge hook after the original call.
// Lua event name: "CharacterAnimal::_NV_setAge"
// Lua signature:  function(self, zeroToOne)
void CallCharacterAnimalSetAgeCallbacks(CharacterAnimal* thisptr, float zeroToOne);

// Fired by CharacterAnimal::_NV_getAge hook.
// Lua event name: "CharacterAnimal::_NV_getAge"
// Lua signature:  function(self, defaultVal) -> number
float CallCharacterAnimalGetAgeCallbacks(const CharacterAnimal* thisptr, float defaultVal);

// Fired by CharacterAnimal::_NV_getAgeInverse hook.
// Lua event name: "CharacterAnimal::_NV_getAgeInverse"
// Lua signature:  function(self, defaultVal) -> number
float CallCharacterAnimalGetAgeInverseCallbacks(const CharacterAnimal* thisptr, float defaultVal);

// Fired by CharacterAnimal::_NV_getAge0to1 hook.
// Lua event name: "CharacterAnimal::_NV_getAge0to1"
// Lua signature:  function(self, defaultVal) -> number
float CallCharacterAnimalGetAge0to1Callbacks(const CharacterAnimal* thisptr, float defaultVal);

// Fired by CharacterAnimal::_NV_getDefaultTaskRepertoireEnum hook.
// Lua event name: "CharacterAnimal::_NV_getDefaultTaskRepertoireEnum"
// Lua signature:  function(self, defaultVal) -> integer
unsigned int CallCharacterAnimalGetDefaultTaskRepertoireEnumCallbacks(const CharacterAnimal* thisptr, unsigned int defaultVal);

// Fired by CharacterAnimal::_NV_canGoIndoors hook.
// Lua event name: "CharacterAnimal::_NV_canGoIndoors"
// Lua signature:  function(self, building, defaultVal) -> boolean
bool CallCharacterAnimalCanGoIndoorsCallbacks(const CharacterAnimal* thisptr, Building* b, bool defaultVal);

// Fired by CharacterAnimal::_NV_getSmellHuntingThresholdBlood hook.
// Lua event name: "CharacterAnimal::_NV_getSmellHuntingThresholdBlood"
// Lua signature:  function(self, defaultVal) -> number
float CallCharacterAnimalGetSmellHuntingThresholdBloodCallbacks(const CharacterAnimal* thisptr, float defaultVal);

// Fired by CharacterAnimal::_NV_getSmellHuntingThresholdEggs hook.
// Lua event name: "CharacterAnimal::_NV_getSmellHuntingThresholdEggs"
// Lua signature:  function(self, defaultVal) -> number
float CallCharacterAnimalGetSmellHuntingThresholdEggsCallbacks(const CharacterAnimal* thisptr, float defaultVal);

// Fired by CharacterAnimal::_NV_getHPMultiplier hook.
// Lua event name: "CharacterAnimal::_NV_getHPMultiplier"
// Lua signature:  function(self, defaultVal) -> number
float CallCharacterAnimalGetHPMultiplierCallbacks(const CharacterAnimal* thisptr, float defaultVal);

// Fired by CharacterAnimal::_NV_foodUpdate hook after the original call.
// Lua event name: "CharacterAnimal::_NV_foodUpdate"
// Lua signature:  function(self)
void CallCharacterAnimalFoodUpdateCallbacks(CharacterAnimal* thisptr);

// Fired by CharacterAnimal::_NV_init hook after the original call.
// Lua event name: "CharacterAnimal::_NV_init"
// Lua signature:  function(self)
void CallCharacterAnimalInitCallbacks(CharacterAnimal* thisptr);

// Fired by CharacterAnimal::_NV_dropItem hook after the original call.
// Lua event name: "CharacterAnimal::_NV_dropItem"
// Lua signature:  function(self, item)
void CallCharacterAnimalDropItemCallbacks(CharacterAnimal* thisptr, RootObject* itembase);

