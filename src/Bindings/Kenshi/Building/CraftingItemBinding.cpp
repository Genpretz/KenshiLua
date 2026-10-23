#include "pch.h"
#include <kenshi/Building/CraftingBuilding.h>
#include "CraftingItemBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/ItemBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/Util/YesNoMaybeBinding.h"

namespace KenshiLua
{

// std::deque<CraftingItem> indexing depends on the element size matching the game's.
static_assert(sizeof(CraftingItem) == 0x68, "CraftingItem size does not match the game");

static CraftingItem* getInstance(lua_State* L, int idx)
{
    return checkObject<CraftingItem>(L, idx, CraftingItemBinding::getMetatableName());
}

// --- Getters for CraftingItem ---
static int CraftingItem_get_item(lua_State* L)
{
    CraftingItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingItem is nil");
    return pushObject<Item>(L, instance->item, ItemBinding::getMetatableName());
}

static int CraftingItem_get_endTime(lua_State* L)
{
    CraftingItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingItem is nil");
    lua_pushnumber(L, instance->endTime);
    return 1;
}

static int CraftingItem_get_progress01(lua_State* L)
{
    CraftingItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingItem is nil");
    lua_pushnumber(L, instance->progress01);
    return 1;
}

static int CraftingItem_get_smithBench(lua_State* L)
{
    CraftingItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingItem is nil");
    return HandBinding::push(L, instance->smithBench);
}

static int CraftingItem_get_rate(lua_State* L)
{
    CraftingItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingItem is nil");
    lua_pushnumber(L, instance->rate);
    return 1;
}

static int CraftingItem_get_name(lua_State* L)
{
    CraftingItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingItem is nil");
    lua_pushstring(L, instance->name.c_str());
    return 1;
}

static int CraftingItem_get_lastErrorCode(lua_State* L)
{
    CraftingItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingItem is nil");
    lua_pushinteger(L, instance->lastErrorCode);
    return 1;
}

static int CraftingItem_get_criticalSuccess(lua_State* L)
{
    CraftingItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingItem is nil");
    return pushObject<YesNoMaybe>(L, &instance->criticalSuccess, YesNoMaybeBinding::getMetatableName());
}

// --- Setters for CraftingItem ---
// ~CraftingItem frees only name, so the queue entry does not own item.
static int CraftingItem_set_item(lua_State* L)
{
    CraftingItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingItem is nil");
    instance->item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    return 0;
}

static int CraftingItem_set_endTime(lua_State* L)
{
    CraftingItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingItem is nil");
    instance->endTime = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CraftingItem_set_progress01(lua_State* L)
{
    CraftingItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingItem is nil");
    instance->progress01 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CraftingItem_set_smithBench(lua_State* L)
{
    CraftingItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingItem is nil");
    instance->smithBench = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int CraftingItem_set_rate(lua_State* L)
{
    CraftingItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingItem is nil");
    instance->rate = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CraftingItem_set_name(lua_State* L)
{
    CraftingItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingItem is nil");
    instance->name = luaL_checkstring(L, 2);
    return 0;
}

static int CraftingItem_set_lastErrorCode(lua_State* L)
{
    CraftingItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingItem is nil");
    instance->lastErrorCode = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CraftingItem_set_criticalSuccess(lua_State* L)
{
    CraftingItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingItem is nil");
    instance->criticalSuccess = *checkObject<YesNoMaybe>(L, 2, YesNoMaybeBinding::getMetatableName());
    return 0;
}

/*
Skipped methods needing manual binding:
  line 24: CraftingItem(...) - non-exported in KenshiLib
  line 26: CraftingItem(...) - non-exported in KenshiLib
  line 36: ~CraftingItem(...) - non-exported in KenshiLib
  line 38: CraftingItem& operator=(...) - non-exported in KenshiLib
*/

int CraftingItemBinding::gc(lua_State* L)
{
    // Borrowed from the owning CraftingBuilding's queue
    return 0;
}

int CraftingItemBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CraftingItem object");
    return 1;
}

void CraftingItemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CraftingItemBinding::gc },
        { "__tostring", CraftingItemBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L,
        CraftingItemBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CraftingItemBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "item", CraftingItem_get_item);
    registerGetter(L, "endTime", CraftingItem_get_endTime);
    registerGetter(L, "progress01", CraftingItem_get_progress01);
    registerGetter(L, "smithBench", CraftingItem_get_smithBench);
    registerGetter(L, "rate", CraftingItem_get_rate);
    registerGetter(L, "name", CraftingItem_get_name);
    registerGetter(L, "lastErrorCode", CraftingItem_get_lastErrorCode);
    registerGetter(L, "criticalSuccess", CraftingItem_get_criticalSuccess);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "item", CraftingItem_set_item);
    registerSetter(L, "endTime", CraftingItem_set_endTime);
    registerSetter(L, "progress01", CraftingItem_set_progress01);
    registerSetter(L, "smithBench", CraftingItem_set_smithBench);
    registerSetter(L, "rate", CraftingItem_set_rate);
    registerSetter(L, "name", CraftingItem_set_name);
    registerSetter(L, "lastErrorCode", CraftingItem_set_lastErrorCode);
    registerSetter(L, "criticalSuccess", CraftingItem_set_criticalSuccess);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
