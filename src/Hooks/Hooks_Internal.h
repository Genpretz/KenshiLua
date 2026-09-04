#pragma once

// ---------------------------------------------------------------------------
// Forward declarations for every InstallHook_* function defined across the
// Hooks_*.cpp files. Hooks_Registry.cpp includes this to build
// g_eventHookRegistry without needing a separate header per subsystem file.
// ---------------------------------------------------------------------------

bool InstallHook_InputHandler_KeyDown();
bool InstallHook_GameWorld_CharsUpdate();
bool InstallHook_Character_Say();
bool InstallHook_Character_Select();
bool InstallHook_Character_Unselect();
bool InstallHook_Character_DeclareDead();
bool InstallHook_Character_PickupObject();
bool InstallHook_Character_GetPickedUp();
bool InstallHook_Character_TakeMoney();
bool InstallHook_Character_EatItem();
bool InstallHook_Character_HitByMeleeAttack();
bool InstallHook_Character_GettingEaten();
bool InstallHook_Character_SetStandingOrder();
bool InstallHook_Character_SetFaction();
bool InstallHook_Character_EquipItem();
bool InstallHook_Character_UnequipItem();
bool InstallHook_Character_ImStealingDoYouNotice();
bool InstallHook_Character_SmugglingTradeCheck();
bool InstallHook_Character_NV_init();
bool InstallHook_Character_isItOkForMeToLoot();
bool InstallHook_Character_getFencingSuccessChance();
bool InstallHook_Character_changeSlaveOwner();
bool InstallHook_Character_setChainedMode();
bool InstallHook_CharStats_SetHoldLocation();
bool InstallHook_CharStats_ClearHoldLocation();
bool InstallHook_CharStats_ChooseAttack();
bool InstallHook_CharStats_XpRunning();
bool InstallHook_CharStats_XpFirstAid();
bool InstallHook_CharStats_XpStealth();
bool InstallHook_CharStats_XpToughness_GetUpEvent();
bool InstallHook_CharStats_XpToughness_RagdollEvent();
bool InstallHook_CharStats_XpToughness_PunchSomething();
bool InstallHook_CharStats_XpEngineering();
bool InstallHook_CharStats_XpLockpicking();
bool InstallHook_CharStats_getStat();
bool InstallHook_CharStats_xpStat_eventBased();
bool InstallHook_CharStats_xpDodgeEvent();
bool InstallHook_PlayerInterface_Recruit();
bool InstallHook_PlayerInterface_SelectObject();
bool InstallHook_PlayerInterface_NewPlayerTaskSelectedCharacters();
bool InstallHook_PlayerInterface_addJobSelectedCharacters();
bool InstallHook_PlayerInterface_addOrderSelectedCharacters();
bool InstallHook_PlayerInterface_activateCharacterEditMode();
bool InstallHook_PlayerInterface_createSquad();
bool InstallHook_PlayerInterface_encounterFaction();
bool InstallHook_ActivePlatoon_AddActiveObject();
bool InstallHook_ActivePlatoon_RemoveObject();
bool InstallHook_Platoon_TaskIsComplete();
bool InstallHook_Platoon_iBuyStolenGoods();
bool InstallHook_Platoon_iBuyIllegalGoods();
bool InstallHook_Item_NotifyTheftFrom();
bool InstallHook_Inventory_getSectionOfType();
bool InstallHook_Inventory_getBestFoodItem();
bool InstallHook_InventoryItemBase_getValueSingle();
bool InstallHook_Inventory_NV_addItem();
bool InstallHook_Inventory_NV_removeItemDontDestroy_returnsItem();
bool InstallHook_Inventory_buyItem();
bool InstallHook_BountyManager_NotifyCrimeWitnessed();
bool InstallHook_FactionRelations_AffectRelations();
bool InstallHook_Faction_chooseARace();
bool InstallHook_Faction_getBuildingReplacement();
bool InstallHook_Faction_createNewEmptyActivePlatoon();
bool InstallHook_Faction_destroyPlatoon();
bool InstallHook_MedicalSystem_Amputate();
bool InstallHook_MedicalSystem_knockout();
bool InstallHook_MedicalSystem_canGetUpWakeUp();
bool InstallHook_DialogueWindow_Show();
bool InstallHook_Dialogue_DoActions();
bool InstallHook_Dialogue_Say();
bool InstallHook_Dialogue_endDialogue();
bool InstallHook_Dialogue__checkCondition();
bool InstallHook_Dialogue_startConversation();
bool InstallHook_Dialogue__endPlayerConversation();
bool InstallHook_Dialogue_startPlayerConversation();
bool InstallHook_Dialogue_sendEvent();
bool InstallHook_Dialogue_stopEvent();
bool InstallHook_RootObjectFactory_chooseMyClothing();
bool InstallHook_BaseLayout_initialise();
bool InstallHook_Ownerships_canIUseThisBuilding();
bool InstallHook_Building_isPublic();
bool InstallHook_Building_isForSale();
bool InstallHook_Building_calculateSaleValue();
bool InstallHook_Building_NV_onBuildingLoaded();
bool InstallHook_Building_NV_setBroken();
bool InstallHook_CharMovement_isRunning();
bool InstallHook_CharMovement_isRunningAway();
bool InstallHook_Building_setResidentSquad();
bool InstallHook_Building_addAnInternalBuilding();
bool InstallHook_InventoryGUI_addTradePartner();
bool InstallHook_BuildModeWindow_confirm();
bool InstallHook_SquadManagementScreen_removeSquad();
bool InstallHook_ManagementScreen_addMessage();
bool InstallHook_TitleScreen_loadGame();
bool InstallHook_Character_addGoal();
bool InstallHook_Character_addJob();
bool InstallHook_Character_addOrder();
bool InstallHook_Character_removeJob();
bool InstallHook_PlayerInterface_serialise();
bool InstallHook_PlayerInterface_loadFromSerialise();
bool InstallHook_Character_NV_serialise();
bool InstallHook_Character_NV_loadFromSerialise();
bool InstallHook_Character_NV_loadFromSerialisePostCreationStage();
bool InstallHook_Building_NV_serialise();
bool InstallHook_Building_NV_loadFromSerialise();
bool InstallHook_Platoon_NV_loadFromSerialise();
bool InstallHook_Town_NV_loadFromSerialise();
bool InstallHook_Building_NV_buyMeCallback();
bool InstallHook_DataPanelLine_Button_pressCallback();
bool InstallHook_InventoryGUI_fencingConfirmationCallback();
bool InstallHook_OrdersPanel_blockmodeButton();
bool InstallHook_OrdersPanel_holdButtonCallback();
bool InstallHook_OrdersPanel_passiveButtonCallback();
bool InstallHook_OrdersPanel_chaseButtonCallback();
bool InstallHook_OrdersPanel_tauntButtonCallback();
bool InstallHook_OrdersPanel_medicButton();
bool InstallHook_OrdersPanel_liftButton();
bool InstallHook_OrdersPanel_prospectingButton();
bool InstallHook_Inventory_NV_sectionAddItemCallback();
bool InstallHook_Inventory_NV_sectionRemoveItemCallback();
bool InstallHook_Inventory_NV_sectionUpdateItemCallback();
bool InstallHook_Inventory_NV_dropItem();
bool InstallHook_UseableStuff_NV_tryOperate();
bool InstallHook_UseableStuff_stopOperating();
bool InstallHook_UseableStuff_occupantHandleChangedEvent();
bool InstallHook_UseableStuff_NV_switchPowerOn();
bool InstallHook_UseableStuff_NV_givePower();
bool InstallHook_UseableStuff_NV_getCostToUse();
bool InstallHook_UseableStuff_NV_couldIOperate();
bool InstallHook_UseableStuff_NV_dontNeedWorkRightNow();

// Building.h (Additional)
bool InstallHook_Building_NV_notifyConstructionComplete();
bool InstallHook_Building_NV_addConstructionProgress();
bool InstallHook_Building_NV_setConstructionProgress();
bool InstallHook_Building_NV_addDismantleProgress();
bool InstallHook_Building_NV_notifyConstructionDismantling();
bool InstallHook_Building_NV_upgrade();
bool InstallHook_Building_NV_canUpgrade();
bool InstallHook_Building_destroyDoors();
bool InstallHook_Building_NV_setFaction();
bool InstallHook_Building_setFloorVisibility();
bool InstallHook_Building_NV_switchLights();
bool InstallHook_Building_NV_switchEffects();
bool InstallHook_Building_NV_notifyEffect();

// WallBuilding.h
bool InstallHook_WallBuilding_NV_hitByMeleeAttack();

// DoorStuff.h
bool InstallHook_DoorStuff_openDoor();
bool InstallHook_DoorStuff_closeDoor();
bool InstallHook_DoorStuff_lockDoor();
bool InstallHook_DoorStuff_unlockDoor();
bool InstallHook_DoorStuff_setDoorState();
bool InstallHook_DoorStuff_NV_hitByMeleeAttack();

// ProductionBuilding.h
bool InstallHook_ProductionBuilding_NV_operate();

// CraftingBuilding.h
bool InstallHook_CraftingBuilding_NV_operate();
bool InstallHook_CraftingBuilding_NV_newCraftingButton();
bool InstallHook_CraftingBuilding_addFinishedCraftItem();
bool InstallHook_CraftingBuilding_notifyCraftFailiure();
bool InstallHook_CraftingBuilding_destroyProductionItem();
bool InstallHook_CraftingBuilding_removeCraft();

// FurnaceBuilding.h
bool InstallHook_FurnaceBuilding_NV_operate();

// ResearchBuilding.h
bool InstallHook_ResearchBuilding_NV_operate();

// FarmBuilding.h
bool InstallHook_FarmBuilding_NV_operate();
bool InstallHook_FarmBuilding_destroyAPlant();
bool InstallHook_FarmBuilding_eat();

// TurretBuilding.h
bool InstallHook_TurretBuilding_NV_operate();
bool InstallHook_TurretBuilding_aimAt();

// UseableStuff.h (Additional)
bool InstallHook_UseableStuff_NV_hitByMeleeAttack();
bool InstallHook_UseableStuff_takePowerFrom();
bool InstallHook_UseableStuff_NV_togglePowerButton();
bool InstallHook_UseableStuff_NV_toggleBattButton();

// PreviewBuilding
bool InstallHook_PreviewBuilding_NV_placeFinalPreviewBuilding();
bool InstallHook_PreviewBuilding_NV_placementVerification();
bool InstallHook_PreviewBuilding_NV_placePreview();

// Constructor Hooks
bool InstallHook_Character_CONSTRUCTOR();
bool InstallHook_Item_CONSTRUCTOR();
bool InstallHook_Gear_CONSTRUCTOR();
bool InstallHook_Sword_CONSTRUCTOR();
bool InstallHook_Crossbow_CONSTRUCTOR();
bool InstallHook_Armour_CONSTRUCTOR();
bool InstallHook_LockedArmour_CONSTRUCTOR();
bool InstallHook_Weapon_CONSTRUCTOR();
bool InstallHook_Building_CONSTRUCTOR();
bool InstallHook_Platoon_CONSTRUCTOR();
bool InstallHook_ActivePlatoon_CONSTRUCTOR();
bool InstallHook_Faction_CONSTRUCTOR();
bool InstallHook_Bounty_CONSTRUCTOR();
bool InstallHook_Damages_CONSTRUCTOR();
bool InstallHook_Inventory_CONSTRUCTOR();

// New Constructor Hooks
bool InstallHook_DoorStuff_CONSTRUCTOR();
bool InstallHook_ProductionBuilding_CONSTRUCTOR();
bool InstallHook_CraftingBuilding_CONSTRUCTOR();
bool InstallHook_FarmBuilding_CONSTRUCTOR();
bool InstallHook_TurretBuilding_CONSTRUCTOR();
bool InstallHook_FurnaceBuilding_CONSTRUCTOR();
bool InstallHook_ResearchBuilding_CONSTRUCTOR();
bool InstallHook_WallBuilding_CONSTRUCTOR();
bool InstallHook_PreviewBuilding_CONSTRUCTOR();
bool InstallHook_UseableStuff_CONSTRUCTOR();
bool InstallHook_StorageBuilding_CONSTRUCTOR();
bool InstallHook_LightBuilding_CONSTRUCTOR();
bool InstallHook_GeneratorBuilding_CONSTRUCTOR();
bool InstallHook_WindGeneratorBuilding_CONSTRUCTOR();
bool InstallHook_GatewayBuilding_CONSTRUCTOR();
bool InstallHook_TortureBuilding_CONSTRUCTOR();
bool InstallHook_RainCollectorBuilding_CONSTRUCTOR();

bool InstallHook_CharacterHuman_CONSTRUCTOR();
bool InstallHook_CharacterAnimal_CONSTRUCTOR();
bool InstallHook_CharStats_CONSTRUCTOR();
bool InstallHook_CharBody_CONSTRUCTOR();
bool InstallHook_CharMovement_CONSTRUCTOR();
bool InstallHook_CombatClass_CONSTRUCTOR();

bool InstallHook_Town_CONSTRUCTOR();
bool InstallHook_TownBase_CONSTRUCTOR();
bool InstallHook_FactionLeader_CONSTRUCTOR();
bool InstallHook_FactionRelations_CONSTRUCTOR();
bool InstallHook_FactionUniqueSquadManager_CONSTRUCTOR();
bool InstallHook_ProsperityManager_CONSTRUCTOR();

bool InstallHook_InventoryItemBase_CONSTRUCTOR();
bool InstallHook_MedicalSystem_CONSTRUCTOR();
bool InstallHook_CombatTechniqueData_CONSTRUCTOR();

bool InstallHook_Dialogue_CONSTRUCTOR();
bool InstallHook_DialogLineData_CONSTRUCTOR();
