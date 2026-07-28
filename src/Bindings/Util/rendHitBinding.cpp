#include "pch.h"
#include "kenshi\util\UtilityT.h"
#include "rendHitBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static rendHit* getInstance(lua_State* L, int idx)
{
    return checkObject<rendHit>(L, idx, rendHitBinding::getMetatableName());
}

// --- Getters for rendHit ---
static int rendHit_get_data(lua_State* L)
{
    rendHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "rendHit is nil");
    lua_pushinteger(L, instance->data);
    return 1;
}

static int rendHit_get_hit(lua_State* L)
{
    rendHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "rendHit is nil");
    pushVector3(L, instance->hit);
    return 1;
}

// --- Setters for rendHit ---
static int rendHit_set_data(lua_State* L)
{
    rendHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "rendHit is nil");
    instance->data = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int rendHit_set_hit(lua_State* L)
{
    rendHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "rendHit is nil");
    readVector3(L, 2, instance->hit);
    return 0;
}

int rendHitBinding::_CONSTRUCTOR(lua_State* L)
{
    rendHit* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "rendHit is nil");

    rendHit* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - rendHitBinding::_CONSTRUCTOR: rendHit* (unbound pointer)
*/

int rendHitBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int rendHitBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.rendHit object");
    return 1;
}

void rendHitBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       rendHitBinding::gc },
        { "__tostring", rendHitBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", rendHitBinding::_CONSTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        rendHitBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, rendHitBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "data", rendHit_get_data);
    registerGetter(L, "hit", rendHit_get_hit);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "data", rendHit_set_data);
    registerSetter(L, "hit", rendHit_set_hit);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua