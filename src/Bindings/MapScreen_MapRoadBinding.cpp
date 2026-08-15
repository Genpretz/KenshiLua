#include "pch.h"
#include "Bindings/MapScreen_MapRoadBinding.h"
#include "Lua/BindingHelpers.h"
#include <kenshi/gui/MapScreen.h>

namespace KenshiLua
{

static MapScreen::MapRoad* getInstance(lua_State* L, int idx)
{
    return checkObject<MapScreen::MapRoad>(L, idx, MapScreen_MapRoadBinding::getMetatableName());
}

static int MapRoad_get_widget(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "MapScreen::MapRoad is nil");
    if (inst->widget) lua_pushlightuserdata(L, (void*)inst->widget);
    else lua_pushnil(L);
    return 1;
}

static int MapRoad_set_widget(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "MapScreen::MapRoad is nil");
    inst->widget = (MyGUI::Widget*)lua_touserdata(L, 2);
    return 0;
}

int MapScreen_MapRoadBinding::gc(lua_State* L)
{
    return 0;
}

int MapScreen_MapRoadBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.MapScreen_MapRoad object");
    return 1;
}

int MapScreen_MapRoadBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a == b) ? 1 : 0);
    return 1;
}

void MapScreen_MapRoadBinding::registerBinding(lua_State* L)
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
    registerGetter(L, "widget", MapRoad_get_widget);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "widget", MapRoad_set_widget);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
