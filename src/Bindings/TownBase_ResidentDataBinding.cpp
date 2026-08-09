#include "pch.h"
#include "Bindings/TownBase_ResidentDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"

namespace KenshiLua
{

static TownBase::ResidentData* getInstance(lua_State* L, int idx)
{
    return checkObject<TownBase::ResidentData>(L, idx, TownBase_ResidentDataBinding::getMetatableName());
}

// --- Getters for ResidentData ---
static int ResidentData_get_data(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "TownBase::ResidentData is nil");
    return pushObject<GameData>(L, inst->data, GameDataBinding::getMetatableName());
}

static int ResidentData_get_buildingsBad(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "TownBase::ResidentData is nil");
    return pushObject<ogre_unordered_set<GameData*>::type>(L, &inst->buildingsBad, OgreUnorderedSetBinding<GameData*>::getMetatableName());
}

static int ResidentData_get_buildingsGood(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "TownBase::ResidentData is nil");
    return pushObject<ogre_unordered_set<GameData*>::type>(L, &inst->buildingsGood, OgreUnorderedSetBinding<GameData*>::getMetatableName());
}

static int ResidentData_get_count(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "TownBase::ResidentData is nil");
    lua_pushinteger(L, inst->count);
    return 1;
}

static int ResidentData_get_chance(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "TownBase::ResidentData is nil");
    lua_pushinteger(L, inst->chance);
    return 1;
}

static int ResidentData_get_priority(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "TownBase::ResidentData is nil");
    lua_pushinteger(L, inst->priority);
    return 1;
}

// --- Setters for ResidentData ---
static int ResidentData_set_data(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "TownBase::ResidentData is nil");
    inst->data = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int ResidentData_set_buildingsBad(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "TownBase::ResidentData is nil");
    auto* val = OgreUnorderedSetBinding<GameData*>::get(L, 2);
    if (val) inst->buildingsBad = *val;
    return 0;
}

static int ResidentData_set_buildingsGood(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "TownBase::ResidentData is nil");
    auto* val = OgreUnorderedSetBinding<GameData*>::get(L, 2);
    if (val) inst->buildingsGood = *val;
    return 0;
}

static int ResidentData_set_count(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "TownBase::ResidentData is nil");
    inst->count = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int ResidentData_set_chance(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "TownBase::ResidentData is nil");
    inst->chance = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int ResidentData_set_priority(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "TownBase::ResidentData is nil");
    inst->priority = (int)luaL_checkinteger(L, 2);
    return 0;
}

int TownBase_ResidentDataBinding::_CONSTRUCTOR(lua_State* L)
{
    auto* obj = (TownBase::ResidentData*)::operator new(sizeof(TownBase::ResidentData));
    ::new ((void*)obj) TownBase::ResidentData();
    if (lua_gettop(L) >= 4)
        obj->count = (int)luaL_checkinteger(L, 4);
    if (lua_gettop(L) >= 5)
        obj->chance = (int)luaL_checkinteger(L, 5);
    if (lua_gettop(L) >= 6)
        obj->priority = (int)luaL_checkinteger(L, 6);
    return pushObject<TownBase::ResidentData>(L, obj, getMetatableName());
}

int TownBase_ResidentDataBinding::_DESTRUCTOR(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "TownBase::ResidentData is nil");
    inst->~ResidentData();
    return 0;
}

int TownBase_ResidentDataBinding::gc(lua_State* L)
{
    return 0;
}

int TownBase_ResidentDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TownBase_ResidentData object");
    return 1;
}

int TownBase_ResidentDataBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (a->data == b->data && a->buildingsBad == b->buildingsBad && a->buildingsGood == b->buildingsGood && a->count == b->count && a->chance == b->chance && a->priority == b->priority)) ? 1 : 0);
    return 1;
}

void TownBase_ResidentDataBinding::registerBinding(lua_State* L)
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
    registerGetter(L, "data", ResidentData_get_data);
    registerGetter(L, "buildingsBad", ResidentData_get_buildingsBad);
    registerGetter(L, "buildingsGood", ResidentData_get_buildingsGood);
    registerGetter(L, "count", ResidentData_get_count);
    registerGetter(L, "chance", ResidentData_get_chance);
    registerGetter(L, "priority", ResidentData_get_priority);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "data", ResidentData_set_data);
    registerSetter(L, "buildingsBad", ResidentData_set_buildingsBad);
    registerSetter(L, "buildingsGood", ResidentData_set_buildingsGood);
    registerSetter(L, "count", ResidentData_set_count);
    registerSetter(L, "chance", ResidentData_set_chance);
    registerSetter(L, "priority", ResidentData_set_priority);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
