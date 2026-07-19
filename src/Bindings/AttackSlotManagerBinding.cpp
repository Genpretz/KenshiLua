#include "pch.h"
#include "kenshi\CombatClass.h"
#include "AttackSlotManagerBinding.h"
#include "Lua/BindingHelpers.h"

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
    lua_pushlightuserdata(L, (void*)instance->combatClass);
    return 1;
}

static int AttackSlotManager_get_attackSlotH(lua_State* L)
{
    AttackSlotManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackSlotManager is nil");
    lua_pushlightuserdata(L, (void*)instance->attackSlotH);
    return 1;
}

// --- Setters for AttackSlotManager ---
static int AttackSlotManager_set_attackSlotH(lua_State* L)
{
    return luaL_error(L, "Read-only or unsupported setter type for attackSlotH");
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

int AttackSlotManagerBinding::_DESTRUCTOR(lua_State* L)
{
    AttackSlotManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AttackSlotManager is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 102: AttackSlotManager* _CONSTRUCTOR(...) - unsupported arg type
  line 104: void freeSlotH(...) - unsupported arg type
  line 106: bool addToSlotH(...) - unsupported arg type
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
        { "_DESTRUCTOR", AttackSlotManagerBinding::_DESTRUCTOR },
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
    lua_pushcfunction(L, AttackSlotManager_get_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, AttackSlotManager_get_combatClass);
    lua_setfield(L, -2, "combatClass");
    lua_pushcfunction(L, AttackSlotManager_get_attackSlotH);
    lua_setfield(L, -2, "attackSlotH");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, AttackSlotManager_set_attackSlotH);
    lua_setfield(L, -2, "attackSlotH");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, AttackSlotManagerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
