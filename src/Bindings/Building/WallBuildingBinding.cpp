#include "pch.h"
#include "Bindings/Building/WallBuildingBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Building/WallBuilding.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static WallBuilding* getS(lua_State* L, int idx)
{
    return checkObject<WallBuilding>(L, idx, WallBuildingBinding::getMetatableName());
}

int WallBuildingBinding::gc(lua_State* L) { return noopGc(L); }

int WallBuildingBinding::tostring(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int WallBuildingBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, WallBuildingBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    WallBuilding* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    // TODO WallSectionLinkType wallSectionLinkType; unsupported __index type from header line 66
    // TODO hand shareBuildStateOfAnother; unsupported __index type from header line 68
    // TODO lektor<hand> othersSharingMyBuildState; unsupported __index type from header line 69

    lua_pushnil(L);
    return 1;
}

int WallBuildingBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    // TODO WallSectionLinkType wallSectionLinkType; unsupported __newindex type from header line 66
    // TODO hand shareBuildStateOfAnother; unsupported __newindex type from header line 68
    // TODO lektor<hand> othersSharingMyBuildState; unsupported __newindex type from header line 69

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int WallBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    s->_DESTRUCTOR();
    return 0;
}

int WallBuildingBinding::getReachRange(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    float result = s->getReachRange();
    lua_pushnumber(L, result);
    return 1;
}

int WallBuildingBinding::_NV_getReachRange(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    float result = s->_NV_getReachRange();
    lua_pushnumber(L, result);
    return 1;
}

int WallBuildingBinding::isForSale(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    bool result = s->isForSale();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WallBuildingBinding::_NV_isForSale(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    bool result = s->_NV_isForSale();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WallBuildingBinding::createPhysical(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    bool result = s->createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WallBuildingBinding::_NV_createPhysical(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    bool result = s->_NV_createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WallBuildingBinding::isDamaged(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    bool result = s->isDamaged();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WallBuildingBinding::_NV_isDamaged(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    bool result = s->_NV_isDamaged();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WallBuildingBinding::getOutsideGateCode(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    int result = s->getOutsideGateCode();
    lua_pushinteger(L, result);
    return 1;
}

int WallBuildingBinding::canUpgrade(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    GameData* result = s->canUpgrade();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int WallBuildingBinding::_NV_canUpgrade(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    GameData* result = s->_NV_canUpgrade();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int WallBuildingBinding::addConstructionProgress(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    float amount = (float)luaL_checknumber(L, 2);
    s->addConstructionProgress(amount);
    return 0;
}

int WallBuildingBinding::_NV_addConstructionProgress(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    float amount = (float)luaL_checknumber(L, 2);
    s->_NV_addConstructionProgress(amount);
    return 0;
}

int WallBuildingBinding::setConstructionProgress(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    float amount = (float)luaL_checknumber(L, 2);
    s->setConstructionProgress(amount);
    return 0;
}

int WallBuildingBinding::_NV_setConstructionProgress(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    float amount = (float)luaL_checknumber(L, 2);
    s->_NV_setConstructionProgress(amount);
    return 0;
}

int WallBuildingBinding::notifyConstructionComplete(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    s->notifyConstructionComplete();
    return 0;
}

int WallBuildingBinding::_NV_notifyConstructionComplete(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    s->_NV_notifyConstructionComplete();
    return 0;
}

int WallBuildingBinding::addDismantleProgress(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    float amount = (float)luaL_checknumber(L, 2);
    bool result = s->addDismantleProgress(amount);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WallBuildingBinding::_NV_addDismantleProgress(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    float amount = (float)luaL_checknumber(L, 2);
    bool result = s->_NV_addDismantleProgress(amount);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WallBuildingBinding::notifyConstructionDismantling(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    s->notifyConstructionDismantling();
    return 0;
}

int WallBuildingBinding::_NV_notifyConstructionDismantling(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    s->_NV_notifyConstructionDismantling();
    return 0;
}

int WallBuildingBinding::getBuildState(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    Building::ConstructionState result = s->getBuildState();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int WallBuildingBinding::_NV_getBuildState(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    Building::ConstructionState result = s->_NV_getBuildState();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int WallBuildingBinding::isALittleWallPartLikeACornerOrSomething(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    bool result = s->isALittleWallPartLikeACornerOrSomething();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WallBuildingBinding::isAShortWallPart(lua_State* L)
{
    WallBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WallBuilding is nil");

    bool result = s->isAShortWallPart();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 24: WallBuilding* _CONSTRUCTOR(...) - unsupported return type
  line 25: UseableStuff* getUseableStuff(...) - unsupported return type
  line 26: UseableStuff* _NV_getUseableStuff(...) - unsupported return type
  line 35: Ogre::Vector3 getPositionForWaypoint_outside(...) - unsupported return type
  line 37: WallBuilding* isAWall(...) - unsupported return type
  line 38: WallBuilding* _NV_isAWall(...) - unsupported return type
  line 39: void upgrade(...) - unsupported arg type
  line 40: void _NV_upgrade(...) - unsupported arg type
  line 41: void getGUIUpgrade(...) - unsupported arg type
  line 42: void _NV_getGUIUpgrade(...) - unsupported arg type
  line 43: void getGUIDestroyButton(...) - unsupported arg type
  line 44: void _NV_getGUIDestroyButton(...) - unsupported arg type
  line 47: void dismantleButton_all(...) - unsupported arg type
  line 48: void _NV_dismantleButton_all(...) - unsupported arg type
  line 59: HitMaterialType hitByMeleeAttack(...) - unsupported return type
  line 60: HitMaterialType _NV_hitByMeleeAttack(...) - unsupported return type
  line 63: void runLinkingCheck(...) - unsupported arg type
  line 67: bool letsShare(...) - unsupported arg type
*/

void WallBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       WallBuildingBinding::gc },
        { "__tostring", WallBuildingBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", WallBuildingBinding::_DESTRUCTOR },
        { "getReachRange", WallBuildingBinding::getReachRange },
        { "_NV_getReachRange", WallBuildingBinding::_NV_getReachRange },
        { "isForSale", WallBuildingBinding::isForSale },
        { "_NV_isForSale", WallBuildingBinding::_NV_isForSale },
        { "createPhysical", WallBuildingBinding::createPhysical },
        { "_NV_createPhysical", WallBuildingBinding::_NV_createPhysical },
        { "isDamaged", WallBuildingBinding::isDamaged },
        { "_NV_isDamaged", WallBuildingBinding::_NV_isDamaged },
        { "getOutsideGateCode", WallBuildingBinding::getOutsideGateCode },
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
    registerClass(L, WallBuildingBinding::getMetatableName(), meta, methods, WallBuildingBinding::index, WallBuildingBinding::newindex);
}

} // namespace KenshiLua