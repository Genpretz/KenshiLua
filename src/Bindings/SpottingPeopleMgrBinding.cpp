#include "pch.h"
#include "kenshi\SensoryData.h"
#include "SpottingPeopleMgrBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/SpotBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/StdMapBinding.h"

namespace KenshiLua
{

static SpottingPeopleMgr* getInstance(lua_State* L, int idx)
{
    return checkObject<SpottingPeopleMgr>(L, idx, SpottingPeopleMgrBinding::getMetatableName());
}

// --- Getters for SpottingPeopleMgr ---
static int SpottingPeopleMgr_get_spottedPeople(lua_State* L)
{
    SpottingPeopleMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpottingPeopleMgr is nil");
    return pushObject<std::map<hand, SensoryData::SpottingPeopleMgr::Spot, std::less<hand>, Ogre::STLAllocator<std::pair<hand const, SensoryData::SpottingPeopleMgr::Spot>, Ogre::GeneralAllocPolicy>>>(L, &instance->spottedPeople, "std::map<hand, SensoryData::SpottingPeopleMgr::Spot>");
}

// --- Setters for SpottingPeopleMgr ---
static int SpottingPeopleMgr_set_spottedPeople(lua_State* L)
{
    SpottingPeopleMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpottingPeopleMgr is nil");
    auto* val = StdMapBinding<hand, SensoryData::SpottingPeopleMgr::Spot>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'spottedPeople' must be std::map<hand, SensoryData::SpottingPeopleMgr::Spot>");
    instance->spottedPeople = *val;
    return 0;
}

int SpottingPeopleMgrBinding::update(lua_State* L)
{
    SpottingPeopleMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpottingPeopleMgr is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->update(time);
    return 0;
}

int SpottingPeopleMgrBinding::resetSeenFlags(lua_State* L)
{
    SpottingPeopleMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpottingPeopleMgr is nil");

    instance->resetSeenFlags();
    return 0;
}

int SpottingPeopleMgrBinding::spot(lua_State* L)
{
    SpottingPeopleMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpottingPeopleMgr is nil");

    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 2 must be hand");
    float timelimit = (float)luaL_checknumber(L, 3);
    instance->spot(*h, timelimit);
    return 0;
}

int SpottingPeopleMgrBinding::getTime(lua_State* L)
{
    SpottingPeopleMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpottingPeopleMgr is nil");

    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 2 must be hand");
    float result = instance->getTime(*h);
    lua_pushnumber(L, result);
    return 1;
}

int SpottingPeopleMgrBinding::cantSeeAnymore(lua_State* L)
{
    SpottingPeopleMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpottingPeopleMgr is nil");

    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 2 must be hand");
    instance->cantSeeAnymore(*h);
    return 0;
}

int SpottingPeopleMgrBinding::has(lua_State* L)
{
    SpottingPeopleMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpottingPeopleMgr is nil");

    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 2 must be hand");
    bool result = instance->has(*h);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SpottingPeopleMgrBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int SpottingPeopleMgrBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.SpottingPeopleMgr object");
    return 1;
}

void SpottingPeopleMgrBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SpottingPeopleMgrBinding::gc },
        { "__tostring", SpottingPeopleMgrBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "update", SpottingPeopleMgrBinding::update },
        { "resetSeenFlags", SpottingPeopleMgrBinding::resetSeenFlags },
        { "spot", SpottingPeopleMgrBinding::spot },
        { "getTime", SpottingPeopleMgrBinding::getTime },
        { "cantSeeAnymore", SpottingPeopleMgrBinding::cantSeeAnymore },
        { "has", SpottingPeopleMgrBinding::has },
        { 0, 0 }
    };

    registerClass(
        L, 
        SpottingPeopleMgrBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SpottingPeopleMgrBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "spottedPeople", SpottingPeopleMgr_get_spottedPeople);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "spottedPeople", SpottingPeopleMgr_set_spottedPeople);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack

    StdMapBinding<hand, SensoryData::SpottingPeopleMgr::Spot>::registerBinding(
        L, 
        "std::map<hand, SensoryData::SpottingPeopleMgr::Spot>", 
        HandBinding::getMetatableName(), 
        SpotBinding::getMetatableName()
    );
}

} // namespace KenshiLua