#include "pch.h"
#include "kenshi\CombatClass.h"
#include "AttackSlotManagerBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/CombatClassBinding.h"
#include "Bindings/Util/HandBinding.h"

namespace KenshiLua
{

typedef CombatClass::AttackSlotManager AttackSlotManager;

static AttackSlotManager* getInstance(lua_State* L, int idx)
{
    return checkObject<AttackSlotManager>(L, idx, AttackSlotManagerBinding::getMetatableName());
}

// --- Getters for AttackSlotManager ---
static int AttackSlotManager_get_me(lua_State* L)
{
    AttackSlotManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackSlotManager is nil");
    return pushObject<Character>(L, instance->me, CharacterBinding::getMetatableName());
}

static int AttackSlotManager_get_combatClass(lua_State* L)
{
    AttackSlotManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackSlotManager is nil");
    return pushObject<CombatClass>(L, instance->combatClass, CombatClassBinding::getMetatableName());
}

static int AttackSlotManager_get_attackSlotH(lua_State* L)
{
    AttackSlotManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackSlotManager is nil");
    lua_newtable(L);
    for (int i = 0; i < 5; ++i)
    {
        lua_newtable(L);
        HandBinding::push(L, instance->attackSlotH[i].who);
        lua_setfield(L, -2, "who");
        lua_pushnumber(L, instance->attackSlotH[i].time);
        lua_setfield(L, -2, "time");
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

// --- Setters for AttackSlotManager ---
static int AttackSlotManager_set_me(lua_State* L)
{
    AttackSlotManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackSlotManager is nil");
    instance->me = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int AttackSlotManager_set_combatClass(lua_State* L)
{
    AttackSlotManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackSlotManager is nil");
    instance->combatClass = lua_isnoneornil(L, 2) ? nullptr : checkObject<CombatClass>(L, 2, CombatClassBinding::getMetatableName());
    return 0;
}

static int AttackSlotManager_set_attackSlotH(lua_State* L)
{
    AttackSlotManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackSlotManager is nil");
    if (lua_istable(L, 2))
    {
        for (int i = 0; i < 5; ++i)
        {
            lua_rawgeti(L, 2, i + 1);
            if (lua_istable(L, -1))
            {
                lua_getfield(L, -1, "who");
                if (lua_isnoneornil(L, -1))
                {
                    instance->attackSlotH[i].who.setNull();
                }
                else
                {
                    hand* h = checkObject<hand>(L, -1, HandBinding::getMetatableName());
                    if (h)
                    {
                        instance->attackSlotH[i].who = *h;
                    }
                }
                lua_pop(L, 1);

                lua_getfield(L, -1, "time");
                if (lua_isnumber(L, -1))
                {
                    instance->attackSlotH[i].time = (float)lua_tonumber(L, -1);
                }
                else if (lua_isnoneornil(L, -1))
                {
                    instance->attackSlotH[i].time = 0.0f;
                }
                lua_pop(L, 1);
            }
            lua_pop(L, 1);
        }
    }
    return 0;
}

int AttackSlotManagerBinding::hasFreeAttackSlot(lua_State* L)
{
    AttackSlotManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackSlotManager is nil");

    bool result = instance->hasFreeAttackSlot();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AttackSlotManagerBinding::freeAllSlotsH(lua_State* L)
{
    AttackSlotManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackSlotManager is nil");

    instance->freeAllSlotsH();
    return 0;
}

int AttackSlotManagerBinding::periodicUpdate(lua_State* L)
{
    AttackSlotManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackSlotManager is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->periodicUpdate(time);
    return 0;
}

int AttackSlotManagerBinding::update(lua_State* L)
{
    AttackSlotManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackSlotManager is nil");

    instance->update();
    return 0;
}

int AttackSlotManagerBinding::getNumAttackSlots(lua_State* L)
{
    AttackSlotManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackSlotManager is nil");

    int result = instance->getNumAttackSlots();
    lua_pushinteger(L, result);
    return 1;
}

int AttackSlotManagerBinding::getMaxPossibleAttackSlots(lua_State* L)
{
    AttackSlotManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackSlotManager is nil");

    int result = instance->getMaxPossibleAttackSlots();
    lua_pushinteger(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 104: void freeSlotH(...) - non-string reference arg
  line 106: bool addToSlotH(...) - non-string reference arg
*/

int AttackSlotManagerBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int AttackSlotManagerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AttackSlotManager object");
    return 1;
}

void AttackSlotManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AttackSlotManagerBinding::gc },
        { "__tostring", AttackSlotManagerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "hasFreeAttackSlot", AttackSlotManagerBinding::hasFreeAttackSlot },
        { "freeAllSlotsH", AttackSlotManagerBinding::freeAllSlotsH },
        { "periodicUpdate", AttackSlotManagerBinding::periodicUpdate },
        { "update", AttackSlotManagerBinding::update },
        { "getNumAttackSlots", AttackSlotManagerBinding::getNumAttackSlots },
        { "getMaxPossibleAttackSlots", AttackSlotManagerBinding::getMaxPossibleAttackSlots },
        { 0, 0 }
    };

    registerClass(
        L, 
        AttackSlotManagerBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AttackSlotManagerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "me", AttackSlotManager_get_me);
    registerGetter(L, "combatClass", AttackSlotManager_get_combatClass);
    registerGetter(L, "attackSlotH", AttackSlotManager_get_attackSlotH);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "me", AttackSlotManager_set_me);
    registerSetter(L, "combatClass", AttackSlotManager_set_combatClass);
    registerSetter(L, "attackSlotH", AttackSlotManager_set_attackSlotH);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, AttackSlotManagerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua