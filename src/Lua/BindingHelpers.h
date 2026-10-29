#pragma once

#include <string>
#include <cstring>
#include <cstdio>

#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_enum.hpp>
#include <boost/type_traits/is_integral.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/algorithm/string.hpp>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    // =========================================================================
    // Forward Declarations & Logging
    // =========================================================================

    void logToFileWarn(const std::string& message);
    void logToFileError(const std::string& message);

    // =========================================================================
    // Source & Path Utilities
    // =========================================================================

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

        // Containment matches the same file named through different paths, such as a
        // mod-relative chunk name and an absolute path from the Script Editor.
        if (boost::algorithm::contains(normHandler, normTarget) || boost::algorithm::contains(normTarget, normHandler))
            return true;

        // Scripts are matched per file, never per mod. ScriptLoader removes the handlers
        // and widgets of a script before loading or reloading it; matching every script
        // in the same mod made loading one file remove what the mod's other files had
        // registered.

        return false;
    }

    // =========================================================================
    // Userdata & Object Lifetime Management
    // =========================================================================

    template <class T>
    inline T* testObject(lua_State* L, int idx, const char* metatableName)
    {
        if (!lua_isuserdata(L, idx) || !metatableName) return 0;
        if (idx < 0 && idx > LUA_REGISTRYINDEX) {
            idx = lua_gettop(L) + idx + 1;
        }

        int top = lua_gettop(L);
        bool match = false;
        if (lua_getmetatable(L, idx)) { // Stack: top+1 = origMT
            int origMTIdx = top + 1;

            lua_pushstring(L, "__isa");
            lua_rawget(L, origMTIdx); // Stack: top+2 = __isa (or nil)
            if (lua_istable(L, -1)) {
                lua_pushstring(L, metatableName);
                lua_rawget(L, -2);
                if (lua_isboolean(L, -1)) {
                    match = (lua_toboolean(L, -1) != 0);
                    lua_settop(L, top);
                    if (!match) return 0;
                    void* raw = lua_touserdata(L, idx);
                    return raw ? (T*)*((void**)raw) : 0;
                }
                lua_pop(L, 1);
            } else {
                lua_pop(L, 1);
                lua_newtable(L);
                lua_pushstring(L, "__isa");
                lua_pushvalue(L, -2);
                lua_rawset(L, origMTIdx);
            }
            int isaIdx = top + 2;

            lua_pushvalue(L, origMTIdx); // Stack: top+3 = curMT
            for (int depth = 0; depth < 32; ++depth) {
                lua_pushstring(L, "__name");
                lua_rawget(L, -2);
                const char* name = lua_tostring(L, -1);
                bool eq = (name && strcmp(name, metatableName) == 0);
                lua_pop(L, 1);

                if (eq) {
                    match = true;
                    break;
                }

                if (!lua_getmetatable(L, -1)) {
                    break;
                }

                lua_pushstring(L, "__index");
                lua_rawget(L, -2);
                if (lua_istable(L, -1) && !lua_rawequal(L, -1, -3)) {
                    lua_replace(L, -3);
                    lua_pop(L, 1);
                } else {
                    break;
                }
            }

            lua_pushstring(L, metatableName);
            lua_pushboolean(L, match ? 1 : 0);
            lua_rawset(L, isaIdx);
        }
        lua_settop(L, top);

        if (match) {
            void* raw = lua_touserdata(L, idx);
            return raw ? (T*)*((void**)raw) : 0;
        }
        return 0;
    }

    // Pushes and returns a readable type name for the value at idx: the metatable
    // __name of bound userdata, otherwise the Lua type name.
    inline const char* pushArgumentTypeName(lua_State* L, int idx)
    {
        int type = lua_type(L, idx);
        if (type == LUA_TUSERDATA && lua_getmetatable(L, idx)) {
            lua_pushstring(L, "__name");
            lua_rawget(L, -2);
            if (lua_type(L, -1) == LUA_TSTRING) {
                lua_remove(L, -2);
                return lua_tostring(L, -1);
            }
            lua_pop(L, 2);
        }
        lua_pushstring(L, type == LUA_TLIGHTUSERDATA ? "lightuserdata" : luaL_typename(L, idx));
        return lua_tostring(L, -1);
    }

    template <class T>
    inline T* checkObject(lua_State* L, int idx, const char* metatableName)
    {
        T* ptr = testObject<T>(L, idx, metatableName);
        if (!ptr) {
            const char* msg = lua_pushfstring(L, "%s expected, got %s",
                metatableName, pushArgumentTypeName(L, idx));
            luaL_argerror(L, idx, msg);
            return 0;
        }
        return ptr;
    }

    // Allocates a new userdata wrapping `ptr` and assigns the named metatable.
    // If ptr is null, pushes nil instead. Always returns 1 (one Lua value pushed).
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

    // Same as pushObject<T> but uses BindingT::getMetatableName() so call sites
    // can be terse: pushObjectT<Character, CharacterBinding>(L, c);
    template <class T, class BindingT>
    inline int pushObjectT(lua_State* L, T* ptr)
    {
        return pushObject<T>(L, ptr, BindingT::getMetatableName());
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

    template <class T, lua_CFunction GcFn>
    inline int pushObjectOwnedCustom(lua_State* L, T* ptr, const char* baseMetatableName)
    {
        if (!ptr) {
            lua_pushnil(L);
            return 1;
        }

        if (!baseMetatableName || !*baseMetatableName) {
            logToFileWarn("[BindingHelpers] pushObjectOwnedCustom: baseMetatableName is null or empty!");
            lua_pushnil(L);
            return 1;
        }

        void** ud = (void**)lua_newuserdata(L, sizeof(void*));
        *ud = (void*)ptr;
        int udIdx = lua_gettop(L);

        char ownedMetaName[160];
        _snprintf(ownedMetaName, sizeof(ownedMetaName), "%s_Owned_%p", baseMetatableName, (void*)GcFn);
        ownedMetaName[sizeof(ownedMetaName) - 1] = '\0';

        luaL_getmetatable(L, ownedMetaName);

        if (lua_isnil(L, -1)) {
            lua_pop(L, 1);
            luaL_newmetatable(L, ownedMetaName);
            int ownedMTIdx = lua_gettop(L);

            luaL_getmetatable(L, baseMetatableName);
            if (lua_istable(L, -1)) {
                int baseMTIdx = lua_gettop(L);

                lua_pushnil(L);
                while (lua_next(L, baseMTIdx) != 0) {
                    if (lua_type(L, -2) == LUA_TSTRING && strcmp(lua_tostring(L, -2), "__gc") == 0) {
                        lua_pop(L, 1);
                    } else {
                        lua_pushvalue(L, -2);
                        lua_insert(L, -2);
                        lua_rawset(L, ownedMTIdx);
                    }
                }

                lua_newtable(L);
                lua_pushvalue(L, baseMTIdx);
                lua_setfield(L, -2, "__index");
                lua_setmetatable(L, ownedMTIdx);

                lua_pop(L, 1);
            } else {
                logToFileWarn(std::string("[BindingHelpers] pushObjectOwnedCustom: base metatable '") + baseMetatableName + "' not found!");
                lua_pop(L, 1);
            }

            lua_pushstring(L, baseMetatableName);
            lua_setfield(L, ownedMTIdx, "__name");

            lua_pushcfunction(L, GcFn);
            lua_setfield(L, ownedMTIdx, "__gc");
        }

        lua_setmetatable(L, udIdx);
        return 1;
    }

    template <class T>
    inline int pushObjectOwned(lua_State* L, T* ptr, const char* baseMetatableName)
    {
        return pushObjectOwnedCustom<T, ownedObjectGc<T>>(L, ptr, baseMetatableName);
    }

    inline std::string extractContainerTypeName(lua_State* L, int idx)
    {
        if (lua_isstring(L, idx))
        {
            return lua_tostring(L, idx);
        }
        else if (lua_isuserdata(L, idx))
        {
            if (lua_getmetatable(L, idx))
            {
                lua_pushstring(L, "__name");
                lua_rawget(L, -2);
                std::string typeName;
                if (lua_isstring(L, -1))
                    typeName = lua_tostring(L, -1);
                lua_pop(L, 2);
                return typeName;
            }
        }
        else if (lua_istable(L, idx))
        {
            lua_pushstring(L, "__name");
            lua_rawget(L, idx);
            std::string typeName;
            if (lua_isstring(L, -1))
                typeName = lua_tostring(L, -1);
            lua_pop(L, 1);

            if (typeName.empty())
            {
                if (lua_getmetatable(L, idx))
                {
                    lua_pushstring(L, "__name");
                    lua_rawget(L, -2);
                    if (lua_isstring(L, -1))
                        typeName = lua_tostring(L, -1);
                    lua_pop(L, 2);
                }
            }
            return typeName;
        }
        return "";
    }

    template <class T>
    inline int pushValue(lua_State* L, const T& val, const char* metatableName)
    {
        void* mem = ::operator new(sizeof(T));
        T* ptr = ::new(mem) T(val);
        return pushObjectOwned<T>(L, ptr, metatableName);
    }

    // =========================================================================
    // Generic Metamethods & Universal Property Dispatchers
    // =========================================================================

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

    // Intercepts obj.property and routes it to the correct getter in __getters, 
    // or returns the method if it exists in the metatable.
    inline int genericPropertyIndex(lua_State* L)
    {
        // Stack: 1 = userdata (object), 2 = key
        if (lua_type(L, 2) != LUA_TSTRING) {
            lua_pushnil(L);
            return 1;
        }

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
                    lua_CFunction getter = lua_tocfunction(L, -1);
                    lua_settop(L, 1); // Leave only arg 1 (userdata) on stack
                    return getter(L);
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
                    lua_CFunction setter = lua_tocfunction(L, -1);
                    lua_settop(L, 3); // Leave userdata (1), key (2), value (3)
                    lua_remove(L, 2); // Remove key so stack is userdata (1), value (2)
                    return setter(L);
                }
            }
        }

        return luaL_error(L, "Property '%s' is read-only or does not exist",
            lua_isstring(L, 2) ? lua_tostring(L, 2) : luaL_typename(L, 2));
    }

    // =========================================================================
    // Registration & Metatable Inheritance Helpers
    // =========================================================================

    inline void registerStaticMethod(lua_State* L, const char* name, lua_CFunction func)
    {
        lua_pushcfunction(L, func);
        lua_setfield(L, -2, name);
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

    template<typename T>
    inline void setEnum(lua_State* L, const char* name, T value)
    {
        lua_pushinteger(L, static_cast<lua_Integer>(value));
        lua_setfield(L, -2, name);
    }

    inline void pushGlobalTable(lua_State* L, const char* tableName)
    {
        lua_getglobal(L, tableName);
        if (!lua_istable(L, -1)) {
            lua_pop(L, 1);
            lua_newtable(L);
        }
    }

    // Pushes the table at a dotted global path, creating each missing table.
    inline void pushGlobalTablePath(lua_State* L, const char* tablePath)
    {
        const char* segment = tablePath;
        const char* separator = strchr(segment, '.');
        std::string name(segment, separator ? separator - segment : strlen(segment));

        lua_getglobal(L, name.c_str());
        if (!lua_istable(L, -1)) {
            lua_pop(L, 1);
            lua_newtable(L);
            lua_pushvalue(L, -1);
            lua_setglobal(L, name.c_str());
        }

        while (separator) {
            segment = separator + 1;
            separator = strchr(segment, '.');
            name.assign(segment, separator ? separator - segment : strlen(segment));

            lua_getfield(L, -1, name.c_str());
            if (!lua_istable(L, -1)) {
                lua_pop(L, 1);
                lua_newtable(L);
                lua_pushvalue(L, -1);
                lua_setfield(L, -3, name.c_str());
            }
            lua_remove(L, -2);
        }
    }

    inline void registerConstructor(lua_State* L, lua_CFunction constructor)
    {
        lua_newtable(L);
        lua_pushcfunction(L, constructor);
        lua_setfield(L, -2, "__call");
        lua_setmetatable(L, -2);
    }

    inline void setNestedClassTable(lua_State* L, const char* parentClassName, const char* fieldName)
    {
        pushGlobalTablePath(L, parentClassName);
        lua_pushvalue(L, -2);
        lua_setfield(L, -2, fieldName);
        lua_pop(L, 1);
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

        lua_newtable(L);
        lua_setfield(L, -2, "__getters");

        lua_newtable(L);
        lua_setfield(L, -2, "__setters");

        lua_pop(L, 1);
    }

    // Establishes metatable inheritance for methods, getters, and setters between two class metatables.
    inline void setMetatableParent(lua_State* L, const char* childMeta, const char* parentMeta)
    {
        // 1. Link child metatable __index fallback to parent metatable
        luaL_getmetatable(L, childMeta);
        if (lua_istable(L, -1)) {
            int childMTIdx = lua_gettop(L);
            luaL_getmetatable(L, parentMeta);
            if (!lua_istable(L, -1)) {
                // Parent metatable doesn't exist, log a warning or return safely
                KenshiLua::logToFileWarn(std::string("[BindingHelpers] setMetatableParent: parent '") + parentMeta + "' not found for child '" + childMeta + "'");
                lua_pop(L, 2); // pop child metatable and nil parent metatable
                return;
            }
            int parentMTIdx = lua_gettop(L);

            lua_pushstring(L, "__isa");
            lua_pushnil(L);
            lua_rawset(L, childMTIdx);

            lua_newtable(L);
            lua_pushvalue(L, parentMTIdx); // duplicate parentMT
            lua_setfield(L, -2, "__index"); // newtable.__index = parentMT
            lua_setmetatable(L, childMTIdx); // childMT's metatable is newtable

            // 2. Ensure child and parent __getters tables exist and link child -> parent
            lua_pushstring(L, "__getters");
            lua_rawget(L, childMTIdx);
            if (!lua_istable(L, -1)) {
                lua_pop(L, 1);
                lua_newtable(L);
                lua_pushstring(L, "__getters");
                lua_pushvalue(L, -2);
                lua_rawset(L, childMTIdx);
            }
            lua_pushstring(L, "__getters");
            lua_rawget(L, parentMTIdx);
            if (!lua_istable(L, -1)) {
                lua_pop(L, 1);
                lua_newtable(L);
                lua_pushstring(L, "__getters");
                lua_pushvalue(L, -2);
                lua_rawset(L, parentMTIdx);
            }
            lua_newtable(L);
            lua_pushvalue(L, -2); // parentGetters
            lua_setfield(L, -2, "__index");
            lua_setmetatable(L, -3); // childGetters's metatable
            lua_pop(L, 2); // pop parentGetters and childGetters

            // 3. Ensure child and parent __setters tables exist and link child -> parent
            lua_pushstring(L, "__setters");
            lua_rawget(L, childMTIdx);
            if (!lua_istable(L, -1)) {
                lua_pop(L, 1);
                lua_newtable(L);
                lua_pushstring(L, "__setters");
                lua_pushvalue(L, -2);
                lua_rawset(L, childMTIdx);
            }
            lua_pushstring(L, "__setters");
            lua_rawget(L, parentMTIdx);
            if (!lua_istable(L, -1)) {
                lua_pop(L, 1);
                lua_newtable(L);
                lua_pushstring(L, "__setters");
                lua_pushvalue(L, -2);
                lua_rawset(L, parentMTIdx);
            }
            lua_newtable(L);
            lua_pushvalue(L, -2); // parentSetters
            lua_setfield(L, -2, "__index");
            lua_setmetatable(L, -3); // childSetters's metatable
            lua_pop(L, 2); // pop parentSetters and childSetters

            lua_pop(L, 1); // pop parentMT
        }
        lua_pop(L, 1); // pop childMT
    }

    // =========================================================================
    // Struct & Math Marshaling Helpers (Lua Tables <-> C++ Objects)
    // =========================================================================

    // -------------------------------------------------------------------------
    // 2D Coordinates & Geometry (Vector2 / Point)
    // -------------------------------------------------------------------------

    // Build a Vector2-like Lua table {x=,y=} from any object exposing .x/.y (e.g. Ogre::Vector2).
    template <class V2>
    inline void pushVector2(lua_State* L, const V2& v)
    {
        lua_createtable(L, 0, 2);
        lua_pushnumber(L, v.x); lua_setfield(L, -2, "x");
        lua_pushnumber(L, v.y); lua_setfield(L, -2, "y");
    }

    // Read a {x,y} table at idx. Missing fields default to 0. Returns true if any field was present.
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

    // Build a Point/Coord-like Lua table {left=,top=,x=,y=} from any object exposing .left/.top (e.g. MyGUI::types::TPoint).
    template <class PT>
    inline void pushPoint(lua_State* L, const PT& pt)
    {
        lua_createtable(L, 0, 4);
        lua_pushinteger(L, pt.left); lua_setfield(L, -2, "left");
        lua_pushinteger(L, pt.top);  lua_setfield(L, -2, "top");
        lua_pushinteger(L, pt.left); lua_setfield(L, -2, "x");
        lua_pushinteger(L, pt.top);  lua_setfield(L, -2, "y");
    }

    // -------------------------------------------------------------------------
    // 3D & 4D Vectors / Rotations (Vector3 / Quaternion)
    // -------------------------------------------------------------------------

    // Build a Vector3-like Lua table {x=,y=,z=} from any object exposing .x/.y/.z (e.g. Ogre::Vector3).
    template <class V3>
    inline void pushVector3(lua_State* L, const V3& v)
    {
        lua_createtable(L, 0, 3);
        lua_pushnumber(L, v.x); lua_setfield(L, -2, "x");
        lua_pushnumber(L, v.y); lua_setfield(L, -2, "y");
        lua_pushnumber(L, v.z); lua_setfield(L, -2, "z");
    }

    // Read a {x,y,z} table at idx. Missing fields default to 0. Returns true if any field was present.
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

    // Build a Quaternion-like Lua table {w=,x=,y=,z=} from any object exposing .w/.x/.y/.z (e.g. Ogre::Quaternion).
    template <class Q4>
    inline void pushQuaternion(lua_State* L, const Q4& q)
    {
        lua_createtable(L, 0, 4);
        lua_pushnumber(L, q.w); lua_setfield(L, -2, "w");
        lua_pushnumber(L, q.x); lua_setfield(L, -2, "x");
        lua_pushnumber(L, q.y); lua_setfield(L, -2, "y");
        lua_pushnumber(L, q.z); lua_setfield(L, -2, "z");
    }

    // Read a {w,x,y,z} table at idx. Missing fields default to 0 (w defaults to 1.0). Returns true if any field was present.
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

    // Build a Vector4-like Lua table {x=,y=,z=,w=} from any object exposing .x/.y/.z/.w (e.g. Ogre::Vector4).
    template <class V4>
    inline void pushVector4(lua_State* L, const V4& v)
    {
        lua_createtable(L, 0, 4);
        lua_pushnumber(L, v.x); lua_setfield(L, -2, "x");
        lua_pushnumber(L, v.y); lua_setfield(L, -2, "y");
        lua_pushnumber(L, v.z); lua_setfield(L, -2, "z");
        lua_pushnumber(L, v.w); lua_setfield(L, -2, "w");
    }

    // Read a {x,y,z,w} table at idx. Missing fields default to 0. Returns true if any field was present.
    template <class V4>
    inline bool readVector4(lua_State* L, int idx, V4& out)
    {
        if (!lua_istable(L, idx)) return false;
        out.x = 0.0f; out.y = 0.0f; out.z = 0.0f; out.w = 0.0f;
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

        lua_getfield(L, idx, "w");
        if (!lua_isnil(L, -1)) { out.w = (float)lua_tonumber(L, -1); any = true; }
        else {
            lua_pop(L, 1);
            lua_rawgeti(L, idx, 4);
            if (!lua_isnil(L, -1)) { out.w = (float)lua_tonumber(L, -1); any = true; }
        }
        lua_pop(L, 1);
        return any;
    }

    // -------------------------------------------------------------------------
    // Colors & Integer Tuples (ColourValue / TripleInt)
    // -------------------------------------------------------------------------

    // Build a ColourValue-like Lua table {r=,g=,b=,a=} from any object exposing .r/.g/.b/.a.
    template <class CV>
    inline void pushColourValue(lua_State* L, const CV& c)
    {
        lua_createtable(L, 0, 4);
        lua_pushnumber(L, c.r); lua_setfield(L, -2, "r");
        lua_pushnumber(L, c.g); lua_setfield(L, -2, "g");
        lua_pushnumber(L, c.b); lua_setfield(L, -2, "b");
        lua_pushnumber(L, c.a); lua_setfield(L, -2, "a");
    }

    // Read a ColourValue-like Lua table at idx. Missing fields default to 0 (a defaults to 1.0).
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

    // Build a TripleInt-like Lua table {val1, val2, val3} from any object exposing .value[3].
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

    template <class V2>
    inline void checkVector2(lua_State* L, int idx, V2& out)
    {
        if (!readVector2(L, idx, out))
        {
            const char* msg = lua_pushfstring(L, "Vector2 expected, got %s",
                pushArgumentTypeName(L, idx));
            luaL_argerror(L, idx, msg);
        }
    }

    template <class V3>
    inline void checkVector3(lua_State* L, int idx, V3& out)
    {
        if (!readVector3(L, idx, out))
        {
            const char* msg = lua_pushfstring(L, "Vector3 expected, got %s",
                pushArgumentTypeName(L, idx));
            luaL_argerror(L, idx, msg);
        }
    }

    template <class Q4>
    inline void checkQuaternion(lua_State* L, int idx, Q4& out)
    {
        if (!readQuaternion(L, idx, out))
        {
            const char* msg = lua_pushfstring(L, "Quaternion expected, got %s",
                pushArgumentTypeName(L, idx));
            luaL_argerror(L, idx, msg);
        }
    }

    template <class V4>
    inline void checkVector4(lua_State* L, int idx, V4& out)
    {
        if (!readVector4(L, idx, out))
        {
            const char* msg = lua_pushfstring(L, "Vector4 expected, got %s",
                pushArgumentTypeName(L, idx));
            luaL_argerror(L, idx, msg);
        }
    }

    template <class CV>
    inline void checkColourValue(lua_State* L, int idx, CV& out)
    {
        if (!readColourValue(L, idx, out))
        {
            const char* msg = lua_pushfstring(L, "ColourValue expected, got %s",
                pushArgumentTypeName(L, idx));
            luaL_argerror(L, idx, msg);
        }
    }

    template <class TI>
    inline void checkTripleInt(lua_State* L, int idx, TI& out)
    {
        if (!readTripleInt(L, idx, out))
        {
            const char* msg = lua_pushfstring(L, "TripleInt expected, got %s",
                pushArgumentTypeName(L, idx));
            luaL_argerror(L, idx, msg);
        }
    }

    // =========================================================================

} // namespace KenshiLua
