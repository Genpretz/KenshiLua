#include "pch.h"
#include "kenshi\SensoryData.h"
#include "SpottingPeopleMgrBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

typedef SensoryData::SpottingPeopleMgr SpottingPeopleMgr;

static SpottingPeopleMgr* getB(lua_State* L, int idx)
{
    return checkObject<SpottingPeopleMgr>(L, idx, SpottingPeopleMgrBinding::getMetatableName());
}

// --- Getters for SpottingPeopleMgr ---
static int SpottingPeopleMgr_get_spottedPeople(lua_State* L)
{
    SpottingPeopleMgr* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpottingPeopleMgr is nil");
    // TODO: Unsupported type for spottedPeople (std::map<hand, SensoryData::SpottingPeopleMgr::Spot, std::less<hand>, Ogre::STLAllocator<std::pair<hand const, SensoryData::SpottingPeopleMgr::Spot>, Ogre::GeneralAllocPolicy > >)
    lua_pushnil(L);
    return 1;
}

// --- Setters for SpottingPeopleMgr ---
static int SpottingPeopleMgr_set_spottedPeople(lua_State* L)
{
    SpottingPeopleMgr* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpottingPeopleMgr is nil");
    return luaL_error(L, "Read-only or unsupported setter type for spottedPeople");
}

int SpottingPeopleMgrBinding::update(lua_State* L)
{
    SpottingPeopleMgr* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpottingPeopleMgr is nil");

    float time = (float)luaL_checknumber(L, 2);
    b->update(time);
    return 0;
}

int SpottingPeopleMgrBinding::resetSeenFlags(lua_State* L)
{
    SpottingPeopleMgr* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpottingPeopleMgr is nil");

    b->resetSeenFlags();
    return 0;
}

int SpottingPeopleMgrBinding::_DESTRUCTOR(lua_State* L)
{
    SpottingPeopleMgr* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpottingPeopleMgr is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 165: void spot(...) - unsupported arg type
  line 166: float getTime(...) - unsupported arg type
  line 168: void cantSeeAnymore(...) - unsupported arg type
  line 169: bool has(...) - unsupported arg type
  line 183: SpottingPeopleMgr* _CONSTRUCTOR(...) - unsupported return type
*/

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
        { "_DESTRUCTOR", SpottingPeopleMgrBinding::_DESTRUCTOR },
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
    lua_pushcfunction(L, SpottingPeopleMgr_get_spottedPeople);
    lua_setfield(L, -2, "spottedPeople");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, SpottingPeopleMgr_set_spottedPeople);
    lua_setfield(L, -2, "spottedPeople");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua