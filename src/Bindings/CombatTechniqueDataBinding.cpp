#include "pch.h"
#include <kenshi\CombatTechniqueData.h>
#include "CombatTechniqueDataBinding.h"
#include "Bindings/ImpactPointBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static CombatTechniqueData* getInstance(lua_State* L, int idx)
{
    return checkObject<CombatTechniqueData>(L, idx, CombatTechniqueDataBinding::getMetatableName());
}

// --- Getters for CombatTechniqueData ---
static int CombatTechniqueData_get_animation(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    lua_pushstring(L, instance->animation.c_str());
    return 1;
}

static int CombatTechniqueData_get_animSpeedMultiplier(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    lua_pushnumber(L, instance->animSpeedMultiplier);
    return 1;
}

static int CombatTechniqueData_get_isBlock(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    lua_pushboolean(L, instance->isBlock ? 1 : 0);
    return 1;
}

static int CombatTechniqueData_get_isDodge(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    lua_pushboolean(L, instance->isDodge ? 1 : 0);
    return 1;
}

static int CombatTechniqueData_get_stumbleDodge(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    lua_pushboolean(L, instance->stumbleDodge ? 1 : 0);
    return 1;
}

static int CombatTechniqueData_get_gainsGround(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    lua_pushboolean(L, instance->gainsGround ? 1 : 0);
    return 1;
}

static int CombatTechniqueData_get_isProne(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    lua_pushboolean(L, instance->isProne ? 1 : 0);
    return 1;
}

static int CombatTechniqueData_get_lowStrike(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    lua_pushboolean(L, instance->lowStrike ? 1 : 0);
    return 1;
}

static int CombatTechniqueData_get_hesitationPoint(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    lua_pushnumber(L, instance->hesitationPoint);
    return 1;
}

static int CombatTechniqueData_get_initialDistance(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    lua_pushnumber(L, instance->initialDistance);
    return 1;
}

static int CombatTechniqueData_get_minDistanceVsStatic(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    lua_pushnumber(L, instance->minDistanceVsStatic);
    return 1;
}

static int CombatTechniqueData_get_acceptableEndTime01(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    lua_pushnumber(L, instance->acceptableEndTime01);
    return 1;
}

static int CombatTechniqueData_get_minSkill(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    lua_pushnumber(L, instance->minSkill);
    return 1;
}

static int CombatTechniqueData_get_maxSkill(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    lua_pushnumber(L, instance->maxSkill);
    return 1;
}

static int CombatTechniqueData_get_maxEncumbrance(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    lua_pushnumber(L, instance->maxEncumbrance);
    return 1;
}

static int CombatTechniqueData_get_chanceMult(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    lua_pushnumber(L, instance->chanceMult);
    return 1;
}

static int CombatTechniqueData_get_maxTargetHits(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    lua_pushinteger(L, instance->maxTargetHits);
    return 1;
}

static int CombatTechniqueData_get_events(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    return pushObject<ogre_unordered_map<GameData*, float>::type>(L, &instance->events, "KenshiLua.GameDataFloatMap");
}

static int CombatTechniqueData_get_skillTypes(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    return luaL_error(L, "Array type skillTypes is not directly accessible; use hasSkillType instead");
}

static int CombatTechniqueData_get_impactPoints(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    return pushObject<lektor<CombatTechniqueData::ImpactPoint>>(L, &instance->impactPoints, "lektor<CombatTechniqueData::ImpactPoint>");
}

// --- Setters for CombatTechniqueData ---
static int CombatTechniqueData_set_animation(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    instance->animation = luaL_checkstring(L, 2);
    return 0;
}

static int CombatTechniqueData_set_animSpeedMultiplier(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    instance->animSpeedMultiplier = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatTechniqueData_set_isBlock(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    instance->isBlock = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatTechniqueData_set_isDodge(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    instance->isDodge = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatTechniqueData_set_stumbleDodge(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    instance->stumbleDodge = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatTechniqueData_set_gainsGround(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    instance->gainsGround = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatTechniqueData_set_isProne(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    instance->isProne = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatTechniqueData_set_lowStrike(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    instance->lowStrike = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CombatTechniqueData_set_hesitationPoint(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    instance->hesitationPoint = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatTechniqueData_set_initialDistance(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    instance->initialDistance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatTechniqueData_set_minDistanceVsStatic(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    instance->minDistanceVsStatic = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatTechniqueData_set_acceptableEndTime01(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    instance->acceptableEndTime01 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatTechniqueData_set_minSkill(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    instance->minSkill = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatTechniqueData_set_maxSkill(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    instance->maxSkill = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatTechniqueData_set_maxEncumbrance(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    instance->maxEncumbrance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatTechniqueData_set_chanceMult(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    instance->chanceMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CombatTechniqueData_set_maxTargetHits(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    instance->maxTargetHits = (int)luaL_checkinteger(L, 2);
    return 0;
}

// TODO: Unsupported type for events (ogre_unordered_map<GameData*, float>::type)
static int CombatTechniqueData_set_events(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for events");
}

static int CombatTechniqueData_set_skillTypes(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    return luaL_error(L, "skillTypes array is read-only");
}

static int CombatTechniqueData_set_impactPoints(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for impactPoints");
}

int CombatTechniqueDataBinding::hasSkillType(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");

    WeaponCategory type = (WeaponCategory)luaL_checkinteger(L, 2);
    bool result = instance->hasSkillType(type);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CombatTechniqueDataBinding::numImpactPoints(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");

    int result = instance->numImpactPoints();
    lua_pushinteger(L, result);
    return 1;
}

int CombatTechniqueDataBinding::impactPoint(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");

    int i = (int)luaL_checkinteger(L, 2);
    CombatTechniqueData::ImpactPoint* result = instance->impactPoint(i);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 15: CombatTechniqueData* _CONSTRUCTOR(...) - unsupported arg type
*/

int CombatTechniqueDataBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int CombatTechniqueDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CombatTechniqueData object");
    return 1;
}

void CombatTechniqueDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CombatTechniqueDataBinding::gc },
        { "__tostring", CombatTechniqueDataBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "hasSkillType", CombatTechniqueDataBinding::hasSkillType },
        { "numImpactPoints", CombatTechniqueDataBinding::numImpactPoints },
        { "impactPoint", CombatTechniqueDataBinding::impactPoint },
        { 0, 0 }
    };

    registerClass(
        L, 
        CombatTechniqueDataBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CombatTechniqueDataBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, CombatTechniqueData_get_animation);
    lua_setfield(L, -2, "animation");
    lua_pushcfunction(L, CombatTechniqueData_get_animSpeedMultiplier);
    lua_setfield(L, -2, "animSpeedMultiplier");
    lua_pushcfunction(L, CombatTechniqueData_get_isBlock);
    lua_setfield(L, -2, "isBlock");
    lua_pushcfunction(L, CombatTechniqueData_get_isDodge);
    lua_setfield(L, -2, "isDodge");
    lua_pushcfunction(L, CombatTechniqueData_get_stumbleDodge);
    lua_setfield(L, -2, "stumbleDodge");
    lua_pushcfunction(L, CombatTechniqueData_get_gainsGround);
    lua_setfield(L, -2, "gainsGround");
    lua_pushcfunction(L, CombatTechniqueData_get_isProne);
    lua_setfield(L, -2, "isProne");
    lua_pushcfunction(L, CombatTechniqueData_get_lowStrike);
    lua_setfield(L, -2, "lowStrike");
    lua_pushcfunction(L, CombatTechniqueData_get_hesitationPoint);
    lua_setfield(L, -2, "hesitationPoint");
    lua_pushcfunction(L, CombatTechniqueData_get_initialDistance);
    lua_setfield(L, -2, "initialDistance");
    lua_pushcfunction(L, CombatTechniqueData_get_minDistanceVsStatic);
    lua_setfield(L, -2, "minDistanceVsStatic");
    lua_pushcfunction(L, CombatTechniqueData_get_acceptableEndTime01);
    lua_setfield(L, -2, "acceptableEndTime01");
    lua_pushcfunction(L, CombatTechniqueData_get_minSkill);
    lua_setfield(L, -2, "minSkill");
    lua_pushcfunction(L, CombatTechniqueData_get_maxSkill);
    lua_setfield(L, -2, "maxSkill");
    lua_pushcfunction(L, CombatTechniqueData_get_maxEncumbrance);
    lua_setfield(L, -2, "maxEncumbrance");
    lua_pushcfunction(L, CombatTechniqueData_get_chanceMult);
    lua_setfield(L, -2, "chanceMult");
    lua_pushcfunction(L, CombatTechniqueData_get_maxTargetHits);
    lua_setfield(L, -2, "maxTargetHits");
    lua_pushcfunction(L, CombatTechniqueData_get_events);
    lua_setfield(L, -2, "events");
    lua_pushcfunction(L, CombatTechniqueData_get_skillTypes);
    lua_setfield(L, -2, "skillTypes");
    lua_pushcfunction(L, CombatTechniqueData_get_impactPoints);
    lua_setfield(L, -2, "impactPoints");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, CombatTechniqueData_set_animation);
    lua_setfield(L, -2, "animation");
    lua_pushcfunction(L, CombatTechniqueData_set_animSpeedMultiplier);
    lua_setfield(L, -2, "animSpeedMultiplier");
    lua_pushcfunction(L, CombatTechniqueData_set_isBlock);
    lua_setfield(L, -2, "isBlock");
    lua_pushcfunction(L, CombatTechniqueData_set_isDodge);
    lua_setfield(L, -2, "isDodge");
    lua_pushcfunction(L, CombatTechniqueData_set_stumbleDodge);
    lua_setfield(L, -2, "stumbleDodge");
    lua_pushcfunction(L, CombatTechniqueData_set_gainsGround);
    lua_setfield(L, -2, "gainsGround");
    lua_pushcfunction(L, CombatTechniqueData_set_isProne);
    lua_setfield(L, -2, "isProne");
    lua_pushcfunction(L, CombatTechniqueData_set_lowStrike);
    lua_setfield(L, -2, "lowStrike");
    lua_pushcfunction(L, CombatTechniqueData_set_hesitationPoint);
    lua_setfield(L, -2, "hesitationPoint");
    lua_pushcfunction(L, CombatTechniqueData_set_initialDistance);
    lua_setfield(L, -2, "initialDistance");
    lua_pushcfunction(L, CombatTechniqueData_set_minDistanceVsStatic);
    lua_setfield(L, -2, "minDistanceVsStatic");
    lua_pushcfunction(L, CombatTechniqueData_set_acceptableEndTime01);
    lua_setfield(L, -2, "acceptableEndTime01");
    lua_pushcfunction(L, CombatTechniqueData_set_minSkill);
    lua_setfield(L, -2, "minSkill");
    lua_pushcfunction(L, CombatTechniqueData_set_maxSkill);
    lua_setfield(L, -2, "maxSkill");
    lua_pushcfunction(L, CombatTechniqueData_set_maxEncumbrance);
    lua_setfield(L, -2, "maxEncumbrance");
    lua_pushcfunction(L, CombatTechniqueData_set_chanceMult);
    lua_setfield(L, -2, "chanceMult");
    lua_pushcfunction(L, CombatTechniqueData_set_maxTargetHits);
    lua_setfield(L, -2, "maxTargetHits");
    lua_pushcfunction(L, CombatTechniqueData_set_events);
    lua_setfield(L, -2, "events");
    lua_pushcfunction(L, CombatTechniqueData_set_skillTypes);
    lua_setfield(L, -2, "skillTypes");
    lua_pushcfunction(L, CombatTechniqueData_set_impactPoints);
    lua_setfield(L, -2, "impactPoints");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack

    // Register container bindings
    LektorValueReadOnlyBinding<CombatTechniqueData::ImpactPoint>::registerBinding(L, "lektor<CombatTechniqueData::ImpactPoint>", ImpactPointBinding::getMetatableName());
    OgreUnorderedMapBinding<GameData*, float>::registerBinding(L, "KenshiLua.GameDataFloatMap", GameDataBinding::getMetatableName(), nullptr);
}

} // namespace KenshiLua