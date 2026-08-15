#include "pch.h"
#include "kenshi\GameData.h"
#include "GameDataHeaderBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Util/LektorBinding.h"

namespace KenshiLua
{

static GameDataHeader* getInstance(lua_State* L, int idx)
{
    return checkObject<GameDataHeader>(L, idx, GameDataHeaderBinding::getMetatableName());
}

// --- Getters for GameDataHeader ---
static int GameDataHeader_get_name(lua_State* L)
{
    GameDataHeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataHeader is nil");
    lua_pushstring(L, instance->name.c_str());
    return 1;
}

static int GameDataHeader_get_author(lua_State* L)
{
    GameDataHeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataHeader is nil");
    lua_pushstring(L, instance->author.c_str());
    return 1;
}

static int GameDataHeader_get_version(lua_State* L)
{
    GameDataHeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataHeader is nil");
    lua_pushinteger(L, instance->version);
    return 1;
}

static int GameDataHeader_get_description(lua_State* L)
{
    GameDataHeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataHeader is nil");
    lua_pushstring(L, instance->description.c_str());
    return 1;
}

static int GameDataHeader_get_dependencies(lua_State* L)
{
    GameDataHeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataHeader is nil");
    return pushObject<lektor<std::string>>(L, &instance->dependencies, "lektor<std::string>");
}

static int GameDataHeader_get_references(lua_State* L)
{
    GameDataHeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataHeader is nil");
    return pushObject<lektor<std::string>>(L, &instance->references, "lektor<std::string>");
}

// --- Setters for GameDataHeader ---
static int GameDataHeader_set_name(lua_State* L)
{
    GameDataHeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataHeader is nil");
    instance->name = luaL_checkstring(L, 2);
    return 0;
}

static int GameDataHeader_set_author(lua_State* L)
{
    GameDataHeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataHeader is nil");
    instance->author = luaL_checkstring(L, 2);
    return 0;
}

static int GameDataHeader_set_version(lua_State* L)
{
    GameDataHeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataHeader is nil");
    instance->version = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int GameDataHeader_set_description(lua_State* L)
{
    GameDataHeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataHeader is nil");
    instance->description = luaL_checkstring(L, 2);
    return 0;
}

static int GameDataHeader_set_dependencies(lua_State* L)
{
    GameDataHeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataHeader is nil");
    auto* val = LektorStringBinding<std::string>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set dependencies must be lektor<std::string>");
    instance->dependencies = *val;
    return 0;
}

static int GameDataHeader_set_references(lua_State* L)
{
    GameDataHeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataHeader is nil");
    auto* val = LektorStringBinding<std::string>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set references must be lektor<std::string>");
    instance->references = *val;
    return 0;
}

int GameDataHeaderBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int GameDataHeaderBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.GameDataHeader object");
    return 1;
}

void GameDataHeaderBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GameDataHeaderBinding::gc },
        { "__tostring", GameDataHeaderBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        GameDataHeaderBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, GameDataHeaderBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "name", GameDataHeader_get_name);
    registerGetter(L, "author", GameDataHeader_get_author);
    registerGetter(L, "version", GameDataHeader_get_version);
    registerGetter(L, "description", GameDataHeader_get_description);
    registerGetter(L, "dependencies", GameDataHeader_get_dependencies);
    registerGetter(L, "references", GameDataHeader_get_references);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "name", GameDataHeader_set_name);
    registerSetter(L, "author", GameDataHeader_set_author);
    registerSetter(L, "version", GameDataHeader_set_version);
    registerSetter(L, "description", GameDataHeader_set_description);
    registerSetter(L, "dependencies", GameDataHeader_set_dependencies);
    registerSetter(L, "references", GameDataHeader_set_references);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    LektorStringBinding<std::string>::registerBinding(L, "lektor<std::string>");

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua