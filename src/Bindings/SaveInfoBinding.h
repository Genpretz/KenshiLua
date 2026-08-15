#pragma once

#include "kenshi/SaveInfo.h"
namespace KenshiLua
{
class SaveInfoBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.SaveInfo"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);
};
} // namespace KenshiLua
