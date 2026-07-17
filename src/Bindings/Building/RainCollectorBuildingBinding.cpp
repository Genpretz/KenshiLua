#include "pch.h"
#include <kenshi/Building/RainCollectorBuilding.h>
#include "RainCollectorBuildingBinding.h"
#include "ProductionBuildingBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static RainCollectorBuilding* getInstance(lua_State* L, int idx)
{
    return checkObject<RainCollectorBuilding>(L, idx, RainCollectorBuildingBinding::getMetatableName());
}

// --- Getters for RainCollectorBuilding ---
// --- Setters for RainCollectorBuilding ---
// --- Methods for RainCollectorBuilding ---
int RainCollectorBuildingBinding::calculateEfficiencyMult(lua_State* L)
{
    RainCollectorBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RainCollectorBuilding is nil");

    float result = instance->calculateEfficiencyMult();
    lua_pushnumber(L, result);
    return 1;
}

int RainCollectorBuildingBinding::_NV_calculateEfficiencyMult(lua_State* L)
{
    RainCollectorBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RainCollectorBuilding is nil");

    float result = instance->_NV_calculateEfficiencyMult();
    lua_pushnumber(L, result);
    return 1;
}

int RainCollectorBuildingBinding::getRainAmount(lua_State* L)
{
    RainCollectorBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RainCollectorBuilding is nil");

    float result = instance->getRainAmount();
    lua_pushnumber(L, result);
    return 1;
}

int RainCollectorBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    RainCollectorBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RainCollectorBuilding is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 11: RainCollectorBuilding* _CONSTRUCTOR(...) - unsupported arg type
  line 14: void getGUIState(...) - unsupported arg type
  line 15: void _NV_getGUIState(...) - unsupported arg type
  line 16: void getGUIToolTipForGroundResourceEfficiency(...) - unsupported arg type
  line 17: void _NV_getGUIToolTipForGroundResourceEfficiency(...) - unsupported arg type
*/

int RainCollectorBuildingBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int RainCollectorBuildingBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.RainCollectorBuilding object");
    return 1;
}

void RainCollectorBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RainCollectorBuildingBinding::gc },
        { "__tostring", RainCollectorBuildingBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "calculateEfficiencyMult", RainCollectorBuildingBinding::calculateEfficiencyMult },
        { "_NV_calculateEfficiencyMult", RainCollectorBuildingBinding::_NV_calculateEfficiencyMult },
        { "getRainAmount", RainCollectorBuildingBinding::getRainAmount },
        { "_DESTRUCTOR", RainCollectorBuildingBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        RainCollectorBuildingBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, RainCollectorBuildingBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ProductionBuilding
    setMetatableParent(L, RainCollectorBuildingBinding::getMetatableName(), ProductionBuildingBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua