#include "pch.h"
#include "Bindings/hkMemoryAllocator_ExtendedInterfaceBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static hkMemoryAllocator::ExtendedInterface* getInstance(lua_State* L, int idx)
{
    return checkObject<hkMemoryAllocator::ExtendedInterface>(L, idx, hkMemoryAllocator_ExtendedInterfaceBinding::getMetatableName());
}

int hkMemoryAllocator_ExtendedInterfaceBinding::gc(lua_State* L)
{
    return 0;
}

int hkMemoryAllocator_ExtendedInterfaceBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.hkMemoryAllocator_ExtendedInterface object");
    return 1;
}

int hkMemoryAllocator_ExtendedInterfaceBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a == b) ? 1 : 0);
    return 1;
}

void hkMemoryAllocator_ExtendedInterfaceBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       operator_eq },
        { "__gc",       gc },
        { "__tostring", tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

}
} // namespace KenshiLua
