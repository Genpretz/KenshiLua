#include "pch.h"
#include "Bindings/GameDataBinding.h"

#include <kenshi/Building/WallBuilding.h>
#include "WallBuildingBinding.h"
#include "BuildingBinding.h"
#include "UseableStuffBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static WallBuilding* getInstance(lua_State* L, int idx)
{
    return checkObject<WallBuilding>(L, idx, WallBuildingBinding::getMetatableName());
}

// --- Getters for WallBuilding ---
static int WallBuilding_get_wallSectionLinkType(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");
    // TODO: Unsupported type for wallSectionLinkType (WallSectionLinkType)
    lua_pushnil(L);
    return 1;
}

static int WallBuilding_get_shareBuildStateOfAnother(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");
    // TODO: Unsupported type for shareBuildStateOfAnother (hand)
    lua_pushnil(L);
    return 1;
}

static int WallBuilding_get_othersSharingMyBuildState(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");
    // TODO: Unsupported type for othersSharingMyBuildState (lektor<hand>)
    lua_pushnil(L);
    return 1;
}

// --- Setters for WallBuilding ---
static int WallBuilding_set_wallSectionLinkType(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for wallSectionLinkType");
}

static int WallBuilding_set_shareBuildStateOfAnother(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for shareBuildStateOfAnother");
}

static int WallBuilding_set_othersSharingMyBuildState(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for othersSharingMyBuildState");
}

// --- Methods for WallBuilding ---
int WallBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int WallBuildingBinding::getUseableStuff(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    UseableStuff* result = instance->getUseableStuff();
    return pushObject<UseableStuff>(L, result, UseableStuffBinding::getMetatableName());
}

int WallBuildingBinding::_NV_getUseableStuff(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    UseableStuff* result = instance->_NV_getUseableStuff();
    return pushObject<UseableStuff>(L, result, UseableStuffBinding::getMetatableName());
}

int WallBuildingBinding::getReachRange(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    float result = instance->getReachRange();
    lua_pushnumber(L, result);
    return 1;
}

int WallBuildingBinding::_NV_getReachRange(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    float result = instance->_NV_getReachRange();
    lua_pushnumber(L, result);
    return 1;
}

int WallBuildingBinding::isForSale(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    bool result = instance->isForSale();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WallBuildingBinding::_NV_isForSale(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    bool result = instance->_NV_isForSale();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WallBuildingBinding::createPhysical(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    bool result = instance->createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WallBuildingBinding::_NV_createPhysical(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    bool result = instance->_NV_createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WallBuildingBinding::isDamaged(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    bool result = instance->isDamaged();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WallBuildingBinding::_NV_isDamaged(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    bool result = instance->_NV_isDamaged();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WallBuildingBinding::getPositionForWaypoint_outside(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    Ogre::Vector3 result = instance->getPositionForWaypoint_outside();
    pushVector3(L, result);
    return 1;
}

int WallBuildingBinding::getOutsideGateCode(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    int result = instance->getOutsideGateCode();
    lua_pushinteger(L, result);
    return 1;
}

int WallBuildingBinding::isAWall(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    WallBuilding* result = instance->isAWall();
    return pushObject<WallBuilding>(L, result, WallBuildingBinding::getMetatableName());
}

int WallBuildingBinding::_NV_isAWall(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    WallBuilding* result = instance->_NV_isAWall();
    return pushObject<WallBuilding>(L, result, WallBuildingBinding::getMetatableName());
}

int WallBuildingBinding::canUpgrade(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    GameData* result = instance->canUpgrade();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int WallBuildingBinding::_NV_canUpgrade(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    GameData* result = instance->_NV_canUpgrade();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int WallBuildingBinding::addConstructionProgress(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    float amount = (float)luaL_checknumber(L, 2);
    instance->addConstructionProgress(amount);
    return 0;
}

int WallBuildingBinding::_NV_addConstructionProgress(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    float amount = (float)luaL_checknumber(L, 2);
    instance->_NV_addConstructionProgress(amount);
    return 0;
}

int WallBuildingBinding::setConstructionProgress(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    float amount = (float)luaL_checknumber(L, 2);
    instance->setConstructionProgress(amount);
    return 0;
}

int WallBuildingBinding::_NV_setConstructionProgress(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    float amount = (float)luaL_checknumber(L, 2);
    instance->_NV_setConstructionProgress(amount);
    return 0;
}

int WallBuildingBinding::notifyConstructionComplete(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    instance->notifyConstructionComplete();
    return 0;
}

int WallBuildingBinding::_NV_notifyConstructionComplete(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    instance->_NV_notifyConstructionComplete();
    return 0;
}

int WallBuildingBinding::addDismantleProgress(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    float amount = (float)luaL_checknumber(L, 2);
    bool result = instance->addDismantleProgress(amount);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WallBuildingBinding::_NV_addDismantleProgress(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    float amount = (float)luaL_checknumber(L, 2);
    bool result = instance->_NV_addDismantleProgress(amount);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WallBuildingBinding::notifyConstructionDismantling(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    instance->notifyConstructionDismantling();
    return 0;
}

int WallBuildingBinding::_NV_notifyConstructionDismantling(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    instance->_NV_notifyConstructionDismantling();
    return 0;
}

int WallBuildingBinding::getBuildState(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    Building::ConstructionState* result = instance->getBuildState();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int WallBuildingBinding::_NV_getBuildState(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    Building::ConstructionState* result = instance->_NV_getBuildState();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int WallBuildingBinding::isALittleWallPartLikeACornerOrSomething(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    bool result = instance->isALittleWallPartLikeACornerOrSomething();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WallBuildingBinding::isAShortWallPart(lua_State* L)
{
    WallBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WallBuilding is nil");

    bool result = instance->isAShortWallPart();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 24: WallBuilding* _CONSTRUCTOR(...) - unsupported arg type
  line 39: void upgrade(...) - unsupported arg type
  line 40: void _NV_upgrade(...) - unsupported arg type
  line 41: void getGUIUpgrade(...) - unsupported arg type
  line 42: void _NV_getGUIUpgrade(...) - unsupported arg type
  line 43: void getGUIDestroyButton(...) - unsupported arg type
  line 44: void _NV_getGUIDestroyButton(...) - unsupported arg type
  line 47: void dismantleButton_all(...) - unsupported arg type
  line 48: void _NV_dismantleButton_all(...) - unsupported arg type
  line 59: HitMaterialType hitByMeleeAttack(...) - unsupported arg type
  line 60: HitMaterialType _NV_hitByMeleeAttack(...) - unsupported arg type
  line 63: void runLinkingCheck(...) - unsupported arg type
  line 67: bool letsShare(...) - unsupported arg type
*/

int WallBuildingBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int WallBuildingBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.WallBuilding object");
    return 1;
}

void WallBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       WallBuildingBinding::gc },
        { "__tostring", WallBuildingBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", WallBuildingBinding::_DESTRUCTOR },
        { "getUseableStuff", WallBuildingBinding::getUseableStuff },
        { "_NV_getUseableStuff", WallBuildingBinding::_NV_getUseableStuff },
        { "getReachRange", WallBuildingBinding::getReachRange },
        { "_NV_getReachRange", WallBuildingBinding::_NV_getReachRange },
        { "isForSale", WallBuildingBinding::isForSale },
        { "_NV_isForSale", WallBuildingBinding::_NV_isForSale },
        { "createPhysical", WallBuildingBinding::createPhysical },
        { "_NV_createPhysical", WallBuildingBinding::_NV_createPhysical },
        { "isDamaged", WallBuildingBinding::isDamaged },
        { "_NV_isDamaged", WallBuildingBinding::_NV_isDamaged },
        { "getPositionForWaypoint_outside", WallBuildingBinding::getPositionForWaypoint_outside },
        { "getOutsideGateCode", WallBuildingBinding::getOutsideGateCode },
        { "isAWall", WallBuildingBinding::isAWall },
        { "_NV_isAWall", WallBuildingBinding::_NV_isAWall },
        { "canUpgrade", WallBuildingBinding::canUpgrade },
        { "_NV_canUpgrade", WallBuildingBinding::_NV_canUpgrade },
        { "addConstructionProgress", WallBuildingBinding::addConstructionProgress },
        { "_NV_addConstructionProgress", WallBuildingBinding::_NV_addConstructionProgress },
        { "setConstructionProgress", WallBuildingBinding::setConstructionProgress },
        { "_NV_setConstructionProgress", WallBuildingBinding::_NV_setConstructionProgress },
        { "notifyConstructionComplete", WallBuildingBinding::notifyConstructionComplete },
        { "_NV_notifyConstructionComplete", WallBuildingBinding::_NV_notifyConstructionComplete },
        { "addDismantleProgress", WallBuildingBinding::addDismantleProgress },
        { "_NV_addDismantleProgress", WallBuildingBinding::_NV_addDismantleProgress },
        { "notifyConstructionDismantling", WallBuildingBinding::notifyConstructionDismantling },
        { "_NV_notifyConstructionDismantling", WallBuildingBinding::_NV_notifyConstructionDismantling },
        { "getBuildState", WallBuildingBinding::getBuildState },
        { "_NV_getBuildState", WallBuildingBinding::_NV_getBuildState },
        { "isALittleWallPartLikeACornerOrSomething", WallBuildingBinding::isALittleWallPartLikeACornerOrSomething },
        { "isAShortWallPart", WallBuildingBinding::isAShortWallPart },
        { 0, 0 }
    };

    registerClass(
        L, 
        WallBuildingBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, WallBuildingBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, WallBuilding_get_wallSectionLinkType);
    lua_setfield(L, -2, "wallSectionLinkType");
    lua_pushcfunction(L, WallBuilding_get_shareBuildStateOfAnother);
    lua_setfield(L, -2, "shareBuildStateOfAnother");
    lua_pushcfunction(L, WallBuilding_get_othersSharingMyBuildState);
    lua_setfield(L, -2, "othersSharingMyBuildState");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, WallBuilding_set_wallSectionLinkType);
    lua_setfield(L, -2, "wallSectionLinkType");
    lua_pushcfunction(L, WallBuilding_set_shareBuildStateOfAnother);
    lua_setfield(L, -2, "shareBuildStateOfAnother");
    lua_pushcfunction(L, WallBuilding_set_othersSharingMyBuildState);
    lua_setfield(L, -2, "othersSharingMyBuildState");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Building
    setMetatableParent(L, WallBuildingBinding::getMetatableName(), BuildingBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua