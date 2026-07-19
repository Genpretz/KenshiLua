#pragma once
#include "kenshi/FitnessSelector.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
    template <typename T>
    struct FitnessSelectorBinding
    {
        typedef FitnessSelector<T> SelectorType;
        static const char* metaName;
        static const char* elemMetaName;
        static const char* listMetaName;
        static const char* itemsScoresMetaName;

        static SelectorType* get(lua_State* L, int idx)
        {
            return checkObject<SelectorType>(L, idx, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int get_totalScore(lua_State* L)
        {
            SelectorType* s = get(L, 1);
            if (!s) return luaL_error(L, "FitnessSelector is nil");
            lua_pushnumber(L, s->totalScore);
            return 1;
        }

        static int set_totalScore(lua_State* L)
        {
            SelectorType* s = get(L, 1);
            if (!s) return luaL_error(L, "FitnessSelector is nil");
            s->totalScore = (float)lua_tonumber(L, 3);
            return 0;
        }

        static int get_highestScore(lua_State* L)
        {
            SelectorType* s = get(L, 1);
            if (!s) return luaL_error(L, "FitnessSelector is nil");
            lua_pushnumber(L, s->highestScore);
            return 1;
        }

        static int set_highestScore(lua_State* L)
        {
            SelectorType* s = get(L, 1);
            if (!s) return luaL_error(L, "FitnessSelector is nil");
            s->highestScore = (float)lua_tonumber(L, 3);
            return 0;
        }

        static int get_highestItem(lua_State* L)
        {
            SelectorType* s = get(L, 1);
            if (!s) return luaL_error(L, "FitnessSelector is nil");
            if (elemMetaName) return pushObject<T>(L, &s->highestItem, elemMetaName);
            LuaCodec<T>::push(L, s->highestItem, nullptr);
            return 1;
        }

        static int set_highestItem(lua_State* L)
        {
            SelectorType* s = get(L, 1);
            if (!s) return luaL_error(L, "FitnessSelector is nil");
            if (elemMetaName) {
                T* ptr = checkObject<T>(L, 3, elemMetaName);
                if (ptr) s->highestItem = *ptr;
            } else {
                s->highestItem = LuaCodec<T>::read(L, 3, nullptr);
            }
            return 0;
        }

        static int get_list(lua_State* L)
        {
            SelectorType* s = get(L, 1);
            if (!s) return luaL_error(L, "FitnessSelector is nil");
            if (listMetaName) return pushObject(L, &s->list, listMetaName);
            lua_pushnil(L);
            return 1;
        }

        static int get_itemsScores(lua_State* L)
        {
            SelectorType* s = get(L, 1);
            if (!s) return luaL_error(L, "FitnessSelector is nil");
            if (itemsScoresMetaName) return pushObject(L, &s->itemsScores, itemsScoresMetaName);
            lua_pushnil(L);
            return 1;
        }

        static void registerBinding(lua_State* L, const char* name, const char* elemMeta, const char* listMeta, const char* itemsScoresMeta)
        {
            metaName = name;
            elemMetaName = elemMeta;
            listMetaName = listMeta;
            itemsScoresMetaName = itemsScoresMeta;

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
    
    template<typename T> const char* FitnessSelectorBinding<T>::metaName = nullptr;
    template<typename T> const char* FitnessSelectorBinding<T>::elemMetaName = nullptr;
    template<typename T> const char* FitnessSelectorBinding<T>::listMetaName = nullptr;
    template<typename T> const char* FitnessSelectorBinding<T>::itemsScoresMetaName = nullptr;
}
