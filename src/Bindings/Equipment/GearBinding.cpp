#include "pch.h"
<<<<<<< HEAD:src/Bindings/Equipment/GearBinding.cpp

#include "Bindings/Equipment/GearBinding.h"
#include "Bindings/Equipment/ItemBinding.h"
#include "Bindings/World/FactionBinding.h"
=======
#include "kenshi\Gear.h"
#include "GearBinding.h"
>>>>>>> main:src/Bindings/GearBinding.cpp
#include "Lua/BindingHelpers.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"

namespace KenshiLua
{

static Gear* getB(lua_State* L, int idx)
{
    return checkObject<Gear>(L, idx, GearBinding::getMetatableName());
}

// --- Getters for Gear ---
static int Gear_get_isUniform(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    return pushObject<Faction>(L, b->isUniform, FactionBinding::getMetatableName());
}

static int Gear_get_value(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    lua_pushinteger(L, b->value);
    return 1;
}

static int Gear_get_crafter(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    lua_pushstring(L, b->crafter.c_str());
    return 1;
}

static int Gear_get_level(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    lua_pushnumber(L, b->level);
    return 1;
}

static int Gear_get_level_0_100(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    lua_pushinteger(L, b->level_0_100);
    return 1;
}

// --- Setters for Gear ---
static int Gear_set_isUniform(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    Faction* f = nullptr;
    if (!lua_isnil(L, 2)) {
        f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    }
    b->isUniform = f;
    return 0;
}

static int Gear_set_value(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    b->value = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Gear_set_crafter(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    b->crafter = luaL_checkstring(L, 2);
    return 0;
}

static int Gear_set_level(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    b->level = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Gear_set_level_0_100(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    b->level_0_100 = (int)luaL_checkinteger(L, 2);
    return 0;
}

// --- Methods for Gear ---
int GearBinding::isGear(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");

    Gear* result = b->isGear();
    return pushObject<Gear>(L, result, GearBinding::getMetatableName());
}

int GearBinding::_NV_isGear(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");

    Gear* result = b->_NV_isGear();
    return pushObject<Gear>(L, result, GearBinding::getMetatableName());
}

int GearBinding::getLevel01(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");

    float result = b->getLevel01();
    lua_pushnumber(L, result);
    return 1;
}

int GearBinding::_NV_getLevel01(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");

    float result = b->_NV_getLevel01();
    lua_pushnumber(L, result);
    return 1;
}

int GearBinding::getLevel(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");

    int result = b->getLevel();
    lua_pushinteger(L, result);
    return 1;
}

int GearBinding::_NV_getLevel(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");

    int result = b->_NV_getLevel();
    lua_pushinteger(L, result);
    return 1;
}

int GearBinding::isAFactionUniform(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");

    Faction* result = b->isAFactionUniform();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int GearBinding::_NV_isAFactionUniform(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");

    Faction* result = b->_NV_isAFactionUniform();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int GearBinding::isPlayerCrafted(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");

    bool result = b->isPlayerCrafted();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GearBinding::_DESTRUCTOR(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");

    b->_DESTRUCTOR();
    return 0;
}

int GearBinding::setInventoryWeAreIn(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->setInventoryWeAreIn(*h);
    return 0;
}

int GearBinding::_NV_setInventoryWeAreIn(lua_State* L)
{
    Item* b = getB(L, 1);
    if (!b) return luaL_error(L, "Item is nil");
    hand* h = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->_NV_setInventoryWeAreIn(*h);
    return 0;
}

int GearBinding::_CONSTRUCTOR(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    GameData* baseData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* companyData = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    GameData* materialData = checkObject<GameData>(L, 4, GameDataBinding::getMetatableName());
    hand* _handle = checkObject<hand>(L, 5, handBinding::getMetatableName());
    int _level = (int)luaL_checkinteger(L, 6);
    Faction* uniform = nullptr;
    if (lua_gettop(L) >= 7 && !lua_isnil(L, 7)) {
        uniform = checkObject<Faction>(L, 7, FactionBinding::getMetatableName());
    }
<<<<<<< HEAD:src/Bindings/Equipment/GearBinding.cpp

    int GearBinding::index(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);

        // 1. Check the metatable first so obj:method() syntax continues to work.
        luaL_getmetatable(L, GearBinding::getMetatableName());
        lua_getfield(L, -1, key);
        if (!lua_isnil(L, -1))
            return 1;   // found a method — return it
        lua_pop(L, 2);  // pop nil result + metatable

        // 2. Fall through to raw member variable access.
        Gear* m = getG(L, 1);
        if (!m) { lua_pushnil(L); return 1; }

        // Readable fields

        // --- float members ---
        LUA_GET_FLOAT_MEMBER(level);
        // --- integer enum members ---
        LUA_GET_INT_MEMBER(value);
        LUA_GET_INT_MEMBER(level_0_100);
        // --- std::string members ---
        LUA_GET_STRING_MEMBER(crafter);

        // Fallback to Item
        return ItemBinding::index(L);
    }

    int GearBinding::newindex(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);

        Gear* m = getG(L, 1);
        if (!m) return luaL_error(L, "Gear is nil");

        // Writeable fields

        // --- float members ---
        LUA_SET_FLOAT_MEMBER(level);
        // --- integer enum members ---
        LUA_SET_INT_MEMBER(value);
        LUA_SET_INT_MEMBER(level_0_100);
        // --- std::string members ---
        LUA_SET_STRING_MEMBER(crafter);

        return ItemBinding::newindex(L);
    }

    int GearBinding::isAFactionUniform(lua_State* L)
    {
        Gear* m = getG(L, 1);
        if (!m || !m->isAFactionUniform()) { lua_pushnil(L); return 1; }
        return pushObject<Faction>(L, m->isAFactionUniform(), FactionBinding::getMetatableName());
    }
    int GearBinding::isPlayerCrafted(lua_State* L) { Gear* m = getG(L, 1); lua_pushboolean(L, m && m->isPlayerCrafted() ? 1 : 0); return 1; }


    void GearBinding::registerBinding(lua_State* L)
    {
        static const luaL_Reg metamethods[] = {
            { "__gc", GearBinding::gc },
            { "__tostring", GearBinding::tostring },
            { 0, 0 }
        };

        static const luaL_Reg methods[] = {
            { "isAFactionUniform", GearBinding::isAFactionUniform },
            { "isPlayerCrafted", GearBinding::isPlayerCrafted },
            { 0, 0 }
        };

        registerClass(
            L,
            GearBinding::getMetatableName(),
            metamethods,
            methods,
            GearBinding::index,
            GearBinding::newindex
            );
    }

    // ------------------------------------------
    // class Weapon : public Gear
    // ------------------------------------------

    static Weapon* getW(lua_State* L, int idx)
    {
        Weapon* w = testObject<Weapon>(L, idx, WeaponBinding::getMetatableName());
        if (w) return w;
        w = (Weapon*)testObject<Sword>(L, idx, SwordBinding::getMetatableName());
        if (w) return w;
        w = (Weapon*)testObject<Crossbow>(L, idx, CrossbowBinding::getMetatableName());
        if (w) return w;
        luaL_argerror(L, idx, "Weapon");
        return nullptr;
    }

    int WeaponBinding::gc(lua_State* L) { return noopGc(L); }

    int WeaponBinding::tostring(lua_State* L)
    {
        Weapon* m = getW(L, 1);
        if (!m) { lua_pushstring(L, "Weapon:nil"); return 1; }
        char buf[160];
        _snprintf(buf, sizeof(buf), "Weapon:%s(%p)", m->isValid() ? m->getName().c_str() : "?", (void*)m);
        lua_pushstring(L, buf);
        return 1;
    }

    int WeaponBinding::index(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);

        // 1. Check the metatable first so obj:method() syntax continues to work.
        luaL_getmetatable(L, WeaponBinding::getMetatableName());
        lua_getfield(L, -1, key);
        if (!lua_isnil(L, -1))
            return 1;   // found a method — return it
        lua_pop(L, 2);  // pop nil result + metatable

        // 2. Fall through to raw member variable access.
        Weapon* m = getW(L, 1);
        if (!m) { lua_pushnil(L); return 1; }

        // Readable fields

        // --- float members ---
        LUA_GET_FLOAT_MEMBER(bleedDamage);
        LUA_GET_FLOAT_MEMBER(combatWeight);
        // --- integer members ---
        LUA_GET_INT_MEMBER(modAttack);
        // --- enum members ---
        LUA_GET_ENUM_MEMBER(category, WeaponCategory);
        LUA_GET_ENUM_MEMBER(category_animationOverride, WeaponCategory);

        // Fallback to Gear
        return GearBinding::index(L);
    }

    int WeaponBinding::newindex(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);

        Weapon* m = getW(L, 1);
        if (!m) return luaL_error(L, "Weapon is nil");

        // Writeable fields
        
        // --- float members ---
        LUA_SET_FLOAT_MEMBER(bleedDamage);
        LUA_SET_FLOAT_MEMBER(combatWeight);
        // --- integer members ---
        LUA_SET_INT_MEMBER(modAttack);
        // --- enum members ---
        LUA_SET_ENUM_MEMBER(category, WeaponCategory);
        LUA_SET_ENUM_MEMBER(category_animationOverride, WeaponCategory);

        return GearBinding::newindex(L);
    }

    int WeaponBinding::is2HandedOnly(lua_State* L)
    {
        Weapon* w = getW(L, 1);
        lua_pushboolean(L, w && w->is2HandedOnly() ? 1 : 0);
        return 1;
    }

    void WeaponBinding::registerBinding(lua_State* L)
    {
        static const luaL_Reg metamethods[] = {
            { "__gc", WeaponBinding::gc },
            { "__tostring", WeaponBinding::tostring },
            { 0, 0 }
        };

        static const luaL_Reg methods[] = {
            { "is2HandedOnly", WeaponBinding::is2HandedOnly },
            { 0, 0 }
        };

        registerClass(
            L,
            WeaponBinding::getMetatableName(),
            metamethods,
            methods,
            WeaponBinding::index,
            WeaponBinding::newindex
        );
    }

    // ------------------------------------------
    // class Sword : public Weapon
    // ------------------------------------------

    static Sword* getS(lua_State* L, int idx)
    {
        Sword* s = testObject<Sword>(L, idx, SwordBinding::getMetatableName());
        if (s) return s;
        luaL_argerror(L, idx, "Sword");
        return nullptr;
    }

    int SwordBinding::gc(lua_State* L) { return noopGc(L); }

    int SwordBinding::tostring(lua_State* L)
    {
        Sword* m = getS(L, 1);
        if (!m) { lua_pushstring(L, "Sword:nil"); return 1; }
        char buf[160];
        _snprintf(buf, sizeof(buf), "Sword:%s(%p)", m->isValid() ? m->getName().c_str() : "?", (void*)m);
        lua_pushstring(L, buf);
        return 1;
    }

    int SwordBinding::index(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);

        // 1. Check the metatable first so obj:method() syntax continues to work.
        luaL_getmetatable(L, SwordBinding::getMetatableName());
        lua_getfield(L, -1, key);
        if (!lua_isnil(L, -1))
            return 1;   // found a method — return it
        lua_pop(L, 2);  // pop nil result + metatable

        // 2. Fall through to raw member variable access.
        Sword* m = getS(L, 1);
        if (!m) { lua_pushnil(L); return 1; }

        // Readable fields
        
        // --- float members ---
        LUA_GET_FLOAT_MEMBER(cutDamage);
        LUA_GET_FLOAT_MEMBER(bluntDamage);
        LUA_GET_FLOAT_MEMBER(minCutDamage);
        // --- integer members ---
        LUA_GET_INT_MEMBER(modDefence);
        LUA_GET_INT_MEMBER(modIndoors);

        // Fallback to Weapon
        return WeaponBinding::index(L);
    }

    int SwordBinding::newindex(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);

        Sword* m = getS(L, 1);
        if (!m) return luaL_error(L, "Sword is nil");

        // Writeable fields

        // --- float members ---
        LUA_SET_FLOAT_MEMBER(cutDamage);
        LUA_SET_FLOAT_MEMBER(bluntDamage);
        LUA_SET_FLOAT_MEMBER(minCutDamage);
        // --- integer members ---
        LUA_SET_INT_MEMBER(modDefence);
        LUA_SET_INT_MEMBER(modIndoors);

        return WeaponBinding::newindex(L);
    }

    int SwordBinding::getClassType(lua_State* L) { Sword* m = getS(L, 1); lua_pushinteger(L, (int)m->getClassType()); return 1; }

    void SwordBinding::registerBinding(lua_State* L)
    {
        static const luaL_Reg metamethods[] = {
            { "__gc", SwordBinding::gc },
            { "__tostring", SwordBinding::tostring },
            { 0, 0 }
        };

        static const luaL_Reg methods[] = {
            { "getClassType",   SwordBinding::getClassType },
            { 0, 0 }
        };

        registerClass(
            L,
            SwordBinding::getMetatableName(),
            metamethods,
            methods,
            SwordBinding::index,
            SwordBinding::newindex
        );
    }
    // ------------------------------------------

    void ArmourEnumBinding::registerArmourClass(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, ArmourClass::GEAR_CLOTH);
        lua_setfield(L, -2, "GEAR_CLOTH");

        lua_pushinteger(L, ArmourClass::GEAR_LIGHT);
        lua_setfield(L, -2, "GEAR_LIGHT");

        lua_pushinteger(L, ArmourClass::GEAR_MEDIUM);
        lua_setfield(L, -2, "GEAR_MEDIUM");

        lua_pushinteger(L, ArmourClass::GEAR_HEAVY);
        lua_setfield(L, -2, "GEAR_HEAVY");

        lua_pushinteger(L, ArmourClass::GEAR_MAX);
        lua_setfield(L, -2, "GEAR_MAX");

        lua_pushinteger(L, ArmourClass::GEAR_CLOTH);
        lua_setfield(L, -2, "CLOTH");

        lua_pushinteger(L, ArmourClass::GEAR_LIGHT);
        lua_setfield(L, -2, "LIGHT");

        lua_pushinteger(L, ArmourClass::GEAR_MEDIUM);
        lua_setfield(L, -2, "MEDIUM");

        lua_pushinteger(L, ArmourClass::GEAR_HEAVY);
        lua_setfield(L, -2, "HEAVY");

        lua_pushinteger(L, ArmourClass::GEAR_MAX);
        lua_setfield(L, -2, "MAX");

        lua_setglobal(L, "ArmourClass");
    }

    // ------------------------------------------
    // class Armour : public Gear
    // ------------------------------------------

    static Armour* getA(lua_State* L, int idx)
    {
        Armour* a = testObject<Armour>(L, idx, ArmourBinding::getMetatableName());
        if (a) return a;
        a = (Armour*)testObject<LockedArmour>(L, idx, LockedArmourBinding::getMetatableName());
        if (a) return a;
        luaL_argerror(L, idx, "Armour");
        return nullptr;
    }

    int ArmourBinding::gc(lua_State* L) { return noopGc(L); }

    int ArmourBinding::tostring(lua_State* L)
    {
        Armour* m = getA(L, 1);
        if (!m) { lua_pushstring(L, "Armour:nil"); return 1; }
        char buf[160];
        _snprintf(buf, sizeof(buf), "Armour:%s(%p)", m->isValid() ? m->getName().c_str() : "?", (void*)m);
        lua_pushstring(L, buf);
        return 1;
    }

    int ArmourBinding::index(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);

        // 1. Check metatable
        luaL_getmetatable(L, ArmourBinding::getMetatableName());
        lua_getfield(L, -1, key);
        if (!lua_isnil(L, -1))
            return 1;
        lua_pop(L, 2);

        // 2. Raw fields
        Armour* m = getA(L, 1);
        if (!m) { lua_pushnil(L); return 1; }

        LUA_GET_FLOAT_MEMBER(cutResistance);
        LUA_GET_FLOAT_MEMBER(bluntResistance);
        LUA_GET_FLOAT_MEMBER(pierceResistance);
        LUA_GET_FLOAT_MEMBER(minCutResistance);
        LUA_GET_FLOAT_MEMBER(cutToStun);
        LUA_GET_FLOAT_MEMBER(athleticsMult);
        LUA_GET_FLOAT_MEMBER(combatSpeedMult);
        LUA_GET_FLOAT_MEMBER(stealthMult);
        LUA_GET_FLOAT_MEMBER(assassinMult);
        LUA_GET_FLOAT_MEMBER(dexterityMult);
        LUA_GET_FLOAT_MEMBER(damageMult);
        LUA_GET_FLOAT_MEMBER(dodgeMult);
        LUA_GET_FLOAT_MEMBER(weatherProtectionAmount);
        LUA_GET_FLOAT_MEMBER(rangedSkillMult);
        LUA_GET_FLOAT_MEMBER(craftTime);

        LUA_GET_INT_MEMBER(combatSkillBonusAttk);
        LUA_GET_INT_MEMBER(combatSkillBonusDef);
        LUA_GET_INT_MEMBER(perceptionBonus);
        LUA_GET_INT_MEMBER(unarmedBonus);
        LUA_GET_FLOAT_MEMBER(fistInjuryMult);

        LUA_GET_ENUM_MEMBER(materialType, ArmourType);
        LUA_GET_ENUM_MEMBER(armourClassEnum, ArmourClass);
        LUA_GET_ENUM_MEMBER(stigma, CharacterTypeEnum);

        // Fallback to Gear
        return GearBinding::index(L);
    }

    int ArmourBinding::newindex(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);

        Armour* m = getA(L, 1);
        if (!m) return luaL_error(L, "Armour is nil");

        LUA_SET_FLOAT_MEMBER(cutResistance);
        LUA_SET_FLOAT_MEMBER(bluntResistance);
        LUA_SET_FLOAT_MEMBER(pierceResistance);
        LUA_SET_FLOAT_MEMBER(minCutResistance);
        LUA_SET_FLOAT_MEMBER(cutToStun);
        LUA_SET_FLOAT_MEMBER(athleticsMult);
        LUA_SET_FLOAT_MEMBER(combatSpeedMult);
        LUA_SET_FLOAT_MEMBER(stealthMult);
        LUA_SET_FLOAT_MEMBER(assassinMult);
        LUA_SET_FLOAT_MEMBER(dexterityMult);
        LUA_SET_FLOAT_MEMBER(damageMult);
        LUA_SET_FLOAT_MEMBER(dodgeMult);
        LUA_SET_FLOAT_MEMBER(weatherProtectionAmount);
        LUA_SET_FLOAT_MEMBER(rangedSkillMult);
        LUA_SET_FLOAT_MEMBER(craftTime);

        LUA_SET_INT_MEMBER(combatSkillBonusAttk);
        LUA_SET_INT_MEMBER(combatSkillBonusDef);
        LUA_SET_INT_MEMBER(perceptionBonus);
        LUA_SET_INT_MEMBER(unarmedBonus);
        LUA_SET_FLOAT_MEMBER(fistInjuryMult);

        LUA_SET_ENUM_MEMBER(materialType, ArmourType);
        LUA_SET_ENUM_MEMBER(armourClassEnum, ArmourClass);
        LUA_SET_ENUM_MEMBER(stigma, CharacterTypeEnum);

        return GearBinding::newindex(L);
    }

    int ArmourBinding::getClassType(lua_State* L)
    {
        Armour* m = getA(L, 1);
        lua_pushinteger(L, (int)m->getClassType());
        return 1;
    }

    int ArmourBinding::isArmour(lua_State* L)
    {
        Armour* m = getA(L, 1);
        lua_pushboolean(L, m && m->isArmour() ? 1 : 0);
        return 1;
    }

    int ArmourBinding::getItemWeight(lua_State* L)
    {
        Armour* m = getA(L, 1);
        lua_pushnumber(L, m->getItemWeight());
        return 1;
    }

    int ArmourBinding::getValueSingle(lua_State* L)
    {
        Armour* m = getA(L, 1);
        bool isPlayer = lua_isnoneornil(L, 2) ? true : (lua_toboolean(L, 2) != 0);
        lua_pushinteger(L, m->getValueSingle(isPlayer));
        return 1;
    }

    int ArmourBinding::hasArmourCoverage(lua_State* L)
    {
        Armour* m = getA(L, 1);
        lua_pushboolean(L, m && m->hasArmourCoverage() ? 1 : 0);
        return 1;
    }

    int ArmourBinding::getCraftTime(lua_State* L)
    {
        Armour* m = getA(L, 1);
        lua_pushnumber(L, m->getCraftTime());
        return 1;
    }

    int ArmourBinding::getWeatherProtection_simple(lua_State* L)
    {
        Armour* m = getA(L, 1);
        WeatherAffecting w = (WeatherAffecting)luaL_checkinteger(L, 2);
        lua_pushnumber(L, m->getWeatherProtection_simple(w));
        return 1;
    }

    void ArmourBinding::registerBinding(lua_State* L)
    {
        static const luaL_Reg metamethods[] = {
            { "__gc", ArmourBinding::gc },
            { "__tostring", ArmourBinding::tostring },
            { 0, 0 }
        };

        static const luaL_Reg methods[] = {
            { "getClassType", ArmourBinding::getClassType },
            { "isArmour", ArmourBinding::isArmour },
            { "getItemWeight", ArmourBinding::getItemWeight },
            { "getValueSingle", ArmourBinding::getValueSingle },
            { "hasArmourCoverage", ArmourBinding::hasArmourCoverage },
            { "getCraftTime", ArmourBinding::getCraftTime },
            { "getWeatherProtection_simple", ArmourBinding::getWeatherProtection_simple },
            { 0, 0 }
        };

        registerClass(
            L,
            ArmourBinding::getMetatableName(),
            metamethods,
            methods,
            ArmourBinding::index,
            ArmourBinding::newindex
        );
    }

    // ------------------------------------------
    // class LockedArmour : public Armour
    // ------------------------------------------

    static LockedArmour* getLA(lua_State* L, int idx)
    {
        LockedArmour* la = testObject<LockedArmour>(L, idx, LockedArmourBinding::getMetatableName());
        if (la) return la;
        luaL_argerror(L, idx, "LockedArmour");
        return nullptr;
    }

    int LockedArmourBinding::gc(lua_State* L) { return noopGc(L); }

    int LockedArmourBinding::tostring(lua_State* L)
    {
        LockedArmour* m = getLA(L, 1);
        if (!m) { lua_pushstring(L, "LockedArmour:nil"); return 1; }
        char buf[160];
        _snprintf(buf, sizeof(buf), "LockedArmour:%s(%p)", m->isValid() ? m->getName().c_str() : "?", (void*)m);
        lua_pushstring(L, buf);
        return 1;
    }

    int LockedArmourBinding::index(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);

        luaL_getmetatable(L, LockedArmourBinding::getMetatableName());
        lua_getfield(L, -1, key);
        if (!lua_isnil(L, -1))
            return 1;
        lua_pop(L, 2);

        LockedArmour* m = getLA(L, 1);
        if (!m) { lua_pushnil(L); return 1; }

        // Fallback to Armour
        return ArmourBinding::index(L);
    }

    int LockedArmourBinding::newindex(lua_State* L)
    {
        LockedArmour* m = getLA(L, 1);
        if (!m) return luaL_error(L, "LockedArmour is nil");

        return ArmourBinding::newindex(L);
    }

    int LockedArmourBinding::isLockedArmour(lua_State* L)
    {
        LockedArmour* m = getLA(L, 1);
        lua_pushboolean(L, m && m->isLockedArmour() ? 1 : 0);
        return 1;
    }

    void LockedArmourBinding::registerBinding(lua_State* L)
    {
        static const luaL_Reg metamethods[] = {
            { "__gc", LockedArmourBinding::gc },
            { "__tostring", LockedArmourBinding::tostring },
            { 0, 0 }
        };

        static const luaL_Reg methods[] = {
            { "isLockedArmour", LockedArmourBinding::isLockedArmour },
            { 0, 0 }
        };

        registerClass(
            L,
            LockedArmourBinding::getMetatableName(),
            metamethods,
            methods,
            LockedArmourBinding::index,
            LockedArmourBinding::newindex
        );
    }

    // ------------------------------------------
    // class Crossbow : public Weapon
    // ------------------------------------------

    static Crossbow* getX(lua_State* L, int idx)
    {
        Crossbow* x = testObject<Crossbow>(L, idx, CrossbowBinding::getMetatableName());
        if (x) return x;
        luaL_argerror(L, idx, "Crossbow");
        return nullptr;
    }

    int CrossbowBinding::gc(lua_State* L) { return noopGc(L); }

    int CrossbowBinding::tostring(lua_State* L)
    {
        Crossbow* m = getX(L, 1);
        if (!m) { lua_pushstring(L, "Crossbow:nil"); return 1; }
        char buf[160];
        _snprintf(buf, sizeof(buf), "Crossbow:%s(%p)", m->isValid() ? m->getName().c_str() : "?", (void*)m);
        lua_pushstring(L, buf);
        return 1;
    }

    int CrossbowBinding::index(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);

        luaL_getmetatable(L, CrossbowBinding::getMetatableName());
        lua_getfield(L, -1, key);
        if (!lua_isnil(L, -1))
            return 1;
        lua_pop(L, 2);

        Crossbow* m = getX(L, 1);
        if (!m) { lua_pushnil(L); return 1; }

        // Fallback to Weapon
        return WeaponBinding::index(L);
    }

    int CrossbowBinding::newindex(lua_State* L)
    {
        Crossbow* m = getX(L, 1);
        if (!m) return luaL_error(L, "Crossbow is nil");

        return WeaponBinding::newindex(L);
    }

    int CrossbowBinding::getClassType(lua_State* L)
    {
        Crossbow* m = getX(L, 1);
        lua_pushinteger(L, (int)m->getClassType());
        return 1;
    }

    void CrossbowBinding::registerBinding(lua_State* L)
    {
        static const luaL_Reg metamethods[] = {
            { "__gc", CrossbowBinding::gc },
            { "__tostring", CrossbowBinding::tostring },
            { 0, 0 }
        };

        static const luaL_Reg methods[] = {
            { "getClassType", CrossbowBinding::getClassType },
            { 0, 0 }
        };

        registerClass(
            L,
            CrossbowBinding::getMetatableName(),
            metamethods,
            methods,
            CrossbowBinding::index,
            CrossbowBinding::newindex
        );
    }
}
=======
    Gear* result = b->_CONSTRUCTOR(baseData, companyData, materialData, *_handle, _level, uniform);
    return pushObject<Gear>(L, result, GearBinding::getMetatableName());
}

int GearBinding::_serialise(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    itemType type = (itemType)luaL_checkinteger(L, 3);
    GameData* result = b->_serialise(container, type);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int GearBinding::_NV__serialise(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    itemType type = (itemType)luaL_checkinteger(L, 3);
    GameData* result = b->_NV__serialise(container, type);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int GearBinding::_loadFromSerialise(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* state = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    b->_loadFromSerialise(container, state);
    return 0;
}

int GearBinding::_NV__loadFromSerialise(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* state = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    b->_NV__loadFromSerialise(container, state);
    return 0;
}

int GearBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int GearBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Gear object");
    return 1;
}

void GearBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GearBinding::gc },
        { "__tostring", GearBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "isGear", GearBinding::isGear },
        { "_NV_isGear", GearBinding::_NV_isGear },
        { "getLevel01", GearBinding::getLevel01 },
        { "_NV_getLevel01", GearBinding::_NV_getLevel01 },
        { "getLevel", GearBinding::getLevel },
        { "_NV_getLevel", GearBinding::_NV_getLevel },
        { "isAFactionUniform", GearBinding::isAFactionUniform },
        { "_NV_isAFactionUniform", GearBinding::_NV_isAFactionUniform },
        { "isPlayerCrafted", GearBinding::isPlayerCrafted },
        { "_DESTRUCTOR", GearBinding::_DESTRUCTOR },
        { "setInventoryWeAreIn", GearBinding::setInventoryWeAreIn },
        { "_NV_setInventoryWeAreIn", GearBinding::_NV_setInventoryWeAreIn },
        { "_CONSTRUCTOR", GearBinding::_CONSTRUCTOR },
        { "_serialise", GearBinding::_serialise },
        { "_NV__serialise", GearBinding::_NV__serialise },
        { "_loadFromSerialise", GearBinding::_loadFromSerialise },
        { "_NV__loadFromSerialise", GearBinding::_NV__loadFromSerialise },
        { 0, 0 }
    };

    registerClass(
        L, 
        GearBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, GearBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, Gear_get_isUniform);
    lua_setfield(L, -2, "isUniform");
    lua_pushcfunction(L, Gear_get_value);
    lua_setfield(L, -2, "value");
    lua_pushcfunction(L, Gear_get_crafter);
    lua_setfield(L, -2, "crafter");
    lua_pushcfunction(L, Gear_get_level);
    lua_setfield(L, -2, "level");
    lua_pushcfunction(L, Gear_get_level_0_100);
    lua_setfield(L, -2, "level_0_100");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, Gear_set_isUniform);
    lua_setfield(L, -2, "isUniform");
    lua_pushcfunction(L, Gear_set_value);
    lua_setfield(L, -2, "value");
    lua_pushcfunction(L, Gear_set_crafter);
    lua_setfield(L, -2, "crafter");
    lua_pushcfunction(L, Gear_set_level);
    lua_setfield(L, -2, "level");
    lua_pushcfunction(L, Gear_set_level_0_100);
    lua_setfield(L, -2, "level_0_100");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
>>>>>>> main:src/Bindings/GearBinding.cpp
