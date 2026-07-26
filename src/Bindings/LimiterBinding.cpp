#include "pch.h"
#include "kenshi\Item.h"
#include "LimiterBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/RaceDataBinding.h"

namespace KenshiLua
{

static Limiter* getInstance(lua_State* L, int idx)
{
    return checkObject<Limiter>(L, idx, LimiterBinding::getMetatableName());
}

// --- Getters for Limiter ---
// --- Setters for Limiter ---
int LimiterBinding::canEquip(lua_State* L)
{
    Limiter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Limiter is nil");

    RaceData* race = checkObject<RaceData>(L, 2, RaceDataBinding::getMetatableName());
    bool isAnimal = lua_toboolean(L, 3) != 0;
    bool result = instance->canEquip(race, isAnimal);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int LimiterBinding::_NV_canEquip(lua_State* L)
{
    Limiter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Limiter is nil");

    RaceData* race = checkObject<RaceData>(L, 2, RaceDataBinding::getMetatableName());
    bool isAnimal = lua_toboolean(L, 3) != 0;
    bool result = instance->_NV_canEquip(race, isAnimal);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int LimiterBinding::_CONSTRUCTOR(lua_State* L)
{
    Limiter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Limiter is nil");

    Limiter* result = instance->_CONSTRUCTOR();
    return pushObject<Limiter>(L, result, LimiterBinding::getMetatableName());
}

int LimiterBinding::_DESTRUCTOR(lua_State* L)
{
    Limiter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Limiter is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped properties needing manual binding:
  line 229: racesExclude (std::set<RaceData*, std::less<RaceData*>, Ogre::STLAllocator<RaceData*, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 230: racesInclude (std::set<RaceData*, std::less<RaceData*>, Ogre::STLAllocator<RaceData*, Ogre::GeneralAllocPolicy > >) - unsupported type
*/

int LimiterBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int LimiterBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Limiter object");
    return 1;
}



static int Limiter_get_racesExclude(lua_State* L)
{
    Limiter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Limiter is nil");
    // TODO: Unsupported type for racesExclude (std::set<RaceData*, std::less<RaceData*>, Ogre::STLAllocator<RaceData*, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'racesExclude' (type: std::set<RaceData*, std::less<RaceData*>, Ogre::STLAllocator<RaceData*, Ogre::GeneralAllocPolicy > >)");
}


static int Limiter_get_racesInclude(lua_State* L)
{
    Limiter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Limiter is nil");
    // TODO: Unsupported type for racesInclude (std::set<RaceData*, std::less<RaceData*>, Ogre::STLAllocator<RaceData*, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'racesInclude' (type: std::set<RaceData*, std::less<RaceData*>, Ogre::STLAllocator<RaceData*, Ogre::GeneralAllocPolicy > >)");
}


static int Limiter_set_racesExclude(lua_State* L)
{
    Limiter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Limiter is nil");
    return luaL_error(L, "Read-only or unsupported setter type for racesExclude");
}


static int Limiter_set_racesInclude(lua_State* L)
{
    Limiter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Limiter is nil");
    return luaL_error(L, "Read-only or unsupported setter type for racesInclude");
}


void LimiterBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       LimiterBinding::gc },
        { "__tostring", LimiterBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "canEquip", LimiterBinding::canEquip },
        { "_NV_canEquip", LimiterBinding::_NV_canEquip },
        { "_CONSTRUCTOR", LimiterBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", LimiterBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        LimiterBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, LimiterBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "racesExclude", Limiter_get_racesExclude);
    registerGetter(L, "racesInclude", Limiter_get_racesInclude);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "racesExclude", Limiter_set_racesExclude);
    registerSetter(L, "racesInclude", Limiter_set_racesInclude);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua