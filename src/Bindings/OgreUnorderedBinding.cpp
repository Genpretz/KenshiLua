#include "pch.h"
#include "Bindings/OgreUnorderedBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/GameData.h>
#include <cstring>
#include <cstdio>

namespace KenshiLua
{

inline void pushTripleInt(lua_State* L, const TripleInt& t)
{
    lua_createtable(L, 3, 0);
    lua_pushinteger(L, t.value[0]); lua_rawseti(L, -2, 1);
    lua_pushinteger(L, t.value[1]); lua_rawseti(L, -2, 2);
    lua_pushinteger(L, t.value[2]); lua_rawseti(L, -2, 3);
}

inline bool readTripleInt(lua_State* L, int idx, TripleInt& out)
{
    if (!lua_istable(L, idx)) return false;
    lua_rawgeti(L, idx, 1); out.value[0] = (int)lua_tointeger(L, -1); lua_pop(L, 1);
    lua_rawgeti(L, idx, 2); out.value[1] = (int)lua_tointeger(L, -1); lua_pop(L, 1);
    lua_rawgeti(L, idx, 3); out.value[2] = (int)lua_tointeger(L, -1); lua_pop(L, 1);
    return true;
}

inline void gameDataReferenceToLua(lua_State* L, const GameDataReference& ref)
{
    lua_createtable(L, 0, 3);
    pushTripleInt(L, ref.values);
    lua_setfield(L, -2, "values");
    lua_pushstring(L, ref.sid.c_str());
    lua_setfield(L, -2, "sid");
    pushObject<GameData>(L, ref.ptr, GameDataBinding::getMetatableName());
    lua_setfield(L, -2, "ptr");
}

inline bool readGameDataReference(lua_State* L, int idx, GameDataReference& out)
{
    if (!lua_istable(L, idx)) return false;
    lua_getfield(L, idx, "values");
    if (!lua_isnil(L, -1)) readTripleInt(L, -1, out.values);
    lua_pop(L, 1);
    lua_getfield(L, idx, "sid");
    if (!lua_isnil(L, -1)) out.sid = lua_tostring(L, -1) ? lua_tostring(L, -1) : "";
    lua_pop(L, 1);
    lua_getfield(L, idx, "ptr");
    if (!lua_isnil(L, -1)) out.ptr = checkObject<GameData>(L, -1, GameDataBinding::getMetatableName());
    lua_pop(L, 1);
    return true;
}

inline void gameDataReferenceVectorToLua(lua_State* L, const Ogre::vector<GameDataReference>::type& vec)
{
    lua_createtable(L, static_cast<int>(vec.size()), 0);
    for (size_t i = 0; i < vec.size(); ++i)
    {
        gameDataReferenceToLua(L, vec[i]);
        lua_rawseti(L, -2, i + 1);
    }
}

inline Ogre::vector<GameDataReference>::type luaToGameDataReferenceVector(lua_State* L, int idx)
{
    Ogre::vector<GameDataReference>::type vec;
    if (!lua_istable(L, idx)) return vec;
    size_t len = lua_rawlen(L, idx);
    for (size_t i = 1; i <= len; ++i)
    {
        lua_rawgeti(L, idx, i);
        GameDataReference ref;
        if (readGameDataReference(L, -1, ref)) vec.push_back(ref);
        lua_pop(L, 1);
    }
    return vec;
}

void stringKeyToLua(lua_State* L, const std::string& k) { lua_pushstring(L, k.c_str()); }
std::string luaToStringKey(lua_State* L, int idx) { return luaL_checkstring(L, idx); }

void boolValToLua(lua_State* L, const bool& v) { lua_pushboolean(L, v); }
bool luaToBoolVal(lua_State* L, int idx) { return lua_toboolean(L, idx) != 0; }

void stringValToLua(lua_State* L, const std::string& v) { lua_pushstring(L, v.c_str()); }
std::string luaToStringVal(lua_State* L, int idx) { return luaL_checkstring(L, idx); }

void intValToLua(lua_State* L, const int& v) { lua_pushinteger(L, v); }
int luaToIntVal(lua_State* L, int idx) { return (int)luaL_checkinteger(L, idx); }

void floatValToLua(lua_State* L, const float& v) { lua_pushnumber(L, v); }
float luaToFloatVal(lua_State* L, int idx) { return (float)luaL_checknumber(L, idx); }

void vector3ValToLua(lua_State* L, const Ogre::Vector3& v) { pushVector3(L, v); }
Ogre::Vector3 luaToVector3Val(lua_State* L, int idx) { Ogre::Vector3 v; readVector3(L, idx, v); return v; }

void quaternionValToLua(lua_State* L, const Ogre::Quaternion& v) { pushQuaternion(L, v); }
Ogre::Quaternion luaToQuaternionVal(lua_State* L, int idx) { Ogre::Quaternion q; readQuaternion(L, idx, q); return q; }

void refVectorValToLua(lua_State* L, const Ogre::vector<GameDataReference>::type& v) { gameDataReferenceVectorToLua(L, v); }
Ogre::vector<GameDataReference>::type luaToRefVectorVal(lua_State* L, int idx) { return luaToGameDataReferenceVector(L, idx); }

void registerOgreUnorderedBindings(lua_State* L)
{
    StringBoolMapBinding::registerBinding(L);
    StringStringMapBinding::registerBinding(L);
    StringIntMapBinding::registerBinding(L);
    StringFloatMapBinding::registerBinding(L);
    StringVector3MapBinding::registerBinding(L);
    StringQuaternionMapBinding::registerBinding(L);
    StringGameDataReferenceVectorMapBinding::registerBinding(L);
}

} // namespace KenshiLua
