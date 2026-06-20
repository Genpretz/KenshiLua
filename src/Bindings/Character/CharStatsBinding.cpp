#include "pch.h"
#include "Bindings/Character/CharStatsBinding.h"
#include "Bindings/Utility/HandBinding.h"
#include "Bindings/System/MedicalSystemBinding.h"
#include "Bindings/Character/CharacterBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Character.h>
#include <kenshi/CharStats.h>
#include <kenshi/MedicalSystem.h>

#include <cstring>

namespace KenshiLua
{

static CharStats* getS(lua_State* L, int idx)
{
    return checkObject<CharStats>(L, idx, CharStatsBinding::getMetatableName());
}

int CharStatsBinding::gc(lua_State* L)       { return noopGc(L); }

int CharStatsBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    // 1. Check the metatable first so obj:method() syntax continues to work.
    luaL_getmetatable(L, CharStatsBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    // 2. Fall through to raw member variable access.
    CharStats* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    // --- object members -----------------------------------------------------
    if (strcmp(key, "medical") == 0)  { return pushObject<MedicalSystem>(L, s->medical, MedicalSystemBinding::getMetatableName()); }
    if (strcmp(key, "me") == 0)       { return pushObject<Character>(L, s->me, CharacterBinding::getMetatableName()); }
    if (strcmp(key, "weapon") == 0)   { return HandBinding::pushHand(L, s->weapon); }

    // --- float members ------------------------------------------------------
    // c++ original naming
    if (strcmp(key, "athleticsMultiplier") == 0) { lua_pushnumber(L, s->athleticsMultiplier); return 1; }
    if (strcmp(key, "combatSpeedMultiplier") == 0) { lua_pushnumber(L, s->combatSpeedMultiplier); return 1; }
    if (strcmp(key, "_skillBonusAttack") == 0) { lua_pushinteger(L, s->_skillBonusAttack); return 1; }
    if (strcmp(key, "_skillBonusDefence") == 0) { lua_pushinteger(L, s->_skillBonusDefence); return 1; }
    if (strcmp(key, "skillBonusIndoors") == 0) { lua_pushinteger(L, s->skillBonusIndoors); return 1; }
    if (strcmp(key, "skillBonusUnarmed") == 0) { lua_pushinteger(L, s->skillBonusUnarmed); return 1; }
    if (strcmp(key, "skillBonusPerception") == 0) { lua_pushinteger(L, s->skillBonusPerception); return 1; }
    if (strcmp(key, "ageMult") == 0) { lua_pushnumber(L, s->ageMult); return 1; }
    if (strcmp(key, "skillMultDodge") == 0) { lua_pushnumber(L, s->skillMultDodge); return 1; }
    if (strcmp(key, "skillMultStealth") == 0) { lua_pushnumber(L, s->skillMultStealth); return 1; }
    if (strcmp(key, "skillMultAssassin") == 0) { lua_pushnumber(L, s->skillMultAssassin); return 1; }
    if (strcmp(key, "skillMultDexterity") == 0) { lua_pushnumber(L, s->skillMultDexterity); return 1; }
    if (strcmp(key, "skillMultDamage") == 0) { lua_pushnumber(L, s->skillMultDamage); return 1; }
    if (strcmp(key, "fistInjuryEquipmentMult") == 0) { lua_pushnumber(L, s->fistInjuryEquipmentMult); return 1; }
    if (strcmp(key, "skillMultRanged") == 0) { lua_pushnumber(L, s->skillMultRanged); return 1; }
    if (strcmp(key, "_strength") == 0) { lua_pushnumber(L, s->_strength); return 1; }
    if (strcmp(key, "fitness") == 0) { lua_pushnumber(L, s->fitness); return 1; }
    if (strcmp(key, "_dexterity") == 0) { lua_pushnumber(L, s->_dexterity); return 1; }
    if (strcmp(key, "perception") == 0) { lua_pushnumber(L, s->perception); return 1; }
    if (strcmp(key, "_toughness") == 0) { lua_pushnumber(L, s->_toughness); return 1; }
    if (strcmp(key, "_athletics") == 0) { lua_pushnumber(L, s->_athletics); return 1; }
    if (strcmp(key, "medic") == 0) { lua_pushnumber(L, s->medic); return 1; }
    if (strcmp(key, "massCombat") == 0) { lua_pushnumber(L, s->massCombat); return 1; }
    if (strcmp(key, "arrowDefence") == 0) { lua_pushnumber(L, s->arrowDefence); return 1; }
    if (strcmp(key, "stealth") == 0) { lua_pushnumber(L, s->stealth); return 1; }
    if (strcmp(key, "swimming") == 0) { lua_pushnumber(L, s->swimming); return 1; }
    if (strcmp(key, "thieving") == 0) { lua_pushnumber(L, s->thieving); return 1; }
    if (strcmp(key, "lockpicking") == 0) { lua_pushnumber(L, s->lockpicking); return 1; }
    if (strcmp(key, "bluff") == 0) { lua_pushnumber(L, s->bluff); return 1; }
    if (strcmp(key, "assassin") == 0) { lua_pushnumber(L, s->assassin); return 1; }
    if (strcmp(key, "survival") == 0) { lua_pushnumber(L, s->survival); return 1; }
    if (strcmp(key, "tracking") == 0) { lua_pushnumber(L, s->tracking); return 1; }
    if (strcmp(key, "climbing") == 0) { lua_pushnumber(L, s->climbing); return 1; }
    if (strcmp(key, "doctor") == 0) { lua_pushnumber(L, s->doctor); return 1; }
    if (strcmp(key, "engineer") == 0) { lua_pushnumber(L, s->engineer); return 1; }
    if (strcmp(key, "weaponSmith") == 0) { lua_pushnumber(L, s->weaponSmith); return 1; }
    if (strcmp(key, "armourSmith") == 0) { lua_pushnumber(L, s->armourSmith); return 1; }
    if (strcmp(key, "bowSmith") == 0) { lua_pushnumber(L, s->bowSmith); return 1; }
    if (strcmp(key, "robotics") == 0) { lua_pushnumber(L, s->robotics); return 1; }
    if (strcmp(key, "science") == 0) { lua_pushnumber(L, s->science); return 1; }
    if (strcmp(key, "labouring") == 0) { lua_pushnumber(L, s->labouring); return 1; }
    if (strcmp(key, "farming") == 0) { lua_pushnumber(L, s->farming); return 1; }
    if (strcmp(key, "cooking") == 0) { lua_pushnumber(L, s->cooking); return 1; }
    if (strcmp(key, "dodging") == 0) { lua_pushnumber(L, s->dodging); return 1; }
    if (strcmp(key, "friendlyFire") == 0) { lua_pushnumber(L, s->friendlyFire); return 1; }
    if (strcmp(key, "katanas") == 0) { lua_pushnumber(L, s->katanas); return 1; }
    if (strcmp(key, "sabres") == 0) { lua_pushnumber(L, s->sabres); return 1; }
    if (strcmp(key, "hackers") == 0) { lua_pushnumber(L, s->hackers); return 1; }
    if (strcmp(key, "blunt") == 0) { lua_pushnumber(L, s->blunt); return 1; }
    if (strcmp(key, "heavyWeapons") == 0) { lua_pushnumber(L, s->heavyWeapons); return 1; }
    if (strcmp(key, "unarmed") == 0) { lua_pushnumber(L, s->unarmed); return 1; }
    if (strcmp(key, "bows") == 0) { lua_pushnumber(L, s->bows); return 1; }
    if (strcmp(key, "turrets") == 0) { lua_pushnumber(L, s->turrets); return 1; }
    if (strcmp(key, "polearms") == 0) { lua_pushnumber(L, s->polearms); return 1; }
    if (strcmp(key, "currentItemMaximumJuryRig") == 0) { lua_pushnumber(L, s->currentItemMaximumJuryRig); return 1; }
    if (strcmp(key, "__meleeAttack") == 0) { lua_pushnumber(L, s->__meleeAttack); return 1; }
    if (strcmp(key, "_meleeDefence") == 0) { lua_pushnumber(L, s->_meleeDefence); return 1; }
    if (strcmp(key, "warriorSpirit") == 0) { lua_pushnumber(L, s->warriorSpirit); return 1; }
    if (strcmp(key, "derivedSpirit") == 0) { lua_pushnumber(L, s->derivedSpirit); return 1; }
    if (strcmp(key, "aggression") == 0) { lua_pushnumber(L, s->aggression); return 1; }
    if (strcmp(key, "goodness") == 0) { lua_pushnumber(L, s->goodness); return 1; }
    if (strcmp(key, "evilness") == 0) { lua_pushnumber(L, s->evilness); return 1; }
    if (strcmp(key, "longestReachingAttack") == 0) { lua_pushnumber(L, s->longestReachingAttack); return 1; }
    if (strcmp(key, "STUBBOURNESS") == 0) { lua_pushnumber(L, s->STUBBOURNESS); return 1; }
    if (strcmp(key, "PROFESSIONALNESS") == 0) { lua_pushnumber(L, s->PROFESSIONALNESS); return 1; }
    if (strcmp(key, "HOLDING_POSITION") == 0) { lua_pushnumber(L, s->HOLDING_POSITION); return 1; }
    if (strcmp(key, "IMMEDIACY") == 0) { lua_pushnumber(L, s->IMMEDIACY); return 1; }
    if (strcmp(key, "IMMEDIACY_MAX_RANGE") == 0) { lua_pushnumber(L, s->IMMEDIACY_MAX_RANGE); return 1; }
    if (strcmp(key, "MANLINESS") == 0) { lua_pushnumber(L, s->MANLINESS); return 1; }
    if (strcmp(key, "MURDEROUS") == 0) { lua_pushnumber(L, s->MURDEROUS); return 1; }
    if (strcmp(key, "_stealthXPMultForGUI") == 0) { lua_pushnumber(L, s->_stealthXPMultForGUI); return 1; }
    if (strcmp(key, "stealthXPTooManyCooksPenalty") == 0) { lua_pushnumber(L, s->stealthXPTooManyCooksPenalty); return 1; }
    if (strcmp(key, "currentOperatingMachineHungerRate") == 0) { lua_pushnumber(L, s->currentOperatingMachineHungerRate); return 1; }
    if (strcmp(key, "moveSpeed") == 0) { lua_pushnumber(L, s->moveSpeed); return 1; }
    if (strcmp(key, "weaponWeightSpeedMult") == 0) { lua_pushnumber(L, s->weaponWeightSpeedMult); return 1; }
    if (strcmp(key, "weaponWeightXPMult") == 0) { lua_pushnumber(L, s->weaponWeightXPMult); return 1; }
    if (strcmp(key, "attackSpeed") == 0) { lua_pushnumber(L, s->attackSpeed); return 1; }
    if (strcmp(key, "blockSpeed") == 0) { lua_pushnumber(L, s->blockSpeed); return 1; }
    if (strcmp(key, "encumbranceMult") == 0) { lua_pushnumber(L, s->encumbranceMult); return 1; }
    if (strcmp(key, "xp") == 0) { lua_pushnumber(L, s->xp); return 1; }
    if (strcmp(key, "cutDamageMult") == 0) { lua_pushnumber(L, s->cutDamageMult); return 1; }
    if (strcmp(key, "bluntDamageMult") == 0) { lua_pushnumber(L, s->bluntDamageMult); return 1; }
    if (strcmp(key, "bleedDamageMult") == 0) { lua_pushnumber(L, s->bleedDamageMult); return 1; }
    if (strcmp(key, "pierceDamageMult") == 0) { lua_pushnumber(L, s->pierceDamageMult); return 1; }
    if (strcmp(key, "cutDamageMin") == 0) { lua_pushnumber(L, s->cutDamageMin); return 1; }
    if (strcmp(key, "bluntDamageMin") == 0) { lua_pushnumber(L, s->bluntDamageMin); return 1; }
    if (strcmp(key, "bonusRobots") == 0) { lua_pushnumber(L, s->bonusRobots); return 1; }
    if (strcmp(key, "bonusHumans") == 0) { lua_pushnumber(L, s->bonusHumans); return 1; }
    if (strcmp(key, "bonusAnimals") == 0) { lua_pushnumber(L, s->bonusAnimals); return 1; }
    if (strcmp(key, "bonusArmourPenetration") == 0) { lua_pushnumber(L, s->bonusArmourPenetration); return 1; }
    if (strcmp(key, "currentWeaponLength") == 0) { lua_pushnumber(L, s->currentWeaponLength); return 1; }
    if (strcmp(key, "weaponWeight") == 0) { lua_pushnumber(L, s->weaponWeight); return 1; }

    // --- boolean members ----------------------------------------------------
    if (strcmp(key, "_defensiveMode") == 0) { lua_pushboolean(L, s->_defensiveMode ? 1 : 0); return 1; }
    if (strcmp(key, "rangedMode") == 0) { lua_pushboolean(L, s->rangedMode ? 1 : 0); return 1; }
    if (strcmp(key, "tauntMode") == 0) { lua_pushboolean(L, s->tauntMode ? 1 : 0); return 1; }
    if (strcmp(key, "_holdPositionMode") == 0) { lua_pushboolean(L, s->_holdPositionMode ? 1 : 0); return 1; }
    if (strcmp(key, "passiveCombatMode") == 0) { lua_pushboolean(L, s->passiveCombatMode ? 1 : 0); return 1; }

    // --- vector members -----------------------------------------------------
    if (strcmp(key, "holdLocation") == 0) { pushVector3(L, s->holdLocation); return 1; }

    // --- integer / enum members --------------------------------------------
    if (strcmp(key, "freeAttributePoints") == 0) { lua_pushinteger(L, s->freeAttributePoints); return 1; }
    if (strcmp(key, "currentWeaponType") == 0) { lua_pushinteger(L, (int)s->currentWeaponType); return 1; }

    // --- complex members that need a dedicated wrapper ----------------------
    // _weatherProtections is a std::map<WeatherAffecting, float> and would need
    // a map/table bridge plus a WeatherAffecting enum wrapper to expose cleanly.
    // if (strcmp(key, "_weatherProtections") == 0) { ... }

    // pCurrentWeaponSkill is a raw float*; expose it once we have a dedicated
    // pointer wrapper or decide on a stable Lua representation.
    // if (strcmp(key, "pCurrentWeaponSkill") == 0) { ... }

    // bonusRaces is a std::map<GameData*, float>; we can expose it once a
    // GameData binding and a map conversion helper exist.
    // if (strcmp(key, "bonusRaces") == 0) { ... }

    lua_pushnil(L);
    return 1;
}

int CharStatsBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    CharStats* s = checkObject<CharStats>(L, 1, CharStatsBinding::getMetatableName());
    if (!s) return luaL_error(L, "CharStats is nil");

    // --- object members -----------------------------------------------------
    if (strcmp(key, "medical") == 0) {
        s->medical = lua_isnil(L, 3) ? 0 : checkObject<MedicalSystem>(L, 3, MedicalSystemBinding::getMetatableName());
        return 0;
    }
    if (strcmp(key, "me") == 0) {
        s->me = lua_isnil(L, 3) ? 0 : checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
        return 0;
    }
    if (strcmp(key, "weapon") == 0) {
        hand* h = (hand*)luaL_checkudata(L, 3, HandBinding::getMetatableName());
        if (!h) return luaL_error(L, "CharStats.weapon: expected hand userdata");
        s->weapon = *h;
        return 0;
    }

    // --- float members ------------------------------------------------------
    if (strcmp(key, "athleticsMultiplier") == 0) { s->athleticsMultiplier = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "combatSpeedMultiplier") == 0) { s->combatSpeedMultiplier = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "_skillBonusAttack") == 0) { s->_skillBonusAttack = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "_skillBonusDefence") == 0) { s->_skillBonusDefence = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "skillBonusIndoors") == 0) { s->skillBonusIndoors = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "skillBonusUnarmed") == 0) { s->skillBonusUnarmed = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "skillBonusPerception") == 0) { s->skillBonusPerception = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "ageMult") == 0) { s->ageMult = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "skillMultDodge") == 0) { s->skillMultDodge = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "skillMultStealth") == 0) { s->skillMultStealth = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "skillMultAssassin") == 0) { s->skillMultAssassin = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "skillMultDexterity") == 0) { s->skillMultDexterity = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "skillMultDamage") == 0) { s->skillMultDamage = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "fistInjuryEquipmentMult") == 0) { s->fistInjuryEquipmentMult = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "skillMultRanged") == 0) { s->skillMultRanged = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "_strength") == 0) { s->_strength = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "fitness") == 0) { s->fitness = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "_dexterity") == 0) { s->_dexterity = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "perception") == 0) { s->perception = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "_toughness") == 0) { s->_toughness = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "_athletics") == 0) { s->_athletics = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "medic") == 0) { s->medic = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "massCombat") == 0) { s->massCombat = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "arrowDefence") == 0) { s->arrowDefence = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "stealth") == 0) { s->stealth = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "swimming") == 0) { s->swimming = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "thieving") == 0) { s->thieving = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "lockpicking") == 0) { s->lockpicking = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "bluff") == 0) { s->bluff = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "assassin") == 0) { s->assassin = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "survival") == 0) { s->survival = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "tracking") == 0) { s->tracking = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "climbing") == 0) { s->climbing = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "doctor") == 0) { s->doctor = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "engineer") == 0) { s->engineer = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "weaponSmith") == 0) { s->weaponSmith = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "armourSmith") == 0) { s->armourSmith = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "bowSmith") == 0) { s->bowSmith = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "robotics") == 0) { s->robotics = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "science") == 0) { s->science = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "labouring") == 0) { s->labouring = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "farming") == 0) { s->farming = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "cooking") == 0) { s->cooking = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "dodging") == 0) { s->dodging = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "friendlyFire") == 0) { s->friendlyFire = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "katanas") == 0) { s->katanas = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "sabres") == 0) { s->sabres = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "hackers") == 0) { s->hackers = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "blunt") == 0) { s->blunt = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "heavyWeapons") == 0) { s->heavyWeapons = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "unarmed") == 0) { s->unarmed = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "bows") == 0) { s->bows = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "turrets") == 0) { s->turrets = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "polearms") == 0) { s->polearms = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "currentItemMaximumJuryRig") == 0) { s->currentItemMaximumJuryRig = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "__meleeAttack") == 0) { s->__meleeAttack = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "_meleeDefence") == 0) { s->_meleeDefence = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "warriorSpirit") == 0) { s->warriorSpirit = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "derivedSpirit") == 0) { s->derivedSpirit = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "aggression") == 0) { s->aggression = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "goodness") == 0) { s->goodness = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "evilness") == 0) { s->evilness = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "longestReachingAttack") == 0) { s->longestReachingAttack = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "STUBBOURNESS") == 0) { s->STUBBOURNESS = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "PROFESSIONALNESS") == 0) { s->PROFESSIONALNESS = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "HOLDING_POSITION") == 0) { s->HOLDING_POSITION = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "IMMEDIACY") == 0) { s->IMMEDIACY = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "IMMEDIACY_MAX_RANGE") == 0) { s->IMMEDIACY_MAX_RANGE = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "MANLINESS") == 0) { s->MANLINESS = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "MURDEROUS") == 0) { s->MURDEROUS = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "_stealthXPMultForGUI") == 0) { s->_stealthXPMultForGUI = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "stealthXPTooManyCooksPenalty") == 0) { s->stealthXPTooManyCooksPenalty = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "currentOperatingMachineHungerRate") == 0) { s->currentOperatingMachineHungerRate = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "moveSpeed") == 0) { s->moveSpeed = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "weaponWeightSpeedMult") == 0) { s->weaponWeightSpeedMult = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "weaponWeightXPMult") == 0) { s->weaponWeightXPMult = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "attackSpeed") == 0) { s->attackSpeed = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "blockSpeed") == 0) { s->blockSpeed = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "encumbranceMult") == 0) { s->encumbranceMult = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "xp") == 0) { s->xp = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "cutDamageMult") == 0) { s->cutDamageMult = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "bluntDamageMult") == 0) { s->bluntDamageMult = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "bleedDamageMult") == 0) { s->bleedDamageMult = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "pierceDamageMult") == 0) { s->pierceDamageMult = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "cutDamageMin") == 0) { s->cutDamageMin = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "bluntDamageMin") == 0) { s->bluntDamageMin = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "bonusRobots") == 0) { s->bonusRobots = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "bonusHumans") == 0) { s->bonusHumans = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "bonusAnimals") == 0) { s->bonusAnimals = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "bonusArmourPenetration") == 0) { s->bonusArmourPenetration = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "currentWeaponLength") == 0) { s->currentWeaponLength = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "weaponWeight") == 0) { s->weaponWeight = (float)luaL_checknumber(L, 3); return 0; }

    // --- boolean members ----------------------------------------------------
    if (strcmp(key, "_defensiveMode") == 0) { s->_defensiveMode = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "rangedMode") == 0) { s->rangedMode = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "tauntMode") == 0) { s->tauntMode = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "_holdPositionMode") == 0) { s->_holdPositionMode = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "passiveCombatMode") == 0) { s->passiveCombatMode = (lua_toboolean(L, 3) != 0); return 0; }

    // --- vector members -----------------------------------------------------
    if (strcmp(key, "holdLocation") == 0) {
        Ogre::Vector3 v = s->holdLocation;
        if (!readVector3(L, 3, v)) return luaL_error(L, "CharStats.holdLocation: expected table with x/y/z");
        s->holdLocation = v;
        return 0;
    }

    // --- integer / enum members --------------------------------------------
    if (strcmp(key, "freeAttributePoints") == 0) { s->freeAttributePoints = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "currentWeaponType") == 0) { s->currentWeaponType = (WeaponCategory)luaL_checkinteger(L, 3); return 0; }

    // --- complex members that need a dedicated wrapper ----------------------
    // _weatherProtections is a std::map<WeatherAffecting, float> and would need
    // a map/table bridge plus a WeatherAffecting enum wrapper to expose cleanly.
    // if (strcmp(key, "_weatherProtections") == 0) { ... }

    // pCurrentWeaponSkill is a raw float*; expose it once we have a dedicated
    // pointer wrapper or decide on a stable Lua representation.
    // if (strcmp(key, "pCurrentWeaponSkill") == 0) { ... }

    // bonusRaces is a std::map<GameData*, float>; we can expose it once a
    // GameData binding and a map conversion helper exist.
    // if (strcmp(key, "bonusRaces") == 0) { ... }

    return luaL_error(L, "CharStats: field '%s' does not exist", key);
}

int CharStatsBinding::tostring(lua_State* L)
{
    CharStats* s = getS(L, 1);
    return genericTostringPtr(L, "CharStats", (void*)s);
}

// --- Getters ------------------------------------------------------------------------------------------------------------------------------------

// --- Core attributes ---------------------------------------------------------
int CharStatsBinding::getStrength(lua_State* L)     { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->strengthActual()); else lua_pushnil(L); return 1; }
int CharStatsBinding::getStrengthRaw(lua_State* L)  { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->_strength); else lua_pushnil(L); return 1; }
int CharStatsBinding::getDexterity(lua_State* L)    { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->dexterityActual()); else lua_pushnil(L); return 1; }
int CharStatsBinding::getDexterityRaw(lua_State* L) { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->_dexterity); else lua_pushnil(L); return 1; }
int CharStatsBinding::getToughness(lua_State* L)    { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->toughness()); else lua_pushnil(L); return 1; }
int CharStatsBinding::getToughnessRaw(lua_State* L) { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->_toughness); else lua_pushnil(L); return 1; }
int CharStatsBinding::getPerception(lua_State* L)   { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->perception); else lua_pushnil(L); return 1; }
int CharStatsBinding::getAthletics(lua_State* L)    { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->_athletics); else lua_pushnil(L); return 1; }

// --- Combat skills -----------------------------------------------------------
int CharStatsBinding::getMeleeAttack(lua_State* L)
{
    CharStats* s = getS(L, 1);
    if (s) lua_pushnumber(L, s->getMeleeAttack()); else lua_pushnil(L);
    return 1;
}

int CharStatsBinding::getMeleeDefence(lua_State* L)
{
    CharStats* s = getS(L, 1);
    bool incDef = lua_isnoneornil(L, 2) ? true : (lua_toboolean(L, 2) != 0);
    if (s) lua_pushnumber(L, s->getMeleeDefence(incDef)); else lua_pushnil(L);
    return 1;
}

int CharStatsBinding::getDodge(lua_State* L)
{
    CharStats* s = getS(L, 1);
    bool bonuses = lua_isnoneornil(L, 2) ? true : (lua_toboolean(L, 2) != 0);
    if (s) lua_pushnumber(L, s->getDodge(bonuses)); else lua_pushnil(L);
    return 1;
}

int CharStatsBinding::getMassCombat(lua_State* L)   { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->massCombat); else lua_pushnil(L); return 1; }
int CharStatsBinding::getMartialArts(lua_State* L)  { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->unarmed); else lua_pushnil(L); return 1; }
int CharStatsBinding::getKatanas(lua_State* L)      { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->katanas); else lua_pushnil(L); return 1; }
int CharStatsBinding::getSabres(lua_State* L)       { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->sabres); else lua_pushnil(L); return 1; }
int CharStatsBinding::getHackers(lua_State* L)      { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->hackers); else lua_pushnil(L); return 1; }
int CharStatsBinding::getBlunt(lua_State* L)        { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->blunt); else lua_pushnil(L); return 1; }
int CharStatsBinding::getHeavyWeapons(lua_State* L) { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->heavyWeapons); else lua_pushnil(L); return 1; }
int CharStatsBinding::getPolearms(lua_State* L)     { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->polearms); else lua_pushnil(L); return 1; }
int CharStatsBinding::getBows(lua_State* L)         { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->bows); else lua_pushnil(L); return 1; }
int CharStatsBinding::getTurrets(lua_State* L)      { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->turrets); else lua_pushnil(L); return 1; }

// --- Field / craft skills ----------------------------------------------------
int CharStatsBinding::getStealth(lua_State* L)      { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->stealth); else lua_pushnil(L); return 1; }
int CharStatsBinding::getThieving(lua_State* L)     { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->thieving); else lua_pushnil(L); return 1; }
int CharStatsBinding::getLockpicking(lua_State* L)  { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->lockpicking); else lua_pushnil(L); return 1; }
int CharStatsBinding::getAssassination(lua_State* L){ CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->assassin); else lua_pushnil(L); return 1; }
int CharStatsBinding::getSurvival(lua_State* L)     { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->survival); else lua_pushnil(L); return 1; }
int CharStatsBinding::getTracking(lua_State* L)     { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->tracking); else lua_pushnil(L); return 1; }
int CharStatsBinding::getClimbing(lua_State* L)     { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->climbing); else lua_pushnil(L); return 1; }
int CharStatsBinding::getSwimming(lua_State* L)     { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->swimming); else lua_pushnil(L); return 1; }
int CharStatsBinding::getBluff(lua_State* L)        { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->bluff); else lua_pushnil(L); return 1; }
int CharStatsBinding::getFieldMedic(lua_State* L)   { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->medic); else lua_pushnil(L); return 1; }
int CharStatsBinding::getDoctor(lua_State* L)       { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->doctor); else lua_pushnil(L); return 1; }
int CharStatsBinding::getScience(lua_State* L)      { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->science); else lua_pushnil(L); return 1; }
int CharStatsBinding::getEngineer(lua_State* L)     { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->engineer); else lua_pushnil(L); return 1; }
int CharStatsBinding::getRobotics(lua_State* L)     { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->robotics); else lua_pushnil(L); return 1; }
int CharStatsBinding::getLabouring(lua_State* L)    { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->labouring); else lua_pushnil(L); return 1; }
int CharStatsBinding::getFarming(lua_State* L)      { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->farming); else lua_pushnil(L); return 1; }
int CharStatsBinding::getCooking(lua_State* L)      { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->cooking); else lua_pushnil(L); return 1; }
int CharStatsBinding::getWeaponSmith(lua_State* L)  { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->weaponSmith); else lua_pushnil(L); return 1; }
int CharStatsBinding::getArmourSmith(lua_State* L)  { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->armourSmith); else lua_pushnil(L); return 1; }
int CharStatsBinding::getBowSmith(lua_State* L)     { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->bowSmith); else lua_pushnil(L); return 1; }

// --- XP / status -------------------------------------------------------------
int CharStatsBinding::getXp(lua_State* L)                  { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->xp); else lua_pushnil(L); return 1; }
int CharStatsBinding::getFreeAttributePoints(lua_State* L) { CharStats* s = getS(L, 1); if (s) lua_pushinteger(L, s->freeAttributePoints); else lua_pushnil(L); return 1; }
int CharStatsBinding::getOverallSkillLevel(lua_State* L)   { CharStats* s = getS(L, 1); if (s) lua_pushnumber(L, s->getOverallSkillLevel_0_100()); else lua_pushnil(L); return 1; }
int CharStatsBinding::isUnarmed(lua_State* L)              { CharStats* s = getS(L, 1); lua_pushboolean(L, s && s->isUnarmed() ? 1 : 0); return 1; }
int CharStatsBinding::isDefensiveMode(lua_State* L)        { CharStats* s = getS(L, 1); lua_pushboolean(L, s && s->isDefensiveMode() ? 1 : 0); return 1; }
int CharStatsBinding::isHoldPositionMode(lua_State* L)     { CharStats* s = getS(L, 1); lua_pushboolean(L, s && s->holdPositionMode() ? 1 : 0); return 1; }
int CharStatsBinding::isRangedMode(lua_State* L)           { CharStats* s = getS(L, 1); lua_pushboolean(L, s && s->rangedMode ? 1 : 0); return 1; }

// --- Linkage -----------------------------------------------------------------
int CharStatsBinding::getMedicalSystem(lua_State* L)
{
    CharStats* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }
    return pushObject<MedicalSystem>(L, s->medical, MedicalSystemBinding::getMetatableName());
}

int CharStatsBinding::getCharacter(lua_State* L)
{
    CharStats* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }
    return pushObject<Character>(L, s->me, CharacterBinding::getMetatableName());
}

// --- Setters ------------------------------------------------------------------------------------------------------------------------------------

int CharStatsBinding::setEquippedWeaponSkill(lua_State* L)
{
    CharStats* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharStats is nil");
    s->setEquippedWeaponSkill((float)luaL_checknumber(L, 2));
    return 0;
}

int CharStatsBinding::_NV_setEquippedWeaponSkill(lua_State* L)
{
    CharStats* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharStats is nil");
    s->_NV_setEquippedWeaponSkill((float)luaL_checknumber(L, 2));
    return 0;
}

int CharStatsBinding::setEquipmentStatBonuses(lua_State* L)
{
    CharStats* s = getS(L, 1);
    if (!s) return luaL_error(L, "CharStats is nil");

    s->setEquipmentStatBonuses(
        (float)luaL_checknumber(L, 2),
        (float)luaL_checknumber(L, 3),
        (int)luaL_checknumber(L, 4),
        (int)luaL_checknumber(L, 5),
        (float)luaL_checknumber(L, 6),
        (int)luaL_checknumber(L, 7),
        (float)luaL_checknumber(L, 8),
        (float)luaL_checknumber(L, 9),
        (int)luaL_checknumber(L, 10),
        (float)luaL_checknumber(L, 11),
        (float)luaL_checknumber(L, 12),
        (float)luaL_checknumber(L, 13),
        (float)luaL_checknumber(L, 14));
    return 0;
}

// --- Registration ------------------------------------------------------------

void CharStatsBinding::registerBinding(lua_State* L)
{
    if (!luaL_newmetatable(L, CharStatsBinding::getMetatableName()))
    {
        lua_pop(L, 1);
        return;
    }

    lua_pushstring(L, CharStatsBinding::getMetatableName());
    lua_setfield(L, -2, "__name");

    lua_pushcfunction(L, CharStatsBinding::gc);
    lua_setfield(L, -2, "__gc");

    lua_pushcfunction(L, CharStatsBinding::tostring);
    lua_setfield(L, -2, "__tostring");

    lua_pushcfunction(L, CharStatsBinding::index);
    lua_setfield(L, -2, "__index");

    lua_pushcfunction(L, CharStatsBinding::newindex);
    lua_setfield(L, -2, "__newindex");

    static const luaL_Reg methods[] = {
        // attributes
        { "getStrength",            CharStatsBinding::getStrength },
        { "getStrengthRaw",         CharStatsBinding::getStrengthRaw },
        { "getDexterity",           CharStatsBinding::getDexterity },
        { "getDexterityRaw",        CharStatsBinding::getDexterityRaw },
        { "getToughness",           CharStatsBinding::getToughness },
        { "getToughnessRaw",        CharStatsBinding::getToughnessRaw },
        { "getPerception",          CharStatsBinding::getPerception },
        { "getAthletics",           CharStatsBinding::getAthletics },
        // combat skills
        { "getMeleeAttack",         CharStatsBinding::getMeleeAttack },
        { "getMeleeDefence",        CharStatsBinding::getMeleeDefence },
        { "getDodge",               CharStatsBinding::getDodge },
        { "getMassCombat",          CharStatsBinding::getMassCombat },
        { "getMartialArts",         CharStatsBinding::getMartialArts },
        { "getKatanas",             CharStatsBinding::getKatanas },
        { "getSabres",              CharStatsBinding::getSabres },
        { "getHackers",             CharStatsBinding::getHackers },
        { "getBlunt",               CharStatsBinding::getBlunt },
        { "getHeavyWeapons",        CharStatsBinding::getHeavyWeapons },
        { "getPolearms",            CharStatsBinding::getPolearms },
        { "getBows",                CharStatsBinding::getBows },
        { "getTurrets",             CharStatsBinding::getTurrets },
        // field / craft
        { "getStealth",             CharStatsBinding::getStealth },
        { "getThieving",            CharStatsBinding::getThieving },
        { "getLockpicking",         CharStatsBinding::getLockpicking },
        { "getAssassination",       CharStatsBinding::getAssassination },
        { "getSurvival",            CharStatsBinding::getSurvival },
        { "getTracking",            CharStatsBinding::getTracking },
        { "getClimbing",            CharStatsBinding::getClimbing },
        { "getSwimming",            CharStatsBinding::getSwimming },
        { "getBluff",               CharStatsBinding::getBluff },
        { "getFieldMedic",          CharStatsBinding::getFieldMedic },
        { "getDoctor",              CharStatsBinding::getDoctor },
        { "getScience",             CharStatsBinding::getScience },
        { "getEngineer",            CharStatsBinding::getEngineer },
        { "getRobotics",            CharStatsBinding::getRobotics },
        { "getLabouring",           CharStatsBinding::getLabouring },
        { "getFarming",             CharStatsBinding::getFarming },
        { "getCooking",             CharStatsBinding::getCooking },
        { "getWeaponSmith",         CharStatsBinding::getWeaponSmith },
        { "getArmourSmith",         CharStatsBinding::getArmourSmith },
        { "getBowSmith",            CharStatsBinding::getBowSmith },
        // xp / status
        { "getXp",                  CharStatsBinding::getXp },
        { "getFreeAttributePoints", CharStatsBinding::getFreeAttributePoints },
        { "getOverallSkillLevel",   CharStatsBinding::getOverallSkillLevel },
        { "isUnarmed",              CharStatsBinding::isUnarmed },
        { "isDefensiveMode",        CharStatsBinding::isDefensiveMode },
        { "isHoldPositionMode",     CharStatsBinding::isHoldPositionMode },
        { "isRangedMode",           CharStatsBinding::isRangedMode },
        // linkage
        { "getMedicalSystem",       CharStatsBinding::getMedicalSystem },
        { "getCharacter",           CharStatsBinding::getCharacter },

        { "setEquippedWeaponSkill", CharStatsBinding::setEquippedWeaponSkill },
        { "_NV_setEquippedWeaponSkill", CharStatsBinding::_NV_setEquippedWeaponSkill },
        { "setEquipmentStatBonuses", CharStatsBinding::setEquipmentStatBonuses },
        { 0, 0 }
    };
    luaL_setfuncs(L, methods, 0);

    lua_pop(L, 1);
}

} // namespace KenshiLua