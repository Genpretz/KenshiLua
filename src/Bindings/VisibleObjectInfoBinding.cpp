#include "pch.h"
#include "kenshi\SensoryData.h"
#include "VisibleObjectInfoBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static VisibleObjectInfo* getInstance(lua_State* L, int idx)
{
    return checkObject<VisibleObjectInfo>(L, idx, VisibleObjectInfoBinding::getMetatableName());
}

// --- Getters for VisibleObjectInfo ---
static int VisibleObjectInfo_get_handle(lua_State* L)
{
    VisibleObjectInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "VisibleObjectInfo is nil");
    return HandBinding::push(L, instance->handle);
}

static int VisibleObjectInfo_get_range(lua_State* L)
{
    VisibleObjectInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "VisibleObjectInfo is nil");
    lua_pushnumber(L, instance->range);
    return 1;
}

static int VisibleObjectInfo_get_isEnemy(lua_State* L)
{
    VisibleObjectInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "VisibleObjectInfo is nil");
    lua_pushboolean(L, instance->isEnemy ? 1 : 0);
    return 1;
}

// --- Setters for VisibleObjectInfo ---
static int VisibleObjectInfo_set_handle(lua_State* L)
{
    VisibleObjectInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "VisibleObjectInfo is nil");
    instance->handle = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int VisibleObjectInfo_set_range(lua_State* L)
{
    VisibleObjectInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "VisibleObjectInfo is nil");
    instance->range = (float)luaL_checknumber(L, 2);
    return 0;
}

static int VisibleObjectInfo_set_isEnemy(lua_State* L)
{
    VisibleObjectInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "VisibleObjectInfo is nil");
    instance->isEnemy = lua_toboolean(L, 2) != 0;
    return 0;
}

/*
Skipped methods needing manual binding:
  line 93: VisibleObjectInfo& operator=(...) - operator
*/

int VisibleObjectInfoBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int VisibleObjectInfoBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.VisibleObjectInfo object");
    return 1;
}

void VisibleObjectInfoBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       VisibleObjectInfoBinding::gc },
        { "__tostring", VisibleObjectInfoBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        VisibleObjectInfoBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, VisibleObjectInfoBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "handle", VisibleObjectInfo_get_handle);
    registerGetter(L, "range", VisibleObjectInfo_get_range);
    registerGetter(L, "isEnemy", VisibleObjectInfo_get_isEnemy);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "handle", VisibleObjectInfo_set_handle);
    registerSetter(L, "range", VisibleObjectInfo_set_range);
    registerSetter(L, "isEnemy", VisibleObjectInfo_set_isEnemy);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua