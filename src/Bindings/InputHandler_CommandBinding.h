#pragma once
#include "kenshi/InputHandler.h"

namespace KenshiLua
{
class InputHandler_CommandBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.InputHandler_Command"; }
    static void registerBinding(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);
};
} // namespace KenshiLua
