#include "pch.h"
#include "Callbacks.h"
#include "EventSystem.h"
#include "Lua/BindingHelpers.h"
#include "Lua/Logger.h"

// KenshiLib x Lua Bindings
#include "Character/CharacterBinding.h"
#include "Character/CharStatsBinding.h"
#include "System/DamagesBinding.h"
#include "World/PlatoonBinding.h"
#include "Equipment/ItemBinding.h"
#include "Core/PlayerInterfaceBinding.h"
#include "World/FactionBinding.h"

// KenshiLib headers
#include <kenshi/Character.h>
#include <kenshi/Platoon.h>
#include <kenshi/Item.h>
#include <kenshi/PlayerInterface.h>
#include <kenshi/Faction.h>
#include <kenshi/Damages.h>

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <luaconf.h>
#include <lauxlib.h>
}

// ---------------------------------------------------------------------------
// Generic Argument Pusher Templates & Overloads
// ---------------------------------------------------------------------------

namespace KenshiLua
{
    // Shorthand metatable helpers
    static inline const char* CharacterMetatable()       { return CharacterBinding::getMetatableName(); }
    static inline const char* CharStatsMetatable()       { return CharStatsBinding::getMetatableName(); }
    static inline const char* DamagesMetatable()         { return DamagesBinding::getMetatableName(); }
    static inline const char* PlatoonMetatable()         { return PlatoonBinding::getMetatableName(); }
    static inline const char* ItemMetatable()            { return ItemBinding::getMetatableName(); }
    static inline const char* PlayerInterfaceMetatable() { return PlayerInterfaceBinding::getMetatableName(); }
    static inline const char* FactionMetatable()         { return FactionBinding::getMetatableName(); }

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

    static inline void pushArg(lua_State* L, RootObject* val)         { pushObject<RootObject>(L, val, "KenshiLua.RootObject"); }
    static inline void pushArg(lua_State* L, Inventory* val)          { pushObject<Inventory>(L, val, "KenshiLua.Inventory"); }
    static inline void pushArg(lua_State* L, CombatTechniqueData* val){ pushObject<CombatTechniqueData>(L, val, "KenshiLua.CombatTechniqueData"); }
    static inline void pushArg(lua_State* L, Tasker* val)             { pushObject<Tasker>(L, val, "KenshiLua.Tasker"); }
    static inline void pushArg(lua_State* L, Building* val)           { pushObject<Building>(L, val, "KenshiLua.Building"); }

    static inline void pushArg(lua_State* L, const hand& val)         { pushObject<hand>(L, const_cast<hand*>(&val), "KenshiLua.hand"); }
    static inline void pushArg(lua_State* L, const Ogre::Vector3& val){ pushVector3(L, val); }
    static inline void pushArg(lua_State* L, YesNoMaybe val)          { lua_pushinteger(L, static_cast<int>(val.key)); }
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

