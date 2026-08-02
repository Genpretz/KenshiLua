#include "pch.h"
#include "kenshi\Gear.h"
#include "CrossbowBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/WeaponBinding.h"

namespace KenshiLua
{

static Crossbow* getInstance(lua_State* L, int idx)
{
    return checkObject<Crossbow>(L, idx, CrossbowBinding::getMetatableName());
}

// --- Getters for Crossbow ---
static int Crossbow_get_gunClass(lua_State* L)
{
    Crossbow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Crossbow is nil");
    lua_pushlightuserdata(L, (void*)instance->gunClass);
    return 1;
}

// --- Setters for Crossbow ---
int CrossbowBinding::_CONSTRUCTOR(lua_State* L)
{
    Crossbow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Crossbow is nil");

    GameData* baseData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    hand _handle = *checkObject<hand>(L, 3, HandBinding::getMetatableName());
    int _overalllevel = (int)luaL_checkinteger(L, 4);
    Crossbow* result = instance->_CONSTRUCTOR(baseData, _handle, _overalllevel);
    return pushObject<Crossbow>(L, result, CrossbowBinding::getMetatableName());
}

int CrossbowBinding::isCrossbow(lua_State* L)
{
    Crossbow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Crossbow is nil");

    Crossbow* result = instance->isCrossbow();
    return pushObject<Crossbow>(L, result, CrossbowBinding::getMetatableName());
}

int CrossbowBinding::_NV_isCrossbow(lua_State* L)
{
    Crossbow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Crossbow is nil");

    Crossbow* result = instance->_NV_isCrossbow();
    return pushObject<Crossbow>(L, result, CrossbowBinding::getMetatableName());
}

int CrossbowBinding::getClassType(lua_State* L)
{
    Crossbow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Crossbow is nil");

    itemType result = instance->getClassType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CrossbowBinding::_NV_getClassType(lua_State* L)
{
    Crossbow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Crossbow is nil");

    itemType result = instance->_NV_getClassType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CrossbowBinding::getCraftMaterialMult(lua_State* L)
{
    Crossbow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Crossbow is nil");

    float result = instance->getCraftMaterialMult();
    lua_pushnumber(L, result);
    return 1;
}

int CrossbowBinding::_NV_getCraftMaterialMult(lua_State* L)
{
    Crossbow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Crossbow is nil");

    float result = instance->_NV_getCraftMaterialMult();
    lua_pushnumber(L, result);
    return 1;
}

int CrossbowBinding::getCraftTime(lua_State* L)
{
    Crossbow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Crossbow is nil");

    float result = instance->getCraftTime();
    lua_pushnumber(L, result);
    return 1;
}

int CrossbowBinding::_NV_getCraftTime(lua_State* L)
{
    Crossbow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Crossbow is nil");

    float result = instance->_NV_getCraftTime();
    lua_pushnumber(L, result);
    return 1;
}

int CrossbowBinding::getRangeInUnits(lua_State* L)
{
    Crossbow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Crossbow is nil");

    float result = instance->getRangeInUnits();
    lua_pushnumber(L, result);
    return 1;
}

int CrossbowBinding::getEquipPositionOffset(lua_State* L)
{
    Crossbow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Crossbow is nil");

    float result = instance->getEquipPositionOffset();
    lua_pushnumber(L, result);
    return 1;
}

int CrossbowBinding::destroyItemEntityCallback_Equipping(lua_State* L)
{
    Crossbow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Crossbow is nil");

    instance->destroyItemEntityCallback_Equipping();
    return 0;
}

int CrossbowBinding::_NV_destroyItemEntityCallback_Equipping(lua_State* L)
{
    Crossbow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Crossbow is nil");

    instance->_NV_destroyItemEntityCallback_Equipping();
    return 0;
}

int CrossbowBinding::setVisible(lua_State* L)
{
    Crossbow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Crossbow is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setVisible(on);
    return 0;
}

int CrossbowBinding::_NV_setVisible(lua_State* L)
{
    Crossbow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Crossbow is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_setVisible(on);
    return 0;
}

int CrossbowBinding::_DESTRUCTOR(lua_State* L)
{
    Crossbow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Crossbow is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 130: void getTooltipData1(...) - unsupported arg type
  line 131: void _NV_getTooltipData1(...) - unsupported arg type
  line 132: void getTooltipData2(...) - unsupported arg type
  line 133: void _NV_getTooltipData2(...) - unsupported arg type
  line 134: void createItemEntityCallback_Equipping(...) - unsupported arg type
  line 135: void _NV_createItemEntityCallback_Equipping(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - Crossbow_get_gunClass: GunClass* (unbound pointer)
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



static int Crossbow_set_gunClass(lua_State* L)
{
    Crossbow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Crossbow is nil");
    return luaL_error(L, "Read-only or unsupported setter type for gunClass");
}


void CrossbowBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CrossbowBinding::gc },
        { "__tostring", CrossbowBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", CrossbowBinding::_CONSTRUCTOR },
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
    registerGetter(L, "gunClass", Crossbow_get_gunClass);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
        registerSetter(L, "gunClass", Crossbow_set_gunClass);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Weapon
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, CrossbowBinding::getMetatableName(), WeaponBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua