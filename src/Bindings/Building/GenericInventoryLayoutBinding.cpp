#include "pch.h"
#include "Bindings/Gui/InventoryLayoutBinding.h"

#include <kenshi/Building/UseableStuff.h>
#include "GenericInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/MyGuiBinding.h"
#include <MyGUI.h>

namespace KenshiLua
{

static GenericInventoryLayout* getInstance(lua_State* L, int idx)
{
    return checkObject<GenericInventoryLayout>(L, idx, GenericInventoryLayoutBinding::getMetatableName());
}

// --- Getters for GenericInventoryLayout ---
static int GenericInventoryLayout_get_arrangeButton(lua_State* L)
{
    GenericInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GenericInventoryLayout is nil");
    return pushObject<MyGUI::Widget>(L, instance->arrangeButton, MyGuiBinding::getMetatableName());
}

// --- Setters for GenericInventoryLayout ---
static int GenericInventoryLayout_set_arrangeButton(lua_State* L)
{
    GenericInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GenericInventoryLayout is nil");
    instance->arrangeButton = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    return 0;
}

int GenericInventoryLayoutBinding::setSize(lua_State* L)
{
    GenericInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GenericInventoryLayout is nil");

    int slotsW = (int)luaL_checkinteger(L, 2);
    int slotsH = (int)luaL_checkinteger(L, 3);
    bool hasArrange = lua_toboolean(L, 4) != 0;
    bool hasType = lua_toboolean(L, 5) != 0;
    instance->setSize(slotsW, slotsH, hasArrange, hasType);
    return 0;
}

int GenericInventoryLayoutBinding::_NV_setSize(lua_State* L)
{
    GenericInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GenericInventoryLayout is nil");

    int slotsW = (int)luaL_checkinteger(L, 2);
    int slotsH = (int)luaL_checkinteger(L, 3);
    bool hasArrange = lua_toboolean(L, 4) != 0;
    bool hasType = lua_toboolean(L, 5) != 0;
    instance->_NV_setSize(slotsW, slotsH, hasArrange, hasType);
    return 0;
}

int GenericInventoryLayoutBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int GenericInventoryLayoutBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.GenericInventoryLayout object");
    return 1;
}

void GenericInventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GenericInventoryLayoutBinding::gc },
        { "__tostring", GenericInventoryLayoutBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setSize", GenericInventoryLayoutBinding::setSize },
        { "_NV_setSize", GenericInventoryLayoutBinding::_NV_setSize },
        { 0, 0 }
    };

    registerClass(
        L, 
        GenericInventoryLayoutBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, GenericInventoryLayoutBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, GenericInventoryLayout_get_arrangeButton);
    lua_setfield(L, -2, "arrangeButton");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, GenericInventoryLayout_set_arrangeButton);
    lua_setfield(L, -2, "arrangeButton");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to InventoryLayout
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, GenericInventoryLayoutBinding::getMetatableName(), InventoryLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua