#include "pch.h"
#include "Bindings/Building/ConsumptionItemBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Building/StorageBuilding.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static ConsumptionItem* getS(lua_State* L, int idx)
{
    return checkObject<ConsumptionItem>(L, idx, ConsumptionItemBinding::getMetatableName());
}

int ConsumptionItemBinding::gc(lua_State* L) { return noopGc(L); }

int ConsumptionItemBinding::tostring(lua_State* L)
{
    ConsumptionItem* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int ConsumptionItemBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, ConsumptionItemBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    ConsumptionItem* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    if (strcmp(key, "amount") == 0) { lua_pushnumber(L, s->amount); return 1; }
    if (strcmp(key, "rate") == 0) { lua_pushnumber(L, s->rate); return 1; }
    if (strcmp(key, "maxCapacity") == 0) { lua_pushinteger(L, s->maxCapacity); return 1; }
    if (strcmp(key, "item") == 0) { return pushObject<GameData>(L, s->item, GameDataBinding::getMetatableName()); }
    if (strcmp(key, "inventorySection") == 0) { return pushObject<InventorySection>(L, s->inventorySection, InventorySectionBinding::getMetatableName()); }

    lua_pushnil(L);
    return 1;
}

int ConsumptionItemBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    ConsumptionItem* s = getS(L, 1);
    if (!s) return luaL_error(L, "ConsumptionItem is nil");

    if (strcmp(key, "amount") == 0) { s->amount = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "rate") == 0) { s->rate = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "maxCapacity") == 0) { s->maxCapacity = (int)luaL_checkinteger(L, 3); return 0; }
    // TODO GameData* item; unsupported __newindex type from header line 43
    // TODO InventorySection* inventorySection; unsupported __newindex type from header line 44

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int ConsumptionItemBinding::isFull(lua_State* L)
{
    ConsumptionItem* s = getS(L, 1);
    if (!s) return luaL_error(L, "ConsumptionItem is nil");

    bool result = s->isFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ConsumptionItemBinding::isEmpty(lua_State* L)
{
    ConsumptionItem* s = getS(L, 1);
    if (!s) return luaL_error(L, "ConsumptionItem is nil");

    bool result = s->isEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 35: ConsumptionItem* _CONSTRUCTOR(...) - overloaded method
  line 37: ConsumptionItem* _CONSTRUCTOR(...) - overloaded method
*/

void ConsumptionItemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ConsumptionItemBinding::gc },
        { "__tostring", ConsumptionItemBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "isFull", ConsumptionItemBinding::isFull },
        { "isEmpty", ConsumptionItemBinding::isEmpty },
        { 0, 0 }
    };
    registerClass(L, ConsumptionItemBinding::getMetatableName(), meta, methods, ConsumptionItemBinding::index, ConsumptionItemBinding::newindex);
}

} // namespace KenshiLua