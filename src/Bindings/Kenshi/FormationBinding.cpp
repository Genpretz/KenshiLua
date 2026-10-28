#include "pch.h"
#include "kenshi/CharMovement.h"
#include "FormationBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/RootObjectBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"

namespace KenshiLua
{

static_assert(offsetof(Formation, character) == 0x8, "Formation::character offset mismatch");
static_assert(offsetof(Formation, followers) == 0x10, "Formation::followers offset mismatch");

static Formation* getInstance(lua_State* L, int idx)
{
    return checkObject<Formation>(L, idx, FormationBinding::getMetatableName());
}

static int Formation_get_character(lua_State* L)
{
    Formation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Formation is nil");
    return pushObject<RootObject>(L, instance->character, RootObjectBinding::getMetatableName());
}

static int Formation_set_character(lua_State* L)
{
    Formation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Formation is nil");
    instance->character = lua_isnoneornil(L, 2) ? nullptr : checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    return 0;
}

static int Formation_get_followers(lua_State* L)
{
    Formation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Formation is nil");
    return pushObject<lektor<hand>>(L, &instance->followers, "lektor<hand>");
}

int FormationBinding::addToFormation(lua_State* L)
{
    Formation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Formation is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "hand is nil");
    int res = instance->addToFormation(*h);
    lua_pushinteger(L, res);
    return 1;
}

int FormationBinding::_NV_addToFormation(lua_State* L)
{
    Formation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Formation is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "hand is nil");
    int res = instance->_NV_addToFormation(*h);
    lua_pushinteger(L, res);
    return 1;
}

int FormationBinding::removeFromFormation(lua_State* L)
{
    Formation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Formation is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "hand is nil");
    instance->removeFromFormation(*h);
    return 0;
}

int FormationBinding::_NV_removeFromFormation(lua_State* L)
{
    Formation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Formation is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "hand is nil");
    instance->_NV_removeFromFormation(*h);
    return 0;
}

int FormationBinding::getFormationPos(lua_State* L)
{
    Formation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Formation is nil");
    int id = (int)luaL_checkinteger(L, 2);
    float tightness = (float)luaL_checknumber(L, 3);
    Ogre::Vector3 result = instance->getFormationPos(id, tightness);
    pushVector3(L, result);
    return 1;
}

int FormationBinding::_NV_getFormationPos(lua_State* L)
{
    Formation* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Formation is nil");
    int id = (int)luaL_checkinteger(L, 2);
    float tightness = (float)luaL_checknumber(L, 3);
    Ogre::Vector3 result = instance->_NV_getFormationPos(id, tightness);
    pushVector3(L, result);
    return 1;
}

int FormationBinding::gc(lua_State* L)
{
    return 0;
}

int FormationBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Formation object");
    return 1;
}

void FormationBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FormationBinding::gc },
        { "__tostring", FormationBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "addToFormation", FormationBinding::addToFormation },
        { "_NV_addToFormation", FormationBinding::_NV_addToFormation },
        { "removeFromFormation", FormationBinding::removeFromFormation },
        { "_NV_removeFromFormation", FormationBinding::_NV_removeFromFormation },
        { "getFormationPos", FormationBinding::getFormationPos },
        { "_NV_getFormationPos", FormationBinding::_NV_getFormationPos },
        { 0, 0 }
    };

    registerClass(
        L, 
        FormationBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FormationBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "character", Formation_get_character);
    registerGetter(L, "followers", Formation_get_followers);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "character", Formation_set_character);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
