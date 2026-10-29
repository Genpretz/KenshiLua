#include "pch.h"
#include "kenshi/ZoneSmell.h"
#include "ZoneSmell_SmellBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static_assert(offsetof(ZoneSmell::Smell, decreaseRate) == 0x8, "ZoneSmell::Smell::decreaseRate offset mismatch");
static_assert(offsetof(ZoneSmell::Smell, increaseRate) == 0xC, "ZoneSmell::Smell::increaseRate offset mismatch");
static_assert(offsetof(ZoneSmell::Smell, pos) == 0x10, "ZoneSmell::Smell::pos offset mismatch");
static_assert(offsetof(ZoneSmell::Smell, numSources) == 0x1C, "ZoneSmell::Smell::numSources offset mismatch");
static_assert(offsetof(ZoneSmell::Smell, strength) == 0x20, "ZoneSmell::Smell::strength offset mismatch");

static ZoneSmell::Smell* getInstance(lua_State* L, int idx)
{
    return checkObject<ZoneSmell::Smell>(L, idx, ZoneSmell_SmellBinding::getMetatableName());
}

static int Smell_get_decreaseRate(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneSmell::Smell is nil");
    lua_pushnumber(L, inst->decreaseRate);
    return 1;
}

static int Smell_set_decreaseRate(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneSmell::Smell is nil");
    inst->decreaseRate = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Smell_get_increaseRate(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneSmell::Smell is nil");
    lua_pushnumber(L, inst->increaseRate);
    return 1;
}

static int Smell_set_increaseRate(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneSmell::Smell is nil");
    inst->increaseRate = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Smell_get_pos(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneSmell::Smell is nil");
    pushVector3(L, inst->pos);
    return 1;
}

static int Smell_set_pos(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneSmell::Smell is nil");
    readVector3(L, 2, inst->pos);
    return 0;
}

static int Smell_get_numSources(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneSmell::Smell is nil");
    lua_pushnumber(L, inst->numSources);
    return 1;
}

static int Smell_set_numSources(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneSmell::Smell is nil");
    inst->numSources = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Smell_get_strength(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneSmell::Smell is nil");
    lua_pushnumber(L, inst->strength);
    return 1;
}

static int Smell_set_strength(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneSmell::Smell is nil");
    inst->strength = (float)luaL_checknumber(L, 2);
    return 0;
}

int ZoneSmell_SmellBinding::update(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneSmell::Smell is nil");
    float time = (float)luaL_checknumber(L, 2);
    inst->update(time);
    return 0;
}

int ZoneSmell_SmellBinding::_NV_update(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneSmell::Smell is nil");
    float time = (float)luaL_checknumber(L, 2);
    inst->_NV_update(time);
    return 0;
}

int ZoneSmell_SmellBinding::gc(lua_State* L)
{
    return 0;
}

int ZoneSmell_SmellBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ZoneSmell_Smell object");
    return 1;
}

void ZoneSmell_SmellBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ZoneSmell_SmellBinding::gc },
        { "__tostring", ZoneSmell_SmellBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "update", ZoneSmell_SmellBinding::update },
        { "_NV_update", ZoneSmell_SmellBinding::_NV_update },
        { 0, 0 }
    };

    registerClass(
        L,
        ZoneSmell_SmellBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ZoneSmell_SmellBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "decreaseRate", Smell_get_decreaseRate);
    registerGetter(L, "increaseRate", Smell_get_increaseRate);
    registerGetter(L, "pos", Smell_get_pos);
    registerGetter(L, "numSources", Smell_get_numSources);
    registerGetter(L, "strength", Smell_get_strength);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "decreaseRate", Smell_set_decreaseRate);
    registerSetter(L, "increaseRate", Smell_set_increaseRate);
    registerSetter(L, "pos", Smell_set_pos);
    registerSetter(L, "numSources", Smell_set_numSources);
    registerSetter(L, "strength", Smell_set_strength);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
