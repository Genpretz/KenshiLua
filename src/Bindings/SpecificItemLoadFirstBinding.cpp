#include "pch.h"
#include "kenshi\RootObject.h"
#include "SpecificItemLoadFirstBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameSaveStateBinding.h"

namespace KenshiLua
{

static SpecificItemLoadFirst* getInstance(lua_State* L, int idx)
{
    return checkObject<SpecificItemLoadFirst>(L, idx, SpecificItemLoadFirstBinding::getMetatableName());
}

// --- Getters for SpecificItemLoadFirst ---
static int SpecificItemLoadFirst_get_baseTypes(lua_State* L)
{
    SpecificItemLoadFirst* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpecificItemLoadFirst is nil");
    lua_pushinteger(L, (lua_Integer)instance->baseTypes);
    return 1;
}

static int SpecificItemLoadFirst_get_stateEnum(lua_State* L)
{
    SpecificItemLoadFirst* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpecificItemLoadFirst is nil");
    lua_pushinteger(L, (lua_Integer)instance->stateEnum);
    return 1;
}

static int SpecificItemLoadFirst_get_specificProperty(lua_State* L)
{
    SpecificItemLoadFirst* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpecificItemLoadFirst is nil");
    lua_pushstring(L, instance->specificProperty.c_str());
    return 1;
}

static int SpecificItemLoadFirst_get_desiredSpecificProperty(lua_State* L)
{
    SpecificItemLoadFirst* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpecificItemLoadFirst is nil");
    lua_pushboolean(L, instance->desiredSpecificProperty ? 1 : 0);
    return 1;
}

// --- Setters for SpecificItemLoadFirst ---
static int SpecificItemLoadFirst_set_baseTypes(lua_State* L)
{
    SpecificItemLoadFirst* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpecificItemLoadFirst is nil");
    instance->baseTypes = (itemType)luaL_checkinteger(L, 2);
    return 0;
}

static int SpecificItemLoadFirst_set_stateEnum(lua_State* L)
{
    SpecificItemLoadFirst* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpecificItemLoadFirst is nil");
    instance->stateEnum = (itemType)luaL_checkinteger(L, 2);
    return 0;
}

static int SpecificItemLoadFirst_set_specificProperty(lua_State* L)
{
    SpecificItemLoadFirst* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpecificItemLoadFirst is nil");
    instance->specificProperty = luaL_checkstring(L, 2);
    return 0;
}

static int SpecificItemLoadFirst_set_desiredSpecificProperty(lua_State* L)
{
    SpecificItemLoadFirst* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpecificItemLoadFirst is nil");
    instance->desiredSpecificProperty = lua_toboolean(L, 2) != 0;
    return 0;
}

int SpecificItemLoadFirstBinding::shouldSkip(lua_State* L)
{
    SpecificItemLoadFirst* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpecificItemLoadFirst is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    bool result = instance->shouldSkip(state);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SpecificItemLoadFirstBinding::_NV_shouldSkip(lua_State* L)
{
    SpecificItemLoadFirst* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpecificItemLoadFirst is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    bool result = instance->_NV_shouldSkip(state);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SpecificItemLoadFirstBinding::flip(lua_State* L)
{
    SpecificItemLoadFirst* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpecificItemLoadFirst is nil");

    instance->flip();
    return 0;
}

int SpecificItemLoadFirstBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int SpecificItemLoadFirstBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.SpecificItemLoadFirst object");
    return 1;
}

void SpecificItemLoadFirstBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SpecificItemLoadFirstBinding::gc },
        { "__tostring", SpecificItemLoadFirstBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "shouldSkip", SpecificItemLoadFirstBinding::shouldSkip },
        { "_NV_shouldSkip", SpecificItemLoadFirstBinding::_NV_shouldSkip },
        { "flip", SpecificItemLoadFirstBinding::flip },
        { 0, 0 }
    };

    registerClass(
        L, 
        SpecificItemLoadFirstBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SpecificItemLoadFirstBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "baseTypes", SpecificItemLoadFirst_get_baseTypes);
    registerGetter(L, "stateEnum", SpecificItemLoadFirst_get_stateEnum);
    registerGetter(L, "specificProperty", SpecificItemLoadFirst_get_specificProperty);
    registerGetter(L, "desiredSpecificProperty", SpecificItemLoadFirst_get_desiredSpecificProperty);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "baseTypes", SpecificItemLoadFirst_set_baseTypes);
    registerSetter(L, "stateEnum", SpecificItemLoadFirst_set_stateEnum);
    registerSetter(L, "specificProperty", SpecificItemLoadFirst_set_specificProperty);
    registerSetter(L, "desiredSpecificProperty", SpecificItemLoadFirst_set_desiredSpecificProperty);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua