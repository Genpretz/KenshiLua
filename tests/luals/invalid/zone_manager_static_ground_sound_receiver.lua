-- EXPECT-DIAGNOSTIC: param-type-mismatch

---@type ZoneManager
local zoneManager

ZoneManager.getGroundSound(zoneManager, GroundType.GROUND_DIRT)
