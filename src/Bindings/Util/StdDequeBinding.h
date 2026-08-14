#pragma once
#include <deque>
#include <type_traits>
#include <ogre/OgreMemoryAllocatorConfig.h>
#include "Lua/BindingHelpers.h"
#include "Lua/LuaCodec.h"

namespace KenshiLua
{
    // Std Deque Binding for Bound Value/Struct Types (T = CraftingItem, Character::RagdollMsg, etc.)
    template <typename T, typename Alloc = std::allocator<T>>
    struct StdDequeValueBinding
    {
        typedef std::deque<T, Alloc> DequeType;
        static const char* metaName;
        static const char* elemMetaName;

        static const char* getMetatableName() { return metaName; }

        static DequeType* get(lua_State* L, int idx)
        {
            return checkObject<DequeType>(L, idx, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int len(lua_State* L)
        {
            DequeType* d = get(L, 1);
            lua_pushinteger(L, d ? (lua_Integer)d->size() : 0);
            return 1;
        }

        static int index(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) { lua_pushnil(L); return 1; }

            if (lua_isnumber(L, 2))
            {
                size_t i = (size_t)lua_tointeger(L, 2);
                if (i < 1 || i > d->size()) { lua_pushnil(L); return 1; }
                return pushObject<T>(L, &(*d)[i - 1], elemMetaName);
            }

            luaL_getmetatable(L, metaName);
            lua_getfield(L, -1, luaL_checkstring(L, 2));
            return 1;
        }

        static int newindex(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) return luaL_error(L, "deque is nil");
            if (!lua_isnumber(L, 2)) return luaL_error(L, "deque: index must be numeric");

            size_t i = (size_t)lua_tointeger(L, 2);

            if (i >= 1 && i <= d->size())
            {
                if (lua_isnil(L, 3))
                    d->erase(d->begin() + (i - 1));
                else
                {
                    T* ptr = checkObject<T>(L, 3, elemMetaName);
                    if (!ptr) return luaL_error(L, "deque: expected valid object for assignment");
                    (*d)[i - 1] = *ptr;
                }
                return 0;
            }
            if (i == d->size() + 1)
            {
                if (!lua_isnil(L, 3))
                {
                    T* ptr = checkObject<T>(L, 3, elemMetaName);
                    if (!ptr) return luaL_error(L, "deque: expected valid object for assignment");
                    d->push_back(*ptr);
                }
                return 0;
            }
            return luaL_error(L, "deque: index %u out of range (size=%u)", (unsigned int)i, (unsigned int)d->size());
        }

        static int push_back(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) return luaL_error(L, "deque is nil");
            T* ptr = checkObject<T>(L, 2, elemMetaName);
            if (!ptr) return luaL_error(L, "deque: expected valid object for push");
            d->push_back(*ptr);
            return 0;
        }

        static int push_front(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) return luaL_error(L, "deque is nil");
            T* ptr = checkObject<T>(L, 2, elemMetaName);
            if (!ptr) return luaL_error(L, "deque: expected valid object for push_front");
            d->push_front(*ptr);
            return 0;
        }

        static int pop_back(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) return luaL_error(L, "deque is nil");
            if (d->empty()) return luaL_error(L, "deque is empty");
            T val = d->back();
            d->pop_back();
            return pushValue<T>(L, val, elemMetaName);
        }

        static int pop_front(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) return luaL_error(L, "deque is nil");
            if (d->empty()) return luaL_error(L, "deque is empty");
            T val = d->front();
            d->pop_front();
            return pushValue<T>(L, val, elemMetaName);
        }

        static int front(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d || d->empty()) { lua_pushnil(L); return 1; }
            return pushObject<T>(L, &d->front(), elemMetaName);
        }

        static int back(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d || d->empty()) { lua_pushnil(L); return 1; }
            return pushObject<T>(L, &d->back(), elemMetaName);
        }

        static int removeAt(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) return luaL_error(L, "deque is nil");
            size_t i = (size_t)luaL_checkinteger(L, 2);
            if (i < 1 || i > d->size()) return luaL_error(L, "deque: removeAt index out of range");
            d->erase(d->begin() + (i - 1));
            return 0;
        }

        static int clear(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (d) d->clear();
            return 0;
        }

        static int empty(lua_State* L)
        {
            DequeType* d = get(L, 1);
            lua_pushboolean(L, (!d || d->empty()) ? 1 : 0);
            return 1;
        }

        static int size(lua_State* L) { return len(L); }

        static int toTable(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) { lua_pushnil(L); return 1; }
            lua_createtable(L, (int)d->size(), 0);
            for (size_t i = 0; i < d->size(); ++i)
            {
                pushObject<T>(L, &(*d)[i], elemMetaName);
                lua_rawseti(L, -2, (int)(i + 1));
            }
            return 1;
        }

        static int iterNext(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) return 0;
            size_t i = (size_t)lua_tointeger(L, 2) + 1;
            if (i > d->size()) return 0;
            lua_pushinteger(L, (lua_Integer)i);
            pushObject<T>(L, &(*d)[i - 1], elemMetaName);
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

        static void registerBinding(lua_State* L, const char* name, const char* elemName)
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
                { "push_back",  push_back },
                { "push_front", push_front },
                { "push",       push_back },
                { "pop_back",   pop_back },
                { "pop_front",  pop_front },
                { "pop",        pop_back },
                { "front",      front },
                { "back",       back },
                { "removeAt",   removeAt },
                { "clear",      clear },
                { "empty",      empty },
                { "size",       size },
                { "toTable",    toTable },
                { 0, 0 }
            };
            registerClass(L, metaName, meta, methods, index, newindex);
        }
    };

    template <typename T, typename Alloc>
    const char* StdDequeValueBinding<T, Alloc>::metaName = nullptr;
    template <typename T, typename Alloc>
    const char* StdDequeValueBinding<T, Alloc>::elemMetaName = nullptr;


    // Std Deque Binding for Primitive Types (float, int, etc.)
    template <typename T, typename Alloc = std::allocator<T>>
    struct StdDequePrimitiveBinding
    {
        typedef std::deque<T, Alloc> DequeType;
        static const char* metaName;

        static const char* getMetatableName() { return metaName; }

        static DequeType* get(lua_State* L, int idx)
        {
            return checkObject<DequeType>(L, idx, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int len(lua_State* L)
        {
            DequeType* d = get(L, 1);
            lua_pushinteger(L, d ? (lua_Integer)d->size() : 0);
            return 1;
        }

        static int index(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) { lua_pushnil(L); return 1; }

            if (lua_isnumber(L, 2))
            {
                size_t i = (size_t)lua_tointeger(L, 2);
                if (i < 1 || i > d->size()) { lua_pushnil(L); return 1; }
                LuaCodec<T>::push(L, (*d)[i - 1], nullptr);
                return 1;
            }

            luaL_getmetatable(L, metaName);
            lua_getfield(L, -1, luaL_checkstring(L, 2));
            return 1;
        }

        static int newindex(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) return luaL_error(L, "deque is nil");
            if (!lua_isnumber(L, 2)) return luaL_error(L, "deque: index must be numeric");

            size_t i = (size_t)lua_tointeger(L, 2);

            if (i >= 1 && i <= d->size())
            {
                if (lua_isnil(L, 3))
                    d->erase(d->begin() + (i - 1));
                else
                    (*d)[i - 1] = LuaCodec<T>::read(L, 3, nullptr);
                return 0;
            }
            if (i == d->size() + 1)
            {
                if (!lua_isnil(L, 3))
                    d->push_back(LuaCodec<T>::read(L, 3, nullptr));
                return 0;
            }
            return luaL_error(L, "deque: index %u out of range (size=%u)", (unsigned int)i, (unsigned int)d->size());
        }

        static int push_back(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) return luaL_error(L, "deque is nil");
            d->push_back(LuaCodec<T>::read(L, 2, nullptr));
            return 0;
        }

        static int push_front(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) return luaL_error(L, "deque is nil");
            d->push_front(LuaCodec<T>::read(L, 2, nullptr));
            return 0;
        }

        static int pop_back(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) return luaL_error(L, "deque is nil");
            if (d->empty()) return luaL_error(L, "deque is empty");
            T val = d->back();
            d->pop_back();
            LuaCodec<T>::push(L, val, nullptr);
            return 1;
        }

        static int pop_front(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) return luaL_error(L, "deque is nil");
            if (d->empty()) return luaL_error(L, "deque is empty");
            T val = d->front();
            d->pop_front();
            LuaCodec<T>::push(L, val, nullptr);
            return 1;
        }

        static int front(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d || d->empty()) { lua_pushnil(L); return 1; }
            LuaCodec<T>::push(L, d->front(), nullptr);
            return 1;
        }

        static int back(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d || d->empty()) { lua_pushnil(L); return 1; }
            LuaCodec<T>::push(L, d->back(), nullptr);
            return 1;
        }

        static int removeAt(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) return luaL_error(L, "deque is nil");
            size_t i = (size_t)luaL_checkinteger(L, 2);
            if (i < 1 || i > d->size()) return luaL_error(L, "deque: removeAt index out of range");
            d->erase(d->begin() + (i - 1));
            return 0;
        }

        static int clear(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (d) d->clear();
            return 0;
        }

        static int empty(lua_State* L)
        {
            DequeType* d = get(L, 1);
            lua_pushboolean(L, (!d || d->empty()) ? 1 : 0);
            return 1;
        }

        static int size(lua_State* L) { return len(L); }

        static int toTable(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) { lua_pushnil(L); return 1; }
            lua_createtable(L, (int)d->size(), 0);
            for (size_t i = 0; i < d->size(); ++i)
            {
                LuaCodec<T>::push(L, (*d)[i], nullptr);
                lua_rawseti(L, -2, (int)(i + 1));
            }
            return 1;
        }

        static int iterNext(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) return 0;
            size_t i = (size_t)lua_tointeger(L, 2) + 1;
            if (i > d->size()) return 0;
            lua_pushinteger(L, (lua_Integer)i);
            LuaCodec<T>::push(L, (*d)[i - 1], nullptr);
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
                { "push_back",  push_back },
                { "push_front", push_front },
                { "push",       push_back },
                { "pop_back",   pop_back },
                { "pop_front",  pop_front },
                { "pop",        pop_back },
                { "front",      front },
                { "back",       back },
                { "removeAt",   removeAt },
                { "clear",      clear },
                { "empty",      empty },
                { "size",       size },
                { "toTable",    toTable },
                { 0, 0 }
            };
            registerClass(L, metaName, meta, methods, index, newindex);
        }
    };

    template <typename T, typename Alloc>
    const char* StdDequePrimitiveBinding<T, Alloc>::metaName = nullptr;


    // Std Deque Binding for Pointer Types (T = U*)
    template <typename T, typename Alloc = std::allocator<T>>
    struct StdDequePtrBinding
    {
        typedef typename std::remove_pointer<T>::type BaseType;
        typedef std::deque<T, Alloc> DequeType;
        static const char* metaName;
        static const char* elemMetaName;

        static const char* getMetatableName() { return metaName; }

        static DequeType* get(lua_State* L, int idx)
        {
            return checkObject<DequeType>(L, idx, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int len(lua_State* L)
        {
            DequeType* d = get(L, 1);
            lua_pushinteger(L, d ? (lua_Integer)d->size() : 0);
            return 1;
        }

        static int index(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) { lua_pushnil(L); return 1; }

            if (lua_isnumber(L, 2))
            {
                size_t i = (size_t)lua_tointeger(L, 2);
                if (i < 1 || i > d->size()) { lua_pushnil(L); return 1; }
                T val = (*d)[i - 1];
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
            DequeType* d = get(L, 1);
            if (!d) return luaL_error(L, "deque is nil");
            if (!lua_isnumber(L, 2)) return luaL_error(L, "deque: index must be numeric");

            size_t i = (size_t)lua_tointeger(L, 2);
            T val = nullptr;
            if (!lua_isnoneornil(L, 3))
            {
                if (elemMetaName)
                    val = checkObject<BaseType>(L, 3, elemMetaName);
                else if (lua_islightuserdata(L, 3))
                    val = (T)lua_touserdata(L, 3);
                else
                    return luaL_error(L, "deque: expected valid object or lightuserdata for assignment");
            }

            if (i >= 1 && i <= d->size())
            {
                if (lua_isnil(L, 3))
                    d->erase(d->begin() + (i - 1));
                else
                    (*d)[i - 1] = val;
                return 0;
            }
            if (i == d->size() + 1)
            {
                if (!lua_isnil(L, 3))
                    d->push_back(val);
                return 0;
            }
            return luaL_error(L, "deque: index %u out of range (size=%u)", (unsigned int)i, (unsigned int)d->size());
        }

        static int push_back(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) return luaL_error(L, "deque is nil");
            T val = nullptr;
            if (!lua_isnoneornil(L, 2))
            {
                if (elemMetaName)
                    val = checkObject<BaseType>(L, 2, elemMetaName);
                else if (lua_islightuserdata(L, 2))
                    val = (T)lua_touserdata(L, 2);
            }
            d->push_back(val);
            return 0;
        }

        static int push_front(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) return luaL_error(L, "deque is nil");
            T val = nullptr;
            if (!lua_isnoneornil(L, 2))
            {
                if (elemMetaName)
                    val = checkObject<BaseType>(L, 2, elemMetaName);
                else if (lua_islightuserdata(L, 2))
                    val = (T)lua_touserdata(L, 2);
            }
            d->push_front(val);
            return 0;
        }

        static int pop_back(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) return luaL_error(L, "deque is nil");
            if (d->empty()) return luaL_error(L, "deque is empty");
            T val = d->back();
            d->pop_back();
            if (!val) { lua_pushnil(L); return 1; }
            if (elemMetaName)
                return pushObject<BaseType>(L, val, elemMetaName);
            else
            {
                lua_pushlightuserdata(L, (void*)val);
                return 1;
            }
        }

        static int pop_front(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) return luaL_error(L, "deque is nil");
            if (d->empty()) return luaL_error(L, "deque is empty");
            T val = d->front();
            d->pop_front();
            if (!val) { lua_pushnil(L); return 1; }
            if (elemMetaName)
                return pushObject<BaseType>(L, val, elemMetaName);
            else
            {
                lua_pushlightuserdata(L, (void*)val);
                return 1;
            }
        }

        static int front(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d || d->empty()) { lua_pushnil(L); return 1; }
            T val = d->front();
            if (!val) { lua_pushnil(L); return 1; }
            if (elemMetaName)
                return pushObject<BaseType>(L, val, elemMetaName);
            else
            {
                lua_pushlightuserdata(L, (void*)val);
                return 1;
            }
        }

        static int back(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d || d->empty()) { lua_pushnil(L); return 1; }
            T val = d->back();
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
            DequeType* d = get(L, 1);
            if (!d) return luaL_error(L, "deque is nil");
            size_t i = (size_t)luaL_checkinteger(L, 2);
            if (i < 1 || i > d->size()) return luaL_error(L, "deque: removeAt index out of range");
            d->erase(d->begin() + (i - 1));
            return 0;
        }

        static int clear(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (d) d->clear();
            return 0;
        }

        static int empty(lua_State* L)
        {
            DequeType* d = get(L, 1);
            lua_pushboolean(L, (!d || d->empty()) ? 1 : 0);
            return 1;
        }

        static int size(lua_State* L) { return len(L); }

        static int toTable(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) { lua_pushnil(L); return 1; }
            lua_createtable(L, (int)d->size(), 0);
            for (size_t i = 0; i < d->size(); ++i)
            {
                T val = (*d)[i];
                if (val)
                {
                    if (elemMetaName)
                        pushObject<BaseType>(L, val, elemMetaName);
                    else
                        lua_pushlightuserdata(L, (void*)val);
                }
                else
                    lua_pushnil(L);
                lua_rawseti(L, -2, (int)(i + 1));
            }
            return 1;
        }

        static int iterNext(lua_State* L)
        {
            DequeType* d = get(L, 1);
            if (!d) return 0;
            size_t i = (size_t)lua_tointeger(L, 2) + 1;
            if (i > d->size()) return 0;
            lua_pushinteger(L, (lua_Integer)i);
            T val = (*d)[i - 1];
            if (val)
            {
                if (elemMetaName)
                    pushObject<BaseType>(L, val, elemMetaName);
                else
                    lua_pushlightuserdata(L, (void*)val);
            }
            else
                lua_pushnil(L);
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
                { "push_back",  push_back },
                { "push_front", push_front },
                { "push",       push_back },
                { "pop_back",   pop_back },
                { "pop_front",  pop_front },
                { "pop",        pop_back },
                { "front",      front },
                { "back",       back },
                { "removeAt",   removeAt },
                { "clear",      clear },
                { "empty",      empty },
                { "size",       size },
                { "toTable",    toTable },
                { 0, 0 }
            };
            registerClass(L, metaName, meta, methods, index, newindex);
        }
    };

    template <typename T, typename Alloc>
    const char* StdDequePtrBinding<T, Alloc>::metaName = nullptr;
    template <typename T, typename Alloc>
    const char* StdDequePtrBinding<T, Alloc>::elemMetaName = nullptr;
}
