#pragma once
#include <type_traits>
#include <string>
#include <unordered_map>
#include <utility>
#include <ogre/OgreVector3.h>
#include <ogre/OgreQuaternion.h>
#include <kenshi/util/OgreUnordered.h>
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Lua/LuaCodec.h"

namespace KenshiLua
{
    typedef int (*OgreSetFactoryFn)(lua_State* L);
    typedef int (*OgreMapFactoryFn)(lua_State* L);

    inline std::unordered_map<std::string, OgreSetFactoryFn>& getOgreSetFactories()
    {
        static std::unordered_map<std::string, OgreSetFactoryFn> s_setFactories;
        return s_setFactories;
    }

    inline void registerOgreSetFactory(const std::string& typeName, OgreSetFactoryFn fn)
    {
        getOgreSetFactories()[typeName] = fn;
    }

    inline std::unordered_map<std::string, OgreMapFactoryFn>& getOgreMapFactories()
    {
        static std::unordered_map<std::string, OgreMapFactoryFn> s_mapFactories;
        return s_mapFactories;
    }

    inline void registerOgreMapFactory(const std::string& typeName, OgreMapFactoryFn fn)
    {
        getOgreMapFactories()[typeName] = fn;
    }

    // Set Binding
    template <typename K>
    struct OgreUnorderedSetBinding
    {
        typedef typename ogre_unordered_set<K>::type SetType;
        static const char* metaName;
        static const char* elemMetaName;

        static const char* getMetatableName() { return metaName; }

        static SetType* get(lua_State* L, int idx)
        {
            return checkObject<SetType>(L, idx, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int gcOwned(lua_State* L)
        {
            void** ud = (void**)lua_touserdata(L, 1);
            if (ud && *ud)
            {
                SetType* s = static_cast<SetType*>(*ud);
                delete s;
                *ud = nullptr;
            }
            return 0;
        }

        static int pushOwned(lua_State* L, SetType* s)
        {
            return pushObjectOwnedCustom<SetType, gcOwned>(L, s, metaName);
        }

        static int createNew(lua_State* L)
        {
            SetType* s = new SetType();
            return pushOwned(L, s);
        }

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
                if (!std::is_same<K, std::string>::value)
                {
                    lua_pushnil(L);
                    return 1;
                }
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
            lua_createtable(L, 0, (int)s->size());
            for (typename SetType::const_iterator it = s->begin(); it != s->end(); ++it)
            {
                LuaCodec<K>::push(L, *it, elemMetaName);
                lua_pushboolean(L, 1);
                lua_settable(L, -3);
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
            for (int n = 0; n < skip && it != s->end(); ++n, ++it) {}
            if (it == s->end()) return 0;
            lua_pushinteger(L, skip + 1);
            lua_replace(L, lua_upvalueindex(1));
            LuaCodec<K>::push(L, *it, elemMetaName);
            lua_pushboolean(L, 1);
            return 2;
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
                { 0, 0 }
            };
            static const luaL_Reg methods[] = {
                { "has",      has },
                { "contains", has },
                { "add",      add },
                { "insert",   add },
                { "remove",   remove },
                { "erase",    remove },
                { "clear",    clear },
                { "toTable",  toTable },
                { "size",     len },
                { "items",    pairs },
                { 0, 0 }
            };
            registerClass(L, metaName, meta, methods, index, newindex);

            registerOgreSetFactory(name, createNew);
            if (elemName)
            {
                registerOgreSetFactory(elemName, createNew);
                registerOgreSetFactory(std::string(elemName) + "*", createNew);
            }
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

        static const char* getMetatableName() { return metaName; }

        static MapType* get(lua_State* L, int idx)
        {
            return checkObject<MapType>(L, idx, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int gcOwned(lua_State* L)
        {
            void** ud = (void**)lua_touserdata(L, 1);
            if (ud && *ud)
            {
                MapType* m = static_cast<MapType*>(*ud);
                delete m;
                *ud = nullptr;
            }
            return 0;
        }

        static int pushOwned(lua_State* L, MapType* m)
        {
            return pushObjectOwnedCustom<MapType, gcOwned>(L, m, metaName);
        }

        static int createNew(lua_State* L)
        {
            MapType* m = new MapType();
            return pushOwned(L, m);
        }

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
                if (!std::is_same<K, std::string>::value)
                {
                    lua_pushnil(L);
                    return 1;
                }
            }

            K key = LuaCodec<K>::read(L, 2, keyMetaName);
            auto it = m->find(key);
            if (it == m->end()) { lua_pushnil(L); return 1; }
            if (valMetaName)
            {
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

        // Stateful iterator: upvalue 1 = skip count
        static int iterNext(lua_State* L)
        {
            MapType* m = get(L, 1);
            if (!m) return 0;
            int skip = (int)lua_tointeger(L, lua_upvalueindex(1));
            typename MapType::const_iterator it = m->begin();
            for (int n = 0; n < skip && it != m->end(); ++n, ++it) {}
            if (it == m->end()) return 0;
            lua_pushinteger(L, skip + 1);
            lua_replace(L, lua_upvalueindex(1));
            LuaCodec<K>::push(L, it->first, keyMetaName);
            if (valMetaName)
                pushObject<V>(L, const_cast<V*>(&it->second), valMetaName);
            else
                LuaCodec<V>::push(L, it->second, nullptr);
            return 2;
        }

        static int pairs(lua_State* L)
        {
            lua_pushinteger(L, 0);
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
                { "contains", has },
                { "remove",   remove },
                { "erase",    remove },
                { "clear",    clear },
                { "toTable",  toTable },
                { "size",     len },
                { "pairs",    pairs },
                { 0, 0 }
            };
            registerClass(L, metaName, meta, methods, index, newindex);

            registerOgreMapFactory(name, createNew);
            if (keyName && valName)
            {
                std::string pairKey = std::string(keyName) + "," + std::string(valName);
                registerOgreMapFactory(pairKey, createNew);
            }
        }
    };

    template <typename K, typename V>
    const char* OgreUnorderedMapBinding<K, V>::metaName = nullptr;

    template <typename K, typename V>
    const char* OgreUnorderedMapBinding<K, V>::keyMetaName = nullptr;

    template <typename K, typename V>
    const char* OgreUnorderedMapBinding<K, V>::valMetaName = nullptr;

    inline int lua_ogre_unordered_set_new(lua_State* L)
    {
        std::string typeName = extractContainerTypeName(L, 1);

        if (typeName.empty())
        {
            return luaL_error(L, "ogre_unordered_set.new: expected type name or class table as argument 1, got %s", luaL_typename(L, 1));
        }

        auto& factories = getOgreSetFactories();
        auto it = factories.find(typeName);
        if (it != factories.end())
        {
            return it->second(L);
        }

        if (typeName.length() > 20 && typeName.rfind("ogre_unordered_set<", 0) == 0 && typeName.back() == '>')
        {
            std::string inner = typeName.substr(19, typeName.length() - 20);
            it = factories.find(inner);
            if (it != factories.end())
                return it->second(L);

            if (inner.back() != '*')
            {
                it = factories.find(inner + "*");
                if (it != factories.end())
                    return it->second(L);
            }
        }

        it = factories.find(typeName + "*");
        if (it != factories.end())
        {
            return it->second(L);
        }

        if (!typeName.empty() && typeName.back() == '*')
        {
            it = factories.find(typeName.substr(0, typeName.length() - 1));
            if (it != factories.end())
                return it->second(L);
        }

        it = factories.find("ogre_unordered_set<" + typeName + ">");
        if (it != factories.end())
        {
            return it->second(L);
        }

        return luaL_error(L, "ogre_unordered_set.new: unsupported or unknown type '%s'", typeName.c_str());
    }

    inline int lua_ogre_unordered_map_new(lua_State* L)
    {
        std::string mapTypeStr;
        if (lua_gettop(L) >= 2)
        {
            std::string kStr = extractContainerTypeName(L, 1);
            std::string vStr = extractContainerTypeName(L, 2);
            if (kStr.empty() || vStr.empty())
            {
                return luaL_error(L, "ogre_unordered_map.new: expected type names or class tables for key and value");
            }
            auto& factories = getOgreMapFactories();

            auto it = factories.find(kStr + "," + vStr);
            if (it != factories.end())
                return it->second(L);

            it = factories.find("ogre_unordered_map<" + kStr + ", " + vStr + ">");
            if (it != factories.end())
                return it->second(L);

            if (kStr.back() != '*')
            {
                it = factories.find(kStr + "*," + vStr);
                if (it != factories.end())
                    return it->second(L);

                it = factories.find("ogre_unordered_map<" + kStr + "*, " + vStr + ">");
                if (it != factories.end())
                    return it->second(L);
            }

            if (vStr.back() != '*')
            {
                it = factories.find(kStr + "," + vStr + "*");
                if (it != factories.end())
                    return it->second(L);

                it = factories.find("ogre_unordered_map<" + kStr + ", " + vStr + "*>");
                if (it != factories.end())
                    return it->second(L);
            }

            return luaL_error(L, "ogre_unordered_map.new: unsupported map type (%s, %s)", kStr.c_str(), vStr.c_str());
        }
        else if (lua_isstring(L, 1))
        {
            mapTypeStr = lua_tostring(L, 1);
            auto& factories = getOgreMapFactories();
            auto it = factories.find(mapTypeStr);
            if (it != factories.end())
                return it->second(L);
            return luaL_error(L, "ogre_unordered_map.new: unsupported map type '%s'", mapTypeStr.c_str());
        }

        return luaL_error(L, "ogre_unordered_map.new: expected (keyType, valType) or full type string");
    }

    inline int lua_ogre_unordered_set_call(lua_State* L)
    {
        lua_remove(L, 1);
        return lua_ogre_unordered_set_new(L);
    }

    inline int lua_ogre_unordered_map_call(lua_State* L)
    {
        lua_remove(L, 1);
        return lua_ogre_unordered_map_new(L);
    }

    inline void registerOgreUnorderedGlobals(lua_State* L)
    {
        // ogre_unordered_set
        lua_newtable(L);
        lua_pushcfunction(L, lua_ogre_unordered_set_new);
        lua_setfield(L, -2, "new");

        lua_newtable(L);
        lua_pushcfunction(L, lua_ogre_unordered_set_call);
        lua_setfield(L, -2, "__call");
        lua_setmetatable(L, -2);
        lua_setglobal(L, "ogre_unordered_set");

        // ogre_unordered_map
        lua_newtable(L);
        lua_pushcfunction(L, lua_ogre_unordered_map_new);
        lua_setfield(L, -2, "new");

        lua_newtable(L);
        lua_pushcfunction(L, lua_ogre_unordered_map_call);
        lua_setfield(L, -2, "__call");
        lua_setmetatable(L, -2);
        lua_setglobal(L, "ogre_unordered_map");
    }
} // namespace KenshiLua
