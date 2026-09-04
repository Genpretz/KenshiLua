#include "pch.h"
#include <kenshi\CombatTechniqueData.h>
#include "CombatTechniqueDataBinding.h"
#include "Bindings/ImpactPointBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/FitnessSelectorBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
typedef FitnessSelectorBinding<CombatTechniqueData*> FitnessSelector_CombatTechniqueData_Binding;

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
    return pushObject<ogre_unordered_map<GameData*, float>::type>(L, &instance->events, OgreUnorderedMapBinding<GameData*, float>::getMetatableName());
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

static int CombatTechniqueData_set_events(lua_State* L)
{
    CombatTechniqueData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CombatTechniqueData is nil");
    ogre_unordered_map<GameData*, float>::type* val = OgreUnorderedMapBinding<GameData*, float>::get(L, 2);
    if (!val) return luaL_error(L, "Expected ogre_unordered_map<GameData*, float>");
    instance->events = *val;
    return 0;
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
    return pushObject<CombatTechniqueData::ImpactPoint>(L, result, ImpactPointBinding::getMetatableName());
}


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
    registerGetter(L, "animation", CombatTechniqueData_get_animation);
    registerGetter(L, "animSpeedMultiplier", CombatTechniqueData_get_animSpeedMultiplier);
    registerGetter(L, "isBlock", CombatTechniqueData_get_isBlock);
    registerGetter(L, "isDodge", CombatTechniqueData_get_isDodge);
    registerGetter(L, "stumbleDodge", CombatTechniqueData_get_stumbleDodge);
    registerGetter(L, "gainsGround", CombatTechniqueData_get_gainsGround);
    registerGetter(L, "isProne", CombatTechniqueData_get_isProne);
    registerGetter(L, "lowStrike", CombatTechniqueData_get_lowStrike);
    registerGetter(L, "hesitationPoint", CombatTechniqueData_get_hesitationPoint);
    registerGetter(L, "initialDistance", CombatTechniqueData_get_initialDistance);
    registerGetter(L, "minDistanceVsStatic", CombatTechniqueData_get_minDistanceVsStatic);
    registerGetter(L, "acceptableEndTime01", CombatTechniqueData_get_acceptableEndTime01);
    registerGetter(L, "minSkill", CombatTechniqueData_get_minSkill);
    registerGetter(L, "maxSkill", CombatTechniqueData_get_maxSkill);
    registerGetter(L, "maxEncumbrance", CombatTechniqueData_get_maxEncumbrance);
    registerGetter(L, "chanceMult", CombatTechniqueData_get_chanceMult);
    registerGetter(L, "maxTargetHits", CombatTechniqueData_get_maxTargetHits);
    registerGetter(L, "events", CombatTechniqueData_get_events);
    registerGetter(L, "skillTypes", CombatTechniqueData_get_skillTypes);
    registerGetter(L, "impactPoints", CombatTechniqueData_get_impactPoints);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "animation", CombatTechniqueData_set_animation);
    registerSetter(L, "animSpeedMultiplier", CombatTechniqueData_set_animSpeedMultiplier);
    registerSetter(L, "isBlock", CombatTechniqueData_set_isBlock);
    registerSetter(L, "isDodge", CombatTechniqueData_set_isDodge);
    registerSetter(L, "stumbleDodge", CombatTechniqueData_set_stumbleDodge);
    registerSetter(L, "gainsGround", CombatTechniqueData_set_gainsGround);
    registerSetter(L, "isProne", CombatTechniqueData_set_isProne);
    registerSetter(L, "lowStrike", CombatTechniqueData_set_lowStrike);
    registerSetter(L, "hesitationPoint", CombatTechniqueData_set_hesitationPoint);
    registerSetter(L, "initialDistance", CombatTechniqueData_set_initialDistance);
    registerSetter(L, "minDistanceVsStatic", CombatTechniqueData_set_minDistanceVsStatic);
    registerSetter(L, "acceptableEndTime01", CombatTechniqueData_set_acceptableEndTime01);
    registerSetter(L, "minSkill", CombatTechniqueData_set_minSkill);
    registerSetter(L, "maxSkill", CombatTechniqueData_set_maxSkill);
    registerSetter(L, "maxEncumbrance", CombatTechniqueData_set_maxEncumbrance);
    registerSetter(L, "chanceMult", CombatTechniqueData_set_chanceMult);
    registerSetter(L, "maxTargetHits", CombatTechniqueData_set_maxTargetHits);
    registerSetter(L, "events", CombatTechniqueData_set_events);
    registerSetter(L, "skillTypes", CombatTechniqueData_set_skillTypes);
    registerSetter(L, "impactPoints", CombatTechniqueData_set_impactPoints);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack

}

} // namespace KenshiLua
