#include "pch.h"
#include "mygui\common\baselayout\BaseLayout.h"
#include "BaseLayoutBinding.h"
#include "Lua/BindingHelpers.h"

namespace wraps
{

static wraps::BaseLayout* getInstance(lua_State* L, int idx)
{
    return KenshiLua::checkObject<wraps::BaseLayout>(L, idx, BaseLayoutBinding::getMetatableName());
}

// --- Getters for BaseLayout ---
static int BaseLayout_get_mMainWidget(lua_State* L)
{
    wraps::BaseLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BaseLayout is nil");
    lua_pushlightuserdata(L, (void*)instance->mMainWidget);
    return 1;
}

static int BaseLayout_get_mPrefix(lua_State* L)
{
    wraps::BaseLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BaseLayout is nil");
    lua_pushstring(L, instance->mPrefix.c_str());
    return 1;
}

static int BaseLayout_get_mLayoutName(lua_State* L)
{
    wraps::BaseLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BaseLayout is nil");
    lua_pushstring(L, instance->mLayoutName.c_str());
    return 1;
}

// --- Setters for BaseLayout ---
static int BaseLayout_set_mPrefix(lua_State* L)
{
    wraps::BaseLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BaseLayout is nil");
    instance->mPrefix = luaL_checkstring(L, 2);
    return 0;
}

static int BaseLayout_set_mLayoutName(lua_State* L)
{
    wraps::BaseLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BaseLayout is nil");
    instance->mLayoutName = luaL_checkstring(L, 2);
    return 0;
}



/*
Skipped properties needing manual binding:
  line 258: mListWindowRoot (MyGUI::VectorWidgetPtr) - unsupported type
  line 260: mListBase (VectorBasePtr) - unsupported type
*/

int BaseLayoutBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int BaseLayoutBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.BaseLayout object");
    return 1;
}

void BaseLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BaseLayoutBinding::gc },
        { "__tostring", BaseLayoutBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    KenshiLua::registerClass(
        L, 
        BaseLayoutBinding::getMetatableName(), 
        meta, 
        methods, 
        KenshiLua::genericPropertyIndex, 
        KenshiLua::genericPropertyNewIndex
    );

    luaL_getmetatable(L, BaseLayoutBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, BaseLayout_get_mMainWidget);
    lua_setfield(L, -2, "mMainWidget");
    lua_pushcfunction(L, BaseLayout_get_mPrefix);
    lua_setfield(L, -2, "mPrefix");
    lua_pushcfunction(L, BaseLayout_get_mLayoutName);
    lua_setfield(L, -2, "mLayoutName");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, BaseLayout_set_mPrefix);
    lua_setfield(L, -2, "mPrefix");
    lua_pushcfunction(L, BaseLayout_set_mLayoutName);
    lua_setfield(L, -2, "mLayoutName");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace wraps