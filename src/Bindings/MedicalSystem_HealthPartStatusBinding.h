#pragma once

#include "kenshi/MedicalSystem.h"
#include "Lua/LuaCodec.h"
#include "Lua/BindingHelpers.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class MedicalSystem_HealthPartStatusBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MedicalSystem_HealthPartStatus"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int serialise(lua_State* L);
    static int load(lua_State* L);
    static int isRobotic(lua_State* L);
    static int getData(lua_State* L);
    static int getRobotLimbEnum(lua_State* L);
    static int setup(lua_State* L);
    static int update(lua_State* L);
    static int updateDerivedHealths(lua_State* L);
    static int getWorstDamage(lua_State* L);
    static int setRobotLimbItem(lua_State* L);
    static int getExtraBleedingAmount(lua_State* L);
    static int isDead(lua_State* L);
    static int getBloodynessMult(lua_State* L);
    static int maxHealth(lua_State* L);
    static int healthAsPercent(lua_State* L);
};

typedef MedicalSystem_HealthPartStatusBinding HealthPartStatusBinding;

template <>
struct LuaCodec<MedicalSystem::HealthPartStatus>
{
    static inline void push(lua_State* L, const MedicalSystem::HealthPartStatus& val, const char* metaName)
    {
        pushObject<MedicalSystem::HealthPartStatus>(
            L,
            const_cast<MedicalSystem::HealthPartStatus*>(&val),
            metaName ? metaName : MedicalSystem_HealthPartStatusBinding::getMetatableName()
        );
    }

    static inline MedicalSystem::HealthPartStatus read(lua_State* L, int idx, const char* metaName)
    {
        MedicalSystem::HealthPartStatus* obj = checkObject<MedicalSystem::HealthPartStatus>(
            L, idx, metaName ? metaName : MedicalSystem_HealthPartStatusBinding::getMetatableName()
        );
        return obj ? *obj : MedicalSystem::HealthPartStatus();
    }
};

} // namespace KenshiLua
