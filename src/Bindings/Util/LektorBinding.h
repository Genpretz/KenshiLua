// LektorBinding.h
#pragma once
#include <kenshi/util/lektor.h>
#include <kenshi/ModInfo.h>
#include "Bindings/ModInfoBinding.h"
#include <string.h>

#include <release_assert.h>

template<typename T>
void lektor_push_back(lektor<T>& lek, const T& val)
{
    if (lek.count >= lek.maxSize)
    {
        uint32_t newMax = lek.maxSize == 0 ? 4 : lek.maxSize * 2;
        T* newStuff = (T*)Ogre::AllocatedObject<
            Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL>
        >::operator new(newMax * sizeof(T));
        if (lek.stuff)
        {
            memcpy(newStuff, lek.stuff, lek.count * sizeof(T));
            Ogre::AllocatedObject<
                Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL>
            >::operator delete(lek.stuff);
        }
        lek.stuff = newStuff;
        lek.maxSize = newMax;
    }
    lek.stuff[lek.count++] = val;
}

template<typename T>
void lektor_pop_back(lektor<T>& lek)
{
    assert_release(lek.count > 0 && "lektor_pop_back: container is empty");
    --lek.count;
    lek.stuff[lek.count].~T();
}

template<typename T>
T lektor_pop_back_val(lektor<T>& lek)
{
    assert_release(lek.count > 0 && "lektor_pop_back_val: container is empty");
    T val = lek.stuff[lek.count - 1];
    --lek.count;
    lek.stuff[lek.count].~T();
    return val;
}

namespace KenshiLua
{
    // One binding per element type T (T = pointer type, e.g. Character*)
    template <typename T>
    struct LektorPtrBinding
    {
        static const char* metaName;
        static const char* elemMetaName;

        static const char* getMetatableName() { return metaName; }

        static lektor<T>* get(lua_State* L, int idx)
        {
            return checkObject<lektor<T>>(L, idx, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int len(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            lua_pushinteger(L, lek ? lek->count : 0);
            return 1;
        }

        static int index(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) { lua_pushnil(L); return 1; }

            // numeric index -> element access (1-based)
            if (lua_isnumber(L, 2))
            {
                uint32_t i = (uint32_t)lua_tointeger(L, 2);
                if (i < 1 || i > lek->count) { lua_pushnil(L); return 1; }
                return pushObject<typename std::remove_pointer<T>::type>(
                    L, lek->stuff[i - 1], elemMetaName);
            }

            // fall through to metatable methods (push, remove, etc.)
            luaL_getmetatable(L, metaName);
            lua_getfield(L, -1, luaL_checkstring(L, 2));
            return 1;
        }

        static int newindex(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) return luaL_error(L, "lektor is nil");

            if (!lua_isnumber(L, 2))
                return luaL_error(L, "lektor: only numeric indices are writable");

            uint32_t i = (uint32_t)lua_tointeger(L, 2);
            T val = checkObject<typename std::remove_pointer<T>::type>(L, 3, elemMetaName);
            if (!val) return luaL_error(L, "lektor: expected valid object for assignment");

            if (i >= 1 && i <= lek->count)
            {
                lek->stuff[i - 1] = val;
                return 0;
            }
            if (i == lek->count + 1)
            {
                lektor_push_back(*lek, val);
                return 0;
            }
            return luaL_error(L, "lektor: index %u out of range (size=%u, can append at %u)",
                i, lek->count, lek->count + 1);
        }

        // push(value) - explicit append, equivalent to newindex at count+1
        static int push(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) return luaL_error(L, "lektor is nil");
            T val = checkObject<typename std::remove_pointer<T>::type>(L, 2, elemMetaName);
            if (!val) return luaL_error(L, "lektor:push expected valid object");
            lektor_push_back(*lek, val);
            return 0;
        }

        // removeAt(i) - shift-left removal (O(n), but matches typical lektor usage)
        static int removeAt(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) return luaL_error(L, "lektor is nil");
            uint32_t i = (uint32_t)luaL_checkinteger(L, 2);
            if (i < 1 || i > lek->count) return luaL_error(L, "lektor:removeAt index out of range");

            for (uint32_t j = i; j < lek->count; ++j)
                lek->stuff[j - 1] = lek->stuff[j];
            --lek->count;
            return 0;
        }

        static int clear(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (lek) lek->clear(); // just resets count, matches lektor.h semantics
            return 0;
        }

        static int size(lua_State* L)
        {
            return len(L);
        }

        static int toTable(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) { lua_pushnil(L); return 1; }
            lua_createtable(L, (int)lek->count, 0);
            for (uint32_t i = 0; i < lek->count; ++i)
            {
                pushObject<typename std::remove_pointer<T>::type>(L, lek->stuff[i], elemMetaName);
                lua_rawseti(L, -2, (int)(i + 1));
            }
            return 1;
        }

        static int pop(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) return luaL_error(L, "lektor is nil");
            if (lek->count == 0) return luaL_error(L, "lektor:pop container is empty");
            T val = lektor_pop_back_val(*lek);
            return pushObject<typename std::remove_pointer<T>::type>(L, val, elemMetaName);
        }

        // Stateless iterator for __pairs/__ipairs: control = integer index (0-based previous)
        static int iterNext(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) return 0;
            uint32_t i = (uint32_t)lua_tointeger(L, 2) + 1; // advance to next (1-based)
            if (i > lek->count) return 0;
            lua_pushinteger(L, (lua_Integer)i);
            pushObject<typename std::remove_pointer<T>::type>(L, lek->stuff[i - 1], elemMetaName);
            return 2;
        }

        static int pairs(lua_State* L)
        {
            lua_pushcfunction(L, iterNext);
            lua_pushvalue(L, 1);
            lua_pushinteger(L, 0);
            return 3;
        }

        static int ipairs(lua_State* L) { return pairs(L); }

        static void registerBinding(lua_State* L, const char* name, const char* elemName)
        {
            metaName = name;
            elemMetaName = elemName;

            static const luaL_Reg meta[] = {
                { "__gc",       gc },
                { "__len",      len },
                { "__index",    index },
                { "__newindex", newindex },
                { "__pairs",    pairs },
                { "__ipairs",   ipairs },
                { 0, 0 }
            };
            static const luaL_Reg methods[] = {
                { "push",      push },
                { "pop",       pop },
                { "removeAt",  removeAt },
                { "clear",     clear },
                { "size",      size },
                { "toTable",   toTable },
                { 0, 0 }
            };
            registerClass(L, metaName, meta, methods, index, newindex);
        }
    };

    template <typename T>
    const char* LektorPtrBinding<T>::metaName = nullptr;
    template <typename T>
    const char* LektorPtrBinding<T>::elemMetaName = nullptr;


    // Binding for lektor<T> where T is a C++ value type (e.g. ModInfo)
    template <typename T>
    struct LektorValueBinding
    {
        static const char* metaName;
        static const char* elemMetaName;

        static const char* getMetatableName() { return metaName; }

        static lektor<T>* get(lua_State* L, int idx)
        {
            return checkObject<lektor<T>>(L, idx, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int len(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            lua_pushinteger(L, lek ? lek->count : 0);
            return 1;
        }

        static int index(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) { lua_pushnil(L); return 1; }

            if (lua_isnumber(L, 2))
            {
                uint32_t i = (uint32_t)lua_tointeger(L, 2);
                if (i < 1 || i > lek->count) { lua_pushnil(L); return 1; }
                return pushObject<T>(L, &lek->stuff[i - 1], elemMetaName);
            }

            luaL_getmetatable(L, metaName);
            lua_getfield(L, -1, luaL_checkstring(L, 2));
            return 1;
        }

        static int newindex(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) return luaL_error(L, "lektor is nil");

            if (!lua_isnumber(L, 2))
                return luaL_error(L, "lektor: only numeric indices are writable");

            uint32_t i = (uint32_t)lua_tointeger(L, 2);
            T* val = checkObject<T>(L, 3, elemMetaName);
            if (!val) return luaL_error(L, "lektor: expected valid object for assignment");

            if (i >= 1 && i <= lek->count)
            {
                lek->stuff[i - 1] = *val;
                return 0;
            }
            if (i == lek->count + 1)
            {
                lektor_push_back(*lek, *val);
                return 0;
            }
            return luaL_error(L, "lektor: index %u out of range (size=%u, can append at %u)",
                i, lek->count, lek->count + 1);
        }

        static int push(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) return luaL_error(L, "lektor is nil");
            T* val = checkObject<T>(L, 2, elemMetaName);
            if (!val) return luaL_error(L, "lektor:push expected valid object");
            lektor_push_back(*lek, *val);
            return 0;
        }

        static int removeAt(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) return luaL_error(L, "lektor is nil");
            uint32_t i = (uint32_t)luaL_checkinteger(L, 2);
            if (i < 1 || i > lek->count) return luaL_error(L, "lektor:removeAt index out of range");

            for (uint32_t j = i; j < lek->count; ++j)
                lek->stuff[j - 1] = lek->stuff[j];
            --lek->count;
            return 0;
        }

        static int clear(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (lek) lek->clear();
            return 0;
        }

        static int size(lua_State* L)
        {
            return len(L);
        }

        static int toTable(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) { lua_pushnil(L); return 1; }
            lua_createtable(L, (int)lek->count, 0);
            for (uint32_t i = 0; i < lek->count; ++i)
            {
                if (elemMetaName)
                    pushObject<T>(L, &lek->stuff[i], elemMetaName);
                else
                    LuaCodec<T>::push(L, lek->stuff[i], nullptr);
                lua_rawseti(L, -2, (int)(i + 1));
            }
            return 1;
        }

        static int pop(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) return luaL_error(L, "lektor is nil");
            if (lek->count == 0) return luaL_error(L, "lektor:pop container is empty");
            T val = lektor_pop_back_val(*lek);
            if (elemMetaName)
                return pushObject<T>(L, &val, elemMetaName);
            else
            {
                LuaCodec<T>::push(L, val, nullptr);
                return 1;
            }
        }

        static int iterNext(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) return 0;
            uint32_t i = (uint32_t)lua_tointeger(L, 2) + 1;
            if (i > lek->count) return 0;
            lua_pushinteger(L, (lua_Integer)i);
            if (elemMetaName)
                pushObject<T>(L, &lek->stuff[i - 1], elemMetaName);
            else
                LuaCodec<T>::push(L, lek->stuff[i - 1], nullptr);
            return 2;
        }

        static int pairs(lua_State* L)
        {
            lua_pushcfunction(L, iterNext);
            lua_pushvalue(L, 1);
            lua_pushinteger(L, 0);
            return 3;
        }

        static int ipairs(lua_State* L) { return pairs(L); }

        static void registerBinding(lua_State* L, const char* name, const char* elemName)
        {
            metaName = name;
            elemMetaName = elemName;

            static const luaL_Reg meta[] = {
                { "__gc",       gc },
                { "__len",      len },
                { "__index",    index },
                { "__newindex", newindex },
                { "__pairs",    pairs },
                { "__ipairs",   ipairs },
                { 0, 0 }
            };
            static const luaL_Reg methods[] = {
                { "push",      push },
                { "pop",       pop },
                { "removeAt",  removeAt },
                { "clear",     clear },
                { "size",      size },
                { "toTable",   toTable },
                { 0, 0 }
            };
            registerClass(L, metaName, meta, methods, index, newindex);
        }
    };

    template <typename T>
    const char* LektorValueBinding<T>::metaName = nullptr;
    template <typename T>
    const char* LektorValueBinding<T>::elemMetaName = nullptr;

    // Binding for lektor<T> where T is a C++ value type and is read-only (no operator= needed)
    template <typename T>
    struct LektorValueReadOnlyBinding
    {
        static const char* metaName;
        static const char* elemMetaName;

        static const char* getMetatableName() { return metaName; }

        static lektor<T>* get(lua_State* L, int idx)
        {
            return checkObject<lektor<T>>(L, idx, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int len(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            lua_pushinteger(L, lek ? lek->count : 0);
            return 1;
        }

        static int index(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) { lua_pushnil(L); return 1; }

            if (lua_isnumber(L, 2))
            {
                uint32_t i = (uint32_t)lua_tointeger(L, 2);
                if (i < 1 || i > lek->count) { lua_pushnil(L); return 1; }
                return pushObject<T>(L, &lek->stuff[i - 1], elemMetaName);
            }

            luaL_getmetatable(L, metaName);
            lua_getfield(L, -1, luaL_checkstring(L, 2));
            return 1;
        }

        static int newindex(lua_State* L)
        {
            return luaL_error(L, "lektor is read-only");
        }

        static int size(lua_State* L)
        {
            return len(L);
        }

        static int toTable(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) { lua_pushnil(L); return 1; }
            lua_createtable(L, (int)lek->count, 0);
            for (uint32_t i = 0; i < lek->count; ++i)
            {
                if (elemMetaName)
                    pushObject<T>(L, &lek->stuff[i], elemMetaName);
                else
                    LuaCodec<T>::push(L, lek->stuff[i], nullptr);
                lua_rawseti(L, -2, (int)(i + 1));
            }
            return 1;
        }

        static int iterNext(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) return 0;
            uint32_t i = (uint32_t)lua_tointeger(L, 2) + 1;
            if (i > lek->count) return 0;
            lua_pushinteger(L, (lua_Integer)i);
            if (elemMetaName)
                pushObject<T>(L, &lek->stuff[i - 1], elemMetaName);
            else
                LuaCodec<T>::push(L, lek->stuff[i - 1], nullptr);
            return 2;
        }

        static int pairs(lua_State* L)
        {
            lua_pushcfunction(L, iterNext);
            lua_pushvalue(L, 1);
            lua_pushinteger(L, 0);
            return 3;
        }

        static int ipairs(lua_State* L) { return pairs(L); }

        static void registerBinding(lua_State* L, const char* name, const char* elemName)
        {
            metaName = name;
            elemMetaName = elemName;

            static const luaL_Reg meta[] = {
                { "__gc",       gc },
                { "__len",      len },
                { "__index",    index },
                { "__newindex", newindex },
                { "__pairs",    pairs },
                { "__ipairs",   ipairs },
                { 0, 0 }
            };
            static const luaL_Reg methods[] = {
                { "size",      size },
                { "toTable",   toTable },
                { 0, 0 }
            };
            registerClass(L, metaName, meta, methods, index, newindex);
        }
    };

    template <typename T>
    const char* LektorValueReadOnlyBinding<T>::metaName = nullptr;
    template <typename T>
    const char* LektorValueReadOnlyBinding<T>::elemMetaName = nullptr;


    // Binding for lektor<std::string>
    template <typename T>
    struct LektorStringBinding
    {
        static const char* metaName;

        static const char* getMetatableName() { return metaName; }

        static lektor<T>* get(lua_State* L, int idx)
        {
            return checkObject<lektor<T>>(L, idx, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int len(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            lua_pushinteger(L, lek ? lek->count : 0);
            return 1;
        }

        static int index(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) { lua_pushnil(L); return 1; }

            if (lua_isnumber(L, 2))
            {
                uint32_t i = (uint32_t)lua_tointeger(L, 2);
                if (i < 1 || i > lek->count) { lua_pushnil(L); return 1; }
                lua_pushstring(L, lek->stuff[i - 1].c_str());
                return 1;
            }

            luaL_getmetatable(L, metaName);
            lua_getfield(L, -1, luaL_checkstring(L, 2));
            return 1;
        }

        static int newindex(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) return luaL_error(L, "lektor is nil");

            if (!lua_isnumber(L, 2))
                return luaL_error(L, "lektor: only numeric indices are writable");

            uint32_t i = (uint32_t)lua_tointeger(L, 2);
            const char* val = luaL_checkstring(L, 3);

            if (i >= 1 && i <= lek->count)
            {
                lek->stuff[i - 1] = val;
                return 0;
            }
            if (i == lek->count + 1)
            {
                lektor_push_back(*lek, std::string(val));
                return 0;
            }
            return luaL_error(L, "lektor: index %u out of range (size=%u, can append at %u)",
                i, lek->count, lek->count + 1);
        }

        static int push(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) return luaL_error(L, "lektor is nil");
            const char* val = luaL_checkstring(L, 2);
            lektor_push_back(*lek, std::string(val));
            return 0;
        }

        static int removeAt(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) return luaL_error(L, "lektor is nil");
            uint32_t i = (uint32_t)luaL_checkinteger(L, 2);
            if (i < 1 || i > lek->count) return luaL_error(L, "lektor:removeAt index out of range");

            for (uint32_t j = i; j < lek->count; ++j)
                lek->stuff[j - 1] = lek->stuff[j];
            --lek->count;
            return 0;
        }

        static int clear(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (lek) lek->clear();
            return 0;
        }

        static int size(lua_State* L)
        {
            return len(L);
        }

        static int toTable(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) { lua_pushnil(L); return 1; }
            lua_createtable(L, (int)lek->count, 0);
            for (uint32_t i = 0; i < lek->count; ++i)
            {
                lua_pushstring(L, lek->stuff[i].c_str());
                lua_rawseti(L, -2, (int)(i + 1));
            }
            return 1;
        }

        static int pop(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) return luaL_error(L, "lektor is nil");
            if (lek->count == 0) return luaL_error(L, "lektor:pop container is empty");
            std::string val = lektor_pop_back_val(*lek);
            lua_pushstring(L, val.c_str());
            return 1;
        }

        static int iterNext(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) return 0;
            uint32_t i = (uint32_t)lua_tointeger(L, 2) + 1;
            if (i > lek->count) return 0;
            lua_pushinteger(L, (lua_Integer)i);
            lua_pushstring(L, lek->stuff[i - 1].c_str());
            return 2;
        }

        static int pairs(lua_State* L)
        {
            lua_pushcfunction(L, iterNext);
            lua_pushvalue(L, 1);
            lua_pushinteger(L, 0);
            return 3;
        }

        static int ipairs(lua_State* L) { return pairs(L); }

        static void registerBinding(lua_State* L, const char* name)
        {
            metaName = name;

            static const luaL_Reg meta[] = {
                { "__gc",       gc },
                { "__len",      len },
                { "__index",    index },
                { "__newindex", newindex },
                { "__pairs",    pairs },
                { "__ipairs",   ipairs },
                { 0, 0 }
            };
            static const luaL_Reg methods[] = {
                { "push",      push },
                { "pop",       pop },
                { "removeAt",  removeAt },
                { "clear",     clear },
                { "size",      size },
                { "toTable",   toTable },
                { 0, 0 }
            };
            registerClass(L, metaName, meta, methods, index, newindex);
        }
    };

    template <typename T>
    const char* LektorStringBinding<T>::metaName = nullptr;

    // Binding for lektor<int>
    template <typename T = int>
    struct LektorIntBinding
    {
        static const char* metaName;

        static const char* getMetatableName() { return metaName; }

        static lektor<T>* get(lua_State* L, int idx)
        {
            return checkObject<lektor<T>>(L, idx, metaName);
        }

        static int push(lua_State* L, lektor<T>* lek)
        {
            return pushObject<lektor<T>>(L, lek, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int len(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            lua_pushinteger(L, lek ? lek->count : 0);
            return 1;
        }

        static int index(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) { lua_pushnil(L); return 1; }

            if (lua_isnumber(L, 2))
            {
                uint32_t i = (uint32_t)lua_tointeger(L, 2);
                if (i < 1 || i > lek->count) { lua_pushnil(L); return 1; }
                lua_pushinteger(L, lek->stuff[i - 1]);
                return 1;
            }

            luaL_getmetatable(L, metaName);
            lua_getfield(L, -1, luaL_checkstring(L, 2));
            return 1;
        }

        static int newindex(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) return luaL_error(L, "lektor is nil");

            if (!lua_isnumber(L, 2))
                return luaL_error(L, "lektor: only numeric indices are writable");

            uint32_t i = (uint32_t)lua_tointeger(L, 2);
            int val = (int)luaL_checkinteger(L, 3);

            if (i >= 1 && i <= lek->count)
            {
                lek->stuff[i - 1] = val;
                return 0;
            }
            if (i == lek->count + 1)
            {
                lektor_push_back(*lek, val);
                return 0;
            }
            return luaL_error(L, "lektor: index %u out of range (size=%u, can append at %u)",
                i, lek->count, lek->count + 1);
        }

        static int pushVal(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) return luaL_error(L, "lektor is nil");
            int val = (int)luaL_checkinteger(L, 2);
            lektor_push_back(*lek, val);
            return 0;
        }

        static int removeAt(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) return luaL_error(L, "lektor is nil");
            uint32_t i = (uint32_t)luaL_checkinteger(L, 2);
            if (i < 1 || i > lek->count) return luaL_error(L, "lektor:removeAt index out of range");

            for (uint32_t j = i; j < lek->count; ++j)
                lek->stuff[j - 1] = lek->stuff[j];
            --lek->count;
            return 0;
        }

        static int clear(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (lek) lek->clear();
            return 0;
        }

        static int size(lua_State* L)
        {
            return len(L);
        }

        static int toTable(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) { lua_pushnil(L); return 1; }
            lua_createtable(L, (int)lek->count, 0);
            for (uint32_t i = 0; i < lek->count; ++i)
            {
                lua_pushinteger(L, lek->stuff[i]);
                lua_rawseti(L, -2, (int)(i + 1));
            }
            return 1;
        }

        static int pop(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) return luaL_error(L, "lektor is nil");
            if (lek->count == 0) return luaL_error(L, "lektor:pop container is empty");
            int val = lektor_pop_back_val(*lek);
            lua_pushinteger(L, val);
            return 1;
        }

        static int iterNext(lua_State* L)
        {
            lektor<T>* lek = get(L, 1);
            if (!lek) return 0;
            uint32_t i = (uint32_t)lua_tointeger(L, 2) + 1;
            if (i > lek->count) return 0;
            lua_pushinteger(L, (lua_Integer)i);
            lua_pushinteger(L, lek->stuff[i - 1]);
            return 2;
        }

        static int pairs(lua_State* L)
        {
            lua_pushcfunction(L, iterNext);
            lua_pushvalue(L, 1);
            lua_pushinteger(L, 0);
            return 3;
        }

        static int ipairs(lua_State* L) { return pairs(L); }

        static void registerBinding(lua_State* L, const char* name)
        {
            metaName = name;

            static const luaL_Reg meta[] = {
                { "__gc",       gc },
                { "__len",      len },
                { "__index",    index },
                { "__newindex", newindex },
                { "__pairs",    pairs },
                { "__ipairs",   ipairs },
                { 0, 0 }
            };
            static const luaL_Reg methods[] = {
                { "push",      pushVal },
                { "pop",       pop },
                { "removeAt",  removeAt },
                { "clear",     clear },
                { "size",      size },
                { "toTable",   toTable },
                { 0, 0 }
            };
            registerClass(L, metaName, meta, methods, index, newindex);
        }
    };

    template <typename T>
    const char* LektorIntBinding<T>::metaName = nullptr;
} // namespace KenshiLua