#include "pch.h"
#include <kenshi\CombatTechniqueData.h>
#include <kenshi/Enums.h>
#include <kenshi/MedicalSystem.h>
#include "ImpactPointBinding.h"
#include "EnumBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Util/LektorBinding.h"

namespace KenshiLua
{
typedef CombatTechniqueData::ImpactPoint ImpactPoint;

static ImpactPoint* getInstance(lua_State* L, int idx)
{
    return checkObject<ImpactPoint>(L, idx, ImpactPointBinding::getMetatableName());
}

// --- Getters for ImpactPoint ---
static int ImpactPoint_get_direction(lua_State* L)
{
    ImpactPoint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ImpactPoint is nil");
    lua_pushinteger(L, (lua_Integer)instance->direction);
    return 1;
}

static int ImpactPoint_get_power(lua_State* L)
{
    ImpactPoint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ImpactPoint is nil");
    lua_pushnumber(L, instance->power);
    return 1;
}

static int ImpactPoint_get_impactAnimationFrame(lua_State* L)
{
    ImpactPoint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ImpactPoint is nil");
    lua_pushnumber(L, instance->impactAnimationFrame);
    return 1;
}

static int ImpactPoint_get_motionStopsAnimationFrame(lua_State* L)
{
    ImpactPoint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ImpactPoint is nil");
    lua_pushnumber(L, instance->motionStopsAnimationFrame);
    return 1;
}

static int ImpactPoint_get_limb(lua_State* L)
{
    ImpactPoint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ImpactPoint is nil");
    lua_pushinteger(L, (lua_Integer)instance->limb);
    return 1;
}

// --- Setters for ImpactPoint ---
static int ImpactPoint_set_direction(lua_State* L)
{
    ImpactPoint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ImpactPoint is nil");
    instance->direction = (CutDirection)luaL_checkinteger(L, 2);
    return 0;
}

static int ImpactPoint_set_power(lua_State* L)
{
    ImpactPoint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ImpactPoint is nil");
    instance->power = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ImpactPoint_set_impactAnimationFrame(lua_State* L)
{
    ImpactPoint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ImpactPoint is nil");
    instance->impactAnimationFrame = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ImpactPoint_set_motionStopsAnimationFrame(lua_State* L)
{
    ImpactPoint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ImpactPoint is nil");
    instance->motionStopsAnimationFrame = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ImpactPoint_set_limb(lua_State* L)
{
    ImpactPoint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ImpactPoint is nil");
    instance->limb = (RobotLimbs::Limb)luaL_checkinteger(L, 2);
    return 0;
}



/*
Skipped methods needing manual binding:
  line 26: const CombatTechniqueData::ImpactPoint& operator=(...) - operator
*/

int ImpactPointBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ImpactPointBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ImpactPoint object");
    return 1;
}

void ImpactPointBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ImpactPointBinding::gc },
        { "__tostring", ImpactPointBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        ImpactPointBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ImpactPointBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "direction", ImpactPoint_get_direction);
    registerGetter(L, "power", ImpactPoint_get_power);
    registerGetter(L, "impactAnimationFrame", ImpactPoint_get_impactAnimationFrame);
    registerGetter(L, "motionStopsAnimationFrame", ImpactPoint_get_motionStopsAnimationFrame);
    registerGetter(L, "limb", ImpactPoint_get_limb);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "direction", ImpactPoint_set_direction);
    registerSetter(L, "power", ImpactPoint_set_power);
    registerSetter(L, "impactAnimationFrame", ImpactPoint_set_impactAnimationFrame);
    registerSetter(L, "motionStopsAnimationFrame", ImpactPoint_set_motionStopsAnimationFrame);
    registerSetter(L, "limb", ImpactPoint_set_limb);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack

    LektorValueReadOnlyBinding<CombatTechniqueData::ImpactPoint>::registerBinding(L, "lektor<CombatTechniqueData::ImpactPoint>", ImpactPointBinding::getMetatableName());
}

} // namespace KenshiLua
