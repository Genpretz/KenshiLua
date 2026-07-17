#include "pch.h"
#include "kenshi\Gear.h"
#include "WeaponBinding.h"
#include "SwordBinding.h"
#include "CrossbowBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CrossbowBinding.h"
#include "Bindings/SwordBinding.h"

namespace KenshiLua
{

static Weapon* getB(lua_State* L, int idx)
{
    return checkObject<Weapon>(L, idx, WeaponBinding::getMetatableName());
}

// --- Getters for Weapon ---
static int Weapon_get_bleedDamage(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");
    lua_pushnumber(L, b->bleedDamage);
    return 1;
}

static int Weapon_get_modAttack(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");
    lua_pushinteger(L, b->modAttack);
    return 1;
}

static int Weapon_get_combatWeight(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");
    lua_pushnumber(L, b->combatWeight);
    return 1;
}

static int Weapon_get_category(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");
    lua_pushinteger(L, (lua_Integer)b->category);
    return 1;
}

static int Weapon_get_category_animationOverride(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");
    lua_pushinteger(L, (lua_Integer)b->category_animationOverride);
    return 1;
}

// --- Setters for Weapon ---
static int Weapon_set_bleedDamage(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");
    b->bleedDamage = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Weapon_set_modAttack(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");
    b->modAttack = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Weapon_set_combatWeight(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");
    b->combatWeight = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Weapon_set_category(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");
    b->category = (WeaponCategory)luaL_checkinteger(L, 2);
    return 0;
}

static int Weapon_set_category_animationOverride(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");
    b->category_animationOverride = (WeaponCategory)luaL_checkinteger(L, 2);
    return 0;
}

int WeaponBinding::getItemWeight(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");

    float result = b->getItemWeight();
    lua_pushnumber(L, result);
    return 1;
}

int WeaponBinding::_NV_getItemWeight(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");

    float result = b->_NV_getItemWeight();
    lua_pushnumber(L, result);
    return 1;
}

int WeaponBinding::getValueSingle(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");

    bool isPlayer = lua_toboolean(L, 2) != 0;
    int result = b->getValueSingle(isPlayer);
    lua_pushinteger(L, result);
    return 1;
}

int WeaponBinding::_NV_getValueSingle(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");

    bool isPlayer = lua_toboolean(L, 2) != 0;
    int result = b->_NV_getValueSingle(isPlayer);
    lua_pushinteger(L, result);
    return 1;
}

int WeaponBinding::getCategory(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");

    WeaponCategory result = b->getCategory();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int WeaponBinding::getCategory_animationOverride(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");

    WeaponCategory result = b->getCategory_animationOverride();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int WeaponBinding::is2HandedOnly(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");

    bool result = b->is2HandedOnly();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WeaponBinding::getCombatWeight(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");

    float result = b->getCombatWeight();
    lua_pushnumber(L, result);
    return 1;
}

int WeaponBinding::getCraftTime(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");

    float result = b->getCraftTime();
    lua_pushnumber(L, result);
    return 1;
}

int WeaponBinding::_NV_getCraftTime(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");

    float result = b->_NV_getCraftTime();
    lua_pushnumber(L, result);
    return 1;
}

int WeaponBinding::getCraftMaterialMult(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");

    float result = b->getCraftMaterialMult();
    lua_pushnumber(L, result);
    return 1;
}

int WeaponBinding::_NV_getCraftMaterialMult(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");

    float result = b->_NV_getCraftMaterialMult();
    lua_pushnumber(L, result);
    return 1;
}

int WeaponBinding::isWeapon(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");

    Weapon* result = b->isWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int WeaponBinding::_NV_isWeapon(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");

    Weapon* result = b->_NV_isWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int WeaponBinding::isSword(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");

    Sword* result = b->isSword();
    return pushObject<Sword>(L, result, SwordBinding::getMetatableName());
}

int WeaponBinding::_NV_isSword(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");

    Sword* result = b->_NV_isSword();
    return pushObject<Sword>(L, result, SwordBinding::getMetatableName());
}

int WeaponBinding::isCrossbow(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");

    Crossbow* result = b->isCrossbow();
    return pushObject<Crossbow>(L, result, CrossbowBinding::getMetatableName());
}

int WeaponBinding::_NV_isCrossbow(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");

    Crossbow* result = b->_NV_isCrossbow();
    return pushObject<Crossbow>(L, result, CrossbowBinding::getMetatableName());
}

int WeaponBinding::getSkillModIndoors(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");

    int result = b->getSkillModIndoors();
    lua_pushinteger(L, result);
    return 1;
}

int WeaponBinding::_NV_getSkillModIndoors(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");

    int result = b->_NV_getSkillModIndoors();
    lua_pushinteger(L, result);
    return 1;
}

int WeaponBinding::_DESTRUCTOR(lua_State* L)
{
    Weapon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Weapon is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 57: void getTooltipData1(...) - unsupported arg type
  line 70: Weapon* _CONSTRUCTOR(...) - unsupported arg type
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
        { "_DESTRUCTOR", WeaponBinding::_DESTRUCTOR },
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
    lua_pushcfunction(L, Weapon_get_bleedDamage);
    lua_setfield(L, -2, "bleedDamage");
    lua_pushcfunction(L, Weapon_get_modAttack);
    lua_setfield(L, -2, "modAttack");
    lua_pushcfunction(L, Weapon_get_combatWeight);
    lua_setfield(L, -2, "combatWeight");
    lua_pushcfunction(L, Weapon_get_category);
    lua_setfield(L, -2, "category");
    lua_pushcfunction(L, Weapon_get_category_animationOverride);
    lua_setfield(L, -2, "category_animationOverride");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, Weapon_set_bleedDamage);
    lua_setfield(L, -2, "bleedDamage");
    lua_pushcfunction(L, Weapon_set_modAttack);
    lua_setfield(L, -2, "modAttack");
    lua_pushcfunction(L, Weapon_set_combatWeight);
    lua_setfield(L, -2, "combatWeight");
    lua_pushcfunction(L, Weapon_set_category);
    lua_setfield(L, -2, "category");
    lua_pushcfunction(L, Weapon_set_category_animationOverride);
    lua_setfield(L, -2, "category_animationOverride");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua