#include "pch.h"
#include "kenshi\GameData.h"
#include "GameDataReferenceBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{

static GameDataReference* getB(lua_State* L, int idx)
{
    return checkObject<GameDataReference>(L, idx, GameDataReferenceBinding::getMetatableName());
}

// --- Getters for GameDataReference ---
static int GameDataReference_get_values(lua_State* L)
{
    GameDataReference* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataReference is nil");
    // TODO: Unsupported type for values (TripleInt)
    lua_pushnil(L);
    return 1;
}

static int GameDataReference_get_sid(lua_State* L)
{
    GameDataReference* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataReference is nil");
    lua_pushstring(L, b->sid.c_str());
    return 1;
}

static int GameDataReference_get_ptr(lua_State* L)
{
    GameDataReference* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataReference is nil");
    return pushObject<GameData>(L, b->ptr, GameDataBinding::getMetatableName());
}

// --- Setters for GameDataReference ---
static int GameDataReference_set_values(lua_State* L)
{
    GameDataReference* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataReference is nil");
    return luaL_error(L, "Read-only or unsupported setter type for values");
}

static int GameDataReference_set_sid(lua_State* L)
{
    GameDataReference* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataReference is nil");
    b->sid = luaL_checkstring(L, 2);
    return 0;
}

static int GameDataReference_set_ptr(lua_State* L)
{
    GameDataReference* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataReference is nil");
    return luaL_error(L, "Read-only or unsupported setter type for ptr");
}

int GameDataReferenceBinding::_DESTRUCTOR(lua_State* L)
{
    GameDataReference* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataReference is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 192: GameDataReference* _CONSTRUCTOR(...) - overloaded method
  line 194: GameDataReference* _CONSTRUCTOR(...) - overloaded method
  line 196: GameDataReference* _CONSTRUCTOR(...) - overloaded method
  line 200: GameData* getPtr(...) - unsupported arg type
  line 203: GameDataReference& operator=(...) - operator
*/

int GameDataReferenceBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int GameDataReferenceBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.GameDataReference object");
    return 1;
}

void GameDataReferenceBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GameDataReferenceBinding::gc },
        { "__tostring", GameDataReferenceBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", GameDataReferenceBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        GameDataReferenceBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, GameDataReferenceBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, GameDataReference_get_values);
    lua_setfield(L, -2, "values");
    lua_pushcfunction(L, GameDataReference_get_sid);
    lua_setfield(L, -2, "sid");
    lua_pushcfunction(L, GameDataReference_get_ptr);
    lua_setfield(L, -2, "ptr");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, GameDataReference_set_values);
    lua_setfield(L, -2, "values");
    lua_pushcfunction(L, GameDataReference_set_sid);
    lua_setfield(L, -2, "sid");
    lua_pushcfunction(L, GameDataReference_set_ptr);
    lua_setfield(L, -2, "ptr");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua