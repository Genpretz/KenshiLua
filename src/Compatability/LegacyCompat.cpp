#include "pch.h"
#include "Compatability/LegacyCompat.h"
#include "Logger.h"

#include <lua.hpp>
#include <cstring>
#include <string>
#include <algorithm>

namespace KenshiLua
{
    namespace LegacyCompat
    {
        struct LegacyEventAlias
        {
            const char* legacy;
            const char* canonical;
        };

    static const LegacyEventAlias g_legacyEventAliases[] = {
        { "BaseLayout::initialise", "wraps::BaseLayout::initialise" },
        { "chooseAttack", "CharStats::chooseAttack" },
        { "clearHoldLocation", "CharStats::clearHoldLocation" },
        { "onActivePlatoonConstructed", "ActivePlatoon::_CONSTRUCTOR" },
        { "onActivePlatoonCreated", "Faction::createNewEmptyActivePlatoon" },
        { "onArmourConstructed", "Armour::_CONSTRUCTOR" },
        { "onBaseLayoutInitialise", "wraps::BaseLayout::initialise" },
        { "onBountyConstructed", "Bounty::_CONSTRUCTOR" },
        { "onBuildModeConfirm", "BuildModeWindow::confirm" },
        { "onBuildingAddConstructionProgress", "Building::_NV_addConstructionProgress" },
        { "onBuildingAddDismantleProgress", "Building::_NV_addDismantleProgress" },
        { "onBuildingAddInternalBuilding", "Building::addAnInternalBuilding" },
        { "onBuildingBrokenChanged", "Building::_NV_setBroken" },
        { "onBuildingBuyMeCallback", "Building::_NV_buyMeCallback" },
        { "onBuildingCalculateSaleValue", "Building::calculateSaleValue" },
        { "onBuildingCanUpgrade", "Building::_NV_canUpgrade" },
        { "onBuildingConstructed", "Building::_CONSTRUCTOR" },
        { "onBuildingDestroyDoors", "Building::destroyDoors" },
        { "onBuildingIsForSale", "Building::isForSale" },
        { "onBuildingIsPublic", "Building::isPublic" },
        { "onBuildingLoadFromSerialise", "Building::_NV_loadFromSerialise" },
        { "onBuildingLoaded", "Building::_NV_onBuildingLoaded" },
        { "onBuildingNotifyConstructionComplete", "Building::_NV_notifyConstructionComplete" },
        { "onBuildingNotifyConstructionDismantling", "Building::_NV_notifyConstructionDismantling" },
        { "onBuildingNotifyEffect", "Building::_NV_notifyEffect" },
        { "onBuildingSerialise", "Building::_NV_serialise" },
        { "onBuildingSetConstructionProgress", "Building::_NV_setConstructionProgress" },
        { "onBuildingSetFaction", "Building::_NV_setFaction" },
        { "onBuildingSetFloorVisibility", "Building::setFloorVisibility" },
        { "onBuildingSetResidentSquad", "Building::setResidentSquad" },
        { "onBuildingSwitchEffects", "Building::_NV_switchEffects" },
        { "onBuildingSwitchLights", "Building::_NV_switchLights" },
        { "onBuildingUpgrade", "Building::_NV_upgrade" },
        { "onBuildingUseCheck", "Ownerships::canIUseThisBuilding" },
        { "onChainedModeChanged", "Character::setChainedMode" },
        { "onCharBodyConstructed", "CharBody::_CONSTRUCTOR" },
        { "onCharMovementConstructed", "CharMovement::_CONSTRUCTOR" },
        { "onCharMovementIsRunning", "CharMovement::isRunning" },
        { "onCharMovementIsRunningAway", "CharMovement::isRunningAway" },
        { "onCharStatsConstructed", "CharStats::_CONSTRUCTOR" },
        { "onCharStatsXpDodgeEvent", "CharStats::xpDodgeEvent" },
        { "onCharStatsXpStatEvent", "CharStats::xpStat_eventBased" },
        { "onCharacterAddGoal", "Character::addGoal" },
        { "onCharacterAddJob", "Character::addJob" },
        { "onCharacterAddOrder", "Character::addOrder" },
        { "onCharacterAnimalConstructed", "CharacterAnimal::_CONSTRUCTOR" },
        { "onCharacterConstructed", "Character::_CONSTRUCTOR" },
        { "onCharacterDeath", "Character::declareDead" },
        { "onCharacterEat", "Character::eatItem" },
        { "onCharacterEquip", "Character::_NV_equipItem" },
        { "onCharacterFactionChanged", "Character::_NV_setFaction" },
        { "onCharacterGetPickedUp", "Character::getPickedUp" },
        { "onCharacterGettingEaten", "Character::_NV_gettingEaten" },
        { "onCharacterHitByMelee", "Character::_NV_hitByMeleeAttack" },
        { "onCharacterHumanConstructed", "CharacterHuman::_CONSTRUCTOR" },
        { "onCharacterInit", "Character::_NV_init" },
        { "onCharacterKnockedOut", "MedicalSystem::knockout" },
        { "onCharacterLoadFromSerialise", "Character::_NV_loadFromSerialise" },
        { "onCharacterLoadFromSerialisePostCreationStage", "Character::_NV_loadFromSerialisePostCreationStage" },
        { "onCharacterLootCheck", "Character::isItOkForMeToLoot" },
        { "onCharacterPickupObject", "Character::pickupObject" },
        { "onCharacterRemoveJob", "Character::removeJob" },
        { "onCharacterSay", "Character::_NV_say" },
        { "onCharacterSelect", "Character::_NV_select" },
        { "onCharacterSerialise", "Character::_NV_serialise" },
        { "onCharacterStandingOrderChanged", "Character::_NV_setStandingOrder" },
        { "onCharacterTakeMoney", "Character::_NV_takeMoney" },
        { "onCharacterUnequip", "Character::_NV_unequipItem" },
        { "onCharacterUnselect", "Character::_NV_unselect" },
        { "onCharacterWakeUp", "MedicalSystem::canGetUpWakeUp" },
        { "onCharsUpdate", "GameWorld::charsUpdate" },
        { "onChooseMyClothing", "RootObjectFactory::chooseMyClothing" },
        { "onCombatClassConstructed", "CombatClass::_CONSTRUCTOR" },
        { "onCombatTechniqueDataConstructed", "CombatTechniqueData::_CONSTRUCTOR" },
        { "onCraftingBuildingAddFinishedCraftItem", "CraftingBuilding::addFinishedCraftItem" },
        { "onCraftingBuildingConstructed", "CraftingBuilding::_CONSTRUCTOR" },
        { "onCraftingBuildingDestroyProductionItem", "CraftingBuilding::destroyProductionItem" },
        { "onCraftingBuildingNewCraftingButton", "CraftingBuilding::_NV_newCraftingButton" },
        { "onCraftingBuildingNotifyCraftFailure", "CraftingBuilding::notifyCraftFailiure" },
        { "onCraftingBuildingOperate", "CraftingBuilding::_NV_operate" },
        { "onCraftingBuildingRemoveCraft", "CraftingBuilding::_removeCraft" },
        { "onCrimeWitnessed", "BountyManager::notifyCrimeWitnessed" },
        { "onCrossbowConstructed", "Crossbow::_CONSTRUCTOR" },
        { "onDamagesConstructed", "Damages::_CONSTRUCTOR" },
        { "onDataPanelLineButtonPress", "DataPanelLine_Button::pressCallback" },
        { "onDialogLineDataConstructed", "DialogLineData::_CONSTRUCTOR" },
        { "onDialogueCheckCondition", "Dialogue::_checkCondition" },
        { "onDialogueConstructed", "Dialogue::_CONSTRUCTOR" },
        { "onDialogueDoActions", "Dialogue::_doActions" },
        { "onDialogueEndDialogue", "Dialogue::endDialogue" },
        { "onDialogueEndPlayerConversation", "Dialogue::_endPlayerConversation" },
        { "onDialogueSay", "Dialogue::say" },
        { "onDialogueSendEvent", "Dialogue::sendEvent" },
        { "onDialogueStartConversation", "Dialogue::startConversation" },
        { "onDialogueStartPlayerConversation", "Dialogue::startPlayerConversation" },
        { "onDialogueStopEvent", "Dialogue::stopEvent" },
        { "onDialogueWindowShow", "DialogueWindow::show" },
        { "onDoorStuffCloseDoor", "DoorStuff::closeDoor" },
        { "onDoorStuffConstructed", "DoorStuff::_CONSTRUCTOR" },
        { "onDoorStuffHitByMeleeAttack", "DoorStuff::_NV_hitByMeleeAttack" },
        { "onDoorStuffLockDoor", "DoorStuff::lockDoor" },
        { "onDoorStuffOpenDoor", "DoorStuff::openDoor" },
        { "onDoorStuffSetDoorState", "DoorStuff::setDoorState" },
        { "onDoorStuffUnlockDoor", "DoorStuff::unlockDoor" },
        { "onFactionChooseRace", "Faction::chooseARace" },
        { "onFactionConstructed", "Faction::_CONSTRUCTOR" },
        { "onFactionEncountered", "PlayerInterface::encounterFaction" },
        { "onFactionGetBuildingReplacement", "Faction::getBuildingReplacement" },
        { "onFactionLeaderConstructed", "FactionLeader::_CONSTRUCTOR" },
        { "onFactionRelationsAffected", "FactionRelations::affectRelations" },
        { "onFactionRelationsConstructed", "FactionRelations::_CONSTRUCTOR" },
        { "onFactionUniqueSquadManagerConstructed", "FactionUniqueSquadManager::_CONSTRUCTOR" },
        { "onFarmBuildingConstructed", "FarmBuilding::_CONSTRUCTOR" },
        { "onFarmBuildingDestroyAPlant", "FarmBuilding::destroyAPlant" },
        { "onFarmBuildingEat", "FarmBuilding::eat" },
        { "onFarmBuildingOperate", "FarmBuilding::_NV_operate" },
        { "onFurnaceBuildingConstructed", "FurnaceBuilding::_CONSTRUCTOR" },
        { "onFurnaceBuildingOperate", "FurnaceBuilding::_NV_operate" },
        { "onGatewayBuildingConstructed", "GatewayBuilding::_CONSTRUCTOR" },
        { "onGearConstructed", "Gear::_CONSTRUCTOR" },
        { "onGeneratorBuildingConstructed", "GeneratorBuilding::_CONSTRUCTOR" },
        { "onGetFencingChance", "Character::getFencingSuccessChance" },
        { "onGetStat", "CharStats::getStat" },
        { "onInventoryAddItem", "Inventory::_NV_addItem" },
        { "onInventoryAddTradePartner", "InventoryGUI::addTradePartner" },
        { "onInventoryConstructed", "Inventory::_CONSTRUCTOR" },
        { "onInventoryDropItem", "Inventory::_NV_dropItem" },
        { "onInventoryGUIFencingConfirmation", "InventoryGUI::fencingConfirmationCallback" },
        { "onInventoryGetBestFoodItem", "Inventory::getBestFoodItem" },
        { "onInventoryGetSectionOfType", "Inventory::getSectionOfType" },
        { "onInventoryItemBaseConstructed", "InventoryItemBase::_CONSTRUCTOR" },
        { "onInventoryRemoveItem", "Inventory::_NV_removeItemDontDestroy_returnsItem" },
        { "onInventorySectionAddItem", "Inventory::_NV__sectionAddItemCallback" },
        { "onInventorySectionRemoveItem", "Inventory::_NV__sectionRemoveItemCallback" },
        { "onInventorySectionUpdateItem", "Inventory::_NV__sectionUpdateItemCallback" },
        { "onItemBought", "Inventory::buyItem" },
        { "onItemConstructed", "Item::_CONSTRUCTOR" },
        { "onItemGetValueSingle", "InventoryItemBase::getValueSingle" },
        { "onItemStolen", "Item::_NV_notifyTheftFrom" },
        { "onKeyDown", "InputHandler::keyDownEvent" },
        { "onLightBuildingConstructed", "LightBuilding::_CONSTRUCTOR" },
        { "onLimbAmputated", "MedicalSystem::amputate" },
        { "onLockedArmourConstructed", "LockedArmour::_CONSTRUCTOR" },
        { "onManagementScreenMessageAdded", "ManagementScreen::addMessage" },
        { "onMedicalSystemConstructed", "MedicalSystem::_CONSTRUCTOR" },
        { "onOrdersPanelBlockModeButton", "OrdersPanel::blockmodeButton" },
        { "onOrdersPanelChaseButton", "OrdersPanel::chaseButtonCallback" },
        { "onOrdersPanelHoldButton", "OrdersPanel::holdButtonCallback" },
        { "onOrdersPanelLiftButton", "OrdersPanel::liftButton" },
        { "onOrdersPanelMedicButton", "OrdersPanel::medicButton" },
        { "onOrdersPanelPassiveButton", "OrdersPanel::passiveButtonCallback" },
        { "onOrdersPanelProspectingButton", "OrdersPanel::prospectingButton" },
        { "onOrdersPanelTauntButton", "OrdersPanel::tauntButtonCallback" },
        { "onPlatoonConstructed", "Platoon::_CONSTRUCTOR" },
        { "onPlatoonDestroyed", "Faction::destroyPlatoon" },
        { "onPlatoonIBuyIllegalGoods", "Platoon::iBuyIllegalGoods" },
        { "onPlatoonIBuyStolenGoods", "Platoon::iBuyStolenGoods" },
        { "onPlatoonLoadFromSerialise", "Platoon::_NV_loadFromSerialise" },
        { "onPlatoonMemberAdded", "ActivePlatoon::_NV_addActiveObject" },
        { "onPlatoonMemberRemoved", "ActivePlatoon::_NV_removeObject" },
        { "onPlatoonTaskComplete", "Platoon::taskIsComplete" },
        { "onPlayerActivateCharacterEditMode", "PlayerInterface::activateCharacterEditMode" },
        { "onPlayerAddJobSelectedCharacters", "PlayerInterface::addJobSelectedCharacters" },
        { "onPlayerAddOrderSelectedCharacters", "PlayerInterface::addOrderSelectedCharacters" },
        { "onPlayerCreateSquad", "PlayerInterface::createSquad" },
        { "onPlayerLoadFromSerialise", "PlayerInterface::loadFromSerialise" },
        { "onPlayerOrderGiven", "PlayerInterface::newPlayerTaskSelectedCharacters" },
        { "onPlayerRecruit", "PlayerInterface::recruit" },
        { "onPlayerSelectObject", "PlayerInterface::selectObject" },
        { "onPlayerSerialise", "PlayerInterface::serialise" },
        { "onPlayerStealCheck", "Character::_NV_ImStealingDoYouNotice" },
        { "onPreviewBuildingConstructed", "PreviewBuilding::_CONSTRUCTOR" },
        { "onPreviewBuildingPlaceFinalPreviewBuilding", "PreviewBuilding::_NV_placeFinalPreviewBuilding" },
        { "onPreviewBuildingPlacePreview", "PreviewBuilding::_NV_placePreview" },
        { "onPreviewBuildingPlacementVerification", "PreviewBuilding::_NV_placementVerification" },
        { "onProductionBuildingConstructed", "ProductionBuilding::_CONSTRUCTOR" },
        { "onProductionBuildingOperate", "ProductionBuilding::_NV_operate" },
        { "onProsperityManagerConstructed", "ProsperityManager::_CONSTRUCTOR" },
        { "onRainCollectorBuildingConstructed", "RainCollectorBuilding::_CONSTRUCTOR" },
        { "onResearchBuildingConstructed", "ResearchBuilding::_CONSTRUCTOR" },
        { "onResearchBuildingOperate", "ResearchBuilding::_NV_operate" },
        { "onSlaveOwnerChanged", "Character::changeSlaveOwner" },
        { "onSmugglingTradeCheck", "Character::_NV_smugglingTradeCheck" },
        { "onSquadRemoved", "SquadManagementScreen::removeSquad" },
        { "onStorageBuildingConstructed", "StorageBuilding::_CONSTRUCTOR" },
        { "onSwordConstructed", "Sword::_CONSTRUCTOR" },
        { "onTitleScreenLoadGame", "TitleScreen::loadGame" },
        { "onTortureBuildingConstructed", "TortureBuilding::_CONSTRUCTOR" },
        { "onTownBaseConstructed", "TownBase::_CONSTRUCTOR" },
        { "onTownConstructed", "Town::_CONSTRUCTOR" },
        { "onTownLoadFromSerialise", "Town::_NV_loadFromSerialise" },
        { "onTurretBuildingAimAt", "TurretBuilding::aimAt" },
        { "onTurretBuildingConstructed", "TurretBuilding::_CONSTRUCTOR" },
        { "onTurretBuildingOperate", "TurretBuilding::_NV_operate" },
        { "onUseableStuffConstructed", "UseableStuff::_CONSTRUCTOR" },
        { "onUseableStuffCouldIOperate", "UseableStuff::_NV_couldIOperate" },
        { "onUseableStuffDontNeedWork", "UseableStuff::_NV_dontNeedWorkRightNow" },
        { "onUseableStuffGetCostToUse", "UseableStuff::_NV_getCostToUse" },
        { "onUseableStuffGivePower", "UseableStuff::_NV_givePower" },
        { "onUseableStuffHitByMeleeAttack", "UseableStuff::_NV_hitByMeleeAttack" },
        { "onUseableStuffOccupantChanged", "UseableStuff::occupantHandleChangedEvent" },
        { "onUseableStuffPowerSwitched", "UseableStuff::_NV_switchPowerOn" },
        { "onUseableStuffStopOperating", "UseableStuff::stopOperating" },
        { "onUseableStuffTakePowerFrom", "UseableStuff::takePowerFrom" },
        { "onUseableStuffToggleBattButton", "UseableStuff::_NV_toggleBattButton" },
        { "onUseableStuffTogglePowerButton", "UseableStuff::_NV_togglePowerButton" },
        { "onUseableStuffTryOperate", "UseableStuff::_NV_tryOperate" },
        { "onWallBuildingConstructed", "WallBuilding::_CONSTRUCTOR" },
        { "onWallBuildingHitByMeleeAttack", "WallBuilding::_NV_hitByMeleeAttack" },
        { "onWeaponConstructed", "Weapon::_CONSTRUCTOR" },
        { "onWindGeneratorBuildingConstructed", "WindGeneratorBuilding::_CONSTRUCTOR" },
        { "setHoldLocation", "CharStats::setHoldLocation" },
        { "xpEngineering", "CharStats::xpEngineering" },
        { "xpFirstAid", "CharStats::xpFirstAid" },
        { "xpLockpicking", "CharStats::xpLockpicking" },
        { "xpRunning", "CharStats::xpRunning" },
        { "xpStealth", "CharStats::xpStealth" },
        { "xpToughness_GetUpEvent", "CharStats::xpToughness_GetUpEvent" },
        { "xpToughness_PunchSomething", "CharStats::xpToughness_PunchSomething" },
        { "xpToughness_RagdollEvent", "CharStats::xpToughness_RagdollEvent" },
    };
        static const size_t g_legacyEventAliasesCount = sizeof(g_legacyEventAliases) / sizeof(g_legacyEventAliases[0]);

        struct LegacyAliasComparator
        {
            bool operator()(const LegacyEventAlias& a, const char* b) const
            {
                return strcmp(a.legacy, b) < 0;
            }
            bool operator()(const char* a, const LegacyEventAlias& b) const
            {
                return strcmp(a, b.legacy) < 0;
            }
        };

        const char* ResolveEventName(const char* rawEventName, const char* source)
        {
            if (!rawEventName || !rawEventName[0])
                return "";

            const LegacyEventAlias* first = g_legacyEventAliases;
            const LegacyEventAlias* last = g_legacyEventAliases + g_legacyEventAliasesCount;
            const LegacyEventAlias* it = std::lower_bound(first, last, rawEventName, LegacyAliasComparator());

            if (it != last && strcmp(it->legacy, rawEventName) == 0)
            {
                if (strcmp(it->legacy, it->canonical) != 0)
                {
                    std::string src = (source && source[0]) ? source : "unknown";
                    Logger::get().log(LogLevel_Warn, std::string("[EventSystem] Script '") + src +
                        "' registered legacy event '" + it->legacy + "'; please update to '" + it->canonical + "'.");
                }
                return it->canonical;
            }

            return rawEventName;
        }

        void Initialize(lua_State* L)
        {
            (void)L;
        }
    }
}
