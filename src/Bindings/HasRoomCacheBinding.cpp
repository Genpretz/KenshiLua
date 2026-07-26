#include "pch.h"
#include "kenshi\Inventory.h"
#include "HasRoomCacheBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{

static HasRoomCache* getInstance(lua_State* L, int idx)
{
    return checkObject<HasRoomCache>(L, idx, HasRoomCacheBinding::getMetatableName());
}

// --- Getters for HasRoomCache ---
// --- Setters for HasRoomCache ---
int HasRoomCacheBinding::modified(lua_State* L)
{
    HasRoomCache* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HasRoomCache is nil");

    instance->modified();
    return 0;
}

int HasRoomCacheBinding::knowsAbout(lua_State* L)
{
    HasRoomCache* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HasRoomCache is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->knowsAbout(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int HasRoomCacheBinding::hasRoomFor(lua_State* L)
{
    HasRoomCache* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HasRoomCache is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->hasRoomFor(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int HasRoomCacheBinding::remember(lua_State* L)
{
    HasRoomCache* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HasRoomCache is nil");

    GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool state = lua_toboolean(L, 3) != 0;
    instance->remember(d, state);
    return 0;
}

int HasRoomCacheBinding::_CONSTRUCTOR(lua_State* L)
{
    HasRoomCache* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HasRoomCache is nil");

    HasRoomCache* result = instance->_CONSTRUCTOR();
    return pushObject<HasRoomCache>(L, result, HasRoomCacheBinding::getMetatableName());
}

int HasRoomCacheBinding::_DESTRUCTOR(lua_State* L)
{
    HasRoomCache* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HasRoomCache is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped properties needing manual binding:
  line 156: itemStates (std::map<GameData*, bool, std::less<GameData*>, std::allocator<std::pair<GameData*const, bool> > >) - unsupported type
*/

int HasRoomCacheBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int HasRoomCacheBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.HasRoomCache object");
    return 1;
}



static int HasRoomCache_get_itemStates(lua_State* L)
{
    HasRoomCache* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HasRoomCache is nil");
    // TODO: Unsupported type for itemStates (std::map<GameData*, bool, std::less<GameData*>, std::allocator<std::pair<GameData*const, bool> > >)
    return luaL_error(L, "Unsupported property 'itemStates' (type: std::map<GameData*, bool, std::less<GameData*>, std::allocator<std::pair<GameData*const, bool> > >)");
}


static int HasRoomCache_set_itemStates(lua_State* L)
{
    HasRoomCache* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HasRoomCache is nil");
    return luaL_error(L, "Read-only or unsupported setter type for itemStates");
}


void HasRoomCacheBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       HasRoomCacheBinding::gc },
        { "__tostring", HasRoomCacheBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "modified", HasRoomCacheBinding::modified },
        { "knowsAbout", HasRoomCacheBinding::knowsAbout },
        { "hasRoomFor", HasRoomCacheBinding::hasRoomFor },
        { "remember", HasRoomCacheBinding::remember },
        { "_CONSTRUCTOR", HasRoomCacheBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", HasRoomCacheBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        HasRoomCacheBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, HasRoomCacheBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
        registerGetter(L, "itemStates", HasRoomCache_get_itemStates);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
        registerSetter(L, "itemStates", HasRoomCache_set_itemStates);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua