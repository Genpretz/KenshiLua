#pragma once
#include "kenshi/Havok.h"

namespace KenshiLua
{
class hkMemoryAllocator_ExtendedInterfaceBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.hkMemoryAllocator_ExtendedInterface"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);
};
} // namespace KenshiLua
