#pragma once
#include <kenshi/RootObject.h>
#include <kenshi/RootObjectFactory.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    typedef RootObjectFactory::CreatelistItem CreatelistItem;

class CreatelistItemBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CreatelistItem"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
};
}
