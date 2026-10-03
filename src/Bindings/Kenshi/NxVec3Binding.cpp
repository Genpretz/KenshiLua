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

int NxVec3Binding::dot(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");

    NxVec3* v = getInstance(L, 2);
    if (!v) return luaL_error(L, "Argument 2 to dot must be NxVec3");

    float result = instance->dot(*v);
    lua_pushnumber(L, result);
    return 1;
}

int NxVec3Binding::equals(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");

    NxVec3* v = getInstance(L, 2);
    if (!v) return luaL_error(L, "Argument 2 to equals must be NxVec3");

    float epsilon = (float)luaL_optnumber(L, 3, 0.0001f);
    bool result = instance->equals(*v, epsilon);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int NxVec3Binding::multiplyAdd(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");

    float s = (float)luaL_checknumber(L, 2);
    NxVec3* a = getInstance(L, 3);
    NxVec3* b = getInstance(L, 4);
    if (!a || !b) return luaL_error(L, "Arguments 3 and 4 to multiplyAdd must be NxVec3");

    instance->multiplyAdd(s, *a, *b);
    return 0;
}

int NxVec3Binding::add(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");

    if (lua_gettop(L) >= 3)
    {
        NxVec3* a = getInstance(L, 2);
        NxVec3* b = getInstance(L, 3);
        if (!a || !b) return luaL_error(L, "Arguments 2 and 3 to add must be NxVec3");
        instance->add(*a, *b);
        return 0;
    }
    else
    {
        NxVec3* b = getInstance(L, 2);
        if (!b) return luaL_error(L, "Argument 2 to add must be NxVec3");
        *instance += *b;
        return 0;
    }
}

int NxVec3Binding::subtract(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");

    if (lua_gettop(L) >= 3)
    {
        NxVec3* a = getInstance(L, 2);
        NxVec3* b = getInstance(L, 3);
        if (!a || !b) return luaL_error(L, "Arguments 2 and 3 to subtract must be NxVec3");
        instance->subtract(*a, *b);
        return 0;
    }
    else
    {
        NxVec3* b = getInstance(L, 2);
        if (!b) return luaL_error(L, "Argument 2 to subtract must be NxVec3");
        *instance -= *b;
        return 0;
    }
}

int NxVec3Binding::cross(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");

    if (lua_gettop(L) >= 3)
    {
        NxVec3* left = getInstance(L, 2);
        NxVec3* right = getInstance(L, 3);
        if (!left || !right) return luaL_error(L, "Arguments 2 and 3 to cross must be NxVec3");
        instance->cross(*left, *right);
        return 0;
    }
    else
    {
        NxVec3* right = getInstance(L, 2);
        if (!right) return luaL_error(L, "Argument 2 to cross must be NxVec3");
        NxVec3 res = *instance ^ *right;
        return pushValue<NxVec3>(L, res, NxVec3Binding::getMetatableName());
    }
}

int NxVec3Binding::set(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");

    if (lua_isuserdata(L, 2))
    {
        NxVec3* other = getInstance(L, 2);
        if (!other) return luaL_error(L, "Argument 2 must be NxVec3");
        *instance = *other;
        return 0;
    }
    float x = (float)luaL_checknumber(L, 2);
    float y = (float)luaL_checknumber(L, 3);
    float z = (float)luaL_checknumber(L, 4);
    instance->set(x, y, z);
    return 0;
}

int NxVec3Binding::constructor(lua_State* L)
{
    int startIdx = 1;
    if (lua_istable(L, 1))
        startIdx = 2; // Invoked via __call metamethod on NxVec3 global table

    int top = lua_gettop(L);
    int numArgs = top - startIdx + 1;

    if (numArgs <= 0)
    {
        NxVec3 v(0.0f, 0.0f, 0.0f);
        return pushValue<NxVec3>(L, v, NxVec3Binding::getMetatableName());
    }
    else if (numArgs == 1)
    {
        NxVec3* other = testObject<NxVec3>(L, startIdx, NxVec3Binding::getMetatableName());
        if (other)
        {
            NxVec3 v(*other);
            return pushValue<NxVec3>(L, v, NxVec3Binding::getMetatableName());
        }
        float a = (float)luaL_checknumber(L, startIdx);
        NxVec3 v(a, a, a);
        return pushValue<NxVec3>(L, v, NxVec3Binding::getMetatableName());
    }
    else
    {
        float x = (float)luaL_optnumber(L, startIdx, 0.0);
        float y = (float)luaL_optnumber(L, startIdx + 1, 0.0);
        float z = (float)luaL_optnumber(L, startIdx + 2, 0.0);
        NxVec3 v(x, y, z);
        return pushValue<NxVec3>(L, v, NxVec3Binding::getMetatableName());
    }
}

int NxVec3Binding::lua_add(lua_State* L)
{
    NxVec3* a = getInstance(L, 1);
    NxVec3* b = getInstance(L, 2);
    if (!a || !b) return luaL_error(L, "Operands to + must be NxVec3");
    NxVec3 res = *a + *b;
    return pushValue<NxVec3>(L, res, NxVec3Binding::getMetatableName());
}

int NxVec3Binding::lua_sub(lua_State* L)
{
    NxVec3* a = getInstance(L, 1);
    NxVec3* b = getInstance(L, 2);
    if (!a || !b) return luaL_error(L, "Operands to - must be NxVec3");
    NxVec3 res(a->x - b->x, a->y - b->y, a->z - b->z);
    return pushValue<NxVec3>(L, res, NxVec3Binding::getMetatableName());
}

int NxVec3Binding::lua_unm(lua_State* L)
{
    NxVec3* a = getInstance(L, 1);
    if (!a) return luaL_error(L, "Operand to unary - must be NxVec3");
    NxVec3 res = -(*a);
    return pushValue<NxVec3>(L, res, NxVec3Binding::getMetatableName());
}

int NxVec3Binding::lua_mul(lua_State* L)
{
    if (lua_isnumber(L, 1))
    {
        float s = (float)lua_tonumber(L, 1);
        NxVec3* v = getInstance(L, 2);
        if (!v) return luaL_error(L, "Right operand must be NxVec3");
        NxVec3 res(v->x * s, v->y * s, v->z * s);
        return pushValue<NxVec3>(L, res, NxVec3Binding::getMetatableName());
    }
    else if (lua_isnumber(L, 2))
    {
        NxVec3* v = getInstance(L, 1);
        if (!v) return luaL_error(L, "Left operand must be NxVec3");
        float s = (float)lua_tonumber(L, 2);
        NxVec3 res(v->x * s, v->y * s, v->z * s);
        return pushValue<NxVec3>(L, res, NxVec3Binding::getMetatableName());
    }
    return luaL_error(L, "Multiplication requires an NxVec3 and a number");
}

int NxVec3Binding::lua_eq(lua_State* L)
{
    NxVec3* a = testObject<NxVec3>(L, 1, NxVec3Binding::getMetatableName());
    NxVec3* b = testObject<NxVec3>(L, 2, NxVec3Binding::getMetatableName());
    if (!a || !b)
    {
        lua_pushboolean(L, 0);
        return 1;
    }
    lua_pushboolean(L, (*a == *b) ? 1 : 0);
    return 1;
}

int NxVec3Binding::operator_assign(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");
    NxVec3* v = getInstance(L, 2);
    if (!v) return luaL_error(L, "Argument 2 to operator_assign must be NxVec3");
    instance->operator=(*v);
    lua_pushvalue(L, 1);
    return 1;
}

int NxVec3Binding::operator_subscript(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");
    int index = (int)luaL_checkinteger(L, 2);
    if (index < 0 || index >= 3)
        return luaL_error(L, "Index out of bounds: %d (expected 0..2)", index);
    if (lua_gettop(L) >= 3)
    {
        float val = (float)luaL_checknumber(L, 3);
        instance->operator[](index) = val;
        return 0;
    }
    else
    {
        float res = instance->operator[](index);
        lua_pushnumber(L, res);
        return 1;
    }
}

int NxVec3Binding::operator_ne(lua_State* L)
{
    NxVec3* a = getInstance(L, 1);
    if (!a) return luaL_error(L, "NxVec3 is nil");
    NxVec3* b = getInstance(L, 2);
    if (!b) return luaL_error(L, "Argument 2 to operator_ne must be NxVec3");
    lua_pushboolean(L, (*a != *b) ? 1 : 0);
    return 1;
}

int NxVec3Binding::operator_add_assign(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");
    NxVec3* v = getInstance(L, 2);
    if (!v) return luaL_error(L, "Argument 2 to operator_add_assign must be NxVec3");
    instance->operator+=(*v);
    lua_pushvalue(L, 1);
    return 1;
}

int NxVec3Binding::operator_sub_assign(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");
    NxVec3* v = getInstance(L, 2);
    if (!v) return luaL_error(L, "Argument 2 to operator_sub_assign must be NxVec3");
    instance->operator-=(*v);
    lua_pushvalue(L, 1);
    return 1;
}

int NxVec3Binding::operator_mul_assign(lua_State* L)
{
    NxVec3* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxVec3 is nil");
    float f = (float)luaL_checknumber(L, 2);
    instance->operator*=(f);
    lua_pushvalue(L, 1);
    return 1;
}

int NxVec3Binding::operator_xor(lua_State* L)
{
    NxVec3* a = getInstance(L, 1);
    if (!a) return luaL_error(L, "NxVec3 is nil");
    NxVec3* b = getInstance(L, 2);
    if (!b) return luaL_error(L, "Argument 2 to operator_xor must be NxVec3");
    NxVec3 res = (*a) ^ (*b);
    return pushValue<NxVec3>(L, res, NxVec3Binding::getMetatableName());
}

int NxVec3Binding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int NxVec3Binding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.NxVec3 object");
    NxVec3* instance = getInstance(L, 1);
    if (!instance) {
        lua_pushstring(L, "NxVec3(nil)");
        return 1;
    }
    char buf[128];
    sprintf_s(buf, "NxVec3(%.3f, %.3f, %.3f)", instance->x, instance->y, instance->z);
    lua_pushstring(L, buf);
    return 1;
}

void NxVec3Binding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       NxVec3Binding::gc },
        { "__tostring", NxVec3Binding::tostring },
        { "__add",      NxVec3Binding::lua_add },
        { "__sub",      NxVec3Binding::lua_sub },
        { "__unm",      NxVec3Binding::lua_unm },
        { "__mul",      NxVec3Binding::lua_mul },
        { "__eq",       NxVec3Binding::lua_eq },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "zero",                NxVec3Binding::zero },
        { "isZero",              NxVec3Binding::isZero },
        { "normalize",           NxVec3Binding::normalize },
        { "setMagnitude",        NxVec3Binding::setMagnitude },
        { "closestAxis",         NxVec3Binding::closestAxis },
        { "isFinite",            NxVec3Binding::isFinite },
        { "magnitude",           NxVec3Binding::magnitude },
        { "magnitudeSquared",    NxVec3Binding::magnitudeSquared },
        { "dot",                 NxVec3Binding::dot },
        { "equals",              NxVec3Binding::equals },
        { "multiplyAdd",         NxVec3Binding::multiplyAdd },
        { "add",                 NxVec3Binding::add },
        { "subtract",            NxVec3Binding::subtract },
        { "cross",               NxVec3Binding::cross },
        { "set",                 NxVec3Binding::set },
        { "operator_assign",     NxVec3Binding::operator_assign },
        { "operator_subscript",  NxVec3Binding::operator_subscript },
        { "operator_eq",         NxVec3Binding::lua_eq },
        { "operator_ne",         NxVec3Binding::operator_ne },
        { "operator_add",        NxVec3Binding::lua_add },
        { "operator_sub",        NxVec3Binding::lua_sub },
        { "operator_unm",        NxVec3Binding::lua_unm },
        { "operator_mul",        NxVec3Binding::lua_mul },
        { "operator_add_assign", NxVec3Binding::operator_add_assign },
        { "operator_sub_assign", NxVec3Binding::operator_sub_assign },
        { "operator_mul_assign", NxVec3Binding::operator_mul_assign },
        { "operator_xor",        NxVec3Binding::operator_xor },
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

    // Register global class table with constructor (__call metamethod)
    pushGlobalTable(L, "NxVec3");
    registerConstructor(L, NxVec3Binding::constructor);
    lua_setglobal(L, "NxVec3");
}

} // namespace KenshiLua