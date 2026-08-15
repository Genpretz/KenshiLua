#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

#include "kenshi/physicsactual.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Util/LektorBinding.h"

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
            ChainType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "MessageChain is nil");
            bool result = instance->flush();
            lua_pushboolean(L, result ? 1 : 0);
            return 1;
        }

        static int getMessageCountMT(lua_State* L)
        {
            ChainType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "MessageChain is nil");
            lua_pushinteger(L, static_cast<lua_Integer>(instance->mainThreadData.size()));
            return 1;
        }

        static int getMessages(lua_State* L)
        {
            ChainType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "MessageChain is nil");
            return LektorPtrBinding<T>::push(L, &instance->mainThreadData);
        }

        static int addMessage(lua_State* L)
        {
            ChainType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "MessageChain is nil");
            if (lua_isuserdata(L, 2))
            {
                void* raw = lua_touserdata(L, 2);
                if (raw)
                {
                    if (lua_islightuserdata(L, 2))
                    {
                        instance->mainThreadData.push_back((T)raw);
                    }
                    else
                    {
                        instance->mainThreadData.push_back((T)*((void**)raw));
                    }
                }
            }
            return 0;
        }

        static int get_mainThreadData(lua_State* L)
        {
            ChainType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "MessageChain is nil");
            return LektorPtrBinding<T>::push(L, &instance->mainThreadData);
        }

        static int set_mainThreadData(lua_State* L)
        {
            ChainType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "MessageChain is nil");
            auto* val = LektorPtrBinding<T>::get(L, 2);
            if (!val) return luaL_error(L, "Expected lektor container object");
            instance->mainThreadData = *val;
            return 0;
        }

        static int get_backThreadData(lua_State* L)
        {
            ChainType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "MessageChain is nil");
            return LektorPtrBinding<T>::push(L, &instance->backThreadData);
        }

        static int set_backThreadData(lua_State* L)
        {
            ChainType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "MessageChain is nil");
            auto* val = LektorPtrBinding<T>::get(L, 2);
            if (!val) return luaL_error(L, "Expected lektor container object");
            instance->backThreadData = *val;
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
                { "flush",             flush },
                { "getMessageCountMT", getMessageCountMT },
                { "getMessages",       getMessages },
                { "addMessage",        addMessage },
                { 0, 0 }
            };

            registerClass(L, metaName, meta, methods, genericPropertyIndex, genericPropertyNewIndex);

            luaL_getmetatable(L, metaName);
            lua_newtable(L);
            registerGetter(L, "mainThreadData", get_mainThreadData);
            registerGetter(L, "backThreadData", get_backThreadData);
            lua_setfield(L, -2, "__getters");

            lua_newtable(L);
            registerSetter(L, "mainThreadData", set_mainThreadData);
            registerSetter(L, "backThreadData", set_backThreadData);
            lua_setfield(L, -2, "__setters");

            lua_pop(L, 1);
        }

        static int push(lua_State* L, ChainType* ptr)
        {
            return pushObject<ChainType>(L, ptr, metaName);
        }
    };

    template <typename T> const char* MessageChainBinding<T>::metaName = nullptr;
}