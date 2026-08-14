#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

#include "kenshi/util/TagsClass.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
    template <typename T>
    class TagsClassBinding
    {
    public:
        typedef TagsClass<T> TagsType;

        static const char* metaName;

        static const char* getMetatableName() { return metaName; }

        static TagsType* get(lua_State* L, int idx)
        {
            return checkObject<TagsType>(L, idx, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int tostring(lua_State* L)
        {
            lua_pushstring(L, metaName ? metaName : "KenshiLua.TagsClass object");
            return 1;
        }

        static int get_flags(lua_State* L)
        {
            TagsType* instance = get(L, 1);
            if (!instance) return luaL_error(L, "TagsClass is nil");
            lua_pushinteger(L, instance->flags);
            return 1;
        }

        static int set_flags(lua_State* L)
        {
            TagsType* instance = get(L, 1);
            if (!instance) return luaL_error(L, "TagsClass is nil");
            instance->flags = (unsigned int)luaL_checkinteger(L, 2);
            return 0;
        }

        static int clearAll(lua_State* L)
        {
            TagsType* instance = get(L, 1);
            if (!instance) return luaL_error(L, "TagsClass is nil");
            instance->clearAll();
            return 0;
        }

        static int hasNONEOfTheseBitsSet(lua_State* L)
        {
            TagsType* instance = get(L, 1);
            if (!instance) return luaL_error(L, "TagsClass is nil");
            unsigned int flagsToTest = (unsigned int)luaL_checkinteger(L, 2);
            lua_pushboolean(L, instance->hasNONEOfTheseBitsSet(flagsToTest) ? 1 : 0);
            return 1;
        }

        static int hasANYOfTheseBitsSet(lua_State* L)
        {
            TagsType* instance = get(L, 1);
            if (!instance) return luaL_error(L, "TagsClass is nil");
            unsigned int flagsToTest = (unsigned int)luaL_checkinteger(L, 2);
            lua_pushboolean(L, instance->hasANYOfTheseBitsSet(flagsToTest) ? 1 : 0);
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
                { "clearAll", clearAll },
                { "hasNONEOfTheseBitsSet", hasNONEOfTheseBitsSet },
                { "hasANYOfTheseBitsSet", hasANYOfTheseBitsSet },
                { 0, 0 }
            };

            registerClass(L, metaName, meta, methods, genericPropertyIndex, genericPropertyNewIndex);

            luaL_getmetatable(L, metaName);
            lua_newtable(L);
            registerGetter(L, "flags", get_flags);
            lua_setfield(L, -2, "__getters");

            lua_newtable(L);
            registerSetter(L, "flags", set_flags);
            lua_setfield(L, -2, "__setters");

            lua_pop(L, 1);
        }

        static int push(lua_State* L, TagsType* ptr)
        {
            return pushObject<TagsType>(L, ptr, metaName);
        }
    };

    template <typename T> const char* TagsClassBinding<T>::metaName = nullptr;
}