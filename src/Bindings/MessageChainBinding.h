#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

#include "kenshi/physicsactual.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
    template <typename T>
    class MessageChainBinding
    {
    public:
        typedef MessageChain<T> ChainType;

        static const char* metaName;

        static const char* getMetatableName() { return metaName; }

        static ChainType* get(lua_State* L, int idx)
        {
            return checkObject<ChainType>(L, idx, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int tostring(lua_State* L)
        {
            lua_pushstring(L, metaName ? metaName : "KenshiLua.MessageChain object");
            return 1;
        }

        static int flush(lua_State* L)
        {
            ChainType* instance = get(L, 1);
            if (!instance) return luaL_error(L, "MessageChain is nil");
            bool result = instance->flush();
            lua_pushboolean(L, result ? 1 : 0);
            return 1;
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
                { "flush", flush },
                { 0, 0 }
            };

            registerClass(L, metaName, meta, methods, genericPropertyIndex, genericPropertyNewIndex);
        }

        static int push(lua_State* L, ChainType* ptr)
        {
            return pushObject<ChainType>(L, ptr, metaName);
        }
    };

    template <typename T> const char* MessageChainBinding<T>::metaName = nullptr;
}