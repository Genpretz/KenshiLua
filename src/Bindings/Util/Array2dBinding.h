#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

#include "kenshi/util/array2d.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
    template <typename T>
    class Array2dBinding
    {
    public:
        typedef Array2d<T> ArrayType;

        static const char* metaName;

        static const char* getMetatableName() { return metaName; }

        static ArrayType* get(lua_State* L, int idx)
        {
            return checkObject<ArrayType>(L, idx, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int tostring(lua_State* L)
        {
            lua_pushstring(L, metaName ? metaName : "KenshiLua.Array2d object");
            return 1;
        }

        static int get_nRows(lua_State* L)
        {
            ArrayType* instance = get(L, 1);
            if (!instance) return luaL_error(L, "Array2d is nil");
            lua_pushinteger(L, instance->nRows);
            return 1;
        }

        static int get_nCols(lua_State* L)
        {
            ArrayType* instance = get(L, 1);
            if (!instance) return luaL_error(L, "Array2d is nil");
            lua_pushinteger(L, instance->nCols);
            return 1;
        }

        static int set_nRows(lua_State* L)
        {
            ArrayType* instance = get(L, 1);
            if (!instance) return luaL_error(L, "Array2d is nil");
            instance->nRows = (unsigned int)luaL_checkinteger(L, 2);
            return 0;
        }

        static int set_nCols(lua_State* L)
        {
            ArrayType* instance = get(L, 1);
            if (!instance) return luaL_error(L, "Array2d is nil");
            instance->nCols = (unsigned int)luaL_checkinteger(L, 2);
            return 0;
        }

        static int resize(lua_State* L)
        {
            ArrayType* instance = get(L, 1);
            if (!instance) return luaL_error(L, "Array2d is nil");
            unsigned int nrows = (unsigned int)luaL_checkinteger(L, 2);
            unsigned int ncols = (unsigned int)luaL_checkinteger(L, 3);
            bool clear = lua_toboolean(L, 4) != 0;
            instance->resize(nrows, ncols, clear);
            return 0;
        }

        static int setToZeros(lua_State* L)
        {
            ArrayType* instance = get(L, 1);
            if (!instance) return luaL_error(L, "Array2d is nil");
            instance->setToZeros();
            return 0;
        }

        static void registerBinding(lua_State* L, const char* name)
        {
            metaName = name;

            static const luaL_Reg meta[] = {
                { "__gc",       gc },
                { "__tostring", tostring },
                { 0, 0 }
            };

            static const luaL_Reg methods[] = {
                { "resize", resize },
                { "setToZeros", setToZeros },
                { 0, 0 }
            };

            registerClass(L, metaName, meta, methods, genericPropertyIndex, genericPropertyNewIndex);

            luaL_getmetatable(L, metaName);
            lua_newtable(L);
            registerGetter(L, "nRows", get_nRows);
            registerGetter(L, "nCols", get_nCols);
            lua_setfield(L, -2, "__getters");

            lua_newtable(L);
            registerSetter(L, "nRows", set_nRows);
            registerSetter(L, "nCols", set_nCols);
            lua_setfield(L, -2, "__setters");

            lua_pop(L, 1);
        }

        static int push(lua_State* L, ArrayType* ptr)
        {
            return pushObject<ArrayType>(L, ptr, metaName);
        }
    };

    template <typename T> const char* Array2dBinding<T>::metaName = nullptr;
}