#pragma once
#include <set>
#include <ogre/OgreMemoryAllocatorConfig.h>
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
    // Generic Std Set Binding
    //
    // Alloc defaults to the Ogre::STLAllocator<T, GeneralAllocPolicy> convention.
    template <typename T,
              typename Compare = std::less<T>,
              typename Alloc = Ogre::STLAllocator<T, Ogre::GeneralAllocPolicy> >
    struct StdSetBinding
    {
        typedef std::set<T, Compare, Alloc> SetType;
        static const char* metaName;
        static const char* elemMetaName;

        static const char* getMetatableName() { return metaName; }

        static SetType* get(lua_State* L, int idx)
        {
            return checkObject<SetType>(L, idx, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int index(lua_State* L)
        {
            SetType* s = get(L, 1);
            if (!s) { lua_pushnil(L); return 1; }

            // Route to metatable methods if key is string matching a method
            if (lua_isstring(L, 2))
            {
                luaL_getmetatable(L, metaName);
                lua_getfield(L, -1, lua_tostring(L, 2));
                if (!lua_isnil(L, -1)) return 1;
                lua_pop(L, 2);
            }

            // Otherwise, check containment for elements
            T elem = LuaCodec<T>::read(L, 2, elemMetaName);
            lua_pushboolean(L, s->find(elem) != s->end() ? 1 : 0);
            return 1;
        }

        static int newindex(lua_State* L)
        {
            SetType* s = get(L, 1);
            if (!s) return luaL_error(L, "set is nil");

            T elem = LuaCodec<T>::read(L, 2, elemMetaName);

            // boolean value dictates inclusion/exclusion (or nil to erase)
            bool add = lua_toboolean(L, 3) != 0;
            if (lua_isnil(L, 3)) add = false;

            if (add)
                s->insert(elem);
            else
                s->erase(elem);

            return 0;
        }

        static int len(lua_State* L)
        {
            SetType* s = get(L, 1);
            lua_pushinteger(L, s ? (lua_Integer)s->size() : 0);
            return 1;
        }

        static int has(lua_State* L)
        {
            SetType* s = get(L, 1);
            if (!s) { lua_pushboolean(L, 0); return 1; }
            T elem = LuaCodec<T>::read(L, 2, elemMetaName);
            lua_pushboolean(L, s->find(elem) != s->end() ? 1 : 0);
            return 1;
        }

        static int insert(lua_State* L)
        {
            SetType* s = get(L, 1);
            if (!s) return luaL_error(L, "set is nil");
            T elem = LuaCodec<T>::read(L, 2, elemMetaName);
            s->insert(elem);
            return 0;
        }

        static int remove(lua_State* L)
        {
            SetType* s = get(L, 1);
            if (!s) return luaL_error(L, "set is nil");
            T elem = LuaCodec<T>::read(L, 2, elemMetaName);
            lua_pushboolean(L, s->erase(elem) > 0 ? 1 : 0);
            return 1;
        }

        static int clear(lua_State* L)
        {
            SetType* s = get(L, 1);
            if (s) s->clear();
            return 0;
        }

        static int toTable(lua_State* L)
        {
            SetType* s = get(L, 1);
            if (!s) { lua_pushnil(L); return 1; }
            lua_createtable(L, (int)s->size(), 0);
            int idx = 1;
            for (typename SetType::const_iterator it = s->begin(); it != s->end(); ++it, ++idx)
            {
                LuaCodec<T>::push(L, *it, elemMetaName);
                lua_rawseti(L, -2, idx);
            }
            return 1;
        }

        // Stateful iterator: upvalue 1 = skip count
        static int iterNext(lua_State* L)
        {
            SetType* s = get(L, 1);
            if (!s) return 0;
            int skip = (int)lua_tointeger(L, lua_upvalueindex(1));
            typename SetType::const_iterator it = s->begin();
            for (int i = 0; i < skip && it != s->end(); ++i, ++it) {}
            if (it == s->end()) return 0;

            lua_pushinteger(L, skip + 1);
            lua_replace(L, lua_upvalueindex(1));

            LuaCodec<T>::push(L, *it, elemMetaName);
            return 1;
        }

        static int pairs(lua_State* L)
        {
            lua_pushinteger(L, 0);
            lua_pushcclosure(L, iterNext, 1);
            lua_pushvalue(L, 1);
            lua_pushnil(L);
            return 3;
        }

        static void registerBinding(lua_State* L, const char* name, const char* elemName = nullptr)
        {
            metaName = name;
            elemMetaName = elemName;

            static const luaL_Reg meta[] = {
                { "__gc",       gc },
                { "__index",    index },
                { "__newindex", newindex },
                { "__len",      len },
                { "__pairs",    pairs },
                { "__ipairs",   pairs },
                { 0, 0 }
            };
            static const luaL_Reg methods[] = {
                { "has",      has },
                { "insert",   insert },
                { "remove",   remove },
                { "clear",    clear },
                { "toTable",  toTable },
                { "size",     len },
                { 0, 0 }
            };
            registerClass(L, metaName, meta, methods, index, newindex);
        }
    };

    template <typename T, typename Compare, typename Alloc>
    const char* StdSetBinding<T, Compare, Alloc>::metaName = nullptr;

    template <typename T, typename Compare, typename Alloc>
    const char* StdSetBinding<T, Compare, Alloc>::elemMetaName = nullptr;
}
