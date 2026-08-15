#pragma once
#include "kenshi/SaveFileSystem.h"

namespace KenshiLua
{
class SaveFileSystem_FileMessageBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.SaveFileSystem_FileMessage"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);
};
} // namespace KenshiLua
