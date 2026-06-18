// pch.h: This is a precompiled header file.
#ifndef PCH_H
#define PCH_H

#include "framework.h"
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <unordered_map>
#include <memory>
#include <algorithm>
#include <functional>
#include <iostream>

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

#include <core/Functions.h>
#include <kenshi/Building/Building.h>
#include <kenshi/Character.h>
#include <kenshi/CharStats.h>
#include <kenshi/Damages.h>
#include <kenshi/Faction.h>
#include <kenshi/PlayerInterface.h>
#include <kenshi/InputHandler.h>
#include <kenshi/GameWorld.h>
#include <kenshi/GameData.h>
#include <kenshi/MedicalSystem.h>
#include <kenshi/Dialogue.h>
#include <kenshi/Platoon.h>
#include <kenshi/util/hand.h>

#endif // PCH_H