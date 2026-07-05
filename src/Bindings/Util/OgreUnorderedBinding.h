#pragma once
#include <type_traits>
#include <kenshi/util/OgreUnordered.h>
#include "Lua/BindingHelpers.h"
#include "Bindings/Util/HandBinding.h"

namespace KenshiLua
{
    // Generic LuaCodec for mapping types to/from Lua State.
    template <typename T, typename Enable = void>
    struct LuaCodec;

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

    // Set Binding
    template <typename K>
    struct OgreUnorderedSetBinding
    {
        typedef typename ogre_unordered_set<K>::type SetType;
        static const char* metaName;
        static const char* elemMetaName;

        static SetType* get(lua_State* L, int idx)
        {
            return checkObject<SetType>(L, idx, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int index(lua_State* L)
        {
            SetType* s = get(L, 1);
            if (!s) { lua_pushnil(L); return 1; }

            if (lua_isstring(L, 2))
            {
                luaL_getmetatable(L, metaName);
                lua_getfield(L, -1, lua_tostring(L, 2));
                if (!lua_isnil(L, -1)) return 1;
                lua_pop(L, 2);
            }

            K key = LuaCodec<K>::read(L, 2, elemMetaName);
            lua_pushboolean(L, s->find(key) != s->end() ? 1 : 0);
            return 1;
        }

        static int newindex(lua_State* L)
        {
            SetType* s = get(L, 1);
            if (!s) return luaL_error(L, "set is nil");

            K key = LuaCodec<K>::read(L, 2, elemMetaName);

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
            SetType* s = get(L, 1);
            lua_pushinteger(L, s ? (lua_Integer)s->size() : 0);
            return 1;
        }

        static int has(lua_State* L)
        {
            SetType* s = get(L, 1);
            if (!s) { lua_pushboolean(L, 0); return 1; }
            K key = LuaCodec<K>::read(L, 2, elemMetaName);
            lua_pushboolean(L, s->find(key) != s->end() ? 1 : 0);
            return 1;
        }

        static int add(lua_State* L)
        {
            SetType* s = get(L, 1);
            if (!s) return luaL_error(L, "set is nil");
            K key = LuaCodec<K>::read(L, 2, elemMetaName);
            auto res = s->insert(key);
            lua_pushboolean(L, res.second ? 1 : 0);
            return 1;
        }

        static int remove(lua_State* L)
        {
            SetType* s = get(L, 1);
            if (!s) return luaL_error(L, "set is nil");
            K key = LuaCodec<K>::read(L, 2, elemMetaName);
            lua_pushboolean(L, s->erase(key) > 0 ? 1 : 0);
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
            lua_newtable(L);
            for (typename SetType::const_iterator it = s->begin(); it != s->end(); ++it)
            {
                LuaCodec<K>::push(L, *it, elemMetaName);
                lua_pushboolean(L, 1);
                lua_settable(L, -3);
            }
            return 1;
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

    template <typename K>
    const char* OgreUnorderedSetBinding<K>::metaName = nullptr;

    template <typename K>
    const char* OgreUnorderedSetBinding<K>::elemMetaName = nullptr;


    // Map Binding
    template <typename K, typename V>
    struct OgreUnorderedMapBinding
    {
        typedef typename ogre_unordered_map<K, V>::type MapType;
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

            if (lua_isstring(L, 2))
            {
                luaL_getmetatable(L, metaName);
                lua_getfield(L, -1, lua_tostring(L, 2));
                if (!lua_isnil(L, -1)) return 1;
                lua_pop(L, 2);
            }

            K key = LuaCodec<K>::read(L, 2, keyMetaName);
            auto it = m->find(key);
            if (it == m->end()) { lua_pushnil(L); return 1; }
            LuaCodec<V>::push(L, it->second, valMetaName);
            return 1;
        }

        static int newindex(lua_State* L)
        {
            MapType* m = get(L, 1);
            if (!m) return luaL_error(L, "map is nil");

            K key = LuaCodec<K>::read(L, 2, keyMetaName);

            if (lua_isnil(L, 3))
            {
                m->erase(key);
                return 0;
            }

            V val = LuaCodec<V>::read(L, 3, valMetaName);
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
                LuaCodec<V>::push(L, it->second, valMetaName);
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

    template <typename K, typename V>
    const char* OgreUnorderedMapBinding<K, V>::metaName = nullptr;

    template <typename K, typename V>
    const char* OgreUnorderedMapBinding<K, V>::keyMetaName = nullptr;

    template <typename K, typename V>
    const char* OgreUnorderedMapBinding<K, V>::valMetaName = nullptr;

} // namespace KenshiLua