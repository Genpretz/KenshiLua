#include "pch.h"
#include "kenshi\gui\MapScreen.h"
#include "MapMarkerCharacterBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/RootObjectBaseBinding.h"

namespace KenshiLua
{
typedef MapScreen::MapMarkerCharacter MapMarkerCharacter;


static MapMarkerCharacter* getInstance(lua_State* L, int idx)
{
    return checkObject<MapMarkerCharacter>(L, idx, MapMarkerCharacterBinding::getMetatableName());
}

// --- Getters for MapMarkerCharacter ---
static int MapMarkerCharacter_get_handle(lua_State* L)
{
    MapMarkerCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapMarkerCharacter is nil");
    return HandBinding::push(L, instance->handle);
}

static int MapMarkerCharacter_get_image(lua_State* L)
{
    MapMarkerCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapMarkerCharacter is nil");
    lua_pushlightuserdata(L, (void*)instance->image);
    return 1;
}

// --- Setters for MapMarkerCharacter ---
static int MapMarkerCharacter_set_handle(lua_State* L)
{
    MapMarkerCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapMarkerCharacter is nil");
    instance->handle = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

int MapMarkerCharacterBinding::setVisible(lua_State* L)
{
    MapMarkerCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapMarkerCharacter is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->setVisible(value);
    return 0;
}

int MapMarkerCharacterBinding::getVisible(lua_State* L)
{
    MapMarkerCharacter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapMarkerCharacter is nil");

    bool result = instance->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 47: void update(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - MapMarkerCharacter_get_image: MyGUI::ImageBox* (unbound pointer)
*/

int MapMarkerCharacterBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int MapMarkerCharacterBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.MapMarkerCharacter object");
    return 1;
}

void MapMarkerCharacterBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       MapMarkerCharacterBinding::gc },
        { "__tostring", MapMarkerCharacterBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setVisible", MapMarkerCharacterBinding::setVisible },
        { "getVisible", MapMarkerCharacterBinding::getVisible },
        { 0, 0 }
    };

    registerClass(
        L, 
        MapMarkerCharacterBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, MapMarkerCharacterBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "handle", MapMarkerCharacter_get_handle);
    registerGetter(L, "image", MapMarkerCharacter_get_image);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "handle", MapMarkerCharacter_set_handle);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua