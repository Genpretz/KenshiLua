#pragma once

#include <cstddef>
#include <typeinfo>
#include <vector>
#include <string>

extern "C" {
#include <lua.h>
}

namespace KenshiLua
{

struct ContainerFactoryDefinition
{
    const char* family;
    lua_CFunction create;
    const char* const* aliases;
    size_t aliasCount;

    ContainerFactoryDefinition()
        : family(NULL), create(NULL), aliases(NULL), aliasCount(0) {}

    template <size_t N>
    ContainerFactoryDefinition(const char* factoryFamily, lua_CFunction factory,
        const char* const (&factoryAliases)[N])
        : family(factoryFamily), create(factory), aliases(factoryAliases), aliasCount(N) {}
};

struct ContainerBindingDefinition
{
    const char* name;
    const char* metadata[3];
    const char* source;
    const std::type_info* containerType;
    const std::type_info* bindingType;
    void (*install)(lua_State* L);
    ContainerFactoryDefinition factory;
};

typedef std::vector<const ContainerBindingDefinition*> ContainerBindingList;

// Only catalogued specializations have a definition. Missing definitions fail to link.
template <typename T>
const ContainerBindingDefinition& containerBindingDefinition();

void registerContainerBindings(lua_State* L, const ContainerBindingList& definitions);
bool beginContainerBinding(lua_State* L, const ContainerBindingDefinition& definition);
lua_CFunction findContainerFactory(lua_State* L, const char* family, const std::string& alias);
lua_CFunction findExplicitContainerFactory(lua_State* L, const char* family, const std::string& alias);
std::string findContainerFactoryElementType(lua_State* L, const char* family, int argument,
    const std::string& metatable);

struct ReadOnlyContainerAccess {};
struct WritableContainerAccess {};

} // namespace KenshiLua

#define KENSHILUA_DEFINE_CONTAINER(Binding, Name, Meta1, Meta2, Meta3, Factory) \
    template <> const char* const Binding::MetadataType::metaName = Name; \
    template <> const char* const Binding::MetadataType::metadata[3] = { Meta1, Meta2, Meta3 }; \
    template <> \
    const ContainerBindingDefinition& containerBindingDefinition<Binding::MetadataType>() \
    { \
        static const ContainerBindingDefinition definition = { \
            Name, { Meta1, Meta2, Meta3 }, __FILE__, \
            &typeid(Binding::ContainerType), &typeid(Binding), \
            Binding::registerBinding, Factory \
        }; \
        return definition; \
    }
