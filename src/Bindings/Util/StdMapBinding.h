#pragma once
#include <map>
#include <ogre/OgreMemoryAllocatorConfig.h>
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
    // Generic Std Map Binding
    //
    // Alloc defaults to the Ogre::STLAllocator<..., GeneralAllocPolicy> convention
    // used by every std::map member field in this codebase (see e.g. GameData.h).
    // This means most call sites only need to specify K and V - see GameDataBinding.cpp.
    // If a field ever uses a different allocation policy, override Alloc explicitly
    // at that call site; do NOT assume the default without checking the field's
    // actual declared type, since checkObject<T> performs an unchecked cast and a
    // mismatched Alloc/Compare will silently corrupt memory rather than fail loudly.
    template <typename K, typename V,
              typename Compare = std::less<K>,
              typename Alloc = Ogre::STLAllocator<std::pair<const K, V>, Ogre::GeneralAllocPolicy> >
    struct StdMapBinding
    {
        typedef std::map<K, V, Compare, Alloc> MapType;
        static const char* metaName;
        static const char* keyMetaName;
        static const char* valMetaName;

        static const char* getMetatableName() { return metaName; }

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
            lua_createtable(L, 0, (int)m->size());
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

        // Stateful iterator: upvalue 1 = skip count (how many to skip from begin)
        static int iterNext(lua_State* L)
        {
            MapType* m = get(L, 1);
            if (!m) return 0;
            int skip = (int)lua_tointeger(L, lua_upvalueindex(1));
            typename MapType::const_iterator it = m->begin();
            for (int s = 0; s < skip && it != m->end(); ++s, ++it) {}
            if (it == m->end()) return 0;
            // Update skip count for next call
            lua_pushinteger(L, skip + 1);
            lua_replace(L, lua_upvalueindex(1));
            // Push key, value
            LuaCodec<K>::push(L, it->first, keyMetaName);
            if (valMetaName)
                pushObject<V>(L, const_cast<V*>(&it->second), valMetaName);
            else
                LuaCodec<V>::push(L, it->second, nullptr);
            return 2;
        }

        static int pairs(lua_State* L)
        {
            lua_pushinteger(L, 0); // initial skip = 0
            lua_pushcclosure(L, iterNext, 1);
            lua_pushvalue(L, 1);
            lua_pushnil(L);
            return 3;
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
                { "__pairs",    pairs },
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