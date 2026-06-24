#include "pch.h"
#include "kenshi\RaceData.h"
#include "RaceDataBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static RaceData* getB(lua_State* L, int idx)
{
    return checkObject<RaceData>(L, idx, RaceDataBinding::getMetatableName());
}

// --- Getters for RaceData ---
static int RaceData_get_specialFoods(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    // TODO: Unsupported type for specialFoods (ogre_unordered_set<GameData*>::type)
    lua_pushnil(L);
    return 1;
}

static int RaceData_get_data(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    return pushObject<GameData>(L, b->data, GameDataBinding::getMetatableName());
}

static int RaceData_get_runSpeedMaxSkill(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    lua_pushnumber(L, b->runSpeedMaxSkill);
    return 1;
}

static int RaceData_get_runSpeedMinSkill(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    lua_pushnumber(L, b->runSpeedMinSkill);
    return 1;
}

static int RaceData_get_originalBloodMin(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    lua_pushnumber(L, b->originalBloodMin);
    return 1;
}

static int RaceData_get_originalBloodMax(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    lua_pushnumber(L, b->originalBloodMax);
    return 1;
}

static int RaceData_get_healRate(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    lua_pushnumber(L, b->healRate);
    return 1;
}

static int RaceData_get_bleedRate(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    lua_pushnumber(L, b->bleedRate);
    return 1;
}

static int RaceData_get_swimSpeed(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    lua_pushnumber(L, b->swimSpeed);
    return 1;
}

static int RaceData_get_walkSpeed(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    lua_pushnumber(L, b->walkSpeed);
    return 1;
}

static int RaceData_get_swimOffset(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    lua_pushnumber(L, b->swimOffset);
    return 1;
}

static int RaceData_get_waterAvoidance(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    lua_pushnumber(L, b->waterAvoidance);
    return 1;
}

static int RaceData_get_hungerRate(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    lua_pushnumber(L, b->hungerRate);
    return 1;
}

static int RaceData_get_visionMultiplier(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    lua_pushnumber(L, b->visionMultiplier);
    return 1;
}

static int RaceData_get_gigantic(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    lua_pushboolean(L, b->gigantic ? 1 : 0);
    return 1;
}

static int RaceData_get_swims(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    lua_pushboolean(L, b->swims ? 1 : 0);
    return 1;
}

static int RaceData_get_carriable(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    lua_pushboolean(L, b->carriable ? 1 : 0);
    return 1;
}

static int RaceData_get_singleGender(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    lua_pushboolean(L, b->singleGender ? 1 : 0);
    return 1;
}

static int RaceData_get_robot(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    lua_pushboolean(L, b->robot ? 1 : 0);
    return 1;
}

static int RaceData_get_vampiric(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    lua_pushboolean(L, b->vampiric ? 1 : 0);
    return 1;
}

static int RaceData_get_noHats(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    lua_pushboolean(L, b->noHats ? 1 : 0);
    return 1;
}

static int RaceData_get_noShirts(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    lua_pushboolean(L, b->noShirts ? 1 : 0);
    return 1;
}

static int RaceData_get_noShoes(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    lua_pushboolean(L, b->noShoes ? 1 : 0);
    return 1;
}

static int RaceData_get_extraAttackSlots(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    lua_pushinteger(L, b->extraAttackSlots);
    return 1;
}

static int RaceData_get_firstAidSkill(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    lua_pushinteger(L, (lua_Integer)b->firstAidSkill);
    return 1;
}

static int RaceData_get_bloodColour(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    // TODO: Unsupported type for bloodColour (Ogre::ColourValue)
    lua_pushnil(L);
    return 1;
}

static int RaceData_get_canGoIndoors(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    lua_pushboolean(L, b->canGoIndoors ? 1 : 0);
    return 1;
}

static int RaceData_get_statMods(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    // TODO: Unsupported type for statMods (ogre_unordered_map<StatsEnumerated, float>::type)
    lua_pushnil(L);
    return 1;
}

static int RaceData_get_weatherImmunities(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    // TODO: Unsupported type for weatherImmunities (ogre_unordered_set<WeatherAffecting>::type)
    lua_pushnil(L);
    return 1;
}

static int RaceData_get_raceGroup(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    // TODO: Unsupported type for raceGroup (RaceGroupData*)
    lua_pushnil(L);
    return 1;
}

// --- Setters for RaceData ---
static int RaceData_set_specialFoods(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for specialFoods");
}

static int RaceData_set_data(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for data");
}

static int RaceData_set_runSpeedMaxSkill(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    b->runSpeedMaxSkill = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RaceData_set_runSpeedMinSkill(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    b->runSpeedMinSkill = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RaceData_set_originalBloodMin(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    b->originalBloodMin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RaceData_set_originalBloodMax(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    b->originalBloodMax = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RaceData_set_healRate(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    b->healRate = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RaceData_set_bleedRate(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    b->bleedRate = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RaceData_set_swimSpeed(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    b->swimSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RaceData_set_walkSpeed(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    b->walkSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RaceData_set_swimOffset(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    b->swimOffset = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RaceData_set_waterAvoidance(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    b->waterAvoidance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RaceData_set_hungerRate(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    b->hungerRate = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RaceData_set_visionMultiplier(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    b->visionMultiplier = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RaceData_set_gigantic(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    b->gigantic = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RaceData_set_swims(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    b->swims = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RaceData_set_carriable(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    b->carriable = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RaceData_set_singleGender(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    b->singleGender = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RaceData_set_robot(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    b->robot = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RaceData_set_vampiric(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    b->vampiric = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RaceData_set_noHats(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    b->noHats = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RaceData_set_noShirts(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    b->noShirts = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RaceData_set_noShoes(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    b->noShoes = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RaceData_set_extraAttackSlots(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    b->extraAttackSlots = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int RaceData_set_firstAidSkill(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    b->firstAidSkill = (StatsEnumerated)luaL_checkinteger(L, 2);
    return 0;
}

static int RaceData_set_bloodColour(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for bloodColour");
}

static int RaceData_set_canGoIndoors(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    b->canGoIndoors = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RaceData_set_statMods(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for statMods");
}

static int RaceData_set_weatherImmunities(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for weatherImmunities");
}

static int RaceData_set_raceGroup(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for raceGroup");
}

int RaceDataBinding::getStatMod(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");

    StatsEnumerated stat = (StatsEnumerated)luaL_checkinteger(L, 2);
    float result = b->getStatMod(stat);
    lua_pushnumber(L, result);
    return 1;
}

int RaceDataBinding::isImmune(lua_State* L)
{
    RaceData* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceData is nil");

    WeatherAffecting w = (WeatherAffecting)luaL_checkinteger(L, 2);
    bool result = b->isImmune(w);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 20: RaceData* getRaceData(...) - static method
  line 21: RaceData* getRaceData(...) - static method
  line 24: RaceData* _CONSTRUCTOR(...) - unsupported arg type
  line 25: bool isRelatedRace(...) - overloaded method
  line 26: bool isRelatedRace(...) - overloaded method
  line 27: bool isSpecificRace(...) - unsupported arg type
  line 29: bool canEat(...) - overloaded method
  line 30: bool canEat(...) - overloaded method
*/

int RaceDataBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int RaceDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.RaceData object");
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
        { "getStatMod", RaceDataBinding::getStatMod },
        { "isImmune", RaceDataBinding::isImmune },
        { 0, 0 }
    };

    registerClass(
        L, 
        RaceDataBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, RaceDataBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, RaceData_get_specialFoods);
    lua_setfield(L, -2, "specialFoods");
    lua_pushcfunction(L, RaceData_get_data);
    lua_setfield(L, -2, "data");
    lua_pushcfunction(L, RaceData_get_runSpeedMaxSkill);
    lua_setfield(L, -2, "runSpeedMaxSkill");
    lua_pushcfunction(L, RaceData_get_runSpeedMinSkill);
    lua_setfield(L, -2, "runSpeedMinSkill");
    lua_pushcfunction(L, RaceData_get_originalBloodMin);
    lua_setfield(L, -2, "originalBloodMin");
    lua_pushcfunction(L, RaceData_get_originalBloodMax);
    lua_setfield(L, -2, "originalBloodMax");
    lua_pushcfunction(L, RaceData_get_healRate);
    lua_setfield(L, -2, "healRate");
    lua_pushcfunction(L, RaceData_get_bleedRate);
    lua_setfield(L, -2, "bleedRate");
    lua_pushcfunction(L, RaceData_get_swimSpeed);
    lua_setfield(L, -2, "swimSpeed");
    lua_pushcfunction(L, RaceData_get_walkSpeed);
    lua_setfield(L, -2, "walkSpeed");
    lua_pushcfunction(L, RaceData_get_swimOffset);
    lua_setfield(L, -2, "swimOffset");
    lua_pushcfunction(L, RaceData_get_waterAvoidance);
    lua_setfield(L, -2, "waterAvoidance");
    lua_pushcfunction(L, RaceData_get_hungerRate);
    lua_setfield(L, -2, "hungerRate");
    lua_pushcfunction(L, RaceData_get_visionMultiplier);
    lua_setfield(L, -2, "visionMultiplier");
    lua_pushcfunction(L, RaceData_get_gigantic);
    lua_setfield(L, -2, "gigantic");
    lua_pushcfunction(L, RaceData_get_swims);
    lua_setfield(L, -2, "swims");
    lua_pushcfunction(L, RaceData_get_carriable);
    lua_setfield(L, -2, "carriable");
    lua_pushcfunction(L, RaceData_get_singleGender);
    lua_setfield(L, -2, "singleGender");
    lua_pushcfunction(L, RaceData_get_robot);
    lua_setfield(L, -2, "robot");
    lua_pushcfunction(L, RaceData_get_vampiric);
    lua_setfield(L, -2, "vampiric");
    lua_pushcfunction(L, RaceData_get_noHats);
    lua_setfield(L, -2, "noHats");
    lua_pushcfunction(L, RaceData_get_noShirts);
    lua_setfield(L, -2, "noShirts");
    lua_pushcfunction(L, RaceData_get_noShoes);
    lua_setfield(L, -2, "noShoes");
    lua_pushcfunction(L, RaceData_get_extraAttackSlots);
    lua_setfield(L, -2, "extraAttackSlots");
    lua_pushcfunction(L, RaceData_get_firstAidSkill);
    lua_setfield(L, -2, "firstAidSkill");
    lua_pushcfunction(L, RaceData_get_bloodColour);
    lua_setfield(L, -2, "bloodColour");
    lua_pushcfunction(L, RaceData_get_canGoIndoors);
    lua_setfield(L, -2, "canGoIndoors");
    lua_pushcfunction(L, RaceData_get_statMods);
    lua_setfield(L, -2, "statMods");
    lua_pushcfunction(L, RaceData_get_weatherImmunities);
    lua_setfield(L, -2, "weatherImmunities");
    lua_pushcfunction(L, RaceData_get_raceGroup);
    lua_setfield(L, -2, "raceGroup");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, RaceData_set_specialFoods);
    lua_setfield(L, -2, "specialFoods");
    lua_pushcfunction(L, RaceData_set_data);
    lua_setfield(L, -2, "data");
    lua_pushcfunction(L, RaceData_set_runSpeedMaxSkill);
    lua_setfield(L, -2, "runSpeedMaxSkill");
    lua_pushcfunction(L, RaceData_set_runSpeedMinSkill);
    lua_setfield(L, -2, "runSpeedMinSkill");
    lua_pushcfunction(L, RaceData_set_originalBloodMin);
    lua_setfield(L, -2, "originalBloodMin");
    lua_pushcfunction(L, RaceData_set_originalBloodMax);
    lua_setfield(L, -2, "originalBloodMax");
    lua_pushcfunction(L, RaceData_set_healRate);
    lua_setfield(L, -2, "healRate");
    lua_pushcfunction(L, RaceData_set_bleedRate);
    lua_setfield(L, -2, "bleedRate");
    lua_pushcfunction(L, RaceData_set_swimSpeed);
    lua_setfield(L, -2, "swimSpeed");
    lua_pushcfunction(L, RaceData_set_walkSpeed);
    lua_setfield(L, -2, "walkSpeed");
    lua_pushcfunction(L, RaceData_set_swimOffset);
    lua_setfield(L, -2, "swimOffset");
    lua_pushcfunction(L, RaceData_set_waterAvoidance);
    lua_setfield(L, -2, "waterAvoidance");
    lua_pushcfunction(L, RaceData_set_hungerRate);
    lua_setfield(L, -2, "hungerRate");
    lua_pushcfunction(L, RaceData_set_visionMultiplier);
    lua_setfield(L, -2, "visionMultiplier");
    lua_pushcfunction(L, RaceData_set_gigantic);
    lua_setfield(L, -2, "gigantic");
    lua_pushcfunction(L, RaceData_set_swims);
    lua_setfield(L, -2, "swims");
    lua_pushcfunction(L, RaceData_set_carriable);
    lua_setfield(L, -2, "carriable");
    lua_pushcfunction(L, RaceData_set_singleGender);
    lua_setfield(L, -2, "singleGender");
    lua_pushcfunction(L, RaceData_set_robot);
    lua_setfield(L, -2, "robot");
    lua_pushcfunction(L, RaceData_set_vampiric);
    lua_setfield(L, -2, "vampiric");
    lua_pushcfunction(L, RaceData_set_noHats);
    lua_setfield(L, -2, "noHats");
    lua_pushcfunction(L, RaceData_set_noShirts);
    lua_setfield(L, -2, "noShirts");
    lua_pushcfunction(L, RaceData_set_noShoes);
    lua_setfield(L, -2, "noShoes");
    lua_pushcfunction(L, RaceData_set_extraAttackSlots);
    lua_setfield(L, -2, "extraAttackSlots");
    lua_pushcfunction(L, RaceData_set_firstAidSkill);
    lua_setfield(L, -2, "firstAidSkill");
    lua_pushcfunction(L, RaceData_set_bloodColour);
    lua_setfield(L, -2, "bloodColour");
    lua_pushcfunction(L, RaceData_set_canGoIndoors);
    lua_setfield(L, -2, "canGoIndoors");
    lua_pushcfunction(L, RaceData_set_statMods);
    lua_setfield(L, -2, "statMods");
    lua_pushcfunction(L, RaceData_set_weatherImmunities);
    lua_setfield(L, -2, "weatherImmunities");
    lua_pushcfunction(L, RaceData_set_raceGroup);
    lua_setfield(L, -2, "raceGroup");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua