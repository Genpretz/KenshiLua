#include "pch.h"
#include "Bindings\DialogueEventBinding.h"

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

void registerEventBinding(lua_State* L)
{
    lua_newtable(L);

    lua_pushstring(L, "EV_NONE");
    lua_pushinteger(L, 0);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_PLAYER_TALK_TO_ME");
    lua_pushinteger(L, 1);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_ANNOUNCEMENT");
    lua_pushinteger(L, 2);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_I_SEE_NEUTRAL_SQUAD");
    lua_pushinteger(L, 3);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_I_SEE_RAGDOLL");
    lua_pushinteger(L, 4);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_ENEMY_SIGHTED");
    lua_pushinteger(L, 5);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_SOUND_THE_ALARM");
    lua_pushinteger(L, 6);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_I_DEFEATED_SOMEONE");
    lua_pushinteger(L, 7);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_THIEF_CAUGHT_STEALING_FROM_ME");
    lua_pushinteger(L, 8);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_SHOO_FROM_MY_BUILDING");
    lua_pushinteger(L, 9);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_MARKED_FOR_DEATH");
    lua_pushinteger(L, 10);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_SCREAMING_TORTURE");
    lua_pushinteger(L, 11);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_BAR_TALK");
    lua_pushinteger(L, 12);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_UNLOCK_MY_CAGE_OR_SHACKLES");
    lua_pushinteger(L, 13);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_UNLOCK_MY_CAGE_ATTEMPT");
    lua_pushinteger(L, 14);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_I_DEFEATED_SQUAD");
    lua_pushinteger(L, 15);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_LAUNCH_ATTACK");
    lua_pushinteger(L, 16);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_INTRUDER_FOUND");
    lua_pushinteger(L, 17);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_HEALING_OTHER_START");
    lua_pushinteger(L, 18);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_BEING_HEALED_START");
    lua_pushinteger(L, 19);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_HEALING_OTHER_FINISHED");
    lua_pushinteger(L, 20);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_BEING_HEALED_FINISHED");
    lua_pushinteger(L, 21);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_FIRSTAID_KIT_EMPTY");
    lua_pushinteger(L, 22);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_GET_UP_PEACE");
    lua_pushinteger(L, 23);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_GET_UP_FIGHT");
    lua_pushinteger(L, 24);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_GET_UP_UNNECCESSARY_FIGHT");
    lua_pushinteger(L, 25);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_HARRASSMENT_SHOUTS");
    lua_pushinteger(L, 26);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_I_SEE_ANIMAL_SQUAD");
    lua_pushinteger(L, 27);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_SPEECH_INTERRUPTED_ATTACKED_BY_TARGET");
    lua_pushinteger(L, 28);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_SPEECH_INTERRUPTED_ATTACKED_BY_STRANGERS");
    lua_pushinteger(L, 29);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_CONTRACT_JOB_ENDED");
    lua_pushinteger(L, 30);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_BETRAYAL");
    lua_pushinteger(L, 31);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_LOOTING_WEAPON_ONLY");
    lua_pushinteger(L, 32);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_LOOTING_EVERYTHING");
    lua_pushinteger(L, 33);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_I_SEE_UNIFORM_IMPOSTER");
    lua_pushinteger(L, 34);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_INTRODUCING_NEW_SLAVE");
    lua_pushinteger(L, 35);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_ESCAPING_SLAVE_SPOTTED");
    lua_pushinteger(L, 36);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_RECAPTURED_A_SLAVE");
    lua_pushinteger(L, 37);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_SHOUT_AT_SLAVE_WORKER");
    lua_pushinteger(L, 38);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_SLAVE_DELIVERY");
    lua_pushinteger(L, 39);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_ESCAPED_EX_SLAVE_SPOTTED");
    lua_pushinteger(L, 40);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_WITNESS_GENERIC_ASSAULT");
    lua_pushinteger(L, 41);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_WITNESS_LOOTING_ALLY");
    lua_pushinteger(L, 42);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_WITNESS_THIEF_OR_LOCKPICK");
    lua_pushinteger(L, 43);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_BOUNTY_SPOTTED");
    lua_pushinteger(L, 44);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_ESCAPED_PRISONER_SPOTTED");
    lua_pushinteger(L, 45);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_PRISONER_FREE_TO_GO");
    lua_pushinteger(L, 46);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_ALMOST_WOKE_UP");
    lua_pushinteger(L, 47);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_ENTER_BIOME");
    lua_pushinteger(L, 48);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_ENTER_TOWN");
    lua_pushinteger(L, 49);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_SQUAD_BROKEN");
    lua_pushinteger(L, 50);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_BOUGHT_ME_FROM_SLAVERY");
    lua_pushinteger(L, 51);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_EATING_SOMETHING_SOUNDS");
    lua_pushinteger(L, 52);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_WORSHIPING_SOMETHING");
    lua_pushinteger(L, 53);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_SLAVE_ESCAPE_OPPORTUNITY_SAVIOR");
    lua_pushinteger(L, 54);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_SLAVE_ESCAPE_OPPORTUNITY_ALONE");
    lua_pushinteger(L, 55);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_ASSASSINATION_FAILED");
    lua_pushinteger(L, 56);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_EATING_MY_CROPS");
    lua_pushinteger(L, 57);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_KIDNAPPING_MY_ALLY");
    lua_pushinteger(L, 58);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_USING_MY_TRAINING_EQUIPMENT");
    lua_pushinteger(L, 59);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_GIVE_UP_CHASE");
    lua_pushinteger(L, 60);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_ACID_FEET");
    lua_pushinteger(L, 61);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_ACID_RAIN");
    lua_pushinteger(L, 62);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_ACID_WATER");
    lua_pushinteger(L, 63);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_WINDY");
    lua_pushinteger(L, 64);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_POISON_GAS");
    lua_pushinteger(L, 65);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_I_SEE_ENEMY_PLAYER");
    lua_pushinteger(L, 66);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_I_SEE_ALLY_PLAYER");
    lua_pushinteger(L, 67);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_I_SEE_ILLEGAL_PLAYER_BUILDING");
    lua_pushinteger(L, 68);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_BURNING");
    lua_pushinteger(L, 69);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_LOST_LEG");
    lua_pushinteger(L, 70);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_LOST_ARM");
    lua_pushinteger(L, 71);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_I_SEE_PLAYER_NICE_BUILDING");
    lua_pushinteger(L, 72);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_TAKEN_OVER_PLAYER_TOWN");
    lua_pushinteger(L, 73);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_CROWD_TRIGGERED");
    lua_pushinteger(L, 74);
    lua_settable(L, -3);

    lua_pushstring(L, "EV_MAX");
    lua_pushinteger(L, 75);
    lua_settable(L, -3);

    lua_setglobal(L, "EventTrigger");
}

} // namespace KenshiLua