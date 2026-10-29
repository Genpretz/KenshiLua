#include "pch.h"
#include "kenshi/Research.h"
#include "ResearchItemBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/GameDataBinding.h"

namespace KenshiLua
{

static_assert(offsetof(ResearchItem, data) == 0x0, "ResearchItem::data offset mismatch");
static_assert(offsetof(ResearchItem, progress) == 0x8, "ResearchItem::progress offset mismatch");

static ResearchItem* getInstance(lua_State* L, int idx)
{
    return checkObject<ResearchItem>(L, idx, ResearchItemBinding::getMetatableName());
}

static int ResearchItem_get_data(lua_State* L)
{
    ResearchItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchItem is nil");
    return pushObject<GameData>(L, instance->data, GameDataBinding::getMetatableName());
}

static int ResearchItem_set_data(lua_State* L)
{
    ResearchItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchItem is nil");
    instance->data = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int ResearchItem_get_progress(lua_State* L)
{
    ResearchItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchItem is nil");
    lua_pushnumber(L, instance->progress);
    return 1;
}

static int ResearchItem_set_progress(lua_State* L)
{
    ResearchItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchItem is nil");
    instance->progress = (float)luaL_checknumber(L, 2);
    return 0;
}

int ResearchItemBinding::getCostItem(lua_State* L)
{
    ResearchItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchItem is nil");

    int id = (int)luaL_checkinteger(L, 2);
    GameData* result = instance->getCostItem(id);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int ResearchItemBinding::getCostItemQuantity(lua_State* L)
{
    ResearchItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchItem is nil");

    int id = (int)luaL_checkinteger(L, 2);
    int result = instance->getCostItemQuantity(id);
    lua_pushinteger(L, result);
    return 1;
}

int ResearchItemBinding::getNumDifferentCostItems(lua_State* L)
{
    ResearchItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResearchItem is nil");

    int result = instance->getNumDifferentCostItems();
    lua_pushinteger(L, result);
    return 1;
}

int ResearchItemBinding::gc(lua_State* L)
{
    return 0;
}

int ResearchItemBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ResearchItem object");
    return 1;
}

void ResearchItemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ResearchItemBinding::gc },
        { "__tostring", ResearchItemBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getCostItem", ResearchItemBinding::getCostItem },
        { "getCostItemQuantity", ResearchItemBinding::getCostItemQuantity },
        { "getNumDifferentCostItems", ResearchItemBinding::getNumDifferentCostItems },
        { 0, 0 }
    };

    registerClass(
        L,
        ResearchItemBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ResearchItemBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "data", ResearchItem_get_data);
    registerGetter(L, "progress", ResearchItem_get_progress);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "data", ResearchItem_set_data);
    registerSetter(L, "progress", ResearchItem_set_progress);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
