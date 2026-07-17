#include "pch.h"
#include <kenshi/gui/BuildModeWindow.h>
#include "BuildingCategoryBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
    typedef BuildModeWindow::BuildingCategory BuildingCategory;

static BuildingCategory* getInstance(lua_State* L, int idx)
{
    return checkObject<BuildingCategory>(L, idx, BuildingCategoryBinding::getMetatableName());
}

// --- Getters for BuildingCategory ---
static int BuildingCategory_get_name(lua_State* L)
{
    BuildingCategory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildingCategory is nil");
    lua_pushstring(L, instance->name.c_str());
    return 1;
}

// --- Setters for BuildingCategory ---
static int BuildingCategory_set_name(lua_State* L)
{
    BuildingCategory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildingCategory is nil");
    instance->name = luaL_checkstring(L, 2);
    return 0;
}

int BuildingCategoryBinding::_DESTRUCTOR(lua_State* L)
{
    BuildingCategory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildingCategory is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 35: bool operator<(...) - operator
  line 37: BuildingCategory* _CONSTRUCTOR(...) - overloaded method
  line 39: BuildingCategory* _CONSTRUCTOR(...) - overloaded method
  line 42: BuildModeWindow::BuildingCategory& operator=(...) - operator
*/

/*
Skipped properties needing manual binding:
  line 34: buildingGroups (Ogre::vector<BuildModeWindow::BuildingGroup>::type) - unsupported type
*/

int BuildingCategoryBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int BuildingCategoryBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.BuildingCategory object");
    return 1;
}

void BuildingCategoryBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BuildingCategoryBinding::gc },
        { "__tostring", BuildingCategoryBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", BuildingCategoryBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        BuildingCategoryBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, BuildingCategoryBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, BuildingCategory_get_name);
    lua_setfield(L, -2, "name");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, BuildingCategory_set_name);
    lua_setfield(L, -2, "name");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua