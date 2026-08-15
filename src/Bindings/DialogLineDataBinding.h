#pragma once

#include "kenshi/Dialogue.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class DialogLineDataBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.DialogLineData"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getParent(lua_State* L);
    static int isForSpecificCharacter(lua_State* L);
    static int hasSpecificCharacterRequirement(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int setupChildren(lua_State* L);
    static int checkRepeatLimits(lua_State* L);
    static int checkTags(lua_State* L);
    static int getName(lua_State* L);
    static int saidItBefore(lua_State* L);
    static int willTalkToEnemies(lua_State* L);
    static int isEmptyNode(lua_State* L);
    static int _NV_isEmptyNode(lua_State* L);
    static int isAnnouncement(lua_State* L);
    static int stampLastTimeSaid(lua_State* L);
    static int getScore(lua_State* L);
    static int getScorePlusChildrenIfEmpty(lua_State* L);
    static int hasChildren(lua_State* L);
    static int checkConditions(lua_State* L);
    static int chooseAChild(lua_State* L);
    static int getStringID(lua_State* L);
    static int getGameData(lua_State* L);
    static int getChildByStringID(lua_State* L);
    static int setParent(lua_State* L);
    static int getMoneyCostForLine(lua_State* L);
    static int getText(lua_State* L);
    static int getPlayerReplies(lua_State* L);
    static int getActions(lua_State* L);
};
}