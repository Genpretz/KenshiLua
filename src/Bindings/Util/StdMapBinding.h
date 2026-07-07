#pragma once
#include <map>
#include "Lua/BindingHelpers.h"
#include "Bindings/Util/OgreUnorderedBinding.h" // For LuaCodec

namespace KenshiLua
{
    // Generic Std Map Binding
    template <typename K, typename V,
              typename Compare = std::less<K>,
              typename Alloc = std::allocator<std::pair<const K, V> > >
    struct StdMapBinding
    {
        typedef std::map<K, V, Compare, Alloc> MapType;
        static const char* metaName;
        static const char* keyMetaName;
        static const char* valMetaName;

        static MapType* get(lua_State* L, int idx)
        {
            return checkObject<MapType>(L, idx, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int index(lua_State* L)
        {
            MapType* m = get(L, 1);
            if (!m) { lua_pushnil(L); return 1; }

            // If key is a string and matches a method name, route to metatable method
            if (lua_isstring(L, 2))
            {
                luaL_getmetatable(L, metaName);
                lua_getfield(L, -1, lua_tostring(L, 2));
                if (!lua_isnil(L, -1)) return 1;
                lua_pop(L, 2);
            }

            // Otherwise, route to key lookup
            K key = LuaCodec<K>::read(L, 2, keyMetaName);
            typename MapType::iterator it = m->find(key);
            if (it == m->end()) { lua_pushnil(L); return 1; }
            
            if (valMetaName)
            {
                // Return by pointer if element has a metatable
                return pushObject<V>(L, &it->second, valMetaName);
            }
            else
            {
                LuaCodec<V>::push(L, it->second, nullptr);
                return 1;
            }
        }

        static int newindex(lua_State* L)
        {
            MapType* m = get(L, 1);
            if (!m) return luaL_error(L, "map is nil");

            K key = LuaCodec<K>::read(L, 2, keyMetaName);

            // Setting value to nil erases the key
            if (lua_isnil(L, 3))
            {
                m->erase(key);
                return 0;
            }

            V val;
            if (valMetaName)
            {
                V* ptr = checkObject<V>(L, 3, valMetaName);
                if (!ptr) return luaL_error(L, "map: expected valid object for assignment");
                val = *ptr;
            }
            else
            {
                val = LuaCodec<V>::read(L, 3, nullptr);
            }

            (*m)[key] = val;
            return 0;
        }

        static int len(lua_State* L)
        {
            MapType* m = get(L, 1);
            lua_pushinteger(L, m ? (lua_Integer)m->size() : 0);
            return 1;
        }

        static int has(lua_State* L)
        {
            MapType* m = get(L, 1);
            if (!m) { lua_pushboolean(L, 0); return 1; }
            K key = LuaCodec<K>::read(L, 2, keyMetaName);
            lua_pushboolean(L, m->find(key) != m->end() ? 1 : 0);
            return 1;
        }

        static int remove(lua_State* L)
        {
            MapType* m = get(L, 1);
            if (!m) return luaL_error(L, "map is nil");
            K key = LuaCodec<K>::read(L, 2, keyMetaName);
            lua_pushboolean(L, m->erase(key) > 0 ? 1 : 0);
            return 1;
        }

        static int clear(lua_State* L)
        {
            MapType* m = get(L, 1);
            if (m) m->clear();
            return 0;
        }

        static int toTable(lua_State* L)
        {
            MapType* m = get(L, 1);
            if (!m) { lua_pushnil(L); return 1; }
            lua_newtable(L);
            for (typename MapType::const_iterator it = m->begin(); it != m->end(); ++it)
            {
                LuaCodec<K>::push(L, it->first, keyMetaName);
                if (valMetaName)
                {
                    pushObject<V>(L, const_cast<V*>(&it->second), valMetaName);
                }
                else
                {
                    LuaCodec<V>::push(L, it->second, nullptr);
                }
                lua_settable(L, -3);
            }
            return 1;
        }

        static void registerBinding(lua_State* L, const char* name, const char* keyName = nullptr, const char* valName = nullptr)
        {
            metaName = name;
            keyMetaName = keyName;
            valMetaName = valName;

            static const luaL_Reg meta[] = {
                { "__gc",       gc },
                { "__index",    index },
                { "__newindex", newindex },
                { "__len",      len },
                { 0, 0 }
            };
            static const luaL_Reg methods[] = {
                { "has",      has },
                { "remove",   remove },
                { "clear",    clear },
                { "toTable",  toTable },
                { "size",     len },
                { 0, 0 }
            };
            registerClass(L, metaName, meta, methods, index, newindex);
        }
    };

    template <typename K, typename V, typename Compare, typename Alloc>
    const char* StdMapBinding<K, V, Compare, Alloc>::metaName = nullptr;

    template <typename K, typename V, typename Compare, typename Alloc>
    const char* StdMapBinding<K, V, Compare, Alloc>::keyMetaName = nullptr;

    template <typename K, typename V, typename Compare, typename Alloc>
    const char* StdMapBinding<K, V, Compare, Alloc>::valMetaName = nullptr;
}
