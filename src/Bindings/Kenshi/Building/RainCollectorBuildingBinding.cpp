#include "pch.h"
#include <kenshi/Building/RainCollectorBuilding.h>
#include "RainCollectorBuildingBinding.h"
#include "ProductionBuildingBinding.h"
#include "Bindings/Kenshi/Gui/DatapanelGUIBinding.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"
#include "Bindings/Kenshi/Util/StringPairBinding.h"
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

int RainCollectorBuildingBinding::getGUIState(lua_State* L)
{
    RainCollectorBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RainCollectorBuilding is nil");
    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIState(datapanel, category);
    return 0;
}

int RainCollectorBuildingBinding::_NV_getGUIState(lua_State* L)
{
    RainCollectorBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RainCollectorBuilding is nil");
    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIState(datapanel, category);
    return 0;
}

int RainCollectorBuildingBinding::getGUIToolTipForGroundResourceEfficiency(lua_State* L)
{
    RainCollectorBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RainCollectorBuilding is nil");
    lektor<StringPair>* out = LektorValueBinding<StringPair>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to getGUIToolTipForGroundResourceEfficiency must be lektor<StringPair>");
    instance->getGUIToolTipForGroundResourceEfficiency(*out);
    return 0;
}

int RainCollectorBuildingBinding::_NV_getGUIToolTipForGroundResourceEfficiency(lua_State* L)
{
    RainCollectorBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RainCollectorBuilding is nil");
    lektor<StringPair>* out = LektorValueBinding<StringPair>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to _NV_getGUIToolTipForGroundResourceEfficiency must be lektor<StringPair>");
    instance->_NV_getGUIToolTipForGroundResourceEfficiency(*out);
    return 0;
}

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
        { "getGUIState", RainCollectorBuildingBinding::getGUIState },
        { "_NV_getGUIState", RainCollectorBuildingBinding::_NV_getGUIState },
        { "getGUIToolTipForGroundResourceEfficiency", RainCollectorBuildingBinding::getGUIToolTipForGroundResourceEfficiency },
        { "_NV_getGUIToolTipForGroundResourceEfficiency", RainCollectorBuildingBinding::_NV_getGUIToolTipForGroundResourceEfficiency },
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
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, RainCollectorBuildingBinding::getMetatableName(), ProductionBuildingBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua