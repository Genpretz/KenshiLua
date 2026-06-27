#include "pch.h"
#include <kenshi/Building/UseableStuff.h>
#include "GenericInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"

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
    lua_pushlightuserdata(L, (void*)instance->arrangeButton);
    return 1;
}

// --- Setters for GenericInventoryLayout ---
static int GenericInventoryLayout_set_arrangeButton(lua_State* L)
{
    GenericInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GenericInventoryLayout is nil");
    return luaL_error(L, "Read-only or unsupported setter type for arrangeButton");
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

int GenericInventoryLayoutBinding::_DESTRUCTOR(lua_State* L)
{
    GenericInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GenericInventoryLayout is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 11: GenericInventoryLayout* _CONSTRUCTOR(...) - overloaded method
  line 13: GenericInventoryLayout* _CONSTRUCTOR(...) - overloaded method
*/

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
        { "_DESTRUCTOR", GenericInventoryLayoutBinding::_DESTRUCTOR },
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
    // // setMetatableParent(L, GenericInventoryLayoutBinding::getMetatableName(), InventoryLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua