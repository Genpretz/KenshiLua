#include "pch.h"
#include <kenshi/gui/InventoryGUI.h>
#include "BackpackInventoryLayoutBinding.h"
#include "GenericFixedInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static BackpackInventoryLayout* getInstance(lua_State* L, int idx)
{
    return checkObject<BackpackInventoryLayout>(L, idx, BackpackInventoryLayoutBinding::getMetatableName());
}

// --- Getters for BackpackInventoryLayout ---
// --- Setters for BackpackInventoryLayout ---
int BackpackInventoryLayoutBinding::_CONSTRUCTOR(lua_State* L)
{
    BackpackInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BackpackInventoryLayout is nil");

    bool standAlone = lua_toboolean(L, 2) != 0;
    BackpackInventoryLayout* result = instance->_CONSTRUCTOR(standAlone);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int BackpackInventoryLayoutBinding::_DESTRUCTOR(lua_State* L)
{
    BackpackInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BackpackInventoryLayout is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 283: void setupSections(...) - unsupported arg type
  line 284: void _NV_setupSections(...) - unsupported arg type
*/

int BackpackInventoryLayoutBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int BackpackInventoryLayoutBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.BackpackInventoryLayout object");
    return 1;
}

void BackpackInventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BackpackInventoryLayoutBinding::gc },
        { "__tostring", BackpackInventoryLayoutBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", BackpackInventoryLayoutBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", BackpackInventoryLayoutBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        BackpackInventoryLayoutBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, BackpackInventoryLayoutBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to GenericFixedInventoryLayout
    setMetatableParent(L, BackpackInventoryLayoutBinding::getMetatableName(), GenericFixedInventoryLayoutBinding::getMetatableName());

        // Wire up inheritance
    setMetatableParent(L, BackpackInventoryLayoutBinding::getMetatableName(), GenericFixedInventoryLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua