#include "pch.h"
#include "Bindings/hkContainerHeapAllocator_AllocatorBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static hkContainerHeapAllocator::Allocator* getInstance(lua_State* L, int idx)
{
    return checkObject<hkContainerHeapAllocator::Allocator>(L, idx, hkContainerHeapAllocator_AllocatorBinding::getMetatableName());
}

int hkContainerHeapAllocator_AllocatorBinding::_CONSTRUCTOR(lua_State* L)
{
    auto* obj = (hkContainerHeapAllocator::Allocator*)::operator new(sizeof(hkContainerHeapAllocator::Allocator));
    ::new ((void*)obj) hkContainerHeapAllocator::Allocator();
    return pushObject<hkContainerHeapAllocator::Allocator>(L, obj, getMetatableName());
}

int hkContainerHeapAllocator_AllocatorBinding::_DESTRUCTOR(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "hkContainerHeapAllocator::Allocator is nil");
    inst->~Allocator();
    return 0;
}

int hkContainerHeapAllocator_AllocatorBinding::gc(lua_State* L)
{
    return 0;
}

int hkContainerHeapAllocator_AllocatorBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.hkContainerHeapAllocator_Allocator object");
    return 1;
}

int hkContainerHeapAllocator_AllocatorBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a == b) ? 1 : 0);
    return 1;
}

void hkContainerHeapAllocator_AllocatorBinding::registerBinding(lua_State* L)
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

}
} // namespace KenshiLua
