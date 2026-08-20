#pragma once
#include <ogre/OgreFastArray.h>
#include <type_traits>
#include "Lua/BindingHelpers.h"
#include "Lua/LuaCodec.h"

namespace KenshiLua
{
    // For fast arrays with pointers as elements
    template <typename T>
    struct OgreFastArrayPtrBinding
    {
        typedef typename std::remove_pointer<T>::type BaseType;
        typedef Ogre::FastArray<T> ArrayType;
        static const char* metaName;
        static const char* elemMetaName;

        static const char* getMetatableName() { return metaName; }

        static ArrayType* get(lua_State* L, int idx)
        {
            return checkObject<ArrayType>(L, idx, metaName);
        }

        static int push(lua_State* L, ArrayType* arr)
        {
            return pushObject<ArrayType>(L, arr, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int len(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            lua_pushinteger(L, arr ? (lua_Integer)arr->size() : 0);
            return 1;
        }

        static int size(lua_State* L) { return len(L); }

        static int empty(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            lua_pushboolean(L, (!arr || arr->empty()) ? 1 : 0);
            return 1;
        }

        static int reserve(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr) return luaL_error(L, "FastArray is nil");
            size_t amount = (size_t)luaL_checkinteger(L, 2);
            arr->reserve(amount);
            return 0;
        }

        static int front(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr || arr->empty()) { lua_pushnil(L); return 1; }
            T val = arr->front();
            if (!val) { lua_pushnil(L); return 1; }
            if (elemMetaName)
                return pushObject<BaseType>(L, val, elemMetaName);
            else
            {
                lua_pushlightuserdata(L, (void*)val);
                return 1;
            }
        }

        static int back(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr || arr->empty()) { lua_pushnil(L); return 1; }
            T val = arr->back();
            if (!val) { lua_pushnil(L); return 1; }
            if (elemMetaName)
                return pushObject<BaseType>(L, val, elemMetaName);
            else
            {
                lua_pushlightuserdata(L, (void*)val);
                return 1;
            }
        }

        static int index(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr) { lua_pushnil(L); return 1; }

            if (lua_isnumber(L, 2))
            {
                size_t i = (size_t)lua_tointeger(L, 2);
                if (i < 1 || i > arr->size()) { lua_pushnil(L); return 1; }
                T val = (*arr)[i - 1];
                if (!val) { lua_pushnil(L); return 1; }
                if (elemMetaName)
                    return pushObject<BaseType>(L, val, elemMetaName);
                else
                {
                    lua_pushlightuserdata(L, (void*)val);
                    return 1;
                }
            }

            luaL_getmetatable(L, metaName);
            lua_getfield(L, -1, luaL_checkstring(L, 2));
            return 1;
        }

        static int newindex(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr) return luaL_error(L, "FastArray is nil");
            if (!lua_isnumber(L, 2)) return luaL_error(L, "FastArray: index must be numeric");

            size_t i = (size_t)lua_tointeger(L, 2);
            T val = nullptr;
            if (!lua_isnoneornil(L, 3))
            {
                if (elemMetaName)
                    val = checkObject<BaseType>(L, 3, elemMetaName);
                else if (lua_islightuserdata(L, 3))
                    val = (T)lua_touserdata(L, 3);
                else
                    return luaL_error(L, "FastArray: expected valid object or lightuserdata for assignment");
            }

            if (i >= 1 && i <= arr->size())
            {
                if (lua_isnil(L, 3))
                    arr->erase(arr->begin() + (i - 1));
                else
                    (*arr)[i - 1] = val;
                return 0;
            }
            if (i == arr->size() + 1)
            {
                if (!lua_isnil(L, 3))
                    arr->push_back(val);
                return 0;
            }
            return luaL_error(L, "FastArray: index %u out of range (size=%u)", (unsigned int)i, (unsigned int)arr->size());
        }

        static int push_back(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr) return luaL_error(L, "FastArray is nil");
            T val = nullptr;
            if (!lua_isnoneornil(L, 2))
            {
                if (elemMetaName)
                    val = checkObject<BaseType>(L, 2, elemMetaName);
                else if (lua_islightuserdata(L, 2))
                    val = (T)lua_touserdata(L, 2);
            }
            arr->push_back(val);
            return 0;
        }

        static int pop_back(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr) return luaL_error(L, "FastArray is nil");
            if (arr->empty()) return luaL_error(L, "FastArray: pop called on empty container");
            T val = arr->back();
            arr->pop_back();
            if (!val) { lua_pushnil(L); return 1; }
            if (elemMetaName)
                return pushObject<BaseType>(L, val, elemMetaName);
            else
            {
                lua_pushlightuserdata(L, (void*)val);
                return 1;
            }
        }

        static int removeAt(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr) return luaL_error(L, "FastArray is nil");
            size_t i = (size_t)luaL_checkinteger(L, 2);
            if (i < 1 || i > arr->size()) return luaL_error(L, "FastArray: removeAt index out of range");
            arr->erase(arr->begin() + (i - 1));
            return 0;
        }

        static int clear(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (arr) arr->clear();
            return 0;
        }

        static int toTable(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr) { lua_pushnil(L); return 1; }
            lua_createtable(L, (int)arr->size(), 0);
            for (size_t i = 0; i < arr->size(); ++i)
            {
                T val = (*arr)[i];
                if (val)
                {
                    if (elemMetaName)
                        pushObject<BaseType>(L, val, elemMetaName);
                    else
                        lua_pushlightuserdata(L, (void*)val);
                }
                else
                    lua_pushnil(L);
                lua_rawseti(L, -2, (int)(i + 1));
            }
            return 1;
        }

        static int iterNext(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr) return 0;
            size_t i = (size_t)lua_tointeger(L, 2) + 1;
            if (i > arr->size()) return 0;
            lua_pushinteger(L, (lua_Integer)i);
            T val = (*arr)[i - 1];
            if (val)
            {
                if (elemMetaName)
                    pushObject<BaseType>(L, val, elemMetaName);
                else
                    lua_pushlightuserdata(L, (void*)val);
            }
            else
                lua_pushnil(L);
            return 2;
        }

        static int pairs(lua_State* L)
        {
            lua_pushcfunction(L, iterNext);
            lua_pushvalue(L, 1);
            lua_pushinteger(L, 0);
            return 3;
        }

        static int ipairs(lua_State* L) { return pairs(L); }

        static void registerBinding(lua_State* L, const char* name, const char* elemName = nullptr)
        {
            metaName = name;
            elemMetaName = elemName;

            static const luaL_Reg meta[] = {
                { "__gc",       gc },
                { "__len",      len },
                { "__index",    index },
                { "__newindex", newindex },
                { "__pairs",    pairs },
                { "__ipairs",   ipairs },
                { 0, 0 }
            };
            static const luaL_Reg methods[] = {
                { "push_back", push_back },
                { "push",      push_back },
                { "pop_back",  pop_back },
                { "pop",       pop_back },
                { "front",     front },
                { "back",      back },
                { "removeAt",  removeAt },
                { "clear",     clear },
                { "empty",     empty },
                { "reserve",   reserve },
                { "size",      size },
                { "toTable",   toTable },
                { 0, 0 }
            };
            registerClass(L, metaName, meta, methods, index, newindex);
        }
    };

    template <typename T>
    const char* OgreFastArrayPtrBinding<T>::metaName = nullptr;
    template <typename T>
    const char* OgreFastArrayPtrBinding<T>::elemMetaName = nullptr;


    // For fast arrays with values as elements
    template <typename T>
    struct OgreFastArrayValueBinding
    {
        typedef Ogre::FastArray<T> ArrayType;
        static const char* metaName;
        static const char* elemMetaName;

        static const char* getMetatableName() { return metaName; }

        static ArrayType* get(lua_State* L, int idx)
        {
            return checkObject<ArrayType>(L, idx, metaName);
        }

        static int push(lua_State* L, ArrayType* arr)
        {
            return pushObject<ArrayType>(L, arr, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int len(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            lua_pushinteger(L, arr ? (lua_Integer)arr->size() : 0);
            return 1;
        }

        static int size(lua_State* L) { return len(L); }

        static int empty(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            lua_pushboolean(L, (!arr || arr->empty()) ? 1 : 0);
            return 1;
        }

        static int reserve(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr) return luaL_error(L, "FastArray is nil");
            size_t amount = (size_t)luaL_checkinteger(L, 2);
            arr->reserve(amount);
            return 0;
        }

        static int front(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr || arr->empty()) { lua_pushnil(L); return 1; }
            if (elemMetaName)
                return pushObject<T>(L, &arr->front(), elemMetaName);
            else
            {
                LuaCodec<T>::push(L, arr->front(), nullptr);
                return 1;
            }
        }

        static int back(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr || arr->empty()) { lua_pushnil(L); return 1; }
            if (elemMetaName)
                return pushObject<T>(L, &arr->back(), elemMetaName);
            else
            {
                LuaCodec<T>::push(L, arr->back(), nullptr);
                return 1;
            }
        }

        static int index(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr) { lua_pushnil(L); return 1; }

            if (lua_isnumber(L, 2))
            {
                size_t i = (size_t)lua_tointeger(L, 2);
                if (i < 1 || i > arr->size()) { lua_pushnil(L); return 1; }
                if (elemMetaName)
                    return pushObject<T>(L, &(*arr)[i - 1], elemMetaName);
                else
                {
                    LuaCodec<T>::push(L, (*arr)[i - 1], nullptr);
                    return 1;
                }
            }

            luaL_getmetatable(L, metaName);
            lua_getfield(L, -1, luaL_checkstring(L, 2));
            return 1;
        }

        static int newindex(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr) return luaL_error(L, "FastArray is nil");
            if (!lua_isnumber(L, 2)) return luaL_error(L, "FastArray: index must be numeric");

            size_t i = (size_t)lua_tointeger(L, 2);

            if (i >= 1 && i <= arr->size())
            {
                if (lua_isnil(L, 3))
                    arr->erase(arr->begin() + (i - 1));
                else
                {
                    if (elemMetaName)
                    {
                        T* ptr = checkObject<T>(L, 3, elemMetaName);
                        if (!ptr) return luaL_error(L, "FastArray: expected valid object for assignment");
                        (*arr)[i - 1] = *ptr;
                    }
                    else
                    {
                        (*arr)[i - 1] = LuaCodec<T>::read(L, 3, nullptr);
                    }
                }
                return 0;
            }
            if (i == arr->size() + 1)
            {
                if (!lua_isnil(L, 3))
                {
                    if (elemMetaName)
                    {
                        T* ptr = checkObject<T>(L, 3, elemMetaName);
                        if (!ptr) return luaL_error(L, "FastArray: expected valid object for assignment");
                        arr->push_back(*ptr);
                    }
                    else
                    {
                        arr->push_back(LuaCodec<T>::read(L, 3, nullptr));
                    }
                }
                return 0;
            }
            return luaL_error(L, "FastArray: index %u out of range (size=%u)", (unsigned int)i, (unsigned int)arr->size());
        }

        static int push_back(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr) return luaL_error(L, "FastArray is nil");
            if (elemMetaName)
            {
                T* ptr = checkObject<T>(L, 2, elemMetaName);
                if (!ptr) return luaL_error(L, "FastArray: expected valid object for push");
                arr->push_back(*ptr);
            }
            else
            {
                arr->push_back(LuaCodec<T>::read(L, 2, nullptr));
            }
            return 0;
        }

        static int pop_back(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr) return luaL_error(L, "FastArray is nil");
            if (arr->empty()) return luaL_error(L, "FastArray: pop called on empty container");
            T val = arr->back();
            arr->pop_back();
            if (elemMetaName)
                return pushValue<T>(L, val, elemMetaName);
            else
            {
                LuaCodec<T>::push(L, val, nullptr);
                return 1;
            }
        }

        static int removeAt(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr) return luaL_error(L, "FastArray is nil");
            size_t i = (size_t)luaL_checkinteger(L, 2);
            if (i < 1 || i > arr->size()) return luaL_error(L, "FastArray: removeAt index out of range");
            arr->erase(arr->begin() + (i - 1));
            return 0;
        }

        static int clear(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (arr) arr->clear();
            return 0;
        }

        static int toTable(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr) { lua_pushnil(L); return 1; }
            lua_createtable(L, (int)arr->size(), 0);
            for (size_t i = 0; i < arr->size(); ++i)
            {
                if (elemMetaName)
                    pushObject<T>(L, &(*arr)[i], elemMetaName);
                else
                    LuaCodec<T>::push(L, (*arr)[i], nullptr);
                lua_rawseti(L, -2, (int)(i + 1));
            }
            return 1;
        }

        static int iterNext(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr) return 0;
            size_t i = (size_t)lua_tointeger(L, 2) + 1;
            if (i > arr->size()) return 0;
            lua_pushinteger(L, (lua_Integer)i);
            if (elemMetaName)
                pushObject<T>(L, &(*arr)[i - 1], elemMetaName);
            else
                LuaCodec<T>::push(L, (*arr)[i - 1], nullptr);
            return 2;
        }

        static int pairs(lua_State* L)
        {
            lua_pushcfunction(L, iterNext);
            lua_pushvalue(L, 1);
            lua_pushinteger(L, 0);
            return 3;
        }

        static int ipairs(lua_State* L) { return pairs(L); }

        static void registerBinding(lua_State* L, const char* name, const char* elemName = nullptr)
        {
            metaName = name;
            elemMetaName = elemName;

            static const luaL_Reg meta[] = {
                { "__gc",       gc },
                { "__len",      len },
                { "__index",    index },
                { "__newindex", newindex },
                { "__pairs",    pairs },
                { "__ipairs",   ipairs },
                { 0, 0 }
            };
            static const luaL_Reg methods[] = {
                { "push_back", push_back },
                { "push",      push_back },
                { "pop_back",  pop_back },
                { "pop",       pop_back },
                { "front",     front },
                { "back",      back },
                { "removeAt",  removeAt },
                { "clear",     clear },
                { "empty",     empty },
                { "reserve",   reserve },
                { "size",      size },
                { "toTable",   toTable },
                { 0, 0 }
            };
            registerClass(L, metaName, meta, methods, index, newindex);
        }
    };

    template <typename T>
    const char* OgreFastArrayValueBinding<T>::metaName = nullptr;
    template <typename T>
    const char* OgreFastArrayValueBinding<T>::elemMetaName = nullptr;


    // For fast arrays with scalar/primitive, hand, string types as elements
    template <typename T>
    struct OgreFastArrayPrimitiveBinding
    {
        typedef Ogre::FastArray<T> ArrayType;
        static const char* metaName;

        static const char* getMetatableName() { return metaName; }

        static ArrayType* get(lua_State* L, int idx)
        {
            return checkObject<ArrayType>(L, idx, metaName);
        }

        static int push(lua_State* L, ArrayType* arr)
        {
            return pushObject<ArrayType>(L, arr, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int len(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            lua_pushinteger(L, arr ? (lua_Integer)arr->size() : 0);
            return 1;
        }

        static int size(lua_State* L) { return len(L); }

        static int empty(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            lua_pushboolean(L, (!arr || arr->empty()) ? 1 : 0);
            return 1;
        }

        static int reserve(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr) return luaL_error(L, "FastArray is nil");
            size_t amount = (size_t)luaL_checkinteger(L, 2);
            arr->reserve(amount);
            return 0;
        }

        static int front(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr || arr->empty()) { lua_pushnil(L); return 1; }
            LuaCodec<T>::push(L, arr->front(), nullptr);
            return 1;
        }

        static int back(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr || arr->empty()) { lua_pushnil(L); return 1; }
            LuaCodec<T>::push(L, arr->back(), nullptr);
            return 1;
        }

        static int index(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr) { lua_pushnil(L); return 1; }

            if (lua_isnumber(L, 2))
            {
                size_t i = (size_t)lua_tointeger(L, 2);
                if (i < 1 || i > arr->size()) { lua_pushnil(L); return 1; }
                LuaCodec<T>::push(L, (*arr)[i - 1], nullptr);
                return 1;
            }

            luaL_getmetatable(L, metaName);
            lua_getfield(L, -1, luaL_checkstring(L, 2));
            return 1;
        }

        static int newindex(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr) return luaL_error(L, "FastArray is nil");
            if (!lua_isnumber(L, 2)) return luaL_error(L, "FastArray: index must be numeric");

            size_t i = (size_t)lua_tointeger(L, 2);

            if (i >= 1 && i <= arr->size())
            {
                if (lua_isnil(L, 3))
                    arr->erase(arr->begin() + (i - 1));
                else
                    (*arr)[i - 1] = LuaCodec<T>::read(L, 3, nullptr);
                return 0;
            }
            if (i == arr->size() + 1)
            {
                if (!lua_isnil(L, 3))
                    arr->push_back(LuaCodec<T>::read(L, 3, nullptr));
                return 0;
            }
            return luaL_error(L, "FastArray: index %u out of range (size=%u)", (unsigned int)i, (unsigned int)arr->size());
        }

        static int push_back(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr) return luaL_error(L, "FastArray is nil");
            arr->push_back(LuaCodec<T>::read(L, 2, nullptr));
            return 0;
        }

        static int pop_back(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr) return luaL_error(L, "FastArray is nil");
            if (arr->empty()) return luaL_error(L, "FastArray: pop called on empty container");
            T val = arr->back();
            arr->pop_back();
            LuaCodec<T>::push(L, val, nullptr);
            return 1;
        }

        static int removeAt(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr) return luaL_error(L, "FastArray is nil");
            size_t i = (size_t)luaL_checkinteger(L, 2);
            if (i < 1 || i > arr->size()) return luaL_error(L, "FastArray: removeAt index out of range");
            arr->erase(arr->begin() + (i - 1));
            return 0;
        }

        static int clear(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (arr) arr->clear();
            return 0;
        }

        static int toTable(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr) { lua_pushnil(L); return 1; }
            lua_createtable(L, (int)arr->size(), 0);
            for (size_t i = 0; i < arr->size(); ++i)
            {
                LuaCodec<T>::push(L, (*arr)[i], nullptr);
                lua_rawseti(L, -2, (int)(i + 1));
            }
            return 1;
        }

        static int iterNext(lua_State* L)
        {
            ArrayType* arr = get(L, 1);
            if (!arr) return 0;
            size_t i = (size_t)lua_tointeger(L, 2) + 1;
            if (i > arr->size()) return 0;
            lua_pushinteger(L, (lua_Integer)i);
            LuaCodec<T>::push(L, (*arr)[i - 1], nullptr);
            return 2;
        }

        static int pairs(lua_State* L)
        {
            lua_pushcfunction(L, iterNext);
            lua_pushvalue(L, 1);
            lua_pushinteger(L, 0);
            return 3;
        }

        static int ipairs(lua_State* L) { return pairs(L); }

        static void registerBinding(lua_State* L, const char* name, const char* elemName = nullptr)
        {
            metaName = name;

            static const luaL_Reg meta[] = {
                { "__gc",       gc },
                { "__len",      len },
                { "__index",    index },
                { "__newindex", newindex },
                { "__pairs",    pairs },
                { "__ipairs",   ipairs },
                { 0, 0 }
            };
            static const luaL_Reg methods[] = {
                { "push_back", push_back },
                { "push",      push_back },
                { "pop_back",  pop_back },
                { "pop",       pop_back },
                { "front",     front },
                { "back",      back },
                { "removeAt",  removeAt },
                { "clear",     clear },
                { "empty",     empty },
                { "reserve",   reserve },
                { "size",      size },
                { "toTable",   toTable },
                { 0, 0 }
            };
            registerClass(L, metaName, meta, methods, index, newindex);
        }
    };

    template <typename T>
    const char* OgreFastArrayPrimitiveBinding<T>::metaName = nullptr;

} // namespace KenshiLua
