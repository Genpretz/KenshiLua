#pragma once

#include <string>
#include <cstring>
#include <cstdio>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    template <class T>
    inline T* testObject(lua_State* L, int idx, const char* metatableName)
    {
        if (!lua_isuserdata(L, idx)) return 0;

        int top = lua_gettop(L);
        bool match = false;
        if (lua_getmetatable(L, idx)) { // Stack: MT
            while (true) {
                lua_pushstring(L, "__name");
                lua_rawget(L, -2);
                const char* name = lua_tostring(L, -1);
                lua_pop(L, 1);

                if (name && strcmp(name, metatableName) == 0) {
                    match = true;
                    break;
                }

                if (!lua_getmetatable(L, -1)) {
                    break;
                }

                lua_pushstring(L, "__index");
                lua_rawget(L, -2);
                if (lua_istable(L, -1)) {
                    lua_replace(L, -3);
                    lua_pop(L, 1);
                } else {
                    break;
                }
            }
        }
        lua_settop(L, top);

        if (match) {
            void* raw = lua_touserdata(L, idx);
            return raw ? (T*)*((void**)raw) : 0;
        }
        return 0;
    }

    template <class T>
    inline T* checkObject(lua_State* L, int idx, const char* metatableName)
    {
        T* ptr = testObject<T>(L, idx, metatableName);
        if (!ptr) {
            const char* msg = lua_pushfstring(L, "%s expected, got %s",
                metatableName, luaL_typename(L, idx));
            luaL_argerror(L, idx, msg);
            return 0;
        }
        return ptr;
    }

    // Allocates a new userdata wrapping `ptr` and assigns the named metatable.
    // If ptr is null, pushes nil instead.  Always returns 1 (one Lua value pushed).
    template <class T>
    inline int pushObject(lua_State* L, T* ptr, const char* metatableName)
    {
        if (!ptr) {
            lua_pushnil(L);
            return 1;
        }
        void** ud = (void**)lua_newuserdata(L, sizeof(void*));
        *ud = (void*)ptr;
        luaL_getmetatable(L, metatableName);
        if (lua_isnil(L, -1)) {
            // Metatable missing - bail out rather than producing an opaque userdata.
            lua_pop(L, 2); // pop nil metatable + the new userdata
            lua_pushnil(L);
            return 1;
        }
        lua_setmetatable(L, -2);
        return 1;
    }

    // Same as pushObject<T> but uses BindingT::getMetatableName() so call sites
    // can be terse:  pushObjectT<Character, CharacterBinding>(L, c);
    template <class T, class BindingT>
    inline int pushObjectT(lua_State* L, T* ptr)
    {
        return pushObject<T>(L, ptr, BindingT::getMetatableName());
    }

    inline void registerClass(lua_State* L,
        const char* metatableName,
        const luaL_Reg* metamethods,
        const luaL_Reg* methods,
        lua_CFunction indexFunc = NULL,
        lua_CFunction newindexFunc = NULL)
    {
        if (!luaL_newmetatable(L, metatableName)) {
            // Already registered? Bail. Pop the existing metatable and return.
            lua_pop(L, 1);
            return;
        }

        lua_pushstring(L, metatableName);
        lua_setfield(L, -2, "__name");

        if (indexFunc) {
            // Caller supplies a C __index that handles both method dispatch and
            // raw field access.
            lua_pushcfunction(L, indexFunc);
            lua_setfield(L, -2, "__index");
        }
        else {
            // Standard idiom: __index = metatable (method-table class).
            lua_pushvalue(L, -1);
            lua_setfield(L, -2, "__index");
        }

        if (newindexFunc) {
            lua_pushcfunction(L, newindexFunc);
            lua_setfield(L, -2, "__newindex");
        }

        if (metamethods) {
            luaL_setfuncs(L, metamethods, 0);
        }
        if (methods) {
            luaL_setfuncs(L, methods, 0);
        }

        lua_pop(L, 1);
    }

    // Build a Vector3-like Lua table {x=,y=,z=} from any object
    // exposing .x/.y/.z (Ogre::Vector3 fits).
    template <class V3>
    inline void pushVector3(lua_State* L, const V3& v)
    {
        lua_createtable(L, 0, 3);
        lua_pushnumber(L, v.x); lua_setfield(L, -2, "x");
        lua_pushnumber(L, v.y); lua_setfield(L, -2, "y");
        lua_pushnumber(L, v.z); lua_setfield(L, -2, "z");
    }

    // Read a {x,y,z} table at idx. Missing fields default to 0. Returns true
    // if any of the three fields was actually present.
    template <class V3>
    inline bool readVector3(lua_State* L, int idx, V3& out)
    {
        if (!lua_istable(L, idx)) return false;
        bool any = false;
        lua_getfield(L, idx, "x"); if (!lua_isnil(L, -1)) { out.x = (float)lua_tonumber(L, -1); any = true; } lua_pop(L, 1);
        lua_getfield(L, idx, "y"); if (!lua_isnil(L, -1)) { out.y = (float)lua_tonumber(L, -1); any = true; } lua_pop(L, 1);
        lua_getfield(L, idx, "z"); if (!lua_isnil(L, -1)) { out.z = (float)lua_tonumber(L, -1); any = true; } lua_pop(L, 1);
        return any;
    }

    // Build a Quaternion-like Lua table {w=,x=,y=,z=} from any object
    // exposing .w/.x/.y/.z (Ogre::Quaternion fits).
    template <class Q4>
    inline void pushQuaternion(lua_State* L, const Q4& q)
    {
        lua_createtable(L, 0, 4);
        lua_pushnumber(L, q.w); lua_setfield(L, -2, "w");
        lua_pushnumber(L, q.x); lua_setfield(L, -2, "x");
        lua_pushnumber(L, q.y); lua_setfield(L, -2, "y");
        lua_pushnumber(L, q.z); lua_setfield(L, -2, "z");
    }

    // Read a {w,x,y,z} table at idx. Missing fields default to 0. Returns true
    // if any of the four fields was actually present.
    template <class Q4>
    inline bool readQuaternion(lua_State* L, int idx, Q4& out)
    {
        if (!lua_istable(L, idx)) return false;
        bool any = false;
        lua_getfield(L, idx, "w"); if (!lua_isnil(L, -1)) { out.w = (float)lua_tonumber(L, -1); any = true; } lua_pop(L, 1);
        lua_getfield(L, idx, "x"); if (!lua_isnil(L, -1)) { out.x = (float)lua_tonumber(L, -1); any = true; } lua_pop(L, 1);
        lua_getfield(L, idx, "y"); if (!lua_isnil(L, -1)) { out.y = (float)lua_tonumber(L, -1); any = true; } lua_pop(L, 1);
        lua_getfield(L, idx, "z"); if (!lua_isnil(L, -1)) { out.z = (float)lua_tonumber(L, -1); any = true; } lua_pop(L, 1);
        return any;
    }

    // Generic __tostring that produces "Type:%p".
    inline int genericTostringPtr(lua_State* L, const char* typeName, void* ptr)
    {
        char buf[96];
        _snprintf(buf, sizeof(buf), "%s:%p", typeName ? typeName : "obj", ptr);
        lua_pushstring(L, buf);
        return 1;
    }

    // Generic __newindex rejecter.
    inline int rejectNewIndex(lua_State* L)
    {
        return luaL_error(L, "object is read-only from Lua");
    }

    // Generic __gc no-op for engine-owned pointers.
    inline int noopGc(lua_State* /*L*/)
    {
        return 0;
    }

    template<typename T>
    inline void setEnum(lua_State* L, const char* name, T value)
    {
        lua_pushinteger(L, static_cast<lua_Integer>(value));
        lua_setfield(L, -2, name);
    }

    // -----------------------------------------------------------------------------
    // Universal Property Dispatchers
    // -----------------------------------------------------------------------------

    // Intercepts obj.property and routes it to the correct getter in __getters, 
    // or returns the method if it exists in the metatable.
    inline int genericPropertyIndex(lua_State* L)
    {
        // Stack: 1 = userdata (object), 2 = string (key)
        const char* key = luaL_checkstring(L, 2);

        if (lua_getmetatable(L, 1)) {
            // 1. Check for a method in the metatable first
            lua_pushvalue(L, 2);
            lua_gettable(L, -2);
            if (!lua_isnil(L, -1)) {
                return 1; // It's a method! Return the function pointer.
            }
            lua_pop(L, 1); // pop the nil

            // 2. Check the __getters table
            lua_pushstring(L, "__getters");
            lua_gettable(L, -2);
            if (lua_istable(L, -1)) {
                lua_pushvalue(L, 2);  // push the key again
                lua_gettable(L, -2);
                if (lua_iscfunction(L, -1)) {
                    // We found the getter function! Execute it.
                    lua_pushvalue(L, 1); // Pass the C++ object as the first argument
                    lua_call(L, 1, 1);   // Call with 1 arg, expect 1 return
                    return 1;
                }
            }
        }

        // Nothing found
        lua_pushnil(L);
        return 1;
    }

    // Intercepts obj.property = value and routes it to the correct setter in __setters.
    inline int genericPropertyNewIndex(lua_State* L)
    {
        // Stack: 1 = userdata, 2 = key, 3 = value

        if (lua_getmetatable(L, 1)) {
            lua_pushstring(L, "__setters");
            lua_gettable(L, -2);

            if (lua_istable(L, -1)) {
                lua_pushvalue(L, 2); // push key
                lua_gettable(L, -2);   // look up the key in __setters

                if (lua_iscfunction(L, -1)) {
                    // We found the setter function! Execute it.
                    lua_pushvalue(L, 1); // Pass the C++ object (arg 1)
                    lua_pushvalue(L, 3); // Pass the new value (arg 2)
                    lua_call(L, 2, 0);   // Call with 2 args, expect 0 returns
                    return 0;
                }
            }
        }

        return luaL_error(L, "Property '%s' is read-only or does not exist", lua_tostring(L, 2));
    }

    // Establishes metatable inheritance for methods, getters, and setters between two class metatables.
    inline void setMetatableParent(lua_State* L, const char* childMeta, const char* parentMeta)
    {
        // 1. Link child metatable __index fallback to parent metatable
        luaL_getmetatable(L, childMeta);
        if (lua_istable(L, -1)) {
            luaL_getmetatable(L, parentMeta);
            if (!lua_istable(L, -1)) {
                // Parent metatable doesn't exist, log a warning or return safely
                lua_pop(L, 2); // pop child metatable and nil parent metatable
                return;
            }

            lua_newtable(L);
            lua_pushvalue(L, -2); // duplicate parentMT
            lua_setfield(L, -2, "__index"); // newtable.__index = parentMT
            lua_setmetatable(L, -3); // childMT's metatable is newtable

            // 2. Link child __getters table __index fallback to parent __getters
            lua_pushstring(L, "__getters");
            lua_rawget(L, -3); // childMT is at -3
            if (lua_istable(L, -1)) {
                lua_newtable(L);
                lua_pushstring(L, "__getters");
                lua_rawget(L, -4); // parentMT is at -4
                if (lua_istable(L, -1)) {
                    lua_setfield(L, -2, "__index");
                    lua_setmetatable(L, -2);
                } else {
                    lua_pop(L, 2);
                }
            }
            lua_pop(L, 1); // pop childGetters

            // 3. Link child __setters table __index fallback to parent __setters
            lua_pushstring(L, "__setters");
            lua_rawget(L, -3); // childMT is at -3
            if (lua_istable(L, -1)) {
                lua_newtable(L);
                lua_pushstring(L, "__setters");
                lua_rawget(L, -4); // parentMT is at -4
                if (lua_istable(L, -1)) {
                    lua_setfield(L, -2, "__index");
                    lua_setmetatable(L, -2);
                } else {
                    lua_pop(L, 2);
                }
            }
            lua_pop(L, 1); // pop childSetters

            lua_pop(L, 1); // pop parentMT
        }
        lua_pop(L, 1); // pop childMT
    }

} // namespace KenshiLua