#include "pch.h"
#include "kenshi\physicsactual.h"
#include "NxMat33Binding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static NxMat33* getInstance(lua_State* L, int idx)
{
    return checkObject<NxMat33>(L, idx, NxMat33Binding::getMetatableName());
}

// --- Getters for NxMat33 ---
// --- Setters for NxMat33 ---
int NxMat33Binding::_DESTRUCTOR(lua_State* L)
{
    NxMat33* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NxMat33 is nil");

    instance->_DESTRUCTOR();
    return 0;
}

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

/*
Skipped methods needing manual binding:
  line 379: NxMat33* _CONSTRUCTOR(...) - overloaded method
  line 381: NxMat33* _CONSTRUCTOR(...) - overloaded method
  line 385: NxMat33* _CONSTRUCTOR(...) - overloaded method
  line 388: const NxMat33& operator=(...) - operator
  line 422: void setColumn(...) - unsupported arg type
  line 423: NxVec3 getRow(...) - unsupported return type
  line 425: NxVec3 getColumn(...) - overloaded method
  line 426: void getColumn(...) - overloaded method
  line 427: const float& operator(...) - operator
  line 437: void fromQuat(...) - unsupported arg type
  line 438: void toQuat(...) - unsupported arg type
  line 441: NxMat33& operator*=(...) - operator
  line 452: void multiply(...) - overloaded method
  line 454: void multiply(...) - overloaded method
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
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", NxMat33Binding::_DESTRUCTOR },
        { "setRowMajor", NxMat33Binding::setRowMajor },
        { "getRowMajor", NxMat33Binding::getRowMajor },
        { "getColumnMajor", NxMat33Binding::getColumnMajor },
        { "setRowMajorStride4", NxMat33Binding::setRowMajorStride4 },
        { "getRowMajorStride4", NxMat33Binding::getRowMajorStride4 },
        { "getColumnMajorStride4", NxMat33Binding::getColumnMajorStride4 },
        { "isFinite", NxMat33Binding::isFinite },
        { "zero", NxMat33Binding::zero },
        { "id", NxMat33Binding::id },
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
}

} // namespace KenshiLua