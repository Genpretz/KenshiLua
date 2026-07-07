#pragma once
#include <vector>
#include <ogre/OgreMemoryAllocatorConfig.h>
#include "Lua/BindingHelpers.h"
#include "Bindings/Util/OgreUnorderedBinding.h" // For LuaCodec

namespace KenshiLua
{
    template <typename T>
    struct OgreVectorValueBinding
    {
        typedef typename Ogre::vector<T>::type VecType;
        static const char* metaName;
        static const char* elemMetaName;

        static VecType* get(lua_State* L, int idx)
        {
            return checkObject<VecType>(L, idx, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int len(lua_State* L)
        {
            VecType* vec = get(L, 1);
            lua_pushinteger(L, vec ? (lua_Integer)vec->size() : 0);
            return 1;
        }

        static int index(lua_State* L)
        {
            VecType* vec = get(L, 1);
            if (!vec) { lua_pushnil(L); return 1; }

            // Check if key is numeric (1-based index)
            if (lua_isnumber(L, 2))
            {
                size_t i = (size_t)lua_tointeger(L, 2);
                if (i < 1 || i > vec->size()) { lua_pushnil(L); return 1; }
                
                // Return by pointer if element is a class/struct, otherwise by value via LuaCodec
                if (elemMetaName)
                {
                    return pushObject<T>(L, &(*vec)[i - 1], elemMetaName);
                }
                else
                {
                    LuaCodec<T>::push(L, (*vec)[i - 1], nullptr);
                    return 1;
                }
            }

            // Fallback to methods in metatable
            luaL_getmetatable(L, metaName);
            lua_getfield(L, -1, luaL_checkstring(L, 2));
            return 1;
        }

        static int newindex(lua_State* L)
        {
            VecType* vec = get(L, 1);
            if (!vec) return luaL_error(L, "vector is nil");

            if (!lua_isnumber(L, 2))
                return luaL_error(L, "vector: only numeric indices are writable");

            size_t i = (size_t)lua_tointeger(L, 2);
            T val;
            if (elemMetaName)
            {
                T* ptr = checkObject<T>(L, 3, elemMetaName);
                if (!ptr) return luaL_error(L, "vector: expected valid object for assignment");
                val = *ptr;
            }
            else
            {
                val = LuaCodec<T>::read(L, 3, nullptr);
            }

            if (i >= 1 && i <= vec->size())
            {
                (*vec)[i - 1] = val;
                return 0;
            }
            if (i == vec->size() + 1)
            {
                vec->push_back(val);
                return 0;
            }
            return luaL_error(L, "vector: index %u out of range (size=%u)", i, (unsigned int)vec->size());
        }

        static int push_back(lua_State* L)
        {
            VecType* vec = get(L, 1);
            if (!vec) return luaL_error(L, "vector is nil");

            T val;
            if (elemMetaName)
            {
                T* ptr = checkObject<T>(L, 2, elemMetaName);
                if (!ptr) return luaL_error(L, "vector:push expected valid object");
                val = *ptr;
            }
            else
            {
                val = LuaCodec<T>::read(L, 2, nullptr);
            }

            vec->push_back(val);
            return 0;
        }

        static int clear(lua_State* L)
        {
            VecType* vec = get(L, 1);
            if (vec) vec->clear();
            return 0;
        }

        static int size(lua_State* L)
        {
            return len(L);
        }

        static void registerBinding(lua_State* L, const char* name, const char* elemName = nullptr)
        {
            metaName = name;
            elemMetaName = elemName;

            static const luaL_Reg meta[] = {
                { "__gc",       gc },
                { "__len",      len },
                { "__index",    index },
                { "__newindex", newindex },
                { 0, 0 }
            };
            static const luaL_Reg methods[] = {
                { "push",      push_back },
                { "clear",     clear },
                { "size",      size },
                { 0, 0 }
            };
            registerClass(L, metaName, meta, methods, index, newindex);
        }
    };

    template <typename T>
    const char* OgreVectorValueBinding<T>::metaName = nullptr;
    template <typename T>
    const char* OgreVectorValueBinding<T>::elemMetaName = nullptr;
}
