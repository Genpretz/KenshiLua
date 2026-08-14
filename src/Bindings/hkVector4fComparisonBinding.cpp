#include "pch.h"
#include "kenshi\havok.h"
#include "hkVector4fComparisonBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static hkVector4fComparison* getInstance(lua_State* L, int idx)
{
    return checkObject<hkVector4fComparison>(L, idx, hkVector4fComparisonBinding::getMetatableName());
}

// --- Getters for hkVector4fComparison ---
// --- Setters for hkVector4fComparison ---
int hkVector4fComparisonBinding::getIndexOfLastComponentSet(lua_State* L)
{
    hkVector4fComparison* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4fComparison is nil");

    int result = instance->getIndexOfLastComponentSet();
    lua_pushinteger(L, result);
    return 1;
}

int hkVector4fComparisonBinding::getIndexOfFirstComponentSet(lua_State* L)
{
    hkVector4fComparison* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4fComparison is nil");

    int result = instance->getIndexOfFirstComponentSet();
    lua_pushinteger(L, result);
    return 1;
}

int hkVector4fComparisonBinding::allAreSet(lua_State* L)
{
    hkVector4fComparison* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4fComparison is nil");

    unsigned int result = instance->allAreSet();
    lua_pushinteger(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 44: const hkVector4fComparison convert(...) - static method
  line 45: Mask getMaskForComponent(...) - static method
  line 48: void setAnd(...) - unsupported arg type
  line 49: void setAndNot(...) - unsupported arg type
  line 50: void setXor(...) - unsupported arg type
  line 51: void setOr(...) - unsupported arg type
  line 52: void setNot(...) - unsupported arg type
  line 53: void setSelect(...) - unsupported arg type
  line 54: void set(Mask m) - unexported method RVA = 0x14A450
  line 57: unsigned int anyIsSet(...) - overloaded method
  line 58: unsigned int anyIsSet(...) - overloaded method
  line 59: Mask getMask(...) - overloaded method
  line 60: Mask getMask(...) - overloaded method
*/

/*
Skipped properties needing manual binding:
  line 62: m_mask (union __m128) - unsupported type
*/

int hkVector4fComparisonBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int hkVector4fComparisonBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.hkVector4fComparison object");
    return 1;
}

void hkVector4fComparisonBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       hkVector4fComparisonBinding::gc },
        { "__tostring", hkVector4fComparisonBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getIndexOfLastComponentSet", hkVector4fComparisonBinding::getIndexOfLastComponentSet },
        { "getIndexOfFirstComponentSet", hkVector4fComparisonBinding::getIndexOfFirstComponentSet },
        { "allAreSet", hkVector4fComparisonBinding::allAreSet },
        { 0, 0 }
    };

    registerClass(
        L, 
        hkVector4fComparisonBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, hkVector4fComparisonBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua