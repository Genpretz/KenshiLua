#include "pch.h"
#include "Callbacks.h"
#include "EventSystem.h"
#include "Lua/BindingHelpers.h"
#include "Logger.h"

// KenshiLib x Lua Bindings
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/CharStatsBinding.h"
#include "Bindings/CombatTechniqueDataBinding.h"
#include "Bindings/DamagesBinding.h"
#include "Bindings/DialogLineDataBinding.h"
#include "Bindings/DialogueBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/Gui/DialogueWindowBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/InventorySectionBinding.h"
#include "Bindings/InventoryItemBaseBinding.h"
#include "Bindings/OwnershipsBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/PlayerInterfaceBinding.h"
#include "Bindings/CharMovementBinding.h"
#include "Bindings/CombatClassBinding.h"
#include "Bindings/GameWorldBinding.h"
#include "Bindings/RaceDataBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/TaskerBinding.h"
#include "Bindings/Gui/InventoryGUIBinding.h"
#include "Bindings/Gui/BuildModeWindowBinding.h"
#include "Bindings/Gui/SquadManagementScreenBinding.h"
#include "Bindings/Gui/ManagementScreenBinding.h"
#include "Bindings/Gui/TitleScreenBinding.h"
#include "Bindings/MyGuiBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/MedicalSystemBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/TownBinding.h"
#include "Bindings/Gui/OrdersPanelBinding.h"
#include "Bindings/Gui/DataPanelLine_ButtonBinding.h"

// KenshiLib headers
#include <kenshi/CharMovement.h>
#include <kenshi/CombatClass.h>
#include <kenshi/GameWorld.h>

// KenshiLib headers
#include <kenshi/Character.h>
#include <kenshi/Platoon.h>
#include <kenshi/Item.h>
#include <kenshi/PlayerInterface.h>
#include <kenshi/Faction.h>
#include <kenshi/Damages.h>
#include <kenshi/gui/DialogueWindow.h>
#include <kenshi/Dialogue.h>
#include <kenshi/util/lektor.h>

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
    static inline const char* FactionMetatable()                { return FactionBinding::getMetatableName(); }
    static inline const char* DialogueWindowMetatable()         { return DialogueWindowBinding::getMetatableName(); }
    static inline const char* DialogueMetatable()               { return DialogueBinding::getMetatableName(); }
    static inline const char* DialogLineDataMetatable()         { return DialogLineDataBinding::getMetatableName(); }
    static inline const char* RootObjectMetatable()             { return RootObjectBinding::getMetatableName(); }
    static inline const char* InventoryMetatable()              { return InventoryBinding::getMetatableName(); }
    static inline const char* OwnershipsMetatable()             { return OwnershipsBinding::getMetatableName(); }
    static inline const char* InventoryItemBaseMetatable()      { return InventoryItemBaseBinding::getMetatableName(); }
    static inline const char* CombatTechniqueDataMetatable()    { return CombatTechniqueDataBinding::getMetatableName(); }
    static inline const char* TaskerMetatable()                 { return TaskerBinding::getMetatableName(); }
    static inline const char* BuildingMetatable()               { return BuildingBinding::getMetatableName(); }
    static inline const char* HandMetatable()                   { return HandBinding::getMetatableName(); }
    static inline const char* GameDataMetatable()               { return GameDataBinding::getMetatableName(); }
    static inline const char* RaceDataMetatable()               { return RaceDataBinding::getMetatableName(); }
    static inline const char* InventorySectionMetatable()       { return InventorySectionBinding::getMetatableName(); }
    static inline const char* MedicalSystemMetatable()          { return MedicalSystemBinding::getMetatableName(); }
    static inline const char* CharMovementMetatable()           { return CharMovementBinding::getMetatableName(); }
    static inline const char* CombatClassMetatable()            { return CombatClassBinding::getMetatableName(); }
    static inline const char* GameWorldMetatable()              { return GameWorldBinding::getMetatableName(); }
    static inline const char* InventoryGUIMetatable()           { return InventoryGUIBinding::getMetatableName(); }
    static inline const char* BuildModeWindowMetatable()        { return BuildModeWindowBinding::getMetatableName(); }
    static inline const char* SquadManagementScreenMetatable()  { return SquadManagementScreenBinding::getMetatableName(); }
    static inline const char* ManagementScreenMetatable()       { return ManagementScreenBinding::getMetatableName(); }
    static inline const char* TitleScreenMetatable()            { return TitleScreenBinding::getMetatableName(); }
    static inline const char* MyGuiWidgetMetatable()            { return MyGuiBinding::getMetatableName(); }
    static inline const char* OrdersPanelMetatable()            { return OrdersPanelBinding::getMetatableName(); }
    static inline const char* DataPanelLineButtonMetatable()    { return DataPanelLine_ButtonBinding::getMetatableName(); }

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
    static inline void pushArg(lua_State* L, ActivePlatoon* val)            { pushObject<ActivePlatoon>(L, val, PlatoonMetatable()); }
    static inline void pushArg(lua_State* L, Item* val)                     { pushObject<Item>(L, val, ItemMetatable()); }
    static inline void pushArg(lua_State* L, Faction* val)                  { pushObject<Faction>(L, val, FactionMetatable()); }
    static inline void pushArg(lua_State* L, PlayerInterface* val)          { pushObject<PlayerInterface>(L, val, PlayerInterfaceMetatable()); }
    static inline void pushArg(lua_State* L, DialogueWindow* val)           { pushObject<DialogueWindow>(L, val, DialogueWindowMetatable()); }
    static inline void pushArg(lua_State* L, Dialogue* val)                 { pushObject<Dialogue>(L, val, DialogueMetatable()); }
    static inline void pushArg(lua_State* L, DialogLineData* val)           { pushObject<DialogLineData>(L, val, DialogLineDataMetatable()); }

    static inline void pushArg(lua_State* L, RootObject* val)               { pushObject<RootObject>(L, val, RootObjectMetatable()); }
    static inline void pushArg(lua_State* L, Inventory* val)                { pushObject<Inventory>(L, val, InventoryMetatable()); }
    static inline void pushArg(lua_State* L, CombatTechniqueData* val)      { pushObject<CombatTechniqueData>(L, val, CombatTechniqueDataMetatable()); }
    static inline void pushArg(lua_State* L, Tasker* val)                   { pushObject<Tasker>(L, val, TaskerMetatable()); }
    static inline void pushArg(lua_State* L, CombatClass* val)              { pushObject<CombatClass>(L, val, CombatClassMetatable()); }
    static inline void pushArg(lua_State* L, GameWorld* val)                { pushObject<GameWorld>(L, val, GameWorldMetatable()); }
    static inline void pushArg(lua_State* L, Building* val)                 { pushObject<Building>(L, val, BuildingMetatable()); }
    static inline void pushArg(lua_State* L, const Building* val)           { pushObject<Building>(L, const_cast<Building*>(val), BuildingMetatable()); }
    static inline void pushArg(lua_State* L, const CharStats* val)          { pushObject<CharStats>(L, const_cast<CharStats*>(val), CharStatsMetatable()); }
    static inline void pushArg(lua_State* L, Ownerships* val)               { pushObject<Ownerships>(L, val, OwnershipsMetatable()); }
    static inline void pushArg(lua_State* L, const InventoryItemBase* val)  { pushObject<InventoryItemBase>(L, const_cast<InventoryItemBase*>(val), InventoryItemBaseMetatable()); }

    static inline void pushArg(lua_State* L, const hand& val)               { pushObject<hand>(L, const_cast<hand*>(&val), HandMetatable()); }
    static inline void pushArg(lua_State* L, const Ogre::Vector3& val)      { pushVector3(L, val); }
    static inline void pushArg(lua_State* L, YesNoMaybe val)                { lua_pushinteger(L, static_cast<int>(val.key)); }
    static inline void pushArg(lua_State* L, GameData* val)                 { pushObject<GameData>(L, val, GameDataMetatable()); }
    static inline void pushArg(lua_State* L, RaceData* val)                 { pushObject<RaceData>(L, val, RaceDataMetatable()); }
    static inline void pushArg(lua_State* L, MedicalSystem* val)            { pushObject<MedicalSystem>(L, val, MedicalSystemMetatable()); }
    static inline void pushArg(lua_State* L, InventoryGUI* val)             { pushObject<InventoryGUI>(L, val, InventoryGUIMetatable()); }
    static inline void pushArg(lua_State* L, BuildModeWindow* val)          { pushObject<BuildModeWindow>(L, val, BuildModeWindowMetatable()); }
    static inline void pushArg(lua_State* L, SquadManagementScreen* val)    { pushObject<SquadManagementScreen>(L, val, SquadManagementScreenMetatable()); }
    static inline void pushArg(lua_State* L, ManagementScreen* val)         { pushObject<ManagementScreen>(L, val, ManagementScreenMetatable()); }
    static inline void pushArg(lua_State* L, TitleScreen* val)              { pushObject<TitleScreen>(L, val, TitleScreenMetatable()); }
    static inline void pushArg(lua_State* L, MyGUI::Widget* val)            { pushObject<MyGUI::Widget>(L, val, MyGuiWidgetMetatable()); }
    static inline void pushArg(lua_State* L, OrdersPanel* val)              { pushObject<OrdersPanel>(L, val, OrdersPanelMetatable()); }
    static inline void pushArg(lua_State* L, DataPanelLine_Button* val)     { pushObject<DataPanelLine_Button>(L, val, DataPanelLineButtonMetatable()); }
    static inline void pushArg(lua_State* L, void* val)                     { lua_pushlightuserdata(L, val); }
    static inline void pushArg(lua_State* L, lektor<GameData*>& val)        { pushObject<lektor<GameData*>>(L, &val, LektorPtrBinding<GameData*>::metaName); }
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

}

// ---------------------------------------------------------------------------
// Event Dispatcher Functions
// ---------------------------------------------------------------------------

void CallCharacterDeclareDeadCallbacks(Character* character)
{
    ArgPusher1<Character*> pusher(character);
    KenshiLua::EventSystem::get().callHandlers("onCharacterDeath", &pusher);
}

void CallCharacterSelectCallbacks(Character* character)
{
    ArgPusher1<Character*> pusher(character);
    KenshiLua::EventSystem::get().callHandlers("onCharacterSelect", &pusher);
}

void CallCharacterUnselectCallbacks(Character* character)
{
    ArgPusher1<Character*> pusher(character);
    KenshiLua::EventSystem::get().callHandlers("onCharacterUnselect", &pusher);
}

void CallCharacterSayCallbacks(Character* character, const std::string& message)
{
    ArgPusher2<Character*, const std::string&> pusher(character, message);
    KenshiLua::EventSystem::get().callHandlers("onCharacterSay", &pusher);
}

void CallCharacterPickupObjectCallbacks(Character* character, Character* who)
{
    ArgPusher2<Character*, Character*> pusher(character, who);
    KenshiLua::EventSystem::get().callHandlers("onCharacterPickupObject", &pusher);
}

void CallCharacterGetPickedUpCallbacks(Character* character, Character* byWhom)
{
    ArgPusher2<Character*, Character*> pusher(character, byWhom);
    KenshiLua::EventSystem::get().callHandlers("onCharacterGetPickedUp", &pusher);
}

void CallCharsUpdateCallbacks()
{
    KenshiLua::EventSystem::get().callHandlers("onCharsUpdate", NULL);
}

void CallKeyDownCallbacks(int keyCode)
{
    ArgPusher1<int> pusher(keyCode);
    KenshiLua::EventSystem::get().callHandlers("onKeyDown", &pusher);
}

void CallCharStatsSetHoldLocationCallbacks(CharStats* stats, const Ogre::Vector3& v)
{
    ArgPusher2<CharStats*, const Ogre::Vector3&> pusher(stats, v);
    KenshiLua::EventSystem::get().callHandlers("setHoldLocation", &pusher);
}

void CallCharStatsClearHoldLocationCallbacks(CharStats* stats)
{
    ArgPusher1<CharStats*> pusher(stats);
    KenshiLua::EventSystem::get().callHandlers("clearHoldLocation", &pusher);
}

CombatTechniqueData* CallCharStatsChooseAttackCallbacks(CharStats* stats, float range, float weaponReach, CombatTechniqueData* lastAttack, bool opponentIsStationary, CombatTechniqueData* defaultVal)
{
    ArgPusher6<CharStats*, float, float, CombatTechniqueData*, bool, CombatTechniqueData*> pusher(stats, range, weaponReach, lastAttack, opponentIsStationary, defaultVal);
    CombatTechniqueData* overrideVal = static_cast<CombatTechniqueData*>(KenshiLua::EventSystem::get().callHandlersObject(
        "chooseAttack", "KenshiLua.CombatTechniqueData", &pusher));
    return overrideVal ? overrideVal : defaultVal;
}

void CallCharStatsXpRunningCallbacks(CharStats* stats, float time, float speed)
{
    ArgPusher3<CharStats*, float, float> pusher(stats, time, speed);
    KenshiLua::EventSystem::get().callHandlers("xpRunning", &pusher);
}

void CallCharStatsXpFirstAidCallbacks(CharStats* stats, Character* patient, float time, int medicStat)
{
    ArgPusher4<CharStats*, Character*, float, int> pusher(stats, patient, time, medicStat);
    KenshiLua::EventSystem::get().callHandlers("xpFirstAid", &pusher);
}

void CallCharStatsXpStealthCallbacks(CharStats* stats, float time, bool enemiesAbout, YesNoMaybe seen, bool isMoving)
{
    ArgPusher5<CharStats*, float, bool, YesNoMaybe, bool> pusher(stats, time, enemiesAbout, seen, isMoving);
    KenshiLua::EventSystem::get().callHandlers("xpStealth", &pusher);
}

void CallCharStatsXpToughness_GetUpEventCallbacks(CharStats* stats)
{
    ArgPusher1<CharStats*> pusher(stats);
    KenshiLua::EventSystem::get().callHandlers("xpToughness_GetUpEvent", &pusher);
}

void CallCharStatsXpToughness_RagdollEventCallbacks(CharStats* stats)
{
    ArgPusher1<CharStats*> pusher(stats);
    KenshiLua::EventSystem::get().callHandlers("xpToughness_RagdollEvent", &pusher);
}

void CallCharStatsXpToughness_PunchSomethingCallbacks(CharStats* stats, int mat)
{
    ArgPusher2<CharStats*, int> pusher(stats, mat);
    KenshiLua::EventSystem::get().callHandlers("xpToughness_PunchSomething", &pusher);
}

void CallCharStatsXpEngineeringCallbacks(CharStats* stats, float time)
{
    ArgPusher2<CharStats*, float> pusher(stats, time);
    KenshiLua::EventSystem::get().callHandlers("xpEngineering", &pusher);
}

void CallCharStatsXpLockpickingCallbacks(CharStats* stats, int lockLevel, bool success)
{
    ArgPusher3<CharStats*, int, bool> pusher(stats, lockLevel, success);
    KenshiLua::EventSystem::get().callHandlers("xpLockpicking", &pusher);
}

void CallCharacterTakeMoneyCallbacks(Character* character, int amount)
{
    ArgPusher2<Character*, int> pusher(character, amount);
    KenshiLua::EventSystem::get().callHandlers("onCharacterTakeMoney", &pusher);
}

void CallCharacterEatCallbacks(Character* character, Item* food, Inventory* from)
{
    ArgPusher3<Character*, Item*, Inventory*> pusher(character, food, from);
    KenshiLua::EventSystem::get().callHandlers("onCharacterEat", &pusher);
}

void CallCharacterHitByMeleeCallbacks(Character* character, int cutDir, Damages* damage, Character* attacker, CombatTechniqueData* attack, int comboID)
{
    ArgPusher6<Character*, int, Damages*, Character*, CombatTechniqueData*, int> pusher(character, cutDir, damage, attacker, attack, comboID);
    KenshiLua::EventSystem::get().callHandlers("onCharacterHitByMelee", &pusher);
}

void CallCharacterGettingEatenCallbacks(Character* character, float amount, Character* eater)
{
    ArgPusher3<Character*, float, Character*> pusher(character, amount, eater);
    KenshiLua::EventSystem::get().callHandlers("onCharacterGettingEaten", &pusher);
}

void CallCharacterStandingOrderChangedCallbacks(Character* character, int orderID, bool on)
{
    ArgPusher3<Character*, int, bool> pusher(character, orderID, on);
    KenshiLua::EventSystem::get().callHandlers("onCharacterStandingOrderChanged", &pusher);
}

void CallCharacterFactionChangedCallbacks(Character* character, Faction* faction, ActivePlatoon* platoon)
{
    ArgPusher3<Character*, Faction*, ActivePlatoon*> pusher(character, faction, platoon);
    KenshiLua::EventSystem::get().callHandlers("onCharacterFactionChanged", &pusher);
}

void CallCharacterEquipCallbacks(Character* character, const std::string& sectionName, Item* item)
{
    ArgPusher3<Character*, const std::string&, Item*> pusher(character, sectionName, item);
    KenshiLua::EventSystem::get().callHandlers("onCharacterEquip", &pusher);
}

void CallCharacterUnequipCallbacks(Character* character, const std::string& sectionName, Item* item)
{
    ArgPusher3<Character*, const std::string&, Item*> pusher(character, sectionName, item);
    KenshiLua::EventSystem::get().callHandlers("onCharacterUnequip", &pusher);
}

void CallCharacterStealNoticeCallbacks(Character* character, RootObject* stealFrom, Item* item)
{
    ArgPusher3<Character*, RootObject*, Item*> pusher(character, stealFrom, item);
    KenshiLua::EventSystem::get().callHandlers("onPlayerStealCheck", &pusher);
}

void CallCharacterSmugglingCheckCallbacks(Character* character, Item* item, Character* who)
{
    ArgPusher3<Character*, Item*, Character*> pusher(character, item, who);
    KenshiLua::EventSystem::get().callHandlers("onSmugglingTradeCheck", &pusher);
}

void CallPlayerRecruitCallbacks(PlayerInterface* player, Character* character, bool editor)
{
    ArgPusher3<PlayerInterface*, Character*, bool> pusher(player, character, editor);
    KenshiLua::EventSystem::get().callHandlers("onPlayerRecruit", &pusher);
}

void CallPlayerSelectCallbacks(PlayerInterface* player, RootObject* obj, bool modifier)
{
    ArgPusher3<PlayerInterface*, RootObject*, bool> pusher(player, obj, modifier);
    KenshiLua::EventSystem::get().callHandlers("onPlayerSelectObject", &pusher);
}

void CallPlayerOrderGivenCallbacks(PlayerInterface* player, int taskType, const hand& targetH, Building* destinationIndoors, const Ogre::Vector3& clickpos, bool addDontClear)
{
    ArgPusher6<PlayerInterface*, int, const hand&, Building*, const Ogre::Vector3&, bool> pusher(player, taskType, targetH, destinationIndoors, clickpos, addDontClear);
    KenshiLua::EventSystem::get().callHandlers("onPlayerOrderGiven", &pusher);
}

void CallPlatoonMemberAddedCallbacks(ActivePlatoon* platoon, RootObject* c)
{
    ArgPusher2<ActivePlatoon*, RootObject*> pusher(platoon, c);
    KenshiLua::EventSystem::get().callHandlers("onPlatoonMemberAdded", &pusher);
}

void CallPlatoonMemberRemovedCallbacks(ActivePlatoon* platoon, RootObject* c)
{
    ArgPusher2<ActivePlatoon*, RootObject*> pusher(platoon, c);
    KenshiLua::EventSystem::get().callHandlers("onPlatoonMemberRemoved", &pusher);
}

void CallPlatoonTaskCompleteCallbacks(Platoon* platoon, Tasker* t)
{
    ArgPusher2<Platoon*, Tasker*> pusher(platoon, t);
    KenshiLua::EventSystem::get().callHandlers("onPlatoonTaskComplete", &pusher);
}

void CallItemStolenCallbacks(Item* item, RootObject* obj)
{
    ArgPusher2<Item*, RootObject*> pusher(item, obj);
    KenshiLua::EventSystem::get().callHandlers("onItemStolen", &pusher);
}

void CallCrimeWitnessedCallbacks(BountyManager* bountyMgr, Faction* against, const hand& againstWho, int expiryTime, int crimeType)
{
    ArgPusher5<BountyManager*, Faction*, const hand&, int, int> pusher(bountyMgr, against, againstWho, expiryTime, crimeType);
    KenshiLua::EventSystem::get().callHandlers("onCrimeWitnessed", &pusher);
}

void CallFactionRelationsAffectedCallbacks(FactionRelations* factionRelations, Faction* other, int eventType, float multiplier)
{
    ArgPusher4<FactionRelations*, Faction*, int, float> pusher(factionRelations, other, eventType, multiplier);
    KenshiLua::EventSystem::get().callHandlers("onFactionRelationsAffected", &pusher);
}

void CallLimbAmputatedCallbacks(MedicalSystem* med, int limb, bool createSeveredItem, const Ogre::Vector3& force)
{
    ArgPusher4<MedicalSystem*, int, bool, const Ogre::Vector3&> pusher(med, limb, createSeveredItem, force);
    KenshiLua::EventSystem::get().callHandlers("onLimbAmputated", &pusher);
}

void CallDialogueWindowShowCallbacks(DialogueWindow* thisptr, Dialogue* dialogue)
{
    ArgPusher2<DialogueWindow*, Dialogue*> pusher(thisptr, dialogue);
    KenshiLua::EventSystem::get().callHandlers("onDialogueWindowShow", &pusher);
}

void CallDialogueDoActionsCallbacks(Dialogue* thisptr, DialogLineData* dialogLine)
{
    ArgPusher2<Dialogue*, DialogLineData*> pusher(thisptr, dialogLine);
    KenshiLua::EventSystem::get().callHandlers("onDialogueDoActions", &pusher);
}

void CallDialogueSayCallbacks(Dialogue* thisptr, DialogLineData* dialogLine)
{
    ArgPusher2<Dialogue*, DialogLineData*> pusher(thisptr, dialogLine);
    KenshiLua::EventSystem::get().callHandlers("onDialogueSay", &pusher);
}

void CallDialogueEndDialogueCallbacks(Dialogue* dialogue, bool definitelyTheEnd)
{
    ArgPusher2<Dialogue*, bool> pusher(dialogue, definitelyTheEnd);
    KenshiLua::EventSystem::get().callHandlers("onDialogueEndDialogue", &pusher);
}

bool CallDialogueCheckConditionCallbacks(Dialogue* dialogue, DialogConditionEnum conditionName, ComparisonEnum compareBy, int val, Character* target, Character* actualConversationTarget, bool defaultVal)
{
    ArgPusher6<Dialogue*, DialogConditionEnum, ComparisonEnum, int, Character*, Character*> pusher(dialogue, conditionName, compareBy, val, target, actualConversationTarget);
    return KenshiLua::EventSystem::get().callHandlersBool("onDialogueCheckCondition", &pusher, defaultVal);
}

bool CallDialogueStartConversationCallbacks(Dialogue* dialogue, Character* target, DialogLineData* talk, EventTriggerEnum ev, bool force, bool defaultVal)
{
    ArgPusher5<Dialogue*, Character*, DialogLineData*, EventTriggerEnum, bool> pusher(dialogue, target, talk, ev, force);
    return KenshiLua::EventSystem::get().callHandlersBool("onDialogueStartConversation", &pusher, defaultVal);
}

void CallDialogueEndPlayerConversationCallbacks(Dialogue* dialogue, bool finished)
{
    ArgPusher2<Dialogue*, bool> pusher(dialogue, finished);
    KenshiLua::EventSystem::get().callHandlers("onDialogueEndPlayerConversation", &pusher);
}

bool CallDialogueStartPlayerConversationCallbacks(Dialogue* dialogue, Character* target, DialogLineData* talk, bool defaultVal)
{
    ArgPusher3<Dialogue*, Character*, DialogLineData*> pusher(dialogue, target, talk);
    return KenshiLua::EventSystem::get().callHandlersBool("onDialogueStartPlayerConversation", &pusher, defaultVal);
}

bool CallDialogueSendEventCallbacks(Dialogue* dialogue, Character* who, EventTriggerEnum what, bool defaultVal)
{
    ArgPusher3<Dialogue*, Character*, EventTriggerEnum> pusher(dialogue, who, what);
    return KenshiLua::EventSystem::get().callHandlersBool("onDialogueSendEvent", &pusher, defaultVal);
}

void CallDialogueStopEventCallbacks(Dialogue* dialogue, EventTriggerEnum what)
{
    ArgPusher2<Dialogue*, EventTriggerEnum> pusher(dialogue, what);
    KenshiLua::EventSystem::get().callHandlers("onDialogueStopEvent", &pusher);
}

void CallCharacterInitCallbacks(Character* character)
{
    ArgPusher1<Character*> pusher(character);
    KenshiLua::EventSystem::get().callHandlers("onCharacterInit", &pusher);
}

void CallChooseMyClothingCallbacks(lektor<GameData*>& gear, GameData* dataList, const std::string& listName, RaceData* race, bool noShoes)
{
    ArgPusher5<lektor<GameData*>&, GameData*, const std::string&, RaceData*, bool> pusher(gear, dataList, listName, race, noShoes);
    KenshiLua::EventSystem::get().callHandlers("onChooseMyClothing", &pusher);
}

void CallBaseLayoutInitialiseCallbacks(const std::string& layout)
{
    ArgPusher1<const std::string&> pusher(layout);
    KenshiLua::EventSystem::get().callHandlers("onBaseLayoutInitialise", &pusher);
}

InventorySection* CallInventoryGetSectionOfTypeCallbacks(Inventory* inventory, int type)
{
    ArgPusher2<Inventory*, int> pusher(inventory, type);
    return static_cast<InventorySection*>(KenshiLua::EventSystem::get().callHandlersObject(
        "onInventoryGetSectionOfType", "KenshiLua.InventorySection", &pusher));
}

Item* CallInventoryGetBestFoodItemCallbacks(Inventory* inventory, Character* race)
{
    ArgPusher2<Inventory*, Character*> pusher(inventory, race);
    return static_cast<Item*>(KenshiLua::EventSystem::get().callHandlersObject(
        "onInventoryGetBestFoodItem", "KenshiLua.Item", &pusher));
}

bool CallCharacterIsItOkForMeToLootCallbacks(Character* me, RootObject* victim, Item* item, bool defaultVal)
{
    ArgPusher3<Character*, RootObject*, Item*> pusher(me, victim, item);
    return KenshiLua::EventSystem::get().callHandlersBool("onCharacterLootCheck", &pusher, defaultVal);
}

float CallCharacterGetFencingSuccessChanceCallbacks(Character* merchant, Item* item, RootObject* thief, float defaultVal)
{
    ArgPusher3<Character*, Item*, RootObject*> pusher(merchant, item, thief);
    return (float)KenshiLua::EventSystem::get().callHandlersNumber("onGetFencingChance", &pusher, defaultVal);
}

float CallCharStatsGetStatCallbacks(const CharStats* stats, int what, bool unmodified, float defaultVal)
{
    ArgPusher3<const CharStats*, int, bool> pusher(stats, what, unmodified);
    return (float)KenshiLua::EventSystem::get().callHandlersNumber("onGetStat", &pusher, defaultVal);
}

GameData* CallFactionChooseARaceCallbacks(Faction* faction, GameData* character, GameData* squadTemplate, GameData* defaultVal)
{
    ArgPusher3<Faction*, GameData*, GameData*> pusher(faction, character, squadTemplate);
    GameData* overrideVal = static_cast<GameData*>(KenshiLua::EventSystem::get().callHandlersObject(
        "onFactionChooseRace", "KenshiLua.GameData", &pusher));
    return overrideVal ? overrideVal : defaultVal;
}

GameData* CallFactionGetBuildingReplacementCallbacks(Faction* faction, GameData* building, GameData* defaultVal)
{
    ArgPusher2<Faction*, GameData*> pusher(faction, building);
    GameData* overrideVal = static_cast<GameData*>(KenshiLua::EventSystem::get().callHandlersObject(
        "onFactionGetBuildingReplacement", "KenshiLua.GameData", &pusher));
    return overrideVal ? overrideVal : defaultVal;
}

bool CallOwnershipsCanIUseThisBuildingCallbacks(Ownerships* ownerships, Building* b, Character* me, bool defaultVal)
{
    ArgPusher3<Ownerships*, Building*, Character*> pusher(ownerships, b, me);
    return KenshiLua::EventSystem::get().callHandlersBool("onBuildingUseCheck", &pusher, defaultVal);
}

bool CallPlatoonIBuyStolenGoodsCallbacks(Platoon* platoon, Item* what, bool defaultVal)
{
    ArgPusher2<Platoon*, Item*> pusher(platoon, what);
    return KenshiLua::EventSystem::get().callHandlersBool("onPlatoonIBuyStolenGoods", &pusher, defaultVal);
}

bool CallPlatoonIBuyIllegalGoodsCallbacks(Platoon* platoon, bool defaultVal)
{
    ArgPusher1<Platoon*> pusher(platoon);
    return KenshiLua::EventSystem::get().callHandlersBool("onPlatoonIBuyIllegalGoods", &pusher, defaultVal);
}

bool CallBuildingIsPublicCallbacks(const Building* b, bool defaultVal)
{
    ArgPusher1<const Building*> pusher(b);
    return KenshiLua::EventSystem::get().callHandlersBool("onBuildingIsPublic", &pusher, defaultVal);
}

bool CallBuildingIsForSaleCallbacks(Building* b, bool defaultVal)
{
    ArgPusher1<Building*> pusher(b);
    return KenshiLua::EventSystem::get().callHandlersBool("onBuildingIsForSale", &pusher, defaultVal);
}

int CallBuildingCalculateSaleValueCallbacks(Building* b, int defaultVal)
{
    ArgPusher1<Building*> pusher(b);
    return (int)KenshiLua::EventSystem::get().callHandlersNumber("onBuildingCalculateSaleValue", &pusher, defaultVal);
}

int CallInventoryItemBaseGetValueSingleCallbacks(const InventoryItemBase* item, bool isPlayer, int defaultVal)
{
    ArgPusher2<const InventoryItemBase*, bool> pusher(item, isPlayer);
    return (int)KenshiLua::EventSystem::get().callHandlersNumber("onItemGetValueSingle", &pusher, defaultVal);
}

bool CallCharMovementIsRunningCallbacks(CharMovement* thisptr, bool defaultVal)
{
    ArgPusher1<CharMovement*> pusher(thisptr);
    return KenshiLua::EventSystem::get().callHandlersBool("onCharMovementIsRunning", &pusher, defaultVal);
}
bool CallCharMovementIsRunningAwayCallbacks(CharMovement* thisptr, const Ogre::Vector3& from, bool defaultVal)
{
    ArgPusher2<CharMovement*, const Ogre::Vector3&> pusher(thisptr, from);
    return KenshiLua::EventSystem::get().callHandlersBool("onCharMovementIsRunningAway", &pusher, defaultVal);
}

void CallCharStatsXpStatEventBasedCallbacks(CharStats* stats, int stat, float amount)
{
    ArgPusher3<CharStats*, int, float> pusher(stats, stat, amount);
    KenshiLua::EventSystem::get().callHandlers("onCharStatsXpStatEvent", &pusher);
}

void CallCharStatsXpDodgeEventCallbacks(CharStats* stats, float enemySkill, bool successful)
{
    ArgPusher3<CharStats*, float, bool> pusher(stats, enemySkill, successful);
    KenshiLua::EventSystem::get().callHandlers("onCharStatsXpDodgeEvent", &pusher);
}

void CallPlayerActivateCharacterEditModeCallbacks(PlayerInterface* player, Character* character)
{
    ArgPusher2<PlayerInterface*, Character*> pusher(player, character);
    KenshiLua::EventSystem::get().callHandlers("onPlayerActivateCharacterEditMode", &pusher);
}

void CallPlayerCreateSquadCallbacks(PlayerInterface* player, ActivePlatoon* newSquad)
{
    ArgPusher2<PlayerInterface*, ActivePlatoon*> pusher(player, newSquad);
    KenshiLua::EventSystem::get().callHandlers("onPlayerCreateSquad", &pusher);
}

void CallBuildingSetResidentSquadCallbacks(Building* building, Platoon* who)
{
    ArgPusher2<Building*, Platoon*> pusher(building, who);
    KenshiLua::EventSystem::get().callHandlers("onBuildingSetResidentSquad", &pusher);
}

void CallBuildingAddInternalBuildingCallbacks(Building* building, Building* b)
{
    ArgPusher2<Building*, Building*> pusher(building, b);
    KenshiLua::EventSystem::get().callHandlers("onBuildingAddInternalBuilding", &pusher);
}

void CallInventoryAddTradePartnerCallbacks(InventoryGUI* tradeWith, bool payment, bool canDrop, bool isPlayer, const hand& who)
{
    ArgPusher5<InventoryGUI*, bool, bool, bool, const hand&> pusher(tradeWith, payment, canDrop, isPlayer, who);
    KenshiLua::EventSystem::get().callHandlers("onInventoryAddTradePartner", &pusher);
}

void CallBuildModeWindowConfirmCallbacks(BuildModeWindow* window, MyGUI::Widget* sender)
{
    ArgPusher2<BuildModeWindow*, MyGUI::Widget*> pusher(window, sender);
    KenshiLua::EventSystem::get().callHandlers("onBuildModeConfirm", &pusher);
}

void CallSquadManagementScreenRemoveSquadCallbacks(SquadManagementScreen* screen, void* squadData)
{
    ArgPusher2<SquadManagementScreen*, void*> pusher(screen, squadData);
    KenshiLua::EventSystem::get().callHandlers("onSquadRemoved", &pusher);
}

void CallManagementScreenAddMessageCallbacks(ManagementScreen* screen, const std::string& owner, const std::string& message, int logColor)
{
    ArgPusher4<ManagementScreen*, const std::string&, const std::string&, int> pusher(screen, owner, message, logColor);
    KenshiLua::EventSystem::get().callHandlers("onManagementScreenMessageAdded", &pusher);
}

void CallTitleScreenLoadGameCallbacks(TitleScreen* titleScreen, MyGUI::Widget* sender)
{
    ArgPusher2<TitleScreen*, MyGUI::Widget*> pusher(titleScreen, sender);
    KenshiLua::EventSystem::get().callHandlers("onTitleScreenLoadGame", &pusher);
}

void CallCharacterAddGoalCallbacks(Character* character, int task, RootObject* subject)
{
    ArgPusher3<Character*, int, RootObject*> pusher(character, task, subject);
    KenshiLua::EventSystem::get().callHandlers("onCharacterAddGoal", &pusher);
}

void CallCharacterAddJobCallbacks(Character* character, int task, RootObject* subject, bool shift, bool addDontClear, const Ogre::Vector3& location)
{
    ArgPusher6<Character*, int, RootObject*, bool, bool, const Ogre::Vector3&> pusher(character, task, subject, shift, addDontClear, location);
    KenshiLua::EventSystem::get().callHandlers("onCharacterAddJob", &pusher);
}

void CallCharacterAddOrderCallbacks(Character* character, Building* dest, int task, RootObject* subject, bool shift, bool clear, const Ogre::Vector3& location)
{
    ArgPusher7<Character*, Building*, int, RootObject*, bool, bool, const Ogre::Vector3&> pusher(character, dest, task, subject, shift, clear, location);
    KenshiLua::EventSystem::get().callHandlers("onCharacterAddOrder", &pusher);
}

void CallCharacterRemoveJobCallbacks(Character* character, int task)
{
    ArgPusher2<Character*, int> pusher(character, task);
    KenshiLua::EventSystem::get().callHandlers("onCharacterRemoveJob", &pusher);
}

void CallPlayerInterfaceAddJobSelectedCharactersCallbacks(PlayerInterface* player, int task, RootObject* subject, bool shift, bool add, const Ogre::Vector3& location)
{
    ArgPusher6<PlayerInterface*, int, RootObject*, bool, bool, const Ogre::Vector3&> pusher(player, task, subject, shift, add, location);
    KenshiLua::EventSystem::get().callHandlers("onPlayerAddJobSelectedCharacters", &pusher);
}

void CallPlayerInterfaceAddOrderSelectedCharactersCallbacks(PlayerInterface* player, Building* destinationIndoors, int task, RootObject* subject, bool shift, bool addDontClear, const Ogre::Vector3& location)
{
    ArgPusher7<PlayerInterface*, Building*, int, RootObject*, bool, bool, const Ogre::Vector3&> pusher(player, destinationIndoors, task, subject, shift, addDontClear, location);
    KenshiLua::EventSystem::get().callHandlers("onPlayerAddOrderSelectedCharacters", &pusher);
}

void CallMedicalSystemKnockoutCallbacks(MedicalSystem* med, float skill)
{
    ArgPusher2<MedicalSystem*, float> pusher(med, skill);
    KenshiLua::EventSystem::get().callHandlers("onCharacterKnockedOut", &pusher);
}

bool CallMedicalSystemCanGetUpWakeUpCallbacks(MedicalSystem* med, bool defaultVal)
{
    ArgPusher1<MedicalSystem*> pusher(med);
    return KenshiLua::EventSystem::get().callHandlersBool("onCharacterWakeUp", &pusher, defaultVal);
}

bool CallInventoryAddItemCallbacks(Inventory* inv, Item* item, int quantity, bool dropOnFail, bool destroyOnFail)
{
    ArgPusher5<Inventory*, Item*, int, bool, bool> pusher(inv, item, quantity, dropOnFail, destroyOnFail);
    return KenshiLua::EventSystem::get().callHandlersBool("onInventoryAddItem", &pusher, true);
}

Item* CallInventoryRemoveItemCallbacks(Inventory* inv, Item* item, int howmany, bool returnCopyIfSomeLeft)
{
    ArgPusher4<Inventory*, Item*, int, bool> pusher(inv, item, howmany, returnCopyIfSomeLeft);
    return static_cast<Item*>(KenshiLua::EventSystem::get().callHandlersObject(
        "onInventoryRemoveItem", KenshiLua::ItemMetatable(), &pusher));
}

Item* CallInventoryBuyItemCallbacks(Inventory* inv, Item* item, RootObject* sender)
{
    ArgPusher3<Inventory*, Item*, RootObject*> pusher(inv, item, sender);
    return static_cast<Item*>(KenshiLua::EventSystem::get().callHandlersObject(
        "onItemBought", KenshiLua::ItemMetatable(), &pusher));
}

void CallFactionActivePlatoonCreatedCallbacks(Faction* faction, Platoon* platoon)
{
    ArgPusher2<Faction*, Platoon*> pusher(faction, platoon);
    KenshiLua::EventSystem::get().callHandlers("onActivePlatoonCreated", &pusher);
}

void CallFactionPlatoonDestroyedCallbacks(Faction* faction, Platoon* platoon)
{
    ArgPusher2<Faction*, Platoon*> pusher(faction, platoon);
    KenshiLua::EventSystem::get().callHandlers("onPlatoonDestroyed", &pusher);
}

void CallPlayerEncounterFactionCallbacks(PlayerInterface* player, Faction* faction)
{
    ArgPusher2<PlayerInterface*, Faction*> pusher(player, faction);
    KenshiLua::EventSystem::get().callHandlers("onFactionEncountered", &pusher);
}

void CallCharacterSlaveOwnerChangedCallbacks(Character* slave, const hand& newOwner)
{
    ArgPusher2<Character*, const hand&> pusher(slave, newOwner);
    KenshiLua::EventSystem::get().callHandlers("onSlaveOwnerChanged", &pusher);
}

void CallCharacterChainedModeChangedCallbacks(Character* character, bool on, const hand& owner)
{
    ArgPusher3<Character*, bool, const hand&> pusher(character, on, owner);
    KenshiLua::EventSystem::get().callHandlers("onChainedModeChanged", &pusher);
}

void CallCharacterIndoorsChangedCallbacks(Character* character, const hand& indoors)
{
    ArgPusher2<Character*, const hand&> pusher(character, indoors);
    KenshiLua::EventSystem::get().callHandlers("onCharacterIndoorsChanged", &pusher);
}

void CallBuildingLoadedCallbacks(Building* building)
{
    ArgPusher1<Building*> pusher(building);
    KenshiLua::EventSystem::get().callHandlers("onBuildingLoaded", &pusher);
}

void CallBuildingBrokenChangedCallbacks(Building* building, bool broken)
{
    ArgPusher2<Building*, bool> pusher(building, broken);
    KenshiLua::EventSystem::get().callHandlers("onBuildingBrokenChanged", &pusher);
}

void CallPlayerInterfaceSerialiseCallbacks(PlayerInterface* player, GameData* data)
{
    ArgPusher2<PlayerInterface*, GameData*> pusher(player, data);
    KenshiLua::EventSystem::get().callHandlers("onPlayerSerialise", &pusher);
}

void CallPlayerInterfaceLoadFromSerialiseCallbacks(PlayerInterface* player, GameData* data)
{
    ArgPusher2<PlayerInterface*, GameData*> pusher(player, data);
    KenshiLua::EventSystem::get().callHandlers("onPlayerLoadFromSerialise", &pusher);
}

void CallCharacterSerialiseCallbacks(Character* character, GameDataContainer* container, GameData* refList)
{
    ArgPusher3<Character*, GameDataContainer*, GameData*> pusher(character, container, refList);
    KenshiLua::EventSystem::get().callHandlers("onCharacterSerialise", &pusher);
}

void CallCharacterLoadFromSerialiseCallbacks(Character* character, GameSaveState* state)
{
    ArgPusher2<Character*, GameSaveState*> pusher(character, state);
    KenshiLua::EventSystem::get().callHandlers("onCharacterLoadFromSerialise", &pusher);
}

void CallCharacterLoadFromSerialisePostCreationStageCallbacks(Character* character, GameSaveState* state)
{
    ArgPusher2<Character*, GameSaveState*> pusher(character, state);
    KenshiLua::EventSystem::get().callHandlers("onCharacterLoadFromSerialisePostCreationStage", &pusher);
}

void CallBuildingSerialiseCallbacks(Building* building, GameDataContainer* container, GameData* refList)
{
    ArgPusher3<Building*, GameDataContainer*, GameData*> pusher(building, container, refList);
    KenshiLua::EventSystem::get().callHandlers("onBuildingSerialise", &pusher);
}

void CallBuildingLoadFromSerialiseCallbacks(Building* building, GameSaveState* state)
{
    ArgPusher2<Building*, GameSaveState*> pusher(building, state);
    KenshiLua::EventSystem::get().callHandlers("onBuildingLoadFromSerialise", &pusher);
}

void CallPlatoonLoadFromSerialiseCallbacks(Platoon* platoon, GameSaveState* state)
{
    ArgPusher2<Platoon*, GameSaveState*> pusher(platoon, state);
    KenshiLua::EventSystem::get().callHandlers("onPlatoonLoadFromSerialise", &pusher);
}

void CallTownLoadFromSerialiseCallbacks(Town* town, GameSaveState* state)
{
    ArgPusher2<Town*, GameSaveState*> pusher(town, state);
    KenshiLua::EventSystem::get().callHandlers("onTownLoadFromSerialise", &pusher);
}

void CallBuildingBuyMeCallbackCallbacks(Building* building, int result)
{
    ArgPusher2<Building*, int> pusher(building, result);
    KenshiLua::EventSystem::get().callHandlers("onBuildingBuyMeCallback", &pusher);
}

void CallDataPanelLineButtonPressCallbacks(DataPanelLine_Button* button, MyGUI::Widget* sender)
{
    ArgPusher2<DataPanelLine_Button*, MyGUI::Widget*> pusher(button, sender);
    KenshiLua::EventSystem::get().callHandlers("onDataPanelLineButtonPress", &pusher);
}

void CallInventoryGUIFencingConfirmationCallbacks(InventoryGUI* gui, int b)
{
    ArgPusher2<InventoryGUI*, int> pusher(gui, b);
    KenshiLua::EventSystem::get().callHandlers("onInventoryGUIFencingConfirmation", &pusher);
}

void CallOrdersPanelBlockModeButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, MyGUI::Widget*> pusher(panel, sender);
    KenshiLua::EventSystem::get().callHandlers("onOrdersPanelBlockModeButton", &pusher);
}

void CallOrdersPanelHoldButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, MyGUI::Widget*> pusher(panel, sender);
    KenshiLua::EventSystem::get().callHandlers("onOrdersPanelHoldButton", &pusher);
}

void CallOrdersPanelPassiveButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, MyGUI::Widget*> pusher(panel, sender);
    KenshiLua::EventSystem::get().callHandlers("onOrdersPanelPassiveButton", &pusher);
}

void CallOrdersPanelChaseButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, MyGUI::Widget*> pusher(panel, sender);
    KenshiLua::EventSystem::get().callHandlers("onOrdersPanelChaseButton", &pusher);
}

void CallOrdersPanelTauntButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, MyGUI::Widget*> pusher(panel, sender);
    KenshiLua::EventSystem::get().callHandlers("onOrdersPanelTauntButton", &pusher);
}

void CallOrdersPanelMedicButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, MyGUI::Widget*> pusher(panel, sender);
    KenshiLua::EventSystem::get().callHandlers("onOrdersPanelMedicButton", &pusher);
}

void CallOrdersPanelLiftButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, MyGUI::Widget*> pusher(panel, sender);
    KenshiLua::EventSystem::get().callHandlers("onOrdersPanelLiftButton", &pusher);
}

void CallOrdersPanelProspectingButtonCallbacks(OrdersPanel* panel, MyGUI::Widget* sender)
{
    ArgPusher2<OrdersPanel*, MyGUI::Widget*> pusher(panel, sender);
    KenshiLua::EventSystem::get().callHandlers("onOrdersPanelProspectingButton", &pusher);
}

void CallInventorySectionAddItemCallbacks(Inventory* inventory, Item* item)
{
    ArgPusher2<Inventory*, Item*> pusher(inventory, item);
    KenshiLua::EventSystem::get().callHandlers("onInventorySectionAddItem", &pusher);
}

void CallInventorySectionRemoveItemCallbacks(Inventory* inventory, Item* item)
{
    ArgPusher2<Inventory*, Item*> pusher(inventory, item);
    KenshiLua::EventSystem::get().callHandlers("onInventorySectionRemoveItem", &pusher);
}

void CallInventorySectionUpdateItemCallbacks(Inventory* inventory, Item* item, int prevQuantity)
{
    ArgPusher3<Inventory*, Item*, int> pusher(inventory, item, prevQuantity);
    KenshiLua::EventSystem::get().callHandlers("onInventorySectionUpdateItem", &pusher);
}

void CallInventoryDropItemCallbacks(Inventory* inventory, Item* item)
{
    ArgPusher2<Inventory*, Item*> pusher(inventory, item);
    KenshiLua::EventSystem::get().callHandlers("onInventoryDropItem", &pusher);
}
