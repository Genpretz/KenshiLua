#pragma once
#include "kenshi/GunClass.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class GunClassBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.GunClass"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int setVisible(lua_State* L);
    static int _NV_setVisible(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int reloadAmmo(lua_State* L);
    static int shoot(lua_State* L);
    static int destroyPhysical(lua_State* L);
    static int _NV_destroyPhysical(lua_State* L);
    static int aimAt(lua_State* L);
    static int _NV_aimAt(lua_State* L);
    static int isAnimationReadyToShoot(lua_State* L);
    static int _NV_isAnimationReadyToShoot(lua_State* L);
    static int setAnimationReadyToShoot(lua_State* L);
    static int _NV_setAnimationReadyToShoot(lua_State* L);
    static int getBarrelPos(lua_State* L);
    static int _NV_getBarrelPos(lua_State* L);
    static int getBarrelPosForTrace(lua_State* L);
    static int _NV_getBarrelPosForTrace(lua_State* L);
    static int getRelativeBarrelPos(lua_State* L);
    static int getAimDir(lua_State* L);
    static int _NV_getAimDir(lua_State* L);
    static int getAimCloseness(lua_State* L);
    static int getGUIData(lua_State* L);
    static int _NV_getGUIData(lua_State* L);
    static int setStateForGUI(lua_State* L);
    static int _NV_setStateForGUI(lua_State* L);
    static int calculateHeightBonus(lua_State* L);
    static int calculateWallBonusMult(lua_State* L);
    static int _NV_calculateWallBonusMult(lua_State* L);
    static int getPowerEfficiencyMult(lua_State* L);
    static int _NV_getPowerEfficiencyMult(lua_State* L);
    static int isReloading(lua_State* L);
    static int isActive(lua_State* L);
    static int calculateAccuracyDeviationAngle(lua_State* L);
    static int calculateReloadTime(lua_State* L);
    static int serialise(lua_State* L);
    static int _NV_serialise(lua_State* L);
    static int loadFromSerialise(lua_State* L);
    static int _NV_loadFromSerialise(lua_State* L);
    static int getDamageMin(lua_State* L);
    static int getDamageMax(lua_State* L);
    static int getARandomDamage(lua_State* L);
    static int isPersonalCrossbow(lua_State* L);
    static int _NV_isPersonalCrossbow(lua_State* L);
    static int isTurret(lua_State* L);
    static int _NV_isTurret(lua_State* L);
    static int getReloadStateForGUI(lua_State* L);
    static int reactivationCheck(lua_State* L);
    static int updatePartVisibilities(lua_State* L);
    static int setCharacter(lua_State* L);
    static int _NV_setCharacter(lua_State* L);
};
}
