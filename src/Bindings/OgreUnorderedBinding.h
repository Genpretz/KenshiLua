// OgreUnorderedMapBinding.h
#pragma once
#include <kenshi/util/OgreUnordered.h>

// if (strcmp(key, "disguiseGUIFeedbacks") == 0)
// {
//     return pushObject<DisguiseFeedbackMap>(L, &c->disguiseGUIFeedbacks, DisguiseFeedbackMapBinding::getMetatableName());
// }

// void enumKeyToLua(lua_State* L, const Character::DisguiseGUIFeedback& k) { lua_pushinteger(L, (int)k); }
// Character::DisguiseGUIFeedback luaToEnumKey(lua_State* L, int idx) { return (Character::DisguiseGUIFeedback)luaL_checkinteger(L, idx); }
// void floatValToLua(lua_State* L, const float& v) { lua_pushnumber(L, v); }
// float luaToFloatVal(lua_State* L, int idx) { return (float)luaL_checknumber(L, idx); }

// local fb = character.disguiseGUIFeedbacks
// fb[0] = 0.5          -- set/insert
// print(fb[0])         -- 0.5
// print(fb:has(0))     -- true
// fb:remove(0)
// for k, v in pairs(fb:toTable()) do ... end  -- iteration via snapshot

namespace KenshiLua
{

// K, V: key/value types. KeyToLua/LuaToKey/ValToLua/LuaToVal: conversion fn pointers.
template 
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
        for (auto& kv : *m)
        {
            KeyToLua(L, kv.first);
            ValToLua(L, kv.second);
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

} // namespace KenshiLua