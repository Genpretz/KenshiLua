#include "pch.h"
#include "Bindings/Dialogue/RepetitionCounterBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Dialogue.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static RepetitionCounter* getS(lua_State* L, int idx)
{
    return checkObject<RepetitionCounter>(L, idx, RepetitionCounterBinding::getMetatableName());
}

int RepetitionCounterBinding::gc(lua_State* L) { return noopGc(L); }

int RepetitionCounterBinding::tostring(lua_State* L)
{
    RepetitionCounter* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int RepetitionCounterBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, RepetitionCounterBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    RepetitionCounter* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    // TODO std::map<EventTriggerEnum, Dialogue::RepetitionCounter::DialogState, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, Dialogue::RepetitionCounter::DialogState>, Ogre::GeneralAllocPolicy > > states; unsupported __index type from header line 295

    lua_pushnil(L);
    return 1;
}

int RepetitionCounterBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    RepetitionCounter* s = getS(L, 1);
    if (!s) return luaL_error(L, "RepetitionCounter is nil");

    // TODO std::map<EventTriggerEnum, Dialogue::RepetitionCounter::DialogState, std::less<EventTriggerEnum>, Ogre::STLAllocator<std::pair<EventTriggerEnum const, Dialogue::RepetitionCounter::DialogState>, Ogre::GeneralAllocPolicy > > states; unsupported __newindex type from header line 295

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int RepetitionCounterBinding::setup(lua_State* L)
{
    RepetitionCounter* s = getS(L, 1);
    if (!s) return luaL_error(L, "RepetitionCounter is nil");

    s->setup();
    return 0;
}

int RepetitionCounterBinding::_DESTRUCTOR(lua_State* L)
{
    RepetitionCounter* s = getS(L, 1);
    if (!s) return luaL_error(L, "RepetitionCounter is nil");

    s->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 297: bool count(...) - unsupported arg type
  line 298: double getTimeSinceLastTrigger(...) - unsupported arg type
  line 299: int getCount(...) - unsupported arg type
  line 303: RepetitionCounter* _CONSTRUCTOR(...) - unsupported return type
*/

void RepetitionCounterBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RepetitionCounterBinding::gc },
        { "__tostring", RepetitionCounterBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "setup", RepetitionCounterBinding::setup },
        { "_DESTRUCTOR", RepetitionCounterBinding::_DESTRUCTOR },
        { 0, 0 }
    };
    registerClass(L, RepetitionCounterBinding::getMetatableName(), meta, methods, RepetitionCounterBinding::index, RepetitionCounterBinding::newindex);
}

} // namespace KenshiLua