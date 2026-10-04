#include "pch.h"
#include "Callbacks.h"
#include "EventSystem.h"
#include "Lua/BindingHelpers.h"
#include "Logger.h"

// KenshiLib x Lua Bindings
#include "Bindings/Kenshi/Building/BuildingBinding.h"
#include "Bindings/Kenshi/Building/UseableStuffBinding.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/CharStatsBinding.h"
#include "Bindings/Kenshi/CombatTechniqueDataBinding.h"
#include "Bindings/Kenshi/DamagesBinding.h"
#include "Bindings/Kenshi/DialogLineDataBinding.h"
#include "Bindings/Kenshi/DialogueBinding.h"
#include "Bindings/Kenshi/FactionBinding.h"
#include "Bindings/Kenshi/FactionManagerBinding.h"
#include "Bindings/Kenshi/FactionWarMgrBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/AppearanceManagerBinding.h"
#include "Bindings/Kenshi/AttachedArrowManagerBinding.h"
#include "Bindings/Kenshi/BountyManagerBinding.h"
#include "Bindings/Kenshi/CombatMovementControllerBinding.h"
#include "Bindings/Kenshi/Gui/DialogueWindowBinding.h"
#include "Bindings/Kenshi/Gui/GenericFixedInventoryLayoutBinding.h"
#include "Bindings/Kenshi/InventoryBinding.h"
#include "Bindings/Kenshi/InventorySectionBinding.h"
#include "Bindings/Kenshi/InventoryItemBaseBinding.h"
#include "Bindings/Kenshi/OwnershipsBinding.h"
#include "Bindings/Kenshi/ItemBinding.h"
#include "Bindings/Kenshi/PlatoonBinding.h"
#include "Bindings/Kenshi/PlayerInterfaceBinding.h"
#include "Bindings/Kenshi/CharMovementBinding.h"
#include "Bindings/Kenshi/CombatClassBinding.h"
#include "Bindings/Kenshi/GameWorldBinding.h"
#include "Bindings/Kenshi/RaceDataBinding.h"
#include "Bindings/Kenshi/RootObjectBinding.h"
#include "Bindings/Kenshi/RootObjectBaseBinding.h"
#include "Bindings/Kenshi/RootObjectFactoryBinding.h"
#include "Bindings/Kenshi/ShopTraderBinding.h"
#include "Bindings/Kenshi/TaskerBinding.h"
#include "Bindings/Kenshi/Gui/InventoryGUIBinding.h"
#include "Bindings/Kenshi/Gui/InventoryLayoutBinding.h"
#include "Bindings/Kenshi/Gui/BuildModeWindowBinding.h"
#include "Bindings/Kenshi/Gui/SquadManagementScreenBinding.h"
#include "Bindings/Kenshi/Gui/ManagementScreenBinding.h"
#include "Bindings/Kenshi/Gui/TitleScreenBinding.h"
#include "Bindings/MyGUI/MyGUIBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"
#include "Bindings/Kenshi/MedicalSystemBinding.h"
#include "Bindings/Kenshi/LimbsInventoryLayoutBinding.h"
#include "Bindings/Kenshi/RobotLimbsBinding.h"
#include "Bindings/Kenshi/GameSaveStateBinding.h"
#include "Bindings/Kenshi/GameDataContainerBinding.h"
#include "Bindings/Kenshi/TownBinding.h"
#include "Bindings/Kenshi/Gui/OrdersPanelBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLine_ButtonBinding.h"
#include "Bindings/Kenshi/InputHandlerBinding.h"
#include "Bindings/Kenshi/Gui/BaseLayoutBinding.h"
#include "Bindings/Kenshi/ActivePlatoonBinding.h"
#include "Bindings/Kenshi/ArmourBinding.h"
#include "Bindings/Kenshi/BountyBinding.h"
#include "Bindings/Kenshi/CrossbowBinding.h"
#include "Bindings/Kenshi/GearBinding.h"
#include "Bindings/Kenshi/LockedArmourBinding.h"
#include "Bindings/Kenshi/SwordBinding.h"
#include "Bindings/Kenshi/WeaponBinding.h"
#include "Bindings/Kenshi/DataObjectContainerBinding.h"
#include "Bindings/Kenshi/Building/DoorStuffBinding.h"
#include "Bindings/Kenshi/Building/ProductionBuildingBinding.h"
#include "Bindings/Kenshi/Building/CraftingBuildingBinding.h"
#include "Bindings/Kenshi/Building/FarmBuildingBinding.h"
#include "Bindings/Kenshi/Building/TurretBuildingBinding.h"
#include "Bindings/Kenshi/Building/FurnaceBuildingBinding.h"
#include "Bindings/Kenshi/Building/ResearchBuildingBinding.h"
#include "Bindings/Kenshi/Building/PreviewBuildingBinding.h"
#include "Bindings/Kenshi/Building/WallBuildingBinding.h"
#include "Bindings/Kenshi/Building/StorageBuildingBinding.h"
#include "Bindings/Kenshi/Building/LightBuildingBinding.h"
#include "Bindings/Kenshi/Building/GeneratorBuildingBinding.h"
#include "Bindings/Kenshi/Building/WindGeneratorBuildingBinding.h"
#include "Bindings/Kenshi/Building/GatewayBuildingBinding.h"
#include "Bindings/Kenshi/Building/TortureBuildingBinding.h"
#include "Bindings/Kenshi/Building/RainCollectorBuildingBinding.h"
#include "Bindings/Kenshi/CharacterHumanBinding.h"
#include "Bindings/Kenshi/CharacterAnimalBinding.h"
#include "Bindings/Kenshi/CharBodyBinding.h"
#include "Bindings/Kenshi/TownBaseBinding.h"
#include "Bindings/Kenshi/FactionLeaderBinding.h"
#include "Bindings/Kenshi/FactionRelationsBinding.h"
#include "Bindings/Kenshi/FactionUniqueSquadManagerBinding.h"
#include "Bindings/Kenshi/ProsperityManagerBinding.h"
#include "Bindings/Kenshi/Gui/DataPanelLineBinding.h"
#include "Bindings/Kenshi/Util/rendHitBinding.h"
#include "Bindings/Kenshi/WorldEventStateQueryBinding.h"
#include "Bindings/Kenshi/ZoneManagerBinding.h"
#include "Bindings/Kenshi/ZoneMapBinding.h"

// KenshiLib headers
#include <kenshi/CharMovement.h>
#include <kenshi/AppearanceManager.h>
#include <kenshi/CombatClass.h>
#include <kenshi/GameWorld.h>
#include <kenshi/Building/Building.h>
#include <kenshi/Building/DoorStuff.h>
#include <kenshi/Building/ProductionBuilding.h>
#include <kenshi/Building/CraftingBuilding.h>
#include <kenshi/Building/FarmBuilding.h>
#include <kenshi/Building/TurretBuilding.h>
#include <kenshi/Building/FurnaceBuilding.h>
#include <kenshi/Building/ResearchBuilding.h>
#include <kenshi/Building/UseableStuff.h>
#include <kenshi/Building/WallBuilding.h>
#include <kenshi/Building/StorageBuilding.h>
#include <kenshi/Building/LightBuilding.h>
#include <kenshi/Building/GeneratorBuilding.h>
#include <kenshi/Building/GatewayBuilding.h>
#include <kenshi/Building/TortureBuilding.h>
#include <kenshi/Building/RainCollectorBuilding.h>
#include <kenshi/CharacterHuman.h>
#include <kenshi/CharacterAnimal.h>
#include <kenshi/CharBody.h>
#include <kenshi/CharStats.h>
#include <kenshi/FactionLeader.h>
#include <kenshi/FactionRelations.h>
#include <kenshi/FactionUniqueSquadManager.h>
#include <kenshi/util/UtilityT.h>
#include <kenshi/InputHandler.h>
#include <kenshi/Character.h>
#include <kenshi/Platoon.h>
#include <kenshi/Item.h>
#include <kenshi/PlayerInterface.h>
#include <kenshi/Faction.h>
#include <kenshi/Damages.h>
#include <kenshi/Gear.h>
#include <kenshi/Bounty.h>
#include <kenshi/gui/DialogueWindow.h>
#include <kenshi/Dialogue.h>
#include <kenshi/WorldEventStateQuery.h>
#include <kenshi/RootObjectFactory.h>
#include <kenshi/FactionWarMgr.h>
#include <kenshi/BountyManager.h>
#include <kenshi/ZoneManager.h>
#include <kenshi/MedicalSystem.h>
#include <kenshi/ShopTrader.h>
#include <kenshi/RootObjectBase.h>
#include <kenshi/gui/InventoryGUI.h>
#include <kenshi/util/lektor.h>
#include <mygui/common/baselayout/BaseLayout.h>

#include <lua.hpp>

// ---------------------------------------------------------------------------
// Generic Argument Pusher Templates & Overloads
// ---------------------------------------------------------------------------

namespace KenshiLua
{
    // Shorthand metatable helpers
    static inline const char* CharacterMetatable()              { return CharacterBinding::getMetatableName(); }
    static inline const char* CharStatsMetatable()              { return CharStatsBinding::getMetatableName(); }
    static inline const char* DamagesMetatable()                { return DamagesBinding::getMetatableName(); }
    static inline const char* PlatoonMetatable()                { return PlatoonBinding::getMetatableName(); }
    static inline const char* ItemMetatable()                   { return ItemBinding::getMetatableName(); }
    static inline const char* PlayerInterfaceMetatable()        { return PlayerInterfaceBinding::getMetatableName(); }
    static inline const char* BountyManagerMetatable()           { return BountyManagerBinding::getMetatableName(); }
    static inline const char* FactionMetatable()                { return FactionBinding::getMetatableName(); }
    static inline const char* DialogueWindowMetatable()         { return DialogueWindowBinding::getMetatableName(); }
    static inline const char* DialogueMetatable()               { return DialogueBinding::getMetatableName(); }
    static inline const char* DialogLineDataMetatable()         { return DialogLineDataBinding::getMetatableName(); }
    static inline const char* RootObjectMetatable()             { return RootObjectBinding::getMetatableName(); }
    static inline const char* RootObjectBaseMetatable()         { return RootObjectBaseBinding::getMetatableName(); }
    static inline const char* RootObjectFactoryMetatable()      { return RootObjectFactoryBinding::getMetatableName(); }
    static inline const char* InventoryMetatable()              { return InventoryBinding::getMetatableName(); }
    static inline const char* OwnershipsMetatable()             { return OwnershipsBinding::getMetatableName(); }
    static inline const char* InventoryItemBaseMetatable()      { return InventoryItemBaseBinding::getMetatableName(); }
    static inline const char* CombatTechniqueDataMetatable()    { return CombatTechniqueDataBinding::getMetatableName(); }
    static inline const char* TaskerMetatable()                 { return TaskerBinding::getMetatableName(); }
    static inline const char* BuildingMetatable()               { return BuildingBinding::getMetatableName(); }
    static inline const char* UseableStuffMetatable()           { return UseableStuffBinding::getMetatableName(); }
    static inline const char* HandMetatable()                   { return HandBinding::getMetatableName(); }
    static inline const char* GameDataMetatable()               { return GameDataBinding::getMetatableName(); }
    static inline const char* AppearanceManagerMetatable()      { return AppearanceManagerBinding::getMetatableName(); }
    static inline const char* CombatMovementControllerMetatable() { return CombatMovementControllerBinding::getMetatableName(); }
    static inline const char* RaceDataMetatable()               { return RaceDataBinding::getMetatableName(); }
    static inline const char* InventorySectionMetatable()       { return InventorySectionBinding::getMetatableName(); }
    static inline const char* MedicalSystemMetatable()          { return MedicalSystemBinding::getMetatableName(); }
    static inline const char* CharMovementMetatable()           { return CharMovementBinding::getMetatableName(); }
    static inline const char* CombatClassMetatable()            { return CombatClassBinding::getMetatableName(); }
    static inline const char* GameWorldMetatable()              { return GameWorldBinding::getMetatableName(); }
    static inline const char* FactionManagerMetatable()         { return FactionManagerBinding::getMetatableName(); }
    static inline const char* FactionWarMgrMetatable()          { return FactionWarMgrBinding::getMetatableName(); }
    static inline const char* InventoryGUIMetatable()           { return InventoryGUIBinding::getMetatableName(); }
    static inline const char* InventoryLayoutMetatable()        { return InventoryLayoutBinding::getMetatableName(); }
    static inline const char* GenericFixedInventoryLayoutMetatable() { return GenericFixedInventoryLayoutBinding::getMetatableName(); }
    static inline const char* BuildModeWindowMetatable()        { return BuildModeWindowBinding::getMetatableName(); }
    static inline const char* SquadManagementScreenMetatable()  { return SquadManagementScreenBinding::getMetatableName(); }
    static inline const char* ManagementScreenMetatable()       { return ManagementScreenBinding::getMetatableName(); }
    static inline const char* TitleScreenMetatable()            { return TitleScreenBinding::getMetatableName(); }
    static inline const char* MyGuiWidgetMetatable()            { return MyGUIBinding::getMetatableName(); }
    static inline const char* OrdersPanelMetatable()            { return OrdersPanelBinding::getMetatableName(); }
    static inline const char* DataPanelLineButtonMetatable()    { return DataPanelLine_ButtonBinding::getMetatableName(); }
    static inline const char* InputHandlerMetatable()           { return InputHandlerBinding::getMetatableName(); }
    static inline const char* AttachedArrowManagerMetatable()   { return AttachedArrowManagerBinding::getMetatableName(); }
    static inline const char* LimbsInventoryLayoutMetatable()   { return LimbsInventoryLayoutBinding::getMetatableName(); }
    static inline const char* RobotLimbsMetatable()             { return RobotLimbsBinding::getMetatableName(); }
    static inline const char* ShopTraderMetatable()             { return ShopTraderBinding::getMetatableName(); }
    static inline const char* BaseLayoutMetatable()             { return BaseLayoutBinding::getMetatableName(); }
    static inline const char* ActivePlatoonMetatable()          { return ActivePlatoonBinding::getMetatableName(); }
    static inline const char* ArmourMetatable()                 { return ArmourBinding::getMetatableName(); }
    static inline const char* BountyMetatable()                 { return BountyBinding::getMetatableName(); }
    static inline const char* CrossbowMetatable()               { return CrossbowBinding::getMetatableName(); }
    static inline const char* GearMetatable()                   { return GearBinding::getMetatableName(); }
    static inline const char* LockedArmourMetatable()           { return LockedArmourBinding::getMetatableName(); }
    static inline const char* SwordMetatable()                  { return SwordBinding::getMetatableName(); }
    static inline const char* WeaponMetatable()                 { return WeaponBinding::getMetatableName(); }
    static inline const char* DataObjectContainerMetatable()    { return DataObjectContainerBinding::getMetatableName(); }
    static inline const char* DoorStuffMetatable()              { return DoorStuffBinding::getMetatableName(); }
    static inline const char* ProductionBuildingMetatable()      { return ProductionBuildingBinding::getMetatableName(); }
    static inline const char* CraftingBuildingMetatable()        { return CraftingBuildingBinding::getMetatableName(); }
    static inline const char* FarmBuildingMetatable()            { return FarmBuildingBinding::getMetatableName(); }
    static inline const char* TurretBuildingMetatable()          { return TurretBuildingBinding::getMetatableName(); }
    static inline const char* FurnaceBuildingMetatable()         { return FurnaceBuildingBinding::getMetatableName(); }
    static inline const char* ResearchBuildingMetatable()        { return ResearchBuildingBinding::getMetatableName(); }
    static inline const char* PreviewBuildingMetatable()         { return PreviewBuildingBinding::getMetatableName(); }
    static inline const char* WallBuildingMetatable()            { return WallBuildingBinding::getMetatableName(); }
    static inline const char* DataPanelLineMetatable()           { return DataPanelLineBinding::getMetatableName(); }
    static inline const char* RendHitMetatable()                 { return rendHitBinding::getMetatableName(); }
    static inline const char* TownMetatable()                   { return TownBinding::getMetatableName(); }
    static inline const char* TownBaseMetatable()               { return TownBaseBinding::getMetatableName(); }
    static inline const char* StorageBuildingMetatable()        { return StorageBuildingBinding::getMetatableName(); }
    static inline const char* LightBuildingMetatable()          { return LightBuildingBinding::getMetatableName(); }
    static inline const char* GeneratorBuildingMetatable()      { return GeneratorBuildingBinding::getMetatableName(); }
    static inline const char* WindGeneratorBuildingMetatable()  { return WindGeneratorBuildingBinding::getMetatableName(); }
    static inline const char* GatewayBuildingMetatable()        { return GatewayBuildingBinding::getMetatableName(); }
    static inline const char* TortureBuildingMetatable()        { return TortureBuildingBinding::getMetatableName(); }
    static inline const char* RainCollectorBuildingMetatable()  { return RainCollectorBuildingBinding::getMetatableName(); }
    static inline const char* CharacterHumanMetatable()         { return CharacterHumanBinding::getMetatableName(); }
    static inline const char* CharacterAnimalMetatable()        { return CharacterAnimalBinding::getMetatableName(); }
    static inline const char* CharBodyMetatable()               { return CharBodyBinding::getMetatableName(); }
    static inline const char* FactionLeaderMetatable()          { return FactionLeaderBinding::getMetatableName(); }
    static inline const char* FactionRelationsMetatable()       { return FactionRelationsBinding::getMetatableName(); }
    static inline const char* FactionUniqueSquadManagerMetatable() { return FactionUniqueSquadManagerBinding::getMetatableName(); }
    static inline const char* ProsperityManagerMetatable()      { return ProsperityManagerBinding::getMetatableName(); }
    static inline const char* WorldEventStateQueryMetatable()   { return WorldEventStateQueryBinding::getMetatableName(); }
    static inline const char* ZoneManagerMetatable()            { return ZoneManagerBinding::getMetatableName(); }
    static inline const char* ZoneMapMetatable()                { return ZoneMapBinding::getMetatableName(); }

    // pushArg overloads for primitive types
    static inline void pushArg(lua_State* L, int val)                       { lua_pushinteger(L, val); }
    static inline void pushArg(lua_State* L, float val)                     { lua_pushnumber(L, val); }
    static inline void pushArg(lua_State* L, bool val)                      { lua_pushboolean(L, val ? 1 : 0); }
    static inline void pushArg(lua_State* L, const std::string& val)        { lua_pushstring(L, val.c_str()); }

    // pushArg overloads for bound classes      
    static inline void pushArg(lua_State* L, Character* val)                { pushObject<Character>(L, val, CharacterMetatable()); }
    static inline void pushArg(lua_State* L, CharStats* val)                { pushObject<CharStats>(L, val, CharStatsMetatable()); }
    static inline void pushArg(lua_State* L, Damages* val)                  { pushObject<Damages>(L, val, DamagesMetatable()); }
    static inline void pushArg(lua_State* L, Platoon* val)                  { pushObject<Platoon>(L, val, PlatoonMetatable()); }
    static inline void pushArg(lua_State* L, ActivePlatoon* val)            { pushObject<ActivePlatoon>(L, val, ActivePlatoonMetatable()); }
    static inline void pushArg(lua_State* L, Item* val)                     { pushObject<Item>(L, val, ItemMetatable()); }
    static inline void pushArg(lua_State* L, Faction* val)                  { pushObject<Faction>(L, val, FactionMetatable()); }
    static inline void pushArg(lua_State* L, PlayerInterface* val)          { pushObject<PlayerInterface>(L, val, PlayerInterfaceMetatable()); }
    static inline void pushArg(lua_State* L, BountyManager* val)             { pushObject<BountyManager>(L, val, BountyManagerMetatable()); }
    static inline void pushArg(lua_State* L, DialogueWindow* val)           { pushObject<DialogueWindow>(L, val, DialogueWindowMetatable()); }
    static inline void pushArg(lua_State* L, Dialogue* val)                 { pushObject<Dialogue>(L, val, DialogueMetatable()); }
    static inline void pushArg(lua_State* L, DialogLineData* val)           { pushObject<DialogLineData>(L, val, DialogLineDataMetatable()); }
    static inline void pushArg(lua_State* L, RootObject* val)               { pushObject<RootObject>(L, val, RootObjectMetatable()); }
    static inline void pushArg(lua_State* L, RootObjectBase* val)           { pushObject<RootObjectBase>(L, val, RootObjectBaseMetatable()); }
    static inline void pushArg(lua_State* L, RootObjectFactory* val)        { pushObject<RootObjectFactory>(L, val, RootObjectFactoryMetatable()); }
    static inline void pushArg(lua_State* L, Inventory* val)                { pushObject<Inventory>(L, val, InventoryMetatable()); }
    static inline void pushArg(lua_State* L, CombatTechniqueData* val)      { pushObject<CombatTechniqueData>(L, val, CombatTechniqueDataMetatable()); }
    static inline void pushArg(lua_State* L, Tasker* val)                   { pushObject<Tasker>(L, val, TaskerMetatable()); }
    static inline void pushArg(lua_State* L, CombatClass* val)              { pushObject<CombatClass>(L, val, CombatClassMetatable()); }
    static inline void pushArg(lua_State* L, GameWorld* val)                { pushObject<GameWorld>(L, val, GameWorldMetatable()); }
    static inline void pushArg(lua_State* L, FactionManager* val)           { pushObject<FactionManager>(L, val, FactionManagerMetatable()); }
    static inline void pushArg(lua_State* L, FactionWarMgr* val)            { pushObject<FactionWarMgr>(L, val, FactionWarMgrMetatable()); }
    static inline void pushArg(lua_State* L, Building* val)                 { pushObject<Building>(L, val, BuildingMetatable()); }
    static inline void pushArg(lua_State* L, const Building* val)           { pushObject<Building>(L, const_cast<Building*>(val), BuildingMetatable()); }
    static inline void pushArg(lua_State* L, UseableStuff* val)             { pushObject<UseableStuff>(L, val, UseableStuffMetatable()); }
    static inline void pushArg(lua_State* L, const UseableStuff* val)       { pushObject<UseableStuff>(L, const_cast<UseableStuff*>(val), UseableStuffMetatable()); }
    static inline void pushArg(lua_State* L, const CharStats* val)          { pushObject<CharStats>(L, const_cast<CharStats*>(val), CharStatsMetatable()); }
    static inline void pushArg(lua_State* L, Ownerships* val)               { pushObject<Ownerships>(L, val, OwnershipsMetatable()); }
    static inline void pushArg(lua_State* L, const InventoryItemBase* val)  { pushObject<InventoryItemBase>(L, const_cast<InventoryItemBase*>(val), InventoryItemBaseMetatable()); }
    static inline void pushArg(lua_State* L, const hand& val)               { HandBinding::push(L, val); }
    static inline void pushArg(lua_State* L, const Ogre::Vector3& val)      { pushVector3(L, val); }
    static inline void pushArg(lua_State* L, const Ogre::Quaternion& val)   { pushQuaternion(L, val); }
    static inline void pushArg(lua_State* L, YesNoMaybe val)                { lua_pushinteger(L, static_cast<int>(val.key)); }
    static inline void pushArg(lua_State* L, GameData* val)                 { pushObject<GameData>(L, val, GameDataMetatable()); }
    static inline void pushArg(lua_State* L, AppearanceManager* val)        { pushObject<AppearanceManager>(L, val, AppearanceManagerMetatable()); }
    static inline void pushArg(lua_State* L, CombatMovementController* val) { pushObject<CombatMovementController>(L, val, CombatMovementControllerMetatable()); }
    static inline void pushArg(lua_State* L, RaceData* val)                 { pushObject<RaceData>(L, val, RaceDataMetatable()); }
    static inline void pushArg(lua_State* L, MedicalSystem* val)            { pushObject<MedicalSystem>(L, val, MedicalSystemMetatable()); }
    static inline void pushArg(lua_State* L, InventoryGUI* val)             { pushObject<InventoryGUI>(L, val, InventoryGUIMetatable()); }
    static inline void pushArg(lua_State* L, InventoryLayout* val)          { pushObject<InventoryLayout>(L, val, InventoryLayoutMetatable()); }
    static inline void pushArg(lua_State* L, GenericFixedInventoryLayout* val) { pushObject<GenericFixedInventoryLayout>(L, val, GenericFixedInventoryLayoutMetatable()); }
    static inline void pushArg(lua_State* L, BuildModeWindow* val)          { pushObject<BuildModeWindow>(L, val, BuildModeWindowMetatable()); }
    static inline void pushArg(lua_State* L, SquadManagementScreen* val)    { pushObject<SquadManagementScreen>(L, val, SquadManagementScreenMetatable()); }
    static inline void pushArg(lua_State* L, ManagementScreen* val)         { pushObject<ManagementScreen>(L, val, ManagementScreenMetatable()); }
    static inline void pushArg(lua_State* L, TitleScreen* val)              { pushObject<TitleScreen>(L, val, TitleScreenMetatable()); }
    static inline void pushArg(lua_State* L, MyGUI::Widget* val)            { pushObject<MyGUI::Widget>(L, val, MyGuiWidgetMetatable()); }
    static inline void pushArg(lua_State* L, OrdersPanel* val)              { pushObject<OrdersPanel>(L, val, OrdersPanelMetatable()); }
    static inline void pushArg(lua_State* L, DataPanelLine_Button* val)     { pushObject<DataPanelLine_Button>(L, val, DataPanelLineButtonMetatable()); }
    static inline void pushArg(lua_State* L, InputHandler* val)             { pushObject<InputHandler>(L, val, InputHandlerMetatable()); }
    static inline void pushArg(lua_State* L, Character::AttachedArrowManager* val) { pushObject<Character::AttachedArrowManager>(L, val, AttachedArrowManagerMetatable()); }
    static inline void pushArg(lua_State* L, LimbsInventoryLayout* val)     { pushObject<LimbsInventoryLayout>(L, val, LimbsInventoryLayoutMetatable()); }
    static inline void pushArg(lua_State* L, RobotLimbs* val)                { pushObject<RobotLimbs>(L, val, RobotLimbsMetatable()); }
    static inline void pushArg(lua_State* L, ShopTrader* val)                { pushObject<ShopTrader>(L, val, ShopTraderMetatable()); }
    static inline void pushArg(lua_State* L, wraps::BaseLayout* val)        { pushObject<wraps::BaseLayout>(L, val, BaseLayoutMetatable()); }
    static inline void pushArg(lua_State* L, void* val)                     { lua_pushlightuserdata(L, val); }
    static inline void pushArg(lua_State* L, lektor<GameData*>& val)        { pushObject<lektor<GameData*>>(L, &val, LektorPtrBinding<GameData*>::metaName); }
    static inline void pushArg(lua_State* L, Armour* val)                   { pushObject<Armour>(L, val, ArmourMetatable()); }
    static inline void pushArg(lua_State* L, Bounty* val)                   { pushObject<Bounty>(L, val, BountyMetatable()); }
    static inline void pushArg(lua_State* L, Crossbow* val)                 { pushObject<Crossbow>(L, val, CrossbowMetatable()); }
    static inline void pushArg(lua_State* L, Gear* val)                     { pushObject<Gear>(L, val, GearMetatable()); }
    static inline void pushArg(lua_State* L, LockedArmour* val)             { pushObject<LockedArmour>(L, val, LockedArmourMetatable()); }
    static inline void pushArg(lua_State* L, Sword* val)                    { pushObject<Sword>(L, val, SwordMetatable()); }
    static inline void pushArg(lua_State* L, Weapon* val)                   { pushObject<Weapon>(L, val, WeaponMetatable()); }
    static inline void pushArg(lua_State* L, DataObjectContainer* val)      { pushObject<DataObjectContainer>(L, val, DataObjectContainerMetatable()); }
    static inline void pushArg(lua_State* L, Layout* val)                   { lua_pushlightuserdata(L, val); }
    static inline void pushArg(lua_State* L, DoorStuff* val)                { pushObject<DoorStuff>(L, val, DoorStuffMetatable()); }
    static inline void pushArg(lua_State* L, ProductionBuilding* val)        { pushObject<ProductionBuilding>(L, val, ProductionBuildingMetatable()); }
    static inline void pushArg(lua_State* L, CraftingBuilding* val)          { pushObject<CraftingBuilding>(L, val, CraftingBuildingMetatable()); }
    static inline void pushArg(lua_State* L, FarmBuilding* val)              { pushObject<FarmBuilding>(L, val, FarmBuildingMetatable()); }
    static inline void pushArg(lua_State* L, TurretBuilding* val)            { pushObject<TurretBuilding>(L, val, TurretBuildingMetatable()); }
    static inline void pushArg(lua_State* L, FurnaceBuilding* val)           { pushObject<FurnaceBuilding>(L, val, FurnaceBuildingMetatable()); }
    static inline void pushArg(lua_State* L, ResearchBuilding* val)          { pushObject<ResearchBuilding>(L, val, ResearchBuildingMetatable()); }
    static inline void pushArg(lua_State* L, PreviewBuilding* val)           { pushObject<PreviewBuilding>(L, val, PreviewBuildingMetatable()); }
    static inline void pushArg(lua_State* L, WallBuilding* val)              { pushObject<WallBuilding>(L, val, WallBuildingMetatable()); }
    static inline void pushArg(lua_State* L, DataPanelLine* val)             { pushObject<DataPanelLine>(L, val, DataPanelLineMetatable()); }
    static inline void pushArg(lua_State* L, rendHit* val)                  { pushObject<rendHit>(L, val, RendHitMetatable()); }
    static inline void pushArg(lua_State* L, const rendHit& val)            { pushObject<rendHit>(L, const_cast<rendHit*>(&val), RendHitMetatable()); }
    static inline void pushArg(lua_State* L, Town* val)                     { pushObject<Town>(L, val, TownMetatable()); }
    static inline void pushArg(lua_State* L, TownBase* val)                 { pushObject<TownBase>(L, val, TownBaseMetatable()); }
    static inline void pushArg(lua_State* L, StorageBuilding* val)          { pushObject<StorageBuilding>(L, val, StorageBuildingMetatable()); }
    static inline void pushArg(lua_State* L, LightBuilding* val)            { pushObject<LightBuilding>(L, val, LightBuildingMetatable()); }
    static inline void pushArg(lua_State* L, GeneratorBuilding* val)        { pushObject<GeneratorBuilding>(L, val, GeneratorBuildingMetatable()); }
    static inline void pushArg(lua_State* L, WindGeneratorBuilding* val)    { pushObject<WindGeneratorBuilding>(L, val, WindGeneratorBuildingMetatable()); }
    static inline void pushArg(lua_State* L, GatewayBuilding* val)          { pushObject<GatewayBuilding>(L, val, GatewayBuildingMetatable()); }
    static inline void pushArg(lua_State* L, TortureBuilding* val)          { pushObject<TortureBuilding>(L, val, TortureBuildingMetatable()); }
    static inline void pushArg(lua_State* L, RainCollectorBuilding* val)    { pushObject<RainCollectorBuilding>(L, val, RainCollectorBuildingMetatable()); }
    static inline void pushArg(lua_State* L, CharacterHuman* val)           { pushObject<CharacterHuman>(L, val, CharacterHumanMetatable()); }
    static inline void pushArg(lua_State* L, CharacterAnimal* val)          { pushObject<CharacterAnimal>(L, val, CharacterAnimalMetatable()); }
    static inline void pushArg(lua_State* L, CharBody* val)                 { pushObject<CharBody>(L, val, CharBodyMetatable()); }
    static inline void pushArg(lua_State* L, FactionLeader* val)            { pushObject<FactionLeader>(L, val, FactionLeaderMetatable()); }
    static inline void pushArg(lua_State* L, FactionRelations* val)         { pushObject<FactionRelations>(L, val, FactionRelationsMetatable()); }
    static inline void pushArg(lua_State* L, FactionUniqueSquadManager* val){ pushObject<FactionUniqueSquadManager>(L, val, FactionUniqueSquadManagerMetatable()); }
    static inline void pushArg(lua_State* L, ProsperityManager* val)        { pushObject<ProsperityManager>(L, val, ProsperityManagerMetatable()); }
    static inline void pushArg(lua_State* L, WorldEventStateQuery* val)     { pushObject<WorldEventStateQuery>(L, val, WorldEventStateQueryMetatable()); }
    static inline void pushArg(lua_State* L, ZoneManager* val)              { pushObject<ZoneManager>(L, val, ZoneManagerMetatable()); }
    static inline void pushArg(lua_State* L, ZoneMap* val)                  { pushObject<ZoneMap>(L, val, ZoneMapMetatable()); }

    // pullArg — reads a (possibly Lua-edited) value back off the stack.
    // No pointer/object overloads on purpose; see IParamsFilter comment.
    static inline void pullArg(lua_State* L, int idx, int& out)         { if (lua_isnumber(L, idx))  out = (int)lua_tointeger(L, idx); }
    static inline void pullArg(lua_State* L, int idx, float& out)       { if (lua_isnumber(L, idx))  out = (float)lua_tonumber(L, idx); }
    static inline void pullArg(lua_State* L, int idx, bool& out)        { if (lua_isboolean(L, idx)) out = lua_toboolean(L, idx) != 0; }
    static inline void pullArg(lua_State* L, int idx, std::string& out) { if (lua_isstring(L, idx))  out = lua_tostring(L, idx); }
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
    ArgPusher6<Dialogue*, DialogConditionEnum, ComparisonEnum, int, Character*, Character*> pusher(dialogue, conditionName, compareBy, val, target, actualConversationTarget);
    return KenshiLua::EventSystem::get().callHandlersBool("Dialogue::_checkCondition", &pusher, defaultVal);
}

bool CallDialogueStartConversationCallbacks(Dialogue* dialogue, Character* target, DialogLineData* talk, EventTriggerEnum ev, bool force, bool defaultVal)
{
    ArgPusher5<Dialogue*, Character*, DialogLineData*, EventTriggerEnum, bool> pusher(dialogue, target, talk, ev, force);
    return KenshiLua::EventSystem::get().callHandlersBool("Dialogue::startConversation", &pusher, defaultVal);
}

void CallDialogueEndPlayerConversationCallbacks(Dialogue* dialogue, bool finished)
{
    ArgPusher2<Dialogue*, bool> pusher(dialogue, finished);
    KenshiLua::EventSystem::get().callHandlers("Dialogue::_endPlayerConversation", &pusher);
}

bool CallDialogueStartPlayerConversationCallbacks(Dialogue* dialogue, Character* target, DialogLineData* talk, bool defaultVal)
{
    ArgPusher3<Dialogue*, Character*, DialogLineData*> pusher(dialogue, target, talk);
    return KenshiLua::EventSystem::get().callHandlersBool("Dialogue::startPlayerConversation", &pusher, defaultVal);
}

bool CallDialogueSendEventCallbacks(Dialogue* dialogue, Character* who, EventTriggerEnum what, bool defaultVal)
{
    ArgPusher3<Dialogue*, Character*, EventTriggerEnum> pusher(dialogue, who, what);
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

InventorySection* CallInventoryGetSectionOfTypeCallbacks(Inventory* inventory, int type)
{
    ArgPusher2<Inventory*, int> pusher(inventory, type);
    return static_cast<InventorySection*>(KenshiLua::EventSystem::get().callHandlersObject(
        "Inventory::getSectionOfType", "KenshiLua.InventorySection", &pusher));
}

Item* CallInventoryGetBestFoodItemCallbacks(Inventory* inventory, Character* race)
{
    ArgPusher2<Inventory*, Character*> pusher(inventory, race);
    return static_cast<Item*>(KenshiLua::EventSystem::get().callHandlersObject(
        "Inventory::getBestFoodItem", "KenshiLua.Item", &pusher));
}

bool CallCharacterIsItOkForMeToLootCallbacks(Character* me, RootObject* victim, Item* item, bool defaultVal)
{
    ArgPusher3<Character*, RootObject*, Item*> pusher(me, victim, item);
    return KenshiLua::EventSystem::get().callHandlersBool("Character::isItOkForMeToLoot", &pusher, defaultVal);
}

float CallCharacterGetFencingSuccessChanceCallbacks(Character* merchant, Item* item, RootObject* thief, float defaultVal)
{
    ArgPusher3<Character*, Item*, RootObject*> pusher(merchant, item, thief);
    return (float)KenshiLua::EventSystem::get().callHandlersNumber("Character::getFencingSuccessChance", &pusher, defaultVal);
}

float CallCharStatsGetStatCallbacks(const CharStats* stats, int what, bool unmodified, float defaultVal)
{
    ArgPusher3<const CharStats*, int, bool> pusher(stats, what, unmodified);
    return (float)KenshiLua::EventSystem::get().callHandlersNumber("CharStats::getStat", &pusher, defaultVal);
}

GameData* CallFactionChooseARaceCallbacks(Faction* faction, GameData* character, GameData* squadTemplate, GameData* defaultVal)
{
    ArgPusher3<Faction*, GameData*, GameData*> pusher(faction, character, squadTemplate);
    GameData* overrideVal = static_cast<GameData*>(KenshiLua::EventSystem::get().callHandlersObject(
        "Faction::chooseARace", "KenshiLua.GameData", &pusher));
    return overrideVal ? overrideVal : defaultVal;
}

GameData* CallFactionGetBuildingReplacementCallbacks(Faction* faction, GameData* building, GameData* defaultVal)
{
    ArgPusher2<Faction*, GameData*> pusher(faction, building);
    GameData* overrideVal = static_cast<GameData*>(KenshiLua::EventSystem::get().callHandlersObject(
        "Faction::getBuildingReplacement", "KenshiLua.GameData", &pusher));
    return overrideVal ? overrideVal : defaultVal;
}

bool CallOwnershipsCanIUseThisBuildingCallbacks(Ownerships* ownerships, Building* b, Character* me, bool defaultVal)
{
    ArgPusher3<Ownerships*, Building*, Character*> pusher(ownerships, b, me);
    return KenshiLua::EventSystem::get().callHandlersBool("Ownerships::canIUseThisBuilding", &pusher, defaultVal);
}

bool CallPlatoonIBuyStolenGoodsCallbacks(Platoon* platoon, Item* what, bool defaultVal)
{
    ArgPusher2<Platoon*, Item*> pusher(platoon, what);
    return KenshiLua::EventSystem::get().callHandlersBool("Platoon::iBuyStolenGoods", &pusher, defaultVal);
}

bool CallPlatoonIBuyIllegalGoodsCallbacks(Platoon* platoon, bool defaultVal)
{
    ArgPusher1<Platoon*> pusher(platoon);
    return KenshiLua::EventSystem::get().callHandlersBool("Platoon::iBuyIllegalGoods", &pusher, defaultVal);
}

bool CallBuildingIsPublicCallbacks(const Building* b, bool defaultVal)
{
    ArgPusher1<const Building*> pusher(b);
    return KenshiLua::EventSystem::get().callHandlersBool("Building::isPublic", &pusher, defaultVal);
}

bool CallBuildingIsForSaleCallbacks(Building* b, bool defaultVal)
{
    ArgPusher1<Building*> pusher(b);
    return KenshiLua::EventSystem::get().callHandlersBool("Building::isForSale", &pusher, defaultVal);
}

int CallBuildingCalculateSaleValueCallbacks(Building* b, int defaultVal)
{
    ArgPusher1<Building*> pusher(b);
    return (int)KenshiLua::EventSystem::get().callHandlersNumber("Building::calculateSaleValue", &pusher, defaultVal);
}

int CallInventoryItemBaseGetValueSingleCallbacks(const InventoryItemBase* item, bool isPlayer, int defaultVal)
{
    ArgPusher2<const InventoryItemBase*, bool> pusher(item, isPlayer);
    return (int)KenshiLua::EventSystem::get().callHandlersNumber("InventoryItemBase::getValueSingle", &pusher, defaultVal);
}

bool CallCharMovementIsRunningCallbacks(CharMovement* thisptr, bool defaultVal)
{
    ArgPusher1<CharMovement*> pusher(thisptr);
    return KenshiLua::EventSystem::get().callHandlersBool("CharMovement::isRunning", &pusher, defaultVal);
}
bool CallCharMovementIsRunningAwayCallbacks(CharMovement* thisptr, const Ogre::Vector3& from, bool defaultVal)
{
    ArgPusher2<CharMovement*, const Ogre::Vector3&> pusher(thisptr, from);
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

void CallManagementScreenAddMessageCallbacks(ManagementScreen* screen, const std::string& owner, const std::string& message, int logColor)
{
    ArgPusher4<ManagementScreen*, const std::string&, const std::string&, int> pusher(screen, owner, message, logColor);
    KenshiLua::EventSystem::get().callHandlers("ManagementScreen::addMessage", &pusher);
}

void CallTitleScreenLoadGameCallbacks(TitleScreen* titleScreen, MyGUI::Widget* sender)
{
    ArgPusher2<TitleScreen*, MyGUI::Widget*> pusher(titleScreen, sender);
    KenshiLua::EventSystem::get().callHandlers("TitleScreen::loadGame", &pusher);
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
    ArgPusher1<MedicalSystem*> pusher(med);
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
    return static_cast<Item*>(KenshiLua::EventSystem::get().callHandlersObject(
        "Inventory::_NV_removeItemDontDestroy_returnsItem", KenshiLua::ItemMetatable(), &pusher));
}

Item* CallInventoryBuyItemCallbacks(Inventory* inv, Item* item, RootObject* sender)
{
    ArgPusher3<Inventory*, Item*, RootObject*> pusher(inv, item, sender);
    return static_cast<Item*>(KenshiLua::EventSystem::get().callHandlersObject(
        "Inventory::buyItem", KenshiLua::ItemMetatable(), &pusher));
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

void CallOrdersPanelBlockModeButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, MyGUI::Widget*> pusher(panel, sender);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::blockmodeButton", &pusher);
}

void CallOrdersPanelHoldButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, MyGUI::Widget*> pusher(panel, sender);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::holdButtonCallback", &pusher);
}

void CallOrdersPanelPassiveButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, MyGUI::Widget*> pusher(panel, sender);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::passiveButtonCallback", &pusher);
}

void CallOrdersPanelChaseButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, MyGUI::Widget*> pusher(panel, sender);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::chaseButtonCallback", &pusher);
}

void CallOrdersPanelTauntButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, MyGUI::Widget*> pusher(panel, sender);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::tauntButtonCallback", &pusher);
}

void CallOrdersPanelMedicButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, MyGUI::Widget*> pusher(panel, sender);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::medicButton", &pusher);
}

void CallOrdersPanelLiftButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, MyGUI::Widget*> pusher(panel, sender);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::liftButton", &pusher);
}

void CallOrdersPanelProspectingButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, MyGUI::Widget*> pusher(panel, sender);
    KenshiLua::EventSystem::get().callHandlers("OrdersPanel::prospectingButton", &pusher);
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
    Character* overrideObj = static_cast<Character*>(KenshiLua::EventSystem::get().callHandlersObject(
        "Character::_CONSTRUCTOR", KenshiLua::CharacterMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Item* CallItemConstructedCallbacks(Item* thisptr, GameData* baseData, GameData* companyData, GameData* _materialData, hand _handle, Item* defaultVal)
{
    ArgPusher6<Item*, GameData*, GameData*, GameData*, const hand&, Item*> pusher(thisptr, baseData, companyData, _materialData, _handle, defaultVal);
    Item* overrideObj = static_cast<Item*>(KenshiLua::EventSystem::get().callHandlersObject(
        "Item::_CONSTRUCTOR", KenshiLua::ItemMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Gear* CallGearConstructedCallbacks(Gear* thisptr, GameData* baseData, GameData* companyData, GameData* materialData, hand _handle, int _level, Faction* uniform, Gear* defaultVal)
{
    ArgPusher8<Gear*, GameData*, GameData*, GameData*, const hand&, int, Faction*, Gear*> pusher(thisptr, baseData, companyData, materialData, _handle, _level, uniform, defaultVal);
    Gear* overrideObj = static_cast<Gear*>(KenshiLua::EventSystem::get().callHandlersObject(
        "Gear::_CONSTRUCTOR", KenshiLua::GearMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Sword* CallSwordConstructedCallbacks(Sword* thisptr, GameData* baseData, GameData* companyData, GameData* materialData, hand _handle, int _level, Sword* defaultVal)
{
    ArgPusher7<Sword*, GameData*, GameData*, GameData*, const hand&, int, Sword*> pusher(thisptr, baseData, companyData, materialData, _handle, _level, defaultVal);
    Sword* overrideObj = static_cast<Sword*>(KenshiLua::EventSystem::get().callHandlersObject(
        "Sword::_CONSTRUCTOR", KenshiLua::SwordMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Crossbow* CallCrossbowConstructedCallbacks(Crossbow* thisptr, GameData* baseData, hand _handle, int _overalllevel, Crossbow* defaultVal)
{
    ArgPusher5<Crossbow*, GameData*, const hand&, int, Crossbow*> pusher(thisptr, baseData, _handle, _overalllevel, defaultVal);
    Crossbow* overrideObj = static_cast<Crossbow*>(KenshiLua::EventSystem::get().callHandlersObject(
        "Crossbow::_CONSTRUCTOR", KenshiLua::CrossbowMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Armour* CallArmourConstructedCallbacks(Armour* thisptr, GameData* baseData, GameData* _materialData, hand _handle, Faction* _uniformFlag, int _level, Armour* defaultVal)
{
    ArgPusher7<Armour*, GameData*, GameData*, const hand&, Faction*, int, Armour*> pusher(thisptr, baseData, _materialData, _handle, _uniformFlag, _level, defaultVal);
    Armour* overrideObj = static_cast<Armour*>(KenshiLua::EventSystem::get().callHandlersObject(
        "Armour::_CONSTRUCTOR", KenshiLua::ArmourMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

LockedArmour* CallLockedArmourConstructedCallbacks(LockedArmour* thisptr, GameData* baseData, GameData* _materialData, hand _handle, Faction* _uniformFlag, int _level, LockedArmour* defaultVal)
{
    ArgPusher7<LockedArmour*, GameData*, GameData*, const hand&, Faction*, int, LockedArmour*> pusher(thisptr, baseData, _materialData, _handle, _uniformFlag, _level, defaultVal);
    LockedArmour* overrideObj = static_cast<LockedArmour*>(KenshiLua::EventSystem::get().callHandlersObject(
        "LockedArmour::_CONSTRUCTOR", KenshiLua::LockedArmourMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Weapon* CallWeaponConstructedCallbacks(Weapon* thisptr, GameData* baseData, GameData* companyData, GameData* materialData, hand _handle, int _level, Weapon* defaultVal)
{
    ArgPusher7<Weapon*, GameData*, GameData*, GameData*, const hand&, int, Weapon*> pusher(thisptr, baseData, companyData, materialData, _handle, _level, defaultVal);
    Weapon* overrideObj = static_cast<Weapon*>(KenshiLua::EventSystem::get().callHandlersObject(
        "Weapon::_CONSTRUCTOR", KenshiLua::WeaponMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Building* CallBuildingConstructedCallbacks(Building* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, Building* defaultVal)
{
    ArgPusher10<Building*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, Building*> pusher(thisptr, data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, defaultVal);
    Building* overrideObj = static_cast<Building*>(KenshiLua::EventSystem::get().callHandlersObject(
        "Building::_CONSTRUCTOR", KenshiLua::BuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Platoon* CallPlatoonConstructedCallbacks(Platoon* thisptr, Faction* f, GameData* _squadTemplate, GameData* platoonState, const Ogre::Vector3& p, bool _persistent, Platoon* defaultVal)
{
    ArgPusher7<Platoon*, Faction*, GameData*, GameData*, const Ogre::Vector3&, bool, Platoon*> pusher(thisptr, f, _squadTemplate, platoonState, p, _persistent, defaultVal);
    Platoon* overrideObj = static_cast<Platoon*>(KenshiLua::EventSystem::get().callHandlersObject(
        "Platoon::_CONSTRUCTOR", KenshiLua::PlatoonMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

ActivePlatoon* CallActivePlatoonConstructedCallbacks(ActivePlatoon* thisptr, Platoon* my, DataObjectContainer* doc, Faction* f, GameData* d, Tasker* _currentGoal, const Ogre::Vector3& _posOffset, ActivePlatoon* defaultVal)
{
    ArgPusher8<ActivePlatoon*, Platoon*, DataObjectContainer*, Faction*, GameData*, Tasker*, const Ogre::Vector3&, ActivePlatoon*> pusher(thisptr, my, doc, f, d, _currentGoal, _posOffset, defaultVal);
    ActivePlatoon* overrideObj = static_cast<ActivePlatoon*>(KenshiLua::EventSystem::get().callHandlersObject(
        "ActivePlatoon::_CONSTRUCTOR", KenshiLua::ActivePlatoonMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Faction* CallFactionConstructedCallbacks(Faction* thisptr, const std::string& _name, Faction* defaultVal)
{
    ArgPusher3<Faction*, const std::string&, Faction*> pusher(thisptr, _name, defaultVal);
    Faction* overrideObj = static_cast<Faction*>(KenshiLua::EventSystem::get().callHandlersObject(
        "Faction::_CONSTRUCTOR", KenshiLua::FactionMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Bounty* CallBountyConstructedCallbacks(Bounty* thisptr, Bounty* defaultVal)
{
    ArgPusher2<Bounty*, Bounty*> pusher(thisptr, defaultVal);
    Bounty* overrideObj = static_cast<Bounty*>(KenshiLua::EventSystem::get().callHandlersObject(
        "Bounty::_CONSTRUCTOR", KenshiLua::BountyMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Damages* CallDamagesConstructedCallbacks(Damages* thisptr, float _cut, float _blunt, float _pierce, float bleed, float armour, Damages* defaultVal)
{
    ArgPusher7<Damages*, float, float, float, float, float, Damages*> pusher(thisptr, _cut, _blunt, _pierce, bleed, armour, defaultVal);
    Damages* overrideObj = static_cast<Damages*>(KenshiLua::EventSystem::get().callHandlersObject(
        "Damages::_CONSTRUCTOR", KenshiLua::DamagesMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Inventory* CallInventoryConstructedCallbacks(Inventory* thisptr, RootObject* _owner, Inventory* defaultVal)
{
    ArgPusher3<Inventory*, RootObject*, Inventory*> pusher(thisptr, _owner, defaultVal);
    Inventory* overrideObj = static_cast<Inventory*>(KenshiLua::EventSystem::get().callHandlersObject(
        "Inventory::_CONSTRUCTOR", KenshiLua::InventoryMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

DoorStuff* CallDoorStuffConstructedCallbacks(DoorStuff* thisptr, GameData* dat, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, Building* par, DoorStuff* defaultVal)
{
    ArgPusher11<DoorStuff*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, Building*, DoorStuff*> pusher(thisptr, dat, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, par, defaultVal);
    DoorStuff* overrideObj = static_cast<DoorStuff*>(KenshiLua::EventSystem::get().callHandlersObject(
        "DoorStuff::_CONSTRUCTOR", KenshiLua::DoorStuffMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

ProductionBuilding* CallProductionBuildingConstructedCallbacks(ProductionBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, ProductionBuilding* defaultVal)
{
    ArgPusher10<ProductionBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, ProductionBuilding*> pusher(thisptr, _data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, defaultVal);
    ProductionBuilding* overrideObj = static_cast<ProductionBuilding*>(KenshiLua::EventSystem::get().callHandlersObject(
        "ProductionBuilding::_CONSTRUCTOR", KenshiLua::ProductionBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

CraftingBuilding* CallCraftingBuildingConstructedCallbacks(CraftingBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, CraftingBuilding* defaultVal)
{
    ArgPusher10<CraftingBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, CraftingBuilding*> pusher(thisptr, _data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, defaultVal);
    CraftingBuilding* overrideObj = static_cast<CraftingBuilding*>(KenshiLua::EventSystem::get().callHandlersObject(
        "CraftingBuilding::_CONSTRUCTOR", KenshiLua::CraftingBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

FarmBuilding* CallFarmBuildingConstructedCallbacks(FarmBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, FarmBuilding* defaultVal)
{
    ArgPusher10<FarmBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, FarmBuilding*> pusher(thisptr, data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, defaultVal);
    FarmBuilding* overrideObj = static_cast<FarmBuilding*>(KenshiLua::EventSystem::get().callHandlersObject(
        "FarmBuilding::_CONSTRUCTOR", KenshiLua::FarmBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

TurretBuilding* CallTurretBuildingConstructedCallbacks(TurretBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, TurretBuilding* defaultVal)
{
    ArgPusher10<TurretBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, TurretBuilding*> pusher(thisptr, _data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, defaultVal);
    TurretBuilding* overrideObj = static_cast<TurretBuilding*>(KenshiLua::EventSystem::get().callHandlersObject(
        "TurretBuilding::_CONSTRUCTOR", KenshiLua::TurretBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

FurnaceBuilding* CallFurnaceBuildingConstructedCallbacks(FurnaceBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, FurnaceBuilding* defaultVal)
{
    ArgPusher10<FurnaceBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, FurnaceBuilding*> pusher(thisptr, data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, defaultVal);
    FurnaceBuilding* overrideObj = static_cast<FurnaceBuilding*>(KenshiLua::EventSystem::get().callHandlersObject(
        "FurnaceBuilding::_CONSTRUCTOR", KenshiLua::FurnaceBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

ResearchBuilding* CallResearchBuildingConstructedCallbacks(ResearchBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, ResearchBuilding* defaultVal)
{
    ArgPusher10<ResearchBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, ResearchBuilding*> pusher(thisptr, _data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, defaultVal);
    ResearchBuilding* overrideObj = static_cast<ResearchBuilding*>(KenshiLua::EventSystem::get().callHandlersObject(
        "ResearchBuilding::_CONSTRUCTOR", KenshiLua::ResearchBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

WallBuilding* CallWallBuildingConstructedCallbacks(WallBuilding* thisptr, GameData* dat, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, Layout* furnitureOf, const hand& town, const hand& _handle, WallBuilding* defaultVal)
{
    ArgPusher9<WallBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, Layout*, const hand&, const hand&, WallBuilding*> pusher(thisptr, dat, position, orientation, _participant, furnitureOf, town, _handle, defaultVal);
    WallBuilding* overrideObj = static_cast<WallBuilding*>(KenshiLua::EventSystem::get().callHandlersObject(
        "WallBuilding::_CONSTRUCTOR", KenshiLua::WallBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

PreviewBuilding* CallPreviewBuildingConstructedCallbacks(PreviewBuilding* thisptr, GameData* data, Building* _furnitureParent, PreviewBuilding* defaultVal)
{
    ArgPusher4<PreviewBuilding*, GameData*, Building*, PreviewBuilding*> pusher(thisptr, data, _furnitureParent, defaultVal);
    PreviewBuilding* overrideObj = static_cast<PreviewBuilding*>(KenshiLua::EventSystem::get().callHandlersObject(
        "PreviewBuilding::_CONSTRUCTOR", KenshiLua::PreviewBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

UseableStuff* CallUseableStuffConstructedCallbacks(UseableStuff* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, UseableStuff* defaultVal)
{
    ArgPusher10<UseableStuff*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, UseableStuff*> pusher(thisptr, _data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, defaultVal);
    UseableStuff* overrideObj = static_cast<UseableStuff*>(KenshiLua::EventSystem::get().callHandlersObject(
        "UseableStuff::_CONSTRUCTOR", KenshiLua::UseableStuffMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

StorageBuilding* CallStorageBuildingConstructedCallbacks(StorageBuilding* thisptr, GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, StorageBuilding* defaultVal)
{
    ArgPusher10<StorageBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, StorageBuilding*> pusher(thisptr, _data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, defaultVal);
    StorageBuilding* overrideObj = static_cast<StorageBuilding*>(KenshiLua::EventSystem::get().callHandlersObject(
        "StorageBuilding::_CONSTRUCTOR", KenshiLua::StorageBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

LightBuilding* CallLightBuildingConstructedCallbacks(LightBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, LightBuilding* defaultVal)
{
    ArgPusher10<LightBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, LightBuilding*> pusher(thisptr, data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, defaultVal);
    LightBuilding* overrideObj = static_cast<LightBuilding*>(KenshiLua::EventSystem::get().callHandlersObject(
        "LightBuilding::_CONSTRUCTOR", KenshiLua::LightBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

GeneratorBuilding* CallGeneratorBuildingConstructedCallbacks(GeneratorBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, GeneratorBuilding* defaultVal)
{
    ArgPusher10<GeneratorBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, GeneratorBuilding*> pusher(thisptr, data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, defaultVal);
    GeneratorBuilding* overrideObj = static_cast<GeneratorBuilding*>(KenshiLua::EventSystem::get().callHandlersObject(
        "GeneratorBuilding::_CONSTRUCTOR", KenshiLua::GeneratorBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

WindGeneratorBuilding* CallWindGeneratorBuildingConstructedCallbacks(WindGeneratorBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors, WindGeneratorBuilding* defaultVal)
{
    ArgPusher10<WindGeneratorBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, WindGeneratorBuilding*> pusher(thisptr, data, position, orientation, _participant, town, _handle, __isfurnitureOf, _indoors, defaultVal);
    WindGeneratorBuilding* overrideObj = static_cast<WindGeneratorBuilding*>(KenshiLua::EventSystem::get().callHandlersObject(
        "WindGeneratorBuilding::_CONSTRUCTOR", KenshiLua::WindGeneratorBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

GatewayBuilding* CallGatewayBuildingConstructedCallbacks(GatewayBuilding* thisptr, GameData* dat, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, GatewayBuilding* defaultVal)
{
    ArgPusher8<GatewayBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, GatewayBuilding*> pusher(thisptr, dat, position, orientation, _participant, town, _handle, defaultVal);
    GatewayBuilding* overrideObj = static_cast<GatewayBuilding*>(KenshiLua::EventSystem::get().callHandlersObject(
        "GatewayBuilding::_CONSTRUCTOR", KenshiLua::GatewayBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

TortureBuilding* CallTortureBuildingConstructedCallbacks(TortureBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* participant, const hand& town, const hand& handle, Layout* isfurnitureOf, Building* indoors, TortureBuilding* defaultVal)
{
    ArgPusher10<TortureBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, TortureBuilding*> pusher(thisptr, data, position, orientation, participant, town, handle, isfurnitureOf, indoors, defaultVal);
    TortureBuilding* overrideObj = static_cast<TortureBuilding*>(KenshiLua::EventSystem::get().callHandlersObject(
        "TortureBuilding::_CONSTRUCTOR", KenshiLua::TortureBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

RainCollectorBuilding* CallRainCollectorBuildingConstructedCallbacks(RainCollectorBuilding* thisptr, GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* participant, const hand& town, const hand& handle, Layout* isfurnitureOf, Building* indoors, RainCollectorBuilding* defaultVal)
{
    ArgPusher10<RainCollectorBuilding*, GameData*, const Ogre::Vector3&, const Ogre::Quaternion&, Faction*, const hand&, const hand&, Layout*, Building*, RainCollectorBuilding*> pusher(thisptr, data, position, orientation, participant, town, handle, isfurnitureOf, indoors, defaultVal);
    RainCollectorBuilding* overrideObj = static_cast<RainCollectorBuilding*>(KenshiLua::EventSystem::get().callHandlersObject(
        "RainCollectorBuilding::_CONSTRUCTOR", KenshiLua::RainCollectorBuildingMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

CharacterHuman* CallCharacterHumanConstructedCallbacks(CharacterHuman* thisptr, GameData* d, Faction* f, const hand& _handle, CharacterHuman* defaultVal)
{
    ArgPusher5<CharacterHuman*, GameData*, Faction*, const hand&, CharacterHuman*> pusher(thisptr, d, f, _handle, defaultVal);
    CharacterHuman* overrideObj = static_cast<CharacterHuman*>(KenshiLua::EventSystem::get().callHandlersObject(
        "CharacterHuman::_CONSTRUCTOR", KenshiLua::CharacterHumanMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

CharacterAnimal* CallCharacterAnimalConstructedCallbacks(CharacterAnimal* thisptr, GameData* d, Faction* f, const hand& _handle, float _age, CharacterAnimal* defaultVal)
{
    ArgPusher6<CharacterAnimal*, GameData*, Faction*, const hand&, float, CharacterAnimal*> pusher(thisptr, d, f, _handle, _age, defaultVal);
    CharacterAnimal* overrideObj = static_cast<CharacterAnimal*>(KenshiLua::EventSystem::get().callHandlersObject(
        "CharacterAnimal::_CONSTRUCTOR", KenshiLua::CharacterAnimalMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

CharStats* CallCharStatsConstructedCallbacks(CharStats* thisptr, CharStats* defaultVal)
{
    ArgPusher2<CharStats*, CharStats*> pusher(thisptr, defaultVal);
    CharStats* overrideObj = static_cast<CharStats*>(KenshiLua::EventSystem::get().callHandlersObject(
        "CharStats::_CONSTRUCTOR", KenshiLua::CharStatsMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

CharBody* CallCharBodyConstructedCallbacks(CharBody* thisptr, CharBody* defaultVal)
{
    ArgPusher2<CharBody*, CharBody*> pusher(thisptr, defaultVal);
    CharBody* overrideObj = static_cast<CharBody*>(KenshiLua::EventSystem::get().callHandlersObject(
        "CharBody::_CONSTRUCTOR", KenshiLua::CharBodyMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

CharMovement* CallCharMovementConstructedCallbacks(CharMovement* thisptr, CharMovement* defaultVal)
{
    ArgPusher2<CharMovement*, CharMovement*> pusher(thisptr, defaultVal);
    CharMovement* overrideObj = static_cast<CharMovement*>(KenshiLua::EventSystem::get().callHandlersObject(
        "CharMovement::_CONSTRUCTOR", KenshiLua::CharMovementMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

CombatClass* CallCombatClassConstructedCallbacks(CombatClass* thisptr, CharMovement* m, void* a, void* an, Character* character, CharStats* st, MedicalSystem* _med, CombatClass* defaultVal)
{
    ArgPusher8<CombatClass*, CharMovement*, void*, void*, Character*, CharStats*, MedicalSystem*, CombatClass*> pusher(thisptr, m, a, an, character, st, _med, defaultVal);
    CombatClass* overrideObj = static_cast<CombatClass*>(KenshiLua::EventSystem::get().callHandlersObject(
        "CombatClass::_CONSTRUCTOR", KenshiLua::CombatClassMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Town* CallTownConstructedCallbacks(Town* thisptr, GameData* d, Town* defaultVal)
{
    ArgPusher3<Town*, GameData*, Town*> pusher(thisptr, d, defaultVal);
    Town* overrideObj = static_cast<Town*>(KenshiLua::EventSystem::get().callHandlersObject(
        "Town::_CONSTRUCTOR", KenshiLua::TownMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

TownBase* CallTownBaseConstructedCallbacks(TownBase* thisptr, GameData* d, TownBase* defaultVal)
{
    ArgPusher3<TownBase*, GameData*, TownBase*> pusher(thisptr, d, defaultVal);
    TownBase* overrideObj = static_cast<TownBase*>(KenshiLua::EventSystem::get().callHandlersObject(
        "TownBase::_CONSTRUCTOR", KenshiLua::TownBaseMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

FactionLeader* CallFactionLeaderConstructedCallbacks(FactionLeader* thisptr, Faction* f, FactionLeader* defaultVal)
{
    ArgPusher3<FactionLeader*, Faction*, FactionLeader*> pusher(thisptr, f, defaultVal);
    FactionLeader* overrideObj = static_cast<FactionLeader*>(KenshiLua::EventSystem::get().callHandlersObject(
        "FactionLeader::_CONSTRUCTOR", KenshiLua::FactionLeaderMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

FactionRelations* CallFactionRelationsConstructedCallbacks(FactionRelations* thisptr, FactionRelations* defaultVal)
{
    ArgPusher2<FactionRelations*, FactionRelations*> pusher(thisptr, defaultVal);
    FactionRelations* overrideObj = static_cast<FactionRelations*>(KenshiLua::EventSystem::get().callHandlersObject(
        "FactionRelations::_CONSTRUCTOR", KenshiLua::FactionRelationsMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

FactionUniqueSquadManager* CallFactionUniqueSquadManagerConstructedCallbacks(FactionUniqueSquadManager* thisptr, FactionUniqueSquadManager* defaultVal)
{
    ArgPusher2<FactionUniqueSquadManager*, FactionUniqueSquadManager*> pusher(thisptr, defaultVal);
    FactionUniqueSquadManager* overrideObj = static_cast<FactionUniqueSquadManager*>(KenshiLua::EventSystem::get().callHandlersObject(
        "FactionUniqueSquadManager::_CONSTRUCTOR", KenshiLua::FactionUniqueSquadManagerMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

ProsperityManager* CallProsperityManagerConstructedCallbacks(ProsperityManager* thisptr, ProsperityManager* defaultVal)
{
    ArgPusher2<ProsperityManager*, ProsperityManager*> pusher(thisptr, defaultVal);
    ProsperityManager* overrideObj = static_cast<ProsperityManager*>(KenshiLua::EventSystem::get().callHandlersObject(
        "ProsperityManager::_CONSTRUCTOR", KenshiLua::ProsperityManagerMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

InventoryItemBase* CallInventoryItemBaseConstructedCallbacks(InventoryItemBase* thisptr, GameData* baseData, GameData* companyData, GameData* materialData, const hand& _handle, InventoryItemBase* defaultVal)
{
    ArgPusher6<InventoryItemBase*, GameData*, GameData*, GameData*, const hand&, InventoryItemBase*> pusher(thisptr, baseData, companyData, materialData, _handle, defaultVal);
    InventoryItemBase* overrideObj = static_cast<InventoryItemBase*>(KenshiLua::EventSystem::get().callHandlersObject(
        "InventoryItemBase::_CONSTRUCTOR", KenshiLua::InventoryItemBaseMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

MedicalSystem* CallMedicalSystemConstructedCallbacks(MedicalSystem* thisptr, MedicalSystem* defaultVal)
{
    ArgPusher2<MedicalSystem*, MedicalSystem*> pusher(thisptr, defaultVal);
    MedicalSystem* overrideObj = static_cast<MedicalSystem*>(KenshiLua::EventSystem::get().callHandlersObject(
        "MedicalSystem::_CONSTRUCTOR", KenshiLua::MedicalSystemMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

CombatTechniqueData* CallCombatTechniqueDataConstructedCallbacks(CombatTechniqueData* thisptr, GameData* data, CombatTechniqueData* defaultVal)
{
    ArgPusher3<CombatTechniqueData*, GameData*, CombatTechniqueData*> pusher(thisptr, data, defaultVal);
    CombatTechniqueData* overrideObj = static_cast<CombatTechniqueData*>(KenshiLua::EventSystem::get().callHandlersObject(
        "CombatTechniqueData::_CONSTRUCTOR", KenshiLua::CombatTechniqueDataMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Dialogue* CallDialogueConstructedCallbacks(Dialogue* thisptr, Dialogue* defaultVal)
{
    ArgPusher2<Dialogue*, Dialogue*> pusher(thisptr, defaultVal);
    Dialogue* overrideObj = static_cast<Dialogue*>(KenshiLua::EventSystem::get().callHandlersObject(
        "Dialogue::_CONSTRUCTOR", KenshiLua::DialogueMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

DialogLineData* CallDialogLineDataConstructedCallbacks(DialogLineData* thisptr, GameData* dat, DialogLineData* defaultVal)
{
    ArgPusher3<DialogLineData*, GameData*, DialogLineData*> pusher(thisptr, dat, defaultVal);
    DialogLineData* overrideObj = static_cast<DialogLineData*>(KenshiLua::EventSystem::get().callHandlersObject(
        "DialogLineData::_CONSTRUCTOR", KenshiLua::DialogLineDataMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

GameData* CallGameDataConstructedCallbacks(GameData* thisptr, GameData* defaultVal)
{
    ArgPusher2<GameData*, GameData*> pusher(thisptr, defaultVal);
    GameData* overrideObj = static_cast<GameData*>(KenshiLua::EventSystem::get().callHandlersObject(
        "GameData::_CONSTRUCTOR", KenshiLua::GameDataMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

Tasker* CallTaskerConstructedCallbacks(Tasker* thisptr, Tasker* defaultVal)
{
    ArgPusher2<Tasker*, Tasker*> pusher(thisptr, defaultVal);
    Tasker* overrideObj = static_cast<Tasker*>(KenshiLua::EventSystem::get().callHandlersObject(
        "Tasker::_CONSTRUCTOR", KenshiLua::TaskerMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

AppearanceManager* CallAppearanceManagerConstructedCallbacks(AppearanceManager* thisptr, AppearanceManager* defaultVal)
{
    ArgPusher2<AppearanceManager*, AppearanceManager*> pusher(thisptr, defaultVal);
    AppearanceManager* overrideObj = static_cast<AppearanceManager*>(KenshiLua::EventSystem::get().callHandlersObject(
        "AppearanceManager::_CONSTRUCTOR", KenshiLua::AppearanceManagerMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

CombatMovementController* CallCombatMovementControllerConstructedCallbacks(CombatMovementController* thisptr, CombatMovementController* defaultVal)
{
    ArgPusher2<CombatMovementController*, CombatMovementController*> pusher(thisptr, defaultVal);
    CombatMovementController* overrideObj = static_cast<CombatMovementController*>(KenshiLua::EventSystem::get().callHandlersObject(
        "CombatMovementController::_CONSTRUCTOR", KenshiLua::CombatMovementControllerMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

WorldEventStateQuery* CallWorldEventStateQueryConstructedCallbacks(WorldEventStateQuery* thisptr, WorldEventStateQuery* defaultVal)
{
    ArgPusher2<WorldEventStateQuery*, WorldEventStateQuery*> pusher(thisptr, defaultVal);
    WorldEventStateQuery* overrideObj = static_cast<WorldEventStateQuery*>(KenshiLua::EventSystem::get().callHandlersObject(
        "WorldEventStateQuery::_CONSTRUCTOR", KenshiLua::WorldEventStateQueryMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

DialogueWindow* CallDialogueWindowConstructedCallbacks(DialogueWindow* thisptr, DialogueWindow* defaultVal)
{
    ArgPusher2<DialogueWindow*, DialogueWindow*> pusher(thisptr, defaultVal);
    DialogueWindow* overrideObj = static_cast<DialogueWindow*>(KenshiLua::EventSystem::get().callHandlersObject(
        "DialogueWindow::_CONSTRUCTOR", KenshiLua::DialogueWindowMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

InventoryGUI* CallInventoryGUIConstructedCallbacks(InventoryGUI* thisptr, Inventory* inventory, InventoryLayout* layout, RootObject* callback, InventoryGUI* defaultVal)
{
    ArgPusher5<InventoryGUI*, Inventory*, InventoryLayout*, RootObject*, InventoryGUI*> pusher(thisptr, inventory, layout, callback, defaultVal);
    InventoryGUI* overrideObj = static_cast<InventoryGUI*>(KenshiLua::EventSystem::get().callHandlersObject(
        "InventoryGUI::_CONSTRUCTOR", KenshiLua::InventoryGUIMetatable(), &pusher));
    return overrideObj ? overrideObj : defaultVal;
}

GenericFixedInventoryLayout* CallGenericFixedInventoryLayoutConstructedCallbacks(GenericFixedInventoryLayout* thisptr, GenericFixedInventoryLayout* defaultVal)
{
    ArgPusher2<GenericFixedInventoryLayout*, GenericFixedInventoryLayout*> pusher(thisptr, defaultVal);
    GenericFixedInventoryLayout* overrideObj = static_cast<GenericFixedInventoryLayout*>(KenshiLua::EventSystem::get().callHandlersObject(
        "GenericFixedInventoryLayout::_CONSTRUCTOR", KenshiLua::GenericFixedInventoryLayoutMetatable(), &pusher));
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
    ArgPusher2<UseableStuff*, Character*> pusher(thisptr, who);
    return (int)KenshiLua::EventSystem::get().callHandlersNumber("UseableStuff::_NV_getCostToUse", &pusher, defaultVal);
}

bool CallUseableStuffCouldIOperateCallbacks(const UseableStuff* thisptr, const hand& h, bool defaultVal)
{
    ArgPusher2<const UseableStuff*, const hand&> pusher(thisptr, h);
    return KenshiLua::EventSystem::get().callHandlersBool("UseableStuff::_NV_couldIOperate", &pusher, defaultVal);
}

bool CallUseableStuffDontNeedWorkCallbacks(const UseableStuff* thisptr, bool defaultVal)
{
    ArgPusher1<const UseableStuff*> pusher(thisptr);
    return KenshiLua::EventSystem::get().callHandlersBool("UseableStuff::_NV_dontNeedWorkRightNow", &pusher, defaultVal);
}

// -----------------------------------------------------------
// Callbacks for hooks in Building/Building.h (Additional)
// -----------------------------------------------------------

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
    ArgPusher2<Building*, float> pusher(thisptr, amount);
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
    ArgPusher1<Building*> pusher(thisptr);
    GameData* overrideObj = static_cast<GameData*>(KenshiLua::EventSystem::get().callHandlersObject(
        "Building::_NV_canUpgrade", KenshiLua::GameDataMetatable(), &pusher));
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

// -----------------------------------------------------------
// Callbacks for hooks in Building/WallBuilding.h
// -----------------------------------------------------------

void CallWallBuildingHitByMeleeAttackCallbacks(WallBuilding* thisptr, int cutDir, Damages* damage, Character* who, CombatTechniqueData* attack, int comboID)
{
    ArgPusher6<WallBuilding*, int, Damages*, Character*, CombatTechniqueData*, int> pusher(thisptr, cutDir, damage, who, attack, comboID);
    KenshiLua::EventSystem::get().callHandlers("WallBuilding::_NV_hitByMeleeAttack", &pusher);
}

// -----------------------------------------------------------
// Callbacks for hooks in Building/DoorStuff.h
// -----------------------------------------------------------

bool CallDoorStuffOpenDoorCallbacks(DoorStuff* thisptr, bool defaultVal)
{
    ArgPusher1<DoorStuff*> pusher(thisptr);
    return KenshiLua::EventSystem::get().callHandlersBool("DoorStuff::openDoor", &pusher, defaultVal);
}

bool CallDoorStuffCloseDoorCallbacks(DoorStuff* thisptr, bool defaultVal)
{
    ArgPusher1<DoorStuff*> pusher(thisptr);
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

// -----------------------------------------------------------
// Callbacks for hooks in Building/ProductionBuilding.h
// -----------------------------------------------------------

void CallProductionBuildingOperateCallbacks(ProductionBuilding* thisptr, Character* who, float amount)
{
    ArgPusher3<ProductionBuilding*, Character*, float> pusher(thisptr, who, amount);
    KenshiLua::EventSystem::get().callHandlers("ProductionBuilding::_NV_operate", &pusher);
}

// -----------------------------------------------------------
// Callbacks for hooks in Building/CraftingBuilding.h
// -----------------------------------------------------------

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

// -----------------------------------------------------------
// Callbacks for hooks in Building/FurnaceBuilding.h
// -----------------------------------------------------------

void CallFurnaceBuildingOperateCallbacks(FurnaceBuilding* thisptr, Character* worker, float amount)
{
    ArgPusher3<FurnaceBuilding*, Character*, float> pusher(thisptr, worker, amount);
    KenshiLua::EventSystem::get().callHandlers("FurnaceBuilding::_NV_operate", &pusher);
}

// -----------------------------------------------------------
// Callbacks for hooks in Building/ResearchBuilding.h
// -----------------------------------------------------------

void CallResearchBuildingOperateCallbacks(ResearchBuilding* thisptr, Character* worker, float amount)
{
    ArgPusher3<ResearchBuilding*, Character*, float> pusher(thisptr, worker, amount);
    KenshiLua::EventSystem::get().callHandlers("ResearchBuilding::_NV_operate", &pusher);
}

// -----------------------------------------------------------
// Callbacks for hooks in Building/FarmBuilding.h
// -----------------------------------------------------------

void CallFarmBuildingOperateCallbacks(FarmBuilding* thisptr, Character* who, float amount)
{
    ArgPusher3<FarmBuilding*, Character*, float> pusher(thisptr, who, amount);
    KenshiLua::EventSystem::get().callHandlers("FarmBuilding::_NV_operate", &pusher);
}

bool CallFarmBuildingDestroyAPlantCallbacks(FarmBuilding* thisptr, bool defaultVal)
{
    ArgPusher1<FarmBuilding*> pusher(thisptr);
    return KenshiLua::EventSystem::get().callHandlersBool("FarmBuilding::destroyAPlant", &pusher, defaultVal);
}

void CallFarmBuildingEatCallbacks(FarmBuilding* thisptr, float rate)
{
    ArgPusher2<FarmBuilding*, float> pusher(thisptr, rate);
    KenshiLua::EventSystem::get().callHandlers("FarmBuilding::eat", &pusher);
}

// -----------------------------------------------------------
// Callbacks for hooks in Building/TurretBuilding.h
// -----------------------------------------------------------

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

// -----------------------------------------------------------
// Callbacks for hooks in Building/UseableStuff.h (Additional)
// -----------------------------------------------------------

void CallUseableStuffHitByMeleeAttackCallbacks(UseableStuff* thisptr, int cutDir, Damages* damage, Character* who, CombatTechniqueData* attack, int comboID)
{
    ArgPusher6<UseableStuff*, int, Damages*, Character*, CombatTechniqueData*, int> pusher(thisptr, cutDir, damage, who, attack, comboID);
    KenshiLua::EventSystem::get().callHandlers("UseableStuff::_NV_hitByMeleeAttack", &pusher);
}

float CallUseableStuffTakePowerFromCallbacks(UseableStuff* thisptr, float amount, float frameTime, float defaultVal)
{
    ArgPusher3<UseableStuff*, float, float> pusher(thisptr, amount, frameTime);
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

// -----------------------------------------------------------
// Callbacks for hooks in PreviewBuilding
// -----------------------------------------------------------

void CallPreviewBuildingPlaceFinalPreviewBuildingCallbacks(PreviewBuilding* thisptr)
{
    ArgPusher1<PreviewBuilding*> pusher(thisptr);
    KenshiLua::EventSystem::get().callHandlers("PreviewBuilding::_NV_placeFinalPreviewBuilding", &pusher);
}

bool CallPreviewBuildingPlacementVerificationCallbacks(PreviewBuilding* thisptr, bool defaultVal)
{
    ArgPusher1<PreviewBuilding*> pusher(thisptr);
    return KenshiLua::EventSystem::get().callHandlersBool("PreviewBuilding::_NV_placementVerification", &pusher, defaultVal);
}

void CallPreviewBuildingPlacePreviewCallbacks(PreviewBuilding* thisptr, const Ogre::Vector3& position, const Ogre::Quaternion& rotation, int floorNumber)
{
    ArgPusher4<PreviewBuilding*, const Ogre::Vector3&, const Ogre::Quaternion&, int> pusher(thisptr, position, rotation, floorNumber);
    KenshiLua::EventSystem::get().callHandlers("PreviewBuilding::_NV_placePreview", &pusher);
}
