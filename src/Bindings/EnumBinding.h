#pragma once

struct lua_State;

namespace KenshiLua
{
    void registerEnumBindings(lua_State* L);
}