#pragma once
#include <kenshi/FitnessSelector.h>
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
    // Generic FitnessSelector Binding template
    template <typename T>
    struct FitnessSelectorBinding
    {
        typedef FitnessSelector<T> SelectorType;
        static const char* metaName;
        static const char* elemMetaName;

        typedef typename std::map<T, float, std::less<T>, Ogre::STLAllocator<std::pair<T const, float>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > ItemsScoresMapType;

        static SelectorType* get(lua_State* L, int idx)
        {
            return checkObject<SelectorType>(L, idx, metaName);
        }

        static int gc(lua_State* L)
        {
            void** ud = (void**)lua_touserdata(L, 1);
            if (ud && *ud)
            {
                delete (SelectorType*)*ud;
                *ud = nullptr;
            }
            return 0;
        }

        static int tostring(lua_State* L)
        {
            lua_pushfstring(L, "%s object", metaName);
            return 1;
        }

        static int reset(lua_State* L)
        {
            SelectorType* s = get(L, 1);
            if (s)
            {
                s->list.clear();
                s->itemsScores.clear();
                s->totalScore = 0.0f;
                s->highestScore = 0.0f;
                s->highestItem = T();
            }
            return 0;
        }

        static int size(lua_State* L)
        {
            SelectorType* s = get(L, 1);
            lua_pushinteger(L, s ? (lua_Integer)s->itemsScores.size() : 0);
            return 1;
        }

        static int empty(lua_State* L)
        {
            SelectorType* s = get(L, 1);
            lua_pushboolean(L, s ? (s->itemsScores.empty() ? 1 : 0) : 1);
            return 1;
        }

        static int hasItem(lua_State* L)
        {
            SelectorType* s = get(L, 1);
            if (!s) { lua_pushboolean(L, 0); return 1; }
            T item = checkObject<typename std::remove_pointer<T>::type>(L, 2, elemMetaName);
            lua_pushboolean(L, s->itemsScores.find(item) != s->itemsScores.end() ? 1 : 0);
            return 1;
        }

        static int getItemScore(lua_State* L)
        {
            SelectorType* s = get(L, 1);
            if (!s) { lua_pushnumber(L, 0); return 1; }
            T item = checkObject<typename std::remove_pointer<T>::type>(L, 2, elemMetaName);
            typename ItemsScoresMapType::const_iterator it = s->itemsScores.find(item);
            lua_pushnumber(L, it != s->itemsScores.end() ? it->second : 0.0f);
            return 1;
        }

        static int addItem(lua_State* L)
        {
            SelectorType* s = get(L, 1);
            if (!s) return 0;
            T item = checkObject<typename std::remove_pointer<T>::type>(L, 2, elemMetaName);
            float score = (float)luaL_checknumber(L, 3);
            s->itemsScores[item] = score;
            s->list.insert(std::make_pair(score, item));
            
            // Recalculate properties using classic C++03 iterators
            s->totalScore = 0.0f;
            s->highestScore = -1.0f;
            s->highestItem = T();
            for (typename ItemsScoresMapType::const_iterator it = s->itemsScores.begin(); it != s->itemsScores.end(); ++it)
            {
                s->totalScore += it->second;
                if (it->second > s->highestScore)
                {
                    s->highestScore = it->second;
                    s->highestItem = it->first;
                }
            }
            return 0;
        }

        static int chooseHighest(lua_State* L)
        {
            SelectorType* s = get(L, 1);
            if (!s || !s->highestItem) { lua_pushnil(L); return 1; }
            return pushObject<typename std::remove_pointer<T>::type>(L, s->highestItem, elemMetaName);
        }

        static int getItems(lua_State* L)
        {
            SelectorType* s = get(L, 1);
            if (!s) { lua_pushnil(L); return 1; }
            lua_newtable(L);
            for (typename ItemsScoresMapType::const_iterator it = s->itemsScores.begin(); it != s->itemsScores.end(); ++it)
            {
                pushObject<typename std::remove_pointer<T>::type>(L, it->first, elemMetaName);
                lua_pushnumber(L, it->second);
                lua_settable(L, -3);
            }
            return 1;
        }

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
            s->totalScore = (float)luaL_checknumber(L, 2);
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
            s->highestScore = (float)luaL_checknumber(L, 2);
            return 0;
        }

        static int get_highestItem(lua_State* L)
        {
            SelectorType* s = get(L, 1);
            if (!s) return luaL_error(L, "FitnessSelector is nil");
            LuaCodec<T>::push(L, s->highestItem, elemMetaName);
            return 1;
        }

        static int set_highestItem(lua_State* L)
        {
            SelectorType* s = get(L, 1);
            if (!s) return luaL_error(L, "FitnessSelector is nil");
            s->highestItem = LuaCodec<T>::read(L, 2, elemMetaName);
            return 0;
        }

        static int _CONSTRUCTOR(lua_State* L)
        {
            SelectorType* s = new SelectorType();
            s->totalScore = 0.0f;
            s->highestScore = 0.0f;
            s->highestItem = T();
            void** ud = (void**)lua_newuserdata(L, sizeof(void*));
            *ud = (void*)s;
            luaL_getmetatable(L, metaName);
            lua_setmetatable(L, -2);
            return 1;
        }

        static void registerBinding(lua_State* L, const char* name, const char* elemName)
        {
            metaName = name;
            elemMetaName = elemName;

            static const luaL_Reg meta[] = {
                { "__gc",       gc },
                { "__tostring", tostring },
                { 0, 0 }
            };
            static const luaL_Reg methods[] = {
                { "reset",         reset },
                { "size",          size },
                { "empty",         empty },
                { "hasItem",       hasItem },
                { "getItemScore",  getItemScore },
                { "addItem",       addItem },
                { "chooseHighest", chooseHighest },
                { "getItems",      getItems },
                { 0, 0 }
            };
            registerClass(L, metaName, meta, methods, genericPropertyIndex, genericPropertyNewIndex);

            // Create __getters and __setters tables to match generated binding layout
            luaL_getmetatable(L, metaName);
            
            lua_newtable(L); // Create __getters table
            lua_pushcfunction(L, get_totalScore);
            lua_setfield(L, -2, "totalScore");
            lua_pushcfunction(L, get_highestScore);
            lua_setfield(L, -2, "highestScore");
            lua_pushcfunction(L, get_highestItem);
            lua_setfield(L, -2, "highestItem");
            lua_setfield(L, -2, "__getters");

            lua_newtable(L); // Create __setters table
            lua_pushcfunction(L, set_totalScore);
            lua_setfield(L, -2, "totalScore");
            lua_pushcfunction(L, set_highestScore);
            lua_setfield(L, -2, "highestScore");
            lua_pushcfunction(L, set_highestItem);
            lua_setfield(L, -2, "highestItem");
            lua_setfield(L, -2, "__setters");

            lua_pop(L, 1); // Pop the metatable

            // Register global class table for construction
            lua_newtable(L);
            lua_pushcfunction(L, _CONSTRUCTOR);
            lua_setfield(L, -2, "new");
            
            std::string globalName = "FitnessSelector_";
            std::string elemBaseName = elemName;
            size_t dotPos = elemBaseName.find_last_of('.');
            if (dotPos != std::string::npos) {
                globalName += elemBaseName.substr(dotPos + 1);
            } else {
                globalName += elemBaseName;
            }
            lua_setglobal(L, globalName.c_str());
        }
    };

    template <typename T>
    const char* FitnessSelectorBinding<T>::metaName = nullptr;

    template <typename T>
    const char* FitnessSelectorBinding<T>::elemMetaName = nullptr;
}
