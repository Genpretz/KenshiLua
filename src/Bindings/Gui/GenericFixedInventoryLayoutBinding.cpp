#include "pch.h"
#include "kenshi\gui\InventoryGUI.h"
#include "GenericFixedInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/InventoryLayoutBinding.h"

namespace KenshiLua
{

static GenericFixedInventoryLayout* getInstance(lua_State* L, int idx)
{
    return checkObject<GenericFixedInventoryLayout>(L, idx, GenericFixedInventoryLayoutBinding::getMetatableName());
}

// --- Getters for GenericFixedInventoryLayout ---
// --- Setters for GenericFixedInventoryLayout ---
int GenericFixedInventoryLayoutBinding::setSize(lua_State* L)
{
    GenericFixedInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GenericFixedInventoryLayout is nil");

    int slotsW = (int)luaL_checkinteger(L, 2);
    int slotsH = (int)luaL_checkinteger(L, 3);
    instance->setSize(slotsW, slotsH);
    return 0;
}

int GenericFixedInventoryLayoutBinding::_NV_setSize(lua_State* L)
{
    GenericFixedInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GenericFixedInventoryLayout is nil");

    int slotsW = (int)luaL_checkinteger(L, 2);
    int slotsH = (int)luaL_checkinteger(L, 3);
    instance->_NV_setSize(slotsW, slotsH);
    return 0;
}

int GenericFixedInventoryLayoutBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int GenericFixedInventoryLayoutBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.GenericFixedInventoryLayout object");
    return 1;
}

void GenericFixedInventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GenericFixedInventoryLayoutBinding::gc },
        { "__tostring", GenericFixedInventoryLayoutBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setSize", GenericFixedInventoryLayoutBinding::setSize },
        { "_NV_setSize", GenericFixedInventoryLayoutBinding::_NV_setSize },
        { 0, 0 }
    };

    registerClass(
        L, 
        GenericFixedInventoryLayoutBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, GenericFixedInventoryLayoutBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to InventoryLayout
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, GenericFixedInventoryLayoutBinding::getMetatableName(), InventoryLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua