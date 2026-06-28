// LektorBinding.h
#pragma once
#include <kenshi/util/lektor.h>
#include <kenshi/util/LektorPushBack.h>

namespace KenshiLua
{
    // One binding per element type T (T = pointer type, e.g. Character*)
    // Metatable name must be unique per instantiation, e.g. "lektor<Character*>"
    template <typename T, const char* MetaName(), const char* ElemMetaName()>
    struct LektorPtrBinding
    {
        static lektor<T>* get(lua_State* L, int idx)
        {
            return checkObject<lektor<T>>(L, idx, MetaName());
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
                    L, lek->stuff[i - 1], ElemMetaName());
            }

            // fall through to metatable methods (push, remove, etc.)
            luaL_getmetatable(L, MetaName());
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
            T val = checkObject<typename std::remove_pointer<T>::type>(L, 3, ElemMetaName());
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
            T val = checkObject<typename std::remove_pointer<T>::type>(L, 2, ElemMetaName());
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

        static void registerBinding(lua_State* L)
        {
            static const luaL_Reg meta[] = {
                { "__gc",       gc },
                { "__len",      len },
                { "__index",    index },
                { "__newindex", newindex },
                { 0, 0 }
            };
            static const luaL_Reg methods[] = {
                { "push",      push },
                { "removeAt",  removeAt },
                { "clear",     clear },
                { "size",      size },
                { 0, 0 }
            };
            registerClass(L, MetaName(), meta, methods, index, newindex);
        }
    };
} // namespace KenshiLua