#include "pch.h"
#include "Bindings/FarmBuilding_PlantSourceBinding.h"
#include "Lua/BindingHelpers.h"
#include <kenshi/Building/FarmBuilding.h>

#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{

static FarmBuilding::PlantSource* getInstance(lua_State* L, int idx)
{
    return checkObject<FarmBuilding::PlantSource>(L, idx, FarmBuilding_PlantSourceBinding::getMetatableName());
}

// --- Getters for PlantSource ---
static int PlantSource_get_data(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    return pushObject<GameData>(L, inst->data, GameDataBinding::getMetatableName());
}

static int PlantSource_get_mesh(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    lua_pushlightuserdata(L, (void*)&inst->mesh);

    return 1;
}

static int PlantSource_get_scaleStart(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    lua_pushnumber(L, inst->scaleStart);
    return 1;
}

static int PlantSource_get_scaleEnd(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    lua_pushnumber(L, inst->scaleEnd);
    return 1;
}

static int PlantSource_get_scaleVariance(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    lua_pushnumber(L, inst->scaleVariance);
    return 1;
}

static int PlantSource_get_offsetStart(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    lua_pushnumber(L, inst->offsetStart);
    return 1;
}

static int PlantSource_get_offsetEnd(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    lua_pushnumber(L, inst->offsetEnd);
    return 1;
}

static int PlantSource_get_delay(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    lua_pushnumber(L, inst->delay);
    return 1;
}

static int PlantSource_get_delayScale(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    lua_pushnumber(L, inst->delayScale);
    return 1;
}

static int PlantSource_get_isStatic(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    lua_pushboolean(L, inst->isStatic ? 1 : 0);
    return 1;
}

static int PlantSource_get_count(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    lua_pushinteger(L, inst->count);
    return 1;
}

static int PlantSource_get_group(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    lua_pushinteger(L, inst->group);
    return 1;
}

// --- Setters for PlantSource ---
static int PlantSource_set_data(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    inst->data = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int PlantSource_set_mesh(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    // Ogre::SharedPtr<Ogre::Mesh> is unbound - read-only

    return luaL_error(L, "mesh is read-only (Ogre::SharedPtr<Ogre::Mesh> is unbound)");
    return 0;
}

static int PlantSource_set_scaleStart(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    inst->scaleStart = (float)luaL_checknumber(L, 2);
    return 0;
}

static int PlantSource_set_scaleEnd(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    inst->scaleEnd = (float)luaL_checknumber(L, 2);
    return 0;
}

static int PlantSource_set_scaleVariance(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    inst->scaleVariance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int PlantSource_set_offsetStart(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    inst->offsetStart = (float)luaL_checknumber(L, 2);
    return 0;
}

static int PlantSource_set_offsetEnd(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    inst->offsetEnd = (float)luaL_checknumber(L, 2);
    return 0;
}

static int PlantSource_set_delay(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    inst->delay = (float)luaL_checknumber(L, 2);
    return 0;
}

static int PlantSource_set_delayScale(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    inst->delayScale = (float)luaL_checknumber(L, 2);
    return 0;
}

static int PlantSource_set_isStatic(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    inst->isStatic = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PlantSource_set_count(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    inst->count = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int PlantSource_set_group(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    inst->group = (int)luaL_checkinteger(L, 2);
    return 0;
}

int FarmBuilding_PlantSourceBinding::_CONSTRUCTOR(lua_State* L)
{
    auto* obj = (FarmBuilding::PlantSource*)::operator new(sizeof(FarmBuilding::PlantSource));
    ::new ((void*)obj) FarmBuilding::PlantSource();
    if (lua_gettop(L) >= 3)
        obj->scaleStart = (float)luaL_checknumber(L, 3);
    if (lua_gettop(L) >= 4)
        obj->scaleEnd = (float)luaL_checknumber(L, 4);
    if (lua_gettop(L) >= 5)
        obj->scaleVariance = (float)luaL_checknumber(L, 5);
    if (lua_gettop(L) >= 6)
        obj->offsetStart = (float)luaL_checknumber(L, 6);
    if (lua_gettop(L) >= 7)
        obj->offsetEnd = (float)luaL_checknumber(L, 7);
    if (lua_gettop(L) >= 8)
        obj->delay = (float)luaL_checknumber(L, 8);
    if (lua_gettop(L) >= 9)
        obj->delayScale = (float)luaL_checknumber(L, 9);
    if (lua_gettop(L) >= 10)
        obj->isStatic = lua_toboolean(L, 10) != 0;
    if (lua_gettop(L) >= 11)
        obj->count = (int)luaL_checkinteger(L, 11);
    if (lua_gettop(L) >= 12)
        obj->group = (int)luaL_checkinteger(L, 12);
    return pushObject<FarmBuilding::PlantSource>(L, obj, getMetatableName());
}

int FarmBuilding_PlantSourceBinding::_DESTRUCTOR(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "FarmBuilding::PlantSource is nil");
    inst->~PlantSource();
    return 0;
}

int FarmBuilding_PlantSourceBinding::gc(lua_State* L)
{
    return 0;
}

int FarmBuilding_PlantSourceBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FarmBuilding_PlantSource object");
    return 1;
}

int FarmBuilding_PlantSourceBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (a->data == b->data && a->mesh == b->mesh && a->scaleStart == b->scaleStart && a->scaleEnd == b->scaleEnd && a->scaleVariance == b->scaleVariance && a->offsetStart == b->offsetStart && a->offsetEnd == b->offsetEnd && a->delay == b->delay && a->delayScale == b->delayScale && a->isStatic == b->isStatic && a->count == b->count && a->group == b->group)) ? 1 : 0);
    return 1;
}

void FarmBuilding_PlantSourceBinding::registerBinding(lua_State* L)
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
    registerGetter(L, "data", PlantSource_get_data);
    registerGetter(L, "mesh", PlantSource_get_mesh);
    registerGetter(L, "scaleStart", PlantSource_get_scaleStart);
    registerGetter(L, "scaleEnd", PlantSource_get_scaleEnd);
    registerGetter(L, "scaleVariance", PlantSource_get_scaleVariance);
    registerGetter(L, "offsetStart", PlantSource_get_offsetStart);
    registerGetter(L, "offsetEnd", PlantSource_get_offsetEnd);
    registerGetter(L, "delay", PlantSource_get_delay);
    registerGetter(L, "delayScale", PlantSource_get_delayScale);
    registerGetter(L, "isStatic", PlantSource_get_isStatic);
    registerGetter(L, "count", PlantSource_get_count);
    registerGetter(L, "group", PlantSource_get_group);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "data", PlantSource_set_data);
    registerSetter(L, "mesh", PlantSource_set_mesh);
    registerSetter(L, "scaleStart", PlantSource_set_scaleStart);
    registerSetter(L, "scaleEnd", PlantSource_set_scaleEnd);
    registerSetter(L, "scaleVariance", PlantSource_set_scaleVariance);
    registerSetter(L, "offsetStart", PlantSource_set_offsetStart);
    registerSetter(L, "offsetEnd", PlantSource_set_offsetEnd);
    registerSetter(L, "delay", PlantSource_set_delay);
    registerSetter(L, "delayScale", PlantSource_set_delayScale);
    registerSetter(L, "isStatic", PlantSource_set_isStatic);
    registerSetter(L, "count", PlantSource_set_count);
    registerSetter(L, "group", PlantSource_set_group);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
