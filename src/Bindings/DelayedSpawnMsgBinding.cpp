#include "pch.h"
#include "kenshi\Town.h"
#include "DelayedSpawnMsgBinding.h"
#include "kenshi/Item.h"
#include "ItemBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/HandBinding.h"

typedef Town::DelayedSpawnMsg DelayedSpawnMsg;

namespace KenshiLua
{

static DelayedSpawnMsg* getB(lua_State* L, int idx)
{
    return checkObject<DelayedSpawnMsg>(L, idx, DelayedSpawnMsgBinding::getMetatableName());
}

// --- Getters for DelayedSpawnMsg ---
static int DelayedSpawnMsg_get_parentTown(lua_State* L)
{
    DelayedSpawnMsg* b = getB(L, 1);
    if (!b) return luaL_error(L, "DelayedSpawnMsg is nil");
    return handBinding::push(L, b->parentTown);
}

static int DelayedSpawnMsg_get_item(lua_State* L)
{
    DelayedSpawnMsg* b = getB(L, 1);
    if (!b) return luaL_error(L, "DelayedSpawnMsg is nil");
    return pushObject<Item>(L, b->item, ItemBinding::getMetatableName());
}

static int DelayedSpawnMsg_get_nestData(lua_State* L)
{
    DelayedSpawnMsg* b = getB(L, 1);
    if (!b) return luaL_error(L, "DelayedSpawnMsg is nil");
    return pushObject<GameData>(L, b->nestData, GameDataBinding::getMetatableName());
}

static int DelayedSpawnMsg_get_pos(lua_State* L)
{
    DelayedSpawnMsg* b = getB(L, 1);
    if (!b) return luaL_error(L, "DelayedSpawnMsg is nil");
    pushVector3(L, b->pos);
    return 1;
}

static int DelayedSpawnMsg_get_insideBuilding(lua_State* L)
{
    DelayedSpawnMsg* b = getB(L, 1);
    if (!b) return luaL_error(L, "DelayedSpawnMsg is nil");
    return handBinding::push(L, b->insideBuilding);
}

// --- Setters for DelayedSpawnMsg ---
static int DelayedSpawnMsg_set_parentTown(lua_State* L)
{
    DelayedSpawnMsg* b = getB(L, 1);
    if (!b) return luaL_error(L, "DelayedSpawnMsg is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->parentTown = *val;
    return 0;
}

static int DelayedSpawnMsg_set_item(lua_State* L)
{
    DelayedSpawnMsg* b = getB(L, 1);
    if (!b) return luaL_error(L, "DelayedSpawnMsg is nil");
    return luaL_error(L, "Read-only or unsupported setter type for item");
}

static int DelayedSpawnMsg_set_nestData(lua_State* L)
{
    DelayedSpawnMsg* b = getB(L, 1);
    if (!b) return luaL_error(L, "DelayedSpawnMsg is nil");
    return luaL_error(L, "Read-only or unsupported setter type for nestData");
}

static int DelayedSpawnMsg_set_pos(lua_State* L)
{
    DelayedSpawnMsg* b = getB(L, 1);
    if (!b) return luaL_error(L, "DelayedSpawnMsg is nil");
    readVector3(L, 2, b->pos);
    return 0;
}

static int DelayedSpawnMsg_set_insideBuilding(lua_State* L)
{
    DelayedSpawnMsg* b = getB(L, 1);
    if (!b) return luaL_error(L, "DelayedSpawnMsg is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->insideBuilding = *val;
    return 0;
}

/*
Skipped methods needing manual binding:
  line 320: DelayedSpawnMsg* _CONSTRUCTOR(...) - overloaded method
  line 322: DelayedSpawnMsg* _CONSTRUCTOR(...) - overloaded method
*/

int DelayedSpawnMsgBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DelayedSpawnMsgBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DelayedSpawnMsg object");
    return 1;
}

void DelayedSpawnMsgBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DelayedSpawnMsgBinding::gc },
        { "__tostring", DelayedSpawnMsgBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        DelayedSpawnMsgBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DelayedSpawnMsgBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, DelayedSpawnMsg_get_parentTown);
    lua_setfield(L, -2, "parentTown");
    lua_pushcfunction(L, DelayedSpawnMsg_get_item);
    lua_setfield(L, -2, "item");
    lua_pushcfunction(L, DelayedSpawnMsg_get_nestData);
    lua_setfield(L, -2, "nestData");
    lua_pushcfunction(L, DelayedSpawnMsg_get_pos);
    lua_setfield(L, -2, "pos");
    lua_pushcfunction(L, DelayedSpawnMsg_get_insideBuilding);
    lua_setfield(L, -2, "insideBuilding");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, DelayedSpawnMsg_set_parentTown);
    lua_setfield(L, -2, "parentTown");
    lua_pushcfunction(L, DelayedSpawnMsg_set_item);
    lua_setfield(L, -2, "item");
    lua_pushcfunction(L, DelayedSpawnMsg_set_nestData);
    lua_setfield(L, -2, "nestData");
    lua_pushcfunction(L, DelayedSpawnMsg_set_pos);
    lua_setfield(L, -2, "pos");
    lua_pushcfunction(L, DelayedSpawnMsg_set_insideBuilding);
    lua_setfield(L, -2, "insideBuilding");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua