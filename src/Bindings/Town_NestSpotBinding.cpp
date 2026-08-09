#include "pch.h"
#include "Bindings/Town_NestSpotBinding.h"
#include "Lua/BindingHelpers.h"

#include "Bindings/GameDataBinding.h"

#include "Bindings/Util/HandBinding.h"

namespace KenshiLua
{

static Town::NestSpot* getInstance(lua_State* L, int idx)
{
    return checkObject<Town::NestSpot>(L, idx, Town_NestSpotBinding::getMetatableName());
}

// --- Getters for NestSpot ---
static int NestSpot_get_pos(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Town::NestSpot is nil");
    pushVector3(L, inst->pos);
    return 1;
}

static int NestSpot_get_data(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Town::NestSpot is nil");
    return pushObject<GameData>(L, inst->data, GameDataBinding::getMetatableName());
}

static int NestSpot_get_building(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Town::NestSpot is nil");
    return HandBinding::push(L, inst->building);
}

// --- Setters for NestSpot ---
static int NestSpot_set_pos(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Town::NestSpot is nil");
    readVector3(L, 2, inst->pos);
    return 0;
}

static int NestSpot_set_data(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Town::NestSpot is nil");
    inst->data = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int NestSpot_set_building(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Town::NestSpot is nil");
    auto* val = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (val) inst->building = *val;
    return 0;
}

int Town_NestSpotBinding::_CONSTRUCTOR(lua_State* L)
{
    auto* obj = (Town::NestSpot*)::operator new(sizeof(Town::NestSpot));
    ::new ((void*)obj) Town::NestSpot();
    if (lua_gettop(L) >= 1)
        readVector3(L, 1, obj->pos);
    return pushObject<Town::NestSpot>(L, obj, getMetatableName());
}

int Town_NestSpotBinding::_DESTRUCTOR(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Town::NestSpot is nil");
    inst->~NestSpot();
    return 0;
}

int Town_NestSpotBinding::gc(lua_State* L)
{
    return 0;
}

int Town_NestSpotBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Town_NestSpot object");
    return 1;
}

int Town_NestSpotBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (a->pos == b->pos && a->data == b->data && a->building == b->building)) ? 1 : 0);
    return 1;
}

void Town_NestSpotBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       operator_eq },
        { "__gc",       gc },
        { "__tostring", tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", _CONSTRUCTOR },
        { "_DESTRUCTOR",  _DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L); // __getters
    registerGetter(L, "pos", NestSpot_get_pos);
    registerGetter(L, "data", NestSpot_get_data);
    registerGetter(L, "building", NestSpot_get_building);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "pos", NestSpot_set_pos);
    registerSetter(L, "data", NestSpot_set_data);
    registerSetter(L, "building", NestSpot_set_building);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
