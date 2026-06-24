#include "pch.h"
#include "kenshi\MedicalSystem.h"
#include "HealthPartStatusBinding.h"
#include "MedicalSystemBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static MedicalSystem::HealthPartStatus* getB(lua_State* L, int idx)
{
    return checkObject<MedicalSystem::HealthPartStatus>(L, idx, HealthPartStatusBinding::getMetatableName());
}

// --- Getters for HealthPartStatus ---
static int HealthPartStatus_get_data(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    return pushObject<GameData>(L, b->data, GameDataBinding::getMetatableName());
}

static int HealthPartStatus_get_whatAmI(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushinteger(L, (lua_Integer)b->whatAmI);
    return 1;
}

static int HealthPartStatus_get_medical(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    return pushObject<MedicalSystem>(L, b->medical, MedicalSystemBinding::getMetatableName());
}

static int HealthPartStatus_get_me(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    return pushObject<Character>(L, b->me, CharacterBinding::getMetatableName());
}

static int HealthPartStatus_get_side(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushinteger(L, (lua_Integer)b->side);
    return 1;
}

static int HealthPartStatus_get_robotLimb(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    // TODO: Unsupported type for robotLimb (RobotLimbItem*)
    lua_pushnil(L);
    return 1;
}

static int HealthPartStatus_get_selfHealing(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushboolean(L, b->selfHealing ? 1 : 0);
    return 1;
}

static int HealthPartStatus_get_collapses(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushboolean(L, b->collapses ? 1 : 0);
    return 1;
}

static int HealthPartStatus_get_fatal(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushboolean(L, b->fatal ? 1 : 0);
    return 1;
}

static int HealthPartStatus_get_KOMult(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, b->KOMult);
    return 1;
}

static int HealthPartStatus_get_hitChance(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, b->hitChance);
    return 1;
}

static int HealthPartStatus_get_hitChanceMult(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, b->hitChanceMult);
    return 1;
}

static int HealthPartStatus_get_flesh(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, b->flesh);
    return 1;
}

static int HealthPartStatus_get_fleshStun(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, b->fleshStun);
    return 1;
}

static int HealthPartStatus_get_bandaging(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, b->bandaging);
    return 1;
}

static int HealthPartStatus_get_juryRigging(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, b->juryRigging);
    return 1;
}

static int HealthPartStatus_get_wearDamage(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, b->wearDamage);
    return 1;
}

static int HealthPartStatus_get__maxHealth(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, b->_maxHealth);
    return 1;
}

static int HealthPartStatus_get_age(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, b->age);
    return 1;
}

static int HealthPartStatus_get_HPMult(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, b->HPMult);
    return 1;
}

static int HealthPartStatus_get_derivedFleshHealthPercent(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    lua_pushnumber(L, b->derivedFleshHealthPercent);
    return 1;
}

// --- Setters for HealthPartStatus ---
static int HealthPartStatus_set_data(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    return luaL_error(L, "Read-only or unsupported setter type for data");
}

static int HealthPartStatus_set_whatAmI(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    b->whatAmI = (MedicalSystem::HealthPartStatus::PartType)luaL_checkinteger(L, 2);
    return 0;
}

static int HealthPartStatus_set_medical(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    return luaL_error(L, "Read-only or unsupported setter type for medical");
}

static int HealthPartStatus_set_me(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    return luaL_error(L, "Read-only or unsupported setter type for me");
}

static int HealthPartStatus_set_side(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    b->side = (LeftRight)luaL_checkinteger(L, 2);
    return 0;
}

static int HealthPartStatus_set_robotLimb(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    return luaL_error(L, "Read-only or unsupported setter type for robotLimb");
}

static int HealthPartStatus_set_selfHealing(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    b->selfHealing = lua_toboolean(L, 2) != 0;
    return 0;
}

static int HealthPartStatus_set_collapses(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    b->collapses = lua_toboolean(L, 2) != 0;
    return 0;
}

static int HealthPartStatus_set_fatal(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    b->fatal = lua_toboolean(L, 2) != 0;
    return 0;
}

static int HealthPartStatus_set_KOMult(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    b->KOMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HealthPartStatus_set_hitChance(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    b->hitChance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HealthPartStatus_set_hitChanceMult(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    b->hitChanceMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HealthPartStatus_set_flesh(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    b->flesh = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HealthPartStatus_set_fleshStun(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    b->fleshStun = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HealthPartStatus_set_bandaging(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    b->bandaging = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HealthPartStatus_set_juryRigging(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    b->juryRigging = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HealthPartStatus_set_wearDamage(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    b->wearDamage = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HealthPartStatus_set__maxHealth(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    b->_maxHealth = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HealthPartStatus_set_age(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    b->age = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HealthPartStatus_set_HPMult(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    b->HPMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int HealthPartStatus_set_derivedFleshHealthPercent(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");
    b->derivedFleshHealthPercent = (float)luaL_checknumber(L, 2);
    return 0;
}

int HealthPartStatusBinding::isRobotic(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");

    bool result = b->isRobotic();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int HealthPartStatusBinding::getData(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");

    GameData* result = b->getData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int HealthPartStatusBinding::getRobotLimbEnum(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");

    RobotLimbs::Limb result = b->getRobotLimbEnum();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int HealthPartStatusBinding::update(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");

    float frameTIME = (float)luaL_checknumber(L, 2);
    float healMultFlesh = (float)luaL_checknumber(L, 3);
    float healMultRobot = (float)luaL_checknumber(L, 4);
    float degenerationRate = (float)luaL_checknumber(L, 5);
    float _age = (float)luaL_checknumber(L, 6);
    float robotWear = (float)luaL_checknumber(L, 7);
    bool result = b->update(frameTIME, healMultFlesh, healMultRobot, degenerationRate, _age, robotWear);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int HealthPartStatusBinding::updateDerivedHealths(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");

    b->updateDerivedHealths();
    return 0;
}

int HealthPartStatusBinding::getWorstDamage(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");

    float brokenBoneValue = (float)luaL_checknumber(L, 2);
    float result = b->getWorstDamage(brokenBoneValue);
    lua_pushnumber(L, result);
    return 1;
}

int HealthPartStatusBinding::getExtraBleedingAmount(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");

    float result = b->getExtraBleedingAmount();
    lua_pushnumber(L, result);
    return 1;
}

int HealthPartStatusBinding::isDead(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");

    bool result = b->isDead();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int HealthPartStatusBinding::getBloodynessMult(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");

    float result = b->getBloodynessMult();
    lua_pushnumber(L, result);
    return 1;
}

int HealthPartStatusBinding::maxHealth(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");

    float result = b->maxHealth();
    lua_pushnumber(L, result);
    return 1;
}

int HealthPartStatusBinding::healthAsPercent(lua_State* L)
{
    MedicalSystem::HealthPartStatus* b = getB(L, 1);
    if (!b) return luaL_error(L, "HealthPartStatus is nil");

    float healt = (float)luaL_checknumber(L, 2);
    float result = b->healthAsPercent(healt);
    lua_pushnumber(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 132: void serialise(...) - unsupported arg type
  line 133: void load(...) - unsupported arg type
  line 150: void setup(...) - unsupported arg type
  line 153: void applyDamage(...) - unsupported arg type
  line 154: void applyWearDamage(...) - unsupported arg type
  line 156: LimbState getRobotLimbState(...) - unsupported return type
  line 157: void setRobotLimbItem(...) - unsupported arg type
*/

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
        { "isRobotic", HealthPartStatusBinding::isRobotic },
        { "getData", HealthPartStatusBinding::getData },
        { "getRobotLimbEnum", HealthPartStatusBinding::getRobotLimbEnum },
        { "update", HealthPartStatusBinding::update },
        { "updateDerivedHealths", HealthPartStatusBinding::updateDerivedHealths },
        { "getWorstDamage", HealthPartStatusBinding::getWorstDamage },
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