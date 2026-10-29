#pragma once

#include "kenshi/Animation/AnimationClass.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class AnimsListsManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AnimsListsManager"; }
    static void registerBinding(lua_State* L);

    static int getSingleton(lua_State* L);
    static int getAnimalList(lua_State* L);
    static int getCharacterList(lua_State* L);
    static int setupCharacterList(lua_State* L);
    static int setupAnimalList(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};

} // namespace KenshiLua

