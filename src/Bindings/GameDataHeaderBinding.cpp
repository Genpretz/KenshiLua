#include "pch.h"
#include "kenshi\GameData.h"
#include "GameDataHeaderBinding.h"
#include "Lua/BindingHelpers.h"

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

int GameDataHeaderBinding::_DESTRUCTOR(lua_State* L)
{
    GameDataHeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataHeader is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 26: GameDataHeader* _CONSTRUCTOR(...) - overloaded method
  line 28: GameDataHeader* _CONSTRUCTOR(...) - overloaded method
  line 30: GameDataHeader* _CONSTRUCTOR(...) - overloaded method
  line 39: GameDataHeader& operator=(...) - operator
*/

/*
Skipped properties needing manual binding:
  line 35: dependencies (lektor<std::string >) - unsupported type
  line 36: references (lektor<std::string >) - unsupported type
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
    registerGetter(L, "name", GameDataHeader_get_name);
    registerGetter(L, "author", GameDataHeader_get_author);
    registerGetter(L, "version", GameDataHeader_get_version);
    registerGetter(L, "description", GameDataHeader_get_description);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "name", GameDataHeader_set_name);
    registerSetter(L, "author", GameDataHeader_set_author);
    registerSetter(L, "version", GameDataHeader_set_version);
    registerSetter(L, "description", GameDataHeader_set_description);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua