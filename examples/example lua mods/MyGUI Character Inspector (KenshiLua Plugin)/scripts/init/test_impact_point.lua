-- test_impact_point.lua
-- This script tests the constructor, getters/setters, and assignment operator of the ImpactPoint binding.

log("[Test ImpactPoint] Starting test...")

-- 1. Create a new ImpactPoint using the constructor
local ip1 = ImpactPoint.__constructor()
if not ip1 then
    log("[Test ImpactPoint] Error: ImpactPoint.__constructor() returned nil!")
    return
end
log("[Test ImpactPoint] Successfully created ip1: " .. tostring(ip1))

-- 2. Verify default values (constructor sets power = 1.0f, others should be 0 due to memset)
log("[Test ImpactPoint] Default power: " .. tostring(ip1.power))
log("[Test ImpactPoint] Default direction: " .. tostring(ip1.direction))
log("[Test ImpactPoint] Default impactAnimationFrame: " .. tostring(ip1.impactAnimationFrame))
log("[Test ImpactPoint] Default motionStopsAnimationFrame: " .. tostring(ip1.motionStopsAnimationFrame))
log("[Test ImpactPoint] Default limb: " .. tostring(ip1.limb))

-- 3. Modify the fields of ip1
log("[Test ImpactPoint] Modifying fields...")
ip1.power = 3.5
ip1.direction = CutDirection.CUT_DOWNWARD
ip1.impactAnimationFrame = 12.0
ip1.motionStopsAnimationFrame = 24.5
ip1.limb = RobotLimbs.LEFT_ARM

-- 4. Verify the updated fields
log("[Test ImpactPoint] Updated power: " .. tostring(ip1.power) .. " (expected: 3.5)")
log("[Test ImpactPoint] Updated direction: " .. tostring(ip1.direction) .. " (expected: " .. tostring(CutDirection.CUT_DOWNWARD) .. ")")
log("[Test ImpactPoint] Updated impactAnimationFrame: " .. tostring(ip1.impactAnimationFrame) .. " (expected: 12.0)")
log("[Test ImpactPoint] Updated motionStopsAnimationFrame: " .. tostring(ip1.motionStopsAnimationFrame) .. " (expected: 24.5)")
log("[Test ImpactPoint] Updated limb: " .. tostring(ip1.limb) .. " (expected: " .. tostring(RobotLimbs.LEFT_ARM) .. ")")

-- 5. Create a second ImpactPoint and test the assignment (operator=)
local ip2 = ImpactPoint.__constructor()
if not ip2 then
    log("[Test ImpactPoint] Error: Failed to create second ImpactPoint!")
    return
end
log("[Test ImpactPoint] Successfully created ip2: " .. tostring(ip2))

log("[Test ImpactPoint] Assigning ip1 to ip2...")
-- Since the binding registers this under the key "operator=", we invoke it via table lookup:
local assign = ip2["operator="]
if not assign then
    log("[Test ImpactPoint] Error: 'operator=' method not found on ip2!")
    return
end
assign(ip2, ip1)

-- 6. Verify ip2 has the copied values
log("[Test ImpactPoint] ip2 power: " .. tostring(ip2.power) .. " (expected: 3.5)")
log("[Test ImpactPoint] ip2 direction: " .. tostring(ip2.direction) .. " (expected: " .. tostring(CutDirection.CUT_DOWNWARD) .. ")")
log("[Test ImpactPoint] ip2 impactAnimationFrame: " .. tostring(ip2.impactAnimationFrame) .. " (expected: 12.0)")
log("[Test ImpactPoint] ip2 motionStopsAnimationFrame: " .. tostring(ip2.motionStopsAnimationFrame) .. " (expected: 24.5)")
log("[Test ImpactPoint] ip2 limb: " .. tostring(ip2.limb) .. " (expected: " .. tostring(RobotLimbs.LEFT_ARM) .. ")")

log("[Test ImpactPoint] Test completed successfully!")
