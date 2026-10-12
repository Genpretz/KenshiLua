#pragma once

#include <string>
#include <kenshi/Character.h>
#include <kenshi/gui/CharacterStatsWindow.h> // nested Stat and StatGroup types
#include <kenshi/gui/FactionsScreen.h> // nested FactionRelationsLine types
#include <kenshi/gui/InventoryGUI.h> // nested inventory helper types
#include <kenshi/gui/MapScreen.h> // nested map marker types
#include <kenshi/gui/ManagementScreen.h> // nested research item type

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
class OrderCellView;
class OrderData;
class OrdersItemBox;
class OptionsWindow;
class MapScreen;
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
class GUIWindow;
class DatapanelGUI;
class ForgottenGUI;
class DataPanelLine_Faction;
class DataPanelLine_Research;
class DataPanelLine_SliderEditable;
class DataPanelLine_Text;
class DataPanelLine_TextEditable;
class DataPanelLine_Slider;
class DataPanelLine_Progress;
class DataPanelLine_CheckBox;
class DataPanelLine_DropBox;
class DataPanelLine_KeyConfig;
class ToolTip;
class ScreenLabelInterface;
class ScreenLabel;
class ScreenLabelDebug;
class FloatingProgressBar;
class StringPair;
class NewGameOptionsWindow;
class GameplayOptions;
class SplashScreen;
class FactionsScreen;
class MainBarGUI;
class MainTabPortraitPlatoon;
class RootObjectContainer;
class MedicalDatapanel;
class InventoryIcon;
class InventorySectionGUI;
class BackpackInventoryLayout;
class ContainerItem;
class iVector2;
namespace wraps { class BaseLayout; }
namespace MyGUI { class Widget; class Gui; }
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
// Callbacks for MyGUI delegates in mygui/MyGUI_Gui.h
// -----------------------------------------------------------

// Fired by the MyGUI::Gui::eventFrameStart delegate
// Raised by the renderer at the start of every frame, including while the game is paused.
// The argument is the time since the previous frame, in seconds.
// Lua event name: "MyGUI::Gui::eventFrameStart"
// Lua signature:  function(time)
void CallMyGUIGuiFrameStartCallbacks(float time);

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


// -----------------------------------------------------------
// Callbacks for hooks in GUIWindow.h
// -----------------------------------------------------------

// Fired by GUIWindow::_NV_setPositionReal hook after the original call.
// Lua event name: "GUIWindow::_NV_setPositionReal"
// Lua signature:  function(self, x, y)
void CallGUIWindowSetPositionRealCallbacks(GUIWindow* thisptr, float x, float y);

// Fired by GUIWindow::_NV_setPosition hook after the original call.
// Lua event name: "GUIWindow::_NV_setPosition"
// Lua signature:  function(self, x, y)
void CallGUIWindowSetPositionCallbacks(GUIWindow* thisptr, int x, int y);

// Fired by GUIWindow::_NV_getWidth hook after the original call.
// Lua event name: "GUIWindow::_NV_getWidth"
// Lua signature:  function(self, defaultVal) -> integer
int CallGUIWindowGetWidthCallbacks(GUIWindow* thisptr, int defaultVal);

// Fired by GUIWindow::_NV_getHeight hook after the original call.
// Lua event name: "GUIWindow::_NV_getHeight"
// Lua signature:  function(self, defaultVal) -> integer
int CallGUIWindowGetHeightCallbacks(GUIWindow* thisptr, int defaultVal);

// Fired by GUIWindow::_NV_getWidthReal hook after the original call.
// Lua event name: "GUIWindow::_NV_getWidthReal"
// Lua signature:  function(self, defaultVal) -> number
float CallGUIWindowGetWidthRealCallbacks(GUIWindow* thisptr, float defaultVal);

// Fired by GUIWindow::_NV_getHeightReal hook after the original call.
// Lua event name: "GUIWindow::_NV_getHeightReal"
// Lua signature:  function(self, defaultVal) -> number
float CallGUIWindowGetHeightRealCallbacks(GUIWindow* thisptr, float defaultVal);

// Fired by GUIWindow::_NV_isVisible hook after the original call.
// Lua event name: "GUIWindow::_NV_isVisible"
// Lua signature:  function(self, defaultVal) -> boolean
bool CallGUIWindowIsVisibleCallbacks(GUIWindow* thisptr, bool defaultVal);

// Fired by GUIWindow::_NV_update hook after the original call.
// Lua event name: "GUIWindow::_NV_update"
// Lua signature:  function(self)
void CallGUIWindowUpdateCallbacks(GUIWindow* thisptr);

// Fired by GUIWindow::_NV_autoChangeSelectedObject hook after the original call.
// Lua event name: "GUIWindow::_NV_autoChangeSelectedObject"
// Lua signature:  function(self, obj)
void CallGUIWindowAutoChangeSelectedObjectCallbacks(GUIWindow* thisptr, const hand& obj);

// Fired by GUIWindow::getWidget hook after the original call.
// Lua event name: "GUIWindow::getWidget"
// Lua signature:  function(self, result)
void CallGUIWindowGetWidgetCallbacks(GUIWindow* thisptr, MyGUI::Widget* result);

// Fired by GUIWindow::_NV_resize hook after the original call.
// Lua event name: "GUIWindow::_NV_resize"
// Lua signature:  function(self, w, h)
void CallGUIWindowResizeCallbacks(GUIWindow* thisptr, int w, int h);


// -----------------------------------------------------------
// Callbacks for hooks in CharacterStatsWindow.h
// -----------------------------------------------------------

// Fired by CharacterStatsWindow::Stat::_DESTRUCTOR hook before the original call.
// Lua event name: "CharacterStatsWindow::Stat::_DESTRUCTOR"
// Lua signature:  function(self)
void CallCharacterStatsWindowStatDestructorCallbacks(CharacterStatsWindow::Stat* thisptr);

// Fired by CharacterStatsWindow::Stat::operator= hook after the original call.
// Lua event name: "CharacterStatsWindow::Stat::operator="
// Lua signature:  function(self, that)
void CallCharacterStatsWindowStatAssignCallbacks(CharacterStatsWindow::Stat* thisptr, CharacterStatsWindow::Stat* that);

// Fired by CharacterStatsWindow::StatGroup::_DESTRUCTOR hook before the original call.
// Lua event name: "CharacterStatsWindow::StatGroup::_DESTRUCTOR"
// Lua signature:  function(self)
void CallCharacterStatsWindowStatGroupDestructorCallbacks(CharacterStatsWindow::StatGroup* thisptr);

// Fired by CharacterStatsWindow::_CONSTRUCTOR hook after the original call.
// Lua event name: "CharacterStatsWindow::_CONSTRUCTOR"
// Lua signature:  function(self, charHandle)
void CallCharacterStatsWindowConstructedCallbacks(CharacterStatsWindow* thisptr, const hand& charHandle);

// Fired by CharacterStatsWindow::_DESTRUCTOR hook before the original call.
// Lua event name: "CharacterStatsWindow::_DESTRUCTOR"
// Lua signature:  function(self)
void CallCharacterStatsWindowDestructorCallbacks(CharacterStatsWindow* thisptr);

// Fired by CharacterStatsWindow::_NV_clear hook after the original call.
// Lua event name: "CharacterStatsWindow::_NV_clear"
// Lua signature:  function(self)
void CallCharacterStatsWindowClearCallbacks(CharacterStatsWindow* thisptr);

// Fired by CharacterStatsWindow::_NV_create hook after the original call.
// Lua event name: "CharacterStatsWindow::_NV_create"
// Lua signature:  function(self)
void CallCharacterStatsWindowCreateCallbacks(CharacterStatsWindow* thisptr);

// Fired by CharacterStatsWindow::_NV_update hook after the original call.
// Lua event name: "CharacterStatsWindow::_NV_update"
// Lua signature:  function(self)
void CallCharacterStatsWindowUpdateCallbacks(CharacterStatsWindow* thisptr);

// Fired by CharacterStatsWindow::_NV_show hook after the original call.
// Lua event name: "CharacterStatsWindow::_NV_show"
// Lua signature:  function(self, on)
void CallCharacterStatsWindowShowCallbacks(CharacterStatsWindow* thisptr, bool on);

// Fired by CharacterStatsWindow::_NV_isVisible hook after the original call.
// Lua event name: "CharacterStatsWindow::_NV_isVisible"
// Lua signature:  function(self, defaultVal) -> boolean
bool CallCharacterStatsWindowIsVisibleCallbacks(CharacterStatsWindow* thisptr, bool defaultVal);

// Fired by CharacterStatsWindow::_NV_autoChangeSelectedObject hook after the original call.
// Lua event name: "CharacterStatsWindow::_NV_autoChangeSelectedObject"
// Lua signature:  function(self, obj)
void CallCharacterStatsWindowAutoChangeSelectedObjectCallbacks(CharacterStatsWindow* thisptr, const hand& obj);

// Fired by CharacterStatsWindow::setAutoUpdateMode hook after the original call.
// Lua event name: "CharacterStatsWindow::setAutoUpdateMode"
// Lua signature:  function(self, on)
void CallCharacterStatsWindowSetAutoUpdateModeCallbacks(CharacterStatsWindow* thisptr, bool on);

// Fired by CharacterStatsWindow::setupStats hook after the original call.
// Lua event name: "CharacterStatsWindow::setupStats"
// Lua signature:  function(self)
void CallCharacterStatsWindowSetupStatsCallbacks(CharacterStatsWindow* thisptr);

// Fired by CharacterStatsWindow::updateStats hook after the original call.
// Lua event name: "CharacterStatsWindow::updateStats"
// Lua signature:  function(self)
void CallCharacterStatsWindowUpdateStatsCallbacks(CharacterStatsWindow* thisptr);

// Fired by CharacterStatsWindow::clearDesctiption hook after the original call.
// Lua event name: "CharacterStatsWindow::clearDesctiption"
// Lua signature:  function(self)
void CallCharacterStatsWindowClearDesctiptionCallbacks(CharacterStatsWindow* thisptr);

// Fired by CharacterStatsWindow::sumStats hook after the original call.
// Lua event name: "CharacterStatsWindow::sumStats"
// Lua signature:  function(self, defaultVal) -> integer
int CallCharacterStatsWindowSumStatsCallbacks(CharacterStatsWindow* thisptr, int defaultVal);

// Fired by CharacterStatsWindow::closeWindow hook before the original call.
// Lua event name: "CharacterStatsWindow::closeWindow"
// Lua signature:  function(self, sender, name)
void CallCharacterStatsWindowCloseWindowCallbacks(CharacterStatsWindow* thisptr, MyGUI::Widget* sender, const std::string& name);

// Fired by CharacterStatsWindow::statMouseOver hook after the original call.
// Lua event name: "CharacterStatsWindow::statMouseOver"
// Lua signature:  function(self, sender, arg2, arg3)
void CallCharacterStatsWindowStatMouseOverCallbacks(CharacterStatsWindow* thisptr, MyGUI::Widget* sender, int arg2, int arg3);

// Fired by CharacterStatsWindow::getStatsPanel hook after the original call.
// Lua event name: "CharacterStatsWindow::getStatsPanel"
// Lua signature:  function(self, group, defaultVal) -> DatapanelGUI
// Returning nil or a non-DatapanelGUI value keeps defaultVal.
DatapanelGUI* CallCharacterStatsWindowGetStatsPanelCallbacks(CharacterStatsWindow* thisptr, int group, DatapanelGUI* defaultVal);

// Fired by CharacterStatsWindow::addStat hook after the original call.
// Lua event name: "CharacterStatsWindow::addStat"
// Lua signature:  function(type, id, name, active, description)
void CallCharacterStatsWindowAddStatCallbacks(int type, const std::string& id, const std::string& name, bool active, const std::string& description);

// Fired by CharacterStatsWindow::getStat hook after the original call.
// Lua event name: "CharacterStatsWindow::getStat"
// Lua signature:  function(type, defaultVal) -> Stat
// Returning nil or a non-Stat value keeps defaultVal.
CharacterStatsWindow::Stat* CallCharacterStatsWindowGetStatCallbacks(int type, CharacterStatsWindow::Stat* defaultVal);

// Fired by CharacterStatsWindow::getStatById hook after the original call.
// Lua event name: "CharacterStatsWindow::getStatById"
// Lua signature:  function(id, defaultVal) -> Stat
// Returning nil or a non-Stat value keeps defaultVal.
CharacterStatsWindow::Stat* CallCharacterStatsWindowGetStatByIdCallbacks(const std::string& id, CharacterStatsWindow::Stat* defaultVal);

// Fired by CharacterStatsWindow::BuildStats hook after the original call.
// Lua event name: "CharacterStatsWindow::BuildStats"
// Lua signature:  function()
void CallCharacterStatsWindowBuildStatsCallbacks();


// -----------------------------------------------------------
// Callbacks for hooks in DatapanelGUI.h
// -----------------------------------------------------------

// Fired by DatapanelGUI::_NV_setPositionReal hook after the original call.
// Lua event name: "DatapanelGUI::_NV_setPositionReal"
// Lua signature:  function(self, x, y)
void CallDatapanelGUISetPositionRealCallbacks(DatapanelGUI* thisptr, float x, float y);

// Fired by DatapanelGUI::_NV_setPosition hook after the original call.
// Lua event name: "DatapanelGUI::_NV_setPosition"
// Lua signature:  function(self, x, y)
void CallDatapanelGUISetPositionCallbacks(DatapanelGUI* thisptr, int x, int y);

// Fired by DatapanelGUI::_NV_resize hook after the original call.
// Lua event name: "DatapanelGUI::_NV_resize"
// Lua signature:  function(self, w, h)
void CallDatapanelGUIResizeCallbacks(DatapanelGUI* thisptr, int w, int h);

// Fired by DatapanelGUI::_NV_clear hook after the original call.
// Lua event name: "DatapanelGUI::_NV_clear"
// Lua signature:  function(self)
void CallDatapanelGUIClearCallbacks(DatapanelGUI* thisptr);

// Fired by DatapanelGUI::_NV_clearPage hook after the original call.
// Lua event name: "DatapanelGUI::_NV_clearPage"
// Lua signature:  function(self, cat)
void CallDatapanelGUIClearPageCallbacks(DatapanelGUI* thisptr, int cat);

// Fired by DatapanelGUI::_NV_hideAllWidgets hook after the original call.
// Lua event name: "DatapanelGUI::_NV_hideAllWidgets"
// Lua signature:  function(self)
void CallDatapanelGUIHideAllWidgetsCallbacks(DatapanelGUI* thisptr);

// Fired by DatapanelGUI::_NV_create hook after the original call.
// Lua event name: "DatapanelGUI::_NV_create"
// Lua signature:  function(self)
void CallDatapanelGUICreateCallbacks(DatapanelGUI* thisptr);

// Fired by DatapanelGUI::_NV_show hook after the original call.
// Lua event name: "DatapanelGUI::_NV_show"
// Lua signature:  function(self, on)
void CallDatapanelGUIShowCallbacks(DatapanelGUI* thisptr, bool on);

// Fired by DatapanelGUI::show_NonSmooth hook after the original call.
// Lua event name: "DatapanelGUI::show_NonSmooth"
// Lua signature:  function(self, on)
void CallDatapanelGUIShow_NonSmoothCallbacks(DatapanelGUI* thisptr, bool on);

// Fired by DatapanelGUI::_NV_update hook after the original call.
// Lua event name: "DatapanelGUI::_NV_update"
// Lua signature:  function(self)
void CallDatapanelGUIUpdateCallbacks(DatapanelGUI* thisptr);

// Fired by DatapanelGUI::setPanelName hook after the original call.
// Lua event name: "DatapanelGUI::setPanelName"
// Lua signature:  function(self, name)
void CallDatapanelGUISetPanelNameCallbacks(DatapanelGUI* thisptr, const std::string& name);

// Fired by DatapanelGUI::_NV_showTabs hook after the original call.
// Lua event name: "DatapanelGUI::_NV_showTabs"
// Lua signature:  function(self, on)
void CallDatapanelGUIShowTabsCallbacks(DatapanelGUI* thisptr, bool on);

// Fired by DatapanelGUI::_NV_addTab hook after the original call.
// Lua event name: "DatapanelGUI::_NV_addTab"
// Lua signature:  function(self, id, name, icon)
void CallDatapanelGUIAddTabCallbacks(DatapanelGUI* thisptr, int id, const std::string& name, const std::string& icon);

// Fired by DatapanelGUI::_NV_setTabEnabled hook after the original call.
// Lua event name: "DatapanelGUI::_NV_setTabEnabled"
// Lua signature:  function(self, id, enabled)
void CallDatapanelGUISetTabEnabledCallbacks(DatapanelGUI* thisptr, int id, bool enabled);

// Fired by DatapanelGUI::_NV_setTabName hook after the original call.
// Lua event name: "DatapanelGUI::_NV_setTabName"
// Lua signature:  function(self, id, name)
void CallDatapanelGUISetTabNameCallbacks(DatapanelGUI* thisptr, int id, const std::string& name);

// Fired by DatapanelGUI::setCaption hook after the original call.
// Lua event name: "DatapanelGUI::setCaption"
// Lua signature:  function(self, s)
void CallDatapanelGUISetCaptionCallbacks(DatapanelGUI* thisptr, const std::string& s);

// Fired by DatapanelGUI::setCloseCallback hook after the original call.
// Lua event name: "DatapanelGUI::setCloseCallback"
// Lua signature:  function(self, close)
void CallDatapanelGUISetCloseCallbackCallbacks(DatapanelGUI* thisptr, void* close);

// Fired by DatapanelGUI::_NV_setAutomaticRefresh hook after the original call.
// Lua event name: "DatapanelGUI::_NV_setAutomaticRefresh"
// Lua signature:  function(self, on)
void CallDatapanelGUISetAutomaticRefreshCallbacks(DatapanelGUI* thisptr, bool on);

// Fired by DatapanelGUI::_NV_setAutomaticTargeting hook after the original call.
// Lua event name: "DatapanelGUI::_NV_setAutomaticTargeting"
// Lua signature:  function(self, on)
void CallDatapanelGUISetAutomaticTargetingCallbacks(DatapanelGUI* thisptr, bool on);

// Fired by DatapanelGUI::_NV__zeroLines hook after the original call.
// Lua event name: "DatapanelGUI::_NV__zeroLines"
// Lua signature:  function(self, cat, result)
void CallDatapanelGUIZeroLinesCallbacks(DatapanelGUI* thisptr, int cat, DataPanelLine* result);

// Fired by DatapanelGUI::setLineStatInfo hook after the original call.
// Lua event name: "DatapanelGUI::setLineStatInfo"
// Lua signature:  function(self, s1, s2, category, result)
void CallDatapanelGUISetLineStatInfoCallbacks(DatapanelGUI* thisptr, const std::string& s1, const std::string& s2, int category, DataPanelLine* result);

// Fired by DatapanelGUI::setLineFaction hook after the original call.
// Lua event name: "DatapanelGUI::setLineFaction"
// Lua signature:  function(self, s1, s2, category, v1, v2, result)
void CallDatapanelGUISetLineFactionCallbacks(DatapanelGUI* thisptr, const std::string& s1, const std::string& s2, int category, float v1, float v2, DataPanelLine_Faction* result);

// Fired by DatapanelGUI::setLineTextButton hook after the original call.
// Lua event name: "DatapanelGUI::setLineTextButton"
// Lua signature:  function(self, text, caption, category, buttonWidth, skin, result)
void CallDatapanelGUISetLineTextButtonCallbacks(DatapanelGUI* thisptr, const std::string& text, const std::string& caption, int category, float buttonWidth, const std::string& skin, DataPanelLine_Button* result);

// Fired by DatapanelGUI::setLineButton hook after the original call.
// Lua event name: "DatapanelGUI::setLineButton"
// Lua signature:  function(self, key, caption, category, result)
void CallDatapanelGUISetLineButtonCallbacks(DatapanelGUI* thisptr, const std::string& key, const std::string& caption, int category, DataPanelLine_Button* result);

// Fired by DatapanelGUI::setLineToggleButton hook after the original call.
// Lua event name: "DatapanelGUI::setLineToggleButton"
// Lua signature:  function(self, key, caption, category, result)
void CallDatapanelGUISetLineToggleButtonCallbacks(DatapanelGUI* thisptr, const std::string& key, const std::string& caption, int category, DataPanelLine_Button* result);

// Fired by DatapanelGUI::setLineSliderEditable hook after the original call.
// Lua event name: "DatapanelGUI::setLineSliderEditable"
// Lua signature:  function(self, key, category, showName, min, max, value, result)
void CallDatapanelGUISetLineSliderEditableCallbacks(DatapanelGUI* thisptr, const std::string& key, int category, bool showName, float min, float max, void* value, DataPanelLine_SliderEditable* result);

// Fired by DatapanelGUI::setLineText hook after the original call.
// Lua event name: "DatapanelGUI::setLineText"
// Lua signature:  function(self, key, caption, category, wordWrap, textAlign, result)
void CallDatapanelGUISetLineTextCallbacks(DatapanelGUI* thisptr, const std::string& key, const std::string& caption, int category, bool wordWrap, int textAlign, DataPanelLine_Text* result);

// Fired by DatapanelGUI::setLineTextEditable hook after the original call.
// Lua event name: "DatapanelGUI::setLineTextEditable"
// Lua signature:  function(self, key, text, category, showKey, multiLine, textAlign, width, result)
void CallDatapanelGUISetLineTextEditableCallbacks(DatapanelGUI* thisptr, const std::string& key, const std::string& text, int category, bool showKey, bool multiLine, int textAlign, float width, DataPanelLine_TextEditable* result);

// Fired by DatapanelGUI::setLineSlider hook after the original call.
// Lua event name: "DatapanelGUI::setLineSlider"
// Lua signature:  function(self, key, caption, min, max, category, value, scale, result)
void CallDatapanelGUISetLineSliderCallbacks(DatapanelGUI* thisptr, const std::string& key, const std::string& caption, float min, float max, int category, void* value, float scale, DataPanelLine_Slider* result);

// Fired by DatapanelGUI::setLineProgress hook after the original call.
// Lua event name: "DatapanelGUI::setLineProgress"
// Lua signature:  function(self, key, category, progressValue, progressText, showKey, result)
void CallDatapanelGUISetLineProgressCallbacks(DatapanelGUI* thisptr, const std::string& key, int category, float progressValue, const std::string& progressText, bool showKey, DataPanelLine_Progress* result);

// Fired by DatapanelGUI::removeLine hook after the original call.
// Lua event name: "DatapanelGUI::removeLine"
// Lua signature:  function(self, s1, category)
void CallDatapanelGUIRemoveLineCallbacks(DatapanelGUI* thisptr, const std::string& s1, int category);

// Fired by DatapanelGUI::setLineCheckbox hook after the original call.
// Lua event name: "DatapanelGUI::setLineCheckbox"
// Lua signature:  function(self, s1, val, category, result)
void CallDatapanelGUISetLineCheckboxCallbacks(DatapanelGUI* thisptr, const std::string& s1, void* val, int category, DataPanelLine_CheckBox* result);

// Fired by DatapanelGUI::setLineDropBox hook after the original call.
// Lua event name: "DatapanelGUI::setLineDropBox"
// Lua signature:  function(self, key, category, valPtr, goBox, width, result)
void CallDatapanelGUISetLineDropBoxCallbacks(DatapanelGUI* thisptr, const std::string& key, int category, void* valPtr, bool goBox, float width, DataPanelLine_DropBox* result);

// Fired by DatapanelGUI::addSpace hook after the original call.
// Lua event name: "DatapanelGUI::addSpace"
// Lua signature:  function(self, category, h)
void CallDatapanelGUIAddSpaceCallbacks(DatapanelGUI* thisptr, int category, float h);

// Fired by DatapanelGUI::setLines hook after the original call.
// Lua event name: "DatapanelGUI::setLines"
// Lua signature:  function(self, data, category)
void CallDatapanelGUISetLinesCallbacks(DatapanelGUI* thisptr, const lektor<StringPair>& data, int category);

// Fired by DatapanelGUI::_NV_setCategoryIcon hook after the original call.
// Lua event name: "DatapanelGUI::_NV_setCategoryIcon"
// Lua signature:  function(self, cat, image)
void CallDatapanelGUISetCategoryIconCallbacks(DatapanelGUI* thisptr, int cat, const std::string& image);

// Fired by DatapanelGUI::_NV_changeCategory hook after the original call.
// Lua event name: "DatapanelGUI::_NV_changeCategory"
// Lua signature:  function(self, cat)
void CallDatapanelGUIChangeCategoryCallbacks(DatapanelGUI* thisptr, int cat);

// Fired by DatapanelGUI::addCustomLine hook after the original call.
// Lua event name: "DatapanelGUI::addCustomLine"
// Lua signature:  function(self, line)
void CallDatapanelGUIAddCustomLineCallbacks(DatapanelGUI* thisptr, DataPanelLine* line);

// Fired by DatapanelGUI::_NV_autoChangeSelectedObject hook after the original call.
// Lua event name: "DatapanelGUI::_NV_autoChangeSelectedObject"
// Lua signature:  function(self, obj)
void CallDatapanelGUIAutoChangeSelectedObjectCallbacks(DatapanelGUI* thisptr, const hand& obj);

// Fired by DatapanelGUI::_NV_setObject hook after the original call.
// Lua event name: "DatapanelGUI::_NV_setObject"
// Lua signature:  function(self, obj)
void CallDatapanelGUISetObjectCallbacks(DatapanelGUI* thisptr, const hand& obj);

// Fired by DatapanelGUI::_NV_setLineSpacing hook after the original call.
// Lua event name: "DatapanelGUI::_NV_setLineSpacing"
// Lua signature:  function(self, numLinesPerScreen)
void CallDatapanelGUISetLineSpacingCallbacks(DatapanelGUI* thisptr, float numLinesPerScreen);

// Fired by DatapanelGUI::_NV_getLine hook after the original call.
// Lua event name: "DatapanelGUI::_NV_getLine"
// Lua signature:  function(self, key, cat, defaultVal) -> DataPanelLine
// Returning nil or a non-DataPanelLine value keeps defaultVal.
DataPanelLine* CallDatapanelGUIGetLineCallbacks(DatapanelGUI* thisptr, const std::string& key, int cat, DataPanelLine* defaultVal);

// Fired by DatapanelGUI::lineExists hook after the original call.
// Lua event name: "DatapanelGUI::lineExists"
// Lua signature:  function(self, key, cat, defaultVal) -> boolean
bool CallDatapanelGUILineExistsCallbacks(DatapanelGUI* thisptr, const std::string& key, int cat, bool defaultVal);

// Fired by DatapanelGUI::tabButton hook after the original call.
// Lua event name: "DatapanelGUI::tabButton"
// Lua signature:  function(self, sender, arg2, arg3, arg4)
void CallDatapanelGUITabButtonCallbacks(DatapanelGUI* thisptr, MyGUI::Widget* sender, int arg2, int arg3, int arg4);

// Fired by DatapanelGUI::getNumLines hook after the original call.
// Lua event name: "DatapanelGUI::getNumLines"
// Lua signature:  function(self, cat, defaultVal) -> integer
int CallDatapanelGUIGetNumLinesCallbacks(DatapanelGUI* thisptr, int cat, int defaultVal);

// Fired by DatapanelGUI::getLineByNum hook after the original call.
// Lua event name: "DatapanelGUI::getLineByNum"
// Lua signature:  function(self, cat, i, defaultVal) -> DataPanelLine
// Returning nil or a non-DataPanelLine value keeps defaultVal.
DataPanelLine* CallDatapanelGUIGetLineByNumCallbacks(DatapanelGUI* thisptr, int cat, int i, DataPanelLine* defaultVal);

// Fired by DatapanelGUI::_DESTRUCTOR hook before the original call.
// Lua event name: "DatapanelGUI::_DESTRUCTOR"
// Lua signature:  function(self)
void CallDatapanelGUIDestructorCallbacks(DatapanelGUI* thisptr);

// Fired by DatapanelGUI::createLine hook after the original call.
// Lua event name: "DatapanelGUI::createLine"
// Lua signature:  function(self, line, category, lastLine, result)
void CallDatapanelGUICreateLineCallbacks(DatapanelGUI* thisptr, DataPanelLine* line, int category, bool lastLine, DataPanelLine* result);

// Fired by DatapanelGUI::getNextVerticalPos hook after the original call.
// Lua event name: "DatapanelGUI::getNextVerticalPos"
// Lua signature:  function(self, category, defaultVal) -> number
float CallDatapanelGUIGetNextVerticalPosCallbacks(DatapanelGUI* thisptr, int category, float defaultVal);

// Fired by DatapanelGUI::closeButtonCallback hook before the original call.
// Lua event name: "DatapanelGUI::closeButtonCallback"
// Lua signature:  function(self, arg1, arg2)
void CallDatapanelGUICloseButtonCallbackCallbacks(DatapanelGUI* thisptr, MyGUI::Widget* arg1, const std::string& arg2);

// Fired by DatapanelGUI::mouseOverCallback hook after the original call.
// Lua event name: "DatapanelGUI::mouseOverCallback"
// Lua signature:  function(self, sender)
void CallDatapanelGUIMouseOverCallbackCallbacks(DatapanelGUI* thisptr, MyGUI::Widget* sender);

// Fired by DatapanelGUI::notifyMouseWheel hook after the original call.
// Lua event name: "DatapanelGUI::notifyMouseWheel"
// Lua signature:  function(self, sender, rel)
void CallDatapanelGUINotifyMouseWheelCallbacks(DatapanelGUI* thisptr, MyGUI::Widget* sender, int rel);

// Fired by DatapanelGUI::getCoords hook after the original call.
// Lua event name: "DatapanelGUI::getCoords"
// Lua signature:  function(self, left, top, width, height, result)
void CallDatapanelGUIGetCoordsCallbacks(DatapanelGUI* thisptr, float left, float top, float width, float height, const MyGUI::IntCoord& result);

// Fired by DatapanelGUI::dataExists hook after the original call.
// Lua event name: "DatapanelGUI::dataExists"
// Lua signature:  function(self, cat, name, defaultVal) -> boolean
bool CallDatapanelGUIDataExistsCallbacks(DatapanelGUI* thisptr, int cat, const std::string& name, bool defaultVal);

// Fired by DatapanelGUI::clearCategoryTabs hook after the original call.
// Lua event name: "DatapanelGUI::clearCategoryTabs"
// Lua signature:  function(self)
void CallDatapanelGUIClearCategoryTabsCallbacks(DatapanelGUI* thisptr);


// -----------------------------------------------------------
// Callbacks for hooks in DataPanelLine.h
// -----------------------------------------------------------

// Fired by DataPanelLine::_DESTRUCTOR hook before the original call.
// Lua event name: "DataPanelLine::_DESTRUCTOR"
// Lua signature:  function(self)
void CallDataPanelLineDestructorCallbacks(DataPanelLine* thisptr);

// Fired by DataPanelLine::_NV_setVisible hook after the original call.
// Lua event name: "DataPanelLine::_NV_setVisible"
// Lua signature:  function(self, on)
void CallDataPanelLineSetVisibleCallbacks(DataPanelLine* thisptr, bool on);

// Fired by DataPanelLine::_NV_setEnabled hook after the original call.
// Lua event name: "DataPanelLine::_NV_setEnabled"
// Lua signature:  function(self, on)
void CallDataPanelLineSetEnabledCallbacks(DataPanelLine* thisptr, bool on);

// Fired by DataPanelLine::_NV_refresh hook after the original call.
// Lua event name: "DataPanelLine::_NV_refresh"
// Lua signature:  function(self)
void CallDataPanelLineRefreshCallbacks(DataPanelLine* thisptr);

// Fired by DataPanelLine::_NV_createMe hook after the original call.
// Lua event name: "DataPanelLine::_NV_createMe"
// Lua signature:  function(self, parent, top, lastLine)
void CallDataPanelLineCreateMeCallbacks(DataPanelLine* thisptr, DatapanelGUI* parent, float top, bool lastLine);

// Fired by DataPanelLine::_NV_resize hook after the original call.
// Lua event name: "DataPanelLine::_NV_resize"
// Lua signature:  function(self, width, height)
void CallDataPanelLineResizeCallbacks(DataPanelLine* thisptr, int width, int height);

// Fired by DataPanelLine::_NV_getBottom hook after the original call.
// Lua event name: "DataPanelLine::_NV_getBottom"
// Lua signature:  function(self, defaultVal) -> integer
int CallDataPanelLineGetBottomCallbacks(DataPanelLine* thisptr, int defaultVal);

// Fired by DataPanelLine_Faction::_CONSTRUCTOR hook after the original call.
// Lua event name: "DataPanelLine_Faction::_CONSTRUCTOR"
// Lua signature:  function(self, a, b, cat, vv1, vv2)
void CallDataPanelLineFactionConstructedCallbacks(DataPanelLine_Faction* thisptr, const std::string& a, const std::string& b, int cat, float vv1, float vv2);

// Fired by DataPanelLine_Faction::_NV_createMe hook after the original call.
// Lua event name: "DataPanelLine_Faction::_NV_createMe"
// Lua signature:  function(self, parent, top, lastLine)
void CallDataPanelLineFactionCreateMeCallbacks(DataPanelLine_Faction* thisptr, DatapanelGUI* parent, float top, bool lastLine);

// Fired by DataPanelLine_Faction::_DESTRUCTOR hook before the original call.
// Lua event name: "DataPanelLine_Faction::_DESTRUCTOR"
// Lua signature:  function(self)
void CallDataPanelLineFactionDestructorCallbacks(DataPanelLine_Faction* thisptr);

// Fired by DataPanelLine_Research::_CONSTRUCTOR hook after the original call.
// Lua event name: "DataPanelLine_Research::_CONSTRUCTOR"
// Lua signature:  function(self, a, b, cat, vv1, barColor, Xbut)
void CallDataPanelLineResearchConstructedCallbacks(DataPanelLine_Research* thisptr, const std::string& a, const std::string& b, int cat, float vv1, const std::string& barColor, bool Xbut);

// Fired by DataPanelLine_Research::_NV_createMe hook after the original call.
// Lua event name: "DataPanelLine_Research::_NV_createMe"
// Lua signature:  function(self, parent, top, lastLine)
void CallDataPanelLineResearchCreateMeCallbacks(DataPanelLine_Research* thisptr, DatapanelGUI* parent, float top, bool lastLine);

// Fired by DataPanelLine_Research::_DESTRUCTOR hook before the original call.
// Lua event name: "DataPanelLine_Research::_DESTRUCTOR"
// Lua signature:  function(self)
void CallDataPanelLineResearchDestructorCallbacks(DataPanelLine_Research* thisptr);

// Fired by DataPanelLine_Button::_CONSTRUCTOR hook after the original call.
// Lua event name: "DataPanelLine_Button::_CONSTRUCTOR"
// Lua signature:  function(self, a, b, cat, w, skin)
void CallDataPanelLineButtonConstructedCallbacks(DataPanelLine_Button* thisptr, const std::string& a, const std::string& b, int cat, float w, const std::string& skin);

// Fired by DataPanelLine_Button::_NV_getUserData hook after the original call.
// Lua event name: "DataPanelLine_Button::_NV_getUserData"
// Lua signature:  function(self, result)
void CallDataPanelLineButtonGetUserDataCallbacks(DataPanelLine_Button* thisptr, const hand& result);

// Fired by DataPanelLine_Button::_NV_createMe hook after the original call.
// Lua event name: "DataPanelLine_Button::_NV_createMe"
// Lua signature:  function(self, parent, top, lastLine)
void CallDataPanelLineButtonCreateMeCallbacks(DataPanelLine_Button* thisptr, DatapanelGUI* parent, float top, bool lastLine);

// Fired by DataPanelLine_Button::_DESTRUCTOR hook before the original call.
// Lua event name: "DataPanelLine_Button::_DESTRUCTOR"
// Lua signature:  function(self)
void CallDataPanelLineButtonDestructorCallbacks(DataPanelLine_Button* thisptr);

// Fired by DataPanelLine_SliderEditable::setEditableValuePtr hook after the original call.
// Lua event name: "DataPanelLine_SliderEditable::setEditableValuePtr"
// Lua signature:  function(self, val, lo, hi)
void CallDataPanelLineSliderEditableSetEditableValuePtrCallbacks(DataPanelLine_SliderEditable* thisptr, void* val, float lo, float hi);

// Fired by DataPanelLine_SliderEditable::_NV_updateValuePtr hook after the original call.
// Lua event name: "DataPanelLine_SliderEditable::_NV_updateValuePtr"
// Lua signature:  function(self, ptr)
void CallDataPanelLineSliderEditableUpdateValuePtrCallbacks(DataPanelLine_SliderEditable* thisptr, void* ptr);

// Fired by DataPanelLine_SliderEditable::setValue hook after the original call.
// Lua event name: "DataPanelLine_SliderEditable::setValue"
// Lua signature:  function(self, v)
void CallDataPanelLineSliderEditableSetValueCallbacks(DataPanelLine_SliderEditable* thisptr, float v);

// Fired by DataPanelLine_SliderEditable::_NV_refresh hook after the original call.
// Lua event name: "DataPanelLine_SliderEditable::_NV_refresh"
// Lua signature:  function(self)
void CallDataPanelLineSliderEditableRefreshCallbacks(DataPanelLine_SliderEditable* thisptr);

// Fired by DataPanelLine_SliderEditable::setPrecision hook after the original call.
// Lua event name: "DataPanelLine_SliderEditable::setPrecision"
// Lua signature:  function(self, dp)
void CallDataPanelLineSliderEditableSetPrecisionCallbacks(DataPanelLine_SliderEditable* thisptr, int dp);

// Fired by DataPanelLine_SliderEditable::_CONSTRUCTOR hook after the original call.
// Lua event name: "DataPanelLine_SliderEditable::_CONSTRUCTOR"
// Lua signature:  function(self, text, category, showName, min, max, value)
void CallDataPanelLineSliderEditableConstructedCallbacks(DataPanelLine_SliderEditable* thisptr, const std::string& text, int category, bool showName, float min, float max, void* value);

// Fired by DataPanelLine_SliderEditable::_NV_createMe hook after the original call.
// Lua event name: "DataPanelLine_SliderEditable::_NV_createMe"
// Lua signature:  function(self, parent, top, lastLine)
void CallDataPanelLineSliderEditableCreateMeCallbacks(DataPanelLine_SliderEditable* thisptr, DatapanelGUI* parent, float top, bool lastLine);

// Fired by DataPanelLine_SliderEditable::editCallback hook after the original call.
// Lua event name: "DataPanelLine_SliderEditable::editCallback"
// Lua signature:  function(self, sender)
void CallDataPanelLineSliderEditableEditCallbackCallbacks(DataPanelLine_SliderEditable* thisptr, MyGUI::Widget* sender);

// Fired by DataPanelLine_SliderEditable::sliderCallback hook after the original call.
// Lua event name: "DataPanelLine_SliderEditable::sliderCallback"
// Lua signature:  function(self, sender, position)
void CallDataPanelLineSliderEditableSliderCallbackCallbacks(DataPanelLine_SliderEditable* thisptr, MyGUI::Widget* sender, int position);

// Fired by DataPanelLine_SliderEditable::_DESTRUCTOR hook before the original call.
// Lua event name: "DataPanelLine_SliderEditable::_DESTRUCTOR"
// Lua signature:  function(self)
void CallDataPanelLineSliderEditableDestructorCallbacks(DataPanelLine_SliderEditable* thisptr);

// Fired by DataPanelLine_Text::_CONSTRUCTOR hook after the original call.
// Lua event name: "DataPanelLine_Text::_CONSTRUCTOR"
// Lua signature:  function(self, key, text, category, wordWrap, textAlign)
void CallDataPanelLineTextConstructedCallbacks(DataPanelLine_Text* thisptr, const std::string& key, const std::string& text, int category, bool wordWrap, int textAlign);

// Fired by DataPanelLine_Text::_NV_createMe hook after the original call.
// Lua event name: "DataPanelLine_Text::_NV_createMe"
// Lua signature:  function(self, parent, top, lastLine)
void CallDataPanelLineTextCreateMeCallbacks(DataPanelLine_Text* thisptr, DatapanelGUI* parent, float top, bool lastLine);

// Fired by DataPanelLine_Text::_DESTRUCTOR hook before the original call.
// Lua event name: "DataPanelLine_Text::_DESTRUCTOR"
// Lua signature:  function(self)
void CallDataPanelLineTextDestructorCallbacks(DataPanelLine_Text* thisptr);

// Fired by DataPanelLine_TextEditable::_CONSTRUCTOR hook after the original call.
// Lua event name: "DataPanelLine_TextEditable::_CONSTRUCTOR"
// Lua signature:  function(self, key, text, category, showKey, multiLine, textAlign, width)
void CallDataPanelLineTextEditableConstructedCallbacks(DataPanelLine_TextEditable* thisptr, const std::string& key, const std::string& text, int category, bool showKey, bool multiLine, int textAlign, float width);

// Fired by DataPanelLine_TextEditable::_NV_createMe hook after the original call.
// Lua event name: "DataPanelLine_TextEditable::_NV_createMe"
// Lua signature:  function(self, parent, top, lastLine)
void CallDataPanelLineTextEditableCreateMeCallbacks(DataPanelLine_TextEditable* thisptr, DatapanelGUI* parent, float top, bool lastLine);

// Fired by DataPanelLine_TextEditable::textChanged hook after the original call.
// Lua event name: "DataPanelLine_TextEditable::textChanged"
// Lua signature:  function(self, sender)
void CallDataPanelLineTextEditableTextChangedCallbacks(DataPanelLine_TextEditable* thisptr, MyGUI::Widget* sender);

// Fired by DataPanelLine_TextEditable::_DESTRUCTOR hook before the original call.
// Lua event name: "DataPanelLine_TextEditable::_DESTRUCTOR"
// Lua signature:  function(self)
void CallDataPanelLineTextEditableDestructorCallbacks(DataPanelLine_TextEditable* thisptr);

// Fired by DataPanelLine_Slider::_CONSTRUCTOR hook after the original call.
// Lua event name: "DataPanelLine_Slider::_CONSTRUCTOR"
// Lua signature:  function(self, key, text, min, max, category, scale)
void CallDataPanelLineSliderConstructedCallbacks(DataPanelLine_Slider* thisptr, const std::string& key, const std::string& text, float min, float max, int category, float scale);

// Fired by DataPanelLine_Slider::sliderValueChanged hook after the original call.
// Lua event name: "DataPanelLine_Slider::sliderValueChanged"
// Lua signature:  function(self, sender, value)
void CallDataPanelLineSliderSliderValueChangedCallbacks(DataPanelLine_Slider* thisptr, MyGUI::Widget* sender, int value);

// Fired by DataPanelLine_Slider::_NV_updateValuePtr hook after the original call.
// Lua event name: "DataPanelLine_Slider::_NV_updateValuePtr"
// Lua signature:  function(self, ptr)
void CallDataPanelLineSliderUpdateValuePtrCallbacks(DataPanelLine_Slider* thisptr, void* ptr);

// Fired by DataPanelLine_Slider::setValue hook after the original call.
// Lua event name: "DataPanelLine_Slider::setValue"
// Lua signature:  function(self, value)
void CallDataPanelLineSliderSetValueCallbacks(DataPanelLine_Slider* thisptr, float value);

// Fired by DataPanelLine_Slider::getValue hook after the original call.
// Lua event name: "DataPanelLine_Slider::getValue"
// Lua signature:  function(self, defaultVal) -> number
float CallDataPanelLineSliderGetValueCallbacks(DataPanelLine_Slider* thisptr, float defaultVal);

// Fired by DataPanelLine_Slider::_NV_refresh hook after the original call.
// Lua event name: "DataPanelLine_Slider::_NV_refresh"
// Lua signature:  function(self)
void CallDataPanelLineSliderRefreshCallbacks(DataPanelLine_Slider* thisptr);

// Fired by DataPanelLine_Slider::_NV_createMe hook after the original call.
// Lua event name: "DataPanelLine_Slider::_NV_createMe"
// Lua signature:  function(self, parent, top, lastLine)
void CallDataPanelLineSliderCreateMeCallbacks(DataPanelLine_Slider* thisptr, DatapanelGUI* parent, float top, bool lastLine);

// Fired by DataPanelLine_Slider::_DESTRUCTOR hook before the original call.
// Lua event name: "DataPanelLine_Slider::_DESTRUCTOR"
// Lua signature:  function(self)
void CallDataPanelLineSliderDestructorCallbacks(DataPanelLine_Slider* thisptr);

// Fired by DataPanelLine_Progress::setProgress hook after the original call.
// Lua event name: "DataPanelLine_Progress::setProgress"
// Lua signature:  function(self, value, text)
void CallDataPanelLineProgressSetProgressCallbacks(DataPanelLine_Progress* thisptr, float value, const std::string& text);

// Fired by DataPanelLine_Progress::_CONSTRUCTOR hook after the original call.
// Lua event name: "DataPanelLine_Progress::_CONSTRUCTOR"
// Lua signature:  function(self, key, category, showKey)
void CallDataPanelLineProgressConstructedCallbacks(DataPanelLine_Progress* thisptr, const std::string& key, int category, bool showKey);

// Fired by DataPanelLine_Progress::_NV_createMe hook after the original call.
// Lua event name: "DataPanelLine_Progress::_NV_createMe"
// Lua signature:  function(self, parent, top, lastLine)
void CallDataPanelLineProgressCreateMeCallbacks(DataPanelLine_Progress* thisptr, DatapanelGUI* parent, float top, bool lastLine);

// Fired by DataPanelLine_Progress::_DESTRUCTOR hook before the original call.
// Lua event name: "DataPanelLine_Progress::_DESTRUCTOR"
// Lua signature:  function(self)
void CallDataPanelLineProgressDestructorCallbacks(DataPanelLine_Progress* thisptr);

// Fired by DataPanelLine_CheckBox::_NV_updateValuePtr hook after the original call.
// Lua event name: "DataPanelLine_CheckBox::_NV_updateValuePtr"
// Lua signature:  function(self, ptr)
void CallDataPanelLineCheckBoxUpdateValuePtrCallbacks(DataPanelLine_CheckBox* thisptr, void* ptr);

// Fired by DataPanelLine_CheckBox::_NV_refresh hook after the original call.
// Lua event name: "DataPanelLine_CheckBox::_NV_refresh"
// Lua signature:  function(self)
void CallDataPanelLineCheckBoxRefreshCallbacks(DataPanelLine_CheckBox* thisptr);

// Fired by DataPanelLine_CheckBox::setValue hook after the original call.
// Lua event name: "DataPanelLine_CheckBox::setValue"
// Lua signature:  function(self, checked)
void CallDataPanelLineCheckBoxSetValueCallbacks(DataPanelLine_CheckBox* thisptr, bool checked);

// Fired by DataPanelLine_CheckBox::setValuePtr hook after the original call.
// Lua event name: "DataPanelLine_CheckBox::setValuePtr"
// Lua signature:  function(self, valPtr)
void CallDataPanelLineCheckBoxSetValuePtrCallbacks(DataPanelLine_CheckBox* thisptr, void* valPtr);

// Fired by DataPanelLine_CheckBox::_CONSTRUCTOR hook after the original call.
// Lua event name: "DataPanelLine_CheckBox::_CONSTRUCTOR"
// Lua signature:  function(self, key, cat, val)
void CallDataPanelLineCheckBoxConstructedCallbacks(DataPanelLine_CheckBox* thisptr, const std::string& key, int cat, void* val);

// Fired by DataPanelLine_CheckBox::notifyToggleCheck hook after the original call.
// Lua event name: "DataPanelLine_CheckBox::notifyToggleCheck"
// Lua signature:  function(self, sender)
void CallDataPanelLineCheckBoxNotifyToggleCheckCallbacks(DataPanelLine_CheckBox* thisptr, MyGUI::Widget* sender);

// Fired by DataPanelLine_CheckBox::_NV_createMe hook after the original call.
// Lua event name: "DataPanelLine_CheckBox::_NV_createMe"
// Lua signature:  function(self, parent, topReal, lastLine)
void CallDataPanelLineCheckBoxCreateMeCallbacks(DataPanelLine_CheckBox* thisptr, DatapanelGUI* parent, float topReal, bool lastLine);

// Fired by DataPanelLine_CheckBox::_DESTRUCTOR hook before the original call.
// Lua event name: "DataPanelLine_CheckBox::_DESTRUCTOR"
// Lua signature:  function(self)
void CallDataPanelLineCheckBoxDestructorCallbacks(DataPanelLine_CheckBox* thisptr);

// Fired by DataPanelLine_DropBox::addAValue hook after the original call.
// Lua event name: "DataPanelLine_DropBox::addAValue"
// Lua signature:  function(self, key, val)
void CallDataPanelLineDropBoxAddAValueCallbacks(DataPanelLine_DropBox* thisptr, const std::string& key, int val);

// Fired by DataPanelLine_DropBox::getSelectedValue hook after the original call.
// Lua event name: "DataPanelLine_DropBox::getSelectedValue"
// Lua signature:  function(self, defaultVal) -> integer
int CallDataPanelLineDropBoxGetSelectedValueCallbacks(DataPanelLine_DropBox* thisptr, int defaultVal);

// Fired by DataPanelLine_DropBox::setSelectedValue hook after the original call.
// Lua event name: "DataPanelLine_DropBox::setSelectedValue"
// Lua signature:  function(self, val)
void CallDataPanelLineDropBoxSetSelectedValueCallbacks(DataPanelLine_DropBox* thisptr, int val);

// Fired by DataPanelLine_DropBox::getSelectedText hook after the original call.
// Lua event name: "DataPanelLine_DropBox::getSelectedText"
// Lua signature:  function(self, result)
void CallDataPanelLineDropBoxGetSelectedTextCallbacks(DataPanelLine_DropBox* thisptr, const std::string& result);

// Fired by DataPanelLine_DropBox::clearValues hook after the original call.
// Lua event name: "DataPanelLine_DropBox::clearValues"
// Lua signature:  function(self)
void CallDataPanelLineDropBoxClearValuesCallbacks(DataPanelLine_DropBox* thisptr);

// Fired by DataPanelLine_DropBox::_NV_createMe hook after the original call.
// Lua event name: "DataPanelLine_DropBox::_NV_createMe"
// Lua signature:  function(self, parent, top, lastLine)
void CallDataPanelLineDropBoxCreateMeCallbacks(DataPanelLine_DropBox* thisptr, DatapanelGUI* parent, float top, bool lastLine);

// Fired by DataPanelLine_DropBox::_NV_updateValuePtr hook after the original call.
// Lua event name: "DataPanelLine_DropBox::_NV_updateValuePtr"
// Lua signature:  function(self, ptr)
void CallDataPanelLineDropBoxUpdateValuePtrCallbacks(DataPanelLine_DropBox* thisptr, void* ptr);

// Fired by DataPanelLine_DropBox::_NV_refresh hook after the original call.
// Lua event name: "DataPanelLine_DropBox::_NV_refresh"
// Lua signature:  function(self)
void CallDataPanelLineDropBoxRefreshCallbacks(DataPanelLine_DropBox* thisptr);

// Fired by DataPanelLine_DropBox::_CONSTRUCTOR hook after the original call.
// Lua event name: "DataPanelLine_DropBox::_CONSTRUCTOR"
// Lua signature:  function(self, text, category, valuePtr, width, hasGobox)
void CallDataPanelLineDropBoxConstructedCallbacks(DataPanelLine_DropBox* thisptr, const std::string& text, int category, void* valuePtr, float width, bool hasGobox);

// Fired by DataPanelLine_DropBox::selectionChange hook after the original call.
// Lua event name: "DataPanelLine_DropBox::selectionChange"
// Lua signature:  function(self, sender, i)
void CallDataPanelLineDropBoxSelectionChangeCallbacks(DataPanelLine_DropBox* thisptr, MyGUI::Widget* sender, int i);

// Fired by DataPanelLine_DropBox::goPressed hook after the original call.
// Lua event name: "DataPanelLine_DropBox::goPressed"
// Lua signature:  function(self, sender)
void CallDataPanelLineDropBoxGoPressedCallbacks(DataPanelLine_DropBox* thisptr, MyGUI::Widget* sender);

// Fired by DataPanelLine_DropBox::_DESTRUCTOR hook before the original call.
// Lua event name: "DataPanelLine_DropBox::_DESTRUCTOR"
// Lua signature:  function(self)
void CallDataPanelLineDropBoxDestructorCallbacks(DataPanelLine_DropBox* thisptr);

// Fired by DataPanelLine_KeyConfig::_CONSTRUCTOR hook after the original call.
// Lua event name: "DataPanelLine_KeyConfig::_CONSTRUCTOR"
// Lua signature:  function(self, cmd, text, cat)
void CallDataPanelLineKeyConfigConstructedCallbacks(DataPanelLine_KeyConfig* thisptr, const std::string& cmd, const std::string& text, int cat);

// Fired by DataPanelLine_KeyConfig::getCommand hook after the original call.
// Lua event name: "DataPanelLine_KeyConfig::getCommand"
// Lua signature:  function(self, result)
void CallDataPanelLineKeyConfigGetCommandCallbacks(DataPanelLine_KeyConfig* thisptr, const std::string& result);

// Fired by DataPanelLine_KeyConfig::oldKey hook after the original call.
// Lua event name: "DataPanelLine_KeyConfig::oldKey"
// Lua signature:  function(self, defaultVal) -> integer
int CallDataPanelLineKeyConfigOldKeyCallbacks(DataPanelLine_KeyConfig* thisptr, int defaultVal);

// Fired by DataPanelLine_KeyConfig::setKey hook after the original call.
// Lua event name: "DataPanelLine_KeyConfig::setKey"
// Lua signature:  function(self, s)
void CallDataPanelLineKeyConfigSetKeyCallbacks(DataPanelLine_KeyConfig* thisptr, const std::string& s);

// Fired by DataPanelLine_KeyConfig::eraseKey hook after the original call.
// Lua event name: "DataPanelLine_KeyConfig::eraseKey"
// Lua signature:  function(self, key)
void CallDataPanelLineKeyConfigEraseKeyCallbacks(DataPanelLine_KeyConfig* thisptr, const std::string& key);

// Fired by DataPanelLine_KeyConfig::_NV_refresh hook after the original call.
// Lua event name: "DataPanelLine_KeyConfig::_NV_refresh"
// Lua signature:  function(self)
void CallDataPanelLineKeyConfigRefreshCallbacks(DataPanelLine_KeyConfig* thisptr);

// Fired by DataPanelLine_KeyConfig::cancel hook after the original call.
// Lua event name: "DataPanelLine_KeyConfig::cancel"
// Lua signature:  function(self)
void CallDataPanelLineKeyConfigCancelCallbacks(DataPanelLine_KeyConfig* thisptr);

// Fired by DataPanelLine_KeyConfig::_NV_createMe hook after the original call.
// Lua event name: "DataPanelLine_KeyConfig::_NV_createMe"
// Lua signature:  function(self, p, vpos, lastLine)
void CallDataPanelLineKeyConfigCreateMeCallbacks(DataPanelLine_KeyConfig* thisptr, DatapanelGUI* p, float vpos, bool lastLine);

// Fired by DataPanelLine_KeyConfig::clickButton hook after the original call.
// Lua event name: "DataPanelLine_KeyConfig::clickButton"
// Lua signature:  function(self, sender)
void CallDataPanelLineKeyConfigClickButtonCallbacks(DataPanelLine_KeyConfig* thisptr, MyGUI::Widget* sender);

// Fired by DataPanelLine_KeyConfig::_DESTRUCTOR hook before the original call.
// Lua event name: "DataPanelLine_KeyConfig::_DESTRUCTOR"
// Lua signature:  function(self)
void CallDataPanelLineKeyConfigDestructorCallbacks(DataPanelLine_KeyConfig* thisptr);


// -----------------------------------------------------------
// Callbacks for hooks in ForgottenGUI.h
// -----------------------------------------------------------

// Fired by ForgottenGUI::_CONSTRUCTOR hook after the original call.
// Lua event name: "ForgottenGUI::_CONSTRUCTOR"
// Lua signature:  function(self)
void CallForgottenGUIConstructedCallbacks(ForgottenGUI* thisptr);

// Fired by ForgottenGUI::_DESTRUCTOR hook before the original call.
// Lua event name: "ForgottenGUI::_DESTRUCTOR"
// Lua signature:  function(self)
void CallForgottenGUIDestructorCallbacks(ForgottenGUI* thisptr);

// Fired by ForgottenGUI::clearGUI hook after the original call.
// Lua event name: "ForgottenGUI::clearGUI"
// Lua signature:  function(self)
void CallForgottenGUIClearGUICallbacks(ForgottenGUI* thisptr);

// Fired by ForgottenGUI::shutDown hook before the original call.
// Lua event name: "ForgottenGUI::shutDown"
// Lua signature:  function(self)
void CallForgottenGUIShutDownCallbacks(ForgottenGUI* thisptr);

// Fired by ForgottenGUI::restart hook after the original call.
// Lua event name: "ForgottenGUI::restart"
// Lua signature:  function(self)
void CallForgottenGUIRestartCallbacks(ForgottenGUI* thisptr);

// Fired by ForgottenGUI::changeFontSize hook after the original call.
// Lua event name: "ForgottenGUI::changeFontSize"
// Lua signature:  function()
void CallForgottenGUIChangeFontSizeCallbacks();

// Fired by ForgottenGUI::setupGuiScaling hook after the original call.
// Lua event name: "ForgottenGUI::setupGuiScaling"
// Lua signature:  function(self)
void CallForgottenGUISetupGuiScalingCallbacks(ForgottenGUI* thisptr);

// Fired by ForgottenGUI::init hook after the original call.
// Lua event name: "ForgottenGUI::init"
// Lua signature:  function(self)
void CallForgottenGUIInitCallbacks(ForgottenGUI* thisptr);

// Fired by ForgottenGUI::getTopOfScreenMessagePosition hook after the original call.
// Lua event name: "ForgottenGUI::getTopOfScreenMessagePosition"
// Lua signature:  function(self, defaultVal) -> number
float CallForgottenGUIGetTopOfScreenMessagePositionCallbacks(ForgottenGUI* thisptr, float defaultVal);

// Fired by ForgottenGUI::showLoadingMessage hook after the original call.
// Lua event name: "ForgottenGUI::showLoadingMessage"
// Lua signature:  function(self, on)
void CallForgottenGUIShowLoadingMessageCallbacks(ForgottenGUI* thisptr, bool on);

// Fired by ForgottenGUI::isLoadingMessageVisible hook after the original call.
// Lua event name: "ForgottenGUI::isLoadingMessageVisible"
// Lua signature:  function(self, defaultVal) -> boolean
bool CallForgottenGUIIsLoadingMessageVisibleCallbacks(ForgottenGUI* thisptr, bool defaultVal);

// Fired by ForgottenGUI::showPauseMessage hook after the original call.
// Lua event name: "ForgottenGUI::showPauseMessage"
// Lua signature:  function(self, on)
void CallForgottenGUIShowPauseMessageCallbacks(ForgottenGUI* thisptr, bool on);

// Fired by ForgottenGUI::isLoading hook after the original call.
// Lua event name: "ForgottenGUI::isLoading"
// Lua signature:  function(self, defaultVal) -> boolean
bool CallForgottenGUIIsLoadingCallbacks(ForgottenGUI* thisptr, bool defaultVal);

// Fired by ForgottenGUI::setLoading hook after the original call.
// Lua event name: "ForgottenGUI::setLoading"
// Lua signature:  function(self, value)
void CallForgottenGUISetLoadingCallbacks(ForgottenGUI* thisptr, bool value);

// Fired by ForgottenGUI::isPaused hook after the original call.
// Lua event name: "ForgottenGUI::isPaused"
// Lua signature:  function(self, defaultVal) -> boolean
bool CallForgottenGUIIsPausedCallbacks(ForgottenGUI* thisptr, bool defaultVal);

// Fired by ForgottenGUI::inDialogue hook after the original call.
// Lua event name: "ForgottenGUI::inDialogue"
// Lua signature:  function(self, defaultVal) -> boolean
bool CallForgottenGUIInDialogueCallbacks(ForgottenGUI* thisptr, bool defaultVal);

// Fired by ForgottenGUI::messageBox hook after the original call.
// Lua event name: "ForgottenGUI::messageBox"
// Lua signature:  function(self, title, message, btn, modal, callback, result)
void CallForgottenGUIMessageBoxCallbacks(ForgottenGUI* thisptr, const std::string& title, const std::string& message, int btn, bool modal, void* callback, MyGUI::Widget* result);

// Fired by ForgottenGUI::hideMessageBox hook after the original call.
// Lua event name: "ForgottenGUI::hideMessageBox"
// Lua signature:  function(self, enter, result)
void CallForgottenGUIHideMessageBoxCallbacks(ForgottenGUI* thisptr, bool enter, bool result);

// Fired by ForgottenGUI::hasModalMessage hook after the original call.
// Lua event name: "ForgottenGUI::hasModalMessage"
// Lua signature:  function(self, defaultVal) -> boolean
bool CallForgottenGUIHasModalMessageCallbacks(ForgottenGUI* thisptr, bool defaultVal);

// Fired by ForgottenGUI::showMainbar hook after the original call.
// Lua event name: "ForgottenGUI::showMainbar"
// Lua signature:  function(self, on)
void CallForgottenGUIShowMainbarCallbacks(ForgottenGUI* thisptr, bool on);

// Fired by ForgottenGUI::updateBountyPanelVisibility hook after the original call.
// Lua event name: "ForgottenGUI::updateBountyPanelVisibility"
// Lua signature:  function(self)
void CallForgottenGUIUpdateBountyPanelVisibilityCallbacks(ForgottenGUI* thisptr);

// Fired by ForgottenGUI::getInDialogue hook after the original call.
// Lua event name: "ForgottenGUI::getInDialogue"
// Lua signature:  function(self, defaultVal) -> boolean
bool CallForgottenGUIGetInDialogueCallbacks(ForgottenGUI* thisptr, bool defaultVal);

// Fired by ForgottenGUI::getToolTip hook after the original call.
// Lua event name: "ForgottenGUI::getToolTip"
// Lua signature:  function(self, defaultVal) -> ToolTip
// Returning nil or a non-ToolTip value keeps defaultVal.
ToolTip* CallForgottenGUIGetToolTipCallbacks(ForgottenGUI* thisptr, ToolTip* defaultVal);

// Fired by ForgottenGUI::toggle hook after the original call.
// Lua event name: "ForgottenGUI::toggle"
// Lua signature:  function(self)
void CallForgottenGUIToggleCallbacks(ForgottenGUI* thisptr);

// Fired by ForgottenGUI::showNames hook after the original call.
// Lua event name: "ForgottenGUI::showNames"
// Lua signature:  function(self, on)
void CallForgottenGUIShowNamesCallbacks(ForgottenGUI* thisptr, bool on);

// Fired by ForgottenGUI::showPrintOutput hook after the original call.
// Lua event name: "ForgottenGUI::showPrintOutput"
// Lua signature:  function(self, v)
void CallForgottenGUIShowPrintOutputCallbacks(ForgottenGUI* thisptr, bool v);

// Fired by ForgottenGUI::showCharacterEditor hook before the original call.
// Lua event name: "ForgottenGUI::showCharacterEditor"
// Lua signature:  function(self, characters, mode, races)
void CallForgottenGUIShowCharacterEditorCallbacks(ForgottenGUI* thisptr, const lektor<Character*>& characters, int mode, const Ogre::vector<GameDataReference>::type* races);

// Fired by ForgottenGUI::closeCharacterEditor hook after the original call.
// Lua event name: "ForgottenGUI::closeCharacterEditor"
// Lua signature:  function(self)
void CallForgottenGUICloseCharacterEditorCallbacks(ForgottenGUI* thisptr);

// Fired by ForgottenGUI::showCharacterStatsWindow hook after the original call.
// Lua event name: "ForgottenGUI::showCharacterStatsWindow"
// Lua signature:  function(self, owner)
void CallForgottenGUIShowCharacterStatsWindowCallbacks(ForgottenGUI* thisptr, const hand& owner);

// Fired by ForgottenGUI::closeCharacterStatsWindow hook after the original call.
// Lua event name: "ForgottenGUI::closeCharacterStatsWindow"
// Lua signature:  function(self, owner)
void CallForgottenGUICloseCharacterStatsWindowCallbacks(ForgottenGUI* thisptr, const hand& owner);

// Fired by ForgottenGUI::closeAllCharacterStatsWindows hook after the original call.
// Lua event name: "ForgottenGUI::closeAllCharacterStatsWindows"
// Lua signature:  function(self)
void CallForgottenGUICloseAllCharacterStatsWindowsCallbacks(ForgottenGUI* thisptr);

// Fired by ForgottenGUI::isStatsWindowOpen hook after the original call.
// Lua event name: "ForgottenGUI::isStatsWindowOpen"
// Lua signature:  function(self, defaultVal) -> boolean
bool CallForgottenGUIIsStatsWindowOpenCallbacks(ForgottenGUI* thisptr, bool defaultVal);

// Fired by ForgottenGUI::toggleStatsWindow hook after the original call.
// Lua event name: "ForgottenGUI::toggleStatsWindow"
// Lua signature:  function(self, owner)
void CallForgottenGUIToggleStatsWindowCallbacks(ForgottenGUI* thisptr, const hand& owner);

// Fired by ForgottenGUI::toggleCharacterStatsWindowPermanent hook after the original call.
// Lua event name: "ForgottenGUI::toggleCharacterStatsWindowPermanent"
// Lua signature:  function(self, owner)
void CallForgottenGUIToggleCharacterStatsWindowPermanentCallbacks(ForgottenGUI* thisptr, const hand& owner);

// Fired by ForgottenGUI::selectedObjectsChanged hook after the original call.
// Lua event name: "ForgottenGUI::selectedObjectsChanged"
// Lua signature:  function(self)
void CallForgottenGUISelectedObjectsChangedCallbacks(ForgottenGUI* thisptr);

// Fired by ForgottenGUI::updateToOrdersPanel hook after the original call.
// Lua event name: "ForgottenGUI::updateToOrdersPanel"
// Lua signature:  function(self)
void CallForgottenGUIUpdateToOrdersPanelCallbacks(ForgottenGUI* thisptr);

// Fired by ForgottenGUI::notifyTownDeleted hook after the original call.
// Lua event name: "ForgottenGUI::notifyTownDeleted"
// Lua signature:  function(self, t)
void CallForgottenGUINotifyTownDeletedCallbacks(ForgottenGUI* thisptr, Town* t);

// Fired by ForgottenGUI::update hook after the original call.
// Lua event name: "ForgottenGUI::update"
// Lua signature:  function(self)
void CallForgottenGUIUpdateCallbacks(ForgottenGUI* thisptr);

// Fired by ForgottenGUI::showTradeWindow hook after the original call.
// Lua event name: "ForgottenGUI::showTradeWindow"
// Lua signature:  function(self, a, b, type)
void CallForgottenGUIShowTradeWindowCallbacks(ForgottenGUI* thisptr, const hand& a, const hand& b, int type);

// Fired by ForgottenGUI::closeTradeWindow hook after the original call.
// Lua event name: "ForgottenGUI::closeTradeWindow"
// Lua signature:  function(self)
void CallForgottenGUICloseTradeWindowCallbacks(ForgottenGUI* thisptr);

// Fired by ForgottenGUI::showInventory hook after the original call.
// Lua event name: "ForgottenGUI::showInventory"
// Lua signature:  function(self, owner, autoPosition, x, y, result)
void CallForgottenGUIShowInventoryCallbacks(ForgottenGUI* thisptr, const hand& owner, bool autoPosition, float x, float y, InventoryGUI* result);

// Fired by ForgottenGUI::showTraderInventory hook after the original call.
// Lua event name: "ForgottenGUI::showTraderInventory"
// Lua signature:  function(self, owner, result)
void CallForgottenGUIShowTraderInventoryCallbacks(ForgottenGUI* thisptr, const hand& owner, InventoryGUI* result);

// Fired by ForgottenGUI::showInventoryBuilding hook after the original call.
// Lua event name: "ForgottenGUI::showInventoryBuilding"
// Lua signature:  function(self, owner, result)
void CallForgottenGUIShowInventoryBuildingCallbacks(ForgottenGUI* thisptr, const hand& owner, InventoryGUI* result);

// Fired by ForgottenGUI::showInventoryNPC hook after the original call.
// Lua event name: "ForgottenGUI::showInventoryNPC"
// Lua signature:  function(self, owner, result)
void CallForgottenGUIShowInventoryNPCCallbacks(ForgottenGUI* thisptr, const hand& owner, InventoryGUI* result);

// Fired by ForgottenGUI::closeInventory hook after the original call.
// Lua event name: "ForgottenGUI::closeInventory"
// Lua signature:  function(self, owner)
void CallForgottenGUICloseInventoryCallbacks(ForgottenGUI* thisptr, const hand& owner);

// Fired by ForgottenGUI::closeInventoryBuilding hook after the original call.
// Lua event name: "ForgottenGUI::closeInventoryBuilding"
// Lua signature:  function(self)
void CallForgottenGUICloseInventoryBuildingCallbacks(ForgottenGUI* thisptr);

// Fired by ForgottenGUI::closeAllInventories hook after the original call.
// Lua event name: "ForgottenGUI::closeAllInventories"
// Lua signature:  function(self)
void CallForgottenGUICloseAllInventoriesCallbacks(ForgottenGUI* thisptr);

// Fired by ForgottenGUI::closeAllWindows hook after the original call.
// Lua event name: "ForgottenGUI::closeAllWindows"
// Lua signature:  function(self)
void CallForgottenGUICloseAllWindowsCallbacks(ForgottenGUI* thisptr);

// Fired by ForgottenGUI::getInventoryWindow hook after the original call.
// Lua event name: "ForgottenGUI::getInventoryWindow"
// Lua signature:  function(self, who, defaultVal) -> InventoryGUI
// Returning nil or a non-InventoryGUI value keeps defaultVal.
InventoryGUI* CallForgottenGUIGetInventoryWindowCallbacks(ForgottenGUI* thisptr, const hand& who, InventoryGUI* defaultVal);

// Fired by ForgottenGUI::toggleInventory hook after the original call.
// Lua event name: "ForgottenGUI::toggleInventory"
// Lua signature:  function(self, owner, parentInv, attached, result)
void CallForgottenGUIToggleInventoryCallbacks(ForgottenGUI* thisptr, const hand& owner, InventoryGUI* parentInv, bool attached, InventoryGUI* result);

// Fired by ForgottenGUI::getNumOpenInventoryWindows hook after the original call.
// Lua event name: "ForgottenGUI::getNumOpenInventoryWindows"
// Lua signature:  function(self, defaultVal) -> integer
int CallForgottenGUIGetNumOpenInventoryWindowsCallbacks(ForgottenGUI* thisptr, int defaultVal);

// Fired by ForgottenGUI::getInventoryWindowWithMouse hook after the original call.
// Lua event name: "ForgottenGUI::getInventoryWindowWithMouse"
// Lua signature:  function(self, defaultVal) -> InventoryGUI
// Returning nil or a non-InventoryGUI value keeps defaultVal.
InventoryGUI* CallForgottenGUIGetInventoryWindowWithMouseCallbacks(ForgottenGUI* thisptr, InventoryGUI* defaultVal);

// Fired by ForgottenGUI::hasInventoryWindowOpen hook after the original call.
// Lua event name: "ForgottenGUI::hasInventoryWindowOpen"
// Lua signature:  function(self, obj, defaultVal) -> boolean
bool CallForgottenGUIHasInventoryWindowOpenCallbacks(ForgottenGUI* thisptr, const hand& obj, bool defaultVal);

// Fired by ForgottenGUI::isAnyInventoryWindowOpen hook after the original call.
// Lua event name: "ForgottenGUI::isAnyInventoryWindowOpen"
// Lua signature:  function(self, defaultVal) -> boolean
bool CallForgottenGUIIsAnyInventoryWindowOpenCallbacks(ForgottenGUI* thisptr, bool defaultVal);

// Fired by ForgottenGUI::toggleInventoryWindowPermanent hook after the original call.
// Lua event name: "ForgottenGUI::toggleInventoryWindowPermanent"
// Lua signature:  function(self, owner)
void CallForgottenGUIToggleInventoryWindowPermanentCallbacks(ForgottenGUI* thisptr, const hand& owner);

// Fired by ForgottenGUI::toggleHelpWindow hook after the original call.
// Lua event name: "ForgottenGUI::toggleHelpWindow"
// Lua signature:  function(self)
void CallForgottenGUIToggleHelpWindowCallbacks(ForgottenGUI* thisptr);

// Fired by ForgottenGUI::addWindowToUpdateList hook after the original call.
// Lua event name: "ForgottenGUI::addWindowToUpdateList"
// Lua signature:  function(self, win)
void CallForgottenGUIAddWindowToUpdateListCallbacks(ForgottenGUI* thisptr, GUIWindow* win);

// Fired by ForgottenGUI::removeWindowFromUpdateList hook after the original call.
// Lua event name: "ForgottenGUI::removeWindowFromUpdateList"
// Lua signature:  function(self, win)
void CallForgottenGUIRemoveWindowFromUpdateListCallbacks(ForgottenGUI* thisptr, GUIWindow* win);

// Fired by ForgottenGUI::addScreenLabel hook after the original call.
// Lua event name: "ForgottenGUI::addScreenLabel"
// Lua signature:  function(self, label)
void CallForgottenGUIAddScreenLabelCallbacks(ForgottenGUI* thisptr, ScreenLabelInterface* label);

// Fired by ForgottenGUI::addDatapanelToUpdateList hook after the original call.
// Lua event name: "ForgottenGUI::addDatapanelToUpdateList"
// Lua signature:  function(self, datapanel)
void CallForgottenGUIAddDatapanelToUpdateListCallbacks(ForgottenGUI* thisptr, DatapanelGUI* datapanel);

// Fired by ForgottenGUI::removeDatapanelFromUpdateList hook after the original call.
// Lua event name: "ForgottenGUI::removeDatapanelFromUpdateList"
// Lua signature:  function(self, datapanel)
void CallForgottenGUIRemoveDatapanelFromUpdateListCallbacks(ForgottenGUI* thisptr, DatapanelGUI* datapanel);

// Fired by ForgottenGUI::destroyWidget hook before the original call.
// Lua event name: "ForgottenGUI::destroyWidget"
// Lua signature:  function(self, widget)
void CallForgottenGUIDestroyWidgetCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* widget);

// Fired by ForgottenGUI::widgetHasMouse hook after the original call.
// Lua event name: "ForgottenGUI::widgetHasMouse"
// Lua signature:  function(self, w, defaultVal) -> boolean
bool CallForgottenGUIWidgetHasMouseCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* w, bool defaultVal);

// Fired by ForgottenGUI::setup hook after the original call.
// Lua event name: "ForgottenGUI::setup"
// Lua signature:  function(self, mRoot, window)
void CallForgottenGUISetupCallbacks(ForgottenGUI* thisptr, void* mRoot, void* window);

// Fired by ForgottenGUI::setMouseCursorVisible hook after the original call.
// Lua event name: "ForgottenGUI::setMouseCursorVisible"
// Lua signature:  function(self, visible)
void CallForgottenGUISetMouseCursorVisibleCallbacks(ForgottenGUI* thisptr, bool visible);

// Fired by ForgottenGUI::_showTradeWindow hook after the original call.
// Lua event name: "ForgottenGUI::_showTradeWindow"
// Lua signature:  function(self, a, b, tradeType)
void CallForgottenGUI_showTradeWindowCallbacks(ForgottenGUI* thisptr, RootObject* a, RootObject* b, int tradeType);

// Fired by ForgottenGUI::setInventoryPosition hook after the original call.
// Lua event name: "ForgottenGUI::setInventoryPosition"
// Lua signature:  function(self, owner, inventory)
void CallForgottenGUISetInventoryPositionCallbacks(ForgottenGUI* thisptr, const hand& owner, InventoryGUI* inventory);

// Fired by ForgottenGUI::inventoriesSelectedObjectUpdate hook after the original call.
// Lua event name: "ForgottenGUI::inventoriesSelectedObjectUpdate"
// Lua signature:  function(self, selectedObject)
void CallForgottenGUIInventoriesSelectedObjectUpdateCallbacks(ForgottenGUI* thisptr, const hand& selectedObject);

// Fired by ForgottenGUI::keepWindownOnScreen hook after the original call.
// Lua event name: "ForgottenGUI::keepWindownOnScreen"
// Lua signature:  function(self, win)
void CallForgottenGUIKeepWindownOnScreenCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* win);

// Fired by ForgottenGUI::getDataLineColor hook after the original call.
// Lua event name: "ForgottenGUI::getDataLineColor"
// Lua signature:  function(self, actualVal, normalVal, result)
void CallForgottenGUIGetDataLineColorCallbacks(ForgottenGUI* thisptr, int actualVal, int normalVal, const std::string& result);

// Fired by ForgottenGUI::createPanel hook after the original call.
// Lua event name: "ForgottenGUI::createPanel"
// Lua signature:  function(self, name, top, left, width, height, layer, skin, result)
void CallForgottenGUICreatePanelCallbacks(ForgottenGUI* thisptr, const std::string& name, float top, float left, float width, float height, const std::string& layer, const std::string& skin, MyGUI::Widget* result);

// Fired by ForgottenGUI::createPanelAbs hook after the original call.
// Lua event name: "ForgottenGUI::createPanelAbs"
// Lua signature:  function(self, name, top, left, width, height, layer, skin, result)
void CallForgottenGUICreatePanelAbsCallbacks(ForgottenGUI* thisptr, const std::string& name, float top, float left, float width, float height, const std::string& layer, const std::string& skin, MyGUI::Widget* result);

// Fired by ForgottenGUI::createImage hook after the original call.
// Lua event name: "ForgottenGUI::createImage"
// Lua signature:  function(self, parent, top, left, width, height, image, result)
void CallForgottenGUICreateImageCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, float top, float left, float width, float height, const std::string& image, MyGUI::Widget* result);

// Fired by ForgottenGUI::createImageAbs hook after the original call.
// Lua event name: "ForgottenGUI::createImageAbs"
// Lua signature:  function(self, parent, top, left, width, height, image, result)
void CallForgottenGUICreateImageAbsCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, int top, int left, int width, int height, const std::string& image, MyGUI::Widget* result);

// Fired by ForgottenGUI::createRotatableImageAbs hook after the original call.
// Lua event name: "ForgottenGUI::createRotatableImageAbs"
// Lua signature:  function(self, parent, top, left, width, height, image, result)
void CallForgottenGUICreateRotatableImageAbsCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, int top, int left, int width, int height, const std::string& image, MyGUI::Widget* result);

// Fired by ForgottenGUI::createTabPanel hook after the original call.
// Lua event name: "ForgottenGUI::createTabPanel"
// Lua signature:  function(self, name, top, left, width, height, layer, skin, result)
void CallForgottenGUICreateTabPanelCallbacks(ForgottenGUI* thisptr, const std::string& name, float top, float left, float width, float height, const std::string& layer, const std::string& skin, MyGUI::Widget* result);

// Fired by ForgottenGUI::createButtonAbs hook after the original call.
// Lua event name: "ForgottenGUI::createButtonAbs"
// Lua signature:  function(self, parent, top, left, width, height, name, text, skin, result)
void CallForgottenGUICreateButtonAbsCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, int top, int left, int width, int height, const std::string& name, const std::string& text, const std::string& skin, MyGUI::Widget* result);

// Fired by ForgottenGUI::createButton hook after the original call.
// Lua event name: "ForgottenGUI::createButton"
// Lua signature:  function(self, parent, top, left, width, height, name, text, skin, result)
void CallForgottenGUICreateButtonCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, float top, float left, float width, float height, const std::string& name, const std::string& text, const std::string& skin, MyGUI::Widget* result);

// Fired by ForgottenGUI::createDropBox hook after the original call.
// Lua event name: "ForgottenGUI::createDropBox"
// Lua signature:  function(self, parent, name, top, left, width, height, result)
void CallForgottenGUICreateDropBoxCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, const std::string& name, float top, float left, float width, float height, MyGUI::Widget* result);

// Fired by ForgottenGUI::createDropBoxAbs hook after the original call.
// Lua event name: "ForgottenGUI::createDropBoxAbs"
// Lua signature:  function(self, parent, name, top, left, width, height, result)
void CallForgottenGUICreateDropBoxAbsCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, const std::string& name, int top, int left, int width, int height, MyGUI::Widget* result);

// Fired by ForgottenGUI::createProgressBar hook after the original call.
// Lua event name: "ForgottenGUI::createProgressBar"
// Lua signature:  function(self, parent, top, left, width, height, type, result)
void CallForgottenGUICreateProgressBarCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, float top, float left, float width, float height, const std::string& type, MyGUI::Widget* result);

// Fired by ForgottenGUI::createProgressBarAbs hook after the original call.
// Lua event name: "ForgottenGUI::createProgressBarAbs"
// Lua signature:  function(self, parent, top, left, width, height, type, result)
void CallForgottenGUICreateProgressBarAbsCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, float top, float left, float width, float height, const std::string& type, MyGUI::Widget* result);

// Fired by ForgottenGUI::createFloatingLabel hook after the original call.
// Lua event name: "ForgottenGUI::createFloatingLabel"
// Lua signature:  function(self, top, left, width, height, text, a, layer, result)
void CallForgottenGUICreateFloatingLabelCallbacks(ForgottenGUI* thisptr, float top, float left, float width, float height, const std::string& text, int a, const std::string& layer, MyGUI::Widget* result);

// Fired by ForgottenGUI::createValueEdit hook after the original call.
// Lua event name: "ForgottenGUI::createValueEdit"
// Lua signature:  function(self, parent, top, left, width, height, name, result)
void CallForgottenGUICreateValueEditCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, float top, float left, float width, float height, const std::string& name, MyGUI::Widget* result);

// Fired by ForgottenGUI::createScrollBarAbs hook after the original call.
// Lua event name: "ForgottenGUI::createScrollBarAbs"
// Lua signature:  function(self, parent, top, left, width, height, range, value, result)
void CallForgottenGUICreateScrollBarAbsCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, int top, int left, int width, int height, int range, int value, MyGUI::Widget* result);

// Fired by ForgottenGUI::createCheckbox hook after the original call.
// Lua event name: "ForgottenGUI::createCheckbox"
// Lua signature:  function(self, parent, left, top, width, height, caption, result)
void CallForgottenGUICreateCheckboxCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, int left, int top, int width, int height, const std::string& caption, MyGUI::Widget* result);

// Fired by ForgottenGUI::createValueEditTransparent hook after the original call.
// Lua event name: "ForgottenGUI::createValueEditTransparent"
// Lua signature:  function(self, parent, top, left, width, height, name, result)
void CallForgottenGUICreateValueEditTransparentCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, float top, float left, float width, float height, const std::string& name, MyGUI::Widget* result);

// Fired by ForgottenGUI::createListbox hook after the original call.
// Lua event name: "ForgottenGUI::createListbox"
// Lua signature:  function(self, parent, top, left, width, height, result)
void CallForgottenGUICreateListboxCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, float top, float left, float width, float height, MyGUI::Widget* result);

// Fired by ForgottenGUI::createFloatingImage hook after the original call.
// Lua event name: "ForgottenGUI::createFloatingImage"
// Lua signature:  function(self, image, top, left, width, height, layer, result)
void CallForgottenGUICreateFloatingImageCallbacks(ForgottenGUI* thisptr, const std::string& image, float top, float left, float width, float height, const std::string& layer, MyGUI::Widget* result);

// Fired by ForgottenGUI::createFloatingImageAbs hook after the original call.
// Lua event name: "ForgottenGUI::createFloatingImageAbs"
// Lua signature:  function(self, image, top, left, width, height, layer, result)
void CallForgottenGUICreateFloatingImageAbsCallbacks(ForgottenGUI* thisptr, const std::string& image, float top, float left, float width, float height, const std::string& layer, MyGUI::Widget* result);

// Fired by ForgottenGUI::createFloatingProgressBar hook after the original call.
// Lua event name: "ForgottenGUI::createFloatingProgressBar"
// Lua signature:  function(self, result)
void CallForgottenGUICreateFloatingProgressBarCallbacks(ForgottenGUI* thisptr, FloatingProgressBar* result);

// Fired by ForgottenGUI::createScreenLabel hook after the original call.
// Lua event name: "ForgottenGUI::createScreenLabel"
// Lua signature:  function(self, text, textColour, textSize, risingSpeed, result)
void CallForgottenGUICreateScreenLabelCallbacks(ForgottenGUI* thisptr, const std::string& text, const MyGUI::Colour& textColour, int textSize, int risingSpeed, ScreenLabel* result);

// Fired by ForgottenGUI::createScreenLabelD hook after the original call.
// Lua event name: "ForgottenGUI::createScreenLabelD"
// Lua signature:  function(self, text, time, result)
void CallForgottenGUICreateScreenLabelDCallbacks(ForgottenGUI* thisptr, const std::string& text, float time, ScreenLabelDebug* result);

// -----------------------------------------------------------
// Callbacks for hooks in gui/NewGameOptionsWindow.h
// -----------------------------------------------------------

// Fired by NewGameOptionsWindow::_CONSTRUCTOR hook after the original call.
// Lua event name: "NewGameOptionsWindow::_CONSTRUCTOR"
// Lua signature:  function(self)
void CallNewGameOptionsWindowConstructedCallbacks(NewGameOptionsWindow* thisptr);

// Fired by NewGameOptionsWindow::_DESTRUCTOR hook before the original call.
// Lua event name: "NewGameOptionsWindow::_DESTRUCTOR"
// Lua signature:  function(self)
void CallNewGameOptionsWindowDestructorCallbacks(NewGameOptionsWindow* thisptr);

// Fired by NewGameOptionsWindow::setVisible hook after the original call.
// Lua event name: "NewGameOptionsWindow::setVisible"
// Lua signature:  function(self, visible)
void CallNewGameOptionsWindowSetVisibleCallbacks(NewGameOptionsWindow* thisptr, bool visible);

// Fired by NewGameOptionsWindow::getVisible hook after the original call.
// Lua event name: "NewGameOptionsWindow::getVisible"
// Lua signature:  function(self, defaultVal) -> boolean
bool CallNewGameOptionsWindowGetVisibleCallbacks(NewGameOptionsWindow* thisptr, bool defaultVal);

// Fired by NewGameOptionsWindow::setPosition hook after the original call.
// Lua event name: "NewGameOptionsWindow::setPosition"
// Lua signature:  function(self, x, y)
void CallNewGameOptionsWindowSetPositionCallbacks(NewGameOptionsWindow* thisptr, int x, int y);

// Fired by NewGameOptionsWindow::update hook after the original call.
// Lua event name: "NewGameOptionsWindow::update"
// Lua signature:  function(self)
void CallNewGameOptionsWindowUpdateCallbacks(NewGameOptionsWindow* thisptr);

// Fired by NewGameOptionsWindow::setOptions hook after the original call.
// Lua event name: "NewGameOptionsWindow::setOptions"
// Lua signature:  function(self, options)
void CallNewGameOptionsWindowSetOptionsCallbacks(NewGameOptionsWindow* thisptr, const GameplayOptions& options);

// -----------------------------------------------------------
// Additional callbacks for hooks in gui/InventoryGUI.h
// -----------------------------------------------------------

// Fired by InventoryIcon::_CONSTRUCTOR hook.
// Lua event name: "InventoryIcon::_CONSTRUCTOR"
// Lua signature: function(self, item, position, parent)
void CallInventoryIconConstructedCallbacks(InventoryIcon* thisptr, Item* item, const MyGUI::types::TPoint<int>& position, MyGUI::Widget* parent);

// Fired by InventoryIcon::setPosition hook.
// Lua event name: "InventoryIcon::setPosition"
// Lua signature: function(self, position)
void CallInventoryIconSetPositionCallbacks(InventoryIcon* thisptr, const MyGUI::types::TPoint<int>& position);

// Fired by InventoryIcon::getSize hook.
// Lua event name: "InventoryIcon::getSize"
// Lua signature: function(self, result)
void CallInventoryIconGetSizeCallbacks(InventoryIcon* thisptr, const MyGUI::types::TSize<int>& result);

// Fired by InventoryIcon::update hook.
// Lua event name: "InventoryIcon::update"
// Lua signature: function(self)
void CallInventoryIconUpdateCallbacks(InventoryIcon* thisptr);

// Fired by InventoryIcon::getWidget hook.
// Lua event name: "InventoryIcon::getWidget"
// Lua signature: function(self, result)
void CallInventoryIconGetWidgetCallbacks(InventoryIcon* thisptr, MyGUI::Widget* result);

// Fired by InventoryIcon::createIconImage hook.
// Lua event name: "InventoryIcon::createIconImage"
// Lua signature: function(item, name, size)
void CallInventoryIconCreateIconImageCallbacks(Item* item, const std::string& name, const iVector2& size);

// Fired by InventoryIcon::getItemSize hook.
// Lua event name: "InventoryIcon::getItemSize"
// Lua signature: function(itemData, result)
void CallInventoryIconGetItemSizeCallbacks(GameData* itemData, const MyGUI::types::TSize<int>& result);

// Fired by InventoryIcon::getItemPosition hook.
// Lua event name: "InventoryIcon::getItemPosition"
// Lua signature: function(x, y, result)
void CallInventoryIconGetItemPositionCallbacks(int x, int y, const MyGUI::types::TPoint<int>& result);

// Fired by InventoryIcon::_DESTRUCTOR hook.
// Lua event name: "InventoryIcon::_DESTRUCTOR"
// Lua signature: function(self)
void CallInventoryIconDestructorCallbacks(InventoryIcon* thisptr);

// Fired by InventorySectionGUI::_CONSTRUCTOR hook.
// Lua event name: "InventorySectionGUI::_CONSTRUCTOR"
// Lua signature: function(self, widget, sectionName)
void CallInventorySectionGUIConstructedCallbacks(InventorySectionGUI* thisptr, MyGUI::Widget* widget, const std::string& sectionName);

// Fired by InventorySectionGUI::_DESTRUCTOR hook.
// Lua event name: "InventorySectionGUI::_DESTRUCTOR"
// Lua signature: function(self)
void CallInventorySectionGUIDestructorCallbacks(InventorySectionGUI* thisptr);

// Fired by InventorySectionGUI::hasMouse hook.
// Lua event name: "InventorySectionGUI::hasMouse"
// Lua signature: function(self, defaultVal) -> boolean
bool CallInventorySectionGUIHasMouseCallbacks(InventorySectionGUI* thisptr, bool defaultVal);

// Fired by InventorySectionGUI::getItemAbsolutePosition hook.
// Lua event name: "InventorySectionGUI::getItemAbsolutePosition"
// Lua signature: function(self, x, y, result)
void CallInventorySectionGUIGetItemAbsolutePositionCallbacks(InventorySectionGUI* thisptr, int x, int y, const MyGUI::types::TPoint<int>& result);

// Fired by InventorySectionGUI::getWidget hook.
// Lua event name: "InventorySectionGUI::getWidget"
// Lua signature: function(self, result)
void CallInventorySectionGUIGetWidgetCallbacks(InventorySectionGUI* thisptr, MyGUI::Widget* result);

// Fired by InventorySectionGUI::getPositionSlot hook.
// Lua event name: "InventorySectionGUI::getPositionSlot"
// Lua signature: function(self, position, section, round, result)
void CallInventorySectionGUIGetPositionSlotCallbacks(InventorySectionGUI* thisptr, const MyGUI::types::TPoint<int>& position, InventorySection* section, bool round, const MyGUI::types::TPoint<int>& result);

// Fired by InventorySectionGUI::getBestPositionSlot hook.
// Lua event name: "InventorySectionGUI::getBestPositionSlot"
// Lua signature: function(self, position, section, item, slot, defaultVal) -> boolean
bool CallInventorySectionGUIGetBestPositionSlotCallbacks(InventorySectionGUI* thisptr, const MyGUI::types::TPoint<int>& position, InventorySection* section, Item* item, const MyGUI::types::TPoint<int>& slot, bool defaultVal);

// Fired by InventorySectionGUI::setEnabled hook.
// Lua event name: "InventorySectionGUI::setEnabled"
// Lua signature: function(self, value)
void CallInventorySectionGUISetEnabledCallbacks(InventorySectionGUI* thisptr, bool value);

// Fired by InventorySectionGUI::refreshIcons hook.
// Lua event name: "InventorySectionGUI::refreshIcons"
// Lua signature: function(self, section)
void CallInventorySectionGUIRefreshIconsCallbacks(InventorySectionGUI* thisptr, InventorySection* section);

// Fired by InventorySectionGUI::update hook.
// Lua event name: "InventorySectionGUI::update"
// Lua signature: function(self)
void CallInventorySectionGUIUpdateCallbacks(InventorySectionGUI* thisptr);

// Fired by InventoryGUI::TradeResult::_CONSTRUCTOR hook.
// Lua event name: "InventoryGUI::TradeResult::_CONSTRUCTOR"
// Lua signature: function(self, value)
void CallInventoryTradeResultConstructedCallbacks(InventoryGUI::TradeResult* thisptr, int value);

// Fired by InventoryGUI::TradeResult::operator== hook.
// Lua event name: "InventoryGUI::TradeResult::operator=="
// Lua signature: function(self, other, defaultVal) -> boolean
bool CallInventoryTradeResultEqualsCallbacks(InventoryGUI::TradeResult* thisptr, InventoryGUI::TradeResult* other, bool defaultVal);

// Fired by InventoryGUI::TradeResult::operator!= hook.
// Lua event name: "InventoryGUI::TradeResult::operator!="
// Lua signature: function(self, other, defaultVal) -> boolean
bool CallInventoryTradeResultNotEqualsCallbacks(InventoryGUI::TradeResult* thisptr, InventoryGUI::TradeResult* other, bool defaultVal);

// Fired by InventoryGUI::TradeResult::showMessage hook.
// Lua event name: "InventoryGUI::TradeResult::showMessage"
// Lua signature: function(self)
void CallInventoryTradeResultShowMessageCallbacks(InventoryGUI::TradeResult* thisptr);

// Fired by InventoryGUI::TradeResult::ShowMessage hook.
// Lua event name: "InventoryGUI::TradeResult::ShowMessage"
// Lua signature: function(value)
void CallInventoryTradeResultStaticShowMessageCallbacks(int value);

// Fired by InventoryGUI::InventoryTradeData::isValid hook.
// Lua event name: "InventoryGUI::InventoryTradeData::isValid"
// Lua signature: function(self, defaultVal) -> boolean
bool CallInventoryTradeDataIsValidCallbacks(InventoryGUI::InventoryTradeData* thisptr, bool defaultVal);

// Fired by InventoryGUI::InventoryTradeData::operator= hook.
// Lua event name: "InventoryGUI::InventoryTradeData::operator="
// Lua signature: function(self, other)
void CallInventoryTradeDataAssignCallbacks(InventoryGUI::InventoryTradeData* thisptr, InventoryGUI::InventoryTradeData* other);

// Fired by InventoryGUI::lockedItemCheck hook.
// Lua event name: "InventoryGUI::lockedItemCheck"
// Lua signature: function(item, defaultVal) -> boolean
bool CallInventoryGUILockedItemCheckCallbacks(LockedArmour* item, bool defaultVal);

// Fired by InventoryGUI::setTradingTown hook.
// Lua event name: "InventoryGUI::setTradingTown"
// Lua signature: function(town)
void CallInventoryGUISetTradingTownCallbacks(const hand& town);

// Fired by InventoryGUI::getTradingTown hook.
// Lua event name: "InventoryGUI::getTradingTown"
// Lua signature: function(defaultVal) -> Town
Town* CallInventoryGUIGetTradingTownCallbacks(Town* defaultVal);

// Fired by InventoryGUI::removeTradePartner hook.
// Lua event name: "InventoryGUI::removeTradePartner"
// Lua signature: function(tradeWith)
void CallInventoryGUIRemoveTradePartnerCallbacks(InventoryGUI* tradeWith);

// Fired by InventoryGUI::clearTradePartners hook.
// Lua event name: "InventoryGUI::clearTradePartners"
// Lua signature: function()
void CallInventoryGUIClearTradePartnersCallbacks();

// Fired by InventoryGUI::canDropMouseItemWithoutPaying hook.
// Lua event name: "InventoryGUI::canDropMouseItemWithoutPaying"
// Lua signature: function(cameFrom, defaultVal) -> boolean
bool CallInventoryGUICanDropMouseItemWithoutPayingCallbacks(InventoryGUI* cameFrom, bool defaultVal);

// Fired by InventoryGUI::_NV_autoChangeSelectedObject hook.
// Lua event name: "InventoryGUI::_NV_autoChangeSelectedObject"
// Lua signature: function(self, obj)
void CallInventoryGUINVAutoChangeSelectedObjectCallbacks(InventoryGUI* thisptr, const hand& obj);

// Fired by InventoryGUI::_NV_update hook.
// Lua event name: "InventoryGUI::_NV_update"
// Lua signature: function(self)
void CallInventoryGUINVUpdateCallbacks(InventoryGUI* thisptr);

// Fired by InventoryGUI::_NV_show hook.
// Lua event name: "InventoryGUI::_NV_show"
// Lua signature: function(self, on)
void CallInventoryGUINVShowCallbacks(InventoryGUI* thisptr, bool on);

// Fired by InventoryGUI::_NV_setPositionReal hook.
// Lua event name: "InventoryGUI::_NV_setPositionReal"
// Lua signature: function(self, x, y)
void CallInventoryGUINVSetPositionRealCallbacks(InventoryGUI* thisptr, float x, float y);

// Fired by InventoryGUI::_NV_refreshSection hook.
// Lua event name: "InventoryGUI::_NV_refreshSection"
// Lua signature: function(self, section)
void CallInventoryGUINVRefreshSectionCallbacks(InventoryGUI* thisptr, InventorySection* section);

// Fired by InventoryGUI::refreshSection hook.
// Lua event name: "InventoryGUI::refreshSection"
// Lua signature: function(self)
void CallInventoryGUIRefreshSectionCallbacks(InventoryGUI* thisptr);

// Fired by InventoryGUI::autoArrangeButton hook.
// Lua event name: "InventoryGUI::autoArrangeButton"
// Lua signature: function(self, sender)
void CallInventoryGUIAutoArrangeButtonCallbacks(InventoryGUI* thisptr, MyGUI::Widget* sender);

// Fired by InventoryGUI::openBackpackButton hook.
// Lua event name: "InventoryGUI::openBackpackButton"
// Lua signature: function(self, sender)
void CallInventoryGUIOpenBackpackButtonCallbacks(InventoryGUI* thisptr, MyGUI::Widget* sender);

// Fired by InventoryGUI::openLimbsInterface hook.
// Lua event name: "InventoryGUI::openLimbsInterface"
// Lua signature: function(self, sender)
void CallInventoryGUIOpenLimbsInterfaceCallbacks(InventoryGUI* thisptr, MyGUI::Widget* sender);

// Fired by InventoryGUI::showBackpack hook.
// Lua event name: "InventoryGUI::showBackpack"
// Lua signature: function(self, on)
void CallInventoryGUIShowBackpackCallbacks(InventoryGUI* thisptr, bool on);

// Fired by InventoryGUI::windowButtonPressed hook.
// Lua event name: "InventoryGUI::windowButtonPressed"
// Lua signature: function(self, widget, name)
void CallInventoryGUIWindowButtonPressedCallbacks(InventoryGUI* thisptr, MyGUI::Widget* widget, const std::string& name);

// Fired by InventoryGUI::stealingGUIInfoUpdate hook.
// Lua event name: "InventoryGUI::stealingGUIInfoUpdate"
// Lua signature: function(self)
void CallInventoryGUIStealingGUIInfoUpdateCallbacks(InventoryGUI* thisptr);

// Fired by InventoryGUI::getTrader1Trader2 hook.
// Lua event name: "InventoryGUI::getTrader1Trader2"
// Lua signature: function(self, trader1, trader2)
void CallInventoryGUIGetTrader1Trader2Callbacks(InventoryGUI* thisptr, InventoryGUI* trader1, InventoryGUI* trader2);

// Fired by InventoryGUI::playSound hook.
// Lua event name: "InventoryGUI::playSound"
// Lua signature: function(self, eventId, item)
void CallInventoryGUIPlaySoundCallbacks(InventoryGUI* thisptr, const std::string& eventId, Item* item);

// Fired by InventoryGUI::refreshAllSections hook.
// Lua event name: "InventoryGUI::refreshAllSections"
// Lua signature: function(self)
void CallInventoryGUIRefreshAllSectionsCallbacks(InventoryGUI* thisptr);

// Fired by InventoryGUI::updateDatapanel hook.
// Lua event name: "InventoryGUI::updateDatapanel"
// Lua signature: function(self)
void CallInventoryGUIUpdateDatapanelCallbacks(InventoryGUI* thisptr);

// Fired by InventoryGUI::rightClickAutoEquipping hook.
// Lua event name: "InventoryGUI::rightClickAutoEquipping"
// Lua signature: function(self)
void CallInventoryGUIRightClickAutoEquippingCallbacks(InventoryGUI* thisptr);

// Fired by InventoryGUI::returnItem hook.
// Lua event name: "InventoryGUI::returnItem"
// Lua signature: function(self, item, sectionName)
void CallInventoryGUIReturnItemCallbacks(InventoryGUI* thisptr, Item* item, const std::string& sectionName);

// Fired by InventoryGUI::sectionMouseButtonPressed hook.
// Lua event name: "InventoryGUI::sectionMouseButtonPressed"
// Lua signature: function(self, sender, left, top, id)
void CallInventoryGUISectionMouseButtonPressedCallbacks(InventoryGUI* thisptr, MyGUI::Widget* sender, int left, int top, int id);

// Fired by InventoryGUI::sectionMouseButtonReleased hook.
// Lua event name: "InventoryGUI::sectionMouseButtonReleased"
// Lua signature: function(self, sender, left, top, id)
void CallInventoryGUISectionMouseButtonReleasedCallbacks(InventoryGUI* thisptr, MyGUI::Widget* sender, int left, int top, int id);

// Fired by InventoryGUI::onWindowFocus hook.
// Lua event name: "InventoryGUI::onWindowFocus"
// Lua signature: function(self, sender, focus)
void CallInventoryGUIOnWindowFocusCallbacks(InventoryGUI* thisptr, MyGUI::Widget* sender, bool focus);

// Fired by InventoryGUI::windowMoved hook.
// Lua event name: "InventoryGUI::windowMoved"
// Lua signature: function(self, sender)
void CallInventoryGUIWindowMovedCallbacks(InventoryGUI* thisptr, MyGUI::Widget* sender);

// Fired by InventoryGUI::_NV_isVisible hook.
// Lua event name: "InventoryGUI::_NV_isVisible"
// Lua signature: function(self, defaultVal) -> boolean
bool CallInventoryGUINVIsVisibleCallbacks(InventoryGUI* thisptr, bool defaultVal);

// Fired by InventoryGUI::getBackpack hook.
// Lua event name: "InventoryGUI::getBackpack"
// Lua signature: function(self, defaultVal) -> ContainerItem
ContainerItem* CallInventoryGUIGetBackpackCallbacks(InventoryGUI* thisptr, ContainerItem* defaultVal);

// Fired by InventoryGUI::_NV_getInventory hook.
// Lua event name: "InventoryGUI::_NV_getInventory"
// Lua signature: function(self, defaultVal) -> Inventory
Inventory* CallInventoryGUINVGetInventoryCallbacks(InventoryGUI* thisptr, Inventory* defaultVal);

// Fired by InventoryGUI::hasSameOwner hook.
// Lua event name: "InventoryGUI::hasSameOwner"
// Lua signature: function(self, other, defaultVal) -> boolean
bool CallInventoryGUIHasSameOwnerCallbacks(InventoryGUI* thisptr, InventoryGUI* other, bool defaultVal);

// Fired by InventoryGUI::_NV_getCallbackCharacter hook.
// Lua event name: "InventoryGUI::_NV_getCallbackCharacter"
// Lua signature: function(self, defaultVal) -> Character
Character* CallInventoryGUINVGetCallbackCharacterCallbacks(InventoryGUI* thisptr, Character* defaultVal);

// Fired by InventoryGUI::_NV_getCallbackObject hook.
// Lua event name: "InventoryGUI::_NV_getCallbackObject"
// Lua signature: function(self, defaultVal) -> RootObject
RootObject* CallInventoryGUINVGetCallbackObjectCallbacks(InventoryGUI* thisptr, RootObject* defaultVal);

// Fired by InventoryGUI::getSelectedItem hook.
// Lua event name: "InventoryGUI::getSelectedItem"
// Lua signature: function(self, sectionName, defaultVal) -> Item
Item* CallInventoryGUIGetSelectedItemCallbacks(InventoryGUI* thisptr, const std::string& sectionName, Item* defaultVal);

// Fired by InventoryGUI::getMouseItem hook.
// Lua event name: "InventoryGUI::getMouseItem"
// Lua signature: function(self, defaultVal) -> Item
Item* CallInventoryGUIGetMouseItemCallbacks(InventoryGUI* thisptr, Item* defaultVal);

// Fired by InventoryGUI::takeCertainAmountFrom hook.
// Lua event name: "InventoryGUI::takeCertainAmountFrom"
// Lua signature: function(self, baseItem, amount, defaultVal) -> Item
Item* CallInventoryGUITakeCertainAmountFromCallbacks(InventoryGUI* thisptr, Item* baseItem, int amount, Item* defaultVal);

// Fired by InventoryGUI::pickupItemToMouse hook.
// Lua event name: "InventoryGUI::pickupItemToMouse"
// Lua signature: function(self, sectionName, defaultVal) -> boolean
bool CallInventoryGUIPickupItemToMouseCallbacks(InventoryGUI* thisptr, const std::string& sectionName, bool defaultVal);

// Fired by InventoryGUI::placeItemFromMouse hook.
// Lua event name: "InventoryGUI::placeItemFromMouse"
// Lua signature: function(self, sectionName, mousePos, defaultVal) -> boolean
bool CallInventoryGUIPlaceItemFromMouseCallbacks(InventoryGUI* thisptr, const std::string& sectionName, const MyGUI::types::TPoint<int>& mousePos, bool defaultVal);

// Fired by InventoryGUI::isTradingForMoney hook.
// Lua event name: "InventoryGUI::isTradingForMoney"
// Lua signature: function(self, cameFrom, defaultVal) -> boolean
bool CallInventoryGUIIsTradingForMoneyCallbacks(InventoryGUI* thisptr, InventoryGUI* cameFrom, bool defaultVal);

// Fired by InventoryGUI::isStealing hook.
// Lua event name: "InventoryGUI::isStealing"
// Lua signature: function(self, cameFrom, defaultVal) -> boolean
bool CallInventoryGUIIsStealingCallbacks(InventoryGUI* thisptr, InventoryGUI* cameFrom, bool defaultVal);

// Fired by InventoryGUI::isWithinRangeToTrade hook.
// Lua event name: "InventoryGUI::isWithinRangeToTrade"
// Lua signature: function(self, otherOwner, stealing, defaultVal) -> boolean
bool CallInventoryGUIIsWithinRangeToTradeCallbacks(InventoryGUI* thisptr, RootObject* otherOwner, bool stealing, bool defaultVal);

// Fired by InventoryGUI::setItemToPlayerPortrait hook.
// Lua event name: "InventoryGUI::setItemToPlayerPortrait"
// Lua signature: function(self, item, character, defaultVal) -> boolean
bool CallInventoryGUISetItemToPlayerPortraitCallbacks(InventoryGUI* thisptr, Item* item, Character* character, bool defaultVal);

// Fired by InventoryGUI::fencingConfirmation hook.
// Lua event name: "InventoryGUI::fencingConfirmation"
// Lua signature: function(self, item, thief, fence, sectionName, mouse, defaultVal) -> boolean
bool CallInventoryGUIFencingConfirmationResultCallbacks(InventoryGUI* thisptr, Item* item, RootObject* thief, Character* fence, const std::string& sectionName, const MyGUI::types::TPoint<int>& mouse, bool defaultVal);

// Fired by InventoryGUI::getPlayerTradeCharacter hook.
// Lua event name: "InventoryGUI::getPlayerTradeCharacter"
// Lua signature: function(self, defaultVal) -> RootObject
RootObject* CallInventoryGUIGetPlayerTradeCharacterCallbacks(InventoryGUI* thisptr, RootObject* defaultVal);

// Fired by InventoryGUI::tryToEquip hook.
// Lua event name: "InventoryGUI::tryToEquip"
// Lua signature: function(self, item, replace, defaultVal) -> boolean
bool CallInventoryGUITryToEquipCallbacks(InventoryGUI* thisptr, Item* item, bool replace, bool defaultVal);

// Fired by InventoryGUI::hasMouse hook.
// Lua event name: "InventoryGUI::hasMouse"
// Lua signature: function(self, defaultVal) -> boolean
bool CallInventoryGUIHasMouseCallbacks(InventoryGUI* thisptr, bool defaultVal);

// Fired by InventoryGUI::getWindowCoord hook.
// Lua event name: "InventoryGUI::getWindowCoord"
// Lua signature: function(self, result)
void CallInventoryGUIGetWindowCoordCallbacks(InventoryGUI* thisptr, const MyGUI::types::TCoord<int>& result);

// Fired by InventoryGUI::getNPCTrader hook.
// Lua event name: "InventoryGUI::getNPCTrader"
// Lua signature: function(defaultVal) -> Character
Character* CallInventoryGUIGetNPCTraderCallbacks(Character* defaultVal);

// Fired by InventoryGUI::isTradingForMoney_static hook.
// Lua event name: "InventoryGUI::isTradingForMoney_static"
// Lua signature: function(defaultVal) -> RootObject
RootObject* CallInventoryGUIIsTradingForMoneyStaticCallbacks(RootObject* defaultVal);

// Fired by InventoryGUI::isTradingAndStealing_static hook.
// Lua event name: "InventoryGUI::isTradingAndStealing_static"
// Lua signature: function(defaultVal) -> RootObject
RootObject* CallInventoryGUIIsTradingAndStealingStaticCallbacks(RootObject* defaultVal);

// Fired by InventoryGUI::getTraderPriceMultiplier hook.
// Lua event name: "InventoryGUI::getTraderPriceMultiplier"
// Lua signature: function(defaultVal) -> number
float CallInventoryGUIGetTraderPriceMultiplierCallbacks(float defaultVal);

// Fired by InventoryGUI::_DESTRUCTOR hook.
// Lua event name: "InventoryGUI::_DESTRUCTOR"
// Lua signature: function(self)
void CallInventoryGUIDestructorCallbacks(InventoryGUI* thisptr);

// Fired by InventoryGUI::RClickAutoTrade hook.
// Lua event name: "InventoryGUI::RClickAutoTrade"
// Lua signature: function(self, invSectionName, x, y, sendingTo, thieveryChecks, first, result)
void CallInventoryGUIRClickAutoTradeCallbacks(InventoryGUI* thisptr, const std::string& invSectionName, int x, int y, InventoryGUI* sendingTo, bool thieveryChecks, bool first, const InventoryGUI::TradeResult& result);

// Fired by InventoryGUI::RClickAutoTradeAll hook.
// Lua event name: "InventoryGUI::RClickAutoTradeAll"
// Lua signature: function(self, invSectionName, x, y, sendingTo, thieveryChecks, first, result)
void CallInventoryGUIRClickAutoTradeAllCallbacks(InventoryGUI* thisptr, const std::string& invSectionName, int x, int y, InventoryGUI* sendingTo, bool thieveryChecks, bool first, const InventoryGUI::TradeResult& result);

// Fired by InventoryGUI::FenceCallbackData::_DESTRUCTOR hook.
// Lua event name: "InventoryGUI::FenceCallbackData::_DESTRUCTOR"
// Lua signature: function(self)
void CallInventoryGUIFenceCallbackDataDestructorCallbacks(InventoryGUI::FenceCallbackData* thisptr);

// Fired by InventoryGUI::getSectionWithMouseLocal hook.
// Lua event name: "InventoryGUI::getSectionWithMouseLocal"
// Lua signature: function(self, result)
void CallInventoryGUIGetSectionWithMouseLocalCallbacks(InventoryGUI* thisptr, const std::string& result);

// Fired by InventoryGUI::getSlotWithMouse hook.
// Lua event name: "InventoryGUI::getSlotWithMouse"
// Lua signature: function(self, result)
void CallInventoryGUIGetSlotWithMouseCallbacks(InventoryGUI* thisptr, const iVector2& result);

// Fired by InventoryGUI::makeIconForItem hook.
// Lua event name: "InventoryGUI::makeIconForItem"
// Lua signature: function(item, x, y, defaultVal) -> InventoryIcon
InventoryIcon* CallInventoryGUIMakeIconForItemCallbacks(Item* item, int x, int y, InventoryIcon* defaultVal);

// Fired by InventoryLayout::_CONSTRUCTOR hook.
// Lua event name: "InventoryLayout::_CONSTRUCTOR"
// Lua signature: function(self, file)
void CallInventoryLayoutConstructedCallbacks(InventoryLayout* thisptr, const std::string& file);

// Fired by InventoryLayout::_DESTRUCTOR hook.
// Lua event name: "InventoryLayout::_DESTRUCTOR"
// Lua signature: function(self)
void CallInventoryLayoutDestructorCallbacks(InventoryLayout* thisptr);

// Fired by InventoryLayout::getWindow hook.
// Lua event name: "InventoryLayout::getWindow"
// Lua signature: function(self, result)
void CallInventoryLayoutGetWindowCallbacks(InventoryLayout* thisptr, MyGUI::Widget* result);

// Fired by InventoryLayout::getWidget hook.
// Lua event name: "InventoryLayout::getWidget"
// Lua signature: function(self, name, result)
void CallInventoryLayoutGetWidgetCallbacks(InventoryLayout* thisptr, const std::string& name, MyGUI::Widget* result);

// Fired by InventoryLayout::_NV_getDatapanel hook.
// Lua event name: "InventoryLayout::_NV_getDatapanel"
// Lua signature: function(self, defaultVal) -> DatapanelGUI
DatapanelGUI* CallInventoryLayoutNVGetDatapanelCallbacks(InventoryLayout* thisptr, DatapanelGUI* defaultVal);

// Fired by InventoryLayout::setupDataPanelInfos hook.
// Lua event name: "InventoryLayout::setupDataPanelInfos"
// Lua signature: function(self, name)
void CallInventoryLayoutSetupDataPanelInfosCallbacks(InventoryLayout* thisptr, const std::string& name);

// Fired by InventoryLayout::notifyCellSizeChanged hook.
// Lua event name: "InventoryLayout::notifyCellSizeChanged"
// Lua signature: function()
void CallInventoryLayoutNotifyCellSizeChangedCallbacks();

// Fired by InventoryLayout::createSectionGUI hook.
// Lua event name: "InventoryLayout::createSectionGUI"
// Lua signature: function(self, section, defaultVal) -> InventorySectionGUI
InventorySectionGUI* CallInventoryLayoutCreateSectionGUICallbacks(InventoryLayout* thisptr, InventorySection* section, InventorySectionGUI* defaultVal);

// Fired by InventoryLayout::setSectionGUIDisabled hook.
// Lua event name: "InventoryLayout::setSectionGUIDisabled"
// Lua signature: function(self, sectionName, width, height)
void CallInventoryLayoutSetSectionGUIDisabledCallbacks(InventoryLayout* thisptr, const std::string& sectionName, int width, int height);

// Fired by InventoryLayout::resizeSection hook.
// Lua event name: "InventoryLayout::resizeSection"
// Lua signature: function(self, section, sectionGUI, result)
void CallInventoryLayoutResizeSectionCallbacks(InventoryLayout* thisptr, InventorySection* section, InventorySectionGUI* sectionGUI, const MyGUI::types::TSize<int>& result);

// Fired by InventoryLayout::resizeSectionWidget hook.
// Lua event name: "InventoryLayout::resizeSectionWidget"
// Lua signature: function(self, width, height, widget, result)
void CallInventoryLayoutResizeSectionWidgetCallbacks(InventoryLayout* thisptr, int width, int height, MyGUI::Widget* widget, const MyGUI::types::TSize<int>& result);

// Fired by GenericFixedInventoryLayout::_NV_setSize hook.
// Lua event name: "GenericFixedInventoryLayout::_NV_setSize"
// Lua signature: function(self, slotsW, slotsH)
void CallGenericFixedInventoryLayoutNVSetSizeCallbacks(GenericFixedInventoryLayout* thisptr, int slotsW, int slotsH);

// Fired by GenericFixedInventoryLayout::_DESTRUCTOR hook.
// Lua event name: "GenericFixedInventoryLayout::_DESTRUCTOR"
// Lua signature: function(self)
void CallGenericFixedInventoryLayoutDestructorCallbacks(GenericFixedInventoryLayout* thisptr);

// Fired by BackpackInventoryLayout::_CONSTRUCTOR hook.
// Lua event name: "BackpackInventoryLayout::_CONSTRUCTOR"
// Lua signature: function(self, standAlone)
void CallBackpackInventoryLayoutConstructedCallbacks(BackpackInventoryLayout* thisptr, bool standAlone);

// Fired by BackpackInventoryLayout::_DESTRUCTOR hook.
// Lua event name: "BackpackInventoryLayout::_DESTRUCTOR"
// Lua signature: function(self)
void CallBackpackInventoryLayoutDestructorCallbacks(BackpackInventoryLayout* thisptr);

// -----------------------------------------------------------
// Callbacks for hooks in gui/MainBarGUI.h
// -----------------------------------------------------------

// Fired by MainTabPortraitPlatoon::addTab hook.
// Lua event name: "MainTabPortraitPlatoon::addTab"
// Lua signature: function(self, tabControl, visible)
void CallMainTabPortraitPlatoonAddTabCallbacks(MainTabPortraitPlatoon* thisptr, MyGUI::Widget* tabControl, bool visible);

// Fired by MainTabPortraitPlatoon::detach hook.
// Lua event name: "MainTabPortraitPlatoon::detach"
// Lua signature: function(self)
void CallMainTabPortraitPlatoonDetachCallbacks(MainTabPortraitPlatoon* thisptr);

// Fired by MainTabPortraitPlatoon::setFlash hook.
// Lua event name: "MainTabPortraitPlatoon::setFlash"
// Lua signature: function(self, flash)
void CallMainTabPortraitPlatoonSetFlashCallbacks(MainTabPortraitPlatoon* thisptr, bool flash);

// Fired by MainTabPortraitPlatoon::update hook.
// Lua event name: "MainTabPortraitPlatoon::update"
// Lua signature: function(self)
void CallMainTabPortraitPlatoonUpdateCallbacks(MainTabPortraitPlatoon* thisptr);

// Fired by MainTabPortraitPlatoon::_DESTRUCTOR hook.
// Lua event name: "MainTabPortraitPlatoon::_DESTRUCTOR"
// Lua signature: function(self)
void CallMainTabPortraitPlatoonDestructorCallbacks(MainTabPortraitPlatoon* thisptr);

// Fired by MainBarGUI::_CONSTRUCTOR hook.
// Lua event name: "MainBarGUI::_CONSTRUCTOR"
// Lua signature: function(self)
void CallMainBarGUIConstructedCallbacks(MainBarGUI* thisptr);

// Fired by MainBarGUI::_DESTRUCTOR hook.
// Lua event name: "MainBarGUI::_DESTRUCTOR"
// Lua signature: function(self)
void CallMainBarGUIDestructorCallbacks(MainBarGUI* thisptr);

// Fired by MainBarGUI::_NV_clear hook.
// Lua event name: "MainBarGUI::_NV_clear"
// Lua signature: function(self)
void CallMainBarGUINVclearCallbacks(MainBarGUI* thisptr);

// Fired by MainBarGUI::_NV_update hook.
// Lua event name: "MainBarGUI::_NV_update"
// Lua signature: function(self)
void CallMainBarGUINVUpdateCallbacks(MainBarGUI* thisptr);

// Fired by MainBarGUI::speedChanged hook.
// Lua event name: "MainBarGUI::speedChanged"
// Lua signature: function(self)
void CallMainBarGUISpeedChangedCallbacks(MainBarGUI* thisptr);

// Fired by MainBarGUI::_NV_updateBountyPanelVisibility hook.
// Lua event name: "MainBarGUI::_NV_updateBountyPanelVisibility"
// Lua signature: function(self)
void CallMainBarGUINVUpdateBountyPanelVisibilityCallbacks(MainBarGUI* thisptr);

// Fired by MainBarGUI::updatePotraitsPlatoon hook.
// Lua event name: "MainBarGUI::updatePotraitsPlatoon"
// Lua signature: function(self)
void CallMainBarGUIUpdatePotraitsPlatoonCallbacks(MainBarGUI* thisptr);

// Fired by MainBarGUI::updatePortraits hook.
// Lua event name: "MainBarGUI::updatePortraits"
// Lua signature: function(self)
void CallMainBarGUIUpdatePortraitsCallbacks(MainBarGUI* thisptr);

// Fired by MainBarGUI::refreshPortraitTabs hook.
// Lua event name: "MainBarGUI::refreshPortraitTabs"
// Lua signature: function(self)
void CallMainBarGUIRefreshPortraitTabsCallbacks(MainBarGUI* thisptr);

// Fired by MainBarGUI::ordersPanelClear hook.
// Lua event name: "MainBarGUI::ordersPanelClear"
// Lua signature: function(self)
void CallMainBarGUIOrdersPanelClearCallbacks(MainBarGUI* thisptr);

// Fired by MainBarGUI::setMessagePosition hook.
// Lua event name: "MainBarGUI::setMessagePosition"
// Lua signature: function(self)
void CallMainBarGUISetMessagePositionCallbacks(MainBarGUI* thisptr);

// Fired by MainBarGUI::_NV_show hook.
// Lua event name: "MainBarGUI::_NV_show"
// Lua signature: function(self, on)
void CallMainBarGUINVShowCallbacks(MainBarGUI* thisptr, bool on);

// Fired by MainBarGUI::setLevelEditMode hook.
// Lua event name: "MainBarGUI::setLevelEditMode"
// Lua signature: function(self, on)
void CallMainBarGUISetLevelEditModeCallbacks(MainBarGUI* thisptr, bool on);

// Fired by MainBarGUI::setLevelEditInteriorMode hook.
// Lua event name: "MainBarGUI::setLevelEditInteriorMode"
// Lua signature: function(self, interiorMode)
void CallMainBarGUISetLevelEditInteriorModeCallbacks(MainBarGUI* thisptr, bool interiorMode);

// Fired by MainBarGUI::setExtendInfoPanelEnabled hook.
// Lua event name: "MainBarGUI::setExtendInfoPanelEnabled"
// Lua signature: function(self, enabled)
void CallMainBarGUISetExtendInfoPanelEnabledCallbacks(MainBarGUI* thisptr, bool enabled);

// Fired by MainBarGUI::_NV_autoChangeSelectedObject hook.
// Lua event name: "MainBarGUI::_NV_autoChangeSelectedObject"
// Lua signature: function(self, obj)
void CallMainBarGUINVAutoChangeSelectedObjectCallbacks(MainBarGUI* thisptr, const hand& obj);

// Fired by MainBarGUI::pressedKey hook.
// Lua event name: "MainBarGUI::pressedKey"
// Lua signature: function(self, keycode)
void CallMainBarGUIPressedKeyCallbacks(MainBarGUI* thisptr, int keycode);

// Fired by MainBarGUI::updatePortrait hook.
// Lua event name: "MainBarGUI::updatePortrait"
// Lua signature: function(self, character)
void CallMainBarGUIUpdatePortraitCallbacks(MainBarGUI* thisptr, const hand& character);

// Fired by MainBarGUI::platoonUpdated hook.
// Lua event name: "MainBarGUI::platoonUpdated"
// Lua signature: function(self, platoon, charAdded)
void CallMainBarGUIPlatoonUpdatedCallbacks(MainBarGUI* thisptr, RootObjectContainer* platoon, bool charAdded);

// Fired by MainBarGUI::updatePortraitSize hook.
// Lua event name: "MainBarGUI::updatePortraitSize"
// Lua signature: function(self, platoon)
void CallMainBarGUIUpdatePortraitSizeCallbacks(MainBarGUI* thisptr, ActivePlatoon* platoon);

// Fired by MainBarGUI::closeMapWindow hook.
// Lua event name: "MainBarGUI::closeMapWindow"
// Lua signature: function(self, sender)
void CallMainBarGUICloseMapWindowCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender);

// Fired by MainBarGUI::toggleMapWindow hook.
// Lua event name: "MainBarGUI::toggleMapWindow"
// Lua signature: function(self, sender)
void CallMainBarGUIToggleMapWindowCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender);

// Fired by MainBarGUI::toggleFactionWindow hook.
// Lua event name: "MainBarGUI::toggleFactionWindow"
// Lua signature: function(self, sender)
void CallMainBarGUIToggleFactionWindowCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender);

// Fired by MainBarGUI::toggleTechWindow hook.
// Lua event name: "MainBarGUI::toggleTechWindow"
// Lua signature: function(self, sender)
void CallMainBarGUIToggleTechWindowCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender);

// Fired by MainBarGUI::toggleCraftWindow hook.
// Lua event name: "MainBarGUI::toggleCraftWindow"
// Lua signature: function(self, sender)
void CallMainBarGUIToggleCraftWindowCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender);

// Fired by MainBarGUI::toggleSquadWindow hook.
// Lua event name: "MainBarGUI::toggleSquadWindow"
// Lua signature: function(self, sender)
void CallMainBarGUIToggleSquadWindowCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender);

// Fired by MainBarGUI::changeFloorButtonUp hook.
// Lua event name: "MainBarGUI::changeFloorButtonUp"
// Lua signature: function(self, sender)
void CallMainBarGUIChangeFloorButtonUpCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender);

// Fired by MainBarGUI::changeFloorButtonDown hook.
// Lua event name: "MainBarGUI::changeFloorButtonDown"
// Lua signature: function(self, sender)
void CallMainBarGUIChangeFloorButtonDownCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender);

// Fired by MainBarGUI::toggleInventory hook.
// Lua event name: "MainBarGUI::toggleInventory"
// Lua signature: function(self, sender)
void CallMainBarGUIToggleInventoryCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender);

// Fired by MainBarGUI::toggleStatsWindow hook.
// Lua event name: "MainBarGUI::toggleStatsWindow"
// Lua signature: function(self, sender)
void CallMainBarGUIToggleStatsWindowCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender);

// Fired by MainBarGUI::toggleHelpWindow hook.
// Lua event name: "MainBarGUI::toggleHelpWindow"
// Lua signature: function(self, sender)
void CallMainBarGUIToggleHelpWindowCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender);

// Fired by MainBarGUI::changeSpeed hook.
// Lua event name: "MainBarGUI::changeSpeed"
// Lua signature: function(self, sender)
void CallMainBarGUIChangeSpeedCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender);

// Fired by MainBarGUI::buildButton hook.
// Lua event name: "MainBarGUI::buildButton"
// Lua signature: function(self, sender)
void CallMainBarGUIBuildButtonCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender);

// Fired by MainBarGUI::ordersPanelFill hook.
// Lua event name: "MainBarGUI::ordersPanelFill"
// Lua signature: function(self, character)
void CallMainBarGUIOrdersPanelFillCallbacks(MainBarGUI* thisptr, const hand& character);

// Fired by MainBarGUI::serialise hook.
// Lua event name: "MainBarGUI::serialise"
// Lua signature: function(self, data)
void CallMainBarGUISerialiseCallbacks(MainBarGUI* thisptr, GameData* data);

// Fired by MainBarGUI::loadFromSerialise hook.
// Lua event name: "MainBarGUI::loadFromSerialise"
// Lua signature: function(self, data)
void CallMainBarGUILoadFromSerialiseCallbacks(MainBarGUI* thisptr, GameData* data);

// Fired by MainBarGUI::portraitChangeSelection hook.
// Lua event name: "MainBarGUI::portraitChangeSelection"
// Lua signature: function(self, sender, index, follow)
void CallMainBarGUIPortraitChangeSelectionCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender, double index, bool follow);

// Fired by MainBarGUI::portraitSelectItemAccept hook.
// Lua event name: "MainBarGUI::portraitSelectItemAccept"
// Lua signature: function(self, sender, index)
void CallMainBarGUIPortraitSelectItemAcceptCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender, double index);

// Fired by MainBarGUI::portraitNotifyItem hook.
// Lua event name: "MainBarGUI::portraitNotifyItem"
// Lua signature: function(self, sender, info)
void CallMainBarGUIPortraitNotifyItemCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender, void* info);

// Fired by MainBarGUI::tabPlatoonChange hook.
// Lua event name: "MainBarGUI::tabPlatoonChange"
// Lua signature: function(self, sender, index)
void CallMainBarGUITabPlatoonChangeCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender, double index);

// Fired by MainBarGUI::extendInfoPanel hook.
// Lua event name: "MainBarGUI::extendInfoPanel"
// Lua signature: function(self, sender, left, top, id)
void CallMainBarGUIExtendInfoPanelCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender, int left, int top, int id);

// Fired by MainBarGUI::getPausePanel hook.
// Lua event name: "MainBarGUI::getPausePanel"
// Lua signature: function(self, result)
void CallMainBarGUIGetPausePanelCallbacks(MainBarGUI* thisptr, MyGUI::Widget* result);

// Fired by MainBarGUI::getLoadingPanel hook.
// Lua event name: "MainBarGUI::getLoadingPanel"
// Lua signature: function(self, result)
void CallMainBarGUIGetLoadingPanelCallbacks(MainBarGUI* thisptr, MyGUI::Widget* result);

// Fired by MainBarGUI::getMedicalPanel hook.
// Lua event name: "MainBarGUI::getMedicalPanel"
// Lua signature: function(self, result)
void CallMainBarGUIGetMedicalPanelCallbacks(MainBarGUI* thisptr, void* result);

// Fired by MainBarGUI::_NV_getToolTip hook.
// Lua event name: "MainBarGUI::_NV_getToolTip"
// Lua signature: function(self, defaultVal) -> ToolTip
ToolTip* CallMainBarGUINVGetToolTipCallbacks(MainBarGUI* thisptr, ToolTip* defaultVal);

// Fired by MainBarGUI::getDatapanel hook.
// Lua event name: "MainBarGUI::getDatapanel"
// Lua signature: function(self, id, defaultVal) -> DatapanelGUI
DatapanelGUI* CallMainBarGUIGetDatapanelCallbacks(MainBarGUI* thisptr, const std::string& id, DatapanelGUI* defaultVal);

// Fired by MainBarGUI::getBuildingInventoryPosition hook.
// Lua event name: "MainBarGUI::getBuildingInventoryPosition"
// Lua signature: function(self, result)
void CallMainBarGUIGetBuildingInventoryPositionCallbacks(MainBarGUI* thisptr, const MyGUI::types::TPoint<int>& result);

// Fired by MainBarGUI::_getWidget hook.
// Lua event name: "MainBarGUI::_getWidget"
// Lua signature: function(self, name, result)
void CallMainBarGUIGetWidgetCallbacks(MainBarGUI* thisptr, const std::string& name, MyGUI::Widget* result);

// -----------------------------------------------------------
// Callbacks for hooks in gui/FactionsScreen.h
// -----------------------------------------------------------

// Fired after FactionsScreen::FactionRelationsLine::_CONSTRUCTOR.
// Lua event name: "FactionsScreen::FactionRelationsLine::_CONSTRUCTOR"
// Lua signature: function(self, faction)
void CallFactionRelationsLineConstructedCallbacks(FactionsScreen::FactionRelationsLine* thisptr, Faction* faction);

// Fired after FactionsScreen::FactionRelationsLine::attachToWidget.
// Lua event name: "FactionsScreen::FactionRelationsLine::attachToWidget"
// Lua signature: function(self, widget)
void CallFactionRelationsLineAttachToWidgetCallbacks(FactionsScreen::FactionRelationsLine* thisptr, MyGUI::Widget* widget);

// Fired after FactionsScreen::FactionRelationsLine::update.
// Lua event name: "FactionsScreen::FactionRelationsLine::update"
// Lua signature: function(self)
void CallFactionRelationsLineUpdateCallbacks(FactionsScreen::FactionRelationsLine* thisptr);

// Fired before FactionsScreen::FactionRelationsLine::_DESTRUCTOR.
// Lua event name: "FactionsScreen::FactionRelationsLine::_DESTRUCTOR"
// Lua signature: function(self)
void CallFactionRelationsLineDestructorCallbacks(FactionsScreen::FactionRelationsLine* thisptr);

// Fired after FactionsScreen::FactionRelationsLine::LessSort::operator().
// Lua event name: "FactionsScreen::FactionRelationsLine::LessSort::operator()"
// Lua signature: function(comparator, left, right, defaultVal) -> boolean
bool CallFactionRelationsLineLessSortCallbacks(void* comparator, FactionsScreen::FactionRelationsLine* left, FactionsScreen::FactionRelationsLine* right, bool defaultVal);

// Fired after FactionsScreen::_CONSTRUCTOR.
// Lua event name: "FactionsScreen::_CONSTRUCTOR"
// Lua signature: function(self, screen)
void CallFactionsScreenConstructedCallbacks(FactionsScreen* thisptr, ManagementScreen* screen);

// Fired before FactionsScreen::_DESTRUCTOR.
// Lua event name: "FactionsScreen::_DESTRUCTOR"
// Lua signature: function(self)
void CallFactionsScreenDestructorCallbacks(FactionsScreen* thisptr);

// Fired after FactionsScreen::getVisible.
// Lua event name: "FactionsScreen::getVisible"
// Lua signature: function(self, defaultVal) -> boolean
bool CallFactionsScreenGetVisibleCallbacks(FactionsScreen* thisptr, bool defaultVal);

// Fired after FactionsScreen::clear.
// Lua event name: "FactionsScreen::clear"
// Lua signature: function(self)
void CallFactionsScreenClearCallbacks(FactionsScreen* thisptr);

// Fired after FactionsScreen::update.
// Lua event name: "FactionsScreen::update"
// Lua signature: function(self)
void CallFactionsScreenUpdateCallbacks(FactionsScreen* thisptr);

// Fired after FactionsScreen::refresh.
// Lua event name: "FactionsScreen::refresh"
// Lua signature: function(self)
void CallFactionsScreenRefreshCallbacks(FactionsScreen* thisptr);

// Fired after FactionsScreen::updateInfo.
// Lua event name: "FactionsScreen::updateInfo"
// Lua signature: function(self)
void CallFactionsScreenUpdateInfoCallbacks(FactionsScreen* thisptr);

// Fired after FactionsScreen::notifyEditTextChange.
// Lua event name: "FactionsScreen::notifyEditTextChange"
// Lua signature: function(self, sender)
void CallFactionsScreenNotifyEditTextChangeCallbacks(FactionsScreen* thisptr, MyGUI::Widget* sender);

// Fired after FactionsScreen::setFocus.
// Lua event name: "FactionsScreen::setFocus"
// Lua signature: function(self, first, second)
void CallFactionsScreenSetFocusCallbacks(FactionsScreen* thisptr, MyGUI::Widget* first, MyGUI::Widget* second);

// Fired after FactionsScreen::loseFocus.
// Lua event name: "FactionsScreen::loseFocus"
// Lua signature: function(self, first, second)
void CallFactionsScreenLoseFocusCallbacks(FactionsScreen* thisptr, MyGUI::Widget* first, MyGUI::Widget* second);

// Fired after FactionsScreen::factionLineSelected.
// Lua event name: "FactionsScreen::factionLineSelected"
// Lua signature: function(self, sender)
void CallFactionsScreenFactionLineSelectedCallbacks(FactionsScreen* thisptr, MyGUI::Widget* sender);

// Fired after FactionsScreen::notifyMouseWheel.
// Lua event name: "FactionsScreen::notifyMouseWheel"
// Lua signature: function(self, sender, rel)
void CallFactionsScreenNotifyMouseWheelCallbacks(FactionsScreen* thisptr, MyGUI::Widget* sender, int rel);

// -----------------------------------------------------------
// Additional callbacks for hooks in gui/DialogueWindow.h
// -----------------------------------------------------------

// Fired after DialogueWindow::getVisible.
// Lua event name: "DialogueWindow::getVisible"
// Lua signature: function(self, defaultVal) -> boolean
bool CallDialogueWindowGetVisibleCallbacks(DialogueWindow* thisptr, bool defaultVal);

// Fired after DialogueWindow::setVisible.
// Lua event name: "DialogueWindow::setVisible"
// Lua signature: function(self, visible)
void CallDialogueWindowSetVisibleCallbacks(DialogueWindow* thisptr, bool visible);

// Fired after DialogueWindow::_NV_show.
// Lua event name: "DialogueWindow::_NV_show"
// Lua signature: function(self, on)
void CallDialogueWindowNVShowCallbacks(DialogueWindow* thisptr, bool on);

// Fired after DialogueWindow::hide.
// Lua event name: "DialogueWindow::hide"
// Lua signature: function(self, dialogue)
void CallDialogueWindowHideCallbacks(DialogueWindow* thisptr, Dialogue* dialogue);

// Fired after DialogueWindow::_NV_isVisible.
// Lua event name: "DialogueWindow::_NV_isVisible"
// Lua signature: function(self, defaultVal) -> boolean
bool CallDialogueWindowNVIsVisibleCallbacks(DialogueWindow* thisptr, bool defaultVal);

// Fired after DialogueWindow::_NV_update.
// Lua event name: "DialogueWindow::_NV_update"
// Lua signature: function(self)
void CallDialogueWindowNVUpdateCallbacks(DialogueWindow* thisptr);

// Fired after DialogueWindow::getTop.
// Lua event name: "DialogueWindow::getTop"
// Lua signature: function(self, defaultVal) -> integer
int CallDialogueWindowGetTopCallbacks(DialogueWindow* thisptr, int defaultVal);

// Fired after DialogueWindow::activateResponse.
// Lua event name: "DialogueWindow::activateResponse"
// Lua signature: function(self, index)
void CallDialogueWindowActivateResponseCallbacks(DialogueWindow* thisptr, int index);

// Fired after DialogueWindow::setNPCText.
// Lua event name: "DialogueWindow::setNPCText"
// Lua signature: function(self, text)
void CallDialogueWindowSetNPCTextCallbacks(DialogueWindow* thisptr, const std::string& text);

// Fired after DialogueWindow::setResponses. responses is borrowed lightuserdata.
// Lua event name: "DialogueWindow::setResponses"
// Lua signature: function(self, responses)
void CallDialogueWindowSetResponsesCallbacks(DialogueWindow* thisptr, const void* responses);

// Fired after DialogueWindow::clearResponses.
// Lua event name: "DialogueWindow::clearResponses"
// Lua signature: function(self)
void CallDialogueWindowClearResponsesCallbacks(DialogueWindow* thisptr);

// Fired after DialogueWindow::changePortrait.
// Lua event name: "DialogueWindow::changePortrait"
// Lua signature: function(self, character, player)
void CallDialogueWindowChangePortraitCallbacks(DialogueWindow* thisptr, Character* character, bool player);

// Fired before DialogueWindow::_DESTRUCTOR.
// Lua event name: "DialogueWindow::_DESTRUCTOR"
// Lua signature: function(self)
void CallDialogueWindowDestructorCallbacks(DialogueWindow* thisptr);

// Fired after DialogueWindow::updatePanelsPosition.
// Lua event name: "DialogueWindow::updatePanelsPosition"
// Lua signature: function(self)
void CallDialogueWindowUpdatePanelsPositionCallbacks(DialogueWindow* thisptr);

// -----------------------------------------------------------
// Callbacks for hooks in gui/SplashScreen.h
// -----------------------------------------------------------

// Fired by SplashScreen::_CONSTRUCTOR hook after the original call.
// Lua event name: "SplashScreen::_CONSTRUCTOR"
// Lua signature:  function(self)
void CallSplashScreenConstructedCallbacks(SplashScreen* thisptr);

// Fired by SplashScreen::_DESTRUCTOR hook before the original call.
// Lua event name: "SplashScreen::_DESTRUCTOR"
// Lua signature:  function(self)
void CallSplashScreenDestructorCallbacks(SplashScreen* thisptr);

// Fired by SplashScreen::update hook after the original call.
// Lua event name: "SplashScreen::update"
// Lua signature:  function(self)
void CallSplashScreenUpdateCallbacks(SplashScreen* thisptr);

// Fired by SplashScreen::getState hook after the original call.
// Lua event name: "SplashScreen::getState"
// Lua signature:  function(self, defaultVal) -> integer
int CallSplashScreenGetStateCallbacks(SplashScreen* thisptr, int defaultVal);

// Fired by SplashScreen::getEnded hook after the original call.
// Lua event name: "SplashScreen::getEnded"
// Lua signature:  function(self, defaultVal) -> boolean
bool CallSplashScreenGetEndedCallbacks(SplashScreen* thisptr, bool defaultVal);

// Fired by SplashScreen::skip hook after the original call.
// Lua event name: "SplashScreen::skip"
// Lua signature:  function(self)
void CallSplashScreenSkipCallbacks(SplashScreen* thisptr);

// Fired by SplashScreen::addLogo hook after the original call.
// Lua event name: "SplashScreen::addLogo"
// Lua signature:  function(self, file, scale)
void CallSplashScreenAddLogoCallbacks(SplashScreen* thisptr, const std::string& file, float scale);


// -----------------------------------------------------------
// Callbacks for OrdersPanel.h, OptionsWindow.h, MapScreen.h,
// ManagementScreen.h, and TitleScreen.h
// -----------------------------------------------------------

// Lua event name: "OrderCellView::_CONSTRUCTOR"
// Lua signature: function(self, parent)
void CallOrderCellViewConstructedCallbacks(OrderCellView* self, MyGUI::Widget* parent);

// Lua event name: "OrderCellView::_DESTRUCTOR"
// Lua signature: function(self)
void CallOrderCellViewDestructorCallbacks(OrderCellView* self);

// Lua event name: "OrderCellView::update"
// Lua signature: function(self, info, data)
void CallOrderCellViewUpdateCallbacks(OrderCellView* self, void* info, OrderData* data);

// Lua event name: "OrderCellView::getCellDimension"
// Lua signature: function(sender, coord, drop)
void CallOrderCellViewGetCellDimensionCallbacks(MyGUI::Widget* sender, const MyGUI::IntCoord& coord, bool drop);

// Lua event name: "OrderCellView::getWidget"
// Lua signature: function(self, result)
void CallOrderCellViewGetWidgetCallbacks(OrderCellView* self, MyGUI::Widget* result);

// Lua event name: "OrderCellView::onRemove"
// Lua signature: function(self, sender)
void CallOrderCellViewOnRemoveCallbacks(OrderCellView* self, MyGUI::Widget* sender);

// Lua event name: "OrderCellView::resize"
// Lua signature: function(self)
void CallOrderCellViewResizeCallbacks(OrderCellView* self);

// Lua event name: "OrderData::_CONSTRUCTOR"
// Lua signature: function(self)
void CallOrderDataConstructedCallbacks(OrderData* self);

// Lua event name: "OrderData::set"
// Lua signature: function(self, task, index, enabled)
void CallOrderDataSetCallbacks(OrderData* self, Tasker* task, int index, bool enabled);

// Lua event name: "OrderData::updateText"
// Lua signature: function(self)
void CallOrderDataUpdateTextCallbacks(OrderData* self);

// Lua event name: "OrderData::_DESTRUCTOR"
// Lua signature: function(self)
void CallOrderDataDestructorCallbacks(OrderData* self);

// Lua event name: "OrderData::operator="
// Lua signature: function(self, other, result)
void CallOrderDataAssignCallbacks(OrderData* self, OrderData* other, OrderData* result);

// Lua event name: "OrdersItemBox::_CONSTRUCTOR"
// Lua signature: function(self, parent)
void CallOrdersItemBoxConstructedCallbacks(OrdersItemBox* self, MyGUI::Widget* parent);

// Lua event name: "OrdersItemBox::_DESTRUCTOR"
// Lua signature: function(self)
void CallOrdersItemBoxDestructorCallbacks(OrdersItemBox* self);

// Lua event name: "OrdersPanel::_CONSTRUCTOR"
// Lua signature: function(self, mainbar, panel)
void CallOrdersPanelConstructedCallbacks(OrdersPanel* self, MainBarGUI* mainbar, MyGUI::Widget* panel);

// Lua event name: "OrdersPanel::_DESTRUCTOR"
// Lua signature: function(self)
void CallOrdersPanelDestructorCallbacks(OrdersPanel* self);

// Lua event name: "OrdersPanel::update"
// Lua signature: function(self, character)
void CallOrdersPanelUpdateCallbacks(OrdersPanel* self, Character* character);

// Lua event name: "OrdersPanel::clear"
// Lua signature: function(self)
void CallOrdersPanelClearCallbacks(OrdersPanel* self);

// Lua event name: "OrdersPanel::command"
// Lua signature: function(self, command)
void CallOrdersPanelCommandCallbacks(OrdersPanel* self, int command);

// Lua event name: "OrdersPanel::refreshOrders"
// Lua signature: function(self)
void CallOrdersPanelRefreshOrdersCallbacks(OrdersPanel* self);

// Lua event name: "OrdersPanel::moveJob"
// Lua signature: function(self, orderIndex, targetIndex)
void CallOrdersPanelMoveJobCallbacks(OrdersPanel* self, int orderIndex, int targetIndex);

// Lua event name: "OrdersPanel::removeJob"
// Lua signature: function(self, data)
void CallOrdersPanelRemoveJobCallbacks(OrdersPanel* self, OrderData* data);

// Lua event name: "OrdersPanel::notifyStartDropOrder"
// Lua signature: function(self, sender, info, defaultVal) -> boolean
bool CallOrdersPanelNotifyStartDropOrderCallbacks(OrdersPanel* self, wraps::BaseLayout* sender, void* info, bool defaultVal);

// Lua event name: "OrdersPanel::notifyRequestDropOrder"
// Lua signature: function(self, sender, info, defaultVal) -> boolean
bool CallOrdersPanelNotifyRequestDropOrderCallbacks(OrdersPanel* self, wraps::BaseLayout* sender, void* info, bool defaultVal);

// Lua event name: "OrdersPanel::notifyEndDropOrder"
// Lua signature: function(self, sender, info, result)
void CallOrdersPanelNotifyEndDropOrderCallbacks(OrdersPanel* self, wraps::BaseLayout* sender, void* info, bool result);

// Lua event name: "OrdersPanel::toggleStealth"
// Lua signature: function(self, sender)
void CallOrdersPanelToggleStealthCallbacks(OrdersPanel* self, MyGUI::Widget* sender);

// Lua event name: "OrdersPanel::toggleRanged"
// Lua signature: function(self, sender)
void CallOrdersPanelToggleRangedCallbacks(OrdersPanel* self, MyGUI::Widget* sender);

// Lua event name: "OrdersPanel::setSpeed"
// Lua signature: function(self, speed)
void CallOrdersPanelSetSpeedCallbacks(OrdersPanel* self, int speed);

// Lua event name: "OrdersPanel::setSpeedImage"
// Lua signature: function(self, speed)
void CallOrdersPanelSetSpeedImageCallbacks(OrdersPanel* self, int speed);

// Lua event name: "OrdersPanel::speedPrevious"
// Lua signature: function(self, sender)
void CallOrdersPanelSpeedPreviousCallbacks(OrdersPanel* self, MyGUI::Widget* sender);

// Lua event name: "OrdersPanel::speedNext"
// Lua signature: function(self, sender)
void CallOrdersPanelSpeedNextCallbacks(OrdersPanel* self, MyGUI::Widget* sender);

// Lua event name: "OrdersPanel::blockmodeButton"
// Lua signature: function(self, sender)
void CallOrdersPanelBlockModeButtonCallbacks(OrdersPanel* self, MyGUI::Widget* sender);

// Lua event name: "OrdersPanel::holdButtonCallback"
// Lua signature: function(self, sender)
void CallOrdersPanelHoldButtonCallbacks(OrdersPanel* self, MyGUI::Widget* sender);

// Lua event name: "OrdersPanel::passiveButtonCallback"
// Lua signature: function(self, sender)
void CallOrdersPanelPassiveButtonCallbacks(OrdersPanel* self, MyGUI::Widget* sender);

// Lua event name: "OrdersPanel::chaseButtonCallback"
// Lua signature: function(self, sender)
void CallOrdersPanelChaseButtonCallbacks(OrdersPanel* self, MyGUI::Widget* sender);

// Lua event name: "OrdersPanel::tauntButtonCallback"
// Lua signature: function(self, sender)
void CallOrdersPanelTauntButtonCallbacks(OrdersPanel* self, MyGUI::Widget* sender);

// Lua event name: "OrdersPanel::medicButton"
// Lua signature: function(self, sender)
void CallOrdersPanelMedicButtonCallbacks(OrdersPanel* self, MyGUI::Widget* sender);

// Lua event name: "OrdersPanel::liftButton"
// Lua signature: function(self, sender)
void CallOrdersPanelLiftButtonCallbacks(OrdersPanel* self, MyGUI::Widget* sender);

// Lua event name: "OrdersPanel::prospectingButton"
// Lua signature: function(self, sender)
void CallOrdersPanelProspectingButtonCallbacks(OrdersPanel* self, MyGUI::Widget* sender);

// Lua event name: "OptionsWindow::getSingleton"
// Lua signature: function(defaultVal) -> OptionsWindow
OptionsWindow* CallOptionsWindowGetSingletonCallbacks(OptionsWindow* defaultVal);

// Lua event name: "OptionsWindow::_NV_show"
// Lua signature: function(self, value)
void CallOptionsWindowNVShowCallbacks(OptionsWindow* self, bool value);

// Lua event name: "OptionsWindow::show"
// Lua signature: function(self)
void CallOptionsWindowShowCallbacks(OptionsWindow* self);

// Lua event name: "OptionsWindow::hide"
// Lua signature: function(self)
void CallOptionsWindowHideCallbacks(OptionsWindow* self);

// Lua event name: "OptionsWindow::toggle"
// Lua signature: function(self)
void CallOptionsWindowToggleCallbacks(OptionsWindow* self);

// Lua event name: "OptionsWindow::isVisible"
// Lua signature: function(self, defaultVal) -> boolean
bool CallOptionsWindowIsVisibleCallbacks(OptionsWindow* self, bool defaultVal);

// Lua event name: "OptionsWindow::waitingForKey"
// Lua signature: function(self, defaultVal) -> boolean
bool CallOptionsWindowWaitingForKeyCallbacks(OptionsWindow* self, bool defaultVal);

// Lua event name: "OptionsWindow::setKey"
// Lua signature: function(self, code)
void CallOptionsWindowSetKeyCallbacks(OptionsWindow* self, int code);

// Lua event name: "OptionsWindow::_NV_update"
// Lua signature: function(self)
void CallOptionsWindowNVUpdateCallbacks(OptionsWindow* self);

// Lua event name: "OptionsWindow::_CONSTRUCTOR"
// Lua signature: function(self)
void CallOptionsWindowConstructedCallbacks(OptionsWindow* self);

// Lua event name: "OptionsWindow::_DESTRUCTOR"
// Lua signature: function(self)
void CallOptionsWindowDestructorCallbacks(OptionsWindow* self);

// Lua event name: "OptionsWindow::saveLocationChanged"
// Lua signature: function(self, line)
void CallOptionsWindowSaveLocationChangedCallbacks(OptionsWindow* self, DataPanelLine* line);

// Lua event name: "OptionsWindow::changeFontSize"
// Lua signature: function(self, line)
void CallOptionsWindowChangeFontSizeCallbacks(OptionsWindow* self, DataPanelLine* line);

// Lua event name: "OptionsWindow::changeVolume"
// Lua signature: function(self, line)
void CallOptionsWindowChangeVolumeCallbacks(OptionsWindow* self, DataPanelLine* line);

// Lua event name: "OptionsWindow::toggleNames"
// Lua signature: function(self, line)
void CallOptionsWindowToggleNamesCallbacks(OptionsWindow* self, DataPanelLine* line);

// Lua event name: "OptionsWindow::resetTutorials"
// Lua signature: function(self, line)
void CallOptionsWindowResetTutorialsCallbacks(OptionsWindow* self, DataPanelLine* line);

// Lua event name: "OptionsWindow::toggleTutorials"
// Lua signature: function(self, line)
void CallOptionsWindowToggleTutorialsCallbacks(OptionsWindow* self, DataPanelLine* line);

// Lua event name: "OptionsWindow::changeDistances"
// Lua signature: function(self, line)
void CallOptionsWindowChangeDistancesCallbacks(OptionsWindow* self, DataPanelLine* line);

// Lua event name: "OptionsWindow::toggleCompositor"
// Lua signature: function(self, line)
void CallOptionsWindowToggleCompositorCallbacks(OptionsWindow* self, DataPanelLine* line);

// Lua event name: "OptionsWindow::resetAllKeys"
// Lua signature: function(self, line)
void CallOptionsWindowResetAllKeysCallbacks(OptionsWindow* self, DataPanelLine* line);

// Lua event name: "OptionsWindow::saveOptions"
// Lua signature: function(self)
void CallOptionsWindowSaveOptionsCallbacks(OptionsWindow* self);

// Lua event name: "OptionsWindow::create"
// Lua signature: function(self)
void CallOptionsWindowCreateCallbacks(OptionsWindow* self);

// Lua event name: "OptionsWindow::updateResolutions"
// Lua signature: function(self)
void CallOptionsWindowUpdateResolutionsCallbacks(OptionsWindow* self);

// Lua event name: "OptionsWindow::closeButton"
// Lua signature: function(self, sender)
void CallOptionsWindowCloseButtonCallbacks(OptionsWindow* self, MyGUI::Widget* sender);

// Lua event name: "MapScreen::MapMarkerTown::_CONSTRUCTOR"
// Lua signature: function(self, town, mapScreen)
void CallMapMarkerTownConstructedCallbacks(MapScreen::MapMarkerTown* self, TownBase* town, MapScreen* mapScreen);

// Lua event name: "MapScreen::MapMarkerTown::_DESTRUCTOR"
// Lua signature: function(self)
void CallMapMarkerTownDestructorCallbacks(MapScreen::MapMarkerTown* self);

// Lua event name: "MapScreen::MapMarkerTown::update"
// Lua signature: function(self, mapPosition, zoom)
void CallMapMarkerTownUpdateCallbacks(MapScreen::MapMarkerTown* self, const MyGUI::IntPoint& mapPosition, int zoom);

// Lua event name: "MapScreen::MapMarkerTown::setVisible"
// Lua signature: function(self, value)
void CallMapMarkerTownSetVisibleCallbacks(MapScreen::MapMarkerTown* self, bool value);

// Lua event name: "MapScreen::MapMarkerTown::getVisible"
// Lua signature: function(self, defaultVal) -> boolean
bool CallMapMarkerTownGetVisibleCallbacks(MapScreen::MapMarkerTown* self, bool defaultVal);

// Lua event name: "MapScreen::MapMarkerCharacter::_CONSTRUCTOR"
// Lua signature: function(self, character, mapScreen)
void CallMapMarkerCharacterConstructedCallbacks(MapScreen::MapMarkerCharacter* self, RootObjectBase* character, MapScreen* mapScreen);

// Lua event name: "MapScreen::MapMarkerCharacter::_DESTRUCTOR"
// Lua signature: function(self)
void CallMapMarkerCharacterDestructorCallbacks(MapScreen::MapMarkerCharacter* self);

// Lua event name: "MapScreen::MapMarkerCharacter::update"
// Lua signature: function(self, mapPosition)
void CallMapMarkerCharacterUpdateCallbacks(MapScreen::MapMarkerCharacter* self, const MyGUI::IntPoint& mapPosition);

// Lua event name: "MapScreen::MapMarkerCharacter::setVisible"
// Lua signature: function(self, value)
void CallMapMarkerCharacterSetVisibleCallbacks(MapScreen::MapMarkerCharacter* self, bool value);

// Lua event name: "MapScreen::MapMarkerCharacter::getVisible"
// Lua signature: function(self, defaultVal) -> boolean
bool CallMapMarkerCharacterGetVisibleCallbacks(MapScreen::MapMarkerCharacter* self, bool defaultVal);

// Lua event name: "MapScreen::_CONSTRUCTOR"
// Lua signature: function(self, screen)
void CallMapScreenConstructedCallbacks(MapScreen* self, ManagementScreen* screen);

// Lua event name: "MapScreen::_DESTRUCTOR"
// Lua signature: function(self)
void CallMapScreenDestructorCallbacks(MapScreen* self);

// Lua event name: "MapScreen::clear"
// Lua signature: function(self)
void CallMapScreenClearCallbacks(MapScreen* self);

// Lua event name: "MapScreen::getVisible"
// Lua signature: function(self, defaultVal) -> boolean
bool CallMapScreenGetVisibleCallbacks(MapScreen* self, bool defaultVal);

// Lua event name: "MapScreen::centerCamera"
// Lua signature: function(self)
void CallMapScreenCenterCameraCallbacks(MapScreen* self);

// Lua event name: "MapScreen::clearTempMarkers"
// Lua signature: function(self)
void CallMapScreenClearTempMarkersCallbacks(MapScreen* self);

// Lua event name: "MapScreen::refresh"
// Lua signature: function(self)
void CallMapScreenRefreshCallbacks(MapScreen* self);

// Lua event name: "MapScreen::update"
// Lua signature: function(self)
void CallMapScreenUpdateCallbacks(MapScreen* self);

// Lua event name: "MapScreen::addSquad"
// Lua signature: function(self, squad)
void CallMapScreenAddSquadCallbacks(MapScreen* self, Platoon* squad);

// Lua event name: "MapScreen::removeSquad"
// Lua signature: function(self, squad)
void CallMapScreenRemoveSquadCallbacks(MapScreen* self, Platoon* squad);

// Lua event name: "MapScreen::hide"
// Lua signature: function(self)
void CallMapScreenHideCallbacks(MapScreen* self);

// Lua event name: "MapScreen::setMovementMarker"
// Lua signature: function(self, position, time)
void CallMapScreenSetMovementMarkerCallbacks(MapScreen* self, const Ogre::Vector3& position, float time);

// Lua event name: "MapScreen::showRoads"
// Lua signature: function(self, on)
void CallMapScreenShowRoadsCallbacks(MapScreen* self, bool on);

// Lua event name: "MapScreen::updatePlayerTownMapMarker"
// Lua signature: function(self, town)
void CallMapScreenUpdatePlayerTownMapMarkerCallbacks(MapScreen* self, const hand& town);

// Lua event name: "MapScreen::updateZoom"
// Lua signature: function(self)
void CallMapScreenUpdateZoomCallbacks(MapScreen* self);

// Lua event name: "MapScreen::updateCameraMarker"
// Lua signature: function(self)
void CallMapScreenUpdateCameraMarkerCallbacks(MapScreen* self);

// Lua event name: "MapScreen::refreshTowns"
// Lua signature: function(self)
void CallMapScreenRefreshTownsCallbacks(MapScreen* self);

// Lua event name: "MapScreen::refreshSquads"
// Lua signature: function(self)
void CallMapScreenRefreshSquadsCallbacks(MapScreen* self);

// Lua event name: "MapScreen::updateCharacterMarker"
// Lua signature: function(self, object)
void CallMapScreenUpdateCharacterMarkerCallbacks(MapScreen* self, RootObjectBase* object);

// Lua event name: "MapScreen::getMouseWorldPosition"
// Lua signature: function(self, position, defaultVal) -> boolean
bool CallMapScreenGetMouseWorldPositionCallbacks(MapScreen* self, const Ogre::Vector3& position, bool defaultVal);

// Lua event name: "MapScreen::worldToMapCoords"
// Lua signature: function(self, position, result)
void CallMapScreenWorldToMapCoordsCallbacks(MapScreen* self, const Ogre::Vector3& position, const MyGUI::IntPoint& result);

// Lua event name: "MapScreen::mapCoordsToWorld"
// Lua signature: function(self, point, result)
void CallMapScreenMapCoordsToWorldCallbacks(MapScreen* self, const MyGUI::IntPoint& point, const Ogre::Vector3& result);

// Lua event name: "MapScreen::mapMouseWheel"
// Lua signature: function(self, sender, rel)
void CallMapScreenMapMouseWheelCallbacks(MapScreen* self, MyGUI::Widget* sender, int rel);

// Lua event name: "MapScreen::mapMousePressed"
// Lua signature: function(self, sender, left, top, id)
void CallMapScreenMapMousePressedCallbacks(MapScreen* self, MyGUI::Widget* sender, int left, int top, int id);

// Lua event name: "MapScreen::mapMouseReleased"
// Lua signature: function(self, sender, left, top, id)
void CallMapScreenMapMouseReleasedCallbacks(MapScreen* self, MyGUI::Widget* sender, int left, int top, int id);

// Lua event name: "MapScreen::setupRoads"
// Lua signature: function(self)
void CallMapScreenSetupRoadsCallbacks(MapScreen* self);

// Lua event name: "MapScreen::updateRoads"
// Lua signature: function(self)
void CallMapScreenUpdateRoadsCallbacks(MapScreen* self);

// Lua event name: "MapScreen::centerButton"
// Lua signature: function(self, sender)
void CallMapScreenCenterButtonCallbacks(MapScreen* self, MyGUI::Widget* sender);

// Lua event name: "MapScreen::zoomInButton"
// Lua signature: function(self, sender)
void CallMapScreenZoomInButtonCallbacks(MapScreen* self, MyGUI::Widget* sender);

// Lua event name: "MapScreen::zoomOutButton"
// Lua signature: function(self, sender)
void CallMapScreenZoomOutButtonCallbacks(MapScreen* self, MyGUI::Widget* sender);

// Lua event name: "MapScreen::getMarkerColor"
// Lua signature: function(who, result)
void CallMapScreenGetMarkerColorCallbacks(RootObjectBase* who, const MyGUI::Colour& result);

// Lua event name: "ManagementScreen::getSingleton"
// Lua signature: function(defaultVal) -> ManagementScreen
ManagementScreen* CallManagementScreenGetSingletonCallbacks(ManagementScreen* defaultVal);

// Lua event name: "ManagementScreen::_DESTRUCTOR"
// Lua signature: function(self)
void CallManagementScreenDestructorCallbacks(ManagementScreen* self);

// Lua event name: "ManagementScreen::update"
// Lua signature: function(self)
void CallManagementScreenUpdateCallbacks(ManagementScreen* self);

// Lua event name: "ManagementScreen::clear"
// Lua signature: function(self)
void CallManagementScreenClearCallbacks(ManagementScreen* self);

// Lua event name: "ManagementScreen::getVisible"
// Lua signature: function(self, defaultVal) -> boolean
bool CallManagementScreenGetVisibleCallbacks(ManagementScreen* self, bool defaultVal);

// Lua event name: "ManagementScreen::setVisible"
// Lua signature: function(self, on, tab)
void CallManagementScreenSetVisibleCallbacks(ManagementScreen* self, bool on, int tab);

// Lua event name: "ManagementScreen::closeEverythingButton"
// Lua signature: function(self, widget, name)
void CallManagementScreenCloseEverythingButtonCallbacks(ManagementScreen* self, MyGUI::Widget* widget, const std::string& name);

// Lua event name: "ManagementScreen::tabCallback"
// Lua signature: function(self, sender, index)
void CallManagementScreenTabCallbackCallbacks(ManagementScreen* self, MyGUI::Widget* sender, double index);

// Lua event name: "ManagementScreen::getCurrentTab"
// Lua signature: function(self, defaultVal) -> number
double CallManagementScreenGetCurrentTabCallbacks(ManagementScreen* self, double defaultVal);

// Lua event name: "ManagementScreen::getTab"
// Lua signature: function(self, index, result)
void CallManagementScreenGetTabCallbacks(ManagementScreen* self, int index, MyGUI::Widget* result);

// Lua event name: "ManagementScreen::getWidget"
// Lua signature: function(self, name, result)
void CallManagementScreenGetWidgetCallbacks(ManagementScreen* self, const std::string& name, MyGUI::Widget* result);

// Lua event name: "ManagementScreen::refresh"
// Lua signature: function(self, current, progress)
void CallManagementScreenRefreshCallbacks(ManagementScreen* self, GameData* current, float progress);

// Lua event name: "ManagementScreen::refreshResearchList"
// Lua signature: function(self)
void CallManagementScreenRefreshResearchListCallbacks(ManagementScreen* self);

// Lua event name: "ManagementScreen::refreshResearchRate"
// Lua signature: function(self)
void CallManagementScreenRefreshResearchRateCallbacks(ManagementScreen* self);

// Lua event name: "ManagementScreen::refreshDiplomacy"
// Lua signature: function(self)
void CallManagementScreenRefreshDiplomacyCallbacks(ManagementScreen* self);

// Lua event name: "ManagementScreen::refreshSquads"
// Lua signature: function(self)
void CallManagementScreenRefreshSquadsCallbacks(ManagementScreen* self);

// Lua event name: "ManagementScreen::refreshMap"
// Lua signature: function(self, centerCamera)
void CallManagementScreenRefreshMapCallbacks(ManagementScreen* self, bool centerCamera);

// Lua event name: "ManagementScreen::showRoads"
// Lua signature: function(self, value)
void CallManagementScreenShowRoadsCallbacks(ManagementScreen* self, bool value);

// Lua event name: "ManagementScreen::addSquadToMap"
// Lua signature: function(self, squad)
void CallManagementScreenAddSquadToMapCallbacks(ManagementScreen* self, Platoon* squad);

// Lua event name: "ManagementScreen::removeSquadFromMap"
// Lua signature: function(self, squad)
void CallManagementScreenRemoveSquadFromMapCallbacks(ManagementScreen* self, Platoon* squad);

// Lua event name: "ManagementScreen::addMessage"
// Lua signature: function(self, owner, message, logColor)
void CallManagementScreenAddMessageCallbacks(ManagementScreen* self, const std::string& owner, const std::string& message, int logColor);

// Lua event name: "ManagementScreen::resetSquads"
// Lua signature: function(self)
void CallManagementScreenResetSquadsCallbacks(ManagementScreen* self);

// Lua event name: "ManagementScreen::refreshMessages"
// Lua signature: function(self)
void CallManagementScreenRefreshMessagesCallbacks(ManagementScreen* self);

// Lua event name: "ManagementScreen::refreshAI"
// Lua signature: function(self)
void CallManagementScreenRefreshAICallbacks(ManagementScreen* self);

// Lua event name: "ManagementScreen::setCraftingBench"
// Lua signature: function(self, buildingHandle)
void CallManagementScreenSetCraftingBenchCallbacks(ManagementScreen* self, const hand& buildingHandle);

// Lua event name: "ManagementScreen::printResearch"
// Lua signature: function(panel, data, listName, displayName, category)
void CallManagementScreenPrintResearchCallbacks(DatapanelGUI* panel, GameData* data, const std::string& listName, const std::string& displayName, int category);

// Lua event name: "ManagementScreen::showDebugMarker"
// Lua signature: function(self, position)
void CallManagementScreenShowDebugMarkerCallbacks(ManagementScreen* self, const Ogre::Vector3& position);

// Lua event name: "ManagementScreen::_CONSTRUCTOR"
// Lua signature: function(self)
void CallManagementScreenConstructedCallbacks(ManagementScreen* self);

// Lua event name: "ManagementScreen::updateResearchListRate"
// Lua signature: function(self)
void CallManagementScreenUpdateResearchListRateCallbacks(ManagementScreen* self);

// Lua event name: "ManagementScreen::refreshResearchListDescription"
// Lua signature: function(self)
void CallManagementScreenRefreshResearchListDescriptionCallbacks(ManagementScreen* self);

// Lua event name: "ManagementScreen::researchTypeSelect"
// Lua signature: function(self, sender, index)
void CallManagementScreenResearchTypeSelectCallbacks(ManagementScreen* self, MyGUI::Widget* sender, double index);

// Lua event name: "ManagementScreen::addButtonPress"
// Lua signature: function(self, sender, left, top, id)
void CallManagementScreenAddButtonPressCallbacks(ManagementScreen* self, MyGUI::Widget* sender, int left, int top, int id);

// Lua event name: "ManagementScreen::removeButtonPress"
// Lua signature: function(self, sender, left, top, id)
void CallManagementScreenRemoveButtonPressCallbacks(ManagementScreen* self, MyGUI::Widget* sender, int left, int top, int id);

// Lua event name: "ManagementScreen::mouseOverCallback"
// Lua signature: function(self, sender, left, top)
void CallManagementScreenMouseOverCallbacks(ManagementScreen* self, MyGUI::Widget* sender, int left, int top);

// Lua event name: "ManagementScreen::TechItemViewData::getName"
// Lua signature: function(self, result)
void CallTechItemViewDataGetNameCallbacks(ManagementScreen::TechItemViewData* self, const std::string& result);

// Lua event name: "ManagementScreen::TechItemViewData::getValue"
// Lua signature: function(self, result)
void CallTechItemViewDataGetValueCallbacks(ManagementScreen::TechItemViewData* self, const std::string& result);

// Lua event name: "ManagementScreen::TechItemViewData::getProgress"
// Lua signature: function(self, defaultVal) -> number
double CallTechItemViewDataGetProgressCallbacks(ManagementScreen::TechItemViewData* self, double defaultVal);

// Lua event name: "ManagementScreen::TechItemViewData::setItem"
// Lua signature: function(self, item)
void CallTechItemViewDataSetItemCallbacks(ManagementScreen::TechItemViewData* self, void* item);

// Lua event name: "ManagementScreen::TechItemViewData::_DESTRUCTOR"
// Lua signature: function(self)
void CallTechItemViewDataDestructorCallbacks(ManagementScreen::TechItemViewData* self);

// Lua event name: "ManagementScreen::researchQueueTooltip"
// Lua signature: function(self, layout, info, data)
void CallManagementScreenResearchQueueTooltipCallbacks(ManagementScreen* self, wraps::BaseLayout* layout, void* info, const ManagementScreen::TechItemViewData& data);

// Lua event name: "ManagementScreen::researchRemoved"
// Lua signature: function(self, index, item)
void CallManagementScreenResearchRemovedCallbacks(ManagementScreen* self, int index, const ManagementScreen::TechItemViewData& item);

// Lua event name: "ManagementScreen::researchValidateOrder"
// Lua signature: function(self, first, second, defaultVal) -> boolean
bool CallManagementScreenResearchValidateOrderCallbacks(ManagementScreen* self, int first, int second, bool defaultVal);

// Lua event name: "TitleScreen::getSingleton"
// Lua signature: function(defaultVal) -> TitleScreen
TitleScreen* CallTitleScreenGetSingletonCallbacks(TitleScreen* defaultVal);

// Lua event name: "TitleScreen::_CONSTRUCTOR"
// Lua signature: function(self)
void CallTitleScreenConstructedCallbacks(TitleScreen* self);

// Lua event name: "TitleScreen::_DESTRUCTOR"
// Lua signature: function(self)
void CallTitleScreenDestructorCallbacks(TitleScreen* self);

// Lua event name: "TitleScreen::_NV_clear"
// Lua signature: function(self)
void CallTitleScreenNVClearCallbacks(TitleScreen* self);

// Lua event name: "TitleScreen::_NV_show"
// Lua signature: function(self, on)
void CallTitleScreenNVShowCallbacks(TitleScreen* self, bool on);

// Lua event name: "TitleScreen::_NV_update"
// Lua signature: function(self)
void CallTitleScreenNVUpdateCallbacks(TitleScreen* self);

// Lua event name: "TitleScreen::closeTheOtherBits"
// Lua signature: function(self, defaultVal) -> boolean
bool CallTitleScreenCloseTheOtherBitsCallbacks(TitleScreen* self, bool defaultVal);

// Lua event name: "TitleScreen::loadGame"
// Lua signature: function(self, sender)
void CallTitleScreenLoadGameCallbacks(TitleScreen* self, MyGUI::Widget* sender);

// Lua event name: "TitleScreen::importGame"
// Lua signature: function(self, sender)
void CallTitleScreenImportGameCallbacks(TitleScreen* self, MyGUI::Widget* sender);

// Lua event name: "TitleScreen::showOptions"
// Lua signature: function(self, sender)
void CallTitleScreenShowOptionsCallbacks(TitleScreen* self, MyGUI::Widget* sender);

// Lua event name: "TitleScreen::credits"
// Lua signature: function(self, sender)
void CallTitleScreenCreditsCallbacks(TitleScreen* self, MyGUI::Widget* sender);

// Lua event name: "TitleScreen::exitGame"
// Lua signature: function(self, sender)
void CallTitleScreenExitGameCallbacks(TitleScreen* self, MyGUI::Widget* sender);

// Lua event name: "TitleScreen::continueGame"
// Lua signature: function(self, sender)
void CallTitleScreenContinueGameCallbacks(TitleScreen* self, MyGUI::Widget* sender);

// Lua event name: "TitleScreen::hover"
// Lua signature: function(self, sender, other)
void CallTitleScreenHoverCallbacks(TitleScreen* self, MyGUI::Widget* sender, MyGUI::Widget* other);

// Lua event name: "TitleScreen::setCreditsVisible"
// Lua signature: function(self, value)
void CallTitleScreenSetCreditsVisibleCallbacks(TitleScreen* self, bool value);
