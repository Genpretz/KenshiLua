#include "pch.h"
#include "kenshi\Town.h"
#include "DelayedSpawnMsgBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "ItemBinding.h"
#include "kenshi/Item.h"

namespace KenshiLua
{

static DelayedSpawnMsg* getInstance(lua_State* L, int idx)
{
    return checkObject<DelayedSpawnMsg>(L, idx, DelayedSpawnMsgBinding::getMetatableName());
}

// --- Getters for DelayedSpawnMsg ---
static int DelayedSpawnMsg_get_parentTown(lua_State* L)
{
    DelayedSpawnMsg* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DelayedSpawnMsg is nil");
    return handBinding::push(L, instance->parentTown);
}

static int DelayedSpawnMsg_get_item(lua_State* L)
{
    DelayedSpawnMsg* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DelayedSpawnMsg is nil");
    return pushObject<Item>(L, instance->item, ItemBinding::getMetatableName());
}

static int DelayedSpawnMsg_get_nestData(lua_State* L)
{
    DelayedSpawnMsg* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DelayedSpawnMsg is nil");
    return pushObject<GameData>(L, instance->nestData, GameDataBinding::getMetatableName());
}

static int DelayedSpawnMsg_get_pos(lua_State* L)
{
    DelayedSpawnMsg* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DelayedSpawnMsg is nil");
    pushVector3(L, instance->pos);
    return 1;
}

static int DelayedSpawnMsg_get_insideBuilding(lua_State* L)
{
    DelayedSpawnMsg* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DelayedSpawnMsg is nil");
    return handBinding::push(L, instance->insideBuilding);
}

// --- Setters for DelayedSpawnMsg ---
static int DelayedSpawnMsg_set_parentTown(lua_State* L)
{
    DelayedSpawnMsg* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DelayedSpawnMsg is nil");
    instance->parentTown = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int DelayedSpawnMsg_set_item(lua_State* L)
{
    DelayedSpawnMsg* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DelayedSpawnMsg is nil");
    instance->item = lua_isnoneornil(L, 2) ? nullptr : checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    return 0;
}

static int DelayedSpawnMsg_set_nestData(lua_State* L)
{
    DelayedSpawnMsg* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DelayedSpawnMsg is nil");
    instance->nestData = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int DelayedSpawnMsg_set_pos(lua_State* L)
{
    DelayedSpawnMsg* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DelayedSpawnMsg is nil");
    readVector3(L, 2, instance->pos);
    return 0;
}

static int DelayedSpawnMsg_set_insideBuilding(lua_State* L)
{
    DelayedSpawnMsg* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DelayedSpawnMsg is nil");
    instance->insideBuilding = *checkObject<hand>(L, 2, handBinding::getMetatableName());
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
    registerGetter(L, "parentTown", DelayedSpawnMsg_get_parentTown);
    registerGetter(L, "item", DelayedSpawnMsg_get_item);
    registerGetter(L, "nestData", DelayedSpawnMsg_get_nestData);
    registerGetter(L, "pos", DelayedSpawnMsg_get_pos);
    registerGetter(L, "insideBuilding", DelayedSpawnMsg_get_insideBuilding);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "parentTown", DelayedSpawnMsg_set_parentTown);
    registerSetter(L, "item", DelayedSpawnMsg_set_item);
    registerSetter(L, "nestData", DelayedSpawnMsg_set_nestData);
    registerSetter(L, "pos", DelayedSpawnMsg_set_pos);
    registerSetter(L, "insideBuilding", DelayedSpawnMsg_set_insideBuilding);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua