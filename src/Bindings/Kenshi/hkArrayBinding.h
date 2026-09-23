#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

#include "kenshi/Havok.h"
#include "Lua/BindingHelpers.h"
#include "hkArrayBaseBinding.h"

namespace KenshiLua
{
    template <typename T1, typename T2 = hkContainerHeapAllocator>
    class hkArrayBinding
    {
    public:
        typedef hkArray<T1, T2> ArrayType;

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
            lua_pushstring(L, metaName ? metaName : "KenshiLua.hkArray object");
            return 1;
        }

        static void registerBinding(lua_State* L, const char* name, const char* elementMeta = nullptr)
        {
            metaName = name;
            elemMetaName = elementMeta;

            static const luaL_Reg meta[] = {
                { "__gc",       gc },
                { "__tostring", tostring },
                { 0, 0 }
            };

            static const luaL_Reg methods[] = {
                { 0, 0 }
            };

            registerClass(L, metaName, meta, methods, genericPropertyIndex, genericPropertyNewIndex);
        }

        static int push(lua_State* L, ArrayType* ptr)
        {
            return pushObject<ArrayType>(L, ptr, metaName);
        }
    };

    template <typename T1, typename T2> const char* hkArrayBinding<T1, T2>::metaName = nullptr;
    template <typename T1, typename T2> const char* hkArrayBinding<T1, T2>::elemMetaName = nullptr;
}