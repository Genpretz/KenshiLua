#include "pch.h"
#include "kenshi\gui\SquadManagementScreen.h"
#include "PortraitDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"

namespace KenshiLua
{

static PortraitData* getInstance(lua_State* L, int idx)
{
    return checkObject<PortraitData>(L, idx, PortraitDataBinding::getMetatableName());
}

// --- Getters for PortraitData ---
static int PortraitData_get_name(lua_State* L)
{
    PortraitData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitData is nil");
    lua_pushstring(L, instance->name.c_str());
    return 1;
}

static int PortraitData_get_flashing(lua_State* L)
{
    PortraitData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitData is nil");
    lua_pushinteger(L, instance->flashing);
    return 1;
}

static int PortraitData_get_state(lua_State* L)
{
    PortraitData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitData is nil");
    lua_pushinteger(L, (lua_Integer)instance->state);
    return 1;
}

static int PortraitData_get_reloadPortrait(lua_State* L)
{
    PortraitData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitData is nil");
    lua_pushboolean(L, instance->reloadPortrait ? 1 : 0);
    return 1;
}

static int PortraitData_get_characterHandle(lua_State* L)
{
    PortraitData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitData is nil");
    return handBinding::push(L, instance->characterHandle);
}

static int PortraitData_get_updateRequested(lua_State* L)
{
    PortraitData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitData is nil");
    lua_pushboolean(L, instance->updateRequested ? 1 : 0);
    return 1;
}

// --- Setters for PortraitData ---
static int PortraitData_set_name(lua_State* L)
{
    PortraitData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitData is nil");
    instance->name = luaL_checkstring(L, 2);
    return 0;
}

static int PortraitData_set_flashing(lua_State* L)
{
    PortraitData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitData is nil");
    instance->flashing = (char)luaL_checkinteger(L, 2);
    return 0;
}

static int PortraitData_set_state(lua_State* L)
{
    PortraitData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitData is nil");
    instance->state = (PortraitData::State)luaL_checkinteger(L, 2);
    return 0;
}

static int PortraitData_set_reloadPortrait(lua_State* L)
{
    PortraitData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitData is nil");
    instance->reloadPortrait = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PortraitData_set_characterHandle(lua_State* L)
{
    PortraitData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitData is nil");
    instance->characterHandle = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int PortraitData_set_updateRequested(lua_State* L)
{
    PortraitData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitData is nil");
    instance->updateRequested = lua_toboolean(L, 2) != 0;
    return 0;
}

int PortraitDataBinding::getCharacter(lua_State* L)
{
    PortraitData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitData is nil");

    Character* result = instance->getCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int PortraitDataBinding::update(lua_State* L)
{
    PortraitData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitData is nil");

    bool result = instance->update();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PortraitDataBinding::forceUpdate(lua_State* L)
{
    PortraitData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitData is nil");

    instance->forceUpdate();
    return 0;
}

int PortraitDataBinding::isSelected(lua_State* L)
{
    PortraitData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitData is nil");

    bool result = instance->isSelected();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PortraitDataBinding::isDown(lua_State* L)
{
    PortraitData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitData is nil");

    bool result = instance->isDown();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PortraitDataBinding::getBackgroundImageName(lua_State* L)
{
    PortraitData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitData is nil");

    std::string result = instance->getBackgroundImageName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int PortraitDataBinding::getBackOverlayImageName(lua_State* L)
{
    PortraitData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitData is nil");

    std::string result = instance->getBackOverlayImageName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int PortraitDataBinding::getFrontOverlayImageName(lua_State* L)
{
    PortraitData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitData is nil");

    std::string result = instance->getFrontOverlayImageName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int PortraitDataBinding::_DESTRUCTOR(lua_State* L)
{
    PortraitData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitData is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 30: const hand& getHandle(...) - reference return type
  line 49: PortraitData* _CONSTRUCTOR(...) - non-string reference arg
*/

int PortraitDataBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int PortraitDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.PortraitData object");
    return 1;
}

void PortraitDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       PortraitDataBinding::gc },
        { "__tostring", PortraitDataBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getCharacter", PortraitDataBinding::getCharacter },
        { "update", PortraitDataBinding::update },
        { "forceUpdate", PortraitDataBinding::forceUpdate },
        { "isSelected", PortraitDataBinding::isSelected },
        { "isDown", PortraitDataBinding::isDown },
        { "getBackgroundImageName", PortraitDataBinding::getBackgroundImageName },
        { "getBackOverlayImageName", PortraitDataBinding::getBackOverlayImageName },
        { "getFrontOverlayImageName", PortraitDataBinding::getFrontOverlayImageName },
        { "_DESTRUCTOR", PortraitDataBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        PortraitDataBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, PortraitDataBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "name", PortraitData_get_name);
    registerGetter(L, "flashing", PortraitData_get_flashing);
    registerGetter(L, "state", PortraitData_get_state);
    registerGetter(L, "reloadPortrait", PortraitData_get_reloadPortrait);
    registerGetter(L, "characterHandle", PortraitData_get_characterHandle);
    registerGetter(L, "updateRequested", PortraitData_get_updateRequested);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "name", PortraitData_set_name);
    registerSetter(L, "flashing", PortraitData_set_flashing);
    registerSetter(L, "state", PortraitData_set_state);
    registerSetter(L, "reloadPortrait", PortraitData_set_reloadPortrait);
    registerSetter(L, "characterHandle", PortraitData_set_characterHandle);
    registerSetter(L, "updateRequested", PortraitData_set_updateRequested);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, PortraitDataBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua