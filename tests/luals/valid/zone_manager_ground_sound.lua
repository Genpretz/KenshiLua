---@type ZoneManager
local zoneManager

local surfaceSound = zoneManager:getGroundSound(GroundType.GROUND_DIRT, true)
local positionSound = zoneManager:getGroundSound({ x = 0, y = 0, z = 0 })
local staticSound = ZoneManager.getGroundSound(GroundType.GROUND_GRASS, false)

assert(type(surfaceSound) == "string")
assert(type(positionSound) == "string")
assert(type(staticSound) == "string")
