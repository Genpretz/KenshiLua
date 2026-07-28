#include "pch.h"
#include <kenshi/FoliageSystem.h>
#include "TreeDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/BuildingBinding.h"

namespace KenshiLua
{

typedef FoliageSystem::TreeData TreeData;

static TreeData* getInstance(lua_State* L, int idx)
{
    return checkObject<TreeData>(L, idx, TreeDataBinding::getMetatableName());
}

// --- Getters for TreeData ---
static int TreeData_get_position(lua_State* L)
{
    TreeData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TreeData is nil");
    pushVector3(L, instance->position);
    return 1;
}

static int TreeData_get_scale(lua_State* L)
{
    TreeData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TreeData is nil");
    lua_pushnumber(L, instance->scale);
    return 1;
}

static int TreeData_get_target(lua_State* L)
{
    TreeData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TreeData is nil");
    lua_pushlightuserdata(L, (void*)instance->target);
    return 1;
}

static int TreeData_get_building(lua_State* L)
{
    TreeData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TreeData is nil");
    return pushObject<Building>(L, instance->building, BuildingBinding::getMetatableName());
}

// --- Setters for TreeData ---
static int TreeData_set_position(lua_State* L)
{
    TreeData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TreeData is nil");
    readVector3(L, 2, instance->position);
    return 0;
}

static int TreeData_set_scale(lua_State* L)
{
    TreeData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TreeData is nil");
    instance->scale = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TreeData_set_building(lua_State* L)
{
    TreeData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TreeData is nil");
    instance->building = lua_isnoneornil(L, 2) ? nullptr : checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    return 0;
}

int TreeDataBinding::_CONSTRUCTOR(lua_State* L)
{
    TreeData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TreeData is nil");

    TreeData* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TreeDataBinding::_DESTRUCTOR(lua_State* L)
{
    TreeData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TreeData is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 107: FoliageSystem::TreeData& operator=(...) - operator
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - TreeData_get_target: Forests::TreeLoader3D* (unbound pointer)
  - TreeDataBinding::_CONSTRUCTOR: TreeData* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 98: rotation (Ogre::Degree) - unsupported type
  line 102: transform (Ogre::Matrix4) - unsupported type
*/

int TreeDataBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TreeDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TreeData object");
    return 1;
}

void TreeDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TreeDataBinding::gc },
        { "__tostring", TreeDataBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", TreeDataBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", TreeDataBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        TreeDataBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TreeDataBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "position", TreeData_get_position);
    registerGetter(L, "scale", TreeData_get_scale);
    registerGetter(L, "target", TreeData_get_target);
    registerGetter(L, "building", TreeData_get_building);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "position", TreeData_set_position);
    registerSetter(L, "scale", TreeData_set_scale);
    registerSetter(L, "building", TreeData_set_building);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, TreeDataBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua