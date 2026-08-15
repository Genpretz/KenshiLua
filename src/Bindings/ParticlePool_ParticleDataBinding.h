#pragma once

#include "kenshi/ZoneManager.h"
namespace KenshiLua
{
class ParticlePool_ParticleDataBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ParticlePool_ParticleData"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);
};
} // namespace KenshiLua
