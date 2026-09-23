#include "pch.h"
#include "kenshi\physicsactual.h"
#include "NxMat33Binding.h"
#include "NxVec3Binding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static NxMat33* getInstance(lua_State* L, int idx)
{
    return checkObject<NxMat33>(L, idx, NxMat33Binding::getMetatableName());
}

// --- Getters for NxMat33 ---
// --- Setters for NxMat33 ---
int NxMat33Binding::setRowMajor(lua_State* L)
{
    NxMat33* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxMat33 is nil");

    const float* d = (const float*)lua_touserdata(L, 2);
    if (d) instance->setRowMajor(d);
    return 0;
}

int NxMat33Binding::getRowMajor(lua_State* L)
{
    NxMat33* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxMat33 is nil");

    float* d = (float*)lua_touserdata(L, 2);
    if (d) instance->getRowMajor(d);
    return 0;
}

int NxMat33Binding::getColumnMajor(lua_State* L)
{
    NxMat33* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxMat33 is nil");

    float* d = (float*)lua_touserdata(L, 2);
    if (d) instance->getColumnMajor(d);
    return 0;
}

int NxMat33Binding::setRowMajorStride4(lua_State* L)
{
    NxMat33* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxMat33 is nil");

    const float* d = (const float*)lua_touserdata(L, 2);
    if (d) instance->setRowMajorStride4(d);
    return 0;
}

int NxMat33Binding::getRowMajorStride4(lua_State* L)
{
    NxMat33* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxMat33 is nil");

    float* d = (float*)lua_touserdata(L, 2);
    if (d) instance->getRowMajorStride4(d);
    return 0;
}

int NxMat33Binding::getColumnMajorStride4(lua_State* L)
{
    NxMat33* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxMat33 is nil");

    float* d = (float*)lua_touserdata(L, 2);
    if (d) instance->getColumnMajorStride4(d);
    return 0;
}

int NxMat33Binding::isFinite(lua_State* L)
{
    NxMat33* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxMat33 is nil");

    bool result = instance->isFinite();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int NxMat33Binding::zero(lua_State* L)
{
    NxMat33* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxMat33 is nil");

    instance->zero();
    return 0;
}

int NxMat33Binding::id(lua_State* L)
{
    NxMat33* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxMat33 is nil");

    instance->id();
    return 0;
}

int NxMat33Binding::setColumn(lua_State* L)
{
    NxMat33* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxMat33 is nil");

    int col = (int)luaL_checkinteger(L, 2);
    NxVec3* v = checkObject<NxVec3>(L, 3, NxVec3Binding::getMetatableName());
    if (!v) return luaL_error(L, "Argument 3 to setColumn must be NxVec3");

    instance->setColumn(col, *v);
    return 0;
}

int NxMat33Binding::getRow(lua_State* L)
{
    NxMat33* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxMat33 is nil");

    int row = (int)luaL_checkinteger(L, 2);
    NxVec3 res = instance->getRow(row);
    return pushValue<NxVec3>(L, res, NxVec3Binding::getMetatableName());
}

int NxMat33Binding::getColumn(lua_State* L)
{
    NxMat33* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxMat33 is nil");

    int col = (int)luaL_checkinteger(L, 2);
    NxVec3 res = instance->getColumn(col);
    return pushValue<NxVec3>(L, res, NxVec3Binding::getMetatableName());
}

int NxMat33Binding::multiply(lua_State* L)
{
    NxMat33* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxMat33 is nil");

    if (lua_gettop(L) >= 3)
    {
        NxMat33* left = checkObject<NxMat33>(L, 2, NxMat33Binding::getMetatableName());
        NxMat33* right = checkObject<NxMat33>(L, 3, NxMat33Binding::getMetatableName());
        if (!left || !right) return luaL_error(L, "Arguments 2 and 3 must be NxMat33");
        instance->multiply(*left, *right);
        return 0;
    }
    else
    {
        NxVec3* v = testObject<NxVec3>(L, 2, NxVec3Binding::getMetatableName());
        if (v)
        {
            NxVec3 res;
            instance->multiply(*v, res);
            return pushValue<NxVec3>(L, res, NxVec3Binding::getMetatableName());
        }
        NxMat33* other = checkObject<NxMat33>(L, 2, NxMat33Binding::getMetatableName());
        if (other)
        {
            *instance *= *other;
            return 0;
        }
        return luaL_error(L, "Argument 2 to multiply must be NxVec3 or NxMat33");
    }
}

int NxMat33Binding::get(lua_State* L)
{
    NxMat33* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxMat33 is nil");

    int row = (int)luaL_checkinteger(L, 2);
    int col = (int)luaL_checkinteger(L, 3);
    if (row < 0 || row > 2 || col < 0 || col > 2)
        return luaL_error(L, "Row and column index out of bounds [0..2]");

    float val = instance->data.m[row][col];
    lua_pushnumber(L, val);
    return 1;
}

int NxMat33Binding::set(lua_State* L)
{
    NxMat33* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxMat33 is nil");

    int row = (int)luaL_checkinteger(L, 2);
    int col = (int)luaL_checkinteger(L, 3);
    float val = (float)luaL_checknumber(L, 4);
    if (row < 0 || row > 2 || col < 0 || col > 2)
        return luaL_error(L, "Row and column index out of bounds [0..2]");

    instance->data.m[row][col] = val;
    return 0;
}

int NxMat33Binding::create(lua_State* L)
{
    NxMat33 m;
    m.id();
    return pushValue<NxMat33>(L, m, NxMat33Binding::getMetatableName());
}

int NxMat33Binding::lua_mul(lua_State* L)
{
    NxMat33* m = getInstance(L, 1);
    if (!m) return luaL_error(L, "Left operand must be NxMat33");

    NxVec3* v = testObject<NxVec3>(L, 2, NxVec3Binding::getMetatableName());
    if (v)
    {
        NxVec3 res = *m * *v;
        return pushValue<NxVec3>(L, res, NxVec3Binding::getMetatableName());
    }

    NxMat33* m2 = testObject<NxMat33>(L, 2, NxMat33Binding::getMetatableName());
    if (m2)
    {
        NxMat33 res;
        res.multiply(*m, *m2);
        return pushValue<NxMat33>(L, res, NxMat33Binding::getMetatableName());
    }

    return luaL_error(L, "Right operand must be NxVec3 or NxMat33");
}

/*
Skipped methods needing manual binding:
  line 388: const NxMat33& operator=(...) - operator
  line 427: const float& operator(...) - operator
  line 437: void fromQuat(...) - unsupported arg type
  line 438: void toQuat(...) - unsupported arg type
  line 441: NxMat33& operator*=(...) - operator
  line 470: NxVec3 operator*(...) - operator
*/

/*
Skipped properties needing manual binding:
  line 473: data (Nx9Real) - unsupported type
*/

int NxMat33Binding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int NxMat33Binding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.NxMat33 object");
    return 1;
}

void NxMat33Binding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       NxMat33Binding::gc },
        { "__tostring", NxMat33Binding::tostring },
        { "__mul",      NxMat33Binding::lua_mul },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setRowMajor", NxMat33Binding::setRowMajor },
        { "getRowMajor", NxMat33Binding::getRowMajor },
        { "getColumnMajor", NxMat33Binding::getColumnMajor },
        { "setRowMajorStride4", NxMat33Binding::setRowMajorStride4 },
        { "getRowMajorStride4", NxMat33Binding::getRowMajorStride4 },
        { "getColumnMajorStride4", NxMat33Binding::getColumnMajorStride4 },
        { "isFinite", NxMat33Binding::isFinite },
        { "zero", NxMat33Binding::zero },
        { "id", NxMat33Binding::id },
        { "setColumn", NxMat33Binding::setColumn },
        { "getRow", NxMat33Binding::getRow },
        { "getColumn", NxMat33Binding::getColumn },
        { "multiply", NxMat33Binding::multiply },
        { "get", NxMat33Binding::get },
        { "set", NxMat33Binding::set },
        { "create", NxMat33Binding::create },
        { 0, 0 }
    };

    registerClass(
        L, 
        NxMat33Binding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, NxMat33Binding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack

    // Register global class table for static methods
    pushGlobalTable(L, "NxMat33");
    registerStaticMethod(L, "create", NxMat33Binding::create);
    lua_setglobal(L, "NxMat33");
}

} // namespace KenshiLua