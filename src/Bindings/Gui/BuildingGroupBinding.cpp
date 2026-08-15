#include "pch.h"
#include "kenshi\gui\BuildModeWindow.h"
#include "BuildingGroupBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

typedef BuildModeWindow::BuildingGroup BuildingGroup;

static BuildingGroup* getInstance(lua_State* L, int idx)
{
    return checkObject<BuildingGroup>(L, idx, BuildingGroupBinding::getMetatableName());
}

// --- Getters for BuildingGroup ---
static int BuildingGroup_get_name(lua_State* L)
{
    BuildingGroup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildingGroup is nil");
    lua_pushstring(L, instance->name.c_str());
    return 1;
}

// --- Setters for BuildingGroup ---
static int BuildingGroup_set_name(lua_State* L)
{
    BuildingGroup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BuildingGroup is nil");
    instance->name = luaL_checkstring(L, 2);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 20: bool operator<(...) - operator
  line 27: BuildModeWindow::BuildingGroup& operator=(...) - operator
*/

/*
Skipped properties needing manual binding:
  line 19: buildings (Ogre::vector<GameData*>::type) - unsupported type
*/

int BuildingGroupBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int BuildingGroupBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.BuildingGroup object");
    return 1;
}

void BuildingGroupBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BuildingGroupBinding::gc },
        { "__tostring", BuildingGroupBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        BuildingGroupBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, BuildingGroupBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "name", BuildingGroup_get_name);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "name", BuildingGroup_set_name);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua