#include "pch.h"
#include "kenshi\MedicalSystem.h"
#include "HealthPartStatusBinding.h"
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
    return checkObject<HealthPartStatus>(L, idx, HealthPartStatusBinding::getMetatableName());
}

// --- Getters for HealthPartStatus ---
static int HealthPartStatus_get_data(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    return pushObject<GameData>(L, instance->data, GameDataBinding::getMetatableName());
}

static int HealthPartStatus_get_whatAmI(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushinteger(L, (lua_Integer)instance->whatAmI);
    return 1;
}

static int HealthPartStatus_get_medical(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    return pushObject<MedicalSystem>(L, instance->medical, MedicalSystemBinding::getMetatableName());
}

static int HealthPartStatus_get_me(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    return pushObject<Character>(L, instance->me, CharacterBinding::getMetatableName());
}

static int HealthPartStatus_get_side(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushinteger(L, (lua_Integer)instance->side);
    return 1;
}

static int HealthPartStatus_get_robotLimb(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    return pushObject<RobotLimbItem>(L, instance->robotLimb, RobotLimbItemBinding::getMetatableName());
}

static int HealthPartStatus_get_selfHealing(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushboolean(L, instance->selfHealing ? 1 : 0);
    return 1;
}

static int HealthPartStatus_get_collapses(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushboolean(L, instance->collapses ? 1 : 0);
    return 1;
}

static int HealthPartStatus_get_fatal(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushboolean(L, instance->fatal ? 1 : 0);
    return 1;
}

static int HealthPartStatus_get_KOMult(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, instance->KOMult);
    return 1;
}

static int HealthPartStatus_get_hitChance(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, instance->hitChance);
    return 1;
}

static int HealthPartStatus_get_hitChanceMult(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, instance->hitChanceMult);
    return 1;
}

static int HealthPartStatus_get_flesh(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, instance->flesh);
    return 1;
}

static int HealthPartStatus_get_fleshStun(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, instance->fleshStun);
    return 1;
}

static int HealthPartStatus_get_bandaging(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, instance->bandaging);
    return 1;
}

static int HealthPartStatus_get_juryRigging(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, instance->juryRigging);
    return 1;
}

static int HealthPartStatus_get_wearDamage(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, instance->wearDamage);
    return 1;
}

static int HealthPartStatus_get__maxHealth(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, instance->_maxHealth);
    return 1;
}

static int HealthPartStatus_get_age(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, instance->age);
    return 1;
}

static int HealthPartStatus_get_HPMult(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, instance->HPMult);
    return 1;
}

static int HealthPartStatus_get_derivedFleshHealthPercent(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, instance->derivedFleshHealthPercent);
    return 1;
}

// --- Setters for HealthPartStatus ---
static int HealthPartStatus_set_data(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->data = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int HealthPartStatus_set_whatAmI(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->whatAmI = (MedicalSystem::HealthPartStatus::PartType)luaL_checkinteger(L, 2);
    return 0;
}

static int HealthPartStatus_set_medical(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->medical = lua_isnoneornil(L, 2) ? nullptr : checkObject<MedicalSystem>(L, 2, MedicalSystemBinding::getMetatableName());
    return 0;
}

static int HealthPartStatus_set_me(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->me = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int HealthPartStatus_set_side(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->side = (LeftRight)luaL_checkinteger(L, 2);
    return 0;
}

static int HealthPartStatus_set_robotLimb(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->robotLimb = lua_isnoneornil(L, 2) ? nullptr : checkObject<RobotLimbItem>(L, 2, RobotLimbItemBinding::getMetatableName());
    return 0;
}

static int HealthPartStatus_set_selfHealing(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->selfHealing = lua_toboolean(L, 2) != 0;
    return 0;
}

static int HealthPartStatus_set_collapses(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->collapses = lua_toboolean(L, 2) != 0;
    return 0;
}

static int HealthPartStatus_set_fatal(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->fatal = lua_toboolean(L, 2) != 0;
    return 0;
}

static int HealthPartStatus_set_KOMult(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->KOMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HealthPartStatus_set_hitChance(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->hitChance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HealthPartStatus_set_hitChanceMult(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->hitChanceMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HealthPartStatus_set_flesh(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->flesh = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HealthPartStatus_set_fleshStun(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->fleshStun = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HealthPartStatus_set_bandaging(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->bandaging = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HealthPartStatus_set_juryRigging(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->juryRigging = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HealthPartStatus_set_wearDamage(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->wearDamage = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HealthPartStatus_set__maxHealth(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->_maxHealth = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HealthPartStatus_set_age(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->age = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HealthPartStatus_set_HPMult(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->HPMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HealthPartStatus_set_derivedFleshHealthPercent(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");
    instance->derivedFleshHealthPercent = (float)luaL_checknumber(L, 2);
    return 0;
}

int HealthPartStatusBinding::serialise(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    GameData* out = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    int num = (int)luaL_checkinteger(L, 3);
    instance->serialise(out, num);
    return 0;
}

int HealthPartStatusBinding::load(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    GameData* out = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    int num = (int)luaL_checkinteger(L, 3);
    instance->load(out, num);
    return 0;
}

int HealthPartStatusBinding::isRobotic(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    bool result = instance->isRobotic();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int HealthPartStatusBinding::getData(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    GameData* result = instance->getData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int HealthPartStatusBinding::getRobotLimbEnum(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    RobotLimbs::Limb result = instance->getRobotLimbEnum();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int HealthPartStatusBinding::setup(lua_State* L)
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

int HealthPartStatusBinding::update(lua_State* L)
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

int HealthPartStatusBinding::updateDerivedHealths(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    instance->updateDerivedHealths();
    return 0;
}

int HealthPartStatusBinding::getWorstDamage(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    float brokenBoneValue = (float)luaL_checknumber(L, 2);
    float result = instance->getWorstDamage(brokenBoneValue);
    lua_pushnumber(L, result);
    return 1;
}

int HealthPartStatusBinding::setRobotLimbItem(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    RobotLimbItem* _robotLimb = checkObject<RobotLimbItem>(L, 2, RobotLimbItemBinding::getMetatableName());
    bool isLoadingASave = lua_toboolean(L, 3) != 0;
    instance->setRobotLimbItem(_robotLimb, isLoadingASave);
    return 0;
}

int HealthPartStatusBinding::getExtraBleedingAmount(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    float result = instance->getExtraBleedingAmount();
    lua_pushnumber(L, result);
    return 1;
}

int HealthPartStatusBinding::isDead(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    bool result = instance->isDead();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int HealthPartStatusBinding::getBloodynessMult(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    float result = instance->getBloodynessMult();
    lua_pushnumber(L, result);
    return 1;
}

int HealthPartStatusBinding::maxHealth(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    float result = instance->maxHealth();
    lua_pushnumber(L, result);
    return 1;
}

int HealthPartStatusBinding::healthAsPercent(lua_State* L)
{
    HealthPartStatus* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HealthPartStatus is nil");

    float healt = (float)luaL_checknumber(L, 2);
    float result = instance->healthAsPercent(healt);
    lua_pushnumber(L, result);
    return 1;
}

int HealthPartStatusBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int HealthPartStatusBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.HealthPartStatus object");
    return 1;
}

void HealthPartStatusBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       HealthPartStatusBinding::gc },
        { "__tostring", HealthPartStatusBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "serialise", HealthPartStatusBinding::serialise },
        { "load", HealthPartStatusBinding::load },
        { "isRobotic", HealthPartStatusBinding::isRobotic },
        { "getData", HealthPartStatusBinding::getData },
        { "getRobotLimbEnum", HealthPartStatusBinding::getRobotLimbEnum },
        { "setup", HealthPartStatusBinding::setup },
        { "update", HealthPartStatusBinding::update },
        { "updateDerivedHealths", HealthPartStatusBinding::updateDerivedHealths },
        { "getWorstDamage", HealthPartStatusBinding::getWorstDamage },
        { "setRobotLimbItem", HealthPartStatusBinding::setRobotLimbItem },
        { "getExtraBleedingAmount", HealthPartStatusBinding::getExtraBleedingAmount },
        { "isDead", HealthPartStatusBinding::isDead },
        { "getBloodynessMult", HealthPartStatusBinding::getBloodynessMult },
        { "maxHealth", HealthPartStatusBinding::maxHealth },
        { "healthAsPercent", HealthPartStatusBinding::healthAsPercent },
        { 0, 0 }
    };

    registerClass(
        L, 
        HealthPartStatusBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, HealthPartStatusBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, HealthPartStatus_get_data);
    lua_setfield(L, -2, "data");
    lua_pushcfunction(L, HealthPartStatus_get_whatAmI);
    lua_setfield(L, -2, "whatAmI");
    lua_pushcfunction(L, HealthPartStatus_get_medical);
    lua_setfield(L, -2, "medical");
    lua_pushcfunction(L, HealthPartStatus_get_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, HealthPartStatus_get_side);
    lua_setfield(L, -2, "side");
    lua_pushcfunction(L, HealthPartStatus_get_robotLimb);
    lua_setfield(L, -2, "robotLimb");
    lua_pushcfunction(L, HealthPartStatus_get_selfHealing);
    lua_setfield(L, -2, "selfHealing");
    lua_pushcfunction(L, HealthPartStatus_get_collapses);
    lua_setfield(L, -2, "collapses");
    lua_pushcfunction(L, HealthPartStatus_get_fatal);
    lua_setfield(L, -2, "fatal");
    lua_pushcfunction(L, HealthPartStatus_get_KOMult);
    lua_setfield(L, -2, "KOMult");
    lua_pushcfunction(L, HealthPartStatus_get_hitChance);
    lua_setfield(L, -2, "hitChance");
    lua_pushcfunction(L, HealthPartStatus_get_hitChanceMult);
    lua_setfield(L, -2, "hitChanceMult");
    lua_pushcfunction(L, HealthPartStatus_get_flesh);
    lua_setfield(L, -2, "flesh");
    lua_pushcfunction(L, HealthPartStatus_get_fleshStun);
    lua_setfield(L, -2, "fleshStun");
    lua_pushcfunction(L, HealthPartStatus_get_bandaging);
    lua_setfield(L, -2, "bandaging");
    lua_pushcfunction(L, HealthPartStatus_get_juryRigging);
    lua_setfield(L, -2, "juryRigging");
    lua_pushcfunction(L, HealthPartStatus_get_wearDamage);
    lua_setfield(L, -2, "wearDamage");
    lua_pushcfunction(L, HealthPartStatus_get__maxHealth);
    lua_setfield(L, -2, "_maxHealth");
    lua_pushcfunction(L, HealthPartStatus_get_age);
    lua_setfield(L, -2, "age");
    lua_pushcfunction(L, HealthPartStatus_get_HPMult);
    lua_setfield(L, -2, "HPMult");
    lua_pushcfunction(L, HealthPartStatus_get_derivedFleshHealthPercent);
    lua_setfield(L, -2, "derivedFleshHealthPercent");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, HealthPartStatus_set_data);
    lua_setfield(L, -2, "data");
    lua_pushcfunction(L, HealthPartStatus_set_whatAmI);
    lua_setfield(L, -2, "whatAmI");
    lua_pushcfunction(L, HealthPartStatus_set_medical);
    lua_setfield(L, -2, "medical");
    lua_pushcfunction(L, HealthPartStatus_set_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, HealthPartStatus_set_side);
    lua_setfield(L, -2, "side");
    lua_pushcfunction(L, HealthPartStatus_set_robotLimb);
    lua_setfield(L, -2, "robotLimb");
    lua_pushcfunction(L, HealthPartStatus_set_selfHealing);
    lua_setfield(L, -2, "selfHealing");
    lua_pushcfunction(L, HealthPartStatus_set_collapses);
    lua_setfield(L, -2, "collapses");
    lua_pushcfunction(L, HealthPartStatus_set_fatal);
    lua_setfield(L, -2, "fatal");
    lua_pushcfunction(L, HealthPartStatus_set_KOMult);
    lua_setfield(L, -2, "KOMult");
    lua_pushcfunction(L, HealthPartStatus_set_hitChance);
    lua_setfield(L, -2, "hitChance");
    lua_pushcfunction(L, HealthPartStatus_set_hitChanceMult);
    lua_setfield(L, -2, "hitChanceMult");
    lua_pushcfunction(L, HealthPartStatus_set_flesh);
    lua_setfield(L, -2, "flesh");
    lua_pushcfunction(L, HealthPartStatus_set_fleshStun);
    lua_setfield(L, -2, "fleshStun");
    lua_pushcfunction(L, HealthPartStatus_set_bandaging);
    lua_setfield(L, -2, "bandaging");
    lua_pushcfunction(L, HealthPartStatus_set_juryRigging);
    lua_setfield(L, -2, "juryRigging");
    lua_pushcfunction(L, HealthPartStatus_set_wearDamage);
    lua_setfield(L, -2, "wearDamage");
    lua_pushcfunction(L, HealthPartStatus_set__maxHealth);
    lua_setfield(L, -2, "_maxHealth");
    lua_pushcfunction(L, HealthPartStatus_set_age);
    lua_setfield(L, -2, "age");
    lua_pushcfunction(L, HealthPartStatus_set_HPMult);
    lua_setfield(L, -2, "HPMult");
    lua_pushcfunction(L, HealthPartStatus_set_derivedFleshHealthPercent);
    lua_setfield(L, -2, "derivedFleshHealthPercent");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
