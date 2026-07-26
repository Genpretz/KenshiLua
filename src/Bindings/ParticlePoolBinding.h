#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ParticlePoolBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ParticlePool"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int init(lua_State* L);
    static int destroy(lua_State* L);
    static int getSize(lua_State* L);
    static int update(lua_State* L);
    static int shiftParticles(lua_State* L);
};
}