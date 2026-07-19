// pch.h: This is a precompiled header file.
#ifndef PCH_H
#define PCH_H

#include "framework.h"
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <unordered_map>
#include <memory>
#include <algorithm>
#include <functional>
#include <iostream>

// Include LuaJIT headers
#include <lua.hpp>

// Include KenshiLib headers
#include <core/Functions.h>
#include <kenshi/Building/Building.h>
#include <kenshi/Character.h>
#include <kenshi/CharStats.h>
#include <kenshi/Damages.h>
#include <kenshi/Faction.h>
#include <kenshi/Globals.h>
#include <kenshi/Item.h>
#include <kenshi/Inventory.h>
#include <kenshi/PlayerInterface.h>
#include <kenshi/InputHandler.h>
#include <kenshi/GameWorld.h>
#include <kenshi/GameData.h>
#include <kenshi/MedicalSystem.h>
#include <kenshi/Dialogue.h>
#include <kenshi/Platoon.h>
#include <kenshi/RootObject.h>
#include <kenshi/Town.h>
#include <kenshi/util/hand.h>

// Include Lua bindings
#include "CharacterBinding.h"
#include "CharStatsBinding.h"
#include "GameDataBinding.h"
#include "FactionBinding.h"
#include "PlatoonBinding.h"
#include "TownBinding.h"
#include "WorldEventStateQueryBinding.h"

// Include Lua helpers and codec
#include "Lua/BindingHelpers.h"
#include "Lua/LuaCodec.h"

// Lua 5.1/LuaJIT compatibility macros and helpers
#if LUA_VERSION_NUM < 502

#ifndef LUA_OK
#define LUA_OK 0
#endif

#define lua_rawlen(L, idx) lua_objlen(L, idx)
#define lua_pushglobaltable(L) lua_pushvalue(L, LUA_GLOBALSINDEX)
#define lua_isinteger(L, idx) (lua_type(L, idx) == LUA_TNUMBER && lua_tonumber(L, idx) == (lua_Number)(lua_Integer)lua_tonumber(L, idx))

inline const char* luaL_tolstring(lua_State* L, int idx, size_t* len) {
    if (luaL_callmeta(L, idx, "__tostring")) {
        if (!lua_isstring(L, -1))
            luaL_error(L, "'__tostring' must return a string");
        if (len) *len = lua_objlen(L, -1);
        return lua_tostring(L, -1);
    }
    switch (lua_type(L, idx)) {
        case LUA_TNUMBER: {
            lua_pushvalue(L, idx);
            const char* s = lua_tostring(L, -1);
            if (len) *len = lua_objlen(L, -1);
            return s;
        }
        case LUA_TSTRING: {
            lua_pushvalue(L, idx);
            if (len) *len = lua_objlen(L, -1);
            return lua_tostring(L, -1);
        }
        case LUA_TBOOLEAN: {
            lua_pushstring(L, lua_toboolean(L, idx) ? "true" : "false");
            if (len) *len = lua_objlen(L, -1);
            return lua_tostring(L, -1);
        }
        case LUA_TNIL: {
            lua_pushliteral(L, "nil");
            if (len) *len = 3;
            return "nil";
        }
        default: {
            const void* p = lua_topointer(L, idx);
            char buffer[64];
            sprintf(buffer, "%s: %p", luaL_typename(L, idx), p);
            lua_pushstring(L, buffer);
            if (len) *len = strlen(buffer);
            return lua_tostring(L, -1);
        }
    }
}

#endif

#endif // PCH_H