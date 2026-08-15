#include "pch.h"
#include "kenshi\Gear.h"
#include "WeaponBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CrossbowBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GearBinding.h"
#include "Bindings/SwordBinding.h"
#include "CrossbowBinding.h"
#include "SwordBinding.h"

namespace KenshiLua
{

static Weapon* getInstance(lua_State* L, int idx)
{
    return checkObject<Weapon>(L, idx, WeaponBinding::getMetatableName());
}

// --- Getters for Weapon ---
static int Weapon_get_bleedDamage(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");
    lua_pushnumber(L, instance->bleedDamage);
    return 1;
}

static int Weapon_get_modAttack(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");
    lua_pushinteger(L, instance->modAttack);
    return 1;
}

static int Weapon_get_combatWeight(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");
    lua_pushnumber(L, instance->combatWeight);
    return 1;
}

static int Weapon_get_category(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");
    lua_pushinteger(L, (lua_Integer)instance->category);
    return 1;
}

static int Weapon_get_category_animationOverride(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");
    lua_pushinteger(L, (lua_Integer)instance->category_animationOverride);
    return 1;
}

// --- Setters for Weapon ---
static int Weapon_set_bleedDamage(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");
    instance->bleedDamage = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Weapon_set_modAttack(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");
    instance->modAttack = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Weapon_set_combatWeight(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");
    instance->combatWeight = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Weapon_set_category(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");
    instance->category = (WeaponCategory)luaL_checkinteger(L, 2);
    return 0;
}

static int Weapon_set_category_animationOverride(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");
    instance->category_animationOverride = (WeaponCategory)luaL_checkinteger(L, 2);
    return 0;
}

int WeaponBinding::getItemWeight(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");

    float result = instance->getItemWeight();
    lua_pushnumber(L, result);
    return 1;
}

int WeaponBinding::_NV_getItemWeight(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");

    float result = instance->_NV_getItemWeight();
    lua_pushnumber(L, result);
    return 1;
}

int WeaponBinding::getValueSingle(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");

    bool isPlayer = lua_toboolean(L, 2) != 0;
    int result = instance->getValueSingle(isPlayer);
    lua_pushinteger(L, result);
    return 1;
}

int WeaponBinding::_NV_getValueSingle(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");

    bool isPlayer = lua_toboolean(L, 2) != 0;
    int result = instance->_NV_getValueSingle(isPlayer);
    lua_pushinteger(L, result);
    return 1;
}

int WeaponBinding::getCategory(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");

    WeaponCategory result = instance->getCategory();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int WeaponBinding::getCategory_animationOverride(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");

    WeaponCategory result = instance->getCategory_animationOverride();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int WeaponBinding::is2HandedOnly(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");

    bool result = instance->is2HandedOnly();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WeaponBinding::getCombatWeight(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");

    float result = instance->getCombatWeight();
    lua_pushnumber(L, result);
    return 1;
}

int WeaponBinding::getCraftTime(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");

    float result = instance->getCraftTime();
    lua_pushnumber(L, result);
    return 1;
}

int WeaponBinding::_NV_getCraftTime(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");

    float result = instance->_NV_getCraftTime();
    lua_pushnumber(L, result);
    return 1;
}

int WeaponBinding::getCraftMaterialMult(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");

    float result = instance->getCraftMaterialMult();
    lua_pushnumber(L, result);
    return 1;
}

int WeaponBinding::_NV_getCraftMaterialMult(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");

    float result = instance->_NV_getCraftMaterialMult();
    lua_pushnumber(L, result);
    return 1;
}

int WeaponBinding::isWeapon(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");

    Weapon* result = instance->isWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int WeaponBinding::_NV_isWeapon(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");

    Weapon* result = instance->_NV_isWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int WeaponBinding::isSword(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");

    Sword* result = instance->isSword();
    return pushObject<Sword>(L, result, SwordBinding::getMetatableName());
}

int WeaponBinding::_NV_isSword(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");

    Sword* result = instance->_NV_isSword();
    return pushObject<Sword>(L, result, SwordBinding::getMetatableName());
}

int WeaponBinding::isCrossbow(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");

    Crossbow* result = instance->isCrossbow();
    return pushObject<Crossbow>(L, result, CrossbowBinding::getMetatableName());
}

int WeaponBinding::_NV_isCrossbow(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");

    Crossbow* result = instance->_NV_isCrossbow();
    return pushObject<Crossbow>(L, result, CrossbowBinding::getMetatableName());
}

int WeaponBinding::getSkillModIndoors(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");

    int result = instance->getSkillModIndoors();
    lua_pushinteger(L, result);
    return 1;
}

int WeaponBinding::_NV_getSkillModIndoors(lua_State* L)
{
    Weapon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Weapon is nil");

    int result = instance->_NV_getSkillModIndoors();
    lua_pushinteger(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 57: void getTooltipData1(...) - unsupported arg type
*/

int WeaponBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int WeaponBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Weapon object");
    return 1;
}

void WeaponBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       WeaponBinding::gc },
        { "__tostring", WeaponBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getItemWeight", WeaponBinding::getItemWeight },
        { "_NV_getItemWeight", WeaponBinding::_NV_getItemWeight },
        { "getValueSingle", WeaponBinding::getValueSingle },
        { "_NV_getValueSingle", WeaponBinding::_NV_getValueSingle },
        { "getCategory", WeaponBinding::getCategory },
        { "getCategory_animationOverride", WeaponBinding::getCategory_animationOverride },
        { "is2HandedOnly", WeaponBinding::is2HandedOnly },
        { "getCombatWeight", WeaponBinding::getCombatWeight },
        { "getCraftTime", WeaponBinding::getCraftTime },
        { "_NV_getCraftTime", WeaponBinding::_NV_getCraftTime },
        { "getCraftMaterialMult", WeaponBinding::getCraftMaterialMult },
        { "_NV_getCraftMaterialMult", WeaponBinding::_NV_getCraftMaterialMult },
        { "isWeapon", WeaponBinding::isWeapon },
        { "_NV_isWeapon", WeaponBinding::_NV_isWeapon },
        { "isSword", WeaponBinding::isSword },
        { "_NV_isSword", WeaponBinding::_NV_isSword },
        { "isCrossbow", WeaponBinding::isCrossbow },
        { "_NV_isCrossbow", WeaponBinding::_NV_isCrossbow },
        { "getSkillModIndoors", WeaponBinding::getSkillModIndoors },
        { "_NV_getSkillModIndoors", WeaponBinding::_NV_getSkillModIndoors },
        { 0, 0 }
    };

    registerClass(
        L, 
        WeaponBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, WeaponBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "bleedDamage", Weapon_get_bleedDamage);
    registerGetter(L, "modAttack", Weapon_get_modAttack);
    registerGetter(L, "combatWeight", Weapon_get_combatWeight);
    registerGetter(L, "category", Weapon_get_category);
    registerGetter(L, "category_animationOverride", Weapon_get_category_animationOverride);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "bleedDamage", Weapon_set_bleedDamage);
    registerSetter(L, "modAttack", Weapon_set_modAttack);
    registerSetter(L, "combatWeight", Weapon_set_combatWeight);
    registerSetter(L, "category", Weapon_set_category);
    registerSetter(L, "category_animationOverride", Weapon_set_category_animationOverride);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Gear
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, WeaponBinding::getMetatableName(), GearBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua