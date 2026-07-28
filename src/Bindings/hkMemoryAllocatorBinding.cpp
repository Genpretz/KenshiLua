#include "pch.h"
#include "kenshi\havok.h"
#include "hkMemoryAllocatorBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static hkMemoryAllocator* getInstance(lua_State* L, int idx)
{
    return checkObject<hkMemoryAllocator>(L, idx, hkMemoryAllocatorBinding::getMetatableName());
}

// --- Getters for hkMemoryAllocator ---
// --- Setters for hkMemoryAllocator ---
int hkMemoryAllocatorBinding::_DESTRUCTOR(lua_State* L)
{
    hkMemoryAllocator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkMemoryAllocator is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int hkMemoryAllocatorBinding::blockAlloc(lua_State* L)
{
    hkMemoryAllocator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkMemoryAllocator is nil");

    int _a1 = (int)luaL_checkinteger(L, 2);
    instance->blockAlloc(_a1);
    return 0;
}

int hkMemoryAllocatorBinding::resetPeakMemoryStatistics(lua_State* L)
{
    hkMemoryAllocator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkMemoryAllocator is nil");

    instance->resetPeakMemoryStatistics();
    return 0;
}

int hkMemoryAllocatorBinding::_NV_resetPeakMemoryStatistics(lua_State* L)
{
    hkMemoryAllocator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkMemoryAllocator is nil");

    instance->_NV_resetPeakMemoryStatistics();
    return 0;
}

int hkMemoryAllocatorBinding::getExtendedInterface(lua_State* L)
{
    hkMemoryAllocator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkMemoryAllocator is nil");

    hkMemoryAllocator::ExtendedInterface* result = instance->getExtendedInterface();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int hkMemoryAllocatorBinding::_NV_getExtendedInterface(lua_State* L)
{
    hkMemoryAllocator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkMemoryAllocator is nil");

    hkMemoryAllocator::ExtendedInterface* result = instance->_NV_getExtendedInterface();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int hkMemoryAllocatorBinding::_CONSTRUCTOR(lua_State* L)
{
    hkMemoryAllocator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkMemoryAllocator is nil");

    hkMemoryAllocator* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 426: void operator delete(...) - static method
  line 469: void blockFree(...) - unsupported arg type
  line 470: void* bufAlloc(...) - non-string reference arg
  line 471: void* _NV_bufAlloc(...) - non-string reference arg
  line 472: void bufFree(...) - unsupported arg type
  line 473: void _NV_bufFree(...) - unsupported arg type
  line 474: void* bufRealloc(...) - unsupported arg type
  line 475: void* _NV_bufRealloc(...) - unsupported arg type
  line 476: void blockAllocBatch(...) - unsupported arg type
  line 477: void _NV_blockAllocBatch(...) - unsupported arg type
  line 478: void blockFreeBatch(...) - unsupported arg type
  line 479: void _NV_blockFreeBatch(...) - unsupported arg type
  line 480: void getMemoryStatistics(...) - non-string reference arg
  line 481: int getAllocatedSize(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - hkMemoryAllocatorBinding::blockAlloc: void* (unbound pointer)
  - hkMemoryAllocatorBinding::getExtendedInterface: hkMemoryAllocator::ExtendedInterface* (unbound pointer)
  - hkMemoryAllocatorBinding::_NV_getExtendedInterface: hkMemoryAllocator::ExtendedInterface* (unbound pointer)
  - hkMemoryAllocatorBinding::_CONSTRUCTOR: hkMemoryAllocator* (unbound pointer)
*/

int hkMemoryAllocatorBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int hkMemoryAllocatorBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.hkMemoryAllocator object");
    return 1;
}

void hkMemoryAllocatorBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       hkMemoryAllocatorBinding::gc },
        { "__tostring", hkMemoryAllocatorBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", hkMemoryAllocatorBinding::_DESTRUCTOR },
        { "blockAlloc", hkMemoryAllocatorBinding::blockAlloc },
        { "resetPeakMemoryStatistics", hkMemoryAllocatorBinding::resetPeakMemoryStatistics },
        { "_NV_resetPeakMemoryStatistics", hkMemoryAllocatorBinding::_NV_resetPeakMemoryStatistics },
        { "getExtendedInterface", hkMemoryAllocatorBinding::getExtendedInterface },
        { "_NV_getExtendedInterface", hkMemoryAllocatorBinding::_NV_getExtendedInterface },
        { "_CONSTRUCTOR", hkMemoryAllocatorBinding::_CONSTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        hkMemoryAllocatorBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, hkMemoryAllocatorBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua