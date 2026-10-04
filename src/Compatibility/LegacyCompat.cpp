#include "pch.h"
#include "Compatibility/LegacyCompat.h"
#include "Logger.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/LayoutManagerBinding.h"
#include <MyGUI.h>

#include <lua.hpp>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>

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

        namespace
        {
            // ========================================================================
            // Legacy enum aliases
            // ========================================================================

            struct LegacyEnumDefinition
            {
                const char* canonicalPath;
                const char* memberAliases;
                const char* legacyPaths;
            };

            // Generated from the enum surface immediately before commit 3adae25.
            // memberAliases uses "legacy=canonical;...". legacyPaths uses ";" separators.
            static const LegacyEnumDefinition s_legacyEnumDefinitions[] = {
                { "AppearanceManager.DataCategory", "", "AppearanceManager_DataCategory" },
                { "AppearanceManager.Gender", "", "AppearanceManager_Gender;Gender" },
                { "ArmourClass", "CLOTH=GEAR_CLOTH;HEAVY=GEAR_HEAVY;LIGHT=GEAR_LIGHT;MAX=GEAR_MAX;MEDIUM=GEAR_MEDIUM", "" },
                { "AttachSlot", "BACK=ATTACH_BACK;BACKPACK=ATTACH_BACKPACK;BEARD=ATTACH_BEARD;BELT=ATTACH_BELT;BODY=ATTACH_BODY;BOOTS=ATTACH_BOOTS;EYES=ATTACH_EYES;GLOVES=ATTACH_GLOVES;HAIR=ATTACH_HAIR;HAT=ATTACH_HAT;LEFT_ARM=ATTACH_LEFT_ARM;LEFT_LEG=ATTACH_LEFT_LEG;LEGS=ATTACH_LEGS;NECK=ATTACH_NECK;NONE=ATTACH_NONE;RIGHT_ARM=ATTACH_RIGHT_ARM;RIGHT_LEG=ATTACH_RIGHT_LEG;SHIRT=ATTACH_SHIRT;WEAPON=ATTACH_WEAPON", "" },
                { "BinaryVersion.KenshiPlatform", "", "BinaryVersion_KenshiPlatform;KenshiPlatform" },
                { "BuildingClassType", "CRAFTING=BCTYPE_CRAFTING;DOOR=BCTYPE_DOOR;FARM=BCTYPE_FARM;FLUFF=BCTYPE_FLUFF;GATEWAY=BCTYPE_GATEWAY;ITEM_FURNACE=BCTYPE_ITEM_FURNACE;LIGHT=BCTYPE_LIGHT;PRODUCTION=BCTYPE_PRODUCTION;RESEARCH=BCTYPE_RESEARCH;SHELL_WITH_INTERIOR=BCTYPE_SHELL_WITH_INTERIOR;STORAGE=BCTYPE_STORAGE;TURRET=BCTYPE_TURRET;USABLE=BCTYPE_USABLE;WALL=BCTYPE_WALL", "" },
                { "BuildingDesignation", "ARMOURY=BD_ARMOURY;BAR=BD_BAR;BARRACKS=BD_BARRACKS;HOSPITAL=BD_HOSPITAL;HQ=BD_HQ;NONE=BD_NONE;PRISON=BD_PRISON;RESIDENTIAL=BD_RESIDENTIAL;RESIDENTIAL_SMALL=BD_RESIDENTIAL_SMALL;SHOP=BD_SHOP;SLAVE_STORAGE=BD_SLAVE_STORAGE;TREASURE=BD_TREASURE", "" },
                { "BuildingFunction", "ANY=BF_ANY;BATTERY=BF_BATTERY;BED=BF_BED;CAGE=BF_CAGE;CHAIR=BF_CHAIR;CORPSE_DISPOSAL=BF_CORPSE_DISPOSAL;CRAFTING=BF_CRAFTING;DOOR=BF_DOOR;ENGINE=BF_ENGINE;FLUFF=BF_FLUFF;GATE=BF_GATE;GENERAL_STORAGE=BF_GENERAL_STORAGE;GENERATOR=BF_GENERATOR;ITEM_FURNACE=BF_ITEM_FURNACE;LIGHT=BF_LIGHT;LIQUID_TANK=BF_LIQUID_TANK;MINE=BF_MINE;MINE_NATURAL=BF_MINE_NATURAL;RAIN_COLLECTOR=BF_RAIN_COLLECTOR;REFINERY=BF_REFINERY;RESEARCH=BF_RESEARCH;RESOURCE_STORAGE=BF_RESOURCE_STORAGE;SHELL_WITH_INTERIOR=BF_SHELL_WITH_INTERIOR;SHOP=BF_SHOP;SKELETON_BED=BF_SKELETON_BED;STEERING=BF_STEERING;TABLE=BF_TABLE;THRONE=BF_THRONE;TRAINING=BF_TRAINING;TURRET=BF_TURRET;WALL=BF_WALL", "" },
                { "BuildingPlacementGroundType.Enum", "", "BuildingPlacementGroundType" },
                { "Character.CharMessage", "CAGE=CHARMESSAGE_CAGE;CARRY=CHARMESSAGE_CARRY;NONE=CHARMESSAGE_NONE", "CharMessage" },
                { "Character.DisguiseGUIFeedback", "I_HATE_YOU=DGF_I_HATE_YOU;MY_SLAVE=DGF_MY_SLAVE;SAME_FACTION=DGF_SAME_FACTION", "DisguiseGUIFeedback" },
                { "CharacterEditMode", "DEBUG=EDIT_DEBUG;MIDGAME=EDIT_MIDGAME;NEWGAME=EDIT_NEWGAME", "CharacterEditWindow_CharacterEditMode" },
                { "CharacterPerceptionTags_LongTerm", "DEFEATED_MY_SQUAD_ONCE=LT_DEFEATED_MY_SQUAD_ONCE;FREED_ME=LT_FREED_ME;FRIENDLY_AQUAINTANCE=LT_FRIENDLY_AQUAINTANCE;I_SCREWED_THIS_GUY=LT_I_SCREWED_THIS_GUY;KILLED_MY_FRIEND=LT_KILLED_MY_FRIEND;MAX=LT_MAX;MY_CAPTOR=LT_MY_CAPTOR;MY_INTRUDER=LT_MY_INTRUDER;MY_LIFESAVER=LT_MY_LIFESAVER;NONE=LT_NONE;SQUAD_LOST_TO_ME_ONCE=LT_SQUAD_LOST_TO_ME_ONCE;STOLE_FROM_ME=LT_STOLE_FROM_ME", "" },
                { "CharacterPerceptionTags_ShortTerm", "AGGRESSOR=ST_AGGRESSOR;CRIMINAL=ST_CRIMINAL;HAS_BEEN_LOOTED=ST_HAS_BEEN_LOOTED;INTRUDER=ST_INTRUDER;NONE=ST_NONE;PRISONER=ST_PRISONER;TEMPORARY_ALLY=ST_TEMPORARY_ALLY;TEMPORARY_ENEMY=ST_TEMPORARY_ENEMY", "" },
                { "CharacterStatsWindow.StatGroup", "", "StatGroup" },
                { "CharacterTypeEnum", "ADVENTURER=OT_ADVENTURER;BANDIT=OT_BANDIT;CIVILIAN=OT_CIVILIAN;DIPLOMAT=OT_DIPLOMAT;END=OT_END;LAW_ENFORCEMENT=OT_LAW_ENFORCEMENT;MILITARY=OT_MILITARY;NONE=OT_NONE;SLAVE=OT_SLAVE;SLAVER=OT_SLAVER;TRADER=OT_TRADER", "CharacterType" },
                { "CharStats.DeadTimeState", "", "CharStats_DeadTimeState;DeadTimeState" },
                { "CharStats.GUIStatsDisplayMode", "MARTIALARTIST=GUI_STATS_MARTIALARTIST;NORMAL=GUI_STATS_NORMAL", "CharStats_GUIStatsDisplayMode;GUIStatsDisplayMode" },
                { "ComparisonEnum", "EQUALS=CE_EQUALS;LESS_THAN=CE_LESS_THAN;MORE_THAN=CE_MORE_THAN", "Comparison" },
                { "CrimeEnum", "ASSAULT=CRIME_ASSAULT;ASSAULT_VIP=CRIME_ASSAULT_VIP;END=CRIME_END;ENSLAVING=CRIME_ENSLAVING;ESCAPE_PRISON=CRIME_ESCAPE_PRISON;FARM_EATING=CRIME_FARM_EATING;FENCING=CRIME_FENCING;KIDNAPPING=CRIME_KIDNAPPING;LOCKPICKING=CRIME_LOCKPICKING;LOOTING=CRIME_LOOTING;MURDER=CRIME_MURDER;NONE=CRIME_NONE;SLAVE_FREEING=CRIME_SLAVE_FREEING;SMUGGLING=CRIME_SMUGGLING;STEALING=CRIME_STEALING;TERRORISM=CRIME_TERRORISM;TRESSPASSING=CRIME_TRESSPASSING;UNIFORM_THEFT=CRIME_UNIFORM_THEFT", "Crime" },
                { "CropType", "ARID=CROP_ARID;GREEN=CROP_GREEN;NULL=CROP_NULL;SWAMP=CROP_SWAMP", "" },
                { "CursorType", "ATTACK=ATTACK_CURSOR;BUILD=BUILD_CURSOR;BUY_HOUSE=BUY_HOUSE_CURSOR;DEFAULT=DEFAULT_CURSOR;DOOR_ESCAPE=DOOR_ESCAPE_CURSOR;GREEN=GREEN_CURSOR;GUARD=GUARD_CURSOR;HAND=HAND_CURSOR;INVALID_MOVEMENT=INVALID_MOVEMENT_CURSOR;KNOCKOUT=KNOCKOUT_CURSOR;LIFT=LIFT_CURSOR;LIGHT=LIGHT_CURSOR;LOCKED=LOCKED_CURSOR;LOOT=LOOT_CURSOR;LOOT_RED=LOOT_CURSOR_RED;MEDIC=MEDIC_CURSOR;MINE=MINE_CURSOR;OPEN_DOOR=OPEN_DOOR_CURSOR;PICK_LOCK=PICK_LOCK_CURSOR;PICKUP_ITEM=PICKUP_ITEM_CURSOR;REPAIR=REPAIR_CURSOR;SPECIAL_TALK=SPECIAL_TALK_CURSOR;STEAL=STEAL_CURSOR;TALK=TALK_CURSOR;TRADER=TRADER_CURSOR;USE=USE_CURSOR", "" },
                { "CutDirection", "DEFAULT=CUT_DEFAULT;DOWNWARD=CUT_DOWNWARD;LEFT=CUT_LEFT;PIERCED=CUT_PIERCED;REAR_DOWNWARD=CUT_REAR_DOWNWARD;REAR_LEFT=CUT_REAR_LEFT;REAR_RIGHT=CUT_REAR_RIGHT;RIGHT=CUT_RIGHT;THRUST=CUT_THRUST;UPWARDS=CUT_UPWARDS", "" },
                { "DataObjectContainer.GroupType", "", "GroupType" },
                { "DataPanelLine.LineType", "BASE=DPL_BASE;BUTTON=DPL_BUTTON;CHECK=DPL_CHECK;CUSTOM=DPL_CUSTOM;DROPBOX=DPL_DROPBOX;EDIT=DPL_EDIT;FACTION=DPL_FACTION;MEDICAL=DPL_MEDICAL;PROGRESS=DPL_PROGRESS;RESEARCH=DPL_RESEARCH;SLIDER=DPL_SLIDER;TEXT=DPL_TEXT;TEXT_EDIT=DPL_TEXT_EDIT", "DataPanelsLineType" },
                { "DialogActionEnum", "AFFECT_RELATIONS=DA_AFFECT_RELATIONS;AFFECT_REPUTATION=DA_AFFECT_REPUTATION;ARREST_TARGET=DA_ARREST_TARGET;ARREST_TARGETS_CARRIED_PERSON=DA_ARREST_TARGETS_CARRIED_PERSON;ASSAULT_PHASE=DA_ASSAULT_PHASE;ASSIGN_BOUNTY=DA_ASSIGN_BOUNTY;ATTACK_CHASE_FOREVER=DA_ATTACK_CHASE_FOREVER;ATTACK_IF_NO_COEXIST=DA_ATTACK_IF_NO_COEXIST;ATTACK_STAY_NEAR_HOME=DA_ATTACK_STAY_NEAR_HOME;ATTACK_TOWN=DA_ATTACK_TOWN;CHARACTER_EDITOR=DA_CHARACTER_EDITOR;CLEAR_AI=DA_CLEAR_AI;CLEAR_BOUNTY=DA_CLEAR_BOUNTY;CRIME_ALARM=DA_CRIME_ALARM;DECLARE_WAR=DA_DECLARE_WAR;END=DA_END;END_WAR=DA_END_WAR;ENSLAVE_TARGETS_CARRIED_PERSON=DA_ENSLAVE_TARGETS_CARRIED_PERSON;FLAG_TEMP_ALLY=DA_FLAG_TEMP_ALLY;FLAG_TEMP_ENEMY=DA_FLAG_TEMP_ENEMY;FOLLOW_WHILE_TALKING=DA_FOLLOW_WHILE_TALKING;FORCE_SPEECH_TIMER=DA_FORCE_SPEECH_TIMER;FREE_TARGET_SLAVE=DA_FREE_TARGET_SLAVE;GIVE_MONEY=DA_GIVE_MONEY;GIVE_TARGET_MY_SLAVES=DA_GIVE_TARGET_MY_SLAVES;GO_HOME=DA_GO_HOME;INCREASE_FACTION_RANK=DA_INCREASE_FACTION_RANK;JOIN_SQUAD_FAST=DA_JOIN_SQUAD_FAST;JOIN_SQUAD_WITH_EDIT=DA_JOIN_SQUAD_WITH_EDIT;KNOCKOUT=DA_KNOCKOUT;LOCK_THIS_DIALOG=DA_LOCK_THIS_DIALOG;MAKE_TARGET_RUN_FASTER=DA_MAKE_TARGET_RUN_FASTER;MASSIVE_ALARM=DA_MASSIVE_ALARM;MATES_KILL_ME=DA_MATES_KILL_ME;MERGE_WITH_SIMILAR_SQUADS=DA_MERGE_WITH_SIMILAR_SQUADS;NONE=DA_NONE;OPEN_NEAREST_GATE=DA_OPEN_NEAREST_GATE;PAY_BOUNTY=DA_PAY_BOUNTY;PLAYER_SELL_PRISONERS=DA_PLAYER_SELL_PRISONERS;PLAYER_SURRENDER_MEMBER_DIFFERENT_RACE=DA_PLAYER_SURRENDER_MEMBER_DIFFERENT_RACE;REMEMBER_CHARACTER=DA_REMEMBER_CHARACTER;REMOVE_SLAVE_STATUS=DA_REMOVE_SLAVE_STATUS;RETREAT_PHASE=DA_RETREAT_PHASE;RUN_AWAY=DA_RUN_AWAY;SEPARATE_TO_MY_OWN_SQUAD=DA_SEPARATE_TO_MY_OWN_SQUAD;SUMMON_MY_SQUAD=DA_SUMMON_MY_SQUAD;TAG_ESCAPED_SLAVE=DA_TAG_ESCAPED_SLAVE;TAKE_MONEY=DA_TAKE_MONEY;TALK_TO_LEADER=DA_TALK_TO_LEADER;THUG_HUNTER=DA_THUG_HUNTER;TRADE=DA_TRADE;VICTORY_PHASE=DA_VICTORY_PHASE", "DialogueAction" },
                { "DialogConditionEnum", "BOUNTY_AMOUNT_ACTUAL=DC_BOUNTY_AMOUNT_ACTUAL;BOUNTY_AMOUNT_PERCEIVED=DC_BOUNTY_AMOUNT_PERCEIVED;BROKEN_ARM=DC_BROKEN_ARM;BROKEN_LEG=DC_BROKEN_LEG;BUILDING_IS_CLOSED_AND_SECURED=DC_BUILDING_IS_CLOSED_AND_SECURED;CAN_AFFORD_BOUNTY=DC_CAN_AFFORD_BOUNTY;CARRYING_BOUNTY_ALIVE=DC_CARRYING_BOUNTY_ALIVE;CARRYING_BOUNTY_DEAD=DC_CARRYING_BOUNTY_DEAD;CARRYING_SOMEONE_TO_ENSLAVE=DC_CARRYING_SOMEONE_TO_ENSLAVE;COPS_AROUND=DC_COPS_AROUND;DAMAGED_HEAD=DC_DAMAGED_HEAD;END=DC_END;FACTION_RANK=DC_FACTION_RANK;FACTION_VARIABLE=DC_FACTION_VARIABLE;HAS_A_BASE_NEARBY=DC_HAS_A_BASE_NEARBY;HAS_AI_CONTRACT=DC_HAS_AI_CONTRACT;HAS_ILLEGAL_ITEM=DC_HAS_ILLEGAL_ITEM;HAS_ROBOT_LIMBS=DC_HAS_ROBOT_LIMBS;HAS_TAG=DC_HAS_TAG;I_HATE_THIS_GUY=DC_I_HATE_THIS_GUY;I_LOVE_THIS_GUY=DC_I_LOVE_THIS_GUY;I_SHOULD_HELP_THIS_GUY=DC_I_SHOULD_HELP_THIS_GUY;I_SHOULD_SCREW_THIS_GUY_OVER=DC_I_SHOULD_SCREW_THIS_GUY_OVER;IM_UNARMED=DC_IM_UNARMED;IMPRISONED_BY_OTHER=DC_IMPRISONED_BY_OTHER;IMPRISONED_BY_TARGET=DC_IMPRISONED_BY_TARGET;IMPRISONMENT_IS_DEATHROW=DC_IMPRISONMENT_IS_DEATHROW;IN_A_NON_PLAYER_TOWN=DC_IN_A_NON_PLAYER_TOWN;IN_A_PLAYER_TOWN=DC_IN_A_PLAYER_TOWN;IN_COMBAT=DC_IN_COMBAT;IN_MY_BUILDING=DC_IN_MY_BUILDING;IS_A_TRADER=DC_IS_A_TRADER;IS_ALLY=DC_IS_ALLY;IS_DEAD=DC_IS_DEAD;IS_ENEMY=DC_IS_ENEMY;IS_ESCAPED_SLAVE=DC_IS_ESCAPED_SLAVE;IS_FEMALE=DC_IS_FEMALE;IS_IMPRISONED=DC_IS_IMPRISONED;IS_IN_LOCKED_CAGE=DC_IS_IN_LOCKED_CAGE;IS_INDOORS=DC_IS_INDOORS;IS_KO=DC_IS_KO;IS_LEADER=DC_IS_LEADER;IS_NEARLY_KO=DC_IS_NEARLY_KO;IS_OUTNUMBERED=DC_IS_OUTNUMBERED;IS_PLAYER=DC_IS_PLAYER;IS_RECRUITABLE=DC_IS_RECRUITABLE;IS_RUNNING=DC_IS_RUNNING;IS_SAME_RACE_AS_ME=DC_IS_SAME_RACE_AS_ME;IS_SLAVE=DC_IS_SLAVE;IS_SNEAKING=DC_IS_SNEAKING;MET_TARGET_BEFORE=DC_MET_TARGET_BEFORE;MIXED_GENDER_GROUP=DC_MIXED_GENDER_GROUP;MY_MISSION_IS_FRIENDLY=DC_MY_MISSION_IS_FRIENDLY;NEARLY_KO=DC_NEARLY_KO;NONE=DC_NONE;NUM_BACKPACKS=DC_NUM_BACKPACKS;NUM_DIALOG_EVENT_REPEATS=DC_NUM_DIALOG_EVENT_REPEATS;PERSONALITY_TAG=DC_PERSONALITY_TAG;PLAYER_TECH_LEVEL=DC_PLAYER_TECH_LEVEL;PLAYERMONEY=DC_PLAYERMONEY;PLAYERS_BEST_TOWN_LEVEL=DC_PLAYERS_BEST_TOWN_LEVEL;RELATIONS=DC_RELATIONS;REPUTATION=DC_REPUTATION;SQUAD_IS_DOWN=DC_SQUAD_IS_DOWN;SQUAD_ONLY_ANIMALS=DC_SQUAD_ONLY_ANIMALS;SQUAD_SIZE=DC_SQUAD_SIZE;STARVING=DC_STARVING;STRONGER_THAN_ME=DC_STRONGER_THAN_ME;TARGET_CHARACTER_EXISTS=DC_TARGET_CHARACTER_EXISTS;TARGET_IN_TALKING_RANGE=DC_TARGET_IN_TALKING_RANGE;TARGET_IS_MY_MISSION_TARGET=DC_TARGET_IS_MY_MISSION_TARGET;TARGET_IS_SLAVE_OF_MY_FACTION=DC_TARGET_IS_SLAVE_OF_MY_FACTION;TARGET_LAST_SEEN_X_HOURS_AGO=DC_TARGET_LAST_SEEN_X_HOURS_AGO;TOWN_HAS_FORTIFICATIONS_WALLS=DC_TOWN_HAS_FORTIFICATIONS_WALLS;TOWN_LEVEL_CURRENT_LOCATION=DC_TOWN_LEVEL_CURRENT_LOCATION;TOWN_WALLS_LOCKED_UP=DC_TOWN_WALLS_LOCKED_UP;USING_MY_TRAINING_EQUIPMENT=DC_USING_MY_TRAINING_EQUIPMENT;WEAKER_THAN_ME=DC_WEAKER_THAN_ME;WEARING_LOCKED_SHACKLES=DC_WEARING_LOCKED_SHACKLES;WITHIN_TOWN_WALLS=DC_WITHIN_TOWN_WALLS", "DialogCondition" },
                { "Dialogue.DT_MSG", "CLEAR_RESPONSES=DT_CLEAR_RESPONSES;CLOSEWINDOW=DT_CLOSEWINDOW;END_DIALOG=DT_END_DIALOG;NONE=DT_NONE;OPENWINDOW=DT_OPENWINDOW;SET_NPC_REPLY=DT_SET_NPC_REPLY;SET_RESPONSES=DT_SET_RESPONSES", "Dialogue_DT_MSG;DT_MSG" },
                { "DoorState", "CLOSED=DOORSTATE_CLOSED;CLOSING=DOORSTATE_CLOSING;OPEN=DOORSTATE_OPEN;OPENING=DOORSTATE_OPENING", "" },
                { "DoorStuff.DoorStateInitial", "", "DoorStateInitial" },
                { "EventTriggerEnum", "______=EV_______;ACID_FEET=EV_ACID_FEET;ACID_RAIN=EV_ACID_RAIN;ACID_WATER=EV_ACID_WATER;ALMOST_WOKE_UP=EV_ALMOST_WOKE_UP;ANNOUNCEMENT=EV_ANNOUNCEMENT;ASSASSINATION_FAILED=EV_ASSASSINATION_FAILED;BAR_TALK=EV_BAR_TALK;BEING_HEALED_FINISHED=EV_BEING_HEALED_FINISHED;BEING_HEALED_START=EV_BEING_HEALED_START;BETRAYAL=EV_BETRAYAL;BOUGHT_ME_FROM_SLAVERY=EV_BOUGHT_ME_FROM_SLAVERY;BOUNTY_SPOTTED=EV_BOUNTY_SPOTTED;BURNING=EV_BURNING;CONTRACT_JOB_ENDED=EV_CONTRACT_JOB_ENDED;CROWD_TRIGGERED=EV_CROWD_TRIGGERED;EATING_MY_CROPS=EV_EATING_MY_CROPS;EATING_SOMETHING_SOUNDS=EV_EATING_SOMETHING_SOUNDS;ENTER_BIOME=EV_ENTER_BIOME;ENTER_TOWN=EV_ENTER_TOWN;ESCAPED_EX_SLAVE_SPOTTED=EV_ESCAPED_EX_SLAVE_SPOTTED;ESCAPED_PRISONER_SPOTTED=EV_ESCAPED_PRISONER_SPOTTED;ESCAPING_SLAVE_SPOTTED=EV_ESCAPING_SLAVE_SPOTTED;FIRSTAID_KIT_EMPTY=EV_FIRSTAID_KIT_EMPTY;GET_UP_FIGHT=EV_GET_UP_FIGHT;GET_UP_PEACE=EV_GET_UP_PEACE;GET_UP_UNNECCESSARY_FIGHT=EV_GET_UP_UNNECCESSARY_FIGHT;GIVE_UP_CHASE=EV_GIVE_UP_CHASE;HARRASSMENT_SHOUTS=EV_HARRASSMENT_SHOUTS;HEALING_OTHER_FINISHED=EV_HEALING_OTHER_FINISHED;HEALING_OTHER_START=EV_HEALING_OTHER_START;I_________=EV_I_________;I_DEFEATED_SQUAD=EV_I_DEFEATED_SQUAD;I_SEE_ALLY_PLAYER=EV_I_SEE_ALLY_PLAYER;I_SEE_ANIMAL_SQUAD=EV_I_SEE_ANIMAL_SQUAD;I_SEE_ENEMY_PLAYER=EV_I_SEE_ENEMY_PLAYER;I_SEE_ILLEGAL_PLAYER_BUILDING=EV_I_SEE_ILLEGAL_PLAYER_BUILDING;I_SEE_NEUTRAL_SQUAD=EV_I_SEE_NEUTRAL_SQUAD;I_SEE_PLAYER_NICE_BUILDING=EV_I_SEE_PLAYER_NICE_BUILDING;I_SEE_RAGDOLL=EV_I_SEE_RAGDOLL;I_SEE_UNIFORM_IMPOSTER=EV_I_SEE_UNIFORM_IMPOSTER;INTRODUCING_NEW_SLAVE=EV_INTRODUCING_NEW_SLAVE;INTRUDER_FOUND=EV_INTRUDER_FOUND;KIDNAPPING_MY_ALLY=EV_KIDNAPPING_MY_ALLY;LAUNCH_ATTACK=EV_LAUNCH_ATTACK;LOOTING_EVERYTHING=EV_LOOTING_EVERYTHING;LOOTING_WEAPON_ONLY=EV_LOOTING_WEAPON_ONLY;LOST_ARM=EV_LOST_ARM;LOST_LEG=EV_LOST_LEG;MARKED_FOR_DEATH=EV_MARKED_FOR_DEATH;MAX=EV_MAX;NONE=EV_NONE;PLAYER_TALK_TO_ME=EV_PLAYER_TALK_TO_ME;POISON_GAS=EV_POISON_GAS;PRISONER_FREE_TO_GO=EV_PRISONER_FREE_TO_GO;RECAPTURED_A_SLAVE=EV_RECAPTURED_A_SLAVE;SCREAMING_TORTURE=EV_SCREAMING_TORTURE;SHOO_FROM_MY_BUILDING=EV_SHOO_FROM_MY_BUILDING;SHOUT_AT_SLAVE_WORKER=EV_SHOUT_AT_SLAVE_WORKER;SLAVE_DELIVERY=EV_SLAVE_DELIVERY;SLAVE_ESCAPE_OPPORTUNITY_ALONE=EV_SLAVE_ESCAPE_OPPORTUNITY_ALONE;SLAVE_ESCAPE_OPPORTUNITY_SAVIOR=EV_SLAVE_ESCAPE_OPPORTUNITY_SAVIOR;SPEECH_INTERRUPTED_ATTACKED_BY_STRANGERS=EV_SPEECH_INTERRUPTED_ATTACKED_BY_STRANGERS;SPEECH_INTERRUPTED_ATTACKED_BY_TARGET=EV_SPEECH_INTERRUPTED_ATTACKED_BY_TARGET;SQUAD_BROKEN=EV_SQUAD_BROKEN;TAKEN_OVER_PLAYER_TOWN=EV_TAKEN_OVER_PLAYER_TOWN;UNLOCK_MY_CAGE_ATTEMPT=EV_UNLOCK_MY_CAGE_ATTEMPT;UNLOCK_MY_CAGE_OR_SHACKLES=EV_UNLOCK_MY_CAGE_OR_SHACKLES;USING_MY_TRAINING_EQUIPMENT=EV_USING_MY_TRAINING_EQUIPMENT;WINDY=EV_WINDY;WITNESS_GENERIC_ASSAULT=EV_WITNESS_GENERIC_ASSAULT;WITNESS_LOOTING_ALLY=EV_WITNESS_LOOTING_ALLY;WITNESS_THIEF_OR_LOCKPICK=EV_WITNESS_THIEF_OR_LOCKPICK;WORSHIPING_SOMETHING=EV_WORSHIPING_SOMETHING", "EventTrigger" },
                { "FactionRelations.FactionEvent", "", "FactionEvent" },
                { "GameData.DataType", "", "GameDataDataType" },
                { "GameWorld.SysMessageEnum", "", "SysMessageEnum" },
                { "GroundType", "CONCRETE=GROUND_CONCRETE;DIRT=GROUND_DIRT;GRASS=GROUND_GRASS;METAL=GROUND_METAL;MUD=GROUND_MUD;SAND=GROUND_SAND;SNOW=GROUND_SNOW;WATER=GROUND_WATER;WOOD=GROUND_WOOD", "" },
                { "HavokCharacter.CharacterState", "", "HavokCharacterState" },
                { "HavokCharacter.PathState", "", "HavokPathState" },
                { "HitMaterialType", "CHAIN=HIT_CHAIN;FLESH=HIT_FLESH;METAL=HIT_METAL;MISSED=HIT_MISSED;SAND=HIT_SAND;SWORD=HIT_SWORD;WOOD=HIT_WOOD", "" },
                { "InputHandler.GameMode", "", "GlobalMode;InputHandlerGameMode" },
                { "InputHandler.Masks", "ALL=ALL_MASK;ALT=ALT_MASK;CTRL=CTRL_MASK;NONE=NONE_MASK;SHIFT=SHIFT_MASK", "Masks" },
                { "InventoryGUI.TradeResult", "", "InventoryGUITradeResult;TradeResult" },
                { "ItemFunction", "___=ITEM____;AMMO=ITEM_AMMO;ANYTHING=ITEM_ANYTHING;BLUEPRINT=ITEM_BLUEPRINT;BOOK=ITEM_BOOK;CLOTHING=ITEM_CLOTHING;CONTAINER=ITEM_CONTAINER;FIRSTAID=ITEM_FIRSTAID;FOOD=ITEM_FOOD;FOOD_RESTRICTED=ITEM_FOOD_RESTRICTED;MEDRIGGING=ITEM_MEDRIGGING;MONEY=ITEM_MONEY;NARCOTIC=ITEM_NARCOTIC;NO_FUNCTION=ITEM_NO_FUNCTION;ROBOTREPAIR=ITEM_ROBOTREPAIR;SEVERED_LIMB=ITEM_SEVERED_LIMB;TOOL=ITEM_TOOL;WEAPON=ITEM_WEAPON", "" },
                { "itemType", "___XXX___=____XXX___", "" },
                { "LeftRight", "BOTH=SIDE_BOTH;LEFT=SIDE_LEFT;NEITHER=SIDE_NEITHER;RIGHT=SIDE_RIGHT", "" },
                { "LimbState", "CRUSHED=LIMB_CRUSHED;ORIGINAL=LIMB_ORIGINAL;REPLACED=LIMB_REPLACED;STUMP=LIMB_STUMP", "" },
                { "Logger.Severity", "DEBUG=Debug;ERROR=Error;FATAL=Fatal;INFO=Info;LOG_ERROR=Error;LOG_INFO=Info;LOG_WARNING=Warning;TRACE=Trace;WARNING=Warning", "LoggerSeverity" },
                { "MapZoomLevel", "CHARACTERS=ZOOM_CHARACTERS;MAX=ZOOM_MAX;MID=ZOOM_MID;MIN=ZOOM_MIN", "" },
                { "MedicalSystem.CollapseStage", "BUT_NO_RAGDOLL=COLLAPSE_BUT_NO_RAGDOLL;KO=COLLAPSE_KO;NONE=COLLAPSE_NONE", "CollapseStage" },
                { "MedicalSystem.HealthPartStatus", "ARM=PART_ARM;HEAD=PART_HEAD;LEG=PART_LEG;TORSO=PART_TORSO", "HealthPartStatus" },
                { "MeshDataLookup.Dir", "", "MeshDataLookup" },
                { "MessageForB.MessageType", "GIVE_TASK=M_GIVE_TASK;UNSELECT_ALL=M_UNSELECT_ALL", "MessageType" },
                { "MessageForB.StandingOrder", "AGG=M_SET_ORDER_AGG;CHASE=M_SET_ORDER_CHASE;DEF=M_SET_ORDER_DEF;DEFENSIVE_COMBAT=M_SET_ORDER_DEFENSIVE_COMBAT;EVADE=M_SET_ORDER_EVADE;FAR=M_SET_ORDER_FAR;GROUP_SPEED=M_SET_ORDER_GROUP_SPEED;HOLD=M_SET_ORDER_HOLD;JOG=M_SET_ORDER_JOG;NEAR=M_SET_ORDER_NEAR;PASSIVE=M_SET_ORDER_PASSIVE;RANGED=M_SET_ORDER_RANGED;RUN=M_SET_ORDER_RUN;STEALTH_OFF=M_SET_ORDER_STEALTH_OFF;STEALTH_ON=M_SET_ORDER_STEALTH_ON;TAUNT=M_SET_ORDER_TAUNT;TOGGLEORDERS__AFTER__THIS=M__TOGGLEORDERS__AFTER__THIS_;WALK=M_SET_ORDER_WALK", "MessageB_StandingOrder" },
                { "MessageLogColor", "NORMAL=ML_NORMAL;PLAYER=ML_PLAYER;SYSTEM=ML_SYSTEM", "" },
                { "MovementMode", "COMBAT=MOVE_COMBAT;DIRECTION=MOVE_DIRECTION;NORMAL=MOVE_NORMAL", "" },
                { "NavMesh.FileMode", "", "NavMeshFileMode" },
                { "NavMesh.State", "", "NavMeshState" },
                { "NxControllerAction", "NONE=NX_ACTION_NONE;PUSH=NX_ACTION_PUSH", "" },
                { "NxShapesType", "ALL_SHAPES=NX_ALL_SHAPES;DYNAMIC_SHAPES=NX_DYNAMIC_SHAPES;STATIC_SHAPES=NX_STATIC_SHAPES", "" },
                { "PlatoonCreationMessage", "DECIMATE=CM_DECIMATE;DELETE=CM_DELETE;EMPTY=CM_EMPTY;NO_MESSAGE=CM_NO_MESSAGE;REFRESH=CM_REFRESH", "" },
                { "PortraitData.State", "", "PortraitState" },
                { "PreviewBuilding.PlacementResult", "INVALID=PLACEMENT_INVALID;OUTSIDE=PLACEMENT_OUTSIDE;VALID=PLACEMENT_VALID", "PreviewBuildingPlacementResult" },
                { "PreviewBuilding.PreviewBuildingClassType", "NORMAL=PREVIEW_NORMAL;WALL=PREVIEW_WALL", "PreviewBuildingClassType" },
                { "ProductionBuilding.ProductionState", "FULL=PRODUCTION_FULL;IMPOSSIBLE=PRODUCTION_IMPOSSIBLE;NORMAL=PRODUCTION_NORMAL;STARVED=PRODUCTION_STARVED", "ProductionState" },
                { "ProneState", "CRIPPLED=PS_CRIPPLED;KO=PS_KO;NORMAL=PS_NORMAL;PLAYING_DEAD=PS_PLAYING_DEAD;STAYING_LOW=PS_STAYING_LOW", "" },
                { "RobotLimbs.Limb", "", "RobotLimbs" },
                { "SaveFileSystem.MessageType", "", "SaveFileSystemMessageType" },
                { "SaveFileSystem.State", "", "SaveFileSystemState" },
                { "SaveManager.Flags", "", "SaveManagerFlags" },
                { "SaveManager.Signal", "", "SaveManagerSignals" },
                { "ScreenLabel.LabelSize", "LARGE=LS_LARGE;MEDIUM=LS_MEDIUM;SMALL=LS_SMALL", "LabelSize" },
                { "ScreenLabel.RisingSpeed", "FAST=RS_FAST;NORMAL=RS_NORMAL;SLOW=RS_SLOW;STOPPED=RS_STOPPED", "RisingSpeed" },
                { "SenseType", "ALLY=SENSE_ALLY;AUTHORITY_FIGURE=SENSE_AUTHORITY_FIGURE;CANT_SEE=SENSE_CANT_SEE;CARRIED=SENSE_CARRIED;CRAWLING=SENSE_CRAWLING;DEAD=SENSE_DEAD;ENEMY=SENSE_ENEMY;ENEMY_OF_MY_SLAVEMASTER=SENSE_ENEMY_OF_MY_SLAVEMASTER;ESCAPED_SLAVE=SENSE_ESCAPED_SLAVE;IN_CAGE=SENSE_IN_CAGE;KO=SENSE_KO;NEUTRAL=SENSE_NEUTRAL;PLAYER=SENSE_PLAYER;ROBOTS=SENSE_ROBOTS;SAME_FACTION=SENSE_SAME_FACTION;SLAVE=SENSE_SLAVE", "" },
                { "SlaveStateEnum", "", "SlaveState" },
                { "SoundRange", "ALWAYS=SOUNDRANGE_ALWAYS;LONG=SOUNDRANGE_LONG;SHORT=SOUNDRANGE_SHORT", "" },
                { "SquadMemberType", "1=SQUAD_1;2=SQUAD_2;LEADER=SQUAD_LEADER;SIGNALS_PLAN=SQUAD_SIGNALS_PLAN;SLAVE=SQUAD_SLAVE", "" },
                { "SquadType", "RESIDENT=SQ_RESIDENT;ROAMING=SQ_ROAMING;UNKNOWN=SQ_UNKNOWN", "" },
                { "StatsEnumerated", "ASSASSINATION=STAT_ASSASSINATION;ATHLETICS=STAT_ATHLETICS;AthleticsXPBonus=_AthleticsXPBonus;AttackSpeedHeavyWeapons=_AttackSpeedHeavyWeapons;BLUNT=STAT_BLUNT;BuildingRate=_BuildingRate;CombatSpeed=_combatSpeed;COOKING=STAT_COOKING;CROSSBOWS=STAT_CROSSBOWS;CurrentRunSpeed=_CurrentRunSpeed;DamageResistance=_DamageResistance;DEXTERITY=STAT_DEXTERITY;DODGE=STAT_DODGE;Encumbrance=_encumbrance;END=STAT_END;ENGINEERING=STAT_ENGINEERING;FARMING=STAT_FARMING;Farming=_Farming;FRIENDLY_FIRE=STAT_FRIENDLY_FIRE;HACKERS=STAT_HACKERS;HEAVYWEAPONS=STAT_HEAVYWEAPONS;HIVEMEDIC=STAT_HIVEMEDIC;KATANAS=STAT_KATANAS;KnockoutTime=_KnockoutTime;LABOURING=STAT_LABOURING;LOCKPICKING=STAT_LOCKPICKING;MARTIALARTS=STAT_MARTIALARTS;MASSCOMBAT=STAT_MASSCOMBAT;MaxCarryWeight=_MaxCarryWeight;MaxRunSpeed=_MaxRunSpeed;MEDIC=STAT_MEDIC;MELEE_ATTACK=STAT_MELEE_ATTACK;MELEE_DEFENCE=STAT_MELEE_DEFENCE;Mining=_Mining;NONE=STAT_NONE;PERCEPTION=STAT_PERCEPTION;POLEARMS=STAT_POLEARMS;PrimaryWeaponDamage=_PrimaryWeaponDamage;PrimaryWeaponSpeed=_PrimaryWeaponSpeed;RepairingRate=_RepairingRate;ROBOTICS=STAT_ROBOTICS;SABRES=STAT_SABRES;SCIENCE=STAT_SCIENCE;SecondaryWeaponDamage=_SecondaryWeaponDamage;SecondaryWeaponSpeed=_SecondaryWeaponSpeed;SMITHING_ARMOUR=STAT_SMITHING_ARMOUR;SMITHING_BOW=STAT_SMITHING_BOW;SMITHING_WEAPON=STAT_SMITHING_WEAPON;STEALTH=STAT_STEALTH;STRENGTH=STAT_STRENGTH;StrengthXPRateCombat=_StrengthXPRateCombat;StrengthXPRateWalk=_StrengthXPRateWalk;SURVIVAL=STAT_SURVIVAL;SWIMMING=STAT_SWIMMING;THIEVING=STAT_THIEVING;TOUGHNESS=STAT_TOUGHNESS;ToughnessKnockoutPoint=_ToughnessKnockoutPoint;ToughnessXPRate=_ToughnessXPRate;TurretAccuracy=_TurretAccuracy;TurretFriendlyFireAvoidance=_TurretFriendlyFireAvoidance;TurretRateOfFire=_TurretRateOfFire;TURRETS=STAT_TURRETS;UsingMachinery=_UsingMachinery;VET=STAT_VET;WEAPONS=STAT_WEAPONS;WoundDeteriorationSpeed=_WoundDeteriorationSpeed", "Stats" },
                { "swordStateEnum", "", "SwordState" },
                { "TalkerEnum", "INTERJECTOR1=T_INTERJECTOR1;INTERJECTOR2=T_INTERJECTOR2;INTERJECTOR3=T_INTERJECTOR3;ME=T_ME;TARGET=T_TARGET;TARGET_IF_PLAYER=T_TARGET_IF_PLAYER;TARGET_WITH_RACE=T_TARGET_WITH_RACE;WHOLE_SQUAD=T_WHOLE_SQUAD", "Talker" },
                { "taskPriority", "FLUFF=TP_FLUFF;JUST_ACTION=TP_JUST_ACTION;MAX_SIZE=TP_MAX_SIZE;NON_URGENT=TP_NON_URGENT;OBEDIENCE=TP_OBEDIENCE;URGENT=TP_URGENT", "" },
                { "TaskType", "LOCK=CUT_LOCK;SHACKLES=CUT_SHACKLES;SLAVE_OBEDIENCE=_SLAVE_OBEDIENCE", "" },
                { "ToolTip.Type", "", "ToolTipType" },
                { "TownAlarmState", "ATTACK=ALARM_ATTACK;ESCAPE=ALARM_ESCAPE;INTRUDER=ALARM_INTRUDER;NONE=ALARM_NONE", "" },
                { "TownType", "MILITARY=TOWN_MILITARY;NEST=TOWN_NEST;NEST_MARKER=TOWN_NEST_MARKER;NULL=TOWN_NULL;OUTPOST=TOWN_OUTPOST;POI=TOWN_POI;PRISON=TOWN_PRISON;RUINS=TOWN_RUINS;SLAVE_CAMP=TOWN_SLAVE_CAMP;TOWN=TOWN_TOWN;VILLAGE=TOWN_VILLAGE", "" },
                { "TradeWindowType", "AUTO=TW_AUTO;LOOTING=TW_LOOTING;MONEY_TRADING=TW_MONEY_TRADING;OFF=TW_OFF", "" },
                { "TutorialGUI.HighlightItem", "", "HighlightItem" },
                { "TutorialItem.State", "", "TutorialItemState" },
                { "UnloadedPlatoonJob", "GOHOME=UPJOB_GOHOME;NONE=UPJOB_NONE;PATROL_LONGRANGE=UPJOB_PATROL_LONGRANGE;PATROL_SHORTRANGE=UPJOB_PATROL_SHORTRANGE;PATROL_TOWN=UPJOB_PATROL_TOWN;TRAVEL_TARGET=UPJOB_TRAVEL_TARGET;TRAVEL_TARGET_FAST=UPJOB_TRAVEL_TARGET_FAST", "" },
                { "UpdatePriority", "HIGH=HIGH_PRIORITY;LOW=LOW_PRIORITY;MED=MED_PRIORITY", "" },
                { "WallSectionLinkType", "CONNECTOR=WALLTYPE_CONNECTOR;LOWER_WEDGE=WALLTYPE_LOWER_WEDGE;NORMAL=WALLTYPE_NORMAL;SHORT=WALLTYPE_SHORT;SINGLE=WALLTYPE_SINGLE", "" },
                { "WaterState", "DEEP=DEEP_WATER;NONE=NO_WATER;THIGH_DEEP=THIGH_DEEP_WATER;VERY_SHALLOW=VERY_SHALLOW_WATER", "" },
                { "WeaponCategory", "BLUNT=SKILL_BLUNT;BOW=SKILL_BOW;BULL=ATTACK_BULL;CAGEBEAST=ATTACK_CAGEBEAST;DOG=ATTACK_DOG;DUCK=ATTACK_DUCK;ELEPHANT=ATTACK_ELEPHANT;FROG=ATTACK_FROG;GAR=ATTACK_GAR;GIRAFFE=ATTACK_GIRAFFE;GOAT=ATTACK_GOAT;GORILLA=ATTACK_GORILLA;HACKERS=SKILL_HACKERS;HEAVY=SKILL_HEAVY;KATANAS=SKILL_KATANAS;NULL=ATTACK_NULL;POLEARMS=ATTACK_POLEARMS;ROBOTSPIDER=ATTACK_ROBOTSPIDER;SABRES=SKILL_SABRES;SPIDER=ATTACK_SPIDER;TURRET=SKILL_TURRET;UNARMED=SKILL_UNARMED", "" },
                { "WeatherAffecting", "ACID=WA_ACID;BURNING=WA_BURNING;DUSTSTORM=WA_DUSTSTORM;GAS=WA_GAS;NONE=WA_NONE;RAIN=WA_RAIN", "" },
                { "WorldEventStateQuery.WarStateEnum", "", "WarStateEnum" },
                { "ZoneActivationType", "CAMERA=ACTIVATION_CAMERA;PLAYER_CHARACTER=ACTIVATION_PLAYER_CHARACTER;TOWN=ACTIVATION_TOWN", "" },
                { "ZoneMap.ZONE_MESSAGE", "", "ZoneMessage" },
                { "ZoneSpacialGrid.Result", "", "ZoneManagerResult" },
                { 0, 0, 0 }
            };

            static int absoluteIndex(lua_State* L, int index)
            {
                if (index > 0 || index <= LUA_REGISTRYINDEX)
                    return index;
                return lua_gettop(L) + index + 1;
            }

            static bool pushTablePath(lua_State* L, const char* path)
            {
                if (!path || !path[0])
                {
                    lua_pushnil(L);
                    return false;
                }

                const char* segment = path;
                const char* separator = strchr(segment, '.');
                std::string name(segment, separator ? separator - segment : strlen(segment));
                lua_getglobal(L, name.c_str());

                while (separator && lua_istable(L, -1))
                {
                    segment = separator + 1;
                    separator = strchr(segment, '.');
                    name.assign(segment, separator ? separator - segment : strlen(segment));
                    lua_getfield(L, -1, name.c_str());
                    lua_remove(L, -2);
                }

                return lua_istable(L, -1) != 0;
            }

            static void pushLegacyAliasMap(lua_State* L, const char* aliases)
            {
                lua_newtable(L);
                if (!aliases || !aliases[0])
                    return;

                const char* entry = aliases;
                while (*entry)
                {
                    const char* equals = strchr(entry, '=');
                    if (!equals)
                        break;

                    const char* end = strchr(equals + 1, ';');
                    if (!end)
                        end = aliases + strlen(aliases);

                    lua_pushlstring(L, entry, equals - entry);
                    lua_pushlstring(L, equals + 1, end - equals - 1);
                    lua_rawset(L, -3);

                    entry = *end ? end + 1 : end;
                }
            }

            static std::string getLegacyEnumSource(lua_State* L)
            {
                lua_Debug debugInfo;
                if (lua_getstack(L, 1, &debugInfo) && lua_getinfo(L, "S", &debugInfo))
                {
                    if (debugInfo.short_src[0])
                        return debugInfo.short_src;
                    if (debugInfo.source && debugInfo.source[0])
                        return debugInfo.source;
                }
                return "unknown";
            }

            static void warnLegacyEnumLookup(lua_State* L, const std::string& legacySyntax,
                const std::string& canonicalSyntax)
            {
                static const char* const warningRegistryKey = "KenshiLua.LegacyEnumWarnings";
                const std::string source = getLegacyEnumSource(L);
                const std::string warningKey = source + "\n" + legacySyntax;

                lua_getfield(L, LUA_REGISTRYINDEX, warningRegistryKey);
                if (!lua_istable(L, -1))
                {
                    lua_pop(L, 1);
                    lua_newtable(L);
                    lua_pushvalue(L, -1);
                    lua_setfield(L, LUA_REGISTRYINDEX, warningRegistryKey);
                }

                lua_getfield(L, -1, warningKey.c_str());
                const bool alreadyWarned = lua_toboolean(L, -1) != 0;
                lua_pop(L, 1);

                if (!alreadyWarned)
                {
                    lua_pushboolean(L, 1);
                    lua_setfield(L, -2, warningKey.c_str());

                    Logger::get().log(LogLevel_Warn, std::string("[EnumBinding] Script '") +
                        source + "' used legacy enum '" + legacySyntax +
                        "'; please update to '" + canonicalSyntax + "'.");
                }

                lua_pop(L, 1);
            }

            static int callPreviousIndex(lua_State* L)
            {
                const int previousType = lua_type(L, lua_upvalueindex(6));
                if (previousType == LUA_TFUNCTION)
                {
                    lua_pushvalue(L, lua_upvalueindex(6));
                    lua_pushvalue(L, 1);
                    lua_pushvalue(L, 2);
                    lua_call(L, 2, 1);
                    return 1;
                }
                if (previousType == LUA_TTABLE)
                {
                    lua_pushvalue(L, 2);
                    lua_gettable(L, lua_upvalueindex(6));
                    return 1;
                }

                lua_pushnil(L);
                return 1;
            }

            static int lua_compat_legacyEnumIndex(lua_State* L)
            {
                if (lua_type(L, 2) != LUA_TSTRING)
                    return callPreviousIndex(L);

                const char* legacyMember = lua_tostring(L, 2);
                const char* canonicalMember = 0;

                lua_pushvalue(L, 2);
                lua_rawget(L, lua_upvalueindex(1));
                if (lua_isstring(L, -1))
                    canonicalMember = lua_tostring(L, -1);
                lua_pop(L, 1);

                const bool warnForEveryMember = lua_toboolean(L, lua_upvalueindex(5)) != 0;
                if (!canonicalMember && warnForEveryMember)
                    canonicalMember = legacyMember;
                if (!canonicalMember)
                    return callPreviousIndex(L);

                lua_pushstring(L, canonicalMember);
                lua_rawget(L, lua_upvalueindex(2));
                if (lua_isnil(L, -1))
                {
                    lua_pop(L, 1);
                    return callPreviousIndex(L);
                }

                const char* legacyPath = lua_tostring(L, lua_upvalueindex(3));
                const char* canonicalPath = lua_tostring(L, lua_upvalueindex(4));
                warnLegacyEnumLookup(L,
                    std::string(legacyPath) + "." + legacyMember,
                    std::string(canonicalPath) + "." + canonicalMember);
                return 1;
            }

            static void installLegacyEnumIndex(lua_State* L, int sourceIndex, int targetIndex,
                int aliasMapIndex, const char* sourcePath, const char* targetPath,
                bool warnForEveryMember)
            {
                sourceIndex = absoluteIndex(L, sourceIndex);
                targetIndex = absoluteIndex(L, targetIndex);
                aliasMapIndex = absoluteIndex(L, aliasMapIndex);

                if (!lua_getmetatable(L, sourceIndex))
                    lua_newtable(L);
                const int metatableIndex = absoluteIndex(L, -1);

                lua_getfield(L, metatableIndex, "__index");
                const int previousIndex = absoluteIndex(L, -1);

                lua_pushvalue(L, aliasMapIndex);
                lua_pushvalue(L, targetIndex);
                lua_pushstring(L, sourcePath);
                lua_pushstring(L, targetPath);
                lua_pushboolean(L, warnForEveryMember ? 1 : 0);
                lua_pushvalue(L, previousIndex);
                lua_pushcclosure(L, lua_compat_legacyEnumIndex, 6);
                lua_setfield(L, metatableIndex, "__index");

                lua_pop(L, 1); // previous __index
                lua_setmetatable(L, sourceIndex);
            }

            static void installLegacyEnumPath(lua_State* L, int targetIndex, int aliasMapIndex,
                const char* legacyPath, const char* canonicalPath)
            {
                lua_getglobal(L, legacyPath);
                if (lua_isnil(L, -1))
                {
                    lua_pop(L, 1);
                    lua_newtable(L);
                    lua_pushvalue(L, -1);
                    lua_setglobal(L, legacyPath);
                }

                if (lua_istable(L, -1))
                    installLegacyEnumIndex(L, -1, targetIndex, aliasMapIndex,
                        legacyPath, canonicalPath, true);
                lua_pop(L, 1);
            }

            static void installLegacyEnumPaths(lua_State* L, int targetIndex, int aliasMapIndex,
                const LegacyEnumDefinition& definition)
            {
                const char* path = definition.legacyPaths;
                while (path && *path)
                {
                    const char* end = strchr(path, ';');
                    if (!end)
                        end = path + strlen(path);

                    const std::string legacyPath(path, end - path);
                    installLegacyEnumPath(L, targetIndex, aliasMapIndex,
                        legacyPath.c_str(), definition.canonicalPath);
                    path = *end ? end + 1 : end;
                }
            }

            static void installEnumCompatibility(lua_State* L)
            {
                const LegacyEnumDefinition* definition = s_legacyEnumDefinitions;
                for (; definition->canonicalPath; ++definition)
                {
                    if (!pushTablePath(L, definition->canonicalPath))
                    {
                        lua_pop(L, 1);
                        continue;
                    }
                    const int targetIndex = absoluteIndex(L, -1);

                    pushLegacyAliasMap(L, definition->memberAliases);
                    const int aliasMapIndex = absoluteIndex(L, -1);

                    if (definition->memberAliases && definition->memberAliases[0])
                    {
                        installLegacyEnumIndex(L, targetIndex, targetIndex, aliasMapIndex,
                            definition->canonicalPath, definition->canonicalPath, false);
                    }

                    installLegacyEnumPaths(L, targetIndex, aliasMapIndex, *definition);
                    lua_pop(L, 2); // alias map, canonical table
                }
            }

            // ========================================================================
            // Global MyGUI Polyfills
            // ========================================================================

            static int lua_compat_resetKeyFocus(lua_State* L)
            {
                if (MyGUI::InputManager::getInstancePtr())
                {
                    if (MyGUI::InputManager::getInstance().getKeyFocusWidget())
                    {
                        MyGUI::InputManager::getInstance().resetKeyFocusWidget();
                    }
                }
                return 0;
            }

            static int lua_compat_setPointerVisible(lua_State* L)
            {
                bool visible = lua_isboolean(L, 1) ? (lua_toboolean(L, 1) != 0) : true;
                if (MyGUI::PointerManager::getInstancePtr())
                {
                    MyGUI::PointerManager::getInstance().setVisible(visible);
                }
                return 0;
            }

            static int lua_compat_isResourceExist(lua_State* L)
            {
                const char* name = luaL_optstring(L, 1, "");
                bool exists = false;
                if (MyGUI::SkinManager::getInstancePtr() && name && name[0])
                {
                    exists = MyGUI::SkinManager::getInstance().isExist(name);
                }
                lua_pushboolean(L, exists ? 1 : 0);
                return 1;
            }

            static int lua_compat_loadResource(lua_State* L)
            {
                if (!MyGUI::LayoutManager::getInstancePtr() || !lua_isstring(L, 1))
                {
                    lua_pushnil(L);
                    return 1;
                }
                return LayoutManagerBinding::loadLayout(L);
            }

            static int lua_compat_createWidget(lua_State* L)
            {
                // Upvalue 1: rawCreateWidget
                int top = lua_gettop(L);
                if (top >= 7 && lua_isstring(L, 7))
                {
                    bool arg8IsUd = (top >= 8 && lua_isuserdata(L, 8));
                    bool arg8IsStrNo9 = (top >= 8 && lua_isstring(L, 8) && (top < 9 || lua_isnil(L, 9)));

                    if (arg8IsUd)
                    {
                        lua_getfield(L, 8, "createWidget");
                        if (lua_isfunction(L, -1))
                        {
                            lua_pushvalue(L, 8); // self (parent)
                            lua_pushvalue(L, 1); // widgetType
                            lua_pushvalue(L, 2); // skin
                            lua_pushvalue(L, 3); // x
                            lua_pushvalue(L, 4); // y
                            lua_pushvalue(L, 5); // w
                            lua_pushvalue(L, 6); // h
                            lua_pushinteger(L, 0); // align
                            lua_pushvalue(L, 7); // name
                            lua_call(L, 8, 1);
                            return 1;
                        }
                        lua_pop(L, 1);
                    }
                    else if (arg8IsStrNo9)
                    {
                        const char* layerStr = lua_tostring(L, 8);
                        const char* layer = (layerStr && layerStr[0]) ? layerStr : "Window";

                        lua_pushvalue(L, lua_upvalueindex(1)); // rawCreateWidget
                        lua_pushvalue(L, 1); // widgetType
                        lua_pushvalue(L, 2); // skin
                        lua_pushvalue(L, 3); // x
                        lua_pushvalue(L, 4); // y
                        lua_pushvalue(L, 5); // w
                        lua_pushvalue(L, 6); // h
                        lua_pushinteger(L, 0); // align
                        lua_pushstring(L, layer); // layer
                        lua_pushvalue(L, 7); // name
                        lua_call(L, 9, 1);
                        return 1;
                    }
                }

                // Default: forward directly to rawCreateWidget
                lua_pushvalue(L, lua_upvalueindex(1));
                for (int i = 1; i <= top; ++i)
                {
                    lua_pushvalue(L, i);
                }
                lua_call(L, top, LUA_MULTRET);
                return lua_gettop(L) - top;
            }

            // ========================================================================
            // Shared Widget Compatibility Methods
            // ========================================================================

            static void getViewportSize(int& vw, int& vh)
            {
                vw = 1920;
                vh = 1080;
                if (MyGUI::RenderManager::getInstancePtr())
                {
                    const MyGUI::IntSize& sz = MyGUI::RenderManager::getInstance().getViewSize();
                    if (sz.width > 0 && sz.height > 0)
                    {
                        vw = sz.width;
                        vh = sz.height;
                    }
                }
            }

            static int lua_compat_setPositionReal(lua_State* L)
            {
                MyGUI::Widget* w = WidgetBinding::getWidget(L, 1);
                int vw = 1920, vh = 1080;
                getViewportSize(vw, vh);

                double x = luaL_optnumber(L, 2, 0.0);
                double y = luaL_optnumber(L, 3, 0.0);
                int px = (int)std::floor(x * vw + 0.5);
                int py = (int)std::floor(y * vh + 0.5);

                if (w)
                {
                    w->setPosition(px, py);
                    if (lua_gettop(L) >= 5 && !lua_isnil(L, 4) && !lua_isnil(L, 5))
                    {
                        double width = luaL_checknumber(L, 4);
                        double height = luaL_checknumber(L, 5);
                        w->setSize((int)std::floor(width * vw + 0.5), (int)std::floor(height * vh + 0.5));
                    }
                }
                else if (lua_istable(L, 1) || lua_isuserdata(L, 1))
                {
                    lua_getfield(L, 1, "setPosition");
                    if (lua_isfunction(L, -1))
                    {
                        lua_pushvalue(L, 1);
                        lua_pushinteger(L, px);
                        lua_pushinteger(L, py);
                        lua_pcall(L, 3, 0, 0);
                    }
                    else
                    {
                        lua_pop(L, 1);
                    }

                    if (lua_gettop(L) >= 5 && !lua_isnil(L, 4) && !lua_isnil(L, 5))
                    {
                        double width = luaL_checknumber(L, 4);
                        double height = luaL_checknumber(L, 5);
                        int pw = (int)std::floor(width * vw + 0.5);
                        int ph = (int)std::floor(height * vh + 0.5);

                        lua_getfield(L, 1, "setSize");
                        if (lua_isfunction(L, -1))
                        {
                            lua_pushvalue(L, 1);
                            lua_pushinteger(L, pw);
                            lua_pushinteger(L, ph);
                            lua_pcall(L, 3, 0, 0);
                        }
                        else
                        {
                            lua_pop(L, 1);
                        }
                    }
                }
                return 0;
            }

            static int lua_compat_getImageSize(lua_State* L)
            {
                MyGUI::Widget* w = WidgetBinding::getWidget(L, 1);
                if (w)
                {
                    MyGUI::IntSize sz = w->getSize();
                    lua_pushinteger(L, sz.width);
                    lua_pushinteger(L, sz.height);
                    return 2;
                }
                else if (lua_istable(L, 1) || lua_isuserdata(L, 1))
                {
                    lua_getfield(L, 1, "getSize");
                    if (lua_isfunction(L, -1))
                    {
                        lua_pushvalue(L, 1);
                        if (lua_pcall(L, 1, 2, 0) == 0)
                        {
                            return 2;
                        }
                        lua_pop(L, 1);
                    }
                    else
                    {
                        lua_pop(L, 1);
                    }
                }
                lua_pushinteger(L, 0);
                lua_pushinteger(L, 0);
                return 2;
            }

            static int lua_compat_setImageInfo(lua_State* L)
            {
                if (!lua_isnoneornil(L, 2))
                {
                    lua_getfield(L, 1, "setImageTexture");
                    if (lua_isfunction(L, -1))
                    {
                        lua_pushvalue(L, 1);
                        lua_pushvalue(L, 2);
                        lua_pcall(L, 2, 0, 0);
                    }
                    else
                    {
                        lua_pop(L, 1);
                    }
                }

                if (!lua_isnoneornil(L, 6)) // a5 ~= nil
                {
                    lua_getfield(L, 1, "setImageCoord");
                    if (lua_isfunction(L, -1))
                    {
                        lua_pushvalue(L, 1);
                        lua_pushvalue(L, 3);
                        lua_pushvalue(L, 4);
                        lua_pushvalue(L, 5);
                        lua_pushvalue(L, 6);
                        lua_pcall(L, 5, 0, 0);
                    }
                    else
                    {
                        lua_pop(L, 1);
                    }

                    if (!lua_isnoneornil(L, 7) && !lua_isnoneornil(L, 8))
                    {
                        lua_getfield(L, 1, "setImageTile");
                        if (lua_isfunction(L, -1))
                        {
                            lua_pushvalue(L, 1);
                            lua_pushvalue(L, 7);
                            lua_pushvalue(L, 8);
                            lua_pcall(L, 3, 0, 0);
                        }
                        else
                        {
                            lua_pop(L, 1);
                        }
                    }
                }
                else
                {
                    if (!lua_isnoneornil(L, 3))
                    {
                        lua_getfield(L, 1, "setImageCoord");
                        if (lua_isfunction(L, -1))
                        {
                            lua_pushvalue(L, 1);
                            lua_pushvalue(L, 3);
                            lua_pcall(L, 2, 0, 0);
                        }
                        else
                        {
                            lua_pop(L, 1);
                        }
                    }
                    if (!lua_isnoneornil(L, 4))
                    {
                        lua_getfield(L, 1, "setImageTile");
                        if (lua_isfunction(L, -1))
                        {
                            lua_pushvalue(L, 1);
                            lua_pushvalue(L, 4);
                            lua_pcall(L, 2, 0, 0);
                        }
                        else
                        {
                            lua_pop(L, 1);
                        }
                    }
                }
                return 0;
            }

            static int lua_compat_setImageRect(lua_State* L)
            {
                lua_getfield(L, 1, "setImageCoord");
                if (lua_isfunction(L, -1))
                {
                    lua_pushvalue(L, 1);
                    if (!lua_isnoneornil(L, 5))
                    {
                        lua_pushvalue(L, 2);
                        lua_pushvalue(L, 3);
                        lua_pushvalue(L, 4);
                        lua_pushvalue(L, 5);
                        lua_pcall(L, 5, 0, 0);
                    }
                    else
                    {
                        lua_pushvalue(L, 2);
                        lua_pcall(L, 2, 0, 0);
                    }
                }
                else
                {
                    lua_pop(L, 1);
                }
                return 0;
            }

            static int lua_compat_attachToWidget(lua_State* L)
            {
                MyGUI::Widget* self = WidgetBinding::getWidget(L, 1);
                MyGUI::Widget* parent = WidgetBinding::getWidget(L, 2);
                if (self && parent)
                {
                    MyGUI::IntPoint pp = parent->getPosition();
                    MyGUI::IntPoint sp = self->getPosition();
                    self->setPosition(sp.left + pp.left, sp.top + pp.top);
                    return 0;
                }

                if ((lua_istable(L, 1) || lua_isuserdata(L, 1)) && (lua_istable(L, 2) || lua_isuserdata(L, 2)))
                {
                    lua_getfield(L, 2, "getPosition");
                    if (lua_isfunction(L, -1))
                    {
                        lua_pushvalue(L, 2);
                        if (lua_pcall(L, 1, 2, 0) == 0)
                        {
                            int px = (int)luaL_optinteger(L, -2, 0);
                            int py = (int)luaL_optinteger(L, -1, 0);
                            lua_pop(L, 2);

                            lua_getfield(L, 1, "getPosition");
                            if (lua_isfunction(L, -1))
                            {
                                lua_pushvalue(L, 1);
                                if (lua_pcall(L, 1, 2, 0) == 0)
                                {
                                    int sx = (int)luaL_optinteger(L, -2, 0);
                                    int sy = (int)luaL_optinteger(L, -1, 0);
                                    lua_pop(L, 2);

                                    lua_getfield(L, 1, "setPosition");
                                    if (lua_isfunction(L, -1))
                                    {
                                        lua_pushvalue(L, 1);
                                        lua_pushinteger(L, sx + px);
                                        lua_pushinteger(L, sy + py);
                                        lua_pcall(L, 3, 0, 0);
                                    }
                                    else
                                    {
                                        lua_pop(L, 1);
                                    }
                                }
                                else
                                {
                                    lua_pop(L, 1);
                                }
                            }
                            else
                            {
                                lua_pop(L, 1);
                            }
                        }
                        else
                        {
                            lua_pop(L, 1);
                        }
                    }
                    else
                    {
                        lua_pop(L, 1);
                    }
                }
                return 0;
            }

            static int lua_compat_detachFromWidget(lua_State* L)
            {
                return 0;
            }

            // ========================================================================
            // Base Widget Monolithic Property Fallbacks
            // ========================================================================

            static int lua_compat_prop_setString(lua_State* L)
            {
                const char* prop = lua_tostring(L, lua_upvalueindex(1));
                if (!prop) return 0;

                size_t len = 0;
                const char* val = luaL_tolstring(L, 2, &len);
                const char* valStr = val ? val : "";

                MyGUI::Widget* w = WidgetBinding::getWidget(L, 1);
                if (w)
                {
                    w->setProperty(prop, valStr);
                }
                else if (lua_istable(L, 1) || lua_isuserdata(L, 1))
                {
                    lua_getfield(L, 1, "setProperty");
                    if (lua_isfunction(L, -1))
                    {
                        lua_pushvalue(L, 1);
                        lua_pushstring(L, prop);
                        lua_pushstring(L, valStr);
                        lua_pcall(L, 3, 0, 0);
                    }
                    else
                    {
                        lua_pop(L, 1);
                    }
                }
                lua_pop(L, 1); // pop string pushed by luaL_tolstring
                return 0;
            }

            static int lua_compat_prop_getString(lua_State* L)
            {
                const char* prop = lua_tostring(L, lua_upvalueindex(1));
                if (lua_istable(L, 1) || lua_isuserdata(L, 1))
                {
                    lua_getfield(L, 1, "getProperty");
                    if (lua_isfunction(L, -1))
                    {
                        lua_pushvalue(L, 1);
                        lua_pushstring(L, prop ? prop : "");
                        if (lua_pcall(L, 2, 1, 0) == 0 && lua_isstring(L, -1))
                        {
                            return 1;
                        }
                        lua_pop(L, 1);
                    }
                    else
                    {
                        lua_pop(L, 1);
                    }
                }

                MyGUI::Widget* w = WidgetBinding::getWidget(L, 1);
                if (w && prop && w->isUserString(prop))
                {
                    lua_pushstring(L, w->getUserString(prop).c_str());
                    return 1;
                }

                lua_pushliteral(L, "");
                return 1;
            }

            static int lua_compat_prop_getNumber(lua_State* L)
            {
                const char* prop = lua_tostring(L, lua_upvalueindex(1));
                if (lua_istable(L, 1) || lua_isuserdata(L, 1))
                {
                    lua_getfield(L, 1, "getProperty");
                    if (lua_isfunction(L, -1))
                    {
                        lua_pushvalue(L, 1);
                        lua_pushstring(L, prop ? prop : "");
                        if (lua_pcall(L, 2, 1, 0) == 0)
                        {
                            if (lua_isnumber(L, -1))
                            {
                                return 1;
                            }
                            if (lua_isstring(L, -1))
                            {
                                double d = atof(lua_tostring(L, -1));
                                lua_pop(L, 1);
                                lua_pushnumber(L, d);
                                return 1;
                            }
                        }
                        lua_pop(L, 1);
                    }
                    else
                    {
                        lua_pop(L, 1);
                    }
                }

                MyGUI::Widget* w = WidgetBinding::getWidget(L, 1);
                if (w && prop && w->isUserString(prop))
                {
                    double d = atof(w->getUserString(prop).c_str());
                    lua_pushnumber(L, d);
                    return 1;
                }

                lua_pushnumber(L, 0);
                return 1;
            }

            static int lua_compat_prop_setBool(lua_State* L)
            {
                const char* prop = lua_tostring(L, lua_upvalueindex(1));
                if (!prop) return 0;

                bool b = lua_toboolean(L, 2) != 0;
                const char* valStr = b ? "true" : "false";

                MyGUI::Widget* w = WidgetBinding::getWidget(L, 1);
                if (w)
                {
                    w->setProperty(prop, valStr);
                }
                else if (lua_istable(L, 1) || lua_isuserdata(L, 1))
                {
                    lua_getfield(L, 1, "setProperty");
                    if (lua_isfunction(L, -1))
                    {
                        lua_pushvalue(L, 1);
                        lua_pushstring(L, prop);
                        lua_pushstring(L, valStr);
                        lua_pcall(L, 3, 0, 0);
                    }
                    else
                    {
                        lua_pop(L, 1);
                    }
                }
                return 0;
            }

            static int lua_compat_prop_getBool(lua_State* L)
            {
                const char* prop = lua_tostring(L, lua_upvalueindex(1));
                if (lua_istable(L, 1) || lua_isuserdata(L, 1))
                {
                    lua_getfield(L, 1, "getProperty");
                    if (lua_isfunction(L, -1))
                    {
                        lua_pushvalue(L, 1);
                        lua_pushstring(L, prop ? prop : "");
                        if (lua_pcall(L, 2, 1, 0) == 0 && lua_isstring(L, -1))
                        {
                            bool b = (strcmp(lua_tostring(L, -1), "true") == 0);
                            lua_pop(L, 1);
                            lua_pushboolean(L, b ? 1 : 0);
                            return 1;
                        }
                        lua_pop(L, 1);
                    }
                    else
                    {
                        lua_pop(L, 1);
                    }
                }

                MyGUI::Widget* w = WidgetBinding::getWidget(L, 1);
                if (w && prop && w->isUserString(prop))
                {
                    bool b = (w->getUserString(prop) == "true");
                    lua_pushboolean(L, b ? 1 : 0);
                    return 1;
                }

                lua_pushboolean(L, 0);
                return 1;
            }

            static int lua_compat_prop_setSize(lua_State* L)
            {
                const char* prop = lua_tostring(L, lua_upvalueindex(1));
                if (!prop) return 0;

                int width = (int)luaL_optinteger(L, 2, 0);
                int height = (int)luaL_optinteger(L, 3, 0);
                char buf[64];
                _snprintf(buf, sizeof(buf), "%d %d", width, height);

                MyGUI::Widget* w = WidgetBinding::getWidget(L, 1);
                if (w)
                {
                    w->setProperty(prop, buf);
                }
                else if (lua_istable(L, 1) || lua_isuserdata(L, 1))
                {
                    lua_getfield(L, 1, "setProperty");
                    if (lua_isfunction(L, -1))
                    {
                        lua_pushvalue(L, 1);
                        lua_pushstring(L, prop);
                        lua_pushstring(L, buf);
                        lua_pcall(L, 3, 0, 0);
                    }
                    else
                    {
                        lua_pop(L, 1);
                    }
                }
                return 0;
            }

            static int lua_compat_prop_getSize(lua_State* L)
            {
                const char* prop = lua_tostring(L, lua_upvalueindex(1));
                std::string val;
                if (lua_istable(L, 1) || lua_isuserdata(L, 1))
                {
                    lua_getfield(L, 1, "getProperty");
                    if (lua_isfunction(L, -1))
                    {
                        lua_pushvalue(L, 1);
                        lua_pushstring(L, prop ? prop : "");
                        if (lua_pcall(L, 2, 1, 0) == 0 && lua_isstring(L, -1))
                        {
                            val = lua_tostring(L, -1);
                        }
                        lua_pop(L, 1);
                    }
                    else
                    {
                        lua_pop(L, 1);
                    }
                }

                if (val.empty())
                {
                    MyGUI::Widget* w = WidgetBinding::getWidget(L, 1);
                    if (w && prop && w->isUserString(prop))
                    {
                        val = w->getUserString(prop);
                    }
                }

                int w = 0, h = 0;
                if (!val.empty())
                {
                    sscanf(val.c_str(), "%d %d", &w, &h);
                }
                lua_pushinteger(L, w);
                lua_pushinteger(L, h);
                return 2;
            }

            static int lua_compat_setVisibleSmooth(lua_State* L)
            {
                MyGUI::Widget* w = WidgetBinding::getWidget(L, 1);
                if (w)
                {
                    w->setVisible(lua_toboolean(L, 2) != 0);
                    return 0;
                }
                if (lua_istable(L, 1) || lua_isuserdata(L, 1))
                {
                    lua_getfield(L, 1, "setVisible");
                    if (lua_isfunction(L, -1))
                    {
                        lua_pushvalue(L, 1);
                        lua_pushvalue(L, 2);
                        lua_pcall(L, 2, 0, 0);
                        return 0;
                    }
                    lua_pop(L, 1);
                }
                return 0;
            }

            static int lua_compat_destroySmooth(lua_State* L)
            {
                MyGUI::Widget* w = WidgetBinding::getWidget(L, 1);
                if (w)
                {
                    return WidgetBinding::destroy(L);
                }
                if (lua_istable(L, 1) || lua_isuserdata(L, 1))
                {
                    lua_getfield(L, 1, "destroy");
                    if (lua_isfunction(L, -1))
                    {
                        lua_pushvalue(L, 1);
                        lua_pcall(L, 1, 0, 0);
                        return 0;
                    }
                    lua_pop(L, 1);
                }
                return 0;
            }

            enum FallbackPropType
            {
                PropType_String,
                PropType_Number,
                PropType_Bool,
                PropType_Size,
            };

            struct FallbackPropRegistration
            {
                const char* setterName;
                const char* getterName;
                const char* propName;
                FallbackPropType type;
            };

            static const FallbackPropRegistration s_fallbackProps[] = {
                { "setFontName",        "getFontName",        "FontName",        PropType_String },
                { "setFontHeight",      "getFontHeight",      "FontHeight",      PropType_Number },
                { "setTextAlign",       "getTextAlign",       "TextAlign",       PropType_Number },
                { "setTextColour",      "getTextColour",      "TextColour",      PropType_String },
                { "setEditReadOnly",    "getEditReadOnly",    "EditReadOnly",    PropType_Bool },
                { "setEditPassword",    "getEditPassword",    "EditPassword",    PropType_Bool },
                { "setEditMultiLine",   "getEditMultiLine",   "EditMultiLine",   PropType_Bool },
                { "setEditStatic",      "getEditStatic",      "EditStatic",      PropType_Bool },
                { "setPasswordChar",    nullptr,              "PasswordChar",    PropType_String },
                { "setOnlyText",        "getOnlyText",        "OnlyText",        PropType_Bool },
                { "setMinSize",         "getMinSize",         "MinSize",         PropType_Size },
                { "setMaxSize",         "getMaxSize",         "MaxSize",         PropType_Size },
                { "setMovable",         "getMovable",         "Movable",         PropType_Bool },
                { "setStateSelected",   "getStateSelected",   "StateSelected",   PropType_Bool },
                { "setImageTexture",    nullptr,              "ImageTexture",    PropType_String },
                { "setImageCoord",      nullptr,              "ImageCoord",      PropType_String },
                { "setImageTile",       nullptr,              "ImageTile",       PropType_String },
                { "setImageIndex",      "getImageIndex",      "ImageIndex",      PropType_Number },
            };
        }

        void InstallEnumCompatibility(lua_State* L)
        {
            if (!L) return;
            installEnumCompatibility(L);
        }

        void InstallMyGUICompatibility(lua_State* L)
        {
            if (!L) return;

            // 1. Global MyGUI convenience helpers
            lua_getglobal(L, "MyGUI");
            if (lua_istable(L, -1))
            {
                auto installGlobalIfMissing = [&](const char* name, lua_CFunction fn) {
                    lua_getfield(L, -1, name);
                    if (lua_isnil(L, -1))
                    {
                        lua_pop(L, 1);
                        lua_pushcfunction(L, fn);
                        lua_setfield(L, -2, name);
                    }
                    else
                    {
                        lua_pop(L, 1);
                    }
                };

                installGlobalIfMissing("resetKeyFocus", lua_compat_resetKeyFocus);
                installGlobalIfMissing("setPointerVisible", lua_compat_setPointerVisible);
                installGlobalIfMissing("isResourceExist", lua_compat_isResourceExist);
                installGlobalIfMissing("loadResource", lua_compat_loadResource);

                // createWidget adapter
                lua_getfield(L, -1, "createWidget");
                if (lua_isfunction(L, -1))
                {
                    if (lua_tocfunction(L, -1) != lua_compat_createWidget)
                    {
                        lua_pushcclosure(L, lua_compat_createWidget, 1);
                        lua_setfield(L, -2, "createWidget");
                    }
                    else
                    {
                        lua_pop(L, 1);
                    }
                }
                else
                {
                    lua_pop(L, 1);
                }
            }
            lua_pop(L, 1);

            // 2. Metatable methods across all MyGUI widget types
            static const char* const s_widgetMetatables[] = {
                "KenshiLua.MyGUI.Widget",
                "KenshiLua.MyGUI.Window",
                "KenshiLua.MyGUI.Button",
                "KenshiLua.MyGUI.EditBox",
                "KenshiLua.MyGUI.TextBox",
                "KenshiLua.MyGUI.ListBox",
                "KenshiLua.MyGUI.ComboBox",
                "KenshiLua.MyGUI.MultiListBox",
                "KenshiLua.MyGUI.ImageBox",
                "KenshiLua.MyGUI.ProgressBar",
                "KenshiLua.MyGUI.ScrollView",
                "KenshiLua.MyGUI.TabControl"
            };

            static const struct {
                const char* name;
                lua_CFunction fn;
            } s_sharedCompatMethods[] = {
                { "setPositionReal",  lua_compat_setPositionReal },
                { "setCoordReal",     lua_compat_setPositionReal },
                { "getImageSize",     lua_compat_getImageSize },
                { "setImageInfo",     lua_compat_setImageInfo },
                { "setImageRect",     lua_compat_setImageRect },
                { "attachToWidget",   lua_compat_attachToWidget },
                { "detachFromWidget", lua_compat_detachFromWidget }
            };

            const size_t numMetatables = sizeof(s_widgetMetatables) / sizeof(s_widgetMetatables[0]);
            const size_t numShared = sizeof(s_sharedCompatMethods) / sizeof(s_sharedCompatMethods[0]);
            const size_t numFallbacks = sizeof(s_fallbackProps) / sizeof(s_fallbackProps[0]);

            for (size_t i = 0; i < numMetatables; ++i)
            {
                const char* metaName = s_widgetMetatables[i];
                luaL_getmetatable(L, metaName);
                if (lua_istable(L, -1))
                {
                    for (size_t j = 0; j < numShared; ++j)
                    {
                        const char* methodName = s_sharedCompatMethods[j].name;
                        lua_CFunction methodFn = s_sharedCompatMethods[j].fn;

                        lua_getfield(L, -1, methodName);
                        if (lua_isnil(L, -1))
                        {
                            lua_pop(L, 1);
                            lua_pushcfunction(L, methodFn);
                            lua_setfield(L, -2, methodName);
                        }
                        else
                        {
                            lua_pop(L, 1);
                        }
                    }

                    if (strcmp(metaName, "KenshiLua.MyGUI.Widget") == 0)
                    {
                        // Install property fallback getters and setters
                        for (size_t k = 0; k < numFallbacks; ++k)
                        {
                            const FallbackPropRegistration& propReg = s_fallbackProps[k];
                            if (propReg.setterName)
                            {
                                lua_getfield(L, -1, propReg.setterName);
                                if (lua_isnil(L, -1))
                                {
                                    lua_pop(L, 1);
                                    lua_pushstring(L, propReg.propName);
                                    lua_CFunction fn = 0;
                                    switch (propReg.type)
                                    {
                                    case PropType_Bool: fn = lua_compat_prop_setBool; break;
                                    case PropType_Size: fn = lua_compat_prop_setSize; break;
                                    default:            fn = lua_compat_prop_setString; break;
                                    }
                                    lua_pushcclosure(L, fn, 1);
                                    lua_setfield(L, -2, propReg.setterName);
                                }
                                else
                                {
                                    lua_pop(L, 1);
                                }
                            }

                            if (propReg.getterName)
                            {
                                lua_getfield(L, -1, propReg.getterName);
                                if (lua_isnil(L, -1))
                                {
                                    lua_pop(L, 1);
                                    lua_pushstring(L, propReg.propName);
                                    lua_CFunction fn = 0;
                                    switch (propReg.type)
                                    {
                                    case PropType_Bool:   fn = lua_compat_prop_getBool; break;
                                    case PropType_Number: fn = lua_compat_prop_getNumber; break;
                                    case PropType_Size:   fn = lua_compat_prop_getSize; break;
                                    default:              fn = lua_compat_prop_getString; break;
                                    }
                                    lua_pushcclosure(L, fn, 1);
                                    lua_setfield(L, -2, propReg.getterName);
                                }
                                else
                                {
                                    lua_pop(L, 1);
                                }
                            }
                        }

                        // Install special methods
                        lua_getfield(L, -1, "setVisibleSmooth");
                        if (lua_isnil(L, -1))
                        {
                            lua_pop(L, 1);
                            lua_pushcfunction(L, lua_compat_setVisibleSmooth);
                            lua_setfield(L, -2, "setVisibleSmooth");
                        }
                        else
                        {
                            lua_pop(L, 1);
                        }

                        lua_getfield(L, -1, "destroySmooth");
                        if (lua_isnil(L, -1))
                        {
                            lua_pop(L, 1);
                            lua_pushcfunction(L, lua_compat_destroySmooth);
                            lua_setfield(L, -2, "destroySmooth");
                        }
                        else
                        {
                            lua_pop(L, 1);
                        }
                    }
                }
                lua_pop(L, 1);
            }
        }

        void Initialize(lua_State* L)
        {
            InstallEnumCompatibility(L);
            InstallMyGUICompatibility(L);
        }
    }
}
