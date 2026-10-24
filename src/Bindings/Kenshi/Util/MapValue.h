#pragma once
#include <type_traits>
#include "Lua/BindingHelpers.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    // Converts a map value that has a metatable. A value stored by value is pushed as a
    // borrowed pointer into the map's storage, and assignment copies the checked object
    // into it. A pointer value already refers to its object, so the pointer itself is
    // pushed and stored; wrapping the address of the map slot would give Lua the slot,
    // and dereferencing the checked object would store its first bytes as the pointer.
    template <typename V, typename Enable = void>
    struct MapValue
    {
        static int push(lua_State* L, const V& value, const char* meta)
        {
            return pushObject<V>(L, const_cast<V*>(&value), meta);
        }

        static V read(lua_State* L, int idx, const char* meta)
        {
            return *checkObject<V>(L, idx, meta);
        }
    };

    template <typename V>
    struct MapValue<V, typename std::enable_if<std::is_pointer<V>::value>::type>
    {
        typedef typename std::remove_pointer<V>::type Object;

        static int push(lua_State* L, V value, const char* meta)
        {
            return pushObject<Object>(L, value, meta);
        }

        static V read(lua_State* L, int idx, const char* meta)
        {
            return checkObject<Object>(L, idx, meta);
        }
    };
}
