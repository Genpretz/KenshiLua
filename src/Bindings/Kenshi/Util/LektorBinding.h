#pragma once
#include "Lua/ContainerBinding.h"
#include <kenshi/util/lektor.h>
#include <kenshi/ModInfo.h>
#include "Bindings/Kenshi/ModInfoBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Lua/LuaCodec.h"
#include "Lua/BindingHelpers.h"
#include <string.h>
#include <string>
#include <type_traits>
#include <utility>
#include <unordered_map>
#include <boost/type_traits/has_trivial_copy.hpp>
#include <boost/type_traits/has_trivial_destructor.hpp>

#include <release_assert.h>

namespace KenshiLua
{
    // Lektor storage blocks that KenshiLua allocated, each mapped to the lektor that
    // owns it. Storage that the engine allocated, for example when a script-created
    // lektor is passed to an engine function that fills it, comes from the engine's
    // allocator. Freeing such a block with Ogre's allocator corrupts the heap, so only
    // blocks recorded here may be freed by KenshiLua.
    inline std::unordered_map<void*, const void*>& lektorOwnedStorage()
    {
        static std::unordered_map<void*, const void*> s_storage;
        return s_storage;
    }

    template <typename T>
    inline bool lektorOwnsStorage(const lektor<T>& lek)
    {
        if (!lek.stuff)
            return false;
        std::unordered_map<void*, const void*>& storage = lektorOwnedStorage();
        std::unordered_map<void*, const void*>::const_iterator it = storage.find((void*)lek.stuff);
        return it != storage.end() && it->second == (const void*)&lek;
    }

    template <typename T>
    inline void lektorRecordOwnedStorage(const lektor<T>& lek)
    {
        if (lek.stuff)
            lektorOwnedStorage()[(void*)lek.stuff] = (const void*)&lek;
    }

    inline void lektorFreeOwnedStorage(void* block)
    {
        lektorOwnedStorage().erase(block);
        Ogre::AllocatedObject<
            Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL>
        >::operator delete(block);
    }
}

template<typename T>
void lektor_push_back(lektor<T>& lek, const T& val)
{
    if (lek.count >= lek.maxSize)
    {
        uint32_t newMax = lek.maxSize == 0 ? 4 : lek.maxSize * 2;
        T* newStuff = (T*)Ogre::AllocatedObject<
            Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL>
        >::operator new(newMax * sizeof(T));
        if (lek.stuff)
        {
            const bool ownedOld = KenshiLua::lektorOwnsStorage(lek);
            if (boost::has_trivial_copy<T>::value)
            {
                memcpy(newStuff, lek.stuff, lek.count * sizeof(T));
            }
            else
            {
                for (uint32_t i = 0; i < lek.count; ++i)
                {
                    ::new((void*)&newStuff[i]) T(std::move(lek.stuff[i]));
                    lek.stuff[i].~T();
                }
            }
            // Free the old block only if KenshiLua allocated it. A block from the
            // engine's allocator must not be freed with Ogre operator delete, so it
            // is deliberately leaked.
            if (ownedOld)
                KenshiLua::lektorFreeOwnedStorage(lek.stuff);
        }
        lek.stuff = newStuff;
        lek.maxSize = newMax;
        KenshiLua::lektorRecordOwnedStorage(lek);
    }
    ::new((void*)&lek.stuff[lek.count++]) T(val);
}

template<typename T>
void lektor_pop_back(lektor<T>& lek)
{
    assert_release(lek.count > 0 && "lektor_pop_back: container is empty");
    --lek.count;
    lek.stuff[lek.count].~T();
}

template<typename T>
T lektor_pop_back_val(lektor<T>& lek)
{
    assert_release(lek.count > 0 && "lektor_pop_back_val: container is empty");
    T val = lek.stuff[lek.count - 1];
    --lek.count;
    lek.stuff[lek.count].~T();
    return val;
}

template<typename T>
void lektor_remove_at(lektor<T>& lek, uint32_t index)
{
    assert_release(index < lek.count && "lektor_remove_at: index out of bounds");
    for (uint32_t j = index + 1; j < lek.count; ++j)
        lek.stuff[j - 1] = std::move(lek.stuff[j]);
    --lek.count;
    lek.stuff[lek.count].~T();
}

namespace KenshiLua
{
    typedef int (*LektorFactoryFn)(lua_State* L);

    template <typename T>
    inline int pushLektorValue(lua_State* L, T* value, const char* elemMetaName)
    {
        return pushObject<T>(L, value, elemMetaName);
    }

    template <>
    inline int pushLektorValue<hand>(lua_State* L, hand* value, const char*)
    {
        return HandBinding::push(L, *value);
    }

    // =========================================================================
    // Policies for LektorContainerBinding
    // =========================================================================

    template <typename T>
    struct LektorPtrPolicy
    {
        static int pushElement(lua_State* L, const T& elem, const char* elemMetaName)
        {
            return pushObject<typename std::remove_pointer<T>::type>(L, elem, elemMetaName);
        }

        static int pushPopped(lua_State* L, const T& elem, const char* elemMetaName)
        {
            return pushElement(L, elem, elemMetaName);
        }

        static T readElement(lua_State* L, int idx, const char* elemMetaName)
        {
            T val = checkObject<typename std::remove_pointer<T>::type>(L, idx, elemMetaName);
            if (!val)
            {
                luaL_error(L, "lektor: expected valid object");
                return NULL;
            }
            return val;
        }

    };

    template <typename T>
    struct LektorValuePolicy
    {
        static int pushElement(lua_State* L, const T& elem, const char* elemMetaName)
        {
            if (elemMetaName)
                return pushLektorValue<T>(L, const_cast<T*>(&elem), elemMetaName);
            else
            {
                LuaCodec<T>::push(L, elem, NULL);
                return 1;
            }
        }

        static int pushPopped(lua_State* L, const T& elem, const char* elemMetaName)
        {
            if (elemMetaName)
                return pushValue<T>(L, elem, elemMetaName);
            else
            {
                LuaCodec<T>::push(L, elem, NULL);
                return 1;
            }
        }

        static T readElement(lua_State* L, int idx, const char* elemMetaName)
        {
            if (elemMetaName)
            {
                T* pVal = checkObject<T>(L, idx, elemMetaName);
                if (!pVal)
                {
                    luaL_error(L, "lektor: expected valid object for assignment");
                    return T();
                }
                return *pVal;
            }
            else
            {
                return LuaCodec<T>::read(L, idx, NULL);
            }
        }

    };

    template <typename T>
    struct LektorValueReadOnlyPolicy : public LektorValuePolicy<T>
    {
    };

    struct LektorStringPolicy
    {
        static int pushElement(lua_State* L, const std::string& elem, const char* /*elemMetaName*/)
        {
            lua_pushlstring(L, elem.c_str(), elem.size());
            return 1;
        }

        static int pushPopped(lua_State* L, const std::string& elem, const char* elemMetaName)
        {
            return pushElement(L, elem, elemMetaName);
        }

        static std::string readElement(lua_State* L, int idx, const char* /*elemMetaName*/)
        {
            size_t len = 0;
            const char* s = luaL_checklstring(L, idx, &len);
            return std::string(s, len);
        }

    };

    struct LektorIntPolicy
    {
        static int pushElement(lua_State* L, const int& elem, const char* /*elemMetaName*/)
        {
            lua_pushinteger(L, (lua_Integer)elem);
            return 1;
        }

        static int pushPopped(lua_State* L, const int& elem, const char* elemMetaName)
        {
            return pushElement(L, elem, elemMetaName);
        }

        static int readElement(lua_State* L, int idx, const char* /*elemMetaName*/)
        {
            return (int)luaL_checkinteger(L, idx);
        }

    };

    // =========================================================================
    // Read-Only Generic Lektor Base Binding
    // =========================================================================

    template <typename T, typename Policy>
    struct LektorReadOnlyContainerBinding
    {
        typedef lektor<T> ContainerType;
        typedef LektorReadOnlyContainerBinding<T, Policy> MetadataType;
        static const char* const metaName;
        static const char* const metadata[3];

        static const char* getMetatableName() { return metaName; }

        static lektor<T>* getInstance(lua_State* L, int idx)
        {
            return checkObject<lektor<T> >(L, idx, metaName);
        }

        static int push(lua_State* L, lektor<T>* lek)
        {
            return pushObject<lektor<T> >(L, lek, metaName);
        }

        static int gc(lua_State* L) { return noopGc(L); }

        static int gcOwned(lua_State* L)
        {
            void** ud = (void**)lua_touserdata(L, 1);
            if (ud && *ud)
            {
                lektor<T>* lek = static_cast<lektor<T>*>(*ud);
                if (lek->stuff)
                {
                    // Only storage KenshiLua allocated is destroyed and freed. Storage
                    // the engine allocated, such as after an engine function filled
                    // this lektor, belongs to the engine's allocator; freeing it with
                    // Ogre operator delete corrupts the heap, so it and its elements
                    // are deliberately leaked.
                    if (lektorOwnsStorage(*lek))
                    {
                        for (uint32_t i = 0; i < lek->count; ++i)
                            lek->stuff[i].~T();
                        lektorFreeOwnedStorage(lek->stuff);
                    }
                    lek->stuff = NULL;
                }
                delete lek;
                *ud = NULL;
            }
            return 0;
        }

        static int pushOwned(lua_State* L, lektor<T>* lek)
        {
            return pushObjectOwnedCustom<lektor<T>, gcOwned>(L, lek, metaName);
        }

        static int createNew(lua_State* L)
        {
            lektor<T>* lek = new lektor<T>();
            return pushOwned(L, lek);
        }

        static int len(lua_State* L)
        {
            lektor<T>* lek = getInstance(L, 1);
            lua_pushinteger(L, lek ? lek->count : 0);
            return 1;
        }

        static int size(lua_State* L)
        {
            return len(L);
        }

        static int index(lua_State* L)
        {
            lektor<T>* lek = getInstance(L, 1);
            if (!lek) { lua_pushnil(L); return 1; }

            // numeric index -> element access (1-based)
            if (lua_isnumber(L, 2))
            {
                uint32_t i = (uint32_t)lua_tointeger(L, 2);
                if (i < 1 || i > lek->count) { lua_pushnil(L); return 1; }
                return Policy::pushElement(L, lek->stuff[i - 1], metadata[0]);
            }

            // fall through to metatable methods
            if (metaName && lua_isstring(L, 2))
            {
                luaL_getmetatable(L, metaName);
                lua_getfield(L, -1, lua_tostring(L, 2));
                return 1;
            }
            lua_pushnil(L);
            return 1;
        }

        static int newindex(lua_State* L)
        {
            return luaL_error(L, "lektor is read-only");
        }

        static int toTable(lua_State* L)
        {
            lektor<T>* lek = getInstance(L, 1);
            if (!lek) { lua_pushnil(L); return 1; }
            lua_createtable(L, (int)lek->count, 0);
            for (uint32_t i = 0; i < lek->count; ++i)
            {
                Policy::pushElement(L, lek->stuff[i], metadata[0]);
                lua_rawseti(L, -2, (int)(i + 1));
            }
            return 1;
        }

        static int iterNext(lua_State* L)
        {
            lektor<T>* lek = getInstance(L, 1);
            if (!lek) return 0;
            uint32_t i = (uint32_t)lua_tointeger(L, 2) + 1;
            if (i > lek->count) return 0;
            lua_pushinteger(L, (lua_Integer)i);
            Policy::pushElement(L, lek->stuff[i - 1], metadata[0]);
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

        static void registerBinding(lua_State* L)
        {
            if (!beginContainerBinding(L, containerBindingDefinition<MetadataType>())) return;

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
                { "size",      size },
                { "toTable",   toTable },
                { 0, 0 }
            };
            registerClass(L, metaName, meta, methods, index, newindex);
        }
    };

    // =========================================================================
    // Writable Generic Lektor Container Binding
    // =========================================================================

    template <typename T, typename Policy>
    struct LektorContainerBinding : public LektorReadOnlyContainerBinding<T, Policy>
    {
        typedef LektorReadOnlyContainerBinding<T, Policy> Base;

        static int push(lua_State* L, lektor<T>* lek)
        {
            return Base::push(L, lek);
        }

        static int newindex(lua_State* L)
        {
            lektor<T>* lek = Base::getInstance(L, 1);
            if (!lek) return luaL_error(L, "lektor is nil");

            if (!lua_isnumber(L, 2))
                return luaL_error(L, "lektor: only numeric indices are writable");

            uint32_t i = (uint32_t)lua_tointeger(L, 2);
            if (i < 1 || i > lek->count + 1)
            {
                return luaL_error(L, "lektor: index %u out of range (size=%u, can append at %u)",
                    i, lek->count, lek->count + 1);
            }

            T val = Policy::readElement(L, 3, Base::metadata[0]);
            if (i <= lek->count)
            {
                lek->stuff[i - 1] = val;
                return 0;
            }
            lektor_push_back(*lek, val);
            return 0;
        }

        static int pushMethod(lua_State* L)
        {
            lektor<T>* lek = Base::getInstance(L, 1);
            if (!lek) return luaL_error(L, "lektor is nil");
            T val = Policy::readElement(L, 2, Base::metadata[0]);
            lektor_push_back(*lek, val);
            return 0;
        }

        static int pop(lua_State* L)
        {
            lektor<T>* lek = Base::getInstance(L, 1);
            if (!lek) return luaL_error(L, "lektor is nil");
            if (lek->count == 0) return luaL_error(L, "lektor:pop container is empty");
            T val = lektor_pop_back_val(*lek);
            return Policy::pushPopped(L, val, Base::metadata[0]);
        }

        static int removeAt(lua_State* L)
        {
            lektor<T>* lek = Base::getInstance(L, 1);
            if (!lek) return luaL_error(L, "lektor is nil");
            uint32_t i = (uint32_t)luaL_checkinteger(L, 2);
            if (i < 1 || i > lek->count) return luaL_error(L, "lektor:removeAt index out of range");

            lektor_remove_at(*lek, i - 1);
            return 0;
        }

        static int clear(lua_State* L)
        {
            lektor<T>* lek = Base::getInstance(L, 1);
            if (lek)
            {
                for (uint32_t i = 0; i < lek->count; ++i)
                    lek->stuff[i].~T();
                lek->clear();
            }
            return 0;
        }

        static void registerBinding(lua_State* L)
        {
            if (!beginContainerBinding(L, containerBindingDefinition<typename Base::MetadataType>())) return;

            static const luaL_Reg meta[] = {
                { "__gc",       Base::gc },
                { "__len",      Base::len },
                { "__index",    Base::index },
                { "__newindex", newindex },
                { "__pairs",    Base::pairs },
                { "__ipairs",   Base::ipairs },
                { 0, 0 }
            };

            static const luaL_Reg methods[] = {
                { "push",      pushMethod },
                { "pop",       pop },
                { "removeAt",  removeAt },
                { "clear",     clear },
                { "size",      Base::size },
                { "toTable",   Base::toTable },
                { 0, 0 }
            };
            registerClass(L, Base::metaName, meta, methods, Base::index, newindex);
        }
    };

    // =========================================================================
    // Concrete Binding Wrappers (MSVC 2010 Compatible Structs)
    // =========================================================================

    template <typename T>
    struct LektorPtrBinding : public LektorContainerBinding<T, LektorPtrPolicy<T> >
    {
    };

    template <typename T>
    struct LektorValueBinding : public LektorContainerBinding<T, LektorValuePolicy<T> >
    {
    };

    template <typename T>
    struct LektorValueReadOnlyBinding : public LektorReadOnlyContainerBinding<T, LektorValueReadOnlyPolicy<T> >
    {
    };

    template <typename T = std::string>
    struct LektorStringBinding : public LektorContainerBinding<std::string, LektorStringPolicy>
    {
    };

    template <typename T = int>
    struct LektorIntBinding : public LektorContainerBinding<int, LektorIntPolicy>
    {
    };

    inline LektorFactoryFn resolveLektorFactory(lua_State* L, const std::string& typeName)
    {
        lua_CFunction fn = findExplicitContainerFactory(L, "lektor", typeName);
        if (fn) return fn;
        if (typeName.length() > 8 && typeName.rfind("lektor<", 0) == 0 && typeName.back() == '>')
            return findExplicitContainerFactory(L, "lektor", typeName.substr(7, typeName.length() - 8));
        return findExplicitContainerFactory(L, "lektor", "lektor<" + typeName + ">");
    }

    inline int lua_lektor_new(lua_State* L)
    {
        LektorFactoryFn fn = NULL;
        {
            std::string typeName = extractContainerTypeName(L, 1);
            if (!lua_isstring(L, 1))
                typeName = findContainerFactoryElementType(L, "lektor", 0, typeName);
            if (typeName.empty())
            {
                lua_pushfstring(L, "lektor.new: expected an explicit type name ('T' or 'T*') or an unambiguous bound type as argument 1, got %s", luaL_typename(L, 1));
            }
            else
            {
                fn = resolveLektorFactory(L, typeName);
                if (!fn)
                {
                    lua_pushfstring(L, "lektor.new: unsupported or unknown type '%s'", typeName.c_str());
                }
            }
        }
        if (!fn)
            return lua_error(L);
        return fn(L);
    }

    inline int lua_lektor_call(lua_State* L)
    {
        lua_remove(L, 1);
        return lua_lektor_new(L);
    }

    inline void registerLektorGlobal(lua_State* L)
    {
        lua_newtable(L);
        lua_pushcfunction(L, lua_lektor_new);
        lua_setfield(L, -2, "new");

        lua_newtable(L);
        lua_pushcfunction(L, lua_lektor_call);
        lua_setfield(L, -2, "__call");
        lua_setmetatable(L, -2);

        lua_setglobal(L, "lektor");
    }
} // namespace KenshiLua
