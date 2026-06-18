#pragma once

#include <string>
#include <cstddef>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

class hand;
std::size_t hash_value(const hand& h);

namespace KenshiLua
{

class HandBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.hand"; }
    static void registerBinding(lua_State* L);

    // Constructs a new hand userdata in-place (placement-new) wrapping a copy
    // of `h`.  Always pushes one value.  Returns 1.
    static int pushHand(lua_State* L, const hand& h);

    // Metamethods
    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int eq(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    // Field accessors (read-only)
    static int isValid(lua_State* L);
    static int isNull(lua_State* L);
    static int getType(lua_State* L);
    static int getIndex(lua_State* L);
    static int getSerial(lua_State* L);
    static int getContainer(lua_State* L);
    static int getContainerSerial(lua_State* L);

    // Resolvers (use KenshiLib's built-in hand->object lookup)
    static int getCharacter(lua_State* L);
    static int getPlatoon(lua_State* L);
    static int getBuilding(lua_State* L);
    static int getItem(lua_State* L);
    static int getTown(lua_State* L);
};

} // namespace KenshiLua
