#include "pch.h"
#include <kenshi/Building/ResearchBuilding.h>
#include "ResearchBuildingInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/GenericInventoryLayoutBinding.h"

namespace KenshiLua
{

static ResearchBuildingInventoryLayout* getInstance(lua_State* L, int idx)
{
    return checkObject<ResearchBuildingInventoryLayout>(L, idx, ResearchBuildingInventoryLayoutBinding::getMetatableName());
}

// --- Getters for ResearchBuildingInventoryLayout ---
static int ResearchBuildingInventoryLayout_get_researchButton(lua_State* L)
{
    ResearchBuildingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchBuildingInventoryLayout is nil");
    lua_pushlightuserdata(L, (void*)instance->researchButton);
    return 1;
}

// --- Setters for ResearchBuildingInventoryLayout ---
static int ResearchBuildingInventoryLayout_set_researchButton(lua_State* L)
{
    ResearchBuildingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchBuildingInventoryLayout is nil");
    return luaL_error(L, "Read-only or unsupported setter type for researchButton");
}

int ResearchBuildingInventoryLayoutBinding::_CONSTRUCTOR(lua_State* L)
{
    ResearchBuildingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchBuildingInventoryLayout is nil");

    ResearchBuildingInventoryLayout* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ResearchBuildingInventoryLayoutBinding::getResearchButton(lua_State* L)
{
    ResearchBuildingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchBuildingInventoryLayout is nil");

    MyGUI::Widget* result = instance->getResearchButton();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ResearchBuildingInventoryLayoutBinding::_DESTRUCTOR(lua_State* L)
{
    ResearchBuildingInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchBuildingInventoryLayout is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 14: void setupSections(...) - unsupported arg type
  line 15: void _NV_setupSections(...) - unsupported arg type
*/

int ResearchBuildingInventoryLayoutBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ResearchBuildingInventoryLayoutBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ResearchBuildingInventoryLayout object");
    return 1;
}

void ResearchBuildingInventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ResearchBuildingInventoryLayoutBinding::gc },
        { "__tostring", ResearchBuildingInventoryLayoutBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", ResearchBuildingInventoryLayoutBinding::_CONSTRUCTOR },
        { "getResearchButton", ResearchBuildingInventoryLayoutBinding::getResearchButton },
        { "_DESTRUCTOR", ResearchBuildingInventoryLayoutBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        ResearchBuildingInventoryLayoutBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ResearchBuildingInventoryLayoutBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, ResearchBuildingInventoryLayout_get_researchButton);
    lua_setfield(L, -2, "researchButton");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, ResearchBuildingInventoryLayout_set_researchButton);
    lua_setfield(L, -2, "researchButton");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to GenericInventoryLayout
    setMetatableParent(L, ResearchBuildingInventoryLayoutBinding::getMetatableName(), GenericInventoryLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua