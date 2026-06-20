#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class CharacterEditWindowBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CharacterEditWindow"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int update(lua_State* L);
    static int loadData(lua_State* L);
    static int initCharacters(lua_State* L);
    static int updateRace(lua_State* L);
    static int updateCharacterPoses(lua_State* L);
    static int clearCharacterPoses(lua_State* L);
    static int updateCharacter(lua_State* L);
    static int updateCurrentCategory(lua_State* L);
    static int confirmMessageCallback(lua_State* L);
    static int setupUI(lua_State* L);
    static int setUIEnabled(lua_State* L);
    static int refreshUI(lua_State* L);
    static int updateLiveObject(lua_State* L);
    static int refreshCharacterPoses(lua_State* L);
    static int exportMeshes(lua_State* L);
};
}