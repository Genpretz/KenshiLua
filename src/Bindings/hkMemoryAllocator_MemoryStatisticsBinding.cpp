#include "pch.h"
#include "Bindings/hkMemoryAllocator_MemoryStatisticsBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static hkMemoryAllocator::MemoryStatistics* getInstance(lua_State* L, int idx)
{
    return checkObject<hkMemoryAllocator::MemoryStatistics>(L, idx, hkMemoryAllocator_MemoryStatisticsBinding::getMetatableName());
}

static int MemoryStatistics_get_m_allocated(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "hkMemoryAllocator::MemoryStatistics is nil");
    lua_pushnumber(L, (lua_Number)inst->m_allocated);
    return 1;
}

static int MemoryStatistics_get_m_inUse(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "hkMemoryAllocator::MemoryStatistics is nil");
    lua_pushnumber(L, (lua_Number)inst->m_inUse);
    return 1;
}

static int MemoryStatistics_get_m_peakInUse(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "hkMemoryAllocator::MemoryStatistics is nil");
    lua_pushnumber(L, (lua_Number)inst->m_peakInUse);
    return 1;
}

static int MemoryStatistics_get_m_available(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "hkMemoryAllocator::MemoryStatistics is nil");
    lua_pushnumber(L, (lua_Number)inst->m_available);
    return 1;
}

static int MemoryStatistics_get_m_totalAvailable(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "hkMemoryAllocator::MemoryStatistics is nil");
    lua_pushnumber(L, (lua_Number)inst->m_totalAvailable);
    return 1;
}

static int MemoryStatistics_get_m_largestBlock(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "hkMemoryAllocator::MemoryStatistics is nil");
    lua_pushnumber(L, (lua_Number)inst->m_largestBlock);
    return 1;
}

static int MemoryStatistics_set_m_allocated(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "hkMemoryAllocator::MemoryStatistics is nil");
    inst->m_allocated = (__int64)luaL_checknumber(L, 2);
    return 0;
}

static int MemoryStatistics_set_m_inUse(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "hkMemoryAllocator::MemoryStatistics is nil");
    inst->m_inUse = (__int64)luaL_checknumber(L, 2);
    return 0;
}

static int MemoryStatistics_set_m_peakInUse(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "hkMemoryAllocator::MemoryStatistics is nil");
    inst->m_peakInUse = (__int64)luaL_checknumber(L, 2);
    return 0;
}

static int MemoryStatistics_set_m_available(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "hkMemoryAllocator::MemoryStatistics is nil");
    inst->m_available = (__int64)luaL_checknumber(L, 2);
    return 0;
}

static int MemoryStatistics_set_m_totalAvailable(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "hkMemoryAllocator::MemoryStatistics is nil");
    inst->m_totalAvailable = (__int64)luaL_checknumber(L, 2);
    return 0;
}

static int MemoryStatistics_set_m_largestBlock(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "hkMemoryAllocator::MemoryStatistics is nil");
    inst->m_largestBlock = (__int64)luaL_checknumber(L, 2);
    return 0;
}

int hkMemoryAllocator_MemoryStatisticsBinding::_CONSTRUCTOR(lua_State* L)
{
    auto* obj = (hkMemoryAllocator::MemoryStatistics*)::operator new(sizeof(hkMemoryAllocator::MemoryStatistics));
    ::new ((void*)obj) hkMemoryAllocator::MemoryStatistics();
    return pushObject<hkMemoryAllocator::MemoryStatistics>(L, obj, getMetatableName());
}

int hkMemoryAllocator_MemoryStatisticsBinding::_DESTRUCTOR(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "hkMemoryAllocator::MemoryStatistics is nil");
    inst->~MemoryStatistics();
    return 0;
}

int hkMemoryAllocator_MemoryStatisticsBinding::gc(lua_State* L)
{
    return 0;
}

int hkMemoryAllocator_MemoryStatisticsBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.hkMemoryAllocator_MemoryStatistics object");
    return 1;
}

int hkMemoryAllocator_MemoryStatisticsBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a == b) ? 1 : 0);
    return 1;
}

void hkMemoryAllocator_MemoryStatisticsBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       operator_eq },
        { "__gc",       gc },
        { "__tostring", tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", _CONSTRUCTOR },
        { "_DESTRUCTOR",  _DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L); // __getters
    registerGetter(L, "m_allocated", MemoryStatistics_get_m_allocated);
    registerGetter(L, "m_inUse", MemoryStatistics_get_m_inUse);
    registerGetter(L, "m_peakInUse", MemoryStatistics_get_m_peakInUse);
    registerGetter(L, "m_available", MemoryStatistics_get_m_available);
    registerGetter(L, "m_totalAvailable", MemoryStatistics_get_m_totalAvailable);
    registerGetter(L, "m_largestBlock", MemoryStatistics_get_m_largestBlock);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "m_allocated", MemoryStatistics_set_m_allocated);
    registerSetter(L, "m_inUse", MemoryStatistics_set_m_inUse);
    registerSetter(L, "m_peakInUse", MemoryStatistics_set_m_peakInUse);
    registerSetter(L, "m_available", MemoryStatistics_set_m_available);
    registerSetter(L, "m_totalAvailable", MemoryStatistics_set_m_totalAvailable);
    registerSetter(L, "m_largestBlock", MemoryStatistics_set_m_largestBlock);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
