#include "pch.h"
#include "Bindings/AkSoundPositionBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/AkVectorBinding.h"

namespace KenshiLua
{

static AkSoundPosition* getInstance(lua_State* L, int idx)
{
    return checkObject<AkSoundPosition>(L, idx, AkSoundPositionBinding::getMetatableName());
}

// --- Getters for AkSoundPosition ---
static int AkSoundPosition_get_Position(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AkSoundPosition is nil");
    return pushValue<AkVector>(L, inst->Position, AkVectorBinding::getMetatableName());
}

static int AkSoundPosition_get_Orientation(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AkSoundPosition is nil");
    return pushValue<AkVector>(L, inst->Orientation, AkVectorBinding::getMetatableName());
}

// --- Setters for AkSoundPosition ---
static int AkSoundPosition_set_Position(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AkSoundPosition is nil");
    auto* val = checkObject<AkVector>(L, 2, AkVectorBinding::getMetatableName());
    if (val) inst->Position = *val;
    return 0;
}

static int AkSoundPosition_set_Orientation(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AkSoundPosition is nil");
    auto* val = checkObject<AkVector>(L, 2, AkVectorBinding::getMetatableName());
    if (val) inst->Orientation = *val;
    return 0;
}

int AkSoundPositionBinding::gc(lua_State* L)
{
    return 0;
}

int AkSoundPositionBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AkSoundPosition object");
    return 1;
}

int AkSoundPositionBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (a == b)) ? 1 : 0);
    return 1;
}

void AkSoundPositionBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       operator_eq },
        { "__gc",       gc },
        { "__tostring", tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L); // __getters
    registerGetter(L, "Position", AkSoundPosition_get_Position);
    registerGetter(L, "Orientation", AkSoundPosition_get_Orientation);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "Position", AkSoundPosition_set_Position);
    registerSetter(L, "Orientation", AkSoundPosition_set_Orientation);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
