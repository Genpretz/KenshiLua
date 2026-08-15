#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

#include "kenshi/Havok.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
    // hkArrayBase<T1> template container binding
    template <typename T1>
    class hkArrayBaseBinding
    {
    public:
        typedef hkArrayBase<T1> ArrayType;

        static const char* metaName;
        static const char* elemMetaName;

        static const char* getMetatableName() { return metaName; }

        static ArrayType* get(lua_State* L, int idx)
        {
            return checkObject<ArrayType>(L, idx, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int tostring(lua_State* L)
        {
            lua_pushstring(L, metaName ? metaName : "KenshiLua.hkArrayBase object");
            return 1;
        }

        static int getSize(lua_State* L)
        {
            ArrayType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "hkArrayBase is nil");
            lua_pushinteger(L, instance->getSize());
            return 1;
        }

        static int getCapacity(lua_State* L)
        {
            ArrayType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "hkArrayBase is nil");
            lua_pushinteger(L, instance->getCapacity());
            return 1;
        }

        static int clear(lua_State* L)
        {
            ArrayType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "hkArrayBase is nil");
            instance->clear();
            return 0;
        }

        static int isEmpty(lua_State* L)
        {
            ArrayType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "hkArrayBase is nil");
            lua_pushboolean(L, instance->isEmpty() ? 1 : 0);
            return 1;
        }

        // --- Getters ---
        static int get_m_data(lua_State* L)
        {
            ArrayType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "hkArrayBase is nil");
            lua_pushlightuserdata(L, (void*)instance->m_data);
            return 1;
        }

        static int get_m_size(lua_State* L)
        {
            ArrayType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "hkArrayBase is nil");
            lua_pushinteger(L, instance->m_size);
            return 1;
        }

        static int get_m_capacityAndFlags(lua_State* L)
        {
            ArrayType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "hkArrayBase is nil");
            lua_pushinteger(L, instance->m_capacityAndFlags);
            return 1;
        }

        // --- Setters ---
        static int set_m_size(lua_State* L)
        {
            ArrayType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "hkArrayBase is nil");
            instance->m_size = (int)luaL_checkinteger(L, 2);
            return 0;
        }

        static int set_m_capacityAndFlags(lua_State* L)
        {
            ArrayType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "hkArrayBase is nil");
            instance->m_capacityAndFlags = (int)luaL_checkinteger(L, 2);
            return 0;
        }

        // --- Index & Len ---
        static int index(lua_State* L)
        {
            ArrayType* arr = getInstance(L, 1);
            if (!arr) { lua_pushnil(L); return 1; }

            if (lua_isstring(L, 2))
            {
                luaL_getmetatable(L, metaName);
                lua_getfield(L, -1, lua_tostring(L, 2));
                if (!lua_isnil(L, -1)) return 1;
                lua_pop(L, 2);
            }

            if (lua_isnumber(L, 2))
            {
                int idx = (int)lua_tointeger(L, 2) - 1;
                if (idx < 0 || idx >= arr->getSize())
                {
                    lua_pushnil(L);
                    return 1;
                }
                if (elemMetaName)
                {
                    return pushObject<T1>(L, &(*arr)[idx], elemMetaName);
                }
                else
                {
                    LuaCodec<T1>::push(L, (*arr)[idx], nullptr);
                    return 1;
                }
            }

            lua_pushnil(L);
            return 1;
        }

        static int len(lua_State* L)
        {
            ArrayType* arr = getInstance(L, 1);
            lua_pushinteger(L, arr ? arr->getSize() : 0);
            return 1;
        }

        static void registerBinding(lua_State* L, const char* name, const char* elementMeta = nullptr)
        {
            metaName = name;
            elemMetaName = elementMeta;

            static const luaL_Reg meta[] = {
                { "__gc",       gc },
                { "__tostring", tostring },
                { "__index",    index },
                { "__len",      len },
                { 0, 0 }
            };

            static const luaL_Reg methods[] = {
                { "getSize",     getSize },
                { "getCapacity", getCapacity },
                { "clear",       clear },
                { "isEmpty",     isEmpty },
                { 0, 0 }
            };

            registerClass(L, metaName, meta, methods, genericPropertyIndex, genericPropertyNewIndex);

            luaL_getmetatable(L, metaName);

            lua_newtable(L); // __getters
            registerGetter(L, "m_data", get_m_data);
            registerGetter(L, "m_size", get_m_size);
            registerGetter(L, "m_capacityAndFlags", get_m_capacityAndFlags);
            lua_setfield(L, -2, "__getters");

            lua_newtable(L); // __setters
            registerSetter(L, "m_size", set_m_size);
            registerSetter(L, "m_capacityAndFlags", set_m_capacityAndFlags);
            lua_setfield(L, -2, "__setters");

            lua_pop(L, 1);
        }

        static int push(lua_State* L, ArrayType* ptr)
        {
            return pushObject<ArrayType>(L, ptr, metaName);
        }
    };

    template <typename T1> const char* hkArrayBaseBinding<T1>::metaName = nullptr;
    template <typename T1> const char* hkArrayBaseBinding<T1>::elemMetaName = nullptr;
}