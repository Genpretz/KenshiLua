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
#include "Bindings/ItemBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/PlayerInterfaceBinding.h"
#include "Bindings/RaceDataBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/TaskerBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/LektorBinding.h"

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
    static inline const char* CombatTechniqueDataMetatable()    { return CombatTechniqueDataBinding::getMetatableName(); }
    static inline const char* TaskerMetatable()                 { return TaskerBinding::getMetatableName(); }
    static inline const char* BuildingMetatable()               { return BuildingBinding::getMetatableName(); }
    static inline const char* HandMetatable()                   { return handBinding::getMetatableName(); }
    static inline const char* GameDataMetatable()               { return GameDataBinding::getMetatableName(); }
    static inline const char* RaceDataMetatable()               { return RaceDataBinding::getMetatableName(); }
    static inline const char* InventorySectionMetatable()       { return InventorySectionBinding::getMetatableName(); }

    // pushArg overloads for primitive types
    static inline void pushArg(lua_State* L, int val)                 { lua_pushinteger(L, val); }
    static inline void pushArg(lua_State* L, float val)               { lua_pushnumber(L, val); }
    static inline void pushArg(lua_State* L, bool val)                { lua_pushboolean(L, val ? 1 : 0); }
    static inline void pushArg(lua_State* L, const std::string& val)  { lua_pushstring(L, val.c_str()); }

    // pushArg overloads for bound classes
    static inline void pushArg(lua_State* L, Character* val)          { pushObject<Character>(L, val, CharacterMetatable()); }
    static inline void pushArg(lua_State* L, CharStats* val)          { pushObject<CharStats>(L, val, CharStatsMetatable()); }
    static inline void pushArg(lua_State* L, Damages* val)            { pushObject<Damages>(L, val, DamagesMetatable()); }
    static inline void pushArg(lua_State* L, Platoon* val)            { pushObject<Platoon>(L, val, PlatoonMetatable()); }
    static inline void pushArg(lua_State* L, ActivePlatoon* val)      { pushObject<ActivePlatoon>(L, val, PlatoonMetatable()); }
    static inline void pushArg(lua_State* L, Item* val)               { pushObject<Item>(L, val, ItemMetatable()); }
    static inline void pushArg(lua_State* L, Faction* val)            { pushObject<Faction>(L, val, FactionMetatable()); }
    static inline void pushArg(lua_State* L, PlayerInterface* val)    { pushObject<PlayerInterface>(L, val, PlayerInterfaceMetatable()); }
    static inline void pushArg(lua_State* L, DialogueWindow* val)     { pushObject<DialogueWindow>(L, val, DialogueWindowMetatable()); }
    static inline void pushArg(lua_State* L, Dialogue* val)           { pushObject<Dialogue>(L, val, DialogueMetatable()); }
    static inline void pushArg(lua_State* L, DialogLineData* val)     { pushObject<DialogLineData>(L, val, DialogLineDataMetatable()); }

    static inline void pushArg(lua_State* L, RootObject* val)         { pushObject<RootObject>(L, val, RootObjectMetatable()); }
    static inline void pushArg(lua_State* L, Inventory* val)          { pushObject<Inventory>(L, val, InventoryMetatable()); }
    static inline void pushArg(lua_State* L, CombatTechniqueData* val){ pushObject<CombatTechniqueData>(L, val, CombatTechniqueDataMetatable()); }
    static inline void pushArg(lua_State* L, Tasker* val)             { pushObject<Tasker>(L, val, TaskerMetatable()); }
    static inline void pushArg(lua_State* L, Building* val)           { pushObject<Building>(L, val, BuildingMetatable()); }

    static inline void pushArg(lua_State* L, const hand& val)         { pushObject<hand>(L, const_cast<hand*>(&val), HandMetatable()); }
    static inline void pushArg(lua_State* L, const Ogre::Vector3& val){ pushVector3(L, val); }
    static inline void pushArg(lua_State* L, YesNoMaybe val)          { lua_pushinteger(L, static_cast<int>(val.key)); }
    static inline void pushArg(lua_State* L, GameData* val)           { pushObject<GameData>(L, val, GameDataMetatable()); }
    static inline void pushArg(lua_State* L, RaceData* val)           { pushObject<RaceData>(L, val, RaceDataMetatable()); }
    static inline void pushArg(lua_State* L, InventorySection* val)   { pushObject<InventorySection>(L, val, InventorySectionMetatable()); }
    static inline void pushArg(lua_State* L, lektor<GameData*>& val)  { pushObject<lektor<GameData*>>(L, &val, LektorPtrBinding<GameData*>::metaName); }
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

void CallCharacterPickupObjectCallbacks(Character* character)
{
    ArgPusher1<Character*> pusher(character);
    KenshiLua::EventSystem::get().callHandlers("onCharacterPickupObject", &pusher);
}

void CallCharacterGetPickedUpCallbacks(Character* byWhom)
{
    ArgPusher1<Character*> pusher(byWhom);
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

void CallCharStatsChooseAttackCallbacks(CharStats* stats, float range, float weaponReach, CombatTechniqueData* lastAttack, bool opponentIsStationary, CombatTechniqueData* chosenAttack)
{
    ArgPusher6<CharStats*, float, float, CombatTechniqueData*, bool, CombatTechniqueData*> pusher(stats, range, weaponReach, lastAttack, opponentIsStationary, chosenAttack);
    KenshiLua::EventSystem::get().callHandlers("chooseAttack", &pusher);
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

void CallCharacterHitByMeleeCallbacks(Character* character, Character* attacker, Damages* damage, int cutDir, CombatTechniqueData* attack, int comboID)
{
    ArgPusher6<Character*, Character*, Damages*, int, CombatTechniqueData*, int> pusher(character, attacker, damage, cutDir, attack, comboID);
    KenshiLua::EventSystem::get().callHandlers("onCharacterHitByMelee", &pusher);
}

void CallCharacterGettingEatenCallbacks(Character* character, Character* eater, float amount)
{
    ArgPusher3<Character*, Character*, float> pusher(character, eater, amount);
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

void CallCharacterStealNoticeCallbacks(Character* character, RootObject* stealFrom, Item* item, bool noticed)
{
    ArgPusher4<Character*, RootObject*, Item*, bool> pusher(character, stealFrom, item, noticed);
    KenshiLua::EventSystem::get().callHandlers("onPlayerStealCheck", &pusher);
}

void CallCharacterSmugglingCheckCallbacks(Character* character, Item* item, Character* who, int result)
{
    ArgPusher4<Character*, Item*, Character*, int> pusher(character, item, who, result);
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

void CallCrimeWitnessedCallbacks(Character* character, Faction* against, const hand& againstWho, int expiryTime, int crimeType)
{
    ArgPusher5<Character*, Faction*, const hand&, int, int> pusher(character, against, againstWho, expiryTime, crimeType);
    KenshiLua::EventSystem::get().callHandlers("onCrimeWitnessed", &pusher);
}

void CallFactionRelationsAffectedCallbacks(Faction* faction, Faction* other, int eventType, float multiplier)
{
    ArgPusher4<Faction*, Faction*, int, float> pusher(faction, other, eventType, multiplier);
    KenshiLua::EventSystem::get().callHandlers("onFactionRelationsAffected", &pusher);
}

void CallLimbAmputatedCallbacks(Character* character, int limb, bool createSeveredItem, const Ogre::Vector3& force)
{
    ArgPusher4<Character*, int, bool, const Ogre::Vector3&> pusher(character, limb, createSeveredItem, force);
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

