#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class AppearanceHumanBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AppearanceHuman"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int setGender(lua_State* L);
    static int _NV_setGender(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int _NV_periodicUpdate(lua_State* L);
    static int setAttachmentsVisible(lua_State* L);
    static int _NV_setAttachmentsVisible(lua_State* L);
    static int setHiddenPartsEnabled(lua_State* L);
    static int showFace(lua_State* L);
    static int setFlayed(lua_State* L);
    static int _NV_setFlayed(lua_State* L);
    static int isFlayed(lua_State* L);
    static int _NV_isFlayed(lua_State* L);
    static int updateProportions(lua_State* L);
    static int createBody(lua_State* L);
    static int _NV_createBody(lua_State* L);
    static int updateAppearance(lua_State* L);
    static int _NV_updateAppearance(lua_State* L);
    static int updateHiddenParts(lua_State* L);
    static int updatePysiqueFromStats(lua_State* L);
    static int updatePhysiqueMuscleMults(lua_State* L);
    static int updateCharaterTexture(lua_State* L);
    static int _NV_updateCharaterTexture(lua_State* L);
    static int setPosture(lua_State* L);
};
}
