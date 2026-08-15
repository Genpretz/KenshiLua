#include "pch.h"
#include "kenshi\physicsactual.h"
#include "NxVec3Binding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static NxVec3* getInstance(lua_State* L, int idx)
{
    return checkObject<NxVec3>(L, idx, NxVec3Binding::getMetatableName());
}

// --- Getters for NxVec3 ---
static int NxVec3_get_x(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");
    lua_pushnumber(L, instance->x);
    return 1;
}

static int NxVec3_get_y(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");
    lua_pushnumber(L, instance->y);
    return 1;
}

static int NxVec3_get_z(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");
    lua_pushnumber(L, instance->z);
    return 1;
}

// --- Setters for NxVec3 ---
static int NxVec3_set_x(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");
    instance->x = (float)luaL_checknumber(L, 2);
    return 0;
}

static int NxVec3_set_y(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");
    instance->y = (float)luaL_checknumber(L, 2);
    return 0;
}

static int NxVec3_set_z(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");
    instance->z = (float)luaL_checknumber(L, 2);
    return 0;
}

int NxVec3Binding::zero(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");

    instance->zero();
    return 0;
}

int NxVec3Binding::isZero(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");

    int result = instance->isZero();
    lua_pushinteger(L, result);
    return 1;
}

int NxVec3Binding::normalize(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");

    float result = instance->normalize();
    lua_pushnumber(L, result);
    return 1;
}

int NxVec3Binding::setMagnitude(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");

    float length = (float)luaL_checknumber(L, 2);
    instance->setMagnitude(length);
    return 0;
}

int NxVec3Binding::closestAxis(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");

    unsigned int result = instance->closestAxis();
    lua_pushinteger(L, result);
    return 1;
}

int NxVec3Binding::isFinite(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");

    bool result = instance->isFinite();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int NxVec3Binding::magnitude(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");

    float result = instance->magnitude();
    lua_pushnumber(L, result);
    return 1;
}

int NxVec3Binding::magnitudeSquared(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");

    float result = instance->magnitudeSquared();
    lua_pushnumber(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 291: const NxVec3& operator=(...) - operator
  line 297: float& operator[](...) - operator
  line 299: bool operator==(...) - operator
  line 300: bool operator!=(...) - operator
  line 302: void set(...) - overloaded method
  line 304: void set(...) - overloaded method
  line 317: void add(...) - unsupported arg type
  line 318: void subtract(...) - unsupported arg type
  line 321: void multiplyAdd(...) - unsupported arg type
  line 327: float dot(...) - unsupported arg type
  line 334: void cross(...) - unsupported arg type
  line 337: bool equals(...) - unsupported arg type
  line 339: NxVec3 operator-(...) - operator
  line 340: NxVec3 operator+(...) - operator
  line 343: NxVec3& operator+=(...) - operator
  line 344: NxVec3& operator-=(...) - operator
  line 345: NxVec3& operator*=(...) - operator
  line 347: NxVec3 operator^(...) - operator
*/

int NxVec3Binding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int NxVec3Binding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.NxVec3 object");
    return 1;
}

void NxVec3Binding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       NxVec3Binding::gc },
        { "__tostring", NxVec3Binding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "zero", NxVec3Binding::zero },
        { "isZero", NxVec3Binding::isZero },
        { "normalize", NxVec3Binding::normalize },
        { "setMagnitude", NxVec3Binding::setMagnitude },
        { "closestAxis", NxVec3Binding::closestAxis },
        { "isFinite", NxVec3Binding::isFinite },
        { "magnitude", NxVec3Binding::magnitude },
        { "magnitudeSquared", NxVec3Binding::magnitudeSquared },
        { 0, 0 }
    };

    registerClass(
        L, 
        NxVec3Binding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, NxVec3Binding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "x", NxVec3_get_x);
    registerGetter(L, "y", NxVec3_get_y);
    registerGetter(L, "z", NxVec3_get_z);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "x", NxVec3_set_x);
    registerSetter(L, "y", NxVec3_set_y);
    registerSetter(L, "z", NxVec3_set_z);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua