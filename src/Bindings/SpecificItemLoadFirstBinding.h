#pragma once

#include "kenshi/RootObject.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    typedef RootObjectContainer::SpecificItemLoadFirst SpecificItemLoadFirst;

class SpecificItemLoadFirstBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.SpecificItemLoadFirst"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int shouldSkip(lua_State* L);
    static int _NV_shouldSkip(lua_State* L);
    static int flip(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}
