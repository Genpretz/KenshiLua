#pragma once
#include "kenshi/AppearanceManager.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class AppearanceManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AppearanceManager"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getInstance(lua_State* L);
    static int createAppearanceData(lua_State* L);
    static int cleanValidateAppearanceData(lua_State* L);
    static int resetAll(lua_State* L);
    static int randomiseAll(lua_State* L);
    static int randomiseAllManual(lua_State* L);
    static int randomHair(lua_State* L);
    static int randomFace(lua_State* L);
    static int randomFaceManual(lua_State* L);
    static int randomPoses(lua_State* L);
    static int randomBody(lua_State* L);
    static int randomBodyManual(lua_State* L);
    static int randomGender(lua_State* L);
    static int randomAnimations(lua_State* L);
    static int getRaceData(lua_State* L);
    static int getRaceIndex(lua_State* L);
    static int getRacesCount(lua_State* L);
    static int isSingleGender(lua_State* L);
    static int setGender(lua_State* L);
    static int setHead(lua_State* L);
    static int getHeadName(lua_State* L);
    static int setRandomHead(lua_State* L);
    static int getHeadIsValid(lua_State* L);
    static int setAttachment(lua_State* L);
    static int getAttachmentName(lua_State* L);
    static int updateModifiers(lua_State* L);
    static int getNormalMap_Plain(lua_State* L);
    static int getNormalMap_Muscle(lua_State* L);
    static int getNormalMap_Starving(lua_State* L);
};
} // namespace KenshiLua
