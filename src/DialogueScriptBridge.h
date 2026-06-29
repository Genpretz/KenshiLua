#pragma once

extern "C" {
#include <lua.h>
}

class Dialogue;
class DialogLineData;

namespace KenshiLua
{
    int luaCheckLuaScriptReferences(lua_State* L);
    int luaGetGameData(lua_State* L);
    void DialogueScriptBridge(Dialogue* thisptr, DialogLineData* dialogLine);
}
