#include "pch.h"
#include "kenshi\Gear.h"
#include "ArmourBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GearBinding.h"
#include "Bindings/EnumBinding.h"

namespace KenshiLua
{

static Armour* getInstance(lua_State* L, int idx)
{
    return checkObject<Armour>(L, idx, ArmourBinding::getMetatableName());
}

// --- Getters for Armour ---
static int Armour_get_cutResistance(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, instance->cutResistance);
    return 1;
}

static int Armour_get_bluntResistance(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, instance->bluntResistance);
    return 1;
}

static int Armour_get_pierceResistance(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, instance->pierceResistance);
    return 1;
}

static int Armour_get_minCutResistance(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, instance->minCutResistance);
    return 1;
}

static int Armour_get_cutToStun(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, instance->cutToStun);
    return 1;
}

static int Armour_get_materialType(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    lua_pushinteger(L, (lua_Integer)instance->materialType);
    return 1;
}

static int Armour_get_athleticsMult(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, instance->athleticsMult);
    return 1;
}

static int Armour_get_combatSkillBonusAttk(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    lua_pushinteger(L, instance->combatSkillBonusAttk);
    return 1;
}

static int Armour_get_combatSkillBonusDef(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    lua_pushinteger(L, instance->combatSkillBonusDef);
    return 1;
}

static int Armour_get_perceptionBonus(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    lua_pushinteger(L, instance->perceptionBonus);
    return 1;
}

static int Armour_get_combatSpeedMult(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, instance->combatSpeedMult);
    return 1;
}

static int Armour_get_stealthMult(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, instance->stealthMult);
    return 1;
}

static int Armour_get_assassinMult(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, instance->assassinMult);
    return 1;
}

static int Armour_get_dexterityMult(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, instance->dexterityMult);
    return 1;
}

static int Armour_get_damageMult(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, instance->damageMult);
    return 1;
}

static int Armour_get_dodgeMult(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, instance->dodgeMult);
    return 1;
}

static int Armour_get_unarmedBonus(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    lua_pushinteger(L, instance->unarmedBonus);
    return 1;
}

static int Armour_get_fistInjuryMult(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, instance->fistInjuryMult);
    return 1;
}

static int Armour_get_weatherProtectionAmount(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, instance->weatherProtectionAmount);
    return 1;
}

static int Armour_get_rangedSkillMult(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, instance->rangedSkillMult);
    return 1;
}

static int Armour_get_craftTime(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    lua_pushnumber(L, instance->craftTime);
    return 1;
}

// --- Setters for Armour ---
static int Armour_set_cutResistance(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    instance->cutResistance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_bluntResistance(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    instance->bluntResistance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_pierceResistance(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    instance->pierceResistance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_minCutResistance(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    instance->minCutResistance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_cutToStun(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    instance->cutToStun = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_materialType(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    instance->materialType = (ArmourType)luaL_checkinteger(L, 2);
    return 0;
}

static int Armour_set_athleticsMult(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    instance->athleticsMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_combatSkillBonusAttk(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    instance->combatSkillBonusAttk = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Armour_set_combatSkillBonusDef(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    instance->combatSkillBonusDef = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Armour_set_perceptionBonus(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    instance->perceptionBonus = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Armour_set_combatSpeedMult(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    instance->combatSpeedMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_stealthMult(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    instance->stealthMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_assassinMult(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    instance->assassinMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_dexterityMult(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    instance->dexterityMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_damageMult(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    instance->damageMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_dodgeMult(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    instance->dodgeMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_unarmedBonus(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    instance->unarmedBonus = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Armour_set_fistInjuryMult(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    instance->fistInjuryMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_weatherProtectionAmount(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    instance->weatherProtectionAmount = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_rangedSkillMult(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    instance->rangedSkillMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Armour_set_craftTime(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    instance->craftTime = (float)luaL_checknumber(L, 2);
    return 0;
}

int ArmourBinding::getClassType(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");

    itemType result = instance->getClassType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ArmourBinding::_NV_getClassType(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");

    itemType result = instance->_NV_getClassType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ArmourBinding::isArmour(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");

    Armour* result = instance->isArmour();
    return pushObject<Armour>(L, result, ArmourBinding::getMetatableName());
}

int ArmourBinding::_NV_isArmour(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");

    Armour* result = instance->_NV_isArmour();
    return pushObject<Armour>(L, result, ArmourBinding::getMetatableName());
}

int ArmourBinding::getItemWeight(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");

    float result = instance->getItemWeight();
    lua_pushnumber(L, result);
    return 1;
}

int ArmourBinding::_NV_getItemWeight(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");

    float result = instance->_NV_getItemWeight();
    lua_pushnumber(L, result);
    return 1;
}

int ArmourBinding::getValueSingle(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");

    bool isPlayer = lua_toboolean(L, 2) != 0;
    int result = instance->getValueSingle(isPlayer);
    lua_pushinteger(L, result);
    return 1;
}

int ArmourBinding::_NV_getValueSingle(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");

    bool isPlayer = lua_toboolean(L, 2) != 0;
    int result = instance->_NV_getValueSingle(isPlayer);
    lua_pushinteger(L, result);
    return 1;
}

int ArmourBinding::didIHitFlesh(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");

    GameData* bodypart = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->didIHitFlesh(bodypart);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ArmourBinding::hasArmourCoverage(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");

    bool result = instance->hasArmourCoverage();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ArmourBinding::getCraftTime(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");

    float result = instance->getCraftTime();
    lua_pushnumber(L, result);
    return 1;
}

int ArmourBinding::_NV_getCraftTime(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");

    float result = instance->_NV_getCraftTime();
    lua_pushnumber(L, result);
    return 1;
}

int ArmourBinding::getWeatherProtection_simple(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");

    WeatherAffecting weather = (WeatherAffecting)luaL_checkinteger(L, 2);
    float result = instance->getWeatherProtection_simple(weather);
    lua_pushnumber(L, result);
    return 1;
}

int ArmourBinding::_CONSTRUCTOR(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");

    GameData* baseData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* _materialData = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    hand _handle = *checkObject<hand>(L, 4, handBinding::getMetatableName());
    Faction* _uniformFlag = checkObject<Faction>(L, 5, FactionBinding::getMetatableName());
    int _level = (int)luaL_checkinteger(L, 6);
    Armour* result = instance->_CONSTRUCTOR(baseData, _materialData, _handle, _uniformFlag, _level);
    return pushObject<Armour>(L, result, ArmourBinding::getMetatableName());
}

int ArmourBinding::_DESTRUCTOR(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 168: void getTooltipData1(...) - unsupported arg type
  line 169: void _NV_getTooltipData1(...) - unsupported arg type
  line 170: void getTooltipData2(...) - unsupported arg type
  line 171: void _NV_getTooltipData2(...) - unsupported arg type
  line 176: float getArmourCraftingMaterialConsumptionRate(...) - static method
*/

/*
Skipped properties needing manual binding:
  line 183: armourClassEnum (ArmourClass) - unsupported type
  line 184: stigma (CharacterTypeEnum) - unsupported type
  line 199: weatherProtections (std::set<WeatherAffecting, std::less<WeatherAffecting>, Ogre::STLAllocator<WeatherAffecting, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 207: bodypartCoverage (ogre_unordered_map<GameData*, float>::type) - unsupported type
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



static int Armour_get_armourClassEnum(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    lua_pushinteger(L, (lua_Integer)instance->armourClassEnum);
    return 1;
}


static int Armour_get_bodypartCoverage(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    // TODO: Unsupported type for bodypartCoverage (ogre_unordered_map<GameData*, float>::type)
    return luaL_error(L, "Unsupported property 'bodypartCoverage' (type: ogre_unordered_map<GameData*, float>::type)");
}


static int Armour_get_stigma(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    lua_pushinteger(L, (lua_Integer)instance->stigma);
    return 1;
}


static int Armour_get_weatherProtections(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    // TODO: Unsupported type for weatherProtections (std::set<WeatherAffecting, std::less<WeatherAffecting>, Ogre::STLAllocator<WeatherAffecting, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'weatherProtections' (type: std::set<WeatherAffecting, std::less<WeatherAffecting>, Ogre::STLAllocator<WeatherAffecting, Ogre::GeneralAllocPolicy > >)");
}


static int Armour_set_armourClassEnum(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    instance->armourClassEnum = (ArmourClass)luaL_checkinteger(L, 2);
    return 0;
}


static int Armour_set_bodypartCoverage(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    return luaL_error(L, "Read-only or unsupported setter type for bodypartCoverage");
}


static int Armour_set_stigma(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    instance->stigma = (CharacterTypeEnum)luaL_checkinteger(L, 2);
    return 0;
}


static int Armour_set_weatherProtections(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    return luaL_error(L, "Read-only or unsupported setter type for weatherProtections");
}


int ArmourBinding::getArmourCraftingMaterialConsumptionRate(lua_State* L)
{
    Armour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Armour is nil");
    float result = Armour::getArmourCraftingMaterialConsumptionRate(instance->data);
    lua_pushnumber(L, result);
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
        { "didIHitFlesh", ArmourBinding::didIHitFlesh },
        { "hasArmourCoverage", ArmourBinding::hasArmourCoverage },
        { "getCraftTime", ArmourBinding::getCraftTime },
        { "_NV_getCraftTime", ArmourBinding::_NV_getCraftTime },
        { "getWeatherProtection_simple", ArmourBinding::getWeatherProtection_simple },
        { "_CONSTRUCTOR", ArmourBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", ArmourBinding::_DESTRUCTOR },
                { "getArmourCraftingMaterialConsumptionRate", ArmourBinding::getArmourCraftingMaterialConsumptionRate },
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
    registerGetter(L, "cutResistance", Armour_get_cutResistance);
    registerGetter(L, "bluntResistance", Armour_get_bluntResistance);
    registerGetter(L, "pierceResistance", Armour_get_pierceResistance);
    registerGetter(L, "minCutResistance", Armour_get_minCutResistance);
    registerGetter(L, "cutToStun", Armour_get_cutToStun);
    registerGetter(L, "materialType", Armour_get_materialType);
    registerGetter(L, "athleticsMult", Armour_get_athleticsMult);
    registerGetter(L, "combatSkillBonusAttk", Armour_get_combatSkillBonusAttk);
    registerGetter(L, "combatSkillBonusDef", Armour_get_combatSkillBonusDef);
    registerGetter(L, "perceptionBonus", Armour_get_perceptionBonus);
    registerGetter(L, "combatSpeedMult", Armour_get_combatSpeedMult);
    registerGetter(L, "stealthMult", Armour_get_stealthMult);
    registerGetter(L, "assassinMult", Armour_get_assassinMult);
    registerGetter(L, "dexterityMult", Armour_get_dexterityMult);
    registerGetter(L, "damageMult", Armour_get_damageMult);
    registerGetter(L, "dodgeMult", Armour_get_dodgeMult);
    registerGetter(L, "unarmedBonus", Armour_get_unarmedBonus);
    registerGetter(L, "fistInjuryMult", Armour_get_fistInjuryMult);
    registerGetter(L, "weatherProtectionAmount", Armour_get_weatherProtectionAmount);
    registerGetter(L, "rangedSkillMult", Armour_get_rangedSkillMult);
    registerGetter(L, "craftTime", Armour_get_craftTime);
    registerGetter(L, "armourClassEnum", Armour_get_armourClassEnum);
    registerGetter(L, "bodypartCoverage", Armour_get_bodypartCoverage);
    registerGetter(L, "stigma", Armour_get_stigma);
    registerGetter(L, "weatherProtections", Armour_get_weatherProtections);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "cutResistance", Armour_set_cutResistance);
    registerSetter(L, "bluntResistance", Armour_set_bluntResistance);
    registerSetter(L, "pierceResistance", Armour_set_pierceResistance);
    registerSetter(L, "minCutResistance", Armour_set_minCutResistance);
    registerSetter(L, "cutToStun", Armour_set_cutToStun);
    registerSetter(L, "materialType", Armour_set_materialType);
    registerSetter(L, "athleticsMult", Armour_set_athleticsMult);
    registerSetter(L, "combatSkillBonusAttk", Armour_set_combatSkillBonusAttk);
    registerSetter(L, "combatSkillBonusDef", Armour_set_combatSkillBonusDef);
    registerSetter(L, "perceptionBonus", Armour_set_perceptionBonus);
    registerSetter(L, "combatSpeedMult", Armour_set_combatSpeedMult);
    registerSetter(L, "stealthMult", Armour_set_stealthMult);
    registerSetter(L, "assassinMult", Armour_set_assassinMult);
    registerSetter(L, "dexterityMult", Armour_set_dexterityMult);
    registerSetter(L, "damageMult", Armour_set_damageMult);
    registerSetter(L, "dodgeMult", Armour_set_dodgeMult);
    registerSetter(L, "unarmedBonus", Armour_set_unarmedBonus);
    registerSetter(L, "fistInjuryMult", Armour_set_fistInjuryMult);
    registerSetter(L, "weatherProtectionAmount", Armour_set_weatherProtectionAmount);
    registerSetter(L, "rangedSkillMult", Armour_set_rangedSkillMult);
    registerSetter(L, "craftTime", Armour_set_craftTime);
    registerSetter(L, "armourClassEnum", Armour_set_armourClassEnum);
    registerSetter(L, "bodypartCoverage", Armour_set_bodypartCoverage);
    registerSetter(L, "stigma", Armour_set_stigma);
    registerSetter(L, "weatherProtections", Armour_set_weatherProtections);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Gear
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, ArmourBinding::getMetatableName(), GearBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua