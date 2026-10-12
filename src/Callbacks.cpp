#include "pch.h"
#include "Callbacks.h"
#include "EventSystem.h"
#include "Lua/BindingHelpers.h"

//Bindings
#include "Bindings/Kenshi/ActivePlatoonBinding.h"
#include "Bindings/Kenshi/AppearanceManagerBinding.h"
#include "Bindings/Kenshi/ArmourBinding.h"
#include "Bindings/Kenshi/AttachedArrowManagerBinding.h"
#include "Bindings/Kenshi/BountyBinding.h"
#include "Bindings/Kenshi/BountyManagerBinding.h"
#include "Bindings/Kenshi/Building/BuildingBinding.h"
#include "Bindings/Kenshi/Building/CraftingBuildingBinding.h"
#include "Bindings/Kenshi/Building/DoorStuffBinding.h"
#include "Bindings/Kenshi/Building/FarmBuildingBinding.h"
#include "Bindings/Kenshi/Building/FurnaceBuildingBinding.h"
#include "Bindings/Kenshi/Building/GatewayBuildingBinding.h"
#include "Bindings/Kenshi/Building/GeneratorBuildingBinding.h"
#include "Bindings/Kenshi/Building/LightBuildingBinding.h"
#include "Bindings/Kenshi/Building/PreviewBuildingBinding.h"
#include "Bindings/Kenshi/Building/ProductionBuildingBinding.h"
#include "Bindings/Kenshi/Building/RainCollectorBuildingBinding.h"
#include "Bindings/Kenshi/Building/ResearchBuildingBinding.h"
#include "Bindings/Kenshi/Building/StorageBuildingBinding.h"
#include "Bindings/Kenshi/Building/TortureBuildingBinding.h"
#include "Bindings/Kenshi/Building/TurretBuildingBinding.h"
#include "Bindings/Kenshi/Building/UseableStuffBinding.h"
#include "Bindings/Kenshi/Building/WallBuildingBinding.h"
#include "Bindings/Kenshi/Building/WindGeneratorBuildingBinding.h"
#include "Bindings/Kenshi/CharBodyBinding.h"
#include "Bindings/Kenshi/CharMovementBinding.h"
#include "Bindings/Kenshi/CharStatsBinding.h"
#include "Bindings/Kenshi/CharacterAnimalBinding.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/CharacterHumanBinding.h"
#include "Bindings/Kenshi/CombatClassBinding.h"
#include "Bindings/Kenshi/CombatMovementControllerBinding.h"
#include "Bindings/Kenshi/CombatTechniqueDataBinding.h"
#include "Bindings/Kenshi/CrossbowBinding.h"
#include "Bindings/Kenshi/DamagesBinding.h"
#include "Bindings/Kenshi/DataObjectContainerBinding.h"
#include "Bindings/Kenshi/DialogLineDataBinding.h"
#include "Bindings/Kenshi/DialogueBinding.h"
#include "Bindings/Kenshi/FactionBinding.h"
#include "Bindings/Kenshi/FactionLeaderBinding.h"
#include "Bindings/Kenshi/FactionManagerBinding.h"
#include "Bindings/Kenshi/FactionRelationsBinding.h"
#include "Bindings/Kenshi/FactionUniqueSquadManagerBinding.h"
#include "Bindings/Kenshi/FactionWarMgrBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/GameDataContainerBinding.h"
#include "Bindings/Kenshi/GameDataCopyStandaloneBinding.h"
#include "Bindings/Kenshi/GameSaveStateBinding.h"
#include "Bindings/Kenshi/GameWorldBinding.h"
#include "Bindings/Kenshi/ContainerItemBinding.h"
#include "Bindings/Kenshi/GameplayOptionsBinding.h"
#include "Bindings/Kenshi/GearBinding.h"
#include "Bindings/Kenshi/Gui/BaseLayoutBinding.h"
#include "Bindings/Kenshi/Gui/BuildModeWindowBinding.h"
#include "Bindings/Kenshi/Gui/CharacterStatsWindowBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLineBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLine_ButtonBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLine_CheckBoxBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLine_DropBoxBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLine_FactionBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLine_KeyConfigBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLine_ProgressBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLine_ResearchBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLine_SliderBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLine_SliderEditableBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLine_TextBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLine_TextEditableBinding.h"
#include "Bindings/Kenshi/Gui/DatapanelGUIBinding.h"
#include "Bindings/Kenshi/Gui/DialogueWindowBinding.h"
#include "Bindings/Kenshi/Gui/FloatingProgressBarBinding.h"
#include "Bindings/Kenshi/Gui/FactionRelationsLineBinding.h"
#include "Bindings/Kenshi/Gui/FactionsScreenBinding.h"
#include "Bindings/Kenshi/Gui/ForgottenGUIBinding.h"
#include "Bindings/Kenshi/Gui/GUIWindowBinding.h"
#include "Bindings/Kenshi/Gui/ScreenLabelBinding.h"
#include "Bindings/Kenshi/Gui/ScreenLabelDebugBinding.h"
#include "Bindings/Kenshi/Gui/ScreenLabelInterfaceBinding.h"
#include "Bindings/Kenshi/Gui/StatBinding.h"
#include "Bindings/Kenshi/Gui/StatGroupBinding.h"
#include "Bindings/Kenshi/Gui/ToolTipBinding.h"
#include "Bindings/Kenshi/Gui/GenericFixedInventoryLayoutBinding.h"
#include "Bindings/Kenshi/Gui/BackpackInventoryLayoutBinding.h"
#include "Bindings/Kenshi/Gui/InventoryIconBinding.h"
#include "Bindings/Kenshi/Gui/InventorySectionGUIBinding.h"
#include "Bindings/Kenshi/Gui/InventoryTradeDataBinding.h"
#include "Bindings/Kenshi/Gui/TradeResultBinding.h"
#include "Bindings/Kenshi/Gui/InventoryGUIBinding.h"
#include "Bindings/Kenshi/Gui/InventoryLayoutBinding.h"
#include "Bindings/Kenshi/Gui/ContextMenuBinding.h"
#include "Bindings/Kenshi/Gui/ContextMenuGUIBinding.h"
#include "Bindings/Kenshi/Gui/ManagementScreenBinding.h"
#include "Bindings/Kenshi/ManagementScreen_TechItemViewDataBinding.h"
#include "Bindings/Kenshi/Gui/MapMarkerCharacterBinding.h"
#include "Bindings/Kenshi/Gui/MapMarkerTownBinding.h"
#include "Bindings/Kenshi/Gui/MapScreenBinding.h"
#include "Bindings/Kenshi/Gui/MainBarGUIBinding.h"
#include "Bindings/Kenshi/Gui/MainTabPortraitPlatoonBinding.h"
#include "Bindings/Kenshi/Gui/NewGameOptionsWindowBinding.h"
#include "Bindings/Kenshi/Gui/OrdersPanelBinding.h"
#include "Bindings/Kenshi/Gui/OrderCellViewBinding.h"
#include "Bindings/Kenshi/Gui/OrderDataBinding.h"
#include "Bindings/Kenshi/Gui/OrdersItemBoxBinding.h"
#include "Bindings/Kenshi/Gui/OptionsWindowBinding.h"
#include "Bindings/Kenshi/Gui/SquadManagementScreenBinding.h"
#include "Bindings/Kenshi/Gui/SplashScreenBinding.h"
#include "Bindings/Kenshi/Gui/TitleScreenBinding.h"
#include "Bindings/Kenshi/InputHandlerBinding.h"
#include "Bindings/Kenshi/InventoryBinding.h"
#include "Bindings/Kenshi/InventoryItemBaseBinding.h"
#include "Bindings/Kenshi/InventorySectionBinding.h"
#include "Bindings/Kenshi/ItemBinding.h"
#include "Bindings/Kenshi/LimbsInventoryLayoutBinding.h"
#include "Bindings/Kenshi/LockedArmourBinding.h"
#include "Bindings/Kenshi/MedicalSystemBinding.h"
#include "Bindings/Kenshi/OwnershipsBinding.h"
#include "Bindings/Kenshi/PlatoonBinding.h"
#include "Bindings/Kenshi/PlayerInterfaceBinding.h"
#include "Bindings/Kenshi/ProsperityManagerBinding.h"
#include "Bindings/Kenshi/RaceDataBinding.h"
#include "Bindings/Kenshi/RobotLimbsBinding.h"
#include "Bindings/Kenshi/RootObjectBaseBinding.h"
#include "Bindings/Kenshi/RootObjectBinding.h"
#include "Bindings/Kenshi/RootObjectFactoryBinding.h"
#include "Bindings/Kenshi/RootObjectContainerBinding.h"
#include "Bindings/Kenshi/ShopTraderBinding.h"
#include "Bindings/Kenshi/SwordBinding.h"
#include "Bindings/Kenshi/TaskerBinding.h"
#include "Bindings/Kenshi/TownBaseBinding.h"
#include "Bindings/Kenshi/TownBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/Util/iVector2Binding.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"
#include "Bindings/Kenshi/Util/rendHitBinding.h"
#include "Bindings/Kenshi/WeaponBinding.h"
#include "Bindings/Kenshi/WorldEventStateQueryBinding.h"
#include "Bindings/Kenshi/InventoryGUI_FenceCallbackDataBinding.h"
#include "Bindings/Kenshi/ZoneManagerBinding.h"
#include "Bindings/Kenshi/ZoneMapBinding.h"
#include "Bindings/MyGUI/MyGUIBinding.h"
#include "Bindings/MyGUI/GuiBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Bindings/MyGUI/TypesBinding.h"

// KenshiLib headers
#include <kenshi/AppearanceManager.h>
#include <kenshi/Bounty.h>
#include <kenshi/BountyManager.h>
#include <kenshi/Building/Building.h>
#include <kenshi/Building/CraftingBuilding.h>
#include <kenshi/Building/DoorStuff.h>
#include <kenshi/Building/FarmBuilding.h>
#include <kenshi/Building/FurnaceBuilding.h>
#include <kenshi/Building/GatewayBuilding.h>
#include <kenshi/Building/GeneratorBuilding.h>
#include <kenshi/Building/LightBuilding.h>
#include <kenshi/Building/ProductionBuilding.h>
#include <kenshi/Building/RainCollectorBuilding.h>
#include <kenshi/Building/ResearchBuilding.h>
#include <kenshi/Building/StorageBuilding.h>
#include <kenshi/Building/TortureBuilding.h>
#include <kenshi/Building/TurretBuilding.h>
#include <kenshi/Building/UseableStuff.h>
#include <kenshi/Building/WallBuilding.h>
#include <kenshi/CharBody.h>
#include <kenshi/CharMovement.h>
#include <kenshi/CharStats.h>
#include <kenshi/Character.h>
#include <kenshi/CharacterAnimal.h>
#include <kenshi/CharacterHuman.h>
#include <kenshi/CombatClass.h>
#include <kenshi/Damages.h>
#include <kenshi/Dialogue.h>
#include <kenshi/Faction.h>
#include <kenshi/FactionLeader.h>
#include <kenshi/FactionRelations.h>
#include <kenshi/FactionUniqueSquadManager.h>
#include <kenshi/FactionWarMgr.h>
#include <kenshi/GameWorld.h>
#include <kenshi/Gear.h>
#include <kenshi/InputHandler.h>
#include <kenshi/Item.h>
#include <kenshi/MedicalSystem.h>
#include <kenshi/Platoon.h>
#include <kenshi/PlayerInterface.h>
#include <kenshi/RootObjectBase.h>
#include <kenshi/RootObjectFactory.h>
#include <kenshi/ShopTrader.h>
#include <kenshi/WorldEventStateQuery.h>
#include <kenshi/ZoneManager.h>
#include <kenshi/gui/DataPanelLine.h>
#include <kenshi/gui/DatapanelGUI.h>
#include <kenshi/gui/DialogueWindow.h>
#include <kenshi/gui/FactionsScreen.h>
#include <kenshi/gui/ForgottenGUI.h>
#include <kenshi/gui/GUIWindow.h>
#include <kenshi/gui/InventoryGUI.h>
#include <kenshi/gui/MainBarGUI.h>
#include <kenshi/gui/ManagementScreen.h>
#include <kenshi/gui/MapScreen.h>
#include <kenshi/gui/NewGameOptionsWindow.h>
#include <kenshi/gui/OptionsWindow.h>
#include <kenshi/gui/OrdersPanel.h>
#include <kenshi/gui/ScreenLabel.h>
#include <kenshi/gui/SplashScreen.h>
#include <kenshi/gui/ToolTip.h>
#include <kenshi/util/UtilityT.h>
#include <kenshi/util/lektor.h>
#include <mygui/common/baselayout/BaseLayout.h>

#include <lua.hpp>

namespace KenshiLua
{
    // Shorthand metatable helpers
    static inline const char* ActivePlatoonMetatable()                              { return ActivePlatoonBinding::getMetatableName(); }
    static inline const char* AppearanceManagerMetatable()                          { return AppearanceManagerBinding::getMetatableName(); }
    static inline const char* ArmourMetatable()                                     { return ArmourBinding::getMetatableName(); }
    static inline const char* AttachedArrowManagerMetatable()                       { return AttachedArrowManagerBinding::getMetatableName(); }
    static inline const char* BaseLayoutMetatable()                                 { return BaseLayoutBinding::getMetatableName(); }
    static inline const char* BountyManagerMetatable()                              { return BountyManagerBinding::getMetatableName(); }
    static inline const char* BountyMetatable()                                     { return BountyBinding::getMetatableName(); }
    static inline const char* BuildingMetatable()                                   { return BuildingBinding::getMetatableName(); }
    static inline const char* BuildModeWindowMetatable()                            { return BuildModeWindowBinding::getMetatableName(); }
    static inline const char* CharacterAnimalMetatable()                            { return CharacterAnimalBinding::getMetatableName(); }
    static inline const char* CharacterHumanMetatable()                             { return CharacterHumanBinding::getMetatableName(); }
    static inline const char* CharacterMetatable()                                  { return CharacterBinding::getMetatableName(); }
    static inline const char* CharBodyMetatable()                                   { return CharBodyBinding::getMetatableName(); }
    static inline const char* CharMovementMetatable()                               { return CharMovementBinding::getMetatableName(); }
    static inline const char* CharStatsMetatable()                                  { return CharStatsBinding::getMetatableName(); }
    static inline const char* CombatClassMetatable()                                { return CombatClassBinding::getMetatableName(); }
    static inline const char* CombatMovementControllerMetatable()                   { return CombatMovementControllerBinding::getMetatableName(); }
    static inline const char* CombatTechniqueDataMetatable()                        { return CombatTechniqueDataBinding::getMetatableName(); }
    static inline const char* CraftingBuildingMetatable()                           { return CraftingBuildingBinding::getMetatableName(); }
    static inline const char* CrossbowMetatable()                                   { return CrossbowBinding::getMetatableName(); }
    static inline const char* DamagesMetatable()                                    { return DamagesBinding::getMetatableName(); }
    static inline const char* DataObjectContainerMetatable()                        { return DataObjectContainerBinding::getMetatableName(); }
    static inline const char* DataPanelLineButtonMetatable()                        { return DataPanelLine_ButtonBinding::getMetatableName(); }
    static inline const char* DataPanelLineMetatable()                              { return DataPanelLineBinding::getMetatableName(); }
    static inline const char* DialogLineDataMetatable()                             { return DialogLineDataBinding::getMetatableName(); }
    static inline const char* DialogueMetatable()                                   { return DialogueBinding::getMetatableName(); }
    static inline const char* DialogueWindowMetatable()                             { return DialogueWindowBinding::getMetatableName(); }
    static inline const char* DoorStuffMetatable()                                  { return DoorStuffBinding::getMetatableName(); }
    static inline const char* FactionLeaderMetatable()                              { return FactionLeaderBinding::getMetatableName(); }
    static inline const char* FactionManagerMetatable()                             { return FactionManagerBinding::getMetatableName(); }
    static inline const char* FactionMetatable()                                    { return FactionBinding::getMetatableName(); }
    static inline const char* FactionRelationsMetatable()                           { return FactionRelationsBinding::getMetatableName(); }
    static inline const char* FactionUniqueSquadManagerMetatable()                  { return FactionUniqueSquadManagerBinding::getMetatableName(); }
    static inline const char* FactionWarMgrMetatable()                              { return FactionWarMgrBinding::getMetatableName(); }
    static inline const char* FactionRelationsLineMetatable()                       { return FactionRelationsLineBinding::getMetatableName(); }
    static inline const char* FactionsScreenMetatable()                             { return FactionsScreenBinding::getMetatableName(); }
    static inline const char* FarmBuildingMetatable()                               { return FarmBuildingBinding::getMetatableName(); }
    static inline const char* FurnaceBuildingMetatable()                            { return FurnaceBuildingBinding::getMetatableName(); }
    static inline const char* GameDataCopyStandaloneMetatable()                     { return GameDataCopyStandaloneBinding::getMetatableName(); }
    static inline const char* GameDataMetatable()                                   { return GameDataBinding::getMetatableName(); }
    static inline const char* GameSaveStateMetatable()                              { return GameSaveStateBinding::getMetatableName(); }
    static inline const char* GameWorldMetatable()                                  { return GameWorldBinding::getMetatableName(); }
    static inline const char* GameplayOptionsMetatable()                            { return GameplayOptionsBinding::getMetatableName(); }
    static inline const char* GatewayBuildingMetatable()                            { return GatewayBuildingBinding::getMetatableName(); }
    static inline const char* GearMetatable()                                       { return GearBinding::getMetatableName(); }
    static inline const char* GeneratorBuildingMetatable()                          { return GeneratorBuildingBinding::getMetatableName(); }
    static inline const char* GenericFixedInventoryLayoutMetatable()                { return GenericFixedInventoryLayoutBinding::getMetatableName(); }
    static inline const char* BackpackInventoryLayoutMetatable()                    { return BackpackInventoryLayoutBinding::getMetatableName(); }
    static inline const char* ContainerItemMetatable()                              { return ContainerItemBinding::getMetatableName(); }
    static inline const char* HandMetatable()                                       { return HandBinding::getMetatableName(); }
    static inline const char* InputHandlerMetatable()                               { return InputHandlerBinding::getMetatableName(); }
    static inline const char* InventoryGUIMetatable()                               { return InventoryGUIBinding::getMetatableName(); }
    static inline const char* InventoryIconMetatable()                              { return InventoryIconBinding::getMetatableName(); }
    static inline const char* InventorySectionGUIMetatable()                        { return InventorySectionGUIBinding::getMetatableName(); }
    static inline const char* InventoryTradeDataMetatable()                         { return InventoryTradeDataBinding::getMetatableName(); }
    static inline const char* InventoryTradeResultMetatable()                       { return TradeResultBinding::getMetatableName(); }
    static inline const char* InventoryFenceCallbackDataMetatable()                 { return InventoryGUI_FenceCallbackDataBinding::getMetatableName(); }
    static inline const char* InventoryItemBaseMetatable()                          { return InventoryItemBaseBinding::getMetatableName(); }
    static inline const char* InventoryLayoutMetatable()                            { return InventoryLayoutBinding::getMetatableName(); }
    static inline const char* InventoryMetatable()                                  { return InventoryBinding::getMetatableName(); }
    static inline const char* InventorySectionMetatable()                           { return InventorySectionBinding::getMetatableName(); }
    static inline const char* ItemMetatable()                                       { return ItemBinding::getMetatableName(); }
    static inline const char* LightBuildingMetatable()                              { return LightBuildingBinding::getMetatableName(); }
    static inline const char* LimbsInventoryLayoutMetatable()                       { return LimbsInventoryLayoutBinding::getMetatableName(); }
    static inline const char* LockedArmourMetatable()                               { return LockedArmourBinding::getMetatableName(); }
    static inline const char* ContextMenuMetatable()                                { return ContextMenuBinding::getMetatableName(); }
    static inline const char* ContextMenuGUIMetatable()                             { return ContextMenuGUIBinding::getMetatableName(); }
    static inline const char* ManagementScreenMetatable()                           { return ManagementScreenBinding::getMetatableName(); }
    static inline const char* ManagementTechItemViewDataMetatable()                 { return ManagementScreen_TechItemViewDataBinding::getMetatableName(); }
    static inline const char* MapMarkerCharacterMetatable()                         { return MapMarkerCharacterBinding::getMetatableName(); }
    static inline const char* MapMarkerTownMetatable()                              { return MapMarkerTownBinding::getMetatableName(); }
    static inline const char* MapScreenMetatable()                                  { return MapScreenBinding::getMetatableName(); }
    static inline const char* MainBarGUIMetatable()                                 { return MainBarGUIBinding::getMetatableName(); }
    static inline const char* MainTabPortraitPlatoonMetatable()                     { return MainTabPortraitPlatoonBinding::getMetatableName(); }
    static inline const char* MedicalSystemMetatable()                              { return MedicalSystemBinding::getMetatableName(); }
    static inline const char* MyGuiWidgetMetatable()                                { return MyGUIBinding::getMetatableName(); }
    static inline const char* NewGameOptionsWindowMetatable()                       { return NewGameOptionsWindowBinding::getMetatableName(); }
    static inline const char* OrdersPanelMetatable()                                { return OrdersPanelBinding::getMetatableName(); }
    static inline const char* OrderCellViewMetatable()                              { return OrderCellViewBinding::getMetatableName(); }
    static inline const char* OrderDataMetatable()                                  { return OrderDataBinding::getMetatableName(); }
    static inline const char* OrdersItemBoxMetatable()                              { return OrdersItemBoxBinding::getMetatableName(); }
    static inline const char* OptionsWindowMetatable()                              { return OptionsWindowBinding::getMetatableName(); }
    static inline const char* OwnershipsMetatable()                                 { return OwnershipsBinding::getMetatableName(); }
    static inline const char* PlatoonMetatable()                                    { return PlatoonBinding::getMetatableName(); }
    static inline const char* PlayerInterfaceMetatable()                            { return PlayerInterfaceBinding::getMetatableName(); }
    static inline const char* PreviewBuildingMetatable()                            { return PreviewBuildingBinding::getMetatableName(); }
    static inline const char* ProductionBuildingMetatable()                         { return ProductionBuildingBinding::getMetatableName(); }
    static inline const char* ProsperityManagerMetatable()                          { return ProsperityManagerBinding::getMetatableName(); }
    static inline const char* RaceDataMetatable()                                   { return RaceDataBinding::getMetatableName(); }
    static inline const char* RainCollectorBuildingMetatable()                      { return RainCollectorBuildingBinding::getMetatableName(); }
    static inline const char* RendHitMetatable()                                    { return rendHitBinding::getMetatableName(); }
    static inline const char* ResearchBuildingMetatable()                           { return ResearchBuildingBinding::getMetatableName(); }
    static inline const char* RobotLimbsMetatable()                                 { return RobotLimbsBinding::getMetatableName(); }
    static inline const char* RootObjectBaseMetatable()                             { return RootObjectBaseBinding::getMetatableName(); }
    static inline const char* RootObjectFactoryMetatable()                          { return RootObjectFactoryBinding::getMetatableName(); }
    static inline const char* RootObjectContainerMetatable()                        { return RootObjectContainerBinding::getMetatableName(); }
    static inline const char* RootObjectMetatable()                                 { return RootObjectBinding::getMetatableName(); }
    static inline const char* ShopTraderMetatable()                                 { return ShopTraderBinding::getMetatableName(); }
    static inline const char* SquadManagementScreenMetatable()                      { return SquadManagementScreenBinding::getMetatableName(); }
    static inline const char* StorageBuildingMetatable()                            { return StorageBuildingBinding::getMetatableName(); }
    static inline const char* SplashScreenMetatable()                               { return SplashScreenBinding::getMetatableName(); }
    static inline const char* SwordMetatable()                                      { return SwordBinding::getMetatableName(); }
    static inline const char* TaskerMetatable()                                     { return TaskerBinding::getMetatableName(); }
    static inline const char* TitleScreenMetatable()                                { return TitleScreenBinding::getMetatableName(); }
    static inline const char* TortureBuildingMetatable()                            { return TortureBuildingBinding::getMetatableName(); }
    static inline const char* TownBaseMetatable()                                   { return TownBaseBinding::getMetatableName(); }
    static inline const char* TownMetatable()                                       { return TownBinding::getMetatableName(); }
    static inline const char* TurretBuildingMetatable()                             { return TurretBuildingBinding::getMetatableName(); }
    static inline const char* UseableStuffMetatable()                               { return UseableStuffBinding::getMetatableName(); }
    static inline const char* WallBuildingMetatable()                               { return WallBuildingBinding::getMetatableName(); }
    static inline const char* WeaponMetatable()                                     { return WeaponBinding::getMetatableName(); }
    static inline const char* WindGeneratorBuildingMetatable()                      { return WindGeneratorBuildingBinding::getMetatableName(); }
    static inline const char* WorldEventStateQueryMetatable()                       { return WorldEventStateQueryBinding::getMetatableName(); }
    static inline const char* ZoneManagerMetatable()                                { return ZoneManagerBinding::getMetatableName(); }
    static inline const char* ZoneMapMetatable()                                    { return ZoneMapBinding::getMetatableName(); }

    // Metatables for the GUI hook events (GUIWindow, CharacterStatsWindow, DatapanelGUI, DataPanelLine, ForgottenGUI)
    static inline const char* CharacterStatsWindowMetatable()                       { return CharacterStatsWindowBinding::getMetatableName(); }
    static inline const char* CharacterStatsWindowStatGroupMetatable()              { return StatGroupBinding::getMetatableName(); }
    static inline const char* CharacterStatsWindowStatMetatable()                   { return StatBinding::getMetatableName(); }
    static inline const char* DataPanelLineCheckBoxMetatable()                      { return DataPanelLine_CheckBoxBinding::getMetatableName(); }
    static inline const char* DataPanelLineDropBoxMetatable()                       { return DataPanelLine_DropBoxBinding::getMetatableName(); }
    static inline const char* DataPanelLineFactionMetatable()                       { return DataPanelLine_FactionBinding::getMetatableName(); }
    static inline const char* DataPanelLineKeyConfigMetatable()                     { return DataPanelLine_KeyConfigBinding::getMetatableName(); }
    static inline const char* DataPanelLineProgressMetatable()                      { return DataPanelLine_ProgressBinding::getMetatableName(); }
    static inline const char* DataPanelLineResearchMetatable()                      { return DataPanelLine_ResearchBinding::getMetatableName(); }
    static inline const char* DataPanelLineSliderEditableMetatable()                { return DataPanelLine_SliderEditableBinding::getMetatableName(); }
    static inline const char* DataPanelLineSliderMetatable()                        { return DataPanelLine_SliderBinding::getMetatableName(); }
    static inline const char* DataPanelLineTextEditableMetatable()                  { return DataPanelLine_TextEditableBinding::getMetatableName(); }
    static inline const char* DataPanelLineTextMetatable()                          { return DataPanelLine_TextBinding::getMetatableName(); }
    static inline const char* DatapanelGUIMetatable()                               { return DatapanelGUIBinding::getMetatableName(); }
    static inline const char* FloatingProgressBarMetatable()                        { return FloatingProgressBarBinding::getMetatableName(); }
    static inline const char* ForgottenGUIMetatable()                               { return ForgottenGUIBinding::getMetatableName(); }
    static inline const char* GUIWindowMetatable()                                  { return GUIWindowBinding::getMetatableName(); }
    static inline const char* ScreenLabelDebugMetatable()                           { return ScreenLabelDebugBinding::getMetatableName(); }
    static inline const char* ScreenLabelInterfaceMetatable()                       { return ScreenLabelInterfaceBinding::getMetatableName(); }
    static inline const char* ScreenLabelMetatable()                                { return ScreenLabelBinding::getMetatableName(); }
    static inline const char* ToolTipMetatable()                                    { return ToolTipBinding::getMetatableName(); }

    // pushArg overloads for primitive types
    static inline void pushArg(lua_State* L, bool val)                              { lua_pushboolean(L, val ? 1 : 0); }
    static inline void pushArg(lua_State* L, const std::string& val)                { lua_pushstring(L, val.c_str()); }
    static inline void pushArg(lua_State* L, float val)                             { lua_pushnumber(L, val); }
    static inline void pushArg(lua_State* L, double val)                            { lua_pushnumber(L, val); }
    static inline void pushArg(lua_State* L, int val)                               { lua_pushinteger(L, val); }

    // pushArg overloads for bound classes      
    static inline void pushArg(lua_State* L, ActivePlatoon* val)                    { pushObject<ActivePlatoon>(L, val, ActivePlatoonMetatable()); }
    static inline void pushArg(lua_State* L, AppearanceManager* val)                { pushObject<AppearanceManager>(L, val, AppearanceManagerMetatable()); }
    static inline void pushArg(lua_State* L, Armour* val)                           { pushObject<Armour>(L, val, ArmourMetatable()); }
    static inline void pushArg(lua_State* L, Bounty* val)                           { pushObject<Bounty>(L, val, BountyMetatable()); }
    static inline void pushArg(lua_State* L, BountyManager* val)                    { pushObject<BountyManager>(L, val, BountyManagerMetatable()); }
    static inline void pushArg(lua_State* L, Building* val)                         { pushObject<Building>(L, val, BuildingMetatable()); }
    static inline void pushArg(lua_State* L, BuildModeWindow* val)                  { pushObject<BuildModeWindow>(L, val, BuildModeWindowMetatable()); }
    static inline void pushArg(lua_State* L, Character* val)                        { pushObject<Character>(L, val, CharacterMetatable()); }
    static inline void pushArg(lua_State* L, Character::AttachedArrowManager* val)  { pushObject<Character::AttachedArrowManager>(L, val, AttachedArrowManagerMetatable()); }
    static inline void pushArg(lua_State* L, CharacterAnimal* val)                  { pushObject<CharacterAnimal>(L, val, CharacterAnimalMetatable()); }
    static inline void pushArg(lua_State* L, CharacterHuman* val)                   { pushObject<CharacterHuman>(L, val, CharacterHumanMetatable()); }
    static inline void pushArg(lua_State* L, CharBody* val)                         { pushObject<CharBody>(L, val, CharBodyMetatable()); }
    static inline void pushArg(lua_State* L, CharStats* val)                        { pushObject<CharStats>(L, val, CharStatsMetatable()); }
    static inline void pushArg(lua_State* L, CombatClass* val)                      { pushObject<CombatClass>(L, val, CombatClassMetatable()); }
    static inline void pushArg(lua_State* L, CombatMovementController* val)         { pushObject<CombatMovementController>(L, val, CombatMovementControllerMetatable()); }
    static inline void pushArg(lua_State* L, CombatTechniqueData* val)              { pushObject<CombatTechniqueData>(L, val, CombatTechniqueDataMetatable()); }
    static inline void pushArg(lua_State* L, ContextMenu* val)                      { pushObject<ContextMenu>(L, val, ContextMenuMetatable()); }
    static inline void pushArg(lua_State* L, ContextMenuGUI* val)                   { pushObject<ContextMenuGUI>(L, val, ContextMenuGUIMetatable()); }
    static inline void pushArg(lua_State* L, const Building* val)                   { pushObject<Building>(L, const_cast<Building*>(val), BuildingMetatable()); }
    static inline void pushArg(lua_State* L, const CharacterAnimal* val)            { pushObject<CharacterAnimal>(L, const_cast<CharacterAnimal*>(val), CharacterAnimalMetatable()); }
    static inline void pushArg(lua_State* L, const CharStats* val)                { pushObject<CharStats>(L, const_cast<CharStats*>(val), CharStatsMetatable()); }
    static inline void pushArg(lua_State* L, const hand& val)                       { HandBinding::push(L, val); }
    static inline void pushArg(lua_State* L, const lektor<int>& val)                { LektorIntBinding<int>::push(L, const_cast<lektor<int>*>(&val)); }
    static inline void pushArg(lua_State* L, const InventoryItemBase* val)          { pushObject<InventoryItemBase>(L, const_cast<InventoryItemBase*>(val), InventoryItemBaseMetatable()); }
    static inline void pushArg(lua_State* L, const rendHit& val)                    { pushObject<rendHit>(L, const_cast<rendHit*>(&val), RendHitMetatable()); }
    static inline void pushArg(lua_State* L, const UseableStuff* val)               { pushObject<UseableStuff>(L, const_cast<UseableStuff*>(val), UseableStuffMetatable()); }
    static inline void pushArg(lua_State* L, CraftingBuilding* val)                 { pushObject<CraftingBuilding>(L, val, CraftingBuildingMetatable()); }
    static inline void pushArg(lua_State* L, Crossbow* val)                         { pushObject<Crossbow>(L, val, CrossbowMetatable()); }
    static inline void pushArg(lua_State* L, Damages* val)                          { pushObject<Damages>(L, val, DamagesMetatable()); }
    static inline void pushArg(lua_State* L, DataObjectContainer* val)              { pushObject<DataObjectContainer>(L, val, DataObjectContainerMetatable()); }
    static inline void pushArg(lua_State* L, DataPanelLine* val)                    { pushObject<DataPanelLine>(L, val, DataPanelLineMetatable()); }
    static inline void pushArg(lua_State* L, DataPanelLine_Button* val)             { pushObject<DataPanelLine_Button>(L, val, DataPanelLineButtonMetatable()); }
    static inline void pushArg(lua_State* L, DialogLineData* val)                   { pushObject<DialogLineData>(L, val, DialogLineDataMetatable()); }
    static inline void pushArg(lua_State* L, Dialogue* val)                         { pushObject<Dialogue>(L, val, DialogueMetatable()); }
    static inline void pushArg(lua_State* L, DialogueWindow* val)                   { pushObject<DialogueWindow>(L, val, DialogueWindowMetatable()); }
    static inline void pushArg(lua_State* L, DoorStuff* val)                        { pushObject<DoorStuff>(L, val, DoorStuffMetatable()); }
    static inline void pushArg(lua_State* L, Faction* val)                          { pushObject<Faction>(L, val, FactionMetatable()); }
    static inline void pushArg(lua_State* L, FactionLeader* val)                    { pushObject<FactionLeader>(L, val, FactionLeaderMetatable()); }
    static inline void pushArg(lua_State* L, FactionManager* val)                   { pushObject<FactionManager>(L, val, FactionManagerMetatable()); }
    static inline void pushArg(lua_State* L, FactionRelations* val)                 { pushObject<FactionRelations>(L, val, FactionRelationsMetatable()); }
    static inline void pushArg(lua_State* L, FactionUniqueSquadManager* val)        { pushObject<FactionUniqueSquadManager>(L, val, FactionUniqueSquadManagerMetatable()); }
    static inline void pushArg(lua_State* L, FactionWarMgr* val)                    { pushObject<FactionWarMgr>(L, val, FactionWarMgrMetatable()); }
    static inline void pushArg(lua_State* L, FactionsScreen::FactionRelationsLine* val) { pushObject<FactionsScreen::FactionRelationsLine>(L, val, FactionRelationsLineMetatable()); }
    static inline void pushArg(lua_State* L, FactionsScreen* val)                   { pushObject<FactionsScreen>(L, val, FactionsScreenMetatable()); }
    static inline void pushArg(lua_State* L, FarmBuilding* val)                     { pushObject<FarmBuilding>(L, val, FarmBuildingMetatable()); }
    static inline void pushArg(lua_State* L, FurnaceBuilding* val)                  { pushObject<FurnaceBuilding>(L, val, FurnaceBuildingMetatable()); }
    static inline void pushArg(lua_State* L, GameDataCopyStandalone* val)           { pushObject<GameDataCopyStandalone>(L, val, GameDataCopyStandaloneMetatable()); }
    static inline void pushArg(lua_State* L, GameSaveState* val)                    { pushObject<GameSaveState>(L, val, GameSaveStateMetatable()); }
    static inline void pushArg(lua_State* L, GameData* val)                     { pushObject<GameData>(L, val, GameDataMetatable()); }
    static inline void pushArg(lua_State* L, GameWorld* val)                        { pushObject<GameWorld>(L, val, GameWorldMetatable()); }
    static inline void pushArg(lua_State* L, const GameplayOptions* val)             { pushObject<GameplayOptions>(L, const_cast<GameplayOptions*>(val), GameplayOptionsMetatable()); }
    static inline void pushArg(lua_State* L, GatewayBuilding* val)                  { pushObject<GatewayBuilding>(L, val, GatewayBuildingMetatable()); }
    static inline void pushArg(lua_State* L, Gear* val)                             { pushObject<Gear>(L, val, GearMetatable()); }
    static inline void pushArg(lua_State* L, GeneratorBuilding* val)                { pushObject<GeneratorBuilding>(L, val, GeneratorBuildingMetatable()); }
    static inline void pushArg(lua_State* L, GenericFixedInventoryLayout* val)      { pushObject<GenericFixedInventoryLayout>(L, val, GenericFixedInventoryLayoutMetatable()); }
    static inline void pushArg(lua_State* L, BackpackInventoryLayout* val)          { pushObject<BackpackInventoryLayout>(L, val, BackpackInventoryLayoutMetatable()); }
    static inline void pushArg(lua_State* L, ContainerItem* val)                    { pushObject<ContainerItem>(L, val, ContainerItemMetatable()); }
    static inline void pushArg(lua_State* L, InputHandler* val)                     { pushObject<InputHandler>(L, val, InputHandlerMetatable()); }
    static inline void pushArg(lua_State* L, Inventory* val)                        { pushObject<Inventory>(L, val, InventoryMetatable()); }
    static inline void pushArg(lua_State* L, InventoryGUI* val)                     { pushObject<InventoryGUI>(L, val, InventoryGUIMetatable()); }
    static inline void pushArg(lua_State* L, InventoryIcon* val)                    { pushObject<InventoryIcon>(L, val, InventoryIconMetatable()); }
    static inline void pushArg(lua_State* L, InventorySectionGUI* val)              { pushObject<InventorySectionGUI>(L, val, InventorySectionGUIMetatable()); }
    static inline void pushArg(lua_State* L, InventoryGUI::InventoryTradeData* val) { pushObject<InventoryGUI::InventoryTradeData>(L, val, InventoryTradeDataMetatable()); }
    static inline void pushArg(lua_State* L, InventoryGUI::TradeResult* val)        { pushObject<InventoryGUI::TradeResult>(L, val, InventoryTradeResultMetatable()); }
    static inline void pushArg(lua_State* L, const InventoryGUI::TradeResult& val)  { pushValue<InventoryGUI::TradeResult>(L, val, InventoryTradeResultMetatable()); }
    static inline void pushArg(lua_State* L, InventoryGUI::FenceCallbackData* val)  { pushObject<InventoryGUI::FenceCallbackData>(L, val, InventoryFenceCallbackDataMetatable()); }
    static inline void pushArg(lua_State* L, InventoryLayout* val)                  { pushObject<InventoryLayout>(L, val, InventoryLayoutMetatable()); }
    static inline void pushArg(lua_State* L, Item* val)                             { pushObject<Item>(L, val, ItemMetatable()); }
    static inline void pushArg(lua_State* L, lektor<GameData*>& val)                { pushObject<lektor<GameData*>>(L, &val, LektorPtrBinding<GameData*>::metaName); }
    static inline void pushArg(lua_State* L, LightBuilding* val)                    { pushObject<LightBuilding>(L, val, LightBuildingMetatable()); }
    static inline void pushArg(lua_State* L, LimbsInventoryLayout* val)             { pushObject<LimbsInventoryLayout>(L, val, LimbsInventoryLayoutMetatable()); }
    static inline void pushArg(lua_State* L, LockedArmour* val)                     { pushObject<LockedArmour>(L, val, LockedArmourMetatable()); }
    static inline void pushArg(lua_State* L, ManagementScreen* val)                 { pushObject<ManagementScreen>(L, val, ManagementScreenMetatable()); }
    static inline void pushArg(lua_State* L, ManagementScreen::TechItemViewData* val) { pushObject<ManagementScreen::TechItemViewData>(L, val, ManagementTechItemViewDataMetatable()); }
    static inline void pushArg(lua_State* L, const ManagementScreen::TechItemViewData& val) { pushValue<ManagementScreen::TechItemViewData>(L, val, ManagementTechItemViewDataMetatable()); }
    static inline void pushArg(lua_State* L, MapScreen* val)                        { pushObject<MapScreen>(L, val, MapScreenMetatable()); }
    static inline void pushArg(lua_State* L, MapScreen::MapMarkerTown* val)         { pushObject<MapScreen::MapMarkerTown>(L, val, MapMarkerTownMetatable()); }
    static inline void pushArg(lua_State* L, MapScreen::MapMarkerCharacter* val)    { pushObject<MapScreen::MapMarkerCharacter>(L, val, MapMarkerCharacterMetatable()); }
    static inline void pushArg(lua_State* L, MainBarGUI* val)                       { pushObject<MainBarGUI>(L, val, MainBarGUIMetatable()); }
    static inline void pushArg(lua_State* L, MainTabPortraitPlatoon* val)           { pushObject<MainTabPortraitPlatoon>(L, val, MainTabPortraitPlatoonMetatable()); }
    static inline void pushArg(lua_State* L, MedicalSystem* val)                    { pushObject<MedicalSystem>(L, val, MedicalSystemMetatable()); }
    static inline void pushArg(lua_State* L, NewGameOptionsWindow* val)             { pushObject<NewGameOptionsWindow>(L, val, NewGameOptionsWindowMetatable()); }
    static inline void pushArg(lua_State* L, OrdersPanel* val)                      { pushObject<OrdersPanel>(L, val, OrdersPanelMetatable()); }
    static inline void pushArg(lua_State* L, OrderCellView* val)                    { pushObject<OrderCellView>(L, val, OrderCellViewMetatable()); }
    static inline void pushArg(lua_State* L, OrderData* val)                        { pushObject<OrderData>(L, val, OrderDataMetatable()); }
    static inline void pushArg(lua_State* L, OrdersItemBox* val)                    { pushObject<OrdersItemBox>(L, val, OrdersItemBoxMetatable()); }
    static inline void pushArg(lua_State* L, OptionsWindow* val)                    { pushObject<OptionsWindow>(L, val, OptionsWindowMetatable()); }
    static inline void pushArg(lua_State* L, Ownerships* val)                       { pushObject<Ownerships>(L, val, OwnershipsMetatable()); }
    static inline void pushArg(lua_State* L, Platoon* val)                          { pushObject<Platoon>(L, val, PlatoonMetatable()); }
    static inline void pushArg(lua_State* L, PlayerInterface* val)                  { pushObject<PlayerInterface>(L, val, PlayerInterfaceMetatable()); }
    static inline void pushArg(lua_State* L, PreviewBuilding* val)                  { pushObject<PreviewBuilding>(L, val, PreviewBuildingMetatable()); }
    static inline void pushArg(lua_State* L, ProductionBuilding* val)               { pushObject<ProductionBuilding>(L, val, ProductionBuildingMetatable()); }
    static inline void pushArg(lua_State* L, ProsperityManager* val)                { pushObject<ProsperityManager>(L, val, ProsperityManagerMetatable()); }
    static inline void pushArg(lua_State* L, RaceData* val)                         { pushObject<RaceData>(L, val, RaceDataMetatable()); }
    static inline void pushArg(lua_State* L, RainCollectorBuilding* val)            { pushObject<RainCollectorBuilding>(L, val, RainCollectorBuildingMetatable()); }
    static inline void pushArg(lua_State* L, rendHit* val)                          { pushObject<rendHit>(L, val, RendHitMetatable()); }
    static inline void pushArg(lua_State* L, ResearchBuilding* val)                 { pushObject<ResearchBuilding>(L, val, ResearchBuildingMetatable()); }
    static inline void pushArg(lua_State* L, RobotLimbs* val)                       { pushObject<RobotLimbs>(L, val, RobotLimbsMetatable()); }
    static inline void pushArg(lua_State* L, RootObject* val)                       { pushObject<RootObject>(L, val, RootObjectMetatable()); }
    static inline void pushArg(lua_State* L, RootObjectBase* val)                   { pushObject<RootObjectBase>(L, val, RootObjectBaseMetatable()); }
    static inline void pushArg(lua_State* L, RootObjectFactory* val)                { pushObject<RootObjectFactory>(L, val, RootObjectFactoryMetatable()); }
    static inline void pushArg(lua_State* L, RootObjectContainer* val)              { pushObject<RootObjectContainer>(L, val, RootObjectContainerMetatable()); }
    static inline void pushArg(lua_State* L, ShopTrader* val)                       { pushObject<ShopTrader>(L, val, ShopTraderMetatable()); }
    static inline void pushArg(lua_State* L, SquadManagementScreen* val)            { pushObject<SquadManagementScreen>(L, val, SquadManagementScreenMetatable()); }
    static inline void pushArg(lua_State* L, StorageBuilding* val)                  { pushObject<StorageBuilding>(L, val, StorageBuildingMetatable()); }
    static inline void pushArg(lua_State* L, SplashScreen* val)                     { pushObject<SplashScreen>(L, val, SplashScreenMetatable()); }
    static inline void pushArg(lua_State* L, Sword* val)                            { pushObject<Sword>(L, val, SwordMetatable()); }
    static inline void pushArg(lua_State* L, Tasker* val)                           { pushObject<Tasker>(L, val, TaskerMetatable()); }
    static inline void pushArg(lua_State* L, TitleScreen* val)                      { pushObject<TitleScreen>(L, val, TitleScreenMetatable()); }
    static inline void pushArg(lua_State* L, TortureBuilding* val)                  { pushObject<TortureBuilding>(L, val, TortureBuildingMetatable()); }
    static inline void pushArg(lua_State* L, Town* val)                             { pushObject<Town>(L, val, TownMetatable()); }
    static inline void pushArg(lua_State* L, TownBase* val)                         { pushObject<TownBase>(L, val, TownBaseMetatable()); }
    static inline void pushArg(lua_State* L, TurretBuilding* val)                   { pushObject<TurretBuilding>(L, val, TurretBuildingMetatable()); }
    static inline void pushArg(lua_State* L, UseableStuff* val)                     { pushObject<UseableStuff>(L, val, UseableStuffMetatable()); }
    static inline void pushArg(lua_State* L, WallBuilding* val)                     { pushObject<WallBuilding>(L, val, WallBuildingMetatable()); }
    static inline void pushArg(lua_State* L, Weapon* val)                           { pushObject<Weapon>(L, val, WeaponMetatable()); }
    static inline void pushArg(lua_State* L, WindGeneratorBuilding* val)            { pushObject<WindGeneratorBuilding>(L, val, WindGeneratorBuildingMetatable()); }
    static inline void pushArg(lua_State* L, WorldEventStateQuery* val)             { pushObject<WorldEventStateQuery>(L, val, WorldEventStateQueryMetatable()); }
    static inline void pushArg(lua_State* L, YesNoMaybe val)                        { lua_pushinteger(L, static_cast<int>(val.key)); }
    static inline void pushArg(lua_State* L, ZoneManager* val)                      { pushObject<ZoneManager>(L, val, ZoneManagerMetatable()); }
    static inline void pushArg(lua_State* L, ZoneMap* val)                          { pushObject<ZoneMap>(L, val, ZoneMapMetatable()); }

    // pushArg overloads for the GUI hook events
    static inline void pushArg(lua_State* L, CharacterStatsWindow* val)             { pushObject<CharacterStatsWindow>(L, val, CharacterStatsWindowMetatable()); }
    static inline void pushArg(lua_State* L, CharacterStatsWindow::Stat* val)       { pushObject<CharacterStatsWindow::Stat>(L, val, CharacterStatsWindowStatMetatable()); }
    static inline void pushArg(lua_State* L, CharacterStatsWindow::StatGroup* val)  { pushObject<CharacterStatsWindow::StatGroup>(L, val, CharacterStatsWindowStatGroupMetatable()); }
    static inline void pushArg(lua_State* L, const lektor<Character*>& val)         { LektorPtrBinding<Character*>::push(L, const_cast<lektor<Character*>*>(&val)); }
    static inline void pushArg(lua_State* L, const lektor<StringPair>& val)         { LektorValueBinding<StringPair>::push(L, const_cast<lektor<StringPair>*>(&val)); }
    static inline void pushArg(lua_State* L, const Ogre::vector<GameDataReference>::type* val) { pushObject<Ogre::vector<GameDataReference>::type>(L, const_cast<Ogre::vector<GameDataReference>::type*>(val), "ogre_vector<GameDataReference>"); }
    static inline void pushArg(lua_State* L, DataPanelLine_CheckBox* val)           { pushObject<DataPanelLine_CheckBox>(L, val, DataPanelLineCheckBoxMetatable()); }
    static inline void pushArg(lua_State* L, DataPanelLine_DropBox* val)            { pushObject<DataPanelLine_DropBox>(L, val, DataPanelLineDropBoxMetatable()); }
    static inline void pushArg(lua_State* L, DataPanelLine_Faction* val)            { pushObject<DataPanelLine_Faction>(L, val, DataPanelLineFactionMetatable()); }
    static inline void pushArg(lua_State* L, DataPanelLine_KeyConfig* val)          { pushObject<DataPanelLine_KeyConfig>(L, val, DataPanelLineKeyConfigMetatable()); }
    static inline void pushArg(lua_State* L, DataPanelLine_Progress* val)           { pushObject<DataPanelLine_Progress>(L, val, DataPanelLineProgressMetatable()); }
    static inline void pushArg(lua_State* L, DataPanelLine_Research* val)           { pushObject<DataPanelLine_Research>(L, val, DataPanelLineResearchMetatable()); }
    static inline void pushArg(lua_State* L, DataPanelLine_Slider* val)             { pushObject<DataPanelLine_Slider>(L, val, DataPanelLineSliderMetatable()); }
    static inline void pushArg(lua_State* L, DataPanelLine_SliderEditable* val)     { pushObject<DataPanelLine_SliderEditable>(L, val, DataPanelLineSliderEditableMetatable()); }
    static inline void pushArg(lua_State* L, DataPanelLine_Text* val)               { pushObject<DataPanelLine_Text>(L, val, DataPanelLineTextMetatable()); }
    static inline void pushArg(lua_State* L, DataPanelLine_TextEditable* val)       { pushObject<DataPanelLine_TextEditable>(L, val, DataPanelLineTextEditableMetatable()); }
    static inline void pushArg(lua_State* L, DatapanelGUI* val)                     { pushObject<DatapanelGUI>(L, val, DatapanelGUIMetatable()); }
    static inline void pushArg(lua_State* L, FloatingProgressBar* val)              { pushObject<FloatingProgressBar>(L, val, FloatingProgressBarMetatable()); }
    static inline void pushArg(lua_State* L, ForgottenGUI* val)                     { pushObject<ForgottenGUI>(L, val, ForgottenGUIMetatable()); }
    static inline void pushArg(lua_State* L, GUIWindow* val)                        { pushObject<GUIWindow>(L, val, GUIWindowMetatable()); }
    static inline void pushArg(lua_State* L, ScreenLabel* val)                      { pushObject<ScreenLabel>(L, val, ScreenLabelMetatable()); }
    static inline void pushArg(lua_State* L, ScreenLabelDebug* val)                 { pushObject<ScreenLabelDebug>(L, val, ScreenLabelDebugMetatable()); }
    static inline void pushArg(lua_State* L, ScreenLabelInterface* val)             { pushObject<ScreenLabelInterface>(L, val, ScreenLabelInterfaceMetatable()); }
    static inline void pushArg(lua_State* L, ToolTip* val)                          { pushObject<ToolTip>(L, val, ToolTipMetatable()); }

	// pushArg overloads for MyGUI types
    static inline void pushArg(lua_State* L, MyGUI::Widget* val)                    { pushObject<MyGUI::Widget>(L, val, MyGuiWidgetMetatable()); }
    static inline void pushArg(lua_State* L, wraps::BaseLayout* val)                { pushObject<wraps::BaseLayout>(L, val, BaseLayoutMetatable()); }
    static inline void pushArg(lua_State* L, MyGUI::Gui* val)                       { pushObject<MyGUI::Gui>(L, val, GuiBinding::getMetatableName()); }
    static inline void pushArg(lua_State* L, const MyGUI::Colour& val)              { pushValue<MyGUI::Colour>(L, val, ColourBinding::getMetatableName()); }
    static inline void pushArg(lua_State* L, const MyGUI::IntCoord& val)            { pushValue<MyGUI::IntCoord>(L, val, IntCoordBinding::getMetatableName()); }
    static inline void pushArg(lua_State* L, const MyGUI::IntPoint& val)            { pushValue<MyGUI::IntPoint>(L, val, IntPointBinding::getMetatableName()); }
    static inline void pushArg(lua_State* L, const MyGUI::IntSize& val)             { pushValue<MyGUI::IntSize>(L, val, IntSizeBinding::getMetatableName()); }
    static inline void pushArg(lua_State* L, const iVector2& val)                   { pushValue<iVector2>(L, val, iVector2Binding::getMetatableName()); }

    // A widget argument pushed with the metatable of its runtime MyGUI type.
    // The plain MyGUI::Widget* overload above keeps the base metatable for
    // existing events.
    struct WidgetArg
    {
        MyGUI::Widget* widget;
        WidgetArg(MyGUI::Widget* w) : widget(w) {}
    };
    static inline void pushArg(lua_State* L, const WidgetArg& val)                  { MyGUIBindings::pushWidget(L, val.widget); }

	// pushArg overloads for Ogre types
    static inline void pushArg(lua_State* L, const Ogre::Quaternion& val)           { pushQuaternion(L, val); }
    static inline void pushArg(lua_State* L, const Ogre::Vector3& val)              { pushVector3(L, val); }

	// pushArg overloads for raw pointers (lightuserdata)
    static inline void pushArg(lua_State* L, Layout* val)                           { lua_pushlightuserdata(L, val); }
    static inline void pushArg(lua_State* L, void* val)                             { lua_pushlightuserdata(L, val); }




    // pullArg — reads a (possibly Lua-edited) value back off the stack.
    // No pointer/object overloads on purpose; see IParamsFilter comment.
    static inline void pullArg(lua_State* L, int idx, bool& out)                    { if (lua_isboolean(L, idx)) out = lua_toboolean(L, idx) != 0; }
    static inline void pullArg(lua_State* L, int idx, float& out)                   { if (lua_isnumber(L, idx))  out = (float)lua_tonumber(L, idx); }
    static inline void pullArg(lua_State* L, int idx, int& out)                     { if (lua_isnumber(L, idx))  out = (int)lua_tointeger(L, idx); }
    static inline void pullArg(lua_State* L, int idx, std::string& out)             { if (lua_isstring(L, idx))  out = lua_tostring(L, idx); }
}

namespace {

    template <typename T1>
    struct ArgPusher1 : public KenshiLua::IArgPusher {
        T1 a1;
        ArgPusher1(T1 _1) : a1(_1) {}
        int push(lua_State* L) const {
            KenshiLua::pushArg(L, a1);
            return 1;
        }
    };

    template <typename T1, typename T2>
    struct ArgPusher2 : public KenshiLua::IArgPusher {
        T1 a1; T2 a2;
        ArgPusher2(T1 _1, T2 _2) : a1(_1), a2(_2) {}
        int push(lua_State* L) const {
            KenshiLua::pushArg(L, a1);
            KenshiLua::pushArg(L, a2);
            return 2;
        }
    };

    template <typename T1, typename T2, typename T3>
    struct ArgPusher3 : public KenshiLua::IArgPusher {
        T1 a1; T2 a2; T3 a3;
        ArgPusher3(T1 _1, T2 _2, T3 _3) : a1(_1), a2(_2), a3(_3) {}
        int push(lua_State* L) const {
            KenshiLua::pushArg(L, a1);
            KenshiLua::pushArg(L, a2);
            KenshiLua::pushArg(L, a3);
            return 3;
        }
    };

    template <typename T1, typename T2, typename T3, typename T4>
    struct ArgPusher4 : public KenshiLua::IArgPusher {
        T1 a1; T2 a2; T3 a3; T4 a4;
        ArgPusher4(T1 _1, T2 _2, T3 _3, T4 _4) : a1(_1), a2(_2), a3(_3), a4(_4) {}
        int push(lua_State* L) const {
            KenshiLua::pushArg(L, a1);
            KenshiLua::pushArg(L, a2);
            KenshiLua::pushArg(L, a3);
            KenshiLua::pushArg(L, a4);
            return 4;
        }
    };

    template <typename T1, typename T2, typename T3, typename T4, typename T5>
    struct ArgPusher5 : public KenshiLua::IArgPusher {
        T1 a1; T2 a2; T3 a3; T4 a4; T5 a5;
        ArgPusher5(T1 _1, T2 _2, T3 _3, T4 _4, T5 _5) : a1(_1), a2(_2), a3(_3), a4(_4), a5(_5) {}
        int push(lua_State* L) const {
            KenshiLua::pushArg(L, a1);
            KenshiLua::pushArg(L, a2);
            KenshiLua::pushArg(L, a3);
            KenshiLua::pushArg(L, a4);
            KenshiLua::pushArg(L, a5);
            return 5;
        }
    };

    template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    struct ArgPusher6 : public KenshiLua::IArgPusher {
        T1 a1; T2 a2; T3 a3; T4 a4; T5 a5; T6 a6;
        ArgPusher6(T1 _1, T2 _2, T3 _3, T4 _4, T5 _5, T6 _6) : a1(_1), a2(_2), a3(_3), a4(_4), a5(_5), a6(_6) {}
        int push(lua_State* L) const {
            KenshiLua::pushArg(L, a1);
            KenshiLua::pushArg(L, a2);
            KenshiLua::pushArg(L, a3);
            KenshiLua::pushArg(L, a4);
            KenshiLua::pushArg(L, a5);
            KenshiLua::pushArg(L, a6);
            return 6;
        }
    };

    template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    struct ArgPusher7 : public KenshiLua::IArgPusher {
        T1 a1; T2 a2; T3 a3; T4 a4; T5 a5; T6 a6; T7 a7;
        ArgPusher7(T1 _1, T2 _2, T3 _3, T4 _4, T5 _5, T6 _6, T7 _7) : a1(_1), a2(_2), a3(_3), a4(_4), a5(_5), a6(_6), a7(_7) {}
        int push(lua_State* L) const {
            KenshiLua::pushArg(L, a1);
            KenshiLua::pushArg(L, a2);
            KenshiLua::pushArg(L, a3);
            KenshiLua::pushArg(L, a4);
            KenshiLua::pushArg(L, a5);
            KenshiLua::pushArg(L, a6);
            KenshiLua::pushArg(L, a7);
            return 7;
        }
    };

    template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
    struct ArgPusher8 : public KenshiLua::IArgPusher {
        T1 a1; T2 a2; T3 a3; T4 a4; T5 a5; T6 a6; T7 a7; T8 a8;
        ArgPusher8(T1 _1, T2 _2, T3 _3, T4 _4, T5 _5, T6 _6, T7 _7, T8 _8) : a1(_1), a2(_2), a3(_3), a4(_4), a5(_5), a6(_6), a7(_7), a8(_8) {}
        int push(lua_State* L) const {
            KenshiLua::pushArg(L, a1);
            KenshiLua::pushArg(L, a2);
            KenshiLua::pushArg(L, a3);
            KenshiLua::pushArg(L, a4);
            KenshiLua::pushArg(L, a5);
            KenshiLua::pushArg(L, a6);
            KenshiLua::pushArg(L, a7);
            KenshiLua::pushArg(L, a8);
            return 8;
        }
    };

    template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
    struct ArgPusher9 : public KenshiLua::IArgPusher {
        T1 a1; T2 a2; T3 a3; T4 a4; T5 a5; T6 a6; T7 a7; T8 a8; T9 a9;
        ArgPusher9(T1 _1, T2 _2, T3 _3, T4 _4, T5 _5, T6 _6, T7 _7, T8 _8, T9 _9) : a1(_1), a2(_2), a3(_3), a4(_4), a5(_5), a6(_6), a7(_7), a8(_8), a9(_9) {}
        int push(lua_State* L) const {
            KenshiLua::pushArg(L, a1);
            KenshiLua::pushArg(L, a2);
            KenshiLua::pushArg(L, a3);
            KenshiLua::pushArg(L, a4);
            KenshiLua::pushArg(L, a5);
            KenshiLua::pushArg(L, a6);
            KenshiLua::pushArg(L, a7);
            KenshiLua::pushArg(L, a8);
            KenshiLua::pushArg(L, a9);
            return 9;
        }
    };

    template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
    struct ArgPusher10 : public KenshiLua::IArgPusher {
        T1 a1; T2 a2; T3 a3; T4 a4; T5 a5; T6 a6; T7 a7; T8 a8; T9 a9; T10 a10;
        ArgPusher10(T1 _1, T2 _2, T3 _3, T4 _4, T5 _5, T6 _6, T7 _7, T8 _8, T9 _9, T10 _10) : a1(_1), a2(_2), a3(_3), a4(_4), a5(_5), a6(_6), a7(_7), a8(_8), a9(_9), a10(_10) {}
        int push(lua_State* L) const {
            KenshiLua::pushArg(L, a1);
            KenshiLua::pushArg(L, a2);
            KenshiLua::pushArg(L, a3);
            KenshiLua::pushArg(L, a4);
            KenshiLua::pushArg(L, a5);
            KenshiLua::pushArg(L, a6);
            KenshiLua::pushArg(L, a7);
            KenshiLua::pushArg(L, a8);
            KenshiLua::pushArg(L, a9);
            KenshiLua::pushArg(L, a10);
            return 10;
        }
    };

    template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
    struct ArgPusher11 : public KenshiLua::IArgPusher {
        T1 a1; T2 a2; T3 a3; T4 a4; T5 a5; T6 a6; T7 a7; T8 a8; T9 a9; T10 a10; T11 a11;
        ArgPusher11(T1 _1, T2 _2, T3 _3, T4 _4, T5 _5, T6 _6, T7 _7, T8 _8, T9 _9, T10 _10, T11 _11) : a1(_1), a2(_2), a3(_3), a4(_4), a5(_5), a6(_6), a7(_7), a8(_8), a9(_9), a10(_10), a11(_11) {}
        int push(lua_State* L) const {
            KenshiLua::pushArg(L, a1);
            KenshiLua::pushArg(L, a2);
            KenshiLua::pushArg(L, a3);
            KenshiLua::pushArg(L, a4);
            KenshiLua::pushArg(L, a5);
            KenshiLua::pushArg(L, a6);
            KenshiLua::pushArg(L, a7);
            KenshiLua::pushArg(L, a8);
            KenshiLua::pushArg(L, a9);
            KenshiLua::pushArg(L, a10);
            KenshiLua::pushArg(L, a11);
            return 11;
        }
    };

}

// ---------------------------------------------------------------------------
// Event Dispatcher Functions
// ---------------------------------------------------------------------------

void CallCharacterDeclareDeadCallbacks(Character* character)
{
    ArgPusher1<Character*> pusher(character);
    KenshiLua::EventSystem::get().callHandlers("Character::declareDead", &pusher);
}

void CallCharacterSelectCallbacks(Character* character)
{
    ArgPusher1<Character*> pusher(character);
    KenshiLua::EventSystem::get().callHandlers("Character::_NV_select", &pusher);
}

void CallCharacterUnselectCallbacks(Character* character)
{
    ArgPusher1<Character*> pusher(character);
    KenshiLua::EventSystem::get().callHandlers("Character::_NV_unselect", &pusher);
}

void CallCharacterSayCallbacks(Character* character, const std::string& message)
{
    ArgPusher2<Character*, const std::string&> pusher(character, message);
    KenshiLua::EventSystem::get().callHandlers("Character::_NV_say", &pusher);
}

void CallCharacterPickupObjectCallbacks(Character* character, Character* who)
{
    ArgPusher2<Character*, Character*> pusher(character, who);
    KenshiLua::EventSystem::get().callHandlers("Character::pickupObject", &pusher);
}

void CallCharacterGetPickedUpCallbacks(Character* character, Character* byWhom)
{
    ArgPusher2<Character*, Character*> pusher(character, byWhom);
    KenshiLua::EventSystem::get().callHandlers("Character::getPickedUp", &pusher);
}

void CallCharsUpdateCallbacks(GameWorld* thisptr)
{
    ArgPusher1<GameWorld*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("GameWorld::charsUpdate", &pusher);
}

void CallKeyDownCallbacks(InputHandler* thisptr, int keyCode)
{
    ArgPusher2<InputHandler*, int> pusher(thisptr, keyCode);
    KenshiLua::EventSystem::get().callHandlers("InputHandler::keyDownEvent", &pusher);
}

void CallCharStatsSetHoldLocationCallbacks(CharStats* stats, const Ogre::Vector3& v)
{
    ArgPusher2<CharStats*, const Ogre::Vector3&> pusher(stats, v);
    KenshiLua::EventSystem::get().callHandlers("CharStats::setHoldLocation", &pusher);
}

void CallCharStatsClearHoldLocationCallbacks(CharStats* stats)
{
    ArgPusher1<CharStats*> pusher(stats);
    KenshiLua::EventSystem::get().callHandlers("CharStats::clearHoldLocation", &pusher);
}

CombatTechniqueData* CallCharStatsChooseAttackCallbacks(CharStats* stats, float range, float weaponReach, CombatTechniqueData* lastAttack, bool opponentIsStationary, CombatTechniqueData* defaultVal)
{
    ArgPusher6<CharStats*, float, float, CombatTechniqueData*, bool, CombatTechniqueData*> pusher(stats, range, weaponReach, lastAttack, opponentIsStationary, defaultVal);
    CombatTechniqueData* overrideVal = static_cast<CombatTechniqueData*>(KenshiLua::EventSystem::get().callHandlersObject(
        "CharStats::chooseAttack", "KenshiLua.CombatTechniqueData", &pusher));
    return overrideVal ? overrideVal : defaultVal;
}

void CallCharStatsXpRunningCallbacks(CharStats* stats, float time, float speed)
{
    ArgPusher3<CharStats*, float, float> pusher(stats, time, speed);
    KenshiLua::EventSystem::get().callHandlers("CharStats::xpRunning", &pusher);
}

void CallCharStatsXpFirstAidCallbacks(CharStats* stats, Character* patient, float time, int medicStat)
{
    ArgPusher4<CharStats*, Character*, float, int> pusher(stats, patient, time, medicStat);
    KenshiLua::EventSystem::get().callHandlers("CharStats::xpFirstAid", &pusher);
}

void CallCharStatsXpStealthCallbacks(CharStats* stats, float time, bool enemiesAbout, YesNoMaybe seen, bool isMoving)
{
    ArgPusher5<CharStats*, float, bool, YesNoMaybe, bool> pusher(stats, time, enemiesAbout, seen, isMoving);
    KenshiLua::EventSystem::get().callHandlers("CharStats::xpStealth", &pusher);
}

void CallCharStatsXpToughness_GetUpEventCallbacks(CharStats* stats)
{
    ArgPusher1<CharStats*> pusher(stats);
    KenshiLua::EventSystem::get().callHandlers("CharStats::xpToughness_GetUpEvent", &pusher);
}

void CallCharStatsXpToughness_RagdollEventCallbacks(CharStats* stats)
{
    ArgPusher1<CharStats*> pusher(stats);
    KenshiLua::EventSystem::get().callHandlers("CharStats::xpToughness_RagdollEvent", &pusher);
}

void CallCharStatsXpToughness_PunchSomethingCallbacks(CharStats* stats, int mat)
{
    ArgPusher2<CharStats*, int> pusher(stats, mat);
    KenshiLua::EventSystem::get().callHandlers("CharStats::xpToughness_PunchSomething", &pusher);
}

void CallCharStatsXpEngineeringCallbacks(CharStats* stats, float time)
{
    ArgPusher2<CharStats*, float> pusher(stats, time);
    KenshiLua::EventSystem::get().callHandlers("CharStats::xpEngineering", &pusher);
}

void CallCharStatsXpLockpickingCallbacks(CharStats* stats, int lockLevel, bool success)
{
    ArgPusher3<CharStats*, int, bool> pusher(stats, lockLevel, success);
    KenshiLua::EventSystem::get().callHandlers("CharStats::xpLockpicking", &pusher);
}

void CallCharacterTakeMoneyCallbacks(Character* character, int amount)
{
    ArgPusher2<Character*, int> pusher(character, amount);
    KenshiLua::EventSystem::get().callHandlers("Character::_NV_takeMoney", &pusher);
}

void CallCharacterEatCallbacks(Character* character, Item* food, Inventory* from)
{
    ArgPusher3<Character*, Item*, Inventory*> pusher(character, food, from);
    KenshiLua::EventSystem::get().callHandlers("Character::eatItem", &pusher);
}

void CallCharacterHitByMeleeCallbacks(Character* character, int cutDir, Damages* damage, Character* attacker, CombatTechniqueData* attack, int comboID)
{
    ArgPusher6<Character*, int, Damages*, Character*, CombatTechniqueData*, int> pusher(character, cutDir, damage, attacker, attack, comboID);
    KenshiLua::EventSystem::get().callHandlers("Character::_NV_hitByMeleeAttack", &pusher);
}

void CallCharacterGettingEatenCallbacks(Character* character, float amount, Character* eater)
{
    ArgPusher3<Character*, float, Character*> pusher(character, amount, eater);
    KenshiLua::EventSystem::get().callHandlers("Character::_NV_gettingEaten", &pusher);
}

void CallCharacterStandingOrderChangedCallbacks(Character* character, int orderID, bool on)
{
    ArgPusher3<Character*, int, bool> pusher(character, orderID, on);
    KenshiLua::EventSystem::get().callHandlers("Character::_NV_setStandingOrder", &pusher);
}

void CallCharacterFactionChangedCallbacks(Character* character, Faction* faction, ActivePlatoon* platoon)
{
    ArgPusher3<Character*, Faction*, ActivePlatoon*> pusher(character, faction, platoon);
    KenshiLua::EventSystem::get().callHandlers("Character::_NV_setFaction", &pusher);
}

void CallCharacterEquipCallbacks(Character* character, const std::string& sectionName, Item* item)
{
    ArgPusher3<Character*, const std::string&, Item*> pusher(character, sectionName, item);
    KenshiLua::EventSystem::get().callHandlers("Character::_NV_equipItem", &pusher);
}

void CallCharacterUnequipCallbacks(Character* character, const std::string& sectionName, Item* item)
{
    ArgPusher3<Character*, const std::string&, Item*> pusher(character, sectionName, item);
    KenshiLua::EventSystem::get().callHandlers("Character::_NV_unequipItem", &pusher);
}

void CallCharacterStealNoticeCallbacks(Character* character, RootObject* stealFrom, Item* item)
{
    ArgPusher3<Character*, RootObject*, Item*> pusher(character, stealFrom, item);
    KenshiLua::EventSystem::get().callHandlers("Character::_NV_ImStealingDoYouNotice", &pusher);
}

void CallCharacterSmugglingCheckCallbacks(Character* character, Item* item, Character* who)
{
    ArgPusher3<Character*, Item*, Character*> pusher(character, item, who);
    KenshiLua::EventSystem::get().callHandlers("Character::_NV_smugglingTradeCheck", &pusher);
}

void CallPlayerRecruitCallbacks(PlayerInterface* player, Character* character, bool editor)
{
    ArgPusher3<PlayerInterface*, Character*, bool> pusher(player, character, editor);
    KenshiLua::EventSystem::get().callHandlers("PlayerInterface::recruit", &pusher);
}

void CallPlayerSelectCallbacks(PlayerInterface* player, RootObject* obj, bool modifier)
{
    ArgPusher3<PlayerInterface*, RootObject*, bool> pusher(player, obj, modifier);
    KenshiLua::EventSystem::get().callHandlers("PlayerInterface::selectObject", &pusher);
}

void CallPlayerOrderGivenCallbacks(PlayerInterface* player, int taskType, const hand& targetH, Building* destinationIndoors, const Ogre::Vector3& clickpos, bool addDontClear)
{
    ArgPusher6<PlayerInterface*, int, const hand&, Building*, const Ogre::Vector3&, bool> pusher(player, taskType, targetH, destinationIndoors, clickpos, addDontClear);
    KenshiLua::EventSystem::get().callHandlers("PlayerInterface::newPlayerTaskSelectedCharacters", &pusher);
}

void CallPlatoonMemberAddedCallbacks(ActivePlatoon* platoon, RootObject* c)
{
    ArgPusher2<ActivePlatoon*, RootObject*> pusher(platoon, c);
    KenshiLua::EventSystem::get().callHandlers("ActivePlatoon::_NV_addActiveObject", &pusher);
}

void CallPlatoonMemberRemovedCallbacks(ActivePlatoon* platoon, RootObject* c)
{
    ArgPusher2<ActivePlatoon*, RootObject*> pusher(platoon, c);
    KenshiLua::EventSystem::get().callHandlers("ActivePlatoon::_NV_removeObject", &pusher);
}

void CallPlatoonTaskCompleteCallbacks(Platoon* platoon, Tasker* t)
{
    ArgPusher2<Platoon*, Tasker*> pusher(platoon, t);
    KenshiLua::EventSystem::get().callHandlers("Platoon::taskIsComplete", &pusher);
}

void CallItemStolenCallbacks(Item* item, RootObject* obj)
{
    ArgPusher2<Item*, RootObject*> pusher(item, obj);
    KenshiLua::EventSystem::get().callHandlers("Item::_NV_notifyTheftFrom", &pusher);
}

void CallCrimeWitnessedCallbacks(BountyManager* bountyMgr, Faction* against, const hand& againstWho, int expiryTime, int crimeType)
{
    ArgPusher5<BountyManager*, Faction*, const hand&, int, int> pusher(bountyMgr, against, againstWho, expiryTime, crimeType);
    KenshiLua::EventSystem::get().callHandlers("BountyManager::notifyCrimeWitnessed", &pusher);
}

void CallFactionRelationsAffectedCallbacks(FactionRelations* factionRelations, Faction* other, int eventType, float multiplier)
{
    ArgPusher4<FactionRelations*, Faction*, int, float> pusher(factionRelations, other, eventType, multiplier);
    KenshiLua::EventSystem::get().callHandlers("FactionRelations::affectRelations", &pusher);
}

void CallLimbAmputatedCallbacks(MedicalSystem* med, int limb, bool createSeveredItem, const Ogre::Vector3& force)
{
    ArgPusher4<MedicalSystem*, int, bool, const Ogre::Vector3&> pusher(med, limb, createSeveredItem, force);
    KenshiLua::EventSystem::get().callHandlers("MedicalSystem::amputate", &pusher);
}

void CallDialogueWindowShowCallbacks(DialogueWindow* thisptr, Dialogue* dialogue)
{
    ArgPusher2<DialogueWindow*, Dialogue*> pusher(thisptr, dialogue);
    KenshiLua::EventSystem::get().callHandlers("DialogueWindow::show", &pusher);
}

void CallDialogueDoActionsCallbacks(Dialogue* thisptr, DialogLineData* dialogLine)
{
    ArgPusher2<Dialogue*, DialogLineData*> pusher(thisptr, dialogLine);
    KenshiLua::EventSystem::get().callHandlers("Dialogue::_doActions", &pusher);
}

void CallDialogueSayCallbacks(Dialogue* thisptr, DialogLineData* dialogLine)
{
    ArgPusher2<Dialogue*, DialogLineData*> pusher(thisptr, dialogLine);
    KenshiLua::EventSystem::get().callHandlers("Dialogue::say", &pusher);
}

void CallDialogueEndDialogueCallbacks(Dialogue* dialogue, bool definitelyTheEnd)
{
    ArgPusher2<Dialogue*, bool> pusher(dialogue, definitelyTheEnd);
    KenshiLua::EventSystem::get().callHandlers("Dialogue::endDialogue", &pusher);
}

bool CallDialogueCheckConditionCallbacks(Dialogue* dialogue, DialogConditionEnum conditionName, ComparisonEnum compareBy, int val, Character* target, Character* actualConversationTarget, bool defaultVal)
{
    ArgPusher7<Dialogue*, DialogConditionEnum, ComparisonEnum, int, Character*, Character*, bool> pusher(dialogue, conditionName, compareBy, val, target, actualConversationTarget, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("Dialogue::_checkCondition", &pusher, defaultVal);
}

bool CallDialogueStartConversationCallbacks(Dialogue* dialogue, Character* target, DialogLineData* talk, EventTriggerEnum ev, bool force, bool defaultVal)
{
    ArgPusher6<Dialogue*, Character*, DialogLineData*, EventTriggerEnum, bool, bool> pusher(dialogue, target, talk, ev, force, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("Dialogue::startConversation", &pusher, defaultVal);
}

void CallDialogueEndPlayerConversationCallbacks(Dialogue* dialogue, bool finished)
{
    ArgPusher2<Dialogue*, bool> pusher(dialogue, finished);
    KenshiLua::EventSystem::get().callHandlers("Dialogue::_endPlayerConversation", &pusher);
}

bool CallDialogueStartPlayerConversationCallbacks(Dialogue* dialogue, Character* target, DialogLineData* talk, bool defaultVal)
{
    ArgPusher4<Dialogue*, Character*, DialogLineData*, bool> pusher(dialogue, target, talk, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("Dialogue::startPlayerConversation", &pusher, defaultVal);
}

bool CallDialogueSendEventCallbacks(Dialogue* dialogue, Character* who, EventTriggerEnum what, bool defaultVal)
{
    ArgPusher4<Dialogue*, Character*, EventTriggerEnum, bool> pusher(dialogue, who, what, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("Dialogue::sendEvent", &pusher, defaultVal);
}

void CallDialogueStopEventCallbacks(Dialogue* dialogue, EventTriggerEnum what)
{
    ArgPusher2<Dialogue*, EventTriggerEnum> pusher(dialogue, what);
    KenshiLua::EventSystem::get().callHandlers("Dialogue::stopEvent", &pusher);
}

void CallCharacterInitCallbacks(Character* character)
{
    ArgPusher1<Character*> pusher(character);
    KenshiLua::EventSystem::get().callHandlers("Character::_NV_init", &pusher);
}

void CallChooseMyClothingCallbacks(lektor<GameData*>& gear, GameData* dataList, const std::string& listName, RaceData* race, bool noShoes)
{
    ArgPusher5<lektor<GameData*>&, GameData*, const std::string&, RaceData*, bool> pusher(gear, dataList, listName, race, noShoes);
    KenshiLua::EventSystem::get().callHandlers("RootObjectFactory::chooseMyClothing", &pusher);
}

void CallBaseLayoutInitialiseCallbacks(wraps::BaseLayout* thisptr, const std::string& layout)
{
    ArgPusher2<wraps::BaseLayout*, const std::string&> pusher(thisptr, layout);
    KenshiLua::EventSystem::get().callHandlers("wraps::BaseLayout::initialise", &pusher);
}

void CallMyGUIGuiFrameStartCallbacks(float time)
{
    ArgPusher1<float> pusher(time);
    KenshiLua::EventSystem::get().callHandlers("MyGUI::Gui::eventFrameStart", &pusher);
}

InventorySection* CallInventoryGetSectionOfTypeCallbacks(Inventory* inventory, int type)
{
    ArgPusher2<Inventory*, int> pusher(inventory, type);
    return static_cast<InventorySection*>(KenshiLua::EventSystem::get().callHandlersObject("Inventory::getSectionOfType", "KenshiLua.InventorySection", &pusher));
}

Item* CallInventoryGetBestFoodItemCallbacks(Inventory* inventory, Character* race)
{
    ArgPusher2<Inventory*, Character*> pusher(inventory, race);
    return static_cast<Item*>(KenshiLua::EventSystem::get().callHandlersObject("Inventory::getBestFoodItem", "KenshiLua.Item", &pusher));
}

bool CallCharacterIsItOkForMeToLootCallbacks(Character* me, RootObject* victim, Item* item, bool defaultVal)
{
    ArgPusher4<Character*, RootObject*, Item*, bool> pusher(me, victim, item, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("Character::_NV_isItOkForMeToLoot", &pusher, defaultVal);
}

float CallCharacterGetFencingSuccessChanceCallbacks(Character* merchant, Item* item, RootObject* thief, float defaultVal)
{
    ArgPusher4<Character*, Item*, RootObject*, float> pusher(merchant, item, thief, defaultVal);
    return (float)KenshiLua::EventSystem::get().callHandlersNumber("Character::getFencingSuccessChance", &pusher, defaultVal);
}

float CallCharStatsGetStatCallbacks(const CharStats* stats, int what, bool unmodified, float defaultVal)
{
    ArgPusher4<const CharStats*, int, bool, float> pusher(stats, what, unmodified, defaultVal);
    return (float)KenshiLua::EventSystem::get().callHandlersNumber("CharStats::getStat", &pusher, defaultVal);
}

GameData* CallFactionChooseARaceCallbacks(Faction* faction, GameData* character, GameData* squadTemplate, GameData* defaultVal)
{
    ArgPusher4<Faction*, GameData*, GameData*, GameData*> pusher(faction, character, squadTemplate, defaultVal);
    GameData* overrideVal = static_cast<GameData*>(KenshiLua::EventSystem::get().callHandlersObject("Faction::chooseARace", "KenshiLua.GameData", &pusher));
    return overrideVal ? overrideVal : defaultVal;
}

GameData* CallFactionGetBuildingReplacementCallbacks(Faction* faction, GameData* building, GameData* defaultVal)
{
    ArgPusher3<Faction*, GameData*, GameData*> pusher(faction, building, defaultVal);
    GameData* overrideVal = static_cast<GameData*>(KenshiLua::EventSystem::get().callHandlersObject("Faction::getBuildingReplacement", "KenshiLua.GameData", &pusher));
    return overrideVal ? overrideVal : defaultVal;
}

bool CallOwnershipsCanIUseThisBuildingCallbacks(Ownerships* ownerships, Building* b, Character* me, bool defaultVal)
{
    ArgPusher4<Ownerships*, Building*, Character*, bool> pusher(ownerships, b, me, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("Ownerships::canIUseThisBuilding", &pusher, defaultVal);
}

bool CallPlatoonIBuyStolenGoodsCallbacks(Platoon* platoon, Item* what, bool defaultVal)
{
    ArgPusher3<Platoon*, Item*, bool> pusher(platoon, what, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("Platoon::iBuyStolenGoods", &pusher, defaultVal);
}

bool CallPlatoonIBuyIllegalGoodsCallbacks(Platoon* platoon, bool defaultVal)
{
    ArgPusher2<Platoon*, bool> pusher(platoon, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("Platoon::iBuyIllegalGoods", &pusher, defaultVal);
}

bool CallBuildingIsPublicCallbacks(const Building* b, bool defaultVal)
{
    ArgPusher2<const Building*, bool> pusher(b, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("Building::_NV_isPublic", &pusher, defaultVal);
}

bool CallBuildingIsForSaleCallbacks(Building* b, bool defaultVal)
{
    ArgPusher2<Building*, bool> pusher(b, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("Building::_NV_isForSale", &pusher, defaultVal);
}

int CallBuildingCalculateSaleValueCallbacks(Building* b, int defaultVal)
{
    ArgPusher2<Building*, int> pusher(b, defaultVal);
    return (int)KenshiLua::EventSystem::get().callHandlersNumber("Building::calculateSaleValue", &pusher, defaultVal);
}

int CallInventoryItemBaseGetValueSingleCallbacks(const InventoryItemBase* item, bool isPlayer, int defaultVal)
{
    ArgPusher3<const InventoryItemBase*, bool, int> pusher(item, isPlayer, defaultVal);
    return (int)KenshiLua::EventSystem::get().callHandlersNumber("InventoryItemBase::getValueSingle", &pusher, defaultVal);
}

bool CallCharMovementIsRunningCallbacks(CharMovement* thisptr, bool defaultVal)
{
    ArgPusher2<CharMovement*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("CharMovement::isRunning", &pusher, defaultVal);
}
bool CallCharMovementIsRunningAwayCallbacks(CharMovement* thisptr, const Ogre::Vector3& from, bool defaultVal)
{
    ArgPusher3<CharMovement*, const Ogre::Vector3&, bool> pusher(thisptr, from, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("CharMovement::isRunningAway", &pusher, defaultVal);
}

void CallCharStatsXpStatEventBasedCallbacks(CharStats* stats, int stat, float amount)
{
    ArgPusher3<CharStats*, int, float> pusher(stats, stat, amount);
    KenshiLua::EventSystem::get().callHandlers("CharStats::xpStat_eventBased", &pusher);
}

void CallCharStatsXpDodgeEventCallbacks(CharStats* stats, float enemySkill, bool successful)
{
    ArgPusher3<CharStats*, float, bool> pusher(stats, enemySkill, successful);
    KenshiLua::EventSystem::get().callHandlers("CharStats::xpDodgeEvent", &pusher);
}

void CallPlayerActivateCharacterEditModeCallbacks(PlayerInterface* player, Character* character)
{
    ArgPusher2<PlayerInterface*, Character*> pusher(player, character);
    KenshiLua::EventSystem::get().callHandlers("PlayerInterface::activateCharacterEditMode", &pusher);
}

void CallPlayerCreateSquadCallbacks(PlayerInterface* player, ActivePlatoon* newSquad)
{
    ArgPusher2<PlayerInterface*, ActivePlatoon*> pusher(player, newSquad);
    KenshiLua::EventSystem::get().callHandlers("PlayerInterface::createSquad", &pusher);
}

void CallBuildingSetResidentSquadCallbacks(Building* building, Platoon* who)
{
    ArgPusher2<Building*, Platoon*> pusher(building, who);
    KenshiLua::EventSystem::get().callHandlers("Building::setResidentSquad", &pusher);
}

void CallBuildingAddInternalBuildingCallbacks(Building* building, Building* b)
{
    ArgPusher2<Building*, Building*> pusher(building, b);
    KenshiLua::EventSystem::get().callHandlers("Building::addAnInternalBuilding", &pusher);
}

void CallInventoryAddTradePartnerCallbacks(InventoryGUI* tradeWith, bool payment, bool canDrop, bool isPlayer, const hand& who)
{
    ArgPusher5<InventoryGUI*, bool, bool, bool, const hand&> pusher(tradeWith, payment, canDrop, isPlayer, who);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::addTradePartner", &pusher);
}

void CallBuildModeWindowConfirmCallbacks(BuildModeWindow* window, MyGUI::Widget* sender)
{
    ArgPusher2<BuildModeWindow*, MyGUI::Widget*> pusher(window, sender);
    KenshiLua::EventSystem::get().callHandlers("BuildModeWindow::confirm", &pusher);
}

void CallSquadManagementScreenRemoveSquadCallbacks(SquadManagementScreen* screen, void* squadData)
{
    ArgPusher2<SquadManagementScreen*, void*> pusher(screen, squadData);
    KenshiLua::EventSystem::get().callHandlers("SquadManagementScreen::removeSquad", &pusher);
}

void CallCharacterAddGoalCallbacks(Character* character, int task, RootObject* subject)
{
    ArgPusher3<Character*, int, RootObject*> pusher(character, task, subject);
    KenshiLua::EventSystem::get().callHandlers("Character::addGoal", &pusher);
}

void CallCharacterAddJobCallbacks(Character* character, int task, RootObject* subject, bool shift, bool addDontClear, const Ogre::Vector3& location)
{
    ArgPusher6<Character*, int, RootObject*, bool, bool, const Ogre::Vector3&> pusher(character, task, subject, shift, addDontClear, location);
    KenshiLua::EventSystem::get().callHandlers("Character::addJob", &pusher);
}

void CallCharacterAddOrderCallbacks(Character* character, Building* dest, int task, RootObject* subject, bool shift, bool clear, const Ogre::Vector3& location)
{
    ArgPusher7<Character*, Building*, int, RootObject*, bool, bool, const Ogre::Vector3&> pusher(character, dest, task, subject, shift, clear, location);
    KenshiLua::EventSystem::get().callHandlers("Character::addOrder", &pusher);
}

void CallCharacterRemoveJobCallbacks(Character* character, int task)
{
    ArgPusher2<Character*, int> pusher(character, task);
    KenshiLua::EventSystem::get().callHandlers("Character::removeJob", &pusher);
}

void CallPlayerInterfaceAddJobSelectedCharactersCallbacks(PlayerInterface* player, int task, RootObject* subject, bool shift, bool add, const Ogre::Vector3& location)
{
    ArgPusher6<PlayerInterface*, int, RootObject*, bool, bool, const Ogre::Vector3&> pusher(player, task, subject, shift, add, location);
    KenshiLua::EventSystem::get().callHandlers("PlayerInterface::addJobSelectedCharacters", &pusher);
}

void CallPlayerInterfaceAddOrderSelectedCharactersCallbacks(PlayerInterface* player, Building* destinationIndoors, int task, RootObject* subject, bool shift, bool addDontClear, const Ogre::Vector3& location)
{
    ArgPusher7<PlayerInterface*, Building*, int, RootObject*, bool, bool, const Ogre::Vector3&> pusher(player, destinationIndoors, task, subject, shift, addDontClear, location);
    KenshiLua::EventSystem::get().callHandlers("PlayerInterface::addOrderSelectedCharacters", &pusher);
}

void CallMedicalSystemKnockoutCallbacks(MedicalSystem* med, float skill)
{
    ArgPusher2<MedicalSystem*, float> pusher(med, skill);
    KenshiLua::EventSystem::get().callHandlers("MedicalSystem::knockout", &pusher);
}

bool CallMedicalSystemCanGetUpWakeUpCallbacks(MedicalSystem* med, bool defaultVal)
{
    ArgPusher2<MedicalSystem*, bool> pusher(med, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("MedicalSystem::canGetUpWakeUp", &pusher, defaultVal);
}

bool CallInventoryAddItemCallbacks(Inventory* inv, Item* item, int quantity, bool dropOnFail, bool destroyOnFail)
{
    ArgPusher5<Inventory*, Item*, int, bool, bool> pusher(inv, item, quantity, dropOnFail, destroyOnFail);
    return KenshiLua::EventSystem::get().callHandlersBool("Inventory::_NV_addItem", &pusher, true);
}

Item* CallInventoryRemoveItemCallbacks(Inventory* inv, Item* item, int howmany, bool returnCopyIfSomeLeft)
{
    ArgPusher4<Inventory*, Item*, int, bool> pusher(inv, item, howmany, returnCopyIfSomeLeft);
    return static_cast<Item*>(KenshiLua::EventSystem::get().callHandlersObject("Inventory::_NV_removeItemDontDestroy_returnsItem", KenshiLua::ItemMetatable(), &pusher));
}

Item* CallInventoryBuyItemCallbacks(Inventory* inv, Item* item, RootObject* sender)
{
    ArgPusher3<Inventory*, Item*, RootObject*> pusher(inv, item, sender);
    return static_cast<Item*>(KenshiLua::EventSystem::get().callHandlersObject("Inventory::buyItem", KenshiLua::ItemMetatable(), &pusher));
}

void CallFactionActivePlatoonCreatedCallbacks(Faction* faction, Platoon* platoon)
{
    ArgPusher2<Faction*, Platoon*> pusher(faction, platoon);
    KenshiLua::EventSystem::get().callHandlers("Faction::createNewEmptyActivePlatoon", &pusher);
}

void CallFactionPlatoonDestroyedCallbacks(Faction* faction, Platoon* platoon)
{
    ArgPusher2<Faction*, Platoon*> pusher(faction, platoon);
    KenshiLua::EventSystem::get().callHandlers("Faction::destroyPlatoon", &pusher);
}

void CallPlayerEncounterFactionCallbacks(PlayerInterface* player, Faction* faction)
{
    ArgPusher2<PlayerInterface*, Faction*> pusher(player, faction);
    KenshiLua::EventSystem::get().callHandlers("PlayerInterface::encounterFaction", &pusher);
}

void CallCharacterSlaveOwnerChangedCallbacks(Character* slave, const hand& newOwner)
{
    ArgPusher2<Character*, const hand&> pusher(slave, newOwner);
    KenshiLua::EventSystem::get().callHandlers("Character::changeSlaveOwner", &pusher);
}

void CallCharacterChainedModeChangedCallbacks(Character* character, bool on, const hand& owner)
{
    ArgPusher3<Character*, bool, const hand&> pusher(character, on, owner);
    KenshiLua::EventSystem::get().callHandlers("Character::setChainedMode", &pusher);
}

void CallBuildingLoadedCallbacks(Building* building)
{
    ArgPusher1<Building*> pusher(building);
    KenshiLua::EventSystem::get().callHandlers("Building::_NV_onBuildingLoaded", &pusher);
}

void CallBuildingBrokenChangedCallbacks(Building* building, bool broken)
{
    ArgPusher2<Building*, bool> pusher(building, broken);
    KenshiLua::EventSystem::get().callHandlers("Building::_NV_setBroken", &pusher);
}

void CallPlayerInterfaceSerialiseCallbacks(PlayerInterface* player, GameData* data)
{
    ArgPusher2<PlayerInterface*, GameData*> pusher(player, data);
    KenshiLua::EventSystem::get().callHandlers("PlayerInterface::serialise", &pusher);
}

void CallPlayerInterfaceLoadFromSerialiseCallbacks(PlayerInterface* player, GameData* data)
{
    ArgPusher2<PlayerInterface*, GameData*> pusher(player, data);
    KenshiLua::EventSystem::get().callHandlers("PlayerInterface::loadFromSerialise", &pusher);
}

void CallCharacterSerialiseCallbacks(Character* character, GameDataContainer* container, GameData* refList)
{
    ArgPusher3<Character*, GameDataContainer*, GameData*> pusher(character, container, refList);
    KenshiLua::EventSystem::get().callHandlers("Character::_NV_serialise", &pusher);
}

void CallCharacterLoadFromSerialiseCallbacks(Character* character, GameSaveState* state)
{
    ArgPusher2<Character*, GameSaveState*> pusher(character, state);
    KenshiLua::EventSystem::get().callHandlers("Character::_NV_loadFromSerialise", &pusher);
}

void CallCharacterLoadFromSerialisePostCreationStageCallbacks(Character* character, GameSaveState* state)
{
    ArgPusher2<Character*, GameSaveState*> pusher(character, state);
    KenshiLua::EventSystem::get().callHandlers("Character::_NV_loadFromSerialisePostCreationStage", &pusher);
}

void CallBuildingSerialiseCallbacks(Building* building, GameDataContainer* container, GameData* refList)
{
    ArgPusher3<Building*, GameDataContainer*, GameData*> pusher(building, container, refList);
    KenshiLua::EventSystem::get().callHandlers("Building::_NV_serialise", &pusher);
}

void CallBuildingLoadFromSerialiseCallbacks(Building* building, GameSaveState* state)
{
    ArgPusher2<Building*, GameSaveState*> pusher(building, state);
    KenshiLua::EventSystem::get().callHandlers("Building::_NV_loadFromSerialise", &pusher);
}

void CallPlatoonLoadFromSerialiseCallbacks(Platoon* platoon, GameSaveState* state)
{
    ArgPusher2<Platoon*, GameSaveState*> pusher(platoon, state);
    KenshiLua::EventSystem::get().callHandlers("Platoon::_NV_loadFromSerialise", &pusher);
}

void CallTownLoadFromSerialiseCallbacks(Town* town, GameSaveState* state)
{
    ArgPusher2<Town*, GameSaveState*> pusher(town, state);
    KenshiLua::EventSystem::get().callHandlers("Town::_NV_loadFromSerialise", &pusher);
}

void CallBuildingBuyMeCallbackCallbacks(Building* building, int result)
{
    ArgPusher2<Building*, int> pusher(building, result);
    KenshiLua::EventSystem::get().callHandlers("Building::_NV_buyMeCallback", &pusher);
}

void CallDataPanelLineButtonPressCallbacks(DataPanelLine_Button* button, MyGUI::Widget* sender)
{
    ArgPusher2<DataPanelLine_Button*, MyGUI::Widget*> pusher(button, sender);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Button::pressCallback", &pusher);
}

void CallInventoryGUIFencingConfirmationCallbacks(InventoryGUI* gui, int b)
{
    ArgPusher2<InventoryGUI*, int> pusher(gui, b);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::fencingConfirmationCallback", &pusher);
}

void CallContextMenuShowContextMenuCallbacks(ContextMenu* menu, bool on, RootObject* what)
{
    ArgPusher3<ContextMenu*, bool, RootObject*> pusher(menu, on, what);
    KenshiLua::EventSystem::get().callHandlers("ContextMenu::showContextMenu", &pusher);
}

void CallContextMenuGUIShowCallbacks(ContextMenuGUI* menuGUI, const lektor<int>& ordersList, const std::string& name, bool offset)
{
    ArgPusher4<ContextMenuGUI*, const lektor<int>&, const std::string&, bool> pusher(menuGUI, ordersList, name, offset);
    KenshiLua::EventSystem::get().callHandlers("ContextMenuGUI::show", &pusher);
}

void CallInventorySectionAddItemCallbacks(Inventory* inventory, Item* item)
{
    ArgPusher2<Inventory*, Item*> pusher(inventory, item);
    KenshiLua::EventSystem::get().callHandlers("Inventory::_NV__sectionAddItemCallback", &pusher);
}

void CallInventorySectionRemoveItemCallbacks(Inventory* inventory, Item* item)
{
    ArgPusher2<Inventory*, Item*> pusher(inventory, item);
    KenshiLua::EventSystem::get().callHandlers("Inventory::_NV__sectionRemoveItemCallback", &pusher);
}

void CallInventorySectionUpdateItemCallbacks(Inventory* inventory, Item* item, int prevQuantity)
{
    ArgPusher3<Inventory*, Item*, int> pusher(inventory, item, prevQuantity);
    KenshiLua::EventSystem::get().callHandlers("Inventory::_NV__sectionUpdateItemCallback", &pusher);
}

void CallInventoryDropItemCallbacks(Inventory* inventory, Item* item)
{
    ArgPusher2<Inventory*, Item*> pusher(inventory, item);
    KenshiLua::EventSystem::get().callHandlers("Inventory::_NV_dropItem", &pusher);
}

Character* CallCharacterConstructedCallbacks(Character* thisptr, GameData* dat, Faction* own, const hand& _handle, Character* defaultVal)
{
    ArgPusher5<Character*, GameData*, Faction*, const hand&, Character*> pusher(thisptr, dat, own, _handle, defaultVal);
    Character* overrideObj = static_cast<Character*>(KenshiLua::EventSystem::get().callHandlersObject("Character::_CONSTRUCTOR", KenshiLua::CharacterMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Item* CallItemConstructedCallbacks(Item* thisptr, GameData* baseData, GameData* companyData, GameData* _materialData, hand _handle, Item* defaultVal)
{
    ArgPusher6<Item*, GameData*, GameData*, GameData*, const hand&, Item*> pusher(thisptr, baseData, companyData, _materialData, _handle, defaultVal);
    Item* overrideObj = static_cast<Item*>(KenshiLua::EventSystem::get().callHandlersObject("Item::_CONSTRUCTOR", KenshiLua::ItemMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Gear* CallGearConstructedCallbacks(Gear* thisptr, GameData* baseData, GameData* companyData, GameData* materialData, hand _handle, int _level, Faction* uniform, Gear* defaultVal)
{
    ArgPusher8<Gear*, GameData*, GameData*, GameData*, const hand&, int, Faction*, Gear*> pusher(thisptr, baseData, companyData, materialData, _handle, _level, uniform, defaultVal);
    Gear* overrideObj = static_cast<Gear*>(KenshiLua::EventSystem::get().callHandlersObject("Gear::_CONSTRUCTOR", KenshiLua::GearMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Sword* CallSwordConstructedCallbacks(Sword* thisptr, GameData* baseData, GameData* companyData, GameData* materialData, hand _handle, int _level, Sword* defaultVal)
{
    ArgPusher7<Sword*, GameData*, GameData*, GameData*, const hand&, int, Sword*> pusher(thisptr, baseData, companyData, materialData, _handle, _level, defaultVal);
    Sword* overrideObj = static_cast<Sword*>(KenshiLua::EventSystem::get().callHandlersObject("Sword::_CONSTRUCTOR", KenshiLua::SwordMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Crossbow* CallCrossbowConstructedCallbacks(Crossbow* thisptr, GameData* baseData, hand _handle, int _overalllevel, Crossbow* defaultVal)
{
    ArgPusher5<Crossbow*, GameData*, const hand&, int, Crossbow*> pusher(thisptr, baseData, _handle, _overalllevel, defaultVal);
    Crossbow* overrideObj = static_cast<Crossbow*>(KenshiLua::EventSystem::get().callHandlersObject("Crossbow::_CONSTRUCTOR", KenshiLua::CrossbowMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Armour* CallArmourConstructedCallbacks(Armour* thisptr, GameData* baseData, GameData* _materialData, hand _handle, Faction* _uniformFlag, int _level, Armour* defaultVal)
{
    ArgPusher7<Armour*, GameData*, GameData*, const hand&, Faction*, int, Armour*> pusher(thisptr, baseData, _materialData, _handle, _uniformFlag, _level, defaultVal);
    Armour* overrideObj = static_cast<Armour*>(KenshiLua::EventSystem::get().callHandlersObject("Armour::_CONSTRUCTOR", KenshiLua::ArmourMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

LockedArmour* CallLockedArmourConstructedCallbacks(LockedArmour* thisptr, GameData* baseData, GameData* _materialData, hand _handle, Faction* _uniformFlag, int _level, LockedArmour* defaultVal)
{
    ArgPusher7<LockedArmour*, GameData*, GameData*, const hand&, Faction*, int, LockedArmour*> pusher(thisptr, baseData, _materialData, _handle, _uniformFlag, _level, defaultVal);
    LockedArmour* overrideObj = static_cast<LockedArmour*>(KenshiLua::EventSystem::get().callHandlersObject("LockedArmour::_CONSTRUCTOR", KenshiLua::LockedArmourMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Weapon* CallWeaponConstructedCallbacks(Weapon* thisptr, GameData* baseData, GameData* companyData, GameData* materialData, hand _handle, int _level, Weapon* defaultVal)
{
    ArgPusher7<Weapon*, GameData*, GameData*, GameData*, const hand&, int, Weapon*> pusher(thisptr, baseData, companyData, materialData, _handle, _level, defaultVal);
	Weapon* overrideObj = static_cast<Weapon*>(KenshiLua::EventSystem::get().callHandlersObject("Weapon::_CONSTRUCTOR", KenshiLua::WeaponMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Building* CallBuildingConstructedCallbacks(Building* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, Building* defaultVal)
{
    ArgPusher10<Building*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, Building*> pusher(thisptr, data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, defaultVal);
    Building* overrideObj = static_cast<Building*>(KenshiLua::EventSystem::get().callHandlersObject("Building::_CONSTRUCTOR", KenshiLua::BuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Platoon* CallPlatoonConstructedCallbacks(Platoon* thisptr, Faction* f, GameData* _squadTemplate, GameData* platoonState, const Ogre::Vector3& p, bool _persistent, Platoon* defaultVal)
{
    ArgPusher7<Platoon*, Faction*, GameData*, GameData*, const Ogre::Vector3&, bool, Platoon*> pusher(thisptr, f, _squadTemplate, platoonState, p, _persistent, defaultVal);
    Platoon* overrideObj = static_cast<Platoon*>(KenshiLua::EventSystem::get().callHandlersObject("Platoon::_CONSTRUCTOR", KenshiLua::PlatoonMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

ActivePlatoon* CallActivePlatoonConstructedCallbacks(ActivePlatoon* thisptr, Platoon* my, DataObjectContainer* doc, Faction* f, GameData* d, Tasker* _currentGoal, const Ogre::Vector3& _posOffset, ActivePlatoon* defaultVal)
{
    ArgPusher8<ActivePlatoon*, Platoon*, DataObjectContainer*, Faction*, GameData*, Tasker*, const Ogre::Vector3&, ActivePlatoon*> pusher(thisptr, my, doc, f, d, _currentGoal, _posOffset, defaultVal);
    ActivePlatoon* overrideObj = static_cast<ActivePlatoon*>(KenshiLua::EventSystem::get().callHandlersObject("ActivePlatoon::_CONSTRUCTOR", KenshiLua::ActivePlatoonMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Faction* CallFactionConstructedCallbacks(Faction* thisptr, const std::string& _name, Faction* defaultVal)
{
    ArgPusher3<Faction*, const std::string&, Faction*> pusher(thisptr, _name, defaultVal);
    Faction* overrideObj = static_cast<Faction*>(KenshiLua::EventSystem::get().callHandlersObject("Faction::_CONSTRUCTOR", KenshiLua::FactionMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Bounty* CallBountyConstructedCallbacks(Bounty* thisptr, Bounty* defaultVal)
{
    ArgPusher2<Bounty*, Bounty*> pusher(thisptr, defaultVal);
    Bounty* overrideObj = static_cast<Bounty*>(KenshiLua::EventSystem::get().callHandlersObject("Bounty::_CONSTRUCTOR", KenshiLua::BountyMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Damages* CallDamagesConstructedCallbacks(Damages* thisptr, float _cut, float _blunt, float _pierce, float bleed, float armour, Damages* defaultVal)
{
    ArgPusher7<Damages*, float, float, float, float, float, Damages*> pusher(thisptr, _cut, _blunt, _pierce, bleed, armour, defaultVal);
    Damages* overrideObj = static_cast<Damages*>(KenshiLua::EventSystem::get().callHandlersObject("Damages::_CONSTRUCTOR", KenshiLua::DamagesMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Inventory* CallInventoryConstructedCallbacks(Inventory* thisptr, RootObject* _owner, Inventory* defaultVal)
{
    ArgPusher3<Inventory*, RootObject*, Inventory*> pusher(thisptr, _owner, defaultVal);
    Inventory* overrideObj = static_cast<Inventory*>(KenshiLua::EventSystem::get().callHandlersObject("Inventory::_CONSTRUCTOR", KenshiLua::InventoryMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

DoorStuff* CallDoorStuffConstructedCallbacks(DoorStuff* thisptr, GameData* dat, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, Building* par, DoorStuff* defaultVal)
{
    ArgPusher11<DoorStuff*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, Building*, DoorStuff*> pusher(thisptr, dat, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, par, defaultVal);
    DoorStuff* overrideObj = static_cast<DoorStuff*>(KenshiLua::EventSystem::get().callHandlersObject("DoorStuff::_CONSTRUCTOR", KenshiLua::DoorStuffMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

ProductionBuilding* CallProductionBuildingConstructedCallbacks(ProductionBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, ProductionBuilding* defaultVal)
{
    ArgPusher10<ProductionBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, ProductionBuilding*> pusher(thisptr, _data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, defaultVal);
    ProductionBuilding* overrideObj = static_cast<ProductionBuilding*>(KenshiLua::EventSystem::get().callHandlersObject("ProductionBuilding::_CONSTRUCTOR", KenshiLua::ProductionBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

CraftingBuilding* CallCraftingBuildingConstructedCallbacks(CraftingBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, CraftingBuilding* defaultVal)
{
    ArgPusher10<CraftingBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, CraftingBuilding*> pusher(thisptr, _data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, defaultVal);
    CraftingBuilding* overrideObj = static_cast<CraftingBuilding*>(KenshiLua::EventSystem::get().callHandlersObject("CraftingBuilding::_CONSTRUCTOR", KenshiLua::CraftingBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

FarmBuilding* CallFarmBuildingConstructedCallbacks(FarmBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, FarmBuilding* defaultVal)
{
    ArgPusher10<FarmBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, FarmBuilding*> pusher(thisptr, data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, defaultVal);
    FarmBuilding* overrideObj = static_cast<FarmBuilding*>(KenshiLua::EventSystem::get().callHandlersObject("FarmBuilding::_CONSTRUCTOR", KenshiLua::FarmBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

TurretBuilding* CallTurretBuildingConstructedCallbacks(TurretBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, TurretBuilding* defaultVal)
{
    ArgPusher10<TurretBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, TurretBuilding*> pusher(thisptr, _data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, defaultVal);
    TurretBuilding* overrideObj = static_cast<TurretBuilding*>(KenshiLua::EventSystem::get().callHandlersObject("TurretBuilding::_CONSTRUCTOR", KenshiLua::TurretBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

FurnaceBuilding* CallFurnaceBuildingConstructedCallbacks(FurnaceBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, FurnaceBuilding* defaultVal)
{
    ArgPusher10<FurnaceBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, FurnaceBuilding*> pusher(thisptr, data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, defaultVal);
    FurnaceBuilding* overrideObj = static_cast<FurnaceBuilding*>(KenshiLua::EventSystem::get().callHandlersObject("FurnaceBuilding::_CONSTRUCTOR", KenshiLua::FurnaceBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

ResearchBuilding* CallResearchBuildingConstructedCallbacks(ResearchBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, ResearchBuilding* defaultVal)
{
    ArgPusher10<ResearchBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, ResearchBuilding*> pusher(thisptr, _data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, defaultVal);
    ResearchBuilding* overrideObj = static_cast<ResearchBuilding*>(KenshiLua::EventSystem::get().callHandlersObject("ResearchBuilding::_CONSTRUCTOR", KenshiLua::ResearchBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

WallBuilding* CallWallBuildingConstructedCallbacks(WallBuilding* thisptr, GameData* dat, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, Layout* furnitureOf, const hand& town, const hand& _handle, WallBuilding* defaultVal)
{
    ArgPusher9<WallBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, Layout*, const hand&, const hand&, WallBuilding*> pusher(thisptr, dat, position, orientation, _participant, furnitureOf, town, _handle, defaultVal);
    WallBuilding* overrideObj = static_cast<WallBuilding*>(KenshiLua::EventSystem::get().callHandlersObject("WallBuilding::_CONSTRUCTOR", KenshiLua::WallBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

PreviewBuilding* CallPreviewBuildingConstructedCallbacks(PreviewBuilding* thisptr, GameData* data, Building* _furnitureParent, PreviewBuilding* defaultVal)
{
    ArgPusher4<PreviewBuilding*, GameData*, Building*, PreviewBuilding*> pusher(thisptr, data, _furnitureParent, defaultVal);
    PreviewBuilding* overrideObj = static_cast<PreviewBuilding*>(KenshiLua::EventSystem::get().callHandlersObject("PreviewBuilding::_CONSTRUCTOR", KenshiLua::PreviewBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

UseableStuff* CallUseableStuffConstructedCallbacks(UseableStuff* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, UseableStuff* defaultVal)
{
    ArgPusher10<UseableStuff*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, UseableStuff*> pusher(thisptr, _data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, defaultVal);
    UseableStuff* overrideObj = static_cast<UseableStuff*>(KenshiLua::EventSystem::get().callHandlersObject("UseableStuff::_CONSTRUCTOR", KenshiLua::UseableStuffMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

StorageBuilding* CallStorageBuildingConstructedCallbacks(StorageBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, StorageBuilding* defaultVal)
{
    ArgPusher10<StorageBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, StorageBuilding*> pusher(thisptr, _data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, defaultVal);
    StorageBuilding* overrideObj = static_cast<StorageBuilding*>(KenshiLua::EventSystem::get().callHandlersObject("StorageBuilding::_CONSTRUCTOR", KenshiLua::StorageBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

LightBuilding* CallLightBuildingConstructedCallbacks(LightBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, LightBuilding* defaultVal)
{
    ArgPusher10<LightBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, LightBuilding*> pusher(thisptr, data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, defaultVal);
    LightBuilding* overrideObj = static_cast<LightBuilding*>(KenshiLua::EventSystem::get().callHandlersObject("LightBuilding::_CONSTRUCTOR", KenshiLua::LightBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

GeneratorBuilding* CallGeneratorBuildingConstructedCallbacks(GeneratorBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, GeneratorBuilding* defaultVal)
{
    ArgPusher10<GeneratorBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, GeneratorBuilding*> pusher(thisptr, data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, defaultVal);
    GeneratorBuilding* overrideObj = static_cast<GeneratorBuilding*>(KenshiLua::EventSystem::get().callHandlersObject("GeneratorBuilding::_CONSTRUCTOR", KenshiLua::GeneratorBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

WindGeneratorBuilding* CallWindGeneratorBuildingConstructedCallbacks(WindGeneratorBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, WindGeneratorBuilding* defaultVal)
{
    ArgPusher10<WindGeneratorBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, WindGeneratorBuilding*> pusher(thisptr, data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, defaultVal);
    WindGeneratorBuilding* overrideObj = static_cast<WindGeneratorBuilding*>(KenshiLua::EventSystem::get().callHandlersObject("WindGeneratorBuilding::_CONSTRUCTOR", KenshiLua::WindGeneratorBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

GatewayBuilding* CallGatewayBuildingConstructedCallbacks(GatewayBuilding* thisptr, GameData* dat, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, GatewayBuilding* defaultVal)
{
    ArgPusher8<GatewayBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, GatewayBuilding*> pusher(thisptr, dat, position, orientation, _participant, town, _handle, defaultVal);
    GatewayBuilding* overrideObj = static_cast<GatewayBuilding*>(KenshiLua::EventSystem::get().callHandlersObject("GatewayBuilding::_CONSTRUCTOR", KenshiLua::GatewayBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

TortureBuilding* CallTortureBuildingConstructedCallbacks(TortureBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* participant, const hand& town, const hand& handle, Layout* isfurnitureOf, Building* indoors, TortureBuilding* defaultVal)
{
    ArgPusher10<TortureBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, TortureBuilding*> pusher(thisptr, data, position, orientation, participant, town, handle, isfurnitureOf, indoors, defaultVal);
    TortureBuilding* overrideObj = static_cast<TortureBuilding*>(KenshiLua::EventSystem::get().callHandlersObject("TortureBuilding::_CONSTRUCTOR", KenshiLua::TortureBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

RainCollectorBuilding* CallRainCollectorBuildingConstructedCallbacks(RainCollectorBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* participant, const hand& town, const hand& handle, Layout* isfurnitureOf, Building* indoors, RainCollectorBuilding* defaultVal)
{
    ArgPusher10<RainCollectorBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, RainCollectorBuilding*> pusher(thisptr, data, position, orientation, participant, town, handle, isfurnitureOf, indoors, defaultVal);
    RainCollectorBuilding* overrideObj = static_cast<RainCollectorBuilding*>(KenshiLua::EventSystem::get().callHandlersObject("RainCollectorBuilding::_CONSTRUCTOR", KenshiLua::RainCollectorBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

CharacterHuman* CallCharacterHumanConstructedCallbacks(CharacterHuman* thisptr, GameData* d, Faction* f, const hand& _handle, CharacterHuman* defaultVal)
{
    ArgPusher5<CharacterHuman*, GameData*, Faction*, const hand&, CharacterHuman*> pusher(thisptr, d, f, _handle, defaultVal);
    CharacterHuman* overrideObj = static_cast<CharacterHuman*>(KenshiLua::EventSystem::get().callHandlersObject("CharacterHuman::_CONSTRUCTOR", KenshiLua::CharacterHumanMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

CharacterAnimal* CallCharacterAnimalConstructedCallbacks(CharacterAnimal* thisptr, GameData* d, Faction* f, const hand& _handle, float _age, CharacterAnimal* defaultVal)
{
    ArgPusher6<CharacterAnimal*, GameData*, Faction*, const hand&, float, CharacterAnimal*> pusher(thisptr, d, f, _handle, _age, defaultVal);
    CharacterAnimal* overrideObj = static_cast<CharacterAnimal*>(KenshiLua::EventSystem::get().callHandlersObject("CharacterAnimal::_CONSTRUCTOR", KenshiLua::CharacterAnimalMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

CharStats* CallCharStatsConstructedCallbacks(CharStats* thisptr, CharStats* defaultVal)
{
    ArgPusher2<CharStats*, CharStats*> pusher(thisptr, defaultVal);
    CharStats* overrideObj = static_cast<CharStats*>(KenshiLua::EventSystem::get().callHandlersObject("CharStats::_CONSTRUCTOR", KenshiLua::CharStatsMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

CharBody* CallCharBodyConstructedCallbacks(CharBody* thisptr, CharBody* defaultVal)
{
    ArgPusher2<CharBody*, CharBody*> pusher(thisptr, defaultVal);
    CharBody* overrideObj = static_cast<CharBody*>(KenshiLua::EventSystem::get().callHandlersObject("CharBody::_CONSTRUCTOR", KenshiLua::CharBodyMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

CharMovement* CallCharMovementConstructedCallbacks(CharMovement* thisptr, CharMovement* defaultVal)
{
    ArgPusher2<CharMovement*, CharMovement*> pusher(thisptr, defaultVal);
    CharMovement* overrideObj = static_cast<CharMovement*>(KenshiLua::EventSystem::get().callHandlersObject("CharMovement::_CONSTRUCTOR", KenshiLua::CharMovementMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

CombatClass* CallCombatClassConstructedCallbacks(CombatClass* thisptr, CharMovement* m, void* a, void* an, Character* character, CharStats* st, MedicalSystem* _med, CombatClass* defaultVal)
{
    ArgPusher8<CombatClass*, CharMovement*, void*, void*, Character*, CharStats*, MedicalSystem*, CombatClass*> pusher(thisptr, m, a, an, character, st, _med, defaultVal);
    CombatClass* overrideObj = static_cast<CombatClass*>(KenshiLua::EventSystem::get().callHandlersObject("CombatClass::_CONSTRUCTOR", KenshiLua::CombatClassMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Town* CallTownConstructedCallbacks(Town* thisptr, GameData* d, Town* defaultVal)
{
    ArgPusher3<Town*, GameData*, Town*> pusher(thisptr, d, defaultVal);
    Town* overrideObj = static_cast<Town*>(KenshiLua::EventSystem::get().callHandlersObject("Town::_CONSTRUCTOR", KenshiLua::TownMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

TownBase* CallTownBaseConstructedCallbacks(TownBase* thisptr, GameData* d, TownBase* defaultVal)
{
    ArgPusher3<TownBase*, GameData*, TownBase*> pusher(thisptr, d, defaultVal);
    TownBase* overrideObj = static_cast<TownBase*>(KenshiLua::EventSystem::get().callHandlersObject("TownBase::_CONSTRUCTOR", KenshiLua::TownBaseMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

FactionLeader* CallFactionLeaderConstructedCallbacks(FactionLeader* thisptr, Faction* f, FactionLeader* defaultVal)
{
    ArgPusher3<FactionLeader*, Faction*, FactionLeader*> pusher(thisptr, f, defaultVal);
    FactionLeader* overrideObj = static_cast<FactionLeader*>(KenshiLua::EventSystem::get().callHandlersObject("FactionLeader::_CONSTRUCTOR", KenshiLua::FactionLeaderMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

FactionRelations* CallFactionRelationsConstructedCallbacks(FactionRelations* thisptr, FactionRelations* defaultVal)
{
    ArgPusher2<FactionRelations*, FactionRelations*> pusher(thisptr, defaultVal);
    FactionRelations* overrideObj = static_cast<FactionRelations*>(KenshiLua::EventSystem::get().callHandlersObject("FactionRelations::_CONSTRUCTOR", KenshiLua::FactionRelationsMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

FactionUniqueSquadManager* CallFactionUniqueSquadManagerConstructedCallbacks(FactionUniqueSquadManager* thisptr, FactionUniqueSquadManager* defaultVal)
{
    ArgPusher2<FactionUniqueSquadManager*, FactionUniqueSquadManager*> pusher(thisptr, defaultVal);
    FactionUniqueSquadManager* overrideObj = static_cast<FactionUniqueSquadManager*>(KenshiLua::EventSystem::get().callHandlersObject("FactionUniqueSquadManager::_CONSTRUCTOR", KenshiLua::FactionUniqueSquadManagerMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

ProsperityManager* CallProsperityManagerConstructedCallbacks(ProsperityManager* thisptr, ProsperityManager* defaultVal)
{
    ArgPusher2<ProsperityManager*, ProsperityManager*> pusher(thisptr, defaultVal);
    ProsperityManager* overrideObj = static_cast<ProsperityManager*>(KenshiLua::EventSystem::get().callHandlersObject("ProsperityManager::_CONSTRUCTOR", KenshiLua::ProsperityManagerMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

InventoryItemBase* CallInventoryItemBaseConstructedCallbacks(InventoryItemBase* thisptr, GameData* baseData, GameData* companyData, GameData* materialData, const hand& _handle, InventoryItemBase* defaultVal)
{
    ArgPusher6<InventoryItemBase*, GameData*, GameData*, GameData*, const hand&, InventoryItemBase*> pusher(thisptr, baseData, companyData, materialData, _handle, defaultVal);
    InventoryItemBase* overrideObj = static_cast<InventoryItemBase*>(KenshiLua::EventSystem::get().callHandlersObject("InventoryItemBase::_CONSTRUCTOR", KenshiLua::InventoryItemBaseMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

MedicalSystem* CallMedicalSystemConstructedCallbacks(MedicalSystem* thisptr, MedicalSystem* defaultVal)
{
    ArgPusher2<MedicalSystem*, MedicalSystem*> pusher(thisptr, defaultVal);
    MedicalSystem* overrideObj = static_cast<MedicalSystem*>(KenshiLua::EventSystem::get().callHandlersObject("MedicalSystem::_CONSTRUCTOR", KenshiLua::MedicalSystemMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

CombatTechniqueData* CallCombatTechniqueDataConstructedCallbacks(CombatTechniqueData* thisptr, GameData* data, CombatTechniqueData* defaultVal)
{
    ArgPusher3<CombatTechniqueData*, GameData*, CombatTechniqueData*> pusher(thisptr, data, defaultVal);
    CombatTechniqueData* overrideObj = static_cast<CombatTechniqueData*>(KenshiLua::EventSystem::get().callHandlersObject("CombatTechniqueData::_CONSTRUCTOR", KenshiLua::CombatTechniqueDataMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Dialogue* CallDialogueConstructedCallbacks(Dialogue* thisptr, Dialogue* defaultVal)
{
    ArgPusher2<Dialogue*, Dialogue*> pusher(thisptr, defaultVal);
    Dialogue* overrideObj = static_cast<Dialogue*>(KenshiLua::EventSystem::get().callHandlersObject("Dialogue::_CONSTRUCTOR", KenshiLua::DialogueMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

DialogLineData* CallDialogLineDataConstructedCallbacks(DialogLineData* thisptr, GameData* dat, DialogLineData* defaultVal)
{
    ArgPusher3<DialogLineData*, GameData*, DialogLineData*> pusher(thisptr, dat, defaultVal);
    DialogLineData* overrideObj = static_cast<DialogLineData*>(KenshiLua::EventSystem::get().callHandlersObject("DialogLineData::_CONSTRUCTOR", KenshiLua::DialogLineDataMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

GameData* CallGameDataConstructedCallbacks(GameData* thisptr, GameData* defaultVal)
{
    ArgPusher2<GameData*, GameData*> pusher(thisptr, defaultVal);
    GameData* overrideObj = static_cast<GameData*>(KenshiLua::EventSystem::get().callHandlersObject("GameData::_CONSTRUCTOR", KenshiLua::GameDataMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Tasker* CallTaskerConstructedCallbacks(Tasker* thisptr, Tasker* defaultVal)
{
    ArgPusher2<Tasker*, Tasker*> pusher(thisptr, defaultVal);
    Tasker* overrideObj = static_cast<Tasker*>(KenshiLua::EventSystem::get().callHandlersObject("Tasker::_CONSTRUCTOR", KenshiLua::TaskerMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

AppearanceManager* CallAppearanceManagerConstructedCallbacks(AppearanceManager* thisptr, AppearanceManager* defaultVal)
{
    ArgPusher2<AppearanceManager*, AppearanceManager*> pusher(thisptr, defaultVal);
    AppearanceManager* overrideObj = static_cast<AppearanceManager*>(KenshiLua::EventSystem::get().callHandlersObject("AppearanceManager::_CONSTRUCTOR", KenshiLua::AppearanceManagerMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

CombatMovementController* CallCombatMovementControllerConstructedCallbacks(CombatMovementController* thisptr, CombatMovementController* defaultVal)
{
    ArgPusher2<CombatMovementController*, CombatMovementController*> pusher(thisptr, defaultVal);
    CombatMovementController* overrideObj = static_cast<CombatMovementController*>(KenshiLua::EventSystem::get().callHandlersObject("CombatMovementController::_CONSTRUCTOR", KenshiLua::CombatMovementControllerMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

WorldEventStateQuery* CallWorldEventStateQueryConstructedCallbacks(WorldEventStateQuery* thisptr, WorldEventStateQuery* defaultVal)
{
    ArgPusher2<WorldEventStateQuery*, WorldEventStateQuery*> pusher(thisptr, defaultVal);
    WorldEventStateQuery* overrideObj = static_cast<WorldEventStateQuery*>(KenshiLua::EventSystem::get().callHandlersObject("WorldEventStateQuery::_CONSTRUCTOR", KenshiLua::WorldEventStateQueryMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

DialogueWindow* CallDialogueWindowConstructedCallbacks(DialogueWindow* thisptr, DialogueWindow* defaultVal)
{
    ArgPusher2<DialogueWindow*, DialogueWindow*> pusher(thisptr, defaultVal);
    DialogueWindow* overrideObj = static_cast<DialogueWindow*>(KenshiLua::EventSystem::get().callHandlersObject("DialogueWindow::_CONSTRUCTOR", KenshiLua::DialogueWindowMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

InventoryGUI* CallInventoryGUIConstructedCallbacks(InventoryGUI* thisptr, Inventory* inventory, InventoryLayout* layout, RootObject* callback, InventoryGUI* defaultVal)
{
    ArgPusher5<InventoryGUI*, Inventory*, InventoryLayout*, RootObject*, InventoryGUI*> pusher(thisptr, inventory, layout, callback, defaultVal);
    InventoryGUI* overrideObj = static_cast<InventoryGUI*>(KenshiLua::EventSystem::get().callHandlersObject("InventoryGUI::_CONSTRUCTOR", KenshiLua::InventoryGUIMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

GenericFixedInventoryLayout* CallGenericFixedInventoryLayoutConstructedCallbacks(GenericFixedInventoryLayout* thisptr, GenericFixedInventoryLayout* defaultVal)
{
    ArgPusher2<GenericFixedInventoryLayout*, GenericFixedInventoryLayout*> pusher(thisptr, defaultVal);
    GenericFixedInventoryLayout* overrideObj = static_cast<GenericFixedInventoryLayout*>(KenshiLua::EventSystem::get().callHandlersObject("GenericFixedInventoryLayout::_CONSTRUCTOR", KenshiLua::GenericFixedInventoryLayoutMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

GameWorld* CallGameWorldConstructedCallbacks(GameWorld* thisptr, GameWorld* defaultVal)
{
    ArgPusher2<GameWorld*, GameWorld*> pusher(thisptr, defaultVal);
    GameWorld* overrideObj = static_cast<GameWorld*>(KenshiLua::EventSystem::get().callHandlersObject("GameWorld::_CONSTRUCTOR", KenshiLua::GameWorldMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

PlayerInterface* CallPlayerInterfaceConstructedCallbacks(PlayerInterface* thisptr, PlayerInterface* defaultVal)
{
    ArgPusher2<PlayerInterface*, PlayerInterface*> pusher(thisptr, defaultVal);
    PlayerInterface* overrideObj = static_cast<PlayerInterface*>(KenshiLua::EventSystem::get().callHandlersObject("PlayerInterface::_CONSTRUCTOR", KenshiLua::PlayerInterfaceMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

InputHandler* CallInputHandlerConstructedCallbacks(InputHandler* thisptr, InputHandler* defaultVal)
{
    ArgPusher2<InputHandler*, InputHandler*> pusher(thisptr, defaultVal);
    InputHandler* overrideObj = static_cast<InputHandler*>(KenshiLua::EventSystem::get().callHandlersObject("InputHandler::_CONSTRUCTOR", KenshiLua::InputHandlerMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

RootObjectFactory* CallRootObjectFactoryConstructedCallbacks(RootObjectFactory* thisptr, RootObjectFactory* defaultVal)
{
    ArgPusher2<RootObjectFactory*, RootObjectFactory*> pusher(thisptr, defaultVal);
    RootObjectFactory* overrideObj = static_cast<RootObjectFactory*>(KenshiLua::EventSystem::get().callHandlersObject("RootObjectFactory::_CONSTRUCTOR", KenshiLua::RootObjectFactoryMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

FactionManager* CallFactionManagerConstructedCallbacks(FactionManager* thisptr, FactionManager* defaultVal)
{
    ArgPusher2<FactionManager*, FactionManager*> pusher(thisptr, defaultVal);
    FactionManager* overrideObj = static_cast<FactionManager*>(KenshiLua::EventSystem::get().callHandlersObject("FactionManager::_CONSTRUCTOR", KenshiLua::FactionManagerMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

FactionWarMgr* CallFactionWarMgrConstructedCallbacks(FactionWarMgr* thisptr, Faction* faction, FactionWarMgr* defaultVal)
{
    ArgPusher3<FactionWarMgr*, Faction*, FactionWarMgr*> pusher(thisptr, faction, defaultVal);
    FactionWarMgr* overrideObj = static_cast<FactionWarMgr*>(KenshiLua::EventSystem::get().callHandlersObject("FactionWarMgr::_CONSTRUCTOR", KenshiLua::FactionWarMgrMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

BountyManager* CallBountyManagerConstructedCallbacks(BountyManager* thisptr, Character* character, BountyManager* defaultVal)
{
    ArgPusher3<BountyManager*, Character*, BountyManager*> pusher(thisptr, character, defaultVal);
    BountyManager* overrideObj = static_cast<BountyManager*>(KenshiLua::EventSystem::get().callHandlersObject("BountyManager::_CONSTRUCTOR", KenshiLua::BountyManagerMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

ZoneMap* CallZoneMapConstructedCallbacks(ZoneMap* thisptr, ZoneMap* defaultVal)
{
    ArgPusher2<ZoneMap*, ZoneMap*> pusher(thisptr, defaultVal);
    ZoneMap* overrideObj = static_cast<ZoneMap*>(KenshiLua::EventSystem::get().callHandlersObject("ZoneMap::_CONSTRUCTOR", KenshiLua::ZoneMapMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

ZoneManager* CallZoneManagerConstructedCallbacks(ZoneManager* thisptr, ZoneManager* defaultVal)
{
    ArgPusher2<ZoneManager*, ZoneManager*> pusher(thisptr, defaultVal);
    ZoneManager* overrideObj = static_cast<ZoneManager*>(KenshiLua::EventSystem::get().callHandlersObject("ZoneManager::_CONSTRUCTOR", KenshiLua::ZoneManagerMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Character::AttachedArrowManager* CallAttachedArrowManagerConstructedCallbacks(Character::AttachedArrowManager* thisptr, Character::AttachedArrowManager* defaultVal)
{
    ArgPusher2<Character::AttachedArrowManager*, Character::AttachedArrowManager*> pusher(thisptr, defaultVal);
    Character::AttachedArrowManager* overrideObj = static_cast<Character::AttachedArrowManager*>(KenshiLua::EventSystem::get().callHandlersObject("Character::AttachedArrowManager::_CONSTRUCTOR", KenshiLua::AttachedArrowManagerMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

LimbsInventoryLayout* CallLimbsInventoryLayoutConstructedCallbacks(LimbsInventoryLayout* thisptr, Character* character, LimbsInventoryLayout* defaultVal)
{
    ArgPusher3<LimbsInventoryLayout*, Character*, LimbsInventoryLayout*> pusher(thisptr, character, defaultVal);
    LimbsInventoryLayout* overrideObj = static_cast<LimbsInventoryLayout*>(KenshiLua::EventSystem::get().callHandlersObject("LimbsInventoryLayout::_CONSTRUCTOR", KenshiLua::LimbsInventoryLayoutMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

RobotLimbs* CallRobotLimbsConstructedCallbacks(RobotLimbs* thisptr, Character* character, RobotLimbs* defaultVal)
{
    ArgPusher3<RobotLimbs*, Character*, RobotLimbs*> pusher(thisptr, character, defaultVal);
    RobotLimbs* overrideObj = static_cast<RobotLimbs*>(KenshiLua::EventSystem::get().callHandlersObject("RobotLimbs::_CONSTRUCTOR", KenshiLua::RobotLimbsMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

ShopTrader* CallShopTraderConstructedCallbacks(ShopTrader* thisptr, Character* character, ShopTrader* defaultVal)
{
    ArgPusher3<ShopTrader*, Character*, ShopTrader*> pusher(thisptr, character, defaultVal);
    ShopTrader* overrideObj = static_cast<ShopTrader*>(KenshiLua::EventSystem::get().callHandlersObject("ShopTrader::_CONSTRUCTOR", KenshiLua::ShopTraderMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

RootObjectBase* CallRootObjectBaseConstructedCallbacks(RootObjectBase* thisptr, GameData* data, Faction* faction, hand handle, RootObjectBase* defaultVal)
{
    ArgPusher5<RootObjectBase*, GameData*, Faction*, hand, RootObjectBase*> pusher(thisptr, data, faction, handle, defaultVal);
    RootObjectBase* overrideObj = static_cast<RootObjectBase*>(KenshiLua::EventSystem::get().callHandlersObject("RootObjectBase::_CONSTRUCTOR", KenshiLua::RootObjectBaseMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

RootObject* CallRootObjectConstructedCallbacks(RootObject* thisptr, GameData* data, Faction* faction, hand handle, RootObject* defaultVal)
{
    ArgPusher5<RootObject*, GameData*, Faction*, hand, RootObject*> pusher(thisptr, data, faction, handle, defaultVal);
    RootObject* overrideObj = static_cast<RootObject*>(KenshiLua::EventSystem::get().callHandlersObject("RootObject::_CONSTRUCTOR", KenshiLua::RootObjectMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

void CallUseableStuffTryOperateCallbacks(UseableStuff* thisptr, const hand& h, bool success)
{
    ArgPusher3<UseableStuff*, const hand&, bool> pusher(thisptr, h, success);
    KenshiLua::EventSystem::get().callHandlers("UseableStuff::_NV_tryOperate", &pusher);
}

void CallUseableStuffStopOperatingCallbacks(UseableStuff* thisptr, const hand& h)
{
    ArgPusher2<UseableStuff*, const hand&> pusher(thisptr, h);
    KenshiLua::EventSystem::get().callHandlers("UseableStuff::stopOperating", &pusher);
}

void CallUseableStuffOccupantChangedCallbacks(UseableStuff* thisptr, const hand& h)
{
    ArgPusher2<UseableStuff*, const hand&> pusher(thisptr, h);
    KenshiLua::EventSystem::get().callHandlers("UseableStuff::occupantHandleChangedEvent", &pusher);
}

void CallUseableStuffPowerSwitchedCallbacks(UseableStuff* thisptr, bool on)
{
    ArgPusher2<UseableStuff*, bool> pusher(thisptr, on);
    KenshiLua::EventSystem::get().callHandlers("UseableStuff::_NV_switchPowerOn", &pusher);
}

void CallUseableStuffGivePowerCallbacks(UseableStuff* thisptr, float amount)
{
    ArgPusher2<UseableStuff*, float> pusher(thisptr, amount);
    KenshiLua::EventSystem::get().callHandlers("UseableStuff::_NV_givePower", &pusher);
}

int CallUseableStuffGetCostToUseCallbacks(UseableStuff* thisptr, Character* who, int defaultVal)
{
    ArgPusher3<UseableStuff*, Character*, int> pusher(thisptr, who, defaultVal);
    return (int)KenshiLua::EventSystem::get().callHandlersNumber("UseableStuff::_NV_getCostToUse", &pusher, defaultVal);
}

bool CallUseableStuffCouldIOperateCallbacks(const UseableStuff* thisptr, const hand& h, bool defaultVal)
{
    ArgPusher3<const UseableStuff*, const hand&, bool> pusher(thisptr, h, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("UseableStuff::_NV_couldIOperate", &pusher, defaultVal);
}

bool CallUseableStuffDontNeedWorkCallbacks(const UseableStuff* thisptr, bool defaultVal)
{
    ArgPusher2<const UseableStuff*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("UseableStuff::_NV_dontNeedWorkRightNow", &pusher, defaultVal);
}

void CallBuildingNotifyConstructionCompleteCallbacks(Building* thisptr)
{
    ArgPusher1<Building*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("Building::_NV_notifyConstructionComplete", &pusher);
}

void CallBuildingAddConstructionProgressCallbacks(Building* thisptr, float amount)
{
    ArgPusher2<Building*, float> pusher(thisptr, amount);
    KenshiLua::EventSystem::get().callHandlers("Building::_NV_addConstructionProgress", &pusher);
}

void CallBuildingSetConstructionProgressCallbacks(Building* thisptr, float amount)
{
    ArgPusher2<Building*, float> pusher(thisptr, amount);
    KenshiLua::EventSystem::get().callHandlers("Building::_NV_setConstructionProgress", &pusher);
}

bool CallBuildingAddDismantleProgressCallbacks(Building* thisptr, float amount, bool defaultVal)
{
    ArgPusher3<Building*, float, bool> pusher(thisptr, amount, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("Building::_NV_addDismantleProgress", &pusher, defaultVal);
}

void CallBuildingNotifyConstructionDismantlingCallbacks(Building* thisptr)
{
    ArgPusher1<Building*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("Building::_NV_notifyConstructionDismantling", &pusher);
}

void CallBuildingUpgradeCallbacks(Building* thisptr, DataPanelLine* line)
{
    ArgPusher2<Building*, DataPanelLine*> pusher(thisptr, line);
    KenshiLua::EventSystem::get().callHandlers("Building::_NV_upgrade", &pusher);
}

GameData* CallBuildingCanUpgradeCallbacks(Building* thisptr, GameData* defaultVal)
{
    ArgPusher2<Building*, GameData*> pusher(thisptr, defaultVal);
    GameData* overrideObj = static_cast<GameData*>(KenshiLua::EventSystem::get().callHandlersObject("Building::_NV_canUpgrade", KenshiLua::GameDataMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

void CallBuildingDestroyDoorsCallbacks(Building* thisptr)
{
    ArgPusher1<Building*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("Building::destroyDoors", &pusher);
}

void CallBuildingSetFactionCallbacks(Building* thisptr, Faction* p, ActivePlatoon* a)
{
    ArgPusher3<Building*, Faction*, ActivePlatoon*> pusher(thisptr, p, a);
    KenshiLua::EventSystem::get().callHandlers("Building::_NV_setFaction", &pusher);
}

void CallBuildingSetFloorVisibilityCallbacks(Building* thisptr, int floor, bool vis)
{
    ArgPusher3<Building*, int, bool> pusher(thisptr, floor, vis);
    KenshiLua::EventSystem::get().callHandlers("Building::setFloorVisibility", &pusher);
}

void CallBuildingSwitchLightsCallbacks(Building* thisptr, bool on)
{
    ArgPusher2<Building*, bool> pusher(thisptr, on);
    KenshiLua::EventSystem::get().callHandlers("Building::_NV_switchLights", &pusher);
}

void CallBuildingSwitchEffectsCallbacks(Building* thisptr, bool on)
{
    ArgPusher2<Building*, bool> pusher(thisptr, on);
    KenshiLua::EventSystem::get().callHandlers("Building::_NV_switchEffects", &pusher);
}

void CallBuildingNotifyEffectCallbacks(Building* thisptr, int type, int what, float strength)
{
    ArgPusher4<Building*, int, int, float> pusher(thisptr, type, what, strength);
    KenshiLua::EventSystem::get().callHandlers("Building::_NV_notifyEffect", &pusher);
}

void CallWallBuildingHitByMeleeAttackCallbacks(WallBuilding* thisptr, int cutDir, Damages* damage, Character* who, CombatTechniqueData* attack, int comboID)
{
    ArgPusher6<WallBuilding*, int, Damages*, Character*, CombatTechniqueData*, int> pusher(thisptr, cutDir, damage, who, attack, comboID);
    KenshiLua::EventSystem::get().callHandlers("WallBuilding::_NV_hitByMeleeAttack", &pusher);
}

bool CallDoorStuffOpenDoorCallbacks(DoorStuff* thisptr, bool defaultVal)
{
    ArgPusher2<DoorStuff*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("DoorStuff::openDoor", &pusher, defaultVal);
}

bool CallDoorStuffCloseDoorCallbacks(DoorStuff* thisptr, bool defaultVal)
{
    ArgPusher2<DoorStuff*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("DoorStuff::closeDoor", &pusher, defaultVal);
}

void CallDoorStuffLockDoorCallbacks(DoorStuff* thisptr)
{
    ArgPusher1<DoorStuff*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DoorStuff::lockDoor", &pusher);
}

void CallDoorStuffUnlockDoorCallbacks(DoorStuff* thisptr)
{
    ArgPusher1<DoorStuff*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DoorStuff::unlockDoor", &pusher);
}

void CallDoorStuffSetDoorStateCallbacks(DoorStuff* thisptr, int doorState)
{
    ArgPusher2<DoorStuff*, int> pusher(thisptr, doorState);
    KenshiLua::EventSystem::get().callHandlers("DoorStuff::setDoorState", &pusher);
}

void CallDoorStuffHitByMeleeAttackCallbacks(DoorStuff* thisptr, int cutDir, Damages* damage, Character* who, CombatTechniqueData* attack, int comboID)
{
    ArgPusher6<DoorStuff*, int, Damages*, Character*, CombatTechniqueData*, int> pusher(thisptr, cutDir, damage, who, attack, comboID);
    KenshiLua::EventSystem::get().callHandlers("DoorStuff::_NV_hitByMeleeAttack", &pusher);
}

void CallProductionBuildingOperateCallbacks(ProductionBuilding* thisptr, Character* who, float amount)
{
    ArgPusher3<ProductionBuilding*, Character*, float> pusher(thisptr, who, amount);
    KenshiLua::EventSystem::get().callHandlers("ProductionBuilding::_NV_operate", &pusher);
}

void CallCraftingBuildingOperateCallbacks(CraftingBuilding* thisptr, Character* worker, float amount)
{
    ArgPusher3<CraftingBuilding*, Character*, float> pusher(thisptr, worker, amount);
    KenshiLua::EventSystem::get().callHandlers("CraftingBuilding::_NV_operate", &pusher);
}

void CallCraftingBuildingNewCraftingButtonCallbacks(CraftingBuilding* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<CraftingBuilding*, MyGUI::Widget*> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("CraftingBuilding::_NV_newCraftingButton", &pusher);
}

void CallCraftingBuildingAddFinishedCraftItemCallbacks(CraftingBuilding* thisptr, Item* what)
{
    ArgPusher2<CraftingBuilding*, Item*> pusher(thisptr, what);
    KenshiLua::EventSystem::get().callHandlers("CraftingBuilding::addFinishedCraftItem", &pusher);
}

void CallCraftingBuildingNotifyCraftFailureCallbacks(CraftingBuilding* thisptr)
{
    ArgPusher1<CraftingBuilding*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("CraftingBuilding::notifyCraftFailiure", &pusher);
}

void CallCraftingBuildingDestroyProductionItemCallbacks(CraftingBuilding* thisptr)
{
    ArgPusher1<CraftingBuilding*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("CraftingBuilding::destroyProductionItem", &pusher);
}

void CallCraftingBuildingRemoveCraftCallbacks(CraftingBuilding* thisptr, int index)
{
    ArgPusher2<CraftingBuilding*, int> pusher(thisptr, index);
    KenshiLua::EventSystem::get().callHandlers("CraftingBuilding::_removeCraft", &pusher);
}

void CallFurnaceBuildingOperateCallbacks(FurnaceBuilding* thisptr, Character* worker, float amount)
{
    ArgPusher3<FurnaceBuilding*, Character*, float> pusher(thisptr, worker, amount);
    KenshiLua::EventSystem::get().callHandlers("FurnaceBuilding::_NV_operate", &pusher);
}

void CallResearchBuildingOperateCallbacks(ResearchBuilding* thisptr, Character* worker, float amount)
{
    ArgPusher3<ResearchBuilding*, Character*, float> pusher(thisptr, worker, amount);
    KenshiLua::EventSystem::get().callHandlers("ResearchBuilding::_NV_operate", &pusher);
}

void CallFarmBuildingOperateCallbacks(FarmBuilding* thisptr, Character* who, float amount)
{
    ArgPusher3<FarmBuilding*, Character*, float> pusher(thisptr, who, amount);
    KenshiLua::EventSystem::get().callHandlers("FarmBuilding::_NV_operate", &pusher);
}

bool CallFarmBuildingDestroyAPlantCallbacks(FarmBuilding* thisptr, bool defaultVal)
{
    ArgPusher2<FarmBuilding*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("FarmBuilding::destroyAPlant", &pusher, defaultVal);
}

void CallFarmBuildingEatCallbacks(FarmBuilding* thisptr, float rate)
{
    ArgPusher2<FarmBuilding*, float> pusher(thisptr, rate);
    KenshiLua::EventSystem::get().callHandlers("FarmBuilding::eat", &pusher);
}

void CallTurretBuildingOperateCallbacks(TurretBuilding* thisptr, Character* gunner, float amount)
{
    ArgPusher3<TurretBuilding*, Character*, float> pusher(thisptr, gunner, amount);
    KenshiLua::EventSystem::get().callHandlers("TurretBuilding::_NV_operate", &pusher);
}

void CallTurretBuildingAimAtCallbacks(TurretBuilding* thisptr, const Ogre::Vector3& targetPos)
{
    ArgPusher2<TurretBuilding*, const Ogre::Vector3&> pusher(thisptr, targetPos);
    KenshiLua::EventSystem::get().callHandlers("TurretBuilding::aimAt", &pusher);
}

void CallUseableStuffHitByMeleeAttackCallbacks(UseableStuff* thisptr, int cutDir, Damages* damage, Character* who, CombatTechniqueData* attack, int comboID)
{
    ArgPusher6<UseableStuff*, int, Damages*, Character*, CombatTechniqueData*, int> pusher(thisptr, cutDir, damage, who, attack, comboID);
    KenshiLua::EventSystem::get().callHandlers("UseableStuff::_NV_hitByMeleeAttack", &pusher);
}

float CallUseableStuffTakePowerFromCallbacks(UseableStuff* thisptr, float amount, float frameTime, float defaultVal)
{
    ArgPusher4<UseableStuff*, float, float, float> pusher(thisptr, amount, frameTime, defaultVal);
    return (float)KenshiLua::EventSystem::get().callHandlersNumber("UseableStuff::takePowerFrom", &pusher, defaultVal);
}

void CallUseableStuffTogglePowerButtonCallbacks(UseableStuff* thisptr, DataPanelLine* line)
{
    ArgPusher2<UseableStuff*, DataPanelLine*> pusher(thisptr, line);
    KenshiLua::EventSystem::get().callHandlers("UseableStuff::_NV_togglePowerButton", &pusher);
}

void CallUseableStuffToggleBattButtonCallbacks(UseableStuff* thisptr, DataPanelLine* line)
{
    ArgPusher2<UseableStuff*, DataPanelLine*> pusher(thisptr, line);
    KenshiLua::EventSystem::get().callHandlers("UseableStuff::_NV_toggleBattButton", &pusher);
}

void CallPreviewBuildingPlaceFinalPreviewBuildingCallbacks(PreviewBuilding* thisptr)
{
    ArgPusher1<PreviewBuilding*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("PreviewBuilding::_NV_placeFinalPreviewBuilding", &pusher);
}

bool CallPreviewBuildingPlacementVerificationCallbacks(PreviewBuilding* thisptr, bool defaultVal)
{
    ArgPusher2<PreviewBuilding*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("PreviewBuilding::_NV_placementVerification", &pusher, defaultVal);
}

void CallPreviewBuildingPlacePreviewCallbacks(PreviewBuilding* thisptr, const Ogre::Vector3& position, const Ogre::Quaternion& rotation, int floorNumber)
{
    ArgPusher4<PreviewBuilding*, const Ogre::Vector3&, const Ogre::Quaternion&, int> pusher(thisptr, position, rotation, floorNumber);
    KenshiLua::EventSystem::get().callHandlers("PreviewBuilding::_NV_placePreview", &pusher);
}

// -----------------------------------------------------------
// Callbacks for hooks in CharacterAnimal.h
// -----------------------------------------------------------

void CallCharacterAnimalIsAnimalCallbacks(CharacterAnimal* thisptr, CharacterAnimal* result)
{
    ArgPusher2<CharacterAnimal*, CharacterAnimal*> pusher(thisptr, result);
    KenshiLua::EventSystem::get().callHandlers("CharacterAnimal::_NV_isAnimal", &pusher);
}

void CallCharacterAnimalCreateAnimationClassCallbacks(CharacterAnimal* thisptr)
{
    ArgPusher1<CharacterAnimal*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("CharacterAnimal::_NV_createAnimationClass", &pusher);
}

void CallCharacterAnimalDrawWeaponCallbacks(CharacterAnimal* thisptr, Item* item, const std::string& lastSlot, bool success)
{
    ArgPusher4<CharacterAnimal*, Item*, const std::string&, bool> pusher(thisptr, item, lastSlot, success);
    KenshiLua::EventSystem::get().callHandlers("CharacterAnimal::_NV_drawWeapon", &pusher);
}

void CallCharacterAnimalSheatheWeaponCallbacks(CharacterAnimal* thisptr)
{
    ArgPusher1<CharacterAnimal*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("CharacterAnimal::_NV_sheatheWeapon", &pusher);
}

Weapon* CallCharacterAnimalGetCurrentWeaponCallbacks(CharacterAnimal* thisptr, Weapon* defaultVal)
{
    ArgPusher2<CharacterAnimal*, Weapon*> pusher(thisptr, defaultVal);
    return static_cast<Weapon*>(KenshiLua::EventSystem::get().callHandlersObject("CharacterAnimal::_NV_getCurrentWeapon", KenshiLua::WeaponMetatable(), &pusher));
}

Weapon* CallCharacterAnimalGetThePreferredWeaponCallbacks(CharacterAnimal* thisptr, Weapon* defaultVal)
{
    ArgPusher2<CharacterAnimal*, Weapon*> pusher(thisptr, defaultVal);
    return static_cast<Weapon*>(KenshiLua::EventSystem::get().callHandlersObject("CharacterAnimal::_NV_getThePreferredWeapon", KenshiLua::WeaponMetatable(), &pusher));
}

void CallCharacterAnimalCreateInventoryLayoutCallbacks(CharacterAnimal* thisptr, InventoryLayout* layout)
{
    ArgPusher2<CharacterAnimal*, InventoryLayout*> pusher(thisptr, layout);
    KenshiLua::EventSystem::get().callHandlers("CharacterAnimal::_NV_createInventoryLayout", &pusher);
}

void CallCharacterAnimalGiveBirthCallbacks(CharacterAnimal* thisptr, GameDataCopyStandalone* appearance, const Ogre::Vector3& position, const Ogre::Quaternion& rotation, GameSaveState* state, ActivePlatoon* tempplatoonptr, Faction* _faction, bool success)
{
    ArgPusher8<CharacterAnimal*, GameDataCopyStandalone*, const Ogre::Vector3&, const Ogre::Quaternion&, GameSaveState*, ActivePlatoon*, Faction*, bool> pusher(thisptr, appearance, position, rotation, state, tempplatoonptr, _faction, success);
    KenshiLua::EventSystem::get().callHandlers("CharacterAnimal::_NV_giveBirth", &pusher);
}

void CallCharacterAnimalSetupInventorySectionsCallbacks(CharacterAnimal* thisptr, GameSaveState* state, bool success)
{
    ArgPusher3<CharacterAnimal*, GameSaveState*, bool> pusher(thisptr, state, success);
    KenshiLua::EventSystem::get().callHandlers("CharacterAnimal::_NV_setupInventorySections", &pusher);
}

void CallCharacterAnimalSetupAudioCallbacks(CharacterAnimal* thisptr)
{
    ArgPusher1<CharacterAnimal*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("CharacterAnimal::_NV_setupAudio", &pusher);
}

void CallCharacterAnimalPeriodicUpdateCallbacks(CharacterAnimal* thisptr)
{
    ArgPusher1<CharacterAnimal*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("CharacterAnimal::_NV_periodicUpdate", &pusher);
}

void CallCharacterAnimalSetAgeCallbacks(CharacterAnimal* thisptr, float zeroToOne)
{
    ArgPusher2<CharacterAnimal*, float> pusher(thisptr, zeroToOne);
    KenshiLua::EventSystem::get().callHandlers("CharacterAnimal::_NV_setAge", &pusher);
}

float CallCharacterAnimalGetAgeCallbacks(const CharacterAnimal* thisptr, float defaultVal)
{
    ArgPusher2<const CharacterAnimal*, float> pusher(thisptr, defaultVal);
    return (float)KenshiLua::EventSystem::get().callHandlersNumber("CharacterAnimal::_NV_getAge", &pusher, defaultVal);
}

float CallCharacterAnimalGetAgeInverseCallbacks(const CharacterAnimal* thisptr, float defaultVal)
{
    ArgPusher2<const CharacterAnimal*, float> pusher(thisptr, defaultVal);
    return (float)KenshiLua::EventSystem::get().callHandlersNumber("CharacterAnimal::_NV_getAgeInverse", &pusher, defaultVal);
}

float CallCharacterAnimalGetAge0to1Callbacks(const CharacterAnimal* thisptr, float defaultVal)
{
    ArgPusher2<const CharacterAnimal*, float> pusher(thisptr, defaultVal);
    return (float)KenshiLua::EventSystem::get().callHandlersNumber("CharacterAnimal::_NV_getAge0to1", &pusher, defaultVal);
}

unsigned int CallCharacterAnimalGetDefaultTaskRepertoireEnumCallbacks(const CharacterAnimal* thisptr, unsigned int defaultVal)
{
    ArgPusher2<const CharacterAnimal*, int> pusher(thisptr, static_cast<int>(defaultVal));
    return (unsigned int)KenshiLua::EventSystem::get().callHandlersNumber("CharacterAnimal::_NV_getDefaultTaskRepertoireEnum", &pusher, (double)defaultVal);
}

bool CallCharacterAnimalCanGoIndoorsCallbacks(const CharacterAnimal* thisptr, Building* b, bool defaultVal)
{
    ArgPusher3<const CharacterAnimal*, Building*, bool> pusher(thisptr, b, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("CharacterAnimal::_NV_canGoIndoors", &pusher, defaultVal);
}

float CallCharacterAnimalGetSmellHuntingThresholdBloodCallbacks(const CharacterAnimal* thisptr, float defaultVal)
{
    ArgPusher2<const CharacterAnimal*, float> pusher(thisptr, defaultVal);
    return (float)KenshiLua::EventSystem::get().callHandlersNumber("CharacterAnimal::_NV_getSmellHuntingThresholdBlood", &pusher, defaultVal);
}

float CallCharacterAnimalGetSmellHuntingThresholdEggsCallbacks(const CharacterAnimal* thisptr, float defaultVal)
{
    ArgPusher2<const CharacterAnimal*, float> pusher(thisptr, defaultVal);
    return (float)KenshiLua::EventSystem::get().callHandlersNumber("CharacterAnimal::_NV_getSmellHuntingThresholdEggs", &pusher, defaultVal);
}

float CallCharacterAnimalGetHPMultiplierCallbacks(const CharacterAnimal* thisptr, float defaultVal)
{
    ArgPusher2<const CharacterAnimal*, float> pusher(thisptr, defaultVal);
    return (float)KenshiLua::EventSystem::get().callHandlersNumber("CharacterAnimal::_NV_getHPMultiplier", &pusher, defaultVal);
}

void CallCharacterAnimalFoodUpdateCallbacks(CharacterAnimal* thisptr)
{
    ArgPusher1<CharacterAnimal*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("CharacterAnimal::_NV_foodUpdate", &pusher);
}

void CallCharacterAnimalInitCallbacks(CharacterAnimal* thisptr)
{
    ArgPusher1<CharacterAnimal*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("CharacterAnimal::_NV_init", &pusher);
}

void CallCharacterAnimalDropItemCallbacks(CharacterAnimal* thisptr, RootObject* itembase)
{
    ArgPusher2<CharacterAnimal*, RootObject*> pusher(thisptr, itembase);
    KenshiLua::EventSystem::get().callHandlers("CharacterAnimal::_NV_dropItem", &pusher);
}

// -----------------------------------------------------------
// Callbacks for hooks in GUIWindow.h
// -----------------------------------------------------------

void CallGUIWindowSetPositionRealCallbacks(GUIWindow* thisptr, float x, float y)
{
    ArgPusher3<GUIWindow*, float, float> pusher(thisptr, x, y);
    KenshiLua::EventSystem::get().callHandlers("GUIWindow::_NV_setPositionReal", &pusher);
}

void CallGUIWindowSetPositionCallbacks(GUIWindow* thisptr, int x, int y)
{
    ArgPusher3<GUIWindow*, int, int> pusher(thisptr, x, y);
    KenshiLua::EventSystem::get().callHandlers("GUIWindow::_NV_setPosition", &pusher);
}

int CallGUIWindowGetWidthCallbacks(GUIWindow* thisptr, int defaultVal)
{
    ArgPusher2<GUIWindow*, int> pusher(thisptr, defaultVal);
    return (int)KenshiLua::EventSystem::get().callHandlersNumber("GUIWindow::_NV_getWidth", &pusher, defaultVal);
}

int CallGUIWindowGetHeightCallbacks(GUIWindow* thisptr, int defaultVal)
{
    ArgPusher2<GUIWindow*, int> pusher(thisptr, defaultVal);
    return (int)KenshiLua::EventSystem::get().callHandlersNumber("GUIWindow::_NV_getHeight", &pusher, defaultVal);
}

float CallGUIWindowGetWidthRealCallbacks(GUIWindow* thisptr, float defaultVal)
{
    ArgPusher2<GUIWindow*, float> pusher(thisptr, defaultVal);
    return (float)KenshiLua::EventSystem::get().callHandlersNumber("GUIWindow::_NV_getWidthReal", &pusher, defaultVal);
}

float CallGUIWindowGetHeightRealCallbacks(GUIWindow* thisptr, float defaultVal)
{
    ArgPusher2<GUIWindow*, float> pusher(thisptr, defaultVal);
    return (float)KenshiLua::EventSystem::get().callHandlersNumber("GUIWindow::_NV_getHeightReal", &pusher, defaultVal);
}

bool CallGUIWindowIsVisibleCallbacks(GUIWindow* thisptr, bool defaultVal)
{
    ArgPusher2<GUIWindow*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("GUIWindow::_NV_isVisible", &pusher, defaultVal);
}

void CallGUIWindowUpdateCallbacks(GUIWindow* thisptr)
{
    ArgPusher1<GUIWindow*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("GUIWindow::_NV_update", &pusher);
}

void CallGUIWindowAutoChangeSelectedObjectCallbacks(GUIWindow* thisptr, const hand& obj)
{
    ArgPusher2<GUIWindow*, const hand&> pusher(thisptr, obj);
    KenshiLua::EventSystem::get().callHandlers("GUIWindow::_NV_autoChangeSelectedObject", &pusher);
}

void CallGUIWindowGetWidgetCallbacks(GUIWindow* thisptr, MyGUI::Widget* result)
{
    ArgPusher2<GUIWindow*, KenshiLua::WidgetArg> pusher(thisptr, result);
    KenshiLua::EventSystem::get().callHandlers("GUIWindow::getWidget", &pusher);
}

void CallGUIWindowResizeCallbacks(GUIWindow* thisptr, int w, int h)
{
    ArgPusher3<GUIWindow*, int, int> pusher(thisptr, w, h);
    KenshiLua::EventSystem::get().callHandlers("GUIWindow::_NV_resize", &pusher);
}


// -----------------------------------------------------------
// Callbacks for hooks in CharacterStatsWindow.h
// -----------------------------------------------------------

void CallCharacterStatsWindowStatDestructorCallbacks(CharacterStatsWindow::Stat* thisptr)
{
    ArgPusher1<CharacterStatsWindow::Stat*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("CharacterStatsWindow::Stat::_DESTRUCTOR", &pusher);
}

void CallCharacterStatsWindowStatAssignCallbacks(CharacterStatsWindow::Stat* thisptr, CharacterStatsWindow::Stat* that)
{
    ArgPusher2<CharacterStatsWindow::Stat*, CharacterStatsWindow::Stat*> pusher(thisptr, that);
    KenshiLua::EventSystem::get().callHandlers("CharacterStatsWindow::Stat::operator=", &pusher);
}

void CallCharacterStatsWindowStatGroupDestructorCallbacks(CharacterStatsWindow::StatGroup* thisptr)
{
    ArgPusher1<CharacterStatsWindow::StatGroup*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("CharacterStatsWindow::StatGroup::_DESTRUCTOR", &pusher);
}

void CallCharacterStatsWindowConstructedCallbacks(CharacterStatsWindow* thisptr, const hand& charHandle)
{
    ArgPusher2<CharacterStatsWindow*, const hand&> pusher(thisptr, charHandle);
    KenshiLua::EventSystem::get().callHandlers("CharacterStatsWindow::_CONSTRUCTOR", &pusher);
}

void CallCharacterStatsWindowDestructorCallbacks(CharacterStatsWindow* thisptr)
{
    ArgPusher1<CharacterStatsWindow*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("CharacterStatsWindow::_DESTRUCTOR", &pusher);
}

void CallCharacterStatsWindowClearCallbacks(CharacterStatsWindow* thisptr)
{
    ArgPusher1<CharacterStatsWindow*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("CharacterStatsWindow::_NV_clear", &pusher);
}

void CallCharacterStatsWindowCreateCallbacks(CharacterStatsWindow* thisptr)
{
    ArgPusher1<CharacterStatsWindow*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("CharacterStatsWindow::_NV_create", &pusher);
}

void CallCharacterStatsWindowUpdateCallbacks(CharacterStatsWindow* thisptr)
{
    ArgPusher1<CharacterStatsWindow*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("CharacterStatsWindow::_NV_update", &pusher);
}

void CallCharacterStatsWindowShowCallbacks(CharacterStatsWindow* thisptr, bool on)
{
    ArgPusher2<CharacterStatsWindow*, bool> pusher(thisptr, on);
    KenshiLua::EventSystem::get().callHandlers("CharacterStatsWindow::_NV_show", &pusher);
}

bool CallCharacterStatsWindowIsVisibleCallbacks(CharacterStatsWindow* thisptr, bool defaultVal)
{
    ArgPusher2<CharacterStatsWindow*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("CharacterStatsWindow::_NV_isVisible", &pusher, defaultVal);
}

void CallCharacterStatsWindowAutoChangeSelectedObjectCallbacks(CharacterStatsWindow* thisptr, const hand& obj)
{
    ArgPusher2<CharacterStatsWindow*, const hand&> pusher(thisptr, obj);
    KenshiLua::EventSystem::get().callHandlers("CharacterStatsWindow::_NV_autoChangeSelectedObject", &pusher);
}

void CallCharacterStatsWindowSetAutoUpdateModeCallbacks(CharacterStatsWindow* thisptr, bool on)
{
    ArgPusher2<CharacterStatsWindow*, bool> pusher(thisptr, on);
    KenshiLua::EventSystem::get().callHandlers("CharacterStatsWindow::setAutoUpdateMode", &pusher);
}

void CallCharacterStatsWindowSetupStatsCallbacks(CharacterStatsWindow* thisptr)
{
    ArgPusher1<CharacterStatsWindow*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("CharacterStatsWindow::setupStats", &pusher);
}

void CallCharacterStatsWindowUpdateStatsCallbacks(CharacterStatsWindow* thisptr)
{
    ArgPusher1<CharacterStatsWindow*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("CharacterStatsWindow::updateStats", &pusher);
}

void CallCharacterStatsWindowClearDesctiptionCallbacks(CharacterStatsWindow* thisptr)
{
    ArgPusher1<CharacterStatsWindow*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("CharacterStatsWindow::clearDesctiption", &pusher);
}

int CallCharacterStatsWindowSumStatsCallbacks(CharacterStatsWindow* thisptr, int defaultVal)
{
    ArgPusher2<CharacterStatsWindow*, int> pusher(thisptr, defaultVal);
    return (int)KenshiLua::EventSystem::get().callHandlersNumber("CharacterStatsWindow::sumStats", &pusher, defaultVal);
}

void CallCharacterStatsWindowCloseWindowCallbacks(CharacterStatsWindow* thisptr, MyGUI::Widget* sender, const std::string& name)
{
    ArgPusher3<CharacterStatsWindow*, KenshiLua::WidgetArg, const std::string&> pusher(thisptr, sender, name);
    KenshiLua::EventSystem::get().callHandlers("CharacterStatsWindow::closeWindow", &pusher);
}

void CallCharacterStatsWindowStatMouseOverCallbacks(CharacterStatsWindow* thisptr, MyGUI::Widget* sender, int arg2, int arg3)
{
    ArgPusher4<CharacterStatsWindow*, KenshiLua::WidgetArg, int, int> pusher(thisptr, sender, arg2, arg3);
    KenshiLua::EventSystem::get().callHandlers("CharacterStatsWindow::statMouseOver", &pusher);
}

DatapanelGUI* CallCharacterStatsWindowGetStatsPanelCallbacks(CharacterStatsWindow* thisptr, int group, DatapanelGUI* defaultVal)
{
    ArgPusher3<CharacterStatsWindow*, int, DatapanelGUI*> pusher(thisptr, group, defaultVal);
    return static_cast<DatapanelGUI*>(KenshiLua::EventSystem::get().callHandlersObject("CharacterStatsWindow::getStatsPanel", KenshiLua::DatapanelGUIMetatable(), &pusher));
}

void CallCharacterStatsWindowAddStatCallbacks(int type, const std::string& id, const std::string& name, bool active, const std::string& description)
{
    ArgPusher5<int, const std::string&, const std::string&, bool, const std::string&> pusher(type, id, name, active, description);
    KenshiLua::EventSystem::get().callHandlers("CharacterStatsWindow::addStat", &pusher);
}

CharacterStatsWindow::Stat* CallCharacterStatsWindowGetStatCallbacks(int type, CharacterStatsWindow::Stat* defaultVal)
{
    ArgPusher2<int, CharacterStatsWindow::Stat*> pusher(type, defaultVal);
    return static_cast<CharacterStatsWindow::Stat*>(KenshiLua::EventSystem::get().callHandlersObject("CharacterStatsWindow::getStat", KenshiLua::CharacterStatsWindowStatMetatable(), &pusher));
}

CharacterStatsWindow::Stat* CallCharacterStatsWindowGetStatByIdCallbacks(const std::string& id, CharacterStatsWindow::Stat* defaultVal)
{
    ArgPusher2<const std::string&, CharacterStatsWindow::Stat*> pusher(id, defaultVal);
    return static_cast<CharacterStatsWindow::Stat*>(KenshiLua::EventSystem::get().callHandlersObject("CharacterStatsWindow::getStatById", KenshiLua::CharacterStatsWindowStatMetatable(), &pusher));
}

void CallCharacterStatsWindowBuildStatsCallbacks()
{
    KenshiLua::EventSystem::get().callHandlers("CharacterStatsWindow::BuildStats", NULL);
}


// -----------------------------------------------------------
// Callbacks for hooks in DatapanelGUI.h
// -----------------------------------------------------------

void CallDatapanelGUISetPositionRealCallbacks(DatapanelGUI* thisptr, float x, float y)
{
    ArgPusher3<DatapanelGUI*, float, float> pusher(thisptr, x, y);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::_NV_setPositionReal", &pusher);
}

void CallDatapanelGUISetPositionCallbacks(DatapanelGUI* thisptr, int x, int y)
{
    ArgPusher3<DatapanelGUI*, int, int> pusher(thisptr, x, y);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::_NV_setPosition", &pusher);
}

void CallDatapanelGUIResizeCallbacks(DatapanelGUI* thisptr, int w, int h)
{
    ArgPusher3<DatapanelGUI*, int, int> pusher(thisptr, w, h);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::_NV_resize", &pusher);
}

void CallDatapanelGUIClearCallbacks(DatapanelGUI* thisptr)
{
    ArgPusher1<DatapanelGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::_NV_clear", &pusher);
}

void CallDatapanelGUIClearPageCallbacks(DatapanelGUI* thisptr, int cat)
{
    ArgPusher2<DatapanelGUI*, int> pusher(thisptr, cat);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::_NV_clearPage", &pusher);
}

void CallDatapanelGUIHideAllWidgetsCallbacks(DatapanelGUI* thisptr)
{
    ArgPusher1<DatapanelGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::_NV_hideAllWidgets", &pusher);
}

void CallDatapanelGUICreateCallbacks(DatapanelGUI* thisptr)
{
    ArgPusher1<DatapanelGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::_NV_create", &pusher);
}

void CallDatapanelGUIShowCallbacks(DatapanelGUI* thisptr, bool on)
{
    ArgPusher2<DatapanelGUI*, bool> pusher(thisptr, on);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::_NV_show", &pusher);
}

void CallDatapanelGUIShow_NonSmoothCallbacks(DatapanelGUI* thisptr, bool on)
{
    ArgPusher2<DatapanelGUI*, bool> pusher(thisptr, on);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::show_NonSmooth", &pusher);
}

void CallDatapanelGUIUpdateCallbacks(DatapanelGUI* thisptr)
{
    ArgPusher1<DatapanelGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::_NV_update", &pusher);
}

void CallDatapanelGUISetPanelNameCallbacks(DatapanelGUI* thisptr, const std::string& name)
{
    ArgPusher2<DatapanelGUI*, const std::string&> pusher(thisptr, name);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::setPanelName", &pusher);
}

void CallDatapanelGUIShowTabsCallbacks(DatapanelGUI* thisptr, bool on)
{
    ArgPusher2<DatapanelGUI*, bool> pusher(thisptr, on);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::_NV_showTabs", &pusher);
}

void CallDatapanelGUIAddTabCallbacks(DatapanelGUI* thisptr, int id, const std::string& name, const std::string& icon)
{
    ArgPusher4<DatapanelGUI*, int, const std::string&, const std::string&> pusher(thisptr, id, name, icon);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::_NV_addTab", &pusher);
}

void CallDatapanelGUISetTabEnabledCallbacks(DatapanelGUI* thisptr, int id, bool enabled)
{
    ArgPusher3<DatapanelGUI*, int, bool> pusher(thisptr, id, enabled);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::_NV_setTabEnabled", &pusher);
}

void CallDatapanelGUISetTabNameCallbacks(DatapanelGUI* thisptr, int id, const std::string& name)
{
    ArgPusher3<DatapanelGUI*, int, const std::string&> pusher(thisptr, id, name);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::_NV_setTabName", &pusher);
}

void CallDatapanelGUISetCaptionCallbacks(DatapanelGUI* thisptr, const std::string& s)
{
    ArgPusher2<DatapanelGUI*, const std::string&> pusher(thisptr, s);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::setCaption", &pusher);
}

void CallDatapanelGUISetCloseCallbackCallbacks(DatapanelGUI* thisptr, void* close)
{
    ArgPusher2<DatapanelGUI*, void*> pusher(thisptr, close);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::setCloseCallback", &pusher);
}

void CallDatapanelGUISetAutomaticRefreshCallbacks(DatapanelGUI* thisptr, bool on)
{
    ArgPusher2<DatapanelGUI*, bool> pusher(thisptr, on);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::_NV_setAutomaticRefresh", &pusher);
}

void CallDatapanelGUISetAutomaticTargetingCallbacks(DatapanelGUI* thisptr, bool on)
{
    ArgPusher2<DatapanelGUI*, bool> pusher(thisptr, on);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::_NV_setAutomaticTargeting", &pusher);
}

void CallDatapanelGUIZeroLinesCallbacks(DatapanelGUI* thisptr, int cat, DataPanelLine* result)
{
    ArgPusher3<DatapanelGUI*, int, DataPanelLine*> pusher(thisptr, cat, result);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::_NV__zeroLines", &pusher);
}

void CallDatapanelGUISetLineStatInfoCallbacks(DatapanelGUI* thisptr, const std::string& s1, const std::string& s2, int category, DataPanelLine* result)
{
    ArgPusher5<DatapanelGUI*, const std::string&, const std::string&, int, DataPanelLine*> pusher(thisptr, s1, s2, category, result);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::setLineStatInfo", &pusher);
}

void CallDatapanelGUISetLineFactionCallbacks(DatapanelGUI* thisptr, const std::string& s1, const std::string& s2, int category, float v1, float v2, DataPanelLine_Faction* result)
{
    ArgPusher7<DatapanelGUI*, const std::string&, const std::string&, int, float, float, DataPanelLine_Faction*> pusher(thisptr, s1, s2, category, v1, v2, result);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::setLineFaction", &pusher);
}

void CallDatapanelGUISetLineTextButtonCallbacks(DatapanelGUI* thisptr, const std::string& text, const std::string& caption, int category, float buttonWidth, const std::string& skin, DataPanelLine_Button* result)
{
    ArgPusher7<DatapanelGUI*, const std::string&, const std::string&, int, float, const std::string&, DataPanelLine_Button*> pusher(thisptr, text, caption, category, buttonWidth, skin, result);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::setLineTextButton", &pusher);
}

void CallDatapanelGUISetLineButtonCallbacks(DatapanelGUI* thisptr, const std::string& key, const std::string& caption, int category, DataPanelLine_Button* result)
{
    ArgPusher5<DatapanelGUI*, const std::string&, const std::string&, int, DataPanelLine_Button*> pusher(thisptr, key, caption, category, result);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::setLineButton", &pusher);
}

void CallDatapanelGUISetLineToggleButtonCallbacks(DatapanelGUI* thisptr, const std::string& key, const std::string& caption, int category, DataPanelLine_Button* result)
{
    ArgPusher5<DatapanelGUI*, const std::string&, const std::string&, int, DataPanelLine_Button*> pusher(thisptr, key, caption, category, result);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::setLineToggleButton", &pusher);
}

void CallDatapanelGUISetLineSliderEditableCallbacks(DatapanelGUI* thisptr, const std::string& key, int category, bool showName, float min, float max, void* value, DataPanelLine_SliderEditable* result)
{
    ArgPusher8<DatapanelGUI*, const std::string&, int, bool, float, float, void*, DataPanelLine_SliderEditable*> pusher(thisptr, key, category, showName, min, max, value, result);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::setLineSliderEditable", &pusher);
}

void CallDatapanelGUISetLineTextCallbacks(DatapanelGUI* thisptr, const std::string& key, const std::string& caption, int category, bool wordWrap, int textAlign, DataPanelLine_Text* result)
{
    ArgPusher7<DatapanelGUI*, const std::string&, const std::string&, int, bool, int, DataPanelLine_Text*> pusher(thisptr, key, caption, category, wordWrap, textAlign, result);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::setLineText", &pusher);
}

void CallDatapanelGUISetLineTextEditableCallbacks(DatapanelGUI* thisptr, const std::string& key, const std::string& text, int category, bool showKey, bool multiLine, int textAlign, float width, DataPanelLine_TextEditable* result)
{
    ArgPusher9<DatapanelGUI*, const std::string&, const std::string&, int, bool, bool, int, float, DataPanelLine_TextEditable*> pusher(thisptr, key, text, category, showKey, multiLine, textAlign, width, result);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::setLineTextEditable", &pusher);
}

void CallDatapanelGUISetLineSliderCallbacks(DatapanelGUI* thisptr, const std::string& key, const std::string& caption, float min, float max, int category, void* value, float scale, DataPanelLine_Slider* result)
{
    ArgPusher9<DatapanelGUI*, const std::string&, const std::string&, float, float, int, void*, float, DataPanelLine_Slider*> pusher(thisptr, key, caption, min, max, category, value, scale, result);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::setLineSlider", &pusher);
}

void CallDatapanelGUISetLineProgressCallbacks(DatapanelGUI* thisptr, const std::string& key, int category, float progressValue, const std::string& progressText, bool showKey, DataPanelLine_Progress* result)
{
    ArgPusher7<DatapanelGUI*, const std::string&, int, float, const std::string&, bool, DataPanelLine_Progress*> pusher(thisptr, key, category, progressValue, progressText, showKey, result);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::setLineProgress", &pusher);
}

void CallDatapanelGUIRemoveLineCallbacks(DatapanelGUI* thisptr, const std::string& s1, int category)
{
    ArgPusher3<DatapanelGUI*, const std::string&, int> pusher(thisptr, s1, category);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::removeLine", &pusher);
}

void CallDatapanelGUISetLineCheckboxCallbacks(DatapanelGUI* thisptr, const std::string& s1, void* val, int category, DataPanelLine_CheckBox* result)
{
    ArgPusher5<DatapanelGUI*, const std::string&, void*, int, DataPanelLine_CheckBox*> pusher(thisptr, s1, val, category, result);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::setLineCheckbox", &pusher);
}

void CallDatapanelGUISetLineDropBoxCallbacks(DatapanelGUI* thisptr, const std::string& key, int category, void* valPtr, bool goBox, float width, DataPanelLine_DropBox* result)
{
    ArgPusher7<DatapanelGUI*, const std::string&, int, void*, bool, float, DataPanelLine_DropBox*> pusher(thisptr, key, category, valPtr, goBox, width, result);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::setLineDropBox", &pusher);
}

void CallDatapanelGUIAddSpaceCallbacks(DatapanelGUI* thisptr, int category, float h)
{
    ArgPusher3<DatapanelGUI*, int, float> pusher(thisptr, category, h);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::addSpace", &pusher);
}

void CallDatapanelGUISetLinesCallbacks(DatapanelGUI* thisptr, const lektor<StringPair>& data, int category)
{
    ArgPusher3<DatapanelGUI*, const lektor<StringPair>&, int> pusher(thisptr, data, category);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::setLines", &pusher);
}

void CallDatapanelGUISetCategoryIconCallbacks(DatapanelGUI* thisptr, int cat, const std::string& image)
{
    ArgPusher3<DatapanelGUI*, int, const std::string&> pusher(thisptr, cat, image);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::_NV_setCategoryIcon", &pusher);
}

void CallDatapanelGUIChangeCategoryCallbacks(DatapanelGUI* thisptr, int cat)
{
    ArgPusher2<DatapanelGUI*, int> pusher(thisptr, cat);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::_NV_changeCategory", &pusher);
}

void CallDatapanelGUIAddCustomLineCallbacks(DatapanelGUI* thisptr, DataPanelLine* line)
{
    ArgPusher2<DatapanelGUI*, DataPanelLine*> pusher(thisptr, line);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::addCustomLine", &pusher);
}

void CallDatapanelGUIAutoChangeSelectedObjectCallbacks(DatapanelGUI* thisptr, const hand& obj)
{
    ArgPusher2<DatapanelGUI*, const hand&> pusher(thisptr, obj);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::_NV_autoChangeSelectedObject", &pusher);
}

void CallDatapanelGUISetObjectCallbacks(DatapanelGUI* thisptr, const hand& obj)
{
    ArgPusher2<DatapanelGUI*, const hand&> pusher(thisptr, obj);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::_NV_setObject", &pusher);
}

void CallDatapanelGUISetLineSpacingCallbacks(DatapanelGUI* thisptr, float numLinesPerScreen)
{
    ArgPusher2<DatapanelGUI*, float> pusher(thisptr, numLinesPerScreen);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::_NV_setLineSpacing", &pusher);
}

DataPanelLine* CallDatapanelGUIGetLineCallbacks(DatapanelGUI* thisptr, const std::string& key, int cat, DataPanelLine* defaultVal)
{
    ArgPusher4<DatapanelGUI*, const std::string&, int, DataPanelLine*> pusher(thisptr, key, cat, defaultVal);
    return static_cast<DataPanelLine*>(KenshiLua::EventSystem::get().callHandlersObject("DatapanelGUI::_NV_getLine", KenshiLua::DataPanelLineMetatable(), &pusher));
}

bool CallDatapanelGUILineExistsCallbacks(DatapanelGUI* thisptr, const std::string& key, int cat, bool defaultVal)
{
    ArgPusher4<DatapanelGUI*, const std::string&, int, bool> pusher(thisptr, key, cat, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("DatapanelGUI::lineExists", &pusher, defaultVal);
}

void CallDatapanelGUITabButtonCallbacks(DatapanelGUI* thisptr, MyGUI::Widget* sender, int arg2, int arg3, int arg4)
{
    ArgPusher5<DatapanelGUI*, KenshiLua::WidgetArg, int, int, int> pusher(thisptr, sender, arg2, arg3, arg4);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::tabButton", &pusher);
}

int CallDatapanelGUIGetNumLinesCallbacks(DatapanelGUI* thisptr, int cat, int defaultVal)
{
    ArgPusher3<DatapanelGUI*, int, int> pusher(thisptr, cat, defaultVal);
    return (int)KenshiLua::EventSystem::get().callHandlersNumber("DatapanelGUI::getNumLines", &pusher, defaultVal);
}

DataPanelLine* CallDatapanelGUIGetLineByNumCallbacks(DatapanelGUI* thisptr, int cat, int i, DataPanelLine* defaultVal)
{
    ArgPusher4<DatapanelGUI*, int, int, DataPanelLine*> pusher(thisptr, cat, i, defaultVal);
    return static_cast<DataPanelLine*>(KenshiLua::EventSystem::get().callHandlersObject("DatapanelGUI::getLineByNum", KenshiLua::DataPanelLineMetatable(), &pusher));
}

void CallDatapanelGUIDestructorCallbacks(DatapanelGUI* thisptr)
{
    ArgPusher1<DatapanelGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::_DESTRUCTOR", &pusher);
}

void CallDatapanelGUICreateLineCallbacks(DatapanelGUI* thisptr, DataPanelLine* line, int category, bool lastLine, DataPanelLine* result)
{
    ArgPusher5<DatapanelGUI*, DataPanelLine*, int, bool, DataPanelLine*> pusher(thisptr, line, category, lastLine, result);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::createLine", &pusher);
}

float CallDatapanelGUIGetNextVerticalPosCallbacks(DatapanelGUI* thisptr, int category, float defaultVal)
{
    ArgPusher3<DatapanelGUI*, int, float> pusher(thisptr, category, defaultVal);
    return (float)KenshiLua::EventSystem::get().callHandlersNumber("DatapanelGUI::getNextVerticalPos", &pusher, defaultVal);
}

void CallDatapanelGUICloseButtonCallbackCallbacks(DatapanelGUI* thisptr, MyGUI::Widget* arg1, const std::string& arg2)
{
    ArgPusher3<DatapanelGUI*, KenshiLua::WidgetArg, const std::string&> pusher(thisptr, arg1, arg2);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::closeButtonCallback", &pusher);
}

void CallDatapanelGUIMouseOverCallbackCallbacks(DatapanelGUI* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<DatapanelGUI*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::mouseOverCallback", &pusher);
}

void CallDatapanelGUINotifyMouseWheelCallbacks(DatapanelGUI* thisptr, MyGUI::Widget* sender, int rel)
{
    ArgPusher3<DatapanelGUI*, KenshiLua::WidgetArg, int> pusher(thisptr, sender, rel);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::notifyMouseWheel", &pusher);
}

void CallDatapanelGUIGetCoordsCallbacks(DatapanelGUI* thisptr, float left, float top, float width, float height, const MyGUI::IntCoord& result)
{
    ArgPusher6<DatapanelGUI*, float, float, float, float, const MyGUI::IntCoord&> pusher(thisptr, left, top, width, height, result);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::getCoords", &pusher);
}

bool CallDatapanelGUIDataExistsCallbacks(DatapanelGUI* thisptr, int cat, const std::string& name, bool defaultVal)
{
    ArgPusher4<DatapanelGUI*, int, const std::string&, bool> pusher(thisptr, cat, name, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("DatapanelGUI::dataExists", &pusher, defaultVal);
}

void CallDatapanelGUIClearCategoryTabsCallbacks(DatapanelGUI* thisptr)
{
    ArgPusher1<DatapanelGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DatapanelGUI::clearCategoryTabs", &pusher);
}


// -----------------------------------------------------------
// Callbacks for hooks in DataPanelLine.h
// -----------------------------------------------------------

void CallDataPanelLineDestructorCallbacks(DataPanelLine* thisptr)
{
    ArgPusher1<DataPanelLine*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine::_DESTRUCTOR", &pusher);
}

void CallDataPanelLineSetVisibleCallbacks(DataPanelLine* thisptr, bool on)
{
    ArgPusher2<DataPanelLine*, bool> pusher(thisptr, on);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine::_NV_setVisible", &pusher);
}

void CallDataPanelLineSetEnabledCallbacks(DataPanelLine* thisptr, bool on)
{
    ArgPusher2<DataPanelLine*, bool> pusher(thisptr, on);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine::_NV_setEnabled", &pusher);
}

void CallDataPanelLineRefreshCallbacks(DataPanelLine* thisptr)
{
    ArgPusher1<DataPanelLine*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine::_NV_refresh", &pusher);
}

void CallDataPanelLineCreateMeCallbacks(DataPanelLine* thisptr, DatapanelGUI* parent, float top, bool lastLine)
{
    ArgPusher4<DataPanelLine*, DatapanelGUI*, float, bool> pusher(thisptr, parent, top, lastLine);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine::_NV_createMe", &pusher);
}

void CallDataPanelLineResizeCallbacks(DataPanelLine* thisptr, int width, int height)
{
    ArgPusher3<DataPanelLine*, int, int> pusher(thisptr, width, height);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine::_NV_resize", &pusher);
}

int CallDataPanelLineGetBottomCallbacks(DataPanelLine* thisptr, int defaultVal)
{
    ArgPusher2<DataPanelLine*, int> pusher(thisptr, defaultVal);
    return (int)KenshiLua::EventSystem::get().callHandlersNumber("DataPanelLine::_NV_getBottom", &pusher, defaultVal);
}

void CallDataPanelLineFactionConstructedCallbacks(DataPanelLine_Faction* thisptr, const std::string& a, const std::string& b, int cat, float vv1, float vv2)
{
    ArgPusher6<DataPanelLine_Faction*, const std::string&, const std::string&, int, float, float> pusher(thisptr, a, b, cat, vv1, vv2);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Faction::_CONSTRUCTOR", &pusher);
}

void CallDataPanelLineFactionCreateMeCallbacks(DataPanelLine_Faction* thisptr, DatapanelGUI* parent, float top, bool lastLine)
{
    ArgPusher4<DataPanelLine_Faction*, DatapanelGUI*, float, bool> pusher(thisptr, parent, top, lastLine);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Faction::_NV_createMe", &pusher);
}

void CallDataPanelLineFactionDestructorCallbacks(DataPanelLine_Faction* thisptr)
{
    ArgPusher1<DataPanelLine_Faction*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Faction::_DESTRUCTOR", &pusher);
}

void CallDataPanelLineResearchConstructedCallbacks(DataPanelLine_Research* thisptr, const std::string& a, const std::string& b, int cat, float vv1, const std::string& barColor, bool Xbut)
{
    ArgPusher7<DataPanelLine_Research*, const std::string&, const std::string&, int, float, const std::string&, bool> pusher(thisptr, a, b, cat, vv1, barColor, Xbut);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Research::_CONSTRUCTOR", &pusher);
}

void CallDataPanelLineResearchCreateMeCallbacks(DataPanelLine_Research* thisptr, DatapanelGUI* parent, float top, bool lastLine)
{
    ArgPusher4<DataPanelLine_Research*, DatapanelGUI*, float, bool> pusher(thisptr, parent, top, lastLine);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Research::_NV_createMe", &pusher);
}

void CallDataPanelLineResearchDestructorCallbacks(DataPanelLine_Research* thisptr)
{
    ArgPusher1<DataPanelLine_Research*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Research::_DESTRUCTOR", &pusher);
}

void CallDataPanelLineButtonConstructedCallbacks(DataPanelLine_Button* thisptr, const std::string& a, const std::string& b, int cat, float w, const std::string& skin)
{
    ArgPusher6<DataPanelLine_Button*, const std::string&, const std::string&, int, float, const std::string&> pusher(thisptr, a, b, cat, w, skin);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Button::_CONSTRUCTOR", &pusher);
}

void CallDataPanelLineButtonGetUserDataCallbacks(DataPanelLine_Button* thisptr, const hand& result)
{
    ArgPusher2<DataPanelLine_Button*, const hand&> pusher(thisptr, result);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Button::_NV_getUserData", &pusher);
}

void CallDataPanelLineButtonCreateMeCallbacks(DataPanelLine_Button* thisptr, DatapanelGUI* parent, float top, bool lastLine)
{
    ArgPusher4<DataPanelLine_Button*, DatapanelGUI*, float, bool> pusher(thisptr, parent, top, lastLine);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Button::_NV_createMe", &pusher);
}

void CallDataPanelLineButtonDestructorCallbacks(DataPanelLine_Button* thisptr)
{
    ArgPusher1<DataPanelLine_Button*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Button::_DESTRUCTOR", &pusher);
}

void CallDataPanelLineSliderEditableSetEditableValuePtrCallbacks(DataPanelLine_SliderEditable* thisptr, void* val, float lo, float hi)
{
    ArgPusher4<DataPanelLine_SliderEditable*, void*, float, float> pusher(thisptr, val, lo, hi);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_SliderEditable::setEditableValuePtr", &pusher);
}

void CallDataPanelLineSliderEditableUpdateValuePtrCallbacks(DataPanelLine_SliderEditable* thisptr, void* ptr)
{
    ArgPusher2<DataPanelLine_SliderEditable*, void*> pusher(thisptr, ptr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_SliderEditable::_NV_updateValuePtr", &pusher);
}

void CallDataPanelLineSliderEditableSetValueCallbacks(DataPanelLine_SliderEditable* thisptr, float v)
{
    ArgPusher2<DataPanelLine_SliderEditable*, float> pusher(thisptr, v);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_SliderEditable::setValue", &pusher);
}

void CallDataPanelLineSliderEditableRefreshCallbacks(DataPanelLine_SliderEditable* thisptr)
{
    ArgPusher1<DataPanelLine_SliderEditable*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_SliderEditable::_NV_refresh", &pusher);
}

void CallDataPanelLineSliderEditableSetPrecisionCallbacks(DataPanelLine_SliderEditable* thisptr, int dp)
{
    ArgPusher2<DataPanelLine_SliderEditable*, int> pusher(thisptr, dp);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_SliderEditable::setPrecision", &pusher);
}

void CallDataPanelLineSliderEditableConstructedCallbacks(DataPanelLine_SliderEditable* thisptr, const std::string& text, int category, bool showName, float min, float max, void* value)
{
    ArgPusher7<DataPanelLine_SliderEditable*, const std::string&, int, bool, float, float, void*> pusher(thisptr, text, category, showName, min, max, value);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_SliderEditable::_CONSTRUCTOR", &pusher);
}

void CallDataPanelLineSliderEditableCreateMeCallbacks(DataPanelLine_SliderEditable* thisptr, DatapanelGUI* parent, float top, bool lastLine)
{
    ArgPusher4<DataPanelLine_SliderEditable*, DatapanelGUI*, float, bool> pusher(thisptr, parent, top, lastLine);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_SliderEditable::_NV_createMe", &pusher);
}

void CallDataPanelLineSliderEditableEditCallbackCallbacks(DataPanelLine_SliderEditable* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<DataPanelLine_SliderEditable*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_SliderEditable::editCallback", &pusher);
}

void CallDataPanelLineSliderEditableSliderCallbackCallbacks(DataPanelLine_SliderEditable* thisptr, MyGUI::Widget* sender, int position)
{
    ArgPusher3<DataPanelLine_SliderEditable*, KenshiLua::WidgetArg, int> pusher(thisptr, sender, position);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_SliderEditable::sliderCallback", &pusher);
}

void CallDataPanelLineSliderEditableDestructorCallbacks(DataPanelLine_SliderEditable* thisptr)
{
    ArgPusher1<DataPanelLine_SliderEditable*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_SliderEditable::_DESTRUCTOR", &pusher);
}

void CallDataPanelLineTextConstructedCallbacks(DataPanelLine_Text* thisptr, const std::string& key, const std::string& text, int category, bool wordWrap, int textAlign)
{
    ArgPusher6<DataPanelLine_Text*, const std::string&, const std::string&, int, bool, int> pusher(thisptr, key, text, category, wordWrap, textAlign);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Text::_CONSTRUCTOR", &pusher);
}

void CallDataPanelLineTextCreateMeCallbacks(DataPanelLine_Text* thisptr, DatapanelGUI* parent, float top, bool lastLine)
{
    ArgPusher4<DataPanelLine_Text*, DatapanelGUI*, float, bool> pusher(thisptr, parent, top, lastLine);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Text::_NV_createMe", &pusher);
}

void CallDataPanelLineTextDestructorCallbacks(DataPanelLine_Text* thisptr)
{
    ArgPusher1<DataPanelLine_Text*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Text::_DESTRUCTOR", &pusher);
}

void CallDataPanelLineTextEditableConstructedCallbacks(DataPanelLine_TextEditable* thisptr, const std::string& key, const std::string& text, int category, bool showKey, bool multiLine, int textAlign, float width)
{
    ArgPusher8<DataPanelLine_TextEditable*, const std::string&, const std::string&, int, bool, bool, int, float> pusher(thisptr, key, text, category, showKey, multiLine, textAlign, width);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_TextEditable::_CONSTRUCTOR", &pusher);
}

void CallDataPanelLineTextEditableCreateMeCallbacks(DataPanelLine_TextEditable* thisptr, DatapanelGUI* parent, float top, bool lastLine)
{
    ArgPusher4<DataPanelLine_TextEditable*, DatapanelGUI*, float, bool> pusher(thisptr, parent, top, lastLine);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_TextEditable::_NV_createMe", &pusher);
}

void CallDataPanelLineTextEditableTextChangedCallbacks(DataPanelLine_TextEditable* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<DataPanelLine_TextEditable*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_TextEditable::textChanged", &pusher);
}

void CallDataPanelLineTextEditableDestructorCallbacks(DataPanelLine_TextEditable* thisptr)
{
    ArgPusher1<DataPanelLine_TextEditable*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_TextEditable::_DESTRUCTOR", &pusher);
}

void CallDataPanelLineSliderConstructedCallbacks(DataPanelLine_Slider* thisptr, const std::string& key, const std::string& text, float min, float max, int category, float scale)
{
    ArgPusher7<DataPanelLine_Slider*, const std::string&, const std::string&, float, float, int, float> pusher(thisptr, key, text, min, max, category, scale);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Slider::_CONSTRUCTOR", &pusher);
}

void CallDataPanelLineSliderSliderValueChangedCallbacks(DataPanelLine_Slider* thisptr, MyGUI::Widget* sender, int value)
{
    ArgPusher3<DataPanelLine_Slider*, KenshiLua::WidgetArg, int> pusher(thisptr, sender, value);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Slider::sliderValueChanged", &pusher);
}

void CallDataPanelLineSliderUpdateValuePtrCallbacks(DataPanelLine_Slider* thisptr, void* ptr)
{
    ArgPusher2<DataPanelLine_Slider*, void*> pusher(thisptr, ptr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Slider::_NV_updateValuePtr", &pusher);
}

void CallDataPanelLineSliderSetValueCallbacks(DataPanelLine_Slider* thisptr, float value)
{
    ArgPusher2<DataPanelLine_Slider*, float> pusher(thisptr, value);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Slider::setValue", &pusher);
}

float CallDataPanelLineSliderGetValueCallbacks(DataPanelLine_Slider* thisptr, float defaultVal)
{
    ArgPusher2<DataPanelLine_Slider*, float> pusher(thisptr, defaultVal);
    return (float)KenshiLua::EventSystem::get().callHandlersNumber("DataPanelLine_Slider::getValue", &pusher, defaultVal);
}

void CallDataPanelLineSliderRefreshCallbacks(DataPanelLine_Slider* thisptr)
{
    ArgPusher1<DataPanelLine_Slider*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Slider::_NV_refresh", &pusher);
}

void CallDataPanelLineSliderCreateMeCallbacks(DataPanelLine_Slider* thisptr, DatapanelGUI* parent, float top, bool lastLine)
{
    ArgPusher4<DataPanelLine_Slider*, DatapanelGUI*, float, bool> pusher(thisptr, parent, top, lastLine);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Slider::_NV_createMe", &pusher);
}

void CallDataPanelLineSliderDestructorCallbacks(DataPanelLine_Slider* thisptr)
{
    ArgPusher1<DataPanelLine_Slider*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Slider::_DESTRUCTOR", &pusher);
}

void CallDataPanelLineProgressSetProgressCallbacks(DataPanelLine_Progress* thisptr, float value, const std::string& text)
{
    ArgPusher3<DataPanelLine_Progress*, float, const std::string&> pusher(thisptr, value, text);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Progress::setProgress", &pusher);
}

void CallDataPanelLineProgressConstructedCallbacks(DataPanelLine_Progress* thisptr, const std::string& key, int category, bool showKey)
{
    ArgPusher4<DataPanelLine_Progress*, const std::string&, int, bool> pusher(thisptr, key, category, showKey);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Progress::_CONSTRUCTOR", &pusher);
}

void CallDataPanelLineProgressCreateMeCallbacks(DataPanelLine_Progress* thisptr, DatapanelGUI* parent, float top, bool lastLine)
{
    ArgPusher4<DataPanelLine_Progress*, DatapanelGUI*, float, bool> pusher(thisptr, parent, top, lastLine);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Progress::_NV_createMe", &pusher);
}

void CallDataPanelLineProgressDestructorCallbacks(DataPanelLine_Progress* thisptr)
{
    ArgPusher1<DataPanelLine_Progress*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_Progress::_DESTRUCTOR", &pusher);
}

void CallDataPanelLineCheckBoxUpdateValuePtrCallbacks(DataPanelLine_CheckBox* thisptr, void* ptr)
{
    ArgPusher2<DataPanelLine_CheckBox*, void*> pusher(thisptr, ptr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_CheckBox::_NV_updateValuePtr", &pusher);
}

void CallDataPanelLineCheckBoxRefreshCallbacks(DataPanelLine_CheckBox* thisptr)
{
    ArgPusher1<DataPanelLine_CheckBox*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_CheckBox::_NV_refresh", &pusher);
}

void CallDataPanelLineCheckBoxSetValueCallbacks(DataPanelLine_CheckBox* thisptr, bool checked)
{
    ArgPusher2<DataPanelLine_CheckBox*, bool> pusher(thisptr, checked);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_CheckBox::setValue", &pusher);
}

void CallDataPanelLineCheckBoxSetValuePtrCallbacks(DataPanelLine_CheckBox* thisptr, void* valPtr)
{
    ArgPusher2<DataPanelLine_CheckBox*, void*> pusher(thisptr, valPtr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_CheckBox::setValuePtr", &pusher);
}

void CallDataPanelLineCheckBoxConstructedCallbacks(DataPanelLine_CheckBox* thisptr, const std::string& key, int cat, void* val)
{
    ArgPusher4<DataPanelLine_CheckBox*, const std::string&, int, void*> pusher(thisptr, key, cat, val);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_CheckBox::_CONSTRUCTOR", &pusher);
}

void CallDataPanelLineCheckBoxNotifyToggleCheckCallbacks(DataPanelLine_CheckBox* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<DataPanelLine_CheckBox*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_CheckBox::notifyToggleCheck", &pusher);
}

void CallDataPanelLineCheckBoxCreateMeCallbacks(DataPanelLine_CheckBox* thisptr, DatapanelGUI* parent, float topReal, bool lastLine)
{
    ArgPusher4<DataPanelLine_CheckBox*, DatapanelGUI*, float, bool> pusher(thisptr, parent, topReal, lastLine);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_CheckBox::_NV_createMe", &pusher);
}

void CallDataPanelLineCheckBoxDestructorCallbacks(DataPanelLine_CheckBox* thisptr)
{
    ArgPusher1<DataPanelLine_CheckBox*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_CheckBox::_DESTRUCTOR", &pusher);
}

void CallDataPanelLineDropBoxAddAValueCallbacks(DataPanelLine_DropBox* thisptr, const std::string& key, int val)
{
    ArgPusher3<DataPanelLine_DropBox*, const std::string&, int> pusher(thisptr, key, val);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_DropBox::addAValue", &pusher);
}

int CallDataPanelLineDropBoxGetSelectedValueCallbacks(DataPanelLine_DropBox* thisptr, int defaultVal)
{
    ArgPusher2<DataPanelLine_DropBox*, int> pusher(thisptr, defaultVal);
    return (int)KenshiLua::EventSystem::get().callHandlersNumber("DataPanelLine_DropBox::getSelectedValue", &pusher, defaultVal);
}

void CallDataPanelLineDropBoxSetSelectedValueCallbacks(DataPanelLine_DropBox* thisptr, int val)
{
    ArgPusher2<DataPanelLine_DropBox*, int> pusher(thisptr, val);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_DropBox::setSelectedValue", &pusher);
}

void CallDataPanelLineDropBoxGetSelectedTextCallbacks(DataPanelLine_DropBox* thisptr, const std::string& result)
{
    ArgPusher2<DataPanelLine_DropBox*, const std::string&> pusher(thisptr, result);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_DropBox::getSelectedText", &pusher);
}

void CallDataPanelLineDropBoxClearValuesCallbacks(DataPanelLine_DropBox* thisptr)
{
    ArgPusher1<DataPanelLine_DropBox*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_DropBox::clearValues", &pusher);
}

void CallDataPanelLineDropBoxCreateMeCallbacks(DataPanelLine_DropBox* thisptr, DatapanelGUI* parent, float top, bool lastLine)
{
    ArgPusher4<DataPanelLine_DropBox*, DatapanelGUI*, float, bool> pusher(thisptr, parent, top, lastLine);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_DropBox::_NV_createMe", &pusher);
}

void CallDataPanelLineDropBoxUpdateValuePtrCallbacks(DataPanelLine_DropBox* thisptr, void* ptr)
{
    ArgPusher2<DataPanelLine_DropBox*, void*> pusher(thisptr, ptr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_DropBox::_NV_updateValuePtr", &pusher);
}

void CallDataPanelLineDropBoxRefreshCallbacks(DataPanelLine_DropBox* thisptr)
{
    ArgPusher1<DataPanelLine_DropBox*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_DropBox::_NV_refresh", &pusher);
}

void CallDataPanelLineDropBoxConstructedCallbacks(DataPanelLine_DropBox* thisptr, const std::string& text, int category, void* valuePtr, float width, bool hasGobox)
{
    ArgPusher6<DataPanelLine_DropBox*, const std::string&, int, void*, float, bool> pusher(thisptr, text, category, valuePtr, width, hasGobox);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_DropBox::_CONSTRUCTOR", &pusher);
}

void CallDataPanelLineDropBoxSelectionChangeCallbacks(DataPanelLine_DropBox* thisptr, MyGUI::Widget* sender, int i)
{
    ArgPusher3<DataPanelLine_DropBox*, KenshiLua::WidgetArg, int> pusher(thisptr, sender, i);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_DropBox::selectionChange", &pusher);
}

void CallDataPanelLineDropBoxGoPressedCallbacks(DataPanelLine_DropBox* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<DataPanelLine_DropBox*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_DropBox::goPressed", &pusher);
}

void CallDataPanelLineDropBoxDestructorCallbacks(DataPanelLine_DropBox* thisptr)
{
    ArgPusher1<DataPanelLine_DropBox*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_DropBox::_DESTRUCTOR", &pusher);
}

void CallDataPanelLineKeyConfigConstructedCallbacks(DataPanelLine_KeyConfig* thisptr, const std::string& cmd, const std::string& text, int cat)
{
    ArgPusher4<DataPanelLine_KeyConfig*, const std::string&, const std::string&, int> pusher(thisptr, cmd, text, cat);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_KeyConfig::_CONSTRUCTOR", &pusher);
}

void CallDataPanelLineKeyConfigGetCommandCallbacks(DataPanelLine_KeyConfig* thisptr, const std::string& result)
{
    ArgPusher2<DataPanelLine_KeyConfig*, const std::string&> pusher(thisptr, result);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_KeyConfig::getCommand", &pusher);
}

int CallDataPanelLineKeyConfigOldKeyCallbacks(DataPanelLine_KeyConfig* thisptr, int defaultVal)
{
    ArgPusher2<DataPanelLine_KeyConfig*, int> pusher(thisptr, defaultVal);
    return (int)KenshiLua::EventSystem::get().callHandlersNumber("DataPanelLine_KeyConfig::oldKey", &pusher, defaultVal);
}

void CallDataPanelLineKeyConfigSetKeyCallbacks(DataPanelLine_KeyConfig* thisptr, const std::string& s)
{
    ArgPusher2<DataPanelLine_KeyConfig*, const std::string&> pusher(thisptr, s);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_KeyConfig::setKey", &pusher);
}

void CallDataPanelLineKeyConfigEraseKeyCallbacks(DataPanelLine_KeyConfig* thisptr, const std::string& key)
{
    ArgPusher2<DataPanelLine_KeyConfig*, const std::string&> pusher(thisptr, key);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_KeyConfig::eraseKey", &pusher);
}

void CallDataPanelLineKeyConfigRefreshCallbacks(DataPanelLine_KeyConfig* thisptr)
{
    ArgPusher1<DataPanelLine_KeyConfig*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_KeyConfig::_NV_refresh", &pusher);
}

void CallDataPanelLineKeyConfigCancelCallbacks(DataPanelLine_KeyConfig* thisptr)
{
    ArgPusher1<DataPanelLine_KeyConfig*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_KeyConfig::cancel", &pusher);
}

void CallDataPanelLineKeyConfigCreateMeCallbacks(DataPanelLine_KeyConfig* thisptr, DatapanelGUI* p, float vpos, bool lastLine)
{
    ArgPusher4<DataPanelLine_KeyConfig*, DatapanelGUI*, float, bool> pusher(thisptr, p, vpos, lastLine);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_KeyConfig::_NV_createMe", &pusher);
}

void CallDataPanelLineKeyConfigClickButtonCallbacks(DataPanelLine_KeyConfig* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<DataPanelLine_KeyConfig*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_KeyConfig::clickButton", &pusher);
}

void CallDataPanelLineKeyConfigDestructorCallbacks(DataPanelLine_KeyConfig* thisptr)
{
    ArgPusher1<DataPanelLine_KeyConfig*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DataPanelLine_KeyConfig::_DESTRUCTOR", &pusher);
}


// -----------------------------------------------------------
// Callbacks for hooks in ForgottenGUI.h
// -----------------------------------------------------------

void CallForgottenGUIConstructedCallbacks(ForgottenGUI* thisptr)
{
    ArgPusher1<ForgottenGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::_CONSTRUCTOR", &pusher);
}

void CallForgottenGUIDestructorCallbacks(ForgottenGUI* thisptr)
{
    ArgPusher1<ForgottenGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::_DESTRUCTOR", &pusher);
}

void CallForgottenGUIClearGUICallbacks(ForgottenGUI* thisptr)
{
    ArgPusher1<ForgottenGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::clearGUI", &pusher);
}

void CallForgottenGUIShutDownCallbacks(ForgottenGUI* thisptr)
{
    ArgPusher1<ForgottenGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::shutDown", &pusher);
}

void CallForgottenGUIRestartCallbacks(ForgottenGUI* thisptr)
{
    ArgPusher1<ForgottenGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::restart", &pusher);
}

void CallForgottenGUIChangeFontSizeCallbacks()
{
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::changeFontSize", NULL);
}

void CallForgottenGUISetupGuiScalingCallbacks(ForgottenGUI* thisptr)
{
    ArgPusher1<ForgottenGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::setupGuiScaling", &pusher);
}

void CallForgottenGUIInitCallbacks(ForgottenGUI* thisptr)
{
    ArgPusher1<ForgottenGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::init", &pusher);
}

float CallForgottenGUIGetTopOfScreenMessagePositionCallbacks(ForgottenGUI* thisptr, float defaultVal)
{
    ArgPusher2<ForgottenGUI*, float> pusher(thisptr, defaultVal);
    return (float)KenshiLua::EventSystem::get().callHandlersNumber("ForgottenGUI::getTopOfScreenMessagePosition", &pusher, defaultVal);
}

void CallForgottenGUIShowLoadingMessageCallbacks(ForgottenGUI* thisptr, bool on)
{
    ArgPusher2<ForgottenGUI*, bool> pusher(thisptr, on);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::showLoadingMessage", &pusher);
}

bool CallForgottenGUIIsLoadingMessageVisibleCallbacks(ForgottenGUI* thisptr, bool defaultVal)
{
    ArgPusher2<ForgottenGUI*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("ForgottenGUI::isLoadingMessageVisible", &pusher, defaultVal);
}

void CallForgottenGUIShowPauseMessageCallbacks(ForgottenGUI* thisptr, bool on)
{
    ArgPusher2<ForgottenGUI*, bool> pusher(thisptr, on);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::showPauseMessage", &pusher);
}

bool CallForgottenGUIIsLoadingCallbacks(ForgottenGUI* thisptr, bool defaultVal)
{
    ArgPusher2<ForgottenGUI*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("ForgottenGUI::isLoading", &pusher, defaultVal);
}

void CallForgottenGUISetLoadingCallbacks(ForgottenGUI* thisptr, bool value)
{
    ArgPusher2<ForgottenGUI*, bool> pusher(thisptr, value);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::setLoading", &pusher);
}

bool CallForgottenGUIIsPausedCallbacks(ForgottenGUI* thisptr, bool defaultVal)
{
    ArgPusher2<ForgottenGUI*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("ForgottenGUI::isPaused", &pusher, defaultVal);
}

bool CallForgottenGUIInDialogueCallbacks(ForgottenGUI* thisptr, bool defaultVal)
{
    ArgPusher2<ForgottenGUI*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("ForgottenGUI::inDialogue", &pusher, defaultVal);
}

void CallForgottenGUIMessageBoxCallbacks(ForgottenGUI* thisptr, const std::string& title, const std::string& message, int btn, bool modal, void* callback, MyGUI::Widget* result)
{
    ArgPusher7<ForgottenGUI*, const std::string&, const std::string&, int, bool, void*, KenshiLua::WidgetArg> pusher(thisptr, title, message, btn, modal, callback, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::messageBox", &pusher);
}

void CallForgottenGUIHideMessageBoxCallbacks(ForgottenGUI* thisptr, bool enter, bool result)
{
    ArgPusher3<ForgottenGUI*, bool, bool> pusher(thisptr, enter, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::hideMessageBox", &pusher);
}

bool CallForgottenGUIHasModalMessageCallbacks(ForgottenGUI* thisptr, bool defaultVal)
{
    ArgPusher2<ForgottenGUI*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("ForgottenGUI::hasModalMessage", &pusher, defaultVal);
}

void CallForgottenGUIShowMainbarCallbacks(ForgottenGUI* thisptr, bool on)
{
    ArgPusher2<ForgottenGUI*, bool> pusher(thisptr, on);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::showMainbar", &pusher);
}

void CallForgottenGUIUpdateBountyPanelVisibilityCallbacks(ForgottenGUI* thisptr)
{
    ArgPusher1<ForgottenGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::updateBountyPanelVisibility", &pusher);
}

bool CallForgottenGUIGetInDialogueCallbacks(ForgottenGUI* thisptr, bool defaultVal)
{
    ArgPusher2<ForgottenGUI*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("ForgottenGUI::getInDialogue", &pusher, defaultVal);
}

ToolTip* CallForgottenGUIGetToolTipCallbacks(ForgottenGUI* thisptr, ToolTip* defaultVal)
{
    ArgPusher2<ForgottenGUI*, ToolTip*> pusher(thisptr, defaultVal);
    return static_cast<ToolTip*>(KenshiLua::EventSystem::get().callHandlersObject("ForgottenGUI::getToolTip", KenshiLua::ToolTipMetatable(), &pusher));
}

void CallForgottenGUIToggleCallbacks(ForgottenGUI* thisptr)
{
    ArgPusher1<ForgottenGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::toggle", &pusher);
}

void CallForgottenGUIShowNamesCallbacks(ForgottenGUI* thisptr, bool on)
{
    ArgPusher2<ForgottenGUI*, bool> pusher(thisptr, on);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::showNames", &pusher);
}

void CallForgottenGUIShowPrintOutputCallbacks(ForgottenGUI* thisptr, bool v)
{
    ArgPusher2<ForgottenGUI*, bool> pusher(thisptr, v);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::showPrintOutput", &pusher);
}

void CallForgottenGUIShowCharacterEditorCallbacks(ForgottenGUI* thisptr, const lektor<Character*>& characters, int mode, const Ogre::vector<GameDataReference>::type* races)
{
    ArgPusher4<ForgottenGUI*, const lektor<Character*>&, int, const Ogre::vector<GameDataReference>::type*> pusher(thisptr, characters, mode, races);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::showCharacterEditor", &pusher);
}

void CallForgottenGUICloseCharacterEditorCallbacks(ForgottenGUI* thisptr)
{
    ArgPusher1<ForgottenGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::closeCharacterEditor", &pusher);
}

void CallForgottenGUIShowCharacterStatsWindowCallbacks(ForgottenGUI* thisptr, const hand& owner)
{
    ArgPusher2<ForgottenGUI*, const hand&> pusher(thisptr, owner);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::showCharacterStatsWindow", &pusher);
}

void CallForgottenGUICloseCharacterStatsWindowCallbacks(ForgottenGUI* thisptr, const hand& owner)
{
    ArgPusher2<ForgottenGUI*, const hand&> pusher(thisptr, owner);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::closeCharacterStatsWindow", &pusher);
}

void CallForgottenGUICloseAllCharacterStatsWindowsCallbacks(ForgottenGUI* thisptr)
{
    ArgPusher1<ForgottenGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::closeAllCharacterStatsWindows", &pusher);
}

bool CallForgottenGUIIsStatsWindowOpenCallbacks(ForgottenGUI* thisptr, bool defaultVal)
{
    ArgPusher2<ForgottenGUI*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("ForgottenGUI::isStatsWindowOpen", &pusher, defaultVal);
}

void CallForgottenGUIToggleStatsWindowCallbacks(ForgottenGUI* thisptr, const hand& owner)
{
    ArgPusher2<ForgottenGUI*, const hand&> pusher(thisptr, owner);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::toggleStatsWindow", &pusher);
}

void CallForgottenGUIToggleCharacterStatsWindowPermanentCallbacks(ForgottenGUI* thisptr, const hand& owner)
{
    ArgPusher2<ForgottenGUI*, const hand&> pusher(thisptr, owner);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::toggleCharacterStatsWindowPermanent", &pusher);
}

void CallForgottenGUISelectedObjectsChangedCallbacks(ForgottenGUI* thisptr)
{
    ArgPusher1<ForgottenGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::selectedObjectsChanged", &pusher);
}

void CallForgottenGUIUpdateToOrdersPanelCallbacks(ForgottenGUI* thisptr)
{
    ArgPusher1<ForgottenGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::updateToOrdersPanel", &pusher);
}

void CallForgottenGUINotifyTownDeletedCallbacks(ForgottenGUI* thisptr, Town* t)
{
    ArgPusher2<ForgottenGUI*, Town*> pusher(thisptr, t);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::notifyTownDeleted", &pusher);
}

void CallForgottenGUIUpdateCallbacks(ForgottenGUI* thisptr)
{
    ArgPusher1<ForgottenGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::update", &pusher);
}

void CallForgottenGUIShowTradeWindowCallbacks(ForgottenGUI* thisptr, const hand& a, const hand& b, int type)
{
    ArgPusher4<ForgottenGUI*, const hand&, const hand&, int> pusher(thisptr, a, b, type);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::showTradeWindow", &pusher);
}

void CallForgottenGUICloseTradeWindowCallbacks(ForgottenGUI* thisptr)
{
    ArgPusher1<ForgottenGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::closeTradeWindow", &pusher);
}

void CallForgottenGUIShowInventoryCallbacks(ForgottenGUI* thisptr, const hand& owner, bool autoPosition, float x, float y, InventoryGUI* result)
{
    ArgPusher6<ForgottenGUI*, const hand&, bool, float, float, InventoryGUI*> pusher(thisptr, owner, autoPosition, x, y, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::showInventory", &pusher);
}

void CallForgottenGUIShowTraderInventoryCallbacks(ForgottenGUI* thisptr, const hand& owner, InventoryGUI* result)
{
    ArgPusher3<ForgottenGUI*, const hand&, InventoryGUI*> pusher(thisptr, owner, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::showTraderInventory", &pusher);
}

void CallForgottenGUIShowInventoryBuildingCallbacks(ForgottenGUI* thisptr, const hand& owner, InventoryGUI* result)
{
    ArgPusher3<ForgottenGUI*, const hand&, InventoryGUI*> pusher(thisptr, owner, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::showInventoryBuilding", &pusher);
}

void CallForgottenGUIShowInventoryNPCCallbacks(ForgottenGUI* thisptr, const hand& owner, InventoryGUI* result)
{
    ArgPusher3<ForgottenGUI*, const hand&, InventoryGUI*> pusher(thisptr, owner, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::showInventoryNPC", &pusher);
}

void CallForgottenGUICloseInventoryCallbacks(ForgottenGUI* thisptr, const hand& owner)
{
    ArgPusher2<ForgottenGUI*, const hand&> pusher(thisptr, owner);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::closeInventory", &pusher);
}

void CallForgottenGUICloseInventoryBuildingCallbacks(ForgottenGUI* thisptr)
{
    ArgPusher1<ForgottenGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::closeInventoryBuilding", &pusher);
}

void CallForgottenGUICloseAllInventoriesCallbacks(ForgottenGUI* thisptr)
{
    ArgPusher1<ForgottenGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::closeAllInventories", &pusher);
}

void CallForgottenGUICloseAllWindowsCallbacks(ForgottenGUI* thisptr)
{
    ArgPusher1<ForgottenGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::closeAllWindows", &pusher);
}

InventoryGUI* CallForgottenGUIGetInventoryWindowCallbacks(ForgottenGUI* thisptr, const hand& who, InventoryGUI* defaultVal)
{
    ArgPusher3<ForgottenGUI*, const hand&, InventoryGUI*> pusher(thisptr, who, defaultVal);
    return static_cast<InventoryGUI*>(KenshiLua::EventSystem::get().callHandlersObject("ForgottenGUI::getInventoryWindow", KenshiLua::InventoryGUIMetatable(), &pusher));
}

void CallForgottenGUIToggleInventoryCallbacks(ForgottenGUI* thisptr, const hand& owner, InventoryGUI* parentInv, bool attached, InventoryGUI* result)
{
    ArgPusher5<ForgottenGUI*, const hand&, InventoryGUI*, bool, InventoryGUI*> pusher(thisptr, owner, parentInv, attached, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::toggleInventory", &pusher);
}

int CallForgottenGUIGetNumOpenInventoryWindowsCallbacks(ForgottenGUI* thisptr, int defaultVal)
{
    ArgPusher2<ForgottenGUI*, int> pusher(thisptr, defaultVal);
    return (int)KenshiLua::EventSystem::get().callHandlersNumber("ForgottenGUI::getNumOpenInventoryWindows", &pusher, defaultVal);
}

InventoryGUI* CallForgottenGUIGetInventoryWindowWithMouseCallbacks(ForgottenGUI* thisptr, InventoryGUI* defaultVal)
{
    ArgPusher2<ForgottenGUI*, InventoryGUI*> pusher(thisptr, defaultVal);
    return static_cast<InventoryGUI*>(KenshiLua::EventSystem::get().callHandlersObject("ForgottenGUI::getInventoryWindowWithMouse", KenshiLua::InventoryGUIMetatable(), &pusher));
}

bool CallForgottenGUIHasInventoryWindowOpenCallbacks(ForgottenGUI* thisptr, const hand& obj, bool defaultVal)
{
    ArgPusher3<ForgottenGUI*, const hand&, bool> pusher(thisptr, obj, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("ForgottenGUI::hasInventoryWindowOpen", &pusher, defaultVal);
}

bool CallForgottenGUIIsAnyInventoryWindowOpenCallbacks(ForgottenGUI* thisptr, bool defaultVal)
{
    ArgPusher2<ForgottenGUI*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("ForgottenGUI::isAnyInventoryWindowOpen", &pusher, defaultVal);
}

void CallForgottenGUIToggleInventoryWindowPermanentCallbacks(ForgottenGUI* thisptr, const hand& owner)
{
    ArgPusher2<ForgottenGUI*, const hand&> pusher(thisptr, owner);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::toggleInventoryWindowPermanent", &pusher);
}

void CallForgottenGUIToggleHelpWindowCallbacks(ForgottenGUI* thisptr)
{
    ArgPusher1<ForgottenGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::toggleHelpWindow", &pusher);
}

void CallForgottenGUIAddWindowToUpdateListCallbacks(ForgottenGUI* thisptr, GUIWindow* win)
{
    ArgPusher2<ForgottenGUI*, GUIWindow*> pusher(thisptr, win);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::addWindowToUpdateList", &pusher);
}

void CallForgottenGUIRemoveWindowFromUpdateListCallbacks(ForgottenGUI* thisptr, GUIWindow* win)
{
    ArgPusher2<ForgottenGUI*, GUIWindow*> pusher(thisptr, win);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::removeWindowFromUpdateList", &pusher);
}

void CallForgottenGUIAddScreenLabelCallbacks(ForgottenGUI* thisptr, ScreenLabelInterface* label)
{
    ArgPusher2<ForgottenGUI*, ScreenLabelInterface*> pusher(thisptr, label);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::addScreenLabel", &pusher);
}

void CallForgottenGUIAddDatapanelToUpdateListCallbacks(ForgottenGUI* thisptr, DatapanelGUI* datapanel)
{
    ArgPusher2<ForgottenGUI*, DatapanelGUI*> pusher(thisptr, datapanel);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::addDatapanelToUpdateList", &pusher);
}

void CallForgottenGUIRemoveDatapanelFromUpdateListCallbacks(ForgottenGUI* thisptr, DatapanelGUI* datapanel)
{
    ArgPusher2<ForgottenGUI*, DatapanelGUI*> pusher(thisptr, datapanel);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::removeDatapanelFromUpdateList", &pusher);
}

void CallForgottenGUIDestroyWidgetCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* widget)
{
    ArgPusher2<ForgottenGUI*, KenshiLua::WidgetArg> pusher(thisptr, widget);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::destroyWidget", &pusher);
}

bool CallForgottenGUIWidgetHasMouseCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* w, bool defaultVal)
{
    ArgPusher3<ForgottenGUI*, KenshiLua::WidgetArg, bool> pusher(thisptr, w, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("ForgottenGUI::widgetHasMouse", &pusher, defaultVal);
}

void CallForgottenGUISetupCallbacks(ForgottenGUI* thisptr, void* mRoot, void* window)
{
    ArgPusher3<ForgottenGUI*, void*, void*> pusher(thisptr, mRoot, window);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::setup", &pusher);
}

void CallForgottenGUISetMouseCursorVisibleCallbacks(ForgottenGUI* thisptr, bool visible)
{
    ArgPusher2<ForgottenGUI*, bool> pusher(thisptr, visible);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::setMouseCursorVisible", &pusher);
}

void CallForgottenGUI_showTradeWindowCallbacks(ForgottenGUI* thisptr, RootObject* a, RootObject* b, int tradeType)
{
    ArgPusher4<ForgottenGUI*, RootObject*, RootObject*, int> pusher(thisptr, a, b, tradeType);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::_showTradeWindow", &pusher);
}

void CallForgottenGUISetInventoryPositionCallbacks(ForgottenGUI* thisptr, const hand& owner, InventoryGUI* inventory)
{
    ArgPusher3<ForgottenGUI*, const hand&, InventoryGUI*> pusher(thisptr, owner, inventory);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::setInventoryPosition", &pusher);
}

void CallForgottenGUIInventoriesSelectedObjectUpdateCallbacks(ForgottenGUI* thisptr, const hand& selectedObject)
{
    ArgPusher2<ForgottenGUI*, const hand&> pusher(thisptr, selectedObject);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::inventoriesSelectedObjectUpdate", &pusher);
}

void CallForgottenGUIKeepWindownOnScreenCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* win)
{
    ArgPusher2<ForgottenGUI*, KenshiLua::WidgetArg> pusher(thisptr, win);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::keepWindownOnScreen", &pusher);
}

void CallForgottenGUIGetDataLineColorCallbacks(ForgottenGUI* thisptr, int actualVal, int normalVal, const std::string& result)
{
    ArgPusher4<ForgottenGUI*, int, int, const std::string&> pusher(thisptr, actualVal, normalVal, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::getDataLineColor", &pusher);
}

void CallForgottenGUICreatePanelCallbacks(ForgottenGUI* thisptr, const std::string& name, float top, float left, float width, float height, const std::string& layer, const std::string& skin, MyGUI::Widget* result)
{
    ArgPusher9<ForgottenGUI*, const std::string&, float, float, float, float, const std::string&, const std::string&, KenshiLua::WidgetArg> pusher(thisptr, name, top, left, width, height, layer, skin, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::createPanel", &pusher);
}

void CallForgottenGUICreatePanelAbsCallbacks(ForgottenGUI* thisptr, const std::string& name, float top, float left, float width, float height, const std::string& layer, const std::string& skin, MyGUI::Widget* result)
{
    ArgPusher9<ForgottenGUI*, const std::string&, float, float, float, float, const std::string&, const std::string&, KenshiLua::WidgetArg> pusher(thisptr, name, top, left, width, height, layer, skin, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::createPanelAbs", &pusher);
}

void CallForgottenGUICreateImageCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, float top, float left, float width, float height, const std::string& image, MyGUI::Widget* result)
{
    ArgPusher8<ForgottenGUI*, KenshiLua::WidgetArg, float, float, float, float, const std::string&, KenshiLua::WidgetArg> pusher(thisptr, parent, top, left, width, height, image, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::createImage", &pusher);
}

void CallForgottenGUICreateImageAbsCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, int top, int left, int width, int height, const std::string& image, MyGUI::Widget* result)
{
    ArgPusher8<ForgottenGUI*, KenshiLua::WidgetArg, int, int, int, int, const std::string&, KenshiLua::WidgetArg> pusher(thisptr, parent, top, left, width, height, image, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::createImageAbs", &pusher);
}

void CallForgottenGUICreateRotatableImageAbsCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, int top, int left, int width, int height, const std::string& image, MyGUI::Widget* result)
{
    ArgPusher8<ForgottenGUI*, KenshiLua::WidgetArg, int, int, int, int, const std::string&, KenshiLua::WidgetArg> pusher(thisptr, parent, top, left, width, height, image, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::createRotatableImageAbs", &pusher);
}

void CallForgottenGUICreateTabPanelCallbacks(ForgottenGUI* thisptr, const std::string& name, float top, float left, float width, float height, const std::string& layer, const std::string& skin, MyGUI::Widget* result)
{
    ArgPusher9<ForgottenGUI*, const std::string&, float, float, float, float, const std::string&, const std::string&, KenshiLua::WidgetArg> pusher(thisptr, name, top, left, width, height, layer, skin, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::createTabPanel", &pusher);
}

void CallForgottenGUICreateButtonAbsCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, int top, int left, int width, int height, const std::string& name, const std::string& text, const std::string& skin, MyGUI::Widget* result)
{
    ArgPusher10<ForgottenGUI*, KenshiLua::WidgetArg, int, int, int, int, const std::string&, const std::string&, const std::string&, KenshiLua::WidgetArg> pusher(thisptr, parent, top, left, width, height, name, text, skin, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::createButtonAbs", &pusher);
}

void CallForgottenGUICreateButtonCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, float top, float left, float width, float height, const std::string& name, const std::string& text, const std::string& skin, MyGUI::Widget* result)
{
    ArgPusher10<ForgottenGUI*, KenshiLua::WidgetArg, float, float, float, float, const std::string&, const std::string&, const std::string&, KenshiLua::WidgetArg> pusher(thisptr, parent, top, left, width, height, name, text, skin, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::createButton", &pusher);
}

void CallForgottenGUICreateDropBoxCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, const std::string& name, float top, float left, float width, float height, MyGUI::Widget* result)
{
    ArgPusher8<ForgottenGUI*, KenshiLua::WidgetArg, const std::string&, float, float, float, float, KenshiLua::WidgetArg> pusher(thisptr, parent, name, top, left, width, height, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::createDropBox", &pusher);
}

void CallForgottenGUICreateDropBoxAbsCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, const std::string& name, int top, int left, int width, int height, MyGUI::Widget* result)
{
    ArgPusher8<ForgottenGUI*, KenshiLua::WidgetArg, const std::string&, int, int, int, int, KenshiLua::WidgetArg> pusher(thisptr, parent, name, top, left, width, height, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::createDropBoxAbs", &pusher);
}

void CallForgottenGUICreateProgressBarCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, float top, float left, float width, float height, const std::string& type, MyGUI::Widget* result)
{
    ArgPusher8<ForgottenGUI*, KenshiLua::WidgetArg, float, float, float, float, const std::string&, KenshiLua::WidgetArg> pusher(thisptr, parent, top, left, width, height, type, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::createProgressBar", &pusher);
}

void CallForgottenGUICreateProgressBarAbsCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, float top, float left, float width, float height, const std::string& type, MyGUI::Widget* result)
{
    ArgPusher8<ForgottenGUI*, KenshiLua::WidgetArg, float, float, float, float, const std::string&, KenshiLua::WidgetArg> pusher(thisptr, parent, top, left, width, height, type, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::createProgressBarAbs", &pusher);
}

void CallForgottenGUICreateFloatingLabelCallbacks(ForgottenGUI* thisptr, float top, float left, float width, float height, const std::string& text, int a, const std::string& layer, MyGUI::Widget* result)
{
    ArgPusher9<ForgottenGUI*, float, float, float, float, const std::string&, int, const std::string&, KenshiLua::WidgetArg> pusher(thisptr, top, left, width, height, text, a, layer, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::createFloatingLabel", &pusher);
}

void CallForgottenGUICreateValueEditCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, float top, float left, float width, float height, const std::string& name, MyGUI::Widget* result)
{
    ArgPusher8<ForgottenGUI*, KenshiLua::WidgetArg, float, float, float, float, const std::string&, KenshiLua::WidgetArg> pusher(thisptr, parent, top, left, width, height, name, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::createValueEdit", &pusher);
}

void CallForgottenGUICreateScrollBarAbsCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, int top, int left, int width, int height, int range, int value, MyGUI::Widget* result)
{
    ArgPusher9<ForgottenGUI*, KenshiLua::WidgetArg, int, int, int, int, int, int, KenshiLua::WidgetArg> pusher(thisptr, parent, top, left, width, height, range, value, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::createScrollBarAbs", &pusher);
}

void CallForgottenGUICreateCheckboxCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, int left, int top, int width, int height, const std::string& caption, MyGUI::Widget* result)
{
    ArgPusher8<ForgottenGUI*, KenshiLua::WidgetArg, int, int, int, int, const std::string&, KenshiLua::WidgetArg> pusher(thisptr, parent, left, top, width, height, caption, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::createCheckbox", &pusher);
}

void CallForgottenGUICreateValueEditTransparentCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, float top, float left, float width, float height, const std::string& name, MyGUI::Widget* result)
{
    ArgPusher8<ForgottenGUI*, KenshiLua::WidgetArg, float, float, float, float, const std::string&, KenshiLua::WidgetArg> pusher(thisptr, parent, top, left, width, height, name, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::createValueEditTransparent", &pusher);
}

void CallForgottenGUICreateListboxCallbacks(ForgottenGUI* thisptr, MyGUI::Widget* parent, float top, float left, float width, float height, MyGUI::Widget* result)
{
    ArgPusher7<ForgottenGUI*, KenshiLua::WidgetArg, float, float, float, float, KenshiLua::WidgetArg> pusher(thisptr, parent, top, left, width, height, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::createListbox", &pusher);
}

void CallForgottenGUICreateFloatingImageCallbacks(ForgottenGUI* thisptr, const std::string& image, float top, float left, float width, float height, const std::string& layer, MyGUI::Widget* result)
{
    ArgPusher8<ForgottenGUI*, const std::string&, float, float, float, float, const std::string&, KenshiLua::WidgetArg> pusher(thisptr, image, top, left, width, height, layer, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::createFloatingImage", &pusher);
}

void CallForgottenGUICreateFloatingImageAbsCallbacks(ForgottenGUI* thisptr, const std::string& image, float top, float left, float width, float height, const std::string& layer, MyGUI::Widget* result)
{
    ArgPusher8<ForgottenGUI*, const std::string&, float, float, float, float, const std::string&, KenshiLua::WidgetArg> pusher(thisptr, image, top, left, width, height, layer, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::createFloatingImageAbs", &pusher);
}

void CallForgottenGUICreateFloatingProgressBarCallbacks(ForgottenGUI* thisptr, FloatingProgressBar* result)
{
    ArgPusher2<ForgottenGUI*, FloatingProgressBar*> pusher(thisptr, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::createFloatingProgressBar", &pusher);
}

void CallForgottenGUICreateScreenLabelCallbacks(ForgottenGUI* thisptr, const std::string& text, const MyGUI::Colour& textColour, int textSize, int risingSpeed, ScreenLabel* result)
{
    ArgPusher6<ForgottenGUI*, const std::string&, const MyGUI::Colour&, int, int, ScreenLabel*> pusher(thisptr, text, textColour, textSize, risingSpeed, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::createScreenLabel", &pusher);
}

void CallForgottenGUICreateScreenLabelDCallbacks(ForgottenGUI* thisptr, const std::string& text, float time, ScreenLabelDebug* result)
{
    ArgPusher4<ForgottenGUI*, const std::string&, float, ScreenLabelDebug*> pusher(thisptr, text, time, result);
    KenshiLua::EventSystem::get().callHandlers("ForgottenGUI::createScreenLabelD", &pusher);
}

// -----------------------------------------------------------
// Callbacks for hooks in gui/NewGameOptionsWindow.h
// -----------------------------------------------------------

void CallNewGameOptionsWindowConstructedCallbacks(NewGameOptionsWindow* thisptr)
{
    ArgPusher1<NewGameOptionsWindow*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("NewGameOptionsWindow::_CONSTRUCTOR", &pusher);
}

void CallNewGameOptionsWindowDestructorCallbacks(NewGameOptionsWindow* thisptr)
{
    ArgPusher1<NewGameOptionsWindow*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("NewGameOptionsWindow::_DESTRUCTOR", &pusher);
}

void CallNewGameOptionsWindowSetVisibleCallbacks(NewGameOptionsWindow* thisptr, bool visible)
{
    ArgPusher2<NewGameOptionsWindow*, bool> pusher(thisptr, visible);
    KenshiLua::EventSystem::get().callHandlers("NewGameOptionsWindow::setVisible", &pusher);
}

bool CallNewGameOptionsWindowGetVisibleCallbacks(NewGameOptionsWindow* thisptr, bool defaultVal)
{
    ArgPusher2<NewGameOptionsWindow*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("NewGameOptionsWindow::getVisible", &pusher, defaultVal);
}

void CallNewGameOptionsWindowSetPositionCallbacks(NewGameOptionsWindow* thisptr, int x, int y)
{
    ArgPusher3<NewGameOptionsWindow*, int, int> pusher(thisptr, x, y);
    KenshiLua::EventSystem::get().callHandlers("NewGameOptionsWindow::setPosition", &pusher);
}

void CallNewGameOptionsWindowUpdateCallbacks(NewGameOptionsWindow* thisptr)
{
    ArgPusher1<NewGameOptionsWindow*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("NewGameOptionsWindow::update", &pusher);
}

void CallNewGameOptionsWindowSetOptionsCallbacks(NewGameOptionsWindow* thisptr, const GameplayOptions& options)
{
    ArgPusher2<NewGameOptionsWindow*, const GameplayOptions*> pusher(thisptr, &options);
    KenshiLua::EventSystem::get().callHandlers("NewGameOptionsWindow::setOptions", &pusher);
}

// -----------------------------------------------------------
// Additional callbacks for hooks in gui/InventoryGUI.h
// -----------------------------------------------------------

void CallInventoryIconConstructedCallbacks(InventoryIcon* thisptr, Item* item, const MyGUI::types::TPoint<int>& position, MyGUI::Widget* parent)
{
    ArgPusher4<InventoryIcon*, Item*, const MyGUI::IntPoint&, KenshiLua::WidgetArg> pusher(thisptr, item, position, parent);
    KenshiLua::EventSystem::get().callHandlers("InventoryIcon::_CONSTRUCTOR", &pusher);
}

void CallInventoryIconSetPositionCallbacks(InventoryIcon* thisptr, const MyGUI::types::TPoint<int>& position)
{
    ArgPusher2<InventoryIcon*, const MyGUI::IntPoint&> pusher(thisptr, position);
    KenshiLua::EventSystem::get().callHandlers("InventoryIcon::setPosition", &pusher);
}

void CallInventoryIconGetSizeCallbacks(InventoryIcon* thisptr, const MyGUI::types::TSize<int>& result)
{
    ArgPusher2<InventoryIcon*, const MyGUI::IntSize&> pusher(thisptr, result);
    KenshiLua::EventSystem::get().callHandlers("InventoryIcon::getSize", &pusher);
}

void CallInventoryIconUpdateCallbacks(InventoryIcon* thisptr)
{
    ArgPusher1<InventoryIcon*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("InventoryIcon::update", &pusher);
}

void CallInventoryIconGetWidgetCallbacks(InventoryIcon* thisptr, MyGUI::Widget* result)
{
    ArgPusher2<InventoryIcon*, KenshiLua::WidgetArg> pusher(thisptr, result);
    KenshiLua::EventSystem::get().callHandlers("InventoryIcon::getWidget", &pusher);
}

void CallInventoryIconCreateIconImageCallbacks(Item* item, const std::string& name, const iVector2& size)
{
    ArgPusher3<Item*, const std::string&, const iVector2&> pusher(item, name, size);
    KenshiLua::EventSystem::get().callHandlers("InventoryIcon::createIconImage", &pusher);
}

void CallInventoryIconGetItemSizeCallbacks(GameData* itemData, const MyGUI::types::TSize<int>& result)
{
    ArgPusher2<GameData*, const MyGUI::IntSize&> pusher(itemData, result);
    KenshiLua::EventSystem::get().callHandlers("InventoryIcon::getItemSize", &pusher);
}

void CallInventoryIconGetItemPositionCallbacks(int x, int y, const MyGUI::types::TPoint<int>& result)
{
    ArgPusher3<int, int, const MyGUI::IntPoint&> pusher(x, y, result);
    KenshiLua::EventSystem::get().callHandlers("InventoryIcon::getItemPosition", &pusher);
}

void CallInventoryIconDestructorCallbacks(InventoryIcon* thisptr)
{
    ArgPusher1<InventoryIcon*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("InventoryIcon::_DESTRUCTOR", &pusher);
}

void CallInventorySectionGUIConstructedCallbacks(InventorySectionGUI* thisptr, MyGUI::Widget* widget, const std::string& sectionName)
{
    ArgPusher3<InventorySectionGUI*, KenshiLua::WidgetArg, const std::string&> pusher(thisptr, widget, sectionName);
    KenshiLua::EventSystem::get().callHandlers("InventorySectionGUI::_CONSTRUCTOR", &pusher);
}

void CallInventorySectionGUIDestructorCallbacks(InventorySectionGUI* thisptr)
{
    ArgPusher1<InventorySectionGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("InventorySectionGUI::_DESTRUCTOR", &pusher);
}

bool CallInventorySectionGUIHasMouseCallbacks(InventorySectionGUI* thisptr, bool defaultVal)
{
    ArgPusher2<InventorySectionGUI*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("InventorySectionGUI::hasMouse", &pusher, defaultVal);
}

void CallInventorySectionGUIGetItemAbsolutePositionCallbacks(InventorySectionGUI* thisptr, int x, int y, const MyGUI::types::TPoint<int>& result)
{
    ArgPusher4<InventorySectionGUI*, int, int, const MyGUI::IntPoint&> pusher(thisptr, x, y, result);
    KenshiLua::EventSystem::get().callHandlers("InventorySectionGUI::getItemAbsolutePosition", &pusher);
}

void CallInventorySectionGUIGetWidgetCallbacks(InventorySectionGUI* thisptr, MyGUI::Widget* result)
{
    ArgPusher2<InventorySectionGUI*, KenshiLua::WidgetArg> pusher(thisptr, result);
    KenshiLua::EventSystem::get().callHandlers("InventorySectionGUI::getWidget", &pusher);
}

void CallInventorySectionGUIGetPositionSlotCallbacks(InventorySectionGUI* thisptr, const MyGUI::types::TPoint<int>& position, InventorySection* section, bool round, const MyGUI::types::TPoint<int>& result)
{
    ArgPusher5<InventorySectionGUI*, const MyGUI::IntPoint&, InventorySection*, bool, const MyGUI::IntPoint&> pusher(thisptr, position, section, round, result);
    KenshiLua::EventSystem::get().callHandlers("InventorySectionGUI::getPositionSlot", &pusher);
}

bool CallInventorySectionGUIGetBestPositionSlotCallbacks(InventorySectionGUI* thisptr, const MyGUI::types::TPoint<int>& position, InventorySection* section, Item* item, const MyGUI::types::TPoint<int>& slot, bool defaultVal)
{
    ArgPusher6<InventorySectionGUI*, const MyGUI::IntPoint&, InventorySection*, Item*, const MyGUI::IntPoint&, bool> pusher(thisptr, position, section, item, slot, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("InventorySectionGUI::getBestPositionSlot", &pusher, defaultVal);
}

void CallInventorySectionGUISetEnabledCallbacks(InventorySectionGUI* thisptr, bool value)
{
    ArgPusher2<InventorySectionGUI*, bool> pusher(thisptr, value);
    KenshiLua::EventSystem::get().callHandlers("InventorySectionGUI::setEnabled", &pusher);
}

void CallInventorySectionGUIRefreshIconsCallbacks(InventorySectionGUI* thisptr, InventorySection* section)
{
    ArgPusher2<InventorySectionGUI*, InventorySection*> pusher(thisptr, section);
    KenshiLua::EventSystem::get().callHandlers("InventorySectionGUI::refreshIcons", &pusher);
}

void CallInventorySectionGUIUpdateCallbacks(InventorySectionGUI* thisptr)
{
    ArgPusher1<InventorySectionGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("InventorySectionGUI::update", &pusher);
}

void CallInventoryTradeResultConstructedCallbacks(InventoryGUI::TradeResult* thisptr, int value)
{
    ArgPusher2<InventoryGUI::TradeResult*, int> pusher(thisptr, value);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::TradeResult::_CONSTRUCTOR", &pusher);
}

bool CallInventoryTradeResultEqualsCallbacks(InventoryGUI::TradeResult* thisptr, InventoryGUI::TradeResult* other, bool defaultVal)
{
    ArgPusher3<InventoryGUI::TradeResult*, InventoryGUI::TradeResult*, bool> pusher(thisptr, other, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("InventoryGUI::TradeResult::operator==", &pusher, defaultVal);
}

bool CallInventoryTradeResultNotEqualsCallbacks(InventoryGUI::TradeResult* thisptr, InventoryGUI::TradeResult* other, bool defaultVal)
{
    ArgPusher3<InventoryGUI::TradeResult*, InventoryGUI::TradeResult*, bool> pusher(thisptr, other, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("InventoryGUI::TradeResult::operator!=", &pusher, defaultVal);
}

void CallInventoryTradeResultShowMessageCallbacks(InventoryGUI::TradeResult* thisptr)
{
    ArgPusher1<InventoryGUI::TradeResult*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::TradeResult::showMessage", &pusher);
}

void CallInventoryTradeResultStaticShowMessageCallbacks(int value)
{
    ArgPusher1<int> pusher(value);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::TradeResult::ShowMessage", &pusher);
}

bool CallInventoryTradeDataIsValidCallbacks(InventoryGUI::InventoryTradeData* thisptr, bool defaultVal)
{
    ArgPusher2<InventoryGUI::InventoryTradeData*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("InventoryGUI::InventoryTradeData::isValid", &pusher, defaultVal);
}

void CallInventoryTradeDataAssignCallbacks(InventoryGUI::InventoryTradeData* thisptr, InventoryGUI::InventoryTradeData* other)
{
    ArgPusher2<InventoryGUI::InventoryTradeData*, InventoryGUI::InventoryTradeData*> pusher(thisptr, other);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::InventoryTradeData::operator=", &pusher);
}

bool CallInventoryGUILockedItemCheckCallbacks(LockedArmour* item, bool defaultVal)
{
    ArgPusher2<LockedArmour*, bool> pusher(item, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("InventoryGUI::lockedItemCheck", &pusher, defaultVal);
}

void CallInventoryGUISetTradingTownCallbacks(const hand& town)
{
    ArgPusher1<const hand&> pusher(town);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::setTradingTown", &pusher);
}

Town* CallInventoryGUIGetTradingTownCallbacks(Town* defaultVal)
{
    ArgPusher1<Town*> pusher(defaultVal);
    return static_cast<Town*>(KenshiLua::EventSystem::get().callHandlersObject("InventoryGUI::getTradingTown", KenshiLua::TownMetatable(), &pusher));
}

void CallInventoryGUIRemoveTradePartnerCallbacks(InventoryGUI* tradeWith)
{
    ArgPusher1<InventoryGUI*> pusher(tradeWith);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::removeTradePartner", &pusher);
}

void CallInventoryGUIClearTradePartnersCallbacks()
{
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::clearTradePartners");
}

bool CallInventoryGUICanDropMouseItemWithoutPayingCallbacks(InventoryGUI* cameFrom, bool defaultVal)
{
    ArgPusher2<InventoryGUI*, bool> pusher(cameFrom, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("InventoryGUI::canDropMouseItemWithoutPaying", &pusher, defaultVal);
}

void CallInventoryGUINVAutoChangeSelectedObjectCallbacks(InventoryGUI* thisptr, const hand& obj)
{
    ArgPusher2<InventoryGUI*, const hand&> pusher(thisptr, obj);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::_NV_autoChangeSelectedObject", &pusher);
}

void CallInventoryGUINVUpdateCallbacks(InventoryGUI* thisptr)
{
    ArgPusher1<InventoryGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::_NV_update", &pusher);
}

void CallInventoryGUINVShowCallbacks(InventoryGUI* thisptr, bool on)
{
    ArgPusher2<InventoryGUI*, bool> pusher(thisptr, on);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::_NV_show", &pusher);
}

void CallInventoryGUINVSetPositionRealCallbacks(InventoryGUI* thisptr, float x, float y)
{
    ArgPusher3<InventoryGUI*, float, float> pusher(thisptr, x, y);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::_NV_setPositionReal", &pusher);
}

void CallInventoryGUINVRefreshSectionCallbacks(InventoryGUI* thisptr, InventorySection* section)
{
    ArgPusher2<InventoryGUI*, InventorySection*> pusher(thisptr, section);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::_NV_refreshSection", &pusher);
}

void CallInventoryGUIRefreshSectionCallbacks(InventoryGUI* thisptr)
{
    ArgPusher1<InventoryGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::refreshSection", &pusher);
}

void CallInventoryGUIAutoArrangeButtonCallbacks(InventoryGUI* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<InventoryGUI*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::autoArrangeButton", &pusher);
}

void CallInventoryGUIOpenBackpackButtonCallbacks(InventoryGUI* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<InventoryGUI*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::openBackpackButton", &pusher);
}

void CallInventoryGUIOpenLimbsInterfaceCallbacks(InventoryGUI* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<InventoryGUI*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::openLimbsInterface", &pusher);
}

void CallInventoryGUIShowBackpackCallbacks(InventoryGUI* thisptr, bool on)
{
    ArgPusher2<InventoryGUI*, bool> pusher(thisptr, on);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::showBackpack", &pusher);
}

void CallInventoryGUIWindowButtonPressedCallbacks(InventoryGUI* thisptr, MyGUI::Widget* widget, const std::string& name)
{
    ArgPusher3<InventoryGUI*, KenshiLua::WidgetArg, const std::string&> pusher(thisptr, widget, name);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::windowButtonPressed", &pusher);
}

void CallInventoryGUIStealingGUIInfoUpdateCallbacks(InventoryGUI* thisptr)
{
    ArgPusher1<InventoryGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::stealingGUIInfoUpdate", &pusher);
}

void CallInventoryGUIGetTrader1Trader2Callbacks(InventoryGUI* thisptr, InventoryGUI* trader1, InventoryGUI* trader2)
{
    ArgPusher3<InventoryGUI*, InventoryGUI*, InventoryGUI*> pusher(thisptr, trader1, trader2);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::getTrader1Trader2", &pusher);
}

void CallInventoryGUIPlaySoundCallbacks(InventoryGUI* thisptr, const std::string& eventId, Item* item)
{
    ArgPusher3<InventoryGUI*, const std::string&, Item*> pusher(thisptr, eventId, item);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::playSound", &pusher);
}

void CallInventoryGUIRefreshAllSectionsCallbacks(InventoryGUI* thisptr)
{
    ArgPusher1<InventoryGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::refreshAllSections", &pusher);
}

void CallInventoryGUIUpdateDatapanelCallbacks(InventoryGUI* thisptr)
{
    ArgPusher1<InventoryGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::updateDatapanel", &pusher);
}

void CallInventoryGUIRightClickAutoEquippingCallbacks(InventoryGUI* thisptr)
{
    ArgPusher1<InventoryGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::rightClickAutoEquipping", &pusher);
}

void CallInventoryGUIReturnItemCallbacks(InventoryGUI* thisptr, Item* item, const std::string& sectionName)
{
    ArgPusher3<InventoryGUI*, Item*, const std::string&> pusher(thisptr, item, sectionName);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::returnItem", &pusher);
}

void CallInventoryGUISectionMouseButtonPressedCallbacks(InventoryGUI* thisptr, MyGUI::Widget* sender, int left, int top, int id)
{
    ArgPusher5<InventoryGUI*, KenshiLua::WidgetArg, int, int, int> pusher(thisptr, sender, left, top, id);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::sectionMouseButtonPressed", &pusher);
}

void CallInventoryGUISectionMouseButtonReleasedCallbacks(InventoryGUI* thisptr, MyGUI::Widget* sender, int left, int top, int id)
{
    ArgPusher5<InventoryGUI*, KenshiLua::WidgetArg, int, int, int> pusher(thisptr, sender, left, top, id);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::sectionMouseButtonReleased", &pusher);
}

void CallInventoryGUIOnWindowFocusCallbacks(InventoryGUI* thisptr, MyGUI::Widget* sender, bool focus)
{
    ArgPusher3<InventoryGUI*, KenshiLua::WidgetArg, bool> pusher(thisptr, sender, focus);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::onWindowFocus", &pusher);
}

void CallInventoryGUIWindowMovedCallbacks(InventoryGUI* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<InventoryGUI*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::windowMoved", &pusher);
}

bool CallInventoryGUINVIsVisibleCallbacks(InventoryGUI* thisptr, bool defaultVal)
{
    ArgPusher2<InventoryGUI*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("InventoryGUI::_NV_isVisible", &pusher, defaultVal);
}

ContainerItem* CallInventoryGUIGetBackpackCallbacks(InventoryGUI* thisptr, ContainerItem* defaultVal)
{
    ArgPusher2<InventoryGUI*, ContainerItem*> pusher(thisptr, defaultVal);
    return static_cast<ContainerItem*>(KenshiLua::EventSystem::get().callHandlersObject("InventoryGUI::getBackpack", KenshiLua::ContainerItemMetatable(), &pusher));
}

Inventory* CallInventoryGUINVGetInventoryCallbacks(InventoryGUI* thisptr, Inventory* defaultVal)
{
    ArgPusher2<InventoryGUI*, Inventory*> pusher(thisptr, defaultVal);
    return static_cast<Inventory*>(KenshiLua::EventSystem::get().callHandlersObject("InventoryGUI::_NV_getInventory", KenshiLua::InventoryMetatable(), &pusher));
}

bool CallInventoryGUIHasSameOwnerCallbacks(InventoryGUI* thisptr, InventoryGUI* other, bool defaultVal)
{
    ArgPusher3<InventoryGUI*, InventoryGUI*, bool> pusher(thisptr, other, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("InventoryGUI::hasSameOwner", &pusher, defaultVal);
}

Character* CallInventoryGUINVGetCallbackCharacterCallbacks(InventoryGUI* thisptr, Character* defaultVal)
{
    ArgPusher2<InventoryGUI*, Character*> pusher(thisptr, defaultVal);
    return static_cast<Character*>(KenshiLua::EventSystem::get().callHandlersObject("InventoryGUI::_NV_getCallbackCharacter", KenshiLua::CharacterMetatable(), &pusher));
}

RootObject* CallInventoryGUINVGetCallbackObjectCallbacks(InventoryGUI* thisptr, RootObject* defaultVal)
{
    ArgPusher2<InventoryGUI*, RootObject*> pusher(thisptr, defaultVal);
    return static_cast<RootObject*>(KenshiLua::EventSystem::get().callHandlersObject("InventoryGUI::_NV_getCallbackObject", KenshiLua::RootObjectMetatable(), &pusher));
}

Item* CallInventoryGUIGetSelectedItemCallbacks(InventoryGUI* thisptr, const std::string& sectionName, Item* defaultVal)
{
    ArgPusher3<InventoryGUI*, const std::string&, Item*> pusher(thisptr, sectionName, defaultVal);
    return static_cast<Item*>(KenshiLua::EventSystem::get().callHandlersObject("InventoryGUI::getSelectedItem", KenshiLua::ItemMetatable(), &pusher));
}

void CallInventoryGUIGetWindowCoordCallbacks(InventoryGUI* thisptr, const MyGUI::types::TCoord<int>& result)
{
    ArgPusher2<InventoryGUI*, const MyGUI::IntCoord&> pusher(thisptr, result);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::getWindowCoord", &pusher);
}

Character* CallInventoryGUIGetNPCTraderCallbacks(Character* defaultVal)
{
    ArgPusher1<Character*> pusher(defaultVal);
    return static_cast<Character*>(KenshiLua::EventSystem::get().callHandlersObject("InventoryGUI::getNPCTrader", KenshiLua::CharacterMetatable(), &pusher));
}

RootObject* CallInventoryGUIIsTradingForMoneyStaticCallbacks(RootObject* defaultVal)
{
    ArgPusher1<RootObject*> pusher(defaultVal);
    return static_cast<RootObject*>(KenshiLua::EventSystem::get().callHandlersObject("InventoryGUI::isTradingForMoney_static", KenshiLua::RootObjectMetatable(), &pusher));
}

RootObject* CallInventoryGUIIsTradingAndStealingStaticCallbacks(RootObject* defaultVal)
{
    ArgPusher1<RootObject*> pusher(defaultVal);
    return static_cast<RootObject*>(KenshiLua::EventSystem::get().callHandlersObject("InventoryGUI::isTradingAndStealing_static", KenshiLua::RootObjectMetatable(), &pusher));
}

float CallInventoryGUIGetTraderPriceMultiplierCallbacks(float defaultVal)
{
    ArgPusher1<float> pusher(defaultVal);
    return static_cast<float>(KenshiLua::EventSystem::get().callHandlersNumber("InventoryGUI::getTraderPriceMultiplier", &pusher, defaultVal));
}

void CallInventoryGUIDestructorCallbacks(InventoryGUI* thisptr)
{
    ArgPusher1<InventoryGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::_DESTRUCTOR", &pusher);
}

bool CallInventoryGUIPickupItemToMouseCallbacks(InventoryGUI* thisptr, const std::string& sectionName, bool defaultVal)
{
    ArgPusher3<InventoryGUI*, const std::string&, bool> pusher(thisptr, sectionName, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("InventoryGUI::pickupItemToMouse", &pusher, defaultVal);
}

bool CallInventoryGUIPlaceItemFromMouseCallbacks(InventoryGUI* thisptr, const std::string& sectionName, const MyGUI::types::TPoint<int>& mousePos, bool defaultVal)
{
    ArgPusher4<InventoryGUI*, const std::string&, const MyGUI::IntPoint&, bool> pusher(thisptr, sectionName, mousePos, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("InventoryGUI::placeItemFromMouse", &pusher, defaultVal);
}

Item* CallInventoryGUIGetMouseItemCallbacks(InventoryGUI* thisptr, Item* defaultVal)
{
    ArgPusher2<InventoryGUI*, Item*> pusher(thisptr, defaultVal);
    return static_cast<Item*>(KenshiLua::EventSystem::get().callHandlersObject("InventoryGUI::getMouseItem", KenshiLua::ItemMetatable(), &pusher));
}

Item* CallInventoryGUITakeCertainAmountFromCallbacks(InventoryGUI* thisptr, Item* baseItem, int amount, Item* defaultVal)
{
    ArgPusher4<InventoryGUI*, Item*, int, Item*> pusher(thisptr, baseItem, amount, defaultVal);
    return static_cast<Item*>(KenshiLua::EventSystem::get().callHandlersObject("InventoryGUI::takeCertainAmountFrom", KenshiLua::ItemMetatable(), &pusher));
}

void CallInventoryGUIRClickAutoTradeCallbacks(InventoryGUI* thisptr, const std::string& invSectionName, int x, int y, InventoryGUI* sendingTo, bool thieveryChecks, bool first, const InventoryGUI::TradeResult& result)
{
    ArgPusher8<InventoryGUI*, const std::string&, int, int, InventoryGUI*, bool, bool, const InventoryGUI::TradeResult&> pusher(thisptr, invSectionName, x, y, sendingTo, thieveryChecks, first, result);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::RClickAutoTrade", &pusher);
}

void CallInventoryGUIRClickAutoTradeAllCallbacks(InventoryGUI* thisptr, const std::string& invSectionName, int x, int y, InventoryGUI* sendingTo, bool thieveryChecks, bool first, const InventoryGUI::TradeResult& result)
{
    ArgPusher8<InventoryGUI*, const std::string&, int, int, InventoryGUI*, bool, bool, const InventoryGUI::TradeResult&> pusher(thisptr, invSectionName, x, y, sendingTo, thieveryChecks, first, result);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::RClickAutoTradeAll", &pusher);
}

bool CallInventoryGUIIsTradingForMoneyCallbacks(InventoryGUI* thisptr, InventoryGUI* cameFrom, bool defaultVal)
{
    ArgPusher3<InventoryGUI*, InventoryGUI*, bool> pusher(thisptr, cameFrom, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("InventoryGUI::isTradingForMoney", &pusher, defaultVal);
}

bool CallInventoryGUIIsStealingCallbacks(InventoryGUI* thisptr, InventoryGUI* cameFrom, bool defaultVal)
{
    ArgPusher3<InventoryGUI*, InventoryGUI*, bool> pusher(thisptr, cameFrom, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("InventoryGUI::isStealing", &pusher, defaultVal);
}

bool CallInventoryGUIIsWithinRangeToTradeCallbacks(InventoryGUI* thisptr, RootObject* otherOwner, bool stealing, bool defaultVal)
{
    ArgPusher4<InventoryGUI*, RootObject*, bool, bool> pusher(thisptr, otherOwner, stealing, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("InventoryGUI::isWithinRangeToTrade", &pusher, defaultVal);
}

bool CallInventoryGUISetItemToPlayerPortraitCallbacks(InventoryGUI* thisptr, Item* item, Character* character, bool defaultVal)
{
    ArgPusher4<InventoryGUI*, Item*, Character*, bool> pusher(thisptr, item, character, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("InventoryGUI::setItemToPlayerPortrait", &pusher, defaultVal);
}

void CallInventoryGUIFenceCallbackDataDestructorCallbacks(InventoryGUI::FenceCallbackData* thisptr)
{
    ArgPusher1<InventoryGUI::FenceCallbackData*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::FenceCallbackData::_DESTRUCTOR", &pusher);
}

bool CallInventoryGUIFencingConfirmationResultCallbacks(InventoryGUI* thisptr, Item* item, RootObject* thief, Character* fence, const std::string& sectionName, const MyGUI::types::TPoint<int>& mouse, bool defaultVal)
{
    ArgPusher7<InventoryGUI*, Item*, RootObject*, Character*, const std::string&, const MyGUI::IntPoint&, bool> pusher(thisptr, item, thief, fence, sectionName, mouse, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("InventoryGUI::fencingConfirmation", &pusher, defaultVal);
}

RootObject* CallInventoryGUIGetPlayerTradeCharacterCallbacks(InventoryGUI* thisptr, RootObject* defaultVal)
{
    ArgPusher2<InventoryGUI*, RootObject*> pusher(thisptr, defaultVal);
    return static_cast<RootObject*>(KenshiLua::EventSystem::get().callHandlersObject("InventoryGUI::getPlayerTradeCharacter", KenshiLua::RootObjectMetatable(), &pusher));
}

bool CallInventoryGUITryToEquipCallbacks(InventoryGUI* thisptr, Item* item, bool replace, bool defaultVal)
{
    ArgPusher4<InventoryGUI*, Item*, bool, bool> pusher(thisptr, item, replace, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("InventoryGUI::tryToEquip", &pusher, defaultVal);
}

bool CallInventoryGUIHasMouseCallbacks(InventoryGUI* thisptr, bool defaultVal)
{
    ArgPusher2<InventoryGUI*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("InventoryGUI::hasMouse", &pusher, defaultVal);
}

void CallInventoryGUIGetSectionWithMouseLocalCallbacks(InventoryGUI* thisptr, const std::string& result)
{
    ArgPusher2<InventoryGUI*, const std::string&> pusher(thisptr, result);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::getSectionWithMouseLocal", &pusher);
}

void CallInventoryGUIGetSlotWithMouseCallbacks(InventoryGUI* thisptr, const iVector2& result)
{
    ArgPusher2<InventoryGUI*, const iVector2&> pusher(thisptr, result);
    KenshiLua::EventSystem::get().callHandlers("InventoryGUI::getSlotWithMouse", &pusher);
}

InventoryIcon* CallInventoryGUIMakeIconForItemCallbacks(Item* item, int x, int y, InventoryIcon* defaultVal)
{
    ArgPusher4<Item*, int, int, InventoryIcon*> pusher(item, x, y, defaultVal);
    return static_cast<InventoryIcon*>(KenshiLua::EventSystem::get().callHandlersObject("InventoryGUI::makeIconForItem", KenshiLua::InventoryIconMetatable(), &pusher));
}

void CallInventoryLayoutConstructedCallbacks(InventoryLayout* thisptr, const std::string& file)
{
    ArgPusher2<InventoryLayout*, const std::string&> pusher(thisptr, file);
    KenshiLua::EventSystem::get().callHandlers("InventoryLayout::_CONSTRUCTOR", &pusher);
}

void CallInventoryLayoutDestructorCallbacks(InventoryLayout* thisptr)
{
    ArgPusher1<InventoryLayout*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("InventoryLayout::_DESTRUCTOR", &pusher);
}

void CallInventoryLayoutGetWindowCallbacks(InventoryLayout* thisptr, MyGUI::Widget* result)
{
    ArgPusher2<InventoryLayout*, KenshiLua::WidgetArg> pusher(thisptr, result);
    KenshiLua::EventSystem::get().callHandlers("InventoryLayout::getWindow", &pusher);
}

void CallInventoryLayoutGetWidgetCallbacks(InventoryLayout* thisptr, const std::string& name, MyGUI::Widget* result)
{
    ArgPusher3<InventoryLayout*, const std::string&, KenshiLua::WidgetArg> pusher(thisptr, name, result);
    KenshiLua::EventSystem::get().callHandlers("InventoryLayout::getWidget", &pusher);
}

DatapanelGUI* CallInventoryLayoutNVGetDatapanelCallbacks(InventoryLayout* thisptr, DatapanelGUI* defaultVal)
{
    ArgPusher2<InventoryLayout*, DatapanelGUI*> pusher(thisptr, defaultVal);
    return static_cast<DatapanelGUI*>(KenshiLua::EventSystem::get().callHandlersObject("InventoryLayout::_NV_getDatapanel", KenshiLua::DatapanelGUIMetatable(), &pusher));
}

void CallInventoryLayoutSetupDataPanelInfosCallbacks(InventoryLayout* thisptr, const std::string& name)
{
    ArgPusher2<InventoryLayout*, const std::string&> pusher(thisptr, name);
    KenshiLua::EventSystem::get().callHandlers("InventoryLayout::setupDataPanelInfos", &pusher);
}

void CallInventoryLayoutNotifyCellSizeChangedCallbacks()
{
    KenshiLua::EventSystem::get().callHandlers("InventoryLayout::notifyCellSizeChanged");
}

InventorySectionGUI* CallInventoryLayoutCreateSectionGUICallbacks(InventoryLayout* thisptr, InventorySection* section, InventorySectionGUI* defaultVal)
{
    ArgPusher3<InventoryLayout*, InventorySection*, InventorySectionGUI*> pusher(thisptr, section, defaultVal);
    return static_cast<InventorySectionGUI*>(KenshiLua::EventSystem::get().callHandlersObject("InventoryLayout::createSectionGUI", KenshiLua::InventorySectionGUIMetatable(), &pusher));
}

void CallInventoryLayoutSetSectionGUIDisabledCallbacks(InventoryLayout* thisptr, const std::string& sectionName, int width, int height)
{
    ArgPusher4<InventoryLayout*, const std::string&, int, int> pusher(thisptr, sectionName, width, height);
    KenshiLua::EventSystem::get().callHandlers("InventoryLayout::setSectionGUIDisabled", &pusher);
}

void CallInventoryLayoutResizeSectionCallbacks(InventoryLayout* thisptr, InventorySection* section, InventorySectionGUI* sectionGUI, const MyGUI::types::TSize<int>& result)
{
    ArgPusher4<InventoryLayout*, InventorySection*, InventorySectionGUI*, const MyGUI::IntSize&> pusher(thisptr, section, sectionGUI, result);
    KenshiLua::EventSystem::get().callHandlers("InventoryLayout::resizeSection", &pusher);
}

void CallInventoryLayoutResizeSectionWidgetCallbacks(InventoryLayout* thisptr, int width, int height, MyGUI::Widget* widget, const MyGUI::types::TSize<int>& result)
{
    ArgPusher5<InventoryLayout*, int, int, KenshiLua::WidgetArg, const MyGUI::IntSize&> pusher(thisptr, width, height, widget, result);
    KenshiLua::EventSystem::get().callHandlers("InventoryLayout::resizeSectionWidget", &pusher);
}

void CallGenericFixedInventoryLayoutNVSetSizeCallbacks(GenericFixedInventoryLayout* thisptr, int slotsW, int slotsH)
{
    ArgPusher3<GenericFixedInventoryLayout*, int, int> pusher(thisptr, slotsW, slotsH);
    KenshiLua::EventSystem::get().callHandlers("GenericFixedInventoryLayout::_NV_setSize", &pusher);
}

void CallGenericFixedInventoryLayoutDestructorCallbacks(GenericFixedInventoryLayout* thisptr)
{
    ArgPusher1<GenericFixedInventoryLayout*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("GenericFixedInventoryLayout::_DESTRUCTOR", &pusher);
}

void CallBackpackInventoryLayoutConstructedCallbacks(BackpackInventoryLayout* thisptr, bool standAlone)
{
    ArgPusher2<BackpackInventoryLayout*, bool> pusher(thisptr, standAlone);
    KenshiLua::EventSystem::get().callHandlers("BackpackInventoryLayout::_CONSTRUCTOR", &pusher);
}

void CallBackpackInventoryLayoutDestructorCallbacks(BackpackInventoryLayout* thisptr)
{
    ArgPusher1<BackpackInventoryLayout*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("BackpackInventoryLayout::_DESTRUCTOR", &pusher);
}

// -----------------------------------------------------------
// Callbacks for hooks in gui/MainBarGUI.h
// -----------------------------------------------------------

void CallMainTabPortraitPlatoonAddTabCallbacks(MainTabPortraitPlatoon* thisptr, MyGUI::Widget* tabControl, bool visible)
{
    ArgPusher3<MainTabPortraitPlatoon*, KenshiLua::WidgetArg, bool> pusher(thisptr, tabControl, visible);
    KenshiLua::EventSystem::get().callHandlers("MainTabPortraitPlatoon::addTab", &pusher);
}

void CallMainTabPortraitPlatoonDetachCallbacks(MainTabPortraitPlatoon* thisptr)
{
    ArgPusher1<MainTabPortraitPlatoon*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("MainTabPortraitPlatoon::detach", &pusher);
}

void CallMainTabPortraitPlatoonSetFlashCallbacks(MainTabPortraitPlatoon* thisptr, bool flash)
{
    ArgPusher2<MainTabPortraitPlatoon*, bool> pusher(thisptr, flash);
    KenshiLua::EventSystem::get().callHandlers("MainTabPortraitPlatoon::setFlash", &pusher);
}

void CallMainTabPortraitPlatoonUpdateCallbacks(MainTabPortraitPlatoon* thisptr)
{
    ArgPusher1<MainTabPortraitPlatoon*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("MainTabPortraitPlatoon::update", &pusher);
}

void CallMainTabPortraitPlatoonDestructorCallbacks(MainTabPortraitPlatoon* thisptr)
{
    ArgPusher1<MainTabPortraitPlatoon*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("MainTabPortraitPlatoon::_DESTRUCTOR", &pusher);
}

void CallMainBarGUIConstructedCallbacks(MainBarGUI* thisptr)
{
    ArgPusher1<MainBarGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::_CONSTRUCTOR", &pusher);
}

void CallMainBarGUIDestructorCallbacks(MainBarGUI* thisptr)
{
    ArgPusher1<MainBarGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::_DESTRUCTOR", &pusher);
}

void CallMainBarGUINVclearCallbacks(MainBarGUI* thisptr)
{
    ArgPusher1<MainBarGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::_NV_clear", &pusher);
}

void CallMainBarGUINVUpdateCallbacks(MainBarGUI* thisptr)
{
    ArgPusher1<MainBarGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::_NV_update", &pusher);
}

void CallMainBarGUISpeedChangedCallbacks(MainBarGUI* thisptr)
{
    ArgPusher1<MainBarGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::speedChanged", &pusher);
}

void CallMainBarGUINVUpdateBountyPanelVisibilityCallbacks(MainBarGUI* thisptr)
{
    ArgPusher1<MainBarGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::_NV_updateBountyPanelVisibility", &pusher);
}

void CallMainBarGUIUpdatePotraitsPlatoonCallbacks(MainBarGUI* thisptr)
{
    ArgPusher1<MainBarGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::updatePotraitsPlatoon", &pusher);
}

void CallMainBarGUIUpdatePortraitsCallbacks(MainBarGUI* thisptr)
{
    ArgPusher1<MainBarGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::updatePortraits", &pusher);
}

void CallMainBarGUIRefreshPortraitTabsCallbacks(MainBarGUI* thisptr)
{
    ArgPusher1<MainBarGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::refreshPortraitTabs", &pusher);
}

void CallMainBarGUIOrdersPanelClearCallbacks(MainBarGUI* thisptr)
{
    ArgPusher1<MainBarGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::ordersPanelClear", &pusher);
}

void CallMainBarGUISetMessagePositionCallbacks(MainBarGUI* thisptr)
{
    ArgPusher1<MainBarGUI*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::setMessagePosition", &pusher);
}

void CallMainBarGUINVShowCallbacks(MainBarGUI* thisptr, bool on)
{
    ArgPusher2<MainBarGUI*, bool> pusher(thisptr, on);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::_NV_show", &pusher);
}

void CallMainBarGUISetLevelEditModeCallbacks(MainBarGUI* thisptr, bool on)
{
    ArgPusher2<MainBarGUI*, bool> pusher(thisptr, on);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::setLevelEditMode", &pusher);
}

void CallMainBarGUISetLevelEditInteriorModeCallbacks(MainBarGUI* thisptr, bool interiorMode)
{
    ArgPusher2<MainBarGUI*, bool> pusher(thisptr, interiorMode);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::setLevelEditInteriorMode", &pusher);
}

void CallMainBarGUISetExtendInfoPanelEnabledCallbacks(MainBarGUI* thisptr, bool enabled)
{
    ArgPusher2<MainBarGUI*, bool> pusher(thisptr, enabled);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::setExtendInfoPanelEnabled", &pusher);
}

void CallMainBarGUINVAutoChangeSelectedObjectCallbacks(MainBarGUI* thisptr, const hand& obj)
{
    ArgPusher2<MainBarGUI*, const hand&> pusher(thisptr, obj);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::_NV_autoChangeSelectedObject", &pusher);
}

void CallMainBarGUIPressedKeyCallbacks(MainBarGUI* thisptr, int keycode)
{
    ArgPusher2<MainBarGUI*, int> pusher(thisptr, keycode);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::pressedKey", &pusher);
}

void CallMainBarGUIUpdatePortraitCallbacks(MainBarGUI* thisptr, const hand& character)
{
    ArgPusher2<MainBarGUI*, const hand&> pusher(thisptr, character);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::updatePortrait", &pusher);
}

void CallMainBarGUIPlatoonUpdatedCallbacks(MainBarGUI* thisptr, RootObjectContainer* platoon, bool charAdded)
{
    ArgPusher3<MainBarGUI*, RootObjectContainer*, bool> pusher(thisptr, platoon, charAdded);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::platoonUpdated", &pusher);
}

void CallMainBarGUIUpdatePortraitSizeCallbacks(MainBarGUI* thisptr, ActivePlatoon* platoon)
{
    ArgPusher2<MainBarGUI*, ActivePlatoon*> pusher(thisptr, platoon);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::updatePortraitSize", &pusher);
}

void CallMainBarGUICloseMapWindowCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<MainBarGUI*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::closeMapWindow", &pusher);
}

void CallMainBarGUIToggleMapWindowCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<MainBarGUI*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::toggleMapWindow", &pusher);
}

void CallMainBarGUIToggleFactionWindowCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<MainBarGUI*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::toggleFactionWindow", &pusher);
}

void CallMainBarGUIToggleTechWindowCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<MainBarGUI*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::toggleTechWindow", &pusher);
}

void CallMainBarGUIToggleCraftWindowCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<MainBarGUI*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::toggleCraftWindow", &pusher);
}

void CallMainBarGUIToggleSquadWindowCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<MainBarGUI*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::toggleSquadWindow", &pusher);
}

void CallMainBarGUIChangeFloorButtonUpCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<MainBarGUI*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::changeFloorButtonUp", &pusher);
}

void CallMainBarGUIChangeFloorButtonDownCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<MainBarGUI*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::changeFloorButtonDown", &pusher);
}

void CallMainBarGUIToggleInventoryCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<MainBarGUI*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::toggleInventory", &pusher);
}

void CallMainBarGUIToggleStatsWindowCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<MainBarGUI*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::toggleStatsWindow", &pusher);
}

void CallMainBarGUIToggleHelpWindowCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<MainBarGUI*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::toggleHelpWindow", &pusher);
}

void CallMainBarGUIChangeSpeedCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<MainBarGUI*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::changeSpeed", &pusher);
}

void CallMainBarGUIBuildButtonCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<MainBarGUI*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::buildButton", &pusher);
}

void CallMainBarGUIOrdersPanelFillCallbacks(MainBarGUI* thisptr, const hand& character)
{
    ArgPusher2<MainBarGUI*, const hand&> pusher(thisptr, character);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::ordersPanelFill", &pusher);
}

void CallMainBarGUISerialiseCallbacks(MainBarGUI* thisptr, GameData* data)
{
    ArgPusher2<MainBarGUI*, GameData*> pusher(thisptr, data);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::serialise", &pusher);
}

void CallMainBarGUILoadFromSerialiseCallbacks(MainBarGUI* thisptr, GameData* data)
{
    ArgPusher2<MainBarGUI*, GameData*> pusher(thisptr, data);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::loadFromSerialise", &pusher);
}

void CallMainBarGUIPortraitChangeSelectionCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender, double index, bool follow)
{
    ArgPusher4<MainBarGUI*, KenshiLua::WidgetArg, double, bool> pusher(thisptr, sender, index, follow);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::portraitChangeSelection", &pusher);
}

void CallMainBarGUIPortraitSelectItemAcceptCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender, double index)
{
    ArgPusher3<MainBarGUI*, KenshiLua::WidgetArg, double> pusher(thisptr, sender, index);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::portraitSelectItemAccept", &pusher);
}

void CallMainBarGUIPortraitNotifyItemCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender, void* info)
{
    ArgPusher3<MainBarGUI*, KenshiLua::WidgetArg, void*> pusher(thisptr, sender, info);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::portraitNotifyItem", &pusher);
}

void CallMainBarGUITabPlatoonChangeCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender, double index)
{
    ArgPusher3<MainBarGUI*, KenshiLua::WidgetArg, double> pusher(thisptr, sender, index);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::tabPlatoonChange", &pusher);
}

void CallMainBarGUIExtendInfoPanelCallbacks(MainBarGUI* thisptr, MyGUI::Widget* sender, int left, int top, int id)
{
    ArgPusher5<MainBarGUI*, KenshiLua::WidgetArg, int, int, int> pusher(thisptr, sender, left, top, id);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::extendInfoPanel", &pusher);
}

void CallMainBarGUIGetPausePanelCallbacks(MainBarGUI* thisptr, MyGUI::Widget* result)
{
    ArgPusher2<MainBarGUI*, KenshiLua::WidgetArg> pusher(thisptr, result);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::getPausePanel", &pusher);
}

void CallMainBarGUIGetLoadingPanelCallbacks(MainBarGUI* thisptr, MyGUI::Widget* result)
{
    ArgPusher2<MainBarGUI*, KenshiLua::WidgetArg> pusher(thisptr, result);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::getLoadingPanel", &pusher);
}

void CallMainBarGUIGetMedicalPanelCallbacks(MainBarGUI* thisptr, void* result)
{
    ArgPusher2<MainBarGUI*, void*> pusher(thisptr, result);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::getMedicalPanel", &pusher);
}

void CallMainBarGUIGetBuildingInventoryPositionCallbacks(MainBarGUI* thisptr, const MyGUI::types::TPoint<int>& result)
{
    ArgPusher2<MainBarGUI*, const MyGUI::IntPoint&> pusher(thisptr, result);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::getBuildingInventoryPosition", &pusher);
}

void CallMainBarGUIGetWidgetCallbacks(MainBarGUI* thisptr, const std::string& name, MyGUI::Widget* result)
{
    ArgPusher3<MainBarGUI*, const std::string&, KenshiLua::WidgetArg> pusher(thisptr, name, result);
    KenshiLua::EventSystem::get().callHandlers("MainBarGUI::_getWidget", &pusher);
}

ToolTip* CallMainBarGUINVGetToolTipCallbacks(MainBarGUI* thisptr, ToolTip* defaultVal)
{
    ArgPusher2<MainBarGUI*, ToolTip*> pusher(thisptr, defaultVal);
    return static_cast<ToolTip*>(KenshiLua::EventSystem::get().callHandlersObject("MainBarGUI::_NV_getToolTip", KenshiLua::ToolTipMetatable(), &pusher));
}

DatapanelGUI* CallMainBarGUIGetDatapanelCallbacks(MainBarGUI* thisptr, const std::string& id, DatapanelGUI* defaultVal)
{
    ArgPusher3<MainBarGUI*, const std::string&, DatapanelGUI*> pusher(thisptr, id, defaultVal);
    return static_cast<DatapanelGUI*>(KenshiLua::EventSystem::get().callHandlersObject("MainBarGUI::getDatapanel", KenshiLua::DatapanelGUIMetatable(), &pusher));
}

// -----------------------------------------------------------
// Callbacks for hooks in gui/FactionsScreen.h
// -----------------------------------------------------------

void CallFactionRelationsLineConstructedCallbacks(FactionsScreen::FactionRelationsLine* thisptr, Faction* faction)
{
    ArgPusher2<FactionsScreen::FactionRelationsLine*, Faction*> pusher(thisptr, faction);
    KenshiLua::EventSystem::get().callHandlers("FactionsScreen::FactionRelationsLine::_CONSTRUCTOR", &pusher);
}

void CallFactionRelationsLineAttachToWidgetCallbacks(FactionsScreen::FactionRelationsLine* thisptr, MyGUI::Widget* widget)
{
    ArgPusher2<FactionsScreen::FactionRelationsLine*, KenshiLua::WidgetArg> pusher(thisptr, widget);
    KenshiLua::EventSystem::get().callHandlers("FactionsScreen::FactionRelationsLine::attachToWidget", &pusher);
}

void CallFactionRelationsLineUpdateCallbacks(FactionsScreen::FactionRelationsLine* thisptr)
{
    ArgPusher1<FactionsScreen::FactionRelationsLine*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("FactionsScreen::FactionRelationsLine::update", &pusher);
}

void CallFactionRelationsLineDestructorCallbacks(FactionsScreen::FactionRelationsLine* thisptr)
{
    ArgPusher1<FactionsScreen::FactionRelationsLine*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("FactionsScreen::FactionRelationsLine::_DESTRUCTOR", &pusher);
}

bool CallFactionRelationsLineLessSortCallbacks(void* comparator, FactionsScreen::FactionRelationsLine* left, FactionsScreen::FactionRelationsLine* right, bool defaultVal)
{
    ArgPusher4<void*, FactionsScreen::FactionRelationsLine*, FactionsScreen::FactionRelationsLine*, bool> pusher(comparator, left, right, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("FactionsScreen::FactionRelationsLine::LessSort::operator()", &pusher, defaultVal);
}

void CallFactionsScreenConstructedCallbacks(FactionsScreen* thisptr, ManagementScreen* screen)
{
    ArgPusher2<FactionsScreen*, ManagementScreen*> pusher(thisptr, screen);
    KenshiLua::EventSystem::get().callHandlers("FactionsScreen::_CONSTRUCTOR", &pusher);
}

void CallFactionsScreenDestructorCallbacks(FactionsScreen* thisptr)
{
    ArgPusher1<FactionsScreen*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("FactionsScreen::_DESTRUCTOR", &pusher);
}

bool CallFactionsScreenGetVisibleCallbacks(FactionsScreen* thisptr, bool defaultVal)
{
    ArgPusher2<FactionsScreen*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("FactionsScreen::getVisible", &pusher, defaultVal);
}

#define DEFINE_FACTIONS_SCREEN_VOID0_CALLBACK(FunctionName, EventName) \
    void FunctionName(FactionsScreen* thisptr) \
    { \
        ArgPusher1<FactionsScreen*> pusher(thisptr); \
        KenshiLua::EventSystem::get().callHandlers(EventName, &pusher); \
    }

DEFINE_FACTIONS_SCREEN_VOID0_CALLBACK(CallFactionsScreenClearCallbacks, "FactionsScreen::clear")
DEFINE_FACTIONS_SCREEN_VOID0_CALLBACK(CallFactionsScreenUpdateCallbacks, "FactionsScreen::update")
DEFINE_FACTIONS_SCREEN_VOID0_CALLBACK(CallFactionsScreenRefreshCallbacks, "FactionsScreen::refresh")
DEFINE_FACTIONS_SCREEN_VOID0_CALLBACK(CallFactionsScreenUpdateInfoCallbacks, "FactionsScreen::updateInfo")

#undef DEFINE_FACTIONS_SCREEN_VOID0_CALLBACK

void CallFactionsScreenNotifyEditTextChangeCallbacks(FactionsScreen* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<FactionsScreen*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("FactionsScreen::notifyEditTextChange", &pusher);
}

void CallFactionsScreenSetFocusCallbacks(FactionsScreen* thisptr, MyGUI::Widget* first, MyGUI::Widget* second)
{
    ArgPusher3<FactionsScreen*, KenshiLua::WidgetArg, KenshiLua::WidgetArg> pusher(thisptr, first, second);
    KenshiLua::EventSystem::get().callHandlers("FactionsScreen::setFocus", &pusher);
}

void CallFactionsScreenLoseFocusCallbacks(FactionsScreen* thisptr, MyGUI::Widget* first, MyGUI::Widget* second)
{
    ArgPusher3<FactionsScreen*, KenshiLua::WidgetArg, KenshiLua::WidgetArg> pusher(thisptr, first, second);
    KenshiLua::EventSystem::get().callHandlers("FactionsScreen::loseFocus", &pusher);
}

void CallFactionsScreenFactionLineSelectedCallbacks(FactionsScreen* thisptr, MyGUI::Widget* sender)
{
    ArgPusher2<FactionsScreen*, KenshiLua::WidgetArg> pusher(thisptr, sender);
    KenshiLua::EventSystem::get().callHandlers("FactionsScreen::factionLineSelected", &pusher);
}

void CallFactionsScreenNotifyMouseWheelCallbacks(FactionsScreen* thisptr, MyGUI::Widget* sender, int rel)
{
    ArgPusher3<FactionsScreen*, KenshiLua::WidgetArg, int> pusher(thisptr, sender, rel);
    KenshiLua::EventSystem::get().callHandlers("FactionsScreen::notifyMouseWheel", &pusher);
}

// -----------------------------------------------------------
// Additional callbacks for hooks in gui/DialogueWindow.h
// -----------------------------------------------------------

void CallDialogueWindowSetVisibleCallbacks(DialogueWindow* thisptr, bool visible)
{
    ArgPusher2<DialogueWindow*, bool> pusher(thisptr, visible);
    KenshiLua::EventSystem::get().callHandlers("DialogueWindow::setVisible", &pusher);
}

bool CallDialogueWindowGetVisibleCallbacks(DialogueWindow* thisptr, bool defaultVal)
{
    ArgPusher2<DialogueWindow*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("DialogueWindow::getVisible", &pusher, defaultVal);
}

void CallDialogueWindowNVShowCallbacks(DialogueWindow* thisptr, bool on)
{
    ArgPusher2<DialogueWindow*, bool> pusher(thisptr, on);
    KenshiLua::EventSystem::get().callHandlers("DialogueWindow::_NV_show", &pusher);
}

void CallDialogueWindowHideCallbacks(DialogueWindow* thisptr, Dialogue* dialogue)
{
    ArgPusher2<DialogueWindow*, Dialogue*> pusher(thisptr, dialogue);
    KenshiLua::EventSystem::get().callHandlers("DialogueWindow::hide", &pusher);
}

bool CallDialogueWindowNVIsVisibleCallbacks(DialogueWindow* thisptr, bool defaultVal)
{
    ArgPusher2<DialogueWindow*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("DialogueWindow::_NV_isVisible", &pusher, defaultVal);
}

void CallDialogueWindowNVUpdateCallbacks(DialogueWindow* thisptr)
{
    ArgPusher1<DialogueWindow*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DialogueWindow::_NV_update", &pusher);
}

int CallDialogueWindowGetTopCallbacks(DialogueWindow* thisptr, int defaultVal)
{
    ArgPusher2<DialogueWindow*, int> pusher(thisptr, defaultVal);
    return static_cast<int>(KenshiLua::EventSystem::get().callHandlersNumber("DialogueWindow::getTop", &pusher, defaultVal));
}

void CallDialogueWindowActivateResponseCallbacks(DialogueWindow* thisptr, int index)
{
    ArgPusher2<DialogueWindow*, int> pusher(thisptr, index);
    KenshiLua::EventSystem::get().callHandlers("DialogueWindow::activateResponse", &pusher);
}

void CallDialogueWindowSetNPCTextCallbacks(DialogueWindow* thisptr, const std::string& text)
{
    ArgPusher2<DialogueWindow*, const std::string&> pusher(thisptr, text);
    KenshiLua::EventSystem::get().callHandlers("DialogueWindow::setNPCText", &pusher);
}

void CallDialogueWindowSetResponsesCallbacks(DialogueWindow* thisptr, const void* responses)
{
    ArgPusher2<DialogueWindow*, void*> pusher(thisptr, const_cast<void*>(responses));
    KenshiLua::EventSystem::get().callHandlers("DialogueWindow::setResponses", &pusher);
}

void CallDialogueWindowClearResponsesCallbacks(DialogueWindow* thisptr)
{
    ArgPusher1<DialogueWindow*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DialogueWindow::clearResponses", &pusher);
}

void CallDialogueWindowChangePortraitCallbacks(DialogueWindow* thisptr, Character* character, bool player)
{
    ArgPusher3<DialogueWindow*, Character*, bool> pusher(thisptr, character, player);
    KenshiLua::EventSystem::get().callHandlers("DialogueWindow::changePortrait", &pusher);
}

void CallDialogueWindowDestructorCallbacks(DialogueWindow* thisptr)
{
    ArgPusher1<DialogueWindow*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DialogueWindow::_DESTRUCTOR", &pusher);
}

void CallDialogueWindowUpdatePanelsPositionCallbacks(DialogueWindow* thisptr)
{
    ArgPusher1<DialogueWindow*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("DialogueWindow::updatePanelsPosition", &pusher);
}

// -----------------------------------------------------------
// Callbacks for hooks in gui/SplashScreen.h
// -----------------------------------------------------------

void CallSplashScreenConstructedCallbacks(SplashScreen* thisptr)
{
    ArgPusher1<SplashScreen*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("SplashScreen::_CONSTRUCTOR", &pusher);
}

void CallSplashScreenDestructorCallbacks(SplashScreen* thisptr)
{
    ArgPusher1<SplashScreen*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("SplashScreen::_DESTRUCTOR", &pusher);
}

void CallSplashScreenUpdateCallbacks(SplashScreen* thisptr)
{
    ArgPusher1<SplashScreen*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("SplashScreen::update", &pusher);
}

int CallSplashScreenGetStateCallbacks(SplashScreen* thisptr, int defaultVal)
{
    ArgPusher2<SplashScreen*, int> pusher(thisptr, defaultVal);
    return static_cast<int>(KenshiLua::EventSystem::get().callHandlersNumber("SplashScreen::getState", &pusher, defaultVal));
}

bool CallSplashScreenGetEndedCallbacks(SplashScreen* thisptr, bool defaultVal)
{
    ArgPusher2<SplashScreen*, bool> pusher(thisptr, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("SplashScreen::getEnded", &pusher, defaultVal);
}

void CallSplashScreenSkipCallbacks(SplashScreen* thisptr)
{
    ArgPusher1<SplashScreen*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("SplashScreen::skip", &pusher);
}

void CallSplashScreenAddLogoCallbacks(SplashScreen* thisptr, const std::string& file, float scale)
{
    ArgPusher3<SplashScreen*, const std::string&, float> pusher(thisptr, file, scale);
    KenshiLua::EventSystem::get().callHandlers("SplashScreen::addLogo", &pusher);
}


// GUI hook callbacks: OrdersPanel, OptionsWindow, MapScreen,
// ManagementScreen, and TitleScreen.

void CallOrderCellViewConstructedCallbacks(OrderCellView* self, MyGUI::Widget* parent)
{
    ArgPusher2<OrderCellView*, KenshiLua::WidgetArg> pusher(self, parent);
    KenshiLua::EventSystem::get().callHandlers("OrderCellView::_CONSTRUCTOR", &pusher);
}

void CallOrderCellViewDestructorCallbacks(OrderCellView* self)
{
    ArgPusher1<OrderCellView*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("OrderCellView::_DESTRUCTOR", &pusher);
}

void CallOrderCellViewUpdateCallbacks(OrderCellView* self, void* info, OrderData* data)
{
    ArgPusher3<OrderCellView*, void*, OrderData*> pusher(self, info, data);
    KenshiLua::EventSystem::get().callHandlers("OrderCellView::update", &pusher);
}

void CallOrderCellViewGetCellDimensionCallbacks(MyGUI::Widget* sender, const MyGUI::IntCoord& coord, bool drop)
{
    ArgPusher3<KenshiLua::WidgetArg, const MyGUI::IntCoord&, bool> pusher(sender, coord, drop);
    KenshiLua::EventSystem::get().callHandlers("OrderCellView::getCellDimension", &pusher);
}

void CallOrderCellViewGetWidgetCallbacks(OrderCellView* self, MyGUI::Widget* result)
{
    ArgPusher2<OrderCellView*, KenshiLua::WidgetArg> pusher(self, result);
    KenshiLua::EventSystem::get().callHandlers("OrderCellView::getWidget", &pusher);
}

void CallOrderCellViewOnRemoveCallbacks(OrderCellView* self, MyGUI::Widget* sender)
{
    ArgPusher2<OrderCellView*, KenshiLua::WidgetArg> pusher(self, sender);
    KenshiLua::EventSystem::get().callHandlers("OrderCellView::onRemove", &pusher);
}

void CallOrderCellViewResizeCallbacks(OrderCellView* self)
{
    ArgPusher1<OrderCellView*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("OrderCellView::resize", &pusher);
}

void CallOrderDataConstructedCallbacks(OrderData* self)
{
    ArgPusher1<OrderData*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("OrderData::_CONSTRUCTOR", &pusher);
}

void CallOrderDataSetCallbacks(OrderData* self, Tasker* task, int index, bool enabled)
{
    ArgPusher4<OrderData*, Tasker*, int, bool> pusher(self, task, index, enabled);
    KenshiLua::EventSystem::get().callHandlers("OrderData::set", &pusher);
}

void CallOrderDataUpdateTextCallbacks(OrderData* self)
{
    ArgPusher1<OrderData*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("OrderData::updateText", &pusher);
}

void CallOrderDataDestructorCallbacks(OrderData* self)
{
    ArgPusher1<OrderData*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("OrderData::_DESTRUCTOR", &pusher);
}

void CallOrderDataAssignCallbacks(OrderData* self, OrderData* other, OrderData* result)
{
    ArgPusher3<OrderData*, OrderData*, OrderData*> pusher(self, other, result);
    KenshiLua::EventSystem::get().callHandlers("OrderData::operator=", &pusher);
}

void CallOrdersItemBoxConstructedCallbacks(OrdersItemBox* self, MyGUI::Widget* parent)
{
    ArgPusher2<OrdersItemBox*, KenshiLua::WidgetArg> pusher(self, parent);
    KenshiLua::EventSystem::get().callHandlers("OrdersItemBox::_CONSTRUCTOR", &pusher);
}

void CallOrdersItemBoxDestructorCallbacks(OrdersItemBox* self)
{
    ArgPusher1<OrdersItemBox*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("OrdersItemBox::_DESTRUCTOR", &pusher);
}

void CallOrdersPanelConstructedCallbacks(OrdersPanel* self, MainBarGUI* mainbar, MyGUI::Widget* panel)
{
    ArgPusher3<OrdersPanel*, MainBarGUI*, KenshiLua::WidgetArg> pusher(self, mainbar, panel);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::_CONSTRUCTOR", &pusher);
}

void CallOrdersPanelDestructorCallbacks(OrdersPanel* self)
{
    ArgPusher1<OrdersPanel*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::_DESTRUCTOR", &pusher);
}

void CallOrdersPanelUpdateCallbacks(OrdersPanel* self, Character* character)
{
    ArgPusher2<OrdersPanel*, Character*> pusher(self, character);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::update", &pusher);
}

void CallOrdersPanelClearCallbacks(OrdersPanel* self)
{
    ArgPusher1<OrdersPanel*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::clear", &pusher);
}

void CallOrdersPanelCommandCallbacks(OrdersPanel* self, int command)
{
    ArgPusher2<OrdersPanel*, int> pusher(self, command);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::command", &pusher);
}

void CallOrdersPanelRefreshOrdersCallbacks(OrdersPanel* self)
{
    ArgPusher1<OrdersPanel*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::refreshOrders", &pusher);
}

void CallOrdersPanelMoveJobCallbacks(OrdersPanel* self, int orderIndex, int targetIndex)
{
    ArgPusher3<OrdersPanel*, int, int> pusher(self, orderIndex, targetIndex);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::moveJob", &pusher);
}

void CallOrdersPanelRemoveJobCallbacks(OrdersPanel* self, OrderData* data)
{
    ArgPusher2<OrdersPanel*, OrderData*> pusher(self, data);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::removeJob", &pusher);
}

bool CallOrdersPanelNotifyStartDropOrderCallbacks(OrdersPanel* self, wraps::BaseLayout* sender, void* info, bool defaultVal)
{
    ArgPusher4<OrdersPanel*, wraps::BaseLayout*, void*, bool> pusher(self, sender, info, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("OrdersPanel::notifyStartDropOrder", &pusher, defaultVal);
}

bool CallOrdersPanelNotifyRequestDropOrderCallbacks(OrdersPanel* self, wraps::BaseLayout* sender, void* info, bool defaultVal)
{
    ArgPusher4<OrdersPanel*, wraps::BaseLayout*, void*, bool> pusher(self, sender, info, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("OrdersPanel::notifyRequestDropOrder", &pusher, defaultVal);
}

void CallOrdersPanelNotifyEndDropOrderCallbacks(OrdersPanel* self, wraps::BaseLayout* sender, void* info, bool result)
{
    ArgPusher4<OrdersPanel*, wraps::BaseLayout*, void*, bool> pusher(self, sender, info, result);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::notifyEndDropOrder", &pusher);
}

void CallOrdersPanelToggleStealthCallbacks(OrdersPanel* self, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, KenshiLua::WidgetArg> pusher(self, sender);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::toggleStealth", &pusher);
}

void CallOrdersPanelToggleRangedCallbacks(OrdersPanel* self, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, KenshiLua::WidgetArg> pusher(self, sender);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::toggleRanged", &pusher);
}

void CallOrdersPanelSetSpeedCallbacks(OrdersPanel* self, int speed)
{
    ArgPusher2<OrdersPanel*, int> pusher(self, speed);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::setSpeed", &pusher);
}

void CallOrdersPanelSetSpeedImageCallbacks(OrdersPanel* self, int speed)
{
    ArgPusher2<OrdersPanel*, int> pusher(self, speed);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::setSpeedImage", &pusher);
}

void CallOrdersPanelSpeedPreviousCallbacks(OrdersPanel* self, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, KenshiLua::WidgetArg> pusher(self, sender);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::speedPrevious", &pusher);
}

void CallOrdersPanelSpeedNextCallbacks(OrdersPanel* self, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, KenshiLua::WidgetArg> pusher(self, sender);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::speedNext", &pusher);
}

OptionsWindow* CallOptionsWindowGetSingletonCallbacks(OptionsWindow* defaultVal)
{
    ArgPusher1<OptionsWindow*> pusher(defaultVal);
    return static_cast<OptionsWindow*>(KenshiLua::EventSystem::get().callHandlersObject("OptionsWindow::getSingleton", KenshiLua::OptionsWindowMetatable(), &pusher));
}

void CallOptionsWindowNVShowCallbacks(OptionsWindow* self, bool value)
{
    ArgPusher2<OptionsWindow*, bool> pusher(self, value);
    KenshiLua::EventSystem::get().callHandlers("OptionsWindow::_NV_show", &pusher);
}

void CallOptionsWindowShowCallbacks(OptionsWindow* self)
{
    ArgPusher1<OptionsWindow*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("OptionsWindow::show", &pusher);
}

void CallOptionsWindowHideCallbacks(OptionsWindow* self)
{
    ArgPusher1<OptionsWindow*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("OptionsWindow::hide", &pusher);
}

void CallOptionsWindowToggleCallbacks(OptionsWindow* self)
{
    ArgPusher1<OptionsWindow*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("OptionsWindow::toggle", &pusher);
}

bool CallOptionsWindowIsVisibleCallbacks(OptionsWindow* self, bool defaultVal)
{
    ArgPusher2<OptionsWindow*, bool> pusher(self, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("OptionsWindow::isVisible", &pusher, defaultVal);
}

bool CallOptionsWindowWaitingForKeyCallbacks(OptionsWindow* self, bool defaultVal)
{
    ArgPusher2<OptionsWindow*, bool> pusher(self, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("OptionsWindow::waitingForKey", &pusher, defaultVal);
}

void CallOptionsWindowSetKeyCallbacks(OptionsWindow* self, int code)
{
    ArgPusher2<OptionsWindow*, int> pusher(self, code);
    KenshiLua::EventSystem::get().callHandlers("OptionsWindow::setKey", &pusher);
}

void CallOptionsWindowNVUpdateCallbacks(OptionsWindow* self)
{
    ArgPusher1<OptionsWindow*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("OptionsWindow::_NV_update", &pusher);
}

void CallOptionsWindowConstructedCallbacks(OptionsWindow* self)
{
    ArgPusher1<OptionsWindow*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("OptionsWindow::_CONSTRUCTOR", &pusher);
}

void CallOptionsWindowDestructorCallbacks(OptionsWindow* self)
{
    ArgPusher1<OptionsWindow*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("OptionsWindow::_DESTRUCTOR", &pusher);
}

void CallOptionsWindowSaveLocationChangedCallbacks(OptionsWindow* self, DataPanelLine* line)
{
    ArgPusher2<OptionsWindow*, DataPanelLine*> pusher(self, line);
    KenshiLua::EventSystem::get().callHandlers("OptionsWindow::saveLocationChanged", &pusher);
}

void CallOptionsWindowChangeFontSizeCallbacks(OptionsWindow* self, DataPanelLine* line)
{
    ArgPusher2<OptionsWindow*, DataPanelLine*> pusher(self, line);
    KenshiLua::EventSystem::get().callHandlers("OptionsWindow::changeFontSize", &pusher);
}

void CallOptionsWindowChangeVolumeCallbacks(OptionsWindow* self, DataPanelLine* line)
{
    ArgPusher2<OptionsWindow*, DataPanelLine*> pusher(self, line);
    KenshiLua::EventSystem::get().callHandlers("OptionsWindow::changeVolume", &pusher);
}

void CallOptionsWindowToggleNamesCallbacks(OptionsWindow* self, DataPanelLine* line)
{
    ArgPusher2<OptionsWindow*, DataPanelLine*> pusher(self, line);
    KenshiLua::EventSystem::get().callHandlers("OptionsWindow::toggleNames", &pusher);
}

void CallOptionsWindowResetTutorialsCallbacks(OptionsWindow* self, DataPanelLine* line)
{
    ArgPusher2<OptionsWindow*, DataPanelLine*> pusher(self, line);
    KenshiLua::EventSystem::get().callHandlers("OptionsWindow::resetTutorials", &pusher);
}

void CallOptionsWindowToggleTutorialsCallbacks(OptionsWindow* self, DataPanelLine* line)
{
    ArgPusher2<OptionsWindow*, DataPanelLine*> pusher(self, line);
    KenshiLua::EventSystem::get().callHandlers("OptionsWindow::toggleTutorials", &pusher);
}

void CallOptionsWindowChangeDistancesCallbacks(OptionsWindow* self, DataPanelLine* line)
{
    ArgPusher2<OptionsWindow*, DataPanelLine*> pusher(self, line);
    KenshiLua::EventSystem::get().callHandlers("OptionsWindow::changeDistances", &pusher);
}

void CallOptionsWindowToggleCompositorCallbacks(OptionsWindow* self, DataPanelLine* line)
{
    ArgPusher2<OptionsWindow*, DataPanelLine*> pusher(self, line);
    KenshiLua::EventSystem::get().callHandlers("OptionsWindow::toggleCompositor", &pusher);
}

void CallOptionsWindowResetAllKeysCallbacks(OptionsWindow* self, DataPanelLine* line)
{
    ArgPusher2<OptionsWindow*, DataPanelLine*> pusher(self, line);
    KenshiLua::EventSystem::get().callHandlers("OptionsWindow::resetAllKeys", &pusher);
}

void CallOptionsWindowSaveOptionsCallbacks(OptionsWindow* self)
{
    ArgPusher1<OptionsWindow*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("OptionsWindow::saveOptions", &pusher);
}

void CallOptionsWindowCreateCallbacks(OptionsWindow* self)
{
    ArgPusher1<OptionsWindow*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("OptionsWindow::create", &pusher);
}

void CallOptionsWindowUpdateResolutionsCallbacks(OptionsWindow* self)
{
    ArgPusher1<OptionsWindow*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("OptionsWindow::updateResolutions", &pusher);
}

void CallOptionsWindowCloseButtonCallbacks(OptionsWindow* self, MyGUI::Widget* sender)
{
    ArgPusher2<OptionsWindow*, KenshiLua::WidgetArg> pusher(self, sender);
    KenshiLua::EventSystem::get().callHandlers("OptionsWindow::closeButton", &pusher);
}

void CallMapMarkerTownConstructedCallbacks(MapScreen::MapMarkerTown* self, TownBase* town, MapScreen* mapScreen)
{
    ArgPusher3<MapScreen::MapMarkerTown*, TownBase*, MapScreen*> pusher(self, town, mapScreen);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::MapMarkerTown::_CONSTRUCTOR", &pusher);
}

void CallMapMarkerTownDestructorCallbacks(MapScreen::MapMarkerTown* self)
{
    ArgPusher1<MapScreen::MapMarkerTown*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::MapMarkerTown::_DESTRUCTOR", &pusher);
}

void CallMapMarkerTownUpdateCallbacks(MapScreen::MapMarkerTown* self, const MyGUI::IntPoint& mapPosition, int zoom)
{
    ArgPusher3<MapScreen::MapMarkerTown*, const MyGUI::IntPoint&, int> pusher(self, mapPosition, zoom);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::MapMarkerTown::update", &pusher);
}

void CallMapMarkerTownSetVisibleCallbacks(MapScreen::MapMarkerTown* self, bool value)
{
    ArgPusher2<MapScreen::MapMarkerTown*, bool> pusher(self, value);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::MapMarkerTown::setVisible", &pusher);
}

bool CallMapMarkerTownGetVisibleCallbacks(MapScreen::MapMarkerTown* self, bool defaultVal)
{
    ArgPusher2<MapScreen::MapMarkerTown*, bool> pusher(self, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("MapScreen::MapMarkerTown::getVisible", &pusher, defaultVal);
}

void CallMapMarkerCharacterConstructedCallbacks(MapScreen::MapMarkerCharacter* self, RootObjectBase* character, MapScreen* mapScreen)
{
    ArgPusher3<MapScreen::MapMarkerCharacter*, RootObjectBase*, MapScreen*> pusher(self, character, mapScreen);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::MapMarkerCharacter::_CONSTRUCTOR", &pusher);
}

void CallMapMarkerCharacterDestructorCallbacks(MapScreen::MapMarkerCharacter* self)
{
    ArgPusher1<MapScreen::MapMarkerCharacter*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::MapMarkerCharacter::_DESTRUCTOR", &pusher);
}

void CallMapMarkerCharacterUpdateCallbacks(MapScreen::MapMarkerCharacter* self, const MyGUI::IntPoint& mapPosition)
{
    ArgPusher2<MapScreen::MapMarkerCharacter*, const MyGUI::IntPoint&> pusher(self, mapPosition);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::MapMarkerCharacter::update", &pusher);
}

void CallMapMarkerCharacterSetVisibleCallbacks(MapScreen::MapMarkerCharacter* self, bool value)
{
    ArgPusher2<MapScreen::MapMarkerCharacter*, bool> pusher(self, value);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::MapMarkerCharacter::setVisible", &pusher);
}

bool CallMapMarkerCharacterGetVisibleCallbacks(MapScreen::MapMarkerCharacter* self, bool defaultVal)
{
    ArgPusher2<MapScreen::MapMarkerCharacter*, bool> pusher(self, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("MapScreen::MapMarkerCharacter::getVisible", &pusher, defaultVal);
}

void CallMapScreenConstructedCallbacks(MapScreen* self, ManagementScreen* screen)
{
    ArgPusher2<MapScreen*, ManagementScreen*> pusher(self, screen);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::_CONSTRUCTOR", &pusher);
}

void CallMapScreenDestructorCallbacks(MapScreen* self)
{
    ArgPusher1<MapScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::_DESTRUCTOR", &pusher);
}

void CallMapScreenClearCallbacks(MapScreen* self)
{
    ArgPusher1<MapScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::clear", &pusher);
}

bool CallMapScreenGetVisibleCallbacks(MapScreen* self, bool defaultVal)
{
    ArgPusher2<MapScreen*, bool> pusher(self, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("MapScreen::getVisible", &pusher, defaultVal);
}

void CallMapScreenCenterCameraCallbacks(MapScreen* self)
{
    ArgPusher1<MapScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::centerCamera", &pusher);
}

void CallMapScreenClearTempMarkersCallbacks(MapScreen* self)
{
    ArgPusher1<MapScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::clearTempMarkers", &pusher);
}

void CallMapScreenRefreshCallbacks(MapScreen* self)
{
    ArgPusher1<MapScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::refresh", &pusher);
}

void CallMapScreenUpdateCallbacks(MapScreen* self)
{
    ArgPusher1<MapScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::update", &pusher);
}

void CallMapScreenAddSquadCallbacks(MapScreen* self, Platoon* squad)
{
    ArgPusher2<MapScreen*, Platoon*> pusher(self, squad);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::addSquad", &pusher);
}

void CallMapScreenRemoveSquadCallbacks(MapScreen* self, Platoon* squad)
{
    ArgPusher2<MapScreen*, Platoon*> pusher(self, squad);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::removeSquad", &pusher);
}

void CallMapScreenHideCallbacks(MapScreen* self)
{
    ArgPusher1<MapScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::hide", &pusher);
}

void CallMapScreenSetMovementMarkerCallbacks(MapScreen* self, const Ogre::Vector3& position, float time)
{
    ArgPusher3<MapScreen*, const Ogre::Vector3&, float> pusher(self, position, time);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::setMovementMarker", &pusher);
}

void CallMapScreenShowRoadsCallbacks(MapScreen* self, bool on)
{
    ArgPusher2<MapScreen*, bool> pusher(self, on);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::showRoads", &pusher);
}

void CallMapScreenUpdatePlayerTownMapMarkerCallbacks(MapScreen* self, const hand& town)
{
    ArgPusher2<MapScreen*, const hand&> pusher(self, town);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::updatePlayerTownMapMarker", &pusher);
}

void CallMapScreenUpdateZoomCallbacks(MapScreen* self)
{
    ArgPusher1<MapScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::updateZoom", &pusher);
}

void CallMapScreenUpdateCameraMarkerCallbacks(MapScreen* self)
{
    ArgPusher1<MapScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::updateCameraMarker", &pusher);
}

void CallMapScreenRefreshTownsCallbacks(MapScreen* self)
{
    ArgPusher1<MapScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::refreshTowns", &pusher);
}

void CallMapScreenRefreshSquadsCallbacks(MapScreen* self)
{
    ArgPusher1<MapScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::refreshSquads", &pusher);
}

void CallMapScreenUpdateCharacterMarkerCallbacks(MapScreen* self, RootObjectBase* object)
{
    ArgPusher2<MapScreen*, RootObjectBase*> pusher(self, object);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::updateCharacterMarker", &pusher);
}

bool CallMapScreenGetMouseWorldPositionCallbacks(MapScreen* self, const Ogre::Vector3& position, bool defaultVal)
{
    ArgPusher3<MapScreen*, const Ogre::Vector3&, bool> pusher(self, position, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("MapScreen::getMouseWorldPosition", &pusher, defaultVal);
}

void CallMapScreenWorldToMapCoordsCallbacks(MapScreen* self, const Ogre::Vector3& position, const MyGUI::IntPoint& result)
{
    ArgPusher3<MapScreen*, const Ogre::Vector3&, const MyGUI::IntPoint&> pusher(self, position, result);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::worldToMapCoords", &pusher);
}

void CallMapScreenMapCoordsToWorldCallbacks(MapScreen* self, const MyGUI::IntPoint& point, const Ogre::Vector3& result)
{
    ArgPusher3<MapScreen*, const MyGUI::IntPoint&, const Ogre::Vector3&> pusher(self, point, result);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::mapCoordsToWorld", &pusher);
}

void CallMapScreenMapMouseWheelCallbacks(MapScreen* self, MyGUI::Widget* sender, int rel)
{
    ArgPusher3<MapScreen*, KenshiLua::WidgetArg, int> pusher(self, sender, rel);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::mapMouseWheel", &pusher);
}

void CallMapScreenMapMousePressedCallbacks(MapScreen* self, MyGUI::Widget* sender, int left, int top, int id)
{
    ArgPusher5<MapScreen*, KenshiLua::WidgetArg, int, int, int> pusher(self, sender, left, top, id);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::mapMousePressed", &pusher);
}

void CallMapScreenMapMouseReleasedCallbacks(MapScreen* self, MyGUI::Widget* sender, int left, int top, int id)
{
    ArgPusher5<MapScreen*, KenshiLua::WidgetArg, int, int, int> pusher(self, sender, left, top, id);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::mapMouseReleased", &pusher);
}

void CallMapScreenSetupRoadsCallbacks(MapScreen* self)
{
    ArgPusher1<MapScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::setupRoads", &pusher);
}

void CallMapScreenUpdateRoadsCallbacks(MapScreen* self)
{
    ArgPusher1<MapScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::updateRoads", &pusher);
}

void CallMapScreenCenterButtonCallbacks(MapScreen* self, MyGUI::Widget* sender)
{
    ArgPusher2<MapScreen*, KenshiLua::WidgetArg> pusher(self, sender);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::centerButton", &pusher);
}

void CallMapScreenZoomInButtonCallbacks(MapScreen* self, MyGUI::Widget* sender)
{
    ArgPusher2<MapScreen*, KenshiLua::WidgetArg> pusher(self, sender);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::zoomInButton", &pusher);
}

void CallMapScreenZoomOutButtonCallbacks(MapScreen* self, MyGUI::Widget* sender)
{
    ArgPusher2<MapScreen*, KenshiLua::WidgetArg> pusher(self, sender);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::zoomOutButton", &pusher);
}

void CallMapScreenGetMarkerColorCallbacks(RootObjectBase* who, const MyGUI::Colour& result)
{
    ArgPusher2<RootObjectBase*, const MyGUI::Colour&> pusher(who, result);
    KenshiLua::EventSystem::get().callHandlers("MapScreen::getMarkerColor", &pusher);
}

ManagementScreen* CallManagementScreenGetSingletonCallbacks(ManagementScreen* defaultVal)
{
    ArgPusher1<ManagementScreen*> pusher(defaultVal);
    return static_cast<ManagementScreen*>(KenshiLua::EventSystem::get().callHandlersObject("ManagementScreen::getSingleton", KenshiLua::ManagementScreenMetatable(), &pusher));
}

void CallManagementScreenDestructorCallbacks(ManagementScreen* self)
{
    ArgPusher1<ManagementScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::_DESTRUCTOR", &pusher);
}

void CallManagementScreenUpdateCallbacks(ManagementScreen* self)
{
    ArgPusher1<ManagementScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::update", &pusher);
}

void CallManagementScreenClearCallbacks(ManagementScreen* self)
{
    ArgPusher1<ManagementScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::clear", &pusher);
}

bool CallManagementScreenGetVisibleCallbacks(ManagementScreen* self, bool defaultVal)
{
    ArgPusher2<ManagementScreen*, bool> pusher(self, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("ManagementScreen::getVisible", &pusher, defaultVal);
}

void CallManagementScreenSetVisibleCallbacks(ManagementScreen* self, bool on, int tab)
{
    ArgPusher3<ManagementScreen*, bool, int> pusher(self, on, tab);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::setVisible", &pusher);
}

void CallManagementScreenCloseEverythingButtonCallbacks(ManagementScreen* self, MyGUI::Widget* widget, const std::string& name)
{
    ArgPusher3<ManagementScreen*, KenshiLua::WidgetArg, const std::string&> pusher(self, widget, name);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::closeEverythingButton", &pusher);
}

void CallManagementScreenTabCallbackCallbacks(ManagementScreen* self, MyGUI::Widget* sender, double index)
{
    ArgPusher3<ManagementScreen*, KenshiLua::WidgetArg, double> pusher(self, sender, index);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::tabCallback", &pusher);
}

double CallManagementScreenGetCurrentTabCallbacks(ManagementScreen* self, double defaultVal)
{
    ArgPusher2<ManagementScreen*, double> pusher(self, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersNumber("ManagementScreen::getCurrentTab", &pusher, defaultVal);
}

void CallManagementScreenGetTabCallbacks(ManagementScreen* self, int index, MyGUI::Widget* result)
{
    ArgPusher3<ManagementScreen*, int, KenshiLua::WidgetArg> pusher(self, index, result);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::getTab", &pusher);
}

void CallManagementScreenGetWidgetCallbacks(ManagementScreen* self, const std::string& name, MyGUI::Widget* result)
{
    ArgPusher3<ManagementScreen*, const std::string&, KenshiLua::WidgetArg> pusher(self, name, result);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::getWidget", &pusher);
}

void CallManagementScreenRefreshCallbacks(ManagementScreen* self, GameData* current, float progress)
{
    ArgPusher3<ManagementScreen*, GameData*, float> pusher(self, current, progress);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::refresh", &pusher);
}

void CallManagementScreenRefreshResearchListCallbacks(ManagementScreen* self)
{
    ArgPusher1<ManagementScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::refreshResearchList", &pusher);
}

void CallManagementScreenRefreshResearchRateCallbacks(ManagementScreen* self)
{
    ArgPusher1<ManagementScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::refreshResearchRate", &pusher);
}

void CallManagementScreenRefreshDiplomacyCallbacks(ManagementScreen* self)
{
    ArgPusher1<ManagementScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::refreshDiplomacy", &pusher);
}

void CallManagementScreenRefreshSquadsCallbacks(ManagementScreen* self)
{
    ArgPusher1<ManagementScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::refreshSquads", &pusher);
}

void CallManagementScreenRefreshMapCallbacks(ManagementScreen* self, bool centerCamera)
{
    ArgPusher2<ManagementScreen*, bool> pusher(self, centerCamera);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::refreshMap", &pusher);
}

void CallManagementScreenShowRoadsCallbacks(ManagementScreen* self, bool value)
{
    ArgPusher2<ManagementScreen*, bool> pusher(self, value);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::showRoads", &pusher);
}

void CallManagementScreenAddSquadToMapCallbacks(ManagementScreen* self, Platoon* squad)
{
    ArgPusher2<ManagementScreen*, Platoon*> pusher(self, squad);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::addSquadToMap", &pusher);
}

void CallManagementScreenRemoveSquadFromMapCallbacks(ManagementScreen* self, Platoon* squad)
{
    ArgPusher2<ManagementScreen*, Platoon*> pusher(self, squad);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::removeSquadFromMap", &pusher);
}

void CallManagementScreenResetSquadsCallbacks(ManagementScreen* self)
{
    ArgPusher1<ManagementScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::resetSquads", &pusher);
}

void CallManagementScreenRefreshMessagesCallbacks(ManagementScreen* self)
{
    ArgPusher1<ManagementScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::refreshMessages", &pusher);
}

void CallManagementScreenRefreshAICallbacks(ManagementScreen* self)
{
    ArgPusher1<ManagementScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::refreshAI", &pusher);
}

void CallManagementScreenSetCraftingBenchCallbacks(ManagementScreen* self, const hand& buildingHandle)
{
    ArgPusher2<ManagementScreen*, const hand&> pusher(self, buildingHandle);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::setCraftingBench", &pusher);
}

void CallManagementScreenPrintResearchCallbacks(DatapanelGUI* panel, GameData* data, const std::string& listName, const std::string& displayName, int category)
{
    ArgPusher5<DatapanelGUI*, GameData*, const std::string&, const std::string&, int> pusher(panel, data, listName, displayName, category);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::printResearch", &pusher);
}

void CallManagementScreenShowDebugMarkerCallbacks(ManagementScreen* self, const Ogre::Vector3& position)
{
    ArgPusher2<ManagementScreen*, const Ogre::Vector3&> pusher(self, position);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::showDebugMarker", &pusher);
}

void CallManagementScreenConstructedCallbacks(ManagementScreen* self)
{
    ArgPusher1<ManagementScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::_CONSTRUCTOR", &pusher);
}

void CallManagementScreenUpdateResearchListRateCallbacks(ManagementScreen* self)
{
    ArgPusher1<ManagementScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::updateResearchListRate", &pusher);
}

void CallManagementScreenRefreshResearchListDescriptionCallbacks(ManagementScreen* self)
{
    ArgPusher1<ManagementScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::refreshResearchListDescription", &pusher);
}

void CallManagementScreenResearchTypeSelectCallbacks(ManagementScreen* self, MyGUI::Widget* sender, double index)
{
    ArgPusher3<ManagementScreen*, KenshiLua::WidgetArg, double> pusher(self, sender, index);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::researchTypeSelect", &pusher);
}

void CallManagementScreenAddButtonPressCallbacks(ManagementScreen* self, MyGUI::Widget* sender, int left, int top, int id)
{
    ArgPusher5<ManagementScreen*, KenshiLua::WidgetArg, int, int, int> pusher(self, sender, left, top, id);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::addButtonPress", &pusher);
}

void CallManagementScreenRemoveButtonPressCallbacks(ManagementScreen* self, MyGUI::Widget* sender, int left, int top, int id)
{
    ArgPusher5<ManagementScreen*, KenshiLua::WidgetArg, int, int, int> pusher(self, sender, left, top, id);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::removeButtonPress", &pusher);
}

void CallManagementScreenMouseOverCallbacks(ManagementScreen* self, MyGUI::Widget* sender, int left, int top)
{
    ArgPusher4<ManagementScreen*, KenshiLua::WidgetArg, int, int> pusher(self, sender, left, top);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::mouseOverCallback", &pusher);
}

void CallTechItemViewDataGetNameCallbacks(ManagementScreen::TechItemViewData* self, const std::string& result)
{
    ArgPusher2<ManagementScreen::TechItemViewData*, const std::string&> pusher(self, result);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::TechItemViewData::getName", &pusher);
}

void CallTechItemViewDataGetValueCallbacks(ManagementScreen::TechItemViewData* self, const std::string& result)
{
    ArgPusher2<ManagementScreen::TechItemViewData*, const std::string&> pusher(self, result);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::TechItemViewData::getValue", &pusher);
}

double CallTechItemViewDataGetProgressCallbacks(ManagementScreen::TechItemViewData* self, double defaultVal)
{
    ArgPusher2<ManagementScreen::TechItemViewData*, double> pusher(self, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersNumber("ManagementScreen::TechItemViewData::getProgress", &pusher, defaultVal);
}

void CallTechItemViewDataSetItemCallbacks(ManagementScreen::TechItemViewData* self, void* item)
{
    ArgPusher2<ManagementScreen::TechItemViewData*, void*> pusher(self, item);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::TechItemViewData::setItem", &pusher);
}

void CallTechItemViewDataDestructorCallbacks(ManagementScreen::TechItemViewData* self)
{
    ArgPusher1<ManagementScreen::TechItemViewData*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::TechItemViewData::_DESTRUCTOR", &pusher);
}

void CallManagementScreenResearchQueueTooltipCallbacks(ManagementScreen* self, wraps::BaseLayout* layout, void* info, const ManagementScreen::TechItemViewData& data)
{
    ArgPusher4<ManagementScreen*, wraps::BaseLayout*, void*, const ManagementScreen::TechItemViewData&> pusher(self, layout, info, data);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::researchQueueTooltip", &pusher);
}

void CallManagementScreenResearchRemovedCallbacks(ManagementScreen* self, int index, const ManagementScreen::TechItemViewData& item)
{
    ArgPusher3<ManagementScreen*, int, const ManagementScreen::TechItemViewData&> pusher(self, index, item);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::researchRemoved", &pusher);
}

bool CallManagementScreenResearchValidateOrderCallbacks(ManagementScreen* self, int first, int second, bool defaultVal)
{
    ArgPusher4<ManagementScreen*, int, int, bool> pusher(self, first, second, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("ManagementScreen::researchValidateOrder", &pusher, defaultVal);
}

TitleScreen* CallTitleScreenGetSingletonCallbacks(TitleScreen* defaultVal)
{
    ArgPusher1<TitleScreen*> pusher(defaultVal);
    return static_cast<TitleScreen*>(KenshiLua::EventSystem::get().callHandlersObject("TitleScreen::getSingleton", KenshiLua::TitleScreenMetatable(), &pusher));
}

void CallTitleScreenConstructedCallbacks(TitleScreen* self)
{
    ArgPusher1<TitleScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("TitleScreen::_CONSTRUCTOR", &pusher);
}

void CallTitleScreenDestructorCallbacks(TitleScreen* self)
{
    ArgPusher1<TitleScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("TitleScreen::_DESTRUCTOR", &pusher);
}

void CallTitleScreenNVClearCallbacks(TitleScreen* self)
{
    ArgPusher1<TitleScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("TitleScreen::_NV_clear", &pusher);
}

void CallTitleScreenNVShowCallbacks(TitleScreen* self, bool on)
{
    ArgPusher2<TitleScreen*, bool> pusher(self, on);
    KenshiLua::EventSystem::get().callHandlers("TitleScreen::_NV_show", &pusher);
}

void CallTitleScreenNVUpdateCallbacks(TitleScreen* self)
{
    ArgPusher1<TitleScreen*> pusher(self);
    KenshiLua::EventSystem::get().callHandlers("TitleScreen::_NV_update", &pusher);
}

bool CallTitleScreenCloseTheOtherBitsCallbacks(TitleScreen* self, bool defaultVal)
{
    ArgPusher2<TitleScreen*, bool> pusher(self, defaultVal);
    return KenshiLua::EventSystem::get().callHandlersBool("TitleScreen::closeTheOtherBits", &pusher, defaultVal);
}

void CallTitleScreenImportGameCallbacks(TitleScreen* self, MyGUI::Widget* sender)
{
    ArgPusher2<TitleScreen*, KenshiLua::WidgetArg> pusher(self, sender);
    KenshiLua::EventSystem::get().callHandlers("TitleScreen::importGame", &pusher);
}

void CallTitleScreenShowOptionsCallbacks(TitleScreen* self, MyGUI::Widget* sender)
{
    ArgPusher2<TitleScreen*, KenshiLua::WidgetArg> pusher(self, sender);
    KenshiLua::EventSystem::get().callHandlers("TitleScreen::showOptions", &pusher);
}

void CallTitleScreenCreditsCallbacks(TitleScreen* self, MyGUI::Widget* sender)
{
    ArgPusher2<TitleScreen*, KenshiLua::WidgetArg> pusher(self, sender);
    KenshiLua::EventSystem::get().callHandlers("TitleScreen::credits", &pusher);
}

void CallTitleScreenExitGameCallbacks(TitleScreen* self, MyGUI::Widget* sender)
{
    ArgPusher2<TitleScreen*, KenshiLua::WidgetArg> pusher(self, sender);
    KenshiLua::EventSystem::get().callHandlers("TitleScreen::exitGame", &pusher);
}

void CallTitleScreenContinueGameCallbacks(TitleScreen* self, MyGUI::Widget* sender)
{
    ArgPusher2<TitleScreen*, KenshiLua::WidgetArg> pusher(self, sender);
    KenshiLua::EventSystem::get().callHandlers("TitleScreen::continueGame", &pusher);
}

void CallTitleScreenHoverCallbacks(TitleScreen* self, MyGUI::Widget* sender, MyGUI::Widget* other)
{
    ArgPusher3<TitleScreen*, KenshiLua::WidgetArg, KenshiLua::WidgetArg> pusher(self, sender, other);
    KenshiLua::EventSystem::get().callHandlers("TitleScreen::hover", &pusher);
}

void CallTitleScreenSetCreditsVisibleCallbacks(TitleScreen* self, bool value)
{
    ArgPusher2<TitleScreen*, bool> pusher(self, value);
    KenshiLua::EventSystem::get().callHandlers("TitleScreen::setCreditsVisible", &pusher);
}

void CallOrdersPanelBlockModeButtonCallbacks(OrdersPanel* self, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, KenshiLua::WidgetArg> pusher(self, sender);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::blockmodeButton", &pusher);
}

void CallOrdersPanelHoldButtonCallbacks(OrdersPanel* self, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, KenshiLua::WidgetArg> pusher(self, sender);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::holdButtonCallback", &pusher);
}

void CallOrdersPanelPassiveButtonCallbacks(OrdersPanel* self, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, KenshiLua::WidgetArg> pusher(self, sender);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::passiveButtonCallback", &pusher);
}

void CallOrdersPanelChaseButtonCallbacks(OrdersPanel* self, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, KenshiLua::WidgetArg> pusher(self, sender);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::chaseButtonCallback", &pusher);
}

void CallOrdersPanelTauntButtonCallbacks(OrdersPanel* self, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, KenshiLua::WidgetArg> pusher(self, sender);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::tauntButtonCallback", &pusher);
}

void CallOrdersPanelMedicButtonCallbacks(OrdersPanel* self, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, KenshiLua::WidgetArg> pusher(self, sender);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::medicButton", &pusher);
}

void CallOrdersPanelLiftButtonCallbacks(OrdersPanel* self, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, KenshiLua::WidgetArg> pusher(self, sender);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::liftButton", &pusher);
}

void CallOrdersPanelProspectingButtonCallbacks(OrdersPanel* self, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, KenshiLua::WidgetArg> pusher(self, sender);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::prospectingButton", &pusher);
}

void CallManagementScreenAddMessageCallbacks(ManagementScreen* self, const std::string& owner, const std::string& message, int logColor)
{
    ArgPusher4<ManagementScreen*, const std::string&, const std::string&, int> pusher(self, owner, message, logColor);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::addMessage", &pusher);
}

void CallTitleScreenLoadGameCallbacks(TitleScreen* self, MyGUI::Widget* sender)
{
    ArgPusher2<TitleScreen*, KenshiLua::WidgetArg> pusher(self, sender);
    KenshiLua::EventSystem::get().callHandlers("TitleScreen::loadGame", &pusher);
}
