#include "pch.h"
#include "kenshi\Inventory.h"
#include "Inventory_HasRoomCacheBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/Util/StdMapBinding.h"

namespace KenshiLua
{

typedef StdMapBinding<GameData*, bool, std::less<GameData*>, std::allocator<std::pair<GameData* const, bool>>> GameDataBoolStdMapBinding;

static HasRoomCache* getInstance(lua_State* L, int idx)
{
    return checkObject<HasRoomCache>(L, idx, Inventory_HasRoomCacheBinding::getMetatableName());
}

// --- Getters for HasRoomCache ---
// --- Setters for HasRoomCache ---
int Inventory_HasRoomCacheBinding::modified(lua_State* L)
{
    HasRoomCache* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HasRoomCache is nil");

    instance->modified();
    return 0;
}

int Inventory_HasRoomCacheBinding::knowsAbout(lua_State* L)
{
    HasRoomCache* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HasRoomCache is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->knowsAbout(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int Inventory_HasRoomCacheBinding::hasRoomFor(lua_State* L)
{
    HasRoomCache* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HasRoomCache is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->hasRoomFor(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int Inventory_HasRoomCacheBinding::remember(lua_State* L)
{
    HasRoomCache* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HasRoomCache is nil");

    GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool state = lua_toboolean(L, 3) != 0;
    instance->remember(d, state);
    return 0;
}

int Inventory_HasRoomCacheBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int Inventory_HasRoomCacheBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Inventory_HasRoomCache object");
    return 1;
}

static int HasRoomCache_get_itemStates(lua_State* L)
{
    HasRoomCache* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HasRoomCache is nil");
    return pushObject<GameDataBoolStdMapBinding::MapType>(L, &instance->itemStates, GameDataBoolStdMapBinding::metaName);
}

static int HasRoomCache_set_itemStates(lua_State* L)
{
    HasRoomCache* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HasRoomCache is nil");
    GameDataBoolStdMapBinding::MapType* val = GameDataBoolStdMapBinding::get(L, 2);
    if (!val) return luaL_error(L, "Expected std::map<GameData*, bool>");
    instance->itemStates = *val;
    return 0;
}


void Inventory_HasRoomCacheBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       Inventory_HasRoomCacheBinding::gc },
        { "__tostring", Inventory_HasRoomCacheBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "modified", Inventory_HasRoomCacheBinding::modified },
        { "knowsAbout", Inventory_HasRoomCacheBinding::knowsAbout },
        { "hasRoomFor", Inventory_HasRoomCacheBinding::hasRoomFor },
        { "remember", Inventory_HasRoomCacheBinding::remember },
        { 0, 0 }
    };

    registerClass(
        L, 
        Inventory_HasRoomCacheBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, Inventory_HasRoomCacheBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "itemStates", HasRoomCache_get_itemStates);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "itemStates", HasRoomCache_set_itemStates);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua