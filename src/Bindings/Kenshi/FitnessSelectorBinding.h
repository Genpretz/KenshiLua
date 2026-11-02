#pragma once
#include "Lua/ContainerBinding.h"
#include "Lua/LuaCodec.h"
#include "kenshi/FitnessSelector.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
    template <typename T>
    struct FitnessSelectorBinding
    {
        typedef FitnessSelector<T> SelectorType;
        typedef SelectorType ContainerType;
        typedef FitnessSelectorBinding<T> MetadataType;
        static const char* const metaName;
        static const char* const metadata[3];

        static SelectorType* getInstance(lua_State* L, int idx)
        {
            return checkObject<SelectorType>(L, idx, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int get_totalScore(lua_State* L)
        {
            SelectorType* s = getInstance(L, 1);
            if (!s) return luaL_error(L, "FitnessSelector is nil");
            lua_pushnumber(L, s->totalScore);
            return 1;
        }

        static int set_totalScore(lua_State* L)
        {
            SelectorType* s = getInstance(L, 1);
            if (!s) return luaL_error(L, "FitnessSelector is nil");
            s->totalScore = (float)lua_tonumber(L, 3);
            return 0;
        }

        static int get_highestScore(lua_State* L)
        {
            SelectorType* s = getInstance(L, 1);
            if (!s) return luaL_error(L, "FitnessSelector is nil");
            lua_pushnumber(L, s->highestScore);
            return 1;
        }

        static int set_highestScore(lua_State* L)
        {
            SelectorType* s = getInstance(L, 1);
            if (!s) return luaL_error(L, "FitnessSelector is nil");
            s->highestScore = (float)lua_tonumber(L, 3);
            return 0;
        }

        static int get_highestItem(lua_State* L)
        {
            SelectorType* s = getInstance(L, 1);
            if (!s) return luaL_error(L, "FitnessSelector is nil");
            if (metadata[0]) return pushObject<T>(L, &s->highestItem, metadata[0]);
            LuaCodec<T>::push(L, s->highestItem, nullptr);
            return 1;
        }

        static int set_highestItem(lua_State* L)
        {
            SelectorType* s = getInstance(L, 1);
            if (!s) return luaL_error(L, "FitnessSelector is nil");
            if (metadata[0]) {
                T* ptr = checkObject<T>(L, 3, metadata[0]);
                if (ptr) s->highestItem = *ptr;
            } else {
                s->highestItem = LuaCodec<T>::read(L, 3, nullptr);
            }
            return 0;
        }

        static int get_list(lua_State* L)
        {
            SelectorType* s = getInstance(L, 1);
            if (!s) return luaL_error(L, "FitnessSelector is nil");
            if (metadata[1]) return pushObject(L, &s->list, metadata[1]);
            lua_pushnil(L);
            return 1;
        }

        static int get_itemsScores(lua_State* L)
        {
            SelectorType* s = getInstance(L, 1);
            if (!s) return luaL_error(L, "FitnessSelector is nil");
            if (metadata[2]) return pushObject(L, &s->itemsScores, metadata[2]);
            lua_pushnil(L);
            return 1;
        }

        static void registerBinding(lua_State* L)
        {
            if (!beginContainerBinding(L, containerBindingDefinition<MetadataType>())) return;

            static const luaL_Reg meta[] = {
                { "__gc", gc },
                { 0, 0 }
            };

            static const luaL_Reg methods[] = {
                { 0, 0 }
            };

            registerClass(
                L, 
                metaName, 
                meta, 
                methods, 
                genericPropertyIndex, 
                genericPropertyNewIndex
            );

            luaL_getmetatable(L, metaName);
            
            lua_newtable(L);
            lua_pushcfunction(L, get_totalScore);
            lua_setfield(L, -2, "totalScore");
            lua_pushcfunction(L, get_highestScore);
            lua_setfield(L, -2, "highestScore");
            lua_pushcfunction(L, get_highestItem);
            lua_setfield(L, -2, "highestItem");
            lua_pushcfunction(L, get_list);
            lua_setfield(L, -2, "list");
            lua_pushcfunction(L, get_itemsScores);
            lua_setfield(L, -2, "itemsScores");
            lua_setfield(L, -2, "__getters");

            lua_newtable(L);
            lua_pushcfunction(L, set_totalScore);
            lua_setfield(L, -2, "totalScore");
            lua_pushcfunction(L, set_highestScore);
            lua_setfield(L, -2, "highestScore");
            lua_pushcfunction(L, set_highestItem);
            lua_setfield(L, -2, "highestItem");
            // list and itemsScores are read-only structurally (we modify via map methods)
            lua_setfield(L, -2, "__setters");

            lua_pop(L, 1);
        }
    };
    
}