#include "pch.h"
#include "Bindings/CombatClass_AttackSlotManager_SlotDataBinding.h"
#include "Lua/BindingHelpers.h"
#include <kenshi/CombatClass.h>

#include "Bindings/Util/HandBinding.h"

namespace KenshiLua
{

static CombatClass::AttackSlotManager::SlotData* getInstance(lua_State* L, int idx)
{
    return checkObject<CombatClass::AttackSlotManager::SlotData>(L, idx, CombatClass_AttackSlotManager_SlotDataBinding::getMetatableName());
}

// --- Getters for SlotData ---
static int SlotData_get_who(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "CombatClass::AttackSlotManager::SlotData is nil");
    return HandBinding::push(L, inst->who);
}

static int SlotData_get_time(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "CombatClass::AttackSlotManager::SlotData is nil");
    lua_pushnumber(L, inst->time);
    return 1;
}

// --- Setters for SlotData ---
static int SlotData_set_who(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "CombatClass::AttackSlotManager::SlotData is nil");
    auto* val = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (val) inst->who = *val;
    return 0;
}

static int SlotData_set_time(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "CombatClass::AttackSlotManager::SlotData is nil");
    inst->time = (float)luaL_checknumber(L, 2);
    return 0;
}

int CombatClass_AttackSlotManager_SlotDataBinding::gc(lua_State* L)
{
    return 0;
}

int CombatClass_AttackSlotManager_SlotDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CombatClass_AttackSlotManager_SlotData object");
    return 1;
}

int CombatClass_AttackSlotManager_SlotDataBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (a->who == b->who && a->time == b->time)) ? 1 : 0);
    return 1;
}

void CombatClass_AttackSlotManager_SlotDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       operator_eq },
        { "__gc",       gc },
        { "__tostring", tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L); // __getters
    registerGetter(L, "who", SlotData_get_who);
    registerGetter(L, "time", SlotData_get_time);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "who", SlotData_set_who);
    registerSetter(L, "time", SlotData_set_time);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
