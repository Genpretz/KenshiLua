#pragma once

#include "kenshi/PhysicsActual.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class PhysicsInterfaceBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.PhysicsInterface"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getBackthread(lua_State* L);
    static int updateUT(lua_State* L);
    static int backThreadUpdate(lua_State* L);
    static int createTriggerHull(lua_State* L);
    static int createStaticCapsule(lua_State* L);
    static int doorWantsSetup(lua_State* L);
    static int scytheInsertPreview(lua_State* L);
    static int loadScytheFileMT(lua_State* L);
    static int queuesAreClearMT(lua_State* L);
    static int setQueuesAreClear(lua_State* L);
};
}