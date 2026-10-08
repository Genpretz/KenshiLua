---@param carry Character_CarryMsg
---@param ragdoll Character_RagdollMsg
---@param task TaskStateData
---@param spot Spot
local function check(carry, ragdoll, task, spot)
    carry.on, carry.rag, carry.hull = true, false, true
    ragdoll.on, ragdoll.part = true, 1
    task.key, task.progressionOnly, task.val = 2, true, false
    spot.timeSoFar, spot.timeLimitMax, spot.stillSeen = 1, 2, true
    assert(carry.on and ragdoll:operator_eq(ragdoll) and task.key == 2 and spot.stillSeen)
end
return check
