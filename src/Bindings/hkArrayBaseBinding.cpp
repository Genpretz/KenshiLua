#include "pch.h"
#include "kenshi\havok.h"
#include "hkArrayBaseBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static hkArrayBase* getInstance(lua_State* L, int idx)
{
    return checkObject<hkArrayBase>(L, idx, hkArrayBaseBinding::getMetatableName());
}

// --- Getters for hkArrayBase ---
static int hkArrayBase_get_m_data(lua_State* L)
{
    hkArrayBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkArrayBase is nil");
    lua_pushlightuserdata(L, (void*)instance->m_data);
    return 1;
}

static int hkArrayBase_get_m_size(lua_State* L)
{
    hkArrayBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkArrayBase is nil");
    lua_pushinteger(L, instance->m_size);
    return 1;
}

static int hkArrayBase_get_m_capacityAndFlags(lua_State* L)
{
    hkArrayBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkArrayBase is nil");
    lua_pushinteger(L, instance->m_capacityAndFlags);
    return 1;
}

// --- Setters for hkArrayBase ---
static int hkArrayBase_set_m_size(lua_State* L)
{
    hkArrayBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkArrayBase is nil");
    instance->m_size = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int hkArrayBase_set_m_capacityAndFlags(lua_State* L)
{
    hkArrayBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkArrayBase is nil");
    instance->m_capacityAndFlags = (int)luaL_checkinteger(L, 2);
    return 0;
}

int hkArrayBaseBinding::_CONSTRUCTOR(lua_State* L)
{
    hkArrayBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkArrayBase is nil");

    hkArrayBase<T1>* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int hkArrayBaseBinding::_DESTRUCTOR(lua_State* L)
{
    hkArrayBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkArrayBase is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int hkArrayBaseBinding::getSize(lua_State* L)
{
    hkArrayBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkArrayBase is nil");

    int result = instance->getSize();
    lua_pushinteger(L, result);
    return 1;
}

int hkArrayBaseBinding::getCapacity(lua_State* L)
{
    hkArrayBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkArrayBase is nil");

    int result = instance->getCapacity();
    lua_pushinteger(L, result);
    return 1;
}

int hkArrayBaseBinding::clear(lua_State* L)
{
    hkArrayBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkArrayBase is nil");

    instance->clear();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 592: const T1& operator[](...) - operator
  line 593: T1& operator[](...) - operator
  line 594: const T1& back(...) - reference return type
  line 598: hkBool isEmpty(...) - unsupported return type
  line 600: void _clearAndDeallocate(...) - unsupported arg type
  line 608: void _pushBack(...) - unsupported arg type
  line 610: hkResult _reserve(...) - unsupported return type
  line 625: void _spliceInto(...) - unsupported arg type
  line 634: void copy(...) - static method
  line 640: hkArrayBase<T1>& copyFromArray(...) - reference return type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - hkArrayBase_get_m_data: T1* (unbound pointer)
  - hkArrayBaseBinding::_CONSTRUCTOR: hkArrayBase<T1>* (unbound pointer)
*/

int hkArrayBaseBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int hkArrayBaseBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.hkArrayBase object");
    return 1;
}

void hkArrayBaseBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       hkArrayBaseBinding::gc },
        { "__tostring", hkArrayBaseBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", hkArrayBaseBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", hkArrayBaseBinding::_DESTRUCTOR },
        { "getSize", hkArrayBaseBinding::getSize },
        { "getCapacity", hkArrayBaseBinding::getCapacity },
        { "clear", hkArrayBaseBinding::clear },
        { 0, 0 }
    };

    registerClass(
        L, 
        hkArrayBaseBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, hkArrayBaseBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "m_data", hkArrayBase_get_m_data);
    registerGetter(L, "m_size", hkArrayBase_get_m_size);
    registerGetter(L, "m_capacityAndFlags", hkArrayBase_get_m_capacityAndFlags);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "m_size", hkArrayBase_set_m_size);
    registerSetter(L, "m_capacityAndFlags", hkArrayBase_set_m_capacityAndFlags);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua