#include "pch.h"
#include "Hooks_Common.h"
#include "Hooks_Internal.h"
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
        { "onBuildingNotifyConstructionComplete",           InstallHook_Building_NV_notifyConstructionComplete },
        { "onBuildingAddConstructionProgress",              InstallHook_Building_NV_addConstructionProgress },
        { "onBuildingSetConstructionProgress",              InstallHook_Building_NV_setConstructionProgress },
        { "onBuildingAddDismantleProgress",                 InstallHook_Building_NV_addDismantleProgress },
        { "onBuildingNotifyConstructionDismantling",        InstallHook_Building_NV_notifyConstructionDismantling },
        { "onBuildingUpgrade",                              InstallHook_Building_NV_upgrade },
        { "onBuildingCanUpgrade",                           InstallHook_Building_NV_canUpgrade },
        { "onBuildingDestroyDoors",                         InstallHook_Building_destroyDoors },
        { "onBuildingSetFaction",                           InstallHook_Building_NV_setFaction },
        { "onBuildingSetFloorVisibility",                   InstallHook_Building_setFloorVisibility },
        { "onBuildingSwitchLights",                         InstallHook_Building_NV_switchLights },
        { "onBuildingSwitchEffects",                        InstallHook_Building_NV_switchEffects },
        { "onBuildingNotifyEffect",                         InstallHook_Building_NV_notifyEffect },

        // Building/WallBuilding.h
        { "onWallBuildingHitByMeleeAttack",                 InstallHook_WallBuilding_NV_hitByMeleeAttack },

        // Building/DoorStuff.h
        { "onDoorStuffOpenDoor",                            InstallHook_DoorStuff_openDoor },
        { "onDoorStuffCloseDoor",                           InstallHook_DoorStuff_closeDoor },
        { "onDoorStuffLockDoor",                            InstallHook_DoorStuff_lockDoor },
        { "onDoorStuffUnlockDoor",                          InstallHook_DoorStuff_unlockDoor },
        { "onDoorStuffSetDoorState",                        InstallHook_DoorStuff_setDoorState },
        { "onDoorStuffHitByMeleeAttack",                    InstallHook_DoorStuff_NV_hitByMeleeAttack },

        // Building/ProductionBuilding.h
        { "onProductionBuildingOperate",                    InstallHook_ProductionBuilding_NV_operate },

        // Building/CraftingBuilding.h
        { "onCraftingBuildingOperate",                      InstallHook_CraftingBuilding_NV_operate },
        { "onCraftingBuildingNewCraftingButton",            InstallHook_CraftingBuilding_NV_newCraftingButton },
        { "onCraftingBuildingAddFinishedCraftItem",         InstallHook_CraftingBuilding_addFinishedCraftItem },
        { "onCraftingBuildingNotifyCraftFailure",           InstallHook_CraftingBuilding_notifyCraftFailiure },
        { "onCraftingBuildingDestroyProductionItem",        InstallHook_CraftingBuilding_destroyProductionItem },
        { "onCraftingBuildingRemoveCraft",                  InstallHook_CraftingBuilding_removeCraft },

        // Building/FurnaceBuilding.h
        { "onFurnaceBuildingOperate",                       InstallHook_FurnaceBuilding_NV_operate },

        // Building/ResearchBuilding.h
        { "onResearchBuildingOperate",                      InstallHook_ResearchBuilding_NV_operate },

        // Building/FarmBuilding.h
        { "onFarmBuildingOperate",                          InstallHook_FarmBuilding_NV_operate },
        { "onFarmBuildingDestroyAPlant",                    InstallHook_FarmBuilding_destroyAPlant },
        { "onFarmBuildingEat",                              InstallHook_FarmBuilding_eat },

        // Building/TurretBuilding.h
        { "onTurretBuildingOperate",                        InstallHook_TurretBuilding_NV_operate },
        { "onTurretBuildingAimAt",                          InstallHook_TurretBuilding_aimAt },

        // Building/UseableStuff.h
        { "onUseableStuffHitByMeleeAttack",                 InstallHook_UseableStuff_NV_hitByMeleeAttack },
        { "onUseableStuffTryOperate",                       InstallHook_UseableStuff_NV_tryOperate },
        { "onUseableStuffStopOperating",                    InstallHook_UseableStuff_stopOperating },
        { "onUseableStuffOccupantChanged",                  InstallHook_UseableStuff_occupantHandleChangedEvent },
        { "onUseableStuffPowerSwitched",                    InstallHook_UseableStuff_NV_switchPowerOn },
        { "onUseableStuffGivePower",                        InstallHook_UseableStuff_NV_givePower },
        { "onUseableStuffGetCostToUse",                     InstallHook_UseableStuff_NV_getCostToUse },
        { "onUseableStuffCouldIOperate",                    InstallHook_UseableStuff_NV_couldIOperate },
        { "onUseableStuffDontNeedWork",                     InstallHook_UseableStuff_NV_dontNeedWorkRightNow },
        { "onUseableStuffTakePowerFrom",                    InstallHook_UseableStuff_takePowerFrom },
        { "onUseableStuffTogglePowerButton",                InstallHook_UseableStuff_NV_togglePowerButton },
        { "onUseableStuffToggleBattButton",                 InstallHook_UseableStuff_NV_toggleBattButton },

        // PreviewBuilding
        { "onPreviewBuildingPlaceFinalPreviewBuilding",     InstallHook_PreviewBuilding_NV_placeFinalPreviewBuilding },
        { "onPreviewBuildingPlacementVerification",         InstallHook_PreviewBuilding_NV_placementVerification },
        { "onPreviewBuildingPlacePreview",                  InstallHook_PreviewBuilding_NV_placePreview },

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

        // Constructor Hooks
        { "onCharacterConstructed",                         InstallHook_Character_CONSTRUCTOR },
        { "onItemConstructed",                              InstallHook_Item_CONSTRUCTOR },
        { "onGearConstructed",                              InstallHook_Gear_CONSTRUCTOR },
        { "onSwordConstructed",                             InstallHook_Sword_CONSTRUCTOR },
        { "onCrossbowConstructed",                          InstallHook_Crossbow_CONSTRUCTOR },
        { "onArmourConstructed",                            InstallHook_Armour_CONSTRUCTOR },
        { "onLockedArmourConstructed",                      InstallHook_LockedArmour_CONSTRUCTOR },
        { "onWeaponConstructed",                            InstallHook_Weapon_CONSTRUCTOR },
        { "onBuildingConstructed",                          InstallHook_Building_CONSTRUCTOR },
        { "onPlatoonConstructed",                           InstallHook_Platoon_CONSTRUCTOR },
        { "onActivePlatoonConstructed",                     InstallHook_ActivePlatoon_CONSTRUCTOR },
        { "onFactionConstructed",                           InstallHook_Faction_CONSTRUCTOR },
        { "onBountyConstructed",                            InstallHook_Bounty_CONSTRUCTOR },
        { "onDamagesConstructed",                           InstallHook_Damages_CONSTRUCTOR },
        { "onInventoryConstructed",                         InstallHook_Inventory_CONSTRUCTOR },
        { "onDoorStuffConstructed",                         InstallHook_DoorStuff_CONSTRUCTOR },
        { "onProductionBuildingConstructed",                InstallHook_ProductionBuilding_CONSTRUCTOR },
        { "onCraftingBuildingConstructed",                  InstallHook_CraftingBuilding_CONSTRUCTOR },
        { "onFarmBuildingConstructed",                      InstallHook_FarmBuilding_CONSTRUCTOR },
        { "onTurretBuildingConstructed",                    InstallHook_TurretBuilding_CONSTRUCTOR },
        { "onFurnaceBuildingConstructed",                   InstallHook_FurnaceBuilding_CONSTRUCTOR },
        { "onResearchBuildingConstructed",                  InstallHook_ResearchBuilding_CONSTRUCTOR },
        { "onWallBuildingConstructed",                      InstallHook_WallBuilding_CONSTRUCTOR },
        { "onPreviewBuildingConstructed",                   InstallHook_PreviewBuilding_CONSTRUCTOR },
        { "onUseableStuffConstructed",                      InstallHook_UseableStuff_CONSTRUCTOR },
        { "onStorageBuildingConstructed",                   InstallHook_StorageBuilding_CONSTRUCTOR },
        { "onLightBuildingConstructed",                     InstallHook_LightBuilding_CONSTRUCTOR },
        { "onGeneratorBuildingConstructed",                 InstallHook_GeneratorBuilding_CONSTRUCTOR },
        { "onWindGeneratorBuildingConstructed",             InstallHook_WindGeneratorBuilding_CONSTRUCTOR },
        { "onGatewayBuildingConstructed",                   InstallHook_GatewayBuilding_CONSTRUCTOR },
        { "onTortureBuildingConstructed",                   InstallHook_TortureBuilding_CONSTRUCTOR },
        { "onRainCollectorBuildingConstructed",             InstallHook_RainCollectorBuilding_CONSTRUCTOR },
        { "onCharacterHumanConstructed",                    InstallHook_CharacterHuman_CONSTRUCTOR },
        { "onCharacterAnimalConstructed",                   InstallHook_CharacterAnimal_CONSTRUCTOR },
        { "onCharStatsConstructed",                         InstallHook_CharStats_CONSTRUCTOR },
        { "onCharBodyConstructed",                          InstallHook_CharBody_CONSTRUCTOR },
        { "onCharMovementConstructed",                      InstallHook_CharMovement_CONSTRUCTOR },
        { "onCombatClassConstructed",                       InstallHook_CombatClass_CONSTRUCTOR },
        { "onTownConstructed",                              InstallHook_Town_CONSTRUCTOR },
        { "onTownBaseConstructed",                          InstallHook_TownBase_CONSTRUCTOR },
        { "onFactionLeaderConstructed",                     InstallHook_FactionLeader_CONSTRUCTOR },
        { "onFactionRelationsConstructed",                  InstallHook_FactionRelations_CONSTRUCTOR },
        { "onFactionUniqueSquadManagerConstructed",         InstallHook_FactionUniqueSquadManager_CONSTRUCTOR },
        { "onProsperityManagerConstructed",                 InstallHook_ProsperityManager_CONSTRUCTOR },
        { "onInventoryItemBaseConstructed",                 InstallHook_InventoryItemBase_CONSTRUCTOR },
        { "onMedicalSystemConstructed",                     InstallHook_MedicalSystem_CONSTRUCTOR },
        { "onCombatTechniqueDataConstructed",               InstallHook_CombatTechniqueData_CONSTRUCTOR },
        { "onDialogueConstructed",                          InstallHook_Dialogue_CONSTRUCTOR },
        { "onDialogLineDataConstructed",                    InstallHook_DialogLineData_CONSTRUCTOR },
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
