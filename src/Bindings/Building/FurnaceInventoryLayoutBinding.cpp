#include "pch.h"
#include <kenshi/Building/FurnaceBuilding.h>
#include "FurnaceInventoryLayoutBinding.h"
#include "BuildInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static FurnaceInventoryLayout* getInstance(lua_State* L, int idx)
{
    return checkObject<FurnaceInventoryLayout>(L, idx, FurnaceInventoryLayoutBinding::getMetatableName());
}

// --- Getters for FurnaceInventoryLayout ---
// --- Setters for FurnaceInventoryLayout ---
// --- Methods for FurnaceInventoryLayout ---
int FurnaceInventoryLayoutBinding::_CONSTRUCTOR(lua_State* L)
{
    FurnaceInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceInventoryLayout is nil");

    std::string title = luaL_checkstring(L, 2);
    int ins = (int)luaL_checkinteger(L, 3);
    int outs = (int)luaL_checkinteger(L, 4);
    FurnaceInventoryLayout* result = instance->_CONSTRUCTOR(title, ins, outs);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int FurnaceInventoryLayoutBinding::_DESTRUCTOR(lua_State* L)
{
    FurnaceInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FurnaceInventoryLayout is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 13: void setupSections(...) - unsupported arg type
  line 14: void _NV_setupSections(...) - unsupported arg type
*/

int FurnaceInventoryLayoutBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int FurnaceInventoryLayoutBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FurnaceInventoryLayout object");
    return 1;
}

void FurnaceInventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FurnaceInventoryLayoutBinding::gc },
        { "__tostring", FurnaceInventoryLayoutBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", FurnaceInventoryLayoutBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", FurnaceInventoryLayoutBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        FurnaceInventoryLayoutBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FurnaceInventoryLayoutBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to BuildInventoryLayout
    // setMetatableParent(L, FurnaceInventoryLayoutBinding::getMetatableName(), BuildInventoryLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
