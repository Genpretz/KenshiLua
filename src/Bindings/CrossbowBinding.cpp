#include "pch.h"
#include "kenshi\Gear.h"
#include "CrossbowBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static Crossbow* getB(lua_State* L, int idx)
{
    return checkObject<Crossbow>(L, idx, CrossbowBinding::getMetatableName());
}

// --- Getters for Crossbow ---
static int Crossbow_get_gunClass(lua_State* L)
{
    Crossbow* b = getB(L, 1);
    if (!b) return luaL_error(L, "Crossbow is nil");
    // TODO: Unsupported type for gunClass (GunClass*)
    return luaL_error(L, "Unsupported property 'gunClass' (type: GunClass*)");
}

// --- Setters for Crossbow ---
static int Crossbow_set_gunClass(lua_State* L)
{
    Crossbow* b = getB(L, 1);
    if (!b) return luaL_error(L, "Crossbow is nil");
    return luaL_error(L, "Read-only or unsupported setter type for gunClass");
}

// --- Methods for Crossbow ---
int CrossbowBinding::isCrossbow(lua_State* L)
{
    Crossbow* b = getB(L, 1);
    if (!b) return luaL_error(L, "Crossbow is nil");

    Crossbow* result = b->isCrossbow();
    return pushObject<Crossbow>(L, result, CrossbowBinding::getMetatableName());
}

int CrossbowBinding::_NV_isCrossbow(lua_State* L)
{
    Crossbow* b = getB(L, 1);
    if (!b) return luaL_error(L, "Crossbow is nil");

    Crossbow* result = b->_NV_isCrossbow();
    return pushObject<Crossbow>(L, result, CrossbowBinding::getMetatableName());
}

int CrossbowBinding::getClassType(lua_State* L)
{
    Crossbow* b = getB(L, 1);
    if (!b) return luaL_error(L, "Crossbow is nil");

    itemType result = b->getClassType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CrossbowBinding::_NV_getClassType(lua_State* L)
{
    Crossbow* b = getB(L, 1);
    if (!b) return luaL_error(L, "Crossbow is nil");

    itemType result = b->_NV_getClassType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CrossbowBinding::getCraftMaterialMult(lua_State* L)
{
    Crossbow* b = getB(L, 1);
    if (!b) return luaL_error(L, "Crossbow is nil");

    float result = b->getCraftMaterialMult();
    lua_pushnumber(L, result);
    return 1;
}

int CrossbowBinding::_NV_getCraftMaterialMult(lua_State* L)
{
    Crossbow* b = getB(L, 1);
    if (!b) return luaL_error(L, "Crossbow is nil");

    float result = b->_NV_getCraftMaterialMult();
    lua_pushnumber(L, result);
    return 1;
}

int CrossbowBinding::getCraftTime(lua_State* L)
{
    Crossbow* b = getB(L, 1);
    if (!b) return luaL_error(L, "Crossbow is nil");

    float result = b->getCraftTime();
    lua_pushnumber(L, result);
    return 1;
}

int CrossbowBinding::_NV_getCraftTime(lua_State* L)
{
    Crossbow* b = getB(L, 1);
    if (!b) return luaL_error(L, "Crossbow is nil");

    float result = b->_NV_getCraftTime();
    lua_pushnumber(L, result);
    return 1;
}

int CrossbowBinding::getRangeInUnits(lua_State* L)
{
    Crossbow* b = getB(L, 1);
    if (!b) return luaL_error(L, "Crossbow is nil");

    float result = b->getRangeInUnits();
    lua_pushnumber(L, result);
    return 1;
}

int CrossbowBinding::getEquipPositionOffset(lua_State* L)
{
    Crossbow* b = getB(L, 1);
    if (!b) return luaL_error(L, "Crossbow is nil");

    float result = b->getEquipPositionOffset();
    lua_pushnumber(L, result);
    return 1;
}

int CrossbowBinding::destroyItemEntityCallback_Equipping(lua_State* L)
{
    Crossbow* b = getB(L, 1);
    if (!b) return luaL_error(L, "Crossbow is nil");

    b->destroyItemEntityCallback_Equipping();
    return 0;
}

int CrossbowBinding::_NV_destroyItemEntityCallback_Equipping(lua_State* L)
{
    Crossbow* b = getB(L, 1);
    if (!b) return luaL_error(L, "Crossbow is nil");

    b->_NV_destroyItemEntityCallback_Equipping();
    return 0;
}

int CrossbowBinding::setVisible(lua_State* L)
{
    Crossbow* b = getB(L, 1);
    if (!b) return luaL_error(L, "Crossbow is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->setVisible(on);
    return 0;
}

int CrossbowBinding::_NV_setVisible(lua_State* L)
{
    Crossbow* b = getB(L, 1);
    if (!b) return luaL_error(L, "Crossbow is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->_NV_setVisible(on);
    return 0;
}

int CrossbowBinding::_DESTRUCTOR(lua_State* L)
{
    Crossbow* b = getB(L, 1);
    if (!b) return luaL_error(L, "Crossbow is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 117: Crossbow* _CONSTRUCTOR(...) - unsupported arg type
  line 130: void getTooltipData1(...) - unsupported arg type
  line 131: void _NV_getTooltipData1(...) - unsupported arg type
  line 132: void getTooltipData2(...) - unsupported arg type
  line 133: void _NV_getTooltipData2(...) - unsupported arg type
  line 134: void createItemEntityCallback_Equipping(...) - unsupported arg type
  line 135: void _NV_createItemEntityCallback_Equipping(...) - unsupported arg type
*/

int CrossbowBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int CrossbowBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Crossbow object");
    return 1;
}

void CrossbowBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CrossbowBinding::gc },
        { "__tostring", CrossbowBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "isCrossbow", CrossbowBinding::isCrossbow },
        { "_NV_isCrossbow", CrossbowBinding::_NV_isCrossbow },
        { "getClassType", CrossbowBinding::getClassType },
        { "_NV_getClassType", CrossbowBinding::_NV_getClassType },
        { "getCraftMaterialMult", CrossbowBinding::getCraftMaterialMult },
        { "_NV_getCraftMaterialMult", CrossbowBinding::_NV_getCraftMaterialMult },
        { "getCraftTime", CrossbowBinding::getCraftTime },
        { "_NV_getCraftTime", CrossbowBinding::_NV_getCraftTime },
        { "getRangeInUnits", CrossbowBinding::getRangeInUnits },
        { "getEquipPositionOffset", CrossbowBinding::getEquipPositionOffset },
        { "destroyItemEntityCallback_Equipping", CrossbowBinding::destroyItemEntityCallback_Equipping },
        { "_NV_destroyItemEntityCallback_Equipping", CrossbowBinding::_NV_destroyItemEntityCallback_Equipping },
        { "setVisible", CrossbowBinding::setVisible },
        { "_NV_setVisible", CrossbowBinding::_NV_setVisible },
        { "_DESTRUCTOR", CrossbowBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        CrossbowBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CrossbowBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, Crossbow_get_gunClass);
    lua_setfield(L, -2, "gunClass");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, Crossbow_set_gunClass);
    lua_setfield(L, -2, "gunClass");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua