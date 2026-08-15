#pragma once

#include "kenshi/gui/FactionsScreen.h"
namespace KenshiLua
{
class FactionsScreen_FactionRelationsLine_LessSortBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.FactionsScreen_FactionRelationsLine_LessSort"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);
};
} // namespace KenshiLua
