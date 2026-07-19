#include "pch.h"
#include "Bindings/RobotLimbItemBinding.h"
#include "Bindings/ItemBinding.h"
#include "Lua/BindingHelpers.h"

// Forward declare RobotLimbItem
class RobotLimbItem;

namespace KenshiLua
{

int RobotLimbItemBinding::gc(lua_State* L)
{
    return 0;
}

int RobotLimbItemBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.RobotLimbItem object");
    return 1;
}

void RobotLimbItemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RobotLimbItemBinding::gc },
        { "__tostring", RobotLimbItemBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        RobotLimbItemBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    // Setup setters/getters tables
    luaL_getmetatable(L, RobotLimbItemBinding::getMetatableName());
    lua_newtable(L); // getters
    lua_setfield(L, -2, "__getters");
    lua_newtable(L); // setters
    lua_setfield(L, -2, "__setters");
    lua_pop(L, 1);

    // RobotLimbItem inherits from Item
    setMetatableParent(L, RobotLimbItemBinding::getMetatableName(), ItemBinding::getMetatableName());
}

} // namespace KenshiLua
