#pragma once
#include <kenshi/util/OgreUnordered.h>

class GameDataReference;

namespace KenshiLua
{

// K, V: key/value types. KeyToLua/LuaToKey/ValToLua/LuaToVal: conversion fn pointers.
template <
    typename K, typename V,
    const char* MetaName(),
    void (*ValToLua)(lua_State*, const V&),
    V (*LuaToVal)(lua_State*, int),
    void (*KeyToLua)(lua_State*, const K&),
    K (*LuaToKey)(lua_State*, int)
>
struct OgreUnorderedMapBinding
{
    typedef typename ogre_unordered_map<K, V>::type MapType;

    static MapType* get(lua_State* L, int idx)
    {
        return checkObject<MapType>(L, idx, MetaName());
    }

    static int gc(lua_State* L) { return noopGc(L); }

    static int index(lua_State* L)
    {
        MapType* m = get(L, 1);
        if (!m) { lua_pushnil(L); return 1; }

        // string method lookup falls through first
        if (lua_isstring(L, 2))
        {
            luaL_getmetatable(L, MetaName());
            lua_getfield(L, -1, lua_tostring(L, 2));
            if (!lua_isnil(L, -1)) return 1;
            lua_pop(L, 2);
        }

        K key = LuaToKey(L, 2);
        auto it = m->find(key);
        if (it == m->end()) { lua_pushnil(L); return 1; }
        ValToLua(L, it->second);
        return 1;
    }

    static int newindex(lua_State* L)
    {
        MapType* m = get(L, 1);
        if (!m) return luaL_error(L, "map is nil");

        K key = LuaToKey(L, 2);

        if (lua_isnil(L, 3))
        {
            m->erase(key); // assign-nil removes the entry
            return 0;
        }

        V val = LuaToVal(L, 3);
        (*m)[key] = val; // boost::unordered_map operator[] handles insert-or-update
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
        K key = LuaToKey(L, 2);
        lua_pushboolean(L, m->find(key) != m->end() ? 1 : 0);
        return 1;
    }

    static int remove(lua_State* L)
    {
        MapType* m = get(L, 1);
        if (!m) return luaL_error(L, "map is nil");
        K key = LuaToKey(L, 2);
        lua_pushboolean(L, m->erase(key) > 0 ? 1 : 0);
        return 1;
    }

    static int clear(lua_State* L)
    {
        MapType* m = get(L, 1);
        if (m) m->clear();
        return 0;
    }

    // toTable() - snapshot for iteration since boost::unordered_map
    // doesn't have a Lua-friendly stable __pairs without extra glue
    static int toTable(lua_State* L)
    {
        MapType* m = get(L, 1);
        if (!m) { lua_pushnil(L); return 1; }
        lua_newtable(L);
        for (typename MapType::const_iterator it = m->begin(); it != m->end(); ++it)
        {
            KeyToLua(L, it->first);
            ValToLua(L, it->second);
            lua_settable(L, -3);
        }
        return 1;
    }

    static void registerBinding(lua_State* L)
    {
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
        registerClass(L, MetaName(), meta, methods, index, newindex);
    }
};

// Metadata name getters
inline const char* StringBoolMapMeta() { return "KenshiLua.StringBoolMap"; }
inline const char* StringStringMapMeta() { return "KenshiLua.StringStringMap"; }
inline const char* StringIntMapMeta() { return "KenshiLua.StringIntMap"; }
inline const char* StringFloatMapMeta() { return "KenshiLua.StringFloatMap"; }
inline const char* StringVector3MapMeta() { return "KenshiLua.StringVector3Map"; }
inline const char* StringQuaternionMapMeta() { return "KenshiLua.StringQuaternionMap"; }
inline const char* StringGameDataReferenceVectorMapMeta() { return "KenshiLua.StringGameDataReferenceVectorMap"; }

// Helper function declarations for conversion
void stringKeyToLua(lua_State* L, const std::string& k);
std::string luaToStringKey(lua_State* L, int idx);

void boolValToLua(lua_State* L, const bool& v);
bool luaToBoolVal(lua_State* L, int idx);

void stringValToLua(lua_State* L, const std::string& v);
std::string luaToStringVal(lua_State* L, int idx);

void intValToLua(lua_State* L, const int& v);
int luaToIntVal(lua_State* L, int idx);

void floatValToLua(lua_State* L, const float& v);
float luaToFloatVal(lua_State* L, int idx);

void vector3ValToLua(lua_State* L, const Ogre::Vector3& v);
Ogre::Vector3 luaToVector3Val(lua_State* L, int idx);

void quaternionValToLua(lua_State* L, const Ogre::Quaternion& v);
Ogre::Quaternion luaToQuaternionVal(lua_State* L, int idx);

void refVectorValToLua(lua_State* L, const Ogre::vector<GameDataReference>::type& v);
Ogre::vector<GameDataReference>::type luaToRefVectorVal(lua_State* L, int idx);

// Typedefs
typedef OgreUnorderedMapBinding<
    std::string, bool,
    StringBoolMapMeta,
    boolValToLua, luaToBoolVal,
    stringKeyToLua, luaToStringKey
> StringBoolMapBinding;

typedef OgreUnorderedMapBinding<
    std::string, std::string,
    StringStringMapMeta,
    stringValToLua, luaToStringVal,
    stringKeyToLua, luaToStringKey
> StringStringMapBinding;

typedef OgreUnorderedMapBinding<
    std::string, int,
    StringIntMapMeta,
    intValToLua, luaToIntVal,
    stringKeyToLua, luaToStringKey
> StringIntMapBinding;

typedef OgreUnorderedMapBinding<
    std::string, float,
    StringFloatMapMeta,
    floatValToLua, luaToFloatVal,
    stringKeyToLua, luaToStringKey
> StringFloatMapBinding;

typedef OgreUnorderedMapBinding<
    std::string, Ogre::Vector3,
    StringVector3MapMeta,
    vector3ValToLua, luaToVector3Val,
    stringKeyToLua, luaToStringKey
> StringVector3MapBinding;

typedef OgreUnorderedMapBinding<
    std::string, Ogre::Quaternion,
    StringQuaternionMapMeta,
    quaternionValToLua, luaToQuaternionVal,
    stringKeyToLua, luaToStringKey
> StringQuaternionMapBinding;

typedef OgreUnorderedMapBinding<
    std::string, Ogre::vector<GameDataReference>::type,
    StringGameDataReferenceVectorMapMeta,
    refVectorValToLua, luaToRefVectorVal,
    stringKeyToLua, luaToStringKey
> StringGameDataReferenceVectorMapBinding;

void registerOgreUnorderedBindings(lua_State* L);

} // namespace KenshiLua