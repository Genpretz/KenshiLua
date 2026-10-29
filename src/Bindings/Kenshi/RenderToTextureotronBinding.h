#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class RenderToTextureotronBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.RenderToTextureotron"; }
    static void registerBinding(lua_State* L);

    static int renderItem(lua_State* L);
    static int renderBuilding(lua_State* L);
    static int renderCharacterNPC(lua_State* L);
    static int buildAllItemsIcons(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};

} // namespace KenshiLua

