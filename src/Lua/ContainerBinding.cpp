#include "pch.h"
#include "Lua/ContainerBinding.h"

#include <stdexcept>

namespace KenshiLua
{
namespace
{
char registryKey;

struct TypeInfoLess
{
    bool operator()(const std::type_info* first, const std::type_info* second) const
    {
        return first->before(*second) != 0;
    }
};

bool sameString(const char* first, const char* second)
{
    return first == second || (first && second && strcmp(first, second) == 0);
}

bool sameDefinition(const ContainerBindingDefinition& first, const ContainerBindingDefinition& second)
{
    if (!sameString(first.name, second.name) ||
        *first.containerType != *second.containerType || *first.bindingType != *second.bindingType ||
        first.install != second.install || !sameString(first.factory.family, second.factory.family) ||
        first.factory.create != second.factory.create || first.factory.aliasCount != second.factory.aliasCount)
        return false;
    for (size_t i = 0; i < 3; ++i)
        if (!sameString(first.metadata[i], second.metadata[i])) return false;
    for (size_t i = 0; i < first.factory.aliasCount; ++i)
        if (!sameString(first.factory.aliases[i], second.factory.aliases[i])) return false;
    return true;
}

void conflict(const char* kind, const std::string& name,
    const ContainerBindingDefinition& first, const ContainerBindingDefinition* second)
{
    std::string message = std::string("Container registration ") + kind + " '" + name + "': " +
        first.source + " [" + first.containerType->name() + "; " + first.bindingType->name() + "]";
    if (second)
        message += std::string(" conflicts with ") + second->source + " [" +
            second->containerType->name() + "; " + second->bindingType->name() + "]";
    else
        message += " conflicts with an existing unclaimed metatable";
    throw std::runtime_error(message);
}

void pushRegistry(lua_State* L)
{
    lua_pushlightuserdata(L, &registryKey);
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L, -1)) return;
    lua_pop(L, 1);
    lua_newtable(L);
    lua_pushlightuserdata(L, &registryKey);
    lua_pushvalue(L, -2);
    lua_rawset(L, LUA_REGISTRYINDEX);
}

const ContainerBindingDefinition* registeredDefinition(lua_State* L, const std::string& key)
{
    pushRegistry(L);
    lua_getfield(L, -1, key.c_str());
    const ContainerBindingDefinition* result =
        static_cast<const ContainerBindingDefinition*>(lua_touserdata(L, -1));
    lua_pop(L, 2);
    return result;
}

void recordDefinition(lua_State* L, const std::string& key, const ContainerBindingDefinition& definition)
{
    pushRegistry(L);
    lua_pushlightuserdata(L, const_cast<ContainerBindingDefinition*>(&definition));
    lua_setfield(L, -2, key.c_str());
    lua_pop(L, 1);
}

std::string factoryKey(const char* family, const std::string& alias)
{
    return std::string("factory:") + family + ":" + alias;
}

int factoryArgumentCount(const char* family)
{
    if (strcmp(family, "ogre_unordered_map") == 0) return 2;
    if (strcmp(family, "lektor") == 0 || strcmp(family, "ogre_unordered_set") == 0) return 1;
    return 0;
}

std::string trimTypeName(const std::string& text)
{
    size_t start = text.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) return std::string();
    return text.substr(start, text.find_last_not_of(" \t\r\n") - start + 1);
}

bool factoryTypeArguments(const char* family, const std::string& spelling, std::string types[2])
{
    std::string text = trimTypeName(spelling);
    std::string prefix = std::string(family) + "<";
    if (text.compare(0, prefix.size(), prefix) == 0 && text.size() > prefix.size() && text.back() == '>')
        text = text.substr(prefix.size(), text.size() - prefix.size() - 1);
    int count = 0;
    int depth = 0;
    size_t start = 0;
    for (size_t i = 0; i <= text.size(); ++i)
    {
        if (i == text.size() || (text[i] == ',' && depth == 0))
        {
            if (count == 2) return false;
            types[count] = trimTypeName(text.substr(start, i - start));
            if (types[count].empty()) return false;
            ++count;
            start = i + 1;
        }
        else if (text[i] == '<') ++depth;
        else if (text[i] == '>' && --depth < 0) return false;
    }
    return depth == 0 && count == factoryArgumentCount(family);
}

size_t pointerDepth(const std::string& type)
{
    size_t depth = 0;
    size_t end = type.size();
    while (end)
    {
        char last = type[end - 1];
        if (last == '*') ++depth;
        else if (last != ' ' && last != '\t') break;
        --end;
    }
    return depth;
}

std::string factoryElementKey(const char* family, int argument, const std::string& metatable)
{
    return std::string("factory-element:") + family + ":" + static_cast<char>('0' + argument) + ":" + metatable;
}

std::string bindingKey(const char* name)
{
    return std::string("binding:") + name;
}

std::string specializationKey(const ContainerBindingDefinition& definition)
{
    // MSVC's decorated RTTI name preserves full specialization identity, including
    // anonymous namespaces. The public diagnostic uses the readable name instead.
    return std::string("specialization:") + definition.bindingType->raw_name();
}

void validateMetatable(lua_State* L, const ContainerBindingDefinition& definition)
{
    const ContainerBindingDefinition* previous = registeredDefinition(L, bindingKey(definition.name));
    if (previous)
    {
        if (!sameDefinition(definition, *previous))
            conflict("definition", definition.name, definition, previous);
        lua_getfield(L, LUA_REGISTRYINDEX, definition.name);
        bool present = lua_istable(L, -1) != 0;
        lua_pop(L, 1);
        if (!present) throw std::runtime_error(std::string("Missing registered container metatable: ") + definition.name);
    }
    else
    {
        lua_getfield(L, LUA_REGISTRYINDEX, definition.name);
        bool occupied = !lua_isnil(L, -1);
        lua_pop(L, 1);
        if (occupied) conflict("name", definition.name, definition, NULL);
    }
    previous = registeredDefinition(L, specializationKey(definition));
    if (previous && !sameDefinition(definition, *previous))
        conflict("specialization", definition.name, definition, previous);
}
}

bool beginContainerBinding(lua_State* L, const ContainerBindingDefinition& definition)
{
    validateMetatable(L, definition);
    if (registeredDefinition(L, bindingKey(definition.name))) return false;
    recordDefinition(L, bindingKey(definition.name), definition);
    recordDefinition(L, specializationKey(definition), definition);
    return true;
}

void registerContainerBindings(lua_State* L, const ContainerBindingList& definitions)
{
    typedef std::map<std::string, const ContainerBindingDefinition*> DefinitionsByName;
    typedef std::map<const std::type_info*, const ContainerBindingDefinition*, TypeInfoLess> DefinitionsByType;
    DefinitionsByName names;
    DefinitionsByName factories;
    DefinitionsByType specializations;
    std::map<std::string, std::string> elementTypes;
    for (size_t i = 0; i < definitions.size(); ++i)
    {
        const ContainerBindingDefinition& definition = *definitions[i];
        DefinitionsByName::const_iterator previous = names.find(definition.name);
        if (previous != names.end() && !sameDefinition(definition, *previous->second))
            conflict("name", definition.name, definition, previous->second);
        names[definition.name] = &definition;
        DefinitionsByType::const_iterator previousType = specializations.find(definition.bindingType);
        if (previousType != specializations.end() && !sameDefinition(definition, *previousType->second))
            conflict("specialization", definition.name, definition, previousType->second);
        specializations[definition.bindingType] = &definition;
        validateMetatable(L, definition);
        if (!definition.factory.create) continue;
        int argumentCount = factoryArgumentCount(definition.factory.family);
        if (argumentCount)
        {
            std::string types[2];
            if (!factoryTypeArguments(definition.factory.family, definition.name, types))
                throw std::runtime_error(std::string("Invalid container factory type: ") + definition.name);
            for (int argument = 0; argument < argumentCount; ++argument)
            {
                if (!definition.metadata[argument]) continue;
                std::string key = factoryElementKey(definition.factory.family, argument, definition.metadata[argument]);
                std::map<std::string, std::string>::iterator found = elementTypes.find(key);
                if (found == elementTypes.end())
                {
                    pushRegistry(L);
                    lua_getfield(L, -1, key.c_str());
                    std::string type = types[argument];
                    if (!lua_isnil(L, -1) && (!lua_isstring(L, -1) || type != lua_tostring(L, -1)))
                        type.clear();
                    lua_pop(L, 2);
                    elementTypes[key] = type;
                }
                else if (found->second != types[argument])
                    found->second.clear();
            }
        }
        for (size_t j = 0; j <= definition.factory.aliasCount; ++j)
        {
            const char* alias = j ? definition.factory.aliases[j - 1] : definition.name;
            std::string key = factoryKey(definition.factory.family, alias);
            previous = factories.find(key);
            const ContainerBindingDefinition* installed = registeredDefinition(L, key);
            if (previous != factories.end() && !sameDefinition(definition, *previous->second))
                conflict("factory alias", alias, definition, previous->second);
            if (installed && !sameDefinition(definition, *installed))
                conflict("factory alias", alias, definition, installed);
            factories[key] = &definition;
        }
    }

    // Validate the whole catalog before any metatable or factory is installed.
    for (size_t i = 0; i < definitions.size(); ++i)
        definitions[i]->install(L);
    for (DefinitionsByName::const_iterator it = factories.begin(); it != factories.end(); ++it)
        recordDefinition(L, it->first, *it->second);
    pushRegistry(L);
    for (std::map<std::string, std::string>::const_iterator it = elementTypes.begin(); it != elementTypes.end(); ++it)
    {
        if (it->second.empty()) lua_pushboolean(L, 0);
        else lua_pushlstring(L, it->second.data(), it->second.size());
        lua_setfield(L, -2, it->first.c_str());
    }
    lua_pop(L, 1);
}

lua_CFunction findContainerFactory(lua_State* L, const char* family, const std::string& alias)
{
    const ContainerBindingDefinition* definition = registeredDefinition(L, factoryKey(family, alias));
    return definition ? definition->factory.create : NULL;
}

lua_CFunction findExplicitContainerFactory(lua_State* L, const char* family, const std::string& alias)
{
    const ContainerBindingDefinition* definition = registeredDefinition(L, factoryKey(family, alias));
    if (!definition) return NULL;
    std::string requested[2];
    std::string actual[2];
    if (!factoryTypeArguments(family, alias, requested) ||
        !factoryTypeArguments(family, definition->name, actual)) return NULL;
    for (int argument = 0; argument < factoryArgumentCount(family); ++argument)
        if (pointerDepth(requested[argument]) != pointerDepth(actual[argument])) return NULL;
    return definition->factory.create;
}

std::string findContainerFactoryElementType(lua_State* L, const char* family, int argument,
    const std::string& metatable)
{
    std::string prefix = std::string(family) + "<";
    if (argument == 0 && factoryArgumentCount(family) == 1 && metatable.compare(0, prefix.size(), prefix) == 0)
    {
        const ContainerBindingDefinition* definition = registeredDefinition(L, factoryKey(family, metatable));
        std::string types[2];
        if (definition && factoryTypeArguments(family, definition->name, types)) return types[0];
    }
    pushRegistry(L);
    std::string key = factoryElementKey(family, argument, metatable);
    lua_getfield(L, -1, key.c_str());
    std::string result;
    if (lua_isstring(L, -1)) result = lua_tostring(L, -1);
    lua_pop(L, 2);
    return result;
}

} // namespace KenshiLua
