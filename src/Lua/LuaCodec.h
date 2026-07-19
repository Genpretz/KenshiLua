#pragma once
#include "Lua/BindingHelpers.h"
#include "Bindings/Util/HandBinding.h"

#include <kenshi/util/hand.h>
#include <ogre/OgreVector3.h>
#include <ogre/OgreQuaternion.h>

#include <type_traits>
#include <string>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    // Generic LuaCodec for mapping types to/from Lua State.
    template <typename T, typename Enable = void>
    struct LuaCodec
    {
        static void push(lua_State* L, const T& val, const char* meta)
        {
            if (meta) {
                pushObject<T>(L, const_cast<T*>(&val), meta);
            }
        }

        static T read(lua_State* L, int idx, const char* meta)
        {
            if (meta) {
                T* ptr = checkObject<T>(L, idx, meta);
                return ptr ? *ptr : T();
            }
            return T();
        }
    };

    // 1. Pointer type specialization
    template <typename T>
    struct LuaCodec<T, typename std::enable_if<std::is_pointer<T>::value>::type>
    {
        static void push(lua_State* L, T val, const char* meta)
        {
            if (meta) {
                pushObject<typename std::remove_pointer<T>::type>(L, val, meta);
            } else {
                if (val) {
                    lua_pushlightuserdata(L, (void*)val);
                } else {
                    lua_pushnil(L);
                }
            }
        }

        static T read(lua_State* L, int idx, const char* meta)
        {
            if (meta) {
                return checkObject<typename std::remove_pointer<T>::type>(L, idx, meta);
            } else {
                return (T)lua_touserdata(L, idx);
            }
        }
    };

    // 2. hand type specialization
    template <>
    struct LuaCodec<hand>
    {
        static void push(lua_State* L, const hand& val, const char* meta)
        {
            handBinding::push(L, val);
        }

        static hand read(lua_State* L, int idx, const char* meta)
        {
            hand* h = checkObject<hand>(L, idx, "KenshiLua.hand");
            return h ? *h : hand();
        }
    };

    // 3. Floating point type specialization
    template <typename T>
    struct LuaCodec<T, typename std::enable_if<std::is_floating_point<T>::value>::type>
    {
        static void push(lua_State* L, T val, const char* meta)
        {
            lua_pushnumber(L, (lua_Number)val);
        }

        static T read(lua_State* L, int idx, const char* meta)
        {
            return (T)luaL_checknumber(L, idx);
        }
    };

    // 4. Integral / Enum type specialization (excluding bool)
    template <typename T>
    struct LuaCodec<T, typename std::enable_if<std::is_integral<T>::value && !std::is_same<T, bool>::value>::type>
    {
        static void push(lua_State* L, T val, const char* meta)
        {
            lua_pushinteger(L, (lua_Integer)val);
        }

        static T read(lua_State* L, int idx, const char* meta)
        {
            return (T)luaL_checkinteger(L, idx);
        }
    };

    // 5. Bool type specialization
    template <>
    struct LuaCodec<bool>
    {
        static void push(lua_State* L, bool val, const char* meta)
        {
            lua_pushboolean(L, val ? 1 : 0);
        }

        static bool read(lua_State* L, int idx, const char* meta)
        {
            return lua_toboolean(L, idx) != 0;
        }
    };

    // 6. std::string type specialization
    template <>
    struct LuaCodec<std::string>
    {
        static void push(lua_State* L, const std::string& val, const char* meta)
        {
            lua_pushlstring(L, val.c_str(), val.size());
        }

        static std::string read(lua_State* L, int idx, const char* meta)
        {
            const char* str = luaL_checkstring(L, idx);
            return str ? std::string(str) : std::string();
        }
    };

    // 7. Ogre::Vector3 type specialization
    template <>
    struct LuaCodec<Ogre::Vector3>
    {
        static void push(lua_State* L, const Ogre::Vector3& val, const char* meta)
        {
            pushVector3(L, val);
        }

        static Ogre::Vector3 read(lua_State* L, int idx, const char* meta)
        {
            Ogre::Vector3 v;
            readVector3(L, idx, v);
            return v;
        }
    };

    // 8. Ogre::Quaternion type specialization
    template <>
    struct LuaCodec<Ogre::Quaternion>
    {
        static void push(lua_State* L, const Ogre::Quaternion& val, const char* meta)
        {
            pushQuaternion(L, val);
        }

        static Ogre::Quaternion read(lua_State* L, int idx, const char* meta)
        {
            Ogre::Quaternion q;
            readQuaternion(L, idx, q);
            return q;
        }
    };
}
