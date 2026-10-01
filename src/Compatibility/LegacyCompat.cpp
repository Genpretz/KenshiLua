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
            InstallMyGUICompatibility(L);
        }
    }
}
