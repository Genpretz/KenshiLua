#include "pch.h"
#include "kenshi\CharMovement.h"
#include "physHitBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/RootObjectBinding.h"

namespace KenshiLua
{

static physHit* getInstance(lua_State* L, int idx)
{
    return checkObject<physHit>(L, idx, physHitBinding::getMetatableName());
}

// --- Getters for physHit ---
static int physHit_get__defaultAltitudeFallback(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");
    lua_pushnumber(L, instance->_defaultAltitudeFallback);
    return 1;
}

static int physHit_get__traceWasAborted(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");
    lua_pushboolean(L, instance->_traceWasAborted ? 1 : 0);
    return 1;
}

static int physHit_get__doNotAbort(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");
    lua_pushboolean(L, instance->_doNotAbort ? 1 : 0);
    return 1;
}

static int physHit_get__needsGroup(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");
    lua_pushboolean(L, instance->_needsGroup ? 1 : 0);
    return 1;
}

static int physHit_get_hit(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");
    lua_pushboolean(L, instance->hit ? 1 : 0);
    return 1;
}

static int physHit_get_position(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");
    pushVector3(L, instance->position);
    return 1;
}

static int physHit_get_normal(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");
    pushVector3(L, instance->normal);
    return 1;
}

static int physHit_get_distance(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");
    lua_pushnumber(L, instance->distance);
    return 1;
}

static int physHit_get_shape(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");
    lua_pushlightuserdata(L, (void*)instance->shape);
    return 1;
}

static int physHit_get_hitObject(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");
    return handBinding::push(L, instance->hitObject);
}

static int physHit_get__group(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");
    lua_pushinteger(L, instance->_group);
    return 1;
}

static int physHit_get__hitObjectUnsafePtr(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");
    return pushObject<RootObject>(L, instance->_hitObjectUnsafePtr, RootObjectBinding::getMetatableName());
}

// --- Setters for physHit ---
static int physHit_set__defaultAltitudeFallback(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");
    instance->_defaultAltitudeFallback = (float)luaL_checknumber(L, 2);
    return 0;
}

static int physHit_set__traceWasAborted(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");
    instance->_traceWasAborted = lua_toboolean(L, 2) != 0;
    return 0;
}

static int physHit_set__doNotAbort(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");
    instance->_doNotAbort = lua_toboolean(L, 2) != 0;
    return 0;
}

static int physHit_set__needsGroup(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");
    instance->_needsGroup = lua_toboolean(L, 2) != 0;
    return 0;
}

static int physHit_set_hit(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");
    instance->hit = lua_toboolean(L, 2) != 0;
    return 0;
}

static int physHit_set_position(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");
    readVector3(L, 2, instance->position);
    return 0;
}

static int physHit_set_normal(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");
    readVector3(L, 2, instance->normal);
    return 0;
}

static int physHit_set_distance(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");
    instance->distance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int physHit_set_hitObject(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");
    instance->hitObject = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int physHit_set__group(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");
    instance->_group = (unsigned short)luaL_checkinteger(L, 2);
    return 0;
}

static int physHit_set__hitObjectUnsafePtr(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");
    instance->_hitObjectUnsafePtr = lua_isnoneornil(L, 2) ? nullptr : checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    return 0;
}

int physHitBinding::traceWasAborted(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");

    bool result = instance->traceWasAborted();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int physHitBinding::reset(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");

    instance->reset();
    return 0;
}

int physHitBinding::hitObjectUnsafePtr(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");

    RootObject* result = instance->hitObjectUnsafePtr();
    return pushObject<RootObject>(L, result, RootObjectBinding::getMetatableName());
}

int physHitBinding::getBuilding(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");

    Building* result = instance->getBuilding();
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
}

int physHitBinding::group(lua_State* L)
{
    physHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "physHit is nil");

    unsigned short result = instance->group();
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

/*
LIGHTUSERDATA DEPENDENCIES:
  - physHit_get_shape: NxShape* (unbound pointer)
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
    registerGetter(L, "_defaultAltitudeFallback", physHit_get__defaultAltitudeFallback);
    registerGetter(L, "_traceWasAborted", physHit_get__traceWasAborted);
    registerGetter(L, "_doNotAbort", physHit_get__doNotAbort);
    registerGetter(L, "_needsGroup", physHit_get__needsGroup);
    registerGetter(L, "hit", physHit_get_hit);
    registerGetter(L, "position", physHit_get_position);
    registerGetter(L, "normal", physHit_get_normal);
    registerGetter(L, "distance", physHit_get_distance);
    registerGetter(L, "shape", physHit_get_shape);
    registerGetter(L, "hitObject", physHit_get_hitObject);
    registerGetter(L, "_group", physHit_get__group);
    registerGetter(L, "_hitObjectUnsafePtr", physHit_get__hitObjectUnsafePtr);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "_defaultAltitudeFallback", physHit_set__defaultAltitudeFallback);
    registerSetter(L, "_traceWasAborted", physHit_set__traceWasAborted);
    registerSetter(L, "_doNotAbort", physHit_set__doNotAbort);
    registerSetter(L, "_needsGroup", physHit_set__needsGroup);
    registerSetter(L, "hit", physHit_set_hit);
    registerSetter(L, "position", physHit_set_position);
    registerSetter(L, "normal", physHit_set_normal);
    registerSetter(L, "distance", physHit_set_distance);
    registerSetter(L, "hitObject", physHit_set_hitObject);
    registerSetter(L, "_group", physHit_set__group);
    registerSetter(L, "_hitObjectUnsafePtr", physHit_set__hitObjectUnsafePtr);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua