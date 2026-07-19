#include "pch.h"
class CraftingItem {};
#include <kenshi/Building/CraftingBuilding.h>
#include "CraftingInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/BuildInventoryLayoutBinding.h"

namespace KenshiLua
{

static CraftingInventoryLayout* getInstance(lua_State* L, int idx)
{
    return checkObject<CraftingInventoryLayout>(L, idx, CraftingInventoryLayoutBinding::getMetatableName());
}

// --- Getters for CraftingInventoryLayout ---
static int CraftingInventoryLayout_get_queueBtn(lua_State* L)
{
    CraftingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingInventoryLayout is nil");
    lua_pushlightuserdata(L, (void*)instance->queueBtn);
    return 1;
}

static int CraftingInventoryLayout_get_craftingName(lua_State* L)
{
    CraftingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingInventoryLayout is nil");
    lua_pushlightuserdata(L, (void*)instance->craftingName);
    return 1;
}

static int CraftingInventoryLayout_get_outputType(lua_State* L)
{
    CraftingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingInventoryLayout is nil");
    lua_pushinteger(L, (lua_Integer)instance->outputType);
    return 1;
}

// --- Setters for CraftingInventoryLayout ---
static int CraftingInventoryLayout_set_queueBtn(lua_State* L)
{
    CraftingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingInventoryLayout is nil");
    return luaL_error(L, "Read-only or unsupported setter type for queueBtn");
}

static int CraftingInventoryLayout_set_craftingName(lua_State* L)
{
    CraftingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingInventoryLayout is nil");
    return luaL_error(L, "Read-only or unsupported setter type for craftingName");
}

static int CraftingInventoryLayout_set_outputType(lua_State* L)
{
    CraftingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingInventoryLayout is nil");
    instance->outputType = (itemType)luaL_checkinteger(L, 2);
    return 0;
}

int CraftingInventoryLayoutBinding::_CONSTRUCTOR(lua_State* L)
{
    CraftingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingInventoryLayout is nil");

    std::string title = luaL_checkstring(L, 2);
    int ins = (int)luaL_checkinteger(L, 3);
    int outs = (int)luaL_checkinteger(L, 4);
    CraftingInventoryLayout* result = instance->_CONSTRUCTOR(title, ins, outs);
    return pushObject<CraftingInventoryLayout>(L, result, CraftingInventoryLayoutBinding::getMetatableName());
}

int CraftingInventoryLayoutBinding::refresh(lua_State* L)
{
    CraftingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingInventoryLayout is nil");

    instance->refresh();
    return 0;
}

int CraftingInventoryLayoutBinding::setOutputType(lua_State* L)
{
    CraftingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingInventoryLayout is nil");

    itemType type = (itemType)luaL_checkinteger(L, 2);
    instance->setOutputType(type);
    return 0;
}

int CraftingInventoryLayoutBinding::setCraftingName(lua_State* L)
{
    CraftingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingInventoryLayout is nil");

    std::string name = luaL_checkstring(L, 2);
    instance->setCraftingName(name);
    return 0;
}

int CraftingInventoryLayoutBinding::getQueueButton(lua_State* L)
{
    CraftingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingInventoryLayout is nil");

    MyGUI::Button* result = instance->getQueueButton();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int CraftingInventoryLayoutBinding::_DESTRUCTOR(lua_State* L)
{
    CraftingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingInventoryLayout is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 29: void setupSections(...) - unsupported arg type
  line 30: void _NV_setupSections(...) - unsupported arg type
*/

int CraftingInventoryLayoutBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int CraftingInventoryLayoutBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CraftingInventoryLayout object");
    return 1;
}

void CraftingInventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CraftingInventoryLayoutBinding::gc },
        { "__tostring", CraftingInventoryLayoutBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", CraftingInventoryLayoutBinding::_CONSTRUCTOR },
        { "refresh", CraftingInventoryLayoutBinding::refresh },
        { "setOutputType", CraftingInventoryLayoutBinding::setOutputType },
        { "setCraftingName", CraftingInventoryLayoutBinding::setCraftingName },
        { "getQueueButton", CraftingInventoryLayoutBinding::getQueueButton },
        { "_DESTRUCTOR", CraftingInventoryLayoutBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        CraftingInventoryLayoutBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CraftingInventoryLayoutBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, CraftingInventoryLayout_get_queueBtn);
    lua_setfield(L, -2, "queueBtn");
    lua_pushcfunction(L, CraftingInventoryLayout_get_craftingName);
    lua_setfield(L, -2, "craftingName");
    lua_pushcfunction(L, CraftingInventoryLayout_get_outputType);
    lua_setfield(L, -2, "outputType");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, CraftingInventoryLayout_set_queueBtn);
    lua_setfield(L, -2, "queueBtn");
    lua_pushcfunction(L, CraftingInventoryLayout_set_craftingName);
    lua_setfield(L, -2, "craftingName");
    lua_pushcfunction(L, CraftingInventoryLayout_set_outputType);
    lua_setfield(L, -2, "outputType");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to BuildInventoryLayout
    // setMetatableParent(L, CraftingInventoryLayoutBinding::getMetatableName(), BuildInventoryLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
