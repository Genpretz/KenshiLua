#pragma once
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Util/HandBinding.h"

#include <kenshi/util/hand.h>
#include <ogre/OgreVector2.h>
#include <ogre/OgreVector3.h>
#include <ogre/OgreVector4.h>
#include <ogre/OgreQuaternion.h>
#include <ogre/OgreColourValue.h>

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
                pushValue<T>(L, val, meta);
            } else {
                lua_pushnil(L);
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
                if (lua_isnoneornil(L, idx)) {
                    return nullptr;
                }
                if (!lua_islightuserdata(L, idx)) {
                    const char* msg = lua_pushfstring(L, "lightuserdata expected, got %s",
                        pushArgumentTypeName(L, idx));
                    luaL_argerror(L, idx, msg);
                    return nullptr;
                }
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
            HandBinding::push(L, val);
        }

        static hand read(lua_State* L, int idx, const char* meta)
        {
            hand* h = checkObject<hand>(L, idx, HandBinding::getMetatableName());
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
    struct LuaCodec<T, typename std::enable_if<(std::is_integral<T>::value || std::is_enum<T>::value) && !std::is_same<T, bool>::value>::type>
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

    // 7. Ogre::Vector2 type specialization
    template <>
    struct LuaCodec<Ogre::Vector2>
    {
        static void push(lua_State* L, const Ogre::Vector2& val, const char* meta)
        {
            pushVector2(L, val);
        }

        static Ogre::Vector2 read(lua_State* L, int idx, const char* meta)
        {
            Ogre::Vector2 v(0.0f, 0.0f);
            checkVector2(L, idx, v);
            return v;
        }
    };

    // 8. Ogre::Vector3 type specialization
    template <>
    struct LuaCodec<Ogre::Vector3>
    {
        static void push(lua_State* L, const Ogre::Vector3& val, const char* meta)
        {
            pushVector3(L, val);
        }

        static Ogre::Vector3 read(lua_State* L, int idx, const char* meta)
        {
            Ogre::Vector3 v(0.0f, 0.0f, 0.0f);
            checkVector3(L, idx, v);
            return v;
        }
    };

    // 9. Ogre::Vector4 type specialization
    template <>
    struct LuaCodec<Ogre::Vector4>
    {
        static void push(lua_State* L, const Ogre::Vector4& val, const char* meta)
        {
            pushVector4(L, val);
        }

        static Ogre::Vector4 read(lua_State* L, int idx, const char* meta)
        {
            Ogre::Vector4 v(0.0f, 0.0f, 0.0f, 0.0f);
            checkVector4(L, idx, v);
            return v;
        }
    };

    // 10. Ogre::Quaternion type specialization
    template <>
    struct LuaCodec<Ogre::Quaternion>
    {
        static void push(lua_State* L, const Ogre::Quaternion& val, const char* meta)
        {
            pushQuaternion(L, val);
        }

        static Ogre::Quaternion read(lua_State* L, int idx, const char* meta)
        {
            Ogre::Quaternion q(1.0f, 0.0f, 0.0f, 0.0f);
            checkQuaternion(L, idx, q);
            return q;
        }
    };

    // 11. Ogre::ColourValue type specialization
    template <>
    struct LuaCodec<Ogre::ColourValue>
    {
        static void push(lua_State* L, const Ogre::ColourValue& val, const char* meta)
        {
            pushColourValue(L, val);
        }

        static Ogre::ColourValue read(lua_State* L, int idx, const char* meta)
        {
            Ogre::ColourValue c(0.0f, 0.0f, 0.0f, 1.0f);
            checkColourValue(L, idx, c);
            return c;
        }
    };
}
