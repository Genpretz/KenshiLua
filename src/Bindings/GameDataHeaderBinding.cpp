#include "pch.h"
#include "kenshi\GameData.h"
#include "GameDataHeaderBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static GameDataHeader* getB(lua_State* L, int idx)
{
    return checkObject<GameDataHeader>(L, idx, GameDataHeaderBinding::getMetatableName());
}

// --- Getters for GameDataHeader ---
static int GameDataHeader_get_name(lua_State* L)
{
    GameDataHeader* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataHeader is nil");
    lua_pushstring(L, b->name.c_str());
    return 1;
}

static int GameDataHeader_get_author(lua_State* L)
{
    GameDataHeader* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataHeader is nil");
    lua_pushstring(L, b->author.c_str());
    return 1;
}

static int GameDataHeader_get_version(lua_State* L)
{
    GameDataHeader* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataHeader is nil");
    lua_pushinteger(L, b->version);
    return 1;
}

static int GameDataHeader_get_description(lua_State* L)
{
    GameDataHeader* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataHeader is nil");
    lua_pushstring(L, b->description.c_str());
    return 1;
}

static int GameDataHeader_get_dependencies(lua_State* L)
{
    GameDataHeader* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataHeader is nil");
    // TODO: Unsupported type for dependencies (lektor<std::string >)
    return luaL_error(L, "Unsupported property 'dependencies' (type: lektor<std::string >)");
}

static int GameDataHeader_get_references(lua_State* L)
{
    GameDataHeader* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataHeader is nil");
    // TODO: Unsupported type for references (lektor<std::string >)
    return luaL_error(L, "Unsupported property 'references' (type: lektor<std::string >)");
}

// --- Setters for GameDataHeader ---
static int GameDataHeader_set_name(lua_State* L)
{
    GameDataHeader* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataHeader is nil");
    b->name = luaL_checkstring(L, 2);
    return 0;
}

static int GameDataHeader_set_author(lua_State* L)
{
    GameDataHeader* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataHeader is nil");
    b->author = luaL_checkstring(L, 2);
    return 0;
}

static int GameDataHeader_set_version(lua_State* L)
{
    GameDataHeader* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataHeader is nil");
    b->version = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int GameDataHeader_set_description(lua_State* L)
{
    GameDataHeader* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataHeader is nil");
    b->description = luaL_checkstring(L, 2);
    return 0;
}

static int GameDataHeader_set_dependencies(lua_State* L)
{
    GameDataHeader* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataHeader is nil");
    return luaL_error(L, "Read-only or unsupported setter type for dependencies");
}

static int GameDataHeader_set_references(lua_State* L)
{
    GameDataHeader* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataHeader is nil");
    return luaL_error(L, "Read-only or unsupported setter type for references");
}

int GameDataHeaderBinding::_DESTRUCTOR(lua_State* L)
{
    GameDataHeader* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataHeader is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 26: GameDataHeader* _CONSTRUCTOR(...) - overloaded method
  line 28: GameDataHeader* _CONSTRUCTOR(...) - overloaded method
  line 30: GameDataHeader* _CONSTRUCTOR(...) - overloaded method
  line 39: GameDataHeader& operator=(...) - operator
*/

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
        { "_DESTRUCTOR", GameDataHeaderBinding::_DESTRUCTOR },
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
    lua_pushcfunction(L, GameDataHeader_get_name);
    lua_setfield(L, -2, "name");
    lua_pushcfunction(L, GameDataHeader_get_author);
    lua_setfield(L, -2, "author");
    lua_pushcfunction(L, GameDataHeader_get_version);
    lua_setfield(L, -2, "version");
    lua_pushcfunction(L, GameDataHeader_get_description);
    lua_setfield(L, -2, "description");
    lua_pushcfunction(L, GameDataHeader_get_dependencies);
    lua_setfield(L, -2, "dependencies");
    lua_pushcfunction(L, GameDataHeader_get_references);
    lua_setfield(L, -2, "references");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, GameDataHeader_set_name);
    lua_setfield(L, -2, "name");
    lua_pushcfunction(L, GameDataHeader_set_author);
    lua_setfield(L, -2, "author");
    lua_pushcfunction(L, GameDataHeader_set_version);
    lua_setfield(L, -2, "version");
    lua_pushcfunction(L, GameDataHeader_set_description);
    lua_setfield(L, -2, "description");
    lua_pushcfunction(L, GameDataHeader_set_dependencies);
    lua_setfield(L, -2, "dependencies");
    lua_pushcfunction(L, GameDataHeader_set_references);
    lua_setfield(L, -2, "references");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua