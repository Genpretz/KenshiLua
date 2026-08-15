#pragma once

#include "kenshi/gui/ManagementScreen.h"
namespace KenshiLua
{
class ManagementScreen_TechItemViewDataBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ManagementScreen_TechItemViewData"; }
    static void registerBinding(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);
};
} // namespace KenshiLua
