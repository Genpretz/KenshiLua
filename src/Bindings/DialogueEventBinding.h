#pragma once

extern "C" {
#include <lua.h>
}

namespace KenshiLua
{

void registerEventBinding(lua_State* L);

} // namespace KenshiLua