#include "pch.h"
#include "KENSHI\GameData.h"
#include "GameDataReferenceBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/Util/TripleIntBinding.h"

namespace KenshiLua
{

static GameDataReference* getInstance(lua_State* L, int idx)
{
    return checkObject<GameDataReference>(L, idx, GameDataReferenceBinding::getMetatableName());
}

// --- Getters for GameDataReference ---
static int GameDataReference_get_values(lua_State* L)
{
    GameDataReference* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataReference is nil");
    return pushObject<TripleInt>(L, &instance->values, TripleIntBinding::getMetatableName());
}

static int GameDataReference_get_sid(lua_State* L)
{
    GameDataReference* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataReference is nil");
    lua_pushstring(L, instance->sid.c_str());
    return 1;
}

static int GameDataReference_get_ptr(lua_State* L)
{
    GameDataReference* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataReference is nil");
    return pushObject<GameData>(L, instance->ptr, GameDataBinding::getMetatableName());
}

// --- Setters for GameDataReference ---
static int GameDataReference_set_values(lua_State* L)
{
    GameDataReference* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataReference is nil");
    instance->values = *checkObject<TripleInt>(L, 2, TripleIntBinding::getMetatableName());
    return 0;
}

static int GameDataReference_set_sid(lua_State* L)
{
    GameDataReference* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataReference is nil");
    instance->sid = luaL_checkstring(L, 2);
    return 0;
}

static int GameDataReference_set_ptr(lua_State* L)
{
    GameDataReference* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataReference is nil");
    instance->ptr = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

int GameDataReferenceBinding::getPtr(lua_State* L)
{
    GameDataReference* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataReference is nil");

    GameDataContainer* source = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* result = instance->getPtr(source);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int GameDataReferenceBinding::_DESTRUCTOR(lua_State* L)
{
    GameDataReference* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataReference is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 192: GameDataReference* _CONSTRUCTOR(...) - overloaded method
  line 194: GameDataReference* _CONSTRUCTOR(...) - overloaded method
  line 196: GameDataReference* _CONSTRUCTOR(...) - overloaded method
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
        { "getPtr", GameDataReferenceBinding::getPtr },
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
    registerGetter(L, "values", GameDataReference_get_values);
    registerGetter(L, "sid", GameDataReference_get_sid);
    registerGetter(L, "ptr", GameDataReference_get_ptr);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "values", GameDataReference_set_values);
    registerSetter(L, "sid", GameDataReference_set_sid);
    registerSetter(L, "ptr", GameDataReference_set_ptr);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua