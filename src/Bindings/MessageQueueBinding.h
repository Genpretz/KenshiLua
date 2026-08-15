#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

#include "kenshi/navmesh.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
    template <typename T>
    class MessageQueueBinding
    {
    public:
        typedef MessageQueue<T> QueueType;

        static const char* metaName;

        static const char* getMetatableName() { return metaName; }

        static QueueType* get(lua_State* L, int idx)
        {
            return checkObject<QueueType>(L, idx, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int tostring(lua_State* L)
        {
            lua_pushstring(L, metaName ? metaName : "KenshiLua.MessageQueue object");
            return 1;
        }

        static int empty(lua_State* L)
        {
            QueueType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "MessageQueue is nil");
            lua_pushboolean(L, (instance->s == 0 || instance->root == nullptr) ? 1 : 0);
            return 1;
        }

        static int size(lua_State* L)
        {
            QueueType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "MessageQueue is nil");
            lua_pushinteger(L, instance->s);
            return 1;
        }

        static int get_s(lua_State* L)
        {
            QueueType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "MessageQueue is nil");
            lua_pushinteger(L, instance->s);
            return 1;
        }

        static int get_root(lua_State* L)
        {
            QueueType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "MessageQueue is nil");
            lua_pushlightuserdata(L, (void*)instance->root);
            return 1;
        }

        static int get_split(lua_State* L)
        {
            QueueType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "MessageQueue is nil");
            lua_pushlightuserdata(L, (void*)instance->split);
            return 1;
        }

        static int get_back(lua_State* L)
        {
            QueueType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "MessageQueue is nil");
            lua_pushlightuserdata(L, (void*)instance->back);
            return 1;
        }

        static int set_s(lua_State* L)
        {
            QueueType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "MessageQueue is nil");
            instance->s = (int)luaL_checkinteger(L, 2);
            return 0;
        }

        static int set_root(lua_State* L)
        {
            QueueType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "MessageQueue is nil");
            instance->root = (typename QueueType::Node*)lua_touserdata(L, 2);
            return 0;
        }

        static int set_split(lua_State* L)
        {
            QueueType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "MessageQueue is nil");
            instance->split = (typename QueueType::Node*)lua_touserdata(L, 2);
            return 0;
        }

        static int set_back(lua_State* L)
        {
            QueueType* instance = getInstance(L, 1);
            if (!instance) return luaL_error(L, "MessageQueue is nil");
            instance->back = (typename QueueType::Node*)lua_touserdata(L, 2);
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
                { "empty", empty },
                { "size",  size },
                { 0, 0 }
            };

            registerClass(L, metaName, meta, methods, genericPropertyIndex, genericPropertyNewIndex);

            luaL_getmetatable(L, metaName);
            lua_newtable(L);
            registerGetter(L, "s", get_s);
            registerGetter(L, "root", get_root);
            registerGetter(L, "split", get_split);
            registerGetter(L, "back", get_back);
            lua_setfield(L, -2, "__getters");

            lua_newtable(L);
            registerSetter(L, "s", set_s);
            registerSetter(L, "root", set_root);
            registerSetter(L, "split", set_split);
            registerSetter(L, "back", set_back);
            lua_setfield(L, -2, "__setters");

            lua_pop(L, 1);
        }

        static int push(lua_State* L, QueueType* ptr)
        {
            return pushObject<QueueType>(L, ptr, metaName);
        }
    };

    template <typename T> const char* MessageQueueBinding<T>::metaName = nullptr;
}