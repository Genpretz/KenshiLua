#include "pch.h"
#include "kenshi\havok.h"
#include "hkArrayBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static hkArray* getInstance(lua_State* L, int idx)
{
    return checkObject<hkArray>(L, idx, hkArrayBinding::getMetatableName());
}

// --- Getters for hkArray ---
// --- Setters for hkArray ---
int hkArrayBinding::_CONSTRUCTOR(lua_State* L)
{
    hkArray* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkArray is nil");

    hkArray<T1, T2>* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int hkArrayBinding::_DESTRUCTOR(lua_State* L)
{
    hkArray* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkArray is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int hkArrayBinding::clearAndDeallocate(lua_State* L)
{
    hkArray* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkArray is nil");

    instance->clearAndDeallocate();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 672: hkArray<T1, T2>(...) - overloaded method
  line 674: ~hkArray<T1, T2>(...) - overloaded method
  line 676: hkArray<T1, T2>& operator=(...) - operator
  line 681: void pushBack(...) - unsupported arg type
  line 694: void spliceInto(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - hkArrayBinding::_CONSTRUCTOR: hkArray<T1, T2>* (unbound pointer)
*/

int hkArrayBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int hkArrayBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.hkArray object");
    return 1;
}

void hkArrayBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       hkArrayBinding::gc },
        { "__tostring", hkArrayBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", hkArrayBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", hkArrayBinding::_DESTRUCTOR },
        { "clearAndDeallocate", hkArrayBinding::clearAndDeallocate },
        { 0, 0 }
    };

    registerClass(
        L, 
        hkArrayBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, hkArrayBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to hkArrayBase<T1>
    // setMetatableParent(L, hkArrayBinding::getMetatableName(), hkArrayBase<T1>Binding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua