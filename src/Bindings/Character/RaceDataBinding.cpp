#include "pch.h"
#include "Bindings/Character/RaceDataBinding.h"
#include "Bindings/Core/GameDataBinding.h"
#include "Bindings/Equipment/ItemBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/RaceData.h>
#include <kenshi/GameData.h>
#include <kenshi/Item.h>

#include <cstdio>
#include <cstring>

namespace KenshiLua
{

static RaceData* getRD(lua_State* L, int idx)
{
    return checkObject<RaceData>(L, idx, RaceDataBinding::getMetatableName());
}

int RaceDataBinding::gc(lua_State* L) { return noopGc(L); }

int RaceDataBinding::tostring(lua_State* L)
{
    RaceData* r = getRD(L, 1);
    if (r == 0) { lua_pushstring(L, "RaceData:nil"); return 1; }
    char buf[160];
    const char* nm = (r->data ? r->data->name.c_str() : "Unknown");
    _snprintf(buf, sizeof(buf), "RaceData:%s(%p)", nm, (void*)r);
    lua_pushstring(L, buf);
    return 1;
}

int RaceDataBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, RaceDataBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    RaceData* r = getRD(L, 1);
    if (r == 0) { lua_pushnil(L); return 1; }

    // --- float members ---
    if (strcmp(key, "runSpeedMaxSkill") == 0) { lua_pushnumber(L, r->runSpeedMaxSkill); return 1; }
    if (strcmp(key, "runSpeedMinSkill") == 0) { lua_pushnumber(L, r->runSpeedMinSkill); return 1; }
    if (strcmp(key, "originalBloodMin") == 0) { lua_pushnumber(L, r->originalBloodMin); return 1; }
    if (strcmp(key, "originalBloodMax") == 0) { lua_pushnumber(L, r->originalBloodMax); return 1; }
    if (strcmp(key, "healRate") == 0) { lua_pushnumber(L, r->healRate); return 1; }
    if (strcmp(key, "bleedRate") == 0) { lua_pushnumber(L, r->bleedRate); return 1; }
    if (strcmp(key, "swimSpeed") == 0) { lua_pushnumber(L, r->swimSpeed); return 1; }
    if (strcmp(key, "walkSpeed") == 0) { lua_pushnumber(L, r->walkSpeed); return 1; }
    if (strcmp(key, "hungerRate") == 0) { lua_pushnumber(L, r->hungerRate); return 1; }
    if (strcmp(key, "visionMultiplier") == 0) { lua_pushnumber(L, r->visionMultiplier); return 1; }

    // --- integer members ---
    if (strcmp(key, "extraAttackSlots") == 0) { lua_pushinteger(L, r->extraAttackSlots); return 1; }

    // --- boolean members ---
    if (strcmp(key, "gigantic") == 0) { lua_pushboolean(L, r->gigantic ? 1 : 0); return 1; }
    if (strcmp(key, "swims") == 0) { lua_pushboolean(L, r->swims ? 1 : 0); return 1; }
    if (strcmp(key, "carriable") == 0) { lua_pushboolean(L, r->carriable ? 1 : 0); return 1; }
    if (strcmp(key, "singleGender") == 0) { lua_pushboolean(L, r->singleGender ? 1 : 0); return 1; }
    if (strcmp(key, "robot") == 0) { lua_pushboolean(L, r->robot ? 1 : 0); return 1; }
    if (strcmp(key, "vampiric") == 0) { lua_pushboolean(L, r->vampiric ? 1 : 0); return 1; }
    if (strcmp(key, "noHats") == 0) { lua_pushboolean(L, r->noHats ? 1 : 0); return 1; }
    if (strcmp(key, "noShirts") == 0) { lua_pushboolean(L, r->noShirts ? 1 : 0); return 1; }
    if (strcmp(key, "noShoes") == 0) { lua_pushboolean(L, r->noShoes ? 1 : 0); return 1; }
    if (strcmp(key, "canGoIndoors") == 0) { lua_pushboolean(L, r->canGoIndoors ? 1 : 0); return 1; }

    // --- unique object members ---
    if (strcmp(key, "data") == 0)
    {
        return pushObject<GameData>(L, r->data, GameDataBinding::getMetatableName());
    }

    lua_pushnil(L);
    return 1;
}

int RaceDataBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    RaceData* r = getRD(L, 1);
    if (r == 0) return luaL_error(L, "RaceData is nil");

    // --- writable floats ---
    if (strcmp(key, "runSpeedMaxSkill") == 0) { r->runSpeedMaxSkill = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "runSpeedMinSkill") == 0) { r->runSpeedMinSkill = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "originalBloodMin") == 0) { r->originalBloodMin = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "originalBloodMax") == 0) { r->originalBloodMax = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "healRate") == 0) { r->healRate = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "bleedRate") == 0) { r->bleedRate = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "swimSpeed") == 0) { r->swimSpeed = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "walkSpeed") == 0) { r->walkSpeed = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "hungerRate") == 0) { r->hungerRate = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "visionMultiplier") == 0) { r->visionMultiplier = (float)luaL_checknumber(L, 3); return 0; }

    // --- writable integers ---
    if (strcmp(key, "extraAttackSlots") == 0) { r->extraAttackSlots = (int)luaL_checkinteger(L, 3); return 0; }

    // --- writable booleans ---
    if (strcmp(key, "gigantic") == 0) { r->gigantic = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "swims") == 0) { r->swims = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "carriable") == 0) { r->carriable = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "singleGender") == 0) { r->singleGender = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "robot") == 0) { r->robot = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "vampiric") == 0) { r->vampiric = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "noHats") == 0) { r->noHats = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "noShirts") == 0) { r->noShirts = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "noShoes") == 0) { r->noShoes = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "canGoIndoors") == 0) { r->canGoIndoors = (lua_toboolean(L, 3) != 0); return 0; }

    return luaL_error(L, "RaceData: field '%s' is read-only or does not exist", key);
}

int RaceDataBinding::isRelatedRace(lua_State* L)
{
    RaceData* r = getRD(L, 1);
    if (r == 0) return luaL_error(L, "RaceData is nil");

    // Can accept either RaceData userdata or GameData userdata
    RaceData* other = testObject<RaceData>(L, 2, RaceDataBinding::getMetatableName());
    if (other != 0)
    {
        lua_pushboolean(L, r->isRelatedRace(other) ? 1 : 0);
        return 1;
    }

    GameData* gd = testObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    if (gd != 0)
    {
        lua_pushboolean(L, r->isRelatedRace(gd) ? 1 : 0);
        return 1;
    }

    return luaL_error(L, "isRelatedRace: expected RaceData or GameData userdata");
}

int RaceDataBinding::canEat(lua_State* L)
{
    RaceData* r = getRD(L, 1);
    if (r == 0) return luaL_error(L, "RaceData is nil");

    bool isAnimal = lua_toboolean(L, 3) != 0;

    Item* item = testObject<Item>(L, 2, ItemBinding::getMetatableName());
    if (item != 0)
    {
        lua_pushboolean(L, r->canEat(item, isAnimal) ? 1 : 0);
        return 1;
    }

    GameData* gd = testObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    if (gd != 0)
    {
        lua_pushboolean(L, r->canEat(gd, isAnimal) ? 1 : 0);
        return 1;
    }

    return luaL_error(L, "canEat: expected Item or GameData userdata");
}

int RaceDataBinding::isImmune(lua_State* L)
{
    RaceData* r = getRD(L, 1);
    if (r == 0) return luaL_error(L, "RaceData is nil");
    int w = (int)luaL_checkinteger(L, 2);
    lua_pushboolean(L, r->isImmune((WeatherAffecting)w) ? 1 : 0);
    return 1;
}

void RaceDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RaceDataBinding::gc },
        { "__tostring", RaceDataBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "isRelatedRace", RaceDataBinding::isRelatedRace },
        { "canEat",        RaceDataBinding::canEat },
        { "isImmune",      RaceDataBinding::isImmune },
        { 0, 0 }
    };
    registerClass(L, RaceDataBinding::getMetatableName(), meta, methods, RaceDataBinding::index, RaceDataBinding::newindex);
}

} // namespace KenshiLua