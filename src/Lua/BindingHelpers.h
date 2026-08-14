#pragma once

#include <string>
#include <cstring>
#include <cstdio>

#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_enum.hpp>
#include <boost/type_traits/is_integral.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/algorithm/string.hpp>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    void logToFileWarn(const std::string& message);

    inline std::string normalizeSourceString(std::string s)
    {
        if (s.empty()) return "";
        if (s[0] == '@') s.erase(0, 1);
        boost::algorithm::replace_all(s, "\\", "/");
        boost::algorithm::to_lower(s);
        return s;
    }

    inline bool sourceMatches(const std::string& handlerSource, const std::string& targetSource)
    {
        std::string normHandler = normalizeSourceString(handlerSource);
        std::string normTarget = normalizeSourceString(targetSource);

        if (normHandler.empty() || normTarget.empty()) return false;
        if (normHandler == normTarget) return true;

        if (boost::algorithm::contains(normHandler, normTarget) || boost::algorithm::contains(normTarget, normHandler))
            return true;


        size_t slashIdx1 = normHandler.find('/');
        size_t slashIdx2 = normTarget.find('/');
        if (slashIdx1 != std::string::npos && slashIdx2 != std::string::npos)
        {
            std::string mod1 = normHandler.substr(0, slashIdx1);
            std::string mod2 = normTarget.substr(0, slashIdx2);
            if (!mod1.empty() && mod1 == mod2)
                return true;
        }

        return false;
    }


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
            logToFileWarn(std::string("[BindingHelpers] pushObject: metatable '") + metatableName + "' missing/unregistered in Lua!");
            lua_pop(L, 2); // pop nil metatable + the new userdata
            lua_pushnil(L);
            return 1;
        }
        lua_setmetatable(L, -2);
        return 1;
    }

    template <class T>
    inline int ownedObjectGc(lua_State* L)
    {
        void** ud = (void**)lua_touserdata(L, 1);
        if (ud && *ud) {
            T* ptr = static_cast<T*>(*ud);
            ptr->~T();
            ::operator delete((void*)ptr);
            *ud = nullptr;
        }
        return 0;
    }

    template <class T>
    inline int pushObjectOwned(lua_State* L, T* ptr, const char* baseMetatableName)
    {
        if (!ptr) {
            lua_pushnil(L);
            return 1;
        }

        std::string ownedMetaName = std::string(baseMetatableName) + "_Owned";
        luaL_getmetatable(L, ownedMetaName.c_str());
        if (lua_isnil(L, -1)) {
            lua_pop(L, 1);
            luaL_newmetatable(L, ownedMetaName.c_str());

            // Set __name to baseMetatableName so testObject<T> matches seamlessly
            lua_pushstring(L, "__name");
            lua_pushstring(L, baseMetatableName);
            lua_rawset(L, -3);

            // Set __index to point to base metatable for method/getter inheritance
            luaL_getmetatable(L, baseMetatableName);
            lua_setfield(L, -2, "__index");

            // Set __gc to automatically delete heap-allocated memory
            lua_pushcfunction(L, ownedObjectGc<T>);
            lua_setfield(L, -2, "__gc");

            // Copy __getters from base metatable so genericPropertyIndex works
            luaL_getmetatable(L, baseMetatableName);
            if (lua_istable(L, -1)) {
                lua_getfield(L, -1, "__getters");
                if (lua_istable(L, -1)) {
                    lua_setfield(L, -4, "__getters"); // set on _Owned MT
                } else {
                    lua_pop(L, 1);
                }
                lua_getfield(L, -1, "__setters");
                if (lua_istable(L, -1)) {
                    lua_setfield(L, -4, "__setters"); // set on _Owned MT
                } else {
                    lua_pop(L, 1);
                }
            }
            lua_pop(L, 1); // pop base metatable
        }

        void** ud = (void**)lua_newuserdata(L, sizeof(void*));
        *ud = (void*)ptr;
        lua_setmetatable(L, -2);
        return 1;
    }

    template <class T>
    inline int pushValue(lua_State* L, const T& val, const char* metatableName)
    {
        void* mem = ::operator new(sizeof(T));
        T* ptr = ::new(mem) T(val);
        return pushObjectOwned<T>(L, ptr, metatableName);
    }



    inline void registerGetter(lua_State* L, const char* name, lua_CFunction getter)
    {
        lua_pushcfunction(L, getter);
        lua_setfield(L, -2, name);
    }

    inline void registerSetter(lua_State* L, const char* name, lua_CFunction setter)
    {
        lua_pushcfunction(L, setter);
        lua_setfield(L, -2, name);
    }

    // Same as pushObject<T> but uses BindingT::getMetatableName() so call sites
    // can be terse:  pushObjectT<Character, CharacterBinding>(L, c);
    template <class T, class BindingT>
    inline int pushObjectT(lua_State* L, T* ptr)
    {
        return pushObject<T>(L, ptr, BindingT::getMetatableName());
    }

    // Generic __eq metamethod for testing equality of the wrapped C++ pointers
    inline int genericEq(lua_State* L)
    {
        if (lua_isuserdata(L, 1) && lua_isuserdata(L, 2)) {
            void* ptr1 = lua_touserdata(L, 1);
            void* ptr2 = lua_touserdata(L, 2);
            if (ptr1 && ptr2) {
                lua_pushboolean(L, *((void**)ptr1) == *((void**)ptr2) ? 1 : 0);
                return 1;
            }
        }
        lua_pushboolean(L, 0);
        return 1;
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

        // Provide a default __eq metamethod for pointer equality
        lua_pushcfunction(L, genericEq);
        lua_setfield(L, -2, "__eq");

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

    // Build a Vector2-like Lua table {x=,y=} from any object
    // exposing .x/.y (Ogre::Vector2 fits).
    template <class V2>
    inline void pushVector2(lua_State* L, const V2& v)
    {
        lua_createtable(L, 0, 2);
        lua_pushnumber(L, v.x); lua_setfield(L, -2, "x");
        lua_pushnumber(L, v.y); lua_setfield(L, -2, "y");
    }

    // Build a Point/Coord-like Lua table {left=,top=,x=,y=} from any object
    // exposing .left/.top (MyGUI::types::TPoint fits).
    template <class PT>
    inline void pushPoint(lua_State* L, const PT& pt)
    {
        lua_createtable(L, 0, 4);
        lua_pushinteger(L, pt.left); lua_setfield(L, -2, "left");
        lua_pushinteger(L, pt.top);  lua_setfield(L, -2, "top");
        lua_pushinteger(L, pt.left); lua_setfield(L, -2, "x");
        lua_pushinteger(L, pt.top);  lua_setfield(L, -2, "y");
    }

    // Read a {x,y} table at idx. Missing fields default to 0. Returns true
    // if any of the two fields was actually present.
    template <class V2>
    inline bool readVector2(lua_State* L, int idx, V2& out)
    {
        if (!lua_istable(L, idx)) return false;
        out.x = 0.0f; out.y = 0.0f;
        bool any = false;
        lua_getfield(L, idx, "x");
        if (!lua_isnil(L, -1)) { out.x = (float)lua_tonumber(L, -1); any = true; }
        else {
            lua_pop(L, 1);
            lua_rawgeti(L, idx, 1);
            if (!lua_isnil(L, -1)) { out.x = (float)lua_tonumber(L, -1); any = true; }
        }
        lua_pop(L, 1);

        lua_getfield(L, idx, "y");
        if (!lua_isnil(L, -1)) { out.y = (float)lua_tonumber(L, -1); any = true; }
        else {
            lua_pop(L, 1);
            lua_rawgeti(L, idx, 2);
            if (!lua_isnil(L, -1)) { out.y = (float)lua_tonumber(L, -1); any = true; }
        }
        lua_pop(L, 1);
        return any;
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
        out.x = 0.0f; out.y = 0.0f; out.z = 0.0f;
        bool any = false;
        lua_getfield(L, idx, "x");
        if (!lua_isnil(L, -1)) { out.x = (float)lua_tonumber(L, -1); any = true; }
        else {
            lua_pop(L, 1);
            lua_rawgeti(L, idx, 1);
            if (!lua_isnil(L, -1)) { out.x = (float)lua_tonumber(L, -1); any = true; }
        }
        lua_pop(L, 1);

        lua_getfield(L, idx, "y");
        if (!lua_isnil(L, -1)) { out.y = (float)lua_tonumber(L, -1); any = true; }
        else {
            lua_pop(L, 1);
            lua_rawgeti(L, idx, 2);
            if (!lua_isnil(L, -1)) { out.y = (float)lua_tonumber(L, -1); any = true; }
        }
        lua_pop(L, 1);

        lua_getfield(L, idx, "z");
        if (!lua_isnil(L, -1)) { out.z = (float)lua_tonumber(L, -1); any = true; }
        else {
            lua_pop(L, 1);
            lua_rawgeti(L, idx, 3);
            if (!lua_isnil(L, -1)) { out.z = (float)lua_tonumber(L, -1); any = true; }
        }
        lua_pop(L, 1);
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
        out.w = 1.0f; out.x = 0.0f; out.y = 0.0f; out.z = 0.0f;
        bool any = false;
        lua_getfield(L, idx, "w");
        if (!lua_isnil(L, -1)) { out.w = (float)lua_tonumber(L, -1); any = true; }
        else {
            lua_pop(L, 1);
            lua_rawgeti(L, idx, 1);
            if (!lua_isnil(L, -1)) { out.w = (float)lua_tonumber(L, -1); any = true; }
        }
        lua_pop(L, 1);

        lua_getfield(L, idx, "x");
        if (!lua_isnil(L, -1)) { out.x = (float)lua_tonumber(L, -1); any = true; }
        else {
            lua_pop(L, 1);
            lua_rawgeti(L, idx, 2);
            if (!lua_isnil(L, -1)) { out.x = (float)lua_tonumber(L, -1); any = true; }
        }
        lua_pop(L, 1);

        lua_getfield(L, idx, "y");
        if (!lua_isnil(L, -1)) { out.y = (float)lua_tonumber(L, -1); any = true; }
        else {
            lua_pop(L, 1);
            lua_rawgeti(L, idx, 3);
            if (!lua_isnil(L, -1)) { out.y = (float)lua_tonumber(L, -1); any = true; }
        }
        lua_pop(L, 1);

        lua_getfield(L, idx, "z");
        if (!lua_isnil(L, -1)) { out.z = (float)lua_tonumber(L, -1); any = true; }
        else {
            lua_pop(L, 1);
            lua_rawgeti(L, idx, 4);
            if (!lua_isnil(L, -1)) { out.z = (float)lua_tonumber(L, -1); any = true; }
        }
        lua_pop(L, 1);
        return any;
    }

    // Build a TripleInt-like Lua table {val1, val2, val3} from any object
    // exposing .value[3].
    template <class TI>
    inline void pushTripleInt(lua_State* L, const TI& t)
    {
        lua_createtable(L, 3, 0);
        lua_pushinteger(L, t.value[0]); lua_rawseti(L, -2, 1);
        lua_pushinteger(L, t.value[1]); lua_rawseti(L, -2, 2);
        lua_pushinteger(L, t.value[2]); lua_rawseti(L, -2, 3);
    }

    // Read a TripleInt-like Lua table {val1, val2, val3} at idx.
    template <class TI>
    inline bool readTripleInt(lua_State* L, int idx, TI& out)
    {
        if (!lua_istable(L, idx)) return false;
        lua_rawgeti(L, idx, 1); out.value[0] = (int)lua_tointeger(L, -1); lua_pop(L, 1);
        lua_rawgeti(L, idx, 2); out.value[1] = (int)lua_tointeger(L, -1); lua_pop(L, 1);
        lua_rawgeti(L, idx, 3); out.value[2] = (int)lua_tointeger(L, -1); lua_pop(L, 1);
        return true;
    }

    // Build a ColourValue-like Lua table {r=,g=,b=,a=} from any object
    // exposing .r/.g/.b/.a.
    template <class CV>
    inline void pushColourValue(lua_State* L, const CV& c)
    {
        lua_createtable(L, 0, 4);
        lua_pushnumber(L, c.r); lua_setfield(L, -2, "r");
        lua_pushnumber(L, c.g); lua_setfield(L, -2, "g");
        lua_pushnumber(L, c.b); lua_setfield(L, -2, "b");
        lua_pushnumber(L, c.a); lua_setfield(L, -2, "a");
    }

    // Read a ColourValue-like Lua table at idx.
    template <class CV>
    inline bool readColourValue(lua_State* L, int idx, CV& out)
    {
        if (!lua_istable(L, idx)) return false;
        out.r = 0.0f; out.g = 0.0f; out.b = 0.0f; out.a = 1.0f;
        bool any = false;
        lua_getfield(L, idx, "r"); if (!lua_isnil(L, -1)) { out.r = (float)lua_tonumber(L, -1); any = true; } lua_pop(L, 1);
        lua_getfield(L, idx, "g"); if (!lua_isnil(L, -1)) { out.g = (float)lua_tonumber(L, -1); any = true; } lua_pop(L, 1);
        lua_getfield(L, idx, "b"); if (!lua_isnil(L, -1)) { out.b = (float)lua_tonumber(L, -1); any = true; } lua_pop(L, 1);
        lua_getfield(L, idx, "a"); if (!lua_isnil(L, -1)) { out.a = (float)lua_tonumber(L, -1); any = true; } lua_pop(L, 1);
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
    inline int rejectNewIndex(lua_State* L, const char* propertyName = NULL)
    {
        if (propertyName) {
            return luaL_error(L, "Property '%s' is read-only", propertyName);
        }
        if (lua_isstring(L, 2)) {
            return luaL_error(L, "Property '%s' is read-only", lua_tostring(L, 2));
        }
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
                KenshiLua::logToFileWarn(std::string("[BindingHelpers] setMetatableParent: parent '") + parentMeta + "' not found for child '" + childMeta + "'");
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