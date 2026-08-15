#include "pch.h"
#include "kenshi\gui\MapScreen.h"
#include "MapMarkerTownBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/TownBaseBinding.h"

namespace KenshiLua
{
typedef MapScreen::MapMarkerTown MapMarkerTown;


static MapMarkerTown* getInstance(lua_State* L, int idx)
{
    return checkObject<MapMarkerTown>(L, idx, MapMarkerTownBinding::getMetatableName());
}

// --- Getters for MapMarkerTown ---
static int MapMarkerTown_get_handle(lua_State* L)
{
    MapMarkerTown* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapMarkerTown is nil");
    return HandBinding::push(L, instance->handle);
}

static int MapMarkerTown_get_zoomLayer(lua_State* L)
{
    MapMarkerTown* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapMarkerTown is nil");
    lua_pushinteger(L, (lua_Integer)instance->zoomLayer);
    return 1;
}

static int MapMarkerTown_get_root(lua_State* L)
{
    MapMarkerTown* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapMarkerTown is nil");
    lua_pushlightuserdata(L, (void*)instance->root);
    return 1;
}

static int MapMarkerTown_get_image(lua_State* L)
{
    MapMarkerTown* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapMarkerTown is nil");
    lua_pushlightuserdata(L, (void*)instance->image);
    return 1;
}

static int MapMarkerTown_get_label(lua_State* L)
{
    MapMarkerTown* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapMarkerTown is nil");
    lua_pushlightuserdata(L, (void*)instance->label);
    return 1;
}

// --- Setters for MapMarkerTown ---
static int MapMarkerTown_set_handle(lua_State* L)
{
    MapMarkerTown* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapMarkerTown is nil");
    instance->handle = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int MapMarkerTown_set_zoomLayer(lua_State* L)
{
    MapMarkerTown* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapMarkerTown is nil");
    instance->zoomLayer = (MapZoomLevel)luaL_checkinteger(L, 2);
    return 0;
}

int MapMarkerTownBinding::setVisible(lua_State* L)
{
    MapMarkerTown* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapMarkerTown is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->setVisible(value);
    return 0;
}

int MapMarkerTownBinding::getVisible(lua_State* L)
{
    MapMarkerTown* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapMarkerTown is nil");

    bool result = instance->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 31: void update(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - MapMarkerTown_get_root: MyGUI::Widget* (unbound pointer)
  - MapMarkerTown_get_image: MyGUI::ImageBox* (unbound pointer)
  - MapMarkerTown_get_label: MyGUI::TextBox* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 30: fullSize (MyGUI::types::TSize<int>) - unsupported type
*/

int MapMarkerTownBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int MapMarkerTownBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.MapMarkerTown object");
    return 1;
}

void MapMarkerTownBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       MapMarkerTownBinding::gc },
        { "__tostring", MapMarkerTownBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setVisible", MapMarkerTownBinding::setVisible },
        { "getVisible", MapMarkerTownBinding::getVisible },
        { 0, 0 }
    };

    registerClass(
        L, 
        MapMarkerTownBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, MapMarkerTownBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "handle", MapMarkerTown_get_handle);
    registerGetter(L, "zoomLayer", MapMarkerTown_get_zoomLayer);
    registerGetter(L, "root", MapMarkerTown_get_root);
    registerGetter(L, "image", MapMarkerTown_get_image);
    registerGetter(L, "label", MapMarkerTown_get_label);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "handle", MapMarkerTown_set_handle);
    registerSetter(L, "zoomLayer", MapMarkerTown_set_zoomLayer);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua