#pragma once
#include "Lua/ContainerBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/Util/ContainerIteration.h"
#include "Bindings/Kenshi/Util/MapValue.h"
#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>
#include <ogre/OgreMemoryAllocatorConfig.h>
#include "Lua/BindingHelpers.h"
#include "Lua/LuaCodec.h"

namespace KenshiLua
{
    // Generic Boost Unordered Set Binding
    //
    // Alloc defaults to the Ogre::STLAllocator<K, GeneralAllocPolicy> convention
    // used throughout this codebase. Override explicitly at the call site if a
    // particular set field uses a different allocation policy - see the caveat
    // in StdMapBinding.h about unchecked casts before relying on this default.
    template <typename K, 
              typename Hash = boost::hash<K>, 
              typename Pred = std::equal_to<K>, 
              typename Alloc = Ogre::STLAllocator<K, Ogre::GeneralAllocPolicy> >
    struct BoostUnorderedSetBinding
    {
        typedef boost::unordered::unordered_set<K, Hash, Pred, Alloc> SetType;
        typedef SetType ContainerType;
        typedef BoostUnorderedSetBinding<K, Hash, Pred, Alloc> MetadataType;
        static const char* const metaName;
        static const char* const metadata[3];

        static const char* getMetatableName() { return metaName; }

        static SetType* getInstance(lua_State* L, int idx)
        {
            return checkObject<SetType>(L, idx, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int index(lua_State* L)
        {
            SetType* s = getInstance(L, 1);
            if (!s) { lua_pushnil(L); return 1; }

            if (lua_isstring(L, 2))
            {
                luaL_getmetatable(L, metaName);
                lua_getfield(L, -1, lua_tostring(L, 2));
                if (!lua_isnil(L, -1)) return 1;
                lua_pop(L, 2);
            }

            K key = LuaCodec<K>::read(L, 2, metadata[0]);
            lua_pushboolean(L, s->find(key) != s->end() ? 1 : 0);
            return 1;
        }

        static int newindex(lua_State* L)
        {
            SetType* s = getInstance(L, 1);
            if (!s) return luaL_error(L, "set is nil");

            K key = LuaCodec<K>::read(L, 2, metadata[0]);

            if (lua_isnil(L, 3) || (lua_isboolean(L, 3) && !lua_toboolean(L, 3)))
            {
                s->erase(key);
            }
            else
            {
                s->insert(key);
            }
            return 0;
        }

        static int len(lua_State* L)
        {
            SetType* s = getInstance(L, 1);
            lua_pushinteger(L, s ? (lua_Integer)s->size() : 0);
            return 1;
        }

        static int has(lua_State* L)
        {
            SetType* s = getInstance(L, 1);
            if (!s) { lua_pushboolean(L, 0); return 1; }
            K key = LuaCodec<K>::read(L, 2, metadata[0]);
            lua_pushboolean(L, s->find(key) != s->end() ? 1 : 0);
            return 1;
        }

        static int add(lua_State* L)
        {
            SetType* s = getInstance(L, 1);
            if (!s) return luaL_error(L, "set is nil");
            K key = LuaCodec<K>::read(L, 2, metadata[0]);
            auto res = s->insert(key);
            lua_pushboolean(L, res.second ? 1 : 0);
            return 1;
        }

        static int remove(lua_State* L)
        {
            SetType* s = getInstance(L, 1);
            if (!s) return luaL_error(L, "set is nil");
            K key = LuaCodec<K>::read(L, 2, metadata[0]);
            lua_pushboolean(L, s->erase(key) > 0 ? 1 : 0);
            return 1;
        }

        static int clear(lua_State* L)
        {
            SetType* s = getInstance(L, 1);
            if (s) s->clear();
            return 0;
        }

        static int toTable(lua_State* L)
        {
            SetType* s = getInstance(L, 1);
            if (!s) { lua_pushnil(L); return 1; }
            lua_createtable(L, 0, (int)s->size());
            for (typename SetType::const_iterator it = s->begin(); it != s->end(); ++it)
            {
                LuaCodec<K>::push(L, *it, metadata[0]);
                lua_pushboolean(L, 1);
                lua_settable(L, -3);
            }
            return 1;
        }

        // pairs() copies the elements into a snapshot table and iterates that. See
        // ContainerIteration.h for why the container is not walked step by step.
        static int pairs(lua_State* L)
        {
            SetType* s = getInstance(L, 1);
            int count = 0;
            lua_createtable(L, s ? (int)s->size() * 2 : 0, 0);
            if (s)
            {
                for (typename SetType::const_iterator it = s->begin(); it != s->end(); ++it)
                {
                    ++count;
                    LuaCodec<K>::push(L, *it, metadata[0]);
                    lua_rawseti(L, -2, 2 * count - 1);
                    lua_pushboolean(L, 1);
                    lua_rawseti(L, -2, 2 * count);
                }
            }
            return pushSnapshotIterator(L, count);
        }

        static int push(lua_State* L, SetType* ptr)
        {
            return pushObject<SetType>(L, ptr, metaName);
        }

        static void registerBinding(lua_State* L)
        {
            if (!beginContainerBinding(L, containerBindingDefinition<MetadataType>())) return;

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
                { "add",      add },
                { "remove",   remove },
                { "clear",    clear },
                { "toTable",  toTable },
                { "size",     len },
                { 0, 0 }
            };
            registerClass(L, metaName, meta, methods, index, newindex);
        }
    };

    // Generic Boost Unordered Map Binding
    //
    // Alloc defaults to the Ogre::STLAllocator<..., GeneralAllocPolicy> convention
    // used by every boost::unordered_map member field in this codebase (see e.g.
    // GameData.h). Most call sites only need to specify K and V - see
    // GameDataBinding.cpp. See the caveat in StdMapBinding.h before relying on
    // this default for a field you haven't verified.
    template <typename K, typename V,
              typename Hash = boost::hash<K>,
              typename Pred = std::equal_to<K>,
              typename Alloc = Ogre::STLAllocator<std::pair<const K, V>, Ogre::GeneralAllocPolicy> >
    struct BoostUnorderedMapBinding
    {
        typedef boost::unordered::unordered_map<K, V, Hash, Pred, Alloc> MapType;
        typedef MapType ContainerType;
        typedef BoostUnorderedMapBinding<K, V, Hash, Pred, Alloc> MetadataType;
        static const char* const metaName;
        static const char* const metadata[3];

        static const char* getMetatableName() { return metaName; }

        static MapType* getInstance(lua_State* L, int idx)
        {
            return checkObject<MapType>(L, idx, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int index(lua_State* L)
        {
            MapType* m = getInstance(L, 1);
            if (!m) { lua_pushnil(L); return 1; }

            if (lua_isstring(L, 2))
            {
                luaL_getmetatable(L, metaName);
                lua_getfield(L, -1, lua_tostring(L, 2));
                if (!lua_isnil(L, -1)) return 1;
                lua_pop(L, 2);
            }

            K key = LuaCodec<K>::read(L, 2, metadata[0]);
            auto it = m->find(key);
            if (it == m->end()) { lua_pushnil(L); return 1; }
            if (metadata[1])
            {
                return MapValue<V>::push(L, it->second, metadata[1]);
            }
            else
            {
                LuaCodec<V>::push(L, it->second, nullptr);
                return 1;
            }
        }

        static int newindex(lua_State* L)
        {
            MapType* m = getInstance(L, 1);
            if (!m) return luaL_error(L, "map is nil");

            if (lua_isnil(L, 3))
            {
                K key = LuaCodec<K>::read(L, 2, metadata[0]);
                m->erase(key);
                return 0;
            }

            if (std::is_same<K, std::string>::value)
            {
                luaL_checkstring(L, 2);
            }

            V val;
            if (metadata[1])
            {
                val = MapValue<V>::read(L, 3, metadata[1]);
            }
            else
            {
                val = LuaCodec<V>::read(L, 3, nullptr);
            }

            K key = LuaCodec<K>::read(L, 2, metadata[0]);
            (*m)[key] = val;
            return 0;
        }

        static int len(lua_State* L)
        {
            MapType* m = getInstance(L, 1);
            lua_pushinteger(L, m ? (lua_Integer)m->size() : 0);
            return 1;
        }

        static int has(lua_State* L)
        {
            MapType* m = getInstance(L, 1);
            if (!m) { lua_pushboolean(L, 0); return 1; }
            K key = LuaCodec<K>::read(L, 2, metadata[0]);
            lua_pushboolean(L, m->find(key) != m->end() ? 1 : 0);
            return 1;
        }

        static int remove(lua_State* L)
        {
            MapType* m = getInstance(L, 1);
            if (!m) return luaL_error(L, "map is nil");
            K key = LuaCodec<K>::read(L, 2, metadata[0]);
            lua_pushboolean(L, m->erase(key) > 0 ? 1 : 0);
            return 1;
        }

        static int clear(lua_State* L)
        {
            MapType* m = getInstance(L, 1);
            if (m) m->clear();
            return 0;
        }

        static int toTable(lua_State* L)
        {
            MapType* m = getInstance(L, 1);
            if (!m) { lua_pushnil(L); return 1; }
            lua_createtable(L, 0, (int)m->size());
            for (typename MapType::const_iterator it = m->begin(); it != m->end(); ++it)
            {
                LuaCodec<K>::push(L, it->first, metadata[0]);
                if (metadata[1])
                {
                    MapValue<V>::push(L, it->second, metadata[1]);
                }
                else
                {
                    LuaCodec<V>::push(L, it->second, nullptr);
                }
                lua_settable(L, -3);
            }
            return 1;
        }

        // pairs() copies the entries into a snapshot table and iterates that. See
        // ContainerIteration.h for why the container is not walked step by step.
        static int pairs(lua_State* L)
        {
            MapType* m = getInstance(L, 1);
            int count = 0;
            lua_createtable(L, m ? (int)m->size() * 2 : 0, 0);
            if (m)
            {
                for (typename MapType::const_iterator it = m->begin(); it != m->end(); ++it)
                {
                    ++count;
                    LuaCodec<K>::push(L, it->first, metadata[0]);
                    lua_rawseti(L, -2, 2 * count - 1);
                    if (metadata[1])
                        MapValue<V>::push(L, it->second, metadata[1]);
                    else
                        LuaCodec<V>::push(L, it->second, nullptr);
                    lua_rawseti(L, -2, 2 * count);
                }
            }
            return pushSnapshotIterator(L, count);
        }

        static int push(lua_State* L, MapType* ptr)
        {
            return pushObject<MapType>(L, ptr, metaName);
        }

        static void registerBinding(lua_State* L)
        {
            if (!beginContainerBinding(L, containerBindingDefinition<MetadataType>())) return;

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

} // namespace KenshiLua