#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class WeaponBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Weapon"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getItemWeight(lua_State* L);
    static int _NV_getItemWeight(lua_State* L);
    static int getValueSingle(lua_State* L);
    static int _NV_getValueSingle(lua_State* L);
    static int getCategory(lua_State* L);
    static int getCategory_animationOverride(lua_State* L);
    static int is2HandedOnly(lua_State* L);
    static int getCombatWeight(lua_State* L);
    static int getCraftTime(lua_State* L);
    static int _NV_getCraftTime(lua_State* L);
    static int getCraftMaterialMult(lua_State* L);
    static int _NV_getCraftMaterialMult(lua_State* L);
    static int isWeapon(lua_State* L);
    static int _NV_isWeapon(lua_State* L);
    static int isSword(lua_State* L);
    static int _NV_isSword(lua_State* L);
    static int isCrossbow(lua_State* L);
    static int _NV_isCrossbow(lua_State* L);
    static int getSkillModIndoors(lua_State* L);
    static int _NV_getSkillModIndoors(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}