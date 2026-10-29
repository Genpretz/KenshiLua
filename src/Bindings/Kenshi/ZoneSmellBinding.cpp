#include "pch.h"
#include "kenshi/ZoneSmell.h"
#include "ZoneSmellBinding.h"
#include "ZoneSmell_SmellBinding.h"
#include "ZoneSmell_SmellMsgBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/ZoneMapBinding.h"

namespace KenshiLua
{

static_assert(offsetof(ZoneSmell, smell_bloodAndCorpses) == 0x0, "ZoneSmell::smell_bloodAndCorpses offset mismatch");
static_assert(offsetof(ZoneSmell, smell_eggs) == 0x8, "ZoneSmell::smell_eggs offset mismatch");
static_assert(offsetof(ZoneSmell, zoneMap) == 0x38, "ZoneSmell::zoneMap offset mismatch");

static ZoneSmell* getInstance(lua_State* L, int idx)
{
    return checkObject<ZoneSmell>(L, idx, ZoneSmellBinding::getMetatableName());
}

static int ZoneSmell_get_smell_bloodAndCorpses(lua_State* L)
{
    ZoneSmell* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSmell is nil");
    if (!instance->smell_bloodAndCorpses) { lua_pushnil(L); return 1; }
    return pushObject<ZoneSmell::Smell>(L, instance->smell_bloodAndCorpses, ZoneSmell_SmellBinding::getMetatableName());
}

static int ZoneSmell_get_smell_eggs(lua_State* L)
{
    ZoneSmell* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSmell is nil");
    if (!instance->smell_eggs) { lua_pushnil(L); return 1; }
    return pushObject<ZoneSmell::Smell>(L, instance->smell_eggs, ZoneSmell_SmellBinding::getMetatableName());
}

static int ZoneSmell_get_zoneMap(lua_State* L)
{
    ZoneSmell* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSmell is nil");
    if (!instance->zoneMap) { lua_pushnil(L); return 1; }
    return pushObject<ZoneMap>(L, instance->zoneMap, ZoneMapBinding::getMetatableName());
}

static int ZoneSmell_set_zoneMap(lua_State* L)
{
    ZoneSmell* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSmell is nil");
    instance->zoneMap = lua_isnoneornil(L, 2) ? nullptr : checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    return 0;
}

int ZoneSmellBinding::_getSmell(lua_State* L)
{
    ZoneSmell* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSmell is nil");

    SmellType t = (SmellType)luaL_checkinteger(L, 2);
    ZoneSmell::Smell* result = instance->_getSmell(t);
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<ZoneSmell::Smell>(L, result, ZoneSmell_SmellBinding::getMetatableName());
}

int ZoneSmellBinding::isEmpty(lua_State* L)
{
    ZoneSmell* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSmell is nil");

    bool result = instance->isEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneSmellBinding::getSmell(lua_State* L)
{
    ZoneSmell* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSmell is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    SmellType type = (SmellType)luaL_checkinteger(L, 3);
    float result = instance->getSmell(pos, type);
    lua_pushnumber(L, result);
    pushVector3(L, pos);
    return 2;
}

int ZoneSmellBinding::getGeneralSmellLevel(lua_State* L)
{
    ZoneSmell* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSmell is nil");

    SmellType type = (SmellType)luaL_checkinteger(L, 2);
    float result = instance->getGeneralSmellLevel(type);
    lua_pushnumber(L, result);
    return 1;
}

int ZoneSmellBinding::periodicUpdate(lua_State* L)
{
    ZoneSmell* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSmell is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->periodicUpdate(time);
    return 0;
}

int ZoneSmellBinding::addSmell(lua_State* L)
{
    ZoneSmell* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSmell is nil");

    ZoneSmell::SmellMessageType type = (ZoneSmell::SmellMessageType)luaL_checkinteger(L, 2);
    void* key = lua_touserdata(L, 3);
    Ogre::Vector3 pos;
    readVector3(L, 4, pos);
    instance->addSmell(type, key, pos);
    return 0;
}

int ZoneSmellBinding::gc(lua_State* L)
{
    return 0;
}

int ZoneSmellBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ZoneSmell object");
    return 1;
}

void ZoneSmellBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ZoneSmellBinding::gc },
        { "__tostring", ZoneSmellBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_getSmell", ZoneSmellBinding::_getSmell },
        { "isEmpty", ZoneSmellBinding::isEmpty },
        { "getSmell", ZoneSmellBinding::getSmell },
        { "getGeneralSmellLevel", ZoneSmellBinding::getGeneralSmellLevel },
        { "periodicUpdate", ZoneSmellBinding::periodicUpdate },
        { "addSmell", ZoneSmellBinding::addSmell },
        { 0, 0 }
    };

    registerClass(
        L,
        ZoneSmellBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ZoneSmellBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "smell_bloodAndCorpses", ZoneSmell_get_smell_bloodAndCorpses);
    registerGetter(L, "smell_eggs", ZoneSmell_get_smell_eggs);
    registerGetter(L, "zoneMap", ZoneSmell_get_zoneMap);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "zoneMap", ZoneSmell_set_zoneMap);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
