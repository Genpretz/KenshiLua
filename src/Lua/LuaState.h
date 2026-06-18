#pragma once

#include <string>
#include <vector>
#include <functional>
#include <map>

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class LuaState;
extern LuaState* g_luaState;

class LuaState
{
public:
    LuaState();
    ~LuaState();

    LuaState(const LuaState&);
    LuaState& operator=(const LuaState&);

    lua_State* getState() { return m_L; }

    bool initialize();
    void close();

    bool loadScript(const char* script, size_t len, const char* chunkname);
    bool loadScriptFile(const char* filepath);

    bool executeString(const char* str);
    bool executeFile(const char* filepath);

    int getLastError() const { return m_lastError; }
    const char* getLastErrorMessage() const { return m_errorMessage.c_str(); }

    void setModName(const std::string& name) { m_modName = name; }
    const std::string& getModName() const { return m_modName; }

    bool isValid() const { return m_L != NULL; }

private:
    lua_State* m_L;
    int m_lastError;
    std::string m_errorMessage;
    std::string m_modName;

    static int panicHandler(lua_State* L);
    static int genericTraceback(lua_State* L);

    bool executeLuaBlock(int (*block)(lua_State*));
};

} // namespace KenshiLua