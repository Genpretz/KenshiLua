#include "pch.h"
#include "Hooks_Common.h"
#include "Hooks_Internal.h"
#include "EventSystem.h"
#include <string>

// ---------------------------------------------------------------------------
// Hook registry mapping Lua event names to domain-specific hook installer functions.
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
        { "InputHandler::keyDownEvent",                                      InstallHook_InputHandler_KeyDown },

        // GameWorld.h          
        { "GameWorld::charsUpdate",                                          InstallHook_GameWorld_CharsUpdate },

        // Character.h          
        { "Character::_NV_say",                                              InstallHook_Character_Say },
        { "Character::_NV_select",                                           InstallHook_Character_Select },
        { "Character::_NV_unselect",                                         InstallHook_Character_Unselect },
        { "Character::declareDead",                                          InstallHook_Character_DeclareDead },
        { "Character::pickupObject",                                         InstallHook_Character_PickupObject },
        { "Character::getPickedUp",                                          InstallHook_Character_GetPickedUp },
        { "Character::_NV_takeMoney",                                        InstallHook_Character_TakeMoney },
        { "Character::eatItem",                                              InstallHook_Character_EatItem },
        { "Character::_NV_hitByMeleeAttack",                                 InstallHook_Character_HitByMeleeAttack },
        { "Character::_NV_gettingEaten",                                     InstallHook_Character_GettingEaten },
        { "Character::_NV_setStandingOrder",                                 InstallHook_Character_SetStandingOrder },
        { "Character::_NV_setFaction",                                       InstallHook_Character_SetFaction },
        { "Character::_NV_equipItem",                                        InstallHook_Character_EquipItem },
        { "Character::_NV_unequipItem",                                      InstallHook_Character_UnequipItem },
        { "Character::_NV_ImStealingDoYouNotice",                            InstallHook_Character_ImStealingDoYouNotice },
        { "Character::_NV_smugglingTradeCheck",                              InstallHook_Character_SmugglingTradeCheck },
        { "Character::_NV_init",                                             InstallHook_Character_NV_init },
        { "Character::isItOkForMeToLoot",                                    InstallHook_Character_isItOkForMeToLoot },
        { "Character::getFencingSuccessChance",                              InstallHook_Character_getFencingSuccessChance },
        { "Character::changeSlaveOwner",                                     InstallHook_Character_changeSlaveOwner },
        { "Character::setChainedMode",                                       InstallHook_Character_setChainedMode },
        { "Character::addGoal",                                              InstallHook_Character_addGoal },
        { "Character::addJob",                                               InstallHook_Character_addJob },
        { "Character::addOrder",                                             InstallHook_Character_addOrder },
        { "Character::removeJob",                                            InstallHook_Character_removeJob },
        { "Character::_NV_serialise",                                        InstallHook_Character_NV_serialise },
        { "Character::_NV_loadFromSerialise",                                InstallHook_Character_NV_loadFromSerialise },
        { "Character::_NV_loadFromSerialisePostCreationStage",               InstallHook_Character_NV_loadFromSerialisePostCreationStage },

        // CharStats.h
        { "CharStats::setHoldLocation",                                      InstallHook_CharStats_SetHoldLocation },
        { "CharStats::clearHoldLocation",                                    InstallHook_CharStats_ClearHoldLocation },
        { "CharStats::chooseAttack",                                         InstallHook_CharStats_ChooseAttack },
        { "CharStats::xpRunning",                                            InstallHook_CharStats_XpRunning },
        { "CharStats::xpFirstAid",                                           InstallHook_CharStats_XpFirstAid },
        { "CharStats::xpStealth",                                            InstallHook_CharStats_XpStealth },
        { "CharStats::xpToughness_GetUpEvent",                               InstallHook_CharStats_XpToughness_GetUpEvent },
        { "CharStats::xpToughness_RagdollEvent",                             InstallHook_CharStats_XpToughness_RagdollEvent },
        { "CharStats::xpToughness_PunchSomething",                           InstallHook_CharStats_XpToughness_PunchSomething },
        { "CharStats::xpEngineering",                                        InstallHook_CharStats_XpEngineering },
        { "CharStats::xpLockpicking",                                        InstallHook_CharStats_XpLockpicking },
        { "CharStats::getStat",                                              InstallHook_CharStats_getStat },
        { "CharStats::xpStat_eventBased",                                    InstallHook_CharStats_xpStat_eventBased },
        { "CharStats::xpDodgeEvent",                                         InstallHook_CharStats_xpDodgeEvent },

        // PlayerInterface.h            
        { "PlayerInterface::recruit",                                        InstallHook_PlayerInterface_Recruit },
        { "PlayerInterface::selectObject",                                   InstallHook_PlayerInterface_SelectObject },
        { "PlayerInterface::newPlayerTaskSelectedCharacters",                InstallHook_PlayerInterface_NewPlayerTaskSelectedCharacters },
        { "PlayerInterface::activateCharacterEditMode",                      InstallHook_PlayerInterface_activateCharacterEditMode },
        { "PlayerInterface::createSquad",                                    InstallHook_PlayerInterface_createSquad },
        { "PlayerInterface::addJobSelectedCharacters",                       InstallHook_PlayerInterface_addJobSelectedCharacters },
        { "PlayerInterface::addOrderSelectedCharacters",                     InstallHook_PlayerInterface_addOrderSelectedCharacters },
        { "PlayerInterface::encounterFaction",                               InstallHook_PlayerInterface_encounterFaction },
        { "PlayerInterface::serialise",                                      InstallHook_PlayerInterface_serialise },
        { "PlayerInterface::loadFromSerialise",                              InstallHook_PlayerInterface_loadFromSerialise },

        // Platoon.h            
        { "ActivePlatoon::_NV_addActiveObject",                              InstallHook_ActivePlatoon_AddActiveObject },
        { "ActivePlatoon::_NV_removeObject",                                 InstallHook_ActivePlatoon_RemoveObject },
        { "Platoon::taskIsComplete",                                         InstallHook_Platoon_TaskIsComplete },
        { "Platoon::iBuyStolenGoods",                                        InstallHook_Platoon_iBuyStolenGoods },
        { "Platoon::iBuyIllegalGoods",                                       InstallHook_Platoon_iBuyIllegalGoods },
        { "Platoon::_NV_loadFromSerialise",                                  InstallHook_Platoon_NV_loadFromSerialise },
        { "Ownerships::canIUseThisBuilding",                                 InstallHook_Ownerships_canIUseThisBuilding },

        // Item.h           
        { "Item::_NV_notifyTheftFrom",                                       InstallHook_Item_NotifyTheftFrom },

        // Inventory.h / InventoryItemBase.h            
        { "Inventory::getSectionOfType",                                     InstallHook_Inventory_getSectionOfType },
        { "Inventory::getBestFoodItem",                                      InstallHook_Inventory_getBestFoodItem },
        { "InventoryItemBase::getValueSingle",                               InstallHook_InventoryItemBase_getValueSingle },
        { "Inventory::_NV_addItem",                                          InstallHook_Inventory_NV_addItem },
        { "Inventory::_NV_removeItemDontDestroy_returnsItem",                InstallHook_Inventory_NV_removeItemDontDestroy_returnsItem },
        { "Inventory::buyItem",                                              InstallHook_Inventory_buyItem },
        { "Inventory::_NV__sectionAddItemCallback",                          InstallHook_Inventory_NV_sectionAddItemCallback },
        { "Inventory::_NV__sectionRemoveItemCallback",                       InstallHook_Inventory_NV_sectionRemoveItemCallback },
        { "Inventory::_NV__sectionUpdateItemCallback",                       InstallHook_Inventory_NV_sectionUpdateItemCallback },
        { "Inventory::_NV_dropItem",                                         InstallHook_Inventory_NV_dropItem },

        // BountyManager.h          
        { "BountyManager::notifyCrimeWitnessed",                             InstallHook_BountyManager_NotifyCrimeWitnessed },

        // FactionRelations.h           
        { "FactionRelations::affectRelations",                               InstallHook_FactionRelations_AffectRelations },

        // Faction.h            
        { "Faction::chooseARace",                                            InstallHook_Faction_chooseARace },
        { "Faction::getBuildingReplacement",                                 InstallHook_Faction_getBuildingReplacement },
        { "Faction::createNewEmptyActivePlatoon",                            InstallHook_Faction_createNewEmptyActivePlatoon },
        { "Faction::destroyPlatoon",                                         InstallHook_Faction_destroyPlatoon },

        // MedicalSystem.h          
        { "MedicalSystem::amputate",                                         InstallHook_MedicalSystem_Amputate },
        { "MedicalSystem::knockout",                                         InstallHook_MedicalSystem_knockout },
        { "MedicalSystem::canGetUpWakeUp",                                   InstallHook_MedicalSystem_canGetUpWakeUp },

        // gui/DialogueWindow.h         
        { "DialogueWindow::show",                                            InstallHook_DialogueWindow_Show },

        // Dialogue.h           
        { "Dialogue::_doActions",                                            InstallHook_Dialogue_DoActions },
        { "Dialogue::say",                                                   InstallHook_Dialogue_Say },
        { "Dialogue::endDialogue",                                           InstallHook_Dialogue_endDialogue },
        { "Dialogue::_checkCondition",                                       InstallHook_Dialogue__checkCondition },
        { "Dialogue::startConversation",                                     InstallHook_Dialogue_startConversation },
        { "Dialogue::_endPlayerConversation",                                InstallHook_Dialogue__endPlayerConversation },
        { "Dialogue::startPlayerConversation",                               InstallHook_Dialogue_startPlayerConversation },
        { "Dialogue::sendEvent",                                             InstallHook_Dialogue_sendEvent },
        { "Dialogue::stopEvent",                                             InstallHook_Dialogue_stopEvent },

        // RootObjectFactory.h          
        { "RootObjectFactory::chooseMyClothing",                             InstallHook_RootObjectFactory_chooseMyClothing },

        // mygui/common/baselayout/BaseLayout.h         
        { "wraps::BaseLayout::initialise",                                   InstallHook_BaseLayout_initialise },

        // Building/Building.h          
        { "Building::isPublic",                                              InstallHook_Building_isPublic },
        { "Building::isForSale",                                             InstallHook_Building_isForSale },
        { "Building::calculateSaleValue",                                    InstallHook_Building_calculateSaleValue },
        { "Building::_NV_onBuildingLoaded",                                  InstallHook_Building_NV_onBuildingLoaded },
        { "Building::_NV_setBroken",                                         InstallHook_Building_NV_setBroken },
        { "Building::setResidentSquad",                                      InstallHook_Building_setResidentSquad },
        { "Building::addAnInternalBuilding",                                 InstallHook_Building_addAnInternalBuilding },
        { "Building::_NV_serialise",                                         InstallHook_Building_NV_serialise },
        { "Building::_NV_loadFromSerialise",                                 InstallHook_Building_NV_loadFromSerialise },
        { "Building::_NV_buyMeCallback",                                     InstallHook_Building_NV_buyMeCallback },
        { "Building::_NV_notifyConstructionComplete",                        InstallHook_Building_NV_notifyConstructionComplete },
        { "Building::_NV_addConstructionProgress",                           InstallHook_Building_NV_addConstructionProgress },
        { "Building::_NV_setConstructionProgress",                           InstallHook_Building_NV_setConstructionProgress },
        { "Building::_NV_addDismantleProgress",                              InstallHook_Building_NV_addDismantleProgress },
        { "Building::_NV_notifyConstructionDismantling",                     InstallHook_Building_NV_notifyConstructionDismantling },
        { "Building::_NV_upgrade",                                           InstallHook_Building_NV_upgrade },
        { "Building::_NV_canUpgrade",                                        InstallHook_Building_NV_canUpgrade },
        { "Building::destroyDoors",                                          InstallHook_Building_destroyDoors },
        { "Building::_NV_setFaction",                                        InstallHook_Building_NV_setFaction },
        { "Building::setFloorVisibility",                                    InstallHook_Building_setFloorVisibility },
        { "Building::_NV_switchLights",                                      InstallHook_Building_NV_switchLights },
        { "Building::_NV_switchEffects",                                     InstallHook_Building_NV_switchEffects },
        { "Building::_NV_notifyEffect",                                      InstallHook_Building_NV_notifyEffect },

        // Building/WallBuilding.h
        { "WallBuilding::_NV_hitByMeleeAttack",                              InstallHook_WallBuilding_NV_hitByMeleeAttack },

        // Building/DoorStuff.h
        { "DoorStuff::openDoor",                                             InstallHook_DoorStuff_openDoor },
        { "DoorStuff::closeDoor",                                            InstallHook_DoorStuff_closeDoor },
        { "DoorStuff::lockDoor",                                             InstallHook_DoorStuff_lockDoor },
        { "DoorStuff::unlockDoor",                                           InstallHook_DoorStuff_unlockDoor },
        { "DoorStuff::setDoorState",                                         InstallHook_DoorStuff_setDoorState },
        { "DoorStuff::_NV_hitByMeleeAttack",                                 InstallHook_DoorStuff_NV_hitByMeleeAttack },

        // Building/ProductionBuilding.h
        { "ProductionBuilding::_NV_operate",                                 InstallHook_ProductionBuilding_NV_operate },

        // Building/CraftingBuilding.h
        { "CraftingBuilding::_NV_operate",                                   InstallHook_CraftingBuilding_NV_operate },
        { "CraftingBuilding::_NV_newCraftingButton",                         InstallHook_CraftingBuilding_NV_newCraftingButton },
        { "CraftingBuilding::addFinishedCraftItem",                          InstallHook_CraftingBuilding_addFinishedCraftItem },
        { "CraftingBuilding::notifyCraftFailiure",                           InstallHook_CraftingBuilding_notifyCraftFailiure },
        { "CraftingBuilding::destroyProductionItem",                         InstallHook_CraftingBuilding_destroyProductionItem },
        { "CraftingBuilding::_removeCraft",                                  InstallHook_CraftingBuilding_removeCraft },

        // Building/FurnaceBuilding.h
        { "FurnaceBuilding::_NV_operate",                                    InstallHook_FurnaceBuilding_NV_operate },

        // Building/ResearchBuilding.h
        { "ResearchBuilding::_NV_operate",                                   InstallHook_ResearchBuilding_NV_operate },

        // Building/FarmBuilding.h
        { "FarmBuilding::_NV_operate",                                       InstallHook_FarmBuilding_NV_operate },
        { "FarmBuilding::destroyAPlant",                                     InstallHook_FarmBuilding_destroyAPlant },
        { "FarmBuilding::eat",                                               InstallHook_FarmBuilding_eat },

        // Building/TurretBuilding.h
        { "TurretBuilding::_NV_operate",                                     InstallHook_TurretBuilding_NV_operate },
        { "TurretBuilding::aimAt",                                           InstallHook_TurretBuilding_aimAt },

        // Building/UseableStuff.h
        { "UseableStuff::_NV_hitByMeleeAttack",                              InstallHook_UseableStuff_NV_hitByMeleeAttack },
        { "UseableStuff::_NV_tryOperate",                                    InstallHook_UseableStuff_NV_tryOperate },
        { "UseableStuff::stopOperating",                                     InstallHook_UseableStuff_stopOperating },
        { "UseableStuff::occupantHandleChangedEvent",                        InstallHook_UseableStuff_occupantHandleChangedEvent },
        { "UseableStuff::_NV_switchPowerOn",                                 InstallHook_UseableStuff_NV_switchPowerOn },
        { "UseableStuff::_NV_givePower",                                     InstallHook_UseableStuff_NV_givePower },
        { "UseableStuff::_NV_getCostToUse",                                  InstallHook_UseableStuff_NV_getCostToUse },
        { "UseableStuff::_NV_couldIOperate",                                 InstallHook_UseableStuff_NV_couldIOperate },
        { "UseableStuff::_NV_dontNeedWorkRightNow",                          InstallHook_UseableStuff_NV_dontNeedWorkRightNow },
        { "UseableStuff::takePowerFrom",                                     InstallHook_UseableStuff_takePowerFrom },
        { "UseableStuff::_NV_togglePowerButton",                             InstallHook_UseableStuff_NV_togglePowerButton },
        { "UseableStuff::_NV_toggleBattButton",                              InstallHook_UseableStuff_NV_toggleBattButton },

        // PreviewBuilding
        { "PreviewBuilding::_NV_placeFinalPreviewBuilding",                  InstallHook_PreviewBuilding_NV_placeFinalPreviewBuilding },
        { "PreviewBuilding::_NV_placementVerification",                      InstallHook_PreviewBuilding_NV_placementVerification },
        { "PreviewBuilding::_NV_placePreview",                               InstallHook_PreviewBuilding_NV_placePreview },

        // CharMovement.h           
        { "CharMovement::isRunning",                                         InstallHook_CharMovement_isRunning },
        { "CharMovement::isRunningAway",                                     InstallHook_CharMovement_isRunningAway },

        // InventoryGUI.h
        { "InventoryGUI::addTradePartner",                                   InstallHook_InventoryGUI_addTradePartner },
        { "InventoryGUI::fencingConfirmationCallback",                       InstallHook_InventoryGUI_fencingConfirmationCallback },

        // OrdersPanel.h
        { "OrdersPanel::blockmodeButton",                                    InstallHook_OrdersPanel_blockmodeButton },
        { "OrdersPanel::holdButtonCallback",                                 InstallHook_OrdersPanel_holdButtonCallback },
        { "OrdersPanel::passiveButtonCallback",                              InstallHook_OrdersPanel_passiveButtonCallback },
        { "OrdersPanel::chaseButtonCallback",                                InstallHook_OrdersPanel_chaseButtonCallback },
        { "OrdersPanel::tauntButtonCallback",                                InstallHook_OrdersPanel_tauntButtonCallback },
        { "OrdersPanel::medicButton",                                        InstallHook_OrdersPanel_medicButton },
        { "OrdersPanel::liftButton",                                         InstallHook_OrdersPanel_liftButton },
        { "OrdersPanel::prospectingButton",                                  InstallHook_OrdersPanel_prospectingButton },

        // Misc
        { "BuildModeWindow::confirm",                                        InstallHook_BuildModeWindow_confirm },
        { "SquadManagementScreen::removeSquad",                              InstallHook_SquadManagementScreen_removeSquad },
        { "ManagementScreen::addMessage",                                    InstallHook_ManagementScreen_addMessage },
        { "TitleScreen::loadGame",                                           InstallHook_TitleScreen_loadGame },
        { "Town::_NV_loadFromSerialise",                                     InstallHook_Town_NV_loadFromSerialise },
        { "DataPanelLine_Button::pressCallback",                             InstallHook_DataPanelLine_Button_pressCallback },

        // Constructor Hooks
        { "Character::_CONSTRUCTOR",                                         InstallHook_Character_CONSTRUCTOR },
        { "Item::_CONSTRUCTOR",                                              InstallHook_Item_CONSTRUCTOR },
        { "Gear::_CONSTRUCTOR",                                              InstallHook_Gear_CONSTRUCTOR },
        { "Sword::_CONSTRUCTOR",                                             InstallHook_Sword_CONSTRUCTOR },
        { "Crossbow::_CONSTRUCTOR",                                          InstallHook_Crossbow_CONSTRUCTOR },
        { "Armour::_CONSTRUCTOR",                                            InstallHook_Armour_CONSTRUCTOR },
        { "LockedArmour::_CONSTRUCTOR",                                      InstallHook_LockedArmour_CONSTRUCTOR },
        { "Weapon::_CONSTRUCTOR",                                            InstallHook_Weapon_CONSTRUCTOR },
        { "Building::_CONSTRUCTOR",                                          InstallHook_Building_CONSTRUCTOR },
        { "Platoon::_CONSTRUCTOR",                                           InstallHook_Platoon_CONSTRUCTOR },
        { "ActivePlatoon::_CONSTRUCTOR",                                     InstallHook_ActivePlatoon_CONSTRUCTOR },
        { "Faction::_CONSTRUCTOR",                                           InstallHook_Faction_CONSTRUCTOR },
        { "Bounty::_CONSTRUCTOR",                                            InstallHook_Bounty_CONSTRUCTOR },
        { "Damages::_CONSTRUCTOR",                                           InstallHook_Damages_CONSTRUCTOR },
        { "Inventory::_CONSTRUCTOR",                                         InstallHook_Inventory_CONSTRUCTOR },
        { "DoorStuff::_CONSTRUCTOR",                                         InstallHook_DoorStuff_CONSTRUCTOR },
        { "ProductionBuilding::_CONSTRUCTOR",                                InstallHook_ProductionBuilding_CONSTRUCTOR },
        { "CraftingBuilding::_CONSTRUCTOR",                                  InstallHook_CraftingBuilding_CONSTRUCTOR },
        { "FarmBuilding::_CONSTRUCTOR",                                      InstallHook_FarmBuilding_CONSTRUCTOR },
        { "TurretBuilding::_CONSTRUCTOR",                                    InstallHook_TurretBuilding_CONSTRUCTOR },
        { "FurnaceBuilding::_CONSTRUCTOR",                                   InstallHook_FurnaceBuilding_CONSTRUCTOR },
        { "ResearchBuilding::_CONSTRUCTOR",                                  InstallHook_ResearchBuilding_CONSTRUCTOR },
        { "WallBuilding::_CONSTRUCTOR",                                      InstallHook_WallBuilding_CONSTRUCTOR },
        { "PreviewBuilding::_CONSTRUCTOR",                                   InstallHook_PreviewBuilding_CONSTRUCTOR },
        { "UseableStuff::_CONSTRUCTOR",                                      InstallHook_UseableStuff_CONSTRUCTOR },
        { "StorageBuilding::_CONSTRUCTOR",                                   InstallHook_StorageBuilding_CONSTRUCTOR },
        { "LightBuilding::_CONSTRUCTOR",                                     InstallHook_LightBuilding_CONSTRUCTOR },
        { "GeneratorBuilding::_CONSTRUCTOR",                                 InstallHook_GeneratorBuilding_CONSTRUCTOR },
        { "WindGeneratorBuilding::_CONSTRUCTOR",                             InstallHook_WindGeneratorBuilding_CONSTRUCTOR },
        { "GatewayBuilding::_CONSTRUCTOR",                                   InstallHook_GatewayBuilding_CONSTRUCTOR },
        { "TortureBuilding::_CONSTRUCTOR",                                   InstallHook_TortureBuilding_CONSTRUCTOR },
        { "RainCollectorBuilding::_CONSTRUCTOR",                             InstallHook_RainCollectorBuilding_CONSTRUCTOR },
        { "CharacterHuman::_CONSTRUCTOR",                                    InstallHook_CharacterHuman_CONSTRUCTOR },
        { "CharacterAnimal::_CONSTRUCTOR",                                   InstallHook_CharacterAnimal_CONSTRUCTOR },
        { "CharStats::_CONSTRUCTOR",                                         InstallHook_CharStats_CONSTRUCTOR },
        { "CharBody::_CONSTRUCTOR",                                          InstallHook_CharBody_CONSTRUCTOR },
        { "CharMovement::_CONSTRUCTOR",                                      InstallHook_CharMovement_CONSTRUCTOR },
        { "CombatClass::_CONSTRUCTOR",                                       InstallHook_CombatClass_CONSTRUCTOR },
        { "Town::_CONSTRUCTOR",                                              InstallHook_Town_CONSTRUCTOR },
        { "TownBase::_CONSTRUCTOR",                                          InstallHook_TownBase_CONSTRUCTOR },
        { "FactionLeader::_CONSTRUCTOR",                                     InstallHook_FactionLeader_CONSTRUCTOR },
        { "FactionRelations::_CONSTRUCTOR",                                  InstallHook_FactionRelations_CONSTRUCTOR },
        { "FactionUniqueSquadManager::_CONSTRUCTOR",                         InstallHook_FactionUniqueSquadManager_CONSTRUCTOR },
        { "ProsperityManager::_CONSTRUCTOR",                                 InstallHook_ProsperityManager_CONSTRUCTOR },
        { "InventoryItemBase::_CONSTRUCTOR",                                 InstallHook_InventoryItemBase_CONSTRUCTOR },
        { "MedicalSystem::_CONSTRUCTOR",                                     InstallHook_MedicalSystem_CONSTRUCTOR },
        { "CombatTechniqueData::_CONSTRUCTOR",                               InstallHook_CombatTechniqueData_CONSTRUCTOR },
        { "Dialogue::_CONSTRUCTOR",                                          InstallHook_Dialogue_CONSTRUCTOR },
        { "DialogLineData::_CONSTRUCTOR",                                    InstallHook_DialogLineData_CONSTRUCTOR },
    };

    static const size_t g_eventHookRegistryCount = sizeof(g_eventHookRegistry) / sizeof(g_eventHookRegistry[0]);

    bool InstallHookForEvent(const std::string& rawEventName)
    {
        const char* canonical = EventSystem::resolveCanonicalEventName(rawEventName.c_str());
        std::string eventName = (canonical && canonical[0]) ? canonical : rawEventName;

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
