#include "pch.h"
#include "kenshi\SensoryData.h"
#include "SpottingPeopleMgrBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static SpottingPeopleMgr* getInstance(lua_State* L, int idx)
{
    return checkObject<SpottingPeopleMgr>(L, idx, SpottingPeopleMgrBinding::getMetatableName());
}

// --- Getters for SpottingPeopleMgr ---
// --- Setters for SpottingPeopleMgr ---
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

int SpottingPeopleMgrBinding::_CONSTRUCTOR(lua_State* L)
{
    SpottingPeopleMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpottingPeopleMgr is nil");

    SpottingPeopleMgr* result = instance->_CONSTRUCTOR();
    return pushObject<SpottingPeopleMgr>(L, result, SpottingPeopleMgrBinding::getMetatableName());
}

int SpottingPeopleMgrBinding::_DESTRUCTOR(lua_State* L)
{
    SpottingPeopleMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpottingPeopleMgr is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 165: void spot(...) - non-string reference arg
  line 166: float getTime(...) - non-string reference arg
  line 168: void cantSeeAnymore(...) - non-string reference arg
  line 169: bool has(...) - non-string reference arg
*/

/*
Skipped properties needing manual binding:
  line 180: spottedPeople (std::map<hand, SensoryData::SpottingPeopleMgr::Spot, std::less<hand>, Ogre::STLAllocator<std::pair<hand const, SensoryData::SpottingPeopleMgr::Spot>, Ogre::GeneralAllocPolicy > >) - unsupported type
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



static int SpottingPeopleMgr_get_spottedPeople(lua_State* L)
{
    SpottingPeopleMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpottingPeopleMgr is nil");
    // TODO: Unsupported type for spottedPeople (std::map<hand, SensoryData::SpottingPeopleMgr::Spot, std::less<hand>, Ogre::STLAllocator<std::pair<hand const, SensoryData::SpottingPeopleMgr::Spot>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'spottedPeople' (type: std::map<hand, SensoryData::SpottingPeopleMgr::Spot, std::less<hand>, Ogre::STLAllocator<std::pair<hand const, SensoryData::SpottingPeopleMgr::Spot>, Ogre::GeneralAllocPolicy > >)");
}


static int SpottingPeopleMgr_set_spottedPeople(lua_State* L)
{
    SpottingPeopleMgr* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SpottingPeopleMgr is nil");
    return luaL_error(L, "Read-only or unsupported setter type for spottedPeople");
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
        { "_CONSTRUCTOR", SpottingPeopleMgrBinding::_CONSTRUCTOR },
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
        registerGetter(L, "spottedPeople", SpottingPeopleMgr_get_spottedPeople);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
        registerSetter(L, "spottedPeople", SpottingPeopleMgr_set_spottedPeople);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua