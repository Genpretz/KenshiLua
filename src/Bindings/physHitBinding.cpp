#include "pch.h"
#include "kenshi\CharMovement.h"
#include "physHitBinding.h"
#include "RootObjectBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Building/BuildingBinding.h"

namespace KenshiLua
{

static physHit* getB(lua_State* L, int idx)
{
    return checkObject<physHit>(L, idx, physHitBinding::getMetatableName());
}

// --- Getters for physHit ---
static int physHit_get__defaultAltitudeFallback(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");
    lua_pushnumber(L, b->_defaultAltitudeFallback);
    return 1;
}

static int physHit_get__traceWasAborted(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");
    lua_pushboolean(L, b->_traceWasAborted ? 1 : 0);
    return 1;
}

static int physHit_get__doNotAbort(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");
    lua_pushboolean(L, b->_doNotAbort ? 1 : 0);
    return 1;
}

static int physHit_get__needsGroup(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");
    lua_pushboolean(L, b->_needsGroup ? 1 : 0);
    return 1;
}

static int physHit_get_hit(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");
    lua_pushboolean(L, b->hit ? 1 : 0);
    return 1;
}

static int physHit_get_position(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");
    pushVector3(L, b->position);
    return 1;
}

static int physHit_get_normal(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");
    pushVector3(L, b->normal);
    return 1;
}

static int physHit_get_distance(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");
    lua_pushnumber(L, b->distance);
    return 1;
}

static int physHit_get_shape(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");
    // TODO: Unsupported type for shape (NxShape*)
    return luaL_error(L, "Unsupported property 'shape' (type: NxShape*)");
}

static int physHit_get_hitObject(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");
    return handBinding::push(L, b->hitObject);
}

static int physHit_get__group(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");
    lua_pushinteger(L, b->_group);
    return 1;
}

static int physHit_get__hitObjectUnsafePtr(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");
    return pushObject<RootObject>(L, b->_hitObjectUnsafePtr, RootObjectBinding::getMetatableName());
}

// --- Setters for physHit ---
static int physHit_set__defaultAltitudeFallback(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");
    b->_defaultAltitudeFallback = (float)luaL_checknumber(L, 2);
    return 0;
}

static int physHit_set__traceWasAborted(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");
    b->_traceWasAborted = lua_toboolean(L, 2) != 0;
    return 0;
}

static int physHit_set__doNotAbort(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");
    b->_doNotAbort = lua_toboolean(L, 2) != 0;
    return 0;
}

static int physHit_set__needsGroup(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");
    b->_needsGroup = lua_toboolean(L, 2) != 0;
    return 0;
}

static int physHit_set_hit(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");
    b->hit = lua_toboolean(L, 2) != 0;
    return 0;
}

static int physHit_set_position(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");
    readVector3(L, 2, b->position);
    return 0;
}

static int physHit_set_normal(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");
    readVector3(L, 2, b->normal);
    return 0;
}

static int physHit_set_distance(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");
    b->distance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int physHit_set_shape(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");
    return luaL_error(L, "Read-only or unsupported setter type for shape");
}

static int physHit_set_hitObject(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->hitObject = *val;
    return 0;
}

static int physHit_set__group(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");
    b->_group = (unsigned short)luaL_checkinteger(L, 2);
    return 0;
}

static int physHit_set__hitObjectUnsafePtr(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");
    return luaL_error(L, "Read-only or unsupported setter type for _hitObjectUnsafePtr");
}

int physHitBinding::traceWasAborted(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");

    bool result = b->traceWasAborted();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int physHitBinding::reset(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");

    b->reset();
    return 0;
}

int physHitBinding::hitObjectUnsafePtr(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");

    RootObject* result = b->hitObjectUnsafePtr();
    return pushObject<RootObject>(L, result, RootObjectBinding::getMetatableName());
}

int physHitBinding::getBuilding(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");

    Building* result = b->getBuilding();
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
}

int physHitBinding::group(lua_State* L)
{
    physHit* b = getB(L, 1);
    if (!b) return luaL_error(L, "physHit is nil");

    unsigned short result = b->group();
    lua_pushinteger(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 39: physHit* _CONSTRUCTOR(...) - overloaded method
  line 41: physHit* _CONSTRUCTOR(...) - overloaded method
  line 43: physHit* _CONSTRUCTOR(...) - overloaded method
  line 44: physHit& operator=(...) - operator
  line 47: operator bool(...) - unsupported return type
*/

int physHitBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int physHitBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.physHit object");
    return 1;
}

void physHitBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       physHitBinding::gc },
        { "__tostring", physHitBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "traceWasAborted", physHitBinding::traceWasAborted },
        { "reset", physHitBinding::reset },
        { "hitObjectUnsafePtr", physHitBinding::hitObjectUnsafePtr },
        { "getBuilding", physHitBinding::getBuilding },
        { "group", physHitBinding::group },
        { 0, 0 }
    };

    registerClass(
        L, 
        physHitBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, physHitBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, physHit_get__defaultAltitudeFallback);
    lua_setfield(L, -2, "_defaultAltitudeFallback");
    lua_pushcfunction(L, physHit_get__traceWasAborted);
    lua_setfield(L, -2, "_traceWasAborted");
    lua_pushcfunction(L, physHit_get__doNotAbort);
    lua_setfield(L, -2, "_doNotAbort");
    lua_pushcfunction(L, physHit_get__needsGroup);
    lua_setfield(L, -2, "_needsGroup");
    lua_pushcfunction(L, physHit_get_hit);
    lua_setfield(L, -2, "hit");
    lua_pushcfunction(L, physHit_get_position);
    lua_setfield(L, -2, "position");
    lua_pushcfunction(L, physHit_get_normal);
    lua_setfield(L, -2, "normal");
    lua_pushcfunction(L, physHit_get_distance);
    lua_setfield(L, -2, "distance");
    lua_pushcfunction(L, physHit_get_shape);
    lua_setfield(L, -2, "shape");
    lua_pushcfunction(L, physHit_get_hitObject);
    lua_setfield(L, -2, "hitObject");
    lua_pushcfunction(L, physHit_get__group);
    lua_setfield(L, -2, "_group");
    lua_pushcfunction(L, physHit_get__hitObjectUnsafePtr);
    lua_setfield(L, -2, "_hitObjectUnsafePtr");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, physHit_set__defaultAltitudeFallback);
    lua_setfield(L, -2, "_defaultAltitudeFallback");
    lua_pushcfunction(L, physHit_set__traceWasAborted);
    lua_setfield(L, -2, "_traceWasAborted");
    lua_pushcfunction(L, physHit_set__doNotAbort);
    lua_setfield(L, -2, "_doNotAbort");
    lua_pushcfunction(L, physHit_set__needsGroup);
    lua_setfield(L, -2, "_needsGroup");
    lua_pushcfunction(L, physHit_set_hit);
    lua_setfield(L, -2, "hit");
    lua_pushcfunction(L, physHit_set_position);
    lua_setfield(L, -2, "position");
    lua_pushcfunction(L, physHit_set_normal);
    lua_setfield(L, -2, "normal");
    lua_pushcfunction(L, physHit_set_distance);
    lua_setfield(L, -2, "distance");
    lua_pushcfunction(L, physHit_set_shape);
    lua_setfield(L, -2, "shape");
    lua_pushcfunction(L, physHit_set_hitObject);
    lua_setfield(L, -2, "hitObject");
    lua_pushcfunction(L, physHit_set__group);
    lua_setfield(L, -2, "_group");
    lua_pushcfunction(L, physHit_set__hitObjectUnsafePtr);
    lua_setfield(L, -2, "_hitObjectUnsafePtr");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua