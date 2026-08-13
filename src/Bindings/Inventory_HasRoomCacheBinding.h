#pragma once
#include <kenshi/Inventory.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    typedef Inventory::HasRoomCache HasRoomCache;

class Inventory_HasRoomCacheBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Inventory_HasRoomCache"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int modified(lua_State* L);
    static int knowsAbout(lua_State* L);
    static int hasRoomFor(lua_State* L);
    static int remember(lua_State* L);
};
}
