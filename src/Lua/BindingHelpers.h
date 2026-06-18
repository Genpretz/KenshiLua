#pragma once

// -----------------------------------------------------------------------------
// BindingHelpers.h
//
// One canonical place for the binding boilerplate that was previously copy-
// pasted across every Bindings/*.cpp file.  Keeps things MSVC2010 / v100
// compatible: no variadic templates, no lambdas, no auto.
//
// Lifetime model: we wrap *engine-owned* pointers (Character*, Faction*, ...).
// The userdata stores a single 'void*' slot.  We never delete the wrapped
// pointer in __gc; Kenshi owns it.  Value-type wrappers (Damages, hand) that
// are placement-newed into the userdata have their own __gc that calls the
// destructor and must NOT use this helper.
// -----------------------------------------------------------------------------

#include <string>
#include <cstring>
#include <cstdio>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

// Generic per-type binding traits.  Each binding specializes (or relies on a
// matching BindingT::getMetatableName()) by way of using its static method.
// We avoid a real traits class to keep things simple - the convention is just
// that every binding class B has a `static const char* getMetatableName()`.

template <class T>
inline T* checkObject(lua_State* L, int idx, const char* metatableName)
{
    void** ud = (void**)luaL_checkudata(L, idx, metatableName);
    return ud ? (T*)*ud : 0;
}

template <class T>
inline T* testObject(lua_State* L, int idx, const char* metatableName)
{
    void* raw = luaL_testudata(L, idx, metatableName);
    if (!raw) return 0;
    return (T*)*((void**)raw);
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

// Standardised metatable construction.  Use this in every binding's
// registerBinding(L).  The fix vs. the legacy pattern: we set __index to the
// metatable itself exactly once.  The metatable doubles as the method table,
// so listing methods directly on it (via luaL_setfuncs) makes them callable
// as `obj:method(...)` without an extra C `__index` strcmp chain.
//
// methods may be NULL if you only want metamethods.
// Standardised metatable construction.  Use this in every binding's
// registerBinding(L).
//
// When indexFunc / newindexFunc are NULL (the default), __index is set to the
// metatable itself (the standard Lua method-table idiom) — suitable for
// bindings that expose only methods and no raw member fields via dot-access.
//
// When indexFunc / newindexFunc are provided, they are registered as C-function
// metamethods instead.  The C function is then responsible for checking the
// metatable for method lookups first (see e.g. BuildingBinding::index) so that
// obj:method() syntax continues to work alongside obj.field dot-access.
//
// methods may be NULL if you only want metamethods.
inline void registerClass(lua_State* L,
    const char* metatableName,
    const luaL_Reg* metamethods,
    const luaL_Reg* methods,
    lua_CFunction indexFunc = NULL,
    lua_CFunction newindexFunc = NULL)
{
    if (!luaL_newmetatable(L, metatableName)) {
        // Already registered — bail.  Pop the existing metatable and return.
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

// Convenience: build a Vector3-like Lua table {x=,y=,z=} from any object
// exposing .x/.y/.z (Ogre::Vector3 fits).  Templated so we don't drag the
// Ogre header into this helper.
template <class V3>
inline void pushVector3(lua_State* L, const V3& v)
{
    lua_createtable(L, 0, 3);
    lua_pushnumber(L, v.x); lua_setfield(L, -2, "x");
    lua_pushnumber(L, v.y); lua_setfield(L, -2, "y");
    lua_pushnumber(L, v.z); lua_setfield(L, -2, "z");
}

// Read a {x,y,z} table at idx.  Missing fields default to 0.  Returns true
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

// Generic __tostring that produces "Type:%p".  Most bindings can point their
// metatable's __tostring at a one-line wrapper that calls this.
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

} // namespace KenshiLua

// -----------------------------------------
// Helper Macros
// -----------------------------------------

// Getters
#define LUA_GET_FLOAT_MEMBER(name) \
    if (strcmp(key, #name) == 0) { \
        lua_pushnumber(L, m->name); \
        return 1; \
    }

#define LUA_GET_INT_MEMBER(name) \
    if (strcmp(key, #name) == 0) { \
        lua_pushinteger(L, m->name); \
        return 1; \
    }

#define LUA_GET_BOOL_MEMBER(name) \
    if (strcmp(key, #name) == 0) { \
        lua_pushboolean(L, m->name); \
        return 1; \
    }

#define LUA_GET_ENUM_MEMBER(name, EnumType) \
    if (strcmp(key, #name) == 0) { \
        lua_pushinteger(L, static_cast<lua_Integer>(m->name)); \
        return 1; \
    }

#define LUA_GET_STRING_MEMBER(name) \
    if (strcmp(key, #name) == 0) { \
        lua_pushstring(L, m->name.c_str()); \
        return 1; \
    }

// Setters
#define LUA_SET_FLOAT_MEMBER(name) \
    if (strcmp(key, #name) == 0) { \
        m->name = static_cast<float>(luaL_checknumber(L, 3)); \
        return 0; \
    }

#define LUA_SET_INT_MEMBER(name) \
    if (strcmp(key, #name) == 0) { \
        m->name = static_cast<int>(luaL_checkinteger(L, 3)); \
        return 0; \
    }

#define LUA_SET_BOOL_MEMBER(name) \
    if (strcmp(key, #name) == 0) { \
        m->name = (lua_toboolean(L, 3) != 0); \
        return 0; \
    }

#define LUA_SET_ENUM_MEMBER(name, EnumType) \
    if (strcmp(key, #name) == 0) { \
        m->name = static_cast<EnumType>(luaL_checkinteger(L, 3)); \
        return 0; \
    }

#define LUA_SET_STRING_MEMBER(name) \
    if (strcmp(key, #name) == 0) { \
        m->name = luaL_checkstring(L, 3); \
        return 0; \
    }

// examples
// LUA_GET_FLOAT_MEMBER(blood);
//
// LUA_SET_BOOL_MEMBER(dead);
//
// LUA_SET_ENUM_MEMBER(proneState, ProneState)