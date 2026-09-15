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
        static const char* elemMetaName;

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

        /*
        // Missing exported funvtions in KenshiLib:
        static int resize(lua_State* L)
        {
            ArrayType* instance = get(L, 1);
            if (!instance) return luaL_error(L, "Array2d is nil");
            unsigned int nrows = (unsigned int)luaL_checkinteger(L, 2);
            unsigned int ncols = (unsigned int)luaL_checkinteger(L, 3);
            bool clear = lua_toboolean(L, 4) != 0;
            instance->resize(nrows, ncols, clear);
            typedef void (*ResizeFn)(void*, unsigned int, unsigned int, bool);
            static ResizeFn fn = (ResizeFn)((char*)GetModuleHandleA(NULL) + 0x5DF300);
            fn(instance, nrows, ncols, clear);
            return 0;
        }

        static int setToZeros(lua_State* L)
        {
            ArrayType* instance = get(L, 1);
            if (!instance) return luaL_error(L, "Array2d is nil");
            instance->setToZeros();
            typedef void (*SetZerosFn)(void*);
            static SetZerosFn fn = (SetZerosFn)((char*)GetModuleHandleA(NULL) + 0x5DA4E0);
            fn(instance);
            return 0;
        }

        static int getElement(lua_State* L)
        {
            ArrayType* instance = get(L, 1);
            if (!instance) return luaL_error(L, "Array2d is nil");
            int row = (int)luaL_checkinteger(L, 2);
            int col = (int)luaL_checkinteger(L, 3);
            if (row < 0 || (unsigned int)row >= instance->nRows || col < 0 || (unsigned int)col >= instance->nCols)
            {
                lua_pushnil(L);
                return 1;
            }
            T* val = (*instance)(row, col);
            if (!val)
            typedef T** (*OpFn)(void*, unsigned int, unsigned int);
            static OpFn fn = (OpFn)((char*)GetModuleHandleA(NULL) + 0x5D6000);
            T** pVal = fn(instance, (unsigned int)row, (unsigned int)col);
            if (!pVal || !*pVal)
            {
                lua_pushnil(L);
                return 1;
            }
            return pushObject<T>(L, val, elemMetaName);
            return pushObject<T>(L, *pVal, elemMetaName);
        }

        static int setElement(lua_State* L)
        {
            ArrayType* instance = get(L, 1);
            if (!instance) return luaL_error(L, "Array2d is nil");
            int row = (int)luaL_checkinteger(L, 2);
            int col = (int)luaL_checkinteger(L, 3);
            if (row < 0 || (unsigned int)row >= instance->nRows || col < 0 || (unsigned int)col >= instance->nCols)
            {
                return luaL_error(L, "Index out of bounds: (%d, %d)", row, col);
            }
            T* val = lua_isnoneornil(L, 4) ? nullptr : checkObject<T>(L, 4, elemMetaName);
            (*instance)(row, col) = val;
            typedef T** (*OpFn)(void*, unsigned int, unsigned int);
            static OpFn fn = (OpFn)((char*)GetModuleHandleA(NULL) + 0x5D6000);
            T** pVal = fn(instance, (unsigned int)row, (unsigned int)col);
            if (pVal)
            {
                *pVal = val;
            }
            return 0;
        }

        static int call(lua_State* L)
        {
            if (lua_gettop(L) >= 4)
                return setElement(L);
            return getElement(L);
        }
        */

        static void registerBinding(lua_State* L, const char* name, const char* elementMetatable = nullptr)
        {
            metaName = name;
            elemMetaName = elementMetatable;

            static const luaL_Reg meta[] = {
                { "__gc",       gc },
                { "__tostring", tostring },
                // { "__call",     call },
                { 0, 0 }
            };

            static const luaL_Reg methods[] = {
                // { "resize",     resize },
                // { "setToZeros", setToZeros },
                // { "get",        getElement },
                // { "set",        setElement },
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
    template <typename T> const char* Array2dBinding<T>::elemMetaName = nullptr;
}