#include "pch.h"
#include "kenshi\Gear.h"
#include "ArmourBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static Armour* getB(lua_State* L, int idx)
{
    return checkObject<Armour>(L, idx, ArmourBinding::getMetatableName());
}

// --- Getters for Armour ---
static int Armour_get_cutResistance(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, b->cutResistance);
    return 1;
}

static int Armour_get_bluntResistance(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, b->bluntResistance);
    return 1;
}

static int Armour_get_pierceResistance(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, b->pierceResistance);
    return 1;
}

static int Armour_get_minCutResistance(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, b->minCutResistance);
    return 1;
}

static int Armour_get_cutToStun(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, b->cutToStun);
    return 1;
}

static int Armour_get_materialType(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    lua_pushinteger(L, (lua_Integer)b->materialType);
    return 1;
}

static int Armour_get_armourClassEnum(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    // TODO: Unsupported type for armourClassEnum (ArmourClass)
    return luaL_error(L, "Unsupported property 'armourClassEnum' (type: ArmourClass)");
}

static int Armour_get_stigma(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    // TODO: Unsupported type for stigma (CharacterTypeEnum)
    return luaL_error(L, "Unsupported property 'stigma' (type: CharacterTypeEnum)");
}

static int Armour_get_athleticsMult(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, b->athleticsMult);
    return 1;
}

static int Armour_get_combatSkillBonusAttk(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    lua_pushinteger(L, b->combatSkillBonusAttk);
    return 1;
}

static int Armour_get_combatSkillBonusDef(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    lua_pushinteger(L, b->combatSkillBonusDef);
    return 1;
}

static int Armour_get_perceptionBonus(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    lua_pushinteger(L, b->perceptionBonus);
    return 1;
}

static int Armour_get_combatSpeedMult(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, b->combatSpeedMult);
    return 1;
}

static int Armour_get_stealthMult(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, b->stealthMult);
    return 1;
}

static int Armour_get_assassinMult(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, b->assassinMult);
    return 1;
}

static int Armour_get_dexterityMult(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, b->dexterityMult);
    return 1;
}

static int Armour_get_damageMult(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, b->damageMult);
    return 1;
}

static int Armour_get_dodgeMult(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, b->dodgeMult);
    return 1;
}

static int Armour_get_unarmedBonus(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    lua_pushinteger(L, b->unarmedBonus);
    return 1;
}

static int Armour_get_fistInjuryMult(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, b->fistInjuryMult);
    return 1;
}

static int Armour_get_weatherProtectionAmount(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, b->weatherProtectionAmount);
    return 1;
}

static int Armour_get_rangedSkillMult(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, b->rangedSkillMult);
    return 1;
}

static int Armour_get_weatherProtections(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    // TODO: Unsupported type for weatherProtections (std::set<WeatherAffecting, std::less<WeatherAffecting>, Ogre::STLAllocator<WeatherAffecting, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'weatherProtections' (type: std::set<WeatherAffecting, std::less<WeatherAffecting>, Ogre::STLAllocator<WeatherAffecting, Ogre::GeneralAllocPolicy > >)");
}

static int Armour_get_bodypartCoverage(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    // TODO: Unsupported type for bodypartCoverage (ogre_unordered_map<GameData*, float>::type)
    return luaL_error(L, "Unsupported property 'bodypartCoverage' (type: ogre_unordered_map<GameData*, float>::type)");
}

static int Armour_get_craftTime(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, b->craftTime);
    return 1;
}

// --- Setters for Armour ---
static int Armour_set_cutResistance(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    b->cutResistance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_bluntResistance(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    b->bluntResistance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_pierceResistance(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    b->pierceResistance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_minCutResistance(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    b->minCutResistance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_cutToStun(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    b->cutToStun = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_materialType(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    b->materialType = (ArmourType)luaL_checkinteger(L, 2);
    return 0;
}

static int Armour_set_armourClassEnum(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    return luaL_error(L, "Read-only or unsupported setter type for armourClassEnum");
}

static int Armour_set_stigma(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    return luaL_error(L, "Read-only or unsupported setter type for stigma");
}

static int Armour_set_athleticsMult(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    b->athleticsMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_combatSkillBonusAttk(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    b->combatSkillBonusAttk = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Armour_set_combatSkillBonusDef(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    b->combatSkillBonusDef = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Armour_set_perceptionBonus(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    b->perceptionBonus = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Armour_set_combatSpeedMult(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    b->combatSpeedMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_stealthMult(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    b->stealthMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_assassinMult(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    b->assassinMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_dexterityMult(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    b->dexterityMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_damageMult(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    b->damageMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_dodgeMult(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    b->dodgeMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_unarmedBonus(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    b->unarmedBonus = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Armour_set_fistInjuryMult(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    b->fistInjuryMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_weatherProtectionAmount(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    b->weatherProtectionAmount = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_rangedSkillMult(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    b->rangedSkillMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_weatherProtections(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    return luaL_error(L, "Read-only or unsupported setter type for weatherProtections");
}

static int Armour_set_bodypartCoverage(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    return luaL_error(L, "Read-only or unsupported setter type for bodypartCoverage");
}

static int Armour_set_craftTime(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");
    b->craftTime = (float)luaL_checknumber(L, 2);
    return 0;
}

int ArmourBinding::getClassType(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");

    itemType result = b->getClassType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ArmourBinding::_NV_getClassType(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");

    itemType result = b->_NV_getClassType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ArmourBinding::isArmour(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");

    Armour* result = b->isArmour();
    return pushObject<Armour>(L, result, ArmourBinding::getMetatableName());
}

int ArmourBinding::_NV_isArmour(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");

    Armour* result = b->_NV_isArmour();
    return pushObject<Armour>(L, result, ArmourBinding::getMetatableName());
}

int ArmourBinding::getItemWeight(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");

    float result = b->getItemWeight();
    lua_pushnumber(L, result);
    return 1;
}

int ArmourBinding::_NV_getItemWeight(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");

    float result = b->_NV_getItemWeight();
    lua_pushnumber(L, result);
    return 1;
}

int ArmourBinding::getValueSingle(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");

    bool isPlayer = lua_toboolean(L, 2) != 0;
    int result = b->getValueSingle(isPlayer);
    lua_pushinteger(L, result);
    return 1;
}

int ArmourBinding::_NV_getValueSingle(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");

    bool isPlayer = lua_toboolean(L, 2) != 0;
    int result = b->_NV_getValueSingle(isPlayer);
    lua_pushinteger(L, result);
    return 1;
}

int ArmourBinding::hasArmourCoverage(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");

    bool result = b->hasArmourCoverage();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ArmourBinding::getCraftTime(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");

    float result = b->getCraftTime();
    lua_pushnumber(L, result);
    return 1;
}

int ArmourBinding::_NV_getCraftTime(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");

    float result = b->_NV_getCraftTime();
    lua_pushnumber(L, result);
    return 1;
}

int ArmourBinding::getWeatherProtection_simple(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");

    WeatherAffecting weather = (WeatherAffecting)luaL_checkinteger(L, 2);
    float result = b->getWeatherProtection_simple(weather);
    lua_pushnumber(L, result);
    return 1;
}

int ArmourBinding::_DESTRUCTOR(lua_State* L)
{
    Armour* b = getB(L, 1);
    if (!b) return luaL_error(L, "Armour is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 168: void getTooltipData1(...) - unsupported arg type
  line 169: void _NV_getTooltipData1(...) - unsupported arg type
  line 170: void getTooltipData2(...) - unsupported arg type
  line 171: void _NV_getTooltipData2(...) - unsupported arg type
  line 172: bool didIHitFlesh(...) - unsupported arg type
  line 176: float getArmourCraftingMaterialConsumptionRate(...) - static method
  line 204: Armour* _CONSTRUCTOR(...) - unsupported arg type
*/

int ArmourBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ArmourBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Armour object");
    return 1;
}

void ArmourBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ArmourBinding::gc },
        { "__tostring", ArmourBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getClassType", ArmourBinding::getClassType },
        { "_NV_getClassType", ArmourBinding::_NV_getClassType },
        { "isArmour", ArmourBinding::isArmour },
        { "_NV_isArmour", ArmourBinding::_NV_isArmour },
        { "getItemWeight", ArmourBinding::getItemWeight },
        { "_NV_getItemWeight", ArmourBinding::_NV_getItemWeight },
        { "getValueSingle", ArmourBinding::getValueSingle },
        { "_NV_getValueSingle", ArmourBinding::_NV_getValueSingle },
        { "hasArmourCoverage", ArmourBinding::hasArmourCoverage },
        { "getCraftTime", ArmourBinding::getCraftTime },
        { "_NV_getCraftTime", ArmourBinding::_NV_getCraftTime },
        { "getWeatherProtection_simple", ArmourBinding::getWeatherProtection_simple },
        { "_DESTRUCTOR", ArmourBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        ArmourBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ArmourBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, Armour_get_cutResistance);
    lua_setfield(L, -2, "cutResistance");
    lua_pushcfunction(L, Armour_get_bluntResistance);
    lua_setfield(L, -2, "bluntResistance");
    lua_pushcfunction(L, Armour_get_pierceResistance);
    lua_setfield(L, -2, "pierceResistance");
    lua_pushcfunction(L, Armour_get_minCutResistance);
    lua_setfield(L, -2, "minCutResistance");
    lua_pushcfunction(L, Armour_get_cutToStun);
    lua_setfield(L, -2, "cutToStun");
    lua_pushcfunction(L, Armour_get_materialType);
    lua_setfield(L, -2, "materialType");
    lua_pushcfunction(L, Armour_get_armourClassEnum);
    lua_setfield(L, -2, "armourClassEnum");
    lua_pushcfunction(L, Armour_get_stigma);
    lua_setfield(L, -2, "stigma");
    lua_pushcfunction(L, Armour_get_athleticsMult);
    lua_setfield(L, -2, "athleticsMult");
    lua_pushcfunction(L, Armour_get_combatSkillBonusAttk);
    lua_setfield(L, -2, "combatSkillBonusAttk");
    lua_pushcfunction(L, Armour_get_combatSkillBonusDef);
    lua_setfield(L, -2, "combatSkillBonusDef");
    lua_pushcfunction(L, Armour_get_perceptionBonus);
    lua_setfield(L, -2, "perceptionBonus");
    lua_pushcfunction(L, Armour_get_combatSpeedMult);
    lua_setfield(L, -2, "combatSpeedMult");
    lua_pushcfunction(L, Armour_get_stealthMult);
    lua_setfield(L, -2, "stealthMult");
    lua_pushcfunction(L, Armour_get_assassinMult);
    lua_setfield(L, -2, "assassinMult");
    lua_pushcfunction(L, Armour_get_dexterityMult);
    lua_setfield(L, -2, "dexterityMult");
    lua_pushcfunction(L, Armour_get_damageMult);
    lua_setfield(L, -2, "damageMult");
    lua_pushcfunction(L, Armour_get_dodgeMult);
    lua_setfield(L, -2, "dodgeMult");
    lua_pushcfunction(L, Armour_get_unarmedBonus);
    lua_setfield(L, -2, "unarmedBonus");
    lua_pushcfunction(L, Armour_get_fistInjuryMult);
    lua_setfield(L, -2, "fistInjuryMult");
    lua_pushcfunction(L, Armour_get_weatherProtectionAmount);
    lua_setfield(L, -2, "weatherProtectionAmount");
    lua_pushcfunction(L, Armour_get_rangedSkillMult);
    lua_setfield(L, -2, "rangedSkillMult");
    lua_pushcfunction(L, Armour_get_weatherProtections);
    lua_setfield(L, -2, "weatherProtections");
    lua_pushcfunction(L, Armour_get_bodypartCoverage);
    lua_setfield(L, -2, "bodypartCoverage");
    lua_pushcfunction(L, Armour_get_craftTime);
    lua_setfield(L, -2, "craftTime");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, Armour_set_cutResistance);
    lua_setfield(L, -2, "cutResistance");
    lua_pushcfunction(L, Armour_set_bluntResistance);
    lua_setfield(L, -2, "bluntResistance");
    lua_pushcfunction(L, Armour_set_pierceResistance);
    lua_setfield(L, -2, "pierceResistance");
    lua_pushcfunction(L, Armour_set_minCutResistance);
    lua_setfield(L, -2, "minCutResistance");
    lua_pushcfunction(L, Armour_set_cutToStun);
    lua_setfield(L, -2, "cutToStun");
    lua_pushcfunction(L, Armour_set_materialType);
    lua_setfield(L, -2, "materialType");
    lua_pushcfunction(L, Armour_set_armourClassEnum);
    lua_setfield(L, -2, "armourClassEnum");
    lua_pushcfunction(L, Armour_set_stigma);
    lua_setfield(L, -2, "stigma");
    lua_pushcfunction(L, Armour_set_athleticsMult);
    lua_setfield(L, -2, "athleticsMult");
    lua_pushcfunction(L, Armour_set_combatSkillBonusAttk);
    lua_setfield(L, -2, "combatSkillBonusAttk");
    lua_pushcfunction(L, Armour_set_combatSkillBonusDef);
    lua_setfield(L, -2, "combatSkillBonusDef");
    lua_pushcfunction(L, Armour_set_perceptionBonus);
    lua_setfield(L, -2, "perceptionBonus");
    lua_pushcfunction(L, Armour_set_combatSpeedMult);
    lua_setfield(L, -2, "combatSpeedMult");
    lua_pushcfunction(L, Armour_set_stealthMult);
    lua_setfield(L, -2, "stealthMult");
    lua_pushcfunction(L, Armour_set_assassinMult);
    lua_setfield(L, -2, "assassinMult");
    lua_pushcfunction(L, Armour_set_dexterityMult);
    lua_setfield(L, -2, "dexterityMult");
    lua_pushcfunction(L, Armour_set_damageMult);
    lua_setfield(L, -2, "damageMult");
    lua_pushcfunction(L, Armour_set_dodgeMult);
    lua_setfield(L, -2, "dodgeMult");
    lua_pushcfunction(L, Armour_set_unarmedBonus);
    lua_setfield(L, -2, "unarmedBonus");
    lua_pushcfunction(L, Armour_set_fistInjuryMult);
    lua_setfield(L, -2, "fistInjuryMult");
    lua_pushcfunction(L, Armour_set_weatherProtectionAmount);
    lua_setfield(L, -2, "weatherProtectionAmount");
    lua_pushcfunction(L, Armour_set_rangedSkillMult);
    lua_setfield(L, -2, "rangedSkillMult");
    lua_pushcfunction(L, Armour_set_weatherProtections);
    lua_setfield(L, -2, "weatherProtections");
    lua_pushcfunction(L, Armour_set_bodypartCoverage);
    lua_setfield(L, -2, "bodypartCoverage");
    lua_pushcfunction(L, Armour_set_craftTime);
    lua_setfield(L, -2, "craftTime");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua