#include "pch.h"
#include "kenshi\Inventory.h"
#include "HasRoomCacheBinding.h"
#include "Lua/BindingHelpers.h"

typedef Inventory::HasRoomCache HasRoomCache;

namespace KenshiLua
{

static HasRoomCache* getB(lua_State* L, int idx)
{
    return checkObject<HasRoomCache>(L, idx, HasRoomCacheBinding::getMetatableName());
}

// --- Getters for HasRoomCache ---
static int HasRoomCache_get_itemStates(lua_State* L)
{
    HasRoomCache* b = getB(L, 1);
    if (!b) return luaL_error(L, "HasRoomCache is nil");
    // TODO: Unsupported type for itemStates (std::map<GameData*, bool, std::less<GameData*>, std::allocator<std::pair<GameData*const, bool> > >)
    lua_pushnil(L);
    return 1;
}

// --- Setters for HasRoomCache ---
static int HasRoomCache_set_itemStates(lua_State* L)
{
    HasRoomCache* b = getB(L, 1);
    if (!b) return luaL_error(L, "HasRoomCache is nil");
    return luaL_error(L, "Read-only or unsupported setter type for itemStates");
}

int HasRoomCacheBinding::modified(lua_State* L)
{
    HasRoomCache* b = getB(L, 1);
    if (!b) return luaL_error(L, "HasRoomCache is nil");

    b->modified();
    return 0;
}

int HasRoomCacheBinding::_DESTRUCTOR(lua_State* L)
{
    HasRoomCache* b = getB(L, 1);
    if (!b) return luaL_error(L, "HasRoomCache is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 158: bool knowsAbout(...) - unsupported arg type
  line 159: bool hasRoomFor(...) - unsupported arg type
  line 160: void remember(...) - unsupported arg type
  line 163: HasRoomCache* _CONSTRUCTOR(...) - unsupported return type
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

void HasRoomCacheBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       HasRoomCacheBinding::gc },
        { "__tostring", HasRoomCacheBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "modified", HasRoomCacheBinding::modified },
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
    lua_pushcfunction(L, HasRoomCache_get_itemStates);
    lua_setfield(L, -2, "itemStates");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, HasRoomCache_set_itemStates);
    lua_setfield(L, -2, "itemStates");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua