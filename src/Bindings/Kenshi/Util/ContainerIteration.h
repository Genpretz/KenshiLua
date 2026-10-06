#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    // Iteration support for containers without random access, such as hash and tree
    // sets and maps. A container's pairs() copies its entries into a snapshot table in
    // one pass and returns an iterator over that table. Walking the container from
    // begin() on every step made a full iteration quadratic, which froze the game for
    // tens of seconds on large engine sets such as GameDataContainer::mainList.
    //
    // The snapshot holds the values that existed when pairs() was called. Values pushed
    // as borrowed pointers into the container, such as map values, still refer to the
    // container's storage and become invalid if their entries are erased.

    // Generic-for iterator over a snapshot table.
    // Upvalue 1: snapshot table, with the i-th key at 2i - 1 and its value at 2i.
    // Upvalue 2: index of the next pair, starting at 1.
    // Upvalue 3: number of pairs.
    inline int snapshotIterNext(lua_State* L)
    {
        lua_Integer i = lua_tointeger(L, lua_upvalueindex(2));
        lua_Integer count = lua_tointeger(L, lua_upvalueindex(3));
        if (i > count)
            return 0;
        lua_pushinteger(L, i + 1);
        lua_replace(L, lua_upvalueindex(2));
        lua_rawgeti(L, lua_upvalueindex(1), (int)(2 * i - 1));
        lua_rawgeti(L, lua_upvalueindex(1), (int)(2 * i));
        return 2;
    }

    // Takes the snapshot table from the top of the stack and returns the generic-for
    // triple: iterator, nil, nil. count is the number of key/value pairs stored.
    inline int pushSnapshotIterator(lua_State* L, int count)
    {
        lua_pushinteger(L, 1);
        lua_pushinteger(L, count);
        lua_pushcclosure(L, snapshotIterNext, 3);
        lua_pushnil(L);
        lua_pushnil(L);
        return 3;
    }
}
