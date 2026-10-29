#include "pch.h"
#include "kenshi/GunClass.h"
#include "GunClassPersonalBinding.h"
#include "GunClassBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Util/HandBinding.h"

namespace KenshiLua
{

static_assert(offsetof(GunClassPersonal, minDamage) == 0x118, "GunClassPersonal::minDamage offset mismatch");
static_assert(offsetof(GunClassPersonal, maxDamage) == 0x11C, "GunClassPersonal::maxDamage offset mismatch");
static_assert(offsetof(GunClassPersonal, animReadyToShoot) == 0x120, "GunClassPersonal::animReadyToShoot offset mismatch");
static_assert(offsetof(GunClassPersonal, character) == 0x128, "GunClassPersonal::character offset mismatch");

static GunClassPersonal* getInstance(lua_State* L, int idx)
{
    return checkObject<GunClassPersonal>(L, idx, GunClassPersonalBinding::getMetatableName());
}

static int GunClassPersonal_get_minDamage(lua_State* L)
{
    GunClassPersonal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClassPersonal is nil");
    lua_pushinteger(L, instance->minDamage);
    return 1;
}

static int GunClassPersonal_set_minDamage(lua_State* L)
{
    GunClassPersonal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClassPersonal is nil");
    instance->minDamage = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int GunClassPersonal_get_maxDamage(lua_State* L)
{
    GunClassPersonal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClassPersonal is nil");
    lua_pushinteger(L, instance->maxDamage);
    return 1;
}

static int GunClassPersonal_set_maxDamage(lua_State* L)
{
    GunClassPersonal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClassPersonal is nil");
    instance->maxDamage = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int GunClassPersonal_get_animReadyToShoot(lua_State* L)
{
    GunClassPersonal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClassPersonal is nil");
    lua_pushboolean(L, instance->animReadyToShoot ? 1 : 0);
    return 1;
}

static int GunClassPersonal_set_animReadyToShoot(lua_State* L)
{
    GunClassPersonal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClassPersonal is nil");
    instance->animReadyToShoot = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GunClassPersonal_get_character(lua_State* L)
{
    GunClassPersonal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClassPersonal is nil");
    return HandBinding::push(L, instance->character);
}

static int GunClassPersonal_set_character(lua_State* L)
{
    GunClassPersonal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClassPersonal is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (h) instance->character = *h;
    return 0;
}

int GunClassPersonalBinding::clearEntitesPtr(lua_State* L)
{
    GunClassPersonal* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClassPersonal is nil");
    instance->clearEntitesPtr();
    return 0;
}

int GunClassPersonalBinding::gc(lua_State* L)
{
    return noopGc(L);
}

int GunClassPersonalBinding::tostring(lua_State* L)
{
    GunClassPersonal* instance = getInstance(L, 1);
    if (!instance) {
        lua_pushstring(L, "GunClassPersonal(nil)");
    } else {
        lua_pushfstring(L, "GunClassPersonal(%p)", instance);
    }
    return 1;
}

void GunClassPersonalBinding::registerBinding(lua_State* L)
{
    luaL_Reg meta[] = {
        { "__gc", GunClassPersonalBinding::gc },
        { "__tostring", GunClassPersonalBinding::tostring },
        { 0, 0 }
    };

    luaL_Reg methods[] = {
        { "clearEntitesPtr", GunClassPersonalBinding::clearEntitesPtr },
        { 0, 0 }
    };

    registerClass(
        L,
        GunClassPersonalBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, GunClassPersonalBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "minDamage", GunClassPersonal_get_minDamage);
    registerGetter(L, "maxDamage", GunClassPersonal_get_maxDamage);
    registerGetter(L, "animReadyToShoot", GunClassPersonal_get_animReadyToShoot);
    registerGetter(L, "character", GunClassPersonal_get_character);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "minDamage", GunClassPersonal_set_minDamage);
    registerSetter(L, "maxDamage", GunClassPersonal_set_maxDamage);
    registerSetter(L, "animReadyToShoot", GunClassPersonal_set_animReadyToShoot);
    registerSetter(L, "character", GunClassPersonal_set_character);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
