#pragma once
#include <vector>
#include <ogre/OgreMemoryAllocatorConfig.h>
#include "Lua/BindingHelpers.h"

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

        static int pop(lua_State* L)
        {
            VecType* vec = get(L, 1);
            if (!vec) return luaL_error(L, "vector is nil");
            if (vec->empty()) return luaL_error(L, "vector:pop container is empty");
            T val = vec->back();
            vec->pop_back();
            if (elemMetaName)
            {
                return pushValue<T>(L, val, elemMetaName);
            }
            else
            {
                LuaCodec<T>::push(L, val, nullptr);
                return 1;
            }
        }

        static int removeAt(lua_State* L)
        {
            VecType* vec = get(L, 1);
            if (!vec) return luaL_error(L, "vector is nil");
            size_t i = (size_t)luaL_checkinteger(L, 2);
            if (i < 1 || i > vec->size()) return luaL_error(L, "vector:removeAt index out of range");
            vec->erase(vec->begin() + (i - 1));
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

        static int toTable(lua_State* L)
        {
            VecType* vec = get(L, 1);
            if (!vec) { lua_pushnil(L); return 1; }
            lua_createtable(L, (int)vec->size(), 0);
            for (size_t i = 0; i < vec->size(); ++i)
            {
                if (elemMetaName)
                    pushObject<T>(L, &(*vec)[i], elemMetaName);
                else
                    LuaCodec<T>::push(L, (*vec)[i], nullptr);
                lua_rawseti(L, -2, (int)(i + 1));
            }
            return 1;
        }

        // Stateless iterator for __pairs/__ipairs: upvalue=none, control=integer index
        static int iterNext(lua_State* L)
        {
            VecType* vec = get(L, 1);
            if (!vec) return 0;
            size_t i = (size_t)lua_tointeger(L, 2); // current control (0-based previous)
            i += 1; // advance to next (1-based)
            if (i > vec->size()) return 0;
            lua_pushinteger(L, (lua_Integer)i);
            if (elemMetaName)
                pushObject<T>(L, &(*vec)[i - 1], elemMetaName);
            else
                LuaCodec<T>::push(L, (*vec)[i - 1], nullptr);
            return 2;
        }

        static int pairs(lua_State* L)
        {
            lua_pushcfunction(L, iterNext);
            lua_pushvalue(L, 1);
            lua_pushinteger(L, 0);
            return 3;
        }

        static int ipairs(lua_State* L)
        {
            return pairs(L); // same semantics for sequential container
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
                { "__pairs",    pairs },
                { "__ipairs",   ipairs },
                { 0, 0 }
            };
            static const luaL_Reg methods[] = {
                { "push",      push_back },
                { "pop",       pop },
                { "removeAt",  removeAt },
                { "clear",     clear },
                { "size",      size },
                { "toTable",   toTable },
                { 0, 0 }
            };
            registerClass(L, metaName, meta, methods, index, newindex);
        }
    };

    template <typename T>
    const char* OgreVectorValueBinding<T>::metaName = nullptr;
    template <typename T>
    const char* OgreVectorValueBinding<T>::elemMetaName = nullptr;

    // Ogre Vector Binding for Pointer Types (T is U*)
    template <typename T>
    struct OgreVectorPtrBinding
    {
        typedef typename std::remove_pointer<T>::type BaseType;
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

            if (lua_isnumber(L, 2))
            {
                size_t i = (size_t)lua_tointeger(L, 2);
                if (i < 1 || i > vec->size()) { lua_pushnil(L); return 1; }
                T val = (*vec)[i - 1];
                if (!val) { lua_pushnil(L); return 1; }
                if (elemMetaName)
                    return pushObject<BaseType>(L, val, elemMetaName);
                else
                {
                    lua_pushlightuserdata(L, (void*)val);
                    return 1;
                }
            }

            luaL_getmetatable(L, metaName);
            lua_getfield(L, -1, luaL_checkstring(L, 2));
            return 1;
        }

        static int newindex(lua_State* L)
        {
            VecType* vec = get(L, 1);
            if (!vec) return luaL_error(L, "vector is nil");
            if (!lua_isnumber(L, 2)) return luaL_error(L, "vector: index must be numeric");

            size_t i = (size_t)lua_tointeger(L, 2);
            T val = nullptr;
            if (!lua_isnoneornil(L, 3))
            {
                if (elemMetaName)
                    val = checkObject<BaseType>(L, 3, elemMetaName);
                else if (lua_islightuserdata(L, 3))
                    val = (T)lua_touserdata(L, 3);
                else
                    return luaL_error(L, "vector: expected valid object or lightuserdata for assignment");
            }

            if (i >= 1 && i <= vec->size())
            {
                if (lua_isnil(L, 3))
                    vec->erase(vec->begin() + (i - 1));
                else
                    (*vec)[i - 1] = val;
                return 0;
            }
            if (i == vec->size() + 1)
            {
                if (!lua_isnil(L, 3))
                    vec->push_back(val);
                return 0;
            }
            return luaL_error(L, "vector: index %u out of range (size=%u)", (unsigned int)i, (unsigned int)vec->size());
        }

        static int push_back(lua_State* L)
        {
            VecType* vec = get(L, 1);
            if (!vec) return luaL_error(L, "vector is nil");
            T val = nullptr;
            if (!lua_isnoneornil(L, 2))
            {
                if (elemMetaName)
                    val = checkObject<BaseType>(L, 2, elemMetaName);
                else if (lua_islightuserdata(L, 2))
                    val = (T)lua_touserdata(L, 2);
            }
            vec->push_back(val);
            return 0;
        }

        static int pop(lua_State* L)
        {
            VecType* vec = get(L, 1);
            if (!vec) return luaL_error(L, "vector is nil");
            if (vec->empty()) return luaL_error(L, "vector:pop container is empty");
            T val = vec->back();
            vec->pop_back();
            if (!val) { lua_pushnil(L); return 1; }
            if (elemMetaName)
                return pushObject<BaseType>(L, val, elemMetaName);
            else
            {
                lua_pushlightuserdata(L, (void*)val);
                return 1;
            }
        }

        static int removeAt(lua_State* L)
        {
            VecType* vec = get(L, 1);
            if (!vec) return luaL_error(L, "vector is nil");
            size_t i = (size_t)luaL_checkinteger(L, 2);
            if (i < 1 || i > vec->size()) return luaL_error(L, "vector:removeAt index out of range");
            vec->erase(vec->begin() + (i - 1));
            return 0;
        }

        static int clear(lua_State* L)
        {
            VecType* vec = get(L, 1);
            if (vec) vec->clear();
            return 0;
        }

        static int size(lua_State* L) { return len(L); }

        static int toTable(lua_State* L)
        {
            VecType* vec = get(L, 1);
            if (!vec) { lua_pushnil(L); return 1; }
            lua_createtable(L, (int)vec->size(), 0);
            for (size_t i = 0; i < vec->size(); ++i)
            {
                T val = (*vec)[i];
                if (!val)
                    lua_pushnil(L);
                else if (elemMetaName)
                    pushObject<BaseType>(L, val, elemMetaName);
                else
                    lua_pushlightuserdata(L, (void*)val);
                lua_rawseti(L, -2, (int)(i + 1));
            }
            return 1;
        }

        static int iterNext(lua_State* L)
        {
            VecType* vec = get(L, 1);
            if (!vec) return 0;
            size_t i = (size_t)lua_tointeger(L, 2) + 1;
            if (i > vec->size()) return 0;
            lua_pushinteger(L, (lua_Integer)i);
            T val = (*vec)[i - 1];
            if (!val)
                lua_pushnil(L);
            else if (elemMetaName)
                pushObject<BaseType>(L, val, elemMetaName);
            else
                lua_pushlightuserdata(L, (void*)val);
            return 2;
        }

        static int pairs(lua_State* L)
        {
            lua_pushcfunction(L, iterNext);
            lua_pushvalue(L, 1);
            lua_pushinteger(L, 0);
            return 3;
        }

        static int ipairs(lua_State* L) { return pairs(L); }

        static void registerBinding(lua_State* L, const char* name, const char* elemName = nullptr)
        {
            metaName = name;
            elemMetaName = elemName;

            static const luaL_Reg meta[] = {
                { "__gc",       gc },
                { "__len",      len },
                { "__index",    index },
                { "__newindex", newindex },
                { "__pairs",    pairs },
                { "__ipairs",   ipairs },
                { 0, 0 }
            };
            static const luaL_Reg methods[] = {
                { "push",      push_back },
                { "pop",       pop },
                { "removeAt",  removeAt },
                { "clear",     clear },
                { "size",      size },
                { "toTable",   toTable },
                { 0, 0 }
            };
            registerClass(L, metaName, meta, methods, index, newindex);
        }
    };

    template <typename T>
    const char* OgreVectorPtrBinding<T>::metaName = nullptr;
    template <typename T>
    const char* OgreVectorPtrBinding<T>::elemMetaName = nullptr;
}
