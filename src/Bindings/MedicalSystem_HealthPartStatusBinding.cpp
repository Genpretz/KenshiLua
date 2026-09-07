#include "pch.h"
#include "kenshi\MedicalSystem.h"
#include "MedicalSystem_HealthPartStatusBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/DamagesBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/MedicalSystemBinding.h"
#include "Bindings/RobotLimbItemBinding.h"

namespace KenshiLua
{

typedef MedicalSystem::HealthPartStatus HealthPartStatus;

static HealthPartStatus* getInstance(lua_State* L, int idx)
{
    return checkObject<HealthPartStatus>(L, idx, MedicalSystem_HealthPartStatusBinding::getMetatableName());
}

// --- Getters for HealthPartStatus ---
static int MedicalSystem_HealthPartStatus_get_data(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    return pushObject<GameData>(L, instance->data, GameDataBinding::getMetatableName());
}

static int MedicalSystem_HealthPartStatus_get_whatAmI(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushinteger(L, (lua_Integer)instance->whatAmI);
    return 1;
}

static int MedicalSystem_HealthPartStatus_get_medical(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    return pushObject<MedicalSystem>(L, instance->medical, MedicalSystemBinding::getMetatableName());
}

static int MedicalSystem_HealthPartStatus_get_me(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    return pushObject<Character>(L, instance->me, CharacterBinding::getMetatableName());
}

static int MedicalSystem_HealthPartStatus_get_side(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushinteger(L, (lua_Integer)instance->side);
    return 1;
}

static int MedicalSystem_HealthPartStatus_get_robotLimb(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    return pushObject<RobotLimbItem>(L, instance->robotLimb, RobotLimbItemBinding::getMetatableName());
}

static int MedicalSystem_HealthPartStatus_get_selfHealing(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushboolean(L, instance->selfHealing ? 1 : 0);
    return 1;
}

static int MedicalSystem_HealthPartStatus_get_collapses(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushboolean(L, instance->collapses ? 1 : 0);
    return 1;
}

static int MedicalSystem_HealthPartStatus_get_fatal(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushboolean(L, instance->fatal ? 1 : 0);
    return 1;
}

static int MedicalSystem_HealthPartStatus_get_KOMult(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, instance->KOMult);
    return 1;
}

static int MedicalSystem_HealthPartStatus_get_hitChance(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, instance->hitChance);
    return 1;
}

static int MedicalSystem_HealthPartStatus_get_hitChanceMult(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, instance->hitChanceMult);
    return 1;
}

static int MedicalSystem_HealthPartStatus_get_flesh(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, instance->flesh);
    return 1;
}

static int MedicalSystem_HealthPartStatus_get_fleshStun(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, instance->fleshStun);
    return 1;
}

static int MedicalSystem_HealthPartStatus_get_bandaging(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, instance->bandaging);
    return 1;
}

static int MedicalSystem_HealthPartStatus_get_juryRigging(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, instance->juryRigging);
    return 1;
}

static int MedicalSystem_HealthPartStatus_get_wearDamage(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, instance->wearDamage);
    return 1;
}

static int MedicalSystem_HealthPartStatus_get__maxHealth(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, instance->_maxHealth);
    return 1;
}

static int MedicalSystem_HealthPartStatus_get_age(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, instance->age);
    return 1;
}

static int MedicalSystem_HealthPartStatus_get_HPMult(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, instance->HPMult);
    return 1;
}

static int MedicalSystem_HealthPartStatus_get_derivedFleshHealthPercent(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, instance->derivedFleshHealthPercent);
    return 1;
}

// --- Setters for HealthPartStatus ---
static int MedicalSystem_HealthPartStatus_set_data(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->data = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int MedicalSystem_HealthPartStatus_set_whatAmI(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->whatAmI = (MedicalSystem::HealthPartStatus::PartType)luaL_checkinteger(L, 2);
    return 0;
}

static int MedicalSystem_HealthPartStatus_set_medical(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->medical = lua_isnoneornil(L, 2) ? nullptr : checkObject<MedicalSystem>(L, 2, MedicalSystemBinding::getMetatableName());
    return 0;
}

static int MedicalSystem_HealthPartStatus_set_me(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->me = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int MedicalSystem_HealthPartStatus_set_side(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->side = (LeftRight)luaL_checkinteger(L, 2);
    return 0;
}

static int MedicalSystem_HealthPartStatus_set_robotLimb(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->robotLimb = lua_isnoneornil(L, 2) ? nullptr : checkObject<RobotLimbItem>(L, 2, RobotLimbItemBinding::getMetatableName());
    return 0;
}

static int MedicalSystem_HealthPartStatus_set_selfHealing(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->selfHealing = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MedicalSystem_HealthPartStatus_set_collapses(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->collapses = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MedicalSystem_HealthPartStatus_set_fatal(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->fatal = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MedicalSystem_HealthPartStatus_set_KOMult(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->KOMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_HealthPartStatus_set_hitChance(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->hitChance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_HealthPartStatus_set_hitChanceMult(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->hitChanceMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_HealthPartStatus_set_flesh(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->flesh = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_HealthPartStatus_set_fleshStun(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->fleshStun = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_HealthPartStatus_set_bandaging(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->bandaging = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_HealthPartStatus_set_juryRigging(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->juryRigging = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_HealthPartStatus_set_wearDamage(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->wearDamage = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_HealthPartStatus_set__maxHealth(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->_maxHealth = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_HealthPartStatus_set_age(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->age = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_HealthPartStatus_set_HPMult(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->HPMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_HealthPartStatus_set_derivedFleshHealthPercent(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->derivedFleshHealthPercent = (float)luaL_checknumber(L, 2);
    return 0;
}

int MedicalSystem_HealthPartStatusBinding::serialise(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    GameData* out = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    int num = (int)luaL_checkinteger(L, 3);
    instance->serialise(out, num);
    return 0;
}

int MedicalSystem_HealthPartStatusBinding::load(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    GameData* out = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    int num = (int)luaL_checkinteger(L, 3);
    instance->load(out, num);
    return 0;
}

int MedicalSystem_HealthPartStatusBinding::isRobotic(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    bool result = instance->isRobotic();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystem_HealthPartStatusBinding::getData(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    GameData* result = instance->getData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int MedicalSystem_HealthPartStatusBinding::getRobotLimbEnum(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    RobotLimbs::Limb result = instance->getRobotLimbEnum();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int MedicalSystem_HealthPartStatusBinding::setup(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    GameData* dat = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    float _hitchance = (float)luaL_checknumber(L, 3);
    float _max = (float)luaL_checknumber(L, 4);
    float _age = (float)luaL_checknumber(L, 5);
    MedicalSystem* med = checkObject<MedicalSystem>(L, 6, MedicalSystemBinding::getMetatableName());
    bool selfHeal = lua_toboolean(L, 7) != 0;
    Character* _me = checkObject<Character>(L, 8, CharacterBinding::getMetatableName());
    instance->setup(dat, _hitchance, _max, _age, med, selfHeal, _me);
    return 0;
}

int MedicalSystem_HealthPartStatusBinding::update(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    float frameTIME = (float)luaL_checknumber(L, 2);
    float healMultFlesh = (float)luaL_checknumber(L, 3);
    float healMultRobot = (float)luaL_checknumber(L, 4);
    float degenerationRate = (float)luaL_checknumber(L, 5);
    float _age = (float)luaL_checknumber(L, 6);
    float robotWear = (float)luaL_checknumber(L, 7);
    bool result = instance->update(frameTIME, healMultFlesh, healMultRobot, degenerationRate, _age, robotWear);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystem_HealthPartStatusBinding::updateDerivedHealths(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    instance->updateDerivedHealths();
    return 0;
}

int MedicalSystem_HealthPartStatusBinding::getWorstDamage(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    float brokenBoneValue = (float)luaL_checknumber(L, 2);
    float result = instance->getWorstDamage(brokenBoneValue);
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystem_HealthPartStatusBinding::setRobotLimbItem(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    RobotLimbItem* _robotLimb = checkObject<RobotLimbItem>(L, 2, RobotLimbItemBinding::getMetatableName());
    bool isLoadingASave = lua_toboolean(L, 3) != 0;
    instance->setRobotLimbItem(_robotLimb, isLoadingASave);
    return 0;
}

int MedicalSystem_HealthPartStatusBinding::getExtraBleedingAmount(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    float result = instance->getExtraBleedingAmount();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystem_HealthPartStatusBinding::isDead(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    bool result = instance->isDead();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystem_HealthPartStatusBinding::getBloodynessMult(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    float result = instance->getBloodynessMult();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystem_HealthPartStatusBinding::maxHealth(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    float result = instance->maxHealth();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystem_HealthPartStatusBinding::healthAsPercent(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    float healt = (float)luaL_checknumber(L, 2);
    float result = instance->healthAsPercent(healt);
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystem_HealthPartStatusBinding::gc(lua_State* L)
{
    // HealthPartStatus instances are owned by MedicalSystem, do not call destructor here
    return 0;
}

int MedicalSystem_HealthPartStatusBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.MedicalSystem_HealthPartStatus object");
    return 1;
}

void MedicalSystem_HealthPartStatusBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       MedicalSystem_HealthPartStatusBinding::gc },
        { "__tostring", MedicalSystem_HealthPartStatusBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "serialise", MedicalSystem_HealthPartStatusBinding::serialise },
        { "load", MedicalSystem_HealthPartStatusBinding::load },
        { "isRobotic", MedicalSystem_HealthPartStatusBinding::isRobotic },
        { "getData", MedicalSystem_HealthPartStatusBinding::getData },
        { "getRobotLimbEnum", MedicalSystem_HealthPartStatusBinding::getRobotLimbEnum },
        { "setup", MedicalSystem_HealthPartStatusBinding::setup },
        { "update", MedicalSystem_HealthPartStatusBinding::update },
        { "updateDerivedHealths", MedicalSystem_HealthPartStatusBinding::updateDerivedHealths },
        { "getWorstDamage", MedicalSystem_HealthPartStatusBinding::getWorstDamage },
        { "setRobotLimbItem", MedicalSystem_HealthPartStatusBinding::setRobotLimbItem },
        { "getExtraBleedingAmount", MedicalSystem_HealthPartStatusBinding::getExtraBleedingAmount },
        { "isDead", MedicalSystem_HealthPartStatusBinding::isDead },
        { "getBloodynessMult", MedicalSystem_HealthPartStatusBinding::getBloodynessMult },
        { "maxHealth", MedicalSystem_HealthPartStatusBinding::maxHealth },
        { "healthAsPercent", MedicalSystem_HealthPartStatusBinding::healthAsPercent },
        { 0, 0 }
    };

    registerClass(
        L, 
        MedicalSystem_HealthPartStatusBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, MedicalSystem_HealthPartStatusBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "data", MedicalSystem_HealthPartStatus_get_data);
    registerGetter(L, "whatAmI", MedicalSystem_HealthPartStatus_get_whatAmI);
    registerGetter(L, "medical", MedicalSystem_HealthPartStatus_get_medical);
    registerGetter(L, "me", MedicalSystem_HealthPartStatus_get_me);
    registerGetter(L, "side", MedicalSystem_HealthPartStatus_get_side);
    registerGetter(L, "robotLimb", MedicalSystem_HealthPartStatus_get_robotLimb);
    registerGetter(L, "selfHealing", MedicalSystem_HealthPartStatus_get_selfHealing);
    registerGetter(L, "collapses", MedicalSystem_HealthPartStatus_get_collapses);
    registerGetter(L, "fatal", MedicalSystem_HealthPartStatus_get_fatal);
    registerGetter(L, "KOMult", MedicalSystem_HealthPartStatus_get_KOMult);
    registerGetter(L, "hitChance", MedicalSystem_HealthPartStatus_get_hitChance);
    registerGetter(L, "hitChanceMult", MedicalSystem_HealthPartStatus_get_hitChanceMult);
    registerGetter(L, "flesh", MedicalSystem_HealthPartStatus_get_flesh);
    registerGetter(L, "fleshStun", MedicalSystem_HealthPartStatus_get_fleshStun);
    registerGetter(L, "bandaging", MedicalSystem_HealthPartStatus_get_bandaging);
    registerGetter(L, "juryRigging", MedicalSystem_HealthPartStatus_get_juryRigging);
    registerGetter(L, "wearDamage", MedicalSystem_HealthPartStatus_get_wearDamage);
    registerGetter(L, "_maxHealth", MedicalSystem_HealthPartStatus_get__maxHealth);
    registerGetter(L, "age", MedicalSystem_HealthPartStatus_get_age);
    registerGetter(L, "HPMult", MedicalSystem_HealthPartStatus_get_HPMult);
    registerGetter(L, "derivedFleshHealthPercent", MedicalSystem_HealthPartStatus_get_derivedFleshHealthPercent);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "data", MedicalSystem_HealthPartStatus_set_data);
    registerSetter(L, "whatAmI", MedicalSystem_HealthPartStatus_set_whatAmI);
    registerSetter(L, "medical", MedicalSystem_HealthPartStatus_set_medical);
    registerSetter(L, "me", MedicalSystem_HealthPartStatus_set_me);
    registerSetter(L, "side", MedicalSystem_HealthPartStatus_set_side);
    registerSetter(L, "robotLimb", MedicalSystem_HealthPartStatus_set_robotLimb);
    registerSetter(L, "selfHealing", MedicalSystem_HealthPartStatus_set_selfHealing);
    registerSetter(L, "collapses", MedicalSystem_HealthPartStatus_set_collapses);
    registerSetter(L, "fatal", MedicalSystem_HealthPartStatus_set_fatal);
    registerSetter(L, "KOMult", MedicalSystem_HealthPartStatus_set_KOMult);
    registerSetter(L, "hitChance", MedicalSystem_HealthPartStatus_set_hitChance);
    registerSetter(L, "hitChanceMult", MedicalSystem_HealthPartStatus_set_hitChanceMult);
    registerSetter(L, "flesh", MedicalSystem_HealthPartStatus_set_flesh);
    registerSetter(L, "fleshStun", MedicalSystem_HealthPartStatus_set_fleshStun);
    registerSetter(L, "bandaging", MedicalSystem_HealthPartStatus_set_bandaging);
    registerSetter(L, "juryRigging", MedicalSystem_HealthPartStatus_set_juryRigging);
    registerSetter(L, "wearDamage", MedicalSystem_HealthPartStatus_set_wearDamage);
    registerSetter(L, "_maxHealth", MedicalSystem_HealthPartStatus_set__maxHealth);
    registerSetter(L, "age", MedicalSystem_HealthPartStatus_set_age);
    registerSetter(L, "HPMult", MedicalSystem_HealthPartStatus_set_HPMult);
    registerSetter(L, "derivedFleshHealthPercent", MedicalSystem_HealthPartStatus_set_derivedFleshHealthPercent);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua


